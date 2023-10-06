// nand2mario, 2022.10
// 

`include "define.vh"

`default_nettype none

module MemoryController(
    input wire clk,                // Main logic clock
    input wire clk_sdram,          // 180-degree of clk
    input wire resetn,
    input wire read_a,             // Set to 1 to read from RAM
    input wire read_b,             // Set to 1 to read from RAM
    input wire write,              // Set to 1 to write to RAM
    input wire refresh,            // Set to 1 to auto-refresh RAM
    input wire [22:0] addr,        // Address to read / write
    input wire [31:0] din,          // Data to write
    input wire [3:0] mask,
    output wire [31:0] dout_a,      // Last read data a, available 4 cycles after read_a is set
    output wire [31:0] dout_b,      // Last read data b, available 4 cycles after read_b is set
    output reg busy,          // 1 while an operation is in progress
    output reg mem_initialized,

    // debug interface
    output reg fail,          // timing mistake or sdram malfunction detected
    output reg [19:0] total_written,

    // Physical SDRAM interface
	inout  wire [31:0] SDRAM_DQ,   // 16 bit bidirectional data bus
	output wire [10:0] SDRAM_A,    // 13 bit multiplexed address bus
	output wire [1:0] SDRAM_BA,   // 4 banks
	output wire SDRAM_nCS,  // a single chip select
	output wire SDRAM_nWE,  // write enable
	output wire SDRAM_nRAS, // row address select
	output wire SDRAM_nCAS, // columns address select
	output wire SDRAM_CLK,
	output wire SDRAM_CKE,
    output wire [3:0] SDRAM_DQM
);

reg [22:0] MemAddr;
reg MemRD, MemWR, MemRefresh, MemInitializing;
reg [31:0] MemDin;
wire [31:0] MemDout;
reg [7:0] cycles;
reg r_read_a, r_read_b;
reg [31:0] da, db;
wire MemBusy, MemDataReady;

assign dout_a = da;
assign dout_b = db;

// SDRAM driver
sdram #(
    .FREQ(`FREQ)
) u_sdram (
    .clk(clk), .clk_sdram(clk_sdram), .resetn(resetn),
	.addr(MemAddr), .rd(MemRD), 
    .wr(MemWR), .refresh(MemRefresh),
    .mask(mask),
	.din(busy ? MemDin : din), .dout(MemDout), .busy(MemBusy), .data_ready(MemDataReady),

    .SDRAM_DQ(SDRAM_DQ), .SDRAM_A(SDRAM_A), .SDRAM_BA(SDRAM_BA), 
    .SDRAM_nCS(SDRAM_nCS), .SDRAM_nWE(SDRAM_nWE), .SDRAM_nRAS(SDRAM_nRAS),
    .SDRAM_nCAS(SDRAM_nCAS), .SDRAM_CLK(SDRAM_CLK), .SDRAM_CKE(SDRAM_CKE),
    .SDRAM_DQM(SDRAM_DQM)
);

always @(posedge clk) begin
    cycles <= cycles == 255 ? 255 : cycles + 1;
    
    if(MemBusy) begin
        MemWR <= 1'b0; MemRD <= 1'b0; MemRefresh <= 1'b0;
    end else
    // Initiate read or write
    if (!busy) begin
        if (read_a || read_b || write || refresh) begin
            MemAddr <= addr;
            MemWR <= write;
            MemRD <= (read_a || read_b);
            MemRefresh <= refresh;
            busy <= 1'b1;
            MemDin <= din;
            cycles <= 1;
            r_read_a <= read_a;
            r_read_b <= read_b;
        end 
    end else if (MemInitializing) begin
        if (~MemBusy) begin
            // initialization is done
            MemInitializing <= 1'b0;
            mem_initialized <= 1;
            busy <= 1'b0;
        end
    end else begin
        // Wait for operation to finish and latch incoming data on read.
        if (cycles == 255 && !MemBusy && 
            (((r_read_a || r_read_b) && MemDataReady) || !(r_read_a || r_read_b)))  begin
            busy <= 0;
            if (r_read_a || r_read_b) begin
                if (~MemDataReady)      // assert data ready
                    fail <= 1'b1;
                if (r_read_a) 
                    da <= MemDout;
                if (r_read_b)
                    db <= MemDout;
                r_read_a <= 1'b0;
                r_read_b <= 1'b0;
            end
        end
    end

    if (~resetn) begin
        busy <= 1'b1;
        fail <= 1'b0;
        total_written <= 0;
        MemInitializing <= 1'b1;
        mem_initialized <= 0;
    end
end


endmodule
