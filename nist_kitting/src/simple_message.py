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

class JointTrajPtRequest(object):

    NUM_JOINTS = 10

    def setSeqNumber(self, seq_number):
        self.seq_number = seq_number

    def setJoints(self, Joints):
        jts = len(Joints)
        if jts < JointTrajPtRequest.NUM_JOINTS:
            self.joints = Joints
            self.joints += [0]*(JointTrajPtRequest.NUM_JOINTS-jts)
        else:
            self.joints = Joints[0:JointTrajPtRequest.NUM_JOINTS]

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
        st += struct.pack(JointTrajPtRequest.NUM_JOINTS*'f', *self.joints)
        st += struct.pack('ff', self.velocity, self.duration)
        return st

    def unpack(self, packed):
        unpacked = struct.unpack('iiiii' + JointTrajPtRequest.NUM_JOINTS*'f' + 'ff', packed)
        self.setSeqNumber(unpacked[4])
        self.setJoints(unpacked[5:5+JointTrajPtRequest.NUM_JOINTS])
        self.setVelocity(unpacked[5+JointTrajPtRequest.NUM_JOINTS])
        self.setDuration(unpacked[5+JointTrajPtRequest.NUM_JOINTS+1])

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
        unpacked = struct.unpack('iiiii' + 'fffffff' + 'ff', packed)
        self.setSeqNumber(unpacked[4])
        self.setPose(unpacked[5], unpacked[6], unpacked[7], unpacked[8], unpacked[9], unpacked[10], unpacked[11])
        self.setTranslationalSpeed(unpacked[12])
        self.setRotationalSpeed(unpacked[13])

if __name__ == "__main__":

    jt = JointTrajPtRequest([1, 2, 3])
    print jt

    njt = JointTrajPtRequest([])
    njt.unpack(jt.pack())
    print njt

    ct = CartTrajPtRequest(1, 2, 3, 0.7071, 0.0, 0.0, 0.7071)
    print ct

    nct = CartTrajPtRequest(0, 0, 0, 0, 0, 0, 1)
    nct.unpack(ct.pack())
    print nct

