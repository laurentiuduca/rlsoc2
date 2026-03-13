// author laurentiu cristian duca
// spdx license identifier apache
// sd driver

`include "define.vh"

module hazard3_sd #(
    parameter W_ADDR = 32,
    parameter W_DATA = 32
) (
    input wire clk,
    input wire rst_n,

    // APB Port
    input wire psel,
    input wire penable,
    input wire pwrite,
    input wire [15:0] paddr,
    input wire [31:0] pwdata,
    output reg [31:0] prdata,
    output reg pready,
    output wire pslverr,

    // sd signals
    output wire spi_mosi,
    spi_clk,
    spi_cs,
    input  wire spi_miso,

    output wire sdsbusy,
    output wire [31:0] sdspi_status
);

    reg [7:0] ctrlstate;

    wire bus_write = pwrite && psel && penable;
    wire bus_read = !pwrite && psel && penable;

    assign pslverr = 0;

    reg        outen;
    reg [ 7:0] outbyte;
    reg [31:0] auxdata = 0;

    reg [ 3:0] mcnt = 0;
    reg mr1 = 0, mr2 = 0, mw1 = 0, mw2 = 0;
    reg [7:0] midata1 = 0, midata2 = 0;
    wire [7:0] midata;
    wire [7:0] mout;
    reg [31:0] maddr1, maddr2;
    wire [31:0] maddr;
    assign maddr = (mr1 | mw1) ? maddr1 : maddr2;
    wire mw;
    assign mw = mw1 | mw2;
    assign midata = mw1 ? midata1 : midata2;

    sdspibram br (
        .clk(clk),
        .maddr(maddr),
        .midata(midata),
        .mw(mw),
        .mout(mout)
    );

    //sd state machine
    reg [7:0] state = 0, errstate = 0;
    reg [31:0] sdsbaddr = 0, oecnt = 0;
    reg sdsrd = 0, sdswr = 0;
    wire sdserror;
    reg noerror = 1;
    wire [2:0] sdserror_code;
    reg [7:0] sdsdin = 0, firstdin = 0;
    reg sdsdin_valid = 0;
    wire sdsdin_taken;
    wire [7:0] sdsdout;
    wire sdsdout_avail;
    reg sdsdout_taken = 0;
    wire [1:0] state_o;
    wire [7:0] sdsfsm_o;
    reg [7:0] firstbyte = 0, first = 0;

`ifdef SIM_MODE
`ifdef simsdspi
    `define dbgsimsd1
    `define SIMSDSIZE (10*1024*1024)
    `define SIMSDNAME "simsd.fat32"
    reg [7:0] simsdmem[0:`SIMSDSIZE-1];
    integer i;
    initial begin
        reg [7:0] b;
        integer fid, n;
        fid = $fopen(`SIMSDNAME, "rb");
        n   = $fread(simsdmem, fid);
        $display("fread %s n=%d", `SIMSDNAME, n);
        if (n != `SIMSDSIZE) $finish;
`ifdef laur0
        for (i = 0; i < SIMSDSIZE; i = i + 1) begin
            if (!feof(f)) begin
                f = $fread(b, fid);
                simsdmem[i] = b;
            end
        end
`endif
    end
`endif
`endif

`ifdef SIM_MODE
    assign sdspi_status = {
        firstbyte, sdserror_code, sdserror, 3'd0, !(ctrlstate == 1), ctrlstate[7:0], state[7:0]
    };
`else
    assign sdspi_status = {
        firstbyte, sdserror_code, sdserror, 3'd0, sdsbusy, ctrlstate[7:0], state[7:0]
    };
`endif
    `define CTRLSTATERDBLK 2
    `define CTRLSTATEWRBLK 12

    // hazard3 sd state machine
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            ctrlstate <= 0;
            pready <= 0;
            midata1 <= 0;
            maddr1 <= 0;
            mw1 <= 0;
            mr1 <= 0;
            mcnt <= 0;
            sdsbaddr <= 0;
            prdata <= 0;
            pready <= 0;
        end else if (ctrlstate == 0) begin
            pready <= 0;
            if (bus_write && pready == 0) begin
                //$display("bus w paddr=%x pwdata=%x pready=%x", paddr, pwdata, pready);
                if (paddr == 16'h8100) begin
		    `ifdef SIM_MODE
                    $display("finish");
                    $finish;
		    `endif
                end
                if (paddr < `SDSPI_BLOCKADDR) begin
                    sdsbaddr <= pwdata;
                    if (paddr - `SDSPI_DEVADDR == 0) begin
                        // read block
                        ctrlstate <= `CTRLSTATERDBLK;
                    end else if (paddr - `SDSPI_DEVADDR == 4) begin
                        // write block;
                        ctrlstate <= `CTRLSTATEWRBLK;
                    end
                end else begin
                    // write to our block mem
                    ctrlstate <= 5;
                    auxdata <= pwdata;
                    midata1 <= pwdata[7:0];
                    maddr1 <= {16'h0, paddr - `SDSPI_BLOCKADDR};
                    mw1 <= 1;
                    mcnt <= 0;
                end
            end else if (bus_read && pready == 0) begin
                //$display("bus r paddr=%x pready=%x", paddr, pready);
                if (paddr < `SDSPI_BLOCKADDR) begin
                    ctrlstate <= 1;
                end else begin
                    // read from our block mem
                    ctrlstate <= 15;
                    maddr1 <= {16'h0, paddr - `SDSPI_BLOCKADDR};
                    mr1 <= 1;
                    mcnt <= 0;
                    prdata <= 0;
                end
            end
        end else if (ctrlstate == 1) begin
            pready <= 1;
            prdata <= sdspi_status;
            ctrlstate <= 0;
	    `ifdef SIM_MODE
            $display("ctrlstate = 1, sdspi_status=%x", sdspi_status);
	    `endif
        end else if (ctrlstate == `CTRLSTATERDBLK) begin
`ifdef dbgsimsd1
            for (i = 0; i < `SDSPI_BLOCKSIZE; i = i + 1) begin
                br.m[i] = simsdmem[i+(sdsbaddr*`SDSPI_BLOCKSIZE)];
                //$write("%x ", br.m[i]);
            end
            //$write("\n");
            $display("rd block done");
`endif
            // read block command 
            ctrlstate <= 0;
            pready <= 1;
        end else if (ctrlstate == `CTRLSTATEWRBLK) begin
`ifdef dbgsimsd1
            for (i = 0; i < `SDSPI_BLOCKSIZE; i = i + 1)
            	simsdmem[i+(sdsbaddr*`SDSPI_BLOCKSIZE)] = br.m[i];
            $display("wr block done");
`endif
            // write block command
            ctrlstate <= 0;
            pready <= 1;
        end else if (ctrlstate == 5) begin
            // write to mem
            mcnt <= mcnt + 1;
            auxdata <= {8'h0, auxdata[31:8]};
            midata1 <= auxdata[15:8];
            maddr1 <= maddr1 + 1;
            if (mcnt == 0) begin
                //if(midata1)
                //	$display("\tbus w addr=%x data=%x", maddr1, midata1);
                ctrlstate <= 6;
                mw1 <= 0;
            end
        end else if (ctrlstate == 6) begin
            pready <= 1;
            ctrlstate <= 0;
        end else if (ctrlstate == 15) begin
            // read from mem
            ctrlstate <= 16;
            mr1 <= 0;
        end else if (ctrlstate == 16) begin
            mcnt   <= mcnt + 1;
            maddr1 <= maddr1 + 1;
	    // chars are contiguous in mem
            prdata <= {mout, mout, mout, mout};
	    //prdata <= mout << ((maddr1 & 3) << 3);
            if (mcnt == 0) begin
                //if(mout)
                //	$display("\tbus r paddr=%x data=%x", maddr1, mout);
                pready <= 1;
                ctrlstate <= 0;
                mr1 <= 0;
            end else ctrlstate <= 15;
            if (maddr1 == 1 && first == 0) begin
                first <= first + 1;
                firstbyte <= mout;
            end
        end
    end

    // sd spi state machine
    always @(posedge clk or negedge rst_n) begin
        if (~rst_n) begin
            state <= 0;
        end else if (state == 0) begin
            oecnt <= 0;
            if (ctrlstate == `CTRLSTATERDBLK && sdsbusy == 0) begin
                state <= 1;
            end else if (ctrlstate == `CTRLSTATEWRBLK && sdsbusy == 0) begin
                state <= 10;
            end
        end else if (state == 1) begin
            sdsrd <= 1;
            state <= 2;
        end else if (state == 2) begin
		if (sdsdout_avail) begin // && !sdserror) begin
                //sdsrd <= 0; // block transfer
                outbyte <= sdsdout;
                state   <= 3;
            end
        end else if (state == 3) begin
            sdsdout_taken <= 1;
            oecnt <= oecnt + 1;
            mw2 <= 1;
            maddr2 <= oecnt;
            midata2 <= outbyte;
            state <= 4;
            //if(oecnt == 0)
            //	firstbyte <= outbyte;
        end else if (state == 4) begin
            mw2 <= 0;
            if (!sdsdout_avail) begin
                sdsdout_taken <= 0;
                if (oecnt < `SDSPI_BLOCKSIZE) begin
                    state <= 2;
                    sdsrd <= 1;
                end else begin
                    sdsrd <= 0;
                    if (sdsbusy == 0) begin
                        // read block completed
                        state <= 0;
                    end
                end
            end
        end else if (state == 10) begin
            if (oecnt < `SDSPI_BLOCKSIZE) begin
                maddr2 <= oecnt;
                mr2 <= 1;
                state <= 16;
            end else begin
                // write block completed
                sdswr <= 0;
                if (sdsbusy == 0) begin
                    oecnt <= 0;
                    state <= 0;
                end
            end
        end else if (state == 16) begin
            // read mem
            mr2   <= 0;
            state <= 11;
        end else if (state == 11) begin
            sdswr <= 1;
            sdsdin <= mout;
            sdsdin_valid <= 1;
            state <= 12;
        end else if (state == 12) begin
            if (sdsdin_taken == 1) begin
                //sdswr <= 0; // block transfer
                sdsdin_valid <= 0;
                state <= 13;
            end
        end else if (state == 13) begin
            if (sdsdin_taken == 0) begin
                oecnt <= oecnt + 1;
                state <= 10;
            end
        end
    end

    sd_controller  /*#(.WRITE_TIMEOUT(1))*/ sdc (
        .clk  (clk),    // twice the SPI clk
        .reset(!rst_n),

        .cs(spi_cs),
        .mosi(spi_mosi),
        .miso(spi_miso),
        .sclk(spi_clk),
        .card_present(1'b1),
        .card_write_prot(1'b0),

        .rd(sdsrd),  // Should latch maddr on rising edge
        .rd_multiple(1'b0),  // Should latch maddr on rising edge
        .wr(sdswr),  // Should latch maddr on rising edge
        .wr_multiple(1'b0),  // Should latch maddr on rising edge
        .addr(sdsbaddr),
        .erase_count(8'h0),  // 8'h2 for multiple write only

        .sd_error(sdserror),  // if an error occurs, reset on next RD or WR
        .sd_busy(sdsbusy),  // '0' if a RD or WR can be accepted
        .sd_error_code(sdserror_code),  //

        .din(sdsdin),
        .din_valid(sdsdin_valid),
        .din_taken(sdsdin_taken),

        .dout(sdsdout),
        .dout_avail(sdsdout_avail),
        .dout_taken(sdsdout_taken),

        // Debug stuff
        .sd_type(state_o),
        .sd_fsm (sdsfsm_o)
    );

endmodule

module sdspibram (
    input wire clk,
    input wire [31:0] maddr,
    input wire [7:0] midata,
    input wire mw,
    output reg [7:0] mout
);

    reg [7:0] m[0:`SDSPI_BLOCKSIZE-1];
    integer i;
    initial for (i = 0; i < `SDSPI_BLOCKSIZE; i = i + 1) m[i] <= 0;
    always @(posedge clk) begin
        if (mw) m[maddr] <= midata;
        mout <= m[maddr];
    end
    //assign mout = m[maddr];
endmodule
