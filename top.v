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
        .CLK(CLK), .RST_X(RST_X), .w_hart_id(0), .w_ipi(bus_ipi),
        .w_init_done(w_init_done), .w_tx_ready(w_tx_ready),
        .w_mem_paddr(bus_mem_paddr[0]), .w_mem_we(bus_mem_we[0]),
        .w_data_wdata(bus_data_wdata[0]), .w_data_data(bus_data_data[0]),
        .w_mtime(bus_mtime[0]), .w_mtimecmp(bus_mtimecmp[0]), .w_wmtimecmp(bus_wmtimecmp[0]), .w_clint_we(bus_clint_we[0]),
        .w_pw_state(bus_pw_state[0]), 
        .w_tlb_req(bus_tlb_req[0]), .w_tlb_busy(bus_tlb_busy[0]),
        .w_mip(bus_mip[0]), .w_wmip(bus_wmip[0]), .w_plic_we(bus_plic_we[0]),
        .w_dram_addr(bus_dram_addr[0]), .w_dram_wdata(bus_dram_wdata[0]), .w_dram_odata(bus_dram_odata[0]), .w_dram_we_t(bus_dram_we_t[0]),
        .w_dram_busy(bus_dram_busy[0]), .w_dram_ctrl(bus_dram_ctrl[0]), .w_dram_le(bus_dram_le[0])
    );

     m_cpummusim core1(
        .CLK(CLK), .RST_X(RST_X), .w_hart_id(1), .w_ipi(bus_ipi),
        .w_init_done(w_init_done), .w_tx_ready(w_tx_ready),
        .w_mem_paddr(bus_mem_paddr[1]), .w_mem_we(bus_mem_we[1]),
        .w_data_wdata(bus_data_wdata[1]), .w_data_data(bus_data_data[1]),
        .w_mtime(bus_mtime[1]), .w_mtimecmp(bus_mtimecmp[1]), .w_wmtimecmp(bus_wmtimecmp[1]), .w_clint_we(bus_clint_we[1]),
        .w_pw_state(bus_pw_state[1]), 
        .w_tlb_req(bus_tlb_req[1]), .w_tlb_busy(bus_tlb_busy[1]),
        .w_mip(bus_mip[1]), .w_wmip(bus_wmip[1]), .w_plic_we(bus_plic_we[1]),
        .w_dram_addr(bus_dram_addr[1]), .w_dram_wdata(bus_dram_wdata[1]), .w_dram_odata(bus_dram_odata[1]), .w_dram_we_t(bus_dram_we_t[1]),
        .w_dram_busy(bus_dram_busy[1]), .w_dram_ctrl(bus_dram_ctrl[1]), .w_dram_le(bus_dram_le[1])
    );   
    
    busarbiter ba(.CLK(CLK), .RST_X(RST_X), .w_grant(w_grant),
        .w_init_done(w_init_done), .w_tx_ready(w_tx_ready),
        .w_mem_paddr(w_mem_paddr), .w_mem_we(w_mem_we),
        .w_data_wdata(w_data_wdata), .w_data_data(w_data_data),
        .w_mtime(w_mtime), .w_mtimecmp(w_mtimecmp), .w_wmtimecmp(w_wmtimecmp), .w_clint_we(w_clint_we),
        .w_tlb_req(w_tlb_req), .w_tlb_busy(w_tlb_busy),
        .w_mip(w_mip), .w_wmip(w_wmip), .w_plic_we(w_plic_we),
        .w_dram_addr(w_dram_addr), .w_dram_wdata(w_dram_wdata), .w_dram_odata(w_dram_odata), .w_dram_we_t(w_dram_we_t),
        .w_dram_busy(w_dram_busy), .w_dram_ctrl(w_dram_ctrl), .w_dram_le(w_dram_le),

        .bus_mem_paddr(bus_mem_paddr), .bus_mem_we(bus_mem_we),
        .bus_data_wdata(bus_data_wdata), .bus_data_data(bus_data_data),
        .bus_mtime(bus_mtime), .bus_mtimecmp(bus_mtimecmp), .bus_wmtimecmp(bus_wmtimecmp), .bus_clint_we(bus_clint_we),
        .bus_pw_state(bus_pw_state), .bus_tlb_req(bus_tlb_req), .bus_tlb_busy(bus_tlb_busy),
        .bus_mip(bus_mip), .bus_wmip(bus_wmip), .bus_plic_we(bus_plic_we),
        .bus_dram_addr(bus_dram_addr), .bus_dram_wdata(bus_dram_wdata), .bus_dram_odata(bus_dram_odata), .bus_dram_we_t(bus_dram_we_t),
        .bus_dram_busy(bus_dram_busy), .bus_dram_ctrl(bus_dram_ctrl), .bus_dram_le(bus_dram_le)
    );

    /**********************************************************************************************/
    // bus interface

    wire w_init_done;
    wire [31:0] w_mem_paddr, bus_mem_paddr[0:`NCORES-1];
    wire w_mem_we, bus_mem_we[0:`NCORES-1];
    wire [31:0] w_data_wdata, bus_data_wdata[0:`NCORES-1];
    wire [31:0] w_data_data, bus_data_data[0:`NCORES-1];
    wire [63:0] w_mtime, w_mtimecmp, w_wmtimecmp, bus_mtime[0:`NCORES-1], bus_mtimecmp[0:`NCORES-1], bus_wmtimecmp[0:`NCORES-1];
    wire w_clint_we, bus_clint_we[0:`NCORES-1];
    wire [2:0]  w_pw_state, bus_pw_state[0:`NCORES-1];
    wire [1:0]  w_tlb_req, bus_tlb_req[0:`NCORES-1];
    wire        w_tlb_busy, bus_tlb_busy[0:`NCORES-1];
    wire [31:0] w_mip, w_wmip, bus_mip[0:`NCORES-1], bus_wmip[0:`NCORES-1];
    wire w_plic_we, bus_plic_we[0:`NCORES-1];
    wire [31:0] w_dram_addr, bus_dram_addr[0:`NCORES-1];
    wire [31:0] w_dram_wdata, bus_dram_wdata[0:`NCORES-1];
    wire [31:0] w_dram_odata, bus_dram_odata[0:`NCORES-1];
    wire w_dram_we_t, bus_dram_we_t[0:`NCORES-1];
    wire w_dram_busy, bus_dram_busy[0:`NCORES-1];
    wire [2:0]   w_dram_ctrl, bus_dram_ctrl[0:`NCORES-1];
    wire w_dram_le, bus_dram_le[0:`NCORES-1];

    wire [31:0] w_grant;
    wire [31:0] bus_ipi;
    /**********************************************************************************************/
    wire        w_isread        = (w_tlb_req == `ACCESS_READ);
    wire        w_iswrite       = (w_tlb_req == `ACCESS_WRITE);

    wire  [3:0] w_dev       = w_mem_paddr[31:28];// & 32'hf0000000;
    wire  [3:0] w_virt      = w_mem_paddr[27:24];// & 32'h0f000000;
    wire  [27:0] w_offset   = w_mem_paddr & 28'h7ffffff;
    reg   [31:0] r_mem_paddr= 0;
    reg   [3:0] r_dev       = 0;// & 32'hf0000000;
    reg   [3:0] r_virt      = 0;// & 32'h0f000000;
    always@(posedge CLK) begin
        r_dev   <= w_dev;
        r_virt  <= w_virt;
        r_mem_paddr <= w_mem_paddr;
    end

    /***********************************          OUTPUT        ***********************************/
    reg  [31:0] r_data_data = 0;
    always@(*) begin
        case (r_dev)
            `CLINT_BASE_TADDR : r_data_data <= r_clint_odata;
            `PLIC_BASE_TADDR  : r_data_data <= r_plic_odata;
            `HVC_BASE_TADDR  : if(r_mem_paddr == `HVC_BASE_ADDR) begin
                                    //$display("HVC_BASE_ADDR %x", r_consf_cnts);
                                    r_data_data <= {24'h0, /*8-$clog2(`KEYBOARD_QUEUE_SIZE)-1*/2'h0, r_consf_cnts};
                                end else if(r_mem_paddr == (`HVC_BASE_ADDR + 4)) begin
                                    //$display("HVC_BASE_ADDR+4 r_char_value %x", r_char_value);
                                    r_data_data <= {24'h0, r_char_value};
                                end
            default           : r_data_data <= w_dram_odata;
        endcase
    end
    assign w_data_data = r_data_data;

    /*********************************          INTERRUPTS          *********************************/
    wire [31:0] w_cons_irq=0;
    wire        w_cons_irq_oe=0;
    wire        w_key_req=0;
    wire [31:0] w_virt_irq      = w_cons_irq;
    wire        w_virt_irq_oe   = w_cons_irq_oe | w_key_req;
    // PLIC
    reg  [31:0] plic_served_irq     = 0;
    reg  [31:0] plic_pending_irq    = 0;
    reg  [31:0] r_plic_odata        = 0;
    // CLINT
    reg  [31:0] r_clint_odata       = 0;

    wire [31:0] w_plic_pending_irq_nxt  =   w_virt_irq_oe ? w_virt_irq : plic_pending_irq;
    wire [31:0] w_plic_mask             =   w_plic_pending_irq_nxt & ~plic_served_irq;
    wire [31:0] w_plic_served_irq_nxt   =   (w_virt_irq_oe) ? plic_served_irq :
                                            (w_isread) ? plic_served_irq | w_plic_mask :
                                            plic_served_irq & ~(1 << (w_data_wdata-1));

    wire w_plic_aces = (w_dev == `PLIC_BASE_TADDR && !w_tlb_busy &&
            ((w_isread && w_plic_mask != 0) || (w_iswrite && w_offset == `PLIC_HART_BASE+4)));

    reg  [31:0] r_wmip = 0;
    reg         r_plic_we = 0;

    reg  [31:0] r_plic_pending_irq_t    = 0;
    reg  [31:0] r_plic_served_irq_t     = 0;

    reg         r_virt_irq_oe_t = 0;
    reg         r_plic_aces_t   = 0;

    reg [32-1:0] r_ipi=0;
    assign bus_ipi = r_ipi;

    wire [31:0] w_plic_mask_nxt = r_plic_pending_irq_t & ~r_plic_served_irq_t;

    always@(posedge CLK) begin
        if(!w_tlb_busy) begin
            //r_plic_we   <= (w_virt_irq_oe || w_plic_aces);
            r_virt_irq_oe_t         <= w_virt_irq_oe;
            r_plic_aces_t           <= w_plic_aces;
            r_plic_pending_irq_t    <= w_plic_pending_irq_nxt;
            r_plic_served_irq_t     <= w_plic_served_irq_nxt;
        end
    end

    assign w_plic_we      = (r_virt_irq_oe_t || r_plic_aces_t);//r_plic_we;
    assign w_wmip  = (w_plic_mask_nxt) ? w_mip | (`MIP_MEIP | `MIP_SEIP) :
                            w_mip & ~(`MIP_MEIP | `MIP_SEIP);

    always@(posedge CLK) begin
        if(w_plic_aces) begin
            r_plic_odata    <= (w_plic_mask!=0) ? w_plic_mask : 0;
            plic_served_irq <= w_plic_served_irq_nxt;
        end

        if(w_virt_irq_oe) begin
            plic_pending_irq    <= w_virt_irq;
        end

        r_clint_odata <=    (w_offset==28'hbff8) ? w_mtime[31:0] :
                            (w_offset==28'hbffc) ? w_mtime[63:32] :
                            (w_offset==28'h4000) ? w_mtimecmp[31:0] :
                            (w_offset==28'h4004) ? w_mtimecmp[63:32] : 0;
        
        // one core sends ipi, the target clears it
        if(r_dev == `CLINT_BASE_TADDR && w_offset[27:8]==20'h0) begin
            if(w_data_data == 32'h0) // clear ipi
                if(w_grant == 0)
                    r_ipi <= {r_ipi[31:1], 1'b0};
                else
                    r_ipi <= {r_ipi[31:2], 1'b0,r_ipi[0]};
            else // send ipi
                if(w_grant == 0)
                    r_ipi <= 32'h02; // signal core 1
                else
                    r_ipi <= 32'h01; // signal core 0
        end
    end

    // shortcut to w_data_we because we do not use microcontroller
    wire w_data_we = w_mem_we;
    assign w_wmtimecmp  = (r_dev == `CLINT_BASE_TADDR && w_offset==28'h4000 && w_data_we != 0) ?
                                {w_mtimecmp[63:32], w_data_wdata} :
                                (r_dev == `CLINT_BASE_TADDR && w_offset==28'h4004 && w_data_we != 0) ?
                                {w_data_wdata, w_mtimecmp[31:0]} : 0;
    assign w_clint_we   = (r_dev == `CLINT_BASE_TADDR && w_offset[27:23]==4 && w_data_we != 0); // do not write ipi_clear

    /**********************************************************************************************/
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
        // optimisation instead of w_mem_wdata put w_data_wdata
        if((w_mem_paddr==`TOHOST_ADDR && w_mem_we) && (w_data_wdata[31:16]==`CMD_PRINT_CHAR)) begin
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
        if((w_mem_paddr==`TOHOST_ADDR && w_mem_we) && (w_data_wdata[31:16]==`CMD_POWER_OFF)) begin
            r_finish = 1;
        end
    end
    always@(posedge CLK) if (r_finish) begin
        $write("FINISH!\n");
        $finish();
    end

    /**********************************************************************************************/
    /***** Keyboard Input *************************************************************************/

    wire [31:0]  w_pl_init_addr;
    wire [31:0]  w_pl_init_data;
    wire         w_pl_init_done;
    wire         w_pl_init_we;
    wire         w_rxd;
    PLOADER ploader(CLK, RST_X, w_rxd, w_pl_init_addr, w_pl_init_data, w_pl_init_we,
                    w_pl_init_done, w_key_we, w_key_data);

    `define KEYBOARD_QUEUE_SIZE 32
    reg   [$clog2(`KEYBOARD_QUEUE_SIZE)-1:0] r_consf_head        = 0;  // Note!!
    reg   [$clog2(`KEYBOARD_QUEUE_SIZE)-1:0] r_consf_tail        = 0;  // Note!!
    reg   [$clog2(`KEYBOARD_QUEUE_SIZE):0] r_consf_cnts        = 0;  // Note!!
    reg         r_consf_en          = 0;
    reg   [7:0] cons_fifo [0:15];
    reg [7:0] r_char_value=0;
`ifdef SIM_MODE
    wire w_file_we;
    read_file rf(.clk(CLK), .r_consf_en(r_consf_en), .we(w_file_we), .w_mtime(w_mtime), .min_time(`ENABLE_TIMER));
`endif

`ifdef SIM_MODE
    initial begin
//`define LAUR_EMPTY_CONSOLE_BUFFER
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

    wire        w_key_we;
    wire  [7:0] w_key_data;
    reg         r_key_we    = 0;
    reg   [7:0] r_key_data  = 0;
    always@(posedge CLK) begin
        r_key_we    <= w_key_we;
        r_key_data  <= w_key_data;
    end

`ifdef SIM_MODE
    integer i;
`endif
    reg r_read_a_char=0;
    always@(posedge CLK) begin
        if(r_mem_paddr != (`HVC_BASE_ADDR + 4))
            	r_read_a_char <= 0;
        else 
	if((r_mem_paddr == (`HVC_BASE_ADDR + 4)) && !r_read_a_char && r_consf_cnts)
	    	r_read_a_char <= 1;
        if((r_mem_paddr == (`HVC_BASE_ADDR + 4)) && !r_read_a_char && r_consf_cnts) begin
                $display("HVC_BASE_ADDR+4 r_consf_cnts %x", r_consf_cnts);
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
			for(i = 0; i < rf.n; i++)
				cons_fifo[r_consf_tail+i] = rf.fifo[i];
			r_consf_tail <= r_consf_tail + rf.n;
			r_consf_cnts <= rf.n;
			r_consf_en <= 1;
		end
	end
`else
        else if(r_key_we) begin
            $display("r_key_we  r_consf_cnts %x", r_consf_cnts);
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
`ifdef SIM_MODE
    reg  [2:0] r_init_state = 5;
`else
    reg  [2:0] r_init_state = 0;
`endif
    reg  [31:0]  r_initaddr  = 0;
    reg  [31:0]  r_checksum = 0;
    always@(posedge CLK) begin
	    r_checksum <= (!RST_X)                      ? 0                             :
                      (!w_init_done & w_pl_init_we) ? r_checksum + w_pl_init_data   :
		               r_checksum;
    end

    wire w_checksum = r_checksum;

    /**************************************************************************************************/
    reg          r_bbl_done   = 0;
    reg          r_disk_done  = 0;
    reg          r_dtree_done = 0;
`ifdef LAUR_MEM_RB
    reg  [31:0]  r_initaddr6  = 0;
`endif
    reg  [31:0]  r_initaddr2 = `BBL_SIZE ; /* initial addres for Disk Drive */
    reg  [31:0]  r_initaddr3 = `D_INITD_ADDR ; /* initial address of Device Tree */

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
    always@(posedge CLK) begin
        r_init_state <= (!RST_X) ? 0 :
                      (r_init_state == 0)                ? 1 :
                      (r_init_state == 1 & r_zero_done)  ? 2 :
		      (r_init_state == 2 & r_bbl_done)   ? 3 :
                      (r_init_state == 3 & r_dtree_done) ? 4 :  
`ifdef LAUR_MEM_RB
		      (r_init_state == 4 & r_disk_done)  ? 6 :
		      (r_init_state == 6 & r_mem_rb_done)  ? 5 :
`else 
                      (r_init_state == 4 & r_disk_done)  ? 5 :
`endif
                      r_init_state;
    end
`endif

    wire [2:0] w_init_state = r_init_state;

    assign w_init_done = (r_init_state == 5);
        
    always@(posedge CLK) begin	
	    if(r_init_state < 1)
		    $display("r_init_state=%d", r_init_state);
        if(w_pl_init_we & (r_init_state == 2)) begin     r_initaddr      <= r_initaddr + 4; end
        if(r_initaddr  >= `BIN_BBL_SIZE)            r_bbl_done      <= 1;
        if(w_pl_init_we & (r_init_state == 3))      r_initaddr3     <= r_initaddr3 + 4;
        if(r_initaddr3 >= (`D_INITD_ADDR + `D_SIZE_DEVT))  r_dtree_done    <= 1;
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
	assign w_verify_checksum = r_verify_checksum;
	wire w_checksum_match = (r_verify_checksum == r_checksum);
    	always@(posedge CLK) begin
		if(r_init_state != 6) begin
			r_rb_state <= 0;
			r_set_dram_le <= 0;
		end else begin
			if(r_rb_state == 0) begin // idle
				if(!r_mem_rb_done)
					r_rb_state <= 1;
			end else if(r_rb_state == 1) begin
				// memory is 0 between (`D_INITD_ADDR + `D_SIZE_DEVT) and `BBL_SIZE
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
					$display("mem[%x]: %x='%c%c%c%c'", r_initaddr6, w_dram_odata, 
						 w_dram_odata >> 24, (w_dram_odata >> 16) & 8'hff, 
						(w_dram_odata >> 8) & 8'hff, w_dram_odata & 8'hff);
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
    always@(posedge CLK) begin
`ifdef SIM_MAIN
	    r_zero_we <= 0;
	    r_zero_done <= 1;
`else
`ifndef ARTYA7
        if(!w_dram_busy & !r_zero_done) r_zero_we <= 1;
`else
        if(!w_dram_busy & !r_zero_done & calib_done) r_zero_we <= 1;
`endif
        if(r_zero_we) begin
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
`ifdef LAUR_MEM_RB
		            (r_init_state == 6) ? r_initaddr6    :
`endif
                    (r_init_state == 3) ? r_initaddr3    : 
                    (r_init_state == 4) ? r_initaddr2    : w_dram_addr_t;
    
    wire [31:0]  w_dram_wdata_t   =   (r_init_state == 1) ? 32'b0 :
                                    (r_init_state == 5) ? w_dram_wdata : w_pl_init_data;

    wire [2:0]   w_dram_ctrl_t  = (!w_init_done) ? `FUNCT3_SW____ : w_dram_ctrl;
    /**********************************************************************************************/

`ifdef LAUR_MEM_RB
    wire w_wr_en =                 (r_init_state == 6) ? 0 :
				                    w_zero_we || w_pl_init_we || w_dram_we_t;
`else
    wire w_wr_en =                  w_zero_we || w_pl_init_we || w_dram_we_t;
`endif


`ifdef SIM_MODE
    m_dram_sim #(`MEM_SIZE) idbmem(.CLK(CLK), .w_addr(w_dram_addr_t2), .w_odata(w_dram_odata), 
        .w_we(w_dram_we_t), .w_le(w_dram_le), .w_wdata(w_dram_wdata_t), .w_ctrl(w_dram_ctrl_t), .w_stall(w_dram_busy), 
        .w_mtime(w_mtime[31:0]));
`else
    DRAM_conRV dram_con (
                               // user interface ports
`ifdef LAUR_MEM_RB
                               .i_rd_en(w_dram_le | r_set_dram_le)
`else
                               .i_rd_en(w_dram_le),
`endif
                               .i_wr_en(w_wr_en),
                               .i_addr(w_dram_addr_t2),
                               .i_data(w_dram_wdata_t),
                               .o_data(w_dram_odata),
                               .o_busy(w_dram_busy),
                               .i_ctrl(w_dram_ctrl_t),
                               // input clk, rst (active-low)
                               .mig_clk(mig_clk),
                               .mig_rst_x(mig_rst_x),
`ifdef ARTYA7
                               .ref_clk(ref_clk),
`endif
                               // ddr interface ports
`ifndef ARTYA7
                               .ddr2_dq(ddr2_dq),
                               .ddr2_dqs_n(ddr2_dqs_n),
                               .ddr2_dqs_p(ddr2_dqs_p),
                               .ddr2_addr(ddr2_addr),
                               .ddr2_ba(ddr2_ba),
                               .ddr2_ras_n(ddr2_ras_n),
                               .ddr2_cas_n(ddr2_cas_n),
                               .ddr2_we_n(ddr2_we_n),
                               .ddr2_ck_p(ddr2_ck_p),
                               .ddr2_ck_n(ddr2_ck_n),
                               .ddr2_cke(ddr2_cke),
                               .ddr2_cs_n(ddr2_cs_n),
                               .ddr2_dm(ddr2_dm),
                               .ddr2_odt(ddr2_odt),
`else
                               .ddr3_dq(ddr3_dq),
                               .ddr3_dqs_n(ddr3_dqs_n),
                               .ddr3_dqs_p(ddr3_dqs_p),
                               .ddr3_addr(ddr3_addr),
                               .ddr3_ba(ddr3_ba),
                               .ddr3_ras_n(ddr3_ras_n),
                               .ddr3_cas_n(ddr3_cas_n),
                               .ddr3_we_n(ddr3_we_n),
                               .ddr3_ck_p(ddr3_ck_p),
                               .ddr3_ck_n(ddr3_ck_n),
                               .ddr3_reset_n(ddr3_reset_n),
                               .ddr3_cke(ddr3_cke),
                               .ddr3_cs_n(ddr3_cs_n),
                               .ddr3_dm(ddr3_dm),
                               .ddr3_odt(ddr3_odt),
`endif
                               // output clk, rst (active-low)
                               .o_clk(o_clk),
                               .o_rst_x(o_rst_x),
                               // other
                               .o_init_calib_complete(calib_done)
                               );
`endif

`ifndef ARTYA7
    wire [15:0] ddr2_dq;
    wire [1:0]  ddr2_dqs_n;
    wire [1:0]  ddr2_dqs_p;
    wire [12:0] ddr2_addr;
    wire [2:0]  ddr2_ba;
    wire        ddr2_ras_n;
    wire        ddr2_cas_n;
    wire        ddr2_we_n;
    wire        ddr2_ck_p;
    wire        ddr2_ck_n;
    wire        ddr2_cke;
    wire        ddr2_cs_n;
    wire [1:0]  ddr2_dm;
    wire        ddr2_odt;
`else
    wire ref_clk;
    wire [15:0] ddr3_dq;
    wire [1:0]  ddr3_dqs_n;
    wire [1:0]  ddr3_dqs_p;
    wire [13:0] ddr3_addr;
    wire [2:0]  ddr3_ba;
    wire        ddr3_ras_n;
    wire        ddr3_cas_n;
    wire        ddr3_we_n;
    wire        ddr3_ck_p;
    wire        ddr3_ck_n;
    wire        ddr3_reset_n;
    wire        ddr3_cke;
    wire        ddr3_cs_n;
    wire [1:0]  ddr3_dm;
    wire        ddr3_odt;
`endif

    /*********************************************************************************************/
    // first 4 leds are set in main.v
    wire [15:0] w_led;
`ifdef LAUR_MEM_RB
    assign w_led = ({r_rb_state[2:0], w_checksum_match} << 12) | (r_mem_rb_done << 11) | (r_init_state << 8)
                    | ({w_pl_init_done, r_disk_done, r_bbl_done, r_zero_done} << 4) | r_init_state;
`else
    assign w_led = /*(w_proc_busy << 12) | (r_mc_mode << 8)*/ 0
                    | ({w_pl_init_done, r_disk_done, r_bbl_done, r_zero_done} << 4) | r_init_state;
`endif

    /**********************************************************************************************/
    // LOAD linux
    integer j;
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
	    idbmem.idbmem.mem[j]=mem_disk[i];
`else
	    idbmem.cache_ctrl.mi.mem[j]=mem_disk[i];
`endif
`else
	    idbmem.idbmem.mem[j]=mem_disk[i];
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
        idbmem.idbmem.mem[j]=mem_bbl[i];
`else
	    idbmem.cache_ctrl.mi.mem[j]=mem_bbl[i];
`endif
`else
	    idbmem.idbmem.mem[j]=mem_bbl[i];
`endif // DRAM_SIM
            j=j+1;
        end
        $write("-------------------------------------------------------------------\n");
    end

/**********************************************************************************************/

/***********************************          write time        *******************************/
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

`define RAM_DEBUG 
`ifdef RAM_DEBUG
reg [31:0] o_pc0=-1, o_ir0=-1, o_pc1=-1, o_ir1=-1, bbl_cnt=0, old_time=-1;
always @(posedge CLK)
begin
    if((core0.p.r_cpc != o_pc0 || core0.p.r_ir != o_ir0 || core1.p.r_cpc != o_pc1 || core1.p.r_ir != o_ir1 || w_mtime != old_time) && bbl_cnt < 50) begin
		o_pc0 <= core0.p.r_cpc;
		o_ir0 <= core0.p.r_ir;
		o_pc1 <= core1.p.r_cpc;
		o_ir1 <= core1.p.r_ir;
		bbl_cnt <= bbl_cnt + 1;
		$write("t=%08d pc0=%08x ir0=%08x pc1=%08x ir1=%08x grant=%x state=%x a_w_dram_busy=%x w_dram_busy=%x le=%x w=%x mw=%x bus_dram_busy=%x,%x \n",
                	core0.p.mtime[31:0], 
                    core0.p.r_cpc, core0.p.r_ir,
                    core1.p.r_cpc, core1.p.r_ir,
                    ba.grant[0], ba.state,
                    ba.a_w_dram_busy, w_dram_busy, 
                    w_dram_le, w_dram_we_t, w_mem_we,
                    bus_dram_busy[0], bus_dram_busy[1]
        );
	end

end
`endif
endmodule

