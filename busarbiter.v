`include "define.vh"

module busarbiter(
    // here we do not keep the w_ notation for wire
    input wire CLK, RST_X, output wire [31:0] w_grant,
    input wire w_init_done, input wire w_tx_ready,
    output reg [31:0] w_mem_paddr, output reg w_mem_we,
    output reg [31:0] w_data_wdata, input wire [31:0] w_data_data,
    output reg [63:0] w_mtime, output reg [63:0] w_mtimecmp, input wire [63:0] w_wmtimecmp, input wire w_clint_we,
    output reg [1:0]  w_tlb_req, output reg w_tlb_busy,
    output reg [31:0] w_mip, input wire [31:0] w_wmip, input wire w_plic_we,
    output reg [31:0] w_dram_addr, output reg [31:0] w_dram_wdata, input wire [31:0] w_dram_odata, output reg w_dram_we_t,
    input wire w_dram_busy, output reg [2:0] w_dram_ctrl, output reg w_dram_le,

    input wire [31:0] bus_mem_paddr[0:`NCORES-1], input wire bus_mem_we[0:`NCORES-1],
    input wire [31:0] bus_data_wdata[0:`NCORES-1], 
    output reg [31:0] bus_data_data[0:`NCORES-1],
    input [63:0] bus_mtime[0:`NCORES-1], input [63:0] bus_mtimecmp[0:`NCORES-1], 
    output reg [63:0] bus_wmtimecmp[0:`NCORES-1], output reg bus_clint_we[0:`NCORES-1],
    input wire [2:0] bus_pw_state[0:`NCORES-1], input wire [1:0] bus_tlb_req[0:`NCORES-1], input wire bus_tlb_busy[0:`NCORES-1],
    input [31:0] bus_mip[0:`NCORES-1], output reg [31:0] bus_wmip[0:`NCORES-1], output reg bus_plic_we[0:`NCORES-1],
    input [31:0] bus_dram_addr[0:`NCORES-1], input [31:0] bus_dram_wdata[0:`NCORES-1], output reg [31:0] bus_dram_odata[0:`NCORES-1], input bus_dram_we_t[0:`NCORES-1],
    output reg bus_dram_busy[0:`NCORES-1], input wire [2:0] bus_dram_ctrl[0:`NCORES-1], input bus_dram_le[0:`NCORES-1]
    );
    /**********************************************************************************************/
    
    reg [31:0] grant=0; // bus granted core
    assign w_grant=grant;

    reg [7:0] state=0;
    integer i;
    reg [7:0] cnt=0;
    //reg a_dram_le=0;
    reg a_dram_le=0;
    wire a_dram_we_t=bus_dram_we_t[grant];

    reg a_w_dram_busy=0;
    reg [31:0] a_w_dram_odata=0;


    always @(posedge CLK) begin
        if(w_init_done) begin
            if(state == 0) begin
                if(!w_tlb_busy && (bus_dram_le[grant]) && !w_dram_busy) begin
                    a_w_dram_busy <= 1;
                    a_dram_le <= 1;
                    state <= 1;
                end
            end else if(state == 1) begin
                if(w_dram_busy) begin
                    a_dram_le <= 0;
                    state <= 2;
                end
            end else if(state == 2) begin
                if(!w_dram_busy) begin
                    a_w_dram_busy <= 0;
                    a_w_dram_odata <= w_dram_odata;
                    state <= 0;
                end
            end
        end
    end

/*
    always @(posedge CLK) begin
        if(!RST_X) begin
            grant <= 0;
            state <= 7;
            a_w_dram_busy <= w_dram_busy;
            cnt <= 0;
        end else if(w_init_done) begin
            if(state == 7) begin
                if(w_dram_busy) begin
                    state <= 0;
                    a_w_dram_busy <= w_dram_busy;
                end
            end else if(state == 0) begin
                a_w_dram_busy <= w_dram_busy;
                if((!w_tlb_busy && !w_dram_busy && w_tx_ready) && cnt < 10)
                    cnt <= cnt + 1;
                if((!w_tlb_busy && !w_dram_busy && w_tx_ready) &&
                    (a_mem_we || a_dram_le || a_dram_we_t || cnt > 2)) begin
                        grant <= (grant + 1) & (`NCORES-1);
                        a_w_dram_busy <= 1;
                        state <= 1;
                end
            end else if(state == 1) begin
                // grant has just changed, a_w_dram_busy is 1; wait for w_dram_busy
                if(w_dram_busy || (bus_dram_we_t[grant]==0 && bus_dram_le[grant]==0))
                    state <= 2;
            end else if(state == 2) begin
                if(!w_dram_busy)
                    state <= 0;
                a_w_dram_busy <= w_dram_busy;
                cnt <= 0;
            end
        end
    end
*/
    always @(*) begin
            w_mem_paddr <= bus_mem_paddr[grant]; w_mem_we <= bus_mem_we[grant];
            w_data_wdata <= bus_data_wdata[grant]; bus_data_data[grant] = w_data_data;
            w_mtime <= bus_mtime[grant]; w_mtimecmp <= bus_mtimecmp[grant]; bus_wmtimecmp[grant] <= w_wmtimecmp; bus_clint_we[grant] = w_clint_we;
            w_tlb_req <= bus_tlb_req[grant]; w_tlb_busy <= bus_tlb_busy[grant];
            w_mip <= bus_mip[grant]; bus_wmip[grant] <= w_wmip; bus_plic_we[grant] = w_plic_we;
            w_dram_addr <= bus_dram_addr[grant]; w_dram_wdata <= bus_dram_wdata[grant]; bus_dram_odata[grant] <= a_w_dram_odata; w_dram_we_t <= a_dram_we_t;
            bus_dram_busy[grant] <= a_w_dram_busy; w_dram_ctrl <= bus_dram_ctrl[grant]; w_dram_le <= a_dram_le;
            for(i=0; i<`NCORES; i=i+1)
                if(grant != i)
                    bus_dram_busy[i] = 1;
    end

endmodule