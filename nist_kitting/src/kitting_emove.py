#!/usr/bin/python

import threading
import rospy
from nist_kitting.msg import *

# do rostopic pub /emove_cmd nist_kitting/emove_cmd -f <yaml.bagy>

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

def emove_cmd_reader_callback(data):
    print "got", data
    
def emove_cmd_reader():
    rospy.Subscriber('emove_cmd', emove_cmd, emove_cmd_reader_callback)
    rospy.spin()

def main_loop():
    pub = rospy.Publisher('emove_stat', emove_stat, queue_size=1)
    rate = rospy.Rate(1)
    msg = emove_stat()
    msg.stat.heartbeat = 0
    while not rospy.is_shutdown():
        msg.stat.heartbeat += 1
        try:
            pub.publish(msg)
            rate.sleep()
        except rospy.ROSInterruptException:
            pass

rospy.init_node('kitting_emove', anonymous=True)

emove_cmd_reader_thread = threading.Thread(target=emove_cmd_reader)
emove_cmd_reader_thread.daemon = True
emove_cmd_reader_thread.start()

main_loop()
