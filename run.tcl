# gw_sh run.tcl
set_device -name GW2AR-18C GW2AR-LV18QN88C8/I7

add_file busarbiter.v
#add_file busarbiter-serial.v
add_file console.v
add_file cpummu.v
add_file define.vh
add_file gowin_rpll.v
add_file loader.v
add_file maintn.v
add_file memory_controller.v
add_file memorytn.v
add_file mmu.v
add_file rvcorem.v
add_file sdram.v

add_file max7219.v
add_file clkdivider.v

add_file sd_loader.v
add_file sd_file_loader.v
add_file sd_file_reader.v
add_file sd_reader.v
add_file sdcmd_ctrl.v

add_file rlsoc.cst

set_option -top_module m_maintn
set_option -use_mspi_as_gpio 1
set_option -use_sspi_as_gpio 1
set_option -use_ready_as_gpio 1
set_option -use_done_as_gpio 1
set_option -rw_check_on_ram 1

run all
#run syn
#run pnr

