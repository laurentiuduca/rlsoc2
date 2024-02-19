// modified by Laurentiu-Cristian Duca, 20231028-1235
// author: Laurentiu-Cristian Duca, date: 2023-05-25
// - dual-core support
// spdx license identifier MIT

`default_nettype none
/**************************************************************************************************/
`include "define.vh"

/**************************************************************************************************/

`ifndef SIM_MODE
module m_maintn(
    input wire CLK,
    input  wire        w_rxd,
    output wire        w_txd,
    output wire [5:0] w_led,
	input wire w_btnl,
	input wire w_btnr,

    // tang nano 20k SDRAM
    output wire O_sdram_clk,
    output wire O_sdram_cke,
    output wire O_sdram_cs_n,            // chip select
    output wire O_sdram_cas_n,           // columns addrefoc select
    output wire O_sdram_ras_n,           // row address select
    output wire O_sdram_wen_n,           // write enable
    inout wire [31:0] IO_sdram_dq,       // 32 bit bidirectional data bus
    output wire [10:0] O_sdram_addr,     // 11 bit multiplexed address bus
    output wire [1:0] O_sdram_ba,        // two banks
    output wire [3:0] O_sdram_dqm,       // 32/4

    // when sdcard_pwr_n = 0, SDcard power on
    output wire         sdcard_pwr_n,
    // signals connect to SD bus
    output wire         sdclk,
    inout  wire         sdcmd,
    input  wire         sddat0,
    output wire         sddat1, sddat2, sddat3,

    // display
    output wire MAX7219_CLK,
    output wire MAX7219_DATA,
    output wire MAX7219_LOAD
    );

    wire pll_clk, clk_sdram;
    Gowin_rPLL_nes pll_nes(
    .clkin(CLK),
    .clkout(pll_clk),          // FREQ main clock
    .clkoutp(clk_sdram)    // FREQ main clock phase shifted
    );

reg RST_X = 0;
reg [7:0] rst_cnt = 0;
always @(posedge pll_clk) begin
    if(rst_cnt < 25) begin
      rst_cnt <= rst_cnt + 1;
		RST_X <= 0;
	 end else
      RST_X <= 1;
end

`else
module m_topsim(CLK, RST_X);
    input wire CLK, RST_X;
    wire pll_clk = CLK;
    wire w_txd;
    wire w_rxd;
    wire clk_sdram;
    wire MAX7219_CLK;
    wire MAX7219_DATA;
    wire MAX7219_LOAD;
`endif

    /**********************************************************************************************/
    // bus interface
    wire w_init_done;
    wire [31:0] bus_core_ir_0, bus_core_ir_1;
    wire [3:0] bus_cpustate0, bus_cpustate1;
    wire [3:0] w_bus_cpustate = w_grant == 0 ? bus_cpustate0 : bus_cpustate1;
    wire [31:0] w_mem_paddr, bus_mem_paddr0, bus_mem_paddr1;
    wire w_data_we, bus_data_we0, bus_data_we1;
    wire [31:0] w_data_wdata, bus_data_wdata0, bus_data_wdata1;
    wire [31:0] w_data_data, bus_data_data0, bus_data_data1;
    wire [63:0] w_mtimecmp0, w_mtimecmp1, w_wmtimecmp0, w_wmtimecmp1;
    wire w_clint_we, bus_clint_we0, bus_clint_we1;
    wire [1:0]  w_tlb_req, bus_tlb_req0, bus_tlb_req1;
    wire        w_tlb_busy, bus_tlb_busy0, bus_tlb_busy1;
    wire [31:0] w_mip, w_wmip, bus_mip0, bus_wmip0, bus_mip1, bus_wmip1;
    wire w_plic_we, bus_plic_we0, bus_plic_we1;
    wire [31:0] w_dram_addr, bus_dram_addr0, bus_dram_addr1;
    wire [31:0] w_dram_wdata, bus_dram_wdata0, bus_dram_wdata1;
    wire [31:0] w_dram_odata, bus_dram_odata0, bus_dram_odata1;
    wire w_dram_we_t, bus_dram_we_t0, bus_dram_we_t1;
    wire w_dram_busy, bus_dram_busy0, bus_dram_busy1;
    wire [2:0]   w_dram_ctrl, bus_dram_ctrl0, bus_dram_ctrl1;
    wire w_dram_le, bus_dram_le0, bus_dram_le1;
    wire [31:0] w_pc0, w_pc1, w_ir0, w_ir1;

    wire [31:0] w_grant;
    wire [31:0] bus_ipi;

    reg [63:0] mtime=0;
    wire [63:0] w_mtime=mtime;

    wire w_tx_ready;
	 wire w_plic_aces;
	 reg         r_plic_aces_t   = 0;
    reg  [31:0] r_plic_odata        = 0;
    reg  [31:0] r_clint_odata       = 0;

	 reg   [$clog2(`KEYBOARD_QUEUE_SIZE):0] r_consf_cnts        = 0;  // Note!!
	 reg [7:0] r_char_value=0;
	 
	 reg         r_uart_we = 0;
    reg   [7:0] r_uart_data = 0;
    wire        w_key_we;
    wire  [7:0] w_key_data;

//`ifdef laur0
    m_cpummu core0(
        .CLK(pll_clk), .RST_X(RST_X), .w_hart_id(0), .w_grant(w_grant), .w_ipi(bus_ipi), .w_core_ir(bus_core_ir_0), .w_state(bus_cpustate0),
        .w_init_done(w_init_done), .w_tx_ready(w_tx_ready),
        .w_mem_paddr(bus_mem_paddr0), .w_data_we(bus_data_we0),
        .w_data_wdata(bus_data_wdata0), .w_data_data(bus_data_data0),
        .w_mtime(w_mtime), .w_mtimecmp(w_mtimecmp0), .w_wmtimecmp(w_wmtimecmp0), .w_clint_we(bus_clint_we0),
        .w_tlb_req(bus_tlb_req0), .w_tlb_busy(bus_tlb_busy0),
        .w_mip(bus_mip0), .w_wmip(bus_wmip0), .w_plic_we(bus_plic_we0),
        .w_dram_addr(bus_dram_addr0), .w_dram_wdata(bus_dram_wdata0), .w_dram_odata(bus_dram_odata0), .w_dram_we_t(bus_dram_we_t0),
        .w_dram_busy(bus_dram_busy0), .w_dram_ctrl(bus_dram_ctrl0), .w_dram_le(bus_dram_le0), .w_pc(w_pc0), .w_ir(w_ir0)
    );
//`endif

`ifndef USE_SINGLE_CORE
     m_cpummu core1(
        .CLK(pll_clk), .RST_X(RST_X), .w_hart_id(1), .w_grant(w_grant), .w_ipi(bus_ipi), .w_core_ir(bus_core_ir_1), .w_state(bus_cpustate1),
        .w_init_done(w_init_done), .w_tx_ready(w_tx_ready),
        .w_mem_paddr(bus_mem_paddr1), .w_data_we(bus_data_we1),
        .w_data_wdata(bus_data_wdata1), .w_data_data(bus_data_data1),
        .w_mtime(w_mtime), .w_mtimecmp(w_mtimecmp1), .w_wmtimecmp(w_wmtimecmp1), .w_clint_we(bus_clint_we1),
        .w_tlb_req(bus_tlb_req1), .w_tlb_busy(bus_tlb_busy1),
        .w_mip(bus_mip1), .w_wmip(bus_wmip1), .w_plic_we(bus_plic_we1),
        .w_dram_addr(bus_dram_addr1), .w_dram_wdata(bus_dram_wdata1), .w_dram_odata(bus_dram_odata1), .w_dram_we_t(bus_dram_we_t1),
        .w_dram_busy(bus_dram_busy1), .w_dram_ctrl(bus_dram_ctrl1), .w_dram_le(bus_dram_le1), .w_pc(w_pc1), .w_ir(w_ir1)
    );   
`endif


    busarbiter ba(.CLK(pll_clk), .RST_X(RST_X), .w_grant(w_grant),
        .w_init_done(w_init_done), .w_tx_ready(w_tx_ready),
        .w_mem_paddr(w_mem_paddr), .w_data_we(w_data_we),
        .w_data_wdata(w_data_wdata), .w_data_data(w_data_data),
        .w_mtime(w_mtime), .w_clint_we(w_clint_we),
        .w_tlb_req(w_tlb_req), .w_tlb_busy(w_tlb_busy),
        .w_mip(w_mip), .w_wmip(w_wmip), .w_plic_aces(w_plic_aces), .r_plic_aces_t(r_plic_aces_t), .w_plic_we(w_plic_we),
        .w_dram_addr(w_dram_addr), .w_dram_wdata(w_dram_wdata), .w_dram_odata(w_dram_odata), .w_dram_we_t(w_dram_we_t),
        .w_dram_busy(w_dram_busy), .w_dram_ctrl(w_dram_ctrl), .w_dram_le(w_dram_le),

        .bus_core_ir0(bus_core_ir_0), .bus_cpustate0(bus_cpustate0),
        .bus_mem_paddr0(bus_mem_paddr0), .bus_data_we0(bus_data_we0),
        .bus_data_wdata0(bus_data_wdata0), .bus_data_data0(bus_data_data0),
        .bus_clint_we0(bus_clint_we0),
        .bus_tlb_req0(bus_tlb_req0), .bus_tlb_busy0(bus_tlb_busy0),
        .bus_mip0(bus_mip0), .bus_wmip0(bus_wmip0), .bus_plic_we0(bus_plic_we0),
        .bus_dram_addr0(bus_dram_addr0), .bus_dram_wdata0(bus_dram_wdata0), .bus_dram_odata0(bus_dram_odata0), .bus_dram_we_t0(bus_dram_we_t0),
        .bus_dram_busy0(bus_dram_busy0), .bus_dram_ctrl0(bus_dram_ctrl0), .bus_dram_le0(bus_dram_le0),

        .bus_core_ir1(bus_core_ir_1), .bus_cpustate1(bus_cpustate1),
        .bus_mem_paddr1(bus_mem_paddr1), .bus_data_we1(bus_data_we1),
        .bus_data_wdata1(bus_data_wdata1), .bus_data_data1(bus_data_data1),
        .bus_clint_we1(bus_clint_we1),
        .bus_tlb_req1(bus_tlb_req1), .bus_tlb_busy1(bus_tlb_busy1),
        .bus_mip1(bus_mip1), .bus_wmip1(bus_wmip1), .bus_plic_we1(bus_plic_we1),
        .bus_dram_addr1(bus_dram_addr1), .bus_dram_wdata1(bus_dram_wdata1), .bus_dram_odata1(bus_dram_odata1), .bus_dram_we_t1(bus_dram_we_t1),
        .bus_dram_busy1(bus_dram_busy1), .bus_dram_ctrl1(bus_dram_ctrl1), .bus_dram_le1(bus_dram_le1)
    );

    always@(posedge pll_clk)
        if(RST_X) mtime <= mtime + 1;

    /**********************************************************************************************/

    wire  [3:0] w_dev       = w_mem_paddr[31:28];// & 32'hf0000000;
    wire  [3:0] w_virt      = w_mem_paddr[27:24];// & 32'h0f000000;
    wire  [27:0] w_offset   = w_mem_paddr & 28'h7ffffff;
    reg   [31:0] r_mem_paddr= 0;
    reg   [3:0] r_dev       = 0;// & 32'hf0000000;
    reg   [3:0] r_virt      = 0;// & 32'h0f000000;
    always@(posedge pll_clk) begin
        r_dev   <= w_dev;
        r_virt  <= w_virt;
        r_mem_paddr <= w_mem_paddr;
    end

    /***********************************          OUTPUT        ***********************************/
    reg  [31:0] r_data_data;
    always@(*) begin
        case (r_dev)
            `CLINT_BASE_TADDR : r_data_data <= r_clint_odata;
            `PLIC_BASE_TADDR  : r_data_data <= r_plic_odata;
            `HVC_BASE_TADDR  : if(r_mem_paddr == `HVC_BASE_ADDR) begin
                                    //$display("HVC_BASE_ADDR %x", r_consf_cnts);
                                    r_data_data <= {24'h0, /*8-$clog2(`KEYBOARD_QUEUE_SIZE)-1*/2'h0, r_consf_cnts /*r_consf_en*/};
                                end else if(r_mem_paddr == (`HVC_BASE_ADDR + 4)) begin
                                    //$display("HVC_BASE_ADDR+4 r_char_value %x", r_char_value);
                                    r_data_data <= {24'h0, cons_fifo[r_consf_head] /*r_char_value*/};
                                end //else begin
                                    //r_data_data <= 0;
                                    //$display ("HVC_BASE_TADDR r_data_data <= 0 ------------------------------------");
                                //end
            default           : r_data_data <= w_dram_odata;
        endcase
    end
    assign w_data_data = r_data_data;

    /*********************************          INTERRUPTS          *********************************/
    
    wire        w_isread        = (w_tlb_req == `ACCESS_READ);
    wire        w_iswrite       = (w_tlb_req == `ACCESS_WRITE);

    wire [31:0] w_cons_irq=0;
    wire        w_cons_irq_oe=0;
    wire        w_key_req=0;
    wire [31:0] w_virt_irq      = w_cons_irq;
    wire        w_virt_irq_oe   = w_cons_irq_oe | w_key_req;
    // PLIC
    reg  [31:0] plic_served_irq     = 0;
    reg  [31:0] plic_pending_irq    = 0;
    // CLINT

    wire [31:0] w_plic_pending_irq_nxt  =   w_virt_irq_oe ? w_virt_irq : plic_pending_irq;
    wire [31:0] w_plic_mask             =   w_plic_pending_irq_nxt & ~plic_served_irq;
    wire [31:0] w_plic_served_irq_nxt   =   (w_virt_irq_oe) ? plic_served_irq :
                                            (w_isread) ? plic_served_irq | w_plic_mask :
                                            plic_served_irq & ~(1 << (w_data_wdata-1));

    assign w_plic_aces = (w_dev == `PLIC_BASE_TADDR && /*!w_tlb_busy &&*/
            ((w_isread && w_plic_mask != 0) || (w_iswrite && w_offset == `PLIC_HART_BASE+4)));

    reg  [31:0] r_wmip = 0;
    reg         r_plic_we = 0;

    reg  [31:0] r_plic_pending_irq_t    = 0;
    reg  [31:0] r_plic_served_irq_t     = 0;

    reg         r_virt_irq_oe_t = 0;

    reg [31:0] r_ipi=0;
    assign bus_ipi = r_ipi;
`ifdef SIM_MODE
    reg [31:0] r_max_displays=0;
`endif

    wire [31:0] w_plic_mask_nxt = r_plic_pending_irq_t & ~r_plic_served_irq_t;
    reg r_was_read=0, r_was_write=0;
    always@(posedge pll_clk) begin
        if(!w_tlb_busy) begin
            //r_plic_we   <= (w_virt_irq_oe || w_plic_aces);
            r_virt_irq_oe_t         <= w_virt_irq_oe;
            r_plic_aces_t           <= w_plic_aces;
            r_was_read              <= w_isread;
            r_was_write             <= w_iswrite;
            r_plic_pending_irq_t    <= w_plic_pending_irq_nxt;
            r_plic_served_irq_t     <= w_plic_served_irq_nxt;
        end
    end

    assign w_plic_we      = (r_virt_irq_oe_t || r_plic_aces_t);//r_plic_we;
    assign w_wmip  = (w_plic_mask_nxt) ? w_mip | (`MIP_MEIP | `MIP_SEIP) :
                            w_mip & ~(`MIP_MEIP | `MIP_SEIP);

    always@(posedge pll_clk) begin
`ifdef SIM_MODE
        if(w_plic_we)
            $display("----w_plic_we w_grant=%x", w_grant);
`endif

        if(w_plic_aces) begin
            r_plic_odata    <= (w_plic_mask!=0) ? w_plic_mask : 0;
            plic_served_irq <= w_plic_served_irq_nxt;
        end

        if(w_virt_irq_oe) begin
            plic_pending_irq    <= w_virt_irq;
        end

        r_clint_odata <=    (r_dev == `CLINT_BASE_TADDR && (w_offset==28'h0 || w_offset==28'h4) && w_data_we == 0) ? r_ipi :
                            (r_dev == `CLINT_BASE_TADDR && (w_offset==28'hbff8) && w_data_we == 0) ? w_mtime[31:0] :
                            (r_dev == `CLINT_BASE_TADDR && (w_offset==28'hbffc) && w_data_we == 0) ? w_mtime[63:32] :
                            (r_dev == `CLINT_BASE_TADDR && (w_offset==28'h4000) && w_data_we == 0) ? w_mtimecmp0[31:0] :
                            (r_dev == `CLINT_BASE_TADDR && (w_offset==28'h4004) && w_data_we == 0) ? w_mtimecmp0[63:32] : 
                            (r_dev == `CLINT_BASE_TADDR && (w_offset==28'h4008) && w_data_we == 0) ? w_mtimecmp1[31:0] :
                            (r_dev == `CLINT_BASE_TADDR && (w_offset==28'h400c) && w_data_we == 0) ? w_mtimecmp1[63:32] : 0;
        
        // ipi
        if(r_dev == `CLINT_BASE_TADDR && (w_offset==28'h0 || w_offset==28'h4) && w_data_we != 0) begin
            if(w_offset==28'h0) begin
                if(w_data_wdata == 32'h0) begin
`ifdef SIM_MODE
`ifndef USE_SINGLE_CORE
                    if(r_max_displays < `IPI_MAX_DISPLAYS) begin
                        $display("t=%8x clear ipi core0 w_grant=%1x c0pc=%x c0ir=%x c1pc=%x c1ir=%x", 
                            w_mtime, w_grant, core0.p.r_cpc, core0.p.r_ir, core1.p.r_cpc, core1.p.r_ir);
                        r_max_displays = r_max_displays + 1;
                    end
`endif
`endif
                    r_ipi <= {r_ipi[31:17], 1'b0, r_ipi[15:1], 1'b0};
                end else begin
`ifdef SIM_MODE
`ifndef USE_SINGLE_CORE
                    if(r_max_displays < `IPI_MAX_DISPLAYS) begin
                        $display("t=%8x send ipi to core0 w_data_wdata=%x w_grant=%1x c0pc=%x c0ir=%x c1pc=%x c1ir=%x", 
                            w_mtime, w_data_wdata, w_grant, core0.p.r_cpc, core0.p.r_ir, core1.p.r_cpc, core1.p.r_ir);
                        r_max_displays = r_max_displays + 1;
                    end
`endif
`endif
                     // signal core 0
                    if(w_data_wdata == 2)
                        r_ipi <= {r_ipi[31:17], 1'b1, r_ipi[15:1], 1'b1}; // S-priv
                    else
                        r_ipi <= {r_ipi[31:17], 1'b0, r_ipi[15:1], 1'b1}; // M-priv
                end
            end else /*if(w_offset == 28'h4)*/ begin
                if(w_data_wdata == 32'h0) begin
`ifdef SIM_MODE
`ifndef USE_SINGLE_CORE
                    if(r_max_displays < `IPI_MAX_DISPLAYS) begin
                        $display("t=%8x clear ipi core1 w_grant=%1x c0pc=%x c0ir=%x c1pc=%x c1ir=%x", 
                            w_mtime, w_grant, core0.p.r_cpc, core0.p.r_ir, core1.p.r_cpc, core1.p.r_ir);
                        r_max_displays = r_max_displays + 1;
                    end
`endif
`endif
                    r_ipi <= {r_ipi[31:18], 1'b0, r_ipi[16], r_ipi[15:2], 1'b0, r_ipi[0]};
                end else begin
`ifdef SIM_MODE
`ifndef USE_SINGLE_CORE
                    if(r_max_displays < `IPI_MAX_DISPLAYS) begin
                        $display("t=%8x send ipi to core1 w_data_wdata=%x w_grant=%1x c0pc=%x c0ir=%x c1pc=%x c1ir=%x", 
                            w_mtime, w_data_wdata, w_grant, core0.p.r_cpc, core0.p.r_ir, core1.p.r_cpc, core1.p.r_ir);
                        r_max_displays = r_max_displays + 1;
                    end
`endif
`endif
                     // signal core 1
                    if(w_data_wdata == 2)
                        r_ipi <= {r_ipi[31:18], 1'b1, r_ipi[16], r_ipi[15:2], 1'b1, r_ipi[0]}; // S-priv
                    else
                        r_ipi <= {r_ipi[31:18], 1'b0, r_ipi[16], r_ipi[15:2], 1'b1, r_ipi[0]}; // M-priv
                end
            end
        end
    end

    // shortcut to w_data_we because we do not use microcontroller
    assign w_wmtimecmp0  = (r_dev == `CLINT_BASE_TADDR && (w_offset==28'h4000 && w_grant == 0) && w_data_we != 0) ?
                                {w_mtimecmp0[63:32], w_data_wdata} :
                                (r_dev == `CLINT_BASE_TADDR && (w_offset==28'h4004 && w_grant == 0) && w_data_we != 0) ?
                                {w_data_wdata, w_mtimecmp0[31:0]} : 0;
    assign w_wmtimecmp1  = (r_dev == `CLINT_BASE_TADDR && (w_offset==28'h4008 && w_grant == 1) && w_data_we != 0) ?
                                {w_mtimecmp1[63:32], w_data_wdata} :
                                (r_dev == `CLINT_BASE_TADDR && (w_offset==28'h400c && w_grant == 1) && w_data_we != 0) ?
                                {w_data_wdata, w_mtimecmp1[31:0]} : 0;
    assign w_clint_we   = r_dev == `CLINT_BASE_TADDR && w_data_we != 0 && 
                          (((w_offset==28'h4000 || w_offset==28'h4004) && w_grant == 0) ||
                           ((w_offset==28'h4008 || w_offset==28'h400c) && w_grant == 1));

    /**********************************************************************************************/
    // OUTPUT CHAR
    UartTx UartTx0(pll_clk, RST_X, r_uart_data, r_uart_we, w_txd, w_tx_ready);

`ifdef LAUR_MEM_RB
    // xsim requires declaration before use
    reg r_rb_uart_we=0;
    reg [7:0] r_rb_uart_data;
`endif
    reg r_wait_ready=1;
    reg          r_finish=0;
    always@(posedge pll_clk) begin
        if(w_tx_ready)
            r_wait_ready <= 1;
        else
            r_wait_ready <= 0;
        // optimisation instead of w_mem_wdata put w_data_wdata
        if((w_mem_paddr==`TOHOST_ADDR && w_data_we) && (w_data_wdata[31:16]==`CMD_PRINT_CHAR) && w_tx_ready && r_wait_ready) begin
            r_uart_we   <= 1;
            r_uart_data <= w_data_wdata[7:0];
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
        if((w_mem_paddr==`TOHOST_ADDR && w_data_we) && (w_data_wdata[31:16]==`CMD_POWER_OFF)) begin
            r_finish = 1;
        end
    end

`ifdef SIM_MODE
    always@(posedge pll_clk) if (r_finish) begin
        $write("FINISH!\n");
        $finish();
    end
`endif

    /***** Keyboard Input *************************************************************************/
    wire [31:0]  w_pl_init_addr;
    wire [31:0]  w_pl_init_data;
    wire         w_pl_init_done;
    wire         w_pl_init_we;
    PLOADER ploader(pll_clk, RST_X, w_rxd, w_pl_init_addr, w_pl_init_data, w_pl_init_we,
                    w_pl_init_done, w_key_we, w_key_data);

    reg   [$clog2(`KEYBOARD_QUEUE_SIZE)-1:0] r_consf_head        = 0;  // Note!!
    reg   [$clog2(`KEYBOARD_QUEUE_SIZE)-1:0] r_consf_tail        = 0;  // Note!!

    reg         r_consf_en          = 0;
    reg   [7:0] cons_fifo [0:`KEYBOARD_QUEUE_SIZE-1];
    
`ifdef SIM_MODE
    wire w_file_we;
    read_file rf(.clk(pll_clk), .r_consf_en(r_consf_en), .we(w_file_we), .w_mtime(w_mtime), .min_time(`ENABLE_TIMER));
`endif

`ifdef SIM_MODE
    initial begin
`define LAUR_EMPTY_CONSOLE_BUFFER
`ifdef LAUR_EMPTY_CONSOLE_BUFFER
	r_consf_en = 0;
	r_consf_head = 0;
	r_consf_tail = 0;
        r_consf_cnts = 0;
`else
        r_consf_en = 1;
        cons_fifo[0] = 8'h72;  // "r"
        cons_fifo[1] = 8'h6f;  // "o"
        cons_fifo[2] = 8'h6f;  // "o"
        cons_fifo[3] = 8'h74;  // "t"
        cons_fifo[4] = 8'hd;   // "(CR)"
        cons_fifo[5] = 8'hd;   // "(CR)"
        r_consf_tail = 6;
        r_consf_cnts = 6;
`endif
    end
`endif

    reg         r_key_we    = 0;
    reg   [7:0] r_key_data  = 0;
    always@(posedge pll_clk) begin
        r_key_we    <= w_key_we;
        r_key_data  <= w_key_data;
    end

`ifdef SIM_MODE
    integer i;
`endif
    always@(posedge pll_clk) begin
        if((r_mem_paddr == (`HVC_BASE_ADDR + 4)) && r_consf_cnts && w_dram_le) begin
                //if(r_consf_en)
                    //$display("HVC_BASE_ADDR+4 r_consf_cnts=%x c=%x w_grant=%x w_pc0=%x w_pc1=%x", 
                    //    r_consf_cnts, cons_fifo[r_consf_head], w_grant, w_pc0, w_pc1);
                r_consf_en <= (r_consf_cnts<=1) ? 0 : 1;
                r_consf_head <= r_consf_head + 1;
                r_consf_cnts <= r_consf_cnts - 1;
                r_char_value <= cons_fifo[r_consf_head];
        end
`ifdef SIM_MODE
	else if(w_file_we) begin
		$display("\nw_file_we\n");
		if(r_consf_cnts != 0)
			$display("warning: w_file_we and r_consf_cnts = %d with r_consf_en=%d", r_consf_cnts, r_consf_en);
		else begin
			for(i = 0; i < rf.n; i=i+1)
				cons_fifo[r_consf_tail+i] = rf.fifo[i];
			r_consf_tail <= r_consf_tail + rf.n;
			r_consf_cnts <= rf.n;
			r_consf_en <= 1;
		end
	end
`else
        else if(r_key_we) begin
            if(r_consf_cnts < `KEYBOARD_QUEUE_SIZE) begin
                cons_fifo[r_consf_tail] <= r_key_data;
                r_consf_tail            <= r_consf_tail + 1;
                r_consf_cnts            <= r_consf_cnts + 1;
                r_consf_en              <= 1;
            end
        end
`endif
    end
    /**********************************************************************************************/
    reg r_sd_init_we=0;
    reg [31:0] r_sd_init_data=0;

`ifndef SIM_MODE
    wire [31:0] w_sd_init_data;
    wire w_sd_init_we, w_sd_init_done;
    sd_loader sd_loader(.clk27mhz(pll_clk), .resetn(RST_X), 
        .w_main_init_state(r_init_state), .DATA(w_sd_init_data), .WE(w_sd_init_we), .DONE(w_sd_init_done),
        .w_ctrl_state(r_sd_state),
        .sdcard_pwr_n(sdcard_pwr_n), .sdclk(sdclk), .sdcmd(sdcmd), 
        .sddat0(sddat0), .sddat1(sddat1), .sddat2(sddat2), .sddat3(sddat3));


    // sd state machine for copying sd to dram
    reg [7:0] r_sd_state=0;

    always @ (posedge pll_clk) begin
            if(r_sd_state == 0) begin
                if(w_sd_init_we && !w_dram_busy) begin
                    r_sd_init_we <= 1;
                    r_sd_init_data <= w_sd_init_data;
                    r_sd_state <= 1;
                    r_sd_checksum <= r_sd_checksum + w_sd_init_data;
                end
            end else if(r_sd_state == 1) begin
                if(w_dram_busy) begin
                    r_sd_init_we <= 0;
                    r_sd_state <= 2;
                end
            end else if(r_sd_state == 2) begin
                if(!w_dram_busy) begin
                    r_initaddr3 <= r_initaddr3 + 4;
                    r_sd_state <= 0;
                end
            end
        if (r_initaddr3 >= `BIN_BBL_SIZE)
            r_bblsd_done <= 1;
    end
`endif

    /**********************************************************************************************/
`ifdef SIM_MODE
    reg  [2:0] r_init_state = 5;
`else
    reg  [2:0] r_init_state = 0;
`endif
    reg  [31:0]  r_initaddr   = 0;
    reg  [31:0]  r_initaddr3  = 0;
    reg  [31:0]  r_checksum = 0, r_sd_checksum=0;
    always@(posedge pll_clk) begin
	    r_checksum <= (!RST_X)                      ? 0                             :
                      (!w_init_done & w_pl_init_we) ? r_checksum + w_pl_init_data   :
		               r_checksum;
    end
    wire [31:0] w_checksum = r_checksum;
    wire [31:0] w_sd_checksum = r_sd_checksum;
    /**************************************************************************************************/
    reg          r_bbl_done   = 0;
    reg          r_bblsd_done = 0;
    reg          r_disk_done  = 0;
`ifdef LAUR_MEM_RB
    reg  [31:0]  r_initaddr6  = 0;
`endif
    reg  [31:0]  r_initaddr2 = `BBL_SIZE ; /* initial addres for Disk Drive */

    // Zero init
    wire w_zero_we;
    reg  r_zero_we=0;
    reg  r_zero_done        = 0;
    reg  [31:0]  r_zeroaddr = 0;

`ifdef LAUR_MEM_RB
    // xsim requires declaration before use
    reg r_mem_rb_done=0;
`endif
`ifndef SIM_MODE
    always@(posedge pll_clk) begin
        r_init_state <= (!RST_X) ? 1 :
                      (r_init_state == 0)                ? 1 :
                      (r_init_state == 1 & r_zero_done)  ? 3 : // sd instead of pl
                      (r_init_state == 2 & r_bbl_done)   ? 4 :
                      (r_init_state == 3 & r_bblsd_done) ? 4 :
`ifdef LAUR_MEM_RB
                      (r_init_state == 4 & r_disk_done)  ? 6 :
                      (r_init_state == 6 & r_mem_rb_done)  ? 5 :
`else 
                      (r_init_state == 4 & r_disk_done)  ? 5 :
`endif
                      r_init_state;
    end
`endif // SIM_MODE

    wire [2:0] w_init_state = r_init_state;

    assign w_init_done = (r_init_state == 5);
        
    always@(posedge pll_clk) begin	
`ifdef SIM_MODE
	    if(r_init_state < 1)
		    $display("r_init_state=%d", r_init_state);
`endif
        if(w_pl_init_we & (r_init_state == 2))      r_initaddr      <= r_initaddr + 4;
        if(r_initaddr  >= `BIN_BBL_SIZE)            r_bbl_done      <= 1;
        //if(w_sd_init_we & (r_init_state == 3))      r_initaddr3      <= r_initaddr3 + 4;
        //if(r_initaddr3  >= `BIN_BBL_SIZE)           r_bblsd_done      <= 1;
        if(w_pl_init_we & (r_init_state == 4))      r_initaddr2     <= r_initaddr2 + 4;
        if(r_initaddr2 >= `BBL_SIZE + `BIN_DISK_SIZE)      r_disk_done     <= 1;

    end

    // xsim requires declaration before use
    reg r_set_dram_le=0;
`ifdef LAUR_MEM_RB
`ifdef LAUR_MEM_RB_ONLY_CHECK
        reg [31:0] r_rb_delay=0;
`endif
	reg [7:0] r_rb_state=0, r_rb_cnt=0;
	reg [31:0] r_rb_data=0, r_verify_checksum=0;
	wire [31:0] w_verify_checksum = r_verify_checksum;
	wire w_checksum_match = (r_verify_checksum == r_checksum);
    wire w_sd_checksum_match = (r_verify_checksum == r_sd_checksum);
    	always@(posedge pll_clk) begin
		if(r_init_state != 6) begin
			r_rb_state <= 0;
			r_set_dram_le <= 0;
		end else begin
			if(r_rb_state == 0) begin // idle
				if(!r_mem_rb_done)
					r_rb_state <= 1;
			end else if(r_rb_state == 1) begin
				if(r_initaddr6 < (`BBL_SIZE + `BIN_DISK_SIZE)) begin
					if(!w_dram_busy) begin
						r_set_dram_le <= 1;
						r_rb_state <= 7;
					end
				end else begin
					r_mem_rb_done <= 1;
					r_rb_state <= 0;
				end
			end else if(r_rb_state == 7) begin // we have sent command
				if(w_dram_busy) begin
					r_set_dram_le <= 0;
					r_rb_state <= 2;
				end
			end else if(r_rb_state == 2) begin // wait ram data
				r_set_dram_le <= 0;
				if(!w_dram_busy) begin
					// we have w_dram_odata
					r_verify_checksum <= r_verify_checksum + w_dram_odata;
					r_rb_data <= w_dram_odata;
`ifdef LAUR_MEM_RB_ONLY_CHECK
`ifdef SIM_MODE
					$display("mem[%x]: %x='%c%c%c%c'", r_initaddr6, w_dram_odata, 
						 w_dram_odata >> 24, (w_dram_odata >> 16) & 8'hff, 
						(w_dram_odata >> 8) & 8'hff, w_dram_odata & 8'hff);
`endif
					r_rb_state <= 20;
					r_rb_delay <= 0;
`else
					r_rb_state <= 3;
`endif
					r_rb_cnt <= 0;
				end
`ifdef LAUR_MEM_RB_ONLY_CHECK
			end else if(r_rb_state == 20) begin
                                if(r_rb_delay < 1) 
                                        r_rb_delay <= r_rb_delay + 1;
                                else begin
                                        r_rb_state <= 0;
                                        r_initaddr6 <= r_initaddr6 + 4;
                                        r_rb_delay <= 0;
                                end	
`endif
			end else if(r_rb_state == 3) begin // send 32 bit data
				if(w_tx_ready)
				   if(r_rb_cnt < 4) begin
						r_rb_cnt <= r_rb_cnt + 1;
						r_rb_uart_data <= r_rb_data[7:0];
						r_rb_data <= {8'h0, r_rb_data[31:8]};
						r_rb_state <= 4;
					end else begin
						r_rb_uart_we <= 0;
						r_initaddr6 <= r_initaddr6 + 4;
						r_rb_state <= 0;
					end
			end else if(r_rb_state == 4) begin // send 1 byte
				r_rb_uart_we <= 1;
				if(!w_tx_ready)
					r_rb_state <= 5;
			end else if(r_rb_state == 5) begin // done sending 1 byte
				r_rb_state <= 3;
				r_rb_uart_we <= 0;
			end
		end
    	end
`endif

    // Zero init
    wire calib_done;
    always@(posedge pll_clk) begin
`ifdef SIM_MAIN
	    r_zero_we <= 0;
	    r_zero_done <= 1;
`else
        if(!w_dram_busy && !r_zero_done && calib_done) 
				r_zero_we <= 1;
		  else if(w_dram_busy && r_zero_we) begin
            r_zero_we    <= 0;
            r_zeroaddr <= r_zeroaddr + 4;
        end
        if(r_zeroaddr >= `MEM_SIZE) r_zero_done <= 1;
`endif
    end

`ifdef SIM_MODE
    assign w_zero_we = 0;
`else
`ifdef SIM_MAIN
    assign w_zero_we = 0;
`else
    assign w_zero_we = r_zero_we;
`endif
`endif
    /**********************************************************************************************/
    wire [31:0] w_dram_addr_t   = ((w_dram_addr[31:28]==9) ?
                                   (w_dram_addr & 32'h3ffffff) + `BBL_SIZE :
                                    w_dram_addr & 32'h3ffffff);
    wire [31:0]  w_dram_addr_t2 =
                    (r_init_state == 1) ? r_zeroaddr     : 
                    (r_init_state == 2) ? r_initaddr     :
                    (r_init_state == 3) ? r_initaddr3    :
`ifdef LAUR_MEM_RB
		            (r_init_state == 6) ? r_initaddr6    :
`endif
                    (r_init_state == 4) ? r_initaddr2    : w_dram_addr_t;
    
    wire [31:0]  w_dram_wdata_t   = (r_init_state == 1) ? 32'b0 :
                                    (r_init_state == 5) ? w_dram_wdata : 
                                    (r_init_state == 3) ? r_sd_init_data : w_pl_init_data;

    wire [2:0]   w_dram_ctrl_t  = (!w_init_done) ? `FUNCT3_SW____ : w_dram_ctrl;
    /**********************************************************************************************/

`ifdef LAUR_MEM_RB
    wire w_wr_en =                 (r_init_state == 6) ? 0 :
				                    w_zero_we || w_pl_init_we || r_sd_init_we || w_dram_we_t;
`else
`ifdef SIM_MODE
        wire w_wr_en =              w_dram_we_t;
`else
    wire w_wr_en =                  w_zero_we || w_pl_init_we || r_sd_init_we || w_dram_we_t;
`endif
`endif

    wire sdram_fail;
    wire w_late_refresh;
    wire [7:0] w_mem_state;
    DRAM_conRV dram_con (
                               // user interface ports
`ifdef LAUR_MEM_RB
                               .i_rd_en(w_dram_le | r_set_dram_le),
`else
                               .i_rd_en(w_dram_le),
`endif
                               .i_wr_en(w_wr_en),
                               .i_addr(w_dram_addr_t2),
                               .i_data(w_dram_wdata_t),
                               .o_data(w_dram_odata),
                               .o_busy(w_dram_busy),
                               .i_ctrl(w_dram_ctrl_t),
                               .sys_state(r_init_state),
                               .w_bus_cpustate(w_bus_cpustate),
                               .mem_state(w_mem_state),

                               .clk(pll_clk),
                               .rst_x(RST_X),
                               .clk_sdram(clk_sdram),
                               .o_init_calib_complete(calib_done),
                               .sdram_fail(sdram_fail),
                               `ifdef TN_DRAM_REFRESH
                               .r_late_refresh(w_late_refresh),
                               `endif

                                `ifdef SIM_MODE
                                .w_mtime(w_mtime)
                                `else
                                .O_sdram_clk(O_sdram_clk),
                               .O_sdram_cke(O_sdram_cke),
                               .O_sdram_cs_n(O_sdram_cs_n),            // chip select
                               .O_sdram_cas_n(O_sdram_cas_n),           // columns address select
                               .O_sdram_ras_n(O_sdram_ras_n),           // row address select
                               .O_sdram_wen_n(O_sdram_wen_n),           // write enable
                               .IO_sdram_dq(IO_sdram_dq),       // 32 bit bidirectional data bus
                               .O_sdram_addr(O_sdram_addr),     // 11 bit multiplexed address bus
                               .O_sdram_ba(O_sdram_ba),        // two banks
                               .O_sdram_dqm(O_sdram_dqm)       // 32/4
                               `endif
                               );
    /**********************************************************************************************/

/***********************************          write time        *******************************/
`ifdef SIM_MODE
`define LAUR_WRITE_TIME
`ifdef LAUR_WRITE_TIME
    reg [63:0] old_w_mtime=0;
    always @(posedge CLK) begin
	    if(old_w_mtime != w_mtime) begin
		    old_w_mtime = w_mtime;
		    if(w_mtime % 64'd10000000 == 64'd0) begin
			    $write("w_mtime=%d ENABLE_TIMER=%d\n", w_mtime, `ENABLE_TIMER);
		    end
	    end
    end
`endif

`endif // SIM_MODE
    /*********************************************************************************************/
`ifndef SIM_MODE
    // debug on display
    max7219 max7219(.clk(pll_clk), .clkdiv(clkdiv), .reset_n(RST_X), .data_vector(data_vector),
            .clk_out(MAX7219_CLK),
            .data_out(MAX7219_DATA),
            .load_out(MAX7219_LOAD)
        );
    wire clkdiv;
    wire [31:0] data_vector;
    clkdivider cd(.clk(pll_clk), .reset_n(RST_X), .n(100), .clkdiv(clkdiv));
    assign data_vector = (w_btnr == 0 && w_btnl == 0) ? w_pc0 : w_btnl ? w_pc1 : w_sd_checksum;

    reg [31:0] rdbg=0;
    reg raux=0;

    assign w_led =  (w_btnl == 0 && w_btnr == 0) ? 
                        ~ {w_sd_checksum_match, r_mem_rb_done, w_sd_init_done, 
                           r_bbl_done, r_zero_done, calib_done & !sdram_fail & !w_late_refresh} : 
                    (w_btnl == 1 && w_btnr == 0) ? ~ rdbg[5:0]: ~ rdbg[11:6];
                    //(w_btnl == 0 && w_btnr == 1) ? ~ w_sd_init_data[5:0];
`endif
    /**********************************************************************************************/
 
`ifdef SIM_MODE
`define RAM_TRACE
`ifdef RAM_TRACE
reg [31:0] old_mem_paddr=0, old_data_data = 0, old_pc0 = 0, rcnt=0;
task ramtrace;
begin
            if (dram_con.i_rd_en && dram_con.o_busy == 0) begin
                daddr <= w_dram_addr; //dram_con.i_addr;
                dstate <= 1;
            end else if (dram_con.i_wr_en && dram_con.o_busy == 0) begin
                dstate <= 4;
                if(mmustate)
                    $fwrite(file, "dram_wr %x %x %x %x %x\n", w_dram_addr/*dram_con.i_addr*/, dram_con.i_data, w_pc0, core0.p.state, mmustate);
                else
                    $fwrite(file, "dram_wr %x %x %x %x\n", w_dram_addr/*dram_con.i_addr*/, dram_con.i_data, w_pc0, core0.p.state);
            end else if ((r_dev == `CLINT_BASE_TADDR || r_dev == `PLIC_BASE_TADDR || 
                         r_dev == `HVC_BASE_TADDR) && w_data_we == 0) begin
                dstate <= 0;
                if(r_plic_aces_t) begin
                    if(r_was_read)
                        $fwrite(file, "plic_r %x %x %x %x\n", r_mem_paddr, r_plic_odata, w_pc0, w_plic_we);
                    else if(r_was_write)
                        $fwrite(file, "plic_w %x %x %x %x\n", r_mem_paddr, w_data_wdata, w_pc0, w_plic_we);
                    else
                        $fwrite(file, "plic_nrw %x %x %x %x %x\n", r_mem_paddr, r_data_data, w_pc0, core0.p.state, w_plic_we);
                end else if(r_mem_paddr != old_mem_paddr || r_data_data != old_data_data || w_pc0 != old_pc0) begin
                    old_mem_paddr <= r_mem_paddr;
                    old_data_data <= r_data_data;
                    old_pc0 <= w_pc0;
                    $fwrite(file, "data_re %x %x %x %x\n", r_mem_paddr, r_data_data, w_pc0, core0.p.state);
                end else begin
                    if (rcnt < 100) begin
                        rcnt = rcnt + 1;
                    end else begin
                        $display("rcnt = 100 dram_con.o_busy=%x", dram_con.o_busy);
                        $finish;
                    end
                end
            end else if((r_dev == `CLINT_BASE_TADDR || r_dev == `PLIC_BASE_TADDR || 
                         r_dev == `HVC_BASE_TADDR || r_dev==4'h4/*`TOHOST_ADDR*/) && w_data_we == 1) begin
                $fwrite(file, "data_we %x %x %x %x\n", w_mem_paddr, w_data_wdata, w_pc0, core0.p.state);
                dstate <= 6;
            end else
                dstate <= 0;
end
endtask

integer file;
reg [999:0] filename;
reg [7:0] trace_state=0, dstate=0, drdev=0;
reg [31:0] daddr=0, dstart=0;
wire [3:0] mmustate=core0.mmu.r_pw_state;
always @(posedge pll_clk)
begin
    if(dstart == 0) begin
            dstart <= 1;
            $sformat(filename, "serial%0d.out", 1);
            file = $fopen(filename, "w");
    end
        if(dstate == 0) begin
            ramtrace;
        end else if (dstate == 1) begin
            if(dram_con.o_busy == 1)
                dstate <= 2;
        end else if (dstate == 2) begin
            if(dram_con.o_busy == 0) begin
                if(mmustate)
                    $fwrite(file, "dram_rd %x %x %x %x %x\n", daddr, dram_con.o_data, w_pc0, core0.p.state, mmustate);
                else
                    $fwrite(file, "dram_rd %x %x %x %x\n", daddr, dram_con.o_data, w_pc0, core0.p.state);
                ramtrace;
            end
        end else if (dstate == 4) begin // wait dram-write
            if(dram_con.o_busy == 1)
                dstate <= 5;
        end else if (dstate == 5) begin
            if(dram_con.o_busy == 0)
                ramtrace;
        end else if (dstate == 6) begin
            if(w_data_we == 0)
                ramtrace;
        end 

        if (w_mtime >= 70000000) begin
                $display("finish ram trace with dstate=%x dram_con.o_busy=%x dram_con.i_rd_en=%x r_dev=%x w_data_we=%x", 
                    dstate, dram_con.o_busy, dram_con.i_rd_en, dram_con.i_wr_en, r_dev, w_data_we);
                $fclose(file);
                dstate <= 400;
                $finish;
        end

        //if(w_pc0 >= 32'hc00001c0 && w_pc0 <= 32'hc00001c8) begin
        //    $display("pc = %x", w_pc0);
        //end
end
`endif // RAM_TRACE
`endif // SIM_MODE
endmodule

