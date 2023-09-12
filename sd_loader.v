// modified by Laurentiu-Cristian Duca, 2023-09-12
// adapted from https://github.com/WangXuan95/FPGA-SDcard-Reader
//--------------------------------------------------------------------------------------------------------
// Module  : fpga_top
// Type    : synthesizable, FPGA's top, IP's example design
// Standard: Verilog 2001 (IEEE1364-2001)
// Function: an example of sd_reader, read a sector (512B) from SDcard and send its content to UART
//           this example runs on Digilent Nexys4-DDR board (Xilinx Artix-7),
//           see http://www.digilent.com.cn/products/product-nexys-4-ddr-artix-7-fpga-trainer-board.html
//--------------------------------------------------------------------------------------------------------

`include "define.vh"

module sd_loader (
    input  wire         clk27mhz,
    // rstn active-low, You can re-read SDcard by pushing the reset button.
    input  wire         resetn,
    // when sdcard_pwr_n = 0, SDcard power on
    output wire         sdcard_pwr_n,
    // signals connect to SD bus
    output wire         sdclk,
    inout  wire         sdcmd,
    input  wire         sddat0,
    output wire         sddat1, sddat2, sddat3,
    
    output reg  [31:0]  DATA,
    output reg          WE,
    output reg          DONE
    );

assign sdcard_pwr_n = 1'b0;                  // keep SDcard power-on

assign {sddat1, sddat2, sddat3} = 3'b111;    // Must set sddat1~3 to 1 to avoid SD card from entering SPI mode


reg [31:0] waddr=0;
wire       rdone;
reg        rstart = 1'b1;
reg [31:0] rsector = 0;

wire       outen;
wire [7:0] outbyte;

    always @(posedge clk27mhz) begin
        if(!resetn) begin
            DATA <= 0;
            WE <= 0;
            waddr <= 0;
            DONE <= 0;
            rstart <= 1;
            rsector <= 0;
        end else begin
            if(rdone)
                rsector <= rsector + 1;
            if(DONE==0 && outen) begin
                DATA  <= {outbyte, DATA[31:8]};
                WE    <= (waddr[1:0]==3);
                waddr <= waddr + 1;
            end else begin
                WE <= 0;
                if(waddr>=`BIN_SIZE) begin
                    DONE <= 1;
                    rstart <= 0;
                end
            end
        end
    end

wire [3:0] card_stat;
wire [1:0] card_type;

//----------------------------------------------------------------------------------------------------
// sd_reader
//----------------------------------------------------------------------------------------------------
sd_reader #(
    .CLK_DIV          ( 2              )   // because clk=27MHz, CLK_DIV must ≥2
) u_sd_reader (
    .rstn             ( resetn         ),
    .clk              ( clk27mhz      ),
    .sdclk            ( sdclk          ),
    .sdcmd            ( sdcmd          ),
    .sddat0           ( sddat0         ),
    .card_stat        ( card_stat      ),  // show the sdcard initialize status
    .card_type        ( card_type       ),  // 0=UNKNOWN    , 1=SDv1    , 2=SDv2  , 3=SDHCv2
    .rstart           ( rstart         ),
    .rsector          ( rsector        ),  // read No. 0 sector (the first sector) in SDcard
    .rbusy            (                ),
    .rdone            ( rdone          ),
    .outen            ( outen          ),
    .outaddr          (                ),
    .outbyte          ( outbyte        )
);

endmodule
