from time import *
from crcl import *

m = DataThingType()
print m

m = DataThingType("Name 1")
print m

m = DataThingType(Name="Name 2")
print m

# ----

m = PointType()
print m

m = PointType("Point 1")
print m

m = PointType(Name="Point 2")

m = PointType(1, 2, 3)
print m

m = PointType(1, 2, 3, Name="Point 3")
print m

if m.set(3, 4, 5): print m
else: print "set failed"

x, y, z = m.get()
print m.Name, "=", x, y, z

# ---

m = VectorType()
print m

m = VectorType("Vector 1")
print m

m = VectorType(Name="Vector 2")

m = VectorType(1, 2, 3)
print m

m = VectorType(1, 2, 3, Name="Vector 3")
print m

if m.set(3, 4, 5): print m
else: print "set failed"

x, y, z = m.get()
print m.Name, "=", x, y, z

# ---

m = PhysicalLocationType()
print m

m = PhysicalLocationType(time())
print m

m = PhysicalLocationType(Name="Name 2")
print m

m = PhysicalLocationType(time(), Name="Name 3")
print m

# ---

m = PoseLocationType()
print m

m = PoseLocationType(PointType(11,12,13), VectorType(0,1,0,Name="Ux"), ZAxis=VectorType(1,0,0))
print m

m = PoseLocationType(PointType(11,12,13), VectorType(1,0,0), VectorType(0,0,1), 0.2, 0.8, Name="Name 4", TimeStamp=time())
print m

# ---

point_a = PointType(0.1, 0.2, 0.3, Name="point_a")
ux = VectorType(1,0,0)
uz = VectorType(0,0,1)
m = PoseOnlyLocationType(point_a, ux, uz, Name="POL 1", TimeStamp=time())
print m

# ---

m = CRCLCommandType(101)
print m

try: m = MiddleCommandType()
except: print "ok on error"

m = MiddleCommandType(102)
print m

m = OpenToolChangerType(103)
print m

m = CloseToolChangerType(104)
print m

m = MoveThroughToType(104)
print m

'''

m = MoveThroughToType(Name = "Move1", CommandID = 17)
point1 = PointType(1, 2, 3, Name="Point1")
point2 = PointType(Name = "Point2")
point3 = PointType()
xaxis = VectorType(1, 0, 0, Name = "ux")
zaxis = VectorType(0, 0, 1)

m.add(PoseOnlyLocationType(point1, xaxis, zaxis))
point2.set(4, 5, 6)
m.add(PoseOnlyLocationType(point2, xaxis, zaxis))
point3.set(7, 8, 9)
m.add(PoseOnlyLocationType(point3, xaxis, zaxis))
print m

jses = JointStatusesType()
jses.add(JointStatusType(1, 1.1, 1.2))
jses.add(JointStatusType(2, 2.1, 2.2))

s = CRCLStatusType(CommandStatusType(), jses)
print s

s = OpenToolChangerType(98)
print s

s = CloseToolChangerType(77)
print s

'''
