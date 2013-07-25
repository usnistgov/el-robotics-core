CREATE TABLE PartsBin(
PartsBinID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPartsBin_PartQuantity INTEGER NOT NULL,
hasPartsBin_SerialNumber varchar(100) NOT NULL,
CHECK(hasPartsBin_PartQuantity >= 0),
PRIMARY KEY (PartsBinID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Human(
HumanID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (HumanID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE LargeContainer(
LargeContainerID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasLargeContainer_SerialNumber varchar(100) NOT NULL,
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
hasKittingWorkstation_LengthUnit varchar(20) NOT NULL,
hasKittingWorkstation_WeightUnit varchar(20) NOT NULL,
hasKittingWorkstation_AngleUnit varchar(20) NOT NULL,
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

CREATE TABLE PhysicalLocation(
PhysicalLocationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPhysicalLocation_Timestamp varchar(255),
PRIMARY KEY (PhysicalLocationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PoseLocationIn(
PoseLocationInID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PoseLocationInID, _NAME)
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
hasPart_SerialNumber varchar(100) NOT NULL,
PRIMARY KEY (PartID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PartsTray(
PartsTrayID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPartsTray_SerialNumber varchar(100) NOT NULL,
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
hasLargeBoxWithKits_Capacity INTEGER NOT NULL,
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
hasVacuumEffectorMultiCup_ArrayRadius DOUBLE NOT NULL,
hasVacuumEffectorMultiCup_ArrayNumber INTEGER NOT NULL,
CHECK(hasVacuumEffectorMultiCup_ArrayRadius >= 0),
CHECK(hasVacuumEffectorMultiCup_ArrayNumber >= 0),
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
hasKitTray_SerialNumber varchar(100) NOT NULL,
PRIMARY KEY (KitTrayID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE BoxyShape(
BoxyShapeID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasBoxyShape_Width DOUBLE NOT NULL,
hasBoxyShape_Height DOUBLE NOT NULL,
hasBoxyShape_Length DOUBLE NOT NULL,
hasBoxyShape_HasTop boolean NOT NULL,
CHECK(hasBoxyShape_Width >= 0),
CHECK(hasBoxyShape_Height >= 0),
CHECK(hasBoxyShape_Length >= 0),
PRIMARY KEY (BoxyShapeID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE StockKeepingUnit(
StockKeepingUnitID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasStockKeepingUnit_Description varchar(255) NOT NULL,
hasStockKeepingUnit_Weight DOUBLE NOT NULL,
CHECK(hasStockKeepingUnit_Weight >= 0),
PRIMARY KEY (StockKeepingUnitID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE CylindricalShape(
CylindricalShapeID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasCylindricalShape_Height DOUBLE NOT NULL,
hasCylindricalShape_HasTop boolean NOT NULL,
hasCylindricalShape_Diameter DOUBLE NOT NULL,
CHECK(hasCylindricalShape_Height >= 0),
CHECK(hasCylindricalShape_Diameter >= 0),
PRIMARY KEY (CylindricalShapeID, _NAME)
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
hasEndEffector_MaximumLoadWeight DOUBLE NOT NULL,
CHECK(hasEndEffector_Weight >= 0),
CHECK(hasEndEffector_MaximumLoadWeight >= 0),
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

CREATE TABLE VacuumEffector(
VacuumEffectorID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasVacuumEffector_CupDiameter DOUBLE NOT NULL,
hasVacuumEffector_Length DOUBLE NOT NULL,
CHECK(hasVacuumEffector_CupDiameter >= 0),
CHECK(hasVacuumEffector_Length >= 0),
PRIMARY KEY (VacuumEffectorID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PoseLocation(
PoseLocationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPoseLocation_OrientationStandardDeviation DOUBLE,
hasPoseLocation_PositionStandardDeviation DOUBLE,
CHECK(hasPoseLocation_OrientationStandardDeviation >= 0),
CHECK(hasPoseLocation_PositionStandardDeviation >= 0),
PRIMARY KEY (PoseLocationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Kit(
KitID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasKit_Finished boolean NOT NULL,
PRIMARY KEY (KitID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Slot(
SlotID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (SlotID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE RelativeLocationOn(
RelativeLocationOnID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (RelativeLocationOnID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE EndEffectorHolder(
EndEffectorHolderID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (EndEffectorHolderID, _NAME)
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

CREATE TABLE isKit_FinishedValue(
KitID INT NOT NULL,
isKit_Finished varchar(255) NOT NULL, 
PRIMARY KEY (KitID,isKit_Finished)
);

CREATE TABLE hasBoxyShape_TopValue(
KitID INT NOT NULL,
hasBoxyShape_Top varchar(255) NOT NULL, 
PRIMARY KEY (KitID,hasBoxyShape_Top)
);



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

ALTER TABLE PhysicalLocation
ADD hadBySecondaryLocation_SolidObject VARCHAR(255),
ADD CONSTRAINT fkhadBySecondaryLocation_SolidObject
FOREIGN KEY(hadBySecondaryLocation_SolidObject) REFERENCES SolidObject(_NAME);

ALTER TABLE SolidObject
ADD hadByObject_KittingWorkstation VARCHAR(255),
ADD CONSTRAINT fkhadByObject_KittingWorkstation
FOREIGN KEY(hadByObject_KittingWorkstation) REFERENCES KittingWorkstation(_NAME);

ALTER TABLE InternalShape
ADD hadByInternalShape_SolidObject VARCHAR(255),
ADD CONSTRAINT fkhadByInternalShape_SolidObject
FOREIGN KEY(hadByInternalShape_SolidObject) REFERENCES SolidObject(_NAME);

ALTER TABLE SolidObject
ADD hasSolidObject_PrimaryLocation VARCHAR(255),
ADD CONSTRAINT fkhasSolidObject_PrimaryLocation
FOREIGN KEY(hasSolidObject_PrimaryLocation) REFERENCES PhysicalLocation(_NAME);

ALTER TABLE SolidObject
ADD hadBySolidObject_WorkTable VARCHAR(255),
ADD CONSTRAINT fkhadBySolidObject_WorkTable
FOREIGN KEY(hadBySolidObject_WorkTable) REFERENCES WorkTable(_NAME);

ALTER TABLE ExternalShape
ADD hadByExternalShape_SolidObject VARCHAR(255),
ADD CONSTRAINT fkhadByExternalShape_SolidObject
FOREIGN KEY(hadByExternalShape_SolidObject) REFERENCES SolidObject(_NAME);

ALTER TABLE EndEffector
ADD hasEndEffector_HeldObject VARCHAR(255),
ADD CONSTRAINT fkhasEndEffector_HeldObject
FOREIGN KEY(hasEndEffector_HeldObject) REFERENCES SolidObject(_NAME);

ALTER TABLE StockKeepingUnit
ADD hadBySku_KittingWorkstation VARCHAR(255),
ADD CONSTRAINT fkhadBySku_KittingWorkstation
FOREIGN KEY(hadBySku_KittingWorkstation) REFERENCES KittingWorkstation(_NAME);

ALTER TABLE KitDesign
ADD hadByKitDesign_KittingWorkstation VARCHAR(255),
ADD CONSTRAINT fkhadByKitDesign_KittingWorkstation
FOREIGN KEY(hadByKitDesign_KittingWorkstation) REFERENCES KittingWorkstation(_NAME);

ALTER TABLE BoxVolume
ADD hadByOtherObstacle_KittingWorkstation VARCHAR(255),
ADD CONSTRAINT fkhadByOtherObstacle_KittingWorkstation
FOREIGN KEY(hadByOtherObstacle_KittingWorkstation) REFERENCES KittingWorkstation(_NAME);

ALTER TABLE KittingWorkstation
ADD hasKittingWorkstation_ChangingStation VARCHAR(255),
ADD CONSTRAINT fkhasKittingWorkstation_ChangingStation
FOREIGN KEY(hasKittingWorkstation_ChangingStation) REFERENCES EndEffectorChangingStation(_NAME);

ALTER TABLE KittingWorkstation
ADD hasKittingWorkstation_Robot VARCHAR(255),
ADD CONSTRAINT fkhasKittingWorkstation_Robot
FOREIGN KEY(hasKittingWorkstation_Robot) REFERENCES Robot(_NAME);

ALTER TABLE EndEffectorChangingStation
ADD hasEndEffectorChangingStation_Base VARCHAR(255),
ADD CONSTRAINT fkhasEndEffectorChangingStation_Base
FOREIGN KEY(hasEndEffectorChangingStation_Base) REFERENCES MechanicalComponent(_NAME);

ALTER TABLE PhysicalLocation
ADD hasPhysicalLocation_RefObject VARCHAR(255),
ADD CONSTRAINT fkhasPhysicalLocation_RefObject
FOREIGN KEY(hasPhysicalLocation_RefObject) REFERENCES SolidObject(_NAME);

ALTER TABLE PoseLocation
ADD hadByGraspPose_ShapeDesign VARCHAR(255),
ADD CONSTRAINT fkhadByGraspPose_ShapeDesign
FOREIGN KEY(hadByGraspPose_ShapeDesign) REFERENCES ShapeDesign(_NAME);

ALTER TABLE StockKeepingUnit
ADD hasStockKeepingUnit_Shape VARCHAR(255),
ADD CONSTRAINT fkhasStockKeepingUnit_Shape
FOREIGN KEY(hasStockKeepingUnit_Shape) REFERENCES ShapeDesign(_NAME);

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
ADD hasPartsTrayWithParts_PartsTray VARCHAR(255),
ADD CONSTRAINT fkhasPartsTrayWithParts_PartsTray
FOREIGN KEY(hasPartsTrayWithParts_PartsTray) REFERENCES PartsTray(_NAME);

ALTER TABLE EndEffector
ADD hadByEndEffector_Robot VARCHAR(255),
ADD CONSTRAINT fkhadByEndEffector_Robot
FOREIGN KEY(hadByEndEffector_Robot) REFERENCES Robot(_NAME);

ALTER TABLE BoxVolume
ADD hadByWorkVolume_Robot VARCHAR(255),
ADD CONSTRAINT fkhadByWorkVolume_Robot
FOREIGN KEY(hadByWorkVolume_Robot) REFERENCES Robot(_NAME);

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

ALTER TABLE EndEffectorHolder
ADD hadByEndEffectorHolder_EndEffectorChangingStation VARCHAR(255),
ADD CONSTRAINT fkhadByEndEffectorHolder_EndEffectorChangingStation
FOREIGN KEY(hadByEndEffectorHolder_EndEffectorChangingStation) REFERENCES EndEffectorChangingStation(_NAME);

ALTER TABLE PoseLocation
ADD hasPoseLocation_XAxis VARCHAR(255),
ADD CONSTRAINT fkhasPoseLocation_XAxis
FOREIGN KEY(hasPoseLocation_XAxis) REFERENCES Vector(_NAME);

ALTER TABLE PoseLocation
ADD hasPoseLocation_ZAxis VARCHAR(255),
ADD CONSTRAINT fkhasPoseLocation_ZAxis
FOREIGN KEY(hasPoseLocation_ZAxis) REFERENCES Vector(_NAME);

ALTER TABLE KitTray
ADD hasKitTray_Sku VARCHAR(255),
ADD CONSTRAINT fkhasKitTray_Sku
FOREIGN KEY(hasKitTray_Sku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE Kit
ADD hasKit_KitTray VARCHAR(255),
ADD CONSTRAINT fkhasKit_KitTray
FOREIGN KEY(hasKit_KitTray) REFERENCES KitTray(_NAME);

ALTER TABLE KitTray
ADD hadByKitTray_LargeBoxWithEmptyKitTrays VARCHAR(255),
ADD CONSTRAINT fkhadByKitTray_LargeBoxWithEmptyKitTrays
FOREIGN KEY(hadByKitTray_LargeBoxWithEmptyKitTrays) REFERENCES LargeBoxWithEmptyKitTrays(_NAME);

CREATE TABLE hasStockKeepingUnit_EndEffector(
StockKeepingUnitID INT NOT NULL,
EndEffectorID INT NOT NULL,
PRIMARY KEY (StockKeepingUnitID,EndEffectorID)
);

ALTER TABLE BoxVolume
ADD hasBoxVolume_MaximumPoint VARCHAR(255),
ADD CONSTRAINT fkhasBoxVolume_MaximumPoint
FOREIGN KEY(hasBoxVolume_MaximumPoint) REFERENCES Point(_NAME);

ALTER TABLE BoxVolume
ADD hasBoxVolume_MinimumPoint VARCHAR(255),
ADD CONSTRAINT fkhasBoxVolume_MinimumPoint
FOREIGN KEY(hasBoxVolume_MinimumPoint) REFERENCES Point(_NAME);

ALTER TABLE PoseLocation
ADD hasPoseLocation_Point VARCHAR(255),
ADD CONSTRAINT fkhasPoseLocation_Point
FOREIGN KEY(hasPoseLocation_Point) REFERENCES Point(_NAME);

ALTER TABLE EndEffectorHolder
ADD hasEndEffectorHolder_EndEffector VARCHAR(255),
ADD CONSTRAINT fkhasEndEffectorHolder_EndEffector
FOREIGN KEY(hasEndEffectorHolder_EndEffector) REFERENCES EndEffector(_NAME);

ALTER TABLE KitDesign
ADD hasKitDesign_KitTraySku VARCHAR(255),
ADD CONSTRAINT fkhasKitDesign_KitTraySku
FOREIGN KEY(hasKitDesign_KitTraySku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE Kit
ADD hasKit_Design VARCHAR(255),
ADD CONSTRAINT fkhasKit_Design
FOREIGN KEY(hasKit_Design) REFERENCES KitDesign(_NAME);

ALTER TABLE Slot
ADD hadBySlot_Kit VARCHAR(255),
ADD CONSTRAINT fkhadBySlot_Kit
FOREIGN KEY(hadBySlot_Kit) REFERENCES Kit(_NAME);

ALTER TABLE Slot
ADD hasSlot_PartRefAndPose VARCHAR(255),
ADD CONSTRAINT fkhasSlot_PartRefAndPose
FOREIGN KEY(hasSlot_PartRefAndPose) REFERENCES PartRefAndPose(_NAME);

ALTER TABLE Slot
ADD hasSlot_Part VARCHAR(255),
ADD CONSTRAINT fkhasSlot_Part
FOREIGN KEY(hasSlot_Part) REFERENCES Part(_NAME);