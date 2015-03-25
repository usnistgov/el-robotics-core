INSERT INTO DataThing
(_NAME)
VALUES('kit-has-slot');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(1, 'kit-has-slot', 'Kit has Slot', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_finger_1_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(2, 'big_gear_finger_1_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_finger_2_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(3, 'big_gear_finger_2_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-physicalLocation-refObject-kit');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(4, 'kitTray-has-physicalLocation-refObject-kit', 'KitTray is associated to Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('RCC8-Under');

INSERT INTO RCC8StateRelation
(RCC8StateRelationID, _NAME, hasRCC8StateRelation_RCC8Set)
VALUES(5, 'RCC8-Under', 'Smaller-Z and (X-EC or X-NTPP or X-TPP or X-PO or X-NTPPi or X-TPPi) and (Y-EC or Y-NTPP or Y-TPP or Y-PO or Y-NTPPi or Y-TPPi)');

INSERT INTO DataThing
(_NAME)
VALUES('part-is-found-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(6, 'part-is-found-param1', 1, 'Part', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffector');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(7, 'look-for-endEffector', 'Look for EndEffector in an EndEffectorHolder', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('slot-can-contain-part-sku');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(8, 'slot-can-contain-part-sku', 'A Slot can contain a type of part given its SKU', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-Increase-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(9, 'place-kit-Increase-1', 1, NULL);

INSERT INTO Increase
(IncreaseID, _NAME, hadByIncrease_Effect)
VALUES(9, 'place-kit-Increase-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-kitTray-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(10, 'kit-has-kitTray-param1', 1, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-kitTray-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(11, 'kit-has-kitTray-param2', 2, 'KitTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_slot_bottom_cover');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(12, 'kit_gearbox_1Top1Bottom1Medium_slot_bottom_cover', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(13, 'kit_gearbox_1Small1Medium_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(13, 'kit_gearbox_1Small1Medium_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationOn
(PoseLocationOnID, _NAME)
VALUES(13, 'kit_gearbox_1Small1Medium_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('WorkTable-KitTray-SR-UnderWithContact');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(14, 'WorkTable-KitTray-SR-UnderWithContact', 'WorkTable', 'KitTray', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-lbwk-FunctionToFunctionLess');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(15, 'look-for-slot-in-lbwk-FunctionToFunctionLess');

INSERT INTO FunctionToFunctionCondition
(FunctionToFunctionConditionID, _NAME, hasFunctionToFunctionCondition_F2, hasFunctionToFunctionCondition_F1)
VALUES(15, 'look-for-slot-in-lbwk-FunctionToFunctionLess', NULL, NULL);

INSERT INTO FunctionToFunctionLess
(FunctionToFunctionLessID, _NAME, hadByFunctionToFunctionLess_Precondition)
VALUES(15, 'look-for-slot-in-lbwk-FunctionToFunctionLess', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_min');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(16, 'point_min', 0.000000, -0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-lbwk-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(17, 'look-for-slot-in-lbwk-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-lbwk-param-4');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(18, 'look-for-slot-in-lbwk-param-4', 'Kit', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-lbwk-param-5');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(19, 'look-for-slot-in-lbwk-param-5', 'EndEffector', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('LargeBoxWithKits-Kit-SR-PartiallyIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(20, 'LargeBoxWithKits-Kit-SR-PartiallyIn', 'Kit', 'LargeBoxWithKits', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-lbwk-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(21, 'look-for-slot-in-lbwk-param-2', 'LargeBoxWithKitsSlot', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-lbwk-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(22, 'look-for-slot-in-lbwk-param-3', 'LargeBoxWithKits', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray-Decrease-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(23, 'place-kitTray-Decrease-1', 1, NULL);

INSERT INTO Decrease
(DecreaseID, _NAME, hadByDecrease_Effect)
VALUES(23, 'place-kitTray-Decrease-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_big_gear_ply');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(24, 'shape_gearbox_big_gear_ply', 'ply file with shape of big gears for a gearbox');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFileName, hasExternalShape_ModelIllustrationName, hasExternalShape_ModelFormatName)
VALUES(24, 'shape_gearbox_big_gear_ply', '/usr/local/iora/ply/big_gear.ply', 'http://aprs-dev.el.nist.gov/jpg/gearbox_big_gear.jpg', 'PLY');

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray-Decrease-2');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(25, 'place-kitTray-Decrease-2', 1, NULL);

INSERT INTO Decrease
(DecreaseID, _NAME, hadByDecrease_Effect)
VALUES(25, 'place-kitTray-Decrease-2', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-EndEffectorHolder-SR-ContainedIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(26, 'EndEffector-EndEffectorHolder-SR-ContainedIn', 'EndEffector', 'EndEffectorHolder', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(27, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(27, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationOn
(PoseLocationOnID, _NAME)
VALUES(27, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part-endEffector-SR-ContainedIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(28, 'part-endEffector-SR-ContainedIn', 'Part', 'EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_finger_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(29, 'medium_gear_finger_1_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-part');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(30, 'look-for-part', 'Task a sensor system to look for a Part given its StockKeepingUnit', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_small_gear');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(31, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_small_gear', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('RCC8-PartiallyIn');

INSERT INTO RCC8StateRelation
(RCC8StateRelationID, _NAME, hasRCC8StateRelation_RCC8Set)
VALUES(32, 'RCC8-PartiallyIn', '(Z-Plus and (Z-NTPP or Z-NTPPi or Z-PO or Z-TPP or Z-TPPi)) and (X-NTPP or X-NTPPi or X-TPP or X-TPPi) and (Y-NTPP or Y-NTPPi or Y-TPP or Y-TPPi)');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_tray_relative_location_in');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefData, hadBySecondaryLocation_SolidObject)
VALUES(33, 'kit_gearbox_1Top1Bottom1Medium_tray_relative_location_in', NULL, NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(33, 'kit_gearbox_1Top1Bottom1Medium_tray_relative_location_in', 'Relative location of kit_gearbox_1Top1Bottom1Medium_tray in a WorkTableArea');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(33, 'kit_gearbox_1Top1Bottom1Medium_tray_relative_location_in');

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_medium_gear_tray_ply');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(34, 'shape_gearbox_medium_gear_tray_ply', 'ply file with shape of parts trays for medium gears for a gearbox');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFileName, hasExternalShape_ModelFormatName)
VALUES(34, 'shape_gearbox_medium_gear_tray_ply', '/usr/local/iora/ply/medium_gear_tray.ply', 'PLY');

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(35, 'small_gear_tray_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-lbwk');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(36, 'look-for-slot-in-lbwk', 'Look for LargeBoxWithKitsSlot in LargeBoxWithKits before placing a finished Kit in it', NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation, hadByObjectOnTable_WorkTable)
VALUES('big_gear_tray', NULL, NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(1, 'big_gear_tray', NULL);

INSERT INTO PartsVessel
(PartsVesselID, _NAME, hasPartsVessel_PartQuantity, hasPartsVessel_SerialNumber, hasPartsVessel_PartSku)
VALUES(1, 'big_gear_tray', 1, 17, NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME)
VALUES(1, 'big_gear_tray');

INSERT INTO DataThing
(_NAME)
VALUES('endEffectorHolder-has-endEffector');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(37, 'endEffectorHolder-has-endEffector', 'EndEffectorHolder is holding EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-heldObject-kitTray-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(38, 'endEffector-has-heldObject-kitTray-param2', 2, 'KitTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part-has-physicalLocation-refObject-kit-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(39, 'part-has-physicalLocation-refObject-kit-param1', 1, 'Part', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part-has-physicalLocation-refObject-kit-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(40, 'part-has-physicalLocation-refObject-kit-param2', 2, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('capacity-of-parts-in-kit');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(41, 'capacity-of-parts-in-kit', 'Number of Parts of a certain StockKeepingUnit that Kit can have', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('set-grasp-F2NLess');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(42, 'set-grasp-F2NLess');

INSERT INTO FunctionToNumberCondition
(FunctionToNumberConditionID, _NAME, hasFunctionToNumberCondition_Number, hasFunctionToNumberCondition_Function)
VALUES(42, 'set-grasp-F2NLess', 1, NULL);

INSERT INTO FunctionToNumberLess
(FunctionToNumberLessID, _NAME, hadByFunctionToNumberLess_Precondition)
VALUES(42, 'set-grasp-F2NLess', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_slot_top_cover');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(43, 'kit_gearbox_1Top1Bottom1Medium_slot_top_cover', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(44, 'place-part-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(45, 'big_gear_1_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_medium_gear_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(46, 'kit_gearbox_1Small1Medium_medium_gear_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-heldObject-kitTray-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(47, 'endEffector-has-heldObject-kitTray-param1', 1, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(48, 'work_table_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('ThreeFingerGrasp13');

INSERT INTO EndEffectorGrasp
(EndEffectorGraspID, _NAME, hadByEffectorAndGrasp_StockKeepingUnit)
VALUES(49, 'ThreeFingerGrasp13', NULL);

INSERT INTO ThreeFingerGrasp
(ThreeFingerGraspID, _NAME, hasThreeFingerGrasp_ThreeFingerGripper)
VALUES(49, 'ThreeFingerGrasp13', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(50, 'finished_kit_receiver_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_tray_1Top1Bottom1Medium_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(51, 'kit_gearbox_tray_1Top1Bottom1Medium_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('largeBoxWithKitsSlot-is-found-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(52, 'largeBoxWithKitsSlot-is-found-param1', 1, 'LargeBoxWithKitsSlot', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('Under');

INSERT INTO IntermediateStateRelation
(IntermediateStateRelationID, _NAME, hasIntermediateStateRelation_RCC8StateRelation, hadByIntermediateStateRelation_SOAP)
VALUES(53, 'Under', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('set-grasp-Increase-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(54, 'set-grasp-Increase-1', 1, NULL);

INSERT INTO Increase
(IncreaseID, _NAME, hadByIncrease_Effect)
VALUES(54, 'set-grasp-Increase-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-no-heldObject-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(55, 'endEffector-has-no-heldObject-param1', 1, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray-not-2');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(56, 'place-kitTray-not-2', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_finger_1_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(57, 'top_cover_finger_1_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray-not-1');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(58, 'place-kitTray-not-1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-SolidObject-SR-NotUnderWithContact');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(59, 'EndEffector-SolidObject-SR-NotUnderWithContact', 'SolidObject', 'EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('robot_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(60, 'robot_point', 2000.000000, 200.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_finger_1_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(61, 'small_gear_finger_1_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('sku_kit_box');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_InternalShape)
VALUES(62, 'sku_kit_box', 'SKU for Boxes for Kits and KitTrays', 1.200000, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_shape_ply');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(63, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_shape_ply', 'External shape for kit_gearbox_1Top1Bottom1Small1Medium1Big_tray');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFileName, hasExternalShape_ModelFormatName)
VALUES(63, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_shape_ply', '/usr/local/iora/ply/kit_gearbox_1Top1Bottom1Small1Medium1Big_tray.ply', 'PLY');

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray-not-4');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(64, 'place-kitTray-not-4', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray-not-3');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(65, 'place-kitTray-not-3', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ThreeFingerGrasp10');

INSERT INTO EndEffectorGrasp
(EndEffectorGraspID, _NAME, hadByEffectorAndGrasp_StockKeepingUnit)
VALUES(66, 'ThreeFingerGrasp10', NULL);

INSERT INTO ThreeFingerGrasp
(ThreeFingerGraspID, _NAME, hasThreeFingerGrasp_ThreeFingerGripper)
VALUES(66, 'ThreeFingerGrasp10', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ThreeFingerGrasp11');

INSERT INTO EndEffectorGrasp
(EndEffectorGraspID, _NAME, hadByEffectorAndGrasp_StockKeepingUnit)
VALUES(67, 'ThreeFingerGrasp11', NULL);

INSERT INTO ThreeFingerGrasp
(ThreeFingerGraspID, _NAME, hasThreeFingerGrasp_ThreeFingerGripper)
VALUES(67, 'ThreeFingerGrasp11', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('final-quantity-of-parts-in-kit');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(68, 'final-quantity-of-parts-in-kit', 'Final quantity of Parts in Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-part-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(69, 'take-part-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ThreeFingerGrasp12');

INSERT INTO EndEffectorGrasp
(EndEffectorGraspID, _NAME, hadByEffectorAndGrasp_StockKeepingUnit)
VALUES(70, 'ThreeFingerGrasp12', NULL);

INSERT INTO ThreeFingerGrasp
(ThreeFingerGraspID, _NAME, hasThreeFingerGrasp_ThreeFingerGripper)
VALUES(70, 'ThreeFingerGrasp12', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-part-param-4');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(71, 'take-part-param-4', 'PartsTray', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part-has-physicalLocation-refObject-endEffector-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(72, 'part-has-physicalLocation-refObject-endEffector-param2', 2, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-part-param-5');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(73, 'take-part-param-5', 'EndEffector', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-part-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(74, 'take-part-param-2', 'Part', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-part-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(75, 'take-part-param-3', 'StockKeepingUnit', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part-has-physicalLocation-refObject-endEffector-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(76, 'part-has-physicalLocation-refObject-endEffector-param1', 1, 'Part', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-part-F2NLess');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(77, 'look-for-part-F2NLess');

INSERT INTO FunctionToNumberCondition
(FunctionToNumberConditionID, _NAME, hasFunctionToNumberCondition_Number, hasFunctionToNumberCondition_Function)
VALUES(77, 'look-for-part-F2NLess', 1, NULL);

INSERT INTO FunctionToNumberLess
(FunctionToNumberLessID, _NAME, hadByFunctionToNumberLess_Precondition)
VALUES(77, 'look-for-part-F2NLess', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-part-param-6');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(78, 'take-part-param-6', 'Kit', 6, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('sku_gearbox_1Top1Bottom1Small1Medium1Big_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_ExternalShape, hasStockKeepingUnit_InternalShape)
VALUES(79, 'sku_gearbox_1Top1Bottom1Small1Medium1Big_tray', 'SKU for kit trays', 0.200000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('sku_partstray_bottom_cover');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_ExternalShape, hasStockKeepingUnit_InternalShape)
VALUES(80, 'sku_partstray_bottom_cover', 'SKU for PartsTrays that hold bottom covers', 0.200000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('workTableArea-is-for-sku');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(81, 'workTableArea-is-for-sku', 'WorkTableArea is reserved for SolidObject tat has StockKeepingUnit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_finger_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(82, 'small_gear_finger_3_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-EndEffector-SR');

INSERT INTO PredicateStateRelationOr
(PredicateStateRelationOrID, _NAME)
VALUES(83, 'kitTray-EndEffector-SR');

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_finger_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(84, 'top_cover_finger_1_point', 4.650000, 84.200000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('ThreeFingerGrasp1');

INSERT INTO EndEffectorGrasp
(EndEffectorGraspID, _NAME, hadByEffectorAndGrasp_StockKeepingUnit)
VALUES(85, 'ThreeFingerGrasp1', NULL);

INSERT INTO ThreeFingerGrasp
(ThreeFingerGraspID, _NAME, hasThreeFingerGrasp_ThreeFingerGripper)
VALUES(85, 'ThreeFingerGrasp1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('Part-Kit-SR-ContainedIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(86, 'Part-Kit-SR-ContainedIn', 'Part', 'Kit', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ThreeFingerGrasp6');

INSERT INTO EndEffectorGrasp
(EndEffectorGraspID, _NAME, hadByEffectorAndGrasp_StockKeepingUnit)
VALUES(87, 'ThreeFingerGrasp6', NULL);

INSERT INTO ThreeFingerGrasp
(ThreeFingerGraspID, _NAME, hasThreeFingerGrasp_ThreeFingerGripper)
VALUES(87, 'ThreeFingerGrasp6', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-not-3');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(88, 'place-part-not-3', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_tray_relative_location_in');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefData, hadBySecondaryLocation_SolidObject)
VALUES(89, 'bottom_cover_tray_relative_location_in', NULL, NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(89, 'bottom_cover_tray_relative_location_in', 'Relative location of bottom_cover_tray in a WorkTableArea');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(89, 'bottom_cover_tray_relative_location_in');

INSERT INTO DataThing
(_NAME)
VALUES('ThreeFingerGrasp7');

INSERT INTO EndEffectorGrasp
(EndEffectorGraspID, _NAME, hadByEffectorAndGrasp_StockKeepingUnit)
VALUES(90, 'ThreeFingerGrasp7', NULL);

INSERT INTO ThreeFingerGrasp
(ThreeFingerGraspID, _NAME, hasThreeFingerGrasp_GraspPose3, hasThreeFingerGrasp_GraspPose2, hasThreeFingerGrasp_GraspPose1, hasThreeFingerGrasp_ThreeFingerGripper)
VALUES(90, 'ThreeFingerGrasp7', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-not-2');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(91, 'place-part-not-2', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ThreeFingerGrasp8');

INSERT INTO EndEffectorGrasp
(EndEffectorGraspID, _NAME, hadByEffectorAndGrasp_StockKeepingUnit)
VALUES(92, 'ThreeFingerGrasp8', NULL);

INSERT INTO ThreeFingerGrasp
(ThreeFingerGraspID, _NAME, hasThreeFingerGrasp_ThreeFingerGripper)
VALUES(92, 'ThreeFingerGrasp8', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-not-1');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(93, 'place-part-not-1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ThreeFingerGrasp9');

INSERT INTO EndEffectorGrasp
(EndEffectorGraspID, _NAME, hadByEffectorAndGrasp_StockKeepingUnit)
VALUES(94, 'ThreeFingerGrasp9', NULL);

INSERT INTO ThreeFingerGrasp
(ThreeFingerGraspID, _NAME, hasThreeFingerGrasp_ThreeFingerGripper)
VALUES(94, 'ThreeFingerGrasp9', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ThreeFingerGrasp2');

INSERT INTO EndEffectorGrasp
(EndEffectorGraspID, _NAME, hadByEffectorAndGrasp_StockKeepingUnit)
VALUES(95, 'ThreeFingerGrasp2', NULL);

INSERT INTO ThreeFingerGrasp
(ThreeFingerGraspID, _NAME, hasThreeFingerGrasp_GraspPose3, hasThreeFingerGrasp_GraspPose2, hasThreeFingerGrasp_GraspPose1, hasThreeFingerGrasp_ThreeFingerGripper)
VALUES(95, 'ThreeFingerGrasp2', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_finger_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(96, 'top_cover_finger_2_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(96, 'top_cover_finger_2_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(96, 'top_cover_finger_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(97, 'empty_kit_tray_supply_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('ThreeFingerGrasp3');

INSERT INTO EndEffectorGrasp
(EndEffectorGraspID, _NAME, hadByEffectorAndGrasp_StockKeepingUnit)
VALUES(98, 'ThreeFingerGrasp3', NULL);

INSERT INTO ThreeFingerGrasp
(ThreeFingerGraspID, _NAME, hasThreeFingerGrasp_GraspPose3, hasThreeFingerGrasp_GraspPose2, hasThreeFingerGrasp_GraspPose1, hasThreeFingerGrasp_ThreeFingerGripper)
VALUES(98, 'ThreeFingerGrasp3', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('NotContainedIn');

INSERT INTO IntermediateStateRelation
(IntermediateStateRelationID, _NAME, hasIntermediateStateRelation_RCC8StateRelation, hadByIntermediateStateRelation_SOAP)
VALUES(99, 'NotContainedIn', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ThreeFingerGrasp4');

INSERT INTO EndEffectorGrasp
(EndEffectorGraspID, _NAME, hadByEffectorAndGrasp_StockKeepingUnit)
VALUES(100, 'ThreeFingerGrasp4', NULL);

INSERT INTO ThreeFingerGrasp
(ThreeFingerGraspID, _NAME, hasThreeFingerGrasp_GraspPose3, hasThreeFingerGrasp_GraspPose2, hasThreeFingerGrasp_GraspPose1, hasThreeFingerGrasp_ThreeFingerGripper)
VALUES(100, 'ThreeFingerGrasp4', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ThreeFingerGrasp5');

INSERT INTO EndEffectorGrasp
(EndEffectorGraspID, _NAME, hadByEffectorAndGrasp_StockKeepingUnit)
VALUES(101, 'ThreeFingerGrasp5', NULL);

INSERT INTO ThreeFingerGrasp
(ThreeFingerGraspID, _NAME, hasThreeFingerGrasp_GraspPose3, hasThreeFingerGrasp_GraspPose2, hasThreeFingerGrasp_GraspPose1, hasThreeFingerGrasp_ThreeFingerGripper)
VALUES(101, 'ThreeFingerGrasp5', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_finger_1_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(102, 'medium_gear_finger_1_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-Kit-SR');

INSERT INTO PredicateStateRelationOr
(PredicateStateRelationOrID, _NAME)
VALUES(103, 'EndEffector-Kit-SR');

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-F2FLess');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(104, 'place-kit-F2FLess');

INSERT INTO FunctionToFunctionCondition
(FunctionToFunctionConditionID, _NAME, hasFunctionToFunctionCondition_F2, hasFunctionToFunctionCondition_F1)
VALUES(104, 'place-kit-F2FLess', NULL, NULL);

INSERT INTO FunctionToFunctionLess
(FunctionToFunctionLessID, _NAME, hadByFunctionToFunctionLess_Precondition)
VALUES(104, 'place-kit-F2FLess', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_shape_ply');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(105, 'kit_gearbox_1Top1Bottom1Medium_shape_ply', 'External shape for kit_gearbox_1Top1Bottom1Medium_tray');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFileName, hasExternalShape_ModelFormatName)
VALUES(105, 'kit_gearbox_1Top1Bottom1Medium_shape_ply', '/usr/local/iora/ply/kit_gearbox_1Top1Bottom1Medium_tray.ply', 'PLY');

INSERT INTO DataThing
(_NAME)
VALUES('workTable-has-objectOnTable-kit-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(106, 'workTable-has-objectOnTable-kit-param1', 1, 'WorkTable', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_finger_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(107, 'top_cover_finger_2_point', 4.650000, 84.200000, 7.120000);

INSERT INTO DataThing
(_NAME)
VALUES('workTable-has-objectOnTable-kit-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(108, 'workTable-has-objectOnTable-kit-param2', 2, 'Kit', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('changing_station_1', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(2, 'changing_station_1');

INSERT INTO EndEffectorChangingStation
(EndEffectorChangingStationID, _NAME, hasEndEffectorChangingStation_Base)
VALUES(2, 'changing_station_1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(109, 'place-kit-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffectorHolder-F2NLess');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(110, 'look-for-endEffectorHolder-F2NLess');

INSERT INTO FunctionToNumberCondition
(FunctionToNumberConditionID, _NAME, hasFunctionToNumberCondition_Number, hasFunctionToNumberCondition_Function)
VALUES(110, 'look-for-endEffectorHolder-F2NLess', 1, NULL);

INSERT INTO FunctionToNumberLess
(FunctionToNumberLessID, _NAME, hadByFunctionToNumberLess_Precondition)
VALUES(110, 'look-for-endEffectorHolder-F2NLess', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(111, 'place-part', 'Place a Part in a Kit', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(112, 'bottom_cover_1_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_big_gear_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(113, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_big_gear_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('take-kitTray-param-5');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(114, 'take-kitTray-param-5', 'StockKeepingUnit', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_top_cover_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(115, 'shape_top_cover_tray', '
        Shape of PartsTrays for top covers
    ');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(115, 'shape_top_cover_tray');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(115, 'shape_top_cover_tray', false, 423.000000, 12.700000, 565.000000);

INSERT INTO DataThing
(_NAME)
VALUES('take-kitTray-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(116, 'take-kitTray-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kitTray-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(117, 'take-kitTray-param-2', 'KitTray', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kitTray-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(118, 'take-kitTray-param-3', 'LargeBoxWithEmptyKitTrays', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kitTray-param-4');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(119, 'take-kitTray-param-4', 'EndEffector', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_gearbox_1Small1Medium_small_gear');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Sku, hadByPartRefAndPose_KitDesign)
VALUES(120, 'part_ref_and_pose_kit_gearbox_1Small1Medium_small_gear', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('quantity-of-parts-in-kit-param1');

INSERT INTO FunctionParameter
(FunctionParameterID, _NAME, hasFunctionParameter_ParameterPosition, hasFunctionParameter_Parameter, hadByFunctionParameter_Function)
VALUES(121, 'quantity-of-parts-in-kit-param1', 1, 'StockKeepingUnit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_finger_1_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(122, 'small_gear_finger_1_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-not-5');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(123, 'place-kit-not-5', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('quantity-of-parts-in-kit-param2');

INSERT INTO FunctionParameter
(FunctionParameterID, _NAME, hasFunctionParameter_ParameterPosition, hasFunctionParameter_Parameter, hadByFunctionParameter_Function)
VALUES(124, 'quantity-of-parts-in-kit-param2', 2, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-physicalLocation-refObject-workTable-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(125, 'kitTray-has-physicalLocation-refObject-workTable-param2', 2, 'WorkTable', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-physicalLocation-refObject-workTable-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(126, 'kitTray-has-physicalLocation-refObject-workTable-param1', 1, 'KitTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_finger_3_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(127, 'top_cover_finger_3_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part-has-physicalLocation-refObject-partsTray-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(128, 'part-has-physicalLocation-refObject-partsTray-param2', 2, 'PartsTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part-has-physicalLocation-refObject-partsTray-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(129, 'part-has-physicalLocation-refObject-partsTray-param1', 1, 'Part', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kitTray-param-5');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(130, 'look-for-kitTray-param-5', 'LargeBoxWithEmptyKitTrays', 5, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation, hadByObjectOnTable_WorkTable)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big', NULL, NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(3, 'kit_gearbox_1Top1Bottom1Small1Medium1Big');

INSERT INTO Kit
(KitID, _NAME, hasKit_Finished, hasKit_Design, hasKit_KitTray)
VALUES(3, 'kit_gearbox_1Top1Bottom1Small1Medium1Big', false, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kitTray-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(131, 'look-for-kitTray-param-2', 'KitTray', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kitTray-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(132, 'look-for-kitTray-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kitTray-param-4');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(133, 'look-for-kitTray-param-4', 'EndEffector', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kitTray-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(134, 'look-for-kitTray-param-3', 'StockKeepingUnit', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_tray_relative_location_in');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefData, hadBySecondaryLocation_SolidObject)
VALUES(135, 'kit_gearbox_1Small1Medium_tray_relative_location_in', NULL, NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(135, 'kit_gearbox_1Small1Medium_tray_relative_location_in', 'Relative location of kit_gearbox_1Small1Medium_tray in a WorkTableArea');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(135, 'kit_gearbox_1Small1Medium_tray_relative_location_in');

INSERT INTO DataThing
(_NAME)
VALUES('NotOnTopWithContact');

INSERT INTO IntermediateStateRelation
(IntermediateStateRelationID, _NAME, hasIntermediateStateRelation_RCC8StateRelation, hadByIntermediateStateRelation_SOAP)
VALUES(136, 'NotOnTopWithContact', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(137, 'empty_kit_tray_box_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('workTableArea-is-not-occupied');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(138, 'workTableArea-is-not-occupied', 'WorkTableArea is not occupied', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(139, 'changing_station_base_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('sku_part_big_gear');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_ExternalShape, hasStockKeepingUnit_InternalShape)
VALUES(140, 'sku_part_big_gear', 'SKU for big gear', 0.200000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_gearbox_1Top1Bottom1Medium');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_KittingWorkstation, hasKitDesign_KitTraySku)
VALUES(141, 'kit_design_gearbox_1Top1Bottom1Medium', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_finger_1_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(142, 'top_cover_finger_1_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('KitTray-LargeBoxWithEmptyKitTrays-SR-ContainedIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(143, 'KitTray-LargeBoxWithEmptyKitTrays-SR-ContainedIn', 'KitTray', 'LargeBoxWithEmptyKitTrays', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-SolidObject-SR-NotContainedIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(144, 'EndEffector-SolidObject-SR-NotContainedIn', 'SolidObject', 'EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(145, 'kit_gearbox_tray_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('create-kit-not-1');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(146, 'create-kit-not-1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('create-kit-not-2');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(147, 'create-kit-not-2', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('robotiq_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(148, 'robotiq_gripper_holder_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-Part-SR-NotUnderWithContact');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(149, 'EndEffector-Part-SR-NotUnderWithContact', 'Part', 'KitTray', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-part-effect-not-1');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(150, 'take-part-effect-not-1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kit');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(151, 'look-for-kit', 'Look for a Kit before picking one', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-part-effect-not-2');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(152, 'take-part-effect-not-2', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_top_cover');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Sku, hadByPartRefAndPose_KitDesign)
VALUES(153, 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_top_cover', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-EndEffectorHolder-ContainedIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(154, 'EndEffector-EndEffectorHolder-ContainedIn', 'EndEffector', 'EndEffectorHolder', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('RCC8-OnTopWithContact');

INSERT INTO RCC8StateRelation
(RCC8StateRelationID, _NAME, hasRCC8StateRelation_RCC8Set)
VALUES(155, 'RCC8-OnTopWithContact', 'Z-EC and Z-Plus and (X-NTPP or X-NTPPi or X-PO or X-TPP or X-TPPi) and (Y-NTPP or Y-NTPPi or Y-PO or Y-TPP or Y-TPPi)');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_tray_area');

INSERT INTO WorkTableArea
(WorkTableAreaID, _NAME, hasWorkTableArea_Ymax, hasWorkTableArea_Ymin, hasWorkTableArea_Xmin, hasWorkTableArea_Xmax, hasWorkTableArea_SolidObject, hadByWorkTableArea_WorkTable, hasWorkTableArea_Sku)
VALUES(156, 'kit_gearbox_1Small1Medium_tray_area', 423.500000, 48.500000, 81.000000, 391.000000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('sku_part_small_gear');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_ExternalShape, hasStockKeepingUnit_InternalShape)
VALUES(157, 'sku_part_small_gear', 'SKU for small gear', 0.100000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-heldObject-kitTray');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(158, 'endEffector-has-heldObject-kitTray', 'EndEffector is holding KitTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_tray_pose_location_on');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(159, 'medium_gear_tray_pose_location_on', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(159, 'medium_gear_tray_pose_location_on', NULL, NULL, NULL);

INSERT INTO PoseLocationOn
(PoseLocationOnID, _NAME)
VALUES(159, 'medium_gear_tray_pose_location_on');

INSERT INTO DataThing
(_NAME)
VALUES('workTable-has-objectOnTable-kit');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(160, 'workTable-has-objectOnTable-kit', 'WorkTable has Kit on its top', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('Part-Kit-SR-PartiallyIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(161, 'Part-Kit-SR-PartiallyIn', 'Part', 'Kit', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-physicalLocation-refObject-endEffectorHolder-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(162, 'endEffector-has-physicalLocation-refObject-endEffectorHolder-param1', 1, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('Kit-LargeBoxWithKits-SR-ContainedIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(163, 'Kit-LargeBoxWithKits-SR-ContainedIn', 'Kit', 'LargeBoxWithKits', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-physicalLocation-refObject-endEffectorHolder-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(164, 'endEffector-has-physicalLocation-refObject-endEffectorHolder-param2', 2, 'EndEffectorHolder', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_slot_medium_gear');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(165, 'kit_gearbox_1Top1Bottom1Medium_slot_medium_gear', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_small_gear_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(166, 'kit_gearbox_1Small1Medium_small_gear_point', 0.000000, -100.000000, -115.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_small_gear_ply');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(167, 'shape_gearbox_small_gear_ply', 'ply file with shape of small gears for a gearbox');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFileName, hasExternalShape_ModelIllustrationName, hasExternalShape_ModelFormatName)
VALUES(167, 'shape_gearbox_small_gear_ply', '/usr/local/iora/ply/small_gear.ply', 'http://aprs-dev.el.nist.gov/jpg/gearbox_small_gear.jpg', 'PLY');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation, hadByObjectOnTable_WorkTable)
VALUES('bottom_cover_tray', NULL, NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(4, 'bottom_cover_tray', NULL);

INSERT INTO PartsVessel
(PartsVesselID, _NAME, hasPartsVessel_PartQuantity, hasPartsVessel_SerialNumber, hasPartsVessel_PartSku)
VALUES(4, 'bottom_cover_tray', 1, 19, NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME)
VALUES(4, 'bottom_cover_tray');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(168, 'changing_station_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(169, 'empty_kit_tray_supply_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_tray_1Small1Medium_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(170, 'kit_gearbox_tray_1Small1Medium_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kit-Increase-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(171, 'look-for-kit-Increase-1', 1, NULL);

INSERT INTO Increase
(IncreaseID, _NAME, hadByIncrease_Effect)
VALUES(171, 'look-for-kit-Increase-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_partstray_area');

INSERT INTO WorkTableArea
(WorkTableAreaID, _NAME, hasWorkTableArea_Ymax, hasWorkTableArea_Ymin, hasWorkTableArea_Xmin, hasWorkTableArea_Xmax, hasWorkTableArea_SolidObject, hadByWorkTableArea_WorkTable, hasWorkTableArea_Sku)
VALUES(172, 'bottom_cover_partstray_area', 400.000000, 0.000000, 605.000000, 1170.000000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffector-in-endEffectorHolder-F2N-Less');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(173, 'look-for-endEffector-in-endEffectorHolder-F2N-Less');

INSERT INTO FunctionToNumberCondition
(FunctionToNumberConditionID, _NAME, hasFunctionToNumberCondition_Number, hasFunctionToNumberCondition_Function)
VALUES(173, 'look-for-endEffector-in-endEffectorHolder-F2N-Less', 1, NULL);

INSERT INTO FunctionToNumberLess
(FunctionToNumberLessID, _NAME, hadByFunctionToNumberLess_Precondition)
VALUES(173, 'look-for-endEffector-in-endEffectorHolder-F2N-Less', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(174, 'small_gear_1_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(175, 'work_table_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_finger_1_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(176, 'big_gear_finger_1_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-Kit-SR-ContainedIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(177, 'EndEffector-Kit-SR-ContainedIn', 'Kit', 'EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-physicalLocation-refObject-lbwk-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(178, 'kit-has-physicalLocation-refObject-lbwk-param1', 1, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffectorHolder');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(179, 'look-for-endEffectorHolder', 'Task the sensor system to look for EndEffectorHolder', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_small_gear_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(180, 'kit_gearbox_1Small1Medium_small_gear_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robotiq_gripper_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(181, 'robotiq_gripper_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('Part-PartsTray-SR-PartiallyIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(182, 'Part-PartsTray-SR-PartiallyIn', 'Part', 'PartsTray', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-physicalLocation-refObject-endEffector-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(183, 'kit-has-physicalLocation-refObject-endEffector-param2', 2, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-physicalLocation-refObject-endEffector-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(184, 'kit-has-physicalLocation-refObject-endEffector-param1', 1, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-physicalLocation-refObject-lbwk-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(185, 'kit-has-physicalLocation-refObject-lbwk-param2', 2, 'LargeBoxWithKits', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_medium_gear_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(186, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_medium_gear_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('RCC8-NotContainedIn');

INSERT INTO RCC8StateRelation
(RCC8StateRelationID, _NAME, hasRCC8StateRelation_RCC8Set)
VALUES(187, 'RCC8-NotContainedIn', 'not((X-TPP or X-NTPP) and (Y-TPP or Y-NTPP) and (Z-TPP or Z-NTPP))');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-part-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(188, 'look-for-part-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_finger_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(189, 'bottom_cover_finger_1_point', 7.900000, 88.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-part-param-4');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(190, 'look-for-part-param-4', 'Kit', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-part-param-5');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(191, 'look-for-part-param-5', 'EndEffector', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-part-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(192, 'look-for-part-param-2', 'Part', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-part-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(193, 'look-for-part-param-3', 'StockKeepingUnit', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part-endEffector-SR-NotUnderWithContact');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(194, 'part-endEffector-SR-NotUnderWithContact', 'SolidObject', 'Part', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_tray', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(5, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_tray', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber)
VALUES(5, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_tray', 2);

INSERT INTO DataThing
(_NAME)
VALUES('attach-endEffector');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(195, 'attach-endEffector', 'Attach an EndEffector to Robot', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('soap');

INSERT INTO SOAP
(SOAPID, _NAME, hasSOAP_Domain, hasSOAP_KittingWorkstation)
VALUES(196, 'soap', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_slot_medium_gear');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(197, 'kit_gearbox_1Small1Medium_slot_medium_gear', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffectorHolder-effect-Increase-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(198, 'look-for-endEffectorHolder-effect-Increase-1', 1, NULL);

INSERT INTO Increase
(IncreaseID, _NAME, hadByIncrease_Effect)
VALUES(198, 'look-for-endEffectorHolder-effect-Increase-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('create-kit-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(199, 'create-kit-effect');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_top_cover_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(200, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_top_cover_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_small_gear_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(201, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_small_gear_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_tray_pose_location_on');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(202, 'big_gear_tray_pose_location_on', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(202, 'big_gear_tray_pose_location_on', NULL, NULL, NULL);

INSERT INTO PoseLocationOn
(PoseLocationOnID, _NAME)
VALUES(202, 'big_gear_tray_pose_location_on');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(203, 'kit_gearbox_1Top1Bottom1Medium_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(203, 'kit_gearbox_1Top1Bottom1Medium_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationOn
(PoseLocationOnID, _NAME)
VALUES(203, 'kit_gearbox_1Top1Bottom1Medium_pose');

INSERT INTO DataThing
(_NAME)
VALUES('RCC8-NotOnTopWithContact');

INSERT INTO RCC8StateRelation
(RCC8StateRelationID, _NAME, hasRCC8StateRelation_RCC8Set)
VALUES(204, 'RCC8-NotOnTopWithContact', 'not(Z-EC and Z-Plus and (X-NTPP or X-NTPPi or X-PO or X-TPP or X-TPPi) and (Y-NTPP or Y-NTPPi or Y-PO or Y-TPP or Y-TPPi))');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-part-Increase-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(205, 'look-for-part-Increase-1', 1, NULL);

INSERT INTO Increase
(IncreaseID, _NAME, hadByIncrease_Effect)
VALUES(205, 'look-for-part-Increase-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_tray_1Small1Medium_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(206, 'kit_gearbox_tray_1Small1Medium_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_gearbox_1Small1Medium_tray', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(6, 'kit_gearbox_1Small1Medium_tray', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber)
VALUES(6, 'kit_gearbox_1Small1Medium_tray', 3);

INSERT INTO DataThing
(_NAME)
VALUES('kitting-domain');

INSERT INTO Domain
(DomainID, _NAME)
VALUES(207, 'kitting-domain');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('robot_1', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(7, 'robot_1');

INSERT INTO Robot
(RobotID, _NAME, hasRobot_MaximumLoadWeight, hasRobot_Description)
VALUES(7, 'robot_1', 7.000000, 'this is the robot');

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(208, 'big_gear_tray_point', 12.700000, 900.000000, 214.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_tray_1Top1Bottom1Medium_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(209, 'kit_gearbox_tray_1Top1Bottom1Medium_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('set-grasp-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(210, 'set-grasp-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-part-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(211, 'look-for-part-effect');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kitTray-F2NLess');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(212, 'look-for-kitTray-F2NLess');

INSERT INTO FunctionToNumberCondition
(FunctionToNumberConditionID, _NAME, hasFunctionToNumberCondition_Number, hasFunctionToNumberCondition_Function)
VALUES(212, 'look-for-kitTray-F2NLess', 1, NULL);

INSERT INTO FunctionToNumberLess
(FunctionToNumberLessID, _NAME, hadByFunctionToNumberLess_Precondition)
VALUES(212, 'look-for-kitTray-F2NLess', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(213, 'finished_kit_receiver_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(213, 'finished_kit_receiver_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(213, 'finished_kit_receiver_pose');

INSERT INTO DataThing
(_NAME)
VALUES('workTable-has-objectOnTable-kitTray-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(214, 'workTable-has-objectOnTable-kitTray-param2', 2, 'KitTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_finger_3_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(215, 'small_gear_finger_3_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('workTable-has-objectOnTable-kitTray-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(216, 'workTable-has-objectOnTable-kitTray-param1', 1, 'WorkTable', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-workTableArea');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(217, 'look-for-workTableArea', 'Look for a  WorkTableArea on a WorkTable to place a SolidObject with StockKeepingUnit', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(218, 'medium_gear_tray_point', 12.700000, 900.000000, 214.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('small_gear_1', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(8, 'small_gear_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(8, 'small_gear_1', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('attach-endEffector-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(219, 'attach-endEffector-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('take-kit-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(220, 'take-kit-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kit-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(221, 'take-kit-param-2', 'Kit', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('sku_gearbox_1Top1Bottom1Medium_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_ExternalShape, hasStockKeepingUnit_InternalShape)
VALUES(222, 'sku_gearbox_1Top1Bottom1Medium_tray', 'SKU for kit trays that can hold only one top cover, one medium gear, and one bottom cover', 0.200000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('OnTopWithContact');

INSERT INTO IntermediateStateRelation
(IntermediateStateRelationID, _NAME, hasIntermediateStateRelation_RCC8StateRelation, hadByIntermediateStateRelation_SOAP)
VALUES(223, 'OnTopWithContact', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kit-param-5');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(224, 'take-kit-param-5', 'StockKeepingUnit', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kit-param-6');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(225, 'take-kit-param-6', 'EndEffector', 6, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kit-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(226, 'take-kit-param-3', 'KitTray', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kit-param-4');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(227, 'take-kit-param-4', 'WorkTable', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-found-flag');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(228, 'kitTray-found-flag', 'Flag used to identify if a KitTray has been found by the sensor system', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('sku_partstray_big_gear_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_ExternalShape, hasStockKeepingUnit_InternalShape)
VALUES(229, 'sku_partstray_big_gear_tray', 'SKU for PartsTrays that hold big gears', 0.200000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('grasp-is-set-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(230, 'grasp-is-set-param1', 1, 'StockKeepingUnit', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('bottom_cover_1', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(9, 'bottom_cover_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(9, 'bottom_cover_1', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_finger_3_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(231, 'bottom_cover_finger_3_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(232, 'robot_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-is-found-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(233, 'kitTray-is-found-param1', 1, 'KitTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('Kit-EndEffector-SR-NotUnderWithContact');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(234, 'Kit-EndEffector-SR-NotUnderWithContact', 'SolidObject', 'Kit', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_small_gear_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(235, 'shape_small_gear_tray', 'Shape of PartsTrays for small gears');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(235, 'shape_small_gear_tray');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(235, 'shape_small_gear_tray', false, 423.000000, 12.700000, 565.000000);

INSERT INTO DataThing
(_NAME)
VALUES('workTable-has-objectOnTable-kitTray');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(236, 'workTable-has-objectOnTable-kitTray', 'WorkTable has KitTray on its top', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_finger_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(237, 'small_gear_finger_1_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(238, 'place-part-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-EndEffectorHolder-SR');

INSERT INTO PredicateStateRelationOr
(PredicateStateRelationOrID, _NAME)
VALUES(239, 'EndEffector-EndEffectorHolder-SR');

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(240, 'bottom_cover_tray_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('endEffectorHolder-found-flag');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(241, 'endEffectorHolder-found-flag', 'Flag used to identify if an EndEffectorHolder has been found by the sensor system', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-heldObject-kit-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(242, 'endEffector-has-heldObject-kit-param1', 1, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-heldObject-kit-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(243, 'endEffector-has-heldObject-kit-param2', 2, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_finger_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(244, 'medium_gear_finger_3_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_small_gear_tray_ply');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(245, 'shape_gearbox_small_gear_tray_ply', 'ply file with shape of parts trays for small gears for a gearbox');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFileName, hasExternalShape_ModelFormatName)
VALUES(245, 'shape_gearbox_small_gear_tray_ply', '/usr/local/iora/ply/small_gear_tray.ply', 'PLY');

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_finger_2_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(246, 'big_gear_finger_2_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robotiq_gripper_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(247, 'robotiq_gripper_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('Part-Kit-SR');

INSERT INTO PredicateStateRelationOr
(PredicateStateRelationOrID, _NAME)
VALUES(248, 'Part-Kit-SR');

INSERT INTO DataThing
(_NAME)
VALUES('set-grasp');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(249, 'set-grasp', 'Set grasp configuration for a given Part that has StockKeepingUnit', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-workTableArea-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(250, 'look-for-workTableArea-effect');

INSERT INTO DataThing
(_NAME)
VALUES('take-part-F2NGreater-1');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(251, 'take-part-F2NGreater-1');

INSERT INTO FunctionToNumberCondition
(FunctionToNumberConditionID, _NAME, hasFunctionToNumberCondition_Number, hasFunctionToNumberCondition_Function)
VALUES(251, 'take-part-F2NGreater-1', 0, NULL);

INSERT INTO FunctionToNumberGreater
(FunctionToNumberGreaterID, _NAME, hadByFunctionToNumberGreater_Precondition)
VALUES(251, 'take-part-F2NGreater-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-part-F2NGreater-2');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(252, 'take-part-F2NGreater-2');

INSERT INTO FunctionToNumberCondition
(FunctionToNumberConditionID, _NAME, hasFunctionToNumberCondition_Number, hasFunctionToNumberCondition_Function)
VALUES(252, 'take-part-F2NGreater-2', 0, NULL);

INSERT INTO FunctionToNumberGreater
(FunctionToNumberGreaterID, _NAME, hadByFunctionToNumberGreater_Precondition)
VALUES(252, 'take-part-F2NGreater-2', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-param-6');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(253, 'place-part-param-6', 'EndEffector', 6, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(254, 'place-part-param-2', 'Part', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(255, 'place-part-param-3', 'StockKeepingUnit', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-param-4');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(256, 'place-part-param-4', 'Kit', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-param-5');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(257, 'place-part-param-5', 'Slot', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-found-flag');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(258, 'endEffector-found-flag', 'Flag used to identify if an EndEffector has been found by the sensor system', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_finger_3_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(259, 'top_cover_finger_3_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('workTable-has-workTableArea');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(260, 'workTable-has-workTableArea', 'WorkTable has  WorkTableArea', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-not-4');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(261, 'place-kit-not-4', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-not-3');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(262, 'place-kit-not-3', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kitting_workstation_1', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(10, 'kitting_workstation_1');

INSERT INTO KittingWorkstation
(KittingWorkstationID, _NAME, hasKittingWorkstation_LengthUnit, hasKittingWorkstation_ForceUnit, hasKittingWorkstation_WeightUnit, hasKittingWorkstation_AngleUnit, hasKittingWorkstation_ChangingStation, hasKittingWorkstation_Robot)
VALUES(10, 'kitting_workstation_1', 'millimeter', 'newton', 'kilogram', 'degree', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-not-2');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(263, 'place-kit-not-2', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-not-1');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(264, 'place-kit-not-1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-kitTray-SR-PartiallyIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(265, 'EndEffector-kitTray-SR-PartiallyIn', 'KitTray', 'EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_finger_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(266, 'medium_gear_finger_2_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(266, 'medium_gear_finger_2_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(266, 'medium_gear_finger_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('take-kitTray');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(267, 'take-kitTray', 'Take a KitTray from a LargeBoxWithEmptyKitTrays', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('quantity-of-kits-in-lbwk-param1');

INSERT INTO FunctionParameter
(FunctionParameterID, _NAME, hasFunctionParameter_ParameterPosition, hasFunctionParameter_Parameter, hadByFunctionParameter_Function)
VALUES(268, 'quantity-of-kits-in-lbwk-param1', 1, 'LargeBoxWithKits', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kitTray-F2NGreater');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(269, 'take-kitTray-F2NGreater');

INSERT INTO FunctionToNumberCondition
(FunctionToNumberConditionID, _NAME, hasFunctionToNumberCondition_Number, hasFunctionToNumberCondition_Function)
VALUES(269, 'take-kitTray-F2NGreater', 0, NULL);

INSERT INTO FunctionToNumberGreater
(FunctionToNumberGreaterID, _NAME, hadByFunctionToNumberGreater_Precondition)
VALUES(269, 'take-kitTray-F2NGreater', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(270, 'kit_gearbox_tray_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('slot-is-found');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(271, 'slot-is-found', 'Slot is found', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_tray_pose_location_on');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(272, 'top_cover_tray_pose_location_on', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(272, 'top_cover_tray_pose_location_on', NULL, NULL, NULL);

INSERT INTO PoseLocationOn
(PoseLocationOnID, _NAME)
VALUES(272, 'top_cover_tray_pose_location_on');

INSERT INTO DataThing
(_NAME)
VALUES('KitTray-endEffector-SR-PartiallyIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(273, 'KitTray-endEffector-SR-PartiallyIn', 'KitTray', 'EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('current-quantity-of-parts-in-kit-param1');

INSERT INTO FunctionParameter
(FunctionParameterID, _NAME, hasFunctionParameter_ParameterPosition, hasFunctionParameter_Parameter, hadByFunctionParameter_Function)
VALUES(274, 'current-quantity-of-parts-in-kit-param1', 1, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part-has-physicalLocation-refObject-endEffector');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hasPositivePredicate_PredicateStateRelationOR, hadByPositivePredicate_Domain)
VALUES(275, 'part-has-physicalLocation-refObject-endEffector', 'Part is held by EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(276, 'bottom_cover_tray_point', 12.700000, 900.000000, 214.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_1Small1Medium_kit_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(277, 'shape_1Small1Medium_kit_tray', 'Shape of KitTrays that can hold a small gear and 1 medium gear');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(277, 'shape_1Small1Medium_kit_tray');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(277, 'shape_1Small1Medium_kit_tray', false, 310.000000, 50.000000, 370.000000);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_finger_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(278, 'big_gear_finger_2_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(278, 'big_gear_finger_2_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(278, 'big_gear_finger_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_medium_gear_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(279, 'kit_gearbox_1Small1Medium_medium_gear_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit-slot-is-found-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(280, 'kit-slot-is-found-param1', 1, 'Slot', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(281, 'kit_gearbox_point', 12.700000, 1645.000000, 1085.000000);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_finger_2_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(282, 'small_gear_finger_2_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('capacity-of-kits-in-lbwk-param1');

INSERT INTO FunctionParameter
(FunctionParameterID, _NAME, hasFunctionParameter_ParameterPosition, hasFunctionParameter_Parameter, hadByFunctionParameter_Function)
VALUES(283, 'capacity-of-kits-in-lbwk-param1', 1, 'LargeBoxWithKits', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_finger_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(284, 'bottom_cover_finger_3_point', 7.900000, 56.100000, -12.200000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_bottom_cover');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Sku, hadByPartRefAndPose_KitDesign)
VALUES(285, 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_bottom_cover', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-physicalLocation-refObject-endEffector');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hasPositivePredicate_PredicateStateRelationOR, hadByPositivePredicate_Domain)
VALUES(286, 'kitTray-has-physicalLocation-refObject-endEffector', 'KitTray is held by EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('partsVessel-has-part-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(287, 'partsVessel-has-part-param2', 2, 'Part', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_1Top1Bottom1Medium_kit_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(288, 'shape_1Top1Bottom1Medium_kit_tray', 'Shape of KitTrays that can gold a top cover, 1 bottom cover, and 1 medium gear');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(288, 'shape_1Top1Bottom1Medium_kit_tray');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(288, 'shape_1Top1Bottom1Medium_kit_tray', false, 310.000000, 50.000000, 370.000000);

INSERT INTO DataThing
(_NAME)
VALUES('partsVessel-has-part-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(289, 'partsVessel-has-part-param1', 1, 'PartsTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('sku_part_bottom_cover');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_ExternalShape, hasStockKeepingUnit_InternalShape)
VALUES(290, 'sku_part_bottom_cover', 'SKU for bottom cover', 0.050000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_gearbox_1Top1Bottom1Small1Medium1Big');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_KittingWorkstation, hasKitDesign_KitTraySku)
VALUES(291, 'kit_design_gearbox_1Top1Bottom1Small1Medium1Big', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(292, 'empty_kit_tray_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(292, 'empty_kit_tray_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(292, 'empty_kit_tray_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part-has-physicalLocation-refObject-kit');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hasPositivePredicate_PredicateStateRelationOR, hadByPositivePredicate_Domain)
VALUES(293, 'part-has-physicalLocation-refObject-kit', 'Part is in Kit', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part-is-found');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(294, 'part-is-found', 'Part is found', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_changing_station_base');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(295, 'shape_changing_station_base', 'Shape of base of changing station');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(295, 'shape_changing_station_base');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(295, 'shape_changing_station_base', true, 100.000000, 500.000000, 420.000000);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(296, 'work_table_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(296, 'work_table_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(296, 'work_table_pose');

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_finger_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(297, 'big_gear_finger_2_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_work_table');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(298, 'shape_work_table', 'Shape of the work table');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(298, 'shape_work_table');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(298, 'shape_work_table', true, 1800.000000, 1000.000000, 1800.000000);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(299, 'medium_gear_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(299, 'medium_gear_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(299, 'medium_gear_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('largeBoxWithKitsSlot-is-not-occupied');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(300, 'largeBoxWithKitsSlot-is-not-occupied', 'LargeBoxWithKitsSlot is not occupied by any Kit', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation, hadByObject_KittingWorkstation)
VALUES('work_table_1', NULL, NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME, hasNoSkuObject_InternalShape)
VALUES(11, 'work_table_1', NULL);

INSERT INTO WorkTable
(WorkTableID, _NAME)
VALUES(11, 'work_table_1');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_slot_small_gear');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(301, 'kit_gearbox_1Small1Medium_slot_small_gear', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-physicalLocation-refObject-endEffector');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hasPositivePredicate_PredicateStateRelationOR, hadByPositivePredicate_Domain)
VALUES(302, 'kit-has-physicalLocation-refObject-endEffector', 'Kit is held by EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(303, 'finished_kit_receiver_point', 0.000000, 2500.000000, 1000.000000);

INSERT INTO DataThing
(_NAME)
VALUES('attach-endEffector-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(304, 'attach-endEffector-param-2', 'EndEffector', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('attach-endEffector-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(305, 'attach-endEffector-param-3', 'EndEffectorHolder', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('attach-endEffector-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(306, 'attach-endEffector-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(307, 'medium_gear_1_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part-found-flag');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(308, 'part-found-flag', 'Flag that tells if a Part has been found', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(309, 'medium_gear_1_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(310, 'work_table_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-physicalLocation-refObject-kit-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(311, 'kitTray-has-physicalLocation-refObject-kit-param2', 2, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-physicalLocation-refObject-kit-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(312, 'kitTray-has-physicalLocation-refObject-kit-param1', 1, 'KitTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kit-not-1');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(313, 'take-kit-not-1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(314, 'place-kitTray-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('take-kit-not-2');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(315, 'take-kit-not-2', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kit-not-3');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(316, 'take-kit-not-3', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(317, 'small_gear_tray_point', 12.700000, 900.000000, 214.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation, hadByObjectOnTable_WorkTable)
VALUES('kit_gearbox_1Small1Medium', NULL, NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(12, 'kit_gearbox_1Small1Medium');

INSERT INTO Kit
(KitID, _NAME, hasKit_Finished, hasKit_Design, hasKit_KitTray)
VALUES(12, 'kit_gearbox_1Small1Medium', false, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit-found-flag');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(318, 'kit-found-flag', 'Flag used to identify if a Kit has been found by the sensor system', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('KitTray-endEffector-SR-NotUnderWithContact');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(319, 'KitTray-endEffector-SR-NotUnderWithContact', 'SolidObject', 'KitTray', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_finger_3_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(320, 'bottom_cover_finger_3_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_gearbox_1Top1Bottom1Medium_bottom_cover');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Sku, hadByPartRefAndPose_KitDesign)
VALUES(321, 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Medium_bottom_cover', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-part-Decrease-2');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(322, 'take-part-Decrease-2', 1, NULL);

INSERT INTO Decrease
(DecreaseID, _NAME, hadByDecrease_Effect)
VALUES(322, 'take-part-Decrease-2', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('Kit-EndEffector-SR-ContainedIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(323, 'Kit-EndEffector-SR-ContainedIn', 'Kit', 'EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffectorHolder-is-found');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(324, 'endEffectorHolder-is-found', ' EndEffectorHolder is found by the sensor sytem', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-part-Decrease-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(325, 'take-part-Decrease-1', 1, NULL);

INSERT INTO Decrease
(DecreaseID, _NAME, hadByDecrease_Effect)
VALUES(325, 'take-part-Decrease-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kit-param-5');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(326, 'look-for-kit-param-5', 'EndEffector', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('Kit-WorkTable-SR-UnderWithContact');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(327, 'Kit-WorkTable-SR-UnderWithContact', 'Kit', 'WorkTable', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kit-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(328, 'look-for-kit-param-3', 'KitTray', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kit-param-4');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(329, 'look-for-kit-param-4', 'StockKeepingUnit', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_partstray_area');

INSERT INTO WorkTableArea
(WorkTableAreaID, _NAME, hasWorkTableArea_Ymax, hasWorkTableArea_Ymin, hasWorkTableArea_Xmin, hasWorkTableArea_Xmax, hasWorkTableArea_SolidObject, hadByWorkTableArea_WorkTable, hasWorkTableArea_Sku)
VALUES(330, 'small_gear_partstray_area', 400.000000, 0.000000, 605.000000, 1170.000000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kit-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(331, 'look-for-kit-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_big_gear_tray_ply');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(332, 'shape_gearbox_big_gear_tray_ply', 'ply file with shape of parts trays for big gears for a gearbox');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFileName, hasExternalShape_ModelFormatName)
VALUES(332, 'shape_gearbox_big_gear_tray_ply', '/usr/local/iora/ply/big_gear_tray.ply', 'PLY');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kit-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(333, 'look-for-kit-param-2', 'Kit', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ContainedInLBWK');

INSERT INTO IntermediateStateRelation
(IntermediateStateRelationID, _NAME, hasIntermediateStateRelation_RCC8StateRelation, hadByIntermediateStateRelation_SOAP)
VALUES(334, 'ContainedInLBWK', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_bottom_cover');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(335, 'shape_gearbox_bottom_cover', 'Shape of bottom covers for a gearbox');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(335, 'shape_gearbox_bottom_cover');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(335, 'shape_gearbox_bottom_cover', true, 100.000000, 47.500000, 196.000000);

INSERT INTO DataThing
(_NAME)
VALUES('largeBoxWithKits-has-slot');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(336, 'largeBoxWithKits-has-slot', 'LargeBoxWithKits has LargeBoxWithKitsSlot', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('NotInContactWith');

INSERT INTO IntermediateStateRelation
(IntermediateStateRelationID, _NAME, hasIntermediateStateRelation_RCC8StateRelation, hadByIntermediateStateRelation_SOAP)
VALUES(337, 'NotInContactWith', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_box', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(13, 'finished_kit_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber)
VALUES(13, 'finished_kit_box', 5);

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-physicalLocation-refObject-lbwk');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hasPositivePredicate_PredicateStateRelationOR, hadByPositivePredicate_Domain)
VALUES(338, 'kit-has-physicalLocation-refObject-lbwk', 'Kit is located in LargeBoxWithKits', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_finger_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(339, 'top_cover_finger_3_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(339, 'top_cover_finger_3_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(339, 'top_cover_finger_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('sku_partstray_small_gear_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_ExternalShape, hasStockKeepingUnit_InternalShape)
VALUES(340, 'sku_partstray_small_gear_tray', 'SKU for PartsTrays that hold small gears', 0.200000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_top_cover_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(341, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_top_cover_x_axis', -1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('big_gear_1', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(14, 'big_gear_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(14, 'big_gear_1', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_finger_2_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(342, 'bottom_cover_finger_2_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('create-kit-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(343, 'create-kit-param-1', 'Kit', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-heldObject-part-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(344, 'endEffector-has-heldObject-part-param2', 2, 'Part', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-heldObject-part-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(345, 'endEffector-has-heldObject-part-param1', 1, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('sku_gearbox_1Small1Medium_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_ExternalShape, hasStockKeepingUnit_InternalShape)
VALUES(346, 'sku_gearbox_1Small1Medium_tray', 'SKU for kit trays that can hold only one small gear and one medium gear', 0.200000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('create-kit-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(347, 'create-kit-param-3', 'WorkTable', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('create-kit-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(348, 'create-kit-param-2', 'KitTray', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_tray_relative_location_in');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefData, hadBySecondaryLocation_SolidObject)
VALUES(349, 'top_cover_tray_relative_location_in', NULL, NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(349, 'top_cover_tray_relative_location_in', 'Relative location of top_cover_tray in a WorkTableArea');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(349, 'top_cover_tray_relative_location_in');

INSERT INTO DataThing
(_NAME)
VALUES('robotiq_gripper_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(350, 'robotiq_gripper_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(351, 'small_gear_tray_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffector-in-endEffectorHolder-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(352, 'look-for-endEffector-in-endEffectorHolder-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffector-in-endEffectorHolder-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(353, 'look-for-endEffector-in-endEffectorHolder-param-2', 'EndEffector', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffector-in-endEffectorHolder-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(354, 'look-for-endEffector-in-endEffectorHolder-param-3', 'EndEffectorHolder', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_big_gear');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(355, 'shape_gearbox_big_gear', 'Shape of bounding cylinder of big gears');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(355, 'shape_gearbox_big_gear');

INSERT INTO CylindricalShape
(CylindricalShapeID, _NAME, hasCylindricalShape_HasTop, hasCylindricalShape_Height, hasCylindricalShape_Diameter)
VALUES(355, 'shape_gearbox_big_gear', true, 37.000000, 81.000000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kit-F2NLess');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(356, 'look-for-kit-F2NLess');

INSERT INTO FunctionToNumberCondition
(FunctionToNumberConditionID, _NAME, hasFunctionToNumberCondition_Number, hasFunctionToNumberCondition_Function)
VALUES(356, 'look-for-kit-F2NLess', 1, NULL);

INSERT INTO FunctionToNumberLess
(FunctionToNumberLessID, _NAME, hadByFunctionToNumberLess_Precondition)
VALUES(356, 'look-for-kit-F2NLess', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_medium_gear_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(357, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_medium_gear_point', 0.000000, -20.000000, -115.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(358, 'finished_kit_box_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('InContactWith');

INSERT INTO IntermediateStateRelation
(IntermediateStateRelationID, _NAME, hasIntermediateStateRelation_RCC8StateRelation, hadByIntermediateStateRelation_SOAP)
VALUES(359, 'InContactWith', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffectorHolder-is-not-occupied-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(360, 'endEffectorHolder-is-not-occupied-param1', 1, 'EndEffectorHolder', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_bottom_cover_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(361, 'kit_gearbox_1Top1Bottom1Medium_bottom_cover_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_medium_gear_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(362, 'shape_medium_gear_tray', 'Shape of PartsTrays for small gears');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(362, 'shape_medium_gear_tray');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(362, 'shape_medium_gear_tray', false, 423.000000, 12.700000, 565.000000);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(363, 'big_gear_1_point', 0.000000, -110.000000, 21.000000);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_finger_3_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(364, 'big_gear_finger_3_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(365, 'big_gear_1_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(366, 'changing_station_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-physicalLocation-refObject-endEffectorHolder');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hasPositivePredicate_PredicateStateRelationOR, hadByPositivePredicate_Domain)
VALUES(367, 'endEffector-has-physicalLocation-refObject-endEffectorHolder', 'EndEffector is located in EndEffectorHolder', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_medium_gear_ply');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(368, 'shape_gearbox_medium_gear_ply', 'ply file with shape of medium gears for a gearbox');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFileName, hasExternalShape_ModelIllustrationName, hasExternalShape_ModelFormatName)
VALUES(368, 'shape_gearbox_medium_gear_ply', '/usr/local/iora/ply/medium_gear.ply', 'http://aprs-dev.el.nist.gov/jpg/gearbox_medium_gear.jpg', 'PLY');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffectorHolder-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(369, 'look-for-endEffectorHolder-effect');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_bottom_cover_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(370, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_bottom_cover_point', 0.000000, -10.000000, 110.000000);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-is-found-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(371, 'endEffector-is-found-param1', 1, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_finger_3_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(372, 'medium_gear_finger_3_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-physicalLocation-refObject-robot');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(373, 'endEffector-has-physicalLocation-refObject-robot', 'EndEffector is attached to Robot', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('LargeBoxWithKits-Kit-SR');

INSERT INTO PredicateStateRelationOr
(PredicateStateRelationOrID, _NAME)
VALUES(374, 'LargeBoxWithKits-Kit-SR');

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-is-for-partSKU-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(375, 'endEffector-is-for-partSKU-param2', 2, 'StockKeepingUnit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-is-for-partSKU-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(376, 'endEffector-is-for-partSKU-param1', 1, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-no-heldObject');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hasPositivePredicate_PredicateStateRelationOR, hadByPositivePredicate_Domain)
VALUES(377, 'endEffector-has-no-heldObject', 'EndEffector is not holding any object', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_top_coer');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(378, 'shape_gearbox_top_coer', 'Shape of top covers for a gearbox');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(378, 'shape_gearbox_top_coer');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(378, 'shape_gearbox_top_coer', true, 95.600000, 24.000000, 197.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit-is-found-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(379, 'kit-is-found-param1', 1, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_finger_2_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(380, 'top_cover_finger_2_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kitTray-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(381, 'look-for-kitTray-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('robot_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(382, 'robot_z_axis', 0.000000, 0.000000, -1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_tray_1Small1Medium_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(383, 'kit_gearbox_tray_1Small1Medium_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_finger_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(384, 'small_gear_finger_1_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(384, 'small_gear_finger_1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(384, 'small_gear_finger_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_bottom_cover_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(385, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_bottom_cover_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_finger_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(386, 'small_gear_finger_3_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(386, 'small_gear_finger_3_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(386, 'small_gear_finger_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('PartiallyIn');

INSERT INTO IntermediateStateRelation
(IntermediateStateRelationID, _NAME, hasIntermediateStateRelation_RCC8StateRelation, hadByIntermediateStateRelation_SOAP)
VALUES(387, 'PartiallyIn', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('Kit-EndEffector-SR');

INSERT INTO PredicateStateRelationOr
(PredicateStateRelationOrID, _NAME)
VALUES(388, 'Kit-EndEffector-SR');

INSERT INTO DataThing
(_NAME)
VALUES('quantity-of-kittrays-in-lbwekt-param1');

INSERT INTO FunctionParameter
(FunctionParameterID, _NAME, hasFunctionParameter_ParameterPosition, hasFunctionParameter_Parameter, hadByFunctionParameter_Function)
VALUES(389, 'quantity-of-kittrays-in-lbwekt-param1', 1, 'LargeBoxWithEmptyKitTrays', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('Kit-LargeBoxWithKits-SR');

INSERT INTO PredicateStateRelationOr
(PredicateStateRelationOrID, _NAME)
VALUES(390, 'Kit-LargeBoxWithKits-SR');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_top_cover_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(391, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_top_cover_point', 0.000000, -10.000000, -20.000000);

INSERT INTO DataThing
(_NAME)
VALUES('lbwkslot_10');

INSERT INTO LargeBoxWithKitsSlot
(LargeBoxWithKitsSlotID, _NAME, hasLargeBoxWithKitsSlot_Rank, hadByLargeBoxWithKitsSlot_LargeBoxWithKits)
VALUES(392, 'lbwkslot_10', 10, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('lbwkslot_11');

INSERT INTO LargeBoxWithKitsSlot
(LargeBoxWithKitsSlotID, _NAME, hasLargeBoxWithKitsSlot_Rank, hadByLargeBoxWithKitsSlot_LargeBoxWithKits)
VALUES(393, 'lbwkslot_11', 11, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('workTable-has-no-objectOnTable-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(394, 'workTable-has-no-objectOnTable-param1', 1, 'WorkTable', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_big_gear_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(395, 'shape_big_gear_tray', 'Shape of PartsTrays for big gears');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(395, 'shape_big_gear_tray');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(395, 'shape_big_gear_tray', false, 423.000000, 12.700000, 565.000000);

INSERT INTO DataThing
(_NAME)
VALUES('workTable-has-no-objectOnTable');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(396, 'workTable-has-no-objectOnTable', 'WorkTable has nothing on top of it', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_finger_3_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(397, 'small_gear_finger_3_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_top_cover_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(398, 'kit_gearbox_1Top1Bottom1Medium_top_cover_point', 0.000000, -10.000000, -20.000000);

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(399, 'place-kit-effect');

INSERT INTO DataThing
(_NAME)
VALUES('LargeBoxWithKits-Kit-SR-ContainedIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(400, 'LargeBoxWithKits-Kit-SR-ContainedIn', 'Kit', 'LargeBoxWithKits', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(401, 'top_cover_1_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(402, 'robot_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(402, 'robot_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(402, 'robot_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-physicalLocation-refObject-lbwekt-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(403, 'kitTray-has-physicalLocation-refObject-lbwekt-param1', 1, 'KitTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-physicalLocation-refObject-lbwekt-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(404, 'kitTray-has-physicalLocation-refObject-lbwekt-param2', 2, 'LargeBoxWithEmptyKitTrays', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('workTableArea-is-found-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(405, 'workTableArea-is-found-param2', 2, 'WorkTableArea', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('workTableArea-is-found-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(406, 'workTableArea-is-found-param1', 1, 'WorkTable', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('largeBoxWithKitsSlot-has-rank-param1');

INSERT INTO FunctionParameter
(FunctionParameterID, _NAME, hasFunctionParameter_ParameterPosition, hasFunctionParameter_Parameter, hadByFunctionParameter_Function)
VALUES(407, 'largeBoxWithKitsSlot-has-rank-param1', 1, 'LargeBoxWithKits', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('largeBoxWithKitsSlot-has-rank-param2');

INSERT INTO FunctionParameter
(FunctionParameterID, _NAME, hasFunctionParameter_ParameterPosition, hasFunctionParameter_Parameter, hadByFunctionParameter_Function)
VALUES(408, 'largeBoxWithKitsSlot-has-rank-param2', 2, 'LargeBoxWithKitsSlot', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(409, 'top_cover_tray_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(410, 'big_gear_tray_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_finger_1_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(411, 'bottom_cover_finger_1_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('quantity-of-parts-in-partstray-param1');

INSERT INTO FunctionParameter
(FunctionParameterID, _NAME, hasFunctionParameter_ParameterPosition, hasFunctionParameter_Parameter, hadByFunctionParameter_Function)
VALUES(412, 'quantity-of-parts-in-partstray-param1', 1, 'PartsTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(413, 'medium_gear_tray_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('take-part-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(414, 'take-part-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(415, 'kit_gearbox_1Top1Bottom1Medium_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('largeBoxWithKitsSlot-has-rank');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(416, 'largeBoxWithKitsSlot-has-rank', 'Set a rank to a LargeBoxWithKitsSlot', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffectorHolder-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(417, 'look-for-endEffectorHolder-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('robotiq_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(418, 'robotiq_gripper_holder_point', 500.000000, 250.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-skuObject-sku-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(419, 'kitTray-has-skuObject-sku-param1', 1, 'KitTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('quantity-of-kittrays-in-lbwekt');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(420, 'quantity-of-kittrays-in-lbwekt', 'Current quantity of KitTrays in LargeBoxWithEmptyKitTrays', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('quantity-of-kits-in-lbwk');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(421, 'quantity-of-kits-in-lbwk', 'Quantity of Kits in LargeBoxWithKits', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-skuObject-sku-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(422, 'kitTray-has-skuObject-sku-param2', 2, 'StockKeepingUnit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('robot-has-no-endEffector');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(423, 'robot-has-no-endEffector', 'Robot has no EndEffector', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_gearbox_1Top1Bottom1Medium_tray', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(15, 'kit_gearbox_1Top1Bottom1Medium_tray', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber)
VALUES(15, 'kit_gearbox_1Top1Bottom1Medium_tray', 1);

INSERT INTO DataThing
(_NAME)
VALUES('WorkTable-SolidObject-SR-NotUnderWithContact');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(424, 'WorkTable-SolidObject-SR-NotUnderWithContact', 'WorkTable', 'SolidObject', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffectorHolder-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(425, 'look-for-endEffectorHolder-param-3', 'EndEffectorHolder', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('lbwk-has-kit-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(426, 'lbwk-has-kit-param1', 1, 'LargeBoxWithKits', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffectorHolder-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(427, 'look-for-endEffectorHolder-param-2', 'EndEffector', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(428, 'big_gear_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(428, 'big_gear_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(428, 'big_gear_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-Kit-SR-NotUnderWithContact');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(429, 'EndEffector-Kit-SR-NotUnderWithContact', 'SolidObject', 'Kit', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(430, 'medium_gear_1_point', 0.000000, -110.000000, 21.000000);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_tray_relative_location_in');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefData, hadBySecondaryLocation_SolidObject)
VALUES(431, 'medium_gear_tray_relative_location_in', NULL, NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(431, 'medium_gear_tray_relative_location_in', 'Relative location of medium_gear_tray in a WorkTableArea');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(431, 'medium_gear_tray_relative_location_in');

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_top_cover_ply');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(432, 'shape_gearbox_top_cover_ply', 'ply file with shape of top covers for a gearbox');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFileName, hasExternalShape_ModelIllustrationName, hasExternalShape_ModelFormatName)
VALUES(432, 'shape_gearbox_top_cover_ply', '/usr/local/iora/ply/top_cover.ply', 'http://aprs-dev.el.nist.gov/jpg/gearbox_top_cover.jpg', 'PLY');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-kit');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(433, 'look-for-slot-in-kit', 'Task a sensor system to look for Slot in Kit before placing a Part in it', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('lbwk-has-kit-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(434, 'lbwk-has-kit-param2', 2, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(435, 'kit_gearbox_1Small1Medium_point', 12.700000, 1645.000000, 1085.000000);

INSERT INTO DataThing
(_NAME)
VALUES('PartsTray-Part-SR-ContainedIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(436, 'PartsTray-Part-SR-ContainedIn', 'Part', 'PartsTray', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_finger_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(437, 'big_gear_finger_3_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_small_gear');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(438, 'shape_gearbox_small_gear', 'Shape of bounding cylinder of small gears');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(438, 'shape_gearbox_small_gear');

INSERT INTO CylindricalShape
(CylindricalShapeID, _NAME, hasCylindricalShape_HasTop, hasCylindricalShape_Height, hasCylindricalShape_Diameter)
VALUES(438, 'shape_gearbox_small_gear', true, 21.400000, 43.700000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-kit-Increase-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(439, 'look-for-slot-in-kit-Increase-1', 1, NULL);

INSERT INTO Increase
(IncreaseID, _NAME, hadByIncrease_Effect)
VALUES(439, 'look-for-slot-in-kit-Increase-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('quantity-of-parts-in-kit');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(440, 'quantity-of-parts-in-kit', 'Current quantity of Parts with StockKeepingUnit in Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-lbwk-FunctionToFunctionEqual');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(441, 'look-for-slot-in-lbwk-FunctionToFunctionEqual');

INSERT INTO FunctionToFunctionCondition
(FunctionToFunctionConditionID, _NAME, hasFunctionToFunctionCondition_F2, hasFunctionToFunctionCondition_F1)
VALUES(441, 'look-for-slot-in-lbwk-FunctionToFunctionEqual', NULL, NULL);

INSERT INTO FunctionToFunctionEqual
(FunctionToFunctionEqualID, _NAME, hadByFunctionToFunctionEqual_Precondition)
VALUES(441, 'look-for-slot-in-lbwk-FunctionToFunctionEqual', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('RCC8-NotUnderWithContact');

INSERT INTO RCC8StateRelation
(RCC8StateRelationID, _NAME, hasRCC8StateRelation_RCC8Set)
VALUES(442, 'RCC8-NotUnderWithContact', 'not(Z-EC and Z-Minus and (X-NTPP or X-NTPPi or X-PO or X-TPP or X-TPPi) and (Y-NTPP or Y-NTPPi or Y-PO or Y-TPP or Y-TPPi))');

INSERT INTO DataThing
(_NAME)
VALUES('RCC8-UnderWithContact');

INSERT INTO RCC8StateRelation
(RCC8StateRelationID, _NAME, hasRCC8StateRelation_RCC8Set)
VALUES(443, 'RCC8-UnderWithContact', 'Z-EC and Z-Minus and (X-NTPP or X-NTPPi or X-PO or X-TPP or X-TPPi) and (Y-NTPP or Y-NTPPi or Y-PO or Y-TPP or Y-TPPi)');

INSERT INTO DataThing
(_NAME)
VALUES('RCC8-NotInContactWith');

INSERT INTO RCC8StateRelation
(RCC8StateRelationID, _NAME, hasRCC8StateRelation_RCC8Set)
VALUES(444, 'RCC8-NotInContactWith', 'not(X-EC or Y-EC or Z-EC)');

INSERT INTO DataThing
(_NAME)
VALUES('endEffectorHolder-has-endEffector-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(445, 'endEffectorHolder-has-endEffector-param1', 1, 'EndEffectorHolder', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('quantity-of-parts-in-partstray');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(446, 'quantity-of-parts-in-partstray', 'Current quantity of Parts in PartsTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffectorHolder-has-endEffector-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(447, 'endEffectorHolder-has-endEffector-param2', 2, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('lbwk-has-kit');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hasPositivePredicate_PredicateStateRelationOR, hadByPositivePredicate_Domain)
VALUES(448, 'lbwk-has-kit', 'LargeBoxWithKits contains Kit', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_tray_relative_location_in');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefData, hadBySecondaryLocation_SolidObject)
VALUES(449, 'big_gear_tray_relative_location_in', NULL, NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(449, 'big_gear_tray_relative_location_in', 'Relative location of big_gear_tray in a WorkTableArea');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(449, 'big_gear_tray_relative_location_in');

INSERT INTO DataThing
(_NAME)
VALUES('attach-endEffector-Decrease-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(450, 'attach-endEffector-Decrease-1', 1, NULL);

INSERT INTO Decrease
(DecreaseID, _NAME, hadByDecrease_Effect)
VALUES(450, 'attach-endEffector-Decrease-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('Kit-EndEffector-SR-PartiallyIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(451, 'Kit-EndEffector-SR-PartiallyIn', 'Kit', 'EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('workTableArea-is-found');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(452, 'workTableArea-is-found', 'WorkTableArea is found for SolidObject with StockKeepingUnit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-physicalLocation-refObject-workTable');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(453, 'kitTray-has-physicalLocation-refObject-workTable', 'KitTray is on WorkTable', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('NotUnderWithContact');

INSERT INTO IntermediateStateRelation
(IntermediateStateRelationID, _NAME, hasIntermediateStateRelation_RCC8StateRelation, hadByIntermediateStateRelation_SOAP)
VALUES(454, 'NotUnderWithContact', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_big_gear_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(455, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_big_gear_point', 0.000000, 80.000000, -115.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_medium_gear_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(456, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_medium_gear_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-is-found');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(457, 'endEffector-is-found', 'EndEffector is found by the sensor system', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_finger_3_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(458, 'medium_gear_finger_3_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_tray_area');

INSERT INTO WorkTableArea
(WorkTableAreaID, _NAME, hasWorkTableArea_Ymax, hasWorkTableArea_Ymin, hasWorkTableArea_Xmin, hasWorkTableArea_Xmax, hasWorkTableArea_SolidObject, hadByWorkTableArea_WorkTable, hasWorkTableArea_Sku)
VALUES(459, 'kit_gearbox_1Top1Bottom1Medium_tray_area', 423.500000, 48.500000, 81.000000, 391.000000, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('changing_station_base', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME, hasNoSkuObject_InternalShape)
VALUES(16, 'changing_station_base', NULL);

INSERT INTO MechanicalComponent
(MechanicalComponentID, _NAME)
VALUES(16, 'changing_station_base');

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_partstray_area');

INSERT INTO WorkTableArea
(WorkTableAreaID, _NAME, hasWorkTableArea_Ymax, hasWorkTableArea_Ymin, hasWorkTableArea_Xmin, hasWorkTableArea_Xmax, hasWorkTableArea_SolidObject, hadByWorkTableArea_WorkTable, hasWorkTableArea_Sku)
VALUES(460, 'top_cover_partstray_area', 400.000000, 0.000000, 605.000000, 1170.000000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-part');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(461, 'take-part', 'Take a Part from a PartsTray', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-heldObject-part');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(462, 'endEffector-has-heldObject-part', 'EndEffector is holding Part', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffector-in-endEffectorHolder-Increase-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(463, 'look-for-endEffector-in-endEffectorHolder-Increase-1', 1, NULL);

INSERT INTO Increase
(IncreaseID, _NAME, hadByIncrease_Effect)
VALUES(463, 'look-for-endEffector-in-endEffectorHolder-Increase-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-is-for-kitTraySKU');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(464, 'endEffector-is-for-kitTraySKU', 'EndEffector can handle KitTrays with StockKeepingUnit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-part-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(465, 'look-for-part-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-kit-F2NLess');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(466, 'look-for-slot-in-kit-F2NLess');

INSERT INTO FunctionToNumberCondition
(FunctionToNumberConditionID, _NAME, hasFunctionToNumberCondition_Number, hasFunctionToNumberCondition_Function)
VALUES(466, 'look-for-slot-in-kit-F2NLess', 1, NULL);

INSERT INTO FunctionToNumberLess
(FunctionToNumberLessID, _NAME, hadByFunctionToNumberLess_Precondition)
VALUES(466, 'look-for-slot-in-kit-F2NLess', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_finger_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(467, 'bottom_cover_finger_1_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(467, 'bottom_cover_finger_1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(467, 'bottom_cover_finger_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_tray_pose_location_on');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(468, 'bottom_cover_tray_pose_location_on', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(468, 'bottom_cover_tray_pose_location_on', NULL, NULL, NULL);

INSERT INTO PoseLocationOn
(PoseLocationOnID, _NAME)
VALUES(468, 'bottom_cover_tray_pose_location_on');

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_finger_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(469, 'big_gear_finger_3_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(469, 'big_gear_finger_3_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(469, 'big_gear_finger_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_top_cover_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(470, 'kit_gearbox_1Top1Bottom1Medium_top_cover_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-physicalLocation-refObject-workTable');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(471, 'kit-has-physicalLocation-refObject-workTable', 'Kit is on WorkTable', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('set-grasp-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(472, 'set-grasp-effect');

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_finger_1_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(473, 'medium_gear_finger_1_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(474, 'top_cover_1_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_bottom_cover_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(475, 'kit_gearbox_1Top1Bottom1Medium_bottom_cover_point', 0.000000, -10.000000, 110.000000);

INSERT INTO DataThing
(_NAME)
VALUES('final-quantity-of-parts-in-kit-param1');

INSERT INTO FunctionParameter
(FunctionParameterID, _NAME, hasFunctionParameter_ParameterPosition, hasFunctionParameter_Parameter, hadByFunctionParameter_Function)
VALUES(476, 'final-quantity-of-parts-in-kit-param1', 1, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('slot-is-not-occupied');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(477, 'slot-is-not-occupied', 'Defines if a Slot is occupied', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_finger_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(478, 'big_gear_finger_1_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(479, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(479, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationOn
(PoseLocationOnID, _NAME)
VALUES(479, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_pose');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffector-in-endEffectorHolder-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(480, 'look-for-endEffector-in-endEffectorHolder-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kit-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(481, 'look-for-kit-effect');

INSERT INTO DataThing
(_NAME)
VALUES('take-part-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(482, 'take-part-effect');

INSERT INTO DataThing
(_NAME)
VALUES('create-kit');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(483, 'create-kit', 'Create a Kit from a KitTray', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffectorHolder-can-hold-endEffector-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(484, 'endEffectorHolder-can-hold-endEffector-param1', 1, 'EndEffectorHolder', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffectorHolder-can-hold-endEffector-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(485, 'endEffectorHolder-can-hold-endEffector-param2', 2, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('WorkTable-Kit-SR-UnderWithContact');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(486, 'WorkTable-Kit-SR-UnderWithContact', 'WorkTable', 'Kit', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-SolidObject-SR');

INSERT INTO PredicateStateRelationOr
(PredicateStateRelationOrID, _NAME)
VALUES(487, 'EndEffector-SolidObject-SR');

INSERT INTO DataThing
(_NAME)
VALUES('workTableArea-is-not-occupied-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(488, 'workTableArea-is-not-occupied-param1', 1, 'WorkTableArea', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('KitTray-EndEffector-SRContainedIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(489, 'KitTray-EndEffector-SRContainedIn', 'KitTray', 'EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('RCC8-OnTopOf');

INSERT INTO RCC8StateRelation
(RCC8StateRelationID, _NAME, hasRCC8StateRelation_RCC8Set)
VALUES(490, 'RCC8-OnTopOf', 'Greater-Z and (X-EQ or X-NTPP or X-TPP or X-PO or X-NTPPi  or X-TPPi) and (Y-EQ or Y-NTPP or Y-TPP or Y-PO or Y-NTPPi or Y-TPPi)');

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_finger_2_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(491, 'bottom_cover_finger_2_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_box');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(492, 'shape_kit_box', 'Shape of boxes to hold kits and kit trays');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(492, 'shape_kit_box');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(492, 'shape_kit_box', false, 300.000000, 300.000000, 500.000000);

INSERT INTO DataThing
(_NAME)
VALUES('Kit-LargeBoxWithKits-SR-PartiallyIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(493, 'Kit-LargeBoxWithKits-SR-PartiallyIn', 'Kit', 'LargeBoxWithKits', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation, hadByObjectOnTable_WorkTable)
VALUES('kit_gearbox_1Top1Bottom1Medium', NULL, NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(17, 'kit_gearbox_1Top1Bottom1Medium');

INSERT INTO Kit
(KitID, _NAME, hasKit_Finished, hasKit_Design, hasKit_KitTray)
VALUES(17, 'kit_gearbox_1Top1Bottom1Medium', false, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-is-for-partSKU');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(494, 'endEffector-is-for-partSKU', 'EndEffector can hold Parts with StockKeepingUnit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_bottom_cover_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(495, 'shape_bottom_cover_tray', '
        Shape of PartsTrays for bottom covers
    ');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(495, 'shape_bottom_cover_tray');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(495, 'shape_bottom_cover_tray', false, 423.000000, 12.700000, 565.000000);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-Kit-SR-PartiallyIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(496, 'EndEffector-Kit-SR-PartiallyIn', 'Kit', 'EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part-has-skuObject-sku-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(497, 'part-has-skuObject-sku-param1', 1, 'Part', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part-has-skuObject-sku-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(498, 'part-has-skuObject-sku-param2', 2, 'StockKeepingUnit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_gearbox_1Small1Medium_medium_gear');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Sku, hadByPartRefAndPose_KitDesign)
VALUES(499, 'part_ref_and_pose_kit_gearbox_1Small1Medium_medium_gear', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_finger_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(500, 'medium_gear_finger_2_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_medium_gear_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(501, 'kit_gearbox_1Small1Medium_medium_gear_point', 0.000000, -20.000000, -115.000000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kit-FunctionToFunctionEqual');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(502, 'look-for-kit-FunctionToFunctionEqual');

INSERT INTO FunctionToFunctionCondition
(FunctionToFunctionConditionID, _NAME, hasFunctionToFunctionCondition_F2, hasFunctionToFunctionCondition_F1)
VALUES(502, 'look-for-kit-FunctionToFunctionEqual', NULL, NULL);

INSERT INTO FunctionToFunctionEqual
(FunctionToFunctionEqualID, _NAME, hadByFunctionToFunctionEqual_Precondition)
VALUES(502, 'look-for-kit-FunctionToFunctionEqual', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(503, 'kit_gearbox_1Top1Bottom1Medium_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(503, 'kit_gearbox_1Top1Bottom1Medium_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationOn
(PoseLocationOnID, _NAME)
VALUES(503, 'kit_gearbox_1Top1Bottom1Medium_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('slot-in-kit-found-flag');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(504, 'slot-in-kit-found-flag', 'Flag used to identify if a slot has been found in a Kit before placing a Part in the Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-is-for-kitTraySKU-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(505, 'endEffector-is-for-kitTraySKU-param2', 2, 'StockKeepingUnit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_medium_gear');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(506, 'shape_gearbox_medium_gear', 'Shape of bounding cylinder of medium gears');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(506, 'shape_gearbox_medium_gear');

INSERT INTO CylindricalShape
(CylindricalShapeID, _NAME, hasCylindricalShape_HasTop, hasCylindricalShape_Height, hasCylindricalShape_Diameter)
VALUES(506, 'shape_gearbox_medium_gear', true, 25.500000, 59.700000);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-is-for-kitTraySKU-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(507, 'endEffector-is-for-kitTraySKU-param1', 1, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kit');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(508, 'place-kit', 'Place a Kit in a LargeBoxWithKits', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(509, 'empty_kit_tray_supply_point', 0.000000, 1500.000000, 1000.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-physicalLocation-refObject-lbwekt');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(510, 'kitTray-has-physicalLocation-refObject-lbwekt', 'KitTray is located in LargeBoxWithEmptyKitTrays', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(511, 'kit_gearbox_1Top1Bottom1Medium_point', 12.700000, 1645.000000, 1085.000000);

INSERT INTO DataThing
(_NAME)
VALUES('attach-endEffector-not-1');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(512, 'attach-endEffector-not-1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_finger_2_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(513, 'top_cover_finger_2_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('lbwkslot_0');

INSERT INTO LargeBoxWithKitsSlot
(LargeBoxWithKitsSlotID, _NAME, hasLargeBoxWithKitsSlot_Rank, hadByLargeBoxWithKitsSlot_LargeBoxWithKits)
VALUES(514, 'lbwkslot_0', 0, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('lbwkslot_3');

INSERT INTO LargeBoxWithKitsSlot
(LargeBoxWithKitsSlotID, _NAME, hasLargeBoxWithKitsSlot_Rank, hadByLargeBoxWithKitsSlot_LargeBoxWithKits)
VALUES(515, 'lbwkslot_3', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('attach-endEffector-not-4');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(516, 'attach-endEffector-not-4', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(517, 'kit_gearbox_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('attach-endEffector-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(518, 'attach-endEffector-effect');

INSERT INTO DataThing
(_NAME)
VALUES('lbwkslot_4');

INSERT INTO LargeBoxWithKitsSlot
(LargeBoxWithKitsSlotID, _NAME, hasLargeBoxWithKitsSlot_Rank, hadByLargeBoxWithKitsSlot_LargeBoxWithKits)
VALUES(519, 'lbwkslot_4', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('attach-endEffector-not-3');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(520, 'attach-endEffector-not-3', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('lbwkslot_1');

INSERT INTO LargeBoxWithKitsSlot
(LargeBoxWithKitsSlotID, _NAME, hasLargeBoxWithKitsSlot_Rank, hadByLargeBoxWithKitsSlot_LargeBoxWithKits)
VALUES(521, 'lbwkslot_1', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('attach-endEffector-not-2');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(522, 'attach-endEffector-not-2', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('lbwkslot_2');

INSERT INTO LargeBoxWithKitsSlot
(LargeBoxWithKitsSlotID, _NAME, hasLargeBoxWithKitsSlot_Rank, hadByLargeBoxWithKitsSlot_LargeBoxWithKits)
VALUES(523, 'lbwkslot_2', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(524, 'changing_station_base_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(524, 'changing_station_base_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(524, 'changing_station_base_pose');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffectorHolder-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(525, 'look-for-endEffectorHolder-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-Decrease-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(526, 'place-kit-Decrease-1', 1, NULL);

INSERT INTO Decrease
(DecreaseID, _NAME, hadByDecrease_Effect)
VALUES(526, 'place-kit-Decrease-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(527, 'finished_kit_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(527, 'finished_kit_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(527, 'finished_kit_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-EndEffectorHolder-PartiallyIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(528, 'EndEffector-EndEffectorHolder-PartiallyIn', 'EndEffector', 'EndEffectorHolder', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_medium_gear_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(529, 'kit_gearbox_1Top1Bottom1Medium_medium_gear_point', 0.000000, -20.000000, -115.000000);

INSERT INTO DataThing
(_NAME)
VALUES('take-kit');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(530, 'take-kit', 'Take Kit from WorkTable', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(531, 'kit_gearbox_1Small1Medium_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(531, 'kit_gearbox_1Small1Medium_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationOn
(PoseLocationOnID, _NAME)
VALUES(531, 'kit_gearbox_1Small1Medium_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(532, 'kit_gearbox_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(533, 'bottom_cover_tray_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_partstray_area');

INSERT INTO WorkTableArea
(WorkTableAreaID, _NAME, hasWorkTableArea_Ymax, hasWorkTableArea_Ymin, hasWorkTableArea_Xmin, hasWorkTableArea_Xmax, hasWorkTableArea_SolidObject, hadByWorkTableArea_WorkTable, hasWorkTableArea_Sku)
VALUES(534, 'big_gear_partstray_area', 400.000000, 0.000000, 605.000000, 1170.000000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_gearbox_1Small1Medium');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_KittingWorkstation, hasKitDesign_KitTraySku)
VALUES(535, 'kit_design_gearbox_1Small1Medium', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('robotiq_gripper', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME, hasNoSkuObject_Weight)
VALUES(18, 'robotiq_gripper', 2.300000);

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_MaximumLoadWeight, hadByEndEffector_Robot)
VALUES(18, 'robotiq_gripper', 'The Adaptive Gripper has three articulated fingers, i.e. Finger A in front of Finger B and Finger C, that each have three joints (three phalanxes per finger). The Gripper can engage up to ten points of contact with an object (three on each of the phalanges plus the palm). The fingers are under-actuated, meaning they have fewer motors than the total number of joints. This configuration allows the fingers to automatically adapt to the shape of object they grip and it also simplifies the control of the Gripper.
				', 2.500000, NULL);

INSERT INTO GripperEffector
(GripperEffectorID, _NAME, hasGripperEffector_MaxGripWidth)
VALUES(18, 'robotiq_gripper', 155.000000);

INSERT INTO GripperThreeFinger
(GripperThreeFingerID, _NAME)
VALUES(18, 'robotiq_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('PartiallyInAndInContactWith');

INSERT INTO IntermediateStateRelation
(IntermediateStateRelationID, _NAME, hasIntermediateStateRelation_RCC8StateRelation, hadByIntermediateStateRelation_SOAP)
VALUES(536, 'PartiallyInAndInContactWith', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-workTableArea-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(537, 'look-for-workTableArea-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('kit-exists-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(538, 'kit-exists-param1', 1, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffectorHolder-is-not-occupied');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(539, 'endEffectorHolder-is-not-occupied', 'EndEffectorHolder is not occupied', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_tray_pose_location_on');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(540, 'small_gear_tray_pose_location_on', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(540, 'small_gear_tray_pose_location_on', NULL, NULL, NULL);

INSERT INTO PoseLocationOn
(PoseLocationOnID, _NAME)
VALUES(540, 'small_gear_tray_pose_location_on');

INSERT INTO DataThing
(_NAME)
VALUES('take-kit-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(541, 'take-kit-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('Robot-EndEffector-SR-InContactWith');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(542, 'Robot-EndEffector-SR-InContactWith', 'EndEffector', 'Robot', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('lbwkslot_9');

INSERT INTO LargeBoxWithKitsSlot
(LargeBoxWithKitsSlotID, _NAME, hasLargeBoxWithKitsSlot_Rank, hadByLargeBoxWithKitsSlot_LargeBoxWithKits)
VALUES(543, 'lbwkslot_9', 9, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_in_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(544, 'relative_location_in_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(544, 'relative_location_in_1', 'kitting_workstation_1 is in kitting_workstation_1');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(544, 'relative_location_in_1');

INSERT INTO DataThing
(_NAME)
VALUES('lbwkslot_6');

INSERT INTO LargeBoxWithKitsSlot
(LargeBoxWithKitsSlotID, _NAME, hasLargeBoxWithKitsSlot_Rank, hadByLargeBoxWithKitsSlot_LargeBoxWithKits)
VALUES(545, 'lbwkslot_6', 6, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(546, 'empty_kit_tray_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(546, 'empty_kit_tray_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(546, 'empty_kit_tray_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('lbwkslot_5');

INSERT INTO LargeBoxWithKitsSlot
(LargeBoxWithKitsSlotID, _NAME, hasLargeBoxWithKitsSlot_Rank, hadByLargeBoxWithKitsSlot_LargeBoxWithKits)
VALUES(547, 'lbwkslot_5', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('lbwkslot_8');

INSERT INTO LargeBoxWithKitsSlot
(LargeBoxWithKitsSlotID, _NAME, hasLargeBoxWithKitsSlot_Rank, hadByLargeBoxWithKitsSlot_LargeBoxWithKits)
VALUES(548, 'lbwkslot_8', 8, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('lbwkslot_7');

INSERT INTO LargeBoxWithKitsSlot
(LargeBoxWithKitsSlotID, _NAME, hasLargeBoxWithKitsSlot_Rank, hadByLargeBoxWithKitsSlot_LargeBoxWithKits)
VALUES(549, 'lbwkslot_7', 7, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-slot-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(550, 'kit-has-slot-param1', 1, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_tray_1Top1Bottom1Medium_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(551, 'kit_gearbox_tray_1Top1Bottom1Medium_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-slot-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(552, 'kit-has-slot-param2', 2, 'Slot', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('detach-endEffector-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(553, 'detach-endEffector-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_shape_ply');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(554, 'kit_gearbox_1Small1Medium_shape_ply', 'External shape for kit_gearbox_1Small1Medium_tray');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFileName, hasExternalShape_ModelFormatName)
VALUES(554, 'kit_gearbox_1Small1Medium_shape_ply', '/usr/local/iora/ply/kit_gearbox_1Small1Medium_tray.ply', 'PLY');

INSERT INTO DataThing
(_NAME)
VALUES('part-endEffector-SR');

INSERT INTO PredicateStateRelationOr
(PredicateStateRelationOrID, _NAME)
VALUES(555, 'part-endEffector-SR');

INSERT INTO DataThing
(_NAME)
VALUES('largeBoxWithKits-has-slot-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(556, 'largeBoxWithKits-has-slot-param2', 2, 'LargeBoxWithKitsSlot', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('largeBoxWithKits-has-slot-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(557, 'largeBoxWithKits-has-slot-param1', 1, 'LargeBoxWithKits', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(558, 'kit_gearbox_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_small_gear_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(559, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_small_gear_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_bottom_cover_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(560, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_bottom_cover_x_axis', -1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_medium_gear');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Sku, hadByPartRefAndPose_KitDesign)
VALUES(561, 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_medium_gear', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(562, 'finished_kit_box_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('detach-endEffector');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(563, 'detach-endEffector', 'Detach an EndEffector from a Robot and place it in the EndEffectorHolder', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kit-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(564, 'look-for-kit-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('part-has-skuObject-sku');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(565, 'part-has-skuObject-sku', 'Part has StockKeepingUnit', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('medium_gear_1', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(19, 'medium_gear_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(19, 'medium_gear_1', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(566, 'changing_station_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(566, 'changing_station_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(566, 'changing_station_pose');

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_finger_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(567, 'top_cover_finger_3_point', 4.650000, 84.200000, -7.120000);

INSERT INTO DataThing
(_NAME)
VALUES('grasp-is-set');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(568, 'grasp-is-set', 'Preset grasp for SKU of part for approach and pick-up', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('RCC8-InContactWith');

INSERT INTO RCC8StateRelation
(RCC8StateRelationID, _NAME, hasRCC8StateRelation_RCC8Set)
VALUES(569, 'RCC8-InContactWith', 'X-EC or Y-EC or Z-EC');

INSERT INTO DataThing
(_NAME)
VALUES('box_volume_1');

INSERT INTO BoxVolume
(BoxVolumeID, _NAME, hasBoxVolume_MaximumPoint, hasBoxVolume_MinimumPoint, hadByWorkVolume_Robot)
VALUES(570, 'box_volume_1', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('RCC8-PartiallyInAndInContactWith');

INSERT INTO RCC8StateRelation
(RCC8StateRelationID, _NAME, hasRCC8StateRelation_RCC8Set)
VALUES(571, 'RCC8-PartiallyInAndInContactWith', '((Z-Plus and (Z-NTPP or Z-NTPPi or Z-PO or Z-TPP or Z-TPPi)) and (X-NTPP or X-NTPPi or X-TPP or X-TPPi) and (Y-NTPP or Y-NTPPi or Y-TPP or Y-TPPi)) and (X-EC or Y-EC or Z-EC)');

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_finger_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(572, 'medium_gear_finger_1_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(572, 'medium_gear_finger_1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(572, 'medium_gear_finger_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('UnderWithContact');

INSERT INTO IntermediateStateRelation
(IntermediateStateRelationID, _NAME, hasIntermediateStateRelation_RCC8StateRelation, hadByIntermediateStateRelation_SOAP)
VALUES(573, 'UnderWithContact', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('RCC8-ContainedInLBWK');

INSERT INTO RCC8StateRelation
(RCC8StateRelationID, _NAME, hasRCC8StateRelation_RCC8Set)
VALUES(574, 'RCC8-ContainedInLBWK', '(X-TPP or X-NTPP) and (Y-TPP or Y-NTPP) and (Z-TPP or Z-NTPP)');

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_finger_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(575, 'small_gear_finger_2_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(575, 'small_gear_finger_2_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(575, 'small_gear_finger_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('sku_part_top_cover');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_ExternalShape, hasStockKeepingUnit_InternalShape)
VALUES(576, 'sku_part_top_cover', 'SKU for top cover', 0.050000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_finger_3_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(577, 'big_gear_finger_3_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-Robot-SR-InContactWith');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(578, 'EndEffector-Robot-SR-InContactWith', 'EndEffector', 'Robot', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_gearbox_1Top1Bottom1Medium_medium_gear');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Sku, hadByPartRefAndPose_KitDesign)
VALUES(579, 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Medium_medium_gear', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffectorHolder-can-hold-endEffector');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(580, 'endEffectorHolder-can-hold-endEffector', 'EndEffectorHolder can hold EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('detach-endEffector-effect-not-3');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(581, 'detach-endEffector-effect-not-3', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('detach-endEffector-effect-not-2');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(582, 'detach-endEffector-effect-not-2', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('detach-endEffector-effect-not-1');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(583, 'detach-endEffector-effect-not-1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(584, 'top_cover_1_point', 0.000000, -110.000000, 21.000000);

INSERT INTO DataThing
(_NAME)
VALUES('sku_partstray_top_cover');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_ExternalShape, hasStockKeepingUnit_InternalShape)
VALUES(585, 'sku_partstray_top_cover', 'SKU for PartsTrays that hold top covers', 0.200000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit-exists');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(586, 'kit-exists', 'Kit exists', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_bottom_cover');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(587, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_bottom_cover', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(588, 'kit_gearbox_1Small1Medium_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(589, 'top_cover_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(589, 'top_cover_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(589, 'top_cover_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-Part-SR-PartiallyIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(590, 'EndEffector-Part-SR-PartiallyIn', 'Part', 'EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray-param-4');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(591, 'place-kitTray-param-4', 'WorkTableArea', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(592, 'place-kitTray-param-3', 'WorkTable', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(593, 'place-kitTray-param-2', 'KitTray', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(594, 'place-kitTray-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('workTable-has-workTableArea-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(595, 'workTable-has-workTableArea-param2', 2, 'WorkTableArea', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('workTable-has-workTableArea-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(596, 'workTable-has-workTableArea-param1', 1, 'WorkTable', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray-param-5');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(597, 'place-kitTray-param-5', 'EndEffector', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('robotiq_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(598, 'robotiq_gripper_holder_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(599, 'place-part-effect');

INSERT INTO DataThing
(_NAME)
VALUES('sku_partstray_medium_gear_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_ExternalShape, hasStockKeepingUnit_InternalShape)
VALUES(600, 'sku_partstray_medium_gear_tray', 'SKU for PartsTrays that hold medium gears', 0.200000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('RCC8-ContainedIn');

INSERT INTO RCC8StateRelation
(RCC8StateRelationID, _NAME, hasRCC8StateRelation_RCC8Set)
VALUES(601, 'RCC8-ContainedIn', '(X-TPP or X-NTPP) and (Y-TPP or Y-NTPP) and (Z-TPP or Z-NTPP)');

INSERT INTO DataThing
(_NAME)
VALUES('place-part-Decrease-3');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(602, 'place-part-Decrease-3', 1, NULL);

INSERT INTO Decrease
(DecreaseID, _NAME, hadByDecrease_Effect)
VALUES(602, 'place-part-Decrease-3', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-Decrease-2');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(603, 'place-part-Decrease-2', 1, NULL);

INSERT INTO Decrease
(DecreaseID, _NAME, hadByDecrease_Effect)
VALUES(603, 'place-part-Decrease-2', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-Decrease-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(604, 'place-part-Decrease-1', 1, NULL);

INSERT INTO Decrease
(DecreaseID, _NAME, hadByDecrease_Effect)
VALUES(604, 'place-part-Decrease-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kit-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(605, 'take-kit-effect');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(606, 'kit_gearbox_1Top1Bottom1Medium_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-kit-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(607, 'look-for-slot-in-kit-param-2', 'Part', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-kit-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(608, 'look-for-slot-in-kit-param-3', 'StockKeepingUnit', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(609, 'finished_kit_receiver_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-kit-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(610, 'look-for-slot-in-kit-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-kit-param-6');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(611, 'look-for-slot-in-kit-param-6', 'EndEffector', 6, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('top_cover_1', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(20, 'top_cover_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(20, 'top_cover_1', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('largeBoxWithKitsSlot-is-not-occupied-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(612, 'largeBoxWithKitsSlot-is-not-occupied-param1', 1, 'LargeBoxWithKitsSlot', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-kit-param-4');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(613, 'look-for-slot-in-kit-param-4', 'Kit', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-kit-param-5');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(614, 'look-for-slot-in-kit-param-5', 'Slot', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(615, 'empty_kit_tray_box_point', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-physicalLocation-refObject-robot-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(616, 'endEffector-has-physicalLocation-refObject-robot-param2', 2, 'Robot', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-physicalLocation-refObject-robot-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(617, 'endEffector-has-physicalLocation-refObject-robot-param1', 1, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-lbwk-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(618, 'look-for-slot-in-lbwk-effect');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation, hadByObject_KittingWorkstation)
VALUES('empty_kit_tray_supply', NULL, NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(21, 'empty_kit_tray_supply');

INSERT INTO LargeBoxWithEmptyKitTrays
(LargeBoxWithEmptyKitTraysID, _NAME, hasLargeBoxWithEmptyKitTrays_LargeContainer)
VALUES(21, 'empty_kit_tray_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kit-F2FEqual');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(619, 'take-kit-F2FEqual');

INSERT INTO FunctionToFunctionCondition
(FunctionToFunctionConditionID, _NAME, hasFunctionToFunctionCondition_F2, hasFunctionToFunctionCondition_F1)
VALUES(619, 'take-kit-F2FEqual', NULL, NULL);

INSERT INTO FunctionToFunctionEqual
(FunctionToFunctionEqualID, _NAME, hadByFunctionToFunctionEqual_Precondition)
VALUES(619, 'take-kit-F2FEqual', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation, hadByObjectOnTable_WorkTable)
VALUES('top_cover_tray', NULL, NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(22, 'top_cover_tray', NULL);

INSERT INTO PartsVessel
(PartsVesselID, _NAME, hasPartsVessel_PartQuantity, hasPartsVessel_SerialNumber, hasPartsVessel_PartSku)
VALUES(22, 'top_cover_tray', 1, 18, NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME)
VALUES(22, 'top_cover_tray');

INSERT INTO DataThing
(_NAME)
VALUES('capacity-of-parts-in-kit-param1');

INSERT INTO FunctionParameter
(FunctionParameterID, _NAME, hasFunctionParameter_ParameterPosition, hasFunctionParameter_Parameter, hadByFunctionParameter_Function)
VALUES(620, 'capacity-of-parts-in-kit-param1', 1, 'StockKeepingUnit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-KitTray-SR-NotUnderWithContact');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(621, 'EndEffector-KitTray-SR-NotUnderWithContact', 'SolidObject', 'KitTray', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(622, 'small_gear_1_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('capacity-of-parts-in-kit-param2');

INSERT INTO FunctionParameter
(FunctionParameterID, _NAME, hasFunctionParameter_ParameterPosition, hasFunctionParameter_Parameter, hadByFunctionParameter_Function)
VALUES(623, 'capacity-of-parts-in-kit-param2', 2, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('partsVessel-has-part');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(624, 'partsVessel-has-part', 'PartsTray contains Part', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('robot-has-no-endEffector-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(625, 'robot-has-no-endEffector-param1', 1, 'Robot', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('detach-endEffector-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(626, 'detach-endEffector-effect');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kitTray-Increase-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(627, 'look-for-kitTray-Increase-1', 1, NULL);

INSERT INTO Increase
(IncreaseID, _NAME, hadByIncrease_Effect)
VALUES(627, 'look-for-kitTray-Increase-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-skuObject-sku');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(628, 'kitTray-has-skuObject-sku', 'KiTray has StockKeepingUnit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('robot-has-endEffector');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(629, 'robot-has-endEffector', 'Robot is equipped with EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_finger_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(630, 'bottom_cover_finger_3_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(630, 'bottom_cover_finger_3_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(630, 'bottom_cover_finger_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('capacity-of-kits-in-lbwk');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(631, 'capacity-of-kits-in-lbwk', 'Number of Kits that LargeBoxWithKits can hold', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('slot-is-not-occupied-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(632, 'slot-is-not-occupied-param1', 1, 'Slot', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation, hadByObjectOnTable_WorkTable)
VALUES('medium_gear_tray', NULL, NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(23, 'medium_gear_tray', NULL);

INSERT INTO PartsVessel
(PartsVesselID, _NAME, hasPartsVessel_PartQuantity, hasPartsVessel_SerialNumber, hasPartsVessel_PartSku)
VALUES(23, 'medium_gear_tray', 1, 16, NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME)
VALUES(23, 'medium_gear_tray');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-workTableArea-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(633, 'look-for-workTableArea-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-workTableArea-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(634, 'look-for-workTableArea-param-2', 'WorkTableArea', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_finger_2_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(635, 'medium_gear_finger_2_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('EndEffector-Robot-SR-NotInContactWith');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(636, 'EndEffector-Robot-SR-NotInContactWith', 'EndEffector', 'Robot', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_finger_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(637, 'bottom_cover_finger_2_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(637, 'bottom_cover_finger_2_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(637, 'bottom_cover_finger_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_tray_area');

INSERT INTO WorkTableArea
(WorkTableAreaID, _NAME, hasWorkTableArea_Ymax, hasWorkTableArea_Ymin, hasWorkTableArea_Xmin, hasWorkTableArea_Xmax, hasWorkTableArea_SolidObject, hadByWorkTableArea_WorkTable, hasWorkTableArea_Sku)
VALUES(638, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_tray_area', 423.500000, 48.500000, 81.000000, 391.000000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('current-quantity-of-parts-in-kit');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(639, 'current-quantity-of-parts-in-kit', 'Current quantity of Parts in Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_1Top1Bottom1Small1Medium1Big_kit_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(640, 'shape_1Top1Bottom1Small1Medium1Big_kit_tray', 'Shape of KitTrays that can hold 1 top cover, 1 bottom cover, 1 small gear, 1 medium gear, and 1 big gear');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(640, 'shape_1Top1Bottom1Small1Medium1Big_kit_tray');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(640, 'shape_1Top1Bottom1Small1Medium1Big_kit_tray', false, 310.000000, 50.000000, 370.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_relative_location_in');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefData, hadBySecondaryLocation_SolidObject)
VALUES(641, 'kit_tray_relative_location_in', NULL, NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(641, 'kit_tray_relative_location_in', 'Relative location of kit_gearbox_1Top1Bottom1Small1Medium1Big_tray in a WorkTableArea');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(641, 'kit_tray_relative_location_in');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kitTray-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(642, 'look-for-kitTray-effect');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(643, 'changing_station_point', 0.000000, 5500.000000, 1000.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_gripper_holder_1');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(644, 'shape_gripper_holder_1', 'Shape of gripper holder 1');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(644, 'shape_gripper_holder_1');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_HasTop, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(644, 'shape_gripper_holder_1', true, 80.000000, 1.000000, 80.000000);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_finger_2_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(645, 'medium_gear_finger_2_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(646, 'small_gear_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(646, 'small_gear_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(646, 'small_gear_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-kit-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(647, 'look-for-slot-in-kit-effect');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(648, 'changing_station_base_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_bottom_cover_ply');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(649, 'shape_gearbox_bottom_cover_ply', 'ply file with shape of bottom covers for a gearbox');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFileName, hasExternalShape_ModelIllustrationName, hasExternalShape_ModelFormatName)
VALUES(649, 'shape_gearbox_bottom_cover_ply', '/usr/local/iora/ply/bottom_cover.ply', 'http://aprs-dev.el.nist.gov/jpg/gearbox_bottom_cover.jpg', 'PLY');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_small_gear');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Sku, hadByPartRefAndPose_KitDesign)
VALUES(650, 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_small_gear', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(651, 'top_cover_tray_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-workTableArea-param-6');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(652, 'look-for-workTableArea-param-6', 'StockKeepingUnit', 6, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-workTableArea-param-5');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(653, 'look-for-workTableArea-param-5', 'EndEffector', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-workTableArea-param-4');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(654, 'look-for-workTableArea-param-4', 'KitTray', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-F2FLess');

INSERT INTO FunctionCondition
(FunctionConditionID, _NAME)
VALUES(655, 'place-part-F2FLess');

INSERT INTO FunctionToFunctionCondition
(FunctionToFunctionConditionID, _NAME, hasFunctionToFunctionCondition_F2, hasFunctionToFunctionCondition_F1)
VALUES(655, 'place-part-F2FLess', NULL, NULL);

INSERT INTO FunctionToFunctionLess
(FunctionToFunctionLessID, _NAME, hadByFunctionToFunctionLess_Precondition)
VALUES(655, 'place-part-F2FLess', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-workTableArea-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(656, 'look-for-workTableArea-param-3', 'WorkTable', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(657, 'kit_gearbox_1Small1Medium_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-Increase-1');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(658, 'place-part-Increase-1', 1, NULL);

INSERT INTO Increase
(IncreaseID, _NAME, hadByIncrease_Effect)
VALUES(658, 'place-part-Increase-1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-part-Increase-2');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(659, 'place-part-Increase-2', 1, NULL);

INSERT INTO Increase
(IncreaseID, _NAME, hadByIncrease_Effect)
VALUES(659, 'place-part-Increase-2', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffectorHolder-is-found-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(660, 'endEffectorHolder-is-found-param1', 1, 'EndEffectorHolder', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-lbwk-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(661, 'look-for-slot-in-lbwk-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('grasp-set-flag');

INSERT INTO Function
(FunctionID, _NAME, hasFunction_Description, hadByFunction_Domain)
VALUES(662, 'grasp-set-flag', 'Flag used to identify if grasp is set before taking a part', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_top_cover_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(663, 'kit_gearbox_1Top1Bottom1Medium_top_cover_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(664, 'place-kitTray', 'Place a KitTray on a WorkTable', NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_box', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(24, 'empty_kit_tray_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber)
VALUES(24, 'empty_kit_tray_box', 4);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_finger_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(665, 'bottom_cover_finger_2_point', 7.900000, 56.100000, 12.200000);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(666, 'bottom_cover_1_point', 0.000000, -110.000000, 21.000000);

INSERT INTO DataThing
(_NAME)
VALUES('workTableArea-is-for-sku-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(667, 'workTableArea-is-for-sku-param2', 2, 'StockKeepingUnit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('workTableArea-is-for-sku-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(668, 'workTableArea-is-for-sku-param1', 1, 'WorkTableArea', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_small_gear_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(669, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_small_gear_point', 0.000000, -100.000000, -115.000000);

INSERT INTO DataThing
(_NAME)
VALUES('detach-endEffector-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(670, 'detach-endEffector-param-3', 'EndEffectorHolder', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-kitTray');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(671, 'kit-has-kitTray', 'Kit is associated with KitTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('detach-endEffector-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(672, 'detach-endEffector-param-2', 'EndEffector', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('detach-endEffector-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(673, 'detach-endEffector-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('endEffector-has-heldObject-kit');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hasPositivePredicate_PredicateStateRelationOR, hadByPositivePredicate_Domain)
VALUES(674, 'endEffector-has-heldObject-kit', 'EndEffector is holding Kit', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(675, 'medium_gear_tray_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_bottom_cover_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(676, 'kit_gearbox_1Top1Bottom1Medium_bottom_cover_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('OnTopOf');

INSERT INTO IntermediateStateRelation
(IntermediateStateRelationID, _NAME, hasIntermediateStateRelation_RCC8StateRelation, hadByIntermediateStateRelation_SOAP)
VALUES(677, 'OnTopOf', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kitTray-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(678, 'take-kitTray-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_gearbox_1Top1Bottom1Medium_top_cover');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Sku, hadByPartRefAndPose_KitDesign)
VALUES(679, 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Medium_top_cover', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(680, 'bottom_cover_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(680, 'bottom_cover_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(680, 'bottom_cover_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('look-for-endEffector-in-endEffectorHolder-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(681, 'look-for-endEffector-in-endEffectorHolder-effect');

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(682, 'big_gear_tray_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-physicalLocation-refObject-endEffector-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(683, 'kitTray-has-physicalLocation-refObject-endEffector-param2', 2, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('sku_part_medium_gear');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_ExternalShape, hasStockKeepingUnit_InternalShape)
VALUES(684, 'sku_part_medium_gear', 'SKU for medium gear', 0.150000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-has-physicalLocation-refObject-endEffector-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(685, 'kitTray-has-physicalLocation-refObject-endEffector-param1', 1, 'KitTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_big_gear');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(686, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_big_gear', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(687, 'changing_station_base_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-slot-in-kit-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(688, 'look-for-slot-in-kit-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_medium_gear_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(689, 'kit_gearbox_1Top1Bottom1Medium_medium_gear_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('take-kitTray-Decrease');

INSERT INTO FunctionOperation
(FunctionOperationID, _NAME, hasFunctionOperation_Value, hasFunctionOperation_Function)
VALUES(690, 'take-kitTray-Decrease', 1, NULL);

INSERT INTO Decrease
(DecreaseID, _NAME, hadByDecrease_Effect)
VALUES(690, 'take-kitTray-Decrease', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_finger_1_XAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(691, 'bottom_cover_finger_1_XAxis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('take-kitTray-not-1');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(692, 'take-kitTray-not-1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('take-kitTray-not-2');

INSERT INTO NegativePredicate
(NegativePredicateID, _NAME, hadByNegativePredicate_Effect, hasNegativePredicate_PositivePredicate)
VALUES(693, 'take-kitTray-not-2', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_big_gear');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Sku, hadByPartRefAndPose_KitDesign)
VALUES(694, 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_big_gear', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('robot-has-endEffector-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(695, 'robot-has-endEffector-param2', 2, 'EndEffector', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('robot-has-endEffector-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(696, 'robot-has-endEffector-param1', 1, 'Robot', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation, hadByObject_KittingWorkstation)
VALUES('finished_kit_receiver', NULL, NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(25, 'finished_kit_receiver');

INSERT INTO LargeBoxWithKits
(LargeBoxWithKitsID, _NAME, hasLargeBoxWithKits_Capacity, hasLargeBoxWithKits_LargeContainer, hasLargeBoxWithKits_KitDesign)
VALUES(25, 'finished_kit_receiver', 12, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_finger_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(697, 'small_gear_finger_2_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part-has-physicalLocation-refObject-partsTray');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(698, 'part-has-physicalLocation-refObject-partsTray', 'Part is in PartsTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kitTray-is-found');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(699, 'kitTray-is-found', ' KitTray is found by the sensor system', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('create-kit-precondition');

INSERT INTO Precondition
(PreconditionID, _NAME)
VALUES(700, 'create-kit-precondition');

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(701, 'finished_kit_box_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robotiq_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(702, 'robotiq_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(702, 'robotiq_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(702, 'robotiq_gripper_holder_pose');

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_top_cover_tray_ply');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(703, 'shape_gearbox_top_cover_tray_ply', 'ply file with shape of parts trays for top covers for a gearbox');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFileName, hasExternalShape_ModelFormatName)
VALUES(703, 'shape_gearbox_top_cover_tray_ply', '/usr/local/iora/ply/top_cover_tray.ply', 'PLY');

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(704, 'empty_kit_tray_box_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_medium_gear');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(705, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_medium_gear', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Medium_medium_gear_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(706, 'kit_gearbox_1Top1Bottom1Medium_medium_gear_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_gearbox_bottom_cover_tray_ply');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(707, 'shape_gearbox_bottom_cover_tray_ply', 'ply file with shape of parts trays for bottom covers for a gearbox');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFileName, hasExternalShape_ModelFormatName)
VALUES(707, 'shape_gearbox_bottom_cover_tray_ply', '/usr/local/iora/ply/bottom_cover_tray.ply', 'PLY');

INSERT INTO DataThing
(_NAME)
VALUES('take-kitTray-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(708, 'take-kitTray-effect');

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-param-4');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(709, 'place-kit-param-4', 'LargeBoxWithKitsSlot', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('robotiq_gripper_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(710, 'robotiq_gripper_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(710, 'robotiq_gripper_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(710, 'robotiq_gripper_pose');

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(711, 'place-kit-param-3', 'EndEffector', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-param-5');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(712, 'place-kit-param-5', 'LargeBoxWithKits', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('set-grasp-param-3');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(713, 'set-grasp-param-3', 'StockKeepingUnit', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_tray_relative_location_in');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefData, hadBySecondaryLocation_SolidObject)
VALUES(714, 'small_gear_tray_relative_location_in', NULL, NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(714, 'small_gear_tray_relative_location_in', 'Relative location of small_gear_tray in a WorkTableArea');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(714, 'small_gear_tray_relative_location_in');

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-physicalLocation-refObject-workTable-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(715, 'kit-has-physicalLocation-refObject-workTable-param2', 2, 'WorkTable', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_partstray_area');

INSERT INTO WorkTableArea
(WorkTableAreaID, _NAME, hasWorkTableArea_Ymax, hasWorkTableArea_Ymin, hasWorkTableArea_Xmin, hasWorkTableArea_Xmax, hasWorkTableArea_SolidObject, hadByWorkTableArea_WorkTable, hasWorkTableArea_Sku)
VALUES(716, 'medium_gear_partstray_area', 400.000000, 0.000000, 605.000000, 1170.000000, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('set-grasp-param-4');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(717, 'set-grasp-param-4', 'EndEffector', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit-has-physicalLocation-refObject-workTable-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(718, 'kit-has-physicalLocation-refObject-workTable-param1', 1, 'Kit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(719, 'top_cover_tray_point', 12.700000, 900.000000, 214.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_big_gear_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(720, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_big_gear_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('big_gear_finger_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(721, 'big_gear_finger_1_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(721, 'big_gear_finger_1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(721, 'big_gear_finger_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('slot-can-contain-part-sku-param2');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(722, 'slot-can-contain-part-sku-param2', 2, 'StockKeepingUnit', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('KitTray-WorkTable-SR-UnderWithContact');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(723, 'KitTray-WorkTable-SR-UnderWithContact', 'KitTray', 'WorkTable', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('slot-can-contain-part-sku-param1');

INSERT INTO PredicateParameter
(PredicateParameterID, _NAME, hasPredicateParameter_ParameterPosition, hasPredicateParameter_Parameter, hadByPredicateParameter_PositivePredicate)
VALUES(724, 'slot-can-contain-part-sku-param1', 1, 'Slot', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(725, 'place-kit-param-2', 'Kit', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kit-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(726, 'place-kit-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('bottom_cover_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(727, 'bottom_cover_1_z_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('set-grasp-param-2');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(728, 'set-grasp-param-2', 'Part', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('medium_gear_finger_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(729, 'medium_gear_finger_3_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(729, 'medium_gear_finger_3_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(729, 'medium_gear_finger_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('set-grasp-param-1');

INSERT INTO ActionParameterSet
(ActionParameterSetID, _NAME, hasActionParameterSet_ActionParameter, hasActionParameterSet_ActionParameterPosition, hadByActionParameterSet_ActionBase)
VALUES(730, 'set-grasp-param-1', 'Robot', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('largeBoxWithKitsSlot-is-found');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(731, 'largeBoxWithKitsSlot-is-found', 'LargeBoxWithKitsSlot is found by the sensor system', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_finger_2_ZAxis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(732, 'small_gear_finger_2_ZAxis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part-endEffector-SR-PartiallyIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PredicateStateRelationOr)
VALUES(733, 'part-endEffector-SR-PartiallyIn', 'Part', 'EndEffector', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ContainedIn');

INSERT INTO IntermediateStateRelation
(IntermediateStateRelationID, _NAME, hasIntermediateStateRelation_RCC8StateRelation, hadByIntermediateStateRelation_SOAP)
VALUES(734, 'ContainedIn', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('place-kitTray-effect');

INSERT INTO Effect
(EffectID, _NAME)
VALUES(735, 'place-kitTray-effect');

INSERT INTO DataThing
(_NAME)
VALUES('point_max');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(736, 'point_max', 2000.000000, 1800.000000, 1800.000000);

INSERT INTO DataThing
(_NAME)
VALUES('small_gear_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_Z, hasPoint_X, hasPoint_Y)
VALUES(737, 'small_gear_1_point', 0.000000, -110.000000, 21.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Small1Medium_small_gear_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_I, hasVector_J, hasVector_K)
VALUES(738, 'kit_gearbox_1Small1Medium_small_gear_x_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('top_cover_finger_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME)
VALUES(739, 'top_cover_finger_1_pose');

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(739, 'top_cover_finger_1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(739, 'top_cover_finger_1_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation, hadByObjectOnTable_WorkTable)
VALUES('small_gear_tray', NULL, NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(26, 'small_gear_tray', NULL);

INSERT INTO PartsVessel
(PartsVesselID, _NAME, hasPartsVessel_PartQuantity, hasPartsVessel_SerialNumber, hasPartsVessel_PartSku)
VALUES(26, 'small_gear_tray', 1, 15, NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME)
VALUES(26, 'small_gear_tray');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('robotiq_gripper_holder', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME, hasNoSkuObject_InternalShape)
VALUES(27, 'robotiq_gripper_holder', NULL);

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_EndEffectorChangingStation)
VALUES(27, 'robotiq_gripper_holder', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit-is-found');

INSERT INTO PositivePredicate
(PositivePredicateID, _NAME, hasPositivePredicate_Description, hadByPositivePredicate_Domain)
VALUES(740, 'kit-is-found', ' Kit is found by the sensor system', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('Part-PartsTray-SR-ContainedIn');

INSERT INTO PredicateStateRelation
(PredicateStateRelationID, _NAME, hasPredicateStateRelation_ReferenceParameter, hasPredicateStateRelation_TargetParameter, hasPredicateStateRelation_IntermediateStateRelation, hadByPredicateStateRelation_PositivePredicate)
VALUES(741, 'Part-PartsTray-SR-ContainedIn', 'Part', 'PartsTray', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_top_cover');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(742, 'kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_top_cover', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('look-for-kitTray');

INSERT INTO ActionBase
(ActionBaseID, _NAME, hasActionBase_Description, hasActionBase_Effect, hasActionBase_Precondition, hadByAction_Domain)
VALUES(743, 'look-for-kitTray', 'Look for a KitTray before picking one', NULL, NULL, NULL);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(44, 462);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(44, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(44, 586);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(44, 275);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(44, 565);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(44, 629);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(44, 271);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(44, 477);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(109, 674);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(109, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(109, 302);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(109, 731);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(109, 629);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(199, 586);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(199, 471);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(199, 160);

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'EndEffector');

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'EndEffectorHolder');

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'Kit');

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'KitTray');

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'LargeBoxWithEmptyKitTrays');

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'LargeBoxWithKits');

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'LargeBoxWithKitsSlot');

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'Part');

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'PartsTray');

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'Robot');

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'Slot');

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'StockKeepingUnit');

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'WorkTable');

INSERT INTO hasDomain_VariableValue
(DomainID, hasDomain_Variable)
VALUES(207, 'WorkTableArea');

INSERT INTO hasDomain_RequirementValue
(DomainID, hasDomain_Requirement)
VALUES(207, 'action-costs');

INSERT INTO hasDomain_RequirementValue
(DomainID, hasDomain_Requirement)
VALUES(207, 'derived-predicates');

INSERT INTO hasDomain_RequirementValue
(DomainID, hasDomain_Requirement)
VALUES(207, 'equality');

INSERT INTO hasDomain_RequirementValue
(DomainID, hasDomain_Requirement)
VALUES(207, 'fluents');

INSERT INTO hasDomain_RequirementValue
(DomainID, hasDomain_Requirement)
VALUES(207, 'strips');

INSERT INTO hasDomain_RequirementValue
(DomainID, hasDomain_Requirement)
VALUES(207, 'typing');

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(210, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(210, 565);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(210, 294);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(211, 294);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(219, 367);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(219, 457);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(219, 37);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(219, 423);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(250, 452);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(314, 158);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(314, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(314, 286);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(314, 629);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(314, 452);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(369, 324);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(381, 377);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(381, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(381, 464);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(381, 510);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(381, 628);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(381, 629);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(399, 377);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(399, 338);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(399, 448);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(414, 377);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(414, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(414, 494);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(414, 568);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(414, 586);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(414, 698);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(414, 565);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(414, 294);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(414, 624);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(414, 629);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(465, 377);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(465, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(465, 494);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(465, 586);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(465, 565);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(465, 629);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(472, 568);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(480, 367);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(480, 37);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(480, 423);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(481, 740);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(482, 462);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(482, 275);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(518, 377);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(518, 373);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(518, 539);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(518, 629);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(525, 377);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(525, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(525, 580);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(525, 539);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(525, 629);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(537, 158);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(537, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(537, 286);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(537, 628);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(537, 629);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(537, 260);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(537, 81);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(537, 138);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(541, 377);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(541, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(541, 464);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(541, 586);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(541, 671);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(541, 740);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(541, 628);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(541, 629);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(553, 377);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(553, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(553, 580);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(553, 324);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(553, 539);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(553, 629);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(564, 377);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(564, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(564, 464);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(564, 586);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(564, 671);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(564, 628);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(564, 629);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(599, 377);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(599, 293);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(605, 674);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(605, 302);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(618, 731);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(626, 367);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(626, 37);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(626, 423);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(642, 699);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(647, 271);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(661, 674);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(661, 586);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(661, 302);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(661, 336);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(661, 300);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(661, 629);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(678, 377);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(678, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(678, 464);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(678, 510);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(678, 628);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(678, 629);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(681, 457);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(688, 462);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(688, 373);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(688, 586);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(688, 1);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(688, 565);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(688, 629);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(688, 8);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(688, 477);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(700, 671);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(700, 4);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(700, 453);

INSERT INTO hasPrecondition_PositivePredicate
(PreconditionID, PositivePredicateID)
VALUES(700, 236);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(708, 158);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(708, 286);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(735, 377);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(735, 453);

INSERT INTO hasEffect_PositivePredicate
(EffectID, PositivePredicateID)
VALUES(735, 236);



UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'kit-has-slot';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'kitTray-has-physicalLocation-refObject-kit';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='part-is-found' WHERE _NAME = 'part-is-found-param1';

UPDATE ActionBase
 SET  hasActionBase_Effect='look-for-endEffector-in-endEffectorHolder-effect', hasActionBase_Precondition= 'look-for-endEffector-in-endEffectorHolder-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'look-for-endEffector';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'slot-can-contain-part-sku';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='quantity-of-kits-in-lbwk' WHERE _NAME = 'place-kit-Increase-1';

UPDATE Increase
 SET  hadByIncrease_Effect='place-kit-effect' WHERE _NAME = 'place-kit-Increase-1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kit-has-kitTray' WHERE _NAME = 'kit-has-kitTray-param1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kit-has-kitTray' WHERE _NAME = 'kit-has-kitTray-param2';

UPDATE Slot
 SET  hadBySlot_Kit='kit_gearbox_1Top1Bottom1Medium', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Medium_bottom_cover' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Medium_slot_bottom_cover';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kit_gearbox_1Small1Medium' WHERE _NAME = 'kit_gearbox_1Small1Medium_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='kit_gearbox_tray_1Small1Medium_x_axis', hasPoseLocation_ZAxis= 'kit_gearbox_tray_1Small1Medium_z_axis', hasPoseLocation_Point= 'kit_gearbox_tray_1Small1Medium_point' WHERE _NAME = 'kit_gearbox_1Small1Medium_tray_pose';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='UnderWithContact', hadByPredicateStateRelation_PositivePredicate= 'workTable-has-objectOnTable-kitTray' WHERE _NAME = 'WorkTable-KitTray-SR-UnderWithContact';

UPDATE FunctionToFunctionCondition
 SET  hasFunctionToFunctionCondition_F2='capacity-of-kits-in-lbwk', hasFunctionToFunctionCondition_F1= 'quantity-of-kits-in-lbwk' WHERE _NAME = 'look-for-slot-in-lbwk-FunctionToFunctionLess';

UPDATE FunctionToFunctionLess
 SET  hadByFunctionToFunctionLess_Precondition='look-for-slot-in-lbwk-precondition' WHERE _NAME = 'look-for-slot-in-lbwk-FunctionToFunctionLess';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-slot-in-lbwk' WHERE _NAME = 'look-for-slot-in-lbwk-param-1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-slot-in-lbwk' WHERE _NAME = 'look-for-slot-in-lbwk-param-4';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-slot-in-lbwk' WHERE _NAME = 'look-for-slot-in-lbwk-param-5';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='PartiallyIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'LargeBoxWithKits-Kit-SR' WHERE _NAME = 'LargeBoxWithKits-Kit-SR-PartiallyIn';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-slot-in-lbwk' WHERE _NAME = 'look-for-slot-in-lbwk-param-2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-slot-in-lbwk' WHERE _NAME = 'look-for-slot-in-lbwk-param-3';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='kitTray-found-flag' WHERE _NAME = 'place-kitTray-Decrease-1';

UPDATE Decrease
 SET  hadByDecrease_Effect='place-kitTray-effect' WHERE _NAME = 'place-kitTray-Decrease-1';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='endEffectorHolder-found-flag' WHERE _NAME = 'place-kitTray-Decrease-2';

UPDATE Decrease
 SET  hadByDecrease_Effect='place-kitTray-effect' WHERE _NAME = 'place-kitTray-Decrease-2';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='ContainedIn', hadByPredicateStateRelation_PositivePredicate= 'endEffectorHolder-has-endEffector' WHERE _NAME = 'EndEffector-EndEffectorHolder-SR-ContainedIn';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kit_gearbox_1Top1Bottom1Small1Medium1Big' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='kit_gearbox_tray_x_axis', hasPoseLocation_ZAxis= 'kit_gearbox_tray_z_axis', hasPoseLocation_Point= 'kit_gearbox_tray_point' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big_tray_pose';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='ContainedIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'part-endEffector-SR' WHERE _NAME = 'part-endEffector-SR-ContainedIn';

UPDATE ActionBase
 SET  hasActionBase_Effect='look-for-part-effect', hasActionBase_Precondition= 'look-for-part-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'look-for-part';

UPDATE Slot
 SET  hadBySlot_Kit='kit_gearbox_1Top1Bottom1Small1Medium1Big', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_small_gear' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_small_gear';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefData='kit_gearbox_1Top1Bottom1Medium_tray_area', hadBySecondaryLocation_SolidObject= 'kit_gearbox_1Top1Bottom1Medium_tray' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Medium_tray_relative_location_in';

UPDATE ActionBase
 SET  hasActionBase_Effect='look-for-slot-in-lbwk-effect', hasActionBase_Precondition= 'look-for-slot-in-lbwk-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'look-for-slot-in-lbwk';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='big_gear_tray_pose_location_on', hadByObjectOnTable_WorkTable= 'work_table_1' WHERE _NAME = 'big_gear_tray';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_partstray_big_gear_tray' WHERE _NAME = 'big_gear_tray';

UPDATE PartsVessel
 SET  hasPartsVessel_PartSku='sku_part_big_gear' WHERE _NAME = 'big_gear_tray';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'endEffectorHolder-has-endEffector';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-has-heldObject-kitTray' WHERE _NAME = 'endEffector-has-heldObject-kitTray-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='part-has-physicalLocation-refObject-kit' WHERE _NAME = 'part-has-physicalLocation-refObject-kit-param1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='part-has-physicalLocation-refObject-kit' WHERE _NAME = 'part-has-physicalLocation-refObject-kit-param2';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'capacity-of-parts-in-kit';

UPDATE FunctionToNumberCondition
 SET  hasFunctionToNumberCondition_Function='grasp-set-flag' WHERE _NAME = 'set-grasp-F2NLess';

UPDATE FunctionToNumberLess
 SET  hadByFunctionToNumberLess_Precondition='set-grasp-precondition' WHERE _NAME = 'set-grasp-F2NLess';

UPDATE Slot
 SET  hadBySlot_Kit='kit_gearbox_1Top1Bottom1Medium', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Medium_top_cover' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Medium_slot_top_cover';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-has-heldObject-kitTray' WHERE _NAME = 'endEffector-has-heldObject-kitTray-param1';

UPDATE EndEffectorGrasp
 SET  hadByEffectorAndGrasp_StockKeepingUnit='sku_partstray_big_gear_tray' WHERE _NAME = 'ThreeFingerGrasp13';

UPDATE ThreeFingerGrasp
 SET  hasThreeFingerGrasp_ThreeFingerGripper='robotiq_gripper' WHERE _NAME = 'ThreeFingerGrasp13';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='largeBoxWithKitsSlot-is-found' WHERE _NAME = 'largeBoxWithKitsSlot-is-found-param1';

UPDATE IntermediateStateRelation
 SET  hasIntermediateStateRelation_RCC8StateRelation='RCC8-Under', hadByIntermediateStateRelation_SOAP= 'soap' WHERE _NAME = 'Under';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='grasp-set-flag' WHERE _NAME = 'set-grasp-Increase-1';

UPDATE Increase
 SET  hadByIncrease_Effect='set-grasp-effect' WHERE _NAME = 'set-grasp-Increase-1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-has-no-heldObject' WHERE _NAME = 'endEffector-has-no-heldObject-param1';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='place-kitTray-effect', hasNegativePredicate_PositivePredicate= 'kitTray-is-found' WHERE _NAME = 'place-kitTray-not-2';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='place-kitTray-effect', hasNegativePredicate_PositivePredicate= 'workTableArea-is-not-occupied' WHERE _NAME = 'place-kitTray-not-1';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='NotUnderWithContact', hadByPredicateStateRelation_PredicateStateRelationOr= 'EndEffector-SolidObject-SR' WHERE _NAME = 'EndEffector-SolidObject-SR-NotUnderWithContact';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_InternalShape= 'shape_kit_box' WHERE _NAME = 'sku_kit_box';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='place-kitTray-effect', hasNegativePredicate_PositivePredicate= 'endEffector-has-heldObject-kitTray' WHERE _NAME = 'place-kitTray-not-4';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='place-kitTray-effect', hasNegativePredicate_PositivePredicate= 'kitTray-has-physicalLocation-refObject-endEffector' WHERE _NAME = 'place-kitTray-not-3';

UPDATE EndEffectorGrasp
 SET  hadByEffectorAndGrasp_StockKeepingUnit='sku_partstray_bottom_cover' WHERE _NAME = 'ThreeFingerGrasp10';

UPDATE ThreeFingerGrasp
 SET  hasThreeFingerGrasp_ThreeFingerGripper='robotiq_gripper' WHERE _NAME = 'ThreeFingerGrasp10';

UPDATE EndEffectorGrasp
 SET  hadByEffectorAndGrasp_StockKeepingUnit='sku_partstray_small_gear_tray' WHERE _NAME = 'ThreeFingerGrasp11';

UPDATE ThreeFingerGrasp
 SET  hasThreeFingerGrasp_ThreeFingerGripper='robotiq_gripper' WHERE _NAME = 'ThreeFingerGrasp11';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'final-quantity-of-parts-in-kit';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-part' WHERE _NAME = 'take-part-param-1';

UPDATE EndEffectorGrasp
 SET  hadByEffectorAndGrasp_StockKeepingUnit='sku_partstray_medium_gear_tray' WHERE _NAME = 'ThreeFingerGrasp12';

UPDATE ThreeFingerGrasp
 SET  hasThreeFingerGrasp_ThreeFingerGripper='robotiq_gripper' WHERE _NAME = 'ThreeFingerGrasp12';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-part' WHERE _NAME = 'take-part-param-4';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='part-has-physicalLocation-refObject-endEffector' WHERE _NAME = 'part-has-physicalLocation-refObject-endEffector-param2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-part' WHERE _NAME = 'take-part-param-5';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-part' WHERE _NAME = 'take-part-param-2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-part' WHERE _NAME = 'take-part-param-3';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='part-has-physicalLocation-refObject-endEffector' WHERE _NAME = 'part-has-physicalLocation-refObject-endEffector-param1';

UPDATE FunctionToNumberCondition
 SET  hasFunctionToNumberCondition_Function='part-found-flag' WHERE _NAME = 'look-for-part-F2NLess';

UPDATE FunctionToNumberLess
 SET  hadByFunctionToNumberLess_Precondition='look-for-part-precondition' WHERE _NAME = 'look-for-part-F2NLess';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-part' WHERE _NAME = 'take-part-param-6';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_ExternalShape= 'kit_gearbox_1Top1Bottom1Small1Medium1Big_shape_ply', hasStockKeepingUnit_InternalShape= 'shape_1Top1Bottom1Small1Medium1Big_kit_tray' WHERE _NAME = 'sku_gearbox_1Top1Bottom1Small1Medium1Big_tray';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_ExternalShape= 'shape_gearbox_bottom_cover_tray_ply', hasStockKeepingUnit_InternalShape= 'shape_bottom_cover_tray' WHERE _NAME = 'sku_partstray_bottom_cover';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'workTableArea-is-for-sku';

UPDATE EndEffectorGrasp
 SET  hadByEffectorAndGrasp_StockKeepingUnit='sku_gearbox_1Top1Bottom1Small1Medium1Big_tray' WHERE _NAME = 'ThreeFingerGrasp1';

UPDATE ThreeFingerGrasp
 SET  hasThreeFingerGrasp_ThreeFingerGripper='robotiq_gripper' WHERE _NAME = 'ThreeFingerGrasp1';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='ContainedIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'Part-Kit-SR' WHERE _NAME = 'Part-Kit-SR-ContainedIn';

UPDATE EndEffectorGrasp
 SET  hadByEffectorAndGrasp_StockKeepingUnit='sku_gearbox_1Small1Medium_tray' WHERE _NAME = 'ThreeFingerGrasp6';

UPDATE ThreeFingerGrasp
 SET  hasThreeFingerGrasp_ThreeFingerGripper='robotiq_gripper' WHERE _NAME = 'ThreeFingerGrasp6';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='place-part-effect', hasNegativePredicate_PositivePredicate= 'slot-is-not-occupied' WHERE _NAME = 'place-part-not-3';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefData='bottom_cover_partstray_area', hadBySecondaryLocation_SolidObject= 'bottom_cover_tray' WHERE _NAME = 'bottom_cover_tray_relative_location_in';

UPDATE EndEffectorGrasp
 SET  hadByEffectorAndGrasp_StockKeepingUnit='sku_part_small_gear' WHERE _NAME = 'ThreeFingerGrasp7';

UPDATE ThreeFingerGrasp
 SET  hasThreeFingerGrasp_GraspPose3='small_gear_finger_3_pose', hasThreeFingerGrasp_GraspPose2= 'small_gear_finger_2_pose', hasThreeFingerGrasp_GraspPose1= 'small_gear_finger_1_pose', hasThreeFingerGrasp_ThreeFingerGripper= 'robotiq_gripper' WHERE _NAME = 'ThreeFingerGrasp7';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='place-part-effect', hasNegativePredicate_PositivePredicate= 'part-has-physicalLocation-refObject-endEffector' WHERE _NAME = 'place-part-not-2';

UPDATE EndEffectorGrasp
 SET  hadByEffectorAndGrasp_StockKeepingUnit='sku_gearbox_1Top1Bottom1Medium_tray' WHERE _NAME = 'ThreeFingerGrasp8';

UPDATE ThreeFingerGrasp
 SET  hasThreeFingerGrasp_ThreeFingerGripper='robotiq_gripper' WHERE _NAME = 'ThreeFingerGrasp8';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='place-part-effect', hasNegativePredicate_PositivePredicate= 'endEffector-has-heldObject-part' WHERE _NAME = 'place-part-not-1';

UPDATE EndEffectorGrasp
 SET  hadByEffectorAndGrasp_StockKeepingUnit='sku_partstray_top_cover' WHERE _NAME = 'ThreeFingerGrasp9';

UPDATE ThreeFingerGrasp
 SET  hasThreeFingerGrasp_ThreeFingerGripper='robotiq_gripper' WHERE _NAME = 'ThreeFingerGrasp9';

UPDATE EndEffectorGrasp
 SET  hadByEffectorAndGrasp_StockKeepingUnit='sku_part_top_cover' WHERE _NAME = 'ThreeFingerGrasp2';

UPDATE ThreeFingerGrasp
 SET  hasThreeFingerGrasp_GraspPose3='top_cover_finger_3_pose', hasThreeFingerGrasp_GraspPose2= 'top_cover_finger_2_pose', hasThreeFingerGrasp_GraspPose1= 'top_cover_finger_1_pose', hasThreeFingerGrasp_ThreeFingerGripper= 'robotiq_gripper' WHERE _NAME = 'ThreeFingerGrasp2';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='top_cover_finger_2_XAxis', hasPoseLocation_ZAxis= 'top_cover_finger_2_ZAxis', hasPoseLocation_Point= 'top_cover_finger_2_point' WHERE _NAME = 'top_cover_finger_2_pose';

UPDATE EndEffectorGrasp
 SET  hadByEffectorAndGrasp_StockKeepingUnit='sku_part_bottom_cover' WHERE _NAME = 'ThreeFingerGrasp3';

UPDATE ThreeFingerGrasp
 SET  hasThreeFingerGrasp_GraspPose3='bottom_cover_finger_3_pose', hasThreeFingerGrasp_GraspPose2= 'bottom_cover_finger_2_pose', hasThreeFingerGrasp_GraspPose1= 'bottom_cover_finger_1_pose', hasThreeFingerGrasp_ThreeFingerGripper= 'robotiq_gripper' WHERE _NAME = 'ThreeFingerGrasp3';

UPDATE IntermediateStateRelation
 SET  hasIntermediateStateRelation_RCC8StateRelation='RCC8-NotContainedIn', hadByIntermediateStateRelation_SOAP= 'soap' WHERE _NAME = 'NotContainedIn';

UPDATE EndEffectorGrasp
 SET  hadByEffectorAndGrasp_StockKeepingUnit='sku_part_big_gear' WHERE _NAME = 'ThreeFingerGrasp4';

UPDATE ThreeFingerGrasp
 SET  hasThreeFingerGrasp_GraspPose3='big_gear_finger_3_pose', hasThreeFingerGrasp_GraspPose2= 'big_gear_finger_2_pose', hasThreeFingerGrasp_GraspPose1= 'big_gear_finger_1_pose', hasThreeFingerGrasp_ThreeFingerGripper= 'robotiq_gripper' WHERE _NAME = 'ThreeFingerGrasp4';

UPDATE EndEffectorGrasp
 SET  hadByEffectorAndGrasp_StockKeepingUnit='sku_part_medium_gear' WHERE _NAME = 'ThreeFingerGrasp5';

UPDATE ThreeFingerGrasp
 SET  hasThreeFingerGrasp_GraspPose3='medium_gear_finger_3_pose', hasThreeFingerGrasp_GraspPose2= 'medium_gear_finger_2_pose', hasThreeFingerGrasp_GraspPose1= 'medium_gear_finger_1_pose', hasThreeFingerGrasp_ThreeFingerGripper= 'robotiq_gripper' WHERE _NAME = 'ThreeFingerGrasp5';

UPDATE FunctionToFunctionCondition
 SET  hasFunctionToFunctionCondition_F2='capacity-of-kits-in-lbwk', hasFunctionToFunctionCondition_F1= 'quantity-of-kits-in-lbwk' WHERE _NAME = 'place-kit-F2FLess';

UPDATE FunctionToFunctionLess
 SET  hadByFunctionToFunctionLess_Precondition='place-kit-precondition' WHERE _NAME = 'place-kit-F2FLess';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='workTable-has-objectOnTable-kit' WHERE _NAME = 'workTable-has-objectOnTable-kit-param1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='workTable-has-objectOnTable-kit' WHERE _NAME = 'workTable-has-objectOnTable-kit-param2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='changing_station_pose' WHERE _NAME = 'changing_station_1';

UPDATE EndEffectorChangingStation
 SET  hasEndEffectorChangingStation_Base='changing_station_base' WHERE _NAME = 'changing_station_1';

UPDATE FunctionToNumberCondition
 SET  hasFunctionToNumberCondition_Function='endEffectorHolder-found-flag' WHERE _NAME = 'look-for-endEffectorHolder-F2NLess';

UPDATE FunctionToNumberLess
 SET  hadByFunctionToNumberLess_Precondition='look-for-endEffectorHolder-precondition' WHERE _NAME = 'look-for-endEffectorHolder-F2NLess';

UPDATE ActionBase
 SET  hasActionBase_Effect='place-part-effect', hasActionBase_Precondition= 'place-part-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'place-part';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-kitTray' WHERE _NAME = 'take-kitTray-param-5';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-kitTray' WHERE _NAME = 'take-kitTray-param-1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-kitTray' WHERE _NAME = 'take-kitTray-param-2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-kitTray' WHERE _NAME = 'take-kitTray-param-3';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-kitTray' WHERE _NAME = 'take-kitTray-param-4';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Point='kit_gearbox_1Small1Medium_small_gear_point', hasPartRefAndPose_XAxis= 'kit_gearbox_1Small1Medium_small_gear_x_axis', hasPartRefAndPose_ZAxis= 'kit_gearbox_1Small1Medium_small_gear_z_axis', hasPartRefAndPose_Sku= 'sku_part_small_gear', hadByPartRefAndPose_KitDesign= 'kit_design_gearbox_1Small1Medium' WHERE _NAME = 'part_ref_and_pose_kit_gearbox_1Small1Medium_small_gear';

UPDATE FunctionParameter
 SET  hadByFunctionParameter_Function='quantity-of-parts-in-kit' WHERE _NAME = 'quantity-of-parts-in-kit-param1';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='place-kit-effect', hasNegativePredicate_PositivePredicate= 'kit-has-physicalLocation-refObject-endEffector' WHERE _NAME = 'place-kit-not-5';

UPDATE FunctionParameter
 SET  hadByFunctionParameter_Function='quantity-of-parts-in-kit' WHERE _NAME = 'quantity-of-parts-in-kit-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kitTray-has-physicalLocation-refObject-workTable' WHERE _NAME = 'kitTray-has-physicalLocation-refObject-workTable-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kitTray-has-physicalLocation-refObject-workTable' WHERE _NAME = 'kitTray-has-physicalLocation-refObject-workTable-param1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='part-has-physicalLocation-refObject-partsTray' WHERE _NAME = 'part-has-physicalLocation-refObject-partsTray-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='part-has-physicalLocation-refObject-partsTray' WHERE _NAME = 'part-has-physicalLocation-refObject-partsTray-param1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-kitTray' WHERE _NAME = 'look-for-kitTray-param-5';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_gearbox_1Top1Bottom1Small1Medium1Big_pose', hadByObjectOnTable_WorkTable= 'work_table_1' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big';

UPDATE Kit
 SET  hasKit_Design='kit_design_gearbox_1Top1Bottom1Small1Medium1Big', hasKit_KitTray= 'kit_gearbox_1Top1Bottom1Small1Medium1Big_tray' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-kitTray' WHERE _NAME = 'look-for-kitTray-param-2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-kitTray' WHERE _NAME = 'look-for-kitTray-param-1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-kitTray' WHERE _NAME = 'look-for-kitTray-param-4';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-kitTray' WHERE _NAME = 'look-for-kitTray-param-3';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefData='kit_gearbox_1Small1Medium_tray_area', hadBySecondaryLocation_SolidObject= 'kit_gearbox_1Small1Medium_tray' WHERE _NAME = 'kit_gearbox_1Small1Medium_tray_relative_location_in';

UPDATE IntermediateStateRelation
 SET  hasIntermediateStateRelation_RCC8StateRelation='RCC8-NotOnTopWithContact', hadByIntermediateStateRelation_SOAP= 'soap' WHERE _NAME = 'NotOnTopWithContact';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'workTableArea-is-not-occupied';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_ExternalShape= 'shape_gearbox_big_gear_ply', hasStockKeepingUnit_InternalShape= 'shape_gearbox_big_gear' WHERE _NAME = 'sku_part_big_gear';

UPDATE KitDesign
 SET  hadByKitDesign_KittingWorkstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'sku_gearbox_1Top1Bottom1Medium_tray' WHERE _NAME = 'kit_design_gearbox_1Top1Bottom1Medium';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='ContainedIn', hadByPredicateStateRelation_PositivePredicate= 'kitTray-has-physicalLocation-refObject-lbwekt' WHERE _NAME = 'KitTray-LargeBoxWithEmptyKitTrays-SR-ContainedIn';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='NotContainedIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'EndEffector-SolidObject-SR' WHERE _NAME = 'EndEffector-SolidObject-SR-NotContainedIn';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='create-kit-effect', hasNegativePredicate_PositivePredicate= 'workTable-has-objectOnTable-kitTray' WHERE _NAME = 'create-kit-not-1';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='create-kit-effect', hasNegativePredicate_PositivePredicate= 'kitTray-has-physicalLocation-refObject-workTable' WHERE _NAME = 'create-kit-not-2';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='NotUnderWithContact', hadByPredicateStateRelation_PositivePredicate= 'endEffector-has-heldObject-part' WHERE _NAME = 'EndEffector-Part-SR-NotUnderWithContact';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='take-part-effect', hasNegativePredicate_PositivePredicate= 'endEffector-has-no-heldObject' WHERE _NAME = 'take-part-effect-not-1';

UPDATE ActionBase
 SET  hasActionBase_Effect='look-for-kit-effect', hasActionBase_Precondition= 'look-for-kit-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'look-for-kit';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='take-part-effect', hasNegativePredicate_PositivePredicate= 'part-has-physicalLocation-refObject-partsTray' WHERE _NAME = 'take-part-effect-not-2';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Point='kit_gearbox_1Top1Bottom1Small1Medium1Big_top_cover_point', hasPartRefAndPose_XAxis= 'kit_gearbox_1Top1Bottom1Small1Medium1Big_top_cover_x_axis', hasPartRefAndPose_ZAxis= 'kit_gearbox_1Top1Bottom1Small1Medium1Big_top_cover_z_axis', hasPartRefAndPose_Sku= 'sku_part_top_cover', hadByPartRefAndPose_KitDesign= 'kit_design_gearbox_1Top1Bottom1Small1Medium1Big' WHERE _NAME = 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_top_cover';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='ContainedIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'EndEffector-EndEffectorHolder-SR' WHERE _NAME = 'EndEffector-EndEffectorHolder-ContainedIn';

UPDATE WorkTableArea
 SET  hasWorkTableArea_SolidObject='kit_gearbox_1Small1Medium_tray', hadByWorkTableArea_WorkTable= 'work_table_1', hasWorkTableArea_Sku= 'sku_gearbox_1Small1Medium_tray' WHERE _NAME = 'kit_gearbox_1Small1Medium_tray_area';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_ExternalShape= 'shape_gearbox_small_gear_ply', hasStockKeepingUnit_InternalShape= 'shape_gearbox_small_gear' WHERE _NAME = 'sku_part_small_gear';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'endEffector-has-heldObject-kitTray';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'medium_gear_tray_pose_location_on';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='medium_gear_tray_x_axis', hasPoseLocation_ZAxis= 'medium_gear_tray_z_axis', hasPoseLocation_Point= 'medium_gear_tray_point' WHERE _NAME = 'medium_gear_tray_pose_location_on';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'workTable-has-objectOnTable-kit';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='PartiallyIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'Part-Kit-SR' WHERE _NAME = 'Part-Kit-SR-PartiallyIn';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-has-physicalLocation-refObject-endEffectorHolder' WHERE _NAME = 'endEffector-has-physicalLocation-refObject-endEffectorHolder-param1';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='ContainedIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'Kit-LargeBoxWithKits-SR' WHERE _NAME = 'Kit-LargeBoxWithKits-SR-ContainedIn';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-has-physicalLocation-refObject-endEffectorHolder' WHERE _NAME = 'endEffector-has-physicalLocation-refObject-endEffectorHolder-param2';

UPDATE Slot
 SET  hadBySlot_Kit='kit_gearbox_1Top1Bottom1Medium', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Medium_medium_gear' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Medium_slot_medium_gear';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='bottom_cover_tray_pose_location_on', hadByObjectOnTable_WorkTable= 'work_table_1' WHERE _NAME = 'bottom_cover_tray';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_partstray_bottom_cover' WHERE _NAME = 'bottom_cover_tray';

UPDATE PartsVessel
 SET  hasPartsVessel_PartSku='sku_part_bottom_cover' WHERE _NAME = 'bottom_cover_tray';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='kit-found-flag' WHERE _NAME = 'look-for-kit-Increase-1';

UPDATE Increase
 SET  hadByIncrease_Effect='look-for-kit-effect' WHERE _NAME = 'look-for-kit-Increase-1';

UPDATE WorkTableArea
 SET  hasWorkTableArea_SolidObject='bottom_cover_tray', hadByWorkTableArea_WorkTable= 'work_table_1', hasWorkTableArea_Sku= 'sku_partstray_bottom_cover' WHERE _NAME = 'bottom_cover_partstray_area';

UPDATE FunctionToNumberCondition
 SET  hasFunctionToNumberCondition_Function='endEffector-found-flag' WHERE _NAME = 'look-for-endEffector-in-endEffectorHolder-F2N-Less';

UPDATE FunctionToNumberLess
 SET  hadByFunctionToNumberLess_Precondition='look-for-endEffector-in-endEffectorHolder-precondition' WHERE _NAME = 'look-for-endEffector-in-endEffectorHolder-F2N-Less';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='ContainedIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'EndEffector-Kit-SR' WHERE _NAME = 'EndEffector-Kit-SR-ContainedIn';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kit-has-physicalLocation-refObject-lbwk' WHERE _NAME = 'kit-has-physicalLocation-refObject-lbwk-param1';

UPDATE ActionBase
 SET  hasActionBase_Effect='look-for-endEffectorHolder-effect', hasActionBase_Precondition= 'look-for-endEffectorHolder-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'look-for-endEffectorHolder';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='PartiallyIn', hadByPredicateStateRelation_PositivePredicate= 'part-has-physicalLocation-refObject-partsTray' WHERE _NAME = 'Part-PartsTray-SR-PartiallyIn';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kit-has-physicalLocation-refObject-endEffector' WHERE _NAME = 'kit-has-physicalLocation-refObject-endEffector-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kit-has-physicalLocation-refObject-endEffector' WHERE _NAME = 'kit-has-physicalLocation-refObject-endEffector-param1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kit-has-physicalLocation-refObject-lbwk' WHERE _NAME = 'kit-has-physicalLocation-refObject-lbwk-param2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-part' WHERE _NAME = 'look-for-part-param-1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-part' WHERE _NAME = 'look-for-part-param-4';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-part' WHERE _NAME = 'look-for-part-param-5';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-part' WHERE _NAME = 'look-for-part-param-2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-part' WHERE _NAME = 'look-for-part-param-3';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='NotUnderWithContact', hadByPredicateStateRelation_PositivePredicate= 'part-has-physicalLocation-refObject-endEffector' WHERE _NAME = 'part-endEffector-SR-NotUnderWithContact';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_gearbox_1Top1Bottom1Small1Medium1Big_tray_pose' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big_tray';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_gearbox_1Top1Bottom1Small1Medium1Big_tray' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big_tray';

UPDATE ActionBase
 SET  hasActionBase_Effect='attach-endEffector-effect', hasActionBase_Precondition= 'attach-endEffector-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'attach-endEffector';

UPDATE SOAP
 SET  hasSOAP_Domain='kitting-domain', hasSOAP_KittingWorkstation= 'kitting_workstation_1' WHERE _NAME = 'soap';

UPDATE Slot
 SET  hadBySlot_Kit='kit_gearbox_1Small1Medium', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_gearbox_1Small1Medium_medium_gear' WHERE _NAME = 'kit_gearbox_1Small1Medium_slot_medium_gear';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='endEffectorHolder-found-flag' WHERE _NAME = 'look-for-endEffectorHolder-effect-Increase-1';

UPDATE Increase
 SET  hadByIncrease_Effect='look-for-endEffectorHolder-effect' WHERE _NAME = 'look-for-endEffectorHolder-effect-Increase-1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'big_gear_tray_pose_location_on';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='big_gear_tray_x_axis', hasPoseLocation_ZAxis= 'big_gear_tray_z_axis', hasPoseLocation_Point= 'big_gear_tray_point' WHERE _NAME = 'big_gear_tray_pose_location_on';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Medium_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='kit_gearbox_1Top1Bottom1Medium_x_axis', hasPoseLocation_ZAxis= 'kit_gearbox_1Top1Bottom1Medium_z_axis', hasPoseLocation_Point= 'kit_gearbox_1Top1Bottom1Medium_point' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Medium_pose';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='part-found-flag' WHERE _NAME = 'look-for-part-Increase-1';

UPDATE Increase
 SET  hadByIncrease_Effect='look-for-part-effect' WHERE _NAME = 'look-for-part-Increase-1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_gearbox_1Small1Medium_tray_pose' WHERE _NAME = 'kit_gearbox_1Small1Medium_tray';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_gearbox_1Small1Medium_tray' WHERE _NAME = 'kit_gearbox_1Small1Medium_tray';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='robot_pose' WHERE _NAME = 'robot_1';

UPDATE FunctionToNumberCondition
 SET  hasFunctionToNumberCondition_Function='kitTray-found-flag' WHERE _NAME = 'look-for-kitTray-F2NLess';

UPDATE FunctionToNumberLess
 SET  hadByFunctionToNumberLess_Precondition='look-for-kitTray-precondition' WHERE _NAME = 'look-for-kitTray-F2NLess';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'finished_kit_receiver_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='finished_kit_receiver_x_axis', hasPoseLocation_ZAxis= 'finished_kit_receiver_z_axis', hasPoseLocation_Point= 'finished_kit_receiver_point' WHERE _NAME = 'finished_kit_receiver_pose';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='workTable-has-objectOnTable-kitTray' WHERE _NAME = 'workTable-has-objectOnTable-kitTray-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='workTable-has-objectOnTable-kitTray' WHERE _NAME = 'workTable-has-objectOnTable-kitTray-param1';

UPDATE ActionBase
 SET  hasActionBase_Effect='look-for-workTableArea-effect', hasActionBase_Precondition= 'look-for-workTableArea-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'look-for-workTableArea';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='small_gear_1_pose' WHERE _NAME = 'small_gear_1';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_part_small_gear' WHERE _NAME = 'small_gear_1';

UPDATE Part
 SET  hadByPart_PartsVessel='small_gear_tray' WHERE _NAME = 'small_gear_1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-kit' WHERE _NAME = 'take-kit-param-1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-kit' WHERE _NAME = 'take-kit-param-2';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_ExternalShape= 'kit_gearbox_1Top1Bottom1Medium_shape_ply', hasStockKeepingUnit_InternalShape= 'shape_1Top1Bottom1Medium_kit_tray' WHERE _NAME = 'sku_gearbox_1Top1Bottom1Medium_tray';

UPDATE IntermediateStateRelation
 SET  hasIntermediateStateRelation_RCC8StateRelation='RCC8-OnTopWithContact', hadByIntermediateStateRelation_SOAP= 'soap' WHERE _NAME = 'OnTopWithContact';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-kit' WHERE _NAME = 'take-kit-param-5';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-kit' WHERE _NAME = 'take-kit-param-6';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-kit' WHERE _NAME = 'take-kit-param-3';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='take-kit' WHERE _NAME = 'take-kit-param-4';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'kitTray-found-flag';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_ExternalShape= 'shape_gearbox_big_gear_tray_ply', hasStockKeepingUnit_InternalShape= 'shape_big_gear_tray' WHERE _NAME = 'sku_partstray_big_gear_tray';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='grasp-is-set' WHERE _NAME = 'grasp-is-set-param1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='bottom_cover_1_pose' WHERE _NAME = 'bottom_cover_1';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_part_bottom_cover' WHERE _NAME = 'bottom_cover_1';

UPDATE Part
 SET  hadByPart_PartsVessel='bottom_cover_tray' WHERE _NAME = 'bottom_cover_1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kitTray-is-found' WHERE _NAME = 'kitTray-is-found-param1';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='NotUnderWithContact', hadByPredicateStateRelation_PositivePredicate= 'kit-has-physicalLocation-refObject-endEffector' WHERE _NAME = 'Kit-EndEffector-SR-NotUnderWithContact';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'workTable-has-objectOnTable-kitTray';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-part' WHERE _NAME = 'place-part-param-1';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'endEffectorHolder-found-flag';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-has-heldObject-kit' WHERE _NAME = 'endEffector-has-heldObject-kit-param1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-has-heldObject-kit' WHERE _NAME = 'endEffector-has-heldObject-kit-param2';

UPDATE ActionBase
 SET  hasActionBase_Effect='set-grasp-effect', hasActionBase_Precondition= 'set-grasp-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'set-grasp';

UPDATE FunctionToNumberCondition
 SET  hasFunctionToNumberCondition_Function='quantity-of-parts-in-partstray' WHERE _NAME = 'take-part-F2NGreater-1';

UPDATE FunctionToNumberGreater
 SET  hadByFunctionToNumberGreater_Precondition='take-part-precondition' WHERE _NAME = 'take-part-F2NGreater-1';

UPDATE FunctionToNumberCondition
 SET  hasFunctionToNumberCondition_Function='grasp-set-flag' WHERE _NAME = 'take-part-F2NGreater-2';

UPDATE FunctionToNumberGreater
 SET  hadByFunctionToNumberGreater_Precondition='take-part-precondition' WHERE _NAME = 'take-part-F2NGreater-2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-part' WHERE _NAME = 'place-part-param-6';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-part' WHERE _NAME = 'place-part-param-2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-part' WHERE _NAME = 'place-part-param-3';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-part' WHERE _NAME = 'place-part-param-4';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-part' WHERE _NAME = 'place-part-param-5';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'endEffector-found-flag';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'workTable-has-workTableArea';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='place-kit-effect', hasNegativePredicate_PositivePredicate= 'kit-exists' WHERE _NAME = 'place-kit-not-4';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='place-kit-effect', hasNegativePredicate_PositivePredicate= 'endEffector-has-heldObject-kit' WHERE _NAME = 'place-kit-not-3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='relative_location_in_1' WHERE _NAME = 'kitting_workstation_1';

UPDATE KittingWorkstation
 SET  hasKittingWorkstation_ChangingStation='changing_station_1', hasKittingWorkstation_Robot= 'robot_1' WHERE _NAME = 'kitting_workstation_1';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='place-kit-effect', hasNegativePredicate_PositivePredicate= 'largeBoxWithKitsSlot-is-not-occupied' WHERE _NAME = 'place-kit-not-2';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='place-kit-effect', hasNegativePredicate_PositivePredicate= 'kit-is-found' WHERE _NAME = 'place-kit-not-1';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='PartiallyIn', hadByPredicateStateRelation_PositivePredicate= 'endEffector-has-heldObject-kitTray' WHERE _NAME = 'EndEffector-kitTray-SR-PartiallyIn';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='medium_gear_finger_2_XAxis', hasPoseLocation_ZAxis= 'medium_gear_finger_2_ZAxis', hasPoseLocation_Point= 'medium_gear_finger_2_point' WHERE _NAME = 'medium_gear_finger_2_pose';

UPDATE ActionBase
 SET  hasActionBase_Effect='take-kitTray-effect', hasActionBase_Precondition= 'take-kitTray-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'take-kitTray';

UPDATE FunctionParameter
 SET  hadByFunctionParameter_Function='quantity-of-kits-in-lbwk' WHERE _NAME = 'quantity-of-kits-in-lbwk-param1';

UPDATE FunctionToNumberCondition
 SET  hasFunctionToNumberCondition_Function='quantity-of-kittrays-in-lbwekt' WHERE _NAME = 'take-kitTray-F2NGreater';

UPDATE FunctionToNumberGreater
 SET  hadByFunctionToNumberGreater_Precondition='take-kitTray-precondition' WHERE _NAME = 'take-kitTray-F2NGreater';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'slot-is-found';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'top_cover_tray_pose_location_on';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='top_cover_tray_x_axis', hasPoseLocation_ZAxis= 'top_cover_tray_z_axis', hasPoseLocation_Point= 'top_cover_tray_point' WHERE _NAME = 'top_cover_tray_pose_location_on';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='PartiallyIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'kitTray-EndEffector-SR' WHERE _NAME = 'KitTray-endEffector-SR-PartiallyIn';

UPDATE FunctionParameter
 SET  hadByFunctionParameter_Function='current-quantity-of-parts-in-kit' WHERE _NAME = 'current-quantity-of-parts-in-kit-param1';

UPDATE PositivePredicate
 SET  hasPositivePredicate_PredicateStateRelationOR='part-endEffector-SR', hadByPositivePredicate_Domain= 'kitting-domain' WHERE _NAME = 'part-has-physicalLocation-refObject-endEffector';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='big_gear_finger_2_XAxis', hasPoseLocation_ZAxis= 'big_gear_finger_2_ZAxis', hasPoseLocation_Point= 'big_gear_finger_2_point' WHERE _NAME = 'big_gear_finger_2_pose';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='slot-is-found' WHERE _NAME = 'kit-slot-is-found-param1';

UPDATE FunctionParameter
 SET  hadByFunctionParameter_Function='capacity-of-kits-in-lbwk' WHERE _NAME = 'capacity-of-kits-in-lbwk-param1';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Point='kit_gearbox_1Top1Bottom1Small1Medium1Big_bottom_cover_point', hasPartRefAndPose_XAxis= 'kit_gearbox_1Top1Bottom1Small1Medium1Big_bottom_cover_x_axis', hasPartRefAndPose_ZAxis= 'kit_gearbox_1Top1Bottom1Small1Medium1Big_bottom_cover_z_axis', hasPartRefAndPose_Sku= 'sku_part_bottom_cover', hadByPartRefAndPose_KitDesign= 'kit_design_gearbox_1Top1Bottom1Small1Medium1Big' WHERE _NAME = 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_bottom_cover';

UPDATE PositivePredicate
 SET  hasPositivePredicate_PredicateStateRelationOR='kitTray-EndEffector-SR', hadByPositivePredicate_Domain= 'kitting-domain' WHERE _NAME = 'kitTray-has-physicalLocation-refObject-endEffector';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='partsVessel-has-part' WHERE _NAME = 'partsVessel-has-part-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='partsVessel-has-part' WHERE _NAME = 'partsVessel-has-part-param1';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_ExternalShape= 'shape_gearbox_bottom_cover_ply', hasStockKeepingUnit_InternalShape= 'shape_gearbox_bottom_cover' WHERE _NAME = 'sku_part_bottom_cover';

UPDATE KitDesign
 SET  hadByKitDesign_KittingWorkstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'sku_gearbox_1Top1Bottom1Small1Medium1Big_tray' WHERE _NAME = 'kit_design_gearbox_1Top1Bottom1Small1Medium1Big';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'empty_kit_tray_box_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='empty_kit_tray_box_x_axis', hasPoseLocation_ZAxis= 'empty_kit_tray_box_z_axis', hasPoseLocation_Point= 'empty_kit_tray_box_point' WHERE _NAME = 'empty_kit_tray_box_pose';

UPDATE PositivePredicate
 SET  hasPositivePredicate_PredicateStateRelationOR='Part-Kit-SR', hadByPositivePredicate_Domain= 'kitting-domain' WHERE _NAME = 'part-has-physicalLocation-refObject-kit';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'part-is-found';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'work_table_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='work_table_x_axis', hasPoseLocation_ZAxis= 'work_table_z_axis', hasPoseLocation_Point= 'work_table_point' WHERE _NAME = 'work_table_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='medium_gear_tray' WHERE _NAME = 'medium_gear_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='medium_gear_1_x_axis', hasPoseLocation_ZAxis= 'medium_gear_1_z_axis', hasPoseLocation_Point= 'medium_gear_1_point' WHERE _NAME = 'medium_gear_1_pose';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'largeBoxWithKitsSlot-is-not-occupied';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='work_table_pose', hadByObject_KittingWorkstation= 'kitting_workstation_1' WHERE _NAME = 'work_table_1';

UPDATE NoSkuObject
 SET  hasNoSkuObject_InternalShape='shape_work_table' WHERE _NAME = 'work_table_1';

UPDATE Slot
 SET  hadBySlot_Kit='kit_gearbox_1Small1Medium', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_gearbox_1Small1Medium_small_gear' WHERE _NAME = 'kit_gearbox_1Small1Medium_slot_small_gear';

UPDATE PositivePredicate
 SET  hasPositivePredicate_PredicateStateRelationOR='Kit-EndEffector-SR', hadByPositivePredicate_Domain= 'kitting-domain' WHERE _NAME = 'kit-has-physicalLocation-refObject-endEffector';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='attach-endEffector' WHERE _NAME = 'attach-endEffector-param-2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='attach-endEffector' WHERE _NAME = 'attach-endEffector-param-3';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='attach-endEffector' WHERE _NAME = 'attach-endEffector-param-1';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'part-found-flag';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kitTray-has-physicalLocation-refObject-kit' WHERE _NAME = 'kitTray-has-physicalLocation-refObject-kit-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kitTray-has-physicalLocation-refObject-kit' WHERE _NAME = 'kitTray-has-physicalLocation-refObject-kit-param1';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='take-kit-effect', hasNegativePredicate_PositivePredicate= 'workTable-has-objectOnTable-kit' WHERE _NAME = 'take-kit-not-1';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='take-kit-effect', hasNegativePredicate_PositivePredicate= 'kit-has-physicalLocation-refObject-workTable' WHERE _NAME = 'take-kit-not-2';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='take-kit-effect', hasNegativePredicate_PositivePredicate= 'endEffector-has-no-heldObject' WHERE _NAME = 'take-kit-not-3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_gearbox_1Small1Medium_pose', hadByObjectOnTable_WorkTable= 'work_table_1' WHERE _NAME = 'kit_gearbox_1Small1Medium';

UPDATE Kit
 SET  hasKit_Design='kit_design_gearbox_1Small1Medium', hasKit_KitTray= 'kit_gearbox_1Small1Medium_tray' WHERE _NAME = 'kit_gearbox_1Small1Medium';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'kit-found-flag';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='NotUnderWithContact', hadByPredicateStateRelation_PositivePredicate= 'kitTray-has-physicalLocation-refObject-endEffector' WHERE _NAME = 'KitTray-endEffector-SR-NotUnderWithContact';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Point='kit_gearbox_1Top1Bottom1Medium_bottom_cover_point', hasPartRefAndPose_XAxis= 'kit_gearbox_1Top1Bottom1Medium_bottom_cover_x_axis', hasPartRefAndPose_ZAxis= 'kit_gearbox_1Top1Bottom1Medium_bottom_cover_z_axis', hasPartRefAndPose_Sku= 'sku_part_bottom_cover', hadByPartRefAndPose_KitDesign= 'kit_design_gearbox_1Top1Bottom1Medium' WHERE _NAME = 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Medium_bottom_cover';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='quantity-of-parts-in-partstray' WHERE _NAME = 'take-part-Decrease-2';

UPDATE Decrease
 SET  hadByDecrease_Effect='take-part-effect' WHERE _NAME = 'take-part-Decrease-2';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='ContainedIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'Kit-EndEffector-SR' WHERE _NAME = 'Kit-EndEffector-SR-ContainedIn';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'endEffectorHolder-is-found';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='slot-in-kit-found-flag' WHERE _NAME = 'take-part-Decrease-1';

UPDATE Decrease
 SET  hadByDecrease_Effect='take-part-effect' WHERE _NAME = 'take-part-Decrease-1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-kit' WHERE _NAME = 'look-for-kit-param-5';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='UnderWithContact', hadByPredicateStateRelation_PositivePredicate= 'kit-has-physicalLocation-refObject-workTable' WHERE _NAME = 'Kit-WorkTable-SR-UnderWithContact';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-kit' WHERE _NAME = 'look-for-kit-param-3';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-kit' WHERE _NAME = 'look-for-kit-param-4';

UPDATE WorkTableArea
 SET  hasWorkTableArea_SolidObject='small_gear_tray', hadByWorkTableArea_WorkTable= 'work_table_1', hasWorkTableArea_Sku= 'sku_partstray_small_gear_tray' WHERE _NAME = 'small_gear_partstray_area';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-kit' WHERE _NAME = 'look-for-kit-param-1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-kit' WHERE _NAME = 'look-for-kit-param-2';

UPDATE IntermediateStateRelation
 SET  hasIntermediateStateRelation_RCC8StateRelation='RCC8-ContainedInLBWK', hadByIntermediateStateRelation_SOAP= 'soap' WHERE _NAME = 'ContainedInLBWK';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'largeBoxWithKits-has-slot';

UPDATE IntermediateStateRelation
 SET  hasIntermediateStateRelation_RCC8StateRelation='RCC8-NotInContactWith', hadByIntermediateStateRelation_SOAP= 'soap' WHERE _NAME = 'NotInContactWith';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_box_pose' WHERE _NAME = 'finished_kit_box';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_kit_box' WHERE _NAME = 'finished_kit_box';

UPDATE PositivePredicate
 SET  hasPositivePredicate_PredicateStateRelationOR='Kit-LargeBoxWithKits-SR', hadByPositivePredicate_Domain= 'kitting-domain' WHERE _NAME = 'kit-has-physicalLocation-refObject-lbwk';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='top_cover_finger_3_XAxis', hasPoseLocation_ZAxis= 'top_cover_finger_3_ZAxis', hasPoseLocation_Point= 'top_cover_finger_3_point' WHERE _NAME = 'top_cover_finger_3_pose';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_ExternalShape= 'shape_gearbox_small_gear_tray_ply', hasStockKeepingUnit_InternalShape= 'shape_small_gear_tray' WHERE _NAME = 'sku_partstray_small_gear_tray';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='big_gear_1_pose' WHERE _NAME = 'big_gear_1';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_part_big_gear' WHERE _NAME = 'big_gear_1';

UPDATE Part
 SET  hadByPart_PartsVessel='big_gear_tray' WHERE _NAME = 'big_gear_1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='create-kit' WHERE _NAME = 'create-kit-param-1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-has-heldObject-part' WHERE _NAME = 'endEffector-has-heldObject-part-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-has-heldObject-part' WHERE _NAME = 'endEffector-has-heldObject-part-param1';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_ExternalShape= 'kit_gearbox_1Small1Medium_shape_ply', hasStockKeepingUnit_InternalShape= 'shape_1Small1Medium_kit_tray' WHERE _NAME = 'sku_gearbox_1Small1Medium_tray';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='create-kit' WHERE _NAME = 'create-kit-param-3';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='create-kit' WHERE _NAME = 'create-kit-param-2';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefData='top_cover_partstray_area', hadBySecondaryLocation_SolidObject= 'top_cover_tray' WHERE _NAME = 'top_cover_tray_relative_location_in';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-endEffector' WHERE _NAME = 'look-for-endEffector-in-endEffectorHolder-param-1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-endEffector' WHERE _NAME = 'look-for-endEffector-in-endEffectorHolder-param-2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-endEffector' WHERE _NAME = 'look-for-endEffector-in-endEffectorHolder-param-3';

UPDATE FunctionToNumberCondition
 SET  hasFunctionToNumberCondition_Function='kit-found-flag' WHERE _NAME = 'look-for-kit-F2NLess';

UPDATE FunctionToNumberLess
 SET  hadByFunctionToNumberLess_Precondition='look-for-kit-precondition' WHERE _NAME = 'look-for-kit-F2NLess';

UPDATE IntermediateStateRelation
 SET  hasIntermediateStateRelation_RCC8StateRelation='RCC8-InContactWith', hadByIntermediateStateRelation_SOAP= 'soap' WHERE _NAME = 'InContactWith';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffectorHolder-is-not-occupied' WHERE _NAME = 'endEffectorHolder-is-not-occupied-param1';

UPDATE PositivePredicate
 SET  hasPositivePredicate_PredicateStateRelationOR='EndEffector-EndEffectorHolder-SR', hadByPositivePredicate_Domain= 'kitting-domain' WHERE _NAME = 'endEffector-has-physicalLocation-refObject-endEffectorHolder';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-is-found' WHERE _NAME = 'endEffector-is-found-param1';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'endEffector-has-physicalLocation-refObject-robot';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-is-for-partSKU' WHERE _NAME = 'endEffector-is-for-partSKU-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-is-for-partSKU' WHERE _NAME = 'endEffector-is-for-partSKU-param1';

UPDATE PositivePredicate
 SET  hasPositivePredicate_PredicateStateRelationOR='EndEffector-SolidObject-SR', hadByPositivePredicate_Domain= 'kitting-domain' WHERE _NAME = 'endEffector-has-no-heldObject';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kit-is-found' WHERE _NAME = 'kit-is-found-param1';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='small_gear_finger_1_XAxis', hasPoseLocation_ZAxis= 'small_gear_finger_1_ZAxis', hasPoseLocation_Point= 'small_gear_finger_1_point' WHERE _NAME = 'small_gear_finger_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='small_gear_finger_3_XAxis', hasPoseLocation_ZAxis= 'small_gear_finger_3_ZAxis', hasPoseLocation_Point= 'small_gear_finger_3_point' WHERE _NAME = 'small_gear_finger_3_pose';

UPDATE IntermediateStateRelation
 SET  hasIntermediateStateRelation_RCC8StateRelation='RCC8-PartiallyIn', hadByIntermediateStateRelation_SOAP= 'soap' WHERE _NAME = 'PartiallyIn';

UPDATE FunctionParameter
 SET  hadByFunctionParameter_Function='quantity-of-kittrays-in-lbwekt' WHERE _NAME = 'quantity-of-kittrays-in-lbwekt-param1';

UPDATE LargeBoxWithKitsSlot
 SET  hadByLargeBoxWithKitsSlot_LargeBoxWithKits='finished_kit_receiver' WHERE _NAME = 'lbwkslot_10';

UPDATE LargeBoxWithKitsSlot
 SET  hadByLargeBoxWithKitsSlot_LargeBoxWithKits='finished_kit_receiver' WHERE _NAME = 'lbwkslot_11';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='workTable-has-no-objectOnTable' WHERE _NAME = 'workTable-has-no-objectOnTable-param1';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'workTable-has-no-objectOnTable';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='ContainedIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'LargeBoxWithKits-Kit-SR' WHERE _NAME = 'LargeBoxWithKits-Kit-SR-ContainedIn';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'robot_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='robot_x_axis', hasPoseLocation_ZAxis= 'robot_z_axis', hasPoseLocation_Point= 'robot_point' WHERE _NAME = 'robot_pose';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kitTray-has-physicalLocation-refObject-lbwekt' WHERE _NAME = 'kitTray-has-physicalLocation-refObject-lbwekt-param1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kitTray-has-physicalLocation-refObject-lbwekt' WHERE _NAME = 'kitTray-has-physicalLocation-refObject-lbwekt-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='workTableArea-is-found' WHERE _NAME = 'workTableArea-is-found-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='workTableArea-is-found' WHERE _NAME = 'workTableArea-is-found-param1';

UPDATE FunctionParameter
 SET  hadByFunctionParameter_Function='largeBoxWithKitsSlot-has-rank' WHERE _NAME = 'largeBoxWithKitsSlot-has-rank-param1';

UPDATE FunctionParameter
 SET  hadByFunctionParameter_Function='largeBoxWithKitsSlot-has-rank' WHERE _NAME = 'largeBoxWithKitsSlot-has-rank-param2';

UPDATE FunctionParameter
 SET  hadByFunctionParameter_Function='quantity-of-parts-in-partstray' WHERE _NAME = 'quantity-of-parts-in-partstray-param1';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'largeBoxWithKitsSlot-has-rank';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-endEffectorHolder' WHERE _NAME = 'look-for-endEffectorHolder-param-1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kitTray-has-skuObject-sku' WHERE _NAME = 'kitTray-has-skuObject-sku-param1';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'quantity-of-kittrays-in-lbwekt';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'quantity-of-kits-in-lbwk';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kitTray-has-skuObject-sku' WHERE _NAME = 'kitTray-has-skuObject-sku-param2';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'robot-has-no-endEffector';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_gearbox_1Top1Bottom1Medium_tray_pose' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Medium_tray';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_gearbox_1Top1Bottom1Medium_tray' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Medium_tray';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='NotUnderWithContact', hadByPredicateStateRelation_PositivePredicate= 'workTable-has-no-objectOnTable' WHERE _NAME = 'WorkTable-SolidObject-SR-NotUnderWithContact';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-endEffectorHolder' WHERE _NAME = 'look-for-endEffectorHolder-param-3';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='lbwk-has-kit' WHERE _NAME = 'lbwk-has-kit-param1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-endEffectorHolder' WHERE _NAME = 'look-for-endEffectorHolder-param-2';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='big_gear_tray' WHERE _NAME = 'big_gear_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='big_gear_1_x_axis', hasPoseLocation_ZAxis= 'big_gear_1_z_axis', hasPoseLocation_Point= 'big_gear_1_point' WHERE _NAME = 'big_gear_1_pose';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='NotUnderWithContact', hadByPredicateStateRelation_PositivePredicate= 'endEffector-has-heldObject-kit' WHERE _NAME = 'EndEffector-Kit-SR-NotUnderWithContact';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefData='medium_gear_partstray_area', hadBySecondaryLocation_SolidObject= 'medium_gear_tray' WHERE _NAME = 'medium_gear_tray_relative_location_in';

UPDATE ActionBase
 SET  hasActionBase_Effect='look-for-slot-in-kit-effect', hasActionBase_Precondition= 'look-for-slot-in-kit-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'look-for-slot-in-kit';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='lbwk-has-kit' WHERE _NAME = 'lbwk-has-kit-param2';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='ContainedIn', hadByPredicateStateRelation_PositivePredicate= 'partsVessel-has-part' WHERE _NAME = 'PartsTray-Part-SR-ContainedIn';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='slot-in-kit-found-flag' WHERE _NAME = 'look-for-slot-in-kit-Increase-1';

UPDATE Increase
 SET  hadByIncrease_Effect='look-for-slot-in-kit-effect' WHERE _NAME = 'look-for-slot-in-kit-Increase-1';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'quantity-of-parts-in-kit';

UPDATE FunctionToFunctionCondition
 SET  hasFunctionToFunctionCondition_F2='largeBoxWithKitsSlot-has-rank', hasFunctionToFunctionCondition_F1= 'quantity-of-kits-in-lbwk' WHERE _NAME = 'look-for-slot-in-lbwk-FunctionToFunctionEqual';

UPDATE FunctionToFunctionEqual
 SET  hadByFunctionToFunctionEqual_Precondition='look-for-slot-in-lbwk-precondition' WHERE _NAME = 'look-for-slot-in-lbwk-FunctionToFunctionEqual';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffectorHolder-has-endEffector' WHERE _NAME = 'endEffectorHolder-has-endEffector-param1';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'quantity-of-parts-in-partstray';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffectorHolder-has-endEffector' WHERE _NAME = 'endEffectorHolder-has-endEffector-param2';

UPDATE PositivePredicate
 SET  hasPositivePredicate_PredicateStateRelationOR='LargeBoxWithKits-Kit-SR', hadByPositivePredicate_Domain= 'kitting-domain' WHERE _NAME = 'lbwk-has-kit';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefData='big_gear_partstray_area', hadBySecondaryLocation_SolidObject= 'big_gear_tray' WHERE _NAME = 'big_gear_tray_relative_location_in';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='endEffector-found-flag' WHERE _NAME = 'attach-endEffector-Decrease-1';

UPDATE Decrease
 SET  hadByDecrease_Effect='attach-endEffector-effect' WHERE _NAME = 'attach-endEffector-Decrease-1';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='PartiallyIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'Kit-EndEffector-SR' WHERE _NAME = 'Kit-EndEffector-SR-PartiallyIn';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'workTableArea-is-found';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'kitTray-has-physicalLocation-refObject-workTable';

UPDATE IntermediateStateRelation
 SET  hasIntermediateStateRelation_RCC8StateRelation='RCC8-NotUnderWithContact', hadByIntermediateStateRelation_SOAP= 'soap' WHERE _NAME = 'NotUnderWithContact';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'endEffector-is-found';

UPDATE WorkTableArea
 SET  hasWorkTableArea_SolidObject='kit_gearbox_1Top1Bottom1Medium_tray', hadByWorkTableArea_WorkTable= 'work_table_1', hasWorkTableArea_Sku= 'sku_gearbox_1Top1Bottom1Medium_tray' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Medium_tray_area';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='changing_station_base_pose' WHERE _NAME = 'changing_station_base';

UPDATE NoSkuObject
 SET  hasNoSkuObject_InternalShape='shape_changing_station_base' WHERE _NAME = 'changing_station_base';

UPDATE WorkTableArea
 SET  hasWorkTableArea_SolidObject='top_cover_tray', hadByWorkTableArea_WorkTable= 'work_table_1', hasWorkTableArea_Sku= 'sku_partstray_top_cover' WHERE _NAME = 'top_cover_partstray_area';

UPDATE ActionBase
 SET  hasActionBase_Effect='take-part-effect', hasActionBase_Precondition= 'take-part-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'take-part';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'endEffector-has-heldObject-part';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='endEffector-found-flag' WHERE _NAME = 'look-for-endEffector-in-endEffectorHolder-Increase-1';

UPDATE Increase
 SET  hadByIncrease_Effect='look-for-endEffector-in-endEffectorHolder-effect' WHERE _NAME = 'look-for-endEffector-in-endEffectorHolder-Increase-1';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'endEffector-is-for-kitTraySKU';

UPDATE FunctionToNumberCondition
 SET  hasFunctionToNumberCondition_Function='slot-in-kit-found-flag' WHERE _NAME = 'look-for-slot-in-kit-F2NLess';

UPDATE FunctionToNumberLess
 SET  hadByFunctionToNumberLess_Precondition='look-for-slot-in-kit-precondition' WHERE _NAME = 'look-for-slot-in-kit-F2NLess';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='bottom_cover_finger_1_XAxis', hasPoseLocation_ZAxis= 'bottom_cover_finger_1_ZAxis', hasPoseLocation_Point= 'bottom_cover_finger_1_point' WHERE _NAME = 'bottom_cover_finger_1_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'bottom_cover_tray_pose_location_on';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='bottom_cover_tray_x_axis', hasPoseLocation_ZAxis= 'bottom_cover_tray_z_axis', hasPoseLocation_Point= 'bottom_cover_tray_point' WHERE _NAME = 'bottom_cover_tray_pose_location_on';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='big_gear_finger_3_XAxis', hasPoseLocation_ZAxis= 'big_gear_finger_3_ZAxis', hasPoseLocation_Point= 'big_gear_finger_3_point' WHERE _NAME = 'big_gear_finger_3_pose';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'kit-has-physicalLocation-refObject-workTable';

UPDATE FunctionParameter
 SET  hadByFunctionParameter_Function='final-quantity-of-parts-in-kit' WHERE _NAME = 'final-quantity-of-parts-in-kit-param1';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'slot-is-not-occupied';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='kit_gearbox_x_axis', hasPoseLocation_ZAxis= 'kit_gearbox_z_axis', hasPoseLocation_Point= 'kit_gearbox_point' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big_pose';

UPDATE ActionBase
 SET  hasActionBase_Effect='create-kit-effect', hasActionBase_Precondition= 'create-kit-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'create-kit';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffectorHolder-can-hold-endEffector' WHERE _NAME = 'endEffectorHolder-can-hold-endEffector-param1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffectorHolder-can-hold-endEffector' WHERE _NAME = 'endEffectorHolder-can-hold-endEffector-param2';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='UnderWithContact', hadByPredicateStateRelation_PositivePredicate= 'workTable-has-objectOnTable-kit' WHERE _NAME = 'WorkTable-Kit-SR-UnderWithContact';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='workTableArea-is-not-occupied' WHERE _NAME = 'workTableArea-is-not-occupied-param1';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='ContainedIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'kitTray-EndEffector-SR' WHERE _NAME = 'KitTray-EndEffector-SRContainedIn';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='PartiallyIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'Kit-LargeBoxWithKits-SR' WHERE _NAME = 'Kit-LargeBoxWithKits-SR-PartiallyIn';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_gearbox_1Top1Bottom1Medium_pose', hadByObjectOnTable_WorkTable= 'work_table_1' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Medium';

UPDATE Kit
 SET  hasKit_Design='kit_design_gearbox_1Top1Bottom1Medium', hasKit_KitTray= 'kit_gearbox_1Top1Bottom1Medium_tray' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Medium';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'endEffector-is-for-partSKU';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='PartiallyIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'EndEffector-Kit-SR' WHERE _NAME = 'EndEffector-Kit-SR-PartiallyIn';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='part-has-skuObject-sku' WHERE _NAME = 'part-has-skuObject-sku-param1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='part-has-skuObject-sku' WHERE _NAME = 'part-has-skuObject-sku-param2';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Point='kit_gearbox_1Small1Medium_medium_gear_point', hasPartRefAndPose_XAxis= 'kit_gearbox_1Small1Medium_medium_gear_x_axis', hasPartRefAndPose_ZAxis= 'kit_gearbox_1Small1Medium_medium_gear_z_axis', hasPartRefAndPose_Sku= 'sku_part_medium_gear', hadByPartRefAndPose_KitDesign= 'kit_design_gearbox_1Small1Medium' WHERE _NAME = 'part_ref_and_pose_kit_gearbox_1Small1Medium_medium_gear';

UPDATE FunctionToFunctionCondition
 SET  hasFunctionToFunctionCondition_F2='final-quantity-of-parts-in-kit', hasFunctionToFunctionCondition_F1= 'current-quantity-of-parts-in-kit' WHERE _NAME = 'look-for-kit-FunctionToFunctionEqual';

UPDATE FunctionToFunctionEqual
 SET  hadByFunctionToFunctionEqual_Precondition='look-for-kit-precondition' WHERE _NAME = 'look-for-kit-FunctionToFunctionEqual';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kit_gearbox_1Top1Bottom1Medium' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Medium_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='kit_gearbox_tray_1Top1Bottom1Medium_x_axis', hasPoseLocation_ZAxis= 'kit_gearbox_tray_1Top1Bottom1Medium_z_axis', hasPoseLocation_Point= 'kit_gearbox_tray_1Top1Bottom1Medium_point' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Medium_tray_pose';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'slot-in-kit-found-flag';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-is-for-kitTraySKU' WHERE _NAME = 'endEffector-is-for-kitTraySKU-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-is-for-kitTraySKU' WHERE _NAME = 'endEffector-is-for-kitTraySKU-param1';

UPDATE ActionBase
 SET  hasActionBase_Effect='place-kit-effect', hasActionBase_Precondition= 'place-kit-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'place-kit';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'kitTray-has-physicalLocation-refObject-lbwekt';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='attach-endEffector-effect', hasNegativePredicate_PositivePredicate= 'endEffectorHolder-has-endEffector' WHERE _NAME = 'attach-endEffector-not-1';

UPDATE LargeBoxWithKitsSlot
 SET  hadByLargeBoxWithKitsSlot_LargeBoxWithKits='finished_kit_receiver' WHERE _NAME = 'lbwkslot_0';

UPDATE LargeBoxWithKitsSlot
 SET  hadByLargeBoxWithKitsSlot_LargeBoxWithKits='finished_kit_receiver' WHERE _NAME = 'lbwkslot_3';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='attach-endEffector-effect', hasNegativePredicate_PositivePredicate= 'robot-has-no-endEffector' WHERE _NAME = 'attach-endEffector-not-4';

UPDATE LargeBoxWithKitsSlot
 SET  hadByLargeBoxWithKitsSlot_LargeBoxWithKits='finished_kit_receiver' WHERE _NAME = 'lbwkslot_4';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='attach-endEffector-effect', hasNegativePredicate_PositivePredicate= 'endEffector-has-physicalLocation-refObject-endEffectorHolder' WHERE _NAME = 'attach-endEffector-not-3';

UPDATE LargeBoxWithKitsSlot
 SET  hadByLargeBoxWithKitsSlot_LargeBoxWithKits='finished_kit_receiver' WHERE _NAME = 'lbwkslot_1';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='attach-endEffector-effect', hasNegativePredicate_PositivePredicate= 'endEffectorHolder-is-found' WHERE _NAME = 'attach-endEffector-not-2';

UPDATE LargeBoxWithKitsSlot
 SET  hadByLargeBoxWithKitsSlot_LargeBoxWithKits='finished_kit_receiver' WHERE _NAME = 'lbwkslot_2';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'changing_station_base_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='changing_station_base_x_axis', hasPoseLocation_ZAxis= 'changing_station_base_z_axis', hasPoseLocation_Point= 'changing_station_base_point' WHERE _NAME = 'changing_station_base_pose';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='kit-found-flag' WHERE _NAME = 'place-kit-Decrease-1';

UPDATE Decrease
 SET  hadByDecrease_Effect='place-kit-effect' WHERE _NAME = 'place-kit-Decrease-1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='finished_kit_receiver' WHERE _NAME = 'finished_kit_box_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='finished_kit_box_x_axis', hasPoseLocation_ZAxis= 'finished_kit_box_z_axis', hasPoseLocation_Point= 'finished_kit_box_point' WHERE _NAME = 'finished_kit_box_pose';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='PartiallyIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'EndEffector-EndEffectorHolder-SR' WHERE _NAME = 'EndEffector-EndEffectorHolder-PartiallyIn';

UPDATE ActionBase
 SET  hasActionBase_Effect='take-kit-effect', hasActionBase_Precondition= 'take-kit-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'take-kit';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'kit_gearbox_1Small1Medium_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='kit_gearbox_1Small1Medium_x_axis', hasPoseLocation_ZAxis= 'kit_gearbox_1Small1Medium_z_axis', hasPoseLocation_Point= 'kit_gearbox_1Small1Medium_point' WHERE _NAME = 'kit_gearbox_1Small1Medium_pose';

UPDATE WorkTableArea
 SET  hasWorkTableArea_SolidObject='big_gear_tray', hadByWorkTableArea_WorkTable= 'work_table_1', hasWorkTableArea_Sku= 'sku_partstray_big_gear_tray' WHERE _NAME = 'big_gear_partstray_area';

UPDATE KitDesign
 SET  hadByKitDesign_KittingWorkstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'sku_gearbox_1Small1Medium_tray' WHERE _NAME = 'kit_design_gearbox_1Small1Medium';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='robotiq_gripper_pose' WHERE _NAME = 'robotiq_gripper';

UPDATE EndEffector
 SET  hadByEndEffector_Robot='robot_1' WHERE _NAME = 'robotiq_gripper';

UPDATE IntermediateStateRelation
 SET  hasIntermediateStateRelation_RCC8StateRelation='RCC8-PartiallyInAndInContactWith', hadByIntermediateStateRelation_SOAP= 'soap' WHERE _NAME = 'PartiallyInAndInContactWith';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kit-exists' WHERE _NAME = 'kit-exists-param1';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'endEffectorHolder-is-not-occupied';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'small_gear_tray_pose_location_on';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='small_gear_tray_x_axis', hasPoseLocation_ZAxis= 'small_gear_tray_z_axis', hasPoseLocation_Point= 'small_gear_tray_point' WHERE _NAME = 'small_gear_tray_pose_location_on';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='InContactWith', hadByPredicateStateRelation_PositivePredicate= 'robot-has-endEffector' WHERE _NAME = 'Robot-EndEffector-SR-InContactWith';

UPDATE LargeBoxWithKitsSlot
 SET  hadByLargeBoxWithKitsSlot_LargeBoxWithKits='finished_kit_receiver' WHERE _NAME = 'lbwkslot_9';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'relative_location_in_1';

UPDATE LargeBoxWithKitsSlot
 SET  hadByLargeBoxWithKitsSlot_LargeBoxWithKits='finished_kit_receiver' WHERE _NAME = 'lbwkslot_6';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'empty_kit_tray_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='empty_kit_tray_supply_x_axis', hasPoseLocation_ZAxis= 'empty_kit_tray_supply_z_axis', hasPoseLocation_Point= 'empty_kit_tray_supply_point' WHERE _NAME = 'empty_kit_tray_supply_pose';

UPDATE LargeBoxWithKitsSlot
 SET  hadByLargeBoxWithKitsSlot_LargeBoxWithKits='finished_kit_receiver' WHERE _NAME = 'lbwkslot_5';

UPDATE LargeBoxWithKitsSlot
 SET  hadByLargeBoxWithKitsSlot_LargeBoxWithKits='finished_kit_receiver' WHERE _NAME = 'lbwkslot_8';

UPDATE LargeBoxWithKitsSlot
 SET  hadByLargeBoxWithKitsSlot_LargeBoxWithKits='finished_kit_receiver' WHERE _NAME = 'lbwkslot_7';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kit-has-slot' WHERE _NAME = 'kit-has-slot-param1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kit-has-slot' WHERE _NAME = 'kit-has-slot-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='largeBoxWithKits-has-slot' WHERE _NAME = 'largeBoxWithKits-has-slot-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='largeBoxWithKits-has-slot' WHERE _NAME = 'largeBoxWithKits-has-slot-param1';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Point='kit_gearbox_1Top1Bottom1Small1Medium1Big_medium_gear_point', hasPartRefAndPose_XAxis= 'kit_gearbox_1Top1Bottom1Small1Medium1Big_medium_gear_x_axis', hasPartRefAndPose_ZAxis= 'kit_gearbox_1Top1Bottom1Small1Medium1Big_medium_gear_z_axis', hasPartRefAndPose_Sku= 'sku_part_medium_gear', hadByPartRefAndPose_KitDesign= 'kit_design_gearbox_1Top1Bottom1Small1Medium1Big' WHERE _NAME = 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_medium_gear';

UPDATE ActionBase
 SET  hasActionBase_Effect='detach-endEffector-effect', hasActionBase_Precondition= 'detach-endEffector-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'detach-endEffector';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'part-has-skuObject-sku';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='medium_gear_1_pose' WHERE _NAME = 'medium_gear_1';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_part_medium_gear' WHERE _NAME = 'medium_gear_1';

UPDATE Part
 SET  hadByPart_PartsVessel='medium_gear_tray' WHERE _NAME = 'medium_gear_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'changing_station_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='changing_station_x_axis', hasPoseLocation_ZAxis= 'changing_station_z_axis', hasPoseLocation_Point= 'changing_station_point' WHERE _NAME = 'changing_station_pose';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'grasp-is-set';

UPDATE BoxVolume
 SET  hasBoxVolume_MaximumPoint='point_max', hasBoxVolume_MinimumPoint= 'point_min', hadByWorkVolume_Robot= 'robot_1' WHERE _NAME = 'box_volume_1';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='medium_gear_finger_1_XAxis', hasPoseLocation_ZAxis= 'medium_gear_finger_1_ZAxis', hasPoseLocation_Point= 'medium_gear_finger_1_point' WHERE _NAME = 'medium_gear_finger_1_pose';

UPDATE IntermediateStateRelation
 SET  hasIntermediateStateRelation_RCC8StateRelation='RCC8-UnderWithContact', hadByIntermediateStateRelation_SOAP= 'soap' WHERE _NAME = 'UnderWithContact';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='small_gear_finger_2_XAxis', hasPoseLocation_ZAxis= 'small_gear_finger_2_ZAxis', hasPoseLocation_Point= 'small_gear_finger_2_point' WHERE _NAME = 'small_gear_finger_2_pose';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_ExternalShape= 'shape_gearbox_top_cover_ply', hasStockKeepingUnit_InternalShape= 'shape_gearbox_top_coer' WHERE _NAME = 'sku_part_top_cover';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='InContactWith', hadByPredicateStateRelation_PositivePredicate= 'endEffector-has-physicalLocation-refObject-robot' WHERE _NAME = 'EndEffector-Robot-SR-InContactWith';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Point='kit_gearbox_1Top1Bottom1Medium_medium_gear_point', hasPartRefAndPose_XAxis= 'kit_gearbox_1Top1Bottom1Medium_medium_gear_x_axis', hasPartRefAndPose_ZAxis= 'kit_gearbox_1Top1Bottom1Medium_medium_gear_z_axis', hasPartRefAndPose_Sku= 'sku_part_medium_gear', hadByPartRefAndPose_KitDesign= 'kit_design_gearbox_1Top1Bottom1Medium' WHERE _NAME = 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Medium_medium_gear';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'endEffectorHolder-can-hold-endEffector';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='detach-endEffector-effect', hasNegativePredicate_PositivePredicate= 'endEffector-has-physicalLocation-refObject-robot' WHERE _NAME = 'detach-endEffector-effect-not-3';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='detach-endEffector-effect', hasNegativePredicate_PositivePredicate= 'robot-has-endEffector' WHERE _NAME = 'detach-endEffector-effect-not-2';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='detach-endEffector-effect', hasNegativePredicate_PositivePredicate= 'endEffectorHolder-is-not-occupied' WHERE _NAME = 'detach-endEffector-effect-not-1';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_ExternalShape= 'shape_gearbox_top_cover_tray_ply', hasStockKeepingUnit_InternalShape= 'shape_top_cover_tray' WHERE _NAME = 'sku_partstray_top_cover';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'kit-exists';

UPDATE Slot
 SET  hadBySlot_Kit='kit_gearbox_1Top1Bottom1Small1Medium1Big', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_bottom_cover' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_bottom_cover';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='top_cover_tray' WHERE _NAME = 'top_cover_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='top_cover_1_x_axis', hasPoseLocation_ZAxis= 'top_cover_1_z_axis', hasPoseLocation_Point= 'top_cover_1_point' WHERE _NAME = 'top_cover_1_pose';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='PartiallyIn', hadByPredicateStateRelation_PositivePredicate= 'endEffector-has-heldObject-part' WHERE _NAME = 'EndEffector-Part-SR-PartiallyIn';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-kitTray' WHERE _NAME = 'place-kitTray-param-4';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-kitTray' WHERE _NAME = 'place-kitTray-param-3';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-kitTray' WHERE _NAME = 'place-kitTray-param-2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-kitTray' WHERE _NAME = 'place-kitTray-param-1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='workTable-has-workTableArea' WHERE _NAME = 'workTable-has-workTableArea-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='workTable-has-workTableArea' WHERE _NAME = 'workTable-has-workTableArea-param1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-kitTray' WHERE _NAME = 'place-kitTray-param-5';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_ExternalShape= 'shape_gearbox_medium_gear_tray_ply', hasStockKeepingUnit_InternalShape= 'shape_medium_gear_tray' WHERE _NAME = 'sku_partstray_medium_gear_tray';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='endEffectorHolder-found-flag' WHERE _NAME = 'place-part-Decrease-3';

UPDATE Decrease
 SET  hadByDecrease_Effect='place-part-effect' WHERE _NAME = 'place-part-Decrease-3';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='part-found-flag' WHERE _NAME = 'place-part-Decrease-2';

UPDATE Decrease
 SET  hadByDecrease_Effect='place-part-effect' WHERE _NAME = 'place-part-Decrease-2';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='grasp-set-flag' WHERE _NAME = 'place-part-Decrease-1';

UPDATE Decrease
 SET  hadByDecrease_Effect='place-part-effect' WHERE _NAME = 'place-part-Decrease-1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-slot-in-kit' WHERE _NAME = 'look-for-slot-in-kit-param-2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-slot-in-kit' WHERE _NAME = 'look-for-slot-in-kit-param-3';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-slot-in-kit' WHERE _NAME = 'look-for-slot-in-kit-param-1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-slot-in-kit' WHERE _NAME = 'look-for-slot-in-kit-param-6';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='top_cover_1_pose' WHERE _NAME = 'top_cover_1';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_part_top_cover' WHERE _NAME = 'top_cover_1';

UPDATE Part
 SET  hadByPart_PartsVessel='top_cover_tray' WHERE _NAME = 'top_cover_1';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='largeBoxWithKitsSlot-is-not-occupied' WHERE _NAME = 'largeBoxWithKitsSlot-is-not-occupied-param1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-slot-in-kit' WHERE _NAME = 'look-for-slot-in-kit-param-4';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-slot-in-kit' WHERE _NAME = 'look-for-slot-in-kit-param-5';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-has-physicalLocation-refObject-robot' WHERE _NAME = 'endEffector-has-physicalLocation-refObject-robot-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffector-has-physicalLocation-refObject-robot' WHERE _NAME = 'endEffector-has-physicalLocation-refObject-robot-param1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_supply_pose', hadByObject_KittingWorkstation= 'kitting_workstation_1' WHERE _NAME = 'empty_kit_tray_supply';

UPDATE LargeBoxWithEmptyKitTrays
 SET  hasLargeBoxWithEmptyKitTrays_LargeContainer='empty_kit_tray_box' WHERE _NAME = 'empty_kit_tray_supply';

UPDATE FunctionToFunctionCondition
 SET  hasFunctionToFunctionCondition_F2='final-quantity-of-parts-in-kit', hasFunctionToFunctionCondition_F1= 'current-quantity-of-parts-in-kit' WHERE _NAME = 'take-kit-F2FEqual';

UPDATE FunctionToFunctionEqual
 SET  hadByFunctionToFunctionEqual_Precondition='take-kit-precondition' WHERE _NAME = 'take-kit-F2FEqual';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='top_cover_tray_pose_location_on', hadByObjectOnTable_WorkTable= 'work_table_1' WHERE _NAME = 'top_cover_tray';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_partstray_top_cover' WHERE _NAME = 'top_cover_tray';

UPDATE PartsVessel
 SET  hasPartsVessel_PartSku='sku_part_top_cover' WHERE _NAME = 'top_cover_tray';

UPDATE FunctionParameter
 SET  hadByFunctionParameter_Function='capacity-of-parts-in-kit' WHERE _NAME = 'capacity-of-parts-in-kit-param1';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='NotUnderWithContact', hadByPredicateStateRelation_PositivePredicate= 'endEffector-has-heldObject-kitTray' WHERE _NAME = 'EndEffector-KitTray-SR-NotUnderWithContact';

UPDATE FunctionParameter
 SET  hadByFunctionParameter_Function='capacity-of-parts-in-kit' WHERE _NAME = 'capacity-of-parts-in-kit-param2';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'partsVessel-has-part';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='robot-has-no-endEffector' WHERE _NAME = 'robot-has-no-endEffector-param1';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='kitTray-found-flag' WHERE _NAME = 'look-for-kitTray-Increase-1';

UPDATE Increase
 SET  hadByIncrease_Effect='look-for-kitTray-effect' WHERE _NAME = 'look-for-kitTray-Increase-1';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'kitTray-has-skuObject-sku';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'robot-has-endEffector';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='bottom_cover_finger_3_XAxis', hasPoseLocation_ZAxis= 'bottom_cover_finger_3_ZAxis', hasPoseLocation_Point= 'bottom_cover_finger_3_point' WHERE _NAME = 'bottom_cover_finger_3_pose';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'capacity-of-kits-in-lbwk';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='slot-is-not-occupied' WHERE _NAME = 'slot-is-not-occupied-param1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='medium_gear_tray_pose_location_on', hadByObjectOnTable_WorkTable= 'work_table_1' WHERE _NAME = 'medium_gear_tray';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_partstray_medium_gear_tray' WHERE _NAME = 'medium_gear_tray';

UPDATE PartsVessel
 SET  hasPartsVessel_PartSku='sku_part_medium_gear' WHERE _NAME = 'medium_gear_tray';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-workTableArea' WHERE _NAME = 'look-for-workTableArea-param-1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-workTableArea' WHERE _NAME = 'look-for-workTableArea-param-2';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='NotInContactWith', hadByPredicateStateRelation_PositivePredicate= 'robot-has-no-endEffector' WHERE _NAME = 'EndEffector-Robot-SR-NotInContactWith';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='bottom_cover_finger_2_XAxis', hasPoseLocation_ZAxis= 'bottom_cover_finger_2_ZAxis', hasPoseLocation_Point= 'bottom_cover_finger_2_point' WHERE _NAME = 'bottom_cover_finger_2_pose';

UPDATE WorkTableArea
 SET  hasWorkTableArea_SolidObject='kit_gearbox_1Top1Bottom1Small1Medium1Big_tray', hadByWorkTableArea_WorkTable= 'work_table_1', hasWorkTableArea_Sku= 'sku_gearbox_1Top1Bottom1Small1Medium1Big_tray' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big_tray_area';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'current-quantity-of-parts-in-kit';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefData='kit_gearbox_1Top1Bottom1Small1Medium1Big_tray_area', hadBySecondaryLocation_SolidObject= 'kit_gearbox_1Top1Bottom1Small1Medium1Big_tray' WHERE _NAME = 'kit_tray_relative_location_in';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='small_gear_tray' WHERE _NAME = 'small_gear_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='small_gear_1_x_axis', hasPoseLocation_ZAxis= 'small_gear_1_z_axis', hasPoseLocation_Point= 'small_gear_1_point' WHERE _NAME = 'small_gear_1_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Point='kit_gearbox_1Top1Bottom1Small1Medium1Big_small_gear_point', hasPartRefAndPose_XAxis= 'kit_gearbox_1Top1Bottom1Small1Medium1Big_small_gear_x_axis', hasPartRefAndPose_ZAxis= 'kit_gearbox_1Top1Bottom1Small1Medium1Big_small_gear_z_axis', hasPartRefAndPose_Sku= 'sku_part_small_gear', hadByPartRefAndPose_KitDesign= 'kit_design_gearbox_1Top1Bottom1Small1Medium1Big' WHERE _NAME = 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_small_gear';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-workTableArea' WHERE _NAME = 'look-for-workTableArea-param-6';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-workTableArea' WHERE _NAME = 'look-for-workTableArea-param-5';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-workTableArea' WHERE _NAME = 'look-for-workTableArea-param-4';

UPDATE FunctionToFunctionCondition
 SET  hasFunctionToFunctionCondition_F2='capacity-of-parts-in-kit', hasFunctionToFunctionCondition_F1= 'quantity-of-parts-in-kit' WHERE _NAME = 'place-part-F2FLess';

UPDATE FunctionToFunctionLess
 SET  hadByFunctionToFunctionLess_Precondition='place-part-precondition' WHERE _NAME = 'place-part-F2FLess';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='look-for-workTableArea' WHERE _NAME = 'look-for-workTableArea-param-3';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='current-quantity-of-parts-in-kit' WHERE _NAME = 'place-part-Increase-1';

UPDATE Increase
 SET  hadByIncrease_Effect='place-part-effect' WHERE _NAME = 'place-part-Increase-1';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='quantity-of-parts-in-kit' WHERE _NAME = 'place-part-Increase-2';

UPDATE Increase
 SET  hadByIncrease_Effect='place-part-effect' WHERE _NAME = 'place-part-Increase-2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='endEffectorHolder-is-found' WHERE _NAME = 'endEffectorHolder-is-found-param1';

UPDATE Function
 SET  hadByFunction_Domain='kitting-domain' WHERE _NAME = 'grasp-set-flag';

UPDATE ActionBase
 SET  hasActionBase_Effect='place-kitTray-effect', hasActionBase_Precondition= 'place-kitTray-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'place-kitTray';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_box_pose' WHERE _NAME = 'empty_kit_tray_box';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_kit_box' WHERE _NAME = 'empty_kit_tray_box';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='workTableArea-is-for-sku' WHERE _NAME = 'workTableArea-is-for-sku-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='workTableArea-is-for-sku' WHERE _NAME = 'workTableArea-is-for-sku-param1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='detach-endEffector' WHERE _NAME = 'detach-endEffector-param-3';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'kit-has-kitTray';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='detach-endEffector' WHERE _NAME = 'detach-endEffector-param-2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='detach-endEffector' WHERE _NAME = 'detach-endEffector-param-1';

UPDATE PositivePredicate
 SET  hasPositivePredicate_PredicateStateRelationOR='EndEffector-Kit-SR', hadByPositivePredicate_Domain= 'kitting-domain' WHERE _NAME = 'endEffector-has-heldObject-kit';

UPDATE IntermediateStateRelation
 SET  hasIntermediateStateRelation_RCC8StateRelation='RCC8-OnTopOf', hadByIntermediateStateRelation_SOAP= 'soap' WHERE _NAME = 'OnTopOf';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Point='kit_gearbox_1Top1Bottom1Medium_top_cover_point', hasPartRefAndPose_XAxis= 'kit_gearbox_1Top1Bottom1Medium_top_cover_x_axis', hasPartRefAndPose_ZAxis= 'kit_gearbox_1Top1Bottom1Medium_top_cover_z_axis', hasPartRefAndPose_Sku= 'sku_part_top_cover', hadByPartRefAndPose_KitDesign= 'kit_design_gearbox_1Top1Bottom1Medium' WHERE _NAME = 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Medium_top_cover';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='bottom_cover_tray' WHERE _NAME = 'bottom_cover_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='bottom_cover_1_x_axis', hasPoseLocation_ZAxis= 'bottom_cover_1_z_axis', hasPoseLocation_Point= 'bottom_cover_1_point' WHERE _NAME = 'bottom_cover_1_pose';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kitTray-has-physicalLocation-refObject-endEffector' WHERE _NAME = 'kitTray-has-physicalLocation-refObject-endEffector-param2';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_ExternalShape= 'shape_gearbox_medium_gear_ply', hasStockKeepingUnit_InternalShape= 'shape_gearbox_medium_gear' WHERE _NAME = 'sku_part_medium_gear';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kitTray-has-physicalLocation-refObject-endEffector' WHERE _NAME = 'kitTray-has-physicalLocation-refObject-endEffector-param1';

UPDATE Slot
 SET  hadBySlot_Kit='kit_gearbox_1Top1Bottom1Small1Medium1Big', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_big_gear' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_big_gear';

UPDATE FunctionOperation
 SET  hasFunctionOperation_Function='quantity-of-kittrays-in-lbwekt' WHERE _NAME = 'take-kitTray-Decrease';

UPDATE Decrease
 SET  hadByDecrease_Effect='take-kitTray-effect' WHERE _NAME = 'take-kitTray-Decrease';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='take-kitTray-effect', hasNegativePredicate_PositivePredicate= 'kitTray-has-physicalLocation-refObject-lbwekt' WHERE _NAME = 'take-kitTray-not-1';

UPDATE NegativePredicate
 SET  hadByNegativePredicate_Effect='take-kitTray-effect', hasNegativePredicate_PositivePredicate= 'endEffector-has-no-heldObject' WHERE _NAME = 'take-kitTray-not-2';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Point='kit_gearbox_1Top1Bottom1Small1Medium1Big_big_gear_point', hasPartRefAndPose_XAxis= 'kit_gearbox_1Top1Bottom1Small1Medium1Big_big_gear_x_axis', hasPartRefAndPose_ZAxis= 'kit_gearbox_1Top1Bottom1Small1Medium1Big_big_gear_z_axis', hasPartRefAndPose_Sku= 'sku_part_big_gear', hadByPartRefAndPose_KitDesign= 'kit_design_gearbox_1Top1Bottom1Small1Medium1Big' WHERE _NAME = 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_big_gear';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='robot-has-endEffector' WHERE _NAME = 'robot-has-endEffector-param2';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='robot-has-endEffector' WHERE _NAME = 'robot-has-endEffector-param1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_receiver_pose', hadByObject_KittingWorkstation= 'kitting_workstation_1' WHERE _NAME = 'finished_kit_receiver';

UPDATE LargeBoxWithKits
 SET  hasLargeBoxWithKits_LargeContainer='finished_kit_box', hasLargeBoxWithKits_KitDesign= 'kit_design_gearbox_1Top1Bottom1Small1Medium1Big' WHERE _NAME = 'finished_kit_receiver';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'part-has-physicalLocation-refObject-partsTray';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'kitTray-is-found';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'robotiq_gripper_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='robotiq_gripper_holder_x_axis', hasPoseLocation_ZAxis= 'robotiq_gripper_holder_z_axis', hasPoseLocation_Point= 'robotiq_gripper_holder_point' WHERE _NAME = 'robotiq_gripper_holder_pose';

UPDATE Slot
 SET  hadBySlot_Kit='kit_gearbox_1Top1Bottom1Small1Medium1Big', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_medium_gear' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_medium_gear';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-kit' WHERE _NAME = 'place-kit-param-4';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='robot_1' WHERE _NAME = 'robotiq_gripper_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='robotiq_gripper_x_axis', hasPoseLocation_ZAxis= 'robotiq_gripper_z_axis', hasPoseLocation_Point= 'robotiq_gripper_point' WHERE _NAME = 'robotiq_gripper_pose';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-kit' WHERE _NAME = 'place-kit-param-3';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-kit' WHERE _NAME = 'place-kit-param-5';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='set-grasp' WHERE _NAME = 'set-grasp-param-3';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefData='small_gear_partstray_area', hadBySecondaryLocation_SolidObject= 'small_gear_tray' WHERE _NAME = 'small_gear_tray_relative_location_in';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kit-has-physicalLocation-refObject-workTable' WHERE _NAME = 'kit-has-physicalLocation-refObject-workTable-param2';

UPDATE WorkTableArea
 SET  hasWorkTableArea_SolidObject='medium_gear_tray', hadByWorkTableArea_WorkTable= 'work_table_1', hasWorkTableArea_Sku= 'sku_partstray_medium_gear_tray' WHERE _NAME = 'medium_gear_partstray_area';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='set-grasp' WHERE _NAME = 'set-grasp-param-4';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='kit-has-physicalLocation-refObject-workTable' WHERE _NAME = 'kit-has-physicalLocation-refObject-workTable-param1';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='big_gear_finger_1_XAxis', hasPoseLocation_ZAxis= 'big_gear_finger_1_ZAxis', hasPoseLocation_Point= 'big_gear_finger_1_point' WHERE _NAME = 'big_gear_finger_1_pose';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='slot-can-contain-part-sku' WHERE _NAME = 'slot-can-contain-part-sku-param2';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='UnderWithContact', hadByPredicateStateRelation_PositivePredicate= 'kitTray-has-physicalLocation-refObject-workTable' WHERE _NAME = 'KitTray-WorkTable-SR-UnderWithContact';

UPDATE PredicateParameter
 SET  hadByPredicateParameter_PositivePredicate='slot-can-contain-part-sku' WHERE _NAME = 'slot-can-contain-part-sku-param1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-kit' WHERE _NAME = 'place-kit-param-2';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='place-kit' WHERE _NAME = 'place-kit-param-1';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='set-grasp' WHERE _NAME = 'set-grasp-param-2';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='medium_gear_finger_3_XAxis', hasPoseLocation_ZAxis= 'medium_gear_finger_3_ZAxis', hasPoseLocation_Point= 'medium_gear_finger_3_point' WHERE _NAME = 'medium_gear_finger_3_pose';

UPDATE ActionParameterSet
 SET  hadByActionParameterSet_ActionBase='set-grasp' WHERE _NAME = 'set-grasp-param-1';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'largeBoxWithKitsSlot-is-found';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='PartiallyIn', hadByPredicateStateRelation_PredicateStateRelationOr= 'part-endEffector-SR' WHERE _NAME = 'part-endEffector-SR-PartiallyIn';

UPDATE IntermediateStateRelation
 SET  hasIntermediateStateRelation_RCC8StateRelation='RCC8-ContainedIn', hadByIntermediateStateRelation_SOAP= 'soap' WHERE _NAME = 'ContainedIn';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='top_cover_finger_1_XAxis', hasPoseLocation_ZAxis= 'top_cover_finger_1_ZAxis', hasPoseLocation_Point= 'top_cover_finger_1_point' WHERE _NAME = 'top_cover_finger_1_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='small_gear_tray_pose_location_on', hadByObjectOnTable_WorkTable= 'work_table_1' WHERE _NAME = 'small_gear_tray';

UPDATE SkuObject
 SET  hasSkuObject_Sku='sku_partstray_small_gear_tray' WHERE _NAME = 'small_gear_tray';

UPDATE PartsVessel
 SET  hasPartsVessel_PartSku='sku_part_small_gear' WHERE _NAME = 'small_gear_tray';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='robotiq_gripper_holder_pose' WHERE _NAME = 'robotiq_gripper_holder';

UPDATE NoSkuObject
 SET  hasNoSkuObject_InternalShape='shape_gripper_holder_1' WHERE _NAME = 'robotiq_gripper_holder';

UPDATE EndEffectorHolder
 SET  hadByEndEffectorHolder_EndEffectorChangingStation='changing_station_1' WHERE _NAME = 'robotiq_gripper_holder';

UPDATE PositivePredicate
 SET  hadByPositivePredicate_Domain='kitting-domain' WHERE _NAME = 'kit-is-found';

UPDATE PredicateStateRelation
 SET  hasPredicateStateRelation_IntermediateStateRelation='ContainedIn', hadByPredicateStateRelation_PositivePredicate= 'part-has-physicalLocation-refObject-partsTray' WHERE _NAME = 'Part-PartsTray-SR-ContainedIn';

UPDATE Slot
 SET  hadBySlot_Kit='kit_gearbox_1Top1Bottom1Small1Medium1Big', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_gearbox_1Top1Bottom1Small1Medium1Big_top_cover' WHERE _NAME = 'kit_gearbox_1Top1Bottom1Small1Medium1Big_slot_top_cover';

UPDATE ActionBase
 SET  hasActionBase_Effect='look-for-kitTray-effect', hasActionBase_Precondition= 'look-for-kitTray-precondition', hadByAction_Domain= 'kitting-domain' WHERE _NAME = 'look-for-kitTray';