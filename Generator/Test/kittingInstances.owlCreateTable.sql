CREATE TABLE PartsBin(
PartsBinID INT NOT NULL,
_NAME varchar(100),
hasBin_PartQuantity INTEGER NOT NULL,
hasBin_PartSkuRef varchar(100) NOT NULL,
CHECK(hasBin_PartQuantity >= 0),
PRIMARY KEY (PartsBinID, _NAME)
);

CREATE TABLE LargeContainer(
LargeContainerID INT NOT NULL,
_NAME varchar(100),
hasLargeContainer_SkuRef varchar(100),
hasLargeContainer_SerialNumber varchar(100),
PRIMARY KEY (LargeContainerID, _NAME)
);

CREATE TABLE SolidObject(
SolidObjectID INT NOT NULL AUTO_INCREMENT, 
_NAME varchar(100),
PRIMARY KEY (SolidObjectID, _NAME)
);

CREATE TABLE KittingWorkstation(
KittingWorkstationID INT NOT NULL,
_NAME varchar(100),
hasWorkstation_LengthUnit varchar(20) NOT NULL,
hasWorkstation_WeightUnit varchar(20) NOT NULL,
hasWorkstation_AngleUnit varchar(20) NOT NULL,
PRIMARY KEY (KittingWorkstationID, _NAME)
);

CREATE TABLE BoxyObject(
BoxyObjectID INT NOT NULL,
_NAME varchar(100),
hasBox_Width DOUBLE NOT NULL,
hasBox_Height DOUBLE NOT NULL,
hasBox_Length DOUBLE NOT NULL,
CHECK(hasBox_Width >= 0),
CHECK(hasBox_Height >= 0),
CHECK(hasBox_Length >= 0),
PRIMARY KEY (BoxyObjectID, _NAME)
);

CREATE TABLE GripperEffector(
GripperEffectorID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (GripperEffectorID, _NAME)
);

CREATE TABLE PhysicalLocation(
PhysicalLocationID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (PhysicalLocationID, _NAME)
);

CREATE TABLE ShapeDesign(
ShapeDesignID INT NOT NULL,
_NAME varchar(100),
hasShapeDesign_Description varchar(255) NOT NULL,
PRIMARY KEY (ShapeDesignID, _NAME)
);

CREATE TABLE RelativeLocationIn(
RelativeLocationInID INT NOT NULL,
_NAME varchar(100),
hasRelativeLocationIn_Description varchar(255) NOT NULL,
PRIMARY KEY (RelativeLocationInID, _NAME)
);

CREATE TABLE KitInstance(
KitInstanceID INT NOT NULL,
_NAME varchar(100),
isKitInstance_Finished boolean NOT NULL,
hasKitInstance_DesignRef varchar(100),
PRIMARY KEY (KitInstanceID, _NAME)
);

CREATE TABLE Part(
PartID INT NOT NULL,
_NAME varchar(100),
hasPart_SerialNumber varchar(100),
hasPart_SkuRef varchar(100),
PRIMARY KEY (PartID, _NAME)
);

CREATE TABLE PartsTrayWithParts(
PartsTrayWithPartsID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (PartsTrayWithPartsID, _NAME)
);

CREATE TABLE PartsTray(
PartsTrayID INT NOT NULL,
_NAME varchar(100),
hasPartsTray_SkuRef varchar(100),
hasPartsTray_SerialNumber varchar(100),
PRIMARY KEY (PartsTrayID, _NAME)
);

CREATE TABLE Pose(
PoseID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (PoseID, _NAME)
);

CREATE TABLE Robot(
RobotID INT NOT NULL,
_NAME varchar(100),
hasRobot_Id varchar(100) NOT NULL,
hasRobot_MaximumLoadWeight DOUBLE NOT NULL,
hasRobot_Description varchar(255) NOT NULL,
CHECK(hasRobot_MaximumLoadWeight >= 0),
PRIMARY KEY (RobotID, _NAME)
);

CREATE TABLE LargeBoxWithKits(
LargeBoxWithKitsID INT NOT NULL,
_NAME varchar(100),
hasLargeBoxWithKits_Capacity INTEGER,
hasLargeBoxWithKits_KitDesignRef varchar(100),
CHECK(hasLargeBoxWithKits_Capacity >= 0),
PRIMARY KEY (LargeBoxWithKitsID, _NAME)
);

CREATE TABLE PartRefAndPose(
PartRefAndPoseID INT NOT NULL,
_NAME varchar(100),
hasPartRefAndPose_Ref varchar(100) NOT NULL,
PRIMARY KEY (PartRefAndPoseID, _NAME)
);

CREATE TABLE VacuumEffectorMultiCup(
VacuumEffectorMultiCupID INT NOT NULL,
_NAME varchar(100),
hasMultiCup_ArrayNumber INTEGER NOT NULL,
hasMultiCup_ArrayRadius DOUBLE NOT NULL,
CHECK(hasMultiCup_ArrayNumber >= 0),
CHECK(hasMultiCup_ArrayRadius >= 0),
PRIMARY KEY (VacuumEffectorMultiCupID, _NAME)
);

CREATE TABLE EndEffectorChangingStation(
EndEffectorChangingStationID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (EndEffectorChangingStationID, _NAME)
);

CREATE TABLE RelativeLocation(
RelativeLocationID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (RelativeLocationID, _NAME)
);

CREATE TABLE Vector(
VectorID INT NOT NULL,
_NAME varchar(100),
hasVector_K DOUBLE NOT NULL,
hasVector_J DOUBLE NOT NULL,
hasVector_I DOUBLE NOT NULL,
PRIMARY KEY (VectorID, _NAME)
);

CREATE TABLE KitTray(
KitTrayID INT NOT NULL,
_NAME varchar(100),
hasKitTray_SerialNumber varchar(100),
hasKitTray_SkuRef varchar(100),
PRIMARY KEY (KitTrayID, _NAME)
);

CREATE TABLE StockKeepingUnit(
StockKeepingUnitID INT NOT NULL,
_NAME varchar(100),
hasSku_Description varchar(255) NOT NULL,
hasSku_Id varchar(100) NOT NULL,
hasSku_Weight DOUBLE NOT NULL,
CHECK(hasSku_Weight >= 0),
PRIMARY KEY (StockKeepingUnitID, _NAME)
);

CREATE TABLE Point(
PointID INT NOT NULL,
_NAME varchar(100),
hasPoint_X DOUBLE NOT NULL,
hasPoint_Y DOUBLE NOT NULL,
hasPoint_Z DOUBLE NOT NULL,
PRIMARY KEY (PointID, _NAME)
);

CREATE TABLE WorkTable(
WorkTableID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (WorkTableID, _NAME)
);

CREATE TABLE LargeBoxWithEmptyKitTrays(
LargeBoxWithEmptyKitTraysID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (LargeBoxWithEmptyKitTraysID, _NAME)
);

CREATE TABLE BoxVolume(
BoxVolumeID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (BoxVolumeID, _NAME)
);

CREATE TABLE VacuumEffectorSingleCup(
VacuumEffectorSingleCupID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (VacuumEffectorSingleCupID, _NAME)
);

CREATE TABLE DataThing(
DataThingID INT NOT NULL AUTO_INCREMENT, 
_NAME varchar(100),
PRIMARY KEY (DataThingID, _NAME)
);

CREATE TABLE EndEffector(
EndEffectorID INT NOT NULL,
_NAME varchar(100),
hasEndEffector_Weight DOUBLE NOT NULL,
hasEffector_MaximumLoadWeight DOUBLE NOT NULL,
hasEndEffector_Description varchar(255) NOT NULL,
hasEndEffector_Id varchar(100) NOT NULL,
CHECK(hasEndEffector_Weight >= 0),
CHECK(hasEffector_MaximumLoadWeight >= 0),
PRIMARY KEY (EndEffectorID, _NAME)
);

CREATE TABLE KitDesign(
KitDesignID INT NOT NULL,
_NAME varchar(100),
hasKitDesign_Id varchar(100) NOT NULL,
hasKitDesign_KitTraySkuRef varchar(100),
PRIMARY KEY (KitDesignID, _NAME)
);

CREATE TABLE VacuumEffector(
VacuumEffectorID INT NOT NULL,
_NAME varchar(100),
hasVacuumEffector_CupDiameter DOUBLE NOT NULL,
hasVacuumEffector_Length DOUBLE NOT NULL,
CHECK(hasVacuumEffector_CupDiameter >= 0),
CHECK(hasVacuumEffector_Length >= 0),
PRIMARY KEY (VacuumEffectorID, _NAME)
);

CREATE TABLE EndEffectorHolder(
EndEffectorHolderID INT NOT NULL,
_NAME varchar(100),
PRIMARY KEY (EndEffectorHolderID, _NAME)
);

CREATE TABLE RelativeLocationOn(
RelativeLocationOnID INT NOT NULL,
_NAME varchar(100),
hasRelativeLocationOn_Description varchar(255) NOT NULL,
PRIMARY KEY (RelativeLocationOnID, _NAME)
);

CREATE TABLE RollPitchYaw(
RollPitchYawID INT NOT NULL,
_NAME varchar(100),
hasRpy_Roll DOUBLE NOT NULL,
hasRpy_Pitch DOUBLE NOT NULL,
hasRpy_Yaw DOUBLE NOT NULL,
PRIMARY KEY (RollPitchYawID, _NAME)
);

CREATE TABLE hasSku_EndEffectorRefsValue(
StockKeepingUnitID INT NOT NULL,
hasSku_EndEffectorRefs varchar(100) NOT NULL, 
PRIMARY KEY (StockKeepingUnitID,hasSku_EndEffectorRefs)
);



ALTER TABLE SolidObject
ADD hasSolidObject_PhysicalLocation VARCHAR(255),
ADD CONSTRAINT fkhasSolidObject_PhysicalLocation
FOREIGN KEY(hasSolidObject_PhysicalLocation) REFERENCES PhysicalLocation(_NAME);

ALTER TABLE EndEffectorChangingStation
ADD hadByChangingStation_Workstation VARCHAR(255),
ADD CONSTRAINT fkhadByChangingStation_Workstation
FOREIGN KEY(hadByChangingStation_Workstation) REFERENCES KittingWorkstation(NAME);

CREATE TABLE hasWorkstation_OtherObstacles(
KittingWorkstationID INT NOT NULL,
BoxVolumeID INT NOT NULL,
PRIMARY KEY (KittingWorkstationID,BoxVolumeID)
);

ALTER TABLE WorkTable
ADD hadByWorkTable_Workstation VARCHAR(255),
ADD CONSTRAINT fkhadByWorkTable_Workstation
FOREIGN KEY(hadByWorkTable_Workstation) REFERENCES KittingWorkstation(NAME);

ALTER TABLE Robot
ADD hadByRobot_Workstation VARCHAR(255),
ADD CONSTRAINT fkhadByRobot_Workstation
FOREIGN KEY(hadByRobot_Workstation) REFERENCES KittingWorkstation(NAME);

ALTER TABLE PhysicalLocation
ADD hasPhysicalLocation_RefObject VARCHAR(255),
ADD CONSTRAINT fkhasPhysicalLocation_RefObject
FOREIGN KEY(hasPhysicalLocation_RefObject) REFERENCES SolidObject(_NAME);

ALTER TABLE KitTray
ADD hadByKitTray_KitInstance VARCHAR(255),
ADD CONSTRAINT fkhadByKitTray_KitInstance
FOREIGN KEY(hadByKitTray_KitInstance) REFERENCES KitInstance(NAME);

ALTER TABLE PartsTray
ADD hadByPartsTray_PartsTrayWithParts VARCHAR(255),
ADD CONSTRAINT fkhadByPartsTray_PartsTrayWithParts
FOREIGN KEY(hadByPartsTray_PartsTrayWithParts) REFERENCES PartsTrayWithParts(NAME);

ALTER TABLE Pose
ADD hasPose_Point VARCHAR(255),
ADD CONSTRAINT fkhasPose_Point
FOREIGN KEY(hasPose_Point) REFERENCES Point(_NAME);

ALTER TABLE Pose
ADD hasPose_Rpy VARCHAR(255),
ADD CONSTRAINT fkhasPose_Rpy
FOREIGN KEY(hasPose_Rpy) REFERENCES RollPitchYaw(_NAME);

CREATE TABLE hasRobot_WorkVolume(
RobotID INT NOT NULL,
BoxVolumeID INT NOT NULL,
PRIMARY KEY (RobotID,BoxVolumeID)
);

ALTER TABLE LargeContainer
ADD hadByLargeContainer_LargeBoxWithKits VARCHAR(255),
ADD CONSTRAINT fkhadByLargeContainer_LargeBoxWithKits
FOREIGN KEY(hadByLargeContainer_LargeBoxWithKits) REFERENCES LargeBoxWithKits(NAME);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_Rpy VARCHAR(255),
ADD CONSTRAINT fkhasPartRefAndPose_Rpy
FOREIGN KEY(hasPartRefAndPose_Rpy) REFERENCES RollPitchYaw(_NAME);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_Point VARCHAR(255),
ADD CONSTRAINT fkhasPartRefAndPose_Point
FOREIGN KEY(hasPartRefAndPose_Point) REFERENCES Point(_NAME);

ALTER TABLE StockKeepingUnit
ADD hasSku_Shape VARCHAR(255),
ADD CONSTRAINT fkhasSku_Shape
FOREIGN KEY(hasSku_Shape) REFERENCES ShapeDesign(_NAME);

ALTER TABLE LargeContainer
ADD hadByLargeContainer_LargeBoxWithEmptyKitTrays VARCHAR(255),
ADD CONSTRAINT fkhadByLargeContainer_LargeBoxWithEmptyKitTrays
FOREIGN KEY(hadByLargeContainer_LargeBoxWithEmptyKitTrays) REFERENCES LargeBoxWithEmptyKitTrays(NAME);

ALTER TABLE BoxVolume
ADD hasBoxVolume_MaximumPoint VARCHAR(255),
ADD CONSTRAINT fkhasBoxVolume_MaximumPoint
FOREIGN KEY(hasBoxVolume_MaximumPoint) REFERENCES Point(_NAME);

ALTER TABLE BoxVolume
ADD hasBoxVolume_MinimumPoint VARCHAR(255),
ADD CONSTRAINT fkhasBoxVolume_MinimumPoint
FOREIGN KEY(hasBoxVolume_MinimumPoint) REFERENCES Point(_NAME);