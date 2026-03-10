# Project F: FPGA Pong - Vivado Build Script (XC7 VGA)
# (C)2023 Will Green, open source hardware released under the MIT License
# Learn more at https://projectf.io/posts/fpga-pong/

# Using this script:
#   1. Add Vivado env to shell: . /opt/Xilinx/Vivado/2022.2/settings64.sh
#   2. Run build script: vivado -mode batch -nolog -nojournal -source build.tcl
#   3. Program board: openFPGALoader -b arty ../pong.bit

# build settings
set design_name "m_maintn"
set arch "xc7"
#set board_name "arty"
set fpga_part "xc7a100tfgg676-1"

# set reference directories for source files
#set lib_dir [file normalize "./"]
#set origin_dir [file normalize "./"]

# read design sources
read_verilog -sv "define.vh"
read_verilog -sv "busarbiter.v"
read_verilog -sv "console.v"
read_verilog -sv "cpummu.v"
read_verilog -sv "sdram-qm/artix7_pll.v"
read_verilog -sv "loader.v"
read_verilog -sv "maintn.v"
read_verilog -sv "memory_controller.v"
read_verilog -sv "memorytn.v"
read_verilog -sv "mmu.v"
read_verilog -sv "rvcorem.v"
read_verilog -sv "sdram-qm/sdramwinb.v"

read_verilog -sv "max7219.v"
read_verilog -sv "clkdivider.v"

read_verilog -sv "sd_loader.v"
read_verilog -sv "sd_file_loader.v"
read_verilog -sv "sd_file_reader.v"
read_verilog -sv "sd_reader.v"
read_verilog -sv "sdcmd_ctrl.v"

# read constraints
read_xdc "qmtechv3.xdc"

# synth
synth_design -top "${design_name}" -part ${fpga_part}
write_checkpoint -force synth.dcp
report_timing_summary -file synthtiming.rpt
report_utilization -file synthutil.rpt

# place and route
opt_design
place_design
route_design
write_checkpoint -force route.dcp
report_timing_summary -file routetiming.rpt
report_utilization -file routeutil.rpt

report_timing_summary

# write bitstream
write_bitstream -force "top.bit"
