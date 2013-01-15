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
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(5, 'stock_keeping_unit_part_a', 'SKU for Part A', 0.180000, NULL);

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

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gripper_holder', NULL);

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hasEndEffectorHolder_EndEffector)
VALUES(2, 'part_gripper_holder', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(11, 'tray_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(11, 'tray_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(11, 'tray_gripper_holder_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(12, 'part_c_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(12, 'part_c_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(12, 'part_c_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(13, 'part_c_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(14, 'part_b_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(14, 'part_b_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(14, 'part_b_supply_pose');

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
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(15, 'stock_keeping_unit_kit_tray', 'SKU for KitTrays', 0.200000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(15, 3);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_a_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(16, 'point_kit_a2b1c1_a_2', 0.400000, 0.300000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_5', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(4, 'part_c_5', 'c5', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_a_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(17, 'point_kit_a2b1c1_a_1', 0.200000, 0.300000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(5, 'part_c_4', 'c4', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(6, 'part_c_3', 'c3', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(7, 'part_c_2', 'c2', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(8, 'part_c_1', 'c1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(18, 'kit_tray_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(19, 'part_a_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(19, 'part_a_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(19, 'part_a_tray_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_8', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(9, 'part_c_8', 'c8', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(20, 'part_c_6_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_7', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(10, 'part_c_7', 'c7', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(21, 'part_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(21, 'part_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(21, 'part_gripper_holder_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_6', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(11, 'part_c_6', 'c6', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(12, 'part_c_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(22, 'part_gripper_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(23, 'part_gripper_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(23, 'part_gripper_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(23, 'part_gripper_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(24, 'part_a_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(25, 'part_a_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(25, 'part_a_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(25, 'part_a_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(26, 'part_b_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(27, 'part_c_6_point', 0.330000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(28, 'part_b_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(13, 'part_a_tray', 6, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(29, 'part_b_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_c');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(30, 'stock_keeping_unit_part_c', 'SKU for Part C', 0.180000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(30, 3);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_b');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(31, 'stock_keeping_unit_part_b', 'SKU for Part B', 0.180000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(31, 3);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(32, 'part_b_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(33, 'finished_kit_box_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_box');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(34, 'stock_keeping_unit_kit_box', 'SKU for Boxes for Kits and KitTrays', 1.200000, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(35, 'z_axis_kit_a2b1c1_c_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(36, 'part_b_7_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(36, 'part_b_7_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(36, 'part_b_7_pose');

INSERT INTO DataThing
(_NAME)
VALUES('point_min');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(37, 'point_min', -1.000000, -1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(38, 'tray_gripper_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(39, 'part_a_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_a');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Model, hasShapeDesign_Description)
VALUES(40, 'shape_part_a', 'PartA', 'Shape of PartA');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(40, 'shape_part_a', 0.080000, 'true', 0.150000, 0.100000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_b');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Model, hasShapeDesign_Description)
VALUES(41, 'shape_part_b', 'PartB', 'Shape of PartB');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(41, 'shape_part_b', 0.080000, 'true', 0.150000, 0.120000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(42, 'part_a_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(42, 'part_a_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(42, 'part_a_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_c');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Model, hasShapeDesign_Description)
VALUES(43, 'shape_part_c', 'PartC', 'Shape of PartC');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(43, 'shape_part_c', 0.080000, 'true', 0.150000, 0.150000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(44, 'part_c_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper', NULL);

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_Weight, hasEffector_MaximumLoadWeight)
VALUES(14, 'tray_gripper', 'large single cup vacuum effector', 0.040000, 0.500000);

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(14, 'tray_gripper', 0.040000, 0.100000);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(14, 'tray_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_box');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Model, hasShapeDesign_Description)
VALUES(45, 'shape_kit_box', 'KitBox', 'Shape of boxes to hold kits and kit trays');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(45, 'shape_kit_box', 0.700000, 'false', 0.800000, 0.900000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(46, 'part_c_3_point', -0.110000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(47, 'part_gripper_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_a_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(48, 'part_ref_and_pose_kit_a2b1c1_a_2', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_a');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(49, 'stock_keeping_unit_parts_tray_a', 'SKU for PartsTray_A', 0.200000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(49, 14);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(50, 'part_a_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_c');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(51, 'stock_keeping_unit_parts_tray_c', 'SKU for PartsTray_C', 0.200000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(51, 14);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(52, 'part_b_1_point', -0.080000, 0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(53, 'work_table_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(54, 'part_b_7_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(55, 'part_b_6_point', -0.240000, -0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(56, 'part_b_8_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(56, 'part_b_8_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(56, 'part_b_8_pose');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_b');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(57, 'stock_keeping_unit_parts_tray_b', 'SKU for PartsTray_B', 0.200000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(57, 14);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_a_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(58, 'part_ref_and_pose_kit_a2b1c1_a_1', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(59, 'changing_station_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(60, 'part_c_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(61, 'part_b_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(61, 'part_b_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(61, 'part_b_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_b_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(62, 'part_ref_and_pose_kit_a2b1c1_b_1', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(63, 'work_table_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(63, 'work_table_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(63, 'work_table_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(64, 'part_a_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(65, 'part_a_1_point', 0.159000, 0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_a_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(66, 'point_kit_a2b2c1_a_2', -0.159000, -0.149000, 0.036000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(67, 'part_c_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_a_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(68, 'point_kit_a2b2c1_a_1', -0.159000, 0.145000, 0.036000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(15, 'part_b_1', 'b1', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(16, 'part_b_2', 'b2', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_5', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(17, 'part_b_5', 'b5', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_6', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(18, 'part_b_6', 'b6', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(19, 'part_b_3', 'b3', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(20, 'part_b_4', 'b4', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_7', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(21, 'part_b_7', 'b7', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(69, 'kit_tray_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(70, 'part_b_6_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(70, 'part_b_6_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(70, 'part_b_6_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_8', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(22, 'part_b_8', 'b8', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(71, 'changing_station_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(72, 'kit_tray_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(73, 'empty_kit_tray_supply_point', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(74, 'z_axis_kit_a2b2c1_a_2', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_supply', NULL);

INSERT INTO LargeBoxWithEmptyKitTrays
(LargeBoxWithEmptyKitTraysID, _NAME, hasLargeBoxWithEmptyKitTrays_LargeContainer)
VALUES(23, 'empty_kit_tray_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(75, 'kit_tray_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_c_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(76, 'point_kit_a2b2c1_c_1', 0.060000, -0.090000, 0.045000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(77, 'part_c_7_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(77, 'part_c_7_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(77, 'part_c_7_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(78, 'part_gripper_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(79, 'part_gripper_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(80, 'part_b_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(81, 'part_b_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(81, 'part_b_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(81, 'part_b_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(82, 'part_c_1_point', 0.110000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(83, 'robot_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(84, 'part_c_8_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(85, 'x_axis_kit_a2b1c1_c_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(86, 'tray_gripper_holder_point', -0.250000, 0.000000, 0.500000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(24, 'part_c_tray', 8, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(87, 'part_c_8_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(87, 'part_c_8_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(87, 'part_c_8_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(25, 'finished_kit_box', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(88, 'part_c_5_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(88, 'part_c_5_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(88, 'part_c_5_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(89, 'kit_tray_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(89, 'kit_tray_3_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(89, 'kit_tray_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(90, 'part_b_2_point', -0.240000, 0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(91, 'part_gripper_point', 0.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_3', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku)
VALUES(26, 'kit_tray_3', 3, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(92, 'x_axis_kit_a2b1c1_b_1', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_2', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku)
VALUES(27, 'kit_tray_2', 2, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_1', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku)
VALUES(28, 'kit_tray_1', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(93, 'part_a_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(94, 'finished_kit_box_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(95, 'part_c_8_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(29, 'empty_kit_tray_box', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(96, 'z_axis_kit_a2b2c1_a_1', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(30, 'part_a_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(97, 'part_c_4_point', -0.330000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(98, 'x_axis_kit_a2b1c1_a_2', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(99, 'x_axis_kit_a2b1c1_a_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(100, 'part_c_8_point', -0.330000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(101, 'part_b_6_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(102, 'part_a_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(103, 'part_b_4_point', 0.240000, 0.120000, 0.067500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_receiver', NULL);

INSERT INTO LargeBoxWithKits
(LargeBoxWithKitsID, _NAME, hasLargeBoxWithKits_Capacity, hasLargeBoxWithKits_LargeContainer, hasLargeBoxWithKits_KitDesign)
VALUES(31, 'finished_kit_receiver', 12, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Model, hasShapeDesign_Description)
VALUES(104, 'shape_kit_tray', 'WCKitTray', 'Shape of KitTrays');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(104, 'shape_kit_tray', 0.300000, 'false', 0.150000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(105, 'part_b_8_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(106, 'part_b_5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(107, 'part_c_5_point', 0.110000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(108, 'part_c_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(32, 'part_b_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(109, 'part_c_7_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(110, 'part_c_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(110, 'part_c_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(110, 'part_c_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(111, 'part_c_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(112, 'kit_tray_3_point', 0.000000, 0.000000, 0.300000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(113, 'part_c_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(114, 'kit_tray_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(114, 'kit_tray_1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(114, 'kit_tray_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(115, 'part_b_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(116, 'part_c_7_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(117, 'tray_gripper_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(118, 'part_b_7_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_a');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Model, hasShapeDesign_Description)
VALUES(119, 'shape_parts_tray_a', 'PartATray', 'Shape of PartsTray_A');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME)
VALUES(119, 'shape_parts_tray_a');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(120, 'part_b_3_point', 0.080000, 0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_b');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Model, hasShapeDesign_Description)
VALUES(121, 'shape_parts_tray_b', 'PartBTray', 'Shape of PartsTray_B');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME)
VALUES(121, 'shape_parts_tray_b');

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_c');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Model, hasShapeDesign_Description)
VALUES(122, 'shape_parts_tray_c', 'PartCTray', 'Shape of PartsTray_C');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME)
VALUES(122, 'shape_parts_tray_c');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(123, 'part_a_4_point', -0.159000, 0.159000, 0.027500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('work_table_1', NULL);

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Height, hasBox_Width, hasBox_Length)
VALUES(33, 'work_table_1', 0.500000, 0.800000, 1.600000);

INSERT INTO WorkTable
(WorkTableID, _NAME)
VALUES(33, 'work_table_1');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(124, 'z_axis_kit_a2b1c1_a_2', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(125, 'z_axis_kit_a2b1c1_a_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_in_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(126, 'relative_location_in_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(126, 'relative_location_in_1', 'The  KittingWorkstation is in kitting_workstation_1');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(126, 'relative_location_in_1');

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(127, 'finished_kit_receiver_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(128, 'part_b_supply_point', 5.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_b_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(129, 'point_kit_a2b2c1_b_2', 0.171000, 0.215000, 0.080000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_b_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(130, 'point_kit_a2b2c1_b_1', 0.219000, -0.166000, 0.080000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(131, 'part_a_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(132, 'kit_tray_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_c_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(133, 'point_kit_a2b1c1_c_1', 0.400000, 0.500000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(134, 'part_b_8_point', 0.240000, -0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(135, 'part_b_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(136, 'part_c_2_point', 0.330000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(137, 'part_b_5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(138, 'kit_tray_2_point', 0.000000, 0.000000, 0.150000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(139, 'part_gripper_holder_point', 0.250000, 0.000000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(140, 'part_b_8_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(141, 'part_c_7_point', -0.110000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('point_max');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(142, 'point_max', 1.000000, 1.000000, 2.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(143, 'part_c_6_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(144, 'part_c_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(144, 'part_c_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(144, 'part_c_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(145, 'part_b_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_c_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(146, 'part_ref_and_pose_kit_a2b2c1_c_1', NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper_holder', NULL);

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME)
VALUES(34, 'tray_gripper_holder');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(147, 'part_c_6_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(147, 'part_c_6_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(147, 'part_c_6_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_c_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(148, 'part_ref_and_pose_kit_a2b1c1_c_1', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(149, 'part_a_3_point', -0.159000, -0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('box_volume_1');

INSERT INTO BoxVolume
(BoxVolumeID, _NAME, hasBoxVolume_MaximumPoint, hasBoxVolume_MinimumPoint)
VALUES(150, 'box_volume_1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(151, 'part_a_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(151, 'part_a_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(151, 'part_a_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(152, 'part_b_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(153, 'empty_kit_tray_box_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(154, 'part_c_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(154, 'part_c_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(154, 'part_c_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(155, 'part_c_5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(156, 'part_b_6_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_a_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(157, 'part_ref_and_pose_kit_a2b2c1_a_1', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_a_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(158, 'part_ref_and_pose_kit_a2b2c1_a_2', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(159, 'part_a_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(159, 'part_a_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(159, 'part_a_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(160, 'part_a_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(161, 'part_a_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(162, 'part_c_supply_point', 6.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(163, 'part_b_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(164, 'finished_kit_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(164, 'finished_kit_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(164, 'finished_kit_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(165, 'part_c_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(166, 'finished_kit_receiver_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(167, 'empty_kit_tray_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(168, 'part_a_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(169, 'part_b_7_point', 0.080000, -0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(170, 'part_c_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(170, 'part_c_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(170, 'part_c_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(171, 'part_a_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(172, 'part_b_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(173, 'changing_station_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(173, 'changing_station_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(173, 'changing_station_pose');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(174, 'z_axis_kit_a2b1c1_b_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_on_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(175, 'relative_location_on_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(175, 'relative_location_on_1', 'The tray_gripper is on robot_1');

INSERT INTO RelativeLocationOn
(RelativeLocationOnID, _NAME)
VALUES(175, 'relative_location_on_1');

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b1c1');

INSERT INTO KitDesign
(KitDesignID, _NAME, hasKitDesign_KitTraySku)
VALUES(176, 'kit_design_a2b1c1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(177, 'x_axis_kit_a2b2c1_a_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b2c1');

INSERT INTO KitDesign
(KitDesignID, _NAME, hasKitDesign_KitTraySku)
VALUES(178, 'kit_design_a2b2c1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(179, 'x_axis_kit_a2b2c1_a_2', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(180, 'part_c_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(181, 'empty_kit_tray_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(181, 'empty_kit_tray_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(181, 'empty_kit_tray_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(182, 'part_a_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(182, 'part_a_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(182, 'part_a_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(183, 'part_a_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(184, 'finished_kit_receiver_point', 1.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(185, 'x_axis_kit_a2b2c1_c_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(186, 'part_c_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(187, 'part_b_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(188, 'part_a_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_b_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(189, 'x_axis_kit_a2b2c1_b_2', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(190, 'x_axis_kit_a2b2c1_b_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(191, 'empty_kit_tray_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(191, 'empty_kit_tray_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(191, 'empty_kit_tray_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('robot_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(192, 'robot_point', 3.000000, 0.000000, 2.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(193, 'finished_kit_box_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('robot_1', NULL);

INSERT INTO Robot
(RobotID, _NAME, hasRobot_Description, hasRobot_MaximumLoadWeight)
VALUES(35, 'robot_1', 'this is the robot', 7.000000);

INSERT INTO hasRobot_WorkVolume
(RobotID, BoxVolumeID)
VALUES(35, 150);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(194, 'part_c_5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(195, 'part_c_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kitting_workstation_1', NULL);

INSERT INTO KittingWorkstation
(KittingWorkstationID, _NAME, hasWorkstation_LengthUnit, hasWorkstation_WeightUnit, hasWorkstation_AngleUnit, hasWorkstation_ChangingStation, hasWorkstation_WorkTable, hasWorkstation_Robot)
VALUES(36, 'kitting_workstation_1', 'meter', 'kilogram', 'degree', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(196, 'empty_kit_tray_box_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(197, 'robot_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(37, 'part_a_1', 'a1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(198, 'part_a_2_point', 0.159000, -0.159000, 0.027500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(38, 'part_a_3', 'a3', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(39, 'part_a_2', 'a2', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(199, 'part_b_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(40, 'part_a_4', 'a4', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_b_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(200, 'point_kit_a2b1c1_b_1', 0.200000, 0.500000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(201, 'part_c_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(202, 'kit_tray_1_point', 0.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('changing_station_1', NULL);

INSERT INTO EndEffectorChangingStation
(EndEffectorChangingStationID, _NAME)
VALUES(41, 'changing_station_1');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(203, 'kit_tray_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(204, 'empty_kit_tray_box_point', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(205, 'z_axis_kit_a2b2c1_b_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_b_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(206, 'z_axis_kit_a2b2c1_b_2', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(207, 'work_table_point', 3.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(208, 'part_c_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(208, 'part_c_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(208, 'part_c_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(209, 'changing_station_point', 7.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(210, 'z_axis_kit_a2b2c1_c_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(211, 'part_a_supply_point', 4.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(212, 'kit_tray_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(212, 'kit_tray_2_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(212, 'kit_tray_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(213, 'part_b_5_point', -0.080000, -0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_b_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(214, 'part_ref_and_pose_kit_a2b2c1_b_2', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_b_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(215, 'part_ref_and_pose_kit_a2b2c1_b_1', NULL, NULL, NULL, NULL);



UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_2_pose';

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
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_3_point', hasPoseLocation_ZAxis= 'part_b_3_z_axis', hasPoseLocation_XAxis= 'part_b_3_x_axis' WHERE _NAME = 'part_b_3_pose';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='shape_part_a' WHERE _NAME = 'stock_keeping_unit_part_a';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'finished_kit_receiver_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='finished_kit_receiver_point', hasPoseLocation_ZAxis= 'finished_kit_receiver_z_axis', hasPoseLocation_XAxis= 'finished_kit_receiver_x_axis' WHERE _NAME = 'finished_kit_receiver_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_5_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_5_point', hasPoseLocation_ZAxis= 'part_b_5_z_axis', hasPoseLocation_XAxis= 'part_b_5_x_axis' WHERE _NAME = 'part_b_5_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_4_point', hasPoseLocation_ZAxis= 'part_b_4_z_axis', hasPoseLocation_XAxis= 'part_b_4_x_axis' WHERE _NAME = 'part_b_4_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gripper_holder_pose' WHERE _NAME = 'part_gripper_holder';

UPDATE EndEffectorHolder
 SET  hasEndEffectorHolder_EndEffector='part_gripper' WHERE _NAME = 'part_gripper_holder';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'tray_gripper_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='tray_gripper_holder_point', hasPoseLocation_ZAxis= 'tray_gripper_holder_z_axis', hasPoseLocation_XAxis= 'tray_gripper_holder_x_axis' WHERE _NAME = 'tray_gripper_holder_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_4_point', hasPoseLocation_ZAxis= 'part_c_4_z_axis', hasPoseLocation_XAxis= 'part_c_4_x_axis' WHERE _NAME = 'part_c_4_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_b_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_supply_point', hasPoseLocation_ZAxis= 'part_b_supply_z_axis', hasPoseLocation_XAxis= 'part_b_supply_x_axis' WHERE _NAME = 'part_b_supply_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gripper_pose' WHERE _NAME = 'part_gripper';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='shape_kit_tray' WHERE _NAME = 'stock_keeping_unit_kit_tray';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_5_pose' WHERE _NAME = 'part_c_5';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_5';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_4_pose' WHERE _NAME = 'part_c_4';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_4';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_3_pose' WHERE _NAME = 'part_c_3';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_2_pose' WHERE _NAME = 'part_c_2';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_1_pose' WHERE _NAME = 'part_c_1';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply' WHERE _NAME = 'part_a_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_tray_point', hasPoseLocation_ZAxis= 'part_a_tray_z_axis', hasPoseLocation_XAxis= 'part_a_tray_x_axis' WHERE _NAME = 'part_a_tray_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_8_pose' WHERE _NAME = 'part_c_8';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_8';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_7_pose' WHERE _NAME = 'part_c_7';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_7';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'part_gripper_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gripper_holder_point', hasPoseLocation_ZAxis= 'part_gripper_holder_z_axis', hasPoseLocation_XAxis= 'part_gripper_holder_x_axis' WHERE _NAME = 'part_gripper_holder_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_6_pose' WHERE _NAME = 'part_c_6';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_6';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_supply_pose' WHERE _NAME = 'part_c_supply';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_c_tray' WHERE _NAME = 'part_c_supply';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_gripper_holder' WHERE _NAME = 'part_gripper_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gripper_point', hasPoseLocation_ZAxis= 'part_gripper_z_axis', hasPoseLocation_XAxis= 'part_gripper_x_axis' WHERE _NAME = 'part_gripper_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_tray' WHERE _NAME = 'part_a_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_1_point', hasPoseLocation_ZAxis= 'part_a_1_z_axis', hasPoseLocation_XAxis= 'part_a_1_x_axis' WHERE _NAME = 'part_a_1_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_tray_pose' WHERE _NAME = 'part_a_tray';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_tray_a' WHERE _NAME = 'part_a_tray';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='shape_part_c' WHERE _NAME = 'stock_keeping_unit_part_c';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='shape_part_b' WHERE _NAME = 'stock_keeping_unit_part_b';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='shape_kit_box' WHERE _NAME = 'stock_keeping_unit_kit_box';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_7_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_7_point', hasPoseLocation_ZAxis= 'part_b_7_z_axis', hasPoseLocation_XAxis= 'part_b_7_x_axis' WHERE _NAME = 'part_b_7_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_tray' WHERE _NAME = 'part_a_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_2_point', hasPoseLocation_ZAxis= 'part_a_2_z_axis', hasPoseLocation_XAxis= 'part_a_2_x_axis' WHERE _NAME = 'part_a_2_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='relative_location_on_1' WHERE _NAME = 'tray_gripper';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_a_2', hasPartRefAndPose_Point= 'point_kit_a2b1c1_a_2', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_a_2' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_a_2';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='shape_parts_tray_a' WHERE _NAME = 'stock_keeping_unit_parts_tray_a';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='shape_parts_tray_c' WHERE _NAME = 'stock_keeping_unit_parts_tray_c';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_8_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_8_point', hasPoseLocation_ZAxis= 'part_b_8_z_axis', hasPoseLocation_XAxis= 'part_b_8_x_axis' WHERE _NAME = 'part_b_8_pose';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='shape_parts_tray_b' WHERE _NAME = 'stock_keeping_unit_parts_tray_b';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_a_1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_a_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_a_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_a_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_tray_point', hasPoseLocation_ZAxis= 'part_b_tray_z_axis', hasPoseLocation_XAxis= 'part_b_tray_x_axis' WHERE _NAME = 'part_b_tray_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_b', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_b_1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_b_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_b_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_b_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'work_table_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='work_table_point', hasPoseLocation_ZAxis= 'work_table_z_axis', hasPoseLocation_XAxis= 'work_table_x_axis' WHERE _NAME = 'work_table_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_1_pose' WHERE _NAME = 'part_b_1';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_2_pose' WHERE _NAME = 'part_b_2';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_5_pose' WHERE _NAME = 'part_b_5';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_5';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_6_pose' WHERE _NAME = 'part_b_6';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_6';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_3_pose' WHERE _NAME = 'part_b_3';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_4_pose' WHERE _NAME = 'part_b_4';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_4';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_7_pose' WHERE _NAME = 'part_b_7';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_7';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_6_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_6_point', hasPoseLocation_ZAxis= 'part_b_6_z_axis', hasPoseLocation_XAxis= 'part_b_6_x_axis' WHERE _NAME = 'part_b_6_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_8_pose' WHERE _NAME = 'part_b_8';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_8';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_supply_pose' WHERE _NAME = 'empty_kit_tray_supply';

UPDATE LargeBoxWithEmptyKitTrays
 SET  hasLargeBoxWithEmptyKitTrays_LargeContainer='empty_kit_tray_box' WHERE _NAME = 'empty_kit_tray_supply';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_7_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_7_point', hasPoseLocation_ZAxis= 'part_c_7_z_axis', hasPoseLocation_XAxis= 'part_c_7_x_axis' WHERE _NAME = 'part_c_7_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_1_point', hasPoseLocation_ZAxis= 'part_b_1_z_axis', hasPoseLocation_XAxis= 'part_b_1_x_axis' WHERE _NAME = 'part_b_1_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_tray_pose' WHERE _NAME = 'part_c_tray';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_tray_c' WHERE _NAME = 'part_c_tray';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_8_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_8_point', hasPoseLocation_ZAxis= 'part_c_8_z_axis', hasPoseLocation_XAxis= 'part_c_8_x_axis' WHERE _NAME = 'part_c_8_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_box_pose' WHERE _NAME = 'finished_kit_box';

UPDATE LargeContainer
 SET  hasLargeContainer_Sku='stock_keeping_unit_kit_box' WHERE _NAME = 'finished_kit_box';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_5_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_5_point', hasPoseLocation_ZAxis= 'part_c_5_z_axis', hasPoseLocation_XAxis= 'part_c_5_x_axis' WHERE _NAME = 'part_c_5_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_box' WHERE _NAME = 'kit_tray_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_3_point', hasPoseLocation_ZAxis= 'kit_tray_3_z_axis', hasPoseLocation_XAxis= 'kit_tray_3_x_axis' WHERE _NAME = 'kit_tray_3_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_3_pose' WHERE _NAME = 'kit_tray_3';

UPDATE KitTray
 SET  hasKitTray_Sku='stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_tray_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_2_pose' WHERE _NAME = 'kit_tray_2';

UPDATE KitTray
 SET  hasKitTray_Sku='stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_tray_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_1_pose' WHERE _NAME = 'kit_tray_1';

UPDATE KitTray
 SET  hasKitTray_Sku='stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_tray_1';

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
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_box' WHERE _NAME = 'kit_tray_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_1_point', hasPoseLocation_ZAxis= 'kit_tray_1_z_axis', hasPoseLocation_XAxis= 'kit_tray_1_x_axis' WHERE _NAME = 'kit_tray_1_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='work_table_pose' WHERE _NAME = 'work_table_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'relative_location_in_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_2_point', hasPoseLocation_ZAxis= 'part_c_2_z_axis', hasPoseLocation_XAxis= 'part_c_2_x_axis' WHERE _NAME = 'part_c_2_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_c', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_c_1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_c_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_c_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_c_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='tray_gripper_holder_pose' WHERE _NAME = 'tray_gripper_holder';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_6_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_6_point', hasPoseLocation_ZAxis= 'part_c_6_z_axis', hasPoseLocation_XAxis= 'part_c_6_x_axis' WHERE _NAME = 'part_c_6_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_c', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_c_1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_c_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_c_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_c_1';

UPDATE BoxVolume
 SET  hasBoxVolume_MaximumPoint='point_max', hasBoxVolume_MinimumPoint= 'point_min' WHERE _NAME = 'box_volume_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_tray' WHERE _NAME = 'part_a_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_4_point', hasPoseLocation_ZAxis= 'part_a_4_z_axis', hasPoseLocation_XAxis= 'part_a_4_x_axis' WHERE _NAME = 'part_a_4_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_3_point', hasPoseLocation_ZAxis= 'part_c_3_z_axis', hasPoseLocation_XAxis= 'part_c_3_x_axis' WHERE _NAME = 'part_c_3_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_a_1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_a_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_a_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_a_1';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_a_2', hasPartRefAndPose_Point= 'point_kit_a2b2c1_a_2', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_a_2' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_a_2';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_tray' WHERE _NAME = 'part_a_3_pose';

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
 SET  hasKitDesign_KitTraySku='stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_design_a2b1c1';

UPDATE KitDesign
 SET  hasKitDesign_KitTraySku='stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_design_a2b2c1';

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
 SET  hasPart_Sku='stock_keeping_unit_part_a' WHERE _NAME = 'part_a_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_3_pose' WHERE _NAME = 'part_a_3';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_a' WHERE _NAME = 'part_a_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_2_pose' WHERE _NAME = 'part_a_2';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_a' WHERE _NAME = 'part_a_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_4_pose' WHERE _NAME = 'part_a_4';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_a' WHERE _NAME = 'part_a_4';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='changing_station_pose' WHERE _NAME = 'changing_station_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_1_point', hasPoseLocation_ZAxis= 'part_c_1_z_axis', hasPoseLocation_XAxis= 'part_c_1_x_axis' WHERE _NAME = 'part_c_1_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_box' WHERE _NAME = 'kit_tray_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_2_point', hasPoseLocation_ZAxis= 'kit_tray_2_z_axis', hasPoseLocation_XAxis= 'kit_tray_2_x_axis' WHERE _NAME = 'kit_tray_2_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_b', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_b_2', hasPartRefAndPose_Point= 'point_kit_a2b2c1_b_2', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_b_2' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_b_2';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_b', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_b_1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_b_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_b_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_b_1';