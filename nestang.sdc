
// NES clocks
create_clock -name CLK -period 37.04 [get_nets {CLK}]       // 27 Mhz
//create_generated_clock -name CLK -source [get_nets {pCLK}] -master_clock pCLK -divide_by 3 [get_nets {CLK}]     // 32.25 Mhz

// HDMI clocks
//create_clock -name CLK_p5 -period 2.6936 [get_nets {CLK_p5}]                    // 371.25 Mhz
//create_generated_clock -name CLK_p -source [get_nets {CLK_p}] -master_clock CLK_p5 -divide_by 5 [get_nets {CLK_p}]     // 74.25 Mhz: 720p pixel clock

//set_clock_groups -asynchronous -group [get_clocks {pCLK} get_clocks{CLK}] -group [get_clocks {CLK_p5} get_clocks{CLK_p}]
report_timing -hold -from_clock [get_clocks {CLK*}] -to_clock [get_clocks {CLK*}] -max_paths 25 -max_common_paths 1
report_timing -setup -from_clock [get_clocks {CLK*}] -to_clock [get_clocks {CLK*}] -max_paths 25 -max_common_paths 1
