#!/usr/bin/python

import sys, os, time, getopt, string, threading, socket, ConfigParser, StringIO
from crcl import *

INIFILE = ""
ROBOT_PORT = ""
ROBOT_HOST = ""
GRIPPER_PORT = ""
GRIPPER_HOST = ""
DEBUG = False

XAXIS = VectorType(1, 0, 0)
ZAXIS = VectorType(0, 0, 1)

RobotCommandID = 0
RobotCommandState = CommandStateType.READY
RobotPose = PoseLocationType(PointType(0,0,0), XAXIS, ZAXIS)

GripperCommandID = 0
GripperCommandState = CommandStateType.READY

def robot_reader(conn):
    global DEBUG, RobotCommandID, RobotCommandState
    size = 1024
    while True:
        try: data = conn.recv(size)
        except: break
        if not data: break
        # print data
        try:
            tree = ET.parse(StringIO.StringIO(data))
            root = tree.getroot()
            if root.tag == "CRCLStatus":
                for child in root:
                    if child.tag == "CommandStatus":
                        t = child.findtext("CommandID")
                        if (t != None) and (t != ""): RobotCommandID = int(t)
                        t = child.findtext("CommandState")
                        if (t != None) and (t != ""):
                            RobotCommandState = toCommandStateType(t)
                        t = child.findtext("Pose") # FIXME
                        if (t != None): print t
                        # else Pose, GripperStatus, etc.
        except:
            mystr = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><CRCLStatus xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:noNamespaceSchemaLocation=\"../xmlSchemas/CRCLStatus.xsd\"><CommandStatus><CommandID>2</CommandID><StatusID>2322</StatusID><CommandState>Done</CommandState></CommandStatus><Pose><Point><X>122.072600</X><Y>-424.659200</Y><Z>507.135200</Z></Point><XAxis><I>-0.418876</I><J>-0.905497</J><K>0.067955</K></XAxis><ZAxis><I>-0.834241</I><J>0.354199</J><K>-0.422593</K></ZAxis></Pose></CRCLStatus>"
            tree = ET.parse(StringIO.StringIO(mystr))
            root = tree.getroot()
            # print root.tag
            # print len(mystr), len(data)
            # print data
    conn.close()

def gripper_reader(conn):
    global DEBUG, GripperCommandID, GripperCommandState
    size = 1024
    while True:
        try: data = conn.recv(size)
        except: break
        if not data: break
        try:
            tree = ET.parse(StringIO.StringIO(data))
            root = tree.getroot()
            if root.tag == "CRCLStatus":
                for child in root:
                    if child.tag == "CommandStatus":
                        t = child.findtext("CommandID")
                        if (t != None) and (t != ""): GripperCommandID = int(t)
                        t = child.findtext("CommandState")
                        if (t != None) and (t != ""): GripperCommandState = toCommandStateType(t)
                        # else Pose, GripperStatus, etc.
        except: pass
    conn.close()

try:
    opts, args = getopt.getopt(sys.argv[1:], "i:r:R:g:G:t:Xd", ["inifile=", "robot=", "robothost=", "gripper=", "gripperhost=", "debug="])
except getopt.GetoptError, err:
    print "crclsh:", str(err)
    sys.exit(1)

for o, a in opts:
    if o in ("-i", "--inifile"):
        INIFILE = a
    elif o in ("-r", "--robot"):
        ROBOT_PORT = a
    elif o in ("-R", "--robothost"):
        ROBOT_HOST = a
    elif o in ("-g", "--gripper"):
        GRIPPER_PORT = a
    elif o in ("-G", "--gripperhost"):
        GRIPPER_HOST = a
    elif o in ("-d", "--debug"):
        DEBUG = True

defdict = {
    "port" : "",
    "host" : "",
    }

if INIFILE != "":
    try:
        with open(INIFILE, "rb") as f:
            config = ConfigParser.ConfigParser(defdict)
            config.read(INIFILE)
            if ROBOT_PORT == "":
                ROBOT_PORT = config.get("robot_prim", "port")
            if ROBOT_HOST == "":
                ROBOT_HOST = config.get("robot_prim", "host")
            if GRIPPER_PORT == "":
                GRIPPER_PORT = config.get("gripper_prim", "port")
            if GRIPPER_HOST == "":
                GRIPPER_HOST = config.get("gripper_prim", "host")
    except IOError as err:
        print "robot_prim: open inifile:", str(err)
        sys.exit(1)
    except (ConfigParser.NoSectionError, ConfigParser.NoOptionError) as err:
        print "robot_prim: read inifile:", str(err)
    except:
        print "robot_prim: inifile error"
        sys.exit(1)

if ROBOT_PORT == "":
    print "crclsh: no robot port provided"
    sys.exit(1)

if ROBOT_HOST == "": ROBOT_HOST = "localhost"

if GRIPPER_PORT == "":
    print "crclsh: no gripper port provided"
    sys.exit(1)

if GRIPPER_HOST == "": GRIPPER_HOST = "localhost"

if DEBUG:
    print "crclsh: robot host:", ROBOT_HOST, ", port:", ROBOT_PORT
    print "crclsh: gripper host:", GRIPPER_HOST, ", port:", GRIPPER_PORT

try:
    robot_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    robot_socket.connect((ROBOT_HOST, int(ROBOT_PORT)))
except IOError as err:
    print "crclsh: can't connect to robot controller", ROBOT_HOST, "on port", ROBOT_PORT, ":", str(err)
    sys.exit(1)

rt = threading.Thread(target=robot_reader, args=(robot_socket,))
rt.daemon = True
rt.start()

try:
    gripper_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    gripper_socket.connect((GRIPPER_HOST, int(GRIPPER_PORT)))
except IOError as err:
    print "crclsh: can't connect to gripper controller", GRIPPER_HOST, "on port", GRIPPER_PORT, ":", str(err)
    sys.exit(1)

gt = threading.Thread(target=gripper_reader, args=(gripper_socket,))
gt.daemon = True
gt.start()

robot_cid = 100
gripper_cid = 200
done = False

while not done:
    try:
        sys.stdout.write("> ")
        line = sys.stdin.readline()
    except KeyboardInterrupt:
        break
    if not line:
        break
    toks = line.split()
    if len(toks) == 0:
        print RobotCommandID, RobotCommandState
        print GripperCommandID, GripperCommandState
        continue

    cmd = toks[0]
    if cmd == "q": break
    elif cmd == "h": print "help"

    elif cmd == "open":
        gripper_cid += 1
        m = OpenToolChangerType(gripper_cid)
        gripper_socket.send(str(m))

    elif cmd == "close":
        try:
            name = toks[1]
        except:
            print "need a gripper name"
            continue
        gripper_cid += 1
        m = CloseToolChangerType(gripper_cid, Name=name)
        gripper_socket.send(str(m))

    elif cmd == "init":
        gripper_cid += 1
        m = InitCanonType(gripper_cid)
        gripper_socket.send(str(m))
        m = InitCanonType(robot_cid)
        robot_socket.send(str(m))



    elif cmd == "set":
        try:
            val = float(toks[1])
        except:
            print "need a gripper value"
            continue
        gripper_cid += 1
        m = SetEndEffectorType(gripper_cid, val)
        gripper_socket.send(str(m))
        
    elif cmd == "move":
        try:
            x = float(toks[1])
            y = float(toks[2])
            z = float(toks[3])
        except:
            print "need x y z"
            continue
        robot_cid += 1
        m = MoveToType(robot_cid, False, PoseOnlyLocationType(PointType(x, y, z),VectorType(-0.093809,0.994010,-0.056074),VectorType(-0.045748,-0.060567,-0.997115)))
        robot_socket.send(str(m))

    else:
        print line

