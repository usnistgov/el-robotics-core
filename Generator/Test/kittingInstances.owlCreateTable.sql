CREATE TABLE PartsBin(
PartsBinID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasBin_PartQuantity INTEGER NOT NULL,
hasBin_PartSkuRef varchar(100) NOT NULL,
CHECK(hasBin_PartQuantity >= 0),
PRIMARY KEY (PartsBinID, _NAME)
);

CREATE TABLE LargeContainer(
LargeContainerID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasLargeContainer_SkuRef varchar(100),
hasLargeContainer_SerialNumber varchar(100),
PRIMARY KEY (LargeContainerID, _NAME)
);

CREATE TABLE SolidObject(
SolidObjectID INT NOT NULL AUTO_INCREMENT, 
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (SolidObjectID, _NAME)
);

CREATE TABLE KittingWorkstation(
KittingWorkstationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasWorkstation_LengthUnit varchar(20) NOT NULL,
hasWorkstation_WeightUnit varchar(20) NOT NULL,
hasWorkstation_AngleUnit varchar(20) NOT NULL,
PRIMARY KEY (KittingWorkstationID, _NAME)
);

CREATE TABLE BoxyObject(
BoxyObjectID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
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
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (GripperEffectorID, _NAME)
);

CREATE TABLE PhysicalLocation(
PhysicalLocationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PhysicalLocationID, _NAME)
);

CREATE TABLE ShapeDesign(
ShapeDesignID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasShapeDesign_Description varchar(255) NOT NULL,
PRIMARY KEY (ShapeDesignID, _NAME)
);

CREATE TABLE RelativeLocationIn(
RelativeLocationInID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasRelativeLocationIn_Description varchar(255) NOT NULL,
PRIMARY KEY (RelativeLocationInID, _NAME)
);

CREATE TABLE KitInstance(
KitInstanceID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
isKitInstance_Finished boolean NOT NULL,
hasKitInstance_DesignRef varchar(100),
PRIMARY KEY (KitInstanceID, _NAME)
);

CREATE TABLE Part(
PartID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPart_SerialNumber varchar(100),
hasPart_SkuRef varchar(100),
PRIMARY KEY (PartID, _NAME)
);

CREATE TABLE PartsTrayWithParts(
PartsTrayWithPartsID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PartsTrayWithPartsID, _NAME)
);

CREATE TABLE PartsTray(
PartsTrayID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPartsTray_SkuRef varchar(100),
hasPartsTray_SerialNumber varchar(100),
PRIMARY KEY (PartsTrayID, _NAME)
);

CREATE TABLE Pose(
PoseID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PoseID, _NAME)
);

CREATE TABLE Robot(
RobotID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasRobot_Id varchar(100) NOT NULL,
hasRobot_MaximumLoadWeight DOUBLE NOT NULL,
hasRobot_Description varchar(255) NOT NULL,
CHECK(hasRobot_MaximumLoadWeight >= 0),
PRIMARY KEY (RobotID, _NAME)
);

CREATE TABLE LargeBoxWithKits(
LargeBoxWithKitsID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasLargeBoxWithKits_Capacity INTEGER,
hasLargeBoxWithKits_KitDesignRef varchar(100),
CHECK(hasLargeBoxWithKits_Capacity >= 0),
PRIMARY KEY (LargeBoxWithKitsID, _NAME)
);

CREATE TABLE PartRefAndPose(
PartRefAndPoseID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPartRefAndPose_Ref varchar(100) NOT NULL,
PRIMARY KEY (PartRefAndPoseID, _NAME)
);

CREATE TABLE VacuumEffectorMultiCup(
VacuumEffectorMultiCupID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasMultiCup_ArrayNumber INTEGER NOT NULL,
hasMultiCup_ArrayRadius DOUBLE NOT NULL,
CHECK(hasMultiCup_ArrayNumber >= 0),
CHECK(hasMultiCup_ArrayRadius >= 0),
PRIMARY KEY (VacuumEffectorMultiCupID, _NAME)
);

CREATE TABLE EndEffectorChangingStation(
EndEffectorChangingStationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (EndEffectorChangingStationID, _NAME)
);

CREATE TABLE RelativeLocation(
RelativeLocationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (RelativeLocationID, _NAME)
);

CREATE TABLE Vector(
VectorID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasVector_K DOUBLE NOT NULL,
hasVector_J DOUBLE NOT NULL,
hasVector_I DOUBLE NOT NULL,
PRIMARY KEY (VectorID, _NAME)
);

CREATE TABLE KitTray(
KitTrayID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasKitTray_SerialNumber varchar(100),
hasKitTray_SkuRef varchar(100),
PRIMARY KEY (KitTrayID, _NAME)
);

CREATE TABLE StockKeepingUnit(
StockKeepingUnitID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasSku_Description varchar(255) NOT NULL,
hasSku_Id varchar(100) NOT NULL,
hasSku_Weight DOUBLE NOT NULL,
CHECK(hasSku_Weight >= 0),
PRIMARY KEY (StockKeepingUnitID, _NAME)
);

CREATE TABLE Point(
PointID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPoint_X DOUBLE NOT NULL,
hasPoint_Y DOUBLE NOT NULL,
hasPoint_Z DOUBLE NOT NULL,
PRIMARY KEY (PointID, _NAME)
);

CREATE TABLE WorkTable(
WorkTableID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (WorkTableID, _NAME)
);

CREATE TABLE LargeBoxWithEmptyKitTrays(
LargeBoxWithEmptyKitTraysID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (LargeBoxWithEmptyKitTraysID, _NAME)
);

CREATE TABLE BoxVolume(
BoxVolumeID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (BoxVolumeID, _NAME)
);

CREATE TABLE VacuumEffectorSingleCup(
VacuumEffectorSingleCupID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (VacuumEffectorSingleCupID, _NAME)
);

CREATE TABLE DataThing(
DataThingID INT NOT NULL AUTO_INCREMENT, 
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (DataThingID, _NAME)
);

CREATE TABLE EndEffector(
EndEffectorID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
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
_NAME varchar(255), INDEX (_NAME),
hasKitDesign_Id varchar(100) NOT NULL,
hasKitDesign_KitTraySkuRef varchar(100),
PRIMARY KEY (KitDesignID, _NAME)
);

CREATE TABLE VacuumEffector(
VacuumEffectorID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasVacuumEffector_CupDiameter DOUBLE NOT NULL,
hasVacuumEffector_Length DOUBLE NOT NULL,
CHECK(hasVacuumEffector_CupDiameter >= 0),
CHECK(hasVacuumEffector_Length >= 0),
PRIMARY KEY (VacuumEffectorID, _NAME)
);

CREATE TABLE EndEffectorHolder(
EndEffectorHolderID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (EndEffectorHolderID, _NAME)
);

CREATE TABLE RelativeLocationOn(
RelativeLocationOnID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasRelativeLocationOn_Description varchar(255) NOT NULL,
PRIMARY KEY (RelativeLocationOnID, _NAME)
);

CREATE TABLE RollPitchYaw(
RollPitchYawID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
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



ALTER TABLE LargeBoxWithKits
ADD hasLargeBoxWithKits_LargeContainer VARCHAR(255),
ADD CONSTRAINT fkhasLargeBoxWithKits_LargeContainer
FOREIGN KEY(hasLargeBoxWithKits_LargeContainer) REFERENCES LargeContainer(_NAME);

ALTER TABLE LargeBoxWithEmptyKitTrays
ADD hasLargeBoxWithEmptyKitTrays_LargeContainer VARCHAR(255),
ADD CONSTRAINT fkhasLargeBoxWithEmptyKitTrays_LargeContainer
FOREIGN KEY(hasLargeBoxWithEmptyKitTrays_LargeContainer) REFERENCES LargeContainer(_NAME);

ALTER TABLE SolidObject
ADD hadBySolidObject_WorkTable VARCHAR(255),
ADD CONSTRAINT fkhadBySolidObject_WorkTable
FOREIGN KEY(hadBySolidObject_WorkTable) REFERENCES WorkTable(_NAME);

ALTER TABLE SolidObject
ADD hasSolidObject_PhysicalLocation VARCHAR(255),
ADD CONSTRAINT fkhasSolidObject_PhysicalLocation
FOREIGN KEY(hasSolidObject_PhysicalLocation) REFERENCES PhysicalLocation(_NAME);

ALTER TABLE KitDesign
ADD hadByKitDesign_Workstation VARCHAR(255),
ADD CONSTRAINT fkhadByKitDesign_Workstation
FOREIGN KEY(hadByKitDesign_Workstation) REFERENCES KittingWorkstation(_NAME);

ALTER TABLE KittingWorkstation
ADD hasWorkstation_ChangingStation VARCHAR(255),
ADD CONSTRAINT fkhasWorkstation_ChangingStation
FOREIGN KEY(hasWorkstation_ChangingStation) REFERENCES EndEffectorChangingStation(_NAME);

CREATE TABLE hasWorkstation_OtherObstacles(
KittingWorkstationID INT NOT NULL,
BoxVolumeID INT NOT NULL,
PRIMARY KEY (KittingWorkstationID,BoxVolumeID)
);

ALTER TABLE KittingWorkstation
ADD hasWorkstation_WorkTable VARCHAR(255),
ADD CONSTRAINT fkhasWorkstation_WorkTable
FOREIGN KEY(hasWorkstation_WorkTable) REFERENCES WorkTable(_NAME);

ALTER TABLE StockKeepingUnit
ADD hadBySku_Workstation VARCHAR(255),
ADD CONSTRAINT fkhadBySku_Workstation
FOREIGN KEY(hadBySku_Workstation) REFERENCES KittingWorkstation(_NAME);

ALTER TABLE KittingWorkstation
ADD hasWorkstation_Robot VARCHAR(255),
ADD CONSTRAINT fkhasWorkstation_Robot
FOREIGN KEY(hasWorkstation_Robot) REFERENCES Robot(_NAME);

ALTER TABLE PhysicalLocation
ADD hasPhysicalLocation_RefObject VARCHAR(255),
ADD CONSTRAINT fkhasPhysicalLocation_RefObject
FOREIGN KEY(hasPhysicalLocation_RefObject) REFERENCES SolidObject(_NAME);

ALTER TABLE Part
ADD hadByPart_KitInstance VARCHAR(255),
ADD CONSTRAINT fkhadByPart_KitInstance
FOREIGN KEY(hadByPart_KitInstance) REFERENCES KitInstance(_NAME);

ALTER TABLE KitInstance
ADD hasKitInstance_Tray VARCHAR(255),
ADD CONSTRAINT fkhasKitInstance_Tray
FOREIGN KEY(hasKitInstance_Tray) REFERENCES KitTray(_NAME);

ALTER TABLE KitInstance
ADD hadByKitInstance_LargeBoxWithKits VARCHAR(255),
ADD CONSTRAINT fkhadByKitInstance_LargeBoxWithKits
FOREIGN KEY(hadByKitInstance_LargeBoxWithKits) REFERENCES LargeBoxWithKits(_NAME);

ALTER TABLE Part
ADD hadByPart_PartsTrayWithParts VARCHAR(255),
ADD CONSTRAINT fkhadByPart_PartsTrayWithParts
FOREIGN KEY(hadByPart_PartsTrayWithParts) REFERENCES PartsTrayWithParts(_NAME);

ALTER TABLE PartsTrayWithParts
ADD hasPartsTrayWithParts_PartsTray VARCHAR(255),
ADD CONSTRAINT fkhasPartsTrayWithParts_PartsTray
FOREIGN KEY(hasPartsTrayWithParts_PartsTray) REFERENCES PartsTray(_NAME);

ALTER TABLE Pose
ADD hasPose_Point VARCHAR(255),
ADD CONSTRAINT fkhasPose_Point
FOREIGN KEY(hasPose_Point) REFERENCES Point(_NAME);

ALTER TABLE Pose
ADD hasPose_Rpy VARCHAR(255),
ADD CONSTRAINT fkhasPose_Rpy
FOREIGN KEY(hasPose_Rpy) REFERENCES RollPitchYaw(_NAME);

ALTER TABLE EndEffector
ADD hadByEndEffector_Robot VARCHAR(255),
ADD CONSTRAINT fkhadByEndEffector_Robot
FOREIGN KEY(hadByEndEffector_Robot) REFERENCES Robot(_NAME);

CREATE TABLE hasRobot_WorkVolume(
RobotID INT NOT NULL,
BoxVolumeID INT NOT NULL,
PRIMARY KEY (RobotID,BoxVolumeID)
);

ALTER TABLE PartRefAndPose
ADD hadByPartRefAndPose_KitDesign VARCHAR(255),
ADD CONSTRAINT fkhadByPartRefAndPose_KitDesign
FOREIGN KEY(hadByPartRefAndPose_KitDesign) REFERENCES KitDesign(_NAME);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_Rpy VARCHAR(255),
ADD CONSTRAINT fkhasPartRefAndPose_Rpy
FOREIGN KEY(hasPartRefAndPose_Rpy) REFERENCES RollPitchYaw(_NAME);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_Point VARCHAR(255),
ADD CONSTRAINT fkhasPartRefAndPose_Point
FOREIGN KEY(hasPartRefAndPose_Point) REFERENCES Point(_NAME);

ALTER TABLE EndEffectorHolder
ADD hadByEndEffectorHolder_ChangingStation VARCHAR(255),
ADD CONSTRAINT fkhadByEndEffectorHolder_ChangingStation
FOREIGN KEY(hadByEndEffectorHolder_ChangingStation) REFERENCES EndEffectorChangingStation(_NAME);

ALTER TABLE KitTray
ADD hadByKitTray_LargeBoxWithEmptyKitTrays VARCHAR(255),
ADD CONSTRAINT fkhadByKitTray_LargeBoxWithEmptyKitTrays
FOREIGN KEY(hadByKitTray_LargeBoxWithEmptyKitTrays) REFERENCES LargeBoxWithEmptyKitTrays(_NAME);

ALTER TABLE StockKeepingUnit
ADD hasSku_Shape VARCHAR(255),
ADD CONSTRAINT fkhasSku_Shape
FOREIGN KEY(hasSku_Shape) REFERENCES ShapeDesign(_NAME);

ALTER TABLE BoxVolume
ADD hasBoxVolume_MaximumPoint VARCHAR(255),
ADD CONSTRAINT fkhasBoxVolume_MaximumPoint
FOREIGN KEY(hasBoxVolume_MaximumPoint) REFERENCES Point(_NAME);

ALTER TABLE BoxVolume
ADD hasBoxVolume_MinimumPoint VARCHAR(255),
ADD CONSTRAINT fkhasBoxVolume_MinimumPoint
FOREIGN KEY(hasBoxVolume_MinimumPoint) REFERENCES Point(_NAME);

ALTER TABLE EndEffectorHolder
ADD hasEndEffectorHolder_EndEffector VARCHAR(255),
ADD CONSTRAINT fkhasEndEffectorHolder_EndEffector
FOREIGN KEY(hasEndEffectorHolder_EndEffector) REFERENCES EndEffector(_NAME);