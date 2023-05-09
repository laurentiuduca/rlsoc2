`include "define.vh"

module busarbiter(
    // here we do not keep the w_ notation for wire
    input wire CLK, RST_X, output wire [31:0] w_grant,
    input wire w_init_done, input wire w_tx_ready,
    output wire [31:0] w_mem_paddr, output wire w_mem_we,
    output wire [31:0] w_data_wdata, input wire [31:0] w_data_data,
    output wire [63:0] w_mtimecmp, input wire [63:0] w_wmtimecmp, input wire w_clint_we,
    output wire [1:0]  w_tlb_req, output wire w_tlb_busy,
    output wire [31:0] w_mip, input wire [31:0] w_wmip, input wire w_plic_aces, input wire r_plic_aces_t, input wire w_plic_we,
    output wire [31:0] w_dram_addr, output wire [31:0] w_dram_wdata, input wire [31:0] w_dram_odata, output wire w_dram_we_t,
    input wire w_dram_busy, output wire [2:0] w_dram_ctrl, output wire w_dram_le,

    input wire [31:0] bus_core_ir0,
    input wire [31:0] bus_mem_paddr0, input wire bus_mem_we0,
    input wire [31:0] bus_data_wdata0, 
    output reg [31:0] bus_data_data0=0,
    input [63:0] bus_mtimecmp0, 
    output reg [63:0] bus_wmtimecmp0=0, output reg bus_clint_we0=0,
    input wire [2:0] bus_pw_state0, input wire [1:0] bus_tlb_req0, input wire bus_tlb_busy0,
    input [31:0] bus_mip0, output reg [31:0] bus_wmip0=0, output reg bus_plic_we0=0,
    input [31:0] bus_dram_addr0, input [31:0] bus_dram_wdata0, output reg [31:0] bus_dram_odata0=0, input bus_dram_we_t0,
    output reg bus_dram_busy0=0, input wire [2:0] bus_dram_ctrl0, input bus_dram_le0,

    input wire [31:0] bus_core_ir1,
    input wire [31:0] bus_mem_paddr1, input wire bus_mem_we1,
    input wire [31:0] bus_data_wdata1, 
    output reg [31:0] bus_data_data1=0,
    input [63:0] bus_mtimecmp1, 
    output reg [63:0] bus_wmtimecmp1=0, output reg bus_clint_we1=0,
    input wire [2:0] bus_pw_state1, input wire [1:0] bus_tlb_req1, input wire bus_tlb_busy1,
    input [31:0] bus_mip1, output reg [31:0] bus_wmip1=0, output reg bus_plic_we1=0,
    input [31:0] bus_dram_addr1, input [31:0] bus_dram_wdata1, output reg [31:0] bus_dram_odata1=0, input bus_dram_we_t1,
    output reg bus_dram_busy1=0, input wire [2:0] bus_dram_ctrl1, input bus_dram_le1
    );
    /**********************************************************************************************/
    
    reg [31:0] grant=0; // bus granted core
    assign w_grant=grant;

    reg [7:0] state=0;
    integer i;
    reg [7:0] cnt=0;
    
    wire a_w_dram_busy = (state == 0) ? w_dram_busy :
                         (state == 1) ? 1 : 
                         (state == 2) ? 1 : w_dram_busy;

    wire no_req = !w_dram_busy && 
                    !w_mem_we && !w_dram_le && !w_dram_we_t && 
                    !w_plic_aces && !r_plic_aces_t &&
                    (w_core_ir[6:0] != `OPCODE_AMO_____);

    always @(posedge CLK) begin
        if(!RST_X) begin
            grant <= 0;
            cnt <= 0;
        end else if(w_init_done) begin
            if(state == 0) begin
                if(no_req) begin
                    state <= 1;
                end
            end else if(state == 1) begin
                if(w_plic_aces)
                    state <= 0;
                else begin
                    // must signal busy to the core
                    grant <= (grant + 1) & (`NCORES-1);
                    state <= 2;
                end
            end else if(state == 2) begin
                // grant has just changed so signal busy to the new core
                state <= 3;
                cnt <= 0;
            end else if(state == 3) begin
                // allow this core to execute its instruction
                /* verilator lint_off UNSIGNED */
                if(cnt < 10)
                    cnt <= cnt + 1;
                else
                    state <= 0;
            end

        end
    end

    always @(*) begin
        if(grant == 0) begin
            bus_data_data0  = w_data_data;
            bus_wmtimecmp0  = w_wmtimecmp;
            bus_clint_we0 <= w_clint_we;
            bus_wmip0 <= w_wmip; bus_plic_we0 <= w_plic_we;
            bus_dram_odata0 = w_dram_odata;
            bus_dram_busy0  = a_w_dram_busy;
            
            bus_data_data1  = 0;
            bus_wmtimecmp1  = 0;
            bus_clint_we1 <= 0;
            bus_wmip1 <= 0; bus_plic_we1 <= 0;
            bus_dram_odata1 = 0;
            bus_dram_busy1  = 1;            
        end else begin
            bus_data_data1  = w_data_data;
            bus_wmtimecmp1  = w_wmtimecmp;
            bus_clint_we1 <= w_clint_we;
            bus_wmip1 <= w_wmip; bus_plic_we1 <= w_plic_we;
            bus_dram_odata1 = w_dram_odata;
            bus_dram_busy1  = a_w_dram_busy;
            
            bus_data_data0  = 0;
            bus_wmtimecmp0  = 0;
            bus_clint_we0 <= 0;
            bus_wmip0 <= 0; bus_plic_we0 <= 0;
            bus_dram_odata0 = 0;
            bus_dram_busy0  = 1;
        end
    end

    assign w_mem_paddr  = grant == 0 ? bus_mem_paddr0 : bus_mem_paddr1;
    assign w_mem_we     = grant == 0 ? bus_mem_we0 : bus_mem_we1;
    assign w_data_wdata = grant == 0 ? bus_data_wdata0 : bus_data_wdata1;
    assign w_mtimecmp   = grant == 0 ? bus_mtimecmp0 : bus_mtimecmp1;
    assign w_tlb_req    = grant == 0 ? bus_tlb_req0 : bus_tlb_req1;
    assign w_tlb_busy   = grant == 0 ? bus_tlb_busy0 : bus_tlb_busy1;
    assign w_mip        = grant == 0 ? bus_mip0 : bus_mip1;
    assign w_dram_addr  = grant == 0 ? bus_dram_addr0 : bus_dram_addr1;
    assign w_dram_wdata = grant == 0 ? bus_dram_wdata0 : bus_dram_wdata1;
    assign w_dram_we_t  = grant == 0 ? bus_dram_we_t0 : bus_dram_we_t1;
    assign w_dram_ctrl  = grant == 0 ? bus_dram_ctrl0 : bus_dram_ctrl1; 
    assign w_dram_le    = grant == 0 ? bus_dram_le0 : bus_dram_le1;
    wire [31:0] w_core_ir = grant == 0 ? bus_core_ir0 : bus_core_ir1;

endmodule