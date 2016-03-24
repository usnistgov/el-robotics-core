rufous Nightmare
=========
Last updated: 3/23/2016 12:17:37 PM  

rufous disk problem
----------------------
Clean the disk
    fsck -As

Had to force a mount
    mount -o remount,rw /
    then deleted trash:
    cd ~/michalos/.local/share/Trash
    rm -rf files/*.*

    sudo apt-get autoremove (problem with kuka ros downloads)

Then removed excessive number of 12.04 kernel images

    cd /boot
    sudo rm *.3.13.0-58*



