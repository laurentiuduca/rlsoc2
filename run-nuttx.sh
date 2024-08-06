set -x
set -e
./build-nuttx.sh
make veri
time ./simv

