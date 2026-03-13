#mv sd_spi.v sd_spi-old.v
ghdl -a -fsynopsys sd_spi.vhd
ghdl --synth -fsynopsys --out=verilog sd_controller > sd_spi.v

