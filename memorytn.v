/* author Laurentiu-Cristian Duca, 20240322
// spdx license identifier MIT
 */
/**************************************************************************************************/
/**************************************************************************************************/
`default_nettype none
/**************************************************************************************************/
`include "define.vh"

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
     input  wire [2:0]                   sys_state,
     input  wire [3:0]                   w_bus_cpustate,
     output wire [7:0]                   mem_state,

   `ifdef SIM_MODE
      input wire [31:0] w_mtime,
   `else
    // SDRAM
    output wire O_sdram_clk,
    output wire O_sdram_cke,
    output wire O_sdram_cs_n,            // chip select
    output wire O_sdram_cas_n,           // columns address select
    output wire O_sdram_ras_n,           // row address select
    output wire O_sdram_wen_n,           // write enable
    inout wire [31:0] IO_sdram_dq,       // 32 bit bidirectional data bus
    output wire [10:0] O_sdram_addr,     // 11 bit multiplexed address bus
    output wire [1:0] O_sdram_ba,        // two banks
    output wire [3:0] O_sdram_dqm,       // 32/4
    `endif

     `ifdef TN_DRAM_REFRESH
     output reg r_late_refresh,
     `endif

     input wire clk,
     input wire rst_x,
     input wire clk_sdram,
     output wire o_init_calib_complete,
     output wire sdram_fail
);

`ifdef SIM_TNSRAM
`define TNSRAM
`else
`ifndef SIM_MODE
`define TNSRAM
`endif
`endif

`ifdef TNSRAM
    reg         r_we    = 0;
    reg         r_rd    = 0;
    wire 	w_busy;
    wire[31:0] w_dram_odata;
    reg [3:0] r_mask = 0;
    reg [2:0] r_ctrl  = 0;
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
    assign o_busy = (r_stall/* | w_busy*/);
    reg [7:0] state_next = 0, state = 0;
    assign mem_state = state;
    reg r_refresh = 0;

task prepare_read_base;
begin
         r_addr <= i_addr;
			r_maddr <= {i_addr[31:2], 2'b0};
         r_ctrl <= i_ctrl;
         r_stall <= 1;
end
endtask 
task prepare_read_end;
begin
			state <= 10;
         r_rd <= 1;
end
endtask 
task prepare_read;
begin
         prepare_read_base;
         prepare_read_end;

end
endtask 

task prepare_write_base;
begin
			r_addr <= i_addr;
         r_maddr <= {i_addr[31:2], 2'b0};
         r_wdata_ui <= (i_ctrl[1:0] == 0) ? {24'h0, i_data[7:0]}  :
                       (i_ctrl[1:0] == 1) ? {16'h0, i_data[15:0]} : 
                        i_data;
         r_ctrl <= i_ctrl;
         r_stall <= 1;
end
endtask
task prepare_write_end;
begin
			state <= 20;
end
endtask 
task prepare_write;
begin
         prepare_write_base;
         prepare_write_end;
end
endtask 

`ifdef TN_DRAM_REFRESH
   reg [31:0] r_refreshcnt = 0;
   reg read_request=0;
   reg write_request=0;
   
   task prepare_refresh;
   begin
            state <= 50;
            r_refresh <= 1;
            //r_stall <= 1;
   end
   endtask 

   // 15us = 405 periods at 27MHz, 2writes take max 200ns
   `define REFRESH_CNT 200 
   `define REFRESH_CNT_MAX 405
   always @(posedge clk) begin
      if(state == 8'd51)
         r_refreshcnt <= 0;
      else
         `ifdef SIM_TNREFRESH
         if(state == 0 && i_rd_en)
         //if(state == 10 || state == 12)
            r_refreshcnt <= r_refreshcnt + 4;
         else if(state == 0 && i_wr_en)
         //if(state == 20 || state == 31 || state == 40 || state == 41 || state == 42)
            r_refreshcnt <= r_refreshcnt + 100;
         else
            r_refreshcnt <= r_refreshcnt + 1;
         `else
         r_refreshcnt <= r_refreshcnt + 1;
         `endif
   end
`endif

    always@(posedge clk) begin
    if(~rst_x) begin
`ifdef TN_DRAM_REFRESH
      read_request <= 0;
      write_request <= 0;
      r_late_refresh <= 0;
`endif
      state <= 0;
      state_next <= 0;
    end else
    case(state)
    8'd0: // idle
		if(i_rd_en && !w_busy) begin
         prepare_read;
      end else if(i_wr_en && !w_busy) begin
         prepare_write;
      end 
`ifdef TN_DRAM_REFRESH
      else if((r_refreshcnt > `REFRESH_CNT) && 
               //((sys_state != 5)) || ((sys_state == 5)  && (w_bus_cpustate == `S_OF)) &&
               !w_busy) begin
         // ram refresh
         prepare_refresh;
         if(r_refresh > `REFRESH_CNT_MAX)
            r_late_refresh <= 1;
      end
   8'd50: begin
      //if(!w_busy) begin
         if(read_request == 0 && i_rd_en) begin
            prepare_read_base;
            read_request <= 1;
         end else if(write_request == 0 && i_wr_en) begin
            prepare_write_base;
            write_request <= 1;
         end
      //end
		if(w_busy) begin
         r_refresh <= 0;
         state <= 51;
      end
   end
   8'd51: begin 
      if(w_busy) begin
         if(read_request == 0 && i_rd_en) begin
            prepare_read_base;
            read_request <= 1;
         end else if(write_request == 0 && i_wr_en) begin
            prepare_write_base;
            write_request <= 1;
         end
      end else begin
         if(read_request) begin
            read_request <= 0;
            prepare_read_end;
         end else if(write_request) begin
            write_request <= 0;
            prepare_write_end;
         end else if(i_rd_en)
            prepare_read;
         else if(i_wr_en)
            prepare_write;
         else begin
            //r_stall <= 0; // refresh does not set r_stall
            if(r_stall != 0)
               $display("TN_DRAM_REFRESH bug r_stall not null ------------");
            state <= 0;
         end
      end
   end
`endif // TN_DRAM_REFRESH
	8'd10: begin //mem read
		if(w_busy) begin
			r_rd <= 0;
         state <= 11;
		end
   end
	8'd11: begin
		if(!w_busy) begin
			r_dram_odata1 <= w_dram_odata;
			if((r_addr[1:0] == 0) || 
				(r_ctrl[1:0] == 0) || // lb
				((r_addr[1:0] <= 2) && (r_ctrl[1:0] == 1))) // lh
			begin
            // one read is enough
				state <= 100;
			end else begin
				state <= 12;
				r_rd <= 1;
				r_maddr <= r_maddr + 4;
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
			state_next <= 100;
      end else if(r_ctrl[1:0]==1) begin // SH
			if(r_addr[1:0] == 0) begin
				r_mask <= 4'b0011;
				r_wdata <= r_wdata_ui;
				state_next <= 100;
			end else if (r_addr[1:0] == 1) begin
				r_mask <= 4'b0110;
				r_wdata <= r_wdata_ui << 8;
				state_next <= 100;
			end else if (r_addr[1:0] == 2) begin
            r_mask <= 4'b1100;
            r_wdata <= r_wdata_ui << 16;
            state_next <= 100;
			end else if (r_addr[1:0] == 3) begin
				// write in two cycles.
            r_mask <= 4'b1000;
            r_wdata <= r_wdata_ui << 24;
            state_next <= 31;
			end
     end else if(r_ctrl[1:0]==2) begin // SW
			if(r_addr[1:0] == 0) begin
				r_mask <= 4'b1111;
				r_wdata <= r_wdata_ui;
            state_next <= 100;
			end else if(r_addr[1:0] == 1) begin
				// write in two cycles.
				r_mask <= 4'b1110;
				r_wdata <= r_wdata_ui << 8;
				state_next <= 40;
			end else if(r_addr[1:0] == 2) begin
				// write in two cycles.
				r_mask <= 4'b1100;
            r_wdata <= r_wdata_ui << 16;
            state_next <= 41;
			end else if(r_addr[1:0] == 3) begin
				// write in two cycles.
				r_mask <= 4'b1000;
            r_wdata <= r_wdata_ui << 24;
             state_next <= 42;
			end
     end
     r_we <= 1;
     state <= 21;
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
`endif // SIM_MODE

`ifdef SIM_MODE
`ifdef SIM_TNSRAM
    m_sdram_sim #(`MEM_SIZE) idbmem(.CLK(clk), .w_addr(r_maddr), .w_odata(w_dram_odata), 
        .w_we(r_we), .w_le(r_rd), .w_wdata(r_wdata), .w_mask(r_mask), .w_stall(w_busy), 
        .w_mtime(w_mtime[31:0]),
        `ifdef TN_DRAM_REFRESH
        .w_refresh(r_refresh)
        `else
        .w_refresh(0)
        `endif
        );
`else
    m_dram_sim #(`MEM_SIZE) idbmem(.CLK(clk), .w_addr(i_addr), .w_odata(o_data), 
        .w_we(i_wr_en), .w_le(i_rd_en), .w_wdata(i_data), .w_ctrl(i_ctrl), .w_stall(o_busy), 
        .w_mtime(w_mtime[31:0]));
`endif
`else
    MemoryController memory(.clk(clk), .clk_sdram(clk_sdram), .resetn(rst_x),
        .read_a(r_rd), 
        .read_b(1'b0),
        .write(r_we),
        .refresh(r_refresh),
        .addr(r_maddr),
        .din(r_wdata), .mask(~r_mask),
        .dout_a(w_dram_odata), .dout_b(),
        .busy(w_busy), .mem_initialized(o_init_calib_complete), .fail(sdram_fail), .total_written(),

        .SDRAM_DQ(IO_sdram_dq), .SDRAM_A(O_sdram_addr), .SDRAM_BA(O_sdram_ba), .SDRAM_nCS(O_sdram_cs_n),
        .SDRAM_nWE(O_sdram_wen_n), .SDRAM_nRAS(O_sdram_ras_n), .SDRAM_nCAS(O_sdram_cas_n), 
        .SDRAM_CLK(O_sdram_clk), .SDRAM_CKE(O_sdram_cke), .SDRAM_DQM(O_sdram_dqm)
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
    #1
`endif

        $write("Running %s\n", {`HEX_DIR,`HEXFILE});
        $readmemh({`HEX_DIR,`HEXFILE}, mem_bbl);
        j=0;

        for(i=0;i<`BBL_SIZE;i=i+1) begin
`ifdef DRAM_SIM
`ifdef SKIP_CACHE
        idbmem.idbmem.mem[j]=mem_bbl[i];
`else
	    idbmem.cache_ctrl.mi.mem[j]=mem_bbl[i];
`endif
`else
	    idbmem.idbmem.mem[j]=mem_bbl[i];
`endif // DRAM_SIM
            j=j+1;
        end
        $write("-------------------------------------------------------------------\n");
    end
`endif
endmodule
/**************************************************************************************************/

