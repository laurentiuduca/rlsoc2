/* Modified by Laurentiu-Cristian Duca, 2021-12-20
 * - implemented a new controller with unaligned ld/sw
 */
/**************************************************************************************************/
/**** RVSoC (Mini Kuroda/RISC-V)                       since 2018-08-07   ArchLab. TokyoTech   ****/
/**** Memory Module v0.02                                                                      ****/
/**************************************************************************************************/
`default_nettype none
/**************************************************************************************************/
`include "define.vh"

/**** DRAM Main Memory module for implementation                                               ****/
/**************************************************************************************************/
`default_nettype wire

/**** DRAM Controller without Cache                                                            ****/
/**************************************************************************************************/
module DRAM_conRV
    (
     // user interface ports
     input  wire                         i_rd_en,
     input  wire                         i_wr_en,
     input  wire [31:0]                  i_addr,
     input  wire [31:0]                  i_data,
     output wire [31:0]                  o_data,
     output wire                         o_busy,
     input  wire [2:0]                   i_ctrl,

     input clk,
     input rst_x,
     input clk_sdram,
     output o_init_calib_complete,

     output O_sdram_clk,
     output O_sdram_cke,
     output O_sdram_cs_n,            // chip select
     output O_sdram_cas_n,           // columns address select
     output O_sdram_ras_n,           // row address select
     output O_sdram_wen_n,           // write enable
     inout [31:0] IO_sdram_dq,       // 32 bit bidirectional data bus
     output [10:0] O_sdram_addr,     // 11 bit multiplexed address bus
     output [1:0] O_sdram_ba,        // two banks
     output [3:0] O_sdram_dqm       // 32/4
);

    reg         r_we    = 0;
    reg         r_rd    = 0;
    wire 	w_busy;
    wire[31:0] w_dram_odata;
    reg [3:0] r_mask = 0;
    reg   [2:0] r_ctrl  = 0;
    reg [31:0] r_odata = 0;
    reg [31:0] r_dram_odata1 = 0;
    reg [23:0] r_dram_odata2 = 0;
    reg [31:0] r_maddr, r_addr;

    // 4+3 bytes shifted with 0 .. 3 bytes.
    wire[31:0] w_odata = {r_dram_odata2, r_dram_odata1} >> {r_addr[1:0], 3'b0};
    assign o_data = (r_ctrl[1:0]==0) ? ((r_ctrl[2]) ? {24'h0, w_odata[7:0]} :
                                         {{24{w_odata[7]}}, w_odata[7:0]}) :
                     (r_ctrl[1:0]==1) ? ((r_ctrl[2]) ? {16'h0, w_odata[15:0]} :
                                         {{16{w_odata[15]}}, w_odata[15:0]}) :
                     w_odata;
    reg [31:0] r_wdata=0, r_wdata_ui=0;

    reg r_stall = 0;
    assign o_busy = (r_stall | w_busy);
    reg [7:0] state = 0, state_next = 0;
    reg [31:0] r_cnt = 0;
    always@(posedge clk) begin
        case(state)
        8'd0: // idle
                if(i_rd_en && !w_busy) begin
                        state <= 10;
			state_next <= 30;
			r_rd <= 1;
                        r_stall <= 1;
                        r_addr <= i_addr;
			r_maddr <= {i_addr[31:4], 4'b0};
                        r_ctrl <= i_ctrl;
                end else if(i_wr_en && !w_busy) begin
			state <= 20;
                        r_stall <= 1;
			r_addr <= i_addr;
                        r_maddr <= {i_addr[31:2], 2'b0};
                        r_wdata_ui <= (i_ctrl[1:0] == 0) ? {24'h0, i_data[7:0]} :
                                   (i_ctrl[1:0] == 1) ? {16'h0, i_data[15:0]} : i_data;
                        r_ctrl <= i_ctrl;
                end
	8'd10: begin //mem read
		if(w_busy) begin
			r_rd <= 0;
                	state <= 11;
		end 
	end
	8'd11: begin
                if(!w_busy) begin
                        r_dram_odata1 <= w_dram_odata;
                        if(r_addr[3:0] <= 12) // one read is enough
                                state <= 100;
                        else begin
                                state <= 12;
                                r_rd <= 1;
                                //r_maddr <= {r_addr[31:4]+28'b1, 4'b0};
                                r_maddr <= r_maddr + 16;
                        end
                end
        end
	8'd12: begin 
		// idem state 10
		if(w_busy) begin
                        r_rd <= 0;
                        state <= 13;
                end
	end
	8'd13: begin
		// similar state 11
		if(!w_busy) begin
                        //r_dram_odata2 <= w_dram_odata[23:0];
			r_dram_odata2 <= w_dram_odata;
                        state <= 100;
                end
	end
	8'd100: begin 
		state <= 0;
		r_stall <= 0;
	end
	8'd20: begin // mem_write
                if(r_ctrl[1:0]==0) begin // SB
			if(r_addr[1:0] == 0) begin
                        	r_mask <= 4'b0001;
				r_wdata <= r_wdata_ui;
			end else if(r_addr[1:0] == 1) begin
				r_mask <= 4'b0010;
				r_wdata <= r_wdata_ui << 8;
			end else if(r_addr[1:0] == 2) begin
                                r_mask <= 4'b0100;
				r_wdata <= r_wdata_ui << 16;
			end else if(r_addr[1:0] == 3) begin
                                r_mask <= 4'b1000;
				r_wdata <= r_wdata_ui << 24;
			end
			r_we <= 1;
			state <= 21;
			state_next <= 100;
                end else if(r_ctrl[1:0]==1) begin // SH
			if(r_addr[1:0] == 0) begin
				r_mask <= 4'b0011;
				r_wdata <= r_wdata_ui;
				r_we <= 1;
				state <= 21;
				state_next <= 100;
			end else if (r_addr[1:0] == 1) begin
				r_mask <= 4'b0110;
				r_wdata <= r_wdata_ui << 8;
				r_we <= 1;
				state <= 21;
				state_next <= 100;
			end else if (r_addr[1:0] == 2) begin
                                r_mask <= 4'b1100;
                                r_we <= 1;
                                r_wdata <= r_wdata_ui << 16;
                                state <= 21;
                                state_next <= 100;
			end else if (r_addr[1:0] == 3) begin
				// write in two cycles.
                                r_mask <= 4'b1000;
                                r_wdata <= r_wdata_ui << 24;
                                r_we <= 1;
                                state <= 21;
                                state_next <= 31;
			end
                end else if(r_ctrl[1:0]==2) begin // SW
			if(r_addr[1:0] == 0) begin
				r_mask <= 4'b1111;
				r_wdata <= r_wdata_ui;
				r_we <= 1;
                                state <= 21;
                                state_next <= 100;
			end else if(r_addr[1:0] == 1) begin
				// write in two cycles.
				r_mask <= 4'b1110;
				r_wdata <= r_wdata_ui << 8;
				r_we <= 1;
				state <= 21;
				state_next <= 40;
			end else if(r_addr[1:0] == 2) begin
				// write in two cycles.
				r_mask <= 4'b1100;
                                r_wdata <= r_wdata_ui << 16;
                                r_we <= 1;
                                state <= 21;
                                state_next <= 41;
			end else if(r_addr[1:0] == 3) begin
				// write in two cycles.
				r_mask <= 4'b1000;
                                r_wdata <= r_wdata_ui << 24;
                                r_we <= 1;
                                state <= 21;
                                state_next <= 42;
			end
                end
                state <= 21;
		r_we <= 1;
	end
	8'd21: begin
		if(w_busy) begin
			r_we <= 0;
			state <= 22;
		end 
	end
	8'd22: begin
		if(!w_busy) begin
			state <= state_next;
		end
	end
        8'd31: begin
                // SH with (r_addr[1:0] == 3) second write
                r_mask <= 4'b0001;
		r_maddr <= r_maddr + 4;
		r_wdata <= r_wdata_ui >> 8;
                r_we <= 1;
                state <= 21;
                state_next <= 100;
        end
	8'd40: begin
		// SW with (r_addr[1:0] == 1) second write
		r_mask <= 4'b0001;
		r_maddr <= r_maddr + 4;
		r_wdata <= r_wdata_ui >> 24;
		r_we <= 1;
                state <= 21;
                state_next <= 100;
	end
	8'd41: begin
		// SW with (r_addr[1:0] == 2) second write
		r_mask <= 4'b0011;
		r_maddr <= r_maddr + 4;
                r_wdata <= r_wdata_ui >> 16;
                r_we <= 1;
                state <= 21;
                state_next <= 100;
	end
        8'd42: begin
                // SW with (r_addr[1:0] == 3) second write
		r_mask <= 4'b0111;
		r_maddr <= r_maddr + 4;
                r_wdata <= r_wdata_ui >> 8;
                r_we <= 1;
                state <= 21;
                state_next <= 100;
	end
	endcase
    end


    MemoryController memory(.clk(clk), .clk_sdram(clk_sdram), .resetn(rst_x),
        .read_a(r_rd), 
        .read_b(1'b0),
        .write(r_we),
        .refresh(refresh),
        .addr(r_maddr),
        .din(r_wdata), .mask(~r_mask),
        .dout_a(w_dram_odata), .dout_b(),
        .busy(w_busy), .mem_initialized(o_init_calib_complete), .fail(), .total_written(),

        .SDRAM_DQ(IO_sdram_dq), .SDRAM_A(O_sdram_addr), .SDRAM_BA(O_sdram_ba), .SDRAM_nCS(O_sdram_cs_n),
        .SDRAM_nWE(O_sdram_wen_n), .SDRAM_nRAS(O_sdram_ras_n), .SDRAM_nCAS(O_sdram_cas_n), 
        .SDRAM_CLK(O_sdram_clk), .SDRAM_CKE(O_sdram_cke), .SDRAM_DQM(O_sdram_dqm)
    );

endmodule
/**************************************************************************************************/

