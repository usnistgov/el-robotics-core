#!/bin/bash

#    ^^ this has to be bash, not /bin/sh, for arrays to work
# run dos2unix ./runmultiterm.bash

p=/usr/local/michalos/fanuc_ws
cmd=( gnome-terminal )
cmd+=( --tab --title="rviz"  --working-directory="$p" 
-e 'bash -c "exec bash"')
cmd+=( --tab --title="catkin" --working-directory="$p" 
-e 'bash -c "exec bash;source ./devel/setup.bash; print env"')
cmd+=( --tab --title="roslaunch" --working-directory="$p" 
-e 'bash -c "`source ./devel/setup.bash`; exec bash"')
cmd+=( --tab --title="github" --working-directory="$HOME/src/github/johnmichaloski/ROS" 
-e 'bash -c "exec bash"')
"${cmd[@]}"
