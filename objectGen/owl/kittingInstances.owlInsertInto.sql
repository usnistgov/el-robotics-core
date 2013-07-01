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
VALUES('part_ref_and_pose_kit_a4b3c2d1_a_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(4, 'part_ref_and_pose_kit_a4b3c2d1_a_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_4_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(2, 'part_d_4_ir', 'd4_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_c_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(5, 'point_kit_a2b3c5_c_3_ir', 0.787200, 0.330100, 0.045000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(6, 'part_b_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(6, 'part_b_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(6, 'part_b_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(7, 'z_axis_kit_a4b3c3_c_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_a4b3c3', NULL);

INSERT INTO Kit
(KitID, _NAME, isKit_Finished, hasKit_Tray, hasKit_Design)
VALUES(3, 'kit_a4b3c3', 'false', NULL, NULL);

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
VALUES(8, 'finished_kit_receiver_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(8, 'finished_kit_receiver_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(8, 'finished_kit_receiver_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(9, 'part_b_5_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(9, 'part_b_5_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(9, 'part_b_5_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(10, 'part_b_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(10, 'part_b_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(10, 'part_b_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c5_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(11, 'kit_a2b3c5_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(11, 'kit_a2b3c5_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(11, 'kit_a2b3c5_pose');

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

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_tray_ir', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(5, 'part_b_tray_ir', 7, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_9_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(6, 'part_b_9_ir', 'b9_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(13, 'kit_tray_2_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_a_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(14, 'point_kit_a2b1c1_a_2', 0.400000, 0.300000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_5', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(7, 'part_c_5', 'c5', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_a_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(15, 'point_kit_a2b1c1_a_1', 0.200000, 0.300000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(8, 'part_c_4', 'c4', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(9, 'part_c_3', 'c3', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(10, 'part_c_2', 'c2', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(11, 'part_c_1', 'c1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_5_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(16, 'kit_tray_5_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_10_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(17, 'part_a_10_point_ir', 0.469500, -0.216000, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(18, 'part_a_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(18, 'part_a_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(18, 'part_a_tray_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_8', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(12, 'part_c_8', 'c8', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_7_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(13, 'part_a_7_ir', 'a7_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_7', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(14, 'part_c_7', 'c7', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c2d1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(19, 'kit_a4b3c2d1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_6', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(15, 'part_c_6', 'c6', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(20, 'z_axis_kit_a4b4c2_b_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(16, 'part_c_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_8_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(21, 'part_a_8_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_b_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(22, 'part_ref_and_pose_kit_a4b3c3_b_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_a_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(23, 'z_axis_kit_a4b3c2d1_a_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_9_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(24, 'part_d_9_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_b_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(25, 'shape_part_b_ir', 'Shape of PartB_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(25, 'shape_part_b_ir', 'USARSim', 'BlockB', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(26, 'part_a_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_8_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(27, 'part_d_8_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_4_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(28, 'part_e_4_point_ir', 0.165600, -0.127400, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(29, 'part_b_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_d_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(30, 'point_kit_a4b3c2d1_d_1_ir', 0.088800, 0.292000, 0.025400);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(17, 'part_a_tray', 6, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_a_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(31, 'shape_part_a_ir', 'Shape of PartA_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(31, 'shape_part_a_ir', 'USARSim', 'BlockA', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_tray_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(32, 'part_d_tray_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(32, 'part_d_tray_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(32, 'part_d_tray_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(33, 'x_axis_kit_a4b3c3_a_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(34, 'part_b_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_b_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(35, 'point_kit_a4b3c3_b_3_ir', 0.635000, 0.114700, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(36, 'part_b_1_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(36, 'part_b_1_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(36, 'part_b_1_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_a_4_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(37, 'point_kit_a4b4c2_a_4_ir', 0.622700, 0.292400, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_a_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(38, 'point_kit_a4b3c3_a_1_ir', 0.546100, 0.368700, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(39, 'z_axis_kit_a2b1c1_c_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray_2_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(40, 'shape_kit_tray_2_ir', 'Shape of KitTray 2');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(40, 'shape_kit_tray_2_ir', 'USARSim', 'KitTray2', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_c_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(41, 'part_ref_and_pose_kit_a4b3c2d1_c_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_11_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(42, 'part_a_11_point_ir', 0.596500, -0.216000, 0.027500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_11_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(18, 'part_a_11_ir', 'a11_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_5_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(43, 'kit_tray_5_point_ir', -0.5, 1.000000, 0.200000);

INSERT INTO DataThing
(_NAME)
VALUES('point_min');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(44, 'point_min', -1.000000, -1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(45, 'part_b_3_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_supply_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(46, 'part_e_supply_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(47, 'tray_gripper_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_a');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(48, 'shape_part_a', 'Shape of PartA');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(48, 'shape_part_a', 'USARSim', 'PartA', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_b');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(49, 'shape_part_b', 'Shape of PartB');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(49, 'shape_part_b', 'USARSim', 'PartB', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_10_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(50, 'part_a_10_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(50, 'part_a_10_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(50, 'part_a_10_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_c');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(51, 'shape_part_c', 'Shape of PartC');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(51, 'shape_part_c', 'USARSim', 'PartC', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(52, 'part_a_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(52, 'part_a_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(52, 'part_a_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_14_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(53, 'part_a_14_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_a_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(54, 'z_axis_kit_a4b4c2_a_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_c_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(55, 'part_ref_and_pose_kit_a4b3c3_c_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_9_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(56, 'part_d_9_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(57, 'part_gripper_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_a_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(58, 'part_ref_and_pose_kit_a4b4c2_a_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_1_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(59, 'part_d_1_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(59, 'part_d_1_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(59, 'part_d_1_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(60, 'part_c_3_point_ir', 0.533400, -0.330200, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_c_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(61, 'x_axis_kit_a4b3c3_c_3_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_6_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(19, 'part_b_6_ir', 'b6', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(62, 'part_b_6_point', -0.240000, -0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_supply_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(63, 'part_d_supply_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(64, 'part_a_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_3_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(65, 'part_d_3_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(66, 'kit_tray_1_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(67, 'part_a_1_point', 0.159000, 0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_d_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(68, 'stock_keeping_unit_part_d_ir', 'SKU for Part D_ir', 0.180000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(68, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_8_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(69, 'part_d_8_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(70, 'part_c_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(71, 'part_b_supply_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(71, 'part_b_supply_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(71, 'part_b_supply_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(72, 'part_c_4_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(73, 'x_axis_kit_a4b3c3_b_3_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(74, 'kit_tray_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(75, 'part_b_6_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(75, 'part_b_6_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(75, 'part_b_6_pose');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_b_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(76, 'point_kit_a2b3c3d1e1_b_1_ir', 0.126800, 0.089300, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(77, 'kit_tray_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_9_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(78, 'part_b_9_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(78, 'part_b_9_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(78, 'part_b_9_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_c_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(79, 'point_kit_a2b2c1_c_1', 0.060000, -0.090000, 0.045000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_2_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(20, 'part_e_2_ir', 'e2_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_2_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(21, 'part_c_2_ir', 'c2_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_4_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(80, 'part_d_4_point_ir', 0.165600, -0.216000, 0.027500);

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
VALUES('shape_parts_tray_c_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(83, 'shape_parts_tray_c_ir', 'Shape of PartsTrays for parts of type C, used for Intention Recognition');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(83, 'shape_parts_tray_c_ir');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(83, 'shape_parts_tray_c_ir', 0.457200, 'false', 0.025400, 0.863600);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_13_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(84, 'part_a_13_point_ir', 0.088500, -0.089000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(85, 'part_b_2_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(85, 'part_b_2_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(85, 'part_b_2_pose_ir');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_9_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(22, 'part_a_9_ir', 'a9_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(86, 'part_b_tray_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c3d1e1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(87, 'kit_a2b3c3d1e1_point', 0.100000, 0.200000, 0.500000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_8_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(23, 'part_b_8_ir', 'b8_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray_1_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(88, 'stock_keeping_unit_kit_tray_1_ir', 'SKU for KitTray 1', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(88, 1);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_c_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(89, 'stock_keeping_unit_part_c_ir', 'SKU for Part C_ir', 0.180000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(89, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(90, 'part_c_5_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(90, 'part_c_5_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(90, 'part_c_5_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(91, 'kit_tray_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(91, 'kit_tray_3_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(91, 'kit_tray_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_9_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(92, 'part_a_9_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(93, 'part_c_7_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(94, 'part_a_3_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_2_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(24, 'part_d_2_ir', 'd2_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(95, 'part_c_4_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(95, 'part_c_4_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(95, 'part_c_4_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(96, 'part_a_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_d_tray_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(97, 'stock_keeping_unit_parts_d_tray_ir', 'SKU for PartsTrays containing parts of type D, used for Intention Recognition', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(97, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(98, 'part_c_8_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_supply_ir', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(25, 'part_e_supply_ir', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(99, 'part_a_4_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(99, 'part_a_4_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(99, 'part_a_4_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_b_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(100, 'part_ref_and_pose_kit_a4b4c2_b_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(101, 'part_a_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_4_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(26, 'part_b_4_ir', 'b4_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_b_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(102, 'point_kit_a4b4c2_b_2_ir', 0.330600, 0.216400, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(103, 'x_axis_kit_a4b4c2_b_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_a_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(104, 'x_axis_kit_a4b3c2d1_a_3_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray_3_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(105, 'stock_keeping_unit_kit_tray_3_ir', 'SKU for KitTray 3', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(105, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(106, 'part_c_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(106, 'part_c_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(106, 'part_c_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_4_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(107, 'part_d_4_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_8_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(27, 'part_d_8_ir', 'd8_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(108, 'part_c_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(109, 'part_a_3_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(110, 'kit_tray_3_point', 2.000000, 0.000000, 0.145000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_5_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(111, 'part_a_5_point_ir', 0.596500, -0.343000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(112, 'x_axis_kit_a2b3c3d1e1_c_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(113, 'z_axis_kit_a2b3c5_b_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_e_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(114, 'x_axis_kit_a2b3c3d1e1_e_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(115, 'part_c_7_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(116, 'tray_gripper_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(117, 'part_b_3_point', 0.080000, 0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(118, 'part_c_8_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(118, 'part_c_8_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(118, 'part_c_8_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_e_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(119, 'shape_parts_tray_e_ir', 'Shape of PartsTrays for parts of type E, used for Intention Recognition');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(119, 'shape_parts_tray_e_ir');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(119, 'shape_parts_tray_e_ir', 0.431900, 'false', 0.025400, 0.889500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_12_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(120, 'part_b_12_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(121, 'part_c_6_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(121, 'part_c_6_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(121, 'part_c_6_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_a_4_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(122, 'point_kit_a4b3c2d1_a_4_ir', 0.088800, 0.088800, 0.025400);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_4_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(28, 'part_a_4_ir', 'a4_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_a_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(123, 'x_axis_kit_a4b3c3_a_4_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_tray_ir', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(29, 'part_a_tray_ir', 6, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_4_ir', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku)
VALUES(30, 'kit_tray_4_ir', 31, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(124, 'part_c_7_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(124, 'part_c_7_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(124, 'part_c_7_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(125, 'part_a_2_point_ir', 0.215500, -0.343000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(126, 'part_b_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(127, 'part_b_1_point_ir', 0.088500, -0.330600, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(128, 'part_b_5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_10_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(31, 'part_b_10_ir', 'b10_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_10_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(32, 'part_a_10_ir', 'a10_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_12_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(129, 'part_a_12_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_max');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(130, 'point_max', 1.000000, 1.000000, 2.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a4b3c3_ir');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(131, 'kit_design_a4b3c3_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(132, 'part_b_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_d_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(133, 'shape_part_d_ir', 'Shape of PartD_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(133, 'shape_part_d_ir', 'USARSim', 'BlockD', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(134, 'part_c_supply_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(134, 'part_c_supply_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(134, 'part_c_supply_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(135, 'x_axis_kit_a4b3c2d1_b_2_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('box_volume_1');

INSERT INTO BoxVolume
(BoxVolumeID, _NAME, hasBoxVolume_MaximumPoint, hasBoxVolume_MinimumPoint)
VALUES(136, 'box_volume_1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_9_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(137, 'part_b_9_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(138, 'part_a_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(138, 'part_a_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(138, 'part_a_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_8_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(139, 'part_d_8_point_ir', 0.445000, -0.089000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(140, 'changing_station_base_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_a_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(141, 'point_kit_a4b3c2d1_a_1_ir', 0.622200, 0.368200, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_c_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(142, 'point_kit_a4b3c3_c_1_ir', 0.127000, 0.330600, 0.025400);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_1_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(33, 'part_a_1_ir', 'a1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(143, 'part_a_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(144, 'z_axis_kit_a4b3c2d1_a_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(145, 'part_a_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_5_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(146, 'part_e_5_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a4b4c2_ir');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(147, 'kit_design_a4b4c2_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(148, 'part_c_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_3_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(149, 'part_e_3_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b4c2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(150, 'kit_a4b4c2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_2_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(151, 'part_d_2_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_b_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(152, 'part_ref_and_pose_kit_a4b3c2d1_b_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(153, 'part_b_5_point_ir', 0.596500, -0.330600, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_4_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(154, 'kit_tray_4_point_ir', -0.5, 1.000000, 0.200000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_a_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(155, 'point_kit_a4b3c2d1_a_3_ir', 0.622200, 0.114200, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_b_4_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(156, 'part_ref_and_pose_kit_a4b4c2_b_4_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b2c1');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(157, 'kit_design_a2b2c1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_a_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(158, 'part_ref_and_pose_kit_a4b3c3_a_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_18_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(159, 'part_a_18_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(160, 'z_axis_kit_a4b4c2_a_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_parts_tray_e_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(161, 'ext_shape_parts_tray_e_ir', 'Shape of PartsTray_E_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(161, 'ext_shape_parts_tray_e_ir', 'USARSim', 'PartTrayE', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(162, 'part_c_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_a_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(163, 'point_kit_a4b3c3_a_3_ir', 0.546100, 0.241700, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(164, 'x_axis_kit_a2b3c3d1e1_a_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_supply_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(165, 'part_e_supply_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_c_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(166, 'part_ref_and_pose_kit_a2b3c3d1e1_c_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(167, 'kit_tray_3_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(167, 'kit_tray_3_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(167, 'kit_tray_3_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(168, 'part_c_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(169, 'x_axis_kit_a2b3c5_c_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(170, 'part_b_8_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(170, 'part_b_8_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(170, 'part_b_8_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(171, 'part_c_6_point_ir', 0.330200, -0.127000, 0.027500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_4_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(34, 'part_c_4_ir', 'c4_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b4c2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(172, 'kit_a4b4c2_point', 0.100000, 0.200000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_c_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(173, 'part_ref_and_pose_kit_a2b3c5_c_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(174, 'part_a_tray_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_10_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(175, 'part_b_10_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_tray_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(176, 'part_e_tray_point_ir', 0.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_11_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(35, 'part_b_11_ir', 'b11_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_2_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(177, 'part_e_2_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(178, 'empty_kit_tray_box_point', 0.500000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_3_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(36, 'part_e_3_ir', 'e3_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_e_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(179, 'part_ref_and_pose_kit_a2b3c3d1e1_e_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(180, 'z_axis_kit_a2b3c5_c_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(181, 'part_c_2_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(181, 'part_c_2_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(181, 'part_c_2_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_b_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(182, 'part_ref_and_pose_kit_a2b3c3d1e1_b_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_tray_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(183, 'part_d_tray_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(184, 'part_b_5_point', -0.080000, -0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_3_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(185, 'part_e_3_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(185, 'part_e_3_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(185, 'part_e_3_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_c_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(186, 'point_kit_a2b3c3d1e1_c_1_ir', 0.457000, 0.330600, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_a_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(187, 'x_axis_kit_a4b4c2_a_4_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(188, 'part_b_2_point_ir', 0.215500, -0.330600, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_5_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(189, 'part_a_5_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(189, 'part_a_5_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(189, 'part_a_5_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_c_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(190, 'z_axis_kit_a2b3c3d1e1_c_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_3_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(37, 'part_d_3_ir', 'd3_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_9_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(191, 'part_a_9_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_c_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(192, 'point_kit_a4b3c2d1_c_2_ir', 0.253900, 0.126900, 0.025400);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(38, 'part_b_tray', 7, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(193, 'finished_kit_receiver_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(193, 'finished_kit_receiver_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(193, 'finished_kit_receiver_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(194, 'z_axis_kit_a4b3c3_b_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_a');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(195, 'stock_keeping_unit_part_a', 'SKU for Part A', 0.180000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(195, 1);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_3_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(39, 'part_a_3_ir', 'a3_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_18_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(40, 'part_a_18_ir', 'a18_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(196, 'part_b_7_point_ir', 0.088500, -0.127400, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_b_tray_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(197, 'stock_keeping_unit_parts_b_tray_ir', 'SKU for PartsTrays containing parts of type B, used for Intention Recognition', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(197, 1);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_16_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(41, 'part_a_16_ir', 'a16_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_7_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(42, 'part_d_7_ir', 'd7_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_7_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(43, 'part_c_7_ir', 'c7_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(198, 'work_table_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(199, 'z_axis_kit_a2b3c5_b_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_15_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(44, 'part_a_15_ir', 'a15_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(200, 'part_c_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_6_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(45, 'part_a_6_ir', 'a6_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(201, 'part_b_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(201, 'part_b_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(201, 'part_b_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b3c3d1e1_ir');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(202, 'kit_design_a2b3c3d1e1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(203, 'stock_keeping_unit_kit_tray', 'SKU for KitTrays', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(203, 1);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_a_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(204, 'point_kit_a2b3c3d1e1_a_2_ir', 0.825300, 0.368700, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(205, 'part_b_4_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(205, 'part_b_4_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(205, 'part_b_4_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(206, 'kit_tray_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(207, 'kit_a2b3c5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(208, 'kit_a4b3c3_point', 0.100000, 0.200000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(209, 'finished_kit_box_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(210, 'part_c_2_point_ir', 0.330200, -0.330200, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_a_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(211, 'point_kit_a2b3c5_a_2_ir', 0.215700, 0.114200, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(212, 'part_gripper_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_17_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(213, 'part_a_17_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_tray_ir', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(46, 'part_c_tray_ir', 8, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_12_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(214, 'part_b_12_point_ir', 0.723500, -0.127400, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_16_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(215, 'part_a_16_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(215, 'part_a_16_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(215, 'part_a_16_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_e_1_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(216, 'part_e_1_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(217, 'part_b_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_16_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(218, 'part_a_16_point_ir', 0.469500, -0.089000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(219, 'finished_kit_box_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_4_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(220, 'part_e_4_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_10_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(221, 'part_a_10_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_c');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(222, 'stock_keeping_unit_part_c', 'SKU for Part C', 0.180000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(222, 1);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_b');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(223, 'stock_keeping_unit_part_b', 'SKU for Part B', 0.180000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(223, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(224, 'part_b_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_c_5_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(225, 'x_axis_kit_a2b3c5_c_5_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_a_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(226, 'point_kit_a4b3c3_a_2_ir', 0.673100, 0.368700, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_a_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(227, 'part_ref_and_pose_kit_a4b4c2_a_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(228, 'part_c_3_point', -0.110000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_15_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(229, 'part_a_15_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(229, 'part_a_15_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(229, 'part_a_15_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_10_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(230, 'part_b_10_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(230, 'part_b_10_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(230, 'part_b_10_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_a_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(231, 'part_ref_and_pose_kit_a2b1c1_a_2', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(232, 'part_a_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_a_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(233, 'part_ref_and_pose_kit_a2b1c1_a_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(234, 'part_b_3_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(235, 'z_axis_kit_a4b3c2d1_c_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(236, 'part_c_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_d_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(237, 'point_kit_a2b3c3d1e1_d_1_ir', 0.291900, 0.292500, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('shape_changing_station_base');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(238, 'shape_changing_station_base', 'Shape of base of changing station');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(238, 'shape_changing_station_base');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(238, 'shape_changing_station_base', 0.100000, 'true', 1.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_11_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(239, 'part_a_11_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_box_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(240, 'stock_keeping_unit_kit_box_ir', 'SKU for Boxes for Kits and KitTrays for Intention Recognition', 1.200000, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(241, 'part_b_8_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_tray_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(242, 'part_e_tray_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_13_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(243, 'part_a_13_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(243, 'part_a_13_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(243, 'part_a_13_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_a_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(244, 'point_kit_a2b2c1_a_2', -0.159000, -0.149000, 0.036000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_a_tray_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(245, 'stock_keeping_unit_parts_a_tray_ir', 'SKU for PartsTrays containing parts of type A, used for Intention Recognition', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(245, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(246, 'part_c_5_point_ir', 0.127000, -0.127000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_a_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(247, 'point_kit_a2b2c1_a_1', -0.159000, 0.145000, 0.036000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_4_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(47, 'part_e_4_ir', 'e4_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_6_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(248, 'part_e_6_point_ir', 0.724400, -0.127400, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_b_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(249, 'part_ref_and_pose_kit_a4b3c2d1_b_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(250, 'x_axis_kit_a4b4c2_a_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(251, 'changing_station_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(252, 'empty_kit_tray_supply_point', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_c_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(253, 'part_ref_and_pose_kit_a4b3c3_c_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(254, 'kit_tray_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_9_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(255, 'part_b_9_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(256, 'part_c_7_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(256, 'part_c_7_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(256, 'part_c_7_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(257, 'part_gripper_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_c_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(258, 'point_kit_a4b4c2_c_1_ir', 0.127400, 0.381300, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_1_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(259, 'part_d_1_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_11_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(260, 'part_b_11_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_11_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(261, 'part_b_11_point_ir', 0.596500, -0.127400, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('robot_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(262, 'robot_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(263, 'part_b_7_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(264, 'x_axis_kit_a2b1c1_c_1', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_tray', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(48, 'part_c_tray', 8, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_b_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(265, 'point_kit_a2b3c5_b_3_ir', 0.749100, 0.126900, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_a_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(266, 'part_ref_and_pose_kit_a4b3c3_a_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(267, 'x_axis_kit_a4b3c3_a_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_14_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(268, 'part_a_14_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_7_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(269, 'part_d_7_point_ir', 0.165600, -0.089000, 0.027500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_7_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(49, 'part_b_7_ir', 'b7', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_c_5_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(270, 'z_axis_kit_a2b3c5_c_5_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_receiver_ir', NULL);

INSERT INTO LargeBoxWithKits
(LargeBoxWithKitsID, _NAME, hasLargeBoxWithKits_Capacity, hasLargeBoxWithKits_LargeContainer, hasLargeBoxWithKits_KitDesign)
VALUES(50, 'finished_kit_receiver_ir', 12, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_c_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(271, 'z_axis_kit_a2b3c5_c_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(272, 'part_b_2_point', -0.240000, 0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_2_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(273, 'part_e_2_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(273, 'part_e_2_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(273, 'part_e_2_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(274, 'part_gripper_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(275, 'part_b_6_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(276, 'x_axis_kit_a4b3c2d1_c_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(277, 'part_c_7_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(278, 'empty_kit_tray_box_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(51, 'empty_kit_tray_box', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(279, 'z_axis_kit_a2b3c5_c_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(280, 'part_c_4_point', -0.330000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(281, 'x_axis_kit_a2b1c1_a_2', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(282, 'z_axis_kit_a4b3c2d1_a_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(283, 'x_axis_kit_a2b1c1_a_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(284, 'part_c_tray_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(285, 'part_c_1_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(286, 'part_b_6_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_6_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(287, 'part_d_6_point_ir', 0.724400, -0.216000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(288, 'z_axis_kit_a2b3c5_a_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_9_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(289, 'part_a_9_point_ir', 0.342500, -0.216000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(290, 'part_a_tray_point_ir', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(291, 'part_c_5_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(292, 'part_b_8_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(293, 'part_b_supply_point_ir', -3.400000, 2.350000, 0.200000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(294, 'part_b_1_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(295, 'part_c_7_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_b_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(296, 'point_kit_a4b3c3_b_1_ir', 0.292100, 0.419100, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_4_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(297, 'kit_tray_4_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_11_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(298, 'part_b_11_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(299, 'part_c_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(300, 'part_c_supply_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(301, 'kit_tray_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(301, 'kit_tray_1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(301, 'kit_tray_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_a');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(302, 'shape_parts_tray_a', 'Shape of PartsTray_A');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(302, 'shape_parts_tray_a', 'USARSim', 'PartATray', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_b');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(303, 'shape_parts_tray_b', 'Shape of PartsTray_B');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(303, 'shape_parts_tray_b', 'USARSim', 'PartBTray', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_c');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(304, 'shape_parts_tray_c', 'Shape of PartsTray_C');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(304, 'shape_parts_tray_c', 'USARSim', 'PartCTray', 'USARPhysObj');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_12_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(52, 'part_a_12_ir', 'a12_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(305, 'part_a_4_point', -0.159000, 0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(306, 'part_c_1_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_in_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(307, 'relative_location_in_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(307, 'relative_location_in_1', 'The  KittingWorkstation is in kitting_workstation_1');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(307, 'relative_location_in_1');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_c_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(308, 'part_ref_and_pose_kit_a4b4c2_c_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(309, 'x_axis_kit_a4b3c2d1_a_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(310, 'z_axis_kit_a2b3c3d1e1_b_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(311, 'part_a_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_4_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(312, 'kit_tray_4_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(312, 'kit_tray_4_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(312, 'kit_tray_4_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_c_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(313, 'point_kit_a2b1c1_c_1', 0.400000, 0.500000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_6_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(314, 'part_d_6_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(315, 'empty_kit_tray_supply_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_supply_ir', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(53, 'part_b_supply_ir', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(316, 'part_c_2_point', 0.330000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(317, 'z_axis_kit_a4b3c2d1_b_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(318, 'kit_tray_2_point', 0.75, 0.000000, 0.075000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(319, 'part_gripper_holder_point', 0.250000, 0.000000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(320, 'x_axis_kit_a2b3c5_a_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(321, 'part_c_6_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(322, 'z_axis_kit_a4b3c2d1_b_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(323, 'part_c_1_point_ir', 0.127000, -0.330200, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_17_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(324, 'part_a_17_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(324, 'part_a_17_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(324, 'part_a_17_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(325, 'part_a_supply_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray_2_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(326, 'stock_keeping_unit_kit_tray_2_ir', 'SKU for KitTray 2', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(326, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(327, 'part_c_6_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(327, 'part_c_6_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(327, 'part_c_6_pose');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_c_tray_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(328, 'stock_keeping_unit_parts_c_tray_ir', 'SKU for PartsTrays containing parts of type C, used for Intention Recognition', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(328, 1);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b3c5_ir');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(329, 'kit_design_a2b3c5_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(330, 'part_b_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(331, 'empty_kit_tray_box_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_1_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(54, 'part_d_1_ir', 'd1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(332, 'part_c_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(332, 'part_c_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(332, 'part_c_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_e_2_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(333, 'part_e_2_point_ir', 0.445000, -0.330600, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(334, 'changing_station_base_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(334, 'changing_station_base_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(334, 'changing_station_base_pose');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_a_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(335, 'point_kit_a2b3c5_a_1_ir', 0.215700, 0.241200, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(336, 'part_a_3_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(336, 'part_a_3_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(336, 'part_a_3_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(337, 'part_c_5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(338, 'z_axis_kit_a4b3c3_a_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_5_ir', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku)
VALUES(55, 'kit_tray_5_ir', 32, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(339, 'part_a_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(339, 'part_a_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(339, 'part_a_3_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_a2b3c3d1e1', NULL);

INSERT INTO Kit
(KitID, _NAME, isKit_Finished, hasKit_Tray, hasKit_Design)
VALUES(56, 'kit_a2b3c3d1e1', 'false', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(340, 'part_b_5_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(341, 'part_c_2_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_b_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(342, 'part_ref_and_pose_kit_a4b4c2_b_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(343, 'finished_kit_receiver_point_ir', 1.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(344, 'kit_a4b3c3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(345, 'kit_a2b3c5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(346, 'finished_kit_receiver_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_d_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(347, 'part_ref_and_pose_kit_a2b3c3d1e1_d_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(348, 'kit_tray_1_point_ir', -0.5, 1.000000, 0.20000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_b_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(349, 'part_ref_and_pose_kit_a2b3c5_b_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_5_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(350, 'part_a_5_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_5_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(351, 'part_d_5_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_supply_ir', NULL);

INSERT INTO LargeBoxWithEmptyKitTrays
(LargeBoxWithEmptyKitTraysID, _NAME, hasLargeBoxWithEmptyKitTrays_LargeContainer)
VALUES(57, 'empty_kit_tray_supply_ir', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(352, 'part_b_7_point', 0.080000, -0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(353, 'part_b_8_point_ir', 0.215500, -0.127400, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(354, 'changing_station_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(354, 'changing_station_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(354, 'changing_station_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_e_5_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(355, 'part_e_5_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(355, 'part_e_5_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(355, 'part_e_5_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(356, 'z_axis_kit_a2b1c1_b_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_6_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(357, 'part_a_6_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_4_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(358, 'part_e_4_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(359, 'x_axis_kit_a2b2c1_a_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_c_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(360, 'point_kit_a2b3c3d1e1_c_2_ir', 0.660200, 0.330600, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(361, 'x_axis_kit_a2b2c1_a_2', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c2d1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(362, 'kit_a4b3c2d1_point', 0.100000, 0.200000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_tray_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(363, 'part_e_tray_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(363, 'part_e_tray_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(363, 'part_e_tray_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(364, 'part_b_8_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(365, 'part_c_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(366, 'part_a_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(367, 'part_c_8_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(368, 'x_axis_kit_a2b2c1_c_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(369, 'part_c_7_point_ir', 0.533400, -0.127000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('robot_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(370, 'robot_point', 3.000000, 0.000000, 2.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(371, 'finished_kit_box_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(372, 'part_c_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_parts_tray_a_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(373, 'ext_shape_parts_tray_a_ir', 'Shape of PartsTray_A_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(373, 'ext_shape_parts_tray_a_ir', 'USARSim', 'PartTrayA', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(374, 'part_b_7_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(375, 'part_a_3_point_ir', 0.342500, -0.343000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(376, 'part_a_2_point', 0.159000, -0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_4_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(377, 'part_d_4_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(377, 'part_d_4_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(377, 'part_d_4_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(378, 'x_axis_kit_a2b3c5_b_2_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_1_ir', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku)
VALUES(58, 'kit_tray_1_ir', 30, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_12_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(379, 'part_b_12_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(379, 'part_b_12_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(379, 'part_b_12_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_b_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(380, 'point_kit_a2b3c5_b_2_ir', 0.088700, 0.203100, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(381, 'part_c_5_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(382, 'part_c_8_point_ir', 0.736600, -0.127000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_a_4_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(383, 'part_ref_and_pose_kit_a4b3c3_a_4_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_supply_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(384, 'part_e_supply_point_ir', -0.250000, 0.320000, 0.200000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray_4_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(385, 'shape_kit_tray_4_ir', 'Shape of KitTray 3');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(385, 'shape_kit_tray_4_ir', 'USARSim', 'KitTray4', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_e_1_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(386, 'part_e_1_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(386, 'part_e_1_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(386, 'part_e_1_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_c_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(387, 'part_ref_and_pose_kit_a2b3c3d1e1_c_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(388, 'part_b_1_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(389, 'z_axis_kit_a2b2c1_b_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_b_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(390, 'z_axis_kit_a2b2c1_b_2', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(391, 'x_axis_kit_a2b3c3d1e1_c_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_c_5_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(392, 'part_ref_and_pose_kit_a2b3c5_c_5_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_b_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(393, 'part_ref_and_pose_kit_a2b2c1_b_2', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_b_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(394, 'part_ref_and_pose_kit_a2b2c1_b_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(395, 'kit_tray_1_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(395, 'kit_tray_1_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(395, 'kit_tray_1_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_7_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(396, 'part_a_7_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(397, 'part_b_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(397, 'part_b_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(397, 'part_b_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(398, 'kit_tray_2_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_14_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(399, 'part_a_14_point_ir', 0.215500, -0.089000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_6_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(400, 'part_e_6_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_tray_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(401, 'part_d_tray_point_ir', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(402, 'part_c_supply_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(403, 'empty_kit_tray_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_c_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(404, 'z_axis_kit_a4b3c3_c_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(405, 'part_c_2_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_c_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(406, 'x_axis_kit_a2b3c5_c_4_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_8_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(59, 'part_a_8_ir', 'a8_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c3d1e1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(407, 'kit_a2b3c3d1e1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gripper_holder', NULL);

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_ChangingStation, hasEndEffectorHolder_EndEffector)
VALUES(60, 'part_gripper_holder', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(408, 'part_c_8_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(409, 'changing_station_base_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_b_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(410, 'z_axis_kit_a4b4c2_b_4_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_e_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(411, 'z_axis_kit_a2b3c3d1e1_e_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_2_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(412, 'part_d_2_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(412, 'part_d_2_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(412, 'part_d_2_pose_ir');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_supply_ir', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(61, 'part_c_supply_ir', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(413, 'part_c_6_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(414, 'part_gripper_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(414, 'part_gripper_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(414, 'part_gripper_pose');

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(415, 'empty_kit_tray_supply_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(415, 'empty_kit_tray_supply_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(415, 'empty_kit_tray_supply_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(416, 'part_c_3_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(416, 'part_c_3_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(416, 'part_c_3_pose_ir');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_6_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(62, 'part_c_6_ir', 'c6_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(417, 'part_c_6_point', 0.330000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_7_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(418, 'part_a_7_point_ir', 0.088500, -0.216000, 0.027500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_8_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(63, 'part_c_8_ir', 'c8_ir', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_17_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(64, 'part_a_17_ir', 'a17_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_e_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(419, 'stock_keeping_unit_part_e_ir', 'SKU for Part E_ir', 0.180000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(419, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_6_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(420, 'part_e_6_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(421, 'part_b_tray_point_ir', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_e_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(422, 'shape_part_e_ir', 'Shape of PartE_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(422, 'shape_part_e_ir', 'USARSim', 'BlockE', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(423, 'part_b_6_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(423, 'part_b_6_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(423, 'part_b_6_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_c_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(424, 'z_axis_kit_a2b3c5_c_4_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(425, 'part_a_supply_point_ir', -0.250000, 2.350000, 0.200000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_a4b3c2d1', NULL);

INSERT INTO Kit
(KitID, _NAME, isKit_Finished, hasKit_Tray, hasKit_Design)
VALUES(65, 'kit_a4b3c2d1', 'false', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_3_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(66, 'part_b_3_ir', 'b3_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(426, 'x_axis_kit_a4b4c2_b_2_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(427, 'x_axis_kit_a2b3c5_a_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_11_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(428, 'part_b_11_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(428, 'part_b_11_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(428, 'part_b_11_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(429, 'part_b_7_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(429, 'part_b_7_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(429, 'part_b_7_pose');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(430, 'x_axis_kit_a2b3c3d1e1_b_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(431, 'part_a_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(432, 'part_c_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(433, 'x_axis_kit_a4b3c3_b_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper', NULL);

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_Weight, hasEffector_MaximumLoadWeight, hadByEndEffector_Robot)
VALUES(67, 'tray_gripper', 'large single cup vacuum effector', 0.040000, 0.500000, NULL);

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(67, 'tray_gripper', 0.040000, 0.100000);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(67, 'tray_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(434, 'empty_kit_tray_box_point_ir', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_a_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(435, 'z_axis_kit_a4b4c2_a_4_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(436, 'work_table_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(437, 'x_axis_kit_a2b3c3d1e1_b_3_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray_5_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(438, 'shape_kit_tray_5_ir', 'Shape of KitTray 5');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(438, 'shape_kit_tray_5_ir', 'USARSim', 'KitTray5', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(439, 'part_b_2_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_c_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(440, 'part_ref_and_pose_kit_a4b4c2_c_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(441, 'part_b_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(441, 'part_b_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(441, 'part_b_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(442, 'kit_tray_2_point_ir', -0.5, 1.000000, 0.2000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(443, 'part_b_4_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_work_table');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(444, 'shape_work_table', 'Shape of the work table');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(444, 'shape_work_table');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(444, 'shape_work_table', 0.800000, 'true', 0.500000, 1.600000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(68, 'part_b_1', 'b1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(445, 'kit_tray_1_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(69, 'part_b_2', 'b2', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_5', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(70, 'part_b_5', 'b5', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_6', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(71, 'part_b_6', 'b6', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(72, 'part_b_3', 'b3', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(73, 'part_b_4', 'b4', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(446, 'empty_kit_tray_supply_point_ir', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_box_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(447, 'shape_kit_box_ir', 'Shape of boxes to hold kits and kit trays used for Intention Recognition');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(447, 'shape_kit_box_ir');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(447, 'shape_kit_box_ir', 0.500000, 'false', 0.800000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_8_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(448, 'part_a_8_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_7', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(74, 'part_b_7', 'b7', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_8', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(75, 'part_b_8', 'b8', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(449, 'part_b_3_point_ir', 0.342500, -0.330600, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(450, 'part_gripper_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_a_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(451, 'part_ref_and_pose_kit_a4b3c3_a_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_5_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(76, 'part_d_5_ir', 'd5_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(452, 'z_axis_kit_a4b4c2_c_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_8_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(453, 'part_a_8_point_ir', 0.215500, -0.216000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(454, 'part_c_8_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(455, 'tray_gripper_holder_point', -0.250000, 0.000000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_5_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(456, 'part_a_5_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(457, 'part_c_tray_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(457, 'part_c_tray_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(457, 'part_c_tray_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(458, 'z_axis_kit_a2b3c3d1e1_c_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(459, 'empty_kit_tray_box_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(460, 'x_axis_kit_a4b3c2d1_c_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b4c2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(461, 'kit_a4b4c2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(461, 'kit_a4b4c2_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(461, 'kit_a4b4c2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_b_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(462, 'part_ref_and_pose_kit_a2b3c3d1e1_b_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(463, 'empty_kit_tray_supply_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(77, 'finished_kit_box', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(464, 'kit_a4b3c3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_6_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(78, 'part_e_6_ir', 'e6_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(465, 'x_axis_kit_a4b4c2_c_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_11_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(466, 'part_a_11_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(466, 'part_a_11_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(466, 'part_a_11_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(467, 'part_c_8_point', -0.330000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_9_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(468, 'part_d_9_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(468, 'part_d_9_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(468, 'part_d_9_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_b_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(469, 'part_ref_and_pose_kit_a2b3c5_b_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(470, 'part_c_5_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(470, 'part_c_5_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(470, 'part_c_5_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(471, 'part_b_7_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(471, 'part_b_7_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(471, 'part_b_7_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(472, 'part_a_1_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(472, 'part_a_1_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(472, 'part_a_1_pose_ir');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_receiver', NULL);

INSERT INTO LargeBoxWithKits
(LargeBoxWithKitsID, _NAME, hasLargeBoxWithKits_Capacity, hasLargeBoxWithKits_LargeContainer, hasLargeBoxWithKits_KitDesign)
VALUES(79, 'finished_kit_receiver', 12, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_a_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(473, 'x_axis_kit_a4b3c2d1_a_4_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(474, 'shape_kit_tray', 'Shape of KitTrays');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(474, 'shape_kit_tray', 'USARSim', 'WCKitTraySmall', 'USARPhysObj');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(80, 'part_b_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(475, 'part_b_4_point_ir', 0.469500, -0.330600, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_1_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(476, 'part_e_1_point_ir', 0.165600, -0.330600, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_18_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(477, 'part_a_18_point_ir', 0.723500, -0.089000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(478, 'part_b_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(479, 'kit_tray_3_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_InternalShape, hasSolidObject_PrimaryLocation)
VALUES('work_table_1', NULL, NULL);

INSERT INTO WorkTable
(WorkTableID, _NAME)
VALUES(81, 'work_table_1');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(480, 'z_axis_kit_a4b4c2_a_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_6_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(481, 'part_a_6_point_ir', 0.723500, -0.343000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(482, 'part_b_3_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(482, 'part_b_3_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(482, 'part_b_3_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_b_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(483, 'part_ref_and_pose_kit_a2b3c5_b_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_a_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(484, 'point_kit_a4b4c2_a_1_ir', 0.495700, 0.419400, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_b_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(485, 'point_kit_a4b4c2_b_3_ir', 0.127400, 0.089370, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_c_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(486, 'point_kit_a4b3c3_c_2_ir', 0.330200, 0.330600, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_parts_tray_c_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(487, 'ext_shape_parts_tray_c_ir', 'Shape of PartsTray_C_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(487, 'ext_shape_parts_tray_c_ir', 'USARSim', 'PartTrayC', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(488, 'kit_tray_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_5_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(489, 'part_e_5_point_ir', 0.445000, -0.127400, 0.027500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_3_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(82, 'part_c_3_ir', 'c3_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_18_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(490, 'part_a_18_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(491, 'part_b_5_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(491, 'part_b_5_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(491, 'part_b_5_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_2_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(492, 'part_d_2_point_ir', 0.445000, -0.343000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_6_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(493, 'part_a_6_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_d_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(494, 'z_axis_kit_a4b3c2d1_d_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray_1_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(495, 'shape_kit_tray_1_ir', 'Shape of KitTray 1');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(495, 'shape_kit_tray_1_ir', 'USARSim', 'KitTray1', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_c_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(496, 'part_ref_and_pose_kit_a2b3c5_c_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_c_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(497, 'part_ref_and_pose_kit_a4b3c3_c_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(498, 'part_c_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(498, 'part_c_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(498, 'part_c_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(499, 'x_axis_kit_a4b3c2d1_a_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_9_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(500, 'part_a_9_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(500, 'part_a_9_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(500, 'part_a_9_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_a_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(501, 'point_kit_a4b3c2d1_a_2_ir', 0.622200, 0.241200, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_b_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(502, 'point_kit_a4b3c3_b_2_ir', 0.419100, 0.127400, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_b_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(503, 'point_kit_a4b3c2d1_b_2_ir', 0.457100, 0.241200, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_c_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(504, 'part_ref_and_pose_kit_a2b1c1_c_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_b_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(505, 'shape_parts_tray_b_ir', 'Shape of PartsTrays for parts of type B, used for Intention Recognition');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(505, 'shape_parts_tray_b_ir');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(505, 'shape_parts_tray_b_ir', 0.457600, 'false', 0.025400, 0.812400);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(506, 'part_a_3_point', -0.159000, -0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_a_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(507, 'point_kit_a4b4c2_a_3_ir', 0.495700, 0.292400, 0.025400);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_a2b3c5', NULL);

INSERT INTO Kit
(KitID, _NAME, isKit_Finished, hasKit_Tray, hasKit_Design)
VALUES(83, 'kit_a2b3c5', 'false', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_1_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(84, 'part_e_1_ir', 'e1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(508, 'part_a_4_point_ir', 0.469500, -0.343000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(509, 'part_b_6_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a4b3c2d1_ir');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(510, 'kit_design_a4b3c2d1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(511, 'x_axis_kit_a4b3c2d1_b_3_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_b_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(512, 'part_ref_and_pose_kit_a4b3c3_b_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_4_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(513, 'kit_tray_4_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_a_4_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(514, 'point_kit_a4b3c3_a_4_ir', 0.673100, 0.241700, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_10_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(515, 'part_a_10_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(516, 'part_c_supply_point', -3.000000, 0.780000, 0.200000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(517, 'changing_station_base_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_5_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(518, 'part_d_5_point_ir', 0.445000, -0.216000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(519, 'x_axis_kit_a4b3c3_b_2_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_9_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(85, 'part_d_9_ir', 'd9_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(520, 'part_b_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(521, 'finished_kit_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(521, 'finished_kit_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(521, 'finished_kit_box_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_5_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(86, 'part_a_5_ir', 'a5_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_c_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(522, 'x_axis_kit_a2b3c3d1e1_c_3_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(523, 'finished_kit_box_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(523, 'finished_kit_box_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(523, 'finished_kit_box_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(524, 'part_c_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(524, 'part_c_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(524, 'part_c_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c3_b_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(525, 'part_ref_and_pose_kit_a4b3c3_b_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_5_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(526, 'part_d_5_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(526, 'part_d_5_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(526, 'part_d_5_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_c_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(527, 'point_kit_a2b3c5_c_1_ir', 0.380800, 0.330100, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(528, 'part_a_tray_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(529, 'x_axis_kit_a4b3c2d1_b_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(530, 'part_b_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_3_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(531, 'part_d_3_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(531, 'part_d_3_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(531, 'part_d_3_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_supply_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(532, 'part_d_supply_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_b_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(533, 'part_ref_and_pose_kit_a2b3c3d1e1_b_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(534, 'z_axis_kit_a2b3c3d1e1_b_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_b_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(535, 'point_kit_a2b3c3d1e1_b_3_ir', 0.825300, 0.127400, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(536, 'part_a_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(536, 'part_a_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(536, 'part_a_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_3_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(537, 'part_d_3_point_ir', 0.724400, -0.343000, 0.027500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_12_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(87, 'part_b_12_ir', 'b12_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(538, 'part_a_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_a_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(539, 'part_ref_and_pose_kit_a4b3c2d1_a_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(540, 'part_b_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b4c2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(541, 'kit_a4b4c2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_12_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(542, 'part_a_12_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(542, 'part_a_12_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(542, 'part_a_12_pose_ir');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kitting_workstation_1', NULL);

INSERT INTO KittingWorkstation
(KittingWorkstationID, _NAME, hasWorkstation_LengthUnit, hasWorkstation_AngleUnit, hasWorkstation_WeightUnit, hasWorkstation_ChangingStation, hasWorkstation_WorkTable, hasWorkstation_Robot)
VALUES(88, 'kitting_workstation_1', 'meter', 'degree', 'kilogram', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(543, 'x_axis_kit_a2b3c3d1e1_a_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_a_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(544, 'z_axis_kit_a4b3c3_a_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(545, 'empty_kit_tray_box_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_6_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(546, 'part_e_6_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(546, 'part_e_6_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(546, 'part_e_6_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_7_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(547, 'part_a_7_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(548, 'kit_a4b3c3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(548, 'kit_a4b3c3_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(548, 'kit_a4b3c3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(549, 'kit_tray_1_point', 0.050000, 0.750000, 0.200000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_tray_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(550, 'part_d_tray_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(551, 'part_a_supply_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(551, 'part_a_supply_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(551, 'part_a_supply_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_d_6_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(552, 'part_d_6_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(553, 'kit_tray_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_1_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(554, 'part_d_1_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_c_4_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(555, 'part_ref_and_pose_kit_a2b3c5_c_4_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_c_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(556, 'shape_part_c_ir', 'Shape of PartC_ir
');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(556, 'shape_part_c_ir', 'USARSim', 'BlockC', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_c_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(557, 'part_ref_and_pose_kit_a2b3c3d1e1_c_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(558, 'part_a_2_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(559, 'changing_station_point', 7.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(560, 'part_a_supply_point', -2.850000, 1.550000, 0.200000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_1_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(89, 'part_c_1_ir', 'c1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(561, 'kit_tray_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(561, 'kit_tray_2_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(561, 'kit_tray_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(562, 'part_c_6_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(563, 'part_b_6_point_ir', 0.723500, -0.330600, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_13_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(564, 'part_a_13_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(565, 'part_c_1_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(565, 'part_c_1_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(565, 'part_c_1_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_e_1_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(566, 'part_e_1_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c3_c_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(567, 'point_kit_a4b3c3_c_3_ir', 0.127000, 0.127400, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('robot_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(568, 'robot_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(568, 'robot_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(568, 'robot_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(569, 'part_c_tray_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_5_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(90, 'part_c_5_ir', 'c5_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(570, 'z_axis_kit_a4b3c3_b_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_11_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(571, 'part_a_11_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_6_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(572, 'part_d_6_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(572, 'part_d_6_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(572, 'part_d_6_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_a_4_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(573, 'part_ref_and_pose_kit_a4b4c2_a_4_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_10_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(574, 'part_b_10_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_e_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(575, 'point_kit_a2b3c3d1e1_e_1_ir', 0.126800, 0.292500, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_b_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(576, 'x_axis_kit_a4b4c2_b_4_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(577, 'tray_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(577, 'tray_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(577, 'tray_gripper_holder_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_a_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(578, 'part_ref_and_pose_kit_a2b3c3d1e1_a_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gripper', NULL);

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_Weight, hasEffector_MaximumLoadWeight)
VALUES(91, 'part_gripper', 'small single cup vacuum effector', 0.010000, 0.400000);

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(91, 'part_gripper', 0.020000, 0.025000);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(91, 'part_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_15_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(579, 'part_a_15_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(580, 'x_axis_kit_a4b4c2_a_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_InternalShape, hasSolidObject_PrimaryLocation)
VALUES('changing_station_base', NULL, NULL);

INSERT INTO MechanicalComponent
(MechanicalComponentID, _NAME)
VALUES(92, 'changing_station_base');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_15_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(581, 'part_a_15_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_d_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(582, 'z_axis_kit_a2b3c3d1e1_d_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_b_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(583, 'point_kit_a2b3c3d1e1_b_2_ir', 0.698300, 0.127400, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_b_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(584, 'part_ref_and_pose_kit_a4b4c2_b_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c3d1e1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(585, 'kit_a2b3c3d1e1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_a_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(586, 'stock_keeping_unit_part_a_ir', 'SKU for Part A_ir', 0.180000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(586, 91);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(587, 'part_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(587, 'part_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(587, 'part_gripper_holder_pose');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_a_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(588, 'z_axis_kit_a2b3c3d1e1_a_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_15_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(589, 'part_a_15_point_ir', 0.342500, -0.089000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_5_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(590, 'kit_tray_5_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_a_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(591, 'z_axis_kit_a4b3c2d1_a_4_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_3_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(592, 'part_e_3_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_parts_tray_d_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(593, 'ext_shape_parts_tray_d_ir', 'Shape of PartsTray_D_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(593, 'ext_shape_parts_tray_d_ir', 'USARSim', 'PartTrayD', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray_4_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(594, 'stock_keeping_unit_kit_tray_4_ir', 'SKU for KitTray 4', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(594, 91);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_supply_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(595, 'part_c_supply_point_ir', -3.400000, 0.320000, 0.200000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(596, 'part_a_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(596, 'part_a_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(596, 'part_a_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(597, 'part_b_tray_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_9_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(598, 'part_b_9_point_ir', 0.342500, -0.127400, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(599, 'kit_tray_2_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(599, 'kit_tray_2_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(599, 'kit_tray_2_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(600, 'part_c_tray_point_ir', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_supply_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(601, 'part_a_supply_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(602, 'part_a_1_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_tray_ir', NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SerialNumber, hasPartsTray_Sku)
VALUES(93, 'part_e_tray_ir', 10, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_a_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(603, 'shape_parts_tray_a_ir', 'Shape of PartsTrays for parts of type A, used for Intention Recognition');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(603, 'shape_parts_tray_a_ir');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(603, 'shape_parts_tray_a_ir', 0.431900, 'false', 0.025400, 0.812400);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_b_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(604, 'part_ref_and_pose_kit_a4b3c2d1_b_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(605, 'part_b_supply_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(606, 'finished_kit_box_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_box');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(607, 'stock_keeping_unit_kit_box', 'SKU for Boxes for Kits and KitTrays', 1.200000, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_d_supply_ir', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(94, 'part_d_supply_ir', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(608, 'part_b_4_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_supply_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(609, 'part_e_supply_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(609, 'part_e_supply_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(609, 'part_e_supply_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_b_4_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(610, 'point_kit_a4b4c2_b_4_ir', 0.330600, 0.089370, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_b_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(611, 'point_kit_a4b4c2_b_1_ir', 0.127400, 0.216400, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_d_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(612, 'x_axis_kit_a2b3c3d1e1_d_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(613, 'part_a_4_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_box');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(614, 'shape_kit_box', 'Shape of boxes to hold kits and kit trays');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(614, 'shape_kit_box');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(614, 'shape_kit_box', 0.700000, 'false', 0.800000, 0.900000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_5_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(95, 'part_b_5_ir', 'b5_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_5_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(615, 'part_d_5_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_12_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(616, 'part_a_12_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(617, 'part_a_1_point_ir', 0.088500, -0.343000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_10_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(618, 'part_b_10_point_ir', 0.469500, -0.127400, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_a');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(619, 'stock_keeping_unit_parts_tray_a', 'SKU for Part a PartsTray', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(619, 91);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(620, 'kit_tray_3_point_ir', -0.5, 1.000000, 0.2000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_c');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(621, 'stock_keeping_unit_parts_tray_c', 'SKU for Part c PartsTrays', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(621, 91);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(622, 'part_b_1_point', -0.080000, 0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_b');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(623, 'stock_keeping_unit_parts_tray_b', 'SKU for Part b PartsTrays', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(623, 91);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(624, 'part_b_8_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(624, 'part_b_8_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(624, 'part_b_8_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(625, 'part_b_7_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c3d1e1_a_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(626, 'part_ref_and_pose_kit_a2b3c3d1e1_a_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(627, 'changing_station_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_9_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(628, 'part_d_9_point_ir', 0.724400, -0.089000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(629, 'part_c_6_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_b_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(630, 'part_ref_and_pose_kit_a2b1c1_b_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(631, 'work_table_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(631, 'work_table_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(631, 'work_table_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_box_ir', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(96, 'empty_kit_tray_box_ir', 4, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_17_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(632, 'part_a_17_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_14_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(97, 'part_a_14_ir', 'a14_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_13_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(633, 'part_a_13_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_18_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(634, 'part_a_18_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(634, 'part_a_18_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(634, 'part_a_18_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(635, 'z_axis_kit_a4b3c2d1_c_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_12_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(636, 'part_a_12_point_ir', 0.723500, -0.216000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_2_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(637, 'part_d_2_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(638, 'z_axis_kit_a2b3c5_a_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(639, 'z_axis_kit_a2b2c1_a_2', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(640, 'z_axis_kit_a4b3c3_a_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_supply', NULL);

INSERT INTO LargeBoxWithEmptyKitTrays
(LargeBoxWithEmptyKitTraysID, _NAME, hasLargeBoxWithEmptyKitTrays_LargeContainer)
VALUES(98, 'empty_kit_tray_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(641, 'x_axis_kit_a2b3c5_b_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(642, 'z_axis_kit_a2b3c3d1e1_b_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(643, 'part_b_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(644, 'part_a_tray_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(644, 'part_a_tray_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(644, 'part_a_tray_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_e_3_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(645, 'part_e_3_point_ir', 0.724400, -0.330600, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_a_4_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(646, 'part_ref_and_pose_kit_a4b3c2d1_a_4_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_2_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(99, 'part_a_2_ir', 'a2_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(647, 'part_a_2_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_c_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(648, 'x_axis_kit_a2b3c5_c_3_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_e_5_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(100, 'part_e_5_ir', 'e5_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(649, 'x_axis_kit_a2b3c5_b_3_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_3_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(650, 'part_d_3_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_a_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(651, 'part_ref_and_pose_kit_a2b3c5_a_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(652, 'part_c_8_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(652, 'part_c_8_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(652, 'part_c_8_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_1_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(101, 'part_b_1_ir', 'b1_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(653, 'part_c_4_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_supply_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(654, 'part_d_supply_point_ir', 0.400000, 1.700000, 0.200000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_d_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(655, 'part_ref_and_pose_kit_a4b3c2d1_d_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_c_3_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(656, 'part_ref_and_pose_kit_a2b3c5_c_3_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(657, 'x_axis_kit_a2b1c1_b_1', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_3', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(102, 'kit_tray_3', 3, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_2', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(103, 'kit_tray_2', 2, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(658, 'finished_kit_box_point', 0.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_1', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(104, 'kit_tray_1', 1, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_a_4_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(659, 'z_axis_kit_a4b3c3_a_4_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(660, 'z_axis_kit_a2b2c1_a_1', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_supply', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(105, 'part_a_supply', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_7_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(661, 'part_a_7_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(661, 'part_a_7_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(661, 'part_a_7_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(662, 'z_axis_kit_a4b4c2_c_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c2d1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(663, 'kit_a4b3c2d1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_1_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(664, 'part_d_1_point_ir', 0.165600, -0.343000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_6_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(665, 'part_a_6_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(665, 'part_a_6_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(665, 'part_a_6_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(666, 'part_b_4_point', 0.240000, 0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_b_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(667, 'point_kit_a4b3c2d1_b_1_ir', 0.457100, 0.365000, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(668, 'z_axis_kit_a4b4c2_b_3_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_b_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hasSku_Shape)
VALUES(669, 'stock_keeping_unit_part_b_ir', 'SKU for Part B_ir', 0.180000, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(669, 91);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a4b3c2d1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(670, 'kit_a4b3c2d1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(670, 'kit_a4b3c2d1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(670, 'kit_a4b3c2d1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(671, 'part_b_5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(672, 'part_c_5_point', 0.110000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(673, 'part_c_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_2_ir', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku)
VALUES(106, 'kit_tray_2_ir', 33, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_d_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(674, 'shape_parts_tray_d_ir', 'Shape of PartsTrays for parts of type D, used for Intention Recognition');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(674, 'shape_parts_tray_d_ir');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Top, hasBoxyShape_Height, hasBoxyShape_Length)
VALUES(674, 'shape_parts_tray_d_ir', 0.431900, 'false', 0.025400, 0.889500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_box_ir', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber, hasLargeContainer_Sku)
VALUES(107, 'finished_kit_box_ir', 5, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(675, 'part_c_4_point_ir', 0.736600, -0.330200, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(676, 'z_axis_kit_a4b3c3_b_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(677, 'part_b_7_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_16_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(678, 'part_a_16_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_a_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(679, 'x_axis_kit_a4b4c2_a_3_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_b_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(680, 'point_kit_a4b3c2d1_b_3_ir', 0.457100, 0.114200, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_17_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(681, 'part_a_17_point_ir', 0.596500, -0.089000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(682, 'z_axis_kit_a2b1c1_a_2', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(683, 'z_axis_kit_a2b1c1_a_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(684, 'z_axis_kit_a2b3c3d1e1_c_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_13_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(108, 'part_a_13_ir', 'a13_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_4_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(685, 'part_d_4_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(686, 'finished_kit_receiver_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(687, 'part_b_supply_point', 0.050000, 1.500000, 0.200000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(688, 'kit_tray_3_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(689, 'finished_kit_receiver_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_b_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(690, 'point_kit_a2b2c1_b_2', 0.171000, 0.215000, 0.080000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_e_tray_ir');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(691, 'stock_keeping_unit_parts_e_tray_ir', 'SKU for PartsTrays containing parts of type E, used for Intention Recognition', 0.200000, NULL, NULL);

INSERT INTO hasSku_EndEffectors
(StockKeepingUnitID, EndEffectorID)
VALUES(691, 91);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_b_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(692, 'point_kit_a2b2c1_b_1', 0.219000, -0.166000, 0.080000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_8_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(693, 'part_d_8_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(693, 'part_d_8_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(693, 'part_d_8_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c3d1e1_a_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(694, 'z_axis_kit_a2b3c3d1e1_a_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c3_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(695, 'z_axis_kit_a4b3c3_c_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_4_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(696, 'part_e_4_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(696, 'part_e_4_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(696, 'part_e_4_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c3d1e1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(697, 'kit_a2b3c3d1e1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(697, 'kit_a2b3c3d1e1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(697, 'kit_a2b3c3d1e1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_8_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(698, 'part_a_8_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(698, 'part_a_8_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(698, 'part_a_8_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(699, 'part_b_8_point', 0.240000, -0.120000, -0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(700, 'part_a_tray_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b3c5_a_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(701, 'part_ref_and_pose_kit_a2b3c5_a_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_3_ir', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_Sku)
VALUES(109, 'kit_tray_3_ir', 34, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_parts_tray_b_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(702, 'ext_shape_parts_tray_b_ir', 'Shape of PartsTray_B_ir');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(702, 'ext_shape_parts_tray_b_ir', 'USARSim', 'PartTrayB', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_a_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(703, 'x_axis_kit_a4b3c3_a_3_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(704, 'part_b_8_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(705, 'part_c_7_point', -0.110000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b3c2d1_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(706, 'z_axis_kit_a4b3c2d1_b_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c3d1e1_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(707, 'x_axis_kit_a2b3c3d1e1_b_2_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c2d1_d_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(708, 'x_axis_kit_a4b3c2d1_d_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_c_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(709, 'part_ref_and_pose_kit_a2b2c1_c_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper_holder', NULL);

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_ChangingStation)
VALUES(110, 'tray_gripper_holder', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(710, 'part_c_3_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b3c5_b_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(711, 'z_axis_kit_a2b3c5_b_2_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_c_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(712, 'point_kit_a2b3c5_c_2_ir', 0.584000, 0.330100, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_14_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(713, 'part_a_14_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(713, 'part_a_14_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(713, 'part_a_14_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_supply_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(714, 'part_b_supply_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_16_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(715, 'part_a_16_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_supply_ir', NULL);

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_Tray)
VALUES(111, 'part_a_supply_ir', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_a_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(716, 'part_ref_and_pose_kit_a2b2c1_a_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_a_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(717, 'part_ref_and_pose_kit_a2b2c1_a_2', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_point_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(718, 'finished_kit_box_point_ir', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_a_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(719, 'point_kit_a2b3c3d1e1_a_1_ir', 0.291900, 0.089300, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_12_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(720, 'part_b_12_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(721, 'part_b_tray_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(721, 'part_b_tray_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(721, 'part_b_tray_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(722, 'empty_kit_tray_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(723, 'part_a_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(724, 'part_c_3_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_5_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(725, 'kit_tray_5_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(725, 'kit_tray_5_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(725, 'kit_tray_5_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(726, 'part_b_2_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(727, 'part_b_5_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_c_5_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(728, 'point_kit_a2b3c5_c_5_ir', 0.584000, 0.126900, 0.025400);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_a4b4c2', NULL);

INSERT INTO Kit
(KitID, _NAME, isKit_Finished, hasKit_Tray, hasKit_Design)
VALUES(112, 'kit_a4b4c2', 'false', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(729, 'part_a_4_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b4c2_a_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(730, 'part_ref_and_pose_kit_a4b4c2_a_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a4b4c2_b_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(731, 'z_axis_kit_a4b4c2_b_1_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(732, 'part_a_1_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_a_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(733, 'point_kit_a4b4c2_a_2_ir', 0.622700, 0.419400, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_on_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(734, 'relative_location_on_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(734, 'relative_location_on_1', 'The tray_gripper is on robot_1');

INSERT INTO RelativeLocationOn
(RelativeLocationOnID, _NAME)
VALUES(734, 'relative_location_on_1');

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b3c5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(735, 'kit_a2b3c5_point', 0.100000, 0.200000, 0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(736, 'finished_kit_receiver_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b1c1');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_Workstation, hasKitDesign_KitTraySku)
VALUES(737, 'kit_design_a2b1c1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_a_1_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(738, 'part_ref_and_pose_kit_a4b3c2d1_a_1_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(739, 'empty_kit_tray_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(739, 'empty_kit_tray_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(739, 'empty_kit_tray_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_b_3_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(740, 'x_axis_kit_a4b4c2_b_3_ir', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_c_4_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(741, 'point_kit_a2b3c5_c_4_ir', 0.380800, 0.126900, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(742, 'finished_kit_receiver_point', 1.500000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_2_ir', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(113, 'part_b_2_ir', 'b2_ir', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(743, 'part_b_6_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_b_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(744, 'x_axis_kit_a2b2c1_b_2', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(745, 'x_axis_kit_a2b2c1_b_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a4b3c2d1_c_2_ir');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(746, 'part_ref_and_pose_kit_a4b3c2d1_c_2_ir', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(747, 'empty_kit_tray_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(747, 'empty_kit_tray_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(747, 'empty_kit_tray_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b3c2d1_c_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(748, 'point_kit_a4b3c2d1_c_1_ir', 0.253900, 0.330100, 0.025400);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('robot_1', NULL);

INSERT INTO Robot
(RobotID, _NAME, hasRobot_Description, hasRobot_MaximumLoadWeight)
VALUES(114, 'robot_1', 'this is the robot', 7.000000);

INSERT INTO hasRobot_WorkVolume
(RobotID, BoxVolumeID)
VALUES(114, 136);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(749, 'x_axis_kit_a4b3c3_c_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(750, 'part_c_5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(751, 'robot_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(115, 'part_a_1', 'a1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b3c5_c_1_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(752, 'x_axis_kit_a2b3c5_c_1_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(116, 'part_a_3', 'a3', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(117, 'part_a_2', 'a2', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(753, 'part_b_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_7_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(754, 'part_d_7_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(754, 'part_d_7_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(754, 'part_d_7_pose_ir');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsTrayWithParts, hasPart_Sku)
VALUES(118, 'part_a_4', 'a4', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a4b4c2_c_2_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(755, 'point_kit_a4b4c2_c_2_ir', 0.330600, 0.381300, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_supply_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(756, 'part_d_supply_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(756, 'part_d_supply_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(756, 'part_d_supply_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_b_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(757, 'point_kit_a2b1c1_b_1', 0.200000, 0.500000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_7_z_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(758, 'part_d_7_z_axis_ir', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(759, 'empty_kit_tray_box_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(759, 'empty_kit_tray_box_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(759, 'empty_kit_tray_box_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c5_b_1_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(760, 'point_kit_a2b3c5_b_1_ir', 0.126800, 0.368200, 0.025400);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('changing_station_1', NULL);

INSERT INTO EndEffectorChangingStation
(EndEffectorChangingStationID, _NAME, hasChangingStation_Base)
VALUES(119, 'changing_station_1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_tray_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(761, 'part_e_tray_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray_3_ir');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(762, 'shape_kit_tray_3_ir', 'Shape of KitTray 3');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelTypeName, hasExternalShape_ModelName, hasExternalShape_ModelFileName)
VALUES(762, 'shape_kit_tray_3_ir', 'USARSim', 'KitTray3', 'USARPhysObj');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_pose_ir');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(763, 'part_a_2_pose_ir', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(763, 'part_a_2_pose_ir', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(763, 'part_a_2_pose_ir');

INSERT INTO DataThing
(_NAME)
VALUES('work_table_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(764, 'work_table_point', 3.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(765, 'part_c_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_Point, hasPoseLocation_ZAxis, hasPoseLocation_XAxis)
VALUES(765, 'part_c_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(765, 'part_c_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(766, 'z_axis_kit_a2b2c1_c_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b3c3d1e1_c_3_ir');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(767, 'point_kit_a2b3c3d1e1_c_3_ir', 0.457000, 0.127400, 0.025400);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b3c3_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(768, 'x_axis_kit_a4b3c3_c_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a4b4c2_c_2_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(769, 'x_axis_kit_a4b4c2_c_2_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_e_2_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(770, 'part_e_2_x_axis_ir', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_d_7_x_axis_ir');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(771, 'part_d_7_x_axis_ir', 0.000000, 0.000000, 1.000000);



UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_d_6_pose_ir' WHERE _NAME = 'part_d_6_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_d_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_d_ir' WHERE _NAME = 'part_d_6_ir';

UPDATE StockKeepingUnit
 SET  hadBySku_Workstation='kitting_workstation_1', hasSku_Shape= 'shape_kit_tray_5_ir' WHERE _NAME = 'stock_keeping_unit_kit_tray_5_ir';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_parts_a_tray_ir', hasPartRefAndPose_ZAxis= 'z_axis_kit_a4b3c2d1_a_3_ir', hadByPartRefAndPose_KitDesign= 'kit_design_a4b3c2d1_ir', hasPartRefAndPose_Point= 'point_kit_a4b3c2d1_a_3_ir', hasPartRefAndPose_XAxis= 'x_axis_kit_a4b3c2d1_a_3_ir' WHERE _NAME = 'part_ref_and_pose_kit_a4b3c2d1_a_3_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_d_4_pose_ir' WHERE _NAME = 'part_d_4_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_d_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_d_ir' WHERE _NAME = 'part_d_4_ir';

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

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply_ir' WHERE _NAME = 'part_c_8_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_8_point_ir', hasPoseLocation_ZAxis= 'part_c_8_z_axis_ir', hasPoseLocation_XAxis= 'part_c_8_x_axis_ir' WHERE _NAME = 'part_c_8_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply_ir' WHERE _NAME = 'part_c_6_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_6_point_ir', hasPoseLocation_ZAxis= 'part_c_6_z_axis_ir', hasPoseLocation_XAxis= 'part_c_6_x_axis_ir' WHERE _NAME = 'part_c_6_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_4_pose_ir' WHERE _NAME = 'part_a_4_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_4_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_tray_pose_ir' WHERE _NAME = 'part_a_tray_ir';

UPDATE PartsTray
 SET  hasPartsTray_Sku='stock_keeping_unit_parts_a_tray_ir' WHERE _NAME = 'part_a_tray_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_4_pose_ir' WHERE _NAME = 'kit_tray_4_ir';

UPDATE KitTray
 SET  hasKitTray_Sku='stock_keeping_unit_kit_tray_4_ir' WHERE _NAME = 'kit_tray_4_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply_ir' WHERE _NAME = 'part_c_7_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_7_point_ir', hasPoseLocation_ZAxis= 'part_c_7_z_axis_ir', hasPoseLocation_XAxis= 'part_c_7_x_axis_ir' WHERE _NAME = 'part_c_7_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_10_pose_ir' WHERE _NAME = 'part_b_10_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_b_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_b_ir' WHERE _NAME = 'part_b_10_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_10_pose_ir' WHERE _NAME = 'part_a_10_ir';

UPDATE Part
 SET  hadByPart_PartsTrayWithParts='part_a_supply_ir', hasPart_Sku= 'stock_keeping_unit_part_a_ir' WHERE _NAME = 'part_a_10_ir';

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
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply_ir' WHERE _NAME = 'empty_kit_tray_box_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='empty_kit_tray_box_point_ir', hasPoseLocation_ZAxis= 'empty_kit_tray_box_z_axis_ir', hasPoseLocation_XAxis= 'empty_kit_tray_box_x_axis_ir' WHERE _NAME = 'empty_kit_tray_box_pose_ir';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='changing_station_pose' WHERE _NAME = 'changing_station_1';

UPDATE EndEffectorChangingStation
 SET  hasChangingStation_Base='changing_station_base' WHERE _NAME = 'changing_station_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_supply_ir' WHERE _NAME = 'part_a_2_pose_ir';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_a_2_point_ir', hasPoseLocation_ZAxis= 'part_a_2_z_axis_ir', hasPoseLocation_XAxis= 'part_a_2_x_axis_ir' WHERE _NAME = 'part_a_2_pose_ir';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_supply' WHERE _NAME = 'part_c_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_Point='part_c_1_point', hasPoseLocation_ZAxis= 'part_c_1_z_axis', hasPoseLocation_XAxis= 'part_c_1_x_axis' WHERE _NAME = 'part_c_1_pose';