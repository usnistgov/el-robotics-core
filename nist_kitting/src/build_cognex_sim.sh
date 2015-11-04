#!/bin/sh

orig_dir=`pwd`;

#nist_kitting_build_cognex_sim.sh
if test ! -f ./build_cognex_sim.sh ||  test `grep -c '#nist_kitting_build_cognex_sim.sh'  ./build_cognex_sim.sh` = 0  ; then 
    cd "${0%%build_cognex_sim.sh}";
fi

set -x;

kitting_src_dir=`pwd`;

\rm -f cognex_sim 2>/dev/null || true;
g++ -g cognex_sim.cpp cognex_db.cpp -I../include -lulapi -ldlulapi -ldl -lpthread -o cognex_sim >/dev/null 2>/dev/null && exit 0;



cd ../../ulapi/ 
make distclean >/dev/null 2>/dev/null || make clean >/dev/null 2>/dev/null || true
./autoconf.sh
./configure
make
sudo make install || true
mkdir target
make install prefix=`pwd`/target/
ulapi_dir=`pwd`/target/;


cd "${kitting_src_dir}";
g++ -g cognex_sim.cpp cognex_db.cpp -I../include -I "${ulapi_dir}/include" -I . -L "${ulapi_dir}/lib" -Wl,--rpath "${ulapi_dir}/lib" -lulapi -ldlulapi -ldl -lpthread -o cognex_sim

cd "${orig_dir}";


