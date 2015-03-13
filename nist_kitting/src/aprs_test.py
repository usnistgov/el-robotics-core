#!/usr/bin/python

import sys
from MySQLdbConn import *

DB_SERVER = "aprs-dev"
DB_USER = "wills"
DB_PASSWD = "ElsaIsdDb!"
DB_NAME = "aprs-dev"

AprsDB = MySQLdbConn()

if not AprsDB.connect(DB_SERVER, DB_USER, DB_PASSWD, DB_NAME):
    print "can't connect to database"
    sys.exit(1)

slots = AprsDB.read("select _NAME from Slot")
print len(slots), "slots:"

for slot in slots:
    if len(slot) > 0:
        name = slot[0]
        try:
            ret = AprsDB.read("select hasPoint_X, hasPoint_Y, hasPoint_Z from Point where _NAME = (select hasPartRefAndPose_Point from PartRefAndPose where _NAME = (select hasSlot_PartRefAndPose from Slot where _NAME = \"" + name + "\"))")
            if len(ret) > 0:
                xyz = ret[0]
                if len(xyz) > 2:
                    x = xyz[0]
                    y = xyz[1]
                    z = xyz[2]
                    print name, "=", x, y, z
        except: pass

kits = AprsDB.read("select _NAME from Kit")
print len(kits), "kits:"

for kit in kits:
    if len(kit) > 0:
        name = kit[0]
        ret = AprsDB.read("select hasPoint_X, hasPoint_Y, hasPoint_Z from Point where _NAME = (select hasPoseLocation_Point from PoseLocation where _NAME = (select hasSolidObject_PrimaryLocation from SolidObject where _NAME = \"" + name + "\"))")
        try:
            if len(ret) > 0:
                xyz = ret[0]
                if len(xyz) > 2:
                    x = xyz[0]
                    y = xyz[1]
                    z = xyz[2]
                    print name, "=", x, y, z
        except: pass

AprsDB.disconnect()

sys.exit(0)
