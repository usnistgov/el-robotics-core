#!/usr/bin/python

import struct

'''
int length;		  /* 4 bytes, constant value should be 16x4 = 64 */
int message_type;	  /* 4 bytes, constant value 11, JOINT TRAJ_PT */
int comm_type;	  /* 4 bytes, constant value 2, REQUEST */
int reply_type;	  /* 4 bytes, N/A */
int seq_number;	  /* 4 bytes, >= 0 */
float joints[JOINT_MAX]; /* 10 4-byte floats, one per joint */
float velocity;	   /* 4 bytes */
float duration;	   /* 4 bytes */
'''

class SimpleMessage(object):
    COMM_TOPIC = 1
    COMM_REQUEST = 2
    COMM_REPLY = 3
    REPLY_NA = 0
    REPLY_SUCCESS = 1
    REPLY_FAILURE = 2
    REPLY_EXECUTING = 3
    NUM_JOINTS = 10

class JointTrajPtRequest(object):

    def setSeqNumber(self, seq_number):
        self.seq_number = seq_number

    def setJoints(self, Joints):
        jts = len(Joints)
        if jts < SimpleMessage.NUM_JOINTS:
            self.joints = Joints
            self.joints += [0]*(SimpleMessage.NUM_JOINTS-jts)
        else:
            self.joints = Joints[0:SimpleMessage.NUM_JOINTS]

    def setVelocity(self, Velocity):
        self.velocity = Velocity

    def setDuration(self, Duration):
        self.duration = Duration

    def __init__(self, Joints):
        self.seq_number = 1
        self.setJoints(Joints)
        self.velocity = 1
        self.duration = 1

    def __str__(self):
        return str(self.seq_number) + ", " + str(self.joints) + ", " + str(self.velocity) + ", " + str(self.duration)

    def pack(self):
        self.seq_number += 1;
        st = struct.pack('iiiii', 64, 11, 2, 0, self.seq_number)
        st += struct.pack(SimpleMessage.NUM_JOINTS*'f', *self.joints)
        st += struct.pack('ff', self.velocity, self.duration)
        return st

    def unpack(self, packed):
        try:
            unpacked = struct.unpack('iiiii' + SimpleMessage.NUM_JOINTS*'f' + 'ff', packed)
            if unpacked[1] != 11: return False
        except:
            return False
        self.setSeqNumber(unpacked[4])
        self.setJoints(unpacked[5:5+SimpleMessage.NUM_JOINTS])
        self.setVelocity(unpacked[5+SimpleMessage.NUM_JOINTS])
        self.setDuration(unpacked[5+SimpleMessage.NUM_JOINTS+1])
        return True

class JointTrajPtReply(object):

    SimpleMessage.NUM_JOINTS = 10

    def setStatus(self, status):
        self.status = status

    def getStatus(self):
        return self.status

    # this corresponds to the 'unused' field
    def setSeqNumber(self, seq_number):
        self.seq_number = seq_number

    def getSeqNumber(self):
        return self.seq_number

    def setJoints(self, Joints):
        jts = len(Joints)
        if jts < SimpleMessage.NUM_JOINTS:
            self.joints = Joints
            self.joints += [0]*(SimpleMessage.NUM_JOINTS-jts)
        else:
            self.joints = Joints[0:SimpleMessage.NUM_JOINTS]

    def __init__(self, status = SimpleMessage.REPLY_SUCCESS):
        # 1 = SUCCESS, 2 = FAILURE
        self.setStatus(status)
        self.setSeqNumber(1)
        self.setJoints(SimpleMessage.NUM_JOINTS*[0])

    def __str__(self):
        return str(self.status) + " " + str(self.seq_number)

    def pack(self):
        self.seq_number += 1;
        st = struct.pack('iiiii', 56, 11, 3, self.status, self.seq_number)
        st += struct.pack(SimpleMessage.NUM_JOINTS*'f', *self.joints)
        return st

    def unpack(self, packed):
        try:
            unpacked = struct.unpack('iiiii' + SimpleMessage.NUM_JOINTS*'f', packed)
            if unpacked[1] != 11: return False
        except:
            return False
        self.setStatus(unpacked[3])
        self.setSeqNumber(unpacked[4])
        self.setJoints(unpacked[5:5+SimpleMessage.NUM_JOINTS])
        return True

'''
int length;		  /* 4 bytes, constant value should be 13x4 = 52 */
int message_type;	  /* 4 bytes, constant value 31, CART TRAJ_PT */
int comm_type;	  /* 4 bytes, constant value 2, REQUEST */
int reply_type;	  /* 4 bytes, N/A */
int seq_number;	  /* 4 bytes, >= 0 */
float x, y, z, qx, qy, qz, qw; /* pose, Cartesian and quaternion */
float translational_speed;	 /* 4 bytes, > 0 */
float rotational_speed;	 /* 4 bytes, > 0 */
'''

class CartTrajPtRequest(object):

    def setSeqNumber(self, seq_number):
        self.seq_number = seq_number

    def setPose(self, x, y, z, qx, qy, qz, qw):
        self.x = x
        self.y = y
        self.z = z
        self.qx = qx
        self.qy = qy
        self.qz = qz
        self.qw = qw

    def setTranslationalSpeed(self, Speed):
        self.translationalSpeed = Speed

    def setRotationalSpeed(self, Speed):
        self.rotationalSpeed = Speed

    def __init__(self, x, y, z, qx, qy, qz, qw):
        self.seq_number = 1
        self.setPose(x, y, z, qx, qy, qz, qw)
        self.setTranslationalSpeed(1)
        self.setRotationalSpeed(1)

    def __str__(self):
        outstr = ""
        for el in self.x, self.y, self.z, self.qx, self.qy, self.qz, self.qw, self.translationalSpeed, self.rotationalSpeed:
            outstr += (str(el) + " ")
        return outstr

    def pack(self):
        self.seq_number += 1;
        st = struct.pack('iiiii', 52, 31, 2, 0, self.seq_number)
        st += struct.pack('fffffff', self.x, self.y, self.z, self.qx, self.qy, self.qz, self.qw)
        st += struct.pack('ff', self.translationalSpeed, self.rotationalSpeed)
        return st

    def unpack(self, packed):
        try:
            unpacked = struct.unpack('iiiii' + 'fffffff' + 'ff', packed)
            if unpacked[1] != 31: return False
        except:
            return False
        self.setSeqNumber(unpacked[4])
        self.setPose(unpacked[5], unpacked[6], unpacked[7], unpacked[8], unpacked[9], unpacked[10], unpacked[11])
        self.setTranslationalSpeed(unpacked[12])
        self.setRotationalSpeed(unpacked[13])
        return True

class CartTrajPtReply(object):

    def setStatus(self, status):
        self.status = status

    def getStatus(self):
        return self.status

    def setSeqNumber(self, seq_number):
        self.seq_number = seq_number

    def __init__(self):
        # 1 = SUCCESS, 2 = FAILURE
        self.SUCCESS = 1
        self.FAILURE = 2
        self.EXEC = 3
        self.status = self.SUCCESS
        self.seq_number = 1

    def __str__(self):
        return str(self.status) + " " + str(self.seq_number)

    def pack(self):
        self.seq_number += 1;
        st = struct.pack('iiiii', 16, 31, 3, self.status, self.seq_number)
        return st

    def unpack(self, packed):
        try:
            unpacked = struct.unpack('iiiii', packed)
            if unpacked[1] != 31: return False
        except:
            return False
        self.setStatus(unpacked[3])
        self.setSeqNumber(unpacked[4])
        return True

'''
int length;	  /* 4 bytes, constant value should be 10x4 = 40 */
int message_type;  /* 4 bytes, constant value 13, ROBOT_STATUS */
int comm_type;	  /* 4 bytes, constant value 1, TOPIC */
int reply_type;	  /* 4 bytes, N/A */
int drives_powered;
int e_stopped;
int error_code;
int in_error;
int in_motion;
int mode;
int motion_possible;
'''

class RobotStatus(object):

    def __init__(self):
        self.drives_powered = 0
        self.e_stopped = 0
        self.error_code = 0
        self.in_error = 0
        self.in_motion = 0
        self.mode = 0
        self.motion_possible = 0
        
    def __str__(self):
        return str(self.drives_powered) + " " + \
            str(self.e_stopped) + " " + \
            str(self.error_code) + " " + \
            str(self.in_error) + " " + \
            str(self.in_motion) + " " + \
            str(self.mode) + " " + \
            str(self.motion_possible)

    def pack(self):
        st = struct.pack('iiiiiiiiiii', 40, 13, 1, 0, self.drives_powered, self.e_stopped, self.error_code, self.in_error, self.in_motion, self.mode, self.motion_possible)
        return st

    def unpack(self, packed):
        try:
            unpacked = struct.unpack('iiiiiiiiiii', packed)
            if unpacked[1] != 13: return False
        except:
            return False
        self.drives_powered = unpacked[4]
        self.e_stopped = unpacked[5]
        self.error_code = unpacked[6]
        self.in_error = unpacked[7]
        self.in_motion = unpacked[8]
        self.mode = unpacked[9]
        self.motion_possible = unpacked[10]
        return True

if __name__ == "__main__":

    jt = JointTrajPtRequest([1, 2, 3])
    print jt

    njt = JointTrajPtRequest([])
    if not njt.unpack(jt.pack()):
        print "unpacking error"
    else: 
        print njt

    ct = CartTrajPtRequest(1, 2, 3, 0.7071, 0.0, 0.0, 0.7071)
    print ct

    nct = CartTrajPtRequest(0, 0, 0, 0, 0, 0, 1)
    if not nct.unpack(ct.pack()):
        print "unpacking error"
    else:
        print nct

    if not nct.unpack(jt.pack()):
        print "unpacking error as expected"
    else:
        print "unexpected unpacking success"

    jtrep = JointTrajPtReply(SimpleMessage.REPLY_EXECUTING)
    print jtrep

    rs = RobotStatus()
    rs.drives_powered = 1
    rs.e_stopped = 2
    rs.error_code = 3
    rs.in_error = 4
    rs.in_motion = 5
    rs.mode = 6
    rs.motion_possible = 7
    print rs
    nrs = RobotStatus()
    if not nrs.unpack(rs.pack()):
        print "unpacking error"
    else:
        print nrs
