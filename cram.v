`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:28:41 10/25/2022 
// Design Name: 
// Module Name:    cram 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
`include "define.vh"

module cram(
	// cram signals
	output wire [`CRAM_ADDR_SIZE:1] cram_addr,
	output wire cram_clk,
	inout wire [`CRAM_DATA_SIZE-1:0] cram_data,
	output wire cram_adv, 
	output wire cram_cre, output wire cram_ce, output wire cram_oe,
	output wire cram_we, output wire cram_lb, output wire cram_ub,
	inout wire cram_wait,
	// our interface
	input wire clk,
	input wire read_a, 
	input wire write,
	input wire [22:0] addr,
	input wire [31:0] din, 
	input wire [3:0] mask, //0=active
	output reg [31:0] dout_a,
   output reg busy
   );

   reg [7:0] r_state=0;
	reg [7:0] r_cnt=0;
	reg [3:0] r_mask=0;
	reg [31:0] r_din=0;

	// block ram signals
	reg [`CRAM_ADDR_SIZE-1:0] addr_i;
`define NOP 2'b00
`define READ 2'b10
`define WRITE 2'b01
	reg [1:0] cfg_rw_i; // read (10) or write (01)
	wire finish;
	reg thx=0;
	reg [`CRAM_DATA_SIZE-1:0] data_i;
	reg go_i=0;
	reg lb_i=0, ub_i=0; // 1 inactive, 0 active. use ub_i for writing garbage
	wire busy_o;
	reg r_wait_busy=0;
	wire [`CRAM_DATA_SIZE-1:0] data_o;

	
	MemoryController mi(
		// These pins are used to talk to the celular ram  (memory_interface <--> cellular_ram);
		.memcntrl_ram_adr(cram_addr), .memcntrl_ram_clk(cram_clk), 
		.memcntrl_ram_adv(cram_adv), .memcntrl_ram_cre(cram_cre),
		.memcntrl_ram_ce(cram_ce), .memcntrl_ram_oe(cram_oe), .memcntrl_ram_we(cram_we),
		.memcntrl_ram_lb(cram_lb), .memcntrl_ram_ub(cram_ub),
		.memcntrl_ram_data(cram_data), .memcntrl_ram_wait(cram_wait),
		// These are the pins used to help interface the memory as if it were a block ram ( some module <--> memory_interface);
		.memcntrl_adr(addr_i), .memcntrl_cfg_rw(cfg_rw_i), .memcntrl_data_in(data_i), .memcntrl_data_out(data_o), .memcntrl_clk(clk), 
		.memcntrl_cfg_busy(busy_o), .memcntrl_cfg_finish(finish), .memcntrl_cfg_thx(thx), .memcntrl_cfg_state(),
		.lb_i(lb_i), .ub_i(ub_i));
		
	always @(posedge clk)
	begin
		case (r_state)
		0: begin
			thx <= 0;
			if (read_a || write) begin
				addr_i <= addr;
				r_din <= din;
				r_mask <= mask;
				lb_i <= mask[0];
				if(read_a) begin
					dout_a <= 0;
					r_state <= 10;
					cfg_rw_i <= `READ;
				end else begin // write
					r_state <= 20;
					cfg_rw_i <= `WRITE;
					data_i = {8'h0, din[7:0]};
					r_din <= din;
				end
				r_wait_busy <= 1;
				r_cnt <= 0;
				busy <= 1;
			end else begin
				lb_i <= 1;
				cfg_rw_i <= `NOP;
			end
		end
		10: begin
			if(busy_o) begin
				// should at least read ub_i
				cfg_rw_i <= `NOP;
				r_wait_busy <= 0;
				if(finish)
					thx <= 1;
				else
					thx <= 0;
			end else if(r_wait_busy == 0) begin
				thx <= 0;
				lb_i <= r_mask[1];
				if(r_mask[0])
					dout_a <= {8'h0, dout_a[31:8]};
				else
					dout_a <= {data_o[7:0], dout_a[31:8]};
				r_wait_busy <= 1;
				r_mask <= {1'b1, r_mask[3:1]};
				addr_i <= addr_i + 1;
				r_cnt <= r_cnt + 1;
				if(r_cnt == 3) begin
					// we have read 4 octets
					r_state <= 0;
					busy <= 0;
					r_cnt <= 0;
					cfg_rw_i <= `NOP;
					lb_i <= 1;
				end else
					cfg_rw_i <= `READ;
			end
		end
		20: begin
			if(busy_o) begin
				// should at least write ub_i
				cfg_rw_i <= `NOP;
				r_wait_busy <= 0;
				if(finish)
					thx <= 1;
				else
					thx <= 0;
			end else if(r_wait_busy == 0) begin
				thx <= 0;
				data_i = {8'h0, r_din[15:8]};
				r_din <= {8'h0, r_din[31:8]};
				lb_i <= r_mask[1];
				r_wait_busy <= 1;
				r_mask <= {1'b1, r_mask[3:1]};
				addr_i <= addr_i + 1;
				r_cnt <= r_cnt + 1;
				if(r_cnt == 3) begin
					// we have written 4 octets
					r_state <= 0;
					busy <= 0;
					r_cnt <= 0;
					lb_i <= 1;
					cfg_rw_i <= `NOP;
				end else
					cfg_rw_i <= `WRITE;
			end
		end
		endcase
	end

endmodule
