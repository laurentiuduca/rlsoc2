// nand2mario, 2022.10
// 

module MemoryController(
    input clk,                // Main logic clock
    input clk_sdram,          // 180-degree of clk
    input resetn,
    input read_a,             // Set to 1 to read from RAM
    input read_b,             // Set to 1 to read from RAM
    input write,              // Set to 1 to write to RAM
    input refresh,            // Set to 1 to auto-refresh RAM
    input [22:0] addr,        // Address to read / write
    input [31:0] din,          // Data to write
    input [3:0] mask,
    output [31:0] dout_a,      // Last read data a, available 4 cycles after read_a is set
    output [31:0] dout_b,      // Last read data b, available 4 cycles after read_b is set
    output reg busy,          // 1 while an operation is in progress
    output reg mem_initialized,

    // debug interface
    output reg fail,          // timing mistake or sdram malfunction detected
    output reg [19:0] total_written,

    // Physical SDRAM interface
	inout  [31:0] SDRAM_DQ,   // 16 bit bidirectional data bus
	output [10:0] SDRAM_A,    // 13 bit multiplexed address bus
	output [1:0] SDRAM_BA,   // 4 banks
	output SDRAM_nCS,  // a single chip select
	output SDRAM_nWE,  // write enable
	output SDRAM_nRAS, // row address select
	output SDRAM_nCAS, // columns address select
	output SDRAM_CLK,
	output SDRAM_CKE,
    output [3:0] SDRAM_DQM
);

reg [22:0] MemAddr;
reg MemRD, MemWR, MemRefresh, MemInitializing;
reg [31:0] MemDin;
wire [31:0] MemDout;
reg [2:0] cycles;
reg r_read_a, r_read_b;
reg [31:0] da, db;
wire MemBusy, MemDataReady;

assign dout_a = (cycles == 3'd4 && r_read_a) ? MemDout : da;
assign dout_b = (cycles == 3'd4 && r_read_b) ? MemDout : db;

localparam FREQ=27_000_000;

// SDRAM driver
sdram #(
    .FREQ(FREQ)
) u_sdram (
    .clk(clk), .clk_sdram(clk_sdram), .resetn(resetn),
	.addr(busy ? MemAddr : addr), .rd(busy ? MemRD : (read_a || read_b)), 
    .wr(busy ? MemWR : write), .refresh(busy ? MemRefresh : refresh),
    .mask(mask),
	.din(busy ? MemDin : din), .dout(MemDout), .busy(MemBusy), .data_ready(MemDataReady),

    .SDRAM_DQ(SDRAM_DQ), .SDRAM_A(SDRAM_A), .SDRAM_BA(SDRAM_BA), 
    .SDRAM_nCS(SDRAM_nCS), .SDRAM_nWE(SDRAM_nWE), .SDRAM_nRAS(SDRAM_nRAS),
    .SDRAM_nCAS(SDRAM_nCAS), .SDRAM_CLK(SDRAM_CLK), .SDRAM_CKE(SDRAM_CKE),
    .SDRAM_DQM(SDRAM_DQM)
);

always @(posedge clk) begin
    MemWR <= 1'b0; MemRD <= 1'b0; MemRefresh <= 1'b0;
    cycles <= cycles == 3'd7 ? 3'd7 : cycles + 3'd1;
    
    // Initiate read or write
    if (!busy) begin
        if (read_a || read_b || write || refresh) begin
            MemAddr <= addr;
            MemWR <= write;
            MemRD <= (read_a || read_b);
            MemRefresh <= refresh;
            busy <= 1'b1;
            MemDin <= din;
            cycles <= 3'd1;
            r_read_a <= read_a;
            r_read_b <= read_b;

            if (write) total_written <= total_written + 1;
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
        if (cycles == 3'd4) begin
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
