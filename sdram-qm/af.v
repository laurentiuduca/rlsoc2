module asyncfifo #(
                               parameter DATA_WIDTH  = 512,
                               parameter ADDR_WIDTH  = 8, // FIFO_DEPTH = 2^ADDR_WIDTH
			       parameter  qid = 0)
    (
     input  wire                    wclk,
         input  wire                    rclk,
     input  wire                    i_wrst_x,
     input  wire                    i_rrst_x,
         input  wire                    i_wen,
         input  wire [DATA_WIDTH-1 : 0] i_data,
     input  wire                    i_ren,
         output wire [DATA_WIDTH-1 : 0] o_data,
         output wire                    o_empty,
         output wire                    o_full);

    reg  [DATA_WIDTH-1 : 0] afifo[(2**ADDR_WIDTH)-1 : 0];
    reg  [ADDR_WIDTH : 0]   waddr;
    reg  [ADDR_WIDTH : 0]   raddr;

    reg  [ADDR_WIDTH : 0]   raddr_gray1;
    reg  [ADDR_WIDTH : 0]   raddr_gray2;

    reg  [ADDR_WIDTH : 0]   waddr_gray1;
    reg  [ADDR_WIDTH : 0]   waddr_gray2;

    wire [DATA_WIDTH-1 : 0] data;

    wire [ADDR_WIDTH : 0]   raddr_gray;
    wire [ADDR_WIDTH : 0]   waddr_gray;

    wire [ADDR_WIDTH : 0]   raddr2;
    wire [ADDR_WIDTH : 0]   waddr2;

    genvar genvar_i;

    // output signals
    assign o_data  = data;
    assign o_empty = (raddr == waddr2);
    assign o_full  = (waddr[ADDR_WIDTH] != raddr2[ADDR_WIDTH]) &&
                     (waddr[ADDR_WIDTH-1 : 0] == raddr2[ADDR_WIDTH-1 : 0]);

    // binary code to gray code
    assign raddr_gray = raddr[ADDR_WIDTH : 0] ^ {1'b0, raddr[ADDR_WIDTH : 1]};
    assign waddr_gray = waddr[ADDR_WIDTH : 0] ^ {1'b0, waddr[ADDR_WIDTH : 1]};

    // gray code to binary code
    generate
            for (genvar_i = 0; genvar_i <= ADDR_WIDTH; genvar_i = genvar_i + 1) begin
                    assign raddr2[genvar_i] = ^raddr_gray2[ADDR_WIDTH : genvar_i];
                    assign waddr2[genvar_i] = ^waddr_gray2[ADDR_WIDTH : genvar_i];
            end
    endgenerate

    // double flopping read address before using it in write clock domain
    always @(posedge wclk) begin
            if (!i_wrst_x) begin
                    raddr_gray1 <= 0;
                    raddr_gray2 <= 0;
            end else begin
                    raddr_gray1 <= raddr_gray;
                    raddr_gray2 <= raddr_gray1;
            end
    end

    // double flopping write address before using it in read clock domain
    always @(posedge rclk) begin
            if (!i_rrst_x) begin
                    waddr_gray1 <= 0;
                    waddr_gray2 <= 0;
            end else begin
                    waddr_gray1 <= waddr_gray;
                    waddr_gray2 <= waddr_gray1;
            end
    end

    `ifdef SIM_MODE
    `define dbgfifo
    reg [7:0] rcnt=0, wcnt=0;
    `endif

    // read
    assign data = afifo[raddr[ADDR_WIDTH-1 : 0]];
    always @(posedge rclk) begin
            if (!i_rrst_x) begin
                    raddr <= 0;
            end else if (i_ren) begin
		`ifdef dbgfifo
			if(rcnt < 1) begin
					$display("fifo %1x read: raddr=%x data={%x,%x,%x,%x,%x}", qid, raddr, 
						data[69:38], data[37:34], data[33], data[32], data[31:0]);
				rcnt <= rcnt + 1;
			end
		`endif
                    raddr <= raddr + 1;
            end
    end

    // write
    always @(posedge wclk) begin
            if (!i_wrst_x) begin
                    waddr <= 0;
            end else if (i_wen) begin
                `ifdef dbgfifo
			if(wcnt < 1) begin
	                        	$display("fifo %1x write: waddr=%x i_data={%x,%x,%x,%x,%x}", qid, waddr, 
						i_data[69:38], i_data[37:34], i_data[33], i_data[32], i_data[31:0]);
				wcnt <= wcnt + 1;
			end
                `endif
		    afifo[waddr[ADDR_WIDTH-1 : 0]] <= i_data;
                    waddr <= waddr + 1;
            end
    end

endmodule

