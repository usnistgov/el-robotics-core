INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(1, 'part_b_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(1, 'part_b_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(1, 'part_b_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(2, 'part_c_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(3, 'robot_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(3, 'robot_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(3, 'robot_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(1, 'part_b_tray', 7, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(4, 'part_b_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(4, 'part_b_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(4, 'part_b_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_a');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(5, 'stock_keeping_unit_part_a', 'SKU for Part A', 0.180000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(5, 1);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(6, 'empty_kit_tray_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(7, 'finished_kit_receiver_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(7, 'finished_kit_receiver_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(7, 'finished_kit_receiver_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(8, 'part_b_5_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(8, 'part_b_5_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(8, 'part_b_5_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(9, 'part_b_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(9, 'part_b_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(9, 'part_b_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('work_table_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(10, 'work_table_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(11, 'part_c_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(11, 'part_c_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(11, 'part_c_4_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gripper_holder', NULL);

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_ChangingStation, hasEndEffectorHolder_EndEffector)
VALUES(2, 'part_gripper_holder', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(12, 'tray_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(12, 'tray_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(12, 'tray_gripper_holder_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(13, 'part_c_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(14, 'changing_station_base_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(15, 'part_b_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(15, 'part_b_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(15, 'part_b_supply_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gripper', NULL);

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_Weight, hasEffector_MaximumLoadWeight)
VALUES(3, 'part_gripper', 'small single cup vacuum effector', 0.010000, 0.400000);

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(3, 'part_gripper', 0.020000, 0.025000);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(3, 'part_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(16, 'stock_keeping_unit_kit_tray', 'SKU for KitTrays', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(16, 3);

INSERT INTO SolidObject
(_NAME, hasSolidObject_InternalShape, hasSolidObject_PrimaryLocation)
VALUES('changing_station_base', NULL, NULL);

INSERT INTO MechanicalComponent
(MechanicalComponentID, _NAME)
VALUES(4, 'changing_station_base');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_a_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(17, 'point_kit_a2b1c1_a_2', 0.400000, 0.300000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_5', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(5, 'part_c_5', 'c5', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_a_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(18, 'point_kit_a2b1c1_a_1', 0.200000, 0.300000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(6, 'part_c_4', 'c4', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(7, 'part_c_3', 'c3', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(8, 'part_c_2', 'c2', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(9, 'part_c_1', 'c1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(19, 'kit_tray_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(20, 'part_a_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(20, 'part_a_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(20, 'part_a_tray_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_8', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(10, 'part_c_8', 'c8', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(21, 'part_c_6_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_7', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(11, 'part_c_7', 'c7', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(22, 'part_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(22, 'part_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(22, 'part_gripper_holder_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_6', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(12, 'part_c_6', 'c6', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(13, 'part_c_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(23, 'part_gripper_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(24, 'part_gripper_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(24, 'part_gripper_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(24, 'part_gripper_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(25, 'part_a_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(26, 'part_a_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(26, 'part_a_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(26, 'part_a_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(27, 'part_b_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(28, 'part_c_6_point', 0.330000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(29, 'part_b_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(14, 'part_a_tray', 6, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(30, 'part_b_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_c');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(31, 'stock_keeping_unit_part_c', 'SKU for Part C', 0.180000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(31, 3);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_b');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(32, 'stock_keeping_unit_part_b', 'SKU for Part B', 0.180000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(32, 3);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(33, 'finished_kit_box_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(34, 'part_b_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_box');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(35, 'stock_keeping_unit_kit_box', 'SKU for Boxes for Kits and KitTrays', 1.200000, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(36, 'z_axis_kit_a2b1c1_c_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(37, 'part_b_7_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(37, 'part_b_7_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(37, 'part_b_7_pose');

INSERT INTO DataThing
(_NAME)
VALUES('point_min');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(38, 'point_min', -1.000000, -1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(39, 'tray_gripper_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(40, 'part_a_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_a');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(41, 'shape_part_a', 'Shape of PartA');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(41, 'shape_part_a', 'USARSim', 'PartA', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_b');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(42, 'shape_part_b', 'Shape of PartB');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(42, 'shape_part_b', 'USARSim', 'PartB', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(43, 'part_c_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(44, 'part_a_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(44, 'part_a_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(44, 'part_a_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_c');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(45, 'shape_part_c', 'Shape of PartC');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(45, 'shape_part_c', 'USARSim', 'PartC', 'USARPhysObj');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper', NULL);

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_Weight, hasEffector_MaximumLoadWeight, hadByEndEffector_Robot)
VALUES(15, 'tray_gripper', 'large single cup vacuum effector', 0.040000, 0.500000, NULL);

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(15, 'tray_gripper', 0.040000, 0.100000);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(15, 'tray_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_box');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(46, 'shape_kit_box', 'Shape of boxes to hold kits and kit trays');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(46, 'shape_kit_box');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(46, 'shape_kit_box', 0.700000, 'false', 0.800000, 0.900000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(47, 'part_c_3_point', -0.110000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(48, 'part_gripper_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_a_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(49, 'part_ref_and_pose_kit_a2b1c1_a_2', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_a');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(50, 'stock_keeping_unit_parts_tray_a', 'SKU for Part a PartsTray', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(50, 15);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(51, 'part_a_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_c');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(52, 'stock_keeping_unit_parts_tray_c', 'SKU for Part c PartsTrays', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(52, 15);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(53, 'part_b_1_point', -0.080000, 0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(54, 'work_table_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(55, 'part_b_7_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(56, 'part_b_6_point', -0.240000, -0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(57, 'part_b_8_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(57, 'part_b_8_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(57, 'part_b_8_pose');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_b');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(58, 'stock_keeping_unit_parts_tray_b', 'SKU for Part b PartsTrays', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(58, 15);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_a_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(59, 'part_ref_and_pose_kit_a2b1c1_a_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(60, 'changing_station_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(61, 'part_c_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(62, 'part_b_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(62, 'part_b_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(62, 'part_b_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_b_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(63, 'part_ref_and_pose_kit_a2b1c1_b_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(64, 'work_table_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(64, 'work_table_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(64, 'work_table_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(65, 'part_a_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_changing_station_base');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(66, 'shape_changing_station_base', 'Shape of base of changing station');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(66, 'shape_changing_station_base');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(66, 'shape_changing_station_base', 0.100000, 'true', 1.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(67, 'part_a_1_point', 0.159000, 0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_a_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(68, 'point_kit_a2b2c1_a_2', -0.159000, -0.149000, 0.036000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(69, 'part_c_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_a_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(70, 'point_kit_a2b2c1_a_1', -0.159000, 0.145000, 0.036000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(16, 'part_b_1', 'b1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_work_table');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(71, 'shape_work_table', 'Shape of the work table');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(71, 'shape_work_table');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(71, 'shape_work_table', 0.800000, 'true', 0.500000, 1.600000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(17, 'part_b_2', 'b2', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_5', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(18, 'part_b_5', 'b5', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_6', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(19, 'part_b_6', 'b6', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(20, 'part_b_3', 'b3', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(21, 'part_b_4', 'b4', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_7', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(22, 'part_b_7', 'b7', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(72, 'kit_tray_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(73, 'part_b_6_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(73, 'part_b_6_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(73, 'part_b_6_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_8', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(23, 'part_b_8', 'b8', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(74, 'changing_station_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(75, 'kit_tray_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(76, 'empty_kit_tray_supply_point', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(77, 'z_axis_kit_a2b2c1_a_2', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_supply', NULL);

INSERT INTO LargeBoxWithEmptyKitTrays
(LargeBoxWithEmptyKitTraysID, _NAME, hasLargeBoxWithEmptyKitTrays_LargeContainer)
VALUES(24, 'empty_kit_tray_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(78, 'kit_tray_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_c_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(79, 'point_kit_a2b2c1_c_1', 0.060000, -0.090000, 0.045000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(80, 'part_c_7_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(80, 'part_c_7_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(80, 'part_c_7_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(81, 'part_gripper_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(82, 'part_gripper_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(83, 'part_b_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(84, 'part_b_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(84, 'part_b_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(84, 'part_b_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(85, 'part_c_1_point', 0.110000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(86, 'robot_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(87, 'part_c_8_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(88, 'x_axis_kit_a2b1c1_c_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(89, 'tray_gripper_holder_point', -0.250000, 0.000000, 0.500000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(25, 'part_c_tray', 8, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(90, 'part_c_8_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(90, 'part_c_8_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(90, 'part_c_8_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(26, 'finished_kit_box', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(91, 'part_c_5_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(91, 'part_c_5_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(91, 'part_c_5_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(92, 'kit_tray_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(92, 'kit_tray_3_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(92, 'kit_tray_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(93, 'part_b_2_point', -0.240000, 0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(94, 'part_gripper_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(95, 'x_axis_kit_a2b1c1_b_1', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_3', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(27, 'kit_tray_3', 3, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_2', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(28, 'kit_tray_2', 2, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_1', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(29, 'kit_tray_1', 1, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(96, 'part_a_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(97, 'finished_kit_box_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(98, 'part_c_8_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(30, 'empty_kit_tray_box', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(99, 'z_axis_kit_a2b2c1_a_1', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(31, 'part_a_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(100, 'part_c_4_point', -0.330000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(101, 'x_axis_kit_a2b1c1_a_2', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(102, 'x_axis_kit_a2b1c1_a_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(103, 'part_c_8_point', -0.330000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(104, 'part_b_6_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(105, 'part_a_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(106, 'part_b_4_point', 0.240000, 0.120000, 0.067500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_receiver', NULL);

INSERT INTO LargeBoxWithKits
(LargeBoxWithKitsID, _NAME, hasLargeBoxWithKits_Capacity, hasLargeBoxWithKits_LargeContainer, hasLargeBoxWithKits_KitDesign)
VALUES(32, 'finished_kit_receiver', 12, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(107, 'shape_kit_tray', 'Shape of KitTrays');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(107, 'shape_kit_tray', 'USARSim', 'WCKitTraySmall', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(108, 'part_b_8_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(109, 'part_b_5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(110, 'part_c_5_point', 0.110000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(111, 'part_c_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(33, 'part_b_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(112, 'part_c_7_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(113, 'part_c_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(113, 'part_c_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(113, 'part_c_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(114, 'part_c_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(115, 'kit_tray_3_point', 2.000000, 0.000000, 0.145000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(116, 'part_c_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(117, 'kit_tray_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(117, 'kit_tray_1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(117, 'kit_tray_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(118, 'part_b_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(119, 'tray_gripper_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(120, 'part_c_7_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(121, 'part_b_7_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_a');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(122, 'shape_parts_tray_a', 'Shape of PartsTray_A');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(122, 'shape_parts_tray_a', 'USARSim', 'PartATray', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(123, 'part_b_3_point', 0.080000, 0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_b');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(124, 'shape_parts_tray_b', 'Shape of PartsTray_B');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(124, 'shape_parts_tray_b', 'USARSim', 'PartBTray', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_c');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(125, 'shape_parts_tray_c', 'Shape of PartsTray_C');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(125, 'shape_parts_tray_c', 'USARSim', 'PartCTray', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(126, 'part_a_4_point', -0.159000, 0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(127, 'z_axis_kit_a2b1c1_a_2', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_InternalShape, hasSolidObject_PrimaryLocation)
VALUES('work_table_1', NULL, NULL);

INSERT INTO WorkTable
(WorkTableID, _NAME)
VALUES(34, 'work_table_1');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(128, 'z_axis_kit_a2b1c1_a_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_in_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(129, 'relative_location_in_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(129, 'relative_location_in_1', 'The  KittingWorkstation is in kitting_workstation_1');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(129, 'relative_location_in_1');

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(130, 'finished_kit_receiver_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(131, 'part_b_supply_point', 0.050000, 1.500000, 0.200000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_b_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(132, 'point_kit_a2b2c1_b_2', 0.171000, 0.215000, 0.080000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_b_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(133, 'point_kit_a2b2c1_b_1', 0.219000, -0.166000, 0.080000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(134, 'part_a_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(135, 'kit_tray_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_c_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(136, 'point_kit_a2b1c1_c_1', 0.400000, 0.500000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(137, 'part_b_8_point', 0.240000, -0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(138, 'part_b_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(139, 'part_c_2_point', 0.330000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(140, 'part_b_5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(141, 'kit_tray_2_point', 2.000000, 0.000000, 0.075000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(142, 'part_gripper_holder_point', 0.250000, 0.000000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(143, 'part_b_8_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(144, 'part_c_7_point', -0.110000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('point_max');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(145, 'point_max', 1.000000, 1.000000, 2.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(146, 'part_c_6_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(147, 'part_c_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(147, 'part_c_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(147, 'part_c_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(148, 'part_b_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_c_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(149, 'part_ref_and_pose_kit_a2b2c1_c_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper_holder', NULL);

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_ChangingStation)
VALUES(35, 'tray_gripper_holder', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(150, 'part_c_6_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(150, 'part_c_6_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(150, 'part_c_6_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_c_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(151, 'part_ref_and_pose_kit_a2b1c1_c_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(152, 'part_a_3_point', -0.159000, -0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('box_volume_1');

INSERT INTO BoxVolume
(BoxVolumeID, _NAME, hasBoxVolume_MaximumPoint, hasBoxVolume_MinimumPoint)
VALUES(153, 'box_volume_1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(154, 'part_a_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(154, 'part_a_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(154, 'part_a_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(155, 'part_b_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(156, 'changing_station_base_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(157, 'empty_kit_tray_box_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(158, 'part_c_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(158, 'part_c_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(158, 'part_c_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(159, 'changing_station_base_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(159, 'changing_station_base_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(159, 'changing_station_base_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(160, 'part_c_5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(161, 'part_b_6_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_a_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(162, 'part_ref_and_pose_kit_a2b2c1_a_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_a_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(163, 'part_ref_and_pose_kit_a2b2c1_a_2', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(164, 'part_a_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(165, 'part_a_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(165, 'part_a_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(165, 'part_a_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(166, 'part_a_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(167, 'changing_station_base_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(168, 'part_c_supply_point', -3.000000, 0.750000, 0.200000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(169, 'part_b_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(170, 'finished_kit_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(170, 'finished_kit_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(170, 'finished_kit_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(171, 'part_c_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(172, 'finished_kit_receiver_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(173, 'empty_kit_tray_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(174, 'part_a_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(175, 'part_b_7_point', 0.080000, -0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(176, 'part_c_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(176, 'part_c_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(176, 'part_c_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(177, 'part_a_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(178, 'part_b_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(179, 'changing_station_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(179, 'changing_station_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(179, 'changing_station_pose');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(180, 'z_axis_kit_a2b1c1_b_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_on_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(181, 'relative_location_on_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(181, 'relative_location_on_1', 'The tray_gripper is on robot_1');

INSERT INTO RelativeLocationOn
(RelativeLocationOnID, _NAME)
VALUES(181, 'relative_location_on_1');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(182, 'x_axis_kit_a2b2c1_a_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b1c1');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(183, 'kit_design_a2b1c1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b2c1');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(184, 'kit_design_a2b2c1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(185, 'x_axis_kit_a2b2c1_a_2', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(186, 'part_c_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(187, 'empty_kit_tray_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(187, 'empty_kit_tray_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(187, 'empty_kit_tray_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(188, 'part_a_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(188, 'part_a_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(188, 'part_a_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(189, 'part_a_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(190, 'finished_kit_receiver_point', 1.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(191, 'x_axis_kit_a2b2c1_c_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(192, 'part_c_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(193, 'part_b_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(194, 'part_a_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_b_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(195, 'x_axis_kit_a2b2c1_b_2', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(196, 'x_axis_kit_a2b2c1_b_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(197, 'empty_kit_tray_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(197, 'empty_kit_tray_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(197, 'empty_kit_tray_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(198, 'finished_kit_box_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(199, 'robot_point', 3.000000, 0.000000, 2.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('robot_1', NULL);

INSERT INTO Robot
(RobotID, _NAME, hasRobot_Description, hasRobot_MaximumLoadWeight)
VALUES(36, 'robot_1', 'this is the robot', 7.000000);

INSERT INTO hasRobot_WorkVolume
(RobotID, BoxVolumeID)
VALUES(36, 153);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(200, 'part_c_5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(201, 'part_c_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kitting_workstation_1', NULL);

INSERT INTO KittingWorkstation
(KittingWorkstationID, _NAME, hasWorkstation_LengthUnit, hasWorkstation_AngleUnit, hasWorkstation_WeightUnit, hasWorkstation_ChangingStation, hasWorkstation_WorkTable, hasWorkstation_Robot)
VALUES(37, 'kitting_workstation_1', 'meter', 'degree', 'kilogram', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(202, 'empty_kit_tray_box_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(203, 'robot_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(38, 'part_a_1', 'a1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(204, 'part_a_2_point', 0.159000, -0.159000, 0.027500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(39, 'part_a_3', 'a3', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(205, 'part_b_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(40, 'part_a_2', 'a2', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(41, 'part_a_4', 'a4', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_b_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(206, 'point_kit_a2b1c1_b_1', 0.200000, 0.500000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(207, 'part_c_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(208, 'kit_tray_1_point', 0.050000, 0.750000, 0.200000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('changing_station_1', NULL);

INSERT INTO EndEffectorChangingStation
(EndEffectorChangingStationID, _NAME, hasChangingStation_Base)
VALUES(42, 'changing_station_1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(209, 'kit_tray_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(210, 'empty_kit_tray_box_point', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(211, 'z_axis_kit_a2b2c1_b_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_b_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(212, 'z_axis_kit_a2b2c1_b_2', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(213, 'work_table_point', 3.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(214, 'part_c_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(214, 'part_c_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(214, 'part_c_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(215, 'changing_station_point', 7.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(216, 'z_axis_kit_a2b2c1_c_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(217, 'part_a_supply_point', -2.850000, 1.600000, 0.200000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(218, 'kit_tray_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(218, 'kit_tray_2_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(218, 'kit_tray_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(219, 'part_b_5_point', -0.080000, -0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_b_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(220, 'part_ref_and_pose_kit_a2b2c1_b_2', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_b_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(221, 'part_ref_and_pose_kit_a2b2c1_b_1', NULL, NULL, NULL, NULL, NULL);



UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_2_point', hasPoseLocation_ZAxis= 'part_b_2_z_axis', hasPoseLocation_XAxis= 'part_b_2_x_axis' WHERE _NAME = 'part_b_2_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'robot_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='robot_point', hasPoseLocation_ZAxis= 'robot_z_axis', hasPoseLocation_XAxis= 'robot_x_axis' WHERE _NAME = 'robot_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_tray_pose' WHERE _NAME = 'part_b_tray';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_tray_b' WHERE _NAME = 'part_b_tray';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_3_point', hasPoseLocation_ZAxis= 'part_b_3_z_axis', hasPoseLocation_XAxis= 'part_b_3_x_axis' WHERE _NAME = 'part_b_3_pose';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_part_a' WHERE _NAME = 'stock_keeping_unit_part_a';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'finished_kit_receiver_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='finished_kit_receiver_point', hasPoseLocation_ZAxis= 'finished_kit_receiver_z_axis', hasPoseLocation_XAxis= 'finished_kit_receiver_x_axis' WHERE _NAME = 'finished_kit_receiver_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_5_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_5_point', hasPoseLocation_ZAxis= 'part_b_5_z_axis', hasPoseLocation_XAxis= 'part_b_5_x_axis' WHERE _NAME = 'part_b_5_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_4_point', hasPoseLocation_ZAxis= 'part_b_4_z_axis', hasPoseLocation_XAxis= 'part_b_4_x_axis' WHERE _NAME = 'part_b_4_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_4_point', hasPoseLocation_ZAxis= 'part_c_4_z_axis', hasPoseLocation_XAxis= 'part_c_4_x_axis' WHERE _NAME = 'part_c_4_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gripper_holder_pose' WHERE _NAME = 'part_gripper_holder';

UPDATE EndEffectorHolder
 SET  hadByEndEffectorHolder_ChangingStation='changing_station_1', hasEndEffectorHolder_EndEffector= 'part_gripper' WHERE _NAME = 'part_gripper_holder';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'tray_gripper_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='tray_gripper_holder_point', hasPoseLocation_ZAxis= 'tray_gripper_holder_z_axis', hasPoseLocation_XAxis= 'tray_gripper_holder_x_axis' WHERE _NAME = 'tray_gripper_holder_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_b_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_supply_point', hasPoseLocation_ZAxis= 'part_b_supply_z_axis', hasPoseLocation_XAxis= 'part_b_supply_x_axis' WHERE _NAME = 'part_b_supply_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gripper_pose' WHERE _NAME = 'part_gripper';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_tray' WHERE _NAME = 'stock_keeping_unit_kit_tray';

UPDATE SolidObject
 SET  hasSolidObject_InternalShape='shape_changing_station_base', hasSolidObject_PrimaryLocation= 'changing_station_base_pose' WHERE _NAME = 'changing_station_base';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_5_pose' WHERE _NAME = 'part_c_5';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply', hasPart_Sku= 'stock_keeping_unit_part_c' WHERE _NAME = 'part_c_5';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_4_pose' WHERE _NAME = 'part_c_4';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply', hasPart_Sku= 'stock_keeping_unit_part_c' WHERE _NAME = 'part_c_4';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_3_pose' WHERE _NAME = 'part_c_3';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply', hasPart_Sku= 'stock_keeping_unit_part_c' WHERE _NAME = 'part_c_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_2_pose' WHERE _NAME = 'part_c_2';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply', hasPart_Sku= 'stock_keeping_unit_part_c' WHERE _NAME = 'part_c_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_1_pose' WHERE _NAME = 'part_c_1';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply', hasPart_Sku= 'stock_keeping_unit_part_c' WHERE _NAME = 'part_c_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply' WHERE _NAME = 'part_a_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_tray_point', hasPoseLocation_ZAxis= 'part_a_tray_z_axis', hasPoseLocation_XAxis= 'part_a_tray_x_axis' WHERE _NAME = 'part_a_tray_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_8_pose' WHERE _NAME = 'part_c_8';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply', hasPart_Sku= 'stock_keeping_unit_part_c' WHERE _NAME = 'part_c_8';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_7_pose' WHERE _NAME = 'part_c_7';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply', hasPart_Sku= 'stock_keeping_unit_part_c' WHERE _NAME = 'part_c_7';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'part_gripper_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gripper_holder_point', hasPoseLocation_ZAxis= 'part_gripper_holder_z_axis', hasPoseLocation_XAxis= 'part_gripper_holder_x_axis' WHERE _NAME = 'part_gripper_holder_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_6_pose' WHERE _NAME = 'part_c_6';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply', hasPart_Sku= 'stock_keeping_unit_part_c' WHERE _NAME = 'part_c_6';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_supply_pose' WHERE _NAME = 'part_c_supply';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_c_tray' WHERE _NAME = 'part_c_supply';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_gripper_holder' WHERE _NAME = 'part_gripper_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gripper_point', hasPoseLocation_ZAxis= 'part_gripper_z_axis', hasPoseLocation_XAxis= 'part_gripper_x_axis' WHERE _NAME = 'part_gripper_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply' WHERE _NAME = 'part_a_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_1_point', hasPoseLocation_ZAxis= 'part_a_1_z_axis', hasPoseLocation_XAxis= 'part_a_1_x_axis' WHERE _NAME = 'part_a_1_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_tray_pose' WHERE _NAME = 'part_a_tray';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_tray_a' WHERE _NAME = 'part_a_tray';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_part_c' WHERE _NAME = 'stock_keeping_unit_part_c';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_part_b' WHERE _NAME = 'stock_keeping_unit_part_b';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_box' WHERE _NAME = 'stock_keeping_unit_kit_box';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_7_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_7_point', hasPoseLocation_ZAxis= 'part_b_7_z_axis', hasPoseLocation_XAxis= 'part_b_7_x_axis' WHERE _NAME = 'part_b_7_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply' WHERE _NAME = 'part_a_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_2_point', hasPoseLocation_ZAxis= 'part_a_2_z_axis', hasPoseLocation_XAxis= 'part_a_2_x_axis' WHERE _NAME = 'part_a_2_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='relative_location_on_1' WHERE _NAME = 'tray_gripper';

UPDATE EndEffector
 SET  hadByEndEffector_Robot='robot_1' WHERE _NAME = 'tray_gripper';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_a_2', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_a_2', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_a_2' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_a_2';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_parts_tray_a' WHERE _NAME = 'stock_keeping_unit_parts_tray_a';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_parts_tray_c' WHERE _NAME = 'stock_keeping_unit_parts_tray_c';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_8_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_8_point', hasPoseLocation_ZAxis= 'part_b_8_z_axis', hasPoseLocation_XAxis= 'part_b_8_x_axis' WHERE _NAME = 'part_b_8_pose';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_parts_tray_b' WHERE _NAME = 'stock_keeping_unit_parts_tray_b';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_a_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_a_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_a_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_a_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_tray_point', hasPoseLocation_ZAxis= 'part_b_tray_z_axis', hasPoseLocation_XAxis= 'part_b_tray_x_axis' WHERE _NAME = 'part_b_tray_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_b', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_b_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_b_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_b_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_b_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'work_table_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='work_table_point', hasPoseLocation_ZAxis= 'work_table_z_axis', hasPoseLocation_XAxis= 'work_table_x_axis' WHERE _NAME = 'work_table_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_1_pose' WHERE _NAME = 'part_b_1';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply', hasPart_Sku= 'stock_keeping_unit_part_b' WHERE _NAME = 'part_b_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_2_pose' WHERE _NAME = 'part_b_2';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply', hasPart_Sku= 'stock_keeping_unit_part_b' WHERE _NAME = 'part_b_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_5_pose' WHERE _NAME = 'part_b_5';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply', hasPart_Sku= 'stock_keeping_unit_part_b' WHERE _NAME = 'part_b_5';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_6_pose' WHERE _NAME = 'part_b_6';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply', hasPart_Sku= 'stock_keeping_unit_part_b' WHERE _NAME = 'part_b_6';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_3_pose' WHERE _NAME = 'part_b_3';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply', hasPart_Sku= 'stock_keeping_unit_part_b' WHERE _NAME = 'part_b_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_4_pose' WHERE _NAME = 'part_b_4';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply', hasPart_Sku= 'stock_keeping_unit_part_b' WHERE _NAME = 'part_b_4';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_7_pose' WHERE _NAME = 'part_b_7';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply', hasPart_Sku= 'stock_keeping_unit_part_b' WHERE _NAME = 'part_b_7';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_6_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_6_point', hasPoseLocation_ZAxis= 'part_b_6_z_axis', hasPoseLocation_XAxis= 'part_b_6_x_axis' WHERE _NAME = 'part_b_6_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_8_pose' WHERE _NAME = 'part_b_8';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply', hasPart_Sku= 'stock_keeping_unit_part_b' WHERE _NAME = 'part_b_8';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_supply_pose' WHERE _NAME = 'empty_kit_tray_supply';

UPDATE LargeBoxWithEmptyKitTrays
 SET  hasLargeBoxWithEmptyKitTrays_LargeContainer='empty_kit_tray_box' WHERE _NAME = 'empty_kit_tray_supply';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_7_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_7_point', hasPoseLocation_ZAxis= 'part_c_7_z_axis', hasPoseLocation_XAxis= 'part_c_7_x_axis' WHERE _NAME = 'part_c_7_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_1_point', hasPoseLocation_ZAxis= 'part_b_1_z_axis', hasPoseLocation_XAxis= 'part_b_1_x_axis' WHERE _NAME = 'part_b_1_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_tray_pose' WHERE _NAME = 'part_c_tray';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_tray_c' WHERE _NAME = 'part_c_tray';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_8_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_8_point', hasPoseLocation_ZAxis= 'part_c_8_z_axis', hasPoseLocation_XAxis= 'part_c_8_x_axis' WHERE _NAME = 'part_c_8_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_box_pose' WHERE _NAME = 'finished_kit_box';

UPDATE LargeContainer
 SET  hasLargeContainer_Sku='stock_keeping_unit_kit_box' WHERE _NAME = 'finished_kit_box';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_5_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_5_point', hasPoseLocation_ZAxis= 'part_c_5_z_axis', hasPoseLocation_XAxis= 'part_c_5_x_axis' WHERE _NAME = 'part_c_5_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_3_point', hasPoseLocation_ZAxis= 'kit_tray_3_z_axis', hasPoseLocation_XAxis= 'kit_tray_3_x_axis' WHERE _NAME = 'kit_tray_3_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_3_pose' WHERE _NAME = 'kit_tray_3';

UPDATE KitTray
 SET  hasKitTray_Sku='stock_keeping_unit_kit_tray', hadByKitTray_LargeBoxWithEmptyKitTrays= 'empty_kit_tray_supply' WHERE _NAME = 'kit_tray_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_2_pose' WHERE _NAME = 'kit_tray_2';

UPDATE KitTray
 SET  hasKitTray_Sku='stock_keeping_unit_kit_tray', hadByKitTray_LargeBoxWithEmptyKitTrays= 'empty_kit_tray_supply' WHERE _NAME = 'kit_tray_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_1_pose' WHERE _NAME = 'kit_tray_1';

UPDATE KitTray
 SET  hasKitTray_Sku='stock_keeping_unit_kit_tray', hadByKitTray_LargeBoxWithEmptyKitTrays= 'empty_kit_tray_supply' WHERE _NAME = 'kit_tray_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_box_pose' WHERE _NAME = 'empty_kit_tray_box';

UPDATE LargeContainer
 SET  hasLargeContainer_Sku='stock_keeping_unit_kit_box' WHERE _NAME = 'empty_kit_tray_box';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_supply_pose' WHERE _NAME = 'part_a_supply';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_a_tray' WHERE _NAME = 'part_a_supply';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_receiver_pose' WHERE _NAME = 'finished_kit_receiver';

UPDATE LargeBoxWithKits
 SET  hasLargeBoxWithKits_LargeContainer='finished_kit_box', hasLargeBoxWithKits_KitDesign= 'kit_design_a2b1c1' WHERE _NAME = 'finished_kit_receiver';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_supply_pose' WHERE _NAME = 'part_b_supply';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_b_tray' WHERE _NAME = 'part_b_supply';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_tray_point', hasPoseLocation_ZAxis= 'part_c_tray_z_axis', hasPoseLocation_XAxis= 'part_c_tray_x_axis' WHERE _NAME = 'part_c_tray_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_1_point', hasPoseLocation_ZAxis= 'kit_tray_1_z_axis', hasPoseLocation_XAxis= 'kit_tray_1_x_axis' WHERE _NAME = 'kit_tray_1_pose';

UPDATE SolidObject
 SET  hasSolidObject_InternalShape='shape_work_table', hasSolidObject_PrimaryLocation= 'work_table_pose' WHERE _NAME = 'work_table_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'relative_location_in_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_2_point', hasPoseLocation_ZAxis= 'part_c_2_z_axis', hasPoseLocation_XAxis= 'part_c_2_x_axis' WHERE _NAME = 'part_c_2_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_c', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_c_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_c_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_c_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_c_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='tray_gripper_holder_pose' WHERE _NAME = 'tray_gripper_holder';

UPDATE EndEffectorHolder
 SET  hadByEndEffectorHolder_ChangingStation='changing_station_1' WHERE _NAME = 'tray_gripper_holder';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_6_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_6_point', hasPoseLocation_ZAxis= 'part_c_6_z_axis', hasPoseLocation_XAxis= 'part_c_6_x_axis' WHERE _NAME = 'part_c_6_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_c', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_c_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_c_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_c_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_c_1';

UPDATE BoxVolume
 SET  hasBoxVolume_MaximumPoint='point_max', hasBoxVolume_MinimumPoint= 'point_min' WHERE _NAME = 'box_volume_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply' WHERE _NAME = 'part_a_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_4_point', hasPoseLocation_ZAxis= 'part_a_4_z_axis', hasPoseLocation_XAxis= 'part_a_4_x_axis' WHERE _NAME = 'part_a_4_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_3_point', hasPoseLocation_ZAxis= 'part_c_3_z_axis', hasPoseLocation_XAxis= 'part_c_3_x_axis' WHERE _NAME = 'part_c_3_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'changing_station_base_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='changing_station_base_point', hasPoseLocation_ZAxis= 'changing_station_base_z_axis', hasPoseLocation_XAxis= 'changing_station_base_x_axis' WHERE _NAME = 'changing_station_base_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_a_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_a_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_a_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_a_1';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_a_2', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_a_2', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_a_2' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_a_2';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply' WHERE _NAME = 'part_a_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_3_point', hasPoseLocation_ZAxis= 'part_a_3_z_axis', hasPoseLocation_XAxis= 'part_a_3_x_axis' WHERE _NAME = 'part_a_3_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='finished_kit_receiver' WHERE _NAME = 'finished_kit_box_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='finished_kit_box_point', hasPoseLocation_ZAxis= 'finished_kit_box_z_axis', hasPoseLocation_XAxis= 'finished_kit_box_x_axis' WHERE _NAME = 'finished_kit_box_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_c_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_supply_point', hasPoseLocation_ZAxis= 'part_c_supply_z_axis', hasPoseLocation_XAxis= 'part_c_supply_x_axis' WHERE _NAME = 'part_c_supply_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'changing_station_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='changing_station_point', hasPoseLocation_ZAxis= 'changing_station_z_axis', hasPoseLocation_XAxis= 'changing_station_x_axis' WHERE _NAME = 'changing_station_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='robot_1' WHERE _NAME = 'relative_location_on_1';

UPDATE KitDesign
 SET  hadByKitDesign_Workstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_design_a2b1c1';

UPDATE KitDesign
 SET  hadByKitDesign_Workstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_design_a2b2c1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'empty_kit_tray_box_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='empty_kit_tray_box_point', hasPoseLocation_ZAxis= 'empty_kit_tray_box_z_axis', hasPoseLocation_XAxis= 'empty_kit_tray_box_x_axis' WHERE _NAME = 'empty_kit_tray_box_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_a_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_supply_point', hasPoseLocation_ZAxis= 'part_a_supply_z_axis', hasPoseLocation_XAxis= 'part_a_supply_x_axis' WHERE _NAME = 'part_a_supply_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'empty_kit_tray_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='empty_kit_tray_supply_point', hasPoseLocation_ZAxis= 'empty_kit_tray_supply_z_axis', hasPoseLocation_XAxis= 'empty_kit_tray_supply_x_axis' WHERE _NAME = 'empty_kit_tray_supply_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='robot_pose' WHERE _NAME = 'robot_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='relative_location_in_1' WHERE _NAME = 'kitting_workstation_1';

UPDATE KittingWorkstation
 SET  hasWorkstation_ChangingStation='changing_station_1', hasWorkstation_WorkTable= 'work_table_1', hasWorkstation_Robot= 'robot_1' WHERE _NAME = 'kitting_workstation_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_1_pose' WHERE _NAME = 'part_a_1';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply', hasPart_Sku= 'stock_keeping_unit_part_a' WHERE _NAME = 'part_a_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_3_pose' WHERE _NAME = 'part_a_3';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply', hasPart_Sku= 'stock_keeping_unit_part_a' WHERE _NAME = 'part_a_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_2_pose' WHERE _NAME = 'part_a_2';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply', hasPart_Sku= 'stock_keeping_unit_part_a' WHERE _NAME = 'part_a_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_4_pose' WHERE _NAME = 'part_a_4';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply', hasPart_Sku= 'stock_keeping_unit_part_a' WHERE _NAME = 'part_a_4';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='changing_station_pose' WHERE _NAME = 'changing_station_1';

UPDATE EndEffectorChangingStation
 SET  hasChangingStation_Base='changing_station_base' WHERE _NAME = 'changing_station_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_1_point', hasPoseLocation_ZAxis= 'part_c_1_z_axis', hasPoseLocation_XAxis= 'part_c_1_x_axis' WHERE _NAME = 'part_c_1_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_2_point', hasPoseLocation_ZAxis= 'kit_tray_2_z_axis', hasPoseLocation_XAxis= 'kit_tray_2_x_axis' WHERE _NAME = 'kit_tray_2_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_b', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_b_2', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_b_2', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_b_2' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_b_2';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_b', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_b_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_b_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_b_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_b_1';