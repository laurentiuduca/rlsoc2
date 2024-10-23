//--------------------------------------------------------------------------------------------------------
// Module  : fpga_top
// Type    : synthesizable, FPGA's top, IP's example design
// Standard: Verilog 2001 (IEEE1364-2001)
// Function: an example of sd_file_reader, read a file from SDcard and send file content to UART
//           this example runs on Digilent Nexys4-DDR board (Xilinx Artix-7),
//           see http://www.digilent.com.cn/products/product-nexys-4-ddr-artix-7-fpga-trainer-board.html
//--------------------------------------------------------------------------------------------------------

`include "define.vh"

module sd_file_loader (
    input  wire         clk27mhz,
    // when sdcard_pwr_n = 0, SDcard power on
    output wire         sdcard_pwr_n,
    // signals connect to SD bus
    output wire         sdclk,
    inout  wire         sdcmd,
    input  wire         sddat0,
    output wire         sddat1, sddat2, sddat3,
    // led to show the status of SDcard
    output wire [5:0]  tangled,
    input wire resetn,
    input  wire [2:0]   w_main_init_state,
    input  wire [7:0]   w_ctrl_state,
    output reg  [31:0]  DATA,
    output reg          WE,
    output reg          DONE
);


wire clk = clk27mhz;
wire [8:0] led;

assign sdcard_pwr_n = 1'b0;                  // keep SDcard power-on

assign {sddat1, sddat2, sddat3} = 3'b111;    // Must set sddat1~3 to 1 to avoid SD card from entering SPI mode



//----------------------------------------------------------------------------------------------------
// sd_file_reader
//----------------------------------------------------------------------------------------------------
wire       outen;     // when outen=1, a byte of file content is read out from outbyte
wire [7:0] outbyte;   // a byte of file content

sd_file_reader #(
    .FILE_NAME_LEN    ( 11      ),         // the length of "example.txt" (in bytes)
    .FILE_NAME        ( "initmem.bin"  ),  // file name to read
    .CLK_DIV          ( 2              )   // because clk=27MHz, CLK_DIV must ≥2
) u_sd_file_reader (
    .rstn             ( resetn         ),
    .clk              ( clk            ),
    .sdclk            ( sdclk          ),
    .sdcmd            ( sdcmd          ),
    .sddat0           ( sddat0         ),
    .card_stat        ( led[3:0]       ),  // show the sdcard initialize status
    .card_type        ( led[5:4]       ),  // 0=UNKNOWN    , 1=SDv1    , 2=SDv2  , 3=SDHCv2
    .filesystem_type  ( led[7:6]       ),  // 0=UNASSIGNED , 1=UNKNOWN , 2=FAT16 , 3=FAT32 
    .file_found       ( led[  8]       ),  // 0=file not found, 1=file found
    .outen            ( outen          ),
    .outbyte          ( outbyte        )
);

    assign tangled = ~{DONE, led[8:4]};

    reg [7:0] state=0;
    reg [1:0] waddr=0;
    reg [7:0] mem[0:3];
    reg       rdone;
    reg [31:0] rsector = 0, i=0;
    
    always @(posedge clk27mhz) begin
        if(!resetn) begin
            rsector <= 0;
            state <= 0;
            WE <= 0;
            DONE <= 0;
            i <= 0;
        end else begin
            if(state == 0) begin
                if (DONE==0) begin
                    if(rdone) begin
                        state <= 20;
                    end
                end
            end else if(state == 20) begin
                if(w_ctrl_state == 0)
                    if(i < `BIN_SIZE) begin
                        WE <= 1;
                        i <= i + 4;
                        state <= 21;
                    end
            end else if(state == 21) begin
                if(w_ctrl_state != 0) begin
                    WE <= 0;
                    state <= 0;
                    if(i>=`BIN_SIZE)
                        DONE <= 1;
                end
            end
        end
    end

    reg rstatechanged=0;
    always @(posedge clk27mhz) begin
        if(!resetn) begin
            waddr <= 0;
            DATA <= 0;
        end else begin
            if(DONE==0 && outen && w_main_init_state == 3) begin
                mem[waddr] <= outbyte;
                waddr <= (waddr + 1) & 2'b11;
                if(waddr == 2'b11) begin
                    DATA <= {outbyte, mem[2], mem[1], mem[0]};
                    rdone <= 1;
                end
            end else if (rdone)
                rdone <= 0;
        end
    end

endmodule
