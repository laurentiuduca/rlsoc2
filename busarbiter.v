`include "define.vh"

module busarbiter(
    input wire CLK, RST_X, output wire [31:0] w_grant,
    input wire w_init_done, input wire w_proc_busy,
    input wire [31:0] w_mem_paddr, input wire w_mem_we,
    output wire [31:0] w_data_wdata, input wire [31:0] w_data_data,
    output wire [63:0] w_mtime, output wire [63:0] w_mtimecmp, input wire [63:0] w_wmtimecmp, input wire w_clint_we,
    output wire [1:0]  w_tlb_req, output wire        w_tlb_busy,
    output wire [31:0] w_mip, input wire [31:0] w_wmip, input w_plic_we,
    output wire [31:0] w_dram_addr, output wire [31:0] w_dram_wdata, input wire [31:0] w_dram_odata, output w_dram_we_t,
    input wire w_dram_busy, output wire [2:0] w_dram_ctrl, output w_dram_le,

    output wire bus_proc_busy[0:`NCORES-1],
    input wire [31:0] bus_mem_paddr[0:`NCORES-1], input wire bus_mem_we[0:`NCORES-1],
    input wire [31:0] bus_data_wdata[0:`NCORES-1], 
    output wire [31:0] bus_data_data[0:`NCORES-1],
    input [63:0] bus_mtime[0:`NCORES-1], bus_mtimecmp[0:`NCORES-1], 
    output [63:0] bus_wmtimecmp[0:`NCORES-1], output wire bus_clint_we[0:`NCORES-1],
    input wire [2:0] bus_pw_state[0:`NCORES-1], input wire [1:0] bus_tlb_req[0:`NCORES-1], input wire bus_tlb_busy[0:`NCORES-1],
    input [31:0] bus_mip[0:`NCORES-1], output [31:0] bus_wmip[0:`NCORES-1], output wire bus_plic_we[0:`NCORES-1],
    input [31:0] bus_dram_addr[0:`NCORES-1], input [31:0] bus_dram_wdata[0:`NCORES-1], output [31:0] bus_dram_odata[0:`NCORES-1], input bus_dram_we_t[0:`NCORES-1],
    output bus_dram_busy[0:`NCORES-1], input wire [2:0] bus_dram_ctrl[0:`NCORES-1], input bus_dram_le[0:`NCORES-1]
    );

    /**********************************************************************************************/
    assign w_grant=r_grant;

    reg [31:0] r_grant=0; // bus granted core

    always @(posedge CLK) begin /////// update program counter
        if(!RST_X) begin

        end
    end

endmodule