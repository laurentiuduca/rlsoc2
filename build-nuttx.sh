set -x
set -e
cd ../../initmem_gen2
./run-nuttx.sh
cd ../rvsoc_src_ver053/src
cp ../../initmem_gen2/init_kernel.txt ../binary/
#cp ../../initmem_gen2/init_disk.txt ../binary/
cp ../../initmem_gen2/initmem.bin ../binary/

