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

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Height, hasBox_Width, hasBox_Length)
VALUES(1, 'part_b_tray', 0.2, 0.3, 0.6);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SkuRef, hasPartsTray_SerialNumber)
VALUES(1, 'part_b_tray', 'SkuIdPartsTray', 7);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_a');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Id, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(2, 'stock_keeping_unit_part_a', 'SKU for Part A', 'SkuIdPartA', 0.18, NULL, NULL);

INSERT INTO hasSku_EndEffectorRefsValue
(StockKeepingUnitID, hasSku_EndEffectorRefs)
VALUES(2, 'ThePartGripper');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_receiver', NULL);

INSERT INTO LargeBoxWithKits
(LargeBoxWithKitsID, _NAME, hasLargeBoxWithKits_Capacity, hasLargeBoxWithKits_KitDesignRef, hasLargeBoxWithKits_LargeContainer)
VALUES(2, 'finished_kit_receiver', 12, 'kit_design_a2b1c1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(3, 'shape_kit_tray', 'Shape of KitTrays');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(4, 'part_b_2_location', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(4, 'part_b_2_location', 'part_b_2 is in part_b_tray');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(4, 'part_b_2_location');

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(5, 'empty_kit_tray_supply_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(6, 'finished_kit_receiver_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(6, 'finished_kit_receiver_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(6, 'finished_kit_receiver_pose');

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
VALUES(7, 'part_c_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(7, 'part_c_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(7, 'part_c_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(8, 'part_c_tray_point', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_c_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Ref, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(9, 'part_ref_and_pose_c_1', 'SkuIdPartC', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(10, 'kit_tray_3_point', 0.0, 0.0, 0.3);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(11, 'work_table_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('point_c_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(12, 'point_c_1', 0.4, 0.5, 0.0);

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
VALUES(13, 'tray_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(13, 'tray_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(13, 'tray_gripper_holder_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(14, 'part_c_tray_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(15, 'kit_tray_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(15, 'kit_tray_1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(15, 'kit_tray_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_a_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Ref, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(16, 'part_ref_and_pose_a_2', 'SkuIdPartA', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_b_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Ref, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(17, 'part_ref_and_pose_b_1', 'SkuIdPartB', NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(18, 'part_b_1_location', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(18, 'part_b_1_location', 'part_b_1 is in part_b_tray');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(18, 'part_b_1_location');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(19, 'part_b_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(19, 'part_b_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(19, 'part_b_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(20, 'part_b_supply_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(21, 'tray_gripper_holder_x_axis', 0.0, 0.0, 1.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gripper', NULL);

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_Weight, hasEndEffector_Id)
VALUES(5, 'part_gripper', 'small single cup vacuum effector', 0.01, 'Thepart_gripper');

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(5, 'part_gripper', 0.02, 0.025);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(5, 'part_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Id, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(22, 'stock_keeping_unit_kit_tray', 'SKU for KitTrays', 'SkuIdKitTray', 0.2, NULL, NULL);

INSERT INTO hasSku_EndEffectorRefsValue
(StockKeepingUnitID, hasSku_EndEffectorRefs)
VALUES(22, 'TheTrayGripper');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SkuRef, hasPart_SerialNumber, hadByPart_PartsTrayWithParts)
VALUES(6, 'part_c_2', 'SkuIdPartC', 16, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SkuRef, hasPart_SerialNumber, hadByPart_PartsTrayWithParts)
VALUES(7, 'part_c_1', 'SkuIdPartC', 15, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(23, 'kit_tray_3_z_axis', 1.0, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('work_table_1', NULL);

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Height, hasBox_Width, hasBox_Length)
VALUES(8, 'work_table_1', 0.5, 0.8, 1.6);

INSERT INTO WorkTable
(WorkTableID, _NAME)
VALUES(8, 'work_table_1');

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_in_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(24, 'relative_location_in_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(24, 'relative_location_in_1', 'The  KittingWorkstation is in kitting_workstation_1');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(24, 'relative_location_in_1');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(25, 'part_a_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(25, 'part_a_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(25, 'part_a_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(26, 'finished_kit_receiver_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(27, 'part_b_supply_point', 5.5, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(28, 'x_axis_a_1', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(29, 'x_axis_a_2', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(30, 'part_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(30, 'part_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(30, 'part_gripper_holder_pose');

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
VALUES(31, 'part_a_supply_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(32, 'part_gripper_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(32, 'part_gripper_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(32, 'part_gripper_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(33, 'part_gripper_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(34, 'kit_tray_3_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(35, 'shape_parts_tray', 'Shape of PartsTrays');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(36, 'part_c_2_location', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(36, 'part_c_2_location', 'part_c_2 is in part_c_tray');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(36, 'part_c_2_location');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(37, 'kit_tray_2_point', 0.0, 0.0, 0.15);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(38, 'part_gripper_holder_point', 0.25, 0.0, 0.5);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(39, 'x_axis_c_1', 0.0, 0.0, 1.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_tray', NULL);

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Height, hasBox_Width, hasBox_Length)
VALUES(10, 'part_a_tray', 0.2, 0.3, 0.6);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SkuRef, hasPartsTray_SerialNumber)
VALUES(10, 'part_a_tray', 'SkuIdPartsTray', 6);

INSERT INTO DataThing
(_NAME)
VALUES('point_max');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(40, 'point_max', 1.0, 1.0, 2.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_a_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Ref, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(41, 'part_ref_and_pose_a_1', 'SkuIdPartA', NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper_holder', NULL);

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_ChangingStation)
VALUES(11, 'tray_gripper_holder', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(42, 'part_c_1_location', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(42, 'part_c_1_location', 'part_c_1 is in part_c_tray');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(42, 'part_c_1_location');

INSERT INTO DataThing
(_NAME)
VALUES('point_a_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(43, 'point_a_1', 0.2, 0.3, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('point_a_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(44, 'point_a_2', 0.4, 0.3, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_c');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Id, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(45, 'stock_keeping_unit_part_c', 'SKU for PartC', 'SkuIdPartC', 0.18, NULL, NULL);

INSERT INTO hasSku_EndEffectorRefsValue
(StockKeepingUnitID, hasSku_EndEffectorRefs)
VALUES(45, 'ThePartGripper');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_b');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Id, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(46, 'stock_keeping_unit_part_b', 'SKU for PartB', 'SkuIdPartB', 0.18, NULL, NULL);

INSERT INTO hasSku_EndEffectorRefsValue
(StockKeepingUnitID, hasSku_EndEffectorRefs)
VALUES(46, 'ThePartGripper');

INSERT INTO DataThing
(_NAME)
VALUES('point_b_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(47, 'point_b_1', 0.2, 0.5, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(48, 'finished_kit_box_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(49, 'part_b_supply_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_box');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Id, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(50, 'stock_keeping_unit_kit_box', 'SKU for Boxes for Kits and KitTrays', 'SkuIdKitBox', 1.2, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('box_volume_1');

INSERT INTO BoxVolume
(BoxVolumeID, _NAME, hasBoxVolume_MaximumPoint, hasBoxVolume_MinimumPoint)
VALUES(51, 'box_volume_1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(52, 'part_b_tray_point', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(53, 'empty_kit_tray_box_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('point_min');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(54, 'point_min', -1.0, -1.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(55, 'z_axis_b_1', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(56, 'tray_gripper_holder_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(57, 'part_c_supply_point', 6.5, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(58, 'part_a_tray_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_a');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(59, 'shape_part_a', 'Shape of PartA');

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_b');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(60, 'shape_part_b', 'Shape of PartB');

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_c');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(61, 'shape_part_c', 'Shape of PartC');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper', NULL);

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_Weight, hasEndEffector_Id, hadByEndEffector_Robot)
VALUES(12, 'tray_gripper', 'large single cup vacuum effector', 0.04, 'TheTrayGripper', NULL);

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(12, 'tray_gripper', 0.04, 0.1);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(12, 'tray_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_box');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(62, 'shape_kit_box', 'Shape of boxes to hold kits and kit trays');

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(63, 'finished_kit_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(63, 'finished_kit_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(63, 'finished_kit_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(64, 'part_c_supply_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(65, 'finished_kit_receiver_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(66, 'empty_kit_tray_supply_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(67, 'z_axis_c_1', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(68, 'part_gripper_holder_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(69, 'work_table_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(70, 'z_axis_a_2', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(71, 'z_axis_a_1', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(72, 'part_c_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(72, 'part_c_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(72, 'part_c_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(73, 'changing_station_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(74, 'part_b_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(74, 'part_b_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(74, 'part_b_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(75, 'part_a_tray_point', 0.0, 0.0, 0.0);

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
VALUES('part_a_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(77, 'part_a_supply_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(78, 'x_axis_b_1', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(79, 'changing_station_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(79, 'changing_station_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(79, 'changing_station_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(80, 'part_a_4_location', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(80, 'part_a_4_location', 'part_a_4 is in part_a_tray');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(80, 'part_a_4_location');

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_on_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(81, 'relative_location_on_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(81, 'relative_location_on_1', 'The tray_gripper is on robot_1');

INSERT INTO RelativeLocationOn
(RelativeLocationOnID, _NAME)
VALUES(81, 'relative_location_on_1');

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b1c1');

INSERT INTO KitDesign
(KitDesignID, _NAME, hasKitDesign_Id, hasKitDesign_KitTraySkuRef, hadByKitDesign_Workstation)
VALUES(82, 'kit_design_a2b1c1', 'kit_design_a2b1c1', 'SkuIdKitTray', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(83, 'part_a_3_location', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(83, 'part_a_3_location', 'part_a_3 is in part_a_tray');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(83, 'part_a_3_location');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SkuRef, hasPart_SerialNumber, hadByPart_PartsTrayWithParts)
VALUES(13, 'part_b_1', 'SkuIdPartB', 13, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SkuRef, hasPart_SerialNumber, hadByPart_PartsTrayWithParts)
VALUES(14, 'part_b_2', 'SkuIdPartB', 14, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(84, 'empty_kit_tray_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(84, 'empty_kit_tray_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(84, 'empty_kit_tray_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(85, 'part_a_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(85, 'part_a_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(85, 'part_a_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(86, 'finished_kit_receiver_point', 1.5, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(87, 'part_b_tray_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(88, 'kit_tray_2_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(89, 'empty_kit_tray_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(89, 'empty_kit_tray_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(89, 'empty_kit_tray_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(90, 'changing_station_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('robot_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(91, 'robot_point', 3.0, 0.0, 2.0);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(92, 'finished_kit_box_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(93, 'empty_kit_tray_supply_point', 0.5, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(94, 'kit_tray_1_x_axis', 0.0, 0.0, 1.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('robot_1', NULL);

INSERT INTO Robot
(RobotID, _NAME, hasRobot_Description, hasRobot_Id, hasRobot_MaximumLoadWeight)
VALUES(15, 'robot_1', 'this is the robot', 'robot_1', 7.0);

INSERT INTO hasRobot_WorkVolume
(RobotID, BoxVolumeID)
VALUES(15, 51);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(95, 'part_c_supply_x_axis', 0.0, 0.0, 1.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_supply', NULL);

INSERT INTO LargeBoxWithEmptyKitTrays
(LargeBoxWithEmptyKitTraysID, _NAME, hasLargeBoxWithEmptyKitTrays_LargeContainer)
VALUES(16, 'empty_kit_tray_supply', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kitting_workstation_1', NULL);

INSERT INTO KittingWorkstation
(KittingWorkstationID, _NAME, hasWorkstation_LengthUnit, hasWorkstation_WeightUnit, hasWorkstation_AngleUnit, hasWorkstation_ChangingStation, hasWorkstation_WorkTable, hasWorkstation_Robot)
VALUES(17, 'kitting_workstation_1', 'meter', 'kilogram', 'degree', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(96, 'empty_kit_tray_box_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('robot_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(97, 'robot_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(98, 'kit_tray_2_x_axis', 0.0, 0.0, 1.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SkuRef, hasPart_SerialNumber, hadByPart_PartsTrayWithParts)
VALUES(18, 'part_a_1', 'SkuIdPartA', 9, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(99, 'part_gripper_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(100, 'part_gripper_holder_z_axis', 1.0, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SkuRef, hasPart_SerialNumber, hadByPart_PartsTrayWithParts)
VALUES(19, 'part_a_3', 'SkuIdPartA', 11, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(101, 'part_b_tray_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(102, 'part_a_1_location', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(102, 'part_a_1_location', 'part_a_1 is in part_a_tray');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(102, 'part_a_1_location');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SkuRef, hasPart_SerialNumber, hadByPart_PartsTrayWithParts)
VALUES(20, 'part_a_2', 'SkuIdPartA', 10, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SkuRef, hasPart_SerialNumber, hadByPart_PartsTrayWithParts)
VALUES(21, 'part_a_4', 'SkuIdPartA', 12, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(103, 'part_c_tray_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('robot_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(104, 'robot_x_axis', 0.0, 0.0, 1.0);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(105, 'tray_gripper_holder_point', -0.25, 0.0, 0.5);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(106, 'part_a_2_location', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(106, 'part_a_2_location', 'part_a_2 is in part_a_tray');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(106, 'part_a_2_location');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(107, 'kit_tray_1_point', 0.0, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_tray', NULL);

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Height, hasBox_Width, hasBox_Length)
VALUES(22, 'part_c_tray', 0.2, 0.3, 0.6);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SkuRef, hasPartsTray_SerialNumber)
VALUES(22, 'part_c_tray', 'SkuIdPartsTray', 8);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('changing_station_1', NULL);

INSERT INTO EndEffectorChangingStation
(EndEffectorChangingStationID, _NAME)
VALUES(23, 'changing_station_1');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_box', NULL);

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Height, hasBox_Width, hasBox_Length)
VALUES(24, 'finished_kit_box', 0.8, 0.7, 0.9);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SkuRef, hasLargeContainer_SerialNumber)
VALUES(24, 'finished_kit_box', 'SkuIdKitBox', 5);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(108, 'kit_tray_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(108, 'kit_tray_3_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(108, 'kit_tray_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(109, 'kit_tray_1_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(110, 'empty_kit_tray_box_point', 0.5, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(111, 'part_gripper_point', 0.0, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_3', NULL);

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Height, hasBox_Width, hasBox_Length)
VALUES(25, 'kit_tray_3', 0.15, 0.3, 0.5);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SkuRef, hasKitTray_SerialNumber, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(25, 'kit_tray_3', 'SkuIdKitTray', 3, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_2', NULL);

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Height, hasBox_Width, hasBox_Length)
VALUES(26, 'kit_tray_2', 0.15, 0.3, 0.5);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SkuRef, hasKitTray_SerialNumber, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(26, 'kit_tray_2', 'SkuIdKitTray', 2, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_1', NULL);

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Height, hasBox_Width, hasBox_Length)
VALUES(27, 'kit_tray_1', 0.15, 0.3, 0.5);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SkuRef, hasKitTray_SerialNumber, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(27, 'kit_tray_1', 'SkuIdKitTray', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(112, 'finished_kit_box_point', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(113, 'part_a_tray_z_axis', 1.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(114, 'work_table_point', 3.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Id, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(115, 'stock_keeping_unit_parts_tray', 'SKU for PartsTrays', 'SkuIdPartsTray', 0.2, NULL, NULL);

INSERT INTO hasSku_EndEffectorRefsValue
(StockKeepingUnitID, hasSku_EndEffectorRefs)
VALUES(115, 'TheTrayGripper');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(116, 'changing_station_point', 7.5, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(117, 'part_a_supply_point', 4.5, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_box', NULL);

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Height, hasBox_Width, hasBox_Length)
VALUES(28, 'empty_kit_tray_box', 0.8, 0.7, 0.9);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SkuRef, hasLargeContainer_SerialNumber)
VALUES(28, 'empty_kit_tray_box', 'SkuIdKitBox', 4);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(118, 'kit_tray_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(118, 'kit_tray_2_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(118, 'kit_tray_2_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(29, 'part_a_supply', NULL);



UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'robot_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='robot_point', hasPoseLocation_ZAxis= 'robot_z_axis', hasPoseLocation_XAxis= 'robot_x_axis' WHERE _NAME = 'robot_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_tray_pose' WHERE _NAME = 'part_b_tray';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_part_a' WHERE _NAME = 'stock_keeping_unit_part_a';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_receiver_pose' WHERE _NAME = 'finished_kit_receiver';

UPDATE LargeBoxWithKits
 SET  hasLargeBoxWithKits_LargeContainer='finished_kit_box' WHERE _NAME = 'finished_kit_receiver';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_2_location';

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

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_ZAxis='z_axis_c_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_c_1', hasPartRefAndPose_XAxis= 'x_axis_c_1' WHERE _NAME = 'part_ref_and_pose_c_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gripper_holder_pose' WHERE _NAME = 'part_gripper_holder';

UPDATE EndEffectorHolder
 SET  hadByEndEffectorHolder_ChangingStation='changing_station_1', hasEndEffectorHolder_EndEffector= 'part_gripper' WHERE _NAME = 'part_gripper_holder';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'tray_gripper_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='tray_gripper_holder_point', hasPoseLocation_ZAxis= 'tray_gripper_holder_z_axis', hasPoseLocation_XAxis= 'tray_gripper_holder_x_axis' WHERE _NAME = 'tray_gripper_holder_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_box' WHERE _NAME = 'kit_tray_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_1_point', hasPoseLocation_ZAxis= 'kit_tray_1_z_axis', hasPoseLocation_XAxis= 'kit_tray_1_x_axis' WHERE _NAME = 'kit_tray_1_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_ZAxis='z_axis_a_2', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_a_2', hasPartRefAndPose_XAxis= 'x_axis_a_2' WHERE _NAME = 'part_ref_and_pose_a_2';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_ZAxis='z_axis_b_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_b_1', hasPartRefAndPose_XAxis= 'x_axis_b_1' WHERE _NAME = 'part_ref_and_pose_b_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_1_location';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_b_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_supply_point', hasPoseLocation_ZAxis= 'part_b_supply_z_axis', hasPoseLocation_XAxis= 'part_b_supply_x_axis' WHERE _NAME = 'part_b_supply_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gripper_pose' WHERE _NAME = 'part_gripper';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_tray' WHERE _NAME = 'stock_keeping_unit_kit_tray';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_2_location' WHERE _NAME = 'part_c_2';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply' WHERE _NAME = 'part_c_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_1_location' WHERE _NAME = 'part_c_1';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply' WHERE _NAME = 'part_c_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='work_table_pose' WHERE _NAME = 'work_table_1';

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
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_2_location';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_tray_pose' WHERE _NAME = 'part_a_tray';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_ZAxis='z_axis_a_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_a_1', hasPartRefAndPose_XAxis= 'x_axis_a_1' WHERE _NAME = 'part_ref_and_pose_a_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='tray_gripper_holder_pose' WHERE _NAME = 'tray_gripper_holder';

UPDATE EndEffectorHolder
 SET  hadByEndEffectorHolder_ChangingStation='changing_station_1' WHERE _NAME = 'tray_gripper_holder';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_1_location';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_part_c' WHERE _NAME = 'stock_keeping_unit_part_c';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_part_b' WHERE _NAME = 'stock_keeping_unit_part_b';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_box' WHERE _NAME = 'stock_keeping_unit_kit_box';

UPDATE BoxVolume
 SET  hasBoxVolume_MaximumPoint='point_max', hasBoxVolume_MinimumPoint= 'point_min' WHERE _NAME = 'box_volume_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='relative_location_on_1' WHERE _NAME = 'tray_gripper';

UPDATE EndEffector
 SET  hadByEndEffector_Robot='robot_1' WHERE _NAME = 'tray_gripper';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='finished_kit_receiver' WHERE _NAME = 'finished_kit_box_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='finished_kit_box_point', hasPoseLocation_ZAxis= 'finished_kit_box_z_axis', hasPoseLocation_XAxis= 'finished_kit_box_x_axis' WHERE _NAME = 'finished_kit_box_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_c_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_supply_point', hasPoseLocation_ZAxis= 'part_c_supply_z_axis', hasPoseLocation_XAxis= 'part_c_supply_x_axis' WHERE _NAME = 'part_c_supply_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_tray_point', hasPoseLocation_ZAxis= 'part_b_tray_z_axis', hasPoseLocation_XAxis= 'part_b_tray_x_axis' WHERE _NAME = 'part_b_tray_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'work_table_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='work_table_point', hasPoseLocation_ZAxis= 'work_table_z_axis', hasPoseLocation_XAxis= 'work_table_x_axis' WHERE _NAME = 'work_table_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'changing_station_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='changing_station_point', hasPoseLocation_ZAxis= 'changing_station_z_axis', hasPoseLocation_XAxis= 'changing_station_x_axis' WHERE _NAME = 'changing_station_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_tray' WHERE _NAME = 'part_a_4_location';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='robot_1' WHERE _NAME = 'relative_location_on_1';

UPDATE KitDesign
 SET  hadByKitDesign_Workstation='kitting_workstation_1' WHERE _NAME = 'kit_design_a2b1c1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_tray' WHERE _NAME = 'part_a_3_location';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_1_location' WHERE _NAME = 'part_b_1';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply' WHERE _NAME = 'part_b_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_2_location' WHERE _NAME = 'part_b_2';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply' WHERE _NAME = 'part_b_2';

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
 SET  hasSolidObject_PrimaryLocation='part_a_1_location' WHERE _NAME = 'part_a_1';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply' WHERE _NAME = 'part_a_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_3_location' WHERE _NAME = 'part_a_3';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply' WHERE _NAME = 'part_a_3';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_tray' WHERE _NAME = 'part_a_1_location';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_2_location' WHERE _NAME = 'part_a_2';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply' WHERE _NAME = 'part_a_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_4_location' WHERE _NAME = 'part_a_4';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply' WHERE _NAME = 'part_a_4';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_tray' WHERE _NAME = 'part_a_2_location';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_tray_pose' WHERE _NAME = 'part_c_tray';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='changing_station_pose' WHERE _NAME = 'changing_station_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_box_pose' WHERE _NAME = 'finished_kit_box';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_box' WHERE _NAME = 'kit_tray_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_3_point', hasPoseLocation_ZAxis= 'kit_tray_3_z_axis', hasPoseLocation_XAxis= 'kit_tray_3_x_axis' WHERE _NAME = 'kit_tray_3_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_3_pose' WHERE _NAME = 'kit_tray_3';

UPDATE KitTray
 SET  hadByKitTray_LargeBoxWithEmptyKitTrays='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_2_pose' WHERE _NAME = 'kit_tray_2';

UPDATE KitTray
 SET  hadByKitTray_LargeBoxWithEmptyKitTrays='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_1_pose' WHERE _NAME = 'kit_tray_1';

UPDATE KitTray
 SET  hadByKitTray_LargeBoxWithEmptyKitTrays='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_1';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_parts_tray' WHERE _NAME = 'stock_keeping_unit_parts_tray';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_box_pose' WHERE _NAME = 'empty_kit_tray_box';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_box' WHERE _NAME = 'kit_tray_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_2_point', hasPoseLocation_ZAxis= 'kit_tray_2_z_axis', hasPoseLocation_XAxis= 'kit_tray_2_x_axis' WHERE _NAME = 'kit_tray_2_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_supply_pose' WHERE _NAME = 'part_a_supply';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_a_tray' WHERE _NAME = 'part_a_supply';