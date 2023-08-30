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
`ifndef SIM_MODE
/**** DRAM Controller without Cache                                                            ****/
/**************************************************************************************************/
module DRAM_conRV#(
`ifndef ARTYA7
              parameter DDR2_DQ_WIDTH   = 16,
              parameter DDR2_DQS_WIDTH  = 2,
              parameter DDR2_ADDR_WIDTH = 13,
              parameter DDR2_BA_WIDTH   = 3,
              parameter DDR2_DM_WIDTH   = 2,
              parameter APP_ADDR_WIDTH  = 27,
`else
              parameter DDR3_DQ_WIDTH   = 16,
              parameter DDR3_DQS_WIDTH  = 2,
              parameter DDR3_ADDR_WIDTH = 14,
              parameter DDR3_BA_WIDTH   = 3,
              parameter DDR3_DM_WIDTH   = 2,
              parameter APP_ADDR_WIDTH  = 28,
`endif
              parameter APP_CMD_WIDTH   = 3,
              parameter APP_DATA_WIDTH  = 128,  // Note
              parameter APP_MASK_WIDTH  = 16)
    (
     // input clk, rst (active-low)
     input  wire                         mig_clk,
     input  wire                         mig_rst_x,
`ifdef ARTYA7
     input  wire                         ref_clk,
`endif
     // memory interface ports
`ifndef ARTYA7
     inout  wire [DDR2_DQ_WIDTH-1 : 0]   ddr2_dq,
     inout  wire [DDR2_DQS_WIDTH-1 : 0]  ddr2_dqs_n,
     inout  wire [DDR2_DQS_WIDTH-1 : 0]  ddr2_dqs_p,
     output wire [DDR2_ADDR_WIDTH-1 : 0] ddr2_addr,
     output wire [DDR2_BA_WIDTH-1 : 0]   ddr2_ba,
     output wire                         ddr2_ras_n,
     output wire                         ddr2_cas_n,
     output wire                         ddr2_we_n,
     output wire [0:0]                   ddr2_ck_p,
     output wire [0:0]                   ddr2_ck_n,
     output wire [0:0]                   ddr2_cke,
     output wire [0:0]                   ddr2_cs_n,
     output wire [DDR2_DM_WIDTH-1 : 0]   ddr2_dm,
     output wire [0:0]                   ddr2_odt,
`else
     inout  wire [DDR3_DQ_WIDTH-1 : 0]   ddr3_dq,
     inout  wire [DDR3_DQS_WIDTH-1 : 0]  ddr3_dqs_n,
     inout  wire [DDR3_DQS_WIDTH-1 : 0]  ddr3_dqs_p,
     output wire [DDR3_ADDR_WIDTH-1 : 0] ddr3_addr,
     output wire [DDR3_BA_WIDTH-1 : 0]   ddr3_ba,
     output wire                         ddr3_ras_n,
     output wire                         ddr3_cas_n,
     output wire                         ddr3_we_n,
     output wire [0:0]                   ddr3_ck_p,
     output wire [0:0]                   ddr3_ck_n,
     output wire                         ddr3_reset_n,
     output wire [0:0]                   ddr3_cke,
     output wire [0:0]                   ddr3_cs_n,
     output wire [DDR3_DM_WIDTH-1 : 0]   ddr3_dm,
     output wire [0:0]                   ddr3_odt,
`endif

     // output clk, rst (active-low)
     output wire                         o_clk,
     output wire                         o_rst_x,
     // user interface ports
     input  wire                         i_rd_en,
     input  wire                         i_wr_en,
     input  wire [31:0]                  i_addr,
     input  wire [31:0]                  i_data,
     output wire                         o_init_calib_complete,
     output wire [31:0]                  o_data,
     output wire                         o_busy,
     input  wire [2:0]                   i_ctrl);

    reg         r_we    = 0;
    reg         r_rd    = 0;
    wire 	w_busy;
    wire[127:0] w_dram_odata;
    reg [3:0] r_mask = 0;
    reg   [2:0] r_ctrl  = 0;
    reg [31:0] r_odata = 0;
    reg [127:0] r_dram_odata1 = 0;
    reg [23:0] r_dram_odata2 = 0;
    reg [31:0] r_maddr, r_addr;

    // 16+3 bytes shifted with 0 or 15 bytes.
    wire[31:0] w_odata = {r_dram_odata2, r_dram_odata1} >> {r_addr[3:0], 3'b0};
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
    always@(posedge o_clk) begin
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

Gowin_rPLL_nes pll_nes(
    .clkin(sys_clk),
    .clkout(clk),          // FREQ main clock
    .clkoutp(clk_sdram)    // FREQ main clock phase shifted
);


  MemoryController memory(.clk(clk), .clk_sdram(clk_sdram), .resetn(sys_resetn),
        .read_a((cfg_rw_i == `MEM_READ_CMD)), 
        .read_b(1'b0),
        .write((cfg_rw_i == `MEM_WRITE_CMD)),
        .refresh(refresh),
        .addr(addr_i),
        .din(data_i), .mask(~r_mask),
        .dout_a(data_o), .dout_b(),
        .busy(busy_o), .mem_initialized(mem_initialized), .fail(ram_fail), .total_written(),

        .SDRAM_DQ(IO_sdram_dq), .SDRAM_A(O_sdram_addr), .SDRAM_BA(O_sdram_ba), .SDRAM_nCS(O_sdram_cs_n),
        .SDRAM_nWE(O_sdram_wen_n), .SDRAM_nRAS(O_sdram_ras_n), .SDRAM_nCAS(O_sdram_cas_n), 
        .SDRAM_CLK(O_sdram_clk), .SDRAM_CKE(O_sdram_cke), .SDRAM_DQM(O_sdram_dqm)
);

`ifdef SKIP_CACHE 
    DRAM_con_witout_cache dram_con_witout_cache (
               // input clk, rst (active-low)
               .mig_clk(mig_clk),
               .mig_rst_x(mig_rst_x),
`ifdef ARTYA7
               .ref_clk(ref_clk),
`endif
               // memory interface ports
               // output clk, rst (active-low)
               .o_clk(o_clk),
               .o_rst_x(o_rst_x),
               // user interface ports
               .i_rd_en(r_rd),
               .i_wr_en(r_we),
	       .o_init_calib_complete(o_init_calib_complete),
	       .i_addr(r_maddr),
               .i_data(r_wdata),
               .o_data(w_dram_odata),
               .o_busy(w_busy),
               .i_mask(~r_mask));
endmodule
/**************************************************************************************************/

