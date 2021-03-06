#!/usr/bin/python

# do rostopic pub /kitting_emove_cmd nist_kitting/emove_cmd -f <yaml.bagy>

import sys, os, time, getopt, string, threading, re, socket, ConfigParser, StringIO, xml.etree.ElementTree as ET, subprocess, shlex
import rospy
from nist_kitting.msg import *
from crcl import *
from MySQLdbConn import *

'''
xmldec = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
uri = "http://www.w3.org/2001/XMLSchema-instance"
xsi = "{" + uri + "}"
dict = {"xmlns:xsi" : uri}
'''

INIFILE = ""
PLAN_FILE = ""
ROBOT_PORT = ""
ROBOT_HOST = ""
GRIPPER_PORT = ""
GRIPPER_HOST = ""
DB_SERVER = ""
DB_USER = ""
DB_PASSWD = ""
DB_NAME = ""
NOCHECK = False
DEBUG = False
PERIOD = 0.5

# the global emove status structure
EmoveStatMsg = emove_stat()

XAXIS = VectorType(1, 0, 0)
ZAXIS = VectorType(0, 0, 1)

RobotCommandID = 0
RobotStatusID = 0
RobotCommandState = CommandStateType.READY
RobotPose = PoseLocationType()

GripperCommandID = 0
GripperStatusID = 0
GripperCommandState = CommandStateType.READY

def except_info():
    exc_type, exc_value = sys.exc_info()[:2]
    return str(exc_type.__name__) + ": " + str(exc_value)

AprsDB = MySQLdbConn()

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
                    if child.tag == "Pose":
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

def robot_poll(cid, tm):
    global DEBUG, PERIOD, RobotCommandID, RobotCommandState
    end = time.time() + tm
    while True:
        if (RobotCommandID == cid) and (RobotCommandState != CommandStateType.WORKING): return RobotCommandState
        elif time.time() > end: return CommandStateType.TIMEOUT
        time.sleep(PERIOD)

def gripper_poll(cid, tm):
    global DEBUG, PERIOD, GripperCommandID, GripperCommandState
    end = time.time() + tm
    while True:
        if (GripperCommandID == cid) and (GripperCommandState != CommandStateType.WORKING): return GripperCommandState
        elif time.time() > end: return CommandStateType.TIMEOUT
        time.sleep(PERIOD)

# --- Handler functions for PDDL commands ---

def strip_suffix(p):
    m = re.match("(.*)_[0-9]*$", p)
    if m == None: return p
    return m.group(1)

def check_predicate(sku, location):
    global NOCHECK, DEBUG
    if DEBUG: print "checking", sku, "at location", location
    if NOCHECK: return True, 0, 0, 0
    try:
        req = "/usr/local/iora/test/testPredicatesEvaluator" + " " + sku + " " + location
        toks = shlex.split(subprocess.check_output(shlex.split(req)))
        x = float(toks[0])
        y = float(toks[1])
        z = float(toks[2])
        return True, x, y, z
    except:
        print "in", os.getcwd()
        print "check_predicate: error on", req, ":", except_info()
    return False, 0, 0, 0

def get_pose(part):
    global NOCHECK, DEBUG, AprsDB
    if DEBUG: print "getting pose of", part
    if NOCHECK: return True, 0, 0, 0
    try:
        ret = AprsDB.read("select X,Y,Z from DirectPose where name = \"" + part + "\"")
        for toks in ret:
            x = float(toks[0])
            y = float(toks[1])
            z = float(toks[2])
        return True, x, y, z
    except: pass
    return False, 0, 0, 0

def get_kit(kit):
    global NOCHECK, DEBUG, AprsDB
    if NOCHECK: return True, PoseLocationType(PointType(0,0,0), VectorType(1,0,0), VectorType(0,0,1))
    try:
        xyz = AprsDB.read("select hasPoint_X, hasPoint_Y, hasPoint_Z from Point where _NAME = (select hasPoseLocation_Point from PoseLocation where _NAME = (select hasSolidObject_PrimaryLocation from SolidObject where _NAME = \"" + kit + "\"))")
        for toks in xyz:
            x = float(toks[0])
            y = float(toks[1])
            z = float(toks[2])
        xijk = AprsDB.read("select hasVector_I, hasVector_J, hasVector_K from Vector where _NAME = (select hasPoseLocation_XAxis from PoseLocation where _NAME = (select hasSolidObject_PrimaryLocation from SolidObject where _NAME = \"" + kit + "\"))")
        for toks in xijk:
            xi = float(toks[0])
            xj = float(toks[1])
            xk = float(toks[2])
        zijk = AprsDB.read("select hasVector_I, hasVector_J, hasVector_K from Vector where _NAME = (select hasPoseLocation_ZAxis from PoseLocation where _NAME = (select hasSolidObject_PrimaryLocation from SolidObject where _NAME = \"" + kit + "\"))")
        for toks in zijk:
            zi = float(toks[0])
            zj = float(toks[1])
            zk = float(toks[2])
        return True, PoseLocationType(PointType(x,y,z), VectorType(xi,xj,xk), VectorType(zi,zj,zk))
    except: pass
    return False, PoseLocationType(PointType(0,0,0), VectorType(1,0,0), VectorType(0,0,1))

def get_slot(slot):
    global NOCHECK, DEBUG, AprsDB
    if NOCHECK: return True, PoseLocationType(PointType(0,0,0), VectorType(1,0,0), VectorType(0,0,1))
    try:
        xyz = AprsDB.read("select hasPoint_X, hasPoint_Y, hasPoint_Z from Point where _NAME = (select hasPartRefAndPose_Point from PartRefAndPose where _NAME = (select hasSlot_PartRefAndPose from Slot where _NAME = \"" + slot + "\"))")
        for toks in xyz:
            x = float(toks[0])
            y = float(toks[1])
            z = float(toks[2])
        xijk = AprsDB.read("select hasVector_I, hasVector_J, hasVector_K from Vector where _NAME = (select hasPartRefAndPose_XAxis from PartRefAndPose where _NAME = (select hasSlot_PartRefAndPose from Slot where _NAME = \"" + slot + "\"))")
        for toks in xijk:
            xi = float(toks[0])
            xj = float(toks[1])
            xk = float(toks[2])
        zijk = AprsDB.read("select hasVector_I, hasVector_J, hasVector_K from Vector where _NAME = (select hasPartRefAndPose_ZAxis from PartRefAndPose where _NAME = (select hasSlot_PartRefAndPose from Slot where _NAME = \"" + slot + "\"))")
        for toks in zijk:
            zi = float(toks[0])
            zj = float(toks[1])
            zk = float(toks[2])
        return True, PoseLocationType(PointType(x,y,z), VectorType(xi,xj,xk), VectorType(zi,zj,zk))
    except: pass
    return False, PoseLocationType(PointType(0,0,0), VectorType(1,0,0), VectorType(0,0,1))

def Create_Kit(toks, robot_port, gripper_port):
    # (create-kit kit_gearbox_1top1bottom1medium kit_design_gearbox_1top1bottom1medium kit_gearbox_1top1bottom1medium_tray work_table_1)
    print toks
    return True

def Look_For_Kit(toks, robot_port, gripper_port):
    # (look-for-kit robot_1 kit_gearbox kit_gearbox_tray sku_gearbox_tray robotiq_gripper)
    print toks
    return True

def Look_For_Part(toks, robot_port, gripper_port):
    # (look-for-part robot_1 big_gear_1 sku_part_big_gear kit_gearbox robotiq_gripper)
    print toks
    return True

def Look_For_Slot_In_Kit(toks, robot_port, gripper_port):
    # (look-for-slot-in-kit robot_1 big_gear_1 sku_part_big_gear kit_gearbox kit_gearbox_slot_big_gear robotiq_gripper)
    print toks
    return True

def Look_For_Slot_In_Lbwk(toks, robot_port, gripper_port):
    # (look-for-slot-in-lbwk robot_1 lbwkslot_0 finished_kit_receiver kit_gearbox robotiq_gripper)
    print toks
    return True

def Look_For_Worktablearea(toks, robot_port, gripper_port):
    # (look-for-worktablearea robot_1 kit_tray_1top1bottom1medium_area work_table_1 kit_gearbox_1top1bottom1medium_tray robotiq_gripper sku_gearbox_1top1bottom1medium_tray)
    print toks
    return True

def Place_Kit(toks, robot_port, gripper_port):
    # (place-kit robot_1 kit_gearbox robotiq_gripper lbwkslot_0 finished_kit_receiver)
    print toks
    return True

def Place_Kittray(toks, robot_port, gripper_port):
    # (place-kittray robot_1 kit_gearbox_1top1bottom1medium_tray work_table_1 kit_tray_1top1bottom1medium_area robotiq_gripper)
    print toks
    return True

def Place_Part(toks, robot_port, gripper_port):
    # (place-part robot_1 small_gear_1 sku_part_small_gear kit_gearbox_1small1medium kit_gearbox_1small1medium_slot_small_gear robotiq_gripper)
    global PERIOD, DEBUG, EmoveStatMsg
    robot_cid = 100
    gripper_cid = 200

    if len(toks) < 7: return False
    if DEBUG: print "do", toks[0], "using robot", toks[1], "for part", toks[2], "of SKU", toks[3], "to kit", toks[4], "at slot", toks[5], "uwing gripper", toks[6]
    part = toks[2]
    sku = strip_suffix(part)
    kit = toks[4]
    slot = toks[5]
    startloc = toks[4]
    endloc = startloc

    # //! Configure gripper for pre-grasp
    # pm.demo->Decouple(curtool);
    gripper_cid += 1
    m = OpenToolChangerType(gripper_cid)
    gripper_port.send(str(m))
    EmoveStatMsg.crcl = "OpenToolChanger"
    if gripper_poll(gripper_cid, 3) != CommandStateType.DONE:
        print "error on", str(m)
        return False

    # pm.demo->Couple(curtool);
    gripper_cid += 1
    m = CloseToolChangerType(gripper_cid)
    gripper_port.send(str(m))
    EmoveStatMsg.crcl = "CloseToolChanger"
    if gripper_poll(gripper_cid, 3) != CommandStateType.DONE: return False

    # //! Open gripper
    # pm.demo->SetTool (0.9);
    gripper_cid += 1
    m = SetEndEffectorParametersType(gripper_cid, ParameterSettingType("set", 0.9))
    gripper_port.send(str(m))
    EmoveStatMsg.crcl = "SetEndEffectorParameters"
    if gripper_poll(gripper_cid, 3) != CommandStateType.DONE: return False

    # //! Move over part at z position
    # pm.demo->MoveTo (poseMe)
    ret, x, y, z = check_predicate(sku, startloc)
    if not ret: 
        print "can't find", sku, "at", startloc
        return False
    ret, x, y, z = get_pose(part)
    robot_cid += 1
    m = MoveToType(robot_cid, False, PoseOnlyLocationType(PointType(x, y, z), XAXIS, ZAXIS))
    robot_port.send(str(m))
    EmoveStatMsg.crcl = "MoveTo"
    if robot_poll(robot_cid, 10) != CommandStateType.DONE: return False

    # //! Grasp part
    # pm.demo->SetTool (0.1);
    gripper_cid += 1
    m = SetEndEffectorParametersType(gripper_cid, ParameterSettingType("set", 0.1))
    gripper_port.send(str(m))
    EmoveStatMsg.crcl = "SetEndEffectorParameters"
    if gripper_poll(gripper_cid, 3) != CommandStateType.DONE: return False

    # //! Move over the part at z position
    # pm.demo->MoveTo (poseMe)

    ret, kitPose = get_kit(kit)
    if DEBUG: 
        if ret == False: print kit, "not found"
        else: print kit, "is at", kitPose

    ret, slotPose = get_slot(slot)
    if DEBUG: 
        if ret == False: print slot, "not found"
        else: print slot, "is at", slotPose

    fullPose = PosePoseMult(kitPose, slotPose)

    robot_cid += 1
    m = MoveToType(robot_cid, False, fullPose)
    robot_port.send(str(m))
    EmoveStatMsg.crcl = "MoveTo"
    if robot_poll(robot_cid, 10) != CommandStateType.DONE: return False

    # else we did it all OK
    return True

def Set_Grasp(toks, robot_port, gripper_port):
    # (set-grasp robot_1 big_gear_1 sku_part_big_gear robotiq_gripper)
    global PERIOD, DEBUG, EmoveStatMsg
    gripper_cid = 200
    timeout = 3

    if len(toks) < 5: return False
    if DEBUG: print "do", toks[0], "using robot", toks[1], "for part", toks[2], "of SKU", toks[3], "of gripper", toks[4]
    part = toks[2]
    sku = strip_suffix(part)

    gripper_cid += 1
    m = SetEndEffectorParametersType(gripper_cid, ParameterSettingType("set", 0.1))
    gripper_port.send(str(m))
    EmoveStatMsg.crcl = "SetEndEffectorParameters"
    if gripper_poll(gripper_cid, timeout) != CommandStateType.DONE: return False
    return True

def Take_Kit(toks, robot_port, gripper_port):
    # (take-kit robot_1 kit_gearbox kit_gearbox_tray work_table_1 sku_gearbox_tray robotiq_gripper)
    print toks
    return True

def Take_Kittray(toks, robot_port, gripper_port):
    # (take-kittray robot_1 kit_gearbox_1top1bottom1medium_tray empty_kit_tray_supply robotiq_gripper sku_gearbox_1top1bottom1medium_tray)
    print toks
    return True

def Take_Part(toks, robot_port, gripper_port):
    # (take-part robot_1 big_gear_1 sku_part_big_gear big_gear_tray robotiq_gripper kit_gearbox)
    print toks
    return True

# --- the dictionary associating PDDL commands with handler functions ---

funcdict = {
    "create-kit" : Create_Kit,
    "look-for-kit" : Look_For_Kit,
    "look-for-part" : Look_For_Part,
    "look-for-slot-in-kit" : Look_For_Slot_In_Kit,
    "look-for-slot-in-lbwk" : Look_For_Slot_In_Lbwk,
    "look-for-worktablearea" : Look_For_Worktablearea,
    "place-kit" : Place_Kit,
    "place-kittray" : Place_Kittray,
    "place-part" : Place_Part,
    "set-grasp" : Set_Grasp,
    "take-kit" : Take_Kit,
    "take-kittray" : Take_Kittray,
    "take-part" : Take_Part
    }

# parseLine looks up the handler functions and calls them with
# the line and the socket ports to the robot and gripper subordinates

def parseLine(line, robot_socket, gripper_socket):
    global EmoveStatMsg
    toks = str.split(line)
    num = len(toks)
    if num == 0: return False

    func = funcdict.get(toks[0], None)
    if (func != None):
        EmoveStatMsg.line = toks[0]
        return func(toks, robot_socket, gripper_socket)

    print "unknown command", toks[0]
    return False

'''
rosmsg show emove_stat
[nist_kitting/emove_stat]:
std_msgs/Header header
  uint32 seq
  time stamp
  string frame_id
nist_core/rcs_stat stat
  uint8 type
  uint8 serial_number
  uint8 state
  uint8 status
  uint8 heartbeat
  float32 period
  float32 cycle
  float32 duration
geometry_msgs/Pose current_pose
  geometry_msgs/Point position
    float64 x
    float64 y
    float64 z
  geometry_msgs/Quaternion orientation
    float64 x
    float64 y
    float64 z
    float64 w
geometry_msgs/Pose target_pose
  geometry_msgs/Point position
    float64 x
    float64 y
    float64 z
  geometry_msgs/Quaternion orientation
    float64 x
    float64 y
    float64 z
    float64 w
string name
string line

-----------

rosmsg show emove_cmd

[nist_kitting/emove_cmd]:
std_msgs/Header header
  uint32 seq
  time stamp
  string frame_id
nist_core/rcs_cmd cmd
  uint8 type
  uint8 serial_number
nist_kitting/emove_move move
  string name
  geometry_msgs/Pose pose
    geometry_msgs/Point position
      float64 x
      float64 y
      float64 z
    geometry_msgs/Quaternion orientation
      float64 x
      float64 y
      float64 z
      float64 w
nist_kitting/emove_run run
  string name
'''

cmddict = {
    0 : "Nop",
    1 : "Init",
    2 : "Halt",
    3 : "WsAssembleKit",
    4 : "TaskMoveObject",
    5 : "EmoveRun",
    6 : "EmoveApproach",
    7 : "EmoveAcquire",
    8 : "EmoveMove",
    9 : "EmoveRelease",
    10 : "EmoveDepart"
    }

statdict = {
    0 : "None",
    1 : "Done",
    2 : "Exec",
    3 : "Error"
    }

statedict = {
    0 : "Uninitialized",
    1 : "NewCommand",
    10 : "S0",
    11 : "S1",
    12 : "S2",
    13 : "S3",
    14 : "S4",
    15 : "S5",
    16 : "S6",
    17 : "S7",
    18 : "S8",
    19 : "S9"
    }

def run_plan(plan_file):
    global DEBUG, EmoveStatMsg
    if DEBUG: print "kitting_emove: running ", plan_file
    try:
        f = open(plan_file, "rb")
    except IOError as err:
        print "kitting_emove: can't open", plan_file, ":", str(err)
        EmoveStatMsg.stat.status = 3
        return False
    for line in f:
        m = re.match("^[\s]*[0-9.].*:[\s]*\((.*)\)[\s]*\[[0-9.].*\]", line)
        if m != None:
            if DEBUG: print "kitting_emove: parsing line", m.group(1)
            retval = parseLine(m.group(1), robot_socket, gripper_socket)
            if retval == False:
                print "kitting_emove: failed:", m.group(1)
                f.close()
                EmoveStatMsg.stat.status = 3
                return False
    f.close()
    EmoveStatMsg.stat.status = 1
    return True

def emove_cmd_reader_callback(data):
    global DEBUG, EmoveStatMsg, cmddict, statdict, PLAN_FILE
    if DEBUG: print "kitting_emove: got:\n", data
    EmoveStatMsg.stat.type = data.cmd.type
    EmoveStatMsg.stat.serial_number = data.cmd.serial_number
    try:
        if data.cmd.type == 5:
            EmoveStatMsg.name = PLAN_FILE
            EmoveStatMsg.stat.status = 2
            run_plan(PLAN_FILE)
        else:
            EmoveStatMsg.stat.status = 3
            print "kitting_emove: unknown command:", data.cmd.type
    except:
        EmoveStatMsg.stat.status = 3
        print "kitting_emove: bad command:", data.cmd.type

def emove_cmd_reader():
    rospy.Subscriber("kitting_emove_cmd", emove_cmd, emove_cmd_reader_callback)
    rospy.spin()

# --- Main ---

try:
    opts, args = getopt.getopt(sys.argv[1:], "i:r:R:g:G:t:Xd", ["inifile=", "robot=", "robothost=", "gripper=", "gripperhost=", "period=", "nocheck", "debug", "dbserver=", "dbuser=", "dbpasswd=", "dbname="])
except getopt.GetoptError, err:
    print "kitting_emove:", str(err)
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
    elif o in ("-t", "--period"):
        PERIOD = float(a)
    elif o in ("-X", "--nocheck"):
        NOCHECK = True
    elif o in ("-d", "--debug"):
        DEBUG = True
# args with long form only go here
    elif o in ("--dbserver"):
        DB_SERVER = a
    elif o in ("--dbuser"):
        DB_USER = a
    elif o in ("--dbpasswd"):
        DB_PASSWD = a
    elif o in ("--dbname"):
        DB_NAME = a

defdict = {
    "plan" : "",
    "port" : "",
    "host" : "",
    "server" : "",
    "user" : "",
    "passwd" : "",
    "name" : ""
    }

if INIFILE != "":
    try:
        with open(INIFILE, "rb") as f:
            config = ConfigParser.ConfigParser(defdict)
            config.read(INIFILE)
            if PLAN_FILE == "":
                PLAN_FILE = config.get("planner", "plan")
            if ROBOT_PORT == "":
                ROBOT_PORT = config.get("robot_prim", "port")
            if ROBOT_HOST == "":
                ROBOT_HOST = config.get("robot_prim", "host")
            if GRIPPER_PORT == "":
                GRIPPER_PORT = config.get("gripper_prim", "port")
            if GRIPPER_HOST == "":
                GRIPPER_HOST = config.get("gripper_prim", "host")
            if DB_SERVER == "":
                DB_SERVER = config.get("mysql", "server")
            if DB_USER == "":
                DB_USER = config.get("mysql", "user")
            if DB_PASSWD == "":
                DB_PASSWD = config.get("mysql", "passwd")
            if DB_NAME == "":
                DB_NAME = config.get("mysql", "name")
    except IOError as err:
        print "robot_prim: open inifile:", str(err)
        sys.exit(1)
    except (ConfigParser.NoSectionError, ConfigParser.NoOptionError) as err:
        print "robot_prim: read inifile:", str(err)
    except:
        print "robot_prim: inifile error"
        sys.exit(1)

if PLAN_FILE == "":
    print "kitting_emove: no plan file specified"
    sys.exit(1)

if ROBOT_PORT == "":
    print "kitting_emove: no robot port provided"
    sys.exit(1)

if ROBOT_HOST == "": ROBOT_HOST = "localhost"

if GRIPPER_PORT == "":
    print "kitting_emove: no gripper port provided"
    sys.exit(1)

if GRIPPER_HOST == "": GRIPPER_HOST = "localhost"

if DB_SERVER == "": DB_SERVER = "aprs-dev"
if DB_USER == "" : DB_USER = "wills"
if DB_PASSWD == "" : DB_PASSWD = "ElsaIsdDb!"
if DB_NAME == "" : DB_NAME = "aprs-dev"

if DEBUG:
    print "kitting_emove: plan file:", PLAN_FILE
    print "kitting_emove: robot host:", ROBOT_HOST, ", port:", ROBOT_PORT
    print "kitting_emove: gripper host:", GRIPPER_HOST, ", port:", GRIPPER_PORT
    print "kitting_emove: MySQL options are:", DB_SERVER, DB_USER, DB_PASSWD, DB_NAME

if not AprsDB.connect(DB_SERVER, DB_USER, DB_PASSWD, DB_NAME):
    print "plan_exec_app: can't connect to database"
    sys.exit(1)

try:
    robot_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    robot_socket.connect((ROBOT_HOST, int(ROBOT_PORT)))
except IOError as err:
    print "kitting_emove: can't connect to robot controller", ROBOT_HOST, "on port", ROBOT_PORT, ":", str(err)
    sys.exit(1)

rt = threading.Thread(target=robot_reader, args=(robot_socket,))
rt.daemon = True
rt.start()

try:
    gripper_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    gripper_socket.connect((GRIPPER_HOST, int(GRIPPER_PORT)))
except IOError as err:
    print "kitting_emove: can't connect to gripper controller", GRIPPER_HOST, "on port", GRIPPER_PORT, ":", str(err)
    sys.exit(1)

gt = threading.Thread(target=gripper_reader, args=(gripper_socket,))
gt.daemon = True
gt.start()

def main_loop():
    global EmoveStatMsg
    pub = rospy.Publisher("kitting_emove_stat", emove_stat, queue_size=1)
    rate = rospy.Rate(4)
    EmoveStatMsg.stat.heartbeat = 0
    EmoveStatMsg.stat.state = 10;
    while not rospy.is_shutdown():
        EmoveStatMsg.stat.heartbeat += 1
        if EmoveStatMsg.stat.heartbeat >= 255: EmoveStatMsg.stat.heartbeat = 0
        try:
            pub.publish(EmoveStatMsg)
            rate.sleep()
        except rospy.ROSInterruptException:
            pass

rospy.init_node('kitting_emove', anonymous=True)

emove_cmd_reader_thread = threading.Thread(target=emove_cmd_reader)
emove_cmd_reader_thread.daemon = True
emove_cmd_reader_thread.start()

main_loop()
