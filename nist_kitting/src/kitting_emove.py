#!/usr/bin/python

# do rostopic pub /kitting_emove_cmd nist_kitting/emove_cmd -f <yaml.bagy>

import sys, os, time, getopt, string, threading, re, socket, ConfigParser, StringIO, xml.etree.ElementTree as ET, subprocess, shlex
import MySQLdb, numpy
import rospy
from nist_kitting.msg import *
from crcl import *

xmldec = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
uri = "http://www.w3.org/2001/XMLSchema-instance"
xsi = "{" + uri + "}"
dict = {"xmlns:xsi" : uri}

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
DEBUG = False
PERIOD = 0.5

# the global emove status structure
EmoveStatMsg = emove_stat()

# the global subordinate statuses

RobotCommandID = 0
RobotCommandState = CommandStateType.READY

GripperCommandID = 0
GripperCommandState = CommandStateType.READY

XAXIS = VectorType(1, 0, 0)
ZAXIS = VectorType(0, 0, 1)

def except_info():
    exc_type, exc_value = sys.exc_info()[:2]
    return str(exc_type.__name__) + ": " + str(exc_value)

class DB(object):

    def __init__(self):
        self.server = None
        self.user = None
        self.passwd = None
        self.db = None
        self.cursor = None

    def disconnect(self):
        try: self.db.close()
        except: pass
        self.init()
        
    def connect(self, server, user, passwd, db):
        try:
            if self.db != None: self.db.close()
            self.db = MySQLdb.connect(server, user, passwd, db)
            self.cursor = self.db.cursor()
        except:
            print "DB:", except_info()
            self.db = None
            self.cursor = None
            return False
        self.server = server
        self.user = user
        self.passwd = passwd
        return True

    def read(self, query):
        try:
            self.cursor.execute(query)
            return self.cursor.fetchall()
        except:
            print "DB:", except_info()
        return ()

    def update(self, request):
        try:
            self.cursor.execute(request)
            self.db.commit()
            return True
        except:
            self.db.rollback()
        return False

AprsDB = DB()

def robot_reader(conn):
    global DEBUG, RobotCommandID, RobotCommandState
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
                        if (t != None) and (t != ""): RobotCommandID = int(t)
                        t = child.findtext("CommandState")
                        if (t != None) and (t != ""): RobotCommandState = toCommandStateType(t)
                        # else Pose, GripperStatus, etc.
        except: pass
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
    global DEBUG
    if DEBUG: print "checking", sku, "at location", location
    try:
        req = os.getenv("HOME", ".") + "/github/iora/test/testPredicatesEvaluator" + " " + sku + " " + location
        toks = shlex.split(subprocess.check_output(shlex.split(req)))
        x = float(toks[0])
        y = float(toks[1])
        z = float(toks[2])
        th = numpy.arctan2(x, y)
        return True, x, y, z, th
    except:
        print "in", os.getcwd()
        print "check_predicate: error on", req, ":", except_info()
    return False, 0, 0, 0, 0

def get_pose(part):
    global DEBUG, AprsDB
    if DEBUG: print "getting pose of", part
    try:
        ret = AprsDB.read("select X,Y,Z from DirectPose where name = " + "\"" + part + "\"")
        for toks in ret:
            x = float(toks[0])
            y = float(toks[1])
            z = float(toks[2])
            th = numpy.arctan2(x, y)
        return True, x, y, z, th
    except: pass
    return False, 0, 0, 0, 0

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

def Place_Kit(toks, robot_port, gripper_port):
    # (place-kit robot_1 kit_gearbox robotiq_gripper lbwkslot_0 finished_kit_receiver)
    print toks
    return True

def Place_Part(toks, robot_port, gripper_port):
    # (place-part robot_1 big_gear_1 sku_part_big_gear kit_gearbox kit_gearbox_slot_big_gear robotiq_gripper)
    global PERIOD, DEBUG
    if len(toks) < 7: return False
    if DEBUG: print "do", toks[0], "using robot", toks[1], "for part", toks[2], "of SKU", toks[3], "to kit", toks[4], "at slot", toks[5], "uwing gripper", toks[6]
    part = toks[2]
    sku = strip_suffix(part)
    startloc = toks[4]
    endloc = startloc # should be toks[5] but we don't have those locs

    # command ids for robot and gripper subordinates
    robot_cid = 100
    gripper_cid = 200

    # //! Configure gripper for pre-grasp
    # pm.demo->Decouple(curtool);
    gripper_cid += 1
    m = OpenToolChangerType(gripper_cid)
    gripper_port.send(str(m))
    if gripper_poll(gripper_cid, 3) != CommandStateType.DONE:
        print "error on", str(m)
        return False

    # pm.demo->Couple(curtool);
    gripper_cid += 1
    m = CloseToolChangerType(gripper_cid)
    gripper_port.send(str(m))
    if gripper_poll(gripper_cid, 3) != CommandStateType.DONE: return False

    # //! Open gripper
    # pm.demo->SetTool (0.9);
    gripper_cid += 1
    m = SetEndEffectorParametersType(gripper_cid, ParameterSettingType("set", 0.9))
    gripper_port.send(str(m))
    if gripper_poll(gripper_cid, 3) != CommandStateType.DONE: return False

    # //! Move over part at z position
    # pm.demo->MoveTo (poseMe)
    ret, x, y, z, th = check_predicate(sku, startloc)
    if not ret: 
        print "can't find", sku, "at", startloc
        return False
    ret, x, y, z, th = get_pose(part)
    robot_cid += 1
    m = MoveThroughToType(robot_cid, False, [PoseOnlyLocationType(PointType(x, y, z), XAXIS, ZAXIS)])
    robot_port.send(str(m))
    if robot_poll(robot_cid, 10) != CommandStateType.DONE: return False

    # //! Grasp part
    # pm.demo->SetTool (0.1);
    gripper_cid += 1
    m = SetEndEffectorParametersType(gripper_cid, ParameterSettingType("set", 0.1))
    gripper_port.send(str(m))
    if gripper_poll(gripper_cid, 3) != CommandStateType.DONE: return False

    # //! Move over the part at z position
    # pm.demo->MoveTo (poseMe)
    ret, x, y, z, th = check_predicate(sku, endloc)
    if not ret: return False
    ret, x, y, z, th = get_pose(part)
    robot_cid += 1
    # FIXME -- replace these randoms with the subprocess call, as above
    m = MoveThroughToType(robot_cid, False, [PoseOnlyLocationType(PointType(x, y, z), XAXIS, ZAXIS)])
    robot_port.send(str(m))
    if robot_poll(robot_cid, 10) != CommandStateType.DONE: return False

    # else we did it all OK
    return True

def Set_Grasp(toks, robot_port, gripper_port):
    # (set-grasp robot_1 big_gear_1 sku_part_big_gear robotiq_gripper)
    print toks
    return True

def Take_Kit(toks, robot_port, gripper_port):
    # (take-kit robot_1 kit_gearbox kit_gearbox_tray work_table_1 sku_gearbox_tray robotiq_gripper)
    print toks
    return True

def Take_Part(toks, robot_port, gripper_port):
    # (take-part robot_1 big_gear_1 sku_part_big_gear big_gear_tray robotiq_gripper kit_gearbox)
    print toks
    return True

# --- the dictionary associating PDDL commands with handler functions ---

funcdict = {
    "look-for-kit" : Look_For_Kit,
    "look-for-part" : Look_For_Part,
    "look-for-slot-in-kit" : Look_For_Slot_In_Kit,
    "look-for-slot-in-lbwk" : Look_For_Slot_In_Lbwk,
    "place-kit" : Place_Kit,
    "place-part" : Place_Part,
    "set-grasp" : Set_Grasp,
    "take-kit" : Take_Kit,
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
        EmoveStatMsg.line = line
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

def run_plan(plan_file):
    global DEBUG, EmoveStatMsg
    if DEBUG: print "kitting_emove: running ", plan_file
    try:
        f = open(plan_file, "rb")
    except IOError as err:
        print "kitting_emove: can't open", plan_file, ":", str(err)
        EmoveStatMsg.stat.status = 0
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
    if DEBUG: print "kitting_emove: got", data
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
    opts, args = getopt.getopt(sys.argv[1:], "i:r:R:g:G:t:d", ["inifile=", "robot=", "robothost=", "gripper=", "gripperhost=", "period=", "debug", "dbserver=", "dbuser=", "dbpasswd=", "dbname="])
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

if DB_SERVER == "": DB_SERVER = "aprs_dev"
if DB_USER == "" : DB_USER = "wills"
if DB_PASSWD == "" : DB_PASSWD = "ElsaIsdDb!"
if DB_NAME == "" : DB_NAME = "aprs-dev"

if DEBUG:
    print "kitting_emove: plan file:", PLAN_FILE
    print "kitting_emove: robot host:", ROBOT_HOST, ", port:", ROBOT_PORT
    print "kitting_emove: gripper host:", GRIPPER_HOST, ", port:", GRIPPER_PORT
    print "kitting_emove: MySQL options are:", DB_SERVER, DB_USER, DB_PASSWD, DB_NAME

if not AprsDB.connect(DB_SERVER, DB_USER, DB_PASSWD, DB_NAME):
    print "pln_exec_app: can't connect to database"
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
