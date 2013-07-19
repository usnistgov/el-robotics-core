INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_6_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(1, 'part_d_6_ir', 'd6_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_5_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(1, 'part_e_5_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray_5_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(2, 'stock_keeping_unit_kit_tray_5_ir', 'SKU for KitTray 5', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(2, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(3, 'part_c_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(4, 'part_gear_1_point', 0.8000, 0.0000, 0.05000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_4_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(2, 'part_d_4_ir', 'd4_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_a_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(5, 'part_ref_and_pose_kit_a4b3c2d1_a_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(6, 'part_gear_shaft_2_point', 0.6, 2.0000, 0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_c_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(7, 'point_kit_a2b3c5_c_3_ir', 0.787200, -0.330100, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(8, 'part_b_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(8, 'part_b_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(8, 'part_b_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(9, 'z_axis_kit_a4b3c3_c_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_a4b3c3', NULL);

INSERT INTO Kit
(KitID, _NAME, isKit_Finished, hasKit_Tray, hasKit_Design)
VALUES(3, 'kit_a4b3c3', false, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_tray_ir', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(4, 'part_d_tray_ir', 9, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(10, 'finished_kit_receiver_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(10, 'finished_kit_receiver_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(10, 'finished_kit_receiver_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(11, 'part_b_5_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(11, 'part_b_5_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(11, 'part_b_5_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(12, 'part_b_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(12, 'part_b_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(12, 'part_b_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c5_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(13, 'kit_a2b3c5_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(13, 'kit_a2b3c5_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(13, 'kit_a2b3c5_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(14, 'part_c_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(14, 'part_c_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(14, 'part_c_4_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_tray_ir', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(5, 'part_b_tray_ir', 7, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_holder', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(6, 'part_gear_holder', 'gearholder', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_9_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(7, 'part_b_9_ir', 'b9_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(15, 'kit_tray_2_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_a_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(16, 'point_kit_a2b1c1_a_2', 0.400000, -0.300000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_5', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(8, 'part_c_5', 'c5', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_a_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(17, 'point_kit_a2b1c1_a_1', 0.200000, -0.300000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(9, 'part_c_4', 'c4', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(10, 'part_c_3', 'c3', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(11, 'part_c_2', 'c2', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(12, 'part_c_1', 'c1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_5_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(18, 'kit_tray_5_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_10_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(19, 'part_a_10_point_ir', 0.469500, -0.216000, -0.065000);

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
VALUES(13, 'part_c_8', 'c8', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_7_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(14, 'part_a_7_ir', 'a7_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_7', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(15, 'part_c_7', 'c7', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c2d1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(21, 'kit_a4b3c2d1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_6', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(16, 'part_c_6', 'c6', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(22, 'z_axis_kit_a4b4c2_b_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(17, 'part_c_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_8_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(23, 'part_a_8_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_b_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(24, 'part_ref_and_pose_kit_a4b3c3_b_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_a_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(25, 'z_axis_kit_a4b3c2d1_a_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_9_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(26, 'part_d_9_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_b_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(27, 'shape_part_b_ir', 'Shape of PartB_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(27, 'shape_part_b_ir', 'USARSim', 'BlockB', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(28, 'part_a_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_boss', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(18, 'part_gear_boss', 'gearboss', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_8_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(29, 'part_d_8_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_4_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(30, 'part_e_4_point_ir', 0.165600, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(31, 'part_b_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_d_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(32, 'point_kit_a4b3c2d1_d_1_ir', 0.088800, -0.292000, -0.065000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(19, 'part_a_tray', 6, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_a_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(33, 'shape_part_a_ir', 'Shape of PartA_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(33, 'shape_part_a_ir', 'USARSim', 'BlockA', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_tray_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(34, 'part_d_tray_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(34, 'part_d_tray_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(34, 'part_d_tray_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(35, 'x_axis_kit_a4b3c3_a_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(36, 'part_b_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_b_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(37, 'point_kit_a4b3c3_b_3_ir', 0.635000, -0.114700, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(38, 'part_gear_5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(39, 'part_b_1_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(39, 'part_b_1_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(39, 'part_b_1_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_a_4_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(40, 'point_kit_a4b4c2_a_4_ir', 0.622700, -0.292400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_a_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(41, 'point_kit_a4b3c3_a_1_ir', 0.546100, -0.368700, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(42, 'z_axis_kit_a2b1c1_c_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray_2_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(43, 'shape_kit_tray_2_ir', 'Shape of KitTray 2');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(43, 'shape_kit_tray_2_ir', 'USARSim', 'KitTray2', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_c_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(44, 'part_ref_and_pose_kit_a4b3c2d1_c_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_11_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(20, 'part_a_11_ir', 'a11_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_11_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(45, 'part_a_11_point_ir', 0.596500, -0.216000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_gear_holder');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(46, 'stock_keeping_unit_part_gear_holder', 'SKU for gear holder', 1.200000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(46, 1);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_5_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(47, 'kit_tray_5_point_ir', -0.5, 1.000000, 0.320000);

INSERT INTO DataThing
(_NAME)
VALUES('point_min');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(48, 'point_min', -1.000000, -1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(49, 'part_b_3_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_supply_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(50, 'part_e_supply_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(51, 'tray_gripper_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_a');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(52, 'shape_part_a', 'Shape of PartA');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(52, 'shape_part_a', 'USARSim', 'PartA', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_b');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(53, 'shape_part_b', 'Shape of PartB');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(53, 'shape_part_b', 'USARSim', 'PartB', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_10_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(54, 'part_a_10_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(54, 'part_a_10_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(54, 'part_a_10_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_c');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(55, 'shape_part_c', 'Shape of PartC');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(55, 'shape_part_c', 'USARSim', 'PartC', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(56, 'part_a_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(56, 'part_a_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(56, 'part_a_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_14_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(57, 'part_a_14_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_a_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(58, 'z_axis_kit_a4b4c2_a_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_c_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(59, 'part_ref_and_pose_kit_a4b3c3_c_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_9_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(60, 'part_d_9_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(61, 'part_gripper_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_a_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(62, 'part_ref_and_pose_kit_a4b4c2_a_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_1_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(63, 'part_d_1_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(63, 'part_d_1_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(63, 'part_d_1_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(64, 'part_c_3_point_ir', 0.533400, -0.330200, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_c_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(65, 'x_axis_kit_a4b3c3_c_3_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_6_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(21, 'part_b_6_ir', 'b6', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(66, 'part_b_6_point', -0.240000, 0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_supply_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(67, 'part_d_supply_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(68, 'part_a_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_3_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(69, 'part_d_3_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(70, 'kit_tray_1_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(71, 'part_a_1_point', 0.159000, -0.159000, -0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_d_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(72, 'stock_keeping_unit_part_d_ir', 'SKU for Part D_ir', 0.180000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(72, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_8_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(73, 'part_d_8_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_base_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(74, 'part_gear_base_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(75, 'part_c_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(76, 'part_b_supply_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(76, 'part_b_supply_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(76, 'part_b_supply_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(77, 'part_c_4_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(78, 'x_axis_kit_a4b3c3_b_3_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(79, 'kit_tray_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(80, 'part_b_6_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(80, 'part_b_6_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(80, 'part_b_6_pose');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_b_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(81, 'point_kit_a2b3c3d1e1_b_1_ir', 0.126800, -0.089300, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(82, 'kit_tray_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(22, 'part_gear_4', 'gear4', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_5', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(23, 'part_gear_5', 'gear5', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(24, 'part_gear_2', 'gear2', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(25, 'part_gear_3', 'gear3', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_9_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(83, 'part_b_9_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(83, 'part_b_9_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(83, 'part_b_9_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_c_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(84, 'point_kit_a2b2c1_c_1', 0.060000, -0.090000, -0.045000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_2_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(26, 'part_e_2_ir', 'e2_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_2_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(27, 'part_c_2_ir', 'c2_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_base', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(28, 'part_gear_base', 'gearbase', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(29, 'part_gear_1', 'gear1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_4_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(85, 'part_d_4_point_ir', 0.165600, -0.216000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(86, 'part_b_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(86, 'part_b_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(86, 'part_b_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(87, 'part_c_1_point', 0.110000, -0.216000, -0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(88, 'part_gear_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_c_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(89, 'shape_parts_tray_c_ir', 'Shape of PartsTrays for parts of type C, used for Intention Recognition');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(89, 'shape_parts_tray_c_ir');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(89, 'shape_parts_tray_c_ir', 0.457200, false, 0.025400, 0.863600);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_13_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(90, 'part_a_13_point_ir', 0.088500, -0.089000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(91, 'part_b_2_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(91, 'part_b_2_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(91, 'part_b_2_pose_ir');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_9_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(30, 'part_a_9_ir', 'a9_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c3d1e1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(92, 'kit_a2b3c3d1e1_point', 0.100000, 0.200000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(93, 'part_b_tray_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_8_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(31, 'part_b_8_ir', 'b8_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray_1_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(94, 'stock_keeping_unit_kit_tray_1_ir', 'SKU for KitTray 1', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(94, 1);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_c_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(95, 'stock_keeping_unit_part_c_ir', 'SKU for Part C_ir', 0.180000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(95, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(96, 'part_c_5_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(96, 'part_c_5_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(96, 'part_c_5_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(97, 'kit_tray_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(97, 'kit_tray_3_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(97, 'kit_tray_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_9_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(98, 'part_a_9_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(99, 'part_c_7_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(100, 'part_a_3_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_2_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(32, 'part_d_2_ir', 'd2_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(101, 'part_a_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(102, 'part_c_4_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(102, 'part_c_4_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(102, 'part_c_4_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_d_tray_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(103, 'stock_keeping_unit_parts_d_tray_ir', 'SKU for PartsTrays containing parts of type D, used for Intention Recognition', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(103, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(104, 'part_c_8_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_supply_ir', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(33, 'part_e_supply_ir', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(105, 'part_a_4_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(105, 'part_a_4_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(105, 'part_a_4_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_b_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(106, 'part_ref_and_pose_kit_a4b4c2_b_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(107, 'part_a_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_4_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(34, 'part_b_4_ir', 'b4_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_b_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(108, 'point_kit_a4b4c2_b_2_ir', 0.330600, -0.216400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(109, 'x_axis_kit_a4b4c2_b_1_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_a_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(110, 'x_axis_kit_a4b3c2d1_a_3_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray_3_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(111, 'stock_keeping_unit_kit_tray_3_ir', 'SKU for KitTray 3', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(111, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(112, 'part_c_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(112, 'part_c_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(112, 'part_c_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_4_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(113, 'part_d_4_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_8_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(35, 'part_d_8_ir', 'd8_ir', NULL, NULL);

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
VALUES(115, 'kit_tray_3_point', 2.000000, 0.000000, 0.225000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(116, 'part_a_3_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_5_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(117, 'part_a_5_point_ir', 0.596500, -0.343000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(118, 'x_axis_kit_a2b3c3d1e1_c_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(119, 'z_axis_kit_a2b3c5_b_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_e_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(120, 'x_axis_kit_a2b3c3d1e1_e_1_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(121, 'tray_gripper_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(122, 'part_c_7_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(123, 'part_b_3_point', 0.080000, -0.120000, -0.05);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_shaft_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(36, 'part_gear_shaft_1', 'gear1', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_shaft_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(37, 'part_gear_shaft_2', 'gear2', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_shaft_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(38, 'part_gear_shaft_3', 'gear3', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(124, 'part_c_8_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(124, 'part_c_8_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(124, 'part_c_8_pose_ir');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_shaft_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_Sku)
VALUES(39, 'part_gear_shaft_4', 'gear4', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_e_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(125, 'shape_parts_tray_e_ir', 'Shape of PartsTrays for parts of type E, used for Intention Recognition');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(125, 'shape_parts_tray_e_ir');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(125, 'shape_parts_tray_e_ir', 0.431900, false, 0.025400, 0.889500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_12_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(126, 'part_b_12_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(127, 'part_c_6_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(127, 'part_c_6_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(127, 'part_c_6_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_a_4_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(128, 'point_kit_a4b3c2d1_a_4_ir', 0.088800, -0.088800, -0.065000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_4_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(40, 'part_a_4_ir', 'a4_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_a_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(129, 'x_axis_kit_a4b3c3_a_4_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_4_ir', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku)
VALUES(41, 'kit_tray_4_ir', 31, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(130, 'part_c_7_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(130, 'part_c_7_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(130, 'part_c_7_pose_ir');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_tray_ir', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(42, 'part_a_tray_ir', 6, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(131, 'part_a_2_point_ir', 0.215500, -0.343000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(132, 'part_b_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(133, 'part_b_1_point_ir', 0.088500, -0.330600, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(134, 'part_b_5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_10_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(43, 'part_a_10_ir', 'a10_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_10_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(44, 'part_b_10_ir', 'b10_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_max');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(135, 'point_max', 1.000000, 1.000000, 2.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_12_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(136, 'part_a_12_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a4b3c3_ir');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(137, 'kit_design_a4b3c3_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(138, 'part_b_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_d_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(139, 'shape_part_d_ir', 'Shape of PartD_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(139, 'shape_part_d_ir', 'USARSim', 'BlockD', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(140, 'part_c_supply_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(140, 'part_c_supply_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(140, 'part_c_supply_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(141, 'x_axis_kit_a4b3c2d1_b_2_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('box_volume_1');

INSERT INTO BoxVolume
(BoxVolumeID, _NAME, hasBoxVolume_MaximumPoint, hasBoxVolume_MinimumPoint)
VALUES(142, 'box_volume_1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_9_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(143, 'part_b_9_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(144, 'part_a_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(144, 'part_a_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(144, 'part_a_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_8_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(145, 'part_d_8_point_ir', 0.445000, -0.089000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(146, 'changing_station_base_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_a_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(147, 'point_kit_a4b3c2d1_a_1_ir', 0.622200, -0.368200, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_c_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(148, 'point_kit_a4b3c3_c_1_ir', 0.127000, -0.330600, -0.065000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_1_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(45, 'part_a_1_ir', 'a1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(149, 'part_a_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(150, 'z_axis_kit_a4b3c2d1_a_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(151, 'part_a_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_5_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(152, 'part_e_5_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a4b4c2_ir');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(153, 'kit_design_a4b4c2_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(154, 'part_c_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_3_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(155, 'part_e_3_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(156, 'part_gear_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(156, 'part_gear_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(156, 'part_gear_holder_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(157, 'part_gear_shaft_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_gear');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(158, 'stock_keeping_unit_part_gear', 'SKU for gears', 1.200000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(158, 1);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b4c2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(159, 'kit_a4b4c2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_2_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(160, 'part_d_2_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_b_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(161, 'part_ref_and_pose_kit_a4b3c2d1_b_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(162, 'part_b_5_point_ir', 0.596500, -0.330600, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_4_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(163, 'kit_tray_4_point_ir', -0.5, 1.000000, 0.320000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_a_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(164, 'point_kit_a4b3c2d1_a_3_ir', 0.622200, -0.114200, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_b_4_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(165, 'part_ref_and_pose_kit_a4b4c2_b_4_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b2c1');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(166, 'kit_design_a2b2c1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_a_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(167, 'part_ref_and_pose_kit_a4b3c3_a_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_18_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(168, 'part_a_18_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(169, 'z_axis_kit_a4b4c2_a_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_parts_tray_e_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(170, 'ext_shape_parts_tray_e_ir', 'Shape of PartsTray_E_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(170, 'ext_shape_parts_tray_e_ir', 'USARSim', 'PartTrayE', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(171, 'part_c_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_a_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(172, 'point_kit_a4b3c3_a_3_ir', 0.546100, -0.241700, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(173, 'x_axis_kit_a2b3c3d1e1_a_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_supply_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(174, 'part_e_supply_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_c_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(175, 'part_ref_and_pose_kit_a2b3c3d1e1_c_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(176, 'kit_tray_3_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(176, 'kit_tray_3_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(176, 'kit_tray_3_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(177, 'part_c_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(178, 'x_axis_kit_a2b3c5_c_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(179, 'part_b_8_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(179, 'part_b_8_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(179, 'part_b_8_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(180, 'part_c_6_point_ir', 0.330200, -0.127000, -0.065000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_4_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(46, 'part_c_4_ir', 'c4_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b4c2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(181, 'kit_a4b4c2_point', 0.100000, 0.200000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_c_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(182, 'part_ref_and_pose_kit_a2b3c5_c_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(183, 'part_a_tray_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_10_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(184, 'part_b_10_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_tray_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(185, 'part_e_tray_point_ir', 0.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_11_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(47, 'part_b_11_ir', 'b11_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_2_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(186, 'part_e_2_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(187, 'empty_kit_tray_box_point', 0.500000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_3_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(48, 'part_e_3_ir', 'e3_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_e_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(188, 'part_ref_and_pose_kit_a2b3c3d1e1_e_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(189, 'z_axis_kit_a2b3c5_c_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(190, 'part_c_2_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(190, 'part_c_2_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(190, 'part_c_2_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_b_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(191, 'part_ref_and_pose_kit_a2b3c3d1e1_b_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_tray_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(192, 'part_d_tray_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(193, 'part_b_5_point', -0.080000, 0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(194, 'part_gear_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_3_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(195, 'part_e_3_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(195, 'part_e_3_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(195, 'part_e_3_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_c_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(196, 'point_kit_a2b3c3d1e1_c_1_ir', 0.457000, -0.330600, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_a_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(197, 'x_axis_kit_a4b4c2_a_4_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(198, 'part_b_2_point_ir', 0.215500, -0.330600, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_5_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(199, 'part_a_5_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(199, 'part_a_5_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(199, 'part_a_5_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_c_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(200, 'z_axis_kit_a2b3c3d1e1_c_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_3_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(49, 'part_d_3_ir', 'd3_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_9_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(201, 'part_a_9_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(50, 'part_b_tray', 7, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_c_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(202, 'point_kit_a4b3c2d1_c_2_ir', 0.253900, -0.126900, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(203, 'finished_kit_receiver_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(203, 'finished_kit_receiver_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(203, 'finished_kit_receiver_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(204, 'z_axis_kit_a4b3c3_b_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_a');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(205, 'stock_keeping_unit_part_a', 'SKU for Part A', 0.180000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(205, 1);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_3_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(51, 'part_a_3_ir', 'a3_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_18_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(52, 'part_a_18_ir', 'a18_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(206, 'part_b_7_point_ir', 0.088500, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_b_tray_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(207, 'stock_keeping_unit_parts_b_tray_ir', 'SKU for PartsTrays containing parts of type B, used for Intention Recognition', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(207, 1);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_16_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(53, 'part_a_16_ir', 'a16_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_7_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(54, 'part_d_7_ir', 'd7_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_7_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(55, 'part_c_7_ir', 'c7_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(208, 'work_table_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(209, 'z_axis_kit_a2b3c5_b_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_15_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(56, 'part_a_15_ir', 'a15_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(210, 'part_c_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_6_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(57, 'part_a_6_ir', 'a6_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(211, 'part_b_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(211, 'part_b_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(211, 'part_b_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b3c3d1e1_ir');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(212, 'kit_design_a2b3c3d1e1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(213, 'stock_keeping_unit_kit_tray', 'SKU for KitTrays', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(213, 1);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_a_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(214, 'point_kit_a2b3c3d1e1_a_2_ir', 0.825300, -0.368700, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(215, 'part_b_4_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(215, 'part_b_4_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(215, 'part_b_4_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(216, 'kit_tray_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(217, 'kit_a2b3c5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(218, 'kit_a4b3c3_point', 0.100000, 0.200000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(219, 'finished_kit_box_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(220, 'part_c_2_point_ir', 0.330200, -0.330200, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_a_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(221, 'point_kit_a2b3c5_a_2_ir', 0.215700, -0.114200, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(222, 'part_gripper_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_17_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(223, 'part_a_17_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(224, 'part_gear_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_tray_ir', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(58, 'part_c_tray_ir', 8, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_12_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(225, 'part_b_12_point_ir', 0.723500, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_16_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(226, 'part_a_16_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(226, 'part_a_16_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(226, 'part_a_16_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_e_1_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(227, 'part_e_1_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(228, 'part_b_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_16_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(229, 'part_a_16_point_ir', 0.469500, -0.089000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(230, 'finished_kit_box_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_4_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(231, 'part_e_4_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_10_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(232, 'part_a_10_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_c');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(233, 'stock_keeping_unit_part_c', 'SKU for Part C', 0.180000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(233, 1);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_b');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(234, 'stock_keeping_unit_part_b', 'SKU for Part B', 0.180000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(234, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(235, 'part_b_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_c_5_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(236, 'x_axis_kit_a2b3c5_c_5_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_gear_boss');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(237, 'ext_shape_gear_boss', 'Shape of the gear boss');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(237, 'ext_shape_gear_boss', 'USARSim', 'gear_boss', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_a_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(238, 'point_kit_a4b3c3_a_2_ir', 0.673100, -0.368700, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_a_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(239, 'part_ref_and_pose_kit_a4b4c2_a_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_5_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(240, 'part_gear_5_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(240, 'part_gear_5_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(240, 'part_gear_5_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(241, 'part_c_3_point', -0.110000, -0.216000, -0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_15_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(242, 'part_a_15_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(242, 'part_a_15_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(242, 'part_a_15_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_10_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(243, 'part_b_10_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(243, 'part_b_10_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(243, 'part_b_10_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_a_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(244, 'part_ref_and_pose_kit_a2b1c1_a_2', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(245, 'part_a_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_a_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(246, 'part_ref_and_pose_kit_a2b1c1_a_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(247, 'part_b_3_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(248, 'z_axis_kit_a4b3c2d1_c_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(249, 'part_c_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_d_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(250, 'point_kit_a2b3c3d1e1_d_1_ir', 0.291900, -0.292500, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(251, 'part_gear_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_changing_station_base');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(252, 'shape_changing_station_base', 'Shape of base of changing station');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(252, 'shape_changing_station_base');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(252, 'shape_changing_station_base', 0.100000, true, 1.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_11_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(253, 'part_a_11_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_box_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(254, 'stock_keeping_unit_kit_box_ir', 'SKU for Boxes for Kits and KitTrays for Intention Recognition', 1.200000, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(255, 'part_b_8_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_tray_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(256, 'part_e_tray_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_13_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(257, 'part_a_13_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(257, 'part_a_13_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(257, 'part_a_13_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_a_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(258, 'point_kit_a2b2c1_a_2', -0.159000, -0.149000, -0.036000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_a_tray_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(259, 'stock_keeping_unit_parts_a_tray_ir', 'SKU for PartsTrays containing parts of type A, used for Intention Recognition', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(259, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(260, 'part_c_5_point_ir', 0.127000, -0.127000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_a_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(261, 'point_kit_a2b2c1_a_1', -0.159000, 0.145000, -0.036000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_4_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(59, 'part_e_4_ir', 'e4_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_6_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(262, 'part_e_6_point_ir', 0.724400, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_b_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(263, 'part_ref_and_pose_kit_a4b3c2d1_b_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(264, 'x_axis_kit_a4b4c2_a_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(265, 'changing_station_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(266, 'empty_kit_tray_supply_point', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(267, 'part_gear_holder_point', 0.60000, 2.3000, 0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_c_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(268, 'part_ref_and_pose_kit_a4b3c3_c_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(269, 'kit_tray_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_9_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(270, 'part_b_9_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(271, 'part_c_7_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(271, 'part_c_7_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(271, 'part_c_7_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(272, 'part_gripper_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_c_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(273, 'point_kit_a4b4c2_c_1_ir', 0.127400, -0.381300, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_1_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(274, 'part_d_1_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_11_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(275, 'part_b_11_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(276, 'robot_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_11_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(277, 'part_b_11_point_ir', 0.596500, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(278, 'part_b_7_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(279, 'x_axis_kit_a2b1c1_c_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_boss_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(280, 'part_gear_boss_point', 1.20000, 0.20000, 0.05000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(60, 'part_c_tray', 8, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_b_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(281, 'point_kit_a2b3c5_b_3_ir', 0.749100, -0.126900, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_a_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(282, 'part_ref_and_pose_kit_a4b3c3_a_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(283, 'x_axis_kit_a4b3c3_a_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_7_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(284, 'part_d_7_point_ir', 0.165600, -0.089000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_14_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(285, 'part_a_14_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_7_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(61, 'part_b_7_ir', 'b7', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_c_5_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(286, 'z_axis_kit_a2b3c5_c_5_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_receiver_ir', NULL);

INSERT INTO LargeBoxWithKits
(LargeBoxWithKitsID, _NAME, hasLargeBoxWithKits_Capacity, hasLargeBoxWithKits_LargeContainer, hasLargeBoxWithKits_KitDesign)
VALUES(62, 'finished_kit_receiver_ir', 12, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_c_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(287, 'z_axis_kit_a2b3c5_c_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(288, 'part_b_2_point', -0.240000, -0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_2_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(289, 'part_e_2_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(289, 'part_e_2_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(289, 'part_e_2_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(290, 'part_gripper_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(291, 'part_b_6_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(292, 'x_axis_kit_a4b3c2d1_c_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(293, 'part_c_7_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(294, 'empty_kit_tray_box_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(63, 'empty_kit_tray_box', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(295, 'z_axis_kit_a2b3c5_c_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(296, 'part_c_4_point', -0.330000, -0.216000, -0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(297, 'x_axis_kit_a2b1c1_a_2', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(298, 'z_axis_kit_a4b3c2d1_a_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(299, 'x_axis_kit_a2b1c1_a_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(300, 'part_c_tray_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(301, 'part_c_1_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(302, 'part_b_6_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_boss_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(303, 'part_gear_boss_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(303, 'part_gear_boss_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(303, 'part_gear_boss_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_6_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(304, 'part_d_6_point_ir', 0.724400, -0.216000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(305, 'z_axis_kit_a2b3c5_a_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_9_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(306, 'part_a_9_point_ir', 0.342500, -0.216000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(307, 'part_gear_shaft_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(308, 'part_a_tray_point_ir', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(309, 'part_c_5_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(310, 'part_b_8_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(311, 'part_b_supply_point_ir', -3.400000, 2.350000, 0.320000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(312, 'part_b_1_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(313, 'part_c_7_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_gear_holder');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(314, 'ext_shape_gear_holder', 'Shape of the gear holder');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(314, 'ext_shape_gear_holder', 'USARSim', 'gear_holder', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_b_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(315, 'point_kit_a4b3c3_b_1_ir', 0.292100, -0.128000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_4_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(316, 'kit_tray_4_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_11_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(317, 'part_b_11_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(318, 'part_c_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(319, 'kit_tray_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(319, 'kit_tray_1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(319, 'kit_tray_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(320, 'part_c_supply_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_a');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(321, 'shape_parts_tray_a', 'Shape of PartsTray_A');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(321, 'shape_parts_tray_a', 'USARSim', 'PartATray', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_b');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(322, 'shape_parts_tray_b', 'Shape of PartsTray_B');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(322, 'shape_parts_tray_b', 'USARSim', 'PartBTray', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_c');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(323, 'shape_parts_tray_c', 'Shape of PartsTray_C');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(323, 'shape_parts_tray_c', 'USARSim', 'PartCTray', 'USARPhysObj');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_12_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(64, 'part_a_12_ir', 'a12_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(324, 'part_a_4_point', -0.159000, -0.159000, -0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(325, 'part_c_1_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_in_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(326, 'relative_location_in_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(326, 'relative_location_in_1', 'The  KittingWorkstation is in kitting_workstation_1');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(326, 'relative_location_in_1');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_c_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(327, 'part_ref_and_pose_kit_a4b4c2_c_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(328, 'x_axis_kit_a4b3c2d1_a_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(329, 'z_axis_kit_a2b3c3d1e1_b_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(330, 'part_a_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(331, 'part_gear_shaft_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(331, 'part_gear_shaft_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(331, 'part_gear_shaft_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_4_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(332, 'kit_tray_4_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(332, 'kit_tray_4_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(332, 'kit_tray_4_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_c_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(333, 'point_kit_a2b1c1_c_1', 0.400000, -0.500000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_6_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(334, 'part_d_6_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(335, 'empty_kit_tray_supply_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_supply_ir', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(65, 'part_b_supply_ir', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(336, 'part_c_2_point', 0.330000, -0.216000, -0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(337, 'z_axis_kit_a4b3c2d1_b_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(338, 'kit_tray_2_point', 0.75, 0.000000, 0.155000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(339, 'part_gripper_holder_point', 0.250000, 0.000000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(340, 'x_axis_kit_a2b3c5_a_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(341, 'part_c_6_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(342, 'z_axis_kit_a4b3c2d1_b_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(343, 'part_c_1_point_ir', 0.127000, -0.330200, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_17_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(344, 'part_a_17_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(344, 'part_a_17_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(344, 'part_a_17_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(345, 'part_a_supply_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray_2_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(346, 'stock_keeping_unit_kit_tray_2_ir', 'SKU for KitTray 2', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(346, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(347, 'part_c_6_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(347, 'part_c_6_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(347, 'part_c_6_pose');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_c_tray_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(348, 'stock_keeping_unit_parts_c_tray_ir', 'SKU for PartsTrays containing parts of type C, used for Intention Recognition', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(348, 1);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b3c5_ir');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(349, 'kit_design_a2b3c5_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(350, 'part_b_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(351, 'empty_kit_tray_box_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_1_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(66, 'part_d_1_ir', 'd1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(352, 'part_c_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(352, 'part_c_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(352, 'part_c_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_e_2_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(353, 'part_e_2_point_ir', 0.445000, -0.330600, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(354, 'changing_station_base_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(354, 'changing_station_base_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(354, 'changing_station_base_pose');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_a_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(355, 'point_kit_a2b3c5_a_1_ir', 0.215700, -0.241200, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(356, 'part_a_3_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(356, 'part_a_3_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(356, 'part_a_3_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(357, 'part_c_5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(358, 'z_axis_kit_a4b3c3_a_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_5_ir', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku)
VALUES(67, 'kit_tray_5_ir', 32, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(359, 'part_a_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(359, 'part_a_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(359, 'part_a_3_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_a2b3c3d1e1', NULL);

INSERT INTO Kit
(KitID, _NAME, isKit_Finished, hasKit_Tray, hasKit_Design)
VALUES(68, 'kit_a2b3c3d1e1', false, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(360, 'part_b_5_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(361, 'part_c_2_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_b_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(362, 'part_ref_and_pose_kit_a4b4c2_b_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(363, 'finished_kit_receiver_point_ir', 1.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(364, 'kit_a4b3c3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(365, 'part_gear_shaft_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(366, 'kit_a2b3c5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(367, 'finished_kit_receiver_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_d_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(368, 'part_ref_and_pose_kit_a2b3c3d1e1_d_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(369, 'kit_tray_1_point_ir', -0.5, 1.000000, 0.320000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_b_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(370, 'part_ref_and_pose_kit_a2b3c5_b_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_5_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(371, 'part_a_5_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_5_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(372, 'part_d_5_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_supply_ir', NULL);

INSERT INTO LargeBoxWithEmptyKitTrays
(LargeBoxWithEmptyKitTraysID, _NAME, hasLargeBoxWithEmptyKitTrays_LargeContainer)
VALUES(69, 'empty_kit_tray_supply_ir', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(373, 'part_b_7_point', 0.080000, 0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(374, 'part_gear_shaft_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(375, 'part_gear_shaft_3_point', 0.6000, 2.1000, 0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(376, 'part_b_8_point_ir', 0.215500, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_gear_shaft');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(377, 'ext_shape_gear_shaft', 'Shape of the gear shaft');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(377, 'ext_shape_gear_shaft', 'USARSim', 'gear_shaft', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(378, 'changing_station_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(378, 'changing_station_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(378, 'changing_station_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_e_5_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(379, 'part_e_5_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(379, 'part_e_5_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(379, 'part_e_5_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(380, 'z_axis_kit_a2b1c1_b_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_6_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(381, 'part_a_6_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_4_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(382, 'part_e_4_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(383, 'x_axis_kit_a2b2c1_a_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_c_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(384, 'point_kit_a2b3c3d1e1_c_2_ir', 0.660200, -0.330600, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(385, 'x_axis_kit_a2b2c1_a_2', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c2d1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(386, 'kit_a4b3c2d1_point', 0.100000, 0.200000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(387, 'part_b_8_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(388, 'part_c_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_tray_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(389, 'part_e_tray_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(389, 'part_e_tray_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(389, 'part_e_tray_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(390, 'part_a_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(391, 'part_c_8_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(392, 'x_axis_kit_a2b2c1_c_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_base_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(393, 'part_gear_base_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(393, 'part_gear_base_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(393, 'part_gear_base_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(394, 'part_c_7_point_ir', 0.533400, -0.127000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(395, 'robot_point', 3.000000, 0.000000, 2.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(396, 'finished_kit_box_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(397, 'part_c_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_parts_tray_a_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(398, 'ext_shape_parts_tray_a_ir', 'Shape of PartsTray_A_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(398, 'ext_shape_parts_tray_a_ir', 'USARSim', 'PartTrayA', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(399, 'part_b_7_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(400, 'part_a_3_point_ir', 0.342500, -0.343000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(401, 'part_a_2_point', 0.159000, 0.159000, -0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_4_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(402, 'part_d_4_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(402, 'part_d_4_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(402, 'part_d_4_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(403, 'x_axis_kit_a2b3c5_b_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_1_ir', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku)
VALUES(70, 'kit_tray_1_ir', 30, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_12_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(404, 'part_b_12_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(404, 'part_b_12_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(404, 'part_b_12_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_b_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(405, 'point_kit_a2b3c5_b_2_ir', 0.088700, -0.203100, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(406, 'part_c_5_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(407, 'part_c_8_point_ir', 0.736600, -0.127000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_a_4_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(408, 'part_ref_and_pose_kit_a4b3c3_a_4_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_supply_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(409, 'part_e_supply_point_ir', -0.250000, 0.320000, 0.320000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray_4_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(410, 'shape_kit_tray_4_ir', 'Shape of KitTray 3');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(410, 'shape_kit_tray_4_ir', 'USARSim', 'KitTray4', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_e_1_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(411, 'part_e_1_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(411, 'part_e_1_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(411, 'part_e_1_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_c_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(412, 'part_ref_and_pose_kit_a2b3c3d1e1_c_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(413, 'part_b_1_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(414, 'z_axis_kit_a2b2c1_b_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_b_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(415, 'z_axis_kit_a2b2c1_b_2', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(416, 'x_axis_kit_a2b3c3d1e1_c_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_c_5_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(417, 'part_ref_and_pose_kit_a2b3c5_c_5_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_b_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(418, 'part_ref_and_pose_kit_a2b2c1_b_2', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_b_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(419, 'part_ref_and_pose_kit_a2b2c1_b_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(420, 'kit_tray_1_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(420, 'kit_tray_1_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(420, 'kit_tray_1_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_7_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(421, 'part_a_7_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(422, 'part_b_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(422, 'part_b_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(422, 'part_b_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(423, 'kit_tray_2_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(424, 'part_gear_shaft_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_14_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(425, 'part_a_14_point_ir', 0.215500, -0.089000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_6_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(426, 'part_e_6_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_tray_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(427, 'part_d_tray_point_ir', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(428, 'part_c_supply_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(429, 'empty_kit_tray_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_c_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(430, 'z_axis_kit_a4b3c3_c_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(431, 'part_c_2_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_c_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(432, 'x_axis_kit_a2b3c5_c_4_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_8_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(71, 'part_a_8_ir', 'a8_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c3d1e1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(433, 'kit_a2b3c3d1e1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gripper_holder', NULL);

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_ChangingStation, hasEndEffectorHolder_EndEffector)
VALUES(72, 'part_gripper_holder', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(434, 'part_c_8_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(435, 'changing_station_base_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(436, 'part_gear_5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_b_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(437, 'z_axis_kit_a4b4c2_b_4_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_e_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(438, 'z_axis_kit_a2b3c3d1e1_e_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_2_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(439, 'part_d_2_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(439, 'part_d_2_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(439, 'part_d_2_pose_ir');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_supply_ir', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(73, 'part_c_supply_ir', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(440, 'part_c_6_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(441, 'part_gripper_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(441, 'part_gripper_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(441, 'part_gripper_pose');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_gear_base');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(442, 'stock_keeping_unit_part_gear_base', 'SKU for gear base', 1.200000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(442, 1);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(443, 'empty_kit_tray_supply_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(443, 'empty_kit_tray_supply_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(443, 'empty_kit_tray_supply_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(444, 'part_c_3_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(444, 'part_c_3_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(444, 'part_c_3_pose_ir');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_6_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(74, 'part_c_6_ir', 'c6_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(445, 'part_c_6_point', 0.330000, 0.216000, -0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_7_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(446, 'part_a_7_point_ir', 0.088500, -0.216000, -0.065000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_8_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(75, 'part_c_8_ir', 'c8_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_17_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(76, 'part_a_17_ir', 'a17_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_e_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(447, 'stock_keeping_unit_part_e_ir', 'SKU for Part E_ir', 0.180000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(447, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_6_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(448, 'part_e_6_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(449, 'part_b_tray_point_ir', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_e_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(450, 'shape_part_e_ir', 'Shape of PartE_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(450, 'shape_part_e_ir', 'USARSim', 'BlockE', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(451, 'part_b_6_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(451, 'part_b_6_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(451, 'part_b_6_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_c_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(452, 'z_axis_kit_a2b3c5_c_4_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_a4b3c2d1', NULL);

INSERT INTO Kit
(KitID, _NAME, isKit_Finished, hasKit_Tray, hasKit_Design)
VALUES(77, 'kit_a4b3c2d1', false, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(453, 'part_a_supply_point_ir', -0.250000, 2.350000, 0.320000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_3_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(78, 'part_b_3_ir', 'b3_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(454, 'part_gear_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(455, 'x_axis_kit_a4b4c2_b_2_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(456, 'x_axis_kit_a2b3c5_a_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_boss_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(457, 'part_gear_boss_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_11_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(458, 'part_b_11_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(458, 'part_b_11_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(458, 'part_b_11_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(459, 'part_b_7_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(459, 'part_b_7_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(459, 'part_b_7_pose');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(460, 'x_axis_kit_a2b3c3d1e1_b_1_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(461, 'part_a_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(462, 'part_c_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(463, 'x_axis_kit_a4b3c3_b_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper', NULL);

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_Weight, hasEffector_MaximumLoadWeight, hadByEndEffector_Robot)
VALUES(79, 'tray_gripper', 'large single cup vacuum effector', 0.040000, 0.500000, NULL);

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(79, 'tray_gripper', 0.040000, 0.100000);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(79, 'tray_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(464, 'empty_kit_tray_box_point_ir', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_a_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(465, 'z_axis_kit_a4b4c2_a_4_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(466, 'work_table_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(467, 'x_axis_kit_a2b3c3d1e1_b_3_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray_5_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(468, 'shape_kit_tray_5_ir', 'Shape of KitTray 5');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(468, 'shape_kit_tray_5_ir', 'USARSim', 'KitTray5', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(469, 'part_b_2_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_c_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(470, 'part_ref_and_pose_kit_a4b4c2_c_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(471, 'part_b_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(471, 'part_b_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(471, 'part_b_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(472, 'kit_tray_2_point_ir', -0.5, 1.000000, 0.320000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(473, 'part_gear_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(474, 'part_gear_5_point', 1.000, 0.2000, 0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(475, 'part_b_4_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_work_table');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(476, 'shape_work_table', 'Shape of the work table');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(476, 'shape_work_table');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(476, 'shape_work_table', 0.800000, true, 0.500000, 1.600000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(80, 'part_b_1', 'b1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(477, 'kit_tray_1_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(81, 'part_b_2', 'b2', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_5', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(82, 'part_b_5', 'b5', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_6', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(83, 'part_b_6', 'b6', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(84, 'part_b_3', 'b3', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(85, 'part_b_4', 'b4', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(478, 'empty_kit_tray_supply_point_ir', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_box_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(479, 'shape_kit_box_ir', 'Shape of boxes to hold kits and kit trays used for Intention Recognition');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(479, 'shape_kit_box_ir');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(479, 'shape_kit_box_ir', 0.500000, false, 0.800000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_8_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(480, 'part_a_8_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_7', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(86, 'part_b_7', 'b7', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_8', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(87, 'part_b_8', 'b8', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(481, 'part_b_3_point_ir', 0.342500, -0.330600, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(482, 'part_gripper_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_a_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(483, 'part_ref_and_pose_kit_a4b3c3_a_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_5_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(88, 'part_d_5_ir', 'd5_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_8_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(484, 'part_a_8_point_ir', 0.215500, -0.216000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(485, 'z_axis_kit_a4b4c2_c_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(486, 'part_c_8_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(487, 'tray_gripper_holder_point', -0.250000, 0.000000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(488, 'part_c_tray_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(488, 'part_c_tray_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(488, 'part_c_tray_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_5_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(489, 'part_a_5_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(490, 'z_axis_kit_a2b3c3d1e1_c_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(491, 'empty_kit_tray_box_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_gear_shaft');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(492, 'stock_keeping_unit_part_gear_shaft', 'SKU for gear shaft', 1.200000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(492, 79);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(493, 'x_axis_kit_a4b3c2d1_c_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b4c2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(494, 'kit_a4b4c2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(494, 'kit_a4b4c2_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(494, 'kit_a4b4c2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_b_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(495, 'part_ref_and_pose_kit_a2b3c3d1e1_b_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(496, 'empty_kit_tray_supply_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(89, 'finished_kit_box', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(497, 'kit_a4b3c3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_6_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(90, 'part_e_6_ir', 'e6_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(498, 'x_axis_kit_a4b4c2_c_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_11_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(499, 'part_a_11_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(499, 'part_a_11_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(499, 'part_a_11_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_base_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(500, 'part_gear_base_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(501, 'part_c_8_point', -0.330000, 0.216000, -0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_9_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(502, 'part_d_9_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(502, 'part_d_9_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(502, 'part_d_9_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_b_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(503, 'part_ref_and_pose_kit_a2b3c5_b_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(504, 'part_c_5_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(504, 'part_c_5_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(504, 'part_c_5_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(505, 'part_b_7_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(505, 'part_b_7_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(505, 'part_b_7_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(506, 'part_a_1_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(506, 'part_a_1_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(506, 'part_a_1_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(507, 'part_gear_shaft_1_point', 0.6000, 1.90000, 0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(508, 'part_gear_shaft_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(508, 'part_gear_shaft_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(508, 'part_gear_shaft_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_a_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(509, 'x_axis_kit_a4b3c2d1_a_4_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_receiver', NULL);

INSERT INTO LargeBoxWithKits
(LargeBoxWithKitsID, _NAME, hasLargeBoxWithKits_Capacity, hasLargeBoxWithKits_LargeContainer, hasLargeBoxWithKits_KitDesign)
VALUES(91, 'finished_kit_receiver', 12, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(510, 'shape_kit_tray', 'Shape of KitTrays');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(510, 'shape_kit_tray', 'USARSim', 'WCKitTraySmall', 'USARPhysObj');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(92, 'part_b_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(511, 'part_b_4_point_ir', 0.469500, -0.330600, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_1_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(512, 'part_e_1_point_ir', 0.165600, -0.330600, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_18_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(513, 'part_a_18_point_ir', 0.723500, -0.089000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(514, 'part_b_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(515, 'kit_tray_3_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_InternalShape, hasSolidObject_PrimaryLocation)
VALUES('work_table_1', NULL, NULL);

INSERT INTO WorkTable
(WorkTableID, _NAME)
VALUES(93, 'work_table_1');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(516, 'z_axis_kit_a4b4c2_a_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_6_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(517, 'part_a_6_point_ir', 0.723500, -0.343000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(518, 'part_b_3_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(518, 'part_b_3_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(518, 'part_b_3_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_b_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(519, 'part_ref_and_pose_kit_a2b3c5_b_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_a_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(520, 'point_kit_a4b4c2_a_1_ir', 0.495700, -0.419400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_b_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(521, 'point_kit_a4b4c2_b_3_ir', 0.127400, -0.089370, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_c_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(522, 'point_kit_a4b3c3_c_2_ir', 0.330200, -0.330600, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_parts_tray_c_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(523, 'ext_shape_parts_tray_c_ir', 'Shape of PartsTray_C_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(523, 'ext_shape_parts_tray_c_ir', 'USARSim', 'PartTrayC', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(524, 'kit_tray_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_5_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(525, 'part_e_5_point_ir', 0.445000, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_18_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(526, 'part_a_18_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_3_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(94, 'part_c_3_ir', 'c3_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(527, 'part_b_5_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(527, 'part_b_5_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(527, 'part_b_5_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_6_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(528, 'part_a_6_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_2_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(529, 'part_d_2_point_ir', 0.445000, -0.343000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_d_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(530, 'z_axis_kit_a4b3c2d1_d_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray_1_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(531, 'shape_kit_tray_1_ir', 'Shape of KitTray 1');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(531, 'shape_kit_tray_1_ir', 'USARSim', 'KitTray1', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_c_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(532, 'part_ref_and_pose_kit_a2b3c5_c_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_c_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(533, 'part_ref_and_pose_kit_a4b3c3_c_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(534, 'part_c_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(534, 'part_c_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(534, 'part_c_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(535, 'x_axis_kit_a4b3c2d1_a_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_9_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(536, 'part_a_9_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(536, 'part_a_9_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(536, 'part_a_9_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_a_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(537, 'point_kit_a4b3c2d1_a_2_ir', 0.622200, -0.241200, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_b_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(538, 'point_kit_a4b3c2d1_b_2_ir', 0.457100, -0.241200, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_b_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(539, 'point_kit_a4b3c3_b_2_ir', 0.419100, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_c_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(540, 'part_ref_and_pose_kit_a2b1c1_c_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_b_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(541, 'shape_parts_tray_b_ir', 'Shape of PartsTrays for parts of type B, used for Intention Recognition');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(541, 'shape_parts_tray_b_ir');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(541, 'shape_parts_tray_b_ir', 0.457600, false, 0.025400, 0.812400);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(542, 'part_a_3_point', -0.159000, 0.159000, -0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_a_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(543, 'point_kit_a4b4c2_a_3_ir', 0.495700, -0.292400, -0.065000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_a2b3c5', NULL);

INSERT INTO Kit
(KitID, _NAME, isKit_Finished, hasKit_Tray, hasKit_Design)
VALUES(95, 'kit_a2b3c5', false, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_1_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(96, 'part_e_1_ir', 'e1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(544, 'part_a_4_point_ir', 0.469500, -0.343000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(545, 'part_b_6_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a4b3c2d1_ir');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(546, 'kit_design_a4b3c2d1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(547, 'x_axis_kit_a4b3c2d1_b_3_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_b_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(548, 'part_ref_and_pose_kit_a4b3c3_b_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_4_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(549, 'kit_tray_4_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_a_4_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(550, 'point_kit_a4b3c3_a_4_ir', 0.673100, -0.241700, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_10_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(551, 'part_a_10_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(552, 'part_c_supply_point', -3.000000, 0.780000, 0.280000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(553, 'changing_station_base_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_5_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(554, 'part_d_5_point_ir', 0.445000, -0.216000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(555, 'x_axis_kit_a4b3c3_b_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_9_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(97, 'part_d_9_ir', 'd9_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(556, 'part_b_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(557, 'finished_kit_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(557, 'finished_kit_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(557, 'finished_kit_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_c_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(558, 'x_axis_kit_a2b3c3d1e1_c_3_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_5_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(98, 'part_a_5_ir', 'a5_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(559, 'finished_kit_box_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(559, 'finished_kit_box_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(559, 'finished_kit_box_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(560, 'part_c_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(560, 'part_c_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(560, 'part_c_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_b_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(561, 'part_ref_and_pose_kit_a4b3c3_b_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_5_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(562, 'part_d_5_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(562, 'part_d_5_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(562, 'part_d_5_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_c_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(563, 'point_kit_a2b3c5_c_1_ir', 0.380800, -0.330100, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(564, 'part_a_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(565, 'part_gear_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(566, 'x_axis_kit_a4b3c2d1_b_1_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(567, 'part_b_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_3_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(568, 'part_d_3_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(568, 'part_d_3_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(568, 'part_d_3_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_supply_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(569, 'part_d_supply_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_b_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(570, 'part_ref_and_pose_kit_a2b3c3d1e1_b_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(571, 'z_axis_kit_a2b3c3d1e1_b_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_b_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(572, 'point_kit_a2b3c3d1e1_b_3_ir', 0.825300, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(573, 'part_a_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(573, 'part_a_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(573, 'part_a_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_3_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(574, 'part_d_3_point_ir', 0.724400, -0.343000, -0.065000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_12_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(99, 'part_b_12_ir', 'b12_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(575, 'part_a_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_a_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(576, 'part_ref_and_pose_kit_a4b3c2d1_a_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(577, 'part_b_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b4c2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(578, 'kit_a4b4c2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_12_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(579, 'part_a_12_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(579, 'part_a_12_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(579, 'part_a_12_pose_ir');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kitting_workstation_1', NULL);

INSERT INTO KittingWorkstation
(KittingWorkstationID, _NAME, hasWorkstation_LengthUnit, hasWorkstation_AngleUnit, hasWorkstation_WeightUnit, hasWorkstation_ChangingStation, hasWorkstation_WorkTable, hasWorkstation_Robot)
VALUES(100, 'kitting_workstation_1', 'meter', 'degree', 'kilogram', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(580, 'x_axis_kit_a2b3c3d1e1_a_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_a_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(581, 'z_axis_kit_a4b3c3_a_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(582, 'empty_kit_tray_box_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_6_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(583, 'part_e_6_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(583, 'part_e_6_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(583, 'part_e_6_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(584, 'part_gear_4_point', 0.8000, 0.20000, 0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_7_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(585, 'part_a_7_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(586, 'kit_a4b3c3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(586, 'kit_a4b3c3_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(586, 'kit_a4b3c3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(587, 'part_gear_2_point', 1, 0.0000, 0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(588, 'kit_tray_1_point', 0.050000, 0.750000, 0.280000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_tray_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(589, 'part_d_tray_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(590, 'part_a_supply_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(590, 'part_a_supply_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(590, 'part_a_supply_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_6_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(591, 'part_d_6_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(592, 'kit_tray_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_1_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(593, 'part_d_1_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_c_4_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(594, 'part_ref_and_pose_kit_a2b3c5_c_4_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_c_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(595, 'part_ref_and_pose_kit_a2b3c3d1e1_c_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(596, 'part_a_2_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(597, 'changing_station_point', 7.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_c_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(598, 'shape_part_c_ir', 'Shape of PartC_ir
');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(598, 'shape_part_c_ir', 'USARSim', 'BlockC', 'USARPhysObj');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_1_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(101, 'part_c_1_ir', 'c1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(599, 'part_a_supply_point', -2.850000, 1.550000, 0.300000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(600, 'kit_tray_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(600, 'kit_tray_2_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(600, 'kit_tray_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(601, 'part_c_6_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(602, 'part_b_6_point_ir', 0.723500, -0.330600, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_13_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(603, 'part_a_13_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(604, 'part_c_1_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(604, 'part_c_1_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(604, 'part_c_1_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_e_1_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(605, 'part_e_1_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_c_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(606, 'point_kit_a4b3c3_c_3_ir', 0.127000, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(607, 'robot_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(607, 'robot_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(607, 'robot_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(608, 'part_c_tray_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_5_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(102, 'part_c_5_ir', 'c5_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(609, 'z_axis_kit_a4b3c3_b_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_11_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(610, 'part_a_11_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_6_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(611, 'part_d_6_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(611, 'part_d_6_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(611, 'part_d_6_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_a_4_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(612, 'part_ref_and_pose_kit_a4b4c2_a_4_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_10_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(613, 'part_b_10_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_e_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(614, 'point_kit_a2b3c3d1e1_e_1_ir', 0.126800, -0.292500, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_b_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(615, 'x_axis_kit_a4b4c2_b_4_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(616, 'tray_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(616, 'tray_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(616, 'tray_gripper_holder_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_a_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(617, 'part_ref_and_pose_kit_a2b3c3d1e1_a_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(618, 'part_gear_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gripper', NULL);

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_Weight, hasEffector_MaximumLoadWeight)
VALUES(103, 'part_gripper', 'small single cup vacuum effector', 0.010000, 0.400000);

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(103, 'part_gripper', 0.020000, 0.025000);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(103, 'part_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_15_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(619, 'part_a_15_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(620, 'x_axis_kit_a4b4c2_a_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_InternalShape, hasSolidObject_PrimaryLocation)
VALUES('changing_station_base', NULL, NULL);

INSERT INTO MechanicalComponent
(MechanicalComponentID, _NAME)
VALUES(104, 'changing_station_base');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_15_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(621, 'part_a_15_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_d_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(622, 'z_axis_kit_a2b3c3d1e1_d_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_b_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(623, 'point_kit_a2b3c3d1e1_b_2_ir', 0.698300, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_b_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(624, 'part_ref_and_pose_kit_a4b4c2_b_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c3d1e1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(625, 'kit_a2b3c3d1e1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_a_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(626, 'stock_keeping_unit_part_a_ir', 'SKU for Part A_ir', 0.180000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(626, 103);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(627, 'part_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(627, 'part_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(627, 'part_gripper_holder_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_base_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(628, 'part_gear_base_point', 1.0000, 2.0000, 0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(629, 'z_axis_kit_a2b3c3d1e1_a_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_15_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(630, 'part_a_15_point_ir', 0.342500, -0.089000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_5_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(631, 'kit_tray_5_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_a_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(632, 'z_axis_kit_a4b3c2d1_a_4_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_3_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(633, 'part_e_3_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(634, 'part_gear_3_point', 1.2000, 0.0000, 0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_parts_tray_d_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(635, 'ext_shape_parts_tray_d_ir', 'Shape of PartsTray_D_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(635, 'ext_shape_parts_tray_d_ir', 'USARSim', 'PartTrayD', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray_4_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(636, 'stock_keeping_unit_kit_tray_4_ir', 'SKU for KitTray 4', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(636, 103);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(637, 'part_c_supply_point_ir', -3.400000, 0.320000, 0.320000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(638, 'part_a_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(638, 'part_a_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(638, 'part_a_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(639, 'part_b_tray_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_9_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(640, 'part_b_9_point_ir', 0.342500, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(641, 'kit_tray_2_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(641, 'kit_tray_2_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(641, 'kit_tray_2_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(642, 'part_gear_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(642, 'part_gear_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(642, 'part_gear_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(643, 'part_gear_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(643, 'part_gear_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(643, 'part_gear_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(644, 'part_c_tray_point_ir', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(645, 'part_a_supply_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(646, 'part_a_1_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_tray_ir', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(105, 'part_e_tray_ir', 10, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_a_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(647, 'shape_parts_tray_a_ir', 'Shape of PartsTrays for parts of type A, used for Intention Recognition');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(647, 'shape_parts_tray_a_ir');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(647, 'shape_parts_tray_a_ir', 0.431900, false, 0.025400, 0.812400);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_b_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(648, 'part_ref_and_pose_kit_a4b3c2d1_b_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(649, 'part_b_supply_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(650, 'finished_kit_box_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_box');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(651, 'stock_keeping_unit_kit_box', 'SKU for Boxes for Kits and KitTrays', 1.200000, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(652, 'part_gear_shaft_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_supply_ir', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(106, 'part_d_supply_ir', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(653, 'part_b_4_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_supply_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(654, 'part_e_supply_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(654, 'part_e_supply_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(654, 'part_e_supply_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_b_4_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(655, 'point_kit_a4b4c2_b_4_ir', 0.330600, -0.089370, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_b_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(656, 'point_kit_a4b4c2_b_1_ir', 0.127400, -0.216400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_d_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(657, 'x_axis_kit_a2b3c3d1e1_d_1_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(658, 'part_a_4_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_box');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(659, 'shape_kit_box', 'Shape of boxes to hold kits and kit trays');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(659, 'shape_kit_box');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(659, 'shape_kit_box', 0.700000, false, 0.800000, 0.900000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_5_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(107, 'part_b_5_ir', 'b5_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_5_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(660, 'part_d_5_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(661, 'part_gear_shaft_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_12_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(662, 'part_a_12_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(663, 'part_a_1_point_ir', 0.088500, -0.343000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_10_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(664, 'part_b_10_point_ir', 0.469500, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_a');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(665, 'stock_keeping_unit_parts_tray_a', 'SKU for Part a PartsTray', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(665, 103);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(666, 'kit_tray_3_point_ir', -0.5, 1.000000, 0.320000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_c');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(667, 'stock_keeping_unit_parts_tray_c', 'SKU for Part c PartsTrays', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(667, 103);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(668, 'part_b_1_point', -0.080000, -0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_b');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(669, 'stock_keeping_unit_parts_tray_b', 'SKU for Part b PartsTrays', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(669, 103);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(670, 'part_b_8_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(670, 'part_b_8_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(670, 'part_b_8_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(671, 'part_b_7_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_a_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(672, 'part_ref_and_pose_kit_a2b3c3d1e1_a_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(673, 'changing_station_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_9_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(674, 'part_d_9_point_ir', 0.724400, -0.089000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(675, 'part_c_6_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_b_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(676, 'part_ref_and_pose_kit_a2b1c1_b_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(677, 'work_table_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(677, 'work_table_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(677, 'work_table_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_box_ir', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(108, 'empty_kit_tray_box_ir', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(678, 'part_gear_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_17_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(679, 'part_a_17_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_14_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(109, 'part_a_14_ir', 'a14_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_13_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(680, 'part_a_13_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_18_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(681, 'part_a_18_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(681, 'part_a_18_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(681, 'part_a_18_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(682, 'z_axis_kit_a4b3c2d1_c_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_12_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(683, 'part_a_12_point_ir', 0.723500, -0.216000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_2_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(684, 'part_d_2_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(685, 'part_gear_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(686, 'z_axis_kit_a2b3c5_a_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(687, 'z_axis_kit_a2b2c1_a_2', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(688, 'z_axis_kit_a4b3c3_a_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_supply', NULL);

INSERT INTO LargeBoxWithEmptyKitTrays
(LargeBoxWithEmptyKitTraysID, _NAME, hasLargeBoxWithEmptyKitTrays_LargeContainer)
VALUES(110, 'empty_kit_tray_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(689, 'x_axis_kit_a2b3c5_b_1_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(690, 'z_axis_kit_a2b3c3d1e1_b_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(691, 'part_b_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(692, 'part_a_tray_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(692, 'part_a_tray_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(692, 'part_a_tray_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_e_3_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(693, 'part_e_3_point_ir', 0.724400, -0.330600, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_a_4_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(694, 'part_ref_and_pose_kit_a4b3c2d1_a_4_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_2_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(111, 'part_a_2_ir', 'a2_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(695, 'part_a_2_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_c_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(696, 'x_axis_kit_a2b3c5_c_3_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_5_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(112, 'part_e_5_ir', 'e5_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(697, 'x_axis_kit_a2b3c5_b_3_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_3_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(698, 'part_d_3_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_a_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(699, 'part_ref_and_pose_kit_a2b3c5_a_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(700, 'part_c_8_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(700, 'part_c_8_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(700, 'part_c_8_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_1_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(113, 'part_b_1_ir', 'b1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(701, 'part_c_4_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_supply_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(702, 'part_d_supply_point_ir', 0.400000, 1.700000, 0.320000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_d_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(703, 'part_ref_and_pose_kit_a4b3c2d1_d_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_c_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(704, 'part_ref_and_pose_kit_a2b3c5_c_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(705, 'x_axis_kit_a2b1c1_b_1', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_3', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(114, 'kit_tray_3', 3, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_2', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(115, 'kit_tray_2', 2, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_1', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(116, 'kit_tray_1', 1, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(706, 'finished_kit_box_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_a_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(707, 'z_axis_kit_a4b3c3_a_4_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(708, 'z_axis_kit_a2b2c1_a_1', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(117, 'part_a_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_7_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(709, 'part_a_7_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(709, 'part_a_7_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(709, 'part_a_7_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(710, 'z_axis_kit_a4b4c2_c_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c2d1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(711, 'kit_a4b3c2d1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_1_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(712, 'part_d_1_point_ir', 0.165600, -0.343000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_6_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(713, 'part_a_6_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(713, 'part_a_6_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(713, 'part_a_6_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(714, 'part_b_4_point', 0.240000, -0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_boss_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(715, 'part_gear_boss_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_b_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(716, 'point_kit_a4b3c2d1_b_1_ir', 0.457100, -0.365000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(717, 'part_gear_shaft_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(717, 'part_gear_shaft_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(717, 'part_gear_shaft_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(718, 'part_gear_shaft_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(719, 'z_axis_kit_a4b4c2_b_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_b_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(720, 'stock_keeping_unit_part_b_ir', 'SKU for Part B_ir', 0.180000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(720, 103);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c2d1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(721, 'kit_a4b3c2d1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(721, 'kit_a4b3c2d1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(721, 'kit_a4b3c2d1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(722, 'part_b_5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(723, 'part_c_5_point', 0.110000, 0.216000, -0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(724, 'part_c_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_2_ir', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku)
VALUES(118, 'kit_tray_2_ir', 33, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_d_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(725, 'shape_parts_tray_d_ir', 'Shape of PartsTrays for parts of type D, used for Intention Recognition');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(725, 'shape_parts_tray_d_ir');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(725, 'shape_parts_tray_d_ir', 0.431900, false, 0.025400, 0.889500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_box_ir', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(119, 'finished_kit_box_ir', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(726, 'part_c_4_point_ir', 0.736600, -0.330200, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(727, 'z_axis_kit_a4b3c3_b_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(728, 'part_b_7_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_16_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(729, 'part_a_16_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_a_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(730, 'x_axis_kit_a4b4c2_a_3_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_b_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(731, 'point_kit_a4b3c2d1_b_3_ir', 0.457100, -0.114200, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_17_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(732, 'part_a_17_point_ir', 0.596500, -0.089000, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(733, 'z_axis_kit_a2b1c1_a_2', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(734, 'z_axis_kit_a2b1c1_a_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(735, 'part_gear_shaft_4_point', 0.6000, 2.20000, 0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(736, 'z_axis_kit_a2b3c3d1e1_c_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_13_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(120, 'part_a_13_ir', 'a13_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_4_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(737, 'part_d_4_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(738, 'finished_kit_receiver_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(739, 'part_b_supply_point', 0.050000, 1.500000, 0.280000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(740, 'kit_tray_3_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(741, 'finished_kit_receiver_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_b_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(742, 'point_kit_a2b2c1_b_2', 0.171000, 0.215000, -0.080000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_e_tray_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(743, 'stock_keeping_unit_parts_e_tray_ir', 'SKU for PartsTrays containing parts of type E, used for Intention Recognition', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(743, 103);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_8_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(744, 'part_d_8_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(744, 'part_d_8_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(744, 'part_d_8_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_b_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(745, 'point_kit_a2b2c1_b_1', 0.219000, -0.166000, -0.080000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(746, 'z_axis_kit_a4b3c3_c_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(747, 'z_axis_kit_a2b3c3d1e1_a_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_4_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(748, 'part_e_4_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(748, 'part_e_4_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(748, 'part_e_4_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_gear_boss');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(749, 'stock_keeping_unit_part_gear_boss', 'SKU for gear boss', 1.200000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(749, 103);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c3d1e1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(750, 'kit_a2b3c3d1e1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(750, 'kit_a2b3c3d1e1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(750, 'kit_a2b3c3d1e1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_8_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(751, 'part_a_8_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(751, 'part_a_8_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(751, 'part_a_8_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(752, 'part_b_8_point', 0.240000, 0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(753, 'part_a_tray_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_a_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(754, 'part_ref_and_pose_kit_a2b3c5_a_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_3_ir', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku)
VALUES(121, 'kit_tray_3_ir', 34, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_parts_tray_b_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(755, 'ext_shape_parts_tray_b_ir', 'Shape of PartsTray_B_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(755, 'ext_shape_parts_tray_b_ir', 'USARSim', 'PartTrayB', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_a_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(756, 'x_axis_kit_a4b3c3_a_3_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(757, 'part_b_8_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(758, 'part_c_7_point', -0.110000, 0.216000, -0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(759, 'z_axis_kit_a4b3c2d1_b_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(760, 'x_axis_kit_a2b3c3d1e1_b_2_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_d_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(761, 'x_axis_kit_a4b3c2d1_d_1_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_c_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(762, 'part_ref_and_pose_kit_a2b2c1_c_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper_holder', NULL);

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_ChangingStation)
VALUES(122, 'tray_gripper_holder', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(763, 'part_c_3_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(764, 'z_axis_kit_a2b3c5_b_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_c_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(765, 'point_kit_a2b3c5_c_2_ir', 0.584000, -0.330100, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_14_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(766, 'part_a_14_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(766, 'part_a_14_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(766, 'part_a_14_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(767, 'part_b_supply_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_16_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(768, 'part_a_16_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_supply_ir', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(123, 'part_a_supply_ir', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_a_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(769, 'part_ref_and_pose_kit_a2b2c1_a_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_gear');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(770, 'ext_shape_gear', 'Shape of the gear');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(770, 'ext_shape_gear', 'USARSim', 'gear', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_a_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(771, 'part_ref_and_pose_kit_a2b2c1_a_2', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(772, 'finished_kit_box_point_ir', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_a_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(773, 'point_kit_a2b3c3d1e1_a_1_ir', 0.291900, -0.089300, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_12_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(774, 'part_b_12_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(775, 'part_b_tray_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(775, 'part_b_tray_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(775, 'part_b_tray_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(776, 'empty_kit_tray_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(777, 'part_gear_shaft_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(777, 'part_gear_shaft_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(777, 'part_gear_shaft_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(778, 'part_a_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(779, 'part_c_3_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_5_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(780, 'kit_tray_5_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(780, 'kit_tray_5_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(780, 'kit_tray_5_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_gear_base');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(781, 'ext_shape_gear_base', 'Shape of the gear base');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(781, 'ext_shape_gear_base', 'USARSim', 'gear_base', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(782, 'part_b_2_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(783, 'part_b_5_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_c_5_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(784, 'point_kit_a2b3c5_c_5_ir', 0.584000, -0.126900, -0.065000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_a4b4c2', NULL);

INSERT INTO Kit
(KitID, _NAME, isKit_Finished, hasKit_Tray, hasKit_Design)
VALUES(124, 'kit_a4b4c2', false, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(785, 'part_a_4_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_a_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(786, 'part_ref_and_pose_kit_a4b4c2_a_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(787, 'z_axis_kit_a4b4c2_b_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(788, 'part_a_1_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_a_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(789, 'point_kit_a4b4c2_a_2_ir', 0.622700, -0.419400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_on_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(790, 'relative_location_on_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(790, 'relative_location_on_1', 'The tray_gripper is on robot_1');

INSERT INTO RelativeLocationOn
(RelativeLocationOnID, _NAME)
VALUES(790, 'relative_location_on_1');

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(791, 'kit_a2b3c5_point', 0.100000, 0.200000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(792, 'finished_kit_receiver_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b1c1');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(793, 'kit_design_a2b1c1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_a_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(794, 'part_ref_and_pose_kit_a4b3c2d1_a_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(795, 'empty_kit_tray_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(795, 'empty_kit_tray_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(795, 'empty_kit_tray_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(796, 'x_axis_kit_a4b4c2_b_3_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_c_4_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(797, 'point_kit_a2b3c5_c_4_ir', 0.380800, -0.126900, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(798, 'finished_kit_receiver_point', 1.500000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_2_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(125, 'part_b_2_ir', 'b2_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(799, 'part_b_6_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_b_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(800, 'x_axis_kit_a2b2c1_b_2', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(801, 'x_axis_kit_a2b2c1_b_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_c_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(802, 'part_ref_and_pose_kit_a4b3c2d1_c_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(803, 'empty_kit_tray_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(803, 'empty_kit_tray_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(803, 'empty_kit_tray_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_c_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(804, 'point_kit_a4b3c2d1_c_1_ir', 0.253900, -0.330100, -0.065000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('robot_1', NULL);

INSERT INTO Robot
(RobotID, _NAME, hasRobot_Description, hasRobot_MaximumLoadWeight)
VALUES(126, 'robot_1', 'this is the robot', 7.000000);

INSERT INTO hasRobot_WorkVolume
(RobotID, BoxVolumeID)
VALUES(126, 142);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(805, 'x_axis_kit_a4b3c3_c_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(806, 'part_c_5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(807, 'robot_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(127, 'part_a_1', 'a1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(808, 'x_axis_kit_a2b3c5_c_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(128, 'part_a_3', 'a3', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(129, 'part_a_2', 'a2', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(809, 'part_b_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_7_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(810, 'part_d_7_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(810, 'part_d_7_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(810, 'part_d_7_pose_ir');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(130, 'part_a_4', 'a4', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_supply_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(811, 'part_d_supply_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(811, 'part_d_supply_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(811, 'part_d_supply_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_c_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(812, 'point_kit_a4b4c2_c_2_ir', 0.330600, -0.381300, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_b_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(813, 'point_kit_a2b1c1_b_1', 0.200000, -0.500000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_7_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(814, 'part_d_7_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(815, 'part_gear_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(815, 'part_gear_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(815, 'part_gear_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(816, 'empty_kit_tray_box_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(816, 'empty_kit_tray_box_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(816, 'empty_kit_tray_box_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_b_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(817, 'point_kit_a2b3c5_b_1_ir', 0.126800, -0.368200, -0.065000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('changing_station_1', NULL);

INSERT INTO EndEffectorChangingStation
(EndEffectorChangingStationID, _NAME, hasChangingStation_Base)
VALUES(131, 'changing_station_1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_tray_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(818, 'part_e_tray_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray_3_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(819, 'shape_kit_tray_3_ir', 'Shape of KitTray 3');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(819, 'shape_kit_tray_3_ir', 'USARSim', 'KitTray3', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(820, 'part_gear_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(820, 'part_gear_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(820, 'part_gear_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(821, 'part_a_2_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(821, 'part_a_2_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(821, 'part_a_2_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('work_table_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(822, 'work_table_point', 3.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(823, 'part_c_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(823, 'part_c_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(823, 'part_c_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(824, 'z_axis_kit_a2b2c1_c_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_c_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(825, 'point_kit_a2b3c3d1e1_c_3_ir', 0.457000, -0.127400, -0.065000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(826, 'x_axis_kit_a4b3c3_c_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(827, 'x_axis_kit_a4b4c2_c_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_2_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(828, 'part_e_2_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_7_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(829, 'part_d_7_x_axis_ir', 0.000000, 0.000000, 1.000000);



UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_d_6_pose_ir' WHERE _NAME = 'part_d_6_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_d_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_d_ir' WHERE _NAME = 'part_d_6_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_tray_5_ir' WHERE _NAME = 'stock_keeping_unit_kit_tray_5_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_d_4_pose_ir' WHERE _NAME = 'part_d_4_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_d_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_d_ir' WHERE _NAME = 'part_d_4_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c2d1_a_3_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c2d1_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c2d1_a_3_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c2d1_a_3_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c2d1_a_3_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_3_point', hasPoseLocation_ZAxis= 'part_b_3_z_axis', hasPoseLocation_XAxis= 'part_b_3_x_axis' WHERE _NAME = 'part_b_3_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_a4b3c3_pose' WHERE _NAME = 'kit_a4b3c3';

UPDATE Kit
 SET  hasKit_Tray='kit_tray_1_ir', hasKit_Design= 'kit_design_a4b3c3_ir' WHERE _NAME = 'kit_a4b3c3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_d_tray_pose_ir' WHERE _NAME = 'part_d_tray_ir';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_d_tray_ir' WHERE _NAME = 'part_d_tray_ir';

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
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'kit_a2b3c5_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_a2b3c5_point', hasPoseLocation_ZAxis= 'kit_a2b3c5_z_axis', hasPoseLocation_XAxis= 'kit_a2b3c5_x_axis' WHERE _NAME = 'kit_a2b3c5_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_4_point', hasPoseLocation_ZAxis= 'part_c_4_z_axis', hasPoseLocation_XAxis= 'part_c_4_x_axis' WHERE _NAME = 'part_c_4_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_tray_pose_ir' WHERE _NAME = 'part_b_tray_ir';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_b_tray_ir' WHERE _NAME = 'part_b_tray_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_holder_pose' WHERE _NAME = 'part_gear_holder';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_gear_holder' WHERE _NAME = 'part_gear_holder';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_9_pose_ir' WHERE _NAME = 'part_b_9_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_b_ir' WHERE _NAME = 'part_b_9_ir';

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
 SET  hasSolidObject_PrimaryLocation='part_a_7_pose_ir' WHERE _NAME = 'part_a_7_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_7_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_7_pose' WHERE _NAME = 'part_c_7';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply', hasPart_Sku= 'stock_keeping_unit_part_c' WHERE _NAME = 'part_c_7';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_6_pose' WHERE _NAME = 'part_c_6';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply', hasPart_Sku= 'stock_keeping_unit_part_c' WHERE _NAME = 'part_c_6';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_supply_pose' WHERE _NAME = 'part_c_supply';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_c_tray' WHERE _NAME = 'part_c_supply';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c3_b_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c3_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c3_b_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c3_b_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c3_b_1_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_boss_pose' WHERE _NAME = 'part_gear_boss';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_gear_boss' WHERE _NAME = 'part_gear_boss';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_tray_pose' WHERE _NAME = 'part_a_tray';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_tray_a' WHERE _NAME = 'part_a_tray';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_d_supply_ir' WHERE _NAME = 'part_d_tray_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_d_tray_point_ir', hasPoseLocation_ZAxis= 'part_d_tray_z_axis_ir', hasPoseLocation_XAxis= 'part_d_tray_x_axis_ir' WHERE _NAME = 'part_d_tray_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply_ir' WHERE _NAME = 'part_b_1_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_1_point_ir', hasPoseLocation_ZAxis= 'part_b_1_z_axis_ir', hasPoseLocation_XAxis= 'part_b_1_x_axis_ir' WHERE _NAME = 'part_b_1_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c2d1_c_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c2d1_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c2d1_c_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c2d1_c_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c2d1_c_1_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_11_pose_ir' WHERE _NAME = 'part_a_11_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_11_ir';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='ext_shape_gear_holder' WHERE _NAME = 'stock_keeping_unit_part_gear_holder';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_10_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_10_point_ir', hasPoseLocation_ZAxis= 'part_a_10_z_axis_ir', hasPoseLocation_XAxis= 'part_a_10_x_axis_ir' WHERE _NAME = 'part_a_10_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply' WHERE _NAME = 'part_a_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_2_point', hasPoseLocation_ZAxis= 'part_a_2_z_axis', hasPoseLocation_XAxis= 'part_a_2_x_axis' WHERE _NAME = 'part_a_2_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c3_c_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c3_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c3_c_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c3_c_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c3_c_1_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b4c2_a_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b4c2_ir', hasPartRefAndPose_Point= 'point_kit_a4b4c2_a_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b4c2_a_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b4c2_a_1_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_d_supply_ir' WHERE _NAME = 'part_d_1_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_d_1_point_ir', hasPoseLocation_ZAxis= 'part_d_1_z_axis_ir', hasPoseLocation_XAxis= 'part_d_1_x_axis_ir' WHERE _NAME = 'part_d_1_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_6_pose_ir' WHERE _NAME = 'part_b_6_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_b_ir' WHERE _NAME = 'part_b_6_ir';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='shape_part_d_ir' WHERE _NAME = 'stock_keeping_unit_part_d_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_b_supply_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_supply_point_ir', hasPoseLocation_ZAxis= 'part_b_supply_z_axis_ir', hasPoseLocation_XAxis= 'part_b_supply_x_axis_ir' WHERE _NAME = 'part_b_supply_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_6_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_6_point', hasPoseLocation_ZAxis= 'part_b_6_z_axis', hasPoseLocation_XAxis= 'part_b_6_x_axis' WHERE _NAME = 'part_b_6_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_4_pose' WHERE _NAME = 'part_gear_4';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_gear' WHERE _NAME = 'part_gear_4';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_5_pose' WHERE _NAME = 'part_gear_5';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_gear' WHERE _NAME = 'part_gear_5';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_2_pose' WHERE _NAME = 'part_gear_2';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_gear' WHERE _NAME = 'part_gear_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_3_pose' WHERE _NAME = 'part_gear_3';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_gear' WHERE _NAME = 'part_gear_3';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply_ir' WHERE _NAME = 'part_b_9_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_9_point_ir', hasPoseLocation_ZAxis= 'part_b_9_z_axis_ir', hasPoseLocation_XAxis= 'part_b_9_x_axis_ir' WHERE _NAME = 'part_b_9_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_e_2_pose_ir' WHERE _NAME = 'part_e_2_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_e_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_e_ir' WHERE _NAME = 'part_e_2_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_2_pose_ir' WHERE _NAME = 'part_c_2_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_c_ir' WHERE _NAME = 'part_c_2_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_base_pose' WHERE _NAME = 'part_gear_base';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_gear_base' WHERE _NAME = 'part_gear_base';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_1_pose' WHERE _NAME = 'part_gear_1';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_gear' WHERE _NAME = 'part_gear_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_1_point', hasPoseLocation_ZAxis= 'part_b_1_z_axis', hasPoseLocation_XAxis= 'part_b_1_x_axis' WHERE _NAME = 'part_b_1_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply_ir' WHERE _NAME = 'part_b_2_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_2_point_ir', hasPoseLocation_ZAxis= 'part_b_2_z_axis_ir', hasPoseLocation_XAxis= 'part_b_2_x_axis_ir' WHERE _NAME = 'part_b_2_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_9_pose_ir' WHERE _NAME = 'part_a_9_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_9_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_8_pose_ir' WHERE _NAME = 'part_b_8_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_b_ir' WHERE _NAME = 'part_b_8_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_tray_1_ir' WHERE _NAME = 'stock_keeping_unit_kit_tray_1_ir';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='shape_part_c_ir' WHERE _NAME = 'stock_keeping_unit_part_c_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_5_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_5_point', hasPoseLocation_ZAxis= 'part_c_5_z_axis', hasPoseLocation_XAxis= 'part_c_5_x_axis' WHERE _NAME = 'part_c_5_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_3_point', hasPoseLocation_ZAxis= 'kit_tray_3_z_axis', hasPoseLocation_XAxis= 'kit_tray_3_x_axis' WHERE _NAME = 'kit_tray_3_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_d_2_pose_ir' WHERE _NAME = 'part_d_2_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_d_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_d_ir' WHERE _NAME = 'part_d_2_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply_ir' WHERE _NAME = 'part_c_4_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_4_point_ir', hasPoseLocation_ZAxis= 'part_c_4_z_axis_ir', hasPoseLocation_XAxis= 'part_c_4_x_axis_ir' WHERE _NAME = 'part_c_4_pose_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'ext_shape_parts_tray_d_ir' WHERE _NAME = 'stock_keeping_unit_parts_d_tray_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_e_supply_pose_ir' WHERE _NAME = 'part_e_supply_ir';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_e_tray_ir' WHERE _NAME = 'part_e_supply_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_4_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_4_point_ir', hasPoseLocation_ZAxis= 'part_a_4_z_axis_ir', hasPoseLocation_XAxis= 'part_a_4_x_axis_ir' WHERE _NAME = 'part_a_4_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b4c2_b_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b4c2_ir', hasPartRefAndPose_Point= 'point_kit_a4b4c2_b_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b4c2_b_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b4c2_b_2_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_4_pose_ir' WHERE _NAME = 'part_b_4_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_b_ir' WHERE _NAME = 'part_b_4_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_tray_3_ir' WHERE _NAME = 'stock_keeping_unit_kit_tray_3_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_tray_point', hasPoseLocation_ZAxis= 'part_c_tray_z_axis', hasPoseLocation_XAxis= 'part_c_tray_x_axis' WHERE _NAME = 'part_c_tray_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_d_8_pose_ir' WHERE _NAME = 'part_d_8_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_d_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_d_ir' WHERE _NAME = 'part_d_8_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_shaft_1_pose' WHERE _NAME = 'part_gear_shaft_1';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_gear_shaft' WHERE _NAME = 'part_gear_shaft_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_shaft_2_pose' WHERE _NAME = 'part_gear_shaft_2';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_gear_shaft' WHERE _NAME = 'part_gear_shaft_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_shaft_3_pose' WHERE _NAME = 'part_gear_shaft_3';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_gear_shaft' WHERE _NAME = 'part_gear_shaft_3';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply_ir' WHERE _NAME = 'part_c_8_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_8_point_ir', hasPoseLocation_ZAxis= 'part_c_8_z_axis_ir', hasPoseLocation_XAxis= 'part_c_8_x_axis_ir' WHERE _NAME = 'part_c_8_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_shaft_4_pose' WHERE _NAME = 'part_gear_shaft_4';

UPDATE Part
 SET  hasPart_Sku='stock_keeping_unit_part_gear_shaft' WHERE _NAME = 'part_gear_shaft_4';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply_ir' WHERE _NAME = 'part_c_6_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_6_point_ir', hasPoseLocation_ZAxis= 'part_c_6_z_axis_ir', hasPoseLocation_XAxis= 'part_c_6_x_axis_ir' WHERE _NAME = 'part_c_6_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_4_pose_ir' WHERE _NAME = 'part_a_4_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_4_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_4_pose_ir' WHERE _NAME = 'kit_tray_4_ir';

UPDATE KitTray
 SET  hasKitTray_Sku='stock_keeping_unit_kit_tray_4_ir' WHERE _NAME = 'kit_tray_4_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply_ir' WHERE _NAME = 'part_c_7_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_7_point_ir', hasPoseLocation_ZAxis= 'part_c_7_z_axis_ir', hasPoseLocation_XAxis= 'part_c_7_x_axis_ir' WHERE _NAME = 'part_c_7_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_tray_pose_ir' WHERE _NAME = 'part_a_tray_ir';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_a_tray_ir' WHERE _NAME = 'part_a_tray_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_10_pose_ir' WHERE _NAME = 'part_a_10_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_10_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_10_pose_ir' WHERE _NAME = 'part_b_10_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_b_ir' WHERE _NAME = 'part_b_10_ir';

UPDATE KitDesign
 SET  hadByKitDesign_Workstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'stock_keeping_unit_kit_tray_1_ir' WHERE _NAME = 'kit_design_a4b3c3_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_c_supply_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_supply_point_ir', hasPoseLocation_ZAxis= 'part_c_supply_z_axis_ir', hasPoseLocation_XAxis= 'part_c_supply_x_axis_ir' WHERE _NAME = 'part_c_supply_pose_ir';

UPDATE BoxVolume
 SET  hasBoxVolume_MaximumPoint='point_max', hasBoxVolume_MinimumPoint= 'point_min' WHERE _NAME = 'box_volume_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply' WHERE _NAME = 'part_a_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_4_point', hasPoseLocation_ZAxis= 'part_a_4_z_axis', hasPoseLocation_XAxis= 'part_a_4_x_axis' WHERE _NAME = 'part_a_4_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_1_pose_ir' WHERE _NAME = 'part_a_1_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_1_ir';

UPDATE KitDesign
 SET  hadByKitDesign_Workstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'stock_keeping_unit_kit_tray_2_ir' WHERE _NAME = 'kit_design_a4b4c2_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gear_holder_point', hasPoseLocation_ZAxis= 'part_gear_holder_z_axis', hasPoseLocation_XAxis= 'part_gear_holder_x_axis' WHERE _NAME = 'part_gear_holder_pose';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='ext_shape_gear' WHERE _NAME = 'stock_keeping_unit_part_gear';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c2d1_b_3_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c2d1_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c2d1_b_3_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c2d1_b_3_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c2d1_b_3_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b4c2_b_4_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b4c2_ir', hasPartRefAndPose_Point= 'point_kit_a4b4c2_b_4_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b4c2_b_4_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b4c2_b_4_ir';

UPDATE KitDesign
 SET  hadByKitDesign_Workstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_design_a2b2c1';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c3_a_3_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c3_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c3_a_3_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c3_a_3_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c3_a_3_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c3d1e1_c_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c3d1e1_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c3d1e1_c_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c3d1e1_c_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c3d1e1_c_1_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply_ir' WHERE _NAME = 'kit_tray_3_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_3_point_ir', hasPoseLocation_ZAxis= 'kit_tray_3_z_axis_ir', hasPoseLocation_XAxis= 'kit_tray_3_x_axis_ir' WHERE _NAME = 'kit_tray_3_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply_ir' WHERE _NAME = 'part_b_8_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_8_point_ir', hasPoseLocation_ZAxis= 'part_b_8_z_axis_ir', hasPoseLocation_XAxis= 'part_b_8_x_axis_ir' WHERE _NAME = 'part_b_8_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_4_pose_ir' WHERE _NAME = 'part_c_4_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_c_ir' WHERE _NAME = 'part_c_4_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c5_c_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c5_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c5_c_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c5_c_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c5_c_1_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_11_pose_ir' WHERE _NAME = 'part_b_11_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_b_ir' WHERE _NAME = 'part_b_11_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_e_3_pose_ir' WHERE _NAME = 'part_e_3_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_e_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_e_ir' WHERE _NAME = 'part_e_3_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_e_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c3d1e1_e_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c3d1e1_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c3d1e1_e_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c3d1e1_e_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c3d1e1_e_1_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply_ir' WHERE _NAME = 'part_c_2_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_2_point_ir', hasPoseLocation_ZAxis= 'part_c_2_z_axis_ir', hasPoseLocation_XAxis= 'part_c_2_x_axis_ir' WHERE _NAME = 'part_c_2_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c3d1e1_b_3_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c3d1e1_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c3d1e1_b_3_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c3d1e1_b_3_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c3d1e1_b_3_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_e_supply_ir' WHERE _NAME = 'part_e_3_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_e_3_point_ir', hasPoseLocation_ZAxis= 'part_e_3_z_axis_ir', hasPoseLocation_XAxis= 'part_e_3_x_axis_ir' WHERE _NAME = 'part_e_3_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_5_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_5_point_ir', hasPoseLocation_ZAxis= 'part_a_5_z_axis_ir', hasPoseLocation_XAxis= 'part_a_5_x_axis_ir' WHERE _NAME = 'part_a_5_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_d_3_pose_ir' WHERE _NAME = 'part_d_3_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_d_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_d_ir' WHERE _NAME = 'part_d_3_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_tray_pose' WHERE _NAME = 'part_b_tray';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_tray_b' WHERE _NAME = 'part_b_tray';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'finished_kit_receiver_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='finished_kit_receiver_point_ir', hasPoseLocation_ZAxis= 'finished_kit_receiver_z_axis_ir', hasPoseLocation_XAxis= 'finished_kit_receiver_x_axis_ir' WHERE _NAME = 'finished_kit_receiver_pose_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_part_a' WHERE _NAME = 'stock_keeping_unit_part_a';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_3_pose_ir' WHERE _NAME = 'part_a_3_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_3_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_18_pose_ir' WHERE _NAME = 'part_a_18_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_18_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'ext_shape_parts_tray_b_ir' WHERE _NAME = 'stock_keeping_unit_parts_b_tray_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_16_pose_ir' WHERE _NAME = 'part_a_16_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_16_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_d_7_pose_ir' WHERE _NAME = 'part_d_7_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_d_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_d_ir' WHERE _NAME = 'part_d_7_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_7_pose_ir' WHERE _NAME = 'part_c_7_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_c_ir' WHERE _NAME = 'part_c_7_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_15_pose_ir' WHERE _NAME = 'part_a_15_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_15_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_6_pose_ir' WHERE _NAME = 'part_a_6_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_6_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_b_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_supply_point', hasPoseLocation_ZAxis= 'part_b_supply_z_axis', hasPoseLocation_XAxis= 'part_b_supply_x_axis' WHERE _NAME = 'part_b_supply_pose';

UPDATE KitDesign
 SET  hadByKitDesign_Workstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'stock_keeping_unit_kit_tray_5_ir' WHERE _NAME = 'kit_design_a2b3c3d1e1_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_tray' WHERE _NAME = 'stock_keeping_unit_kit_tray';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply_ir' WHERE _NAME = 'part_b_4_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_4_point_ir', hasPoseLocation_ZAxis= 'part_b_4_z_axis_ir', hasPoseLocation_XAxis= 'part_b_4_x_axis_ir' WHERE _NAME = 'part_b_4_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_tray_pose_ir' WHERE _NAME = 'part_c_tray_ir';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_c_tray_ir' WHERE _NAME = 'part_c_tray_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_16_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_16_point_ir', hasPoseLocation_ZAxis= 'part_a_16_z_axis_ir', hasPoseLocation_XAxis= 'part_a_16_x_axis_ir' WHERE _NAME = 'part_a_16_pose_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_part_c' WHERE _NAME = 'stock_keeping_unit_part_c';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_part_b' WHERE _NAME = 'stock_keeping_unit_part_b';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b4c2_a_3_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b4c2_ir', hasPartRefAndPose_Point= 'point_kit_a4b4c2_a_3_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b4c2_a_3_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b4c2_a_3_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_5_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gear_5_point', hasPoseLocation_ZAxis= 'part_gear_5_z_axis', hasPoseLocation_XAxis= 'part_gear_5_x_axis' WHERE _NAME = 'part_gear_5_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_15_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_15_point_ir', hasPoseLocation_ZAxis= 'part_a_15_z_axis_ir', hasPoseLocation_XAxis= 'part_a_15_x_axis_ir' WHERE _NAME = 'part_a_15_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply_ir' WHERE _NAME = 'part_b_10_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_10_point_ir', hasPoseLocation_ZAxis= 'part_b_10_z_axis_ir', hasPoseLocation_XAxis= 'part_b_10_x_axis_ir' WHERE _NAME = 'part_b_10_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_a_2', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_a_2', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_a_2' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_a_2';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_a_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_a_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_a_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_a_1';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_box_ir' WHERE _NAME = 'stock_keeping_unit_kit_box_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_13_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_13_point_ir', hasPoseLocation_ZAxis= 'part_a_13_z_axis_ir', hasPoseLocation_XAxis= 'part_a_13_x_axis_ir' WHERE _NAME = 'part_a_13_pose_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'ext_shape_parts_tray_a_ir' WHERE _NAME = 'stock_keeping_unit_parts_a_tray_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_e_4_pose_ir' WHERE _NAME = 'part_e_4_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_e_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_e_ir' WHERE _NAME = 'part_e_4_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c2d1_b_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c2d1_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c2d1_b_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c2d1_b_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c2d1_b_2_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c3_c_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c3_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c3_c_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c3_c_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c3_c_2_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_7_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_7_point', hasPoseLocation_ZAxis= 'part_c_7_z_axis', hasPoseLocation_XAxis= 'part_c_7_x_axis' WHERE _NAME = 'part_c_7_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_tray_pose' WHERE _NAME = 'part_c_tray';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_tray_c' WHERE _NAME = 'part_c_tray';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c3_a_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c3_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c3_a_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c3_a_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c3_a_1_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_7_pose_ir' WHERE _NAME = 'part_b_7_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_b_ir' WHERE _NAME = 'part_b_7_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_receiver_pose_ir' WHERE _NAME = 'finished_kit_receiver_ir';

UPDATE LargeBoxWithKits
 SET  hasLargeBoxWithKits_LargeContainer='finished_kit_box_ir', hasLargeBoxWithKits_KitDesign= 'kit_design_a4b3c3_ir' WHERE _NAME = 'finished_kit_receiver_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_e_supply_ir' WHERE _NAME = 'part_e_2_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_e_2_point_ir', hasPoseLocation_ZAxis= 'part_e_2_z_axis_ir', hasPoseLocation_XAxis= 'part_e_2_x_axis_ir' WHERE _NAME = 'part_e_2_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_box_pose' WHERE _NAME = 'empty_kit_tray_box';

UPDATE LargeContainer
 SET  hasLargeContainer_Sku='stock_keeping_unit_kit_box' WHERE _NAME = 'empty_kit_tray_box';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_boss_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gear_boss_point', hasPoseLocation_ZAxis= 'part_gear_boss_z_axis', hasPoseLocation_XAxis= 'part_gear_boss_x_axis' WHERE _NAME = 'part_gear_boss_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_1_point', hasPoseLocation_ZAxis= 'kit_tray_1_z_axis', hasPoseLocation_XAxis= 'kit_tray_1_x_axis' WHERE _NAME = 'kit_tray_1_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_12_pose_ir' WHERE _NAME = 'part_a_12_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_12_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'relative_location_in_1';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b4c2_c_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b4c2_ir', hasPartRefAndPose_Point= 'point_kit_a4b4c2_c_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b4c2_c_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b4c2_c_2_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_shaft_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gear_shaft_3_point', hasPoseLocation_ZAxis= 'part_gear_shaft_3_z_axis', hasPoseLocation_XAxis= 'part_gear_shaft_3_x_axis' WHERE _NAME = 'part_gear_shaft_3_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply_ir' WHERE _NAME = 'kit_tray_4_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_4_point_ir', hasPoseLocation_ZAxis= 'kit_tray_4_z_axis_ir', hasPoseLocation_XAxis= 'kit_tray_4_x_axis_ir' WHERE _NAME = 'kit_tray_4_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_supply_pose_ir' WHERE _NAME = 'part_b_supply_ir';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_b_tray_ir' WHERE _NAME = 'part_b_supply_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_17_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_17_point_ir', hasPoseLocation_ZAxis= 'part_a_17_z_axis_ir', hasPoseLocation_XAxis= 'part_a_17_x_axis_ir' WHERE _NAME = 'part_a_17_pose_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_tray_2_ir' WHERE _NAME = 'stock_keeping_unit_kit_tray_2_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_6_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_6_point', hasPoseLocation_ZAxis= 'part_c_6_z_axis', hasPoseLocation_XAxis= 'part_c_6_x_axis' WHERE _NAME = 'part_c_6_pose';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'ext_shape_parts_tray_c_ir' WHERE _NAME = 'stock_keeping_unit_parts_c_tray_ir';

UPDATE KitDesign
 SET  hadByKitDesign_Workstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'stock_keeping_unit_kit_tray_3_ir' WHERE _NAME = 'kit_design_a2b3c5_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_d_1_pose_ir' WHERE _NAME = 'part_d_1_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_d_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_d_ir' WHERE _NAME = 'part_d_1_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_3_point', hasPoseLocation_ZAxis= 'part_c_3_z_axis', hasPoseLocation_XAxis= 'part_c_3_x_axis' WHERE _NAME = 'part_c_3_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'changing_station_base_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='changing_station_base_point', hasPoseLocation_ZAxis= 'changing_station_base_z_axis', hasPoseLocation_XAxis= 'changing_station_base_x_axis' WHERE _NAME = 'changing_station_base_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_3_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_3_point_ir', hasPoseLocation_ZAxis= 'part_a_3_z_axis_ir', hasPoseLocation_XAxis= 'part_a_3_x_axis_ir' WHERE _NAME = 'part_a_3_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_5_pose_ir' WHERE _NAME = 'kit_tray_5_ir';

UPDATE KitTray
 SET  hasKitTray_Sku='stock_keeping_unit_kit_tray_5_ir' WHERE _NAME = 'kit_tray_5_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply' WHERE _NAME = 'part_a_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_3_point', hasPoseLocation_ZAxis= 'part_a_3_z_axis', hasPoseLocation_XAxis= 'part_a_3_x_axis' WHERE _NAME = 'part_a_3_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_a2b3c3d1e1_pose' WHERE _NAME = 'kit_a2b3c3d1e1';

UPDATE Kit
 SET  hasKit_Tray='kit_tray_5_ir', hasKit_Design= 'kit_design_a2b3c3d1e1_ir' WHERE _NAME = 'kit_a2b3c3d1e1';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b4c2_b_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b4c2_ir', hasPartRefAndPose_Point= 'point_kit_a4b4c2_b_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b4c2_b_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b4c2_b_1_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_d_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c3d1e1_d_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c3d1e1_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c3d1e1_d_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c3d1e1_d_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c3d1e1_d_1_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c5_b_3_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c5_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c5_b_3_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c5_b_3_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c5_b_3_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_supply_pose_ir' WHERE _NAME = 'empty_kit_tray_supply_ir';

UPDATE LargeBoxWithEmptyKitTrays
 SET  hasLargeBoxWithEmptyKitTrays_LargeContainer='empty_kit_tray_box_ir' WHERE _NAME = 'empty_kit_tray_supply_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'changing_station_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='changing_station_point', hasPoseLocation_ZAxis= 'changing_station_z_axis', hasPoseLocation_XAxis= 'changing_station_x_axis' WHERE _NAME = 'changing_station_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_e_supply_ir' WHERE _NAME = 'part_e_5_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_e_5_point_ir', hasPoseLocation_ZAxis= 'part_e_5_z_axis_ir', hasPoseLocation_XAxis= 'part_e_5_x_axis_ir' WHERE _NAME = 'part_e_5_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_e_supply_ir' WHERE _NAME = 'part_e_tray_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_e_tray_point_ir', hasPoseLocation_ZAxis= 'part_e_tray_z_axis_ir', hasPoseLocation_XAxis= 'part_e_tray_x_axis_ir' WHERE _NAME = 'part_e_tray_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_base_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gear_base_point', hasPoseLocation_ZAxis= 'part_gear_base_z_axis', hasPoseLocation_XAxis= 'part_gear_base_x_axis' WHERE _NAME = 'part_gear_base_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_d_supply_ir' WHERE _NAME = 'part_d_4_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_d_4_point_ir', hasPoseLocation_ZAxis= 'part_d_4_z_axis_ir', hasPoseLocation_XAxis= 'part_d_4_x_axis_ir' WHERE _NAME = 'part_d_4_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_1_pose_ir' WHERE _NAME = 'kit_tray_1_ir';

UPDATE KitTray
 SET  hasKitTray_Sku='stock_keeping_unit_kit_tray_1_ir' WHERE _NAME = 'kit_tray_1_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply_ir' WHERE _NAME = 'part_b_12_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_12_point_ir', hasPoseLocation_ZAxis= 'part_b_12_z_axis_ir', hasPoseLocation_XAxis= 'part_b_12_x_axis_ir' WHERE _NAME = 'part_b_12_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c3_a_4_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c3_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c3_a_4_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c3_a_4_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c3_a_4_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_e_supply_ir' WHERE _NAME = 'part_e_1_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_e_1_point_ir', hasPoseLocation_ZAxis= 'part_e_1_z_axis_ir', hasPoseLocation_XAxis= 'part_e_1_x_axis_ir' WHERE _NAME = 'part_e_1_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c3d1e1_c_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c3d1e1_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c3d1e1_c_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c3d1e1_c_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c3d1e1_c_2_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c5_c_5_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c5_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c5_c_5_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c5_c_5_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c5_c_5_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_b', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_b_2', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_b_2', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_b_2' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_b_2';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_b', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_b_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_b_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_b_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_b_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply_ir' WHERE _NAME = 'kit_tray_1_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_1_point_ir', hasPoseLocation_ZAxis= 'kit_tray_1_z_axis_ir', hasPoseLocation_XAxis= 'kit_tray_1_x_axis_ir' WHERE _NAME = 'kit_tray_1_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_2_point', hasPoseLocation_ZAxis= 'part_b_2_z_axis', hasPoseLocation_XAxis= 'part_b_2_x_axis' WHERE _NAME = 'part_b_2_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_8_pose_ir' WHERE _NAME = 'part_a_8_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_8_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gripper_holder_pose' WHERE _NAME = 'part_gripper_holder';

UPDATE EndEffectorHolder
 SET  hadByEndEffectorHolder_ChangingStation='changing_station_1', hasEndEffectorHolder_EndEffector= 'part_gripper' WHERE _NAME = 'part_gripper_holder';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_d_supply_ir' WHERE _NAME = 'part_d_2_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_d_2_point_ir', hasPoseLocation_ZAxis= 'part_d_2_z_axis_ir', hasPoseLocation_XAxis= 'part_d_2_x_axis_ir' WHERE _NAME = 'part_d_2_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_supply_pose_ir' WHERE _NAME = 'part_c_supply_ir';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_c_tray_ir' WHERE _NAME = 'part_c_supply_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_gripper_holder' WHERE _NAME = 'part_gripper_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gripper_point', hasPoseLocation_ZAxis= 'part_gripper_z_axis', hasPoseLocation_XAxis= 'part_gripper_x_axis' WHERE _NAME = 'part_gripper_pose';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='ext_shape_gear_base' WHERE _NAME = 'stock_keeping_unit_part_gear_base';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'empty_kit_tray_supply_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='empty_kit_tray_supply_point_ir', hasPoseLocation_ZAxis= 'empty_kit_tray_supply_z_axis_ir', hasPoseLocation_XAxis= 'empty_kit_tray_supply_x_axis_ir' WHERE _NAME = 'empty_kit_tray_supply_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply_ir' WHERE _NAME = 'part_c_3_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_3_point_ir', hasPoseLocation_ZAxis= 'part_c_3_z_axis_ir', hasPoseLocation_XAxis= 'part_c_3_x_axis_ir' WHERE _NAME = 'part_c_3_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_6_pose_ir' WHERE _NAME = 'part_c_6_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_c_ir' WHERE _NAME = 'part_c_6_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_8_pose_ir' WHERE _NAME = 'part_c_8_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_c_ir' WHERE _NAME = 'part_c_8_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_17_pose_ir' WHERE _NAME = 'part_a_17_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_17_ir';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='shape_part_e_ir' WHERE _NAME = 'stock_keeping_unit_part_e_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply_ir' WHERE _NAME = 'part_b_6_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_6_point_ir', hasPoseLocation_ZAxis= 'part_b_6_z_axis_ir', hasPoseLocation_XAxis= 'part_b_6_x_axis_ir' WHERE _NAME = 'part_b_6_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_a4b3c2d1_pose' WHERE _NAME = 'kit_a4b3c2d1';

UPDATE Kit
 SET  hasKit_Tray='kit_tray_4_ir', hasKit_Design= 'kit_design_a4b3c2d1_ir' WHERE _NAME = 'kit_a4b3c2d1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_3_pose_ir' WHERE _NAME = 'part_b_3_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_b_ir' WHERE _NAME = 'part_b_3_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply_ir' WHERE _NAME = 'part_b_11_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_11_point_ir', hasPoseLocation_ZAxis= 'part_b_11_z_axis_ir', hasPoseLocation_XAxis= 'part_b_11_x_axis_ir' WHERE _NAME = 'part_b_11_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_7_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_7_point', hasPoseLocation_ZAxis= 'part_b_7_z_axis', hasPoseLocation_XAxis= 'part_b_7_x_axis' WHERE _NAME = 'part_b_7_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='relative_location_on_1' WHERE _NAME = 'tray_gripper';

UPDATE EndEffector
 SET  hadByEndEffector_Robot='robot_1' WHERE _NAME = 'tray_gripper';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b4c2_c_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b4c2_ir', hasPartRefAndPose_Point= 'point_kit_a4b4c2_c_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b4c2_c_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b4c2_c_1_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_tray_point', hasPoseLocation_ZAxis= 'part_b_tray_z_axis', hasPoseLocation_XAxis= 'part_b_tray_x_axis' WHERE _NAME = 'part_b_tray_pose';

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

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_8_pose' WHERE _NAME = 'part_b_8';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply', hasPart_Sku= 'stock_keeping_unit_part_b' WHERE _NAME = 'part_b_8';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c3_a_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c3_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c3_a_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c3_a_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c3_a_2_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_d_5_pose_ir' WHERE _NAME = 'part_d_5_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_d_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_d_ir' WHERE _NAME = 'part_d_5_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply_ir' WHERE _NAME = 'part_c_tray_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_tray_point_ir', hasPoseLocation_ZAxis= 'part_c_tray_z_axis_ir', hasPoseLocation_XAxis= 'part_c_tray_x_axis_ir' WHERE _NAME = 'part_c_tray_pose_ir';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='ext_shape_gear_shaft' WHERE _NAME = 'stock_keeping_unit_part_gear_shaft';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'kit_a4b4c2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_a4b4c2_point', hasPoseLocation_ZAxis= 'kit_a4b4c2_z_axis', hasPoseLocation_XAxis= 'kit_a4b4c2_x_axis' WHERE _NAME = 'kit_a4b4c2_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c3d1e1_b_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c3d1e1_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c3d1e1_b_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c3d1e1_b_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c3d1e1_b_1_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_box_pose' WHERE _NAME = 'finished_kit_box';

UPDATE LargeContainer
 SET  hasLargeContainer_Sku='stock_keeping_unit_kit_box' WHERE _NAME = 'finished_kit_box';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_e_6_pose_ir' WHERE _NAME = 'part_e_6_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_e_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_e_ir' WHERE _NAME = 'part_e_6_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_11_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_11_point_ir', hasPoseLocation_ZAxis= 'part_a_11_z_axis_ir', hasPoseLocation_XAxis= 'part_a_11_x_axis_ir' WHERE _NAME = 'part_a_11_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_d_supply_ir' WHERE _NAME = 'part_d_9_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_d_9_point_ir', hasPoseLocation_ZAxis= 'part_d_9_z_axis_ir', hasPoseLocation_XAxis= 'part_d_9_x_axis_ir' WHERE _NAME = 'part_d_9_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c5_b_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c5_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c5_b_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c5_b_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c5_b_2_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply_ir' WHERE _NAME = 'part_c_5_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_5_point_ir', hasPoseLocation_ZAxis= 'part_c_5_z_axis_ir', hasPoseLocation_XAxis= 'part_c_5_x_axis_ir' WHERE _NAME = 'part_c_5_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply_ir' WHERE _NAME = 'part_b_7_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_7_point_ir', hasPoseLocation_ZAxis= 'part_b_7_z_axis_ir', hasPoseLocation_XAxis= 'part_b_7_x_axis_ir' WHERE _NAME = 'part_b_7_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_1_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_1_point_ir', hasPoseLocation_ZAxis= 'part_a_1_z_axis_ir', hasPoseLocation_XAxis= 'part_a_1_x_axis_ir' WHERE _NAME = 'part_a_1_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_shaft_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gear_shaft_4_point', hasPoseLocation_ZAxis= 'part_gear_shaft_4_z_axis', hasPoseLocation_XAxis= 'part_gear_shaft_4_x_axis' WHERE _NAME = 'part_gear_shaft_4_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_receiver_pose' WHERE _NAME = 'finished_kit_receiver';

UPDATE LargeBoxWithKits
 SET  hasLargeBoxWithKits_LargeContainer='finished_kit_box', hasLargeBoxWithKits_KitDesign= 'kit_design_a2b1c1' WHERE _NAME = 'finished_kit_receiver';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_supply_pose' WHERE _NAME = 'part_b_supply';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_b_tray' WHERE _NAME = 'part_b_supply';

UPDATE SolidObject
 SET  hasSolidObject_InternalShape='shape_work_table', hasSolidObject_PrimaryLocation= 'work_table_pose' WHERE _NAME = 'work_table_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply_ir' WHERE _NAME = 'part_b_3_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_3_point_ir', hasPoseLocation_ZAxis= 'part_b_3_z_axis_ir', hasPoseLocation_XAxis= 'part_b_3_x_axis_ir' WHERE _NAME = 'part_b_3_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c5_b_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c5_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c5_b_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c5_b_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c5_b_1_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_3_pose_ir' WHERE _NAME = 'part_c_3_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_c_ir' WHERE _NAME = 'part_c_3_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply_ir' WHERE _NAME = 'part_b_5_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_5_point_ir', hasPoseLocation_ZAxis= 'part_b_5_z_axis_ir', hasPoseLocation_XAxis= 'part_b_5_x_axis_ir' WHERE _NAME = 'part_b_5_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c5_c_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c5_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c5_c_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c5_c_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c5_c_2_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c3_c_3_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c3_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c3_c_3_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c3_c_3_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c3_c_3_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_2_point', hasPoseLocation_ZAxis= 'part_c_2_z_axis', hasPoseLocation_XAxis= 'part_c_2_x_axis' WHERE _NAME = 'part_c_2_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_9_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_9_point_ir', hasPoseLocation_ZAxis= 'part_a_9_z_axis_ir', hasPoseLocation_XAxis= 'part_a_9_x_axis_ir' WHERE _NAME = 'part_a_9_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_c', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_c_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_c_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_c_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_c_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_a2b3c5_pose' WHERE _NAME = 'kit_a2b3c5';

UPDATE Kit
 SET  hasKit_Tray='kit_tray_3_ir', hasKit_Design= 'kit_design_a2b3c5_ir' WHERE _NAME = 'kit_a2b3c5';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_e_1_pose_ir' WHERE _NAME = 'part_e_1_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_e_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_e_ir' WHERE _NAME = 'part_e_1_ir';

UPDATE KitDesign
 SET  hadByKitDesign_Workstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'stock_keeping_unit_kit_tray_4_ir' WHERE _NAME = 'kit_design_a4b3c2d1_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c3_b_3_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c3_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c3_b_3_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c3_b_3_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c3_b_3_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_d_9_pose_ir' WHERE _NAME = 'part_d_9_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_d_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_d_ir' WHERE _NAME = 'part_d_9_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='finished_kit_receiver' WHERE _NAME = 'finished_kit_box_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='finished_kit_box_point', hasPoseLocation_ZAxis= 'finished_kit_box_z_axis', hasPoseLocation_XAxis= 'finished_kit_box_x_axis' WHERE _NAME = 'finished_kit_box_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_5_pose_ir' WHERE _NAME = 'part_a_5_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_5_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='finished_kit_receiver_ir' WHERE _NAME = 'finished_kit_box_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='finished_kit_box_point_ir', hasPoseLocation_ZAxis= 'finished_kit_box_z_axis_ir', hasPoseLocation_XAxis= 'finished_kit_box_x_axis_ir' WHERE _NAME = 'finished_kit_box_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_c_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_supply_point', hasPoseLocation_ZAxis= 'part_c_supply_z_axis', hasPoseLocation_XAxis= 'part_c_supply_x_axis' WHERE _NAME = 'part_c_supply_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c3_b_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c3_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c3_b_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c3_b_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c3_b_2_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_d_supply_ir' WHERE _NAME = 'part_d_5_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_d_5_point_ir', hasPoseLocation_ZAxis= 'part_d_5_z_axis_ir', hasPoseLocation_XAxis= 'part_d_5_x_axis_ir' WHERE _NAME = 'part_d_5_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_d_supply_ir' WHERE _NAME = 'part_d_3_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_d_3_point_ir', hasPoseLocation_ZAxis= 'part_d_3_z_axis_ir', hasPoseLocation_XAxis= 'part_d_3_x_axis_ir' WHERE _NAME = 'part_d_3_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c3d1e1_b_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c3d1e1_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c3d1e1_b_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c3d1e1_b_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c3d1e1_b_2_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_a_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_supply_point', hasPoseLocation_ZAxis= 'part_a_supply_z_axis', hasPoseLocation_XAxis= 'part_a_supply_x_axis' WHERE _NAME = 'part_a_supply_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_12_pose_ir' WHERE _NAME = 'part_b_12_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_b_ir' WHERE _NAME = 'part_b_12_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c2d1_a_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c2d1_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c2d1_a_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c2d1_a_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c2d1_a_2_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_12_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_12_point_ir', hasPoseLocation_ZAxis= 'part_a_12_z_axis_ir', hasPoseLocation_XAxis= 'part_a_12_x_axis_ir' WHERE _NAME = 'part_a_12_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='relative_location_in_1' WHERE _NAME = 'kitting_workstation_1';

UPDATE KittingWorkstation
 SET  hasWorkstation_ChangingStation='changing_station_1', hasWorkstation_WorkTable= 'work_table_1', hasWorkstation_Robot= 'robot_1' WHERE _NAME = 'kitting_workstation_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_e_supply_ir' WHERE _NAME = 'part_e_6_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_e_6_point_ir', hasPoseLocation_ZAxis= 'part_e_6_z_axis_ir', hasPoseLocation_XAxis= 'part_e_6_x_axis_ir' WHERE _NAME = 'part_e_6_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'kit_a4b3c3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_a4b3c3_point', hasPoseLocation_ZAxis= 'kit_a4b3c3_z_axis', hasPoseLocation_XAxis= 'kit_a4b3c3_x_axis' WHERE _NAME = 'kit_a4b3c3_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_a_supply_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_supply_point_ir', hasPoseLocation_ZAxis= 'part_a_supply_z_axis_ir', hasPoseLocation_XAxis= 'part_a_supply_x_axis_ir' WHERE _NAME = 'part_a_supply_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c5_c_4_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c5_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c5_c_4_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c5_c_4_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c5_c_4_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c3d1e1_c_3_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c3d1e1_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c3d1e1_c_3_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c3d1e1_c_3_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c3d1e1_c_3_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_1_pose_ir' WHERE _NAME = 'part_c_1_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_c_ir' WHERE _NAME = 'part_c_1_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_2_point', hasPoseLocation_ZAxis= 'kit_tray_2_z_axis', hasPoseLocation_XAxis= 'kit_tray_2_x_axis' WHERE _NAME = 'kit_tray_2_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply_ir' WHERE _NAME = 'part_c_1_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_1_point_ir', hasPoseLocation_ZAxis= 'part_c_1_z_axis_ir', hasPoseLocation_XAxis= 'part_c_1_x_axis_ir' WHERE _NAME = 'part_c_1_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'robot_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='robot_point', hasPoseLocation_ZAxis= 'robot_z_axis', hasPoseLocation_XAxis= 'robot_x_axis' WHERE _NAME = 'robot_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_5_pose_ir' WHERE _NAME = 'part_c_5_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_c_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_c_ir' WHERE _NAME = 'part_c_5_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_d_supply_ir' WHERE _NAME = 'part_d_6_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_d_6_point_ir', hasPoseLocation_ZAxis= 'part_d_6_z_axis_ir', hasPoseLocation_XAxis= 'part_d_6_x_axis_ir' WHERE _NAME = 'part_d_6_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b4c2_a_4_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b4c2_ir', hasPartRefAndPose_Point= 'point_kit_a4b4c2_a_4_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b4c2_a_4_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b4c2_a_4_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'tray_gripper_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='tray_gripper_holder_point', hasPoseLocation_ZAxis= 'tray_gripper_holder_z_axis', hasPoseLocation_XAxis= 'tray_gripper_holder_x_axis' WHERE _NAME = 'tray_gripper_holder_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c3d1e1_a_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c3d1e1_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c3d1e1_a_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c3d1e1_a_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c3d1e1_a_2_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gripper_pose' WHERE _NAME = 'part_gripper';

UPDATE SolidObject
 SET  hasSolidObject_InternalShape='shape_changing_station_base', hasSolidObject_PrimaryLocation= 'changing_station_base_pose' WHERE _NAME = 'changing_station_base';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b4c2_b_3_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b4c2_ir', hasPartRefAndPose_Point= 'point_kit_a4b4c2_b_3_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b4c2_b_3_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b4c2_b_3_ir';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='shape_part_a_ir' WHERE _NAME = 'stock_keeping_unit_part_a_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'part_gripper_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gripper_holder_point', hasPoseLocation_ZAxis= 'part_gripper_holder_z_axis', hasPoseLocation_XAxis= 'part_gripper_holder_x_axis' WHERE _NAME = 'part_gripper_holder_pose';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_tray_4_ir' WHERE _NAME = 'stock_keeping_unit_kit_tray_4_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply' WHERE _NAME = 'part_a_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_1_point', hasPoseLocation_ZAxis= 'part_a_1_z_axis', hasPoseLocation_XAxis= 'part_a_1_x_axis' WHERE _NAME = 'part_a_1_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply_ir' WHERE _NAME = 'kit_tray_2_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_2_point_ir', hasPoseLocation_ZAxis= 'kit_tray_2_z_axis_ir', hasPoseLocation_XAxis= 'kit_tray_2_x_axis_ir' WHERE _NAME = 'kit_tray_2_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gear_4_point', hasPoseLocation_ZAxis= 'part_gear_4_z_axis', hasPoseLocation_XAxis= 'part_gear_4_x_axis' WHERE _NAME = 'part_gear_4_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gear_2_point', hasPoseLocation_ZAxis= 'part_gear_2_z_axis', hasPoseLocation_XAxis= 'part_gear_2_x_axis' WHERE _NAME = 'part_gear_2_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_e_tray_pose_ir' WHERE _NAME = 'part_e_tray_ir';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_e_tray_ir' WHERE _NAME = 'part_e_tray_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_b_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c2d1_b_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c2d1_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c2d1_b_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c2d1_b_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c2d1_b_1_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_box' WHERE _NAME = 'stock_keeping_unit_kit_box';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_d_supply_pose_ir' WHERE _NAME = 'part_d_supply_ir';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_d_tray_ir' WHERE _NAME = 'part_d_supply_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_e_supply_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_e_supply_point_ir', hasPoseLocation_ZAxis= 'part_e_supply_z_axis_ir', hasPoseLocation_XAxis= 'part_e_supply_x_axis_ir' WHERE _NAME = 'part_e_supply_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_5_pose_ir' WHERE _NAME = 'part_b_5_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_b_ir' WHERE _NAME = 'part_b_5_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_parts_tray_a' WHERE _NAME = 'stock_keeping_unit_parts_tray_a';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_parts_tray_c' WHERE _NAME = 'stock_keeping_unit_parts_tray_c';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_parts_tray_b' WHERE _NAME = 'stock_keeping_unit_parts_tray_b';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply' WHERE _NAME = 'part_b_8_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_8_point', hasPoseLocation_ZAxis= 'part_b_8_z_axis', hasPoseLocation_XAxis= 'part_b_8_x_axis' WHERE _NAME = 'part_b_8_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c3d1e1_a_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c3d1e1_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c3d1e1_a_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c3d1e1_a_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c3d1e1_a_1_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_b', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_b_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_b_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_b_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_b_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'work_table_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='work_table_point', hasPoseLocation_ZAxis= 'work_table_z_axis', hasPoseLocation_XAxis= 'work_table_x_axis' WHERE _NAME = 'work_table_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_box_pose_ir' WHERE _NAME = 'empty_kit_tray_box_ir';

UPDATE LargeContainer
 SET  hasLargeContainer_Sku='stock_keeping_unit_kit_box_ir' WHERE _NAME = 'empty_kit_tray_box_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_14_pose_ir' WHERE _NAME = 'part_a_14_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_14_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_18_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_18_point_ir', hasPoseLocation_ZAxis= 'part_a_18_z_axis_ir', hasPoseLocation_XAxis= 'part_a_18_x_axis_ir' WHERE _NAME = 'part_a_18_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_supply_pose' WHERE _NAME = 'empty_kit_tray_supply';

UPDATE LargeBoxWithEmptyKitTrays
 SET  hasLargeBoxWithEmptyKitTrays_LargeContainer='empty_kit_tray_box' WHERE _NAME = 'empty_kit_tray_supply';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_tray_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_tray_point_ir', hasPoseLocation_ZAxis= 'part_a_tray_z_axis_ir', hasPoseLocation_XAxis= 'part_a_tray_x_axis_ir' WHERE _NAME = 'part_a_tray_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c2d1_a_4_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c2d1_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c2d1_a_4_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c2d1_a_4_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c2d1_a_4_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_2_pose_ir' WHERE _NAME = 'part_a_2_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_2_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_e_5_pose_ir' WHERE _NAME = 'part_e_5_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_e_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_e_ir' WHERE _NAME = 'part_e_5_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c5_a_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c5_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c5_a_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c5_a_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c5_a_2_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_8_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_8_point', hasPoseLocation_ZAxis= 'part_c_8_z_axis', hasPoseLocation_XAxis= 'part_c_8_x_axis' WHERE _NAME = 'part_c_8_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_1_pose_ir' WHERE _NAME = 'part_b_1_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_b_ir' WHERE _NAME = 'part_b_1_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_d_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c2d1_d_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c2d1_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c2d1_d_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c2d1_d_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c2d1_d_1_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c5_c_3_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c5_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c5_c_3_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c5_c_3_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c5_c_3_ir';

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
 SET  hasSolidObject_PrimaryLocation='part_a_supply_pose' WHERE _NAME = 'part_a_supply';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_a_tray' WHERE _NAME = 'part_a_supply';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_7_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_7_point_ir', hasPoseLocation_ZAxis= 'part_a_7_z_axis_ir', hasPoseLocation_XAxis= 'part_a_7_x_axis_ir' WHERE _NAME = 'part_a_7_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_6_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_6_point_ir', hasPoseLocation_ZAxis= 'part_a_6_z_axis_ir', hasPoseLocation_XAxis= 'part_a_6_x_axis_ir' WHERE _NAME = 'part_a_6_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_shaft_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gear_shaft_2_point', hasPoseLocation_ZAxis= 'part_gear_shaft_2_z_axis', hasPoseLocation_XAxis= 'part_gear_shaft_2_x_axis' WHERE _NAME = 'part_gear_shaft_2_pose';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='shape_part_b_ir' WHERE _NAME = 'stock_keeping_unit_part_b_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'kit_a4b3c2d1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_a4b3c2d1_point', hasPoseLocation_ZAxis= 'kit_a4b3c2d1_z_axis', hasPoseLocation_XAxis= 'kit_a4b3c2d1_x_axis' WHERE _NAME = 'kit_a4b3c2d1_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_2_pose_ir' WHERE _NAME = 'kit_tray_2_ir';

UPDATE KitTray
 SET  hasKitTray_Sku='stock_keeping_unit_kit_tray_2_ir' WHERE _NAME = 'kit_tray_2_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_box_pose_ir' WHERE _NAME = 'finished_kit_box_ir';

UPDATE LargeContainer
 SET  hasLargeContainer_Sku='stock_keeping_unit_kit_box_ir' WHERE _NAME = 'finished_kit_box_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_13_pose_ir' WHERE _NAME = 'part_a_13_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_13_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'ext_shape_parts_tray_e_ir' WHERE _NAME = 'stock_keeping_unit_parts_e_tray_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_d_supply_ir' WHERE _NAME = 'part_d_8_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_d_8_point_ir', hasPoseLocation_ZAxis= 'part_d_8_z_axis_ir', hasPoseLocation_XAxis= 'part_d_8_x_axis_ir' WHERE _NAME = 'part_d_8_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_e_supply_ir' WHERE _NAME = 'part_e_4_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_e_4_point_ir', hasPoseLocation_ZAxis= 'part_e_4_z_axis_ir', hasPoseLocation_XAxis= 'part_e_4_x_axis_ir' WHERE _NAME = 'part_e_4_pose_ir';

UPDATE StockKeepingUnit
 SET  hasSku_Shape='ext_shape_gear_boss' WHERE _NAME = 'stock_keeping_unit_part_gear_boss';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'kit_a2b3c3d1e1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_a2b3c3d1e1_point', hasPoseLocation_ZAxis= 'kit_a2b3c3d1e1_z_axis', hasPoseLocation_XAxis= 'kit_a2b3c3d1e1_x_axis' WHERE _NAME = 'kit_a2b3c3d1e1_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_8_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_8_point_ir', hasPoseLocation_ZAxis= 'part_a_8_z_axis_ir', hasPoseLocation_XAxis= 'part_a_8_x_axis_ir' WHERE _NAME = 'part_a_8_pose_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b3c5_a_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a2b3c5_ir', hasPartRefAndPose_Point= 'point_kit_a2b3c5_a_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b3c5_a_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a2b3c5_a_1_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_3_pose_ir' WHERE _NAME = 'kit_tray_3_ir';

UPDATE KitTray
 SET  hasKitTray_Sku='stock_keeping_unit_kit_tray_3_ir' WHERE _NAME = 'kit_tray_3_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_c', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_c_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_c_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_c_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_c_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='tray_gripper_holder_pose' WHERE _NAME = 'tray_gripper_holder';

UPDATE EndEffectorHolder
 SET  hadByEndEffectorHolder_ChangingStation='changing_station_1' WHERE _NAME = 'tray_gripper_holder';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_14_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_14_point_ir', hasPoseLocation_ZAxis= 'part_a_14_z_axis_ir', hasPoseLocation_XAxis= 'part_a_14_x_axis_ir' WHERE _NAME = 'part_a_14_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_supply_pose_ir' WHERE _NAME = 'part_a_supply_ir';

UPDATE PartsTrayWithParts
 SET  hasPartsTrayWithParts_Tray='part_a_tray_ir' WHERE _NAME = 'part_a_supply_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_a_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_a_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_a_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_a_1';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_a_2', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_a_2', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_a_2' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_a_2';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_supply_ir' WHERE _NAME = 'part_b_tray_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_b_tray_point_ir', hasPoseLocation_ZAxis= 'part_b_tray_z_axis_ir', hasPoseLocation_XAxis= 'part_b_tray_x_axis_ir' WHERE _NAME = 'part_b_tray_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_shaft_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gear_shaft_1_point', hasPoseLocation_ZAxis= 'part_gear_shaft_1_z_axis', hasPoseLocation_XAxis= 'part_gear_shaft_1_x_axis' WHERE _NAME = 'part_gear_shaft_1_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply_ir' WHERE _NAME = 'kit_tray_5_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='kit_tray_5_point_ir', hasPoseLocation_ZAxis= 'kit_tray_5_z_axis_ir', hasPoseLocation_XAxis= 'kit_tray_5_x_axis_ir' WHERE _NAME = 'kit_tray_5_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_a4b4c2_pose' WHERE _NAME = 'kit_a4b4c2';

UPDATE Kit
 SET  hasKit_Tray='kit_tray_2_ir', hasKit_Design= 'kit_design_a4b4c2_ir' WHERE _NAME = 'kit_a4b4c2';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b4c2_a_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b4c2_ir', hasPartRefAndPose_Point= 'point_kit_a4b4c2_a_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b4c2_a_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b4c2_a_2_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='robot_1' WHERE _NAME = 'relative_location_on_1';

UPDATE KitDesign
 SET  hadByKitDesign_Workstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_design_a2b1c1';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c2d1_a_1_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c2d1_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c2d1_a_1_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c2d1_a_1_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c2d1_a_1_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'empty_kit_tray_box_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='empty_kit_tray_box_point', hasPoseLocation_ZAxis= 'empty_kit_tray_box_z_axis', hasPoseLocation_XAxis= 'empty_kit_tray_box_x_axis' WHERE _NAME = 'empty_kit_tray_box_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_2_pose_ir' WHERE _NAME = 'part_b_2_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_b_ir' WHERE _NAME = 'part_b_2_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_c_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c2d1_c_2_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c2d1_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c2d1_c_2_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c2d1_c_2_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c2d1_c_2_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'empty_kit_tray_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='empty_kit_tray_supply_point', hasPoseLocation_ZAxis= 'empty_kit_tray_supply_z_axis', hasPoseLocation_XAxis= 'empty_kit_tray_supply_x_axis' WHERE _NAME = 'empty_kit_tray_supply_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='robot_pose' WHERE _NAME = 'robot_1';

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

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_d_supply_ir' WHERE _NAME = 'part_d_7_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_d_7_point_ir', hasPoseLocation_ZAxis= 'part_d_7_z_axis_ir', hasPoseLocation_XAxis= 'part_d_7_x_axis_ir' WHERE _NAME = 'part_d_7_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_4_pose' WHERE _NAME = 'part_a_4';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply', hasPart_Sku= 'stock_keeping_unit_part_a' WHERE _NAME = 'part_a_4';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_d_supply_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_d_supply_point_ir', hasPoseLocation_ZAxis= 'part_d_supply_z_axis_ir', hasPoseLocation_XAxis= 'part_d_supply_x_axis_ir' WHERE _NAME = 'part_d_supply_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gear_3_point', hasPoseLocation_ZAxis= 'part_gear_3_z_axis', hasPoseLocation_XAxis= 'part_gear_3_x_axis' WHERE _NAME = 'part_gear_3_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply_ir' WHERE _NAME = 'empty_kit_tray_box_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='empty_kit_tray_box_point_ir', hasPoseLocation_ZAxis= 'empty_kit_tray_box_z_axis_ir', hasPoseLocation_XAxis= 'empty_kit_tray_box_x_axis_ir' WHERE _NAME = 'empty_kit_tray_box_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='changing_station_pose' WHERE _NAME = 'changing_station_1';

UPDATE EndEffectorChangingStation
 SET  hasChangingStation_Base='changing_station_base' WHERE _NAME = 'changing_station_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_gear_1_point', hasPoseLocation_ZAxis= 'part_gear_1_z_axis', hasPoseLocation_XAxis= 'part_gear_1_x_axis' WHERE _NAME = 'part_gear_1_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_2_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_2_point_ir', hasPoseLocation_ZAxis= 'part_a_2_z_axis_ir', hasPoseLocation_XAxis= 'part_a_2_x_axis_ir' WHERE _NAME = 'part_a_2_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_1_point', hasPoseLocation_ZAxis= 'part_c_1_z_axis', hasPoseLocation_XAxis= 'part_c_1_x_axis' WHERE _NAME = 'part_c_1_pose';