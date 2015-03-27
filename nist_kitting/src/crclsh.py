#!/usr/bin/python

import sys, os, time, getopt, string, threading, socket, ConfigParser, StringIO
from crcl import *

xmldec = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
uri = "http://www.w3.org/2001/XMLSchema-instance"
xsi = "{" + uri + "}"
dict = {"xmlns:xsi" : uri}

def except_info():
    exc_type, exc_value = sys.exc_info()[:2]
    return str(exc_type.__name__) + ": " + str(exc_value)

INIFILE = ""
ROBOT_PORT = ""
ROBOT_HOST = ""
GRIPPER_PORT = ""
GRIPPER_HOST = ""
DEBUG = False

XAXIS = VectorType(1, 0, 0)
ZAXIS = VectorType(0, 0, 1)

RobotCommandID = 0
RobotStatusID = 0
RobotCommandState = CommandStateType.READY
RobotPose = PoseLocationType()

GripperCommandID = 0
GripperStatusID = 0
GripperCommandState = CommandStateType.READY
GripperName = ""
GripperType = ""
GripperSeparation = 0

def printStatus():
    global RobotCommandID, RobotStatusID, RobotCommandState, RobotPose
    global GripperCommandID, GripperStatusID, GripperCommandState, GripperName, GripperType, GripperSeparation

    print "Robot:", RobotCommandID, RobotStatusID, RobotCommandState, RobotPose
    print "Gripper:", GripperCommandID, GripperStatusID, GripperCommandState, GripperName, GripperType, GripperSeparation

'''
Kuka LWR status looks like:

<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<CRCLStatus xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:noNamespaceSchemaLocation=\"../xmlSchemas/CRCLStatus.xsd\">
  <CommandStatus>
    <CommandID>2</CommandID>
    <StatusID>2322</StatusID>
    <CommandState>Done</CommandState>
  </CommandStatus>
  <Pose>
    <Point>
      <X>122.072600</X><Y>-424.659200</Y><Z>507.135200</Z>
    </Point>
    <XAxis>
      <I>-0.418876</I><J>-0.905497</J><K>0.067955</K>
    </XAxis>
    <ZAxis>
      <I>-0.834241</I><J>0.354199</J><K>-0.422593</K>
    </ZAxis>
  </Pose>
</CRCLStatus>
'''

def robot_reader(conn):
    global DEBUG, RobotCommandID, RobotStatusID, RobotCommandState, RobotPose
    size = 1024
    while True:
        try: data = conn.recv(size)
        except: break
        if not data: break
        try:
            tree = ET.parse(StringIO.StringIO(data.rstrip(' \t\n\r\0')))
            root = tree.getroot()
            if root.tag == "CRCLStatus":
                for child in root:
                    if child.tag == "CommandStatus":
                        t = child.findtext("CommandID")
                        if (t != None) and (t != ""): RobotCommandID = int(t)
                        t = child.findtext("StatusID")
                        if (t != None) and (t != ""): RobotStatusID = int(t)
                        t = child.findtext("CommandState")
                        if (t != None) and (t != ""): RobotCommandState = toCommandStateType(t)
                    elif child.tag == "Pose":
                        for cc in child:
                            if cc.tag == "Point":
                                x = float(cc.findtext("X"))
                                y = float(cc.findtext("Y"))
                                z = float(cc.findtext("Z"))
                            if cc.tag == "XAxis":
                                xi = float(cc.findtext("I"))
                                xj = float(cc.findtext("J"))
                                xk = float(cc.findtext("K"))
                            if cc.tag == "ZAxis":
                                zi = float(cc.findtext("I"))
                                zj = float(cc.findtext("J"))
                                zk = float(cc.findtext("K"))
                        RobotPose = PoseLocationType(PointType(x,y,z), VectorType(xi,xj,xk), VectorType(zi,zj,zk))
        except:
            print "crclsh: robot_reader:", except_info()
    conn.close()

def gripper_reader(conn):
    global DEBUG, GripperCommandID, GripperStatusID, GripperCommandState
    global GripperName, GripperType, GripperSeparation
    size = 1024
    while True:
        try: data = conn.recv(size)
        except: break
        if not data: break
        try:
            tree = ET.parse(StringIO.StringIO(data.rstrip(' \t\n\r\0')))
            root = tree.getroot()
            if root.tag == "CRCLStatus":
                for child in root:
                    if child.tag == "CommandStatus":
                        t = child.findtext("CommandID")
                        GripperCommandID = int(t)
                        t = child.findtext("StatusID")
                        GripperStatusID = int(t)
                        t = child.findtext("CommandState")
                        GripperCommandState = toCommandStateType(t)
                    elif child.tag == "GripperStatus":
                        t = child.findtext("GripperName")
                        if (t != None) and (t != ""): GripperName = t
                        gt = child.attrib.get(xsi+"type", None)
                        GripperType = gt
                        if gt == "ParallelGripperStatusType":
                            f = float(child.findtext("Separation"))
                            GripperSeparation = f
                        elif gt == "ThreeFingerGripperStatusType":
                            pass
                        elif gt == "VacuumGripperStatusType":
                            pass
        except:
            print "crclsh: gripper_reader:", except_info()
    conn.close()

def printHelp():
    help = '''
Command-line options:
-i, --inifile <inifile>  : use <inifile> to get the parameters
-r, --robot <port>       : use TCP <port> to connect to the robot
-R, --robothost <host>   : use <host> that runs the robot
-g, --gripper <port>     : use TCP <port> to connect to the gripper
-G, --gripperhost <host> : use <host> that runs the gripper
-d, --debug              : turn debug printing on
-?, --help               : print this help and exit

Interactive commands:
q, ^D, ^C                : quit
?                        : print this help message
[Enter]                  : print robot and gripper status
init                     : send InitCanon to both the robot and gripper
end                      : send EndCanon to both the robot and gripper
open                     : send OpenToolChanger to the grippper
close <name>             : send CloseToolChanger for gripper <name>
set <value>              : send SetEndEffector for gripper <value>
params <name value> ...  : send gripper SetEndEffectorParameters for pairs
move <x y z xi xj xk zi zj zk> : send MoveTo to robot
'''
    print help

try:
    opts, args = getopt.getopt(sys.argv[1:], "i:r:R:g:G:t:Xd?", ["inifile=", "robot=", "robothost=", "gripper=", "gripperhost=", "debug", "help"])
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
    elif o in ("-?", "--help"):
        printHelp()
        sys.exit(0)

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
        print "crclsh: open inifile:", str(err)
        sys.exit(1)
    except (ConfigParser.NoSectionError, ConfigParser.NoOptionError) as err:
        print "crclsh: read inifile:", str(err)
    except:
        print "crclsh: inifile error"
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
        printStatus()
        continue

    cmd = toks[0]

    if cmd == "q": break

    elif cmd == "?":
        printHelp()

    elif cmd == "init":
        gripper_cid += 1
        m = InitCanonType(gripper_cid)
        gripper_socket.send(str(m))
        robot_cid += 1
        m = InitCanonType(robot_cid)
        robot_socket.send(str(m))

    elif cmd == "end":
        gripper_cid += 1
        m = EndCanonType(gripper_cid)
        gripper_socket.send(str(m))
        robot_cid += 1
        m = EndCanonType(robot_cid)
        robot_socket.send(str(m))

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

    elif cmd == "set":
        try:
            val = float(toks[1])
        except:
            print "need a gripper value"
            continue
        gripper_cid += 1
        m = SetEndEffectorType(gripper_cid, val)
        gripper_socket.send(str(m))

    elif cmd == "params":
        params = []
        for name, val in zip(toks[1::2], toks[2::2]):
            params.append(ParameterSettingType(name, val))
        if len(params) == 0:
            print "need a list of name-value pairs"
            continue
        gripper_cid += 1
        m = SetEndEffectorParametersType(gripper_cid, params)
        gripper_socket.send(str(m))
        
    elif cmd == "move":
        try:
            x = float(toks[1])
            y = float(toks[2])
            z = float(toks[3])
            xi = float(toks[4])
            xj = float(toks[5])
            xk = float(toks[6])
            zi = float(toks[7])
            zj = float(toks[8])
            zk = float(toks[9])
        except:
            print "need x y z xi xj xk zi zj zk"
            continue
        robot_cid += 1
        m = MoveToType(robot_cid, False, PoseOnlyLocationType(PointType(x, y, z), VectorType(xi, xj, xk), VectorType(zi, zj, zk)))
        robot_socket.send(str(m))

    else:
        print "? :", line

