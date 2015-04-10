#!/usr/bin/python

import sys, StringIO, xml.etree.ElementTree as ET
from crcl import *

uri = "http://www.w3.org/2001/XMLSchema-instance"
xsi = "{" + uri + "}"

def handleMoveToType(child):
    try:
        commandid = int(child.findtext("CommandID"))
        movestraight = child.findtext("MoveStraight")
        i = child.find("EndPosition")
        ii = i.find("Point")
        x = float(ii.findtext("X"))
        y = float(ii.findtext("Y"))
        z = float(ii.findtext("Z"))
        ii = i.find("XAxis")
        xi = float(ii.findtext("I"))
        xj = float(ii.findtext("J"))
        xk = float(ii.findtext("K"))
        ii = i.find("ZAxis")
        zi = float(ii.findtext("I"))
        zj = float(ii.findtext("J"))
        zk = float(ii.findtext("K"))
        print "MoveToType", str(commandid), str(movestraight), str(x), str(y), str(z), str(xi), str(xj), str(xk), str(zi), str(zj), str(zk)
    except:
        return False
    return True

Retval = True

try:
    f = open(sys.argv[1], 'r')
except IndexError:
    print "need a file argument"
    sys.exit(1)
except IOError:
    print "can't open", sys.argv[1]
    sys.exit(1)
except:
    print sys.exc_info()[1]
    sys.exit(1)

data = f.read()

if not data: sys.exit(0)

try:
    tree = ET.parse(StringIO.StringIO(data))
    root = tree.getroot()
except:
    print "not a CRCL file"
    sys.exit(1)

if root.tag != "CRCLProgram":
    print "not a CRCL program"
    sys.exit(1)

for child in root:
    if child.tag == "InitCanon": pass
    elif child.tag == "EndCanon": pass
    elif child.tag == "MiddleCommand":
        cmd = child.attrib.get(xsi+"type", None)
        if cmd == "ActuateJointsType": print cmd
        elif cmd == "CloseToolChangerType": print cmd
        elif cmd == "ConfigureJointReportsType": print cmd
        elif cmd == "DwellType": print cmd
        elif cmd == "GetStatusType": print cmd
        elif cmd == "MessageType": print cmd
        elif cmd == "MoveScrewType": print cmd
        elif cmd == "MoveThroughToType": print cmd
        elif cmd == "MoveToType":
            Retval = handleMoveToType(child)
            if not Retval: break
        elif cmd == "OpenToolChangerType": print cmd
        elif cmd == "RunProgramType": print cmd
        elif cmd == "SetAngleUnitsType": print cmd
        elif cmd == "SetEndEffectorParametersType": print cmd
        elif cmd == "SetEndEffectorType": print cmd
        elif cmd == "SetEndPoseToleranceType": print cmd
        elif cmd == "SetForceUnitsType": print cmd
        elif cmd == "SetIntermediatePoseToleranceType": print cmd
        elif cmd == "SetLengthUnitsType": print cmd
        elif cmd == "SetMotionCoordinationType": print cmd
        elif cmd == "SetRobotParametersType": print cmd
        elif cmd == "SetRotAccelAbsoluteType": print cmd
        elif cmd == "SetRotAccelRelativeType": print cmd
        elif cmd == "SetRotSpeedAbsoluteType": print cmd
        elif cmd == "SetRotSpeedRelativeType": print cmd
        elif cmd == "SetTorqueUnitsType": print cmd
        elif cmd == "SetTransAccelAbsoluteType": print cmd
        elif cmd == "SetTransAccelRelativeType": print cmd
        elif cmd == "SetTransSpeedAbsoluteType": print cmd
        elif cmd == "SetTransSpeedRelativeType": print cmd
        elif cmd == "StopMotionType": print cmd
    else:
        # not a CRCL program
        print "not a CRCL program:", child.tag

if Retval: sys.exit(0)
else: sys.exit(1)



