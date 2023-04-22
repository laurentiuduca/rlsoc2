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

    m_cpummusim core0(CLK, RST_X);

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

