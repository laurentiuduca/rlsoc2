/* Modified by Laurentiu-Cristian Duca, 2021-12-20
 * - memory model similar to dram memory controller with DRAM_SIM
 * or simple memory model
 * - debug with RAM_DEBUG
 * - allow ICARUS simulation
 */
/**************************************************************************************************/
/**** RVSoC (Mini Kuroda/RISC-V)                       since 2018-08-07   ArchLab. TokyoTech   ****/
/**** top module and simulation module v0.01                                                   ****/
/**************************************************************************************************/
`default_nettype none
/**************************************************************************************************/
`include "define.vh"

/**************************************************************************************************/
`ifdef ICARUS
module m_topsim();
    reg CLK = 0;
    reg RST_X;

    initial forever #50 CLK = ~CLK;

    initial begin
        #50  RST_X = 0;
        #300 RST_X = 1;
    end
`ifdef laur0
    initial begin
	$dumpfile("signals.vcd");
        $dumpvars(0, m_topsim);
    end
`endif
`else
module m_topsim(CLK, RST_X);
    input wire CLK, RST_X;
`endif

    m_cpummusim core0(
        .CLK(CLK), 
        .RST_X(RST_X), 
        .w_tx_ready(w_tx_ready),
        .w_mem_paddr(w_mem_paddr),
        .w_mem_we(w_mem_we),
        .w_mem_wdata(w_mem_wdata));

    /**********************************************************************************************/
    // bus signals
    wire [31:0] w_mem_paddr;
    wire w_mem_we;
    wire [31:0] w_mem_wdata;

    /*********************************         TOHOST         *********************************/
    // OUTPUT CHAR
    UartTx UartTx0(CLK, RST_X, r_uart_data, r_uart_we, w_txd, w_tx_ready);
    wire w_txd;
    reg         r_uart_we = 0;
    reg   [7:0] r_uart_data = 0;
`ifdef LAUR_MEM_RB
    // xsim requires declaration before use
    reg r_rb_uart_we=0;
    reg [7:0] r_rb_uart_data;
`endif
    wire w_tx_ready;
    reg          r_finish=0;
    always@(posedge CLK) begin
        if((w_mem_paddr==`TOHOST_ADDR && w_mem_we) && (w_mem_wdata[31:16]==`CMD_PRINT_CHAR)) begin
            r_uart_we   <= 1;
            r_uart_data <= w_mem_wdata[7:0];
`ifdef LAUR_MEM_RB
	end else if(r_rb_uart_we) begin
		r_uart_we <= 1;
		r_uart_data <= r_rb_uart_data;
`endif
    	end else begin 
            r_uart_we   <= 0;
            r_uart_data <= 0;
        end
        // Finish Simulation
        if((w_mem_paddr==`TOHOST_ADDR && w_mem_we) && (w_mem_wdata[31:16]==`CMD_POWER_OFF)) begin
            r_finish = 1;
        end
    end
    always@(posedge CLK) if (r_finish) begin
        $write("FINISH!\n");
        $finish();
    end
    /**********************************************************************************************/
    // LOAD linux
    integer i,j;
    //integer k;
    reg  [7:0] mem_bbl [0:`BBL_SIZE-1];
    reg  [7:0] mem_disk[0:`DISK_SIZE-1];
    initial begin
`ifndef VERILATOR
    #1
`endif
`ifdef LINUX
        $write("Load image file: %s\n", `IMAGE_FILE);
        $readmemh(`IMAGE_FILE, mem_disk);
        j=`BBL_SIZE;

        for(i=0;i<`DISK_SIZE;i=i+1) begin
`ifdef DRAM_SIM
`ifdef SKIP_CACHE
	    core0.mmu.idbmem.idbmem.mem[j]=mem_disk[i];
`else
	    core0.mmu.idbmem.cache_ctrl.idbmem.mem[j]=mem_disk[i];
`endif
`else
	    core0.mmu.idbmem.idbmem.mem[j]=mem_disk[i];
`endif // DRAM_SIM
            j=j+1;
        end
`endif // LINUX
        $write("Running %s\n", {`HEX_DIR,`HEXFILE});
        $readmemh({`HEX_DIR,`HEXFILE}, mem_bbl);
        j=0;

        for(i=0;i<`BBL_SIZE;i=i+1) begin
`ifdef DRAM_SIM
`ifdef SKIP_CACHE
            core0.mmu.idbmem.idbmem.mem[j]=mem_bbl[i];
`else
	    core0.mmu.idbmem.cache_ctrl.idbmem.mem[j]=mem_bbl[i];
`endif
`else
	    core0.mmu.idbmem.idbmem.mem[j]=mem_bbl[i];
`endif // DRAM_SIM
            j=j+1;
        end
        $write("-------------------------------------------------------------------\n");
    end

/**********************************************************************************************/

endmodule

