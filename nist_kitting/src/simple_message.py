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
        self.seq_number = 101
        self.setJoints(Joints)
        self.velocity = 202
        self.duration = 303

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

if __name__ == "__main__":

    jt = JointTrajPtRequest([1.0, 2.0, 3])
    print jt
    packed = jt.pack()
    
    njt = JointTrajPtRequest([])
    njt.unpack(packed)
    print njt


