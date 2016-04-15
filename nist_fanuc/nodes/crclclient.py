

import socket   
import sys 
import math
#from mathutils import Matrix 
import numpy as np
from numpy import matrix
import time
from xml.dom import minidom
import os.path


class CrclClientSocket:
    def __init__(self, host, port):
        self.host=host
        self.port=port
        self.stopconnecting=False
        # quit when find </CRCLStatus>
        self.End='</CRCLStatus>'
        self.nextdata=''

    def connect(self):
        try:
            if(self.stopconnecting):
                return
            self.sock = socket.socket(
                    socket.AF_INET, socket.SOCK_STREAM)
            self.sock.connect((self.host, self.port))
        except socket.error, msg:
            print 'Failed to create socket. Error code: ' + str(msg[0]) + ' , Error message : ' + msg[1]
            time.sleep( 5 )
            self.connect()
   
    def disconnect(self):
        self.sock.close()
 
    def syncsend(self, msg):
        print  msg
        sent = self.sock.send(msg)
        if sent == 0:
            self.disconnect()
            self.connect()  
            # raise RuntimeError("socket connection broken")      
 
    # http://code.activestate.com/recipes/408859/

    def syncreceive(self, end):
        #total_data=[];
        self.End=end # '</CRCLStatus>'
        data=''
        alldata=self.nextdata
        while True:
                data=self.sock.recv(8192)
                if data == 0:
                    alldata='' # empty string
                    return 
                alldata=alldata+data
                if self.End in alldata:
                    alldata=alldata[:alldata.find(self.End)]
                    self.nextdata=data[data.find(self.End)+1:]
                    break
        return alldata  # ''.join(total_data)

def CrclActuateJoints(cmd, num, pos, vel, acc):
    return '''<?xml version="1.0" encoding="UTF-8"?>
<CRCLCommandInstance
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:noNamespaceSchemaLocation="../xmlSchemas/CRCLCommandInstance.xsd">
  <CRCLCommand xsi:type="ActuateJointsType">
    <CommandID>{}</CommandID>
    <ActuateJoint>
      <JointNumber>{}</JointNumber>
      <JointPosition>{}</JointPosition>
      <JointDetails xsi:type="JointSpeedAccelType">
        <JointSpeed>{}</JointSpeed>
        <JointAccel>{}</JointAccel>
      </JointDetails>
    </ActuateJoint>
  </CRCLCommand>
</CRCLCommandInstance>'''.format(cmd,num, pos, vel, acc)
 
def CrclMoveTo(cmd, x,y,z,xi,xj,xk,zi,zj,zk):
    return '''<?xml version="1.0" encoding="UTF-8"?>
<CRCLCommandInstance
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:noNamespaceSchemaLocation="../xmlSchemas/CRCLCommandInstance.xsd">
  <CRCLCommand xsi:type="MoveToType">
    <CommandID>{}</CommandID>
    <MoveStraight>true</MoveStraight>
    <EndPosition>
      <Point>
        <X>{}</X> <Y>{}</Y> <Z>{}</Z>
      </Point>
      <XAxis>
        <I>{}</I> <J>{}</J> <K>{}</K>
      </XAxis>
      <ZAxis>
        <I>{}</I> <J>{}</J> <K>{}</K>
      </ZAxis>
    </EndPosition>
  </CRCLCommand>
</CRCLCommandInstance>'''.format(cmd, x,y,z, xi, xj, xk, zi, zj, zk)
 
def CrclGetStatusCmd(cmd):
    return '''
    <?xml version="1.0" encoding="UTF-8"?>
<CRCLCommandInstance
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:noNamespaceSchemaLocation="../xmlSchemas/CRCLCommandInstance.xsd">
  <CRCLCommand xsi:type="GetStatusType">
     <CommandID>{}</CommandID>
  </CRCLCommand>
</CRCLCommandInstance>
'''.format(cmd)

def CrclDwellCmd(cmd,dwell):
    return '''
 <?xml version="1.0" encoding="UTF-8"?>
<CRCLCommandInstance
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
  xsi:noNamespaceSchemaLocation="../xmlSchemas/CRCLCommandInstance.xsd">
    <CRCLCommand xsi:type="DwellType">
        <CommandID>{}</CommandID>
        <DwellTime>{}</DwellTime>
    </CRCLCommand>
</CRCLCommandInstance>
'''.format(cmd, dwell)


def parseStatus(str):
    status=''
    xmldoc=minidom.parseString(str)
    jointlist = xmldoc.getElementsByTagName('JointPosition') 
    # assuming in order?
    for s in jointlist:
        status = status +(s.childNodes[0].nodeValue)+":"
    x = xmldoc.getElementsByTagName("X")[0].childNodes[0].nodeValue
    y = xmldoc.getElementsByTagName("Y")[0].childNodes[0].nodeValue
    z = xmldoc.getElementsByTagName("Z")[0].childNodes[0].nodeValue
    xi= xmldoc.getElementsByTagName("XAxis")[0].getElementsByTagName("I")[0].childNodes[0].nodeValue
    xj= xmldoc.getElementsByTagName("XAxis")[0].getElementsByTagName("J")[0].childNodes[0].nodeValue
    xk= xmldoc.getElementsByTagName("XAxis")[0].getElementsByTagName("K")[0].childNodes[0].nodeValue
    zi= xmldoc.getElementsByTagName("ZAxis")[0].getElementsByTagName("I")[0].childNodes[0].nodeValue
    zj= xmldoc.getElementsByTagName("ZAxis")[0].getElementsByTagName("J")[0].childNodes[0].nodeValue
    zk= xmldoc.getElementsByTagName("ZAxis")[0].getElementsByTagName("K")[0].childNodes[0].nodeValue
    status = status + '\n'+ '(' + x +","+ y +","+ z +'),' + '(' + xi +","+ xj +","+ xk +'),'+ '(' + zi +","+ zj +","+ zk +')'+ '\n'
    return status

def x_rot(rads):
  return np.matrix([
  [1,0,0], 
  [0, np.cos(rads), -np.sin(rads)],
  [0, np.sin(rads), np.cos(rads)]])

def y_rot(rads):
  return np.matrix([
  [np.cos(rads), 0, np.sin(rads)],
  [0, 1, 0], 
  [-np.sin(rads), 0, np.cos(rads)]])

def z_rot(rads):
  return np.matrix([
  [np.cos(rads), -np.sin(rads), 0],
  [np.sin(rads), np.cos(rads), 0],
  [0,0,1]]) 
  
def rot_max(yaw, pitch, roll):
    #m=np.matrix([[1, 0,0], [0,1,0], [0,0,1]])
    yaw = math.radians(yaw)
    pitch = math.radians(pitch)
    roll = math.radians(roll)
    return z_rot(yaw)* y_rot(pitch) * x_rot(roll)

    
cmd=1
mysocket = CrclClientSocket("localhost", 64444)
print 'Socket Created'
mysocket.connect()
print 'Socket connected'

print '> ',
#for line in sys.stdin:
while(1):
    #line = 'r "/usr/local/michalos/nistfanuc_ws/src/nist_fanuc/doc/fanuclrmateprogram.xml"'
    #line = 'g 0.465 0 0.695 -180.0 -90 0'
    line=sys.stdin.readline()
    if not line.strip():
        continue

    tokens = line.split()
    if(len(tokens)==0):
        continue
    if tokens[0] == 'q' :
	break
    if tokens[0] == 'r' :
        print "r \"program path\""
        line = tokens[1].strip('\"')
        line = line[0:].strip()
	if (not os.path.isfile(line) ):
		print "Not a file name"
		continue
        print line
        try:
            contents = open(line, 'r').read()
        except IOError:
            print "Bad file name", line
        # add try catch bad file
        mysocket.syncsend(contents)

    elif tokens[0] == 'g' :
        print "g x y z r p y - in degrees"
        m = rot_max(float(tokens[6]), float(tokens[5]), float(tokens[4]))
        xi=m.item(0,0); xj=m.item(1,0); xk=m.item(2,0)
        zi=m.item(0,2); zj=m.item(1,2); zk=m.item(2,2)
        print xi,":",xj,":",xk
        print zi,":",zj,":",zk
        s=CrclMoveTo(str(cmd), str(tokens[1]),str(tokens[2]),str(tokens[3]),str(xi),str(xj),str(xk),str(zi),str(zj),str(zk))
        mysocket.syncsend(s)
    elif tokens[0] == 'j' :
        print "j # pos vel acc - in degrees"
        print tokens[0], " ", tokens[1], " ", tokens[2]
        #s=CrclActuateJoints(str(cmd), tokens[1], str(math.radians(float(tokens[2]))), 4.0, 1.0)
        s=CrclActuateJoints(str(cmd), tokens[1], tokens[2], 4.0, 1.0)
        mysocket.syncsend(s)
    elif line[0:0] == 'd' :
        print "d n - dwell in seconds"
        s=CrclDwellCmd(str(cmd),tokens[1])
        mysocket.syncsend(s)
    elif line[0:0] == 's' :
        print "s - status"
        s=CrclGetStatusCmd(str(cmd))
        mysocket.syncsend(s)
        # wait for respose
        resp=mysocket.syncreceive('</CRCLStatus>')
        status=parseStatus( resp)
        print status
    else:
         print "do not dispair, danger is not imminent" 
    cmd=cmd+1
    print '> ',

mysocket.disconnect()
