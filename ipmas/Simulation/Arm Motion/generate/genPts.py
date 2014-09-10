#!/usr/bin/python

import random
import math

num_goals = 100

robotBaseOffset = [-1.266, -1.222, -1.472]

def getRandCont(randMin, randMax):
  return random.random() * (randMax - randMin) + randMin

def getUnitVector(vec):
  vecMag = math.sqrt(sum([x**2 for x in vec]))
  unitVec = [x/vecMag for x in vec]
  return unitVec

def getRandomUnitVector():
  vec = [getRandCont(-1, 1) for i in range(3)]
  return getUnitVector(vec)

def getRandomPerp(vec):
  other = getRandomUnitVector()
  dotProduct = sum([x * y for (x,y) in zip(vec, other)])
  
  perp = [x - dotProduct * y for (x, y) in zip(other, vec)]
  return getUnitVector(perp)

def trunc(n, f):
  slen = len('%.*f' % (n, f))
  return str(f)[:slen]
  
outFile = open('randCommand.txt', 'w')
outFile.write("InitCanon()\n")
for index in range(num_goals):
  pos = [getRandCont(-2.3,2.3), getRandCont(-2.3,2.3), getRandCont(0,2.3)]
  
  #adjust by robot base
  pos = [x + y for (x,y) in zip(robotBaseOffset, pos)]
  
  zAxis = getRandomUnitVector()
  xAxis = getRandomPerp(zAxis)
  
  line = ("MoveTo({{"+trunc(3,pos[0]) + "," +  trunc(3,pos[1]) + "," + trunc(3,pos[2]) + "},{" + 
    trunc(3,zAxis[0]) + "," + trunc(3,zAxis[1]) + "," + trunc(3,zAxis[2]) + "},{" + 
    trunc(3,xAxis[0]) + "," + trunc(3,xAxis[1]) + "," + trunc(3,xAxis[2]) + "}})\n")
  outFile.write(line)
outFile.write("EndCanon(36)\n")
outFile.close()
    
