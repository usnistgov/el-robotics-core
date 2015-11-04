#!/bin/sh

set -x;
#nist_kitting_run_cognex_sim.sh
if test ! -f ./run_cognex_sim.sh || test `grep -c '#nist_kitting_run_cognex_sim.sh'  ./run_cognex_sim.sh` = 0  ; then 
    cd "${0%%run_cognex_sim.sh }";
fi



./cognex_sim -p 4000 -f cognex_sim.txt
