#!/usr/bin/env python
#spins off a thread to listen for joint_states messages
#and provides the same information (or subsets of) as a service

#import roslib
#roslib.load_manifest('joint_states_listener') # catkin no longer uses load_manifest
import rospy
#from joint_states_listener.srv import *
from sensor_msgs.msg import JointState
from std_msgs.msg import String

import threading
import math
import tf
from tf import TransformListener

#holds the latest states obtained from joint_states messages
class LatestJointStates:

    def __init__(self):
        self.lock = threading.Lock()
        self.name = []
        self.position = []
        self.lastposition = []
        self.velocity = []
        self.effort = []
        self.thread = threading.Thread(target=self.joint_states_listener)
        self.thread.start()

 #       s = rospy.Service('return_joint_states', LatestJointStates, self.return_joint_states)
        
    #pretty-print list to string
    def pplist(self,list):
        #return ' '.join(['%2.3f'%x for x in list])
        return ' '.join(['%2.3f'%math.degrees(x) for x in list])

    #thread function: listen for joint_states messages
    def joint_states_listener(self):
        rospy.Subscriber('joint_states', JointState, self.joint_states_callback)
        rospy.spin()


    #callback function: when a joint_states message arrives, save the values
    def joint_states_callback(self, msg):
        self.lock.acquire()
        self.name = msg.name
        self.position = msg.position
        self.velocity = msg.velocity
        self.effort = msg.effort
        self.lock.release()
        if(self.lastposition!=self.position):
            print "position:", self.pplist(self.position)
        self.lastposition=self.position


def callback1(data):
	print "Data = " + data.data


#run the server
if __name__ == "__main__":
    rospy.init_node('robotstatus')
    rate = rospy.Rate(1)
    latestjointstates = LatestJointStates()
    #s = rospy.Service('return_joint_states', LatestJointStates, latestjointstates.return_joint_states)

    print "joints_states_listener server started, waiting for queries"
    #rospy.Subscriber("/move_group/status"  , String, callback1)
    tf1=TransformListener()
    rospy.sleep(2)
    #tf1.waitforTransform("/base_link", "tool0", rospy.Time.now(), rospy.Duration(1))
    t = tf1.getLatestCommonTime("/base_link", "/tool0")
    position, quaternion = tf1.lookupTransform("/base_link", "/tool0", t)
    print position, quaternion
    while not rospy.is_shutdown():
	rospy.sleep(1.0)
	t = tf1.getLatestCommonTime("/base_link", "/tool0")
	#tf1.waitForTransform("/base_link", "tool0", rospy.Time.now(), rospy.Duration(1))
	(trans,rot) = tf1.lookupTransform("/base_link", "/tool0", t)
	print trans, rot
 	#rospy.spin()
