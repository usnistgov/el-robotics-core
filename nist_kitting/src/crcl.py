#!/usr/bin/python

class DataThingType(object):
    def __init__(self, Name=""):
        self.Name = Name

class PointType(DataThingType):
    def __init__(self, X = 0, Y = 0, Z = 0):
        DataThingType.__init__(self, "PointType")
        self.X = X
        self.Y = Y
        self.Z = Z

class AxisType(DataThingType):
    def __init__(self, I, J, K):
        DataThingType.__init__(self, "AxisType")
        self.I = I
        self.J = J
        self.K = K

class XAxisType(AxisType):
    def __init__(self):
        AxisType.__init__(self, 1, 0, 0)

class YAxisType(AxisType):
    def __init__(self):
        AxisType.__init__(self, 0, 1, 0)

class ZAxisType(AxisType):
    def __init__(self):
        AxisType.__init__(self, 0, 0, 1)

class PoseType(DataThingType):
    def __init__(self):
        DataThingType.__init__(self, "PoseType")
        self.PointType = PointType()
        self.XAxisType = XAxisType()
        self.ZAxisType = ZAxisType()

class WaypointType(DataThingType):
    def __init__(self):
        DataThingType.__init__(self, "WayPointType")
        self.PointType = PointType()
        self.XAxisType = XAxisType()
        self.ZAxisType = ZAxisType()

# When we have xsi:type attributes, we have an inheritance relationship,
# e.g., <CRCLCommand xsi:type="MoveThroughToType">

class CRCLCommandType(DataThingType):
    def __init__(self, CommandID = 0):
        DataThingType.__init__(self, "CRCLCommandType")
        self.CommandID = CommandID

class MiddleCommandType(CRCLCommandType):
    def __init__(self, CommandID = 0):
        CRCLCommandType.__init__(self, CommandID)

class MoveThroughToType(MiddleCommandType):
    def __init__(self, CommandID = 0):
        MiddleCommandType.__init__(self, CommandID)
        self.MoveStraight = False
        self.Waypoint = [ ]
        self.NumPositions = len(self.Waypoint)
    def add(self, wps):
        try:
            self.Waypoint.append(wps)
        except:
            return False
        self.NumPositions = len(self.Waypoint)
        return True

class InitCanonType(CRCLCommandType):
    def __init__(self, CommmandID = 0):
        CRCLCommandType.__init__(self, CommandID)

class EndCanonType(CRCLCommandType):
    def __init__(self, CommmandID = 0):
        CRCLCommandType.__init__(self, CommandID)

class SetEndEffectorType(CRCLCommandType):
    def __init__(self, CommandID = 0):
        CRCLCommandType.__init__(self, CommandID)
        self.Setting = 0
    def set(self, Setting):
        self.Setting = Setting
        return True

# We don't have xsi:type attributes for <CRCLStatus>, so no inheritance

class CommandStateEnumType(object):
    DONE = 1
    ERROR = 2
    WORKING = 3
    READY = 4

class CommandStatusType(DataThingType):
    def __init__(self, CommandID = 0, StatusID = 0, CommandState = CommandStateEnumType.READY):
        DataThingType.__init__(self, "CommandStatusType")
        self.CommandID = CommandID
        self.StatusID = StatusID
        self.CommandState = CommandState

class JointStatusType(DataThingType):
    def __init__(self, JointNumber = 0, JointPosition = 0, JointTorqueOrForce = 0):
        DataThingType.__init__(self, "JointStatusType")
        self.JointNumber = JointNumber
        self.JointPosition = JointPosition
        self.JointTorqueOrForce = JointTorqueOrForce

class JointStatusesType(DataThingType):
    def __init__(self):
        DataThingType.__init__(self, "JointStatusesType")
        self.JointStatus = [ ]
    def add(self, wps):
        try:
            self.JointStatus.append(wps)
        except:
            return False
        return True

class GripperStatusType(DataThingType):
    def __init__(self, GripperName = "Gripper"):
        DataThingType.__init__(self, "GripperStatusType")
        self.GripperName = GripperName

class ParallelGripperStatusType(GripperStatusType):
    def __init__(self, Separation = 0):
        GripperStatusType.__init__(self, "ParallelGripper")
        self.Separation = Separation

class VacuumGripperStatusType(GripperStatusType):
    def __init__(self, IsPowered = False):
        GripperStatusType.__init__(self, "VacuumGripper")
        self.IsPowered = IsPowered

class CRCLStatusType(DataThingType):
    def __init__(self, CommandStatus, JointStatuses, Pose, GripperStatus):
        DataThingType.__init__(self, "CRCLStatusType")
        self.CommandStatus = CommandStatus
        self.JointStatuses = JointStatuses
        self.Pose = Pose
        self.GripperStatus = GripperStatus
