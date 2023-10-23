set -x
set -e
./build.sh
make veri
time ./simv

