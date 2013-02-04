INSERT INTO DataThing
(_NAME)
VALUES('robot_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(1, 'robot_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(1, 'robot_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(1, 'robot_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(1, 'part_b_tray', 7, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_a');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(2, 'stock_keeping_unit_part_a', 'SKU for Part A', 0.180000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(2, 1);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_receiver', NULL);

INSERT INTO LargeBoxWithKits
(LargeBoxWithKitsID, _NAME, hasLargeBoxWithKits_Capacity, hasLargeBoxWithKits_LargeContainer, hasLargeBoxWithKits_KitDesign)
VALUES(2, 'finished_kit_receiver', 12, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(3, 'shape_kit_tray', 'Shape of KitTrays');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(3, 'shape_kit_tray');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(3, 'shape_kit_tray', 0.300000, 'false', 0.150000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(4, 'empty_kit_tray_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(5, 'finished_kit_receiver_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(5, 'finished_kit_receiver_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(5, 'finished_kit_receiver_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(3, 'part_b_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(6, 'part_c_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(6, 'part_c_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(6, 'part_c_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(7, 'part_c_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(8, 'work_table_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gripper_holder', NULL);

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_ChangingStation, hasEndEffectorHolder_EndEffector)
VALUES(4, 'part_gripper_holder', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(9, 'tray_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(9, 'tray_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(9, 'tray_gripper_holder_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(10, 'part_c_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(11, 'kit_tray_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(11, 'kit_tray_1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(11, 'kit_tray_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(12, 'changing_station_base_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(13, 'part_b_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(13, 'part_b_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(13, 'part_b_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(14, 'part_b_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(15, 'tray_gripper_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gripper', NULL);

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_Weight, hasEffector_MaximumLoadWeight)
VALUES(5, 'part_gripper', 'small single cup vacuum effector', 0.010000, 0.400000);

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(5, 'part_gripper', 0.020000, 0.025000);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(5, 'part_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(16, 'stock_keeping_unit_kit_tray', 'SKU for KitTrays', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(16, 5);

INSERT INTO SolidObject
(_NAME, hasSolidObject_InternalShape, hasSolidObject_PrimaryLocation)
VALUES('changing_station_base', NULL, NULL);

INSERT INTO MechanicalComponent
(MechanicalComponentID, _NAME)
VALUES(6, 'changing_station_base');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_a_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(17, 'point_kit_a2b1c1_a_2', 0.400000, 0.300000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_a_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(18, 'point_kit_a2b1c1_a_1', 0.200000, 0.300000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(19, 'z_axis_kit_a2b1c1_a_2', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(7, 'part_c_1', 'c1', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_InternalShape, hasSolidObject_PrimaryLocation)
VALUES('work_table_1', NULL, NULL);

INSERT INTO WorkTable
(WorkTableID, _NAME)
VALUES(8, 'work_table_1');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(20, 'z_axis_kit_a2b1c1_a_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_in_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(21, 'relative_location_in_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(21, 'relative_location_in_1', 'The  KittingWorkstation is in kitting_workstation_1');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(21, 'relative_location_in_1');

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(22, 'finished_kit_receiver_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(23, 'part_a_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(23, 'part_a_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(23, 'part_a_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(24, 'part_b_supply_point', 5.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(25, 'part_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(25, 'part_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(25, 'part_gripper_holder_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(9, 'part_c_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(26, 'part_a_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(27, 'part_gripper_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(27, 'part_gripper_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(27, 'part_gripper_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(28, 'part_gripper_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(29, 'shape_parts_tray', 'Shape of PartsTrays');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(29, 'shape_parts_tray');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(29, 'shape_parts_tray', 0.300000, 'false', 0.200000, 0.600000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_c_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(30, 'point_kit_a2b1c1_c_1', 0.400000, 0.500000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(31, 'part_a_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(31, 'part_a_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(31, 'part_a_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(32, 'part_gripper_holder_point', 0.250000, 0.000000, 0.500000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(10, 'part_a_tray', 6, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_max');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(33, 'point_max', 1.000000, 1.000000, 2.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(34, 'part_b_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper_holder', NULL);

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_ChangingStation)
VALUES(11, 'tray_gripper_holder', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_c_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(35, 'part_ref_and_pose_kit_a2b1c1_c_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_c');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(36, 'stock_keeping_unit_part_c', 'SKU for Part C', 0.180000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(36, 5);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_b');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(37, 'stock_keeping_unit_part_b', 'SKU for Part B', 0.180000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(37, 5);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(38, 'part_b_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_d');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(39, 'stock_keeping_unit_part_d', 'SKU for Part D', 0.180000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(39, 5);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(40, 'finished_kit_box_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_box');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(41, 'stock_keeping_unit_kit_box', 'SKU for Boxes for Kits and KitTrays', 1.200000, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('box_volume_1');

INSERT INTO BoxVolume
(BoxVolumeID, _NAME, hasBoxVolume_MaximumPoint, hasBoxVolume_MinimumPoint)
VALUES(42, 'box_volume_1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(43, 'z_axis_kit_a2b1c1_c_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(44, 'part_b_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(45, 'changing_station_base_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(46, 'empty_kit_tray_box_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(47, 'changing_station_base_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(47, 'changing_station_base_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(47, 'changing_station_base_pose');

INSERT INTO DataThing
(_NAME)
VALUES('point_min');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(48, 'point_min', -1.000000, -1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(49, 'part_a_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(50, 'tray_gripper_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(51, 'part_c_supply_point', 6.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(52, 'changing_station_base_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(53, 'part_a_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_a');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(54, 'shape_part_a', 'Shape of PartA');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(54, 'shape_part_a');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(54, 'shape_part_a', 0.080000, 'true', 0.150000, 0.100000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_b');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(55, 'shape_part_b', 'Shape of PartB');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(55, 'shape_part_b');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(55, 'shape_part_b', 0.080000, 'true', 0.150000, 0.120000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_c');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(56, 'shape_part_c', 'Shape of PartC');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(56, 'shape_part_c');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(56, 'shape_part_c', 0.080000, 'true', 0.150000, 0.150000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(57, 'part_a_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(57, 'part_a_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(57, 'part_a_2_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper', NULL);

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_Weight, hasEffector_MaximumLoadWeight, hadByEndEffector_Robot)
VALUES(12, 'tray_gripper', 'large single cup vacuum effector', 0.040000, 0.500000, NULL);

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(12, 'tray_gripper', 0.040000, 0.100000);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(12, 'tray_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_box');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(58, 'shape_kit_box', 'Shape of boxes to hold kits and kit trays');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(58, 'shape_kit_box');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(58, 'shape_kit_box', 0.700000, 'false', 0.800000, 0.900000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(59, 'finished_kit_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(59, 'finished_kit_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(59, 'finished_kit_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(60, 'finished_kit_receiver_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(61, 'part_c_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(62, 'empty_kit_tray_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(63, 'part_gripper_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_a_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(64, 'part_ref_and_pose_kit_a2b1c1_a_2', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(65, 'part_a_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(66, 'part_b_1_point', -0.080000, 0.120000, 0.067500);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(67, 'work_table_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(68, 'part_c_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(68, 'part_c_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(68, 'part_c_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_a_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(69, 'part_ref_and_pose_kit_a2b1c1_a_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(70, 'changing_station_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_d');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(71, 'shape_part_d', 'Shape of PartD');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(71, 'shape_part_d', 'OpenGL', 'model of part d shape', 'model/Part_d.gl');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(72, 'part_c_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(73, 'part_b_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(73, 'part_b_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(73, 'part_b_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(74, 'part_a_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_b_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(75, 'part_ref_and_pose_kit_a2b1c1_b_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(76, 'work_table_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(76, 'work_table_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(76, 'work_table_pose');

INSERT INTO DataThing
(_NAME)
VALUES('shape_changing_station_base');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(77, 'shape_changing_station_base', 'Shape of base of changing station');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(77, 'shape_changing_station_base');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(77, 'shape_changing_station_base', 0.100000, 'true', 1.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(78, 'part_a_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(79, 'part_b_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(80, 'changing_station_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(80, 'changing_station_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(80, 'changing_station_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(81, 'part_a_1_point', 0.159000, 0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(82, 'z_axis_kit_a2b1c1_b_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_on_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(83, 'relative_location_on_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(83, 'relative_location_on_1', 'The tray_gripper is on robot_1');

INSERT INTO RelativeLocationOn
(RelativeLocationOnID, _NAME)
VALUES(83, 'relative_location_on_1');

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b1c1');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(84, 'kit_design_a2b1c1', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(13, 'part_b_1', 'b1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_work_table');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(85, 'shape_work_table', 'Shape of the work table');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(85, 'shape_work_table');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(85, 'shape_work_table', 0.800000, 'true', 0.500000, 1.600000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(86, 'empty_kit_tray_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(86, 'empty_kit_tray_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(86, 'empty_kit_tray_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(87, 'part_a_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(87, 'part_a_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(87, 'part_a_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(88, 'finished_kit_receiver_point', 1.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(89, 'part_a_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(90, 'part_c_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(91, 'part_a_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(92, 'part_b_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(93, 'empty_kit_tray_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(93, 'empty_kit_tray_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(93, 'empty_kit_tray_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(94, 'changing_station_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(95, 'robot_point', 3.000000, 0.000000, 2.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(96, 'empty_kit_tray_supply_point', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(97, 'kit_tray_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(98, 'finished_kit_box_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('robot_1', NULL);

INSERT INTO Robot
(RobotID, _NAME, hasRobot_Description, hasRobot_MaximumLoadWeight)
VALUES(14, 'robot_1', 'this is the robot', 7.000000);

INSERT INTO hasRobot_WorkVolume
(RobotID, BoxVolumeID)
VALUES(14, 42);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(99, 'part_c_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_supply', NULL);

INSERT INTO LargeBoxWithEmptyKitTrays
(LargeBoxWithEmptyKitTraysID, _NAME, hasLargeBoxWithEmptyKitTrays_LargeContainer)
VALUES(15, 'empty_kit_tray_supply', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kitting_workstation_1', NULL);

INSERT INTO KittingWorkstation
(KittingWorkstationID, _NAME, hasWorkstation_LengthUnit, hasWorkstation_AngleUnit, hasWorkstation_WeightUnit, hasWorkstation_ChangingStation, hasWorkstation_WorkTable, hasWorkstation_Robot)
VALUES(16, 'kitting_workstation_1', 'meter', 'degree', 'kilogram', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('robot_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(100, 'robot_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(101, 'empty_kit_tray_box_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(102, 'part_gripper_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(17, 'part_a_1', 'a1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(103, 'part_gripper_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(104, 'part_a_2_point', 0.159000, -0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(105, 'part_b_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(18, 'part_a_2', 'a2', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_b_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(106, 'point_kit_a2b1c1_b_1', 0.200000, 0.500000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(107, 'part_b_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(107, 'part_b_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(107, 'part_b_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(108, 'part_c_1_point', 0.110000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(109, 'part_c_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(110, 'robot_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(111, 'tray_gripper_holder_point', -0.250000, 0.000000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(112, 'x_axis_kit_a2b1c1_c_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(113, 'kit_tray_1_point', 0.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(19, 'part_c_tray', 8, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('changing_station_1', NULL);

INSERT INTO EndEffectorChangingStation
(EndEffectorChangingStationID, _NAME, hasChangingStation_Base)
VALUES(20, 'changing_station_1', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(21, 'finished_kit_box', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(114, 'kit_tray_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(115, 'empty_kit_tray_box_point', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(116, 'part_gripper_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(117, 'x_axis_kit_a2b1c1_b_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(118, 'finished_kit_box_point', 0.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_1', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(22, 'kit_tray_1', 1, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(119, 'part_a_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(120, 'work_table_point', 3.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(121, 'stock_keeping_unit_parts_tray', 'SKU for PartsTrays', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(121, 12);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(122, 'part_c_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(122, 'part_c_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(122, 'part_c_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(123, 'changing_station_point', 7.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(124, 'part_a_supply_point', 4.500000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(23, 'empty_kit_tray_box', 4, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(24, 'part_a_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(125, 'x_axis_kit_a2b1c1_a_2', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(126, 'x_axis_kit_a2b1c1_a_1', 0.000000, 0.000000, 1.000000);



UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'robot_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='robot_point', hasPoseLocation_ZAxis= 'robot_z_axis', hasPoseLocation_XAxis= 'robot_x_axis' WHERE _NAME = 'robot_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_tray_pose' WHERE _NAME = 'part_b_tray';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_tray' WHERE _NAME = 'part_b_tray';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_part_a' WHERE _NAME = 'stock_keeping_unit_part_a';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_receiver_pose' WHERE _NAME = 'finished_kit_receiver';

UPDATE LargeBoxWithKits
 SET  hasLargeBoxWithKits_LargeContainer='finished_kit_box', hasLargeBoxWithKits_KitDesign= 'kit_design_a2b1c1' WHERE _NAME = 'finished_kit_receiver';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'finished_kit_receiver_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='finished_kit_receiver_point', hasPoseLocation_ZAxis= 'finished_kit_receiver_z_axis', hasPoseLocation_XAxis= 'finished_kit_receiver_x_axis' WHERE _NAME = 'finished_kit_receiver_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_supply_pose' WHERE _NAME = 'part_b_supply';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_b_tray' WHERE _NAME = 'part_b_supply';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_tray_point', hasPoseLocation_ZAxis= 'part_c_tray_z_axis', hasPoseLocation_XAxis= 'part_c_tray_x_axis' WHERE _NAME = 'part_c_tray_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gripper_holder_pose' WHERE _NAME = 'part_gripper_holder';

UPDATE EndEffectorHolder
 SET  hadByEndEffectorHolder_ChangingStation='changing_station_1', hasEndEffectorHolder_EndEffector= 'part_gripper' WHERE _NAME = 'part_gripper_holder';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'tray_gripper_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='tray_gripper_holder_point', hasPoseLocation_ZAxis= 'tray_gripper_holder_z_axis', hasPoseLocation_XAxis= 'tray_gripper_holder_x_axis' WHERE _NAME = 'tray_gripper_holder_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_1_point', hasPoseLocation_ZAxis= 'kit_tray_1_z_axis', hasPoseLocation_XAxis= 'kit_tray_1_x_axis' WHERE _NAME = 'kit_tray_1_pose';

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
 SET  hasSolidObject_PrimaryLocation='part_c_1_pose' WHERE _NAME = 'part_c_1';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply', hasPart_Sku= 'stock_keeping_unit_part_c' WHERE _NAME = 'part_c_1';

UPDATE SolidObject
 SET  hasSolidObject_InternalShape='shape_work_table', hasSolidObject_PrimaryLocation= 'work_table_pose' WHERE _NAME = 'work_table_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'relative_location_in_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply' WHERE _NAME = 'part_a_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_tray_point', hasPoseLocation_ZAxis= 'part_a_tray_z_axis', hasPoseLocation_XAxis= 'part_a_tray_x_axis' WHERE _NAME = 'part_a_tray_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'part_gripper_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gripper_holder_point', hasPoseLocation_ZAxis= 'part_gripper_holder_z_axis', hasPoseLocation_XAxis= 'part_gripper_holder_x_axis' WHERE _NAME = 'part_gripper_holder_pose';

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
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_tray' WHERE _NAME = 'part_a_tray';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='tray_gripper_holder_pose' WHERE _NAME = 'tray_gripper_holder';

UPDATE EndEffectorHolder
 SET  hadByEndEffectorHolder_ChangingStation='changing_station_1' WHERE _NAME = 'tray_gripper_holder';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_c', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_c_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_c_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_c_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_c_1';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_part_c' WHERE _NAME = 'stock_keeping_unit_part_c';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_part_b' WHERE _NAME = 'stock_keeping_unit_part_b';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_part_d' WHERE _NAME = 'stock_keeping_unit_part_d';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_box' WHERE _NAME = 'stock_keeping_unit_kit_box';

UPDATE BoxVolume
 SET  hasBoxVolume_MaximumPoint='point_max', hasBoxVolume_MinimumPoint= 'point_min' WHERE _NAME = 'box_volume_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'changing_station_base_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='changing_station_base_point', hasPoseLocation_ZAxis= 'changing_station_base_z_axis', hasPoseLocation_XAxis= 'changing_station_base_x_axis' WHERE _NAME = 'changing_station_base_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply' WHERE _NAME = 'part_a_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_2_point', hasPoseLocation_ZAxis= 'part_a_2_z_axis', hasPoseLocation_XAxis= 'part_a_2_x_axis' WHERE _NAME = 'part_a_2_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='relative_location_on_1' WHERE _NAME = 'tray_gripper';

UPDATE EndEffector
 SET  hadByEndEffector_Robot='robot_1' WHERE _NAME = 'tray_gripper';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='finished_kit_receiver' WHERE _NAME = 'finished_kit_box_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='finished_kit_box_point', hasPoseLocation_ZAxis= 'finished_kit_box_z_axis', hasPoseLocation_XAxis= 'finished_kit_box_x_axis' WHERE _NAME = 'finished_kit_box_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_a_2', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_a_2', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_a_2' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_a_2';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_c_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_supply_point', hasPoseLocation_ZAxis= 'part_c_supply_z_axis', hasPoseLocation_XAxis= 'part_c_supply_x_axis' WHERE _NAME = 'part_c_supply_pose';

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

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'changing_station_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='changing_station_point', hasPoseLocation_ZAxis= 'changing_station_z_axis', hasPoseLocation_XAxis= 'changing_station_x_axis' WHERE _NAME = 'changing_station_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='robot_1' WHERE _NAME = 'relative_location_on_1';

UPDATE KitDesign
 SET  hadByKitDesign_Workstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_design_a2b1c1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_1_pose' WHERE _NAME = 'part_b_1';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply', hasPart_Sku= 'stock_keeping_unit_part_b' WHERE _NAME = 'part_b_1';

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
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_supply_pose' WHERE _NAME = 'empty_kit_tray_supply';

UPDATE LargeBoxWithEmptyKitTrays
 SET  hasLargeBoxWithEmptyKitTrays_LargeContainer='empty_kit_tray_box' WHERE _NAME = 'empty_kit_tray_supply';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='relative_location_in_1' WHERE _NAME = 'kitting_workstation_1';

UPDATE KittingWorkstation
 SET  hasWorkstation_ChangingStation='changing_station_1', hasWorkstation_WorkTable= 'work_table_1', hasWorkstation_Robot= 'robot_1' WHERE _NAME = 'kitting_workstation_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_1_pose' WHERE _NAME = 'part_a_1';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply', hasPart_Sku= 'stock_keeping_unit_part_a' WHERE _NAME = 'part_a_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_2_pose' WHERE _NAME = 'part_a_2';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply', hasPart_Sku= 'stock_keeping_unit_part_a' WHERE _NAME = 'part_a_2';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_1_point', hasPoseLocation_ZAxis= 'part_b_1_z_axis', hasPoseLocation_XAxis= 'part_b_1_x_axis' WHERE _NAME = 'part_b_1_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_tray_pose' WHERE _NAME = 'part_c_tray';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_tray' WHERE _NAME = 'part_c_tray';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='changing_station_pose' WHERE _NAME = 'changing_station_1';

UPDATE EndEffectorChangingStation
 SET  hasChangingStation_Base='changing_station_base' WHERE _NAME = 'changing_station_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_box_pose' WHERE _NAME = 'finished_kit_box';

UPDATE LargeContainer
 SET  hasLargeContainer_Sku='stock_keeping_unit_kit_box' WHERE _NAME = 'finished_kit_box';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_1_pose' WHERE _NAME = 'kit_tray_1';

UPDATE KitTray
 SET  hasKitTray_Sku='stock_keeping_unit_kit_tray', hadByKitTray_LargeBoxWithEmptyKitTrays= 'empty_kit_tray_supply' WHERE _NAME = 'kit_tray_1';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_parts_tray' WHERE _NAME = 'stock_keeping_unit_parts_tray';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_1_point', hasPoseLocation_ZAxis= 'part_c_1_z_axis', hasPoseLocation_XAxis= 'part_c_1_x_axis' WHERE _NAME = 'part_c_1_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_box_pose' WHERE _NAME = 'empty_kit_tray_box';

UPDATE LargeContainer
 SET  hasLargeContainer_Sku='stock_keeping_unit_kit_box' WHERE _NAME = 'empty_kit_tray_box';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_supply_pose' WHERE _NAME = 'part_a_supply';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_a_tray' WHERE _NAME = 'part_a_supply';