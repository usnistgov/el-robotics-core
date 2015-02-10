#!/usr/bin/python

import sys
from ctypes import *

# Run as, e.g., python crobot.py ..\..\nist_core\win32\Debug\nist_core_dll

if len(sys.argv) < 2:
    print "need the name of the DLL"
    sys.exit(1)

lib = cdll.LoadLibrary(sys.argv[1])

crobot = lib.crcl_sim_robot_new(None)

x = c_double(1)
y = c_double(-2)
z = c_double(3.14)
xrot = c_double(-0.1)
yrot = c_double(0.2)
zrot = c_double(-0.3)

lib.crcl_sim_robot_move_straight_to(crobot, x, y, z, xrot, yrot, zrot)

lib.crcl_sim_robot_get_robot_pose(crobot, byref(x), byref(y), byref(z), byref(xrot), byref(yrot), byref(zrot))

print x.value, y.value, z.value

