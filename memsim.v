`include "define.vh"

/**************************************************************************************************/
/**** Byte unit BRAM Main Memory module with LATENCY for simulation (1-port)                   ****/
/**************************************************************************************************/
`ifdef DRAM_SIM
module m_bu_mem #(parameter MEM_SIZE = `MEM_SIZE)
            (CLK, w_addr, w_odata, w_we, w_le, w_wdata, w_ctrl, w_stall, w_mask);
    input  wire             CLK;
    input  wire [31:0] w_addr;
    output wire [127:0] w_odata;
    input  wire w_we, w_le;
    input  wire [31:0] w_wdata;
    input  wire [2:0] w_ctrl;
    output wire w_stall;
    // active 0 mask
    input wire [3:0] w_mask;

    reg   [7:0] mem [0:MEM_SIZE-1];

    reg [7:0] state=0;
    reg r_stall=0;
    assign w_stall = r_stall;
    reg [31:0] r_addr;
    reg [31:0] r_wdata;
    reg [127:0] r_odata=0, r_odata_aux=0;
    reg [3:0] r_mask;
    assign w_odata=r_odata;
    reg [7:0] r_cnt;
    `ifdef RAM_DEBUG
    reg r_was_read=0, r_was_write=0;
    reg r_last_addr=1;
    reg [31:0] rd_cnt=20;
    `endif
    always @(posedge CLK) begin
	case(state)
	8'd0: begin // idle
		if(w_le) begin
                        state <= 10;
                        r_stall <= 1;
                        r_addr <= w_addr;
			r_odata_aux <= 
			   {mem[w_addr+15], mem[w_addr+14], mem[w_addr+13], mem[w_addr+12],
                            mem[w_addr+11], mem[w_addr+10], mem[w_addr+9],  mem[w_addr+8],
                            mem[w_addr+7],  mem[w_addr+6],  mem[w_addr+5],  mem[w_addr+4],
                            mem[w_addr+3],  mem[w_addr+2],  mem[w_addr+1],  mem[w_addr+0]};
                end else if(w_we) begin
                        state <= 20;
                        r_stall <= 1;
                        r_addr <= w_addr;
                        r_wdata <= w_wdata;
			r_mask <= w_mask;
                end
	end
	8'd10: begin
		r_odata <= r_odata_aux;
		`ifdef RAM_DEBUG
		r_was_read <= 1;
                `endif
		r_cnt <= 0;
		state <= 100;
	end
	8'd20: begin
		if(!r_mask[0]) begin
			mem[r_addr] <= r_wdata;
		end
		if(!r_mask[1]) begin
			mem[r_addr+1] <= r_wdata >> 8;
		end
		if(!r_mask[2]) begin
                        mem[r_addr+2] <= r_wdata >> 16;
		end
		if(!r_mask[3]) begin
                        mem[r_addr+3] <= r_wdata >> 24;
		end
		`ifdef RAM_DEBUG
		r_was_write <= 1;
		`endif
		r_cnt <= 0;
		state <= 100;
	end
	8'd100: begin
		if(r_cnt <= `LATENCY)
			r_cnt <= r_cnt + 1;
		else begin
			`ifdef RAM_DEBUG
			rd_cnt <= rd_cnt + 1;
			if(rd_cnt < 20) begin
				if(r_was_read && (r_last_addr != r_addr))
					$display("RAM read: mem[%x] is %x", r_addr, r_odata);
				if(r_was_write && (r_last_addr != r_addr))
					$display("RAM write: mem[%x] <= %x", r_addr, {mem[r_addr+3], mem[r_addr+2], mem[r_addr+1], mem[r_addr]});
			end
			`endif
			state <= 110;
		end
	end
	8'd110: begin
		`ifdef RAM_DEBUG
		r_was_read <= 0;
		r_was_write <= 0;
		r_last_addr <= r_addr;
		`endif
		state <= 0;
		r_stall <= 0;
	end
	endcase
    end

endmodule

/**************************************************************************************************/
/**** BRAM Wrapper for simulation (1-port)                                                     ****/
/**************************************************************************************************/
// template from memory.v
module m_dram_sim#(parameter MEM_SIZE = `MEM_SIZE)(
     input wire                         o_clk,
     input  wire [31:0]                  i_addr,
     output wire [31:0]                  o_data,
     input  wire                         i_wr_en,
     input  wire                         i_rd_en,
     input  wire [31:0]                  i_data,
     input  wire [2:0]                   i_ctrl,
     output wire                         o_busy,
     input wire [31:0]                   w_mtime);

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

    // 16+3 bytes shifted with r_addr[3:0]*8 bits
    wire[151:0] w_odata_aux = {r_dram_odata2, r_dram_odata1} >> {r_addr[3:0], 3'b0};
    wire[31:0] w_odata = w_odata_aux[31:0];
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
    `ifdef RAM_DEBUG
    reg r_was_read=0, r_was_write=0;
    reg [31:0] rd_cnt=20;
    `endif
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
			`ifdef RAM_DEBUG
			r_was_read <= 1;
			`endif
                end else if(i_wr_en && !w_busy) begin
			state <= 20;
                        r_stall <= 1;
			r_addr <= i_addr;
                        r_maddr <= {i_addr[31:2], 2'b0};
                        r_wdata_ui <= (i_ctrl[1:0] == 0) ? {24'h0, i_data[7:0]} :
                                   (i_ctrl[1:0] == 1) ? {16'h0, i_data[15:0]} : i_data;
                        r_ctrl <= i_ctrl;
			`ifdef RAM_DEBUG
			r_was_write <= 1;
			`endif
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
		`ifdef RAM_DEBUG
		r_was_read <= 0;
		r_was_write <= 1;
`ifdef SKIP_CACHE
		if(r_was_read && (w_odata != {idbmem.mem[r_addr+3], idbmem.mem[r_addr+2], idbmem.mem[r_addr+1], idbmem.mem[r_addr]}))
			$display("MEM BUG: r_addr=%x w_odata=%x != %x", r_addr, w_odata, {idbmem.mem[r_addr+3], idbmem.mem[r_addr+2], idbmem.mem[r_addr+1], idbmem.mem[r_addr]});
`else
`endif
		`endif
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

`ifdef SKIP_CACHE 
    m_bu_mem#(MEM_SIZE) mi(.CLK(o_clk), .w_addr(r_maddr), .w_odata(w_dram_odata),
                               .w_we(r_we), .w_le(r_rd), .w_wdata(r_wdata), .w_ctrl(r_ctrl), .w_stall(w_busy), .w_mask(~r_mask));
`else
    cache_ctrl#(MEM_SIZE) cache_ctrl(.o_clk(o_clk), .i_rd_en(r_rd), .i_wr_en(r_we), .i_addr(r_maddr), .i_data(r_wdata), 
				     .o_data(w_dram_odata), .o_busy(w_busy), .i_mask(r_mask), .w_mtime(w_mtime));
`endif // SKIP_CACHE
endmodule
/**************************************************************************************************/

/**** Memory Controller with Cache                                                             ****/

/**************************************************************************************************/

module cache_ctrl#(parameter MEM_SIZE = `MEM_SIZE)(
     // on FPGA, o_clk is output
     input wire                         o_clk,
     // user interface ports
     input  wire                         i_rd_en,
     input  wire                         i_wr_en,
     input  wire [31:0]                  i_addr,
     input  wire [31:0]                  i_data,
     output wire[127:0]                  o_data,
     output wire                         o_busy,
     input  wire [3:0]                   i_mask,
     input wire [31:0]                   w_mtime);

    /***** store output data to registers in posedge clock cycle *****/
    reg   [1:0] r_cache_state = 0;

    reg  [31:0] r_addr = 0;
    reg   [2:0] r_ctrl = 0;
    reg [127:0] r_o_data = 0;

    // DRAM
    wire        w_dram_stall;
    wire        w_dram_le;
    wire [31:0] w_dram_addr = (i_wr_en) ? i_addr : r_addr;
    wire[127:0] w_dram_odata;

    // Cache
    wire        c_oe;
    wire        c_clr   = (r_cache_state == 2'b11 && c_oe);
    wire        c_we    = (r_cache_state == 2'b10 && !w_dram_stall);
    wire [31:0] c_addr  = (r_cache_state == 2'b00) ? i_addr : r_addr;
    wire[127:0] c_idata = w_dram_odata;
    wire[127:0] c_odata;
`ifdef CACHE_DEBUG
    // evaluation
    reg  hit_rate_shown=0;
    reg         e_test=1;
    reg  [31:0] e_data;
    reg  [63:0] e_cnt = 0;
    reg  [63:0] e_hit = 0;
`endif
    /*
    cache states:
        2'b00=idle,
        (2'b01=read && c_oe)=read made in c_odata,
        2'b10=cache read miss;
        2'b11=write

    */
    always@(posedge o_clk) begin
        if(r_cache_state == 2'b01 && !c_oe) begin
            r_cache_state <= 2'b10;
`ifdef CACHE_DEBUG
	    e_test <= c_oe;
            e_data <= c_odata;
`endif
        end
        else if(r_cache_state == 2'b11 || (r_cache_state == 2'b01 && c_oe)
                || (r_cache_state == 2'b10 && !w_dram_stall)) begin
            r_cache_state <= 2'b00;
            r_o_data <= (r_cache_state == 2'b01) ? c_odata : w_dram_odata;
`ifdef CACHE_DEBUG
	    if(r_cache_state == 2'b01 && c_oe) begin
                e_hit <= e_hit + 1;
            end
	    // CACHE DATA CHECK
            if(r_cache_state!=2'b11 && e_test) begin
                if(e_data != w_dram_odata) begin
                    $write("%d: CACHE DATA WRONG!!, ADDR:%x DATA%x %x\n",
                            w_mtime, r_addr, w_dram_odata, e_data);
                    $finish();
                end
            end
`endif
        end
        else if(i_wr_en) begin
            r_cache_state <= 2'b11;
            r_addr <= i_addr;
        end
        else if(i_rd_en) begin
            r_cache_state <= 2'b01;
            r_addr <= i_addr;
`ifdef CACHE_DEBUG
	    e_cnt           <= e_cnt + 1;
`endif
        end
`ifdef CACHE_DEBUG
`ifdef laur0
	if((w_mtime == 500000) && (!hit_rate_shown)) begin
	    hit_rate_shown = 1;
            $write("Cache hit rate: cnt = %d, hit = %d\n", e_cnt, e_hit);
            $write("\thit rate = %f\n", 1.0*e_hit/e_cnt);
        end
`endif
`endif
    end

    m_dram_cache#(28,128,`CACHE_SIZE/16) cache(o_clk, 1'b1, 1'b0, c_clr, c_we,
                                c_addr[31:4], c_idata, c_odata, c_oe);

    assign w_dram_le = (r_cache_state == 2'b01 && !c_oe);
    assign o_busy = w_dram_stall || r_cache_state != 0;

    assign o_data = r_o_data;

    m_bu_mem#(MEM_SIZE) mi(.CLK(o_clk), .w_addr(w_dram_addr), .w_odata(w_dram_odata),
                               .w_we(i_wr_en), .w_le(w_dram_le), .w_wdata(i_data), .w_ctrl(r_ctrl), .w_stall(w_dram_stall), .w_mask(~i_mask));
endmodule
`else
// simplest memory model
/**************************************************************************************************/
/**** Byte unit BRAM Main Memory module with LATENCY for simulation (1-port)                   ****/
/**************************************************************************************************/
module m_bu_mem #(parameter MEM_SIZE = `MEM_SIZE)
            (CLK, w_addr, w_odata, w_we, w_le, w_wdata, w_ctrl, w_stall);
    input  wire             CLK;
    input  wire [`XLEN-1:0] w_addr;
    output wire [`XLEN-1:0] w_odata;
    input  wire             w_we, w_le;
    input  wire [`XLEN-1:0] w_wdata;
    input  wire       [2:0] w_ctrl;
    output wire             w_stall;

    reg   [2:0] r_ctrl  = 0;
    reg  [31:0] r_addr  = 0;
    reg  [31:0] r_cnt   = 0;

    reg   [7:0] mem [0:MEM_SIZE-1];
    reg [`XLEN-1:0] r_odata = 0;

    assign w_odata = (r_ctrl[1:0]==0) ? ((r_ctrl[2]) ? {24'h0, r_odata[7:0]} :
                                         {{24{r_odata[7]}}, r_odata[7:0]}) :
                     (r_ctrl[1:0]==1) ? ((r_ctrl[2]) ? {16'h0, r_odata[15:0]} :
                                         {{16{r_odata[15]}}, r_odata[15:0]}) :
                     r_odata;

    reg r_stall=0;
    assign w_stall = r_stall;
    reg [`XLEN-1:0] r_maddr;
    // Select Write DATA
    wire [7:0] w_data3, w_data2, w_data1, w_data0;
    reg [31:0] r_wdata=0;
    assign {w_data3, w_data2, w_data1, w_data0} = r_wdata;
    reg [7:0] state = 0;
    always@(posedge CLK) begin
        case(state)
        8'd0: // idle
                if(w_le) begin
                        state <= 1;
                        r_stall <= 1;
                        r_maddr <= w_addr;
			r_ctrl <= w_ctrl;
                end else if(w_we) begin
                        state <= 2;
                        r_stall <= 1;
                        r_maddr <= w_addr;
                        r_wdata <= (w_ctrl[1:0] == 0) ? {24'h0, w_wdata[7:0]} :
                                   (w_ctrl[1:0] == 1) ? {16'h0, w_wdata[15:0]} : w_wdata;
                        r_ctrl <= w_ctrl;
                end
        8'd1: begin // mem read
		r_odata <= {mem[r_maddr+3], mem[r_maddr+2], mem[r_maddr+1], mem[r_maddr+0]};
		//state <= 11; // 10
		//r_cnt <= 0;
		state <= 0;
                r_stall <= 0;
	end 
	8'd10: begin
		if(r_cnt <= `LATENCY)
			r_cnt <= r_cnt + 1;
		else 
			state <= 11;
	end 
	8'd11: begin
                state <= 0;
                r_stall <= 0;
        end 
	8'd2: begin // mem write
                //r_odata <= {mem[r_maddr+3], mem[r_maddr+2], mem[r_maddr+1], mem[r_maddr+0]};
		//r_odata <= r_wdata;
		if(r_ctrl[1:0]==0) begin // SB
                                mem[r_maddr] <= w_data0;
                end else if(r_ctrl[1:0]==1) begin // SH
                                mem[r_maddr] <= w_data0;
                                mem[r_maddr+1] <= w_data1;
                end else if(r_ctrl[1:0]==2) begin // SW
                                mem[r_maddr  ] <= w_data0;
                                mem[r_maddr+1] <= w_data1;
                                mem[r_maddr+2] <= w_data2;
                                mem[r_maddr+3] <= w_data3;
                end
		//r_cnt <= 0;
		//state <= 11; // 10
		state <= 0;
                r_stall <= 0;
	end
        endcase
    end
endmodule
/**************************************************************************************************/
/**** BRAM Wrapper for simulation (1-port)                                                     ****/
/**************************************************************************************************/
module m_dram_sim#(parameter MEM_SIZE = `MEM_SIZE)
            (CLK, w_addr, w_odata, w_we, w_le, w_wdata, w_ctrl, w_stall, w_mtime);
    input  wire             CLK;
    input  wire [`XLEN-1:0] w_addr;
    output wire [`XLEN-1:0] w_odata;
    input  wire             w_we, w_le;
    input  wire [`XLEN-1:0] w_wdata;
    input  wire       [2:0] w_ctrl;
    output wire             w_stall;
    input  wire      [31:0] w_mtime;

    m_bu_mem#(MEM_SIZE) mi(CLK, w_addr, w_odata,
                                w_we, w_le, w_wdata, w_ctrl, w_stall);

endmodule
`endif // DRAM_SIM

