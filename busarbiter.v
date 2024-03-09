// author: Laurentiu-Cristian Duca, date: 2023-05-25
// spdx license identifier MIT

`include "define.vh"

module busarbiter(
    // here we do not keep the w_ notation for wire
    input wire CLK, RST_X, output wire [31:0] w_grant,
    input wire w_init_done, input wire w_tx_ready,
    output wire [31:0] w_mem_paddr, output wire w_data_we, output wire w_data_le, 
    input wire [3:0] w_data_busy, output reg [3:0] bus_data_busy0, output reg [3:0] bus_data_busy1,
    output wire [31:0] w_data_wdata, input wire [31:0] w_data_data,
    input wire [63:0] w_mtime,
    output wire [1:0]  w_tlb_req, output wire w_tlb_busy,
    output wire [31:0] w_mip, input wire [31:0] w_wmip, input wire w_plic_aces, input wire r_plic_aces_t, input wire w_plic_we,
    output wire [31:0] w_dram_addr, output wire [31:0] w_dram_wdata, input wire [31:0] w_dram_odata, output wire w_dram_we_t,
    input wire w_dram_busy, output wire [2:0] w_dram_ctrl, output wire w_dram_le,

    input wire [31:0] bus_core_ir0, input wire [3:0] bus_cpustate0,
    input wire [31:0] bus_mem_paddr0, input wire bus_data_we0, input wire bus_data_le0,
    input wire [31:0] bus_data_wdata0, 
    output reg [31:0] bus_data_data0,
    input wire [1:0] bus_tlb_req0, input wire bus_tlb_busy0,
    input [31:0] bus_mip0, output reg [31:0] bus_wmip0, output reg bus_plic_we0,
    input [31:0] bus_dram_addr0, input [31:0] bus_dram_wdata0, output reg [31:0] bus_dram_odata0, input bus_dram_we_t0,
    output reg bus_dram_busy0, input wire [2:0] bus_dram_ctrl0, input bus_dram_le0,

    input wire [31:0] bus_core_ir1, input wire [3:0] bus_cpustate1,
    input wire [31:0] bus_mem_paddr1, input wire bus_data_we1, input wire bus_data_le1,
    input wire [31:0] bus_data_wdata1, 
    output reg [31:0] bus_data_data1,
    input wire [1:0] bus_tlb_req1, input wire bus_tlb_busy1,
    input [31:0] bus_mip1, output reg [31:0] bus_wmip1, output reg bus_plic_we1,
    input [31:0] bus_dram_addr1, input [31:0] bus_dram_wdata1, output reg [31:0] bus_dram_odata1, input bus_dram_we_t1,
    output reg bus_dram_busy1, input wire [2:0] bus_dram_ctrl1, input bus_dram_le1
    );
    /**********************************************************************************************/
    
    reg [31:0] grant=0; // bus granted core
    assign w_grant=grant;

    reg [7:0] state=0;
    
    wire w_sys_busy = w_dram_busy || !w_tx_ready || w_data_busy;

`ifdef USE_SINGLE_CORE

    always@(posedge CLK) 
    begin
        if(!RST_X) begin
            grant <= 0;
        end else if(w_init_done) begin
        if(state == 0) begin
            if(w_sys_busy)
                $display("------------- sys-busy in state0");
            if(bus_dram_le0) begin
                bus_dram_busy0 <= 1;
                // set control signals
                r_ba_dram_le0 <= 1;
                r_ba_dram_we_t0 <= 0;
                r_ba_data_le0 <= 0;
                r_ba_data_we0 <= 0;
                // get dram signals
                r_bus_dram_addr0 <= bus_dram_addr0;
                r_bus_dram_ctrl0 <= bus_dram_ctrl0;
                //$display("dram rd addr=%x", bus_dram_addr0);
                state <= 1;
                if(/*bus_dram_le0 || */bus_dram_we_t0 || bus_data_le0 || bus_data_we0)
                    $display("------------- two on bus for dram-rd");
            end else if (bus_dram_we_t0) begin
                bus_dram_busy0 <= 1;
                // set control signals
                r_ba_dram_le0 <= 0;
                r_ba_dram_we_t0 <= 1;
                r_ba_data_le0 <= 0;
                r_ba_data_we0 <= 0;
                // get dram signals
                r_bus_dram_addr0 <= bus_dram_addr0;
                r_bus_dram_ctrl0 <= bus_dram_ctrl0;
                r_bus_dram_wdata0 <= bus_dram_wdata0;
                //$display("dram wr addr=%x data=%x", bus_dram_addr0, bus_dram_wdata0);
                state <= 11;
                if(bus_dram_le0 || /*bus_dram_we_t0 ||*/ bus_data_le0 || bus_data_we0)
                    $display("---------------- two on bus for dram-wr");
            end else if(bus_data_le0) begin
                bus_data_busy0 <= 1;
                // set control signals
                r_ba_dram_le0 <= 0;
                r_ba_dram_we_t0 <= 0;
                r_ba_data_le0 <= 1;
                r_ba_data_we0 <= 0;
                // get data signals
                r_bus_mem_paddr0 <= bus_mem_paddr0;
                //$display("data rd addr=%x", bus_mem_paddr0);
                state <= 21;
            end else if(bus_data_we0) begin
                bus_data_busy0 <= 1;
                // set control signals
                r_ba_dram_le0 <= 0;
                r_ba_dram_we_t0 <= 0;
                r_ba_data_le0 <= 0;
                r_ba_data_we0 <= 1;
                // get data signals
                r_bus_mem_paddr0 <= bus_mem_paddr0;
                r_bus_data_wdata0 <= bus_data_wdata0;
                //$display("data wr addr=%x data=%x", bus_mem_paddr0, bus_data_wdata0);
                state <= 31;
            end
        end else if(state == 1) begin // dram read
            if(w_sys_busy) begin
                r_ba_dram_le0 <=0;
                state <= 2;
            end
        end else if(state == 2) begin
            if(!w_sys_busy) begin
                // collect dram data
                r_bus_dram_odata0 <= w_dram_odata; // mmu
                r_bus_data_data0 <= w_dram_odata; // cpu
                bus_dram_busy0 <= 0;
                state <= 0;
            end
        end else if(state == 11) begin // dram write
             if(w_sys_busy) begin
                r_ba_dram_we_t0 <= 0;
                state <= 12;
            end
        end else if(state == 12) begin
            if(!w_sys_busy) begin 
                bus_dram_busy0 <= 0;
                state <= 0;
            end
        end else if(state == 21) begin // data read
             if(w_sys_busy) begin
                r_ba_data_le0 <= 0;
                state <= 22;
            end
        end else if(state == 22) begin
            if(!w_sys_busy) begin
                r_bus_data_data0 <= w_data_data;
                bus_data_busy0 <= 0;
                state <= 0;
            end
        end else if(state == 31) begin // data write
            if(w_sys_busy) begin
                r_ba_data_we0 <= 0;
                state <= 32;
            end
        end else if(state == 32) begin
            if(!w_sys_busy) begin
                bus_data_busy0 <= 0;
                state <= 0;
            end
        end 
        end // init_done
    end

    always @(*) begin
        if(grant == 0) begin
            bus_wmip0 <= w_wmip; 
            bus_plic_we0 <= w_plic_we;
            bus_dram_odata0 <= r_bus_dram_odata0;
            bus_data_data0  <= r_bus_data_data0;
        end
    end    

    assign w_dram_addr  = grant == 0 ? r_bus_dram_addr0 : bus_dram_addr1;
    assign w_dram_wdata = grant == 0 ? r_bus_dram_wdata0 : bus_dram_wdata1;
    assign w_dram_we_t  = grant == 0 ? r_ba_dram_we_t0 : bus_dram_we_t1;
    assign w_dram_le    = grant == 0 ? r_ba_dram_le0 : bus_dram_le1;
    assign w_dram_ctrl  = grant == 0 ? r_bus_dram_ctrl0 : bus_dram_ctrl1; 

    assign w_mem_paddr  = grant == 0 ? r_bus_mem_paddr0 : bus_mem_paddr1;
    assign w_data_we    = grant == 0 ? r_ba_data_we0 : bus_data_we1;
    assign w_data_le    = grant == 0 ? r_ba_data_le0 : bus_data_le1;
    assign w_data_wdata = grant == 0 ? r_bus_data_wdata0 : bus_data_wdata1;

    assign w_tlb_req    = grant == 0 ? bus_tlb_req0 : bus_tlb_req1;
    assign w_tlb_busy   = grant == 0 ? bus_tlb_busy0 : bus_tlb_busy1;
    assign w_mip        = grant == 0 ? bus_mip0 : bus_mip1;

    wire [31:0] w_core_ir = grant == 0 ? bus_core_ir0 : bus_core_ir1;
    wire [3:0] w_bus_cpustate = grant == 0 ? bus_cpustate0 : bus_cpustate1;

    reg [31:0] r_bus_dram_addr0=0;
    reg [31:0] r_bus_dram_wdata0=0;
    reg r_ba_dram_we_t0=0;
    reg r_ba_dram_le0=0;
    reg [2:0] r_bus_dram_ctrl0=0;
    reg [31:0] r_bus_dram_odata0=0;

    reg [31:0] r_bus_mem_paddr0=0;
    reg r_ba_data_we0=0;
    reg r_ba_data_le0=0;
    reg [31:0] r_bus_data_wdata0=0;
    reg [31:0] r_bus_data_data0=0;

`else
`endif
    
    

endmodule
