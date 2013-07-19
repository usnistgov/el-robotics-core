CREATE TABLE PartsBin(
PartsBinID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPartsBin_PartQuantity INTEGER NOT NULL,
hasPartsBin_SerialNumber varchar(100),
CHECK(hasPartsBin_PartQuantity >= 0),
PRIMARY KEY (PartsBinID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE LargeContainer(
LargeContainerID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasLargeContainer_SerialNumber varchar(100),
PRIMARY KEY (LargeContainerID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE SolidObject(
SolidObjectID INT NOT NULL AUTO_INCREMENT, 
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (SolidObjectID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE KittingWorkstation(
KittingWorkstationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasWorkstation_LengthUnit varchar(20) NOT NULL,
hasWorkstation_AngleUnit varchar(20) NOT NULL,
hasWorkstation_WeightUnit varchar(20) NOT NULL,
PRIMARY KEY (KittingWorkstationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE MechanicalComponent(
MechanicalComponentID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (MechanicalComponentID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE GripperEffector(
GripperEffectorID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (GripperEffectorID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PoseLocationIn(
PoseLocationInID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PoseLocationInID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PhysicalLocation(
PhysicalLocationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PhysicalLocationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE ShapeDesign(
ShapeDesignID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasShapeDesign_Description varchar(255) NOT NULL,
PRIMARY KEY (ShapeDesignID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE RelativeLocationIn(
RelativeLocationInID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (RelativeLocationInID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Part(
PartID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPart_SerialNumber varchar(100),
PRIMARY KEY (PartID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PartsTray(
PartsTrayID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPartsTray_SerialNumber varchar(100),
PRIMARY KEY (PartsTrayID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PartsTrayWithParts(
PartsTrayWithPartsID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PartsTrayWithPartsID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Robot(
RobotID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasRobot_Description varchar(255) NOT NULL,
hasRobot_MaximumLoadWeight DOUBLE NOT NULL,
CHECK(hasRobot_MaximumLoadWeight >= 0),
PRIMARY KEY (RobotID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE LargeBoxWithKits(
LargeBoxWithKitsID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasLargeBoxWithKits_Capacity INTEGER,
CHECK(hasLargeBoxWithKits_Capacity >= 0),
PRIMARY KEY (LargeBoxWithKitsID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PartRefAndPose(
PartRefAndPoseID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PartRefAndPoseID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE VacuumEffectorMultiCup(
VacuumEffectorMultiCupID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasMultiCup_ArrayNumber INTEGER NOT NULL,
hasMultiCup_ArrayRadius DOUBLE NOT NULL,
CHECK(hasMultiCup_ArrayNumber >= 0),
CHECK(hasMultiCup_ArrayRadius >= 0),
PRIMARY KEY (VacuumEffectorMultiCupID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE EndEffectorChangingStation(
EndEffectorChangingStationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (EndEffectorChangingStationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE RelativeLocation(
RelativeLocationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasRelativeLocation_Description varchar(255) NOT NULL,
PRIMARY KEY (RelativeLocationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE InternalShape(
InternalShapeID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (InternalShapeID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Vector(
VectorID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasVector_K DOUBLE NOT NULL,
hasVector_J DOUBLE NOT NULL,
hasVector_I DOUBLE NOT NULL,
PRIMARY KEY (VectorID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE KitTray(
KitTrayID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasKitTray_SerialNumber varchar(100),
PRIMARY KEY (KitTrayID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE BoxyShape(
BoxyShapeID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasBoxyShape_Width DOUBLE NOT NULL,
hasBoxyShape_Top boolean NOT NULL,
hasBoxyShape_Height DOUBLE NOT NULL,
hasBoxyShape_Length DOUBLE NOT NULL,
CHECK(hasBoxyShape_Width >= 0),
CHECK(hasBoxyShape_Height >= 0),
CHECK(hasBoxyShape_Length >= 0),
PRIMARY KEY (BoxyShapeID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE StockKeepingUnit(
StockKeepingUnitID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasSku_Description varchar(255) NOT NULL,
hasSku_Weight DOUBLE NOT NULL,
CHECK(hasSku_Weight >= 0),
PRIMARY KEY (StockKeepingUnitID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Point(
PointID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPoint_X DOUBLE NOT NULL,
hasPoint_Y DOUBLE NOT NULL,
hasPoint_Z DOUBLE NOT NULL,
PRIMARY KEY (PointID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE WorkTable(
WorkTableID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (WorkTableID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE LargeBoxWithEmptyKitTrays(
LargeBoxWithEmptyKitTraysID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (LargeBoxWithEmptyKitTraysID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE BoxVolume(
BoxVolumeID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (BoxVolumeID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE VacuumEffectorSingleCup(
VacuumEffectorSingleCupID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (VacuumEffectorSingleCupID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE DataThing(
DataThingID INT NOT NULL AUTO_INCREMENT, 
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (DataThingID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE EndEffector(
EndEffectorID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasEndEffector_Description varchar(255) NOT NULL,
hasEndEffector_Weight DOUBLE NOT NULL,
hasEffector_MaximumLoadWeight DOUBLE NOT NULL,
CHECK(hasEndEffector_Weight >= 0),
CHECK(hasEffector_MaximumLoadWeight >= 0),
PRIMARY KEY (EndEffectorID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE ExternalShape(
ExternalShapeID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasExternalShape_ModelTypeName varchar(255) NOT NULL,
hasExternalShape_ModelName varchar(255),
hasExternalShape_ModelFileName varchar(255) NOT NULL,
PRIMARY KEY (ExternalShapeID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE KitDesign(
KitDesignID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (KitDesignID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PoseLocation(
PoseLocationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PoseLocationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Kit(
KitID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
isKit_Finished boolean NOT NULL,
PRIMARY KEY (KitID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE VacuumEffector(
VacuumEffectorID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasVacuumEffector_CupDiameter DOUBLE NOT NULL,
hasVacuumEffector_Length DOUBLE NOT NULL,
CHECK(hasVacuumEffector_CupDiameter >= 0),
CHECK(hasVacuumEffector_Length >= 0),
PRIMARY KEY (VacuumEffectorID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE EndEffectorHolder(
EndEffectorHolderID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (EndEffectorHolderID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE RelativeLocationOn(
RelativeLocationOnID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (RelativeLocationOnID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PoseOnlyLocation(
PoseOnlyLocationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PoseOnlyLocationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PoseLocationOn(
PoseLocationOnID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PoseLocationOnID, _NAME)
)ENGINE=InnoDB;



ALTER TABLE PartsBin
ADD hasPartsBin_Sku VARCHAR(255),
ADD CONSTRAINT fkhasPartsBin_Sku
FOREIGN KEY(hasPartsBin_Sku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE PartsBin
ADD hasPartsBin_PartSku VARCHAR(255),
ADD CONSTRAINT fkhasPartsBin_PartSku
FOREIGN KEY(hasPartsBin_PartSku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE LargeBoxWithKits
ADD hasLargeBoxWithKits_LargeContainer VARCHAR(255),
ADD CONSTRAINT fkhasLargeBoxWithKits_LargeContainer
FOREIGN KEY(hasLargeBoxWithKits_LargeContainer) REFERENCES LargeContainer(_NAME);

ALTER TABLE LargeContainer
ADD hasLargeContainer_Sku VARCHAR(255),
ADD CONSTRAINT fkhasLargeContainer_Sku
FOREIGN KEY(hasLargeContainer_Sku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE LargeBoxWithEmptyKitTrays
ADD hasLargeBoxWithEmptyKitTrays_LargeContainer VARCHAR(255),
ADD CONSTRAINT fkhasLargeBoxWithEmptyKitTrays_LargeContainer
FOREIGN KEY(hasLargeBoxWithEmptyKitTrays_LargeContainer) REFERENCES LargeContainer(_NAME);

CREATE TABLE hasSolidObject_SecondaryLocation(
SolidObjectID INT NOT NULL,
PhysicalLocationID INT NOT NULL,
PRIMARY KEY (SolidObjectID,PhysicalLocationID)
);

ALTER TABLE SolidObject
ADD hasSolidObject_InternalShape VARCHAR(255),
ADD CONSTRAINT fkhasSolidObject_InternalShape
FOREIGN KEY(hasSolidObject_InternalShape) REFERENCES InternalShape(_NAME);

ALTER TABLE SolidObject
ADD hasSolidObject_PrimaryLocation VARCHAR(255),
ADD CONSTRAINT fkhasSolidObject_PrimaryLocation
FOREIGN KEY(hasSolidObject_PrimaryLocation) REFERENCES PhysicalLocation(_NAME);

ALTER TABLE SolidObject
ADD hadBySolidObject_WorkTable VARCHAR(255),
ADD CONSTRAINT fkhadBySolidObject_WorkTable
FOREIGN KEY(hadBySolidObject_WorkTable) REFERENCES WorkTable(_NAME);

ALTER TABLE SolidObject
ADD hasSolidObject_ExternalShape VARCHAR(255),
ADD CONSTRAINT fkhasSolidObject_ExternalShape
FOREIGN KEY(hasSolidObject_ExternalShape) REFERENCES ExternalShape(_NAME);

ALTER TABLE KitDesign
ADD hadByKitDesign_Workstation VARCHAR(255),
ADD CONSTRAINT fkhadByKitDesign_Workstation
FOREIGN KEY(hadByKitDesign_Workstation) REFERENCES KittingWorkstation(_NAME);

ALTER TABLE KittingWorkstation
ADD hasWorkstation_ChangingStation VARCHAR(255),
ADD CONSTRAINT fkhasWorkstation_ChangingStation
FOREIGN KEY(hasWorkstation_ChangingStation) REFERENCES EndEffectorChangingStation(_NAME);

ALTER TABLE KittingWorkstation
ADD hasWorkstation_WorkTable VARCHAR(255),
ADD CONSTRAINT fkhasWorkstation_WorkTable
FOREIGN KEY(hasWorkstation_WorkTable) REFERENCES WorkTable(_NAME);

CREATE TABLE hasWorkstation_OtherObstacles(
KittingWorkstationID INT NOT NULL,
BoxVolumeID INT NOT NULL,
PRIMARY KEY (KittingWorkstationID,BoxVolumeID)
);

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

ALTER TABLE ShapeDesign
ADD hasShapeDesign_GraspPose VARCHAR(255),
ADD CONSTRAINT fkhasShapeDesign_GraspPose
FOREIGN KEY(hasShapeDesign_GraspPose) REFERENCES PoseLocation(_NAME);

ALTER TABLE Part
ADD hadByPart_Kit VARCHAR(255),
ADD CONSTRAINT fkhadByPart_Kit
FOREIGN KEY(hadByPart_Kit) REFERENCES Kit(_NAME);

ALTER TABLE Part
ADD hadByPart_PartsTrayWithParts VARCHAR(255),
ADD CONSTRAINT fkhadByPart_PartsTrayWithParts
FOREIGN KEY(hadByPart_PartsTrayWithParts) REFERENCES PartsTrayWithParts(_NAME);

ALTER TABLE Part
ADD hasPart_Sku VARCHAR(255),
ADD CONSTRAINT fkhasPart_Sku
FOREIGN KEY(hasPart_Sku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE PartsTray
ADD hasPartsTray_Sku VARCHAR(255),
ADD CONSTRAINT fkhasPartsTray_Sku
FOREIGN KEY(hasPartsTray_Sku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE PartsTrayWithParts
ADD hasPartsTrayWithParts_Tray VARCHAR(255),
ADD CONSTRAINT fkhasPartsTrayWithParts_Tray
FOREIGN KEY(hasPartsTrayWithParts_Tray) REFERENCES PartsTray(_NAME);

ALTER TABLE EndEffector
ADD hadByEndEffector_Robot VARCHAR(255),
ADD CONSTRAINT fkhadByEndEffector_Robot
FOREIGN KEY(hadByEndEffector_Robot) REFERENCES Robot(_NAME);

CREATE TABLE hasRobot_WorkVolume(
RobotID INT NOT NULL,
BoxVolumeID INT NOT NULL,
PRIMARY KEY (RobotID,BoxVolumeID)
);

ALTER TABLE Kit
ADD hadByKit_LargeBoxWithKits VARCHAR(255),
ADD CONSTRAINT fkhadByKit_LargeBoxWithKits
FOREIGN KEY(hadByKit_LargeBoxWithKits) REFERENCES LargeBoxWithKits(_NAME);

ALTER TABLE LargeBoxWithKits
ADD hasLargeBoxWithKits_KitDesign VARCHAR(255),
ADD CONSTRAINT fkhasLargeBoxWithKits_KitDesign
FOREIGN KEY(hasLargeBoxWithKits_KitDesign) REFERENCES KitDesign(_NAME);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_Sku VARCHAR(255),
ADD CONSTRAINT fkhasPartRefAndPose_Sku
FOREIGN KEY(hasPartRefAndPose_Sku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_ZAxis VARCHAR(255),
ADD CONSTRAINT fkhasPartRefAndPose_ZAxis
FOREIGN KEY(hasPartRefAndPose_ZAxis) REFERENCES Vector(_NAME);

ALTER TABLE PartRefAndPose
ADD hadByPartRefAndPose_KitDesign VARCHAR(255),
ADD CONSTRAINT fkhadByPartRefAndPose_KitDesign
FOREIGN KEY(hadByPartRefAndPose_KitDesign) REFERENCES KitDesign(_NAME);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_Point VARCHAR(255),
ADD CONSTRAINT fkhasPartRefAndPose_Point
FOREIGN KEY(hasPartRefAndPose_Point) REFERENCES Point(_NAME);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_XAxis VARCHAR(255),
ADD CONSTRAINT fkhasPartRefAndPose_XAxis
FOREIGN KEY(hasPartRefAndPose_XAxis) REFERENCES Vector(_NAME);

ALTER TABLE EndEffectorChangingStation
ADD hasChangingStation_Base VARCHAR(255),
ADD CONSTRAINT fkhasChangingStation_Base
FOREIGN KEY(hasChangingStation_Base) REFERENCES MechanicalComponent(_NAME);

ALTER TABLE EndEffectorHolder
ADD hadByEndEffectorHolder_ChangingStation VARCHAR(255),
ADD CONSTRAINT fkhadByEndEffectorHolder_ChangingStation
FOREIGN KEY(hadByEndEffectorHolder_ChangingStation) REFERENCES EndEffectorChangingStation(_NAME);

ALTER TABLE KitTray
ADD hasKitTray_Sku VARCHAR(255),
ADD CONSTRAINT fkhasKitTray_Sku
FOREIGN KEY(hasKitTray_Sku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE Kit
ADD hasKit_Tray VARCHAR(255),
ADD CONSTRAINT fkhasKit_Tray
FOREIGN KEY(hasKit_Tray) REFERENCES KitTray(_NAME);

ALTER TABLE KitTray
ADD hadByKitTray_LargeBoxWithEmptyKitTrays VARCHAR(255),
ADD CONSTRAINT fkhadByKitTray_LargeBoxWithEmptyKitTrays
FOREIGN KEY(hadByKitTray_LargeBoxWithEmptyKitTrays) REFERENCES LargeBoxWithEmptyKitTrays(_NAME);

CREATE TABLE hasSku_EndEffectors(
StockKeepingUnitID INT NOT NULL,
EndEffectorID INT NOT NULL,
PRIMARY KEY (StockKeepingUnitID,EndEffectorID)
);

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

ALTER TABLE EndEffector
ADD hasEndEffector_HeldObject VARCHAR(255),
ADD CONSTRAINT fkhasEndEffector_HeldObject
FOREIGN KEY(hasEndEffector_HeldObject) REFERENCES SolidObject(_NAME);

ALTER TABLE EndEffectorHolder
ADD hasEndEffectorHolder_EndEffector VARCHAR(255),
ADD CONSTRAINT fkhasEndEffectorHolder_EndEffector
FOREIGN KEY(hasEndEffectorHolder_EndEffector) REFERENCES EndEffector(_NAME);

ALTER TABLE KitDesign
ADD hasKitDesign_KitTraySku VARCHAR(255),
ADD CONSTRAINT fkhasKitDesign_KitTraySku
FOREIGN KEY(hasKitDesign_KitTraySku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE PoseLocation
ADD hasPoseLocation_Point VARCHAR(255),
ADD CONSTRAINT fkhasPoseLocation_Point
FOREIGN KEY(hasPoseLocation_Point) REFERENCES Point(_NAME);

ALTER TABLE PoseLocation
ADD hasPoseLocation_ZAxis VARCHAR(255),
ADD CONSTRAINT fkhasPoseLocation_ZAxis
FOREIGN KEY(hasPoseLocation_ZAxis) REFERENCES Vector(_NAME);

ALTER TABLE PoseLocation
ADD hasPoseLocation_XAxis VARCHAR(255),
ADD CONSTRAINT fkhasPoseLocation_XAxis
FOREIGN KEY(hasPoseLocation_XAxis) REFERENCES Vector(_NAME);

ALTER TABLE Kit
ADD hasKit_Design VARCHAR(255),
ADD CONSTRAINT fkhasKit_Design
FOREIGN KEY(hasKit_Design) REFERENCES KitDesign(_NAME);