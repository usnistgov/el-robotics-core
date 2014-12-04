#!/usr/bin/python

class Point(object):
    def __init__(self, X = 0, Y = 0, Z = 0):
        self.X = X
        self.Y = Y
        self.Z = Z

class Axis(object):
    def __init__(self, I, J, K):
        self.I = I
        self.J = J
        self.K = K

class XAxis(Axis):
    def __init__(self):
        Axis.__init__(self, 1, 0, 0)

class YAxis(Axis):
    def __init__(self):
        Axis.__init__(self, 0, 1, 0)

class ZAxis(Axis):
    def __init__(self):
        Axis.__init__(self, 0, 0, 1)

class Pose(object):
    def __init__(self):
        self.Point = Point()
        self.XAxis = XAxis()
        self.ZAxis = ZAxis()

class Waypoint(object):
    def __init__(self):
        self.Point = Point()
        self.XAxis = XAxis()
        self.ZAxis = ZAxis()

# When we have xsi:type attributes, we have an inheritance relationship,
# e.g., <CRCLCommand xsi:type="MoveThroughToType">

class CRCLCommand(object):
    def __init__(self, CommandID):
        self.CommandID = CommandID

class MoveThroughTo(CRCLCommand):
    def __init__(self, CommandID = 0):
        CRCLCommand.__init__(self, CommandID)
        self.MoveStraight = False
        self._Waypoints = [Waypoint()]
        self.NumPositions = len(self._Waypoints)

class InitCanon(CRCLCommand):
    def __init__(self, CommmandID = 0):
        CRCLCommand.__init__(self, CommandID)

class EndCanon(CRCLCommand):
    def __init__(self, CommmandID = 0):
        CRCLCommand.__init__(self, CommandID)

# We don't have xsi:type attributes for <CRCLStatus>, so no inheritance

class CommandStatus(object):
    READY = 11
    WORKING = 22
    def __init__(self, CommandID = 0, StatusID = 0, CommandState = READY):
        self.CommandID = CommandID
        self.StatusID = StatusID
        self.CommandState = CommandState

class JointStatus(object):
    def __init__(self, JointNumber = 0, JointPosition = 0, JointTorqueOrForce = 0):
        self.JointNumber = JointNumber
        self.JointPosition = JointPosition
        self.JointTorqueOrForce = JointTorqueOrForce

