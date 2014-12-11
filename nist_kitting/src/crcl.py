#!/usr/bin/python

import sys, StringIO, xml.etree.ElementTree as ET

xmldec = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
uri = "http://www.w3.org/2001/XMLSchema-instance"
xsi = "{" + uri + "}"
dict = {"xmlns:xsi" : uri}

class DataThingType(object):

    def __init__(self, Name=""):
        self.Name = Name

class PointType(DataThingType):

    def __init__(self, X = 0, Y = 0, Z = 0):
        DataThingType.__init__(self)
        self.X = X
        self.Y = Y
        self.Z = Z

class VectorType(DataThingType):

    def __init__(self, I, J, K):
        DataThingType.__init__(self)
        self.I = I
        self.J = J
        self.K = K

class PhysicalLocationType(DataThingType):

    def __init__(self, TimeStamp = 0):
        DataThingType.__init__(self)
        self.TimeStamp = TimeStamp

class PoseLocationType(PhysicalLocationType):

    def __init__(self, Point = PointType(), XAxis = VectorType(1,0,0), ZAxis = VectorType(0,0,1), PositionStandardDeviation = 1, OrientationStandardDeviation = 1):
        PhysicalLocationType.__init__(self)
        self.Point = Point
        self.XAxis = XAxis
        self.ZAxis = ZAxis
        self.PositionStandardDeviation = PositionStandardDeviation
        self.OrientationStandardDeviation = OrientationStandardDeviation

class PoseOnlyLocationType(PoseLocationType):

    def __init__(self):
        PoseLocationType.__init__(self)
        self.PointType = PointType()
        self.XAxisType = VectorType(1,0,0)
        self.ZAxisType = VectorType(0,0,1)

class CRCLCommandType(DataThingType):

    def __init__(self, CommandID = 0):
        DataThingType.__init__(self)
        self.CommandID = CommandID

class MiddleCommandType(CRCLCommandType):

    def __init__(self, CommandID = 0):
        CRCLCommandType.__init__(self, CommandID)

class OpenToolChangerType(MiddleCommandType):

    def __init__(self, CommandID = 0):
        MiddleCommandType.__init__(self, CommandID)

    def __str__(self):
        root = ET.Element("CRCLCommandInstance", attrib=dict)
        ccel = ET.Element("CRCLCommand", attrib={"xsi:type" : "OpenToolChangerType"})
        root.append(ccel)
        ET.SubElement(ccel, "CommandID").text = str(self.CommandID)
        tree = ET.ElementTree(root)
        output = StringIO.StringIO()
        tree.write(output)
        outstr = output.getvalue()
        output.close()
        return outstr

class CloseToolChangerType(MiddleCommandType):

    def __init__(self, CommandID = 0):
        MiddleCommandType.__init__(self, CommandID)

    def __str__(self):
        root = ET.Element("CRCLCommandInstance", attrib=dict)
        ccel = ET.Element("CRCLCommand", attrib={"xsi:type" : "OpenToolChangerType"})
        root.append(ccel)
        ET.SubElement(ccel, "CommandID").text = str(self.CommandID)
        tree = ET.ElementTree(root)
        output = StringIO.StringIO()
        tree.write(output)
        outstr = output.getvalue()
        output.close()
        return outstr

class MoveThroughToType(MiddleCommandType):

    def __init__(self, CommandID = 0):
        MiddleCommandType.__init__(self, CommandID)
        self.MoveStraight = False
        self.Waypoint = []
        self.NumPositions = len(self.Waypoint)

    def __str__(self):
        root = ET.Element("CRCLCommandInstance", attrib=dict)
        ccel = ET.Element("CRCLCommand", attrib={"xsi:type" : "MoveThroughToType"})
        root.append(ccel)
        ET.SubElement(ccel, "CommandID").text = str(self.CommandID)
        if self.MoveStraight: ET.SubElement(ccel, "MoveStraight").text = "true"
        else: ET.SubElement(ccel, "MoveStraight").text = "false"
        for wp in self.Waypoint:
            wpel = ET.SubElement(ccel, "Waypoint")
            ptel = ET.SubElement(wpel, "Point")
            ET.SubElement(ptel, "X").text = str(wp.PointType.X)
            ET.SubElement(ptel, "Y").text = str(wp.PointType.Y)
            ET.SubElement(ptel, "Z").text = str(wp.PointType.Z)
            xel = ET.SubElement(wpel, "XAxis")
            ET.SubElement(xel, "I").text = str(wp.XAxisType.I)
            ET.SubElement(xel, "J").text = str(wp.XAxisType.J)
            ET.SubElement(xel, "K").text = str(wp.XAxisType.K)
            zel = ET.SubElement(wpel, "ZAxis")
            ET.SubElement(zel, "I").text = str(wp.ZAxisType.I)
            ET.SubElement(zel, "J").text = str(wp.ZAxisType.J)
            ET.SubElement(zel, "K").text = str(wp.ZAxisType.K)
        ET.SubElement(ccel, "NumPositions").text = str(self.NumPositions)
        tree = ET.ElementTree(root)
        output = StringIO.StringIO()
        tree.write(output)
        outstr = output.getvalue()
        output.close()
        return outstr

    def add(self, wps):
        try:
            self.Waypoint.append(wps)
        except:
            return False
        self.NumPositions = len(self.Waypoint)
        return True

class SetEndEffectorParametersType(MiddleCommandType):

    def __init__(self, Parameters, CommandID = 0):
        MiddleCommandType.__init__(self, CommandID)
        self.ParameterSetting = []
        for key in iter(Parameters):
            pst = ParameterSettingType(key, Parameters.get(key))
            self.ParameterSetting.append(pst)

    def __str__(self):
        root = ET.Element("CRCLCommandInstance", attrib=dict)
        ccel = ET.SubElement(root, "CRCLCommand", attrib={"xsi:type" : "SetEndEffectorParametersType"})
        ET.SubElement(ccel, "CommandID").text = str(self.CommandID)
        for p in self.ParameterSetting:
            psel = ET.SubElement(ccel, "ParameterSetting")
            pnel = ET.SubElement(psel, "ParameterName").text = str(p.ParameterName)
            pvel = ET.SubElement(psel, "ParameterValue").text = str(p.ParameterValue)
        tree = ET.ElementTree(root)
        output = StringIO.StringIO()
        tree.write(output)
        outstr = output.getvalue()
        output.close()
        return outstr

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

class ParameterSettingType(DataThingType):

    def __init__(self, ParameterName, ParameterValue, CommandID = 0):
        DataThingType.__init__(self, "ParameterSettingType")
        self.ParameterName = ParameterName
        self.ParameterValue = ParameterValue

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

    def __str__(self):
        root = ET.Element("CRCLStatus", attrib=dict)
        csel = ET.SubElement(root, "CommandStatus")
        ET.SubElement(csel, "CommandID").text = "1"
        ET.SubElement(csel, "StatusID").text = "1"
        ET.SubElement(csel, "CommandID").text = "1"
        ET.SubElement(csel, "CommandState").text = "Working"
        tree = ET.ElementTree(root)
        output = StringIO.StringIO()
        tree.write(output)
        outstr = output.getvalue()
        output.close()
        return outstr
