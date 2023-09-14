// modified by Laurentiu-Cristian Duca, 2023-09-12
// adapted from https://github.com/WangXuan95/FPGA-SDcard-Reader
//--------------------------------------------------------------------------------------------------------

`include "define.vh"

module sd_loader (
    input  wire         clk27mhz,
    // rstn active-low, You can re-read SDcard by pushing the reset button.
    input  wire         resetn,
    input  wire [2:0]   init_state,
    input  wire         w_dram_busy,
    output reg          r_refreshcmd,
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
reg        rstart = 0;
reg [31:0] rsector = 0, last_refresh_sector=0;

wire       outen;
wire [7:0] outbyte;

reg [7:0] state=0;
`ifdef DRAM_REFRESH_LOGIC
reg dram_logic = 1;
`else
reg dram_logic = 0;
`endif

    always @(posedge clk27mhz) begin
        if(!resetn) begin
            DATA <= 0;
            WE <= 0;
            waddr <= 0;
            DONE <= 0;
            rstart <= 0;
            rsector <= 0;
            state <= 0;
            last_refresh_sector <= 0;
            r_refreshcmd <= 0;
        end else begin
            if(state == 0) begin
                if (DONE==0) begin
                    if(rdone)
                        if(((rsector - last_refresh_sector) > 5) && dram_logic) begin
                                // ram refresh
                                rstart <= 0;
                                state <= 10;
                                last_refresh_sector <= rsector;
                        end else begin
                            r_refreshcmd <= 0;
                            if(init_state == 3) begin
                                rsector <= rsector + 1;
                                rstart <= 1;
                            end else
                                rstart <= 0;
                        end
                    else begin
                        if(init_state == 3)
                            rstart <= 1;
                        else
                            rstart <= 0;
                    end
                end else
                    rstart <= 0;
                    
                if(DONE==0 && outen && init_state == 3) begin
                    DATA  <= {outbyte, DATA[31:8]};
                    WE    <= (waddr[1:0]==3);
                    waddr <= waddr + 1;
                end else begin
                    WE <= 0;
                    if(waddr>=`BIN_SIZE)
                        DONE <= 1;
                end
            end else if(state == 10) begin
                if(!w_dram_busy ) begin
                    r_refreshcmd <= 1;
                    state <= 1;
                end
            end else if (state == 1) begin
                if(w_dram_busy) begin
                    state <= 2;
                    r_refreshcmd <= 0;
                end
            end else if (state == 2) begin
                if(!w_dram_busy) begin
                    state <= 0;
                    rsector <= rsector + 1;
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
