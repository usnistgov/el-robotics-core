CREATE TABLE FunctionToFunctionGreater(
FunctionToFunctionGreaterID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (FunctionToFunctionGreaterID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE MarkingLayout(
MarkingLayoutID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (MarkingLayoutID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionToFunctionGreaterOrEqual(
FunctionToFunctionGreaterOrEqualID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (FunctionToFunctionGreaterOrEqualID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE ParallelGripperGrasp(
ParallelGripperGraspID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasParallelGripperGrasp_GraspSeparation DOUBLE NOT NULL,
hasParallelGripperGrasp_ApproachSeparation DOUBLE NOT NULL,
CHECK(hasParallelGripperGrasp_GraspSeparation >= 0),
CHECK(hasParallelGripperGrasp_ApproachSeparation >= 0),
PRIMARY KEY (ParallelGripperGraspID, _NAME)
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

CREATE TABLE LargeContainer(
LargeContainerID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasLargeContainer_SerialNumber varchar(100) NOT NULL,
PRIMARY KEY (LargeContainerID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE RelativeLocationIn(
RelativeLocationInID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (RelativeLocationInID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE EndEffectorChangingStation(
EndEffectorChangingStationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (EndEffectorChangingStationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Marking(
MarkingID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (MarkingID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE VacuumEffectorSingleGrasp(
VacuumEffectorSingleGraspID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (VacuumEffectorSingleGraspID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PoseLocationIn(
PoseLocationInID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PoseLocationInID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE SkuObject(
SkuObjectID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (SkuObjectID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Slot(
SlotID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (SlotID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE IntermediateStateRelation(
IntermediateStateRelationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (IntermediateStateRelationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE GripperThreeFinger(
GripperThreeFingerID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (GripperThreeFingerID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE LargeBoxWithEmptyKitTrays(
LargeBoxWithEmptyKitTraysID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (LargeBoxWithEmptyKitTraysID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PartsTray(
PartsTrayID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PartsTrayID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionToFunctionLess(
FunctionToFunctionLessID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (FunctionToFunctionLessID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Decrease(
DecreaseID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (DecreaseID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Effect(
EffectID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (EffectID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PartRefAndPose(
PartRefAndPoseID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PartRefAndPoseID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE DataThing(
DataThingID INT NOT NULL AUTO_INCREMENT, 
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (DataThingID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE LargeBoxWithKits(
LargeBoxWithKitsID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasLargeBoxWithKits_Capacity INTEGER NOT NULL,
CHECK(hasLargeBoxWithKits_Capacity >= 0),
PRIMARY KEY (LargeBoxWithKitsID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE BoxyShape(
BoxyShapeID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasBoxyShape_HasTop boolean NOT NULL,
hasBoxyShape_Width DOUBLE NOT NULL,
hasBoxyShape_Height DOUBLE NOT NULL,
hasBoxyShape_Length DOUBLE NOT NULL,
CHECK(hasBoxyShape_Width >= 0),
CHECK(hasBoxyShape_Height >= 0),
CHECK(hasBoxyShape_Length >= 0),
PRIMARY KEY (BoxyShapeID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE RelativeLocation(
RelativeLocationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasRelativeLocation_Description varchar(255) NOT NULL,
PRIMARY KEY (RelativeLocationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionToNumberCondition(
FunctionToNumberConditionID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasFunctionToNumberCondition_Number INTEGER NOT NULL,
PRIMARY KEY (FunctionToNumberConditionID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Kit(
KitID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasKit_Finished boolean NOT NULL,
PRIMARY KEY (KitID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE SolidObject(
SolidObjectID INT NOT NULL AUTO_INCREMENT, 
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (SolidObjectID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PartsVessel(
PartsVesselID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPartsVessel_PartQuantity INTEGER NOT NULL,
hasPartsVessel_SerialNumber varchar(100) NOT NULL,
CHECK(hasPartsVessel_PartQuantity >= 0),
PRIMARY KEY (PartsVesselID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE ActionBase(
ActionBaseID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasActionBase_Description varchar(255),
PRIMARY KEY (ActionBaseID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Point(
PointID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPoint_Z DOUBLE NOT NULL,
hasPoint_X DOUBLE NOT NULL,
hasPoint_Y DOUBLE NOT NULL,
PRIMARY KEY (PointID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionParameter(
FunctionParameterID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasFunctionParameter_ParameterPosition INTEGER NOT NULL,
hasFunctionParameter_Parameter varchar(100) NOT NULL,
PRIMARY KEY (FunctionParameterID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE WorkTable(
WorkTableID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (WorkTableID, _NAME)
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

CREATE TABLE Vector(
VectorID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasVector_I DOUBLE NOT NULL,
hasVector_J DOUBLE NOT NULL,
hasVector_K DOUBLE NOT NULL,
PRIMARY KEY (VectorID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionToNumberLessOrEqual(
FunctionToNumberLessOrEqualID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (FunctionToNumberLessOrEqualID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE SOAP(
SOAPID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (SOAPID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PredicateParameter(
PredicateParameterID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPredicateParameter_ParameterPosition INTEGER NOT NULL,
hasPredicateParameter_Parameter varchar(100) NOT NULL,
PRIMARY KEY (PredicateParameterID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE GripperParallel(
GripperParallelID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (GripperParallelID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE KittingWorkstation(
KittingWorkstationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasKittingWorkstation_LengthUnit varchar(20) NOT NULL,
hasKittingWorkstation_ForceUnit varchar(255) NOT NULL,
hasKittingWorkstation_WeightUnit varchar(20) NOT NULL,
hasKittingWorkstation_AngleUnit varchar(20) NOT NULL,
PRIMARY KEY (KittingWorkstationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE GripperOther(
GripperOtherID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (GripperOtherID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionToFunctionCondition(
FunctionToFunctionConditionID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (FunctionToFunctionConditionID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PredicateStateRelationOr(
PredicateStateRelationOrID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PredicateStateRelationOrID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Robot(
RobotID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasRobot_MaximumLoadWeight DOUBLE NOT NULL,
hasRobot_Description varchar(255) NOT NULL,
CHECK(hasRobot_MaximumLoadWeight >= 0),
PRIMARY KEY (RobotID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE VacuumEffectorSingleCup(
VacuumEffectorSingleCupID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (VacuumEffectorSingleCupID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Increase(
IncreaseID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (IncreaseID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE ActionParameterSet(
ActionParameterSetID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasActionParameterSet_ActionParameter varchar(100) NOT NULL,
hasActionParameterSet_ActionParameterPosition INTEGER NOT NULL,
CHECK(hasActionParameterSet_ActionParameterPosition >= 0),
PRIMARY KEY (ActionParameterSetID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE MarkingModel(
MarkingModelID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasMarkingModel_MarkingFileName varchar(255) NOT NULL,
hasMarkingModel_MarkingFormatName varchar(255) NOT NULL,
hasMarkingModel_MarkingName varchar(255),
PRIMARY KEY (MarkingModelID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE RelativeLocationOn(
RelativeLocationOnID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (RelativeLocationOnID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Human(
HumanID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (HumanID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionToNumberGreaterOrEqual(
FunctionToNumberGreaterOrEqualID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (FunctionToNumberGreaterOrEqualID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE CylindricalShape(
CylindricalShapeID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasCylindricalShape_HasTop boolean NOT NULL,
hasCylindricalShape_Height DOUBLE NOT NULL,
hasCylindricalShape_Diameter DOUBLE NOT NULL,
CHECK(hasCylindricalShape_Height >= 0),
CHECK(hasCylindricalShape_Diameter >= 0),
PRIMARY KEY (CylindricalShapeID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionToNumberEqual(
FunctionToNumberEqualID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (FunctionToNumberEqualID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE ThreeFingerGrasp(
ThreeFingerGraspID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasThreeFingerGrasp_MinForce DOUBLE,
hasThreeFingerGrasp_MaxForce DOUBLE,
CHECK(hasThreeFingerGrasp_MinForce >= 0),
CHECK(hasThreeFingerGrasp_MaxForce >= 0),
PRIMARY KEY (ThreeFingerGraspID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PredicateStateRelation(
PredicateStateRelationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPredicateStateRelation_ReferenceParameter varchar(100) NOT NULL,
hasPredicateStateRelation_TargetParameter varchar(100),
PRIMARY KEY (PredicateStateRelationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionToNumberGreater(
FunctionToNumberGreaterID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (FunctionToNumberGreaterID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE ExternalShape(
ExternalShapeID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasExternalShape_ModelName varchar(255),
hasExternalShape_ModelFileName varchar(255) NOT NULL,
hasExternalShape_ModelIllustrationName varchar(255),
hasExternalShape_ModelFormatName varchar(255) NOT NULL,
PRIMARY KEY (ExternalShapeID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Precondition(
PreconditionID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PreconditionID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PartsBin(
PartsBinID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PartsBinID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE GripperEffector(
GripperEffectorID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasGripperEffector_MaxGripWidth DOUBLE,
CHECK(hasGripperEffector_MaxGripWidth >= 0),
PRIMARY KEY (GripperEffectorID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE InternalShape(
InternalShapeID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (InternalShapeID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE GripperTwoJaws(
GripperTwoJawsID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (GripperTwoJawsID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE EndEffectorGrasp(
EndEffectorGraspID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (EndEffectorGraspID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PoseLocationOn(
PoseLocationOnID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PoseLocationOnID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE EndEffector(
EndEffectorID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasEndEffector_Description varchar(255) NOT NULL,
hasEndEffector_MaximumLoadWeight DOUBLE NOT NULL,
CHECK(hasEndEffector_MaximumLoadWeight >= 0),
PRIMARY KEY (EndEffectorID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE VacuumEffector(
VacuumEffectorID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasVacuumEffector_Length DOUBLE NOT NULL,
hasVacuumEffector_CupDiameter DOUBLE NOT NULL,
CHECK(hasVacuumEffector_Length >= 0),
CHECK(hasVacuumEffector_CupDiameter >= 0),
PRIMARY KEY (VacuumEffectorID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE EndEffectorHolder(
EndEffectorHolderID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (EndEffectorHolderID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Function(
FunctionID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasFunction_Description varchar(255),
PRIMARY KEY (FunctionID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE NoSkuObject(
NoSkuObjectID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasNoSkuObject_Weight DOUBLE,
CHECK(hasNoSkuObject_Weight >= 0),
PRIMARY KEY (NoSkuObjectID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionToFunctionEqual(
FunctionToFunctionEqualID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (FunctionToFunctionEqualID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE TwoJawsGrasp(
TwoJawsGraspID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasTwoJawsGrasp_MaxForce DOUBLE,
hasTwoJawsGrasp_MinForce DOUBLE,
CHECK(hasTwoJawsGrasp_MaxForce >= 0),
CHECK(hasTwoJawsGrasp_MinForce >= 0),
PRIMARY KEY (TwoJawsGraspID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionCondition(
FunctionConditionID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (FunctionConditionID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionOperation(
FunctionOperationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasFunctionOperation_Value INTEGER NOT NULL,
PRIMARY KEY (FunctionOperationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE StockKeepingUnit(
StockKeepingUnitID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasStockKeepingUnit_Description varchar(255) NOT NULL,
hasStockKeepingUnit_Weight DOUBLE NOT NULL,
CHECK(hasStockKeepingUnit_Weight >= 0),
PRIMARY KEY (StockKeepingUnitID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PoseOnlyLocation(
PoseOnlyLocationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (PoseOnlyLocationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE BoxVolume(
BoxVolumeID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (BoxVolumeID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE ShapeDesign(
ShapeDesignID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasShapeDesign_Description varchar(255) NOT NULL,
PRIMARY KEY (ShapeDesignID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE RCC8StateRelation(
RCC8StateRelationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasRCC8StateRelation_RCC8Set varchar(255) NOT NULL,
PRIMARY KEY (RCC8StateRelationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionToFunctionLessOrEqual(
FunctionToFunctionLessOrEqualID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (FunctionToFunctionLessOrEqualID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PositivePredicate(
PositivePredicateID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPositivePredicate_Description varchar(255),
PRIMARY KEY (PositivePredicateID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE WorkTableArea(
WorkTableAreaID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasWorkTableArea_Ymax DOUBLE NOT NULL,
hasWorkTableArea_Ymin DOUBLE NOT NULL,
hasWorkTableArea_Xmin DOUBLE NOT NULL,
hasWorkTableArea_Xmax DOUBLE NOT NULL,
PRIMARY KEY (WorkTableAreaID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Part(
PartID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPart_SerialNumber varchar(100) NOT NULL,
PRIMARY KEY (PartID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE PhysicalLocation(
PhysicalLocationID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasPhysicalLocation_Timestamp varchar(255),
PRIMARY KEY (PhysicalLocationID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE LargeBoxWithKitsSlot(
LargeBoxWithKitsSlotID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasLargeBoxWithKitsSlot_Rank INTEGER NOT NULL,
PRIMARY KEY (LargeBoxWithKitsSlotID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE OtherGripperGrasp(
OtherGripperGraspID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasOtherGripperGrasp_MaxForce DOUBLE,
hasOtherGripperGrasp_MinForce DOUBLE,
CHECK(hasOtherGripperGrasp_MaxForce >= 0),
CHECK(hasOtherGripperGrasp_MinForce >= 0),
PRIMARY KEY (OtherGripperGraspID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE MechanicalComponent(
MechanicalComponentID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (MechanicalComponentID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE NegativePredicate(
NegativePredicateID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (NegativePredicateID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE KitTray(
KitTrayID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
hasKitTray_SerialNumber varchar(100) NOT NULL,
PRIMARY KEY (KitTrayID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE KitDesign(
KitDesignID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (KitDesignID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE Domain(
DomainID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (DomainID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE FunctionToNumberLess(
FunctionToNumberLessID INT NOT NULL,
_NAME varchar(255), INDEX (_NAME),
PRIMARY KEY (FunctionToNumberLessID, _NAME)
)ENGINE=InnoDB;

CREATE TABLE hasDomain_VariableValue(
DomainID INT NOT NULL,
hasDomain_Variable varchar(100) NOT NULL, 
PRIMARY KEY (DomainID,hasDomain_Variable)
);

CREATE TABLE hasDomain_RequirementValue(
DomainID INT NOT NULL,
hasDomain_Requirement varchar(100) NOT NULL, 
PRIMARY KEY (DomainID,hasDomain_Requirement)
);



ALTER TABLE FunctionToFunctionGreater
ADD hadByFunctionToFunctionGreater_Precondition VARCHAR(255),
ADD CONSTRAINT fkhadByFunctionToFunctionGreater_Precondition
FOREIGN KEY(hadByFunctionToFunctionGreater_Precondition) REFERENCES Precondition(_NAME);

ALTER TABLE MarkingLayout
ADD hasMarkingLayout_Point VARCHAR(255),
ADD CONSTRAINT fkhasMarkingLayout_Point
FOREIGN KEY(hasMarkingLayout_Point) REFERENCES Point(_NAME);

ALTER TABLE MarkingLayout
ADD hasMarkingLayout_YAxis VARCHAR(255),
ADD CONSTRAINT fkhasMarkingLayout_YAxis
FOREIGN KEY(hasMarkingLayout_YAxis) REFERENCES Vector(_NAME);

ALTER TABLE MarkingLayout
ADD hasMarkingLayout_XAxis VARCHAR(255),
ADD CONSTRAINT fkhasMarkingLayout_XAxis
FOREIGN KEY(hasMarkingLayout_XAxis) REFERENCES Vector(_NAME);

ALTER TABLE Marking
ADD hasMarking_MarkingLayout VARCHAR(255),
ADD CONSTRAINT fkhasMarking_MarkingLayout
FOREIGN KEY(hasMarking_MarkingLayout) REFERENCES MarkingLayout(_NAME);

ALTER TABLE FunctionToFunctionGreaterOrEqual
ADD hadByFunctionToFunctionGreaterOrEqual_Precondition VARCHAR(255),
ADD CONSTRAINT fkhadByFunctionToFunctionGreaterOrEqual_Precondition
FOREIGN KEY(hadByFunctionToFunctionGreaterOrEqual_Precondition) REFERENCES Precondition(_NAME);

ALTER TABLE ParallelGripperGrasp
ADD hasParallelGripperGrasp_GraspPose VARCHAR(255),
ADD CONSTRAINT fkhasParallelGripperGrasp_GraspPose
FOREIGN KEY(hasParallelGripperGrasp_GraspPose) REFERENCES PoseLocation(_NAME);

ALTER TABLE ParallelGripperGrasp
ADD hasParallelGripperGrasp_ParallelGripper VARCHAR(255),
ADD CONSTRAINT fkhasParallelGripperGrasp_ParallelGripper
FOREIGN KEY(hasParallelGripperGrasp_ParallelGripper) REFERENCES GripperParallel(_NAME);

ALTER TABLE ThreeFingerGrasp
ADD hasThreeFingerGrasp_GraspPose3 VARCHAR(255),
ADD CONSTRAINT fkhasThreeFingerGrasp_GraspPose3
FOREIGN KEY(hasThreeFingerGrasp_GraspPose3) REFERENCES PoseLocation(_NAME);

ALTER TABLE PoseLocation
ADD hasPoseLocation_XAxis VARCHAR(255),
ADD CONSTRAINT fkhasPoseLocation_XAxis
FOREIGN KEY(hasPoseLocation_XAxis) REFERENCES Vector(_NAME);

ALTER TABLE TwoJawsGrasp
ADD hasTwoJawsGrasp_GraspPose1 VARCHAR(255),
ADD CONSTRAINT fkhasTwoJawsGrasp_GraspPose1
FOREIGN KEY(hasTwoJawsGrasp_GraspPose1) REFERENCES PoseLocation(_NAME);

ALTER TABLE TwoJawsGrasp
ADD hasTwoJawsGrasp_GraspPose2 VARCHAR(255),
ADD CONSTRAINT fkhasTwoJawsGrasp_GraspPose2
FOREIGN KEY(hasTwoJawsGrasp_GraspPose2) REFERENCES PoseLocation(_NAME);

ALTER TABLE ThreeFingerGrasp
ADD hasThreeFingerGrasp_GraspPose2 VARCHAR(255),
ADD CONSTRAINT fkhasThreeFingerGrasp_GraspPose2
FOREIGN KEY(hasThreeFingerGrasp_GraspPose2) REFERENCES PoseLocation(_NAME);

ALTER TABLE PoseLocation
ADD hasPoseLocation_ZAxis VARCHAR(255),
ADD CONSTRAINT fkhasPoseLocation_ZAxis
FOREIGN KEY(hasPoseLocation_ZAxis) REFERENCES Vector(_NAME);

ALTER TABLE ThreeFingerGrasp
ADD hasThreeFingerGrasp_GraspPose1 VARCHAR(255),
ADD CONSTRAINT fkhasThreeFingerGrasp_GraspPose1
FOREIGN KEY(hasThreeFingerGrasp_GraspPose1) REFERENCES PoseLocation(_NAME);

ALTER TABLE PoseLocation
ADD hadByGraspPose_OtherGripperGrasp VARCHAR(255),
ADD CONSTRAINT fkhadByGraspPose_OtherGripperGrasp
FOREIGN KEY(hadByGraspPose_OtherGripperGrasp) REFERENCES OtherGripperGrasp(_NAME);

ALTER TABLE VacuumEffectorSingleGrasp
ADD hasVacuumEffectorSingleGrasp_GraspPose VARCHAR(255),
ADD CONSTRAINT fkhasVacuumEffectorSingleGrasp_GraspPose
FOREIGN KEY(hasVacuumEffectorSingleGrasp_GraspPose) REFERENCES PoseLocation(_NAME);

ALTER TABLE PoseLocation
ADD hasPoseLocation_Point VARCHAR(255),
ADD CONSTRAINT fkhasPoseLocation_Point
FOREIGN KEY(hasPoseLocation_Point) REFERENCES Point(_NAME);

ALTER TABLE LargeBoxWithEmptyKitTrays
ADD hasLargeBoxWithEmptyKitTrays_LargeContainer VARCHAR(255),
ADD CONSTRAINT fkhasLargeBoxWithEmptyKitTrays_LargeContainer
FOREIGN KEY(hasLargeBoxWithEmptyKitTrays_LargeContainer) REFERENCES LargeContainer(_NAME);

ALTER TABLE LargeBoxWithKits
ADD hasLargeBoxWithKits_LargeContainer VARCHAR(255),
ADD CONSTRAINT fkhasLargeBoxWithKits_LargeContainer
FOREIGN KEY(hasLargeBoxWithKits_LargeContainer) REFERENCES LargeContainer(_NAME);

ALTER TABLE KittingWorkstation
ADD hasKittingWorkstation_ChangingStation VARCHAR(255),
ADD CONSTRAINT fkhasKittingWorkstation_ChangingStation
FOREIGN KEY(hasKittingWorkstation_ChangingStation) REFERENCES EndEffectorChangingStation(_NAME);

ALTER TABLE EndEffectorHolder
ADD hadByEndEffectorHolder_EndEffectorChangingStation VARCHAR(255),
ADD CONSTRAINT fkhadByEndEffectorHolder_EndEffectorChangingStation
FOREIGN KEY(hadByEndEffectorHolder_EndEffectorChangingStation) REFERENCES EndEffectorChangingStation(_NAME);

ALTER TABLE EndEffectorChangingStation
ADD hasEndEffectorChangingStation_Base VARCHAR(255),
ADD CONSTRAINT fkhasEndEffectorChangingStation_Base
FOREIGN KEY(hasEndEffectorChangingStation_Base) REFERENCES MechanicalComponent(_NAME);

ALTER TABLE Marking
ADD hadByMarking_ShapeDesign VARCHAR(255),
ADD CONSTRAINT fkhadByMarking_ShapeDesign
FOREIGN KEY(hadByMarking_ShapeDesign) REFERENCES ShapeDesign(_NAME);

ALTER TABLE Marking
ADD hasMarking_MarkingModel VARCHAR(255),
ADD CONSTRAINT fkhasMarking_MarkingModel
FOREIGN KEY(hasMarking_MarkingModel) REFERENCES MarkingModel(_NAME);

ALTER TABLE VacuumEffectorSingleGrasp
ADD hasVacuumEffectorSingleGrasp_VacuumEffectorSingle VARCHAR(255),
ADD CONSTRAINT fkhasVacuumEffectorSingleGrasp_VacuumEffectorSingle
FOREIGN KEY(hasVacuumEffectorSingleGrasp_VacuumEffectorSingle) REFERENCES VacuumEffectorSingleCup(_NAME);

ALTER TABLE SkuObject
ADD hasSkuObject_Sku VARCHAR(255),
ADD CONSTRAINT fkhasSkuObject_Sku
FOREIGN KEY(hasSkuObject_Sku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE Slot
ADD hadBySlot_Kit VARCHAR(255),
ADD CONSTRAINT fkhadBySlot_Kit
FOREIGN KEY(hadBySlot_Kit) REFERENCES Kit(_NAME);

ALTER TABLE Slot
ADD hasSlot_Part VARCHAR(255),
ADD CONSTRAINT fkhasSlot_Part
FOREIGN KEY(hasSlot_Part) REFERENCES Part(_NAME);

ALTER TABLE Slot
ADD hasSlot_PartRefAndPose VARCHAR(255),
ADD CONSTRAINT fkhasSlot_PartRefAndPose
FOREIGN KEY(hasSlot_PartRefAndPose) REFERENCES PartRefAndPose(_NAME);

ALTER TABLE PredicateStateRelation
ADD hasPredicateStateRelation_IntermediateStateRelation VARCHAR(255),
ADD CONSTRAINT fkhasPredicateStateRelation_IntermediateStateRelation
FOREIGN KEY(hasPredicateStateRelation_IntermediateStateRelation) REFERENCES IntermediateStateRelation(_NAME);

ALTER TABLE IntermediateStateRelation
ADD hasIntermediateStateRelation_RCC8StateRelation VARCHAR(255),
ADD CONSTRAINT fkhasIntermediateStateRelation_RCC8StateRelation
FOREIGN KEY(hasIntermediateStateRelation_RCC8StateRelation) REFERENCES RCC8StateRelation(_NAME);

ALTER TABLE IntermediateStateRelation
ADD hadByIntermediateStateRelation_SOAP VARCHAR(255),
ADD CONSTRAINT fkhadByIntermediateStateRelation_SOAP
FOREIGN KEY(hadByIntermediateStateRelation_SOAP) REFERENCES SOAP(_NAME);

ALTER TABLE ThreeFingerGrasp
ADD hasThreeFingerGrasp_ThreeFingerGripper VARCHAR(255),
ADD CONSTRAINT fkhasThreeFingerGrasp_ThreeFingerGripper
FOREIGN KEY(hasThreeFingerGrasp_ThreeFingerGripper) REFERENCES GripperThreeFinger(_NAME);

ALTER TABLE KitTray
ADD hadByKitTray_LargeBoxWithEmptyKitTrays VARCHAR(255),
ADD CONSTRAINT fkhadByKitTray_LargeBoxWithEmptyKitTrays
FOREIGN KEY(hadByKitTray_LargeBoxWithEmptyKitTrays) REFERENCES LargeBoxWithEmptyKitTrays(_NAME);

ALTER TABLE FunctionToFunctionLess
ADD hadByFunctionToFunctionLess_Precondition VARCHAR(255),
ADD CONSTRAINT fkhadByFunctionToFunctionLess_Precondition
FOREIGN KEY(hadByFunctionToFunctionLess_Precondition) REFERENCES Precondition(_NAME);

ALTER TABLE Decrease
ADD hadByDecrease_Effect VARCHAR(255),
ADD CONSTRAINT fkhadByDecrease_Effect
FOREIGN KEY(hadByDecrease_Effect) REFERENCES Effect(_NAME);

ALTER TABLE Increase
ADD hadByIncrease_Effect VARCHAR(255),
ADD CONSTRAINT fkhadByIncrease_Effect
FOREIGN KEY(hadByIncrease_Effect) REFERENCES Effect(_NAME);

CREATE TABLE hasEffect_PositivePredicate(
EffectID INT NOT NULL,
PositivePredicateID INT NOT NULL,
PRIMARY KEY (EffectID,PositivePredicateID)
);

ALTER TABLE NegativePredicate
ADD hadByNegativePredicate_Effect VARCHAR(255),
ADD CONSTRAINT fkhadByNegativePredicate_Effect
FOREIGN KEY(hadByNegativePredicate_Effect) REFERENCES Effect(_NAME);

ALTER TABLE ActionBase
ADD hasActionBase_Effect VARCHAR(255),
ADD CONSTRAINT fkhasActionBase_Effect
FOREIGN KEY(hasActionBase_Effect) REFERENCES Effect(_NAME);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_Point VARCHAR(255),
ADD CONSTRAINT fkhasPartRefAndPose_Point
FOREIGN KEY(hasPartRefAndPose_Point) REFERENCES Point(_NAME);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_XAxis VARCHAR(255),
ADD CONSTRAINT fkhasPartRefAndPose_XAxis
FOREIGN KEY(hasPartRefAndPose_XAxis) REFERENCES Vector(_NAME);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_ZAxis VARCHAR(255),
ADD CONSTRAINT fkhasPartRefAndPose_ZAxis
FOREIGN KEY(hasPartRefAndPose_ZAxis) REFERENCES Vector(_NAME);

ALTER TABLE PartRefAndPose
ADD hasPartRefAndPose_Sku VARCHAR(255),
ADD CONSTRAINT fkhasPartRefAndPose_Sku
FOREIGN KEY(hasPartRefAndPose_Sku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE PartRefAndPose
ADD hadByPartRefAndPose_KitDesign VARCHAR(255),
ADD CONSTRAINT fkhadByPartRefAndPose_KitDesign
FOREIGN KEY(hadByPartRefAndPose_KitDesign) REFERENCES KitDesign(_NAME);

ALTER TABLE PhysicalLocation
ADD hasPhysicalLocation_RefData VARCHAR(255),
ADD CONSTRAINT fkhasPhysicalLocation_RefData
FOREIGN KEY(hasPhysicalLocation_RefData) REFERENCES DataThing(_NAME);

ALTER TABLE Kit
ADD hadByKit_LargeBoxWithKits VARCHAR(255),
ADD CONSTRAINT fkhadByKit_LargeBoxWithKits
FOREIGN KEY(hadByKit_LargeBoxWithKits) REFERENCES LargeBoxWithKits(_NAME);

ALTER TABLE LargeBoxWithKitsSlot
ADD hadByLargeBoxWithKitsSlot_LargeBoxWithKits VARCHAR(255),
ADD CONSTRAINT fkhadByLargeBoxWithKitsSlot_LargeBoxWithKits
FOREIGN KEY(hadByLargeBoxWithKitsSlot_LargeBoxWithKits) REFERENCES LargeBoxWithKits(_NAME);

ALTER TABLE LargeBoxWithKits
ADD hasLargeBoxWithKits_KitDesign VARCHAR(255),
ADD CONSTRAINT fkhasLargeBoxWithKits_KitDesign
FOREIGN KEY(hasLargeBoxWithKits_KitDesign) REFERENCES KitDesign(_NAME);

ALTER TABLE FunctionToNumberCondition
ADD hasFunctionToNumberCondition_Function VARCHAR(255),
ADD CONSTRAINT fkhasFunctionToNumberCondition_Function
FOREIGN KEY(hasFunctionToNumberCondition_Function) REFERENCES Function(_NAME);

ALTER TABLE Kit
ADD hasKit_Design VARCHAR(255),
ADD CONSTRAINT fkhasKit_Design
FOREIGN KEY(hasKit_Design) REFERENCES KitDesign(_NAME);

CREATE TABLE hadByKit_LargeBoxWithKitsSlot(
KitID INT NOT NULL,
LargeBoxWithKitsSlotID INT NOT NULL,
PRIMARY KEY (KitID,LargeBoxWithKitsSlotID)
);

ALTER TABLE Kit
ADD hasKit_KitTray VARCHAR(255),
ADD CONSTRAINT fkhasKit_KitTray
FOREIGN KEY(hasKit_KitTray) REFERENCES KitTray(_NAME);

ALTER TABLE Part
ADD hadByPart_Kit VARCHAR(255),
ADD CONSTRAINT fkhadByPart_Kit
FOREIGN KEY(hadByPart_Kit) REFERENCES Kit(_NAME);

ALTER TABLE SolidObject
ADD hasSolidObject_PrimaryLocation VARCHAR(255),
ADD CONSTRAINT fkhasSolidObject_PrimaryLocation
FOREIGN KEY(hasSolidObject_PrimaryLocation) REFERENCES PhysicalLocation(_NAME);

ALTER TABLE WorkTableArea
ADD hasWorkTableArea_SolidObject VARCHAR(255),
ADD CONSTRAINT fkhasWorkTableArea_SolidObject
FOREIGN KEY(hasWorkTableArea_SolidObject) REFERENCES SolidObject(_NAME);

ALTER TABLE SolidObject
ADD hadByObjectOnTable_WorkTable VARCHAR(255),
ADD CONSTRAINT fkhadByObjectOnTable_WorkTable
FOREIGN KEY(hadByObjectOnTable_WorkTable) REFERENCES WorkTable(_NAME);

ALTER TABLE PhysicalLocation
ADD hadBySecondaryLocation_SolidObject VARCHAR(255),
ADD CONSTRAINT fkhadBySecondaryLocation_SolidObject
FOREIGN KEY(hadBySecondaryLocation_SolidObject) REFERENCES SolidObject(_NAME);

ALTER TABLE PhysicalLocation
ADD hasPhysicalLocation_RefObject VARCHAR(255),
ADD CONSTRAINT fkhasPhysicalLocation_RefObject
FOREIGN KEY(hasPhysicalLocation_RefObject) REFERENCES SolidObject(_NAME);

ALTER TABLE EndEffector
ADD hasEndEffector_HeldObject VARCHAR(255),
ADD CONSTRAINT fkhasEndEffector_HeldObject
FOREIGN KEY(hasEndEffector_HeldObject) REFERENCES SolidObject(_NAME);

ALTER TABLE SolidObject
ADD hadByObject_KittingWorkstation VARCHAR(255),
ADD CONSTRAINT fkhadByObject_KittingWorkstation
FOREIGN KEY(hadByObject_KittingWorkstation) REFERENCES KittingWorkstation(_NAME);

ALTER TABLE PartsVessel
ADD hasPartsVessel_PartSku VARCHAR(255),
ADD CONSTRAINT fkhasPartsVessel_PartSku
FOREIGN KEY(hasPartsVessel_PartSku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE Part
ADD hadByPart_PartsVessel VARCHAR(255),
ADD CONSTRAINT fkhadByPart_PartsVessel
FOREIGN KEY(hadByPart_PartsVessel) REFERENCES PartsVessel(_NAME);

ALTER TABLE ActionBase
ADD hasActionBase_Precondition VARCHAR(255),
ADD CONSTRAINT fkhasActionBase_Precondition
FOREIGN KEY(hasActionBase_Precondition) REFERENCES Precondition(_NAME);

ALTER TABLE ActionParameterSet
ADD hadByActionParameterSet_ActionBase VARCHAR(255),
ADD CONSTRAINT fkhadByActionParameterSet_ActionBase
FOREIGN KEY(hadByActionParameterSet_ActionBase) REFERENCES ActionBase(_NAME);

ALTER TABLE ActionBase
ADD hadByAction_Domain VARCHAR(255),
ADD CONSTRAINT fkhadByAction_Domain
FOREIGN KEY(hadByAction_Domain) REFERENCES Domain(_NAME);

ALTER TABLE BoxVolume
ADD hasBoxVolume_MaximumPoint VARCHAR(255),
ADD CONSTRAINT fkhasBoxVolume_MaximumPoint
FOREIGN KEY(hasBoxVolume_MaximumPoint) REFERENCES Point(_NAME);

ALTER TABLE BoxVolume
ADD hasBoxVolume_MinimumPoint VARCHAR(255),
ADD CONSTRAINT fkhasBoxVolume_MinimumPoint
FOREIGN KEY(hasBoxVolume_MinimumPoint) REFERENCES Point(_NAME);

ALTER TABLE FunctionParameter
ADD hadByFunctionParameter_Function VARCHAR(255),
ADD CONSTRAINT fkhadByFunctionParameter_Function
FOREIGN KEY(hadByFunctionParameter_Function) REFERENCES Function(_NAME);

ALTER TABLE WorkTableArea
ADD hadByWorkTableArea_WorkTable VARCHAR(255),
ADD CONSTRAINT fkhadByWorkTableArea_WorkTable
FOREIGN KEY(hadByWorkTableArea_WorkTable) REFERENCES WorkTable(_NAME);

ALTER TABLE FunctionToNumberLessOrEqual
ADD hadByFunctionToNumberLessOrEqual_Precondition VARCHAR(255),
ADD CONSTRAINT fkhadByFunctionToNumberLessOrEqual_Precondition
FOREIGN KEY(hadByFunctionToNumberLessOrEqual_Precondition) REFERENCES Precondition(_NAME);

ALTER TABLE SOAP
ADD hasSOAP_Domain VARCHAR(255),
ADD CONSTRAINT fkhasSOAP_Domain
FOREIGN KEY(hasSOAP_Domain) REFERENCES Domain(_NAME);

ALTER TABLE SOAP
ADD hasSOAP_KittingWorkstation VARCHAR(255),
ADD CONSTRAINT fkhasSOAP_KittingWorkstation
FOREIGN KEY(hasSOAP_KittingWorkstation) REFERENCES KittingWorkstation(_NAME);

ALTER TABLE PredicateParameter
ADD hadByPredicateParameter_PositivePredicate VARCHAR(255),
ADD CONSTRAINT fkhadByPredicateParameter_PositivePredicate
FOREIGN KEY(hadByPredicateParameter_PositivePredicate) REFERENCES PositivePredicate(_NAME);

ALTER TABLE KittingWorkstation
ADD hasKittingWorkstation_Robot VARCHAR(255),
ADD CONSTRAINT fkhasKittingWorkstation_Robot
FOREIGN KEY(hasKittingWorkstation_Robot) REFERENCES Robot(_NAME);

ALTER TABLE BoxVolume
ADD hadByOtherObstacle_KittingWorkstation VARCHAR(255),
ADD CONSTRAINT fkhadByOtherObstacle_KittingWorkstation
FOREIGN KEY(hadByOtherObstacle_KittingWorkstation) REFERENCES KittingWorkstation(_NAME);

ALTER TABLE StockKeepingUnit
ADD hadBySku_KittingWorkstation VARCHAR(255),
ADD CONSTRAINT fkhadBySku_KittingWorkstation
FOREIGN KEY(hadBySku_KittingWorkstation) REFERENCES KittingWorkstation(_NAME);

ALTER TABLE KitDesign
ADD hadByKitDesign_KittingWorkstation VARCHAR(255),
ADD CONSTRAINT fkhadByKitDesign_KittingWorkstation
FOREIGN KEY(hadByKitDesign_KittingWorkstation) REFERENCES KittingWorkstation(_NAME);

ALTER TABLE OtherGripperGrasp
ADD hasOtherGripperGrasp_OtherGripper VARCHAR(255),
ADD CONSTRAINT fkhasOtherGripperGrasp_OtherGripper
FOREIGN KEY(hasOtherGripperGrasp_OtherGripper) REFERENCES GripperOther(_NAME);

ALTER TABLE FunctionToFunctionCondition
ADD hasFunctionToFunctionCondition_F2 VARCHAR(255),
ADD CONSTRAINT fkhasFunctionToFunctionCondition_F2
FOREIGN KEY(hasFunctionToFunctionCondition_F2) REFERENCES Function(_NAME);

ALTER TABLE FunctionToFunctionCondition
ADD hasFunctionToFunctionCondition_F1 VARCHAR(255),
ADD CONSTRAINT fkhasFunctionToFunctionCondition_F1
FOREIGN KEY(hasFunctionToFunctionCondition_F1) REFERENCES Function(_NAME);

ALTER TABLE PositivePredicate
ADD hasPositivePredicate_PredicateStateRelationOR VARCHAR(255),
ADD CONSTRAINT fkhasPositivePredicate_PredicateStateRelationOR
FOREIGN KEY(hasPositivePredicate_PredicateStateRelationOR) REFERENCES PredicateStateRelationOr(_NAME);

ALTER TABLE PredicateStateRelation
ADD hadByPredicateStateRelation_PredicateStateRelationOr VARCHAR(255),
ADD CONSTRAINT fkhadByPredicateStateRelation_PredicateStateRelationOr
FOREIGN KEY(hadByPredicateStateRelation_PredicateStateRelationOr) REFERENCES PredicateStateRelationOr(_NAME);

ALTER TABLE EndEffector
ADD hadByEndEffector_Robot VARCHAR(255),
ADD CONSTRAINT fkhadByEndEffector_Robot
FOREIGN KEY(hadByEndEffector_Robot) REFERENCES Robot(_NAME);

ALTER TABLE BoxVolume
ADD hadByWorkVolume_Robot VARCHAR(255),
ADD CONSTRAINT fkhadByWorkVolume_Robot
FOREIGN KEY(hadByWorkVolume_Robot) REFERENCES Robot(_NAME);

ALTER TABLE FunctionToNumberGreaterOrEqual
ADD hadByFunctionToNumberGreaterOrEqual_Precondition VARCHAR(255),
ADD CONSTRAINT fkhadByFunctionToNumberGreaterOrEqual_Precondition
FOREIGN KEY(hadByFunctionToNumberGreaterOrEqual_Precondition) REFERENCES Precondition(_NAME);

ALTER TABLE FunctionToNumberEqual
ADD hadByFunctionToNumberEqual_Precondition VARCHAR(255),
ADD CONSTRAINT fkhadByFunctionToNumberEqual_Precondition
FOREIGN KEY(hadByFunctionToNumberEqual_Precondition) REFERENCES Precondition(_NAME);

ALTER TABLE PredicateStateRelation
ADD hadByPredicateStateRelation_PositivePredicate VARCHAR(255),
ADD CONSTRAINT fkhadByPredicateStateRelation_PositivePredicate
FOREIGN KEY(hadByPredicateStateRelation_PositivePredicate) REFERENCES PositivePredicate(_NAME);

ALTER TABLE FunctionToNumberGreater
ADD hadByFunctionToNumberGreater_Precondition VARCHAR(255),
ADD CONSTRAINT fkhadByFunctionToNumberGreater_Precondition
FOREIGN KEY(hadByFunctionToNumberGreater_Precondition) REFERENCES Precondition(_NAME);

ALTER TABLE NoSkuObject
ADD hasNoSkuObject_ExternalShape VARCHAR(255),
ADD CONSTRAINT fkhasNoSkuObject_ExternalShape
FOREIGN KEY(hasNoSkuObject_ExternalShape) REFERENCES ExternalShape(_NAME);

ALTER TABLE StockKeepingUnit
ADD hasStockKeepingUnit_ExternalShape VARCHAR(255),
ADD CONSTRAINT fkhasStockKeepingUnit_ExternalShape
FOREIGN KEY(hasStockKeepingUnit_ExternalShape) REFERENCES ExternalShape(_NAME);

ALTER TABLE FunctionToFunctionEqual
ADD hadByFunctionToFunctionEqual_Precondition VARCHAR(255),
ADD CONSTRAINT fkhadByFunctionToFunctionEqual_Precondition
FOREIGN KEY(hadByFunctionToFunctionEqual_Precondition) REFERENCES Precondition(_NAME);

ALTER TABLE FunctionToFunctionLessOrEqual
ADD hadByFunctionToFunctionLessOrEqual_Precondition VARCHAR(255),
ADD CONSTRAINT fkhadByFunctionToFunctionLessOrEqual_Precondition
FOREIGN KEY(hadByFunctionToFunctionLessOrEqual_Precondition) REFERENCES Precondition(_NAME);

CREATE TABLE hasPrecondition_PositivePredicate(
PreconditionID INT NOT NULL,
PositivePredicateID INT NOT NULL,
PRIMARY KEY (PreconditionID,PositivePredicateID)
);

ALTER TABLE FunctionToNumberLess
ADD hadByFunctionToNumberLess_Precondition VARCHAR(255),
ADD CONSTRAINT fkhadByFunctionToNumberLess_Precondition
FOREIGN KEY(hadByFunctionToNumberLess_Precondition) REFERENCES Precondition(_NAME);

ALTER TABLE StockKeepingUnit
ADD hasStockKeepingUnit_InternalShape VARCHAR(255),
ADD CONSTRAINT fkhasStockKeepingUnit_InternalShape
FOREIGN KEY(hasStockKeepingUnit_InternalShape) REFERENCES InternalShape(_NAME);

ALTER TABLE NoSkuObject
ADD hasNoSkuObject_InternalShape VARCHAR(255),
ADD CONSTRAINT fkhasNoSkuObject_InternalShape
FOREIGN KEY(hasNoSkuObject_InternalShape) REFERENCES InternalShape(_NAME);

ALTER TABLE TwoJawsGrasp
ADD hasTwoJawsGrasp_TwoJawsGripper VARCHAR(255),
ADD CONSTRAINT fkhasTwoJawsGrasp_TwoJawsGripper
FOREIGN KEY(hasTwoJawsGrasp_TwoJawsGripper) REFERENCES GripperTwoJaws(_NAME);

ALTER TABLE EndEffectorGrasp
ADD hadByEffectorAndGrasp_StockKeepingUnit VARCHAR(255),
ADD CONSTRAINT fkhadByEffectorAndGrasp_StockKeepingUnit
FOREIGN KEY(hadByEffectorAndGrasp_StockKeepingUnit) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE EndEffectorGrasp
ADD hadByEffectorAndGrasp_NoSkuObject VARCHAR(255),
ADD CONSTRAINT fkhadByEffectorAndGrasp_NoSkuObject
FOREIGN KEY(hadByEffectorAndGrasp_NoSkuObject) REFERENCES NoSkuObject(_NAME);

ALTER TABLE EndEffectorHolder
ADD hasEndEffectorHolder_EndEffector VARCHAR(255),
ADD CONSTRAINT fkhasEndEffectorHolder_EndEffector
FOREIGN KEY(hasEndEffectorHolder_EndEffector) REFERENCES EndEffector(_NAME);

CREATE TABLE hadByCanHoldEndEffector_EndEffectorHolder(
EndEffectorID INT NOT NULL,
EndEffectorHolderID INT NOT NULL,
PRIMARY KEY (EndEffectorID,EndEffectorHolderID)
);

ALTER TABLE Function
ADD hadByFunction_Domain VARCHAR(255),
ADD CONSTRAINT fkhadByFunction_Domain
FOREIGN KEY(hadByFunction_Domain) REFERENCES Domain(_NAME);

ALTER TABLE FunctionOperation
ADD hasFunctionOperation_Function VARCHAR(255),
ADD CONSTRAINT fkhasFunctionOperation_Function
FOREIGN KEY(hasFunctionOperation_Function) REFERENCES Function(_NAME);

ALTER TABLE WorkTableArea
ADD hasWorkTableArea_Sku VARCHAR(255),
ADD CONSTRAINT fkhasWorkTableArea_Sku
FOREIGN KEY(hasWorkTableArea_Sku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE KitDesign
ADD hasKitDesign_KitTraySku VARCHAR(255),
ADD CONSTRAINT fkhasKitDesign_KitTraySku
FOREIGN KEY(hasKitDesign_KitTraySku) REFERENCES StockKeepingUnit(_NAME);

ALTER TABLE PositivePredicate
ADD hadByPositivePredicate_Domain VARCHAR(255),
ADD CONSTRAINT fkhadByPositivePredicate_Domain
FOREIGN KEY(hadByPositivePredicate_Domain) REFERENCES Domain(_NAME);

ALTER TABLE NegativePredicate
ADD hasNegativePredicate_PositivePredicate VARCHAR(255),
ADD CONSTRAINT fkhasNegativePredicate_PositivePredicate
FOREIGN KEY(hasNegativePredicate_PositivePredicate) REFERENCES PositivePredicate(_NAME);