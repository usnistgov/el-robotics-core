#!/usr/bin/python

import sys, StringIO, xml.etree.ElementTree as ET

xmldec = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
uri = "http://www.w3.org/2001/XMLSchema-instance"
xsi = "{" + uri + "}"
dict = {"xmlns:xsi" : uri}

class DataThingType(object):

    def __init__(self, Name=None, **kwargs):
        self.Name = Name

    def set(self, Name):
        self.Name = Name

    def get(self):
        return self.Name

    def tree(self, root=None):
        if self.Name == None: return ""
        if root == None: root = ET.Element(None)
        ET.SubElement(root, "Name").text = str(self.Name)
        return ET.ElementTree(root)

    def __str__(self):
        if self.Name == None: return ""
        output = StringIO.StringIO()
        self.tree().write(output)
        outstr = output.getvalue()
        output.close()
        return outstr

class PointType(DataThingType):

    def __init__(self, X=0, Y=0, Z=0, **kwargs):
        super(PointType, self).__init__(**kwargs)
        self.X = X
        self.Y = Y
        self.Z = Z

    def set(self, X, Y, Z):
        self.X = X
        self.Y = Y
        self.Z = Z

    def get(self):
        return self.X, self.Y, self.Z

    def tree(self, root):
        if root == None: root = ET.Element(None)
        super(PointType, self).tree(root)
        ET.SubElement(root, "X").text = str(self.X)
        ET.SubElement(root, "Y").text = str(self.Y)
        ET.SubElement(root, "Z").text = str(self.Z)
        return ET.ElementTree(root)

    def __str__(self):
        output = StringIO.StringIO()
        self.tree().write(output)
        outstr = output.getvalue()
        output.close()
        return outstr

class VectorType(DataThingType):

    def __init__(self, I=0, J=0, K=0, **kwargs):
        super(VectorType, self).__init__(**kwargs)
        self.I = I
        self.J = J
        self.K = K

    def set(self, I, J, Z):
        self.I = I
        self.J = J
        self.K = K

    def get(self):
        return self.I, self.J, self.K

    def tree(self, root):
        if root == None: root = ET.Element(None)
        super(VectorType, self).tree(root)
        ET.SubElement(root, "I").text = str(self.I)
        ET.SubElement(root, "J").text = str(self.J)
        ET.SubElement(root, "K").text = str(self.K)
        return ET.ElementTree(root)

    def __str__(self):
        output = StringIO.StringIO()
        self.tree().write(output)
        outstr = output.getvalue()
        output.close()
        return outstr

class PhysicalLocationType(DataThingType):

    def __init__(self, TimeStamp = 0):
        DataThingType.__init__(self)
        self.TimeStamp = TimeStamp

    def set(self, TimeStamp):
        self.TimeStamp = TimeStamp

class PoseLocationType(PhysicalLocationType):

    def __init__(self, Point = PointType(), XAxis = VectorType(1,0,0), ZAxis = VectorType(0,0,1), PositionStandardDeviation = 1, OrientationStandardDeviation = 1):
        PhysicalLocationType.__init__(self)
        self.Point = Point
        self.XAxis = XAxis
        self.ZAxis = ZAxis
        self.PositionStandardDeviation = PositionStandardDeviation
        self.OrientationStandardDeviation = OrientationStandardDeviation

    def set(self, Point, XAxis, ZAxis, PositionStandardDeviation, OrientationStandardDeviation):
        self.Point = Point
        self.XAxis = XAxis
        self.ZAxis = ZAxis
        self.PositionStandardDeviation = PositionStandardDeviation
        self.OrientationStandardDeviation = OrientationStandardDeviation

    def get(self):
        return self.Point.get(), self.XAxis.get(), self.ZAxis,get(), self.PositionStandardDeviation, self.OrientationStandardDeviation

    def tree(self, root):
        el = ET.SubElement(root, "PoseLocation")
        self.Point.tree(el)
        self.XAxis.tree(el)
        self.ZAxis.tree(el)
        ET.SubElement(el, "PositionStandardDeviation").text = str(self.PositionStandardDeviation)
        ET.SubElement(el, "OrientationStandardDeviation").text = str(self.OrientationStandardDeviation)

class PoseOnlyLocationType(PoseLocationType):

    def __init__(self, Point, XAxis, ZAxis):
        PoseLocationType.__init__(self, Point, XAxis, ZAxis)
        self.Point = Point
        self.XAxis = XAxis
        self.ZAxis = ZAxis

class CRCLCommandType(DataThingType):

    def __init__(self, CommandID = 0, **kwargs):
        super(CRCLCommandType, self).__init__(**kwargs)
        self.CommandID = CommandID

    def tree(self, root = None):
        if root == None: root = super(CRCLCommandType, self).tree()
        else: super(CRCLCommandType, self).tree(root)
        ET.SubElement(root, "CommandID").text = str(self.CommandID)
        
class MiddleCommandType(CRCLCommandType):

    def __init__(self, **kwargs):
        super(MiddleCommandType, self).__init__(**kwargs)

    def tree(self, root = None):
        return super(MiddleCommandType, self).tree(root)

class OpenToolChangerType(MiddleCommandType):

    def __init__(self, **kwargs):
        super(OpenToolChangerType, self).__init__(**kwargs)

    def tree(self, root = None):
        if root == None: root = ET.Element("CRCLCommandInstance", attrib=dict)
        else: ET.SubElement(root, "CRCLCommandInstance", attrib=dict)
        ccel = ET.SubElement(root, "CRCLCommand", attrib={"xsi:type" : "OpenToolChangerType"})
        super(OpenToolChangerType, self).tree(ccel)
        return ET.ElementTree(root)

    def __str__(self):
        output = StringIO.StringIO()
        self.tree().write(output)
        outstr = output.getvalue()
        output.close()
        return outstr

class CloseToolChangerType(MiddleCommandType):

    def __init__(self, **kwargs):
        super(CloseToolChangerType, self).__init__(**kwargs)

    def tree(self, root = None):
        if root == None: root = ET.Element("CRCLCommandInstance", attrib=dict)
        else: ET.SubElement(root, "CRCLCommandInstance", attrib=dict)
        ccel = ET.SubElement(root, "CRCLCommand", attrib={"xsi:type" : "CloseToolChangerType"})
        super(CloseToolChangerType, self).tree(ccel)
        return ET.ElementTree(root)

    def __str__(self):
        output = StringIO.StringIO()
        self.tree().write(output)
        outstr = output.getvalue()
        output.close()
        return outstr

class MoveThroughToType(MiddleCommandType):

    def __init__(self, **kwargs):
        super(MoveThroughToType, self).__init__(**kwargs)
        self.MoveStraight = False
        self.Waypoint = []
        self.NumPositions = len(self.Waypoint)

    def tree(self, root=None):
        if root == None: root = ET.Element("CRCLCommandInstance", attrib=dict)
        else: ET.SubElement(root, "CRCLCommandInstance", attrib=dict)
        ccel = ET.SubElement(root, "CRCLCommand", attrib={"xsi:type" : "MoveThroughToType"})
        super(MoveThroughToType, self).tree(ccel)
        if self.MoveStraight: ET.SubElement(ccel, "MoveStraight").text = "true"
        else: ET.SubElement(ccel, "MoveStraight").text = "false"
        for wp in self.Waypoint:
            wpel = ET.SubElement(ccel, "Waypoint")
            wp.Point.tree(wpel)
            wp.XAxis.tree(wpel)
            wp.ZAxis.tree(wpel)
        ET.SubElement(ccel, "NumPositions").text = str(self.NumPositions)
        return ET.ElementTree(root)

    def __str__(self):
        output = StringIO.StringIO()
        self.tree().write(output)
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

class CommandStateType(object):
    DONE = "Done"
    ERROR = "Error"
    WORKING = "Wprking"
    READY = "Ready"

class CommandStatusType(DataThingType):

    def __init__(self, CommandID = 0, StatusID = 0, CommandState = CommandStateType.READY):
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

    def tree(self, root):
        jsel = ET.SubElement(root, "JointStatus")
        ET.SubElement(jsel, "JointNumber").text = str(self.JointNumber)
        ET.SubElement(jsel, "JointPosition").text = str(self.JointPosition)
        ET.SubElement(jsel, "JointTorqueOrForce").text = str(self.JointTorqueOrForce)

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

    def tree(self, root):
        jssel = ET.SubElement(root, "JointStatuses")
        for js in self.JointStatus:
            js.tree(jssel)

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

    def __init__(self, CommandStatus, JointStatuses=None, Pose=None, GripperStatus=None):
        DataThingType.__init__(self, "CRCLStatusType")
        self.CommandStatus = CommandStatus
        self.JointStatuses = JointStatuses
        self.Pose = Pose
        self.GripperStatus = GripperStatus

    def __str__(self):
        root = ET.Element("CRCLStatus", attrib=dict)
        csel = ET.SubElement(root, "CommandStatus")
        ET.SubElement(csel, "CommandID").text = str(self.CommandStatus.CommandID)
        ET.SubElement(csel, "StatusID").text = str(self.CommandStatus.StatusID)
        ET.SubElement(csel, "CommandState").text = str(self.CommandStatus.CommandState)
        if self.JointStatuses != None:
            self.JointStatuses.tree(root)
        tree = ET.ElementTree(root)
        output = StringIO.StringIO()
        tree.write(output)
        outstr = output.getvalue()
        output.close()
        return outstr
