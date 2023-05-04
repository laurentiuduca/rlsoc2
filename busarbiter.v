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

`ifdef laurnotdefined
    always @(posedge CLK) begin /////// update program counter
        if(!RST_X) begin
            grant <= 0;
            setall(0);
            state <= 0;
        end else begin
            case(state)
            0: begin          
                setall(0);
            end
            endcase
        end
    end
`endif

    always @(*)
        setandwait(0);

    task setandwait();
    input id;
    begin
            bus_proc_busy[id] <= w_proc_busy;
            w_mem_paddr <= bus_mem_paddr[id]; w_mem_we <= bus_mem_we[id];
            w_data_wdata <= bus_data_wdata[id]; bus_data_data[id] = w_data_data;
            w_mtime <= bus_mtime[id]; w_mtimecmp <= bus_mtimecmp[id]; bus_wmtimecmp[id] <= w_wmtimecmp; bus_clint_we[id] = w_clint_we;
            w_tlb_req <= bus_tlb_req[id]; w_tlb_busy <= bus_tlb_busy[id];
            w_mip <= bus_mip[id]; bus_wmip[id] <= w_wmip; bus_plic_we[id] = w_plic_we;
            w_dram_addr <= bus_dram_addr[id]; w_dram_wdata <= bus_dram_wdata[id]; bus_dram_odata[id] <= w_dram_odata; w_dram_we_t <= bus_dram_we_t[id];
            bus_dram_busy[id] <= w_dram_busy; w_dram_ctrl <= bus_dram_ctrl[id]; w_dram_le <= bus_dram_le[id];
    end
    endtask

    task setall();
    input id;
    begin
            bus_proc_busy[id] <= w_proc_busy;
            w_mem_paddr <= bus_mem_paddr[id]; w_mem_we <= bus_mem_we[id];
            w_data_wdata <= bus_data_wdata[id]; bus_data_data[id] = w_data_data;
            w_mtime <= bus_mtime[id]; w_mtimecmp <= bus_mtimecmp[id]; bus_wmtimecmp[id] <= w_wmtimecmp; bus_clint_we[id] = w_clint_we;
            w_tlb_req <= bus_tlb_req[id]; w_tlb_busy <= bus_tlb_busy[id];
            w_mip <= bus_mip[id]; bus_wmip[id] <= w_wmip; bus_plic_we[id] = w_plic_we;
            w_dram_addr <= bus_dram_addr[id]; w_dram_wdata <= bus_dram_wdata[id]; bus_dram_odata[id] <= w_dram_odata; w_dram_we_t <= bus_dram_we_t[id];
            bus_dram_busy[id] <= w_dram_busy; w_dram_ctrl <= bus_dram_ctrl[id]; w_dram_le <= bus_dram_le[id];
    end
    endtask

endmodule