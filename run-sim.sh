set -x
set -e
make veri
cd /home/laur/lucru/cn/riscv/rvsoc-site-japan/initmem_gen2
./run.sh
cd /home/laur/lucru/cn/riscv/rvsoc-site-japan/rvsoc_src_ver053/src
cp ../../initmem_gen2/init_kernel.txt ../binary/
cp ../../initmem_gen2/init_disk.txt ../binary/
./simv

