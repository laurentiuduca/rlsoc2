#
# System signal
#
set_property PACKAGE_PIN G20 [get_ports w_led[1]]
set_property IOSTANDARD LVCMOS33 [get_ports w_led[1]]
set_property PACKAGE_PIN G21 [get_ports w_led[0]]
set_property IOSTANDARD LVCMOS33 [get_ports w_led[0]]
set_property PACKAGE_PIN M21 [get_ports CLK]
set_property IOSTANDARD LVCMOS33 [get_ports CLK]
create_clock -add -name CLK -period 20.00 [get_ports { CLK }];
#create_generated_clock -add -name sys_clk -period 20 [get_pins mmcmclock/clk_sys]
set_property IOSTANDARD LVCMOS33 [get_ports w_btnl]
set_property PACKAGE_PIN H7 [get_ports w_btnl]
set_property IOSTANDARD LVCMOS33 [get_ports w_btnr]
set_property PACKAGE_PIN M6 [get_ports w_btnr]

set_property PACKAGE_PIN F3 [get_ports w_rxd]
set_property IOSTANDARD LVCMOS33 [get_ports w_rxd]
set_property PACKAGE_PIN E3 [get_ports w_txd]
set_property IOSTANDARD LVCMOS33 [get_ports w_txd]


#
# SDRAM signals
#
set_property -dict {PACKAGE_PIN G22 IOSTANDARD LVCMOS33 SLEW FAST} [get_ports SDCLK0]
set_property PACKAGE_PIN H22 [get_ports SDCKE0]
set_property IOSTANDARD LVCMOS33 [get_ports SDCKE0]

set_property PACKAGE_PIN K23 [get_ports DQM[1]]
set_property IOSTANDARD LVCMOS33 [get_ports DQM[1]]
set_property PACKAGE_PIN J25 [get_ports DQM[0]]
set_property IOSTANDARD LVCMOS33 [get_ports DQM[0]]

set_property PACKAGE_PIN K25 [get_ports CAS]
set_property IOSTANDARD LVCMOS33 [get_ports CAS]
set_property PACKAGE_PIN K26 [get_ports RAS]
set_property IOSTANDARD LVCMOS33 [get_ports RAS]
set_property PACKAGE_PIN J26 [get_ports SDWE]
set_property IOSTANDARD LVCMOS33 [get_ports SDWE]
set_property PACKAGE_PIN L25 [get_ports SDCS0]
set_property IOSTANDARD LVCMOS33 [get_ports SDCS0]

set_property PACKAGE_PIN M26 [get_ports Bank[1]]
set_property IOSTANDARD LVCMOS33 [get_ports Bank[1]]
set_property PACKAGE_PIN M25 [get_ports Bank[0]]
set_property IOSTANDARD LVCMOS33 [get_ports Bank[0]]

set_property PACKAGE_PIN J21 [get_ports Address[12]]
set_property IOSTANDARD LVCMOS33 [get_ports Address[12]]
set_property PACKAGE_PIN K22 [get_ports Address[11]]
set_property IOSTANDARD LVCMOS33 [get_ports Address[11]]
set_property PACKAGE_PIN R25 [get_ports Address[10]]
set_property IOSTANDARD LVCMOS33 [get_ports Address[10]]
set_property PACKAGE_PIN K21 [get_ports Address[9]]
set_property IOSTANDARD LVCMOS33 [get_ports Address[9]]
set_property PACKAGE_PIN L22 [get_ports Address[8]]
set_property IOSTANDARD LVCMOS33 [get_ports Address[8]]
set_property PACKAGE_PIN L23 [get_ports Address[7]]
set_property IOSTANDARD LVCMOS33 [get_ports Address[7]]
set_property PACKAGE_PIN L24 [get_ports Address[6]]
set_property IOSTANDARD LVCMOS33 [get_ports Address[6]]
set_property PACKAGE_PIN M22 [get_ports Address[5]]
set_property IOSTANDARD LVCMOS33 [get_ports Address[5]]
set_property PACKAGE_PIN M24 [get_ports Address[4]]
set_property IOSTANDARD LVCMOS33 [get_ports Address[4]]
set_property PACKAGE_PIN N26 [get_ports Address[3]]
set_property IOSTANDARD LVCMOS33 [get_ports Address[3]]
set_property PACKAGE_PIN P26 [get_ports Address[2]]
set_property IOSTANDARD LVCMOS33 [get_ports Address[2]]
set_property PACKAGE_PIN P25 [get_ports Address[1]]
set_property IOSTANDARD LVCMOS33 [get_ports Address[1]]
set_property PACKAGE_PIN R26 [get_ports Address[0]]
set_property IOSTANDARD LVCMOS33 [get_ports Address[0]]

set_property PACKAGE_PIN D25 [get_ports Data[0]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[0]]
set_property PACKAGE_PIN D26 [get_ports Data[1]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[1]]
set_property PACKAGE_PIN E25 [get_ports Data[2]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[2]]
set_property PACKAGE_PIN E26 [get_ports Data[3]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[3]]
set_property PACKAGE_PIN F25 [get_ports Data[4]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[4]]
set_property PACKAGE_PIN G25 [get_ports Data[5]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[5]]
set_property PACKAGE_PIN G26 [get_ports Data[6]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[6]]
set_property PACKAGE_PIN H26 [get_ports Data[7]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[7]]
set_property PACKAGE_PIN J24 [get_ports Data[8]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[8]]
set_property PACKAGE_PIN J23 [get_ports Data[9]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[9]]
set_property PACKAGE_PIN H24 [get_ports Data[10]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[10]]
set_property PACKAGE_PIN H23 [get_ports Data[11]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[11]]
set_property PACKAGE_PIN G24 [get_ports Data[12]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[12]]
set_property PACKAGE_PIN F24 [get_ports Data[13]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[13]]
set_property PACKAGE_PIN F23 [get_ports Data[14]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[14]]
set_property PACKAGE_PIN E23 [get_ports Data[15]]
set_property IOSTANDARD LVCMOS33 [get_ports Data[15]]

#pmod J10, BANK35_

## ---- MAX7219 DIN (serial data input) ----
set_property PACKAGE_PIN G8 [get_ports {MAX7219_DATA}]
set_property IOSTANDARD LVCMOS33 [get_ports {MAX7219_DATA}]
set_property PULLDOWN FALSE [get_ports {MAX7219_DATA}]
set_property DRIVE 8 [get_ports {MAX7219_DATA}]
set_property SLEW SLOW [get_ports {MAX7219_DATA}]

## ---- MAX7219 CLK (serial clock) ----
set_property PACKAGE_PIN G5 [get_ports {MAX7219_CLK}]
set_property IOSTANDARD LVCMOS33 [get_ports {MAX7219_CLK}]
set_property PULLDOWN FALSE [get_ports {MAX7219_CLK}]
set_property DRIVE 8 [get_ports {MAX7219_CLK}]
set_property SLEW SLOW [get_ports {MAX7219_CLK}]

## ---- MAX7219 CS / LOAD (chip select) ----
set_property PACKAGE_PIN G7 [get_ports {MAX7219_LOAD}]
set_property IOSTANDARD LVCMOS33 [get_ports {MAX7219_LOAD}]
set_property PULLDOWN FALSE [get_ports {MAX7219_LOAD}]
set_property DRIVE 8 [get_ports {MAX7219_LOAD}]
set_property SLEW SLOW [get_ports {MAX7219_LOAD}]


# SDcard
#set_property -dict { PACKAGE_PIN E2    IOSTANDARD LVCMOS33 } [get_ports { sdcard_pwr_n }];   #IO_L14P_T2_SRCC_35 Sch=sd_resetn
#set_property -dict { PACKAGE_PIN N6    IOSTANDARD LVCMOS33 } [get_ports { sd_cd }];          #IO_L9N_T1_DQS_AD7N_35 Sch=sd_cd
set_property -dict { PACKAGE_PIN L4    IOSTANDARD LVCMOS33 } [get_ports { sdclk }];          #IO_L9P_T1_DQS_AD7P_35 Sch=sdclk
set_property -dict { PACKAGE_PIN J8    IOSTANDARD LVCMOS33 } [get_ports { sdcmd }];          #IO_L16N_T2_35 Sch=sdcmd mosi
set_property -dict { PACKAGE_PIN M5    IOSTANDARD LVCMOS33 } [get_ports { sddat0 }];         #IO_L16P_T2_35 Sch=sd_dat[0] miso
set_property -dict { PACKAGE_PIN M7    IOSTANDARD LVCMOS33 } [get_ports { sddat1 }];         #IO_L18N_T2_35 Sch=sd_dat[1]
set_property -dict { PACKAGE_PIN H6    IOSTANDARD LVCMOS33 } [get_ports { sddat2 }];         #IO_L18P_T2_35 Sch=sd_dat[2]
set_property -dict { PACKAGE_PIN J6    IOSTANDARD LVCMOS33 } [get_ports { sddat3 }];         #IO_L14N_T2_SRCC_35 Sch=sd_dat[3] cs

set_property CONFIG_VOLTAGE 3.3 [current_design]
set_property CFGBVS VCCO [current_design]


set_property BITSTREAM.CONFIG.SPI_BUSWIDTH 4 [current_design]
