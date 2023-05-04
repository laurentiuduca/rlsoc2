`include "define.vh"

module busarbiter(
    // here we do not keep the w_ notation for wire
    input wire CLK, RST_X, output wire [31:0] w_grant, input wire w_tx_ready,
    input wire w_init_done, input wire w_proc_busy,
    output reg [31:0] w_mem_paddr, output reg w_mem_we,
    output reg [31:0] w_data_wdata, input wire [31:0] w_data_data,
    output reg [63:0] w_mtime, output reg [63:0] w_mtimecmp, input wire [63:0] w_wmtimecmp, input wire w_clint_we,
    output reg [1:0]  w_tlb_req, output reg w_tlb_busy,
    output reg [31:0] w_mip, input wire [31:0] w_wmip, input wire w_plic_we,
    output reg [31:0] w_dram_addr, output reg [31:0] w_dram_wdata, input wire [31:0] w_dram_odata, output reg w_dram_we_t,
    input wire w_dram_busy, output reg [2:0] w_dram_ctrl, output reg w_dram_le,

    output reg bus_proc_busy[0:`NCORES-1],
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
    
    reg [31:0] grant=0; // bus granted core
    assign w_grant=grant;

    reg [7:0] state=0;
    integer i;
    wire [2:0] a_pw_state = grant == 0 ? bus_pw_state[1] : bus_pw_state[0];
    wire a_tlb_busy = grant == 0 ? bus_tlb_busy[1] : bus_tlb_busy[0];
    reg a_w_dram_busy=0;

/*
- restore other core // w_dram_busy is 0 and txready
if(tlbbusy)
    if r_pw_state==0|2 
        v <= w
    else
        v <= w except w_dram_busy
        wait 1 clk
        v <= w_procbusy
else
    v <= w except w_dram_busy
    wait 1 clk
    v <= w_procbusy

- preempt //w_dram_busy is 0 and txready
if(tlbbusy)
    v_dram_busy <= 1
else
    v_dram_busy <= 1
*/

    always @(posedge CLK) begin
        if(!RST_X) begin
            grant <= 0;
            state <= 0;
            a_w_dram_busy <= w_dram_busy;
        end else if(w_init_done) begin
            a_w_dram_busy <= w_dram_busy;
            if(state == 0) begin
                if(!w_dram_busy && w_tx_ready) begin
                    grant <= 1 - grant; // only 2 cores for now
                    if(a_tlb_busy)
                        if(a_pw_state == 0 || a_pw_state == 2) ; // all by default
                        else begin
                            a_w_dram_busy <= 1;
                            state <= 1;
                        end
                end
            end else if(state == 1) 
                state <= 2; // wait for the real w_dram_busy
            else if(state == 2)
                state <= 0;
        end
    end

    always @(*) begin
        if(grant == 0)
            setbyid(0);
        else
            setbyid(1);
    end

    task setbyid();
    input id;
    begin
            bus_proc_busy[id] <= w_proc_busy;
            w_mem_paddr <= bus_mem_paddr[id]; w_mem_we <= bus_mem_we[id];
            w_data_wdata <= bus_data_wdata[id]; bus_data_data[id] = w_data_data;
            w_mtime <= bus_mtime[id]; w_mtimecmp <= bus_mtimecmp[id]; bus_wmtimecmp[id] <= w_wmtimecmp; bus_clint_we[id] = w_clint_we;
            w_tlb_req <= bus_tlb_req[id]; w_tlb_busy <= bus_tlb_busy[id];
            w_mip <= bus_mip[id]; bus_wmip[id] <= w_wmip; bus_plic_we[id] = w_plic_we;
            w_dram_addr <= bus_dram_addr[id]; w_dram_wdata <= bus_dram_wdata[id]; bus_dram_odata[id] <= w_dram_odata; w_dram_we_t <= bus_dram_we_t[id];
            bus_dram_busy[id] <= a_w_dram_busy; w_dram_ctrl <= bus_dram_ctrl[id]; w_dram_le <= bus_dram_le[id];
            for(i=0; i<`NCORES; i=i+1)
                if(id != i)
                    bus_dram_busy[i] = 1;
    end
    endtask

endmodule