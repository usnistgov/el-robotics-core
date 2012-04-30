CREATE TABLE PartsBin(
PartsBinID INT NOT NULL,
_NAME varchar(100),
hasBin_PartQuantity INTEGER NOT NULL,
hasBin_PartSkuRef varchar(100) NOT NULL,
CHECK(hasBin_PartQuantity >= 0),
PRIMARY KEY (PartsBinID)
);

CREATE TABLE LargeContainer(
LargeContainerID INT NOT NULL,
_NAME varchar(100),
hasLargeContainer_SkuRef varchar(100),
hasLargeContainer_SerialNumber varchar(100),
PRIMARY KEY (LargeContainerID)
);

CREATE TABLE SolidObject(
SolidObjectID INT NOT NULL AUTO_INCREMENT, 
_NAME varchar(100),
PRIMARY KEY (SolidObjectID)
);

CREATE TABLE KittingWorkstation(
KittingWorkstationID INT NOT NULL,
_NAME varchar(100),
hasWorkstation_LengthUnit varchar(20) NOT NULL,
hasWorkstation_WeightUnit varchar(20) NOT NULL,
hasWorkstation_AngleUnit varchar(20) NOT NULL,
PRIMARY KEY (KittingWorkstationID)
);

CREATE TABLE BoxyObject(
BoxyObjectID INT NOT NULL,
_NAME varchar(100),
hasBox_Width DECIMAL NOT NULL,
hasBox_Height DECIMAL NOT NULL,
hasBox_Length DECIMAL NOT NULL,
CHECK(hasBox_Width >= 0),
CHECK(hasBox_Height >= 0),
CHECK(hasBox_Length >= 0),
PRIMARY KEY (BoxyObjectID)
);

CREATE TABLE GripperEffector(
GripperEffectorID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (GripperEffectorID)
);

CREATE TABLE PhysicalLocation(
PhysicalLocationID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (PhysicalLocationID)
);

CREATE TABLE ShapeDesign(
ShapeDesignID INT NOT NULL,
_NAME varchar(100),
hasShapeDesign_Description varchar(255) NOT NULL,
PRIMARY KEY (ShapeDesignID)
);

CREATE TABLE RelativeLocationIn(
RelativeLocationInID INT NOT NULL,
_NAME varchar(100),
hasRelativeLocationIn_Description varchar(255) NOT NULL,
PRIMARY KEY (RelativeLocationInID)
);

CREATE TABLE KitInstance(
KitInstanceID INT NOT NULL,
_NAME varchar(100),
isKitInstance_Finished boolean NOT NULL,
hasKitInstance_DesignRef varchar(100),
PRIMARY KEY (KitInstanceID)
);

CREATE TABLE Part(
PartID INT NOT NULL,
_NAME varchar(100),
hasPart_SerialNumber varchar(100),
hasPart_SkuRef varchar(100),
PRIMARY KEY (PartID)
);

CREATE TABLE PartsTrayWithParts(
PartsTrayWithPartsID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (PartsTrayWithPartsID)
);

CREATE TABLE PartsTray(
PartsTrayID INT NOT NULL,
_NAME varchar(100),
hasPartsTray_SkuRef varchar(100),
hasPartsTray_SerialNumber varchar(100),
PRIMARY KEY (PartsTrayID)
);

CREATE TABLE Pose(
PoseID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (PoseID)
);

CREATE TABLE Robot(
RobotID INT NOT NULL,
_NAME varchar(100),
hasRobot_Id varchar(100) NOT NULL,
hasRobot_MaximumLoadWeight DECIMAL NOT NULL,
hasRobot_Description varchar(255) NOT NULL,
CHECK(hasRobot_MaximumLoadWeight >= 0),
PRIMARY KEY (RobotID)
);

CREATE TABLE LargeBoxWithKits(
LargeBoxWithKitsID INT NOT NULL,
_NAME varchar(100),
hasLargeBoxWithKits_Capacity INTEGER,
hasLargeBoxWithKits_KitDesignRef varchar(100),
CHECK(hasLargeBoxWithKits_Capacity >= 0),
PRIMARY KEY (LargeBoxWithKitsID)
);

CREATE TABLE PartRefAndPose(
PartRefAndPoseID INT NOT NULL,
_NAME varchar(100),
hasPartRefAndPose_Ref varchar(100) NOT NULL,
PRIMARY KEY (PartRefAndPoseID)
);

CREATE TABLE VacuumEffectorMultiCup(
VacuumEffectorMultiCupID INT NOT NULL,
_NAME varchar(100),
hasMultiCup_ArrayNumber INTEGER NOT NULL,
hasMultiCup_ArrayRadius DECIMAL NOT NULL,
CHECK(hasMultiCup_ArrayNumber >= 0),
CHECK(hasMultiCup_ArrayRadius >= 0),
PRIMARY KEY (VacuumEffectorMultiCupID)
);

CREATE TABLE EndEffectorChangingStation(
EndEffectorChangingStationID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (EndEffectorChangingStationID)
);

CREATE TABLE RelativeLocation(
RelativeLocationID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (RelativeLocationID)
);

CREATE TABLE Vector(
VectorID INT NOT NULL,
_NAME varchar(100),
hasVector_K DECIMAL NOT NULL,
hasVector_J DECIMAL NOT NULL,
hasVector_I DECIMAL NOT NULL,
PRIMARY KEY (VectorID)
);

CREATE TABLE KitTray(
KitTrayID INT NOT NULL,
_NAME varchar(100),
hasKitTray_SerialNumber varchar(100),
hasKitTray_SkuRef varchar(100),
PRIMARY KEY (KitTrayID)
);

CREATE TABLE StockKeepingUnit(
StockKeepingUnitID INT NOT NULL,
_NAME varchar(100),
hasSku_Description varchar(255) NOT NULL,
hasSku_Id varchar(100) NOT NULL,
hasSku_Weight DECIMAL NOT NULL,
CHECK(hasSku_Weight >= 0),
PRIMARY KEY (StockKeepingUnitID)
);

CREATE TABLE Point(
PointID INT NOT NULL,
_NAME varchar(100),
hasPoint_X DECIMAL NOT NULL,
hasPoint_Y DECIMAL NOT NULL,
hasPoint_Z DECIMAL NOT NULL,
PRIMARY KEY (PointID)
);

CREATE TABLE WorkTable(
WorkTableID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (WorkTableID)
);

CREATE TABLE LargeBoxWithEmptyKitTrays(
LargeBoxWithEmptyKitTraysID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (LargeBoxWithEmptyKitTraysID)
);

CREATE TABLE BoxVolume(
BoxVolumeID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (BoxVolumeID)
);

CREATE TABLE VacuumEffectorSingleCup(
VacuumEffectorSingleCupID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (VacuumEffectorSingleCupID)
);

CREATE TABLE DataThing(
DataThingID INT NOT NULL AUTO_INCREMENT, 
_NAME varchar(100),
PRIMARY KEY (DataThingID)
);

CREATE TABLE EndEffector(
EndEffectorID INT NOT NULL,
_NAME varchar(100),
hasEndEffector_Weight DECIMAL NOT NULL,
hasEffector_MaximumLoadWeight DECIMAL NOT NULL,
hasEndEffector_Description varchar(255) NOT NULL,
hasEndEffector_Id varchar(100) NOT NULL,
CHECK(hasEndEffector_Weight >= 0),
CHECK(hasEffector_MaximumLoadWeight >= 0),
PRIMARY KEY (EndEffectorID)
);

CREATE TABLE KitDesign(
KitDesignID INT NOT NULL,
_NAME varchar(100),
hasKitDesign_Id varchar(100) NOT NULL,
hasKitDesign_KitTraySkuRef varchar(100),
PRIMARY KEY (KitDesignID)
);

CREATE TABLE VacuumEffector(
VacuumEffectorID INT NOT NULL,
_NAME varchar(100),
hasVacuumEffector_CupDiameter DECIMAL NOT NULL,
hasVacuumEffector_Length DECIMAL NOT NULL,
CHECK(hasVacuumEffector_CupDiameter >= 0),
CHECK(hasVacuumEffector_Length >= 0),
PRIMARY KEY (VacuumEffectorID)
);

CREATE TABLE EndEffectorHolder(
EndEffectorHolderID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (EndEffectorHolderID)
);

CREATE TABLE RelativeLocationOn(
RelativeLocationOnID INT NOT NULL,
_NAME varchar(100),
hasRelativeLocationOn_Description varchar(255) NOT NULL,
PRIMARY KEY (RelativeLocationOnID)
);

CREATE TABLE RollPitchYaw(
RollPitchYawID INT NOT NULL,
_NAME varchar(100),
hasRpy_Roll DECIMAL NOT NULL,
hasRpy_Pitch DECIMAL NOT NULL,
hasRpy_Yaw DECIMAL NOT NULL,
PRIMARY KEY (RollPitchYawID)
);

CREATE TABLE hasSku_EndEffectorRefsValue(
StockKeepingUnitID INT NOT NULL,
hasSku_EndEffectorRefs varchar(100) NOT NULL, 
PRIMARY KEY (StockKeepingUnitID,hasSku_EndEffectorRefs)
);



ALTER TABLE SolidObject
ADD hasSolidObject_PhysicalLocation INT,
ADD CONSTRAINT fkhasSolidObject_PhysicalLocation
FOREIGN KEY(hasSolidObject_PhysicalLocation) REFERENCES PhysicalLocation(PhysicalLocationID);

ALTER TABLE EndEffectorChangingStation
ADD hadByChangingStation_Workstation INT,
ADD CONSTRAINT fkhadByChangingStation_Workstation
FOREIGN KEY(hadByChangingStation_Workstation) REFERENCES KittingWorkstation(KittingWorkstationID);

CREATE TABLE hasWorkstation_OtherObstacles(
KittingWorkstationID INT NOT NULL,
BoxVolumeID INT NOT NULL,
PRIMARY KEY (KittingWorkstationID,BoxVolumeID)
);

ALTER TABLE WorkTable
ADD hadByWorkTable_Workstation INT,
ADD CONSTRAINT fkhadByWorkTable_Workstation
FOREIGN KEY(hadByWorkTable_Workstation) REFERENCES KittingWorkstation(KittingWorkstationID);

ALTER TABLE Robot
ADD hadByRobot_Workstation INT,
ADD CONSTRAINT fkhadByRobot_Workstation
FOREIGN KEY(hadByRobot_Workstation) REFERENCES KittingWorkstation(KittingWorkstationID);

ALTER TABLE PhysicalLocation
ADD hasPhysicalLocation_RefObject INT,
ADD CONSTRAINT fkhasPhysicalLocation_RefObject
FOREIGN KEY(hasPhysicalLocation_RefObject) REFERENCES SolidObject(SolidObjectID);

ALTER TABLE KitTray
ADD hadByKitTray_KitInstance INT,
ADD CONSTRAINT fkhadByKitTray_KitInstance
FOREIGN KEY(hadByKitTray_KitInstance) REFERENCES KitInstance(KitInstanceID);

ALTER TABLE PartsTray
ADD hadByPartsTray_PartsTrayWithParts INT,
ADD CONSTRAINT fkhadByPartsTray_PartsTrayWithParts
FOREIGN KEY(hadByPartsTray_PartsTrayWithParts) REFERENCES PartsTrayWithParts(PartsTrayWithPartsID);

ALTER TABLE Pose
ADD hasPose_Point INT,
ADD CONSTRAINT fkhasPose_Point
FOREIGN KEY(hasPose_Point) REFERENCES Point(PointID);

ALTER TABLE Pose
ADD hasPose_Rpy INT,
ADD CONSTRAINT fkhasPose_Rpy
FOREIGN KEY(hasPose_Rpy) REFERENCES RollPitchYaw(RollPitchYawID);

CREATE TABLE hasRobot_WorkVolume(
RobotID INT NOT NULL,
BoxVolumeID INT NOT NULL,
PRIMARY KEY (RobotID,BoxVolumeID)
);

ALTER TABLE LargeContainer
ADD hadByLargeContainer_LargeBoxWithKits INT,
ADD CONSTRAINT fkhadByLargeContainer_LargeBoxWithKits
FOREIGN KEY(hadByLargeContainer_LargeBoxWithKits) REFERENCES LargeBoxWithKits(LargeBoxWithKitsID);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_Rpy INT,
ADD CONSTRAINT fkhasPartRefAndPose_Rpy
FOREIGN KEY(hasPartRefAndPose_Rpy) REFERENCES RollPitchYaw(RollPitchYawID);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_Point INT,
ADD CONSTRAINT fkhasPartRefAndPose_Point
FOREIGN KEY(hasPartRefAndPose_Point) REFERENCES Point(PointID);

ALTER TABLE StockKeepingUnit
ADD hasSku_Shape INT,
ADD CONSTRAINT fkhasSku_Shape
FOREIGN KEY(hasSku_Shape) REFERENCES ShapeDesign(ShapeDesignID);

ALTER TABLE LargeContainer
ADD hadByLargeContainer_LargeBoxWithEmptyKitTrays INT,
ADD CONSTRAINT fkhadByLargeContainer_LargeBoxWithEmptyKitTrays
FOREIGN KEY(hadByLargeContainer_LargeBoxWithEmptyKitTrays) REFERENCES LargeBoxWithEmptyKitTrays(LargeBoxWithEmptyKitTraysID);

ALTER TABLE BoxVolume
ADD hasBoxVolume_MaximumPoint INT,
ADD CONSTRAINT fkhasBoxVolume_MaximumPoint
FOREIGN KEY(hasBoxVolume_MaximumPoint) REFERENCES Point(PointID);

ALTER TABLE BoxVolume
ADD hasBoxVolume_MinimumPoint INT,
ADD CONSTRAINT fkhasBoxVolume_MinimumPoint
FOREIGN KEY(hasBoxVolume_MinimumPoint) REFERENCES Point(PointID);