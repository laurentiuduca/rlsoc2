/* author Laurentiu-Cristian Duca, 20240322
// spdx license identifier MIT
 */
/**************************************************************************************************/
/**************************************************************************************************/
`default_nettype none
/**************************************************************************************************/
`include "define.vh"

/**************************************************************************************************/
module DRAM_conRV #(parameter PRELOAD_FILE = "")
    (
     // user interface ports
     input  wire                         i_rd_en,
     input  wire                         i_wr_en,
     input  wire [31:0]                  i_addr,
     input  wire [31:0]                  i_data,
     output wire [31:0]                  o_data,
     output wire                         o_busy,
     input  wire [3:0]                   i_ctrl,
     input  wire [2:0]                   sys_state,
     input  wire [3:0]                   w_bus_cpustate,
     output wire [7:0]                   mem_state,
     input  wire [31:0]                  d_pc,

   `ifdef SIM_MODE
      input wire [31:0] w_mtime,
   `else
    // SDRAM
    output wire SDCLK0,
    output wire SDCKE0,
    output wire [1:0]DQM,
    output wire CAS,
    output wire RAS,
    output wire SDWE,
    output wire SDCS0,
    inout wire [15:0]Data,
    output wire [12:0]Address,
    output wire [1:0]Bank,
    `endif

     input wire clk,
     input wire rst_x,
     input wire clk_sdram
);

    reg         req     = 0;
    reg         r_we    = 0;
    reg         r_rd    = 0;
    wire 	w_busy;
    wire[31:0] w_dram_odata;
    reg [3:0] r_mask=0, r_mmask=0;
    reg [31:0] r_dram_odata=0;
    reg [31:0] r_addr=0, r_maddr=0;

    wire[31:0] w_odata = r_dram_odata;
    assign o_data = w_odata;
    reg [31:0] r_wdata=0, r_mwdata=0;

    reg r_stall = 0;
    assign o_busy = r_stall;
    reg [7:0] state = 0, ramstate=0;
    assign mem_state = state;
    reg r_refresh = 0;

    wire empty_afifo1, empty_afifo2;
    wire full_afifo1, full_afifo2;
    reg wen_afifo1=0, wen_afifo2=0;
    reg ren_afifo1=0, ren_afifo2=0;
    `define af1size 70 // = addr + mask + rd + wr + idata
    `define af2size 70 // odata
    reg [`af1size-1:0] din_afifo1=0;
    wire [`af1size-1:0] dout_afifo1; 
    reg [`af2size-1:0] din_afifo2=0;
    wire [`af1size-1:0] dout_afifo2; 
    // proc to sdram
    asyncfifo #(
                .DATA_WIDTH(`af1size),
                .ADDR_WIDTH(2),
		.qid(1))
    afifo1 (
            .wclk(clk),
            .rclk(clk_sdram),
            .i_wrst_x(rst_x),
            .i_rrst_x(rst_x),
            .i_wen(wen_afifo1),
            .i_data(din_afifo1),
            .i_ren(ren_afifo1),
            .o_data(dout_afifo1),
            .o_empty(empty_afifo1),
            .o_full(full_afifo1));
    // sdram to pl
    asyncfifo #(
                .DATA_WIDTH(`af2size),
                .ADDR_WIDTH(2),
		.qid(2))
    afifo2 (
            .wclk(clk_sdram),
            .rclk(clk),
            .i_wrst_x(rst_x),
            .i_rrst_x(rst_x),
            .i_wen(wen_afifo2),
            .i_data(din_afifo2),
            .i_ren(ren_afifo2),
            .o_data(dout_afifo2),
            .o_empty(empty_afifo2),
            .o_full(full_afifo2));

task prepare_read;
begin
	 r_addr <= i_addr;
         r_mask <= 4'hf;
         r_stall <= 1;
 	 state <= 10;
end
endtask 

task prepare_write;
begin
	 r_addr <= i_addr;
         r_wdata <= i_data;
         r_mask <= i_ctrl;
         r_stall <= 1;
	 state <= 20;
end
endtask 

    // proc to sdram
always@(posedge clk) begin
    if(~rst_x) begin
      state <= 0;
    end else
    case(state)
	8'd0: // idle
       		if(i_rd_en && !ramstate && empty_afifo1 && empty_afifo2) begin
         		prepare_read;
      		end else if(i_wr_en && !ramstate && empty_afifo1 && empty_afifo2) begin
         		prepare_write;
      		end
        8'd10: begin // mem read
	       din_afifo1 <= {r_addr, r_mask, 1'b1, 1'b0, r_wdata};
	       wen_afifo1 <= 1;
	       state <= 11;
        end	       
	8'd11: begin 
		wen_afifo1 <= 0;
		if(!empty_afifo1)
			state <= 12;
        end
	8'd12: begin 
		if(empty_afifo1 && !empty_afifo2) begin
			state <= 13;
		end
	end
	8'd13: begin
		ren_afifo2 <= 1;
		r_dram_odata <= dout_afifo2;
		state <= 14;
	end
	8'd14: begin
		ren_afifo2 <= 0;
		r_stall <= 0;
		state <= 0;
		if(i_rd_en) begin
                                $display("error rd");
                                $finish();
		end
	end
        8'd20: begin // mem write
		din_afifo1 <= {r_addr, r_mask, 1'b0, 1'b1, r_wdata};
                wen_afifo1 <= 1;
                state <= 21;

        end
	8'd21: begin
                wen_afifo1 <= 0;
                if(!empty_afifo1)
                        state <= 22;
        end
        8'd22: begin
                if(empty_afifo1) begin
			r_stall <= 0;
                        state <= 0;
			if(i_wr_en) begin
				$display("error wr");
				$finish();
			end

                end
        end
	endcase
end

    // sdram to proc
    always@(posedge clk_sdram) begin
    if(~rst_x) begin
      ramstate <= 0;
    end else
    case(ramstate)
        8'd0: // idle
                if(!empty_afifo1) begin
                        ren_afifo1 <= 1;
			{r_maddr, r_mmask, r_rd, r_we, r_mwdata} <= dout_afifo1;
			ramstate <= 1;
                end
	8'd1: begin
		// command from proc
		ren_afifo1 <= 0;
		if(r_rd) begin
			if(w_busy) begin
				r_rd <= 0;
				ramstate <= 10;
			end
		end else if(r_we) begin
			if(w_busy) begin
				r_we <= 0;
				ramstate <= 20;
			end
		end else begin
			$display("afifo logic error");
			$finish;
		end
	end
	8'd10: begin // read
		if(!w_busy) begin
			din_afifo2 <= w_dram_odata;
			wen_afifo2 <= 1;
			ramstate <= 11;
		end
	end
	8'd11: begin
		wen_afifo2 <= 0;
		if(!empty_afifo2) begin
			ramstate <= 0;
		end
	end
	8'd20: begin
		if(!w_busy)
			ramstate <= 0;
	end
	endcase	
end

`ifdef SIM_MODE
    m_sdram_sim #(`BIN_SIZE/2) idbmem(.CLK(clk), .w_addr(r_maddr), .w_odata(w_dram_odata),
        .w_we(r_we), .w_le(r_rd), .w_wdata(r_mwdata), .w_mask(~r_mmask), .w_stall(w_busy), 
        .w_mtime(w_mtime[31:0]),
        .w_refresh(0)
        );
`else
    wire [6:0] drvstate;
    assign SDCLK0=clk_sdram;
    sdramwinb sdram_instance_name(
        .clk(clk_sdram),
        .rst(rst_x), // active low
        .data(Data),
        .addr(Address),
        .ba(Bank),
        .cke(SDCKE0),
        .cs_n(SDCS0),
        .ras_n(RAS),
        .cas_n(CAS),
        .we_n(SDWE),
        .dqm(DQM),

	.dqmi(~r_mmask),
        .busy(w_busy),
        .uaddr(r_maddr),
        .ucmd(r_rd | r_we),
        .uwe(r_we),
        .uwrdata(r_mwdata),
        .urddata(w_dram_odata),
        .state_cnt(drvstate)
);
`endif

/**********************************************************************************************/

`ifdef SIM_MODE
    // LOAD linux
    integer i, j;
    //integer k;
    reg  [7:0] mem_bbl [0:`BBL_SIZE-1];
    initial begin
`ifndef VERILATOR
    $display("VERILATOR NOT DEFINED");
    #1
`endif

        $write("Running %s\n", PRELOAD_FILE);
        $readmemh(PRELOAD_FILE, mem_bbl);
        j=0;

        for(i=0;i<`BBL_SIZE;i=i+2) begin
	    idbmem.idbmem.mem[j][7:0]=mem_bbl[i];
	    idbmem.idbmem.mem[j][15:8]=mem_bbl[i+1];
            j=j+1;
        end
        $write("-------------------------------------------------------------------\n");
    end
`endif
endmodule
/**************************************************************************************************/

