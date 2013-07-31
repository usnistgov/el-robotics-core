#!/usr/bin/python

import random
import math
import os
import re

num_goals = 100

robotBaseOffset = [-1.266, -1.222, -1.472]
jointLimits = [(-3.140,3.140), (-2.356,0.610), (-2.094,2.757),(-3.140,3.140),(-2.076,2.076),(-3.140,3.140)]
tmpname = "tmp"

def getRandCont(randMin, randMax):
  return random.random() * (randMax - randMin) + randMin

def getFKPose():
  jtVals = [0]*6
  for i in range(len(jtVals)):
    jtVals[i] = getRandCont(jointLimits[i][0], jointLimits[i][1])
  cmdStr = "./compute fk " + " ".join(map(str, jtVals)) + " > " +tmpname
  os.system(cmdStr)
  tmpfile = open(tmpname, 'r')
  pos = []
  xAxis = []
  zAxis = []
  rot3next = False
  for line in tmpfile:
    matchPos = re.search(r"Translation:  x: ([0-9.\-]*)  y: ([0-9.\-]*)  z: ([0-9.\-]*)", line)
    matchRot1 = re.search(r"Rotation +([0-9.\-]+) +([0-9.\-]+) +([0-9.\-]+)", line)
    matchRot2 = re.search(r"Matrix: +([0-9.\-]+) +([0-9.\-]+) +([0-9.\-]+)", line)
    matchRot3 = re.search(r" +([0-9.\-]+) +([0-9.\-]+) +([0-9.\-]+)", line)
    if matchPos:
      pos = map(float,matchPos.groups())
    elif matchRot1 or matchRot2 or (matchRot3 and rot3next):
      if matchRot1: match = matchRot1
      if matchRot2: match = matchRot2
      if matchRot3: match = matchRot3
      xAxis.append(float(match.groups()[0]))
      zAxis.append(float(match.groups()[2]))
    if matchRot2:
      rot3next=True
    else:
      rot3next=False
  tmpfile.close()
  os.remove(tmpname)
  return [pos, xAxis, zAxis]
  
def rotatePiX(vec):
  ret = vec[:]
  ret[1] = -1 * ret[1]
  ret[2] = -1 * ret[2]
  return ret

def trunc(n, f):
  slen = len('%.*f' % (n, f))
  return str(f)[:slen]

outFile = open('randCommand.txt', 'w')
outFile.write("InitCanon()\n")
for index in range(num_goals):
  pose = getFKPose()
  pos = pose[0]
  xAxis = pose[1]
  zAxis = pose[2]
  
  pos = rotatePiX(pos)
  xAxis = rotatePiX(xAxis)
  zAxis = rotatePiX(zAxis)
  
  #adjust by robot base
  pos = [x + y for (x,y) in zip(robotBaseOffset, pos)]
  
  line = ("MoveTo({{"+trunc(3,pos[0]) + "," +  trunc(3,pos[1]) + "," + trunc(3,pos[2]) + "},{" + 
    trunc(3,zAxis[0]) + "," + trunc(3,zAxis[1]) + "," + trunc(3,zAxis[2]) + "},{" + 
    trunc(3,xAxis[0]) + "," + trunc(3,xAxis[1]) + "," + trunc(3,xAxis[2]) + "}})\n")
  outFile.write(line)
outFile.write("EndCanon(36)\n")
outFile.close()
