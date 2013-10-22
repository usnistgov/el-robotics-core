INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b2c1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(1, 'kit_a2b2c1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_grasp_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(2, 'part_a_grasp_point', 0.000000, 0.000000, 0.021900);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(3, 'part_b_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(3, 'part_b_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(3, 'part_b_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(4, 'part_c_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(5, 'part_gear_1_point', 0.8000, -0.0000, -0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(6, 'robot_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(6, 'robot_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(6, 'robot_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(7, 'part_gear_shaft_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(8, 'part_gear_shaft_2_point', 0.6, -2.0000, -0.05000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_tray', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(1, 'part_b_tray', NULL);

INSERT INTO PartsVessel
(PartsVesselID, _NAME, hasPartsVessel_PartQuantity, hasPartsVessel_SerialNumber, hasPartsVessel_PartSku)
VALUES(1, 'part_b_tray', 8, 7, NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME)
VALUES(1, 'part_b_tray');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_a');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation)
VALUES(9, 'stock_keeping_unit_part_a', 'SKU for Part A', 0.180000, NULL);

INSERT INTO hasStockKeepingUnit_EndEffector
(StockKeepingUnitID, EndEffectorID)
VALUES(9, 1);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(10, 'part_b_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(10, 'part_b_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(10, 'part_b_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(11, 'empty_kit_tray_supply_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(12, 'finished_kit_receiver_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(12, 'finished_kit_receiver_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(12, 'finished_kit_receiver_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(13, 'part_b_5_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(13, 'part_b_5_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(13, 'part_b_5_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(14, 'part_b_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(14, 'part_b_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(14, 'part_b_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('work_table_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(15, 'work_table_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_grasp_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(16, 'part_a_grasp_z_axis', -1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(17, 'tray_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(17, 'tray_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(17, 'tray_gripper_holder_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gripper_holder', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(2, 'part_gripper_holder');

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_EndEffectorChangingStation, hasEndEffectorHolder_EndEffector)
VALUES(2, 'part_gripper_holder', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(18, 'part_c_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(18, 'part_c_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(18, 'part_c_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(19, 'part_c_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_holder', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(3, 'part_gear_holder', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber)
VALUES(3, 'part_gear_holder', 'gearholder');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(20, 'changing_station_base_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(21, 'part_gear_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_grasp_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(22, 'part_b_grasp_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gripper', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(4, 'part_gripper');

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_Weight, hasEndEffector_MaximumLoadWeight)
VALUES(4, 'part_gripper', 'small single cup vacuum effector', 0.010000, 0.400000);

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(4, 'part_gripper', 0.020000, 0.025000);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(4, 'part_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_tray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation)
VALUES(23, 'stock_keeping_unit_kit_tray', 'SKU for KitTrays', 0.200000, NULL);

INSERT INTO hasStockKeepingUnit_EndEffector
(StockKeepingUnitID, EndEffectorID)
VALUES(23, 4);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(24, 'part_gear_5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('changing_station_base', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME, hasNoSkuObject_InternalShape)
VALUES(5, 'changing_station_base', NULL);

INSERT INTO MechanicalComponent
(MechanicalComponentID, _NAME)
VALUES(5, 'changing_station_base');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_5', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(6, 'part_c_5', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(6, 'part_c_5', 'c5', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_a_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(25, 'point_kit_a2b1c1_a_2', 0.400000, 0.300000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_4', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(7, 'part_c_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(7, 'part_c_4', 'c4', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_a_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(26, 'point_kit_a2b1c1_a_1', 0.200000, 0.300000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_3', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(8, 'part_c_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(8, 'part_c_3', 'c3', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_2', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(9, 'part_c_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(9, 'part_c_2', 'c2', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_1', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(10, 'part_c_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(10, 'part_c_1', 'c1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(27, 'kit_tray_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_grasp_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(28, 'part_b_grasp_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hadByGraspPose_ShapeDesign, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(28, 'part_b_grasp_pose', NULL, NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(28, 'part_b_grasp_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(29, 'part_a_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(29, 'part_a_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(29, 'part_a_tray_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_8', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(11, 'part_c_8', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(11, 'part_c_8', 'c8', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(30, 'part_c_6_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_7', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(12, 'part_c_7', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(12, 'part_c_7', 'c7', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_6', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(13, 'part_c_6', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(13, 'part_c_6', 'c6', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_base_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(31, 'part_gear_base_point', 1.0000, -2.0000, -0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(32, 'part_gripper_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(32, 'part_gripper_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(32, 'part_gripper_holder_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(33, 'part_gripper_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(34, 'part_gripper_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(34, 'part_gripper_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(34, 'part_gripper_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_grasp_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(35, 'part_a_grasp_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hadByGraspPose_ShapeDesign, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(35, 'part_a_grasp_pose', NULL, NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(35, 'part_a_grasp_pose');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_gear_base');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight)
VALUES(36, 'stock_keeping_unit_part_gear_base', 'SKU for gear base', 1.200000);

INSERT INTO hasStockKeepingUnit_EndEffector
(StockKeepingUnitID, EndEffectorID)
VALUES(36, 4);

INSERT INTO DataThing
(_NAME)
VALUES('trash_table_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(37, 'trash_table_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(37, 'trash_table_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(37, 'trash_table_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(38, 'part_gear_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_grasp_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(39, 'part_b_grasp_z_axis', -1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(40, 'part_gear_3_point', 1.2000, -0.0000, -0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b2c1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(41, 'kit_a2b2c1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(42, 'part_a_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(43, 'part_a_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(43, 'part_a_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(43, 'part_a_1_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_boss', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(14, 'part_gear_boss', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber)
VALUES(14, 'part_gear_boss', 'gearboss');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(44, 'part_b_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(45, 'part_c_6_point', 0.330000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(46, 'part_b_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_tray', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(15, 'part_a_tray', NULL);

INSERT INTO PartsVessel
(PartsVesselID, _NAME, hasPartsVessel_PartQuantity, hasPartsVessel_SerialNumber, hasPartsVessel_PartSku)
VALUES(15, 'part_a_tray', 4, 6, NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME)
VALUES(15, 'part_a_tray');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(47, 'part_gear_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(47, 'part_gear_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(47, 'part_gear_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(48, 'part_gear_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(48, 'part_gear_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(48, 'part_gear_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(49, 'part_b_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(50, 'part_gear_5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_c');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation)
VALUES(51, 'stock_keeping_unit_part_c', 'SKU for Part C', 0.180000, NULL);

INSERT INTO hasStockKeepingUnit_EndEffector
(StockKeepingUnitID, EndEffectorID)
VALUES(51, 4);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_b');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation)
VALUES(52, 'stock_keeping_unit_part_b', 'SKU for Part B', 0.180000, NULL);

INSERT INTO hasStockKeepingUnit_EndEffector
(StockKeepingUnitID, EndEffectorID)
VALUES(52, 4);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(53, 'finished_kit_box_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_kit_box');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation, hasStockKeepingUnit_InternalShape)
VALUES(54, 'stock_keeping_unit_kit_box', 'SKU for Boxes for Kits and KitTrays', 1.200000, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(55, 'z_axis_kit_a2b1c1_c_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_gear_boss');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(56, 'ext_shape_gear_boss', 'Shape of the gear boss');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFormatName, hasExternalShape_ModelName, hasExternalShape_ModelFileName, hadByExternalShape_StockKeepingUnit)
VALUES(56, 'ext_shape_gear_boss', 'USARSim', 'gear_boss', 'USARPhysObj', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(57, 'part_gear_shaft_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(58, 'part_gear_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_boss_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(59, 'part_gear_boss_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(60, 'part_b_7_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(60, 'part_b_7_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(60, 'part_b_7_pose');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_gear_holder');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight)
VALUES(61, 'stock_keeping_unit_part_gear_holder', 'SKU for gear holder', 1.200000);

INSERT INTO hasStockKeepingUnit_EndEffector
(StockKeepingUnitID, EndEffectorID)
VALUES(61, 4);

INSERT INTO DataThing
(_NAME)
VALUES('point_min');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(62, 'point_min', -1.000000, -1.000000, -2.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(63, 'tray_gripper_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(64, 'part_a_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_a');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(65, 'shape_part_a', 'Shape of PartA');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFormatName, hasExternalShape_ModelName, hasExternalShape_ModelFileName, hadByExternalShape_StockKeepingUnit)
VALUES(65, 'shape_part_a', 'USARSim', 'PartA', 'USARPhysObj', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_5_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(66, 'part_gear_5_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(66, 'part_gear_5_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(66, 'part_gear_5_pose');

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_b');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(67, 'shape_part_b', 'Shape of PartB');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFormatName, hasExternalShape_ModelName, hasExternalShape_ModelFileName, hadByExternalShape_StockKeepingUnit)
VALUES(67, 'shape_part_b', 'USARSim', 'PartB', 'USARPhysObj', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_part_c');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(68, 'shape_part_c', 'Shape of PartC');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFormatName, hasExternalShape_ModelName, hasExternalShape_ModelFileName, hadByExternalShape_StockKeepingUnit)
VALUES(68, 'shape_part_c', 'USARSim', 'PartC', 'USARPhysObj', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(69, 'part_c_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(70, 'part_a_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(70, 'part_a_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(70, 'part_a_2_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(16, 'tray_gripper');

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Description, hasEndEffector_Weight, hasEndEffector_MaximumLoadWeight, hadByEndEffector_Robot)
VALUES(16, 'tray_gripper', 'large single cup vacuum effector', 0.040000, 0.500000, NULL);

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(16, 'tray_gripper', 0.040000, 0.100000);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(16, 'tray_gripper');

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_box');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(71, 'shape_kit_box', 'Shape of boxes to hold kits and kit trays');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(71, 'shape_kit_box');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length, hasBoxyShape_HasTop)
VALUES(71, 'shape_kit_box', 0.700000, 0.800000, 0.900000, false);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(72, 'part_c_3_point', -0.110000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(73, 'part_gear_shaft_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(74, 'part_gripper_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_a_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(75, 'part_ref_and_pose_kit_a2b1c1_a_2', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_a');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation)
VALUES(76, 'stock_keeping_unit_parts_tray_a', 'SKU for Part a PartsTray', 0.200000, NULL);

INSERT INTO hasStockKeepingUnit_EndEffector
(StockKeepingUnitID, EndEffectorID)
VALUES(76, 16);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(77, 'part_a_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_c');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation)
VALUES(78, 'stock_keeping_unit_parts_tray_c', 'SKU for Part c PartsTrays', 0.200000, NULL);

INSERT INTO hasStockKeepingUnit_EndEffector
(StockKeepingUnitID, EndEffectorID)
VALUES(78, 16);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(79, 'part_b_1_point', -0.080000, 0.120000, 0.05);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_parts_tray_b');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight, hadBySku_KittingWorkstation)
VALUES(80, 'stock_keeping_unit_parts_tray_b', 'SKU for Part b PartsTrays', 0.200000, NULL);

INSERT INTO hasStockKeepingUnit_EndEffector
(StockKeepingUnitID, EndEffectorID)
VALUES(80, 16);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(81, 'work_table_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(82, 'part_b_7_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(83, 'part_b_6_point', -0.240000, -0.120000, 0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(84, 'part_b_8_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(84, 'part_b_8_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(84, 'part_b_8_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_a_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(85, 'part_ref_and_pose_kit_a2b1c1_a_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(86, 'changing_station_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(87, 'part_c_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(88, 'part_b_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(88, 'part_b_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(88, 'part_b_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_b_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(89, 'part_ref_and_pose_kit_a2b1c1_b_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(90, 'work_table_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(90, 'work_table_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(90, 'work_table_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(91, 'part_gear_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_changing_station_base');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(92, 'shape_changing_station_base', 'Shape of base of changing station');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(92, 'shape_changing_station_base');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length, hasBoxyShape_HasTop)
VALUES(92, 'shape_changing_station_base', 0.100000, 1.000000, 1.000000, true);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(93, 'part_gear_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(94, 'part_gear_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(95, 'part_gear_5_point', 1.000, -0.2000, -0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(96, 'part_a_1_point', 0.159000, 0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_a_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(97, 'point_kit_a2b2c1_a_2', -0.159000, 0.149000, 0.036000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_base_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(98, 'part_gear_base_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(99, 'part_c_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_a_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(100, 'point_kit_a2b2c1_a_1', -0.159000, -0.145000, 0.036000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_work_table');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(101, 'shape_work_table', 'Shape of the work table');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(101, 'shape_work_table');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length, hasBoxyShape_HasTop)
VALUES(101, 'shape_work_table', 2.880000, 1.088000, 3.968000, true);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_1', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(17, 'part_b_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(17, 'part_b_1', 'b1', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_2', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(18, 'part_b_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(18, 'part_b_2', 'b2', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_5', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(19, 'part_b_5', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(19, 'part_b_5', 'b5', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_6', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(20, 'part_b_6', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(20, 'part_b_6', 'b6', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_3', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(21, 'part_b_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(21, 'part_b_3', 'b3', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_4', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(22, 'part_b_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(22, 'part_b_4', 'b4', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_7', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(23, 'part_b_7', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(23, 'part_b_7', 'b7', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(102, 'kit_tray_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(103, 'part_b_6_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(103, 'part_b_6_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(103, 'part_b_6_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_b_8', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(24, 'part_b_8', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(24, 'part_b_8', 'b8', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(104, 'changing_station_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(105, 'kit_tray_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(106, 'empty_kit_tray_supply_point', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(107, 'part_gear_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(108, 'z_axis_kit_a2b2c1_a_2', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_4', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(25, 'part_gear_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber)
VALUES(25, 'part_gear_4', 'gear4');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(109, 'part_gear_holder_point', 0.60000, -2.3000, -0.05000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_5', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(26, 'part_gear_5', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber)
VALUES(26, 'part_gear_5', 'gear5');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_supply', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(27, 'empty_kit_tray_supply');

INSERT INTO LargeBoxWithEmptyKitTrays
(LargeBoxWithEmptyKitTraysID, _NAME, hasLargeBoxWithEmptyKitTrays_LargeContainer)
VALUES(27, 'empty_kit_tray_supply', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_2', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(28, 'part_gear_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber)
VALUES(28, 'part_gear_2', 'gear2');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_3', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(29, 'part_gear_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber)
VALUES(29, 'part_gear_3', 'gear3');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(110, 'kit_tray_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_c_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(111, 'point_kit_a2b2c1_c_1', 0.060000, 0.090000, 0.045000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(112, 'part_c_7_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(112, 'part_c_7_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(112, 'part_c_7_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(113, 'part_gripper_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(114, 'part_gripper_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_base', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(30, 'part_gear_base', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber)
VALUES(30, 'part_gear_base', 'gearbase');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(115, 'part_b_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_1', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(31, 'part_gear_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber)
VALUES(31, 'part_gear_1', 'gear1');

INSERT INTO DataThing
(_NAME)
VALUES('trash_table_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(116, 'trash_table_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(117, 'part_b_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(117, 'part_b_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(117, 'part_b_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(118, 'part_c_1_point', 0.110000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(119, 'part_gear_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('robot_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(120, 'robot_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(121, 'part_c_8_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(122, 'tray_gripper_holder_point', -0.250000, 0.000000, -0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(123, 'x_axis_kit_a2b1c1_c_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_boss_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(124, 'part_gear_boss_point', 1.20000, -0.20000, -0.05000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_c_tray', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(32, 'part_c_tray', NULL);

INSERT INTO PartsVessel
(PartsVesselID, _NAME, hasPartsVessel_PartQuantity, hasPartsVessel_SerialNumber, hasPartsVessel_PartSku)
VALUES(32, 'part_c_tray', 8, 8, NULL);

INSERT INTO PartsTray
(PartsTrayID, _NAME)
VALUES(32, 'part_c_tray');

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_gear_shaft');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight)
VALUES(125, 'stock_keeping_unit_part_gear_shaft', 'SKU for gear shaft', 1.200000);

INSERT INTO hasStockKeepingUnit_EndEffector
(StockKeepingUnitID, EndEffectorID)
VALUES(125, 16);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(126, 'part_c_8_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(126, 'part_c_8_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(126, 'part_c_8_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_box', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(33, 'finished_kit_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber)
VALUES(33, 'finished_kit_box', 5);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(127, 'part_c_5_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(127, 'part_c_5_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(127, 'part_c_5_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(128, 'kit_tray_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(128, 'kit_tray_3_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(128, 'kit_tray_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(129, 'part_b_2_point', -0.240000, 0.120000, 0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(130, 'part_gripper_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(131, 'x_axis_kit_a2b1c1_b_1', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_3', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(34, 'kit_tray_3', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(34, 'kit_tray_3', 3, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_2', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(35, 'kit_tray_2', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(35, 'kit_tray_2', 2, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(132, 'finished_kit_box_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(133, 'part_a_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kit_tray_1', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(36, 'kit_tray_1', NULL);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(36, 'kit_tray_1', 1, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(134, 'part_c_8_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('empty_kit_tray_box', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(37, 'empty_kit_tray_box', NULL);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SerialNumber)
VALUES(37, 'empty_kit_tray_box', 4);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_base_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(135, 'part_gear_base_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(136, 'z_axis_kit_a2b2c1_a_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(137, 'part_c_4_point', -0.330000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(138, 'x_axis_kit_a2b1c1_a_2', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b1c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(139, 'x_axis_kit_a2b1c1_a_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_8_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(140, 'part_c_8_point', -0.330000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(141, 'part_b_6_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_boss_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(142, 'part_gear_boss_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(142, 'part_gear_boss_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(142, 'part_gear_boss_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(143, 'part_a_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(144, 'part_b_4_point', 0.240000, 0.120000, 0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_boss_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(145, 'part_gear_boss_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('trash_table_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(146, 'trash_table_point', 1.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(147, 'part_gear_shaft_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(148, 'part_gear_shaft_1_point', 0.6000, -1.90000, -0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_4_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(149, 'part_gear_shaft_4_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(150, 'part_gear_shaft_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(150, 'part_gear_shaft_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(150, 'part_gear_shaft_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(151, 'part_gear_shaft_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(151, 'part_gear_shaft_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(151, 'part_gear_shaft_4_pose');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('finished_kit_receiver', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(38, 'finished_kit_receiver');

INSERT INTO LargeBoxWithKits
(LargeBoxWithKitsID, _NAME, hasLargeBoxWithKits_Capacity, hasLargeBoxWithKits_LargeContainer, hasLargeBoxWithKits_KitDesign)
VALUES(38, 'finished_kit_receiver', 12, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_kit_tray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(152, 'shape_kit_tray', 'Shape of KitTrays');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFormatName, hasExternalShape_ModelName, hasExternalShape_ModelFileName, hadByExternalShape_StockKeepingUnit)
VALUES(152, 'shape_kit_tray', 'USARSim', 'WCKitTraySmall', 'USARPhysObj', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(153, 'part_b_8_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(154, 'part_c_5_point', 0.110000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(155, 'part_b_5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(156, 'part_c_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(157, 'part_c_tray_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(157, 'part_c_tray_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(157, 'part_c_tray_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(158, 'part_c_7_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(159, 'part_c_tray_point', -3.000000, -0.780000, -0.280000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(160, 'kit_tray_3_point', 2.000000, 0.000000, -0.225000);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_gear_holder');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(161, 'ext_shape_gear_holder', 'Shape of the gear holder');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFormatName, hasExternalShape_ModelName, hasExternalShape_ModelFileName, hadByExternalShape_StockKeepingUnit)
VALUES(161, 'ext_shape_gear_holder', 'USARSim', 'gear_holder', 'USARPhysObj', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_grasp_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(162, 'part_c_grasp_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hadByGraspPose_ShapeDesign, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(162, 'part_c_grasp_pose', NULL, NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(162, 'part_c_grasp_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(163, 'part_c_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(164, 'kit_tray_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(164, 'kit_tray_1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(164, 'kit_tray_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('tray_gripper_holder_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(165, 'tray_gripper_holder_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(166, 'part_c_7_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(167, 'part_b_7_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_a');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(168, 'shape_parts_tray_a', 'Shape of PartsTray_A');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFormatName, hasExternalShape_ModelName, hasExternalShape_ModelFileName, hadByExternalShape_StockKeepingUnit)
VALUES(168, 'shape_parts_tray_a', 'USARSim', 'PartATray', 'USARPhysObj', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(169, 'part_b_3_point', 0.080000, 0.120000, 0.05);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_b');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(170, 'shape_parts_tray_b', 'Shape of PartsTray_B');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFormatName, hasExternalShape_ModelName, hasExternalShape_ModelFileName, hadByExternalShape_StockKeepingUnit)
VALUES(170, 'shape_parts_tray_b', 'USARSim', 'PartBTray', 'USARPhysObj', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_parts_tray_c');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(171, 'shape_parts_tray_c', 'Shape of PartsTray_C');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFormatName, hasExternalShape_ModelName, hasExternalShape_ModelFileName, hadByExternalShape_StockKeepingUnit)
VALUES(171, 'shape_parts_tray_c', 'USARSim', 'PartCTray', 'USARPhysObj', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(172, 'part_a_4_point', -0.159000, 0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_grasp_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(173, 'part_c_grasp_point', 0.000000, 0.000000, 0.030500);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(174, 'z_axis_kit_a2b1c1_a_2', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('work_table_1', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME, hasNoSkuObject_InternalShape)
VALUES(39, 'work_table_1', NULL);

INSERT INTO WorkTable
(WorkTableID, _NAME)
VALUES(39, 'work_table_1');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(175, 'part_gear_shaft_4_point', 0.6000, -2.20000, -0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(176, 'z_axis_kit_a2b1c1_a_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_in_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(177, 'relative_location_in_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(177, 'relative_location_in_1', 'The  KittingWorkstation is in kitting_workstation_1');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME)
VALUES(177, 'relative_location_in_1');

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(178, 'finished_kit_receiver_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_shaft_1', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(40, 'part_gear_shaft_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber)
VALUES(40, 'part_gear_shaft_1', 'gear1');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_shaft_2', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(41, 'part_gear_shaft_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber)
VALUES(41, 'part_gear_shaft_2', 'gear2');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_b_2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(179, 'point_kit_a2b2c1_b_2', 0.171000, -0.215000, 0.080000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b2c1_b_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(180, 'point_kit_a2b2c1_b_1', 0.219000, 0.166000, 0.080000);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_gear_boss');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight)
VALUES(181, 'stock_keeping_unit_part_gear_boss', 'SKU for gear boss', 1.200000);

INSERT INTO hasStockKeepingUnit_EndEffector
(StockKeepingUnitID, EndEffectorID)
VALUES(181, 16);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_shaft_3', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(42, 'part_gear_shaft_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber)
VALUES(42, 'part_gear_shaft_3', 'gear3');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_gear_shaft_4', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(43, 'part_gear_shaft_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber)
VALUES(43, 'part_gear_shaft_4', 'gear4');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(182, 'kit_tray_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(183, 'part_gear_shaft_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(183, 'part_gear_shaft_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(183, 'part_gear_shaft_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_c_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(184, 'point_kit_a2b1c1_c_1', 0.400000, 0.500000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(185, 'part_b_8_point', 0.240000, -0.120000, 0.05);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(186, 'part_b_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(187, 'part_c_2_point', 0.330000, 0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(188, 'part_b_5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(189, 'kit_tray_2_point', 0.75, 0.000000, -0.155000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gripper_holder_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(190, 'part_gripper_holder_point', 0.250000, 0.000000, -0.500000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_grasp_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(191, 'part_a_grasp_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b2c1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(192, 'kit_a2b2c1_point', 0.0500000, -0.7500000, -0.2800000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_8_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(193, 'part_b_8_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('trash_table', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME, hasNoSkuObject_InternalShape)
VALUES(44, 'trash_table', NULL);

INSERT INTO WorkTable
(WorkTableID, _NAME)
VALUES(44, 'trash_table');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_7_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(194, 'part_c_7_point', -0.110000, -0.216000, 0.035000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b2c1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(195, 'kit_a2b2c1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(195, 'kit_a2b2c1_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(195, 'kit_a2b2c1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('point_max');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(196, 'point_max', 1.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(197, 'part_c_6_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(198, 'part_c_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(198, 'part_c_2_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(198, 'part_c_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(199, 'part_b_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_c_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(200, 'part_ref_and_pose_kit_a2b2c1_c_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('tray_gripper_holder', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(45, 'tray_gripper_holder');

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_EndEffectorChangingStation)
VALUES(45, 'tray_gripper_holder', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_6_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(201, 'part_c_6_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(201, 'part_c_6_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(201, 'part_c_6_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b1c1_c_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(202, 'part_ref_and_pose_kit_a2b1c1_c_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(203, 'part_a_3_point', -0.159000, -0.159000, 0.027500);

INSERT INTO DataThing
(_NAME)
VALUES('box_volume_1');

INSERT INTO BoxVolume
(BoxVolumeID, _NAME, hadByWorkVolume_Robot, hasBoxVolume_MaximumPoint, hasBoxVolume_MinimumPoint)
VALUES(204, 'box_volume_1', NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(205, 'part_a_4_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(205, 'part_a_4_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(205, 'part_a_4_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(206, 'part_b_tray_point', 0.050000, -1.500000, -0.280000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(207, 'changing_station_base_point', 0.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(208, 'part_c_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(208, 'part_c_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(208, 'part_c_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(209, 'empty_kit_tray_box_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(210, 'changing_station_base_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(210, 'changing_station_base_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(210, 'changing_station_base_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(211, 'part_c_5_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_6_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(212, 'part_b_6_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_a_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(213, 'part_ref_and_pose_kit_a2b2c1_a_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_gear');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(214, 'ext_shape_gear', 'Shape of the gear');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFormatName, hasExternalShape_ModelName, hasExternalShape_ModelFileName, hadByExternalShape_StockKeepingUnit)
VALUES(214, 'ext_shape_gear', 'USARSim', 'gear', 'USARPhysObj', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_a_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(215, 'part_ref_and_pose_kit_a2b2c1_a_2', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(216, 'part_a_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(216, 'part_a_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(216, 'part_a_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_a_4_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(217, 'part_a_4_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(218, 'part_a_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_base_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(219, 'changing_station_base_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(220, 'part_gear_shaft_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(221, 'part_b_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(222, 'finished_kit_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(222, 'finished_kit_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(222, 'finished_kit_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(223, 'finished_kit_receiver_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(224, 'part_gear_shaft_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(224, 'part_gear_shaft_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(224, 'part_gear_shaft_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(225, 'empty_kit_tray_supply_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_3_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(226, 'part_a_3_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_holder_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(227, 'part_gear_holder_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(227, 'part_gear_holder_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(227, 'part_gear_holder_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(228, 'part_gear_shaft_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_7_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(229, 'part_b_7_point', 0.080000, -0.120000, 0.05);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_gear_base');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(230, 'ext_shape_gear_base', 'Shape of the gear base');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFormatName, hasExternalShape_ModelName, hasExternalShape_ModelFileName, hadByExternalShape_StockKeepingUnit)
VALUES(230, 'ext_shape_gear_base', 'USARSim', 'gear_base', 'USARPhysObj', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('stock_keeping_unit_part_gear');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasStockKeepingUnit_Description, hasStockKeepingUnit_Weight)
VALUES(231, 'stock_keeping_unit_part_gear', 'SKU for gears', 1.200000);

INSERT INTO hasStockKeepingUnit_EndEffector
(StockKeepingUnitID, EndEffectorID)
VALUES(231, 16);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_tray_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(232, 'part_a_tray_point', -2.850000, -1.550000, -0.300000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_3_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(233, 'part_gear_shaft_3_point', 0.6000, -2.1000, -0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_shaft_2_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(234, 'part_gear_shaft_2_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_holder_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(235, 'part_gear_holder_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(236, 'part_b_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('ext_shape_gear_shaft');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(237, 'ext_shape_gear_shaft', 'Shape of the gear shaft');

INSERT INTO ExternalShape
(ExternalShapeID, _NAME, hasExternalShape_ModelFormatName, hasExternalShape_ModelName, hasExternalShape_ModelFileName, hadByExternalShape_StockKeepingUnit)
VALUES(237, 'ext_shape_gear_shaft', 'USARSim', 'gear_shaft', 'USARPhysObj', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(238, 'changing_station_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(238, 'changing_station_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(238, 'changing_station_pose');

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b1c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(239, 'z_axis_kit_a2b1c1_b_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('relative_location_on_1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(240, 'relative_location_on_1', NULL);

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME, hasRelativeLocation_Description)
VALUES(240, 'relative_location_on_1', 'The tray_gripper is on robot_1');

INSERT INTO RelativeLocationOn
(RelativeLocationOnID, _NAME)
VALUES(240, 'relative_location_on_1');

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b1c1');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_KittingWorkstation, hasKitDesign_KitTraySku)
VALUES(241, 'kit_design_a2b1c1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_a_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(242, 'x_axis_kit_a2b2c1_a_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_design_a2b2c1');

INSERT INTO KitDesign
(KitDesignID, _NAME, hadByKitDesign_KittingWorkstation, hasKitDesign_KitTraySku)
VALUES(243, 'kit_design_a2b2c1', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_a_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(244, 'x_axis_kit_a2b2c1_a_2', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(245, 'empty_kit_tray_box_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(245, 'empty_kit_tray_box_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(245, 'empty_kit_tray_box_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_3_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(246, 'part_c_3_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_grasp_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(247, 'part_b_grasp_point', 0.000000, 0.000000, 0.064700);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_receiver_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(248, 'finished_kit_receiver_point', 1.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(249, 'part_a_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(250, 'x_axis_kit_a2b2c1_c_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(251, 'part_c_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(252, 'part_b_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_1_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(253, 'part_a_1_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_b_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(254, 'x_axis_kit_a2b2c1_b_2', 0.000000, 1.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('x_axis_kit_a2b2c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(255, 'x_axis_kit_a2b2c1_b_1', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_base_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(256, 'part_gear_base_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(256, 'part_gear_base_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(256, 'part_gear_base_pose');

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_supply_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(257, 'empty_kit_tray_supply_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(257, 'empty_kit_tray_supply_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(257, 'empty_kit_tray_supply_pose');

INSERT INTO DataThing
(_NAME)
VALUES('robot_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(258, 'robot_point', 3.000000, 0.000000, -2.000000);

INSERT INTO DataThing
(_NAME)
VALUES('finished_kit_box_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(259, 'finished_kit_box_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('robot_1', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(46, 'robot_1');

INSERT INTO Robot
(RobotID, _NAME, hasRobot_Description, hasRobot_MaximumLoadWeight)
VALUES(46, 'robot_1', 'this is the robot', 7.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_5_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(260, 'part_c_5_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('kitting_workstation_1', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(47, 'kitting_workstation_1');

INSERT INTO KittingWorkstation
(KittingWorkstationID, _NAME, hasKittingWorkstation_LengthUnit, hasKittingWorkstation_WeightUnit, hasKittingWorkstation_AngleUnit, hasKittingWorkstation_ChangingStation, hasKittingWorkstation_Robot)
VALUES(47, 'kitting_workstation_1', 'meter', 'kilogram', 'degree', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b2c1_slot_4');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(261, 'kit_a2b2c1_slot_4', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b2c1_slot_5');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(262, 'kit_a2b2c1_slot_5', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('robot_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(263, 'robot_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(264, 'empty_kit_tray_box_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b2c1_slot_2');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(265, 'kit_a2b2c1_slot_2', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b2c1_slot_3');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(266, 'kit_a2b2c1_slot_3', NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('kit_a2b2c1_slot_1');

INSERT INTO Slot
(SlotID, _NAME, hadBySlot_Kit, hasSlot_PartRefAndPose)
VALUES(267, 'kit_a2b2c1_slot_1', NULL, NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_1', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(48, 'part_a_1', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(48, 'part_a_1', 'a1', NULL);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_3', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(49, 'part_a_3', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(49, 'part_a_3', 'a3', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_a_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(268, 'part_a_2_point', 0.159000, -0.159000, 0.027500);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_2', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(50, 'part_a_2', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(50, 'part_a_2', 'a2', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_tray_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(269, 'part_b_tray_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('part_a_4', NULL);

INSERT INTO SkuObject
(SkuObjectID, _NAME, hasSkuObject_Sku)
VALUES(51, 'part_a_4', NULL);

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hadByPart_PartsVessel)
VALUES(51, 'part_a_4', 'a4', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_4_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(270, 'part_gear_4_point', 0.8000, -0.20000, -0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('point_kit_a2b1c1_b_1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(271, 'point_kit_a2b1c1_b_1', 0.200000, 0.500000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_tray_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(272, 'part_c_tray_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_2_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(273, 'part_gear_2_point', 1, -0.0000, -0.05000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_3_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(274, 'part_gear_3_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(274, 'part_gear_3_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(274, 'part_gear_3_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_c_grasp_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(275, 'part_c_grasp_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(276, 'kit_tray_1_point', 0.050000, -0.750000, -0.280000);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PrimaryLocation)
VALUES('changing_station_1', NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(52, 'changing_station_1');

INSERT INTO EndEffectorChangingStation
(EndEffectorChangingStationID, _NAME, hasEndEffectorChangingStation_Base)
VALUES(52, 'changing_station_1', NULL);

INSERT INTO DataThing
(_NAME)
VALUES('shape_trash_table');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(277, 'shape_trash_table', 'Shape of the trash table');

INSERT INTO InternalShape
(InternalShapeID, _NAME)
VALUES(277, 'shape_trash_table');

INSERT INTO BoxyShape
(BoxyShapeID, _NAME, hasBoxyShape_Width, hasBoxyShape_Height, hasBoxyShape_Length, hasBoxyShape_HasTop)
VALUES(277, 'shape_trash_table', 0.800000, 0.500000, 1.600000, true);

INSERT INTO DataThing
(_NAME)
VALUES('trash_table_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(278, 'trash_table_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(279, 'part_gear_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(279, 'part_gear_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(279, 'part_gear_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_1_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(280, 'kit_tray_1_z_axis', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('empty_kit_tray_box_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(281, 'empty_kit_tray_box_point', 0.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_b_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(282, 'z_axis_kit_a2b2c1_b_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('work_table_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(283, 'work_table_point', 1.468000, -1.108000, -1.344000);

INSERT INTO SolidObject
(_NAME, hadByObjectOnTable_WorkTable, hasSolidObject_PrimaryLocation)
VALUES('kit_a2b2c1', NULL, NULL);

INSERT INTO NoSkuObject
(NoSkuObjectID, _NAME)
VALUES(53, 'kit_a2b2c1');

INSERT INTO Kit
(KitID, _NAME, hasKit_Finished, hasKit_KitTray, hasKit_Design)
VALUES(53, 'kit_a2b2c1', false, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_b_2');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(284, 'z_axis_kit_a2b2c1_b_2', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_1_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(285, 'part_c_1_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(285, 'part_c_1_pose', NULL, NULL, NULL);

INSERT INTO PoseLocationIn
(PoseLocationInID, _NAME)
VALUES(285, 'part_c_1_pose');

INSERT INTO DataThing
(_NAME)
VALUES('changing_station_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(286, 'changing_station_point', 7.500000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('z_axis_kit_a2b2c1_c_1');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(287, 'z_axis_kit_a2b2c1_c_1', 1.000000, 0.000000, 0.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_b_5_point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(288, 'part_b_5_point', -0.080000, -0.120000, 0.05);

INSERT INTO DataThing
(_NAME)
VALUES('kit_tray_2_pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(289, 'kit_tray_2_pose', NULL);

INSERT INTO PoseLocation
(PoseLocationID, _NAME, hasPoseLocation_XAxis, hasPoseLocation_ZAxis, hasPoseLocation_Point)
VALUES(289, 'kit_tray_2_pose', NULL, NULL, NULL);

INSERT INTO PoseOnlyLocation
(PoseOnlyLocationID, _NAME)
VALUES(289, 'kit_tray_2_pose');

INSERT INTO DataThing
(_NAME)
VALUES('part_gear_2_x_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(290, 'part_gear_2_x_axis', 0.000000, 0.000000, 1.000000);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_b_2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(291, 'part_ref_and_pose_kit_a2b2c1_b_2', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_ref_and_pose_kit_a2b2c1_b_1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Sku, hasPartRefAndPose_ZAxis, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Point, hasPartRefAndPose_XAxis)
VALUES(292, 'part_ref_and_pose_kit_a2b2c1_b_1', NULL, NULL, NULL, NULL, NULL);

INSERT INTO DataThing
(_NAME)
VALUES('part_c_grasp_z_axis');

INSERT INTO Vector
(VectorID, _NAME, hasVector_K, hasVector_J, hasVector_I)
VALUES(293, 'part_c_grasp_z_axis', -1.000000, 0.000000, 0.000000);



UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_b_2_x_axis', hasPoseLocation_ZAxis= 'part_b_2_z_axis', hasPoseLocation_Point= 'part_b_2_point' WHERE _NAME = 'part_b_2_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'robot_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='robot_x_axis', hasPoseLocation_ZAxis= 'robot_z_axis', hasPoseLocation_Point= 'robot_point' WHERE _NAME = 'robot_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_tray_pose' WHERE _NAME = 'part_b_tray';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_parts_tray_b' WHERE _NAME = 'part_b_tray';

UPDATE PartsVessel
 SET  hasPartsVessel_PartSku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_tray';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1' WHERE _NAME = 'stock_keeping_unit_part_a';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_b_3_x_axis', hasPoseLocation_ZAxis= 'part_b_3_z_axis', hasPoseLocation_Point= 'part_b_3_point' WHERE _NAME = 'part_b_3_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'finished_kit_receiver_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='finished_kit_receiver_x_axis', hasPoseLocation_ZAxis= 'finished_kit_receiver_z_axis', hasPoseLocation_Point= 'finished_kit_receiver_point' WHERE _NAME = 'finished_kit_receiver_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_5_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_b_5_x_axis', hasPoseLocation_ZAxis= 'part_b_5_z_axis', hasPoseLocation_Point= 'part_b_5_point' WHERE _NAME = 'part_b_5_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_b_4_x_axis', hasPoseLocation_ZAxis= 'part_b_4_z_axis', hasPoseLocation_Point= 'part_b_4_point' WHERE _NAME = 'part_b_4_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'tray_gripper_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='tray_gripper_holder_x_axis', hasPoseLocation_ZAxis= 'tray_gripper_holder_z_axis', hasPoseLocation_Point= 'tray_gripper_holder_point' WHERE _NAME = 'tray_gripper_holder_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gripper_holder_pose' WHERE _NAME = 'part_gripper_holder';

UPDATE EndEffectorHolder
 SET  hadByEndEffectorHolder_EndEffectorChangingStation='changing_station_1', hasEndEffectorHolder_EndEffector= 'part_gripper' WHERE _NAME = 'part_gripper_holder';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_c_4_x_axis', hasPoseLocation_ZAxis= 'part_c_4_z_axis', hasPoseLocation_Point= 'part_c_4_point' WHERE _NAME = 'part_c_4_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_holder_pose' WHERE _NAME = 'part_gear_holder';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_gear_holder' WHERE _NAME = 'part_gear_holder';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gripper_pose' WHERE _NAME = 'part_gripper';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1' WHERE _NAME = 'stock_keeping_unit_kit_tray';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='changing_station_base_pose' WHERE _NAME = 'changing_station_base';

UPDATE NoSkuObject
 SET  hasNoSkuObject_InternalShape='shape_changing_station_base' WHERE _NAME = 'changing_station_base';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_5_pose' WHERE _NAME = 'part_c_5';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_5';

UPDATE Part
 SET  hadByPart_PartsVessel='part_c_tray' WHERE _NAME = 'part_c_5';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_4_pose' WHERE _NAME = 'part_c_4';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_4';

UPDATE Part
 SET  hadByPart_PartsVessel='part_c_tray' WHERE _NAME = 'part_c_4';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_3_pose' WHERE _NAME = 'part_c_3';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_3';

UPDATE Part
 SET  hadByPart_PartsVessel='part_c_tray' WHERE _NAME = 'part_c_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_2_pose' WHERE _NAME = 'part_c_2';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_2';

UPDATE Part
 SET  hadByPart_PartsVessel='part_c_tray' WHERE _NAME = 'part_c_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_1_pose' WHERE _NAME = 'part_c_1';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_1';

UPDATE Part
 SET  hadByPart_PartsVessel='part_c_tray' WHERE _NAME = 'part_c_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_b_grasp_pose';

UPDATE PoseLocation
 SET  hadByGraspPose_ShapeDesign='shape_part_b', hasPoseLocation_XAxis= 'part_b_grasp_x_axis', hasPoseLocation_ZAxis= 'part_b_grasp_z_axis', hasPoseLocation_Point= 'part_b_grasp_point' WHERE _NAME = 'part_b_grasp_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_a_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_a_tray_x_axis', hasPoseLocation_ZAxis= 'part_a_tray_z_axis', hasPoseLocation_Point= 'part_a_tray_point' WHERE _NAME = 'part_a_tray_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_8_pose' WHERE _NAME = 'part_c_8';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_8';

UPDATE Part
 SET  hadByPart_PartsVessel='part_c_tray' WHERE _NAME = 'part_c_8';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_7_pose' WHERE _NAME = 'part_c_7';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_7';

UPDATE Part
 SET  hadByPart_PartsVessel='part_c_tray' WHERE _NAME = 'part_c_7';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_6_pose' WHERE _NAME = 'part_c_6';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_6';

UPDATE Part
 SET  hadByPart_PartsVessel='part_c_tray' WHERE _NAME = 'part_c_6';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'part_gripper_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gripper_holder_x_axis', hasPoseLocation_ZAxis= 'part_gripper_holder_z_axis', hasPoseLocation_Point= 'part_gripper_holder_point' WHERE _NAME = 'part_gripper_holder_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_gripper_holder' WHERE _NAME = 'part_gripper_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gripper_x_axis', hasPoseLocation_ZAxis= 'part_gripper_z_axis', hasPoseLocation_Point= 'part_gripper_point' WHERE _NAME = 'part_gripper_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_a_grasp_pose';

UPDATE PoseLocation
 SET  hadByGraspPose_ShapeDesign='shape_part_a', hasPoseLocation_XAxis= 'part_a_grasp_x_axis', hasPoseLocation_ZAxis= 'part_a_grasp_z_axis', hasPoseLocation_Point= 'part_a_grasp_point' WHERE _NAME = 'part_a_grasp_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'trash_table_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='trash_table_x_axis', hasPoseLocation_ZAxis= 'trash_table_z_axis', hasPoseLocation_Point= 'trash_table_point' WHERE _NAME = 'trash_table_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_tray' WHERE _NAME = 'part_a_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_a_1_x_axis', hasPoseLocation_ZAxis= 'part_a_1_z_axis', hasPoseLocation_Point= 'part_a_1_point' WHERE _NAME = 'part_a_1_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_boss_pose' WHERE _NAME = 'part_gear_boss';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_gear_boss' WHERE _NAME = 'part_gear_boss';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_tray_pose' WHERE _NAME = 'part_a_tray';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_parts_tray_a' WHERE _NAME = 'part_a_tray';

UPDATE PartsVessel
 SET  hasPartsVessel_PartSku='stock_keeping_unit_part_a' WHERE _NAME = 'part_a_tray';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gear_4_x_axis', hasPoseLocation_ZAxis= 'part_gear_4_z_axis', hasPoseLocation_Point= 'part_gear_4_point' WHERE _NAME = 'part_gear_4_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gear_2_x_axis', hasPoseLocation_ZAxis= 'part_gear_2_z_axis', hasPoseLocation_Point= 'part_gear_2_point' WHERE _NAME = 'part_gear_2_pose';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1' WHERE _NAME = 'stock_keeping_unit_part_c';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1' WHERE _NAME = 'stock_keeping_unit_part_b';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1', hasStockKeepingUnit_InternalShape= 'shape_kit_box' WHERE _NAME = 'stock_keeping_unit_kit_box';

UPDATE ExternalShape
 SET  hadByExternalShape_StockKeepingUnit='stock_keeping_unit_part_gear_boss' WHERE _NAME = 'ext_shape_gear_boss';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_7_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_b_7_x_axis', hasPoseLocation_ZAxis= 'part_b_7_z_axis', hasPoseLocation_Point= 'part_b_7_point' WHERE _NAME = 'part_b_7_pose';

UPDATE ExternalShape
 SET  hadByExternalShape_StockKeepingUnit='stock_keeping_unit_part_a' WHERE _NAME = 'shape_part_a';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_5_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gear_5_x_axis', hasPoseLocation_ZAxis= 'part_gear_5_z_axis', hasPoseLocation_Point= 'part_gear_5_point' WHERE _NAME = 'part_gear_5_pose';

UPDATE ExternalShape
 SET  hadByExternalShape_StockKeepingUnit='stock_keeping_unit_part_b' WHERE _NAME = 'shape_part_b';

UPDATE ExternalShape
 SET  hadByExternalShape_StockKeepingUnit='stock_keeping_unit_part_c' WHERE _NAME = 'shape_part_c';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_tray' WHERE _NAME = 'part_a_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_a_2_x_axis', hasPoseLocation_ZAxis= 'part_a_2_z_axis', hasPoseLocation_Point= 'part_a_2_point' WHERE _NAME = 'part_a_2_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='relative_location_on_1' WHERE _NAME = 'tray_gripper';

UPDATE EndEffector
 SET  hadByEndEffector_Robot='robot_1' WHERE _NAME = 'tray_gripper';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_a_2', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_a_2', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_a_2' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_a_2';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1' WHERE _NAME = 'stock_keeping_unit_parts_tray_a';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1' WHERE _NAME = 'stock_keeping_unit_parts_tray_c';

UPDATE StockKeepingUnit
 SET  hadBySku_KittingWorkstation='kitting_workstation_1' WHERE _NAME = 'stock_keeping_unit_parts_tray_b';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_8_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_b_8_x_axis', hasPoseLocation_ZAxis= 'part_b_8_z_axis', hasPoseLocation_Point= 'part_b_8_point' WHERE _NAME = 'part_b_8_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_a_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_a_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_a_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_a_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_b_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_b_tray_x_axis', hasPoseLocation_ZAxis= 'part_b_tray_z_axis', hasPoseLocation_Point= 'part_b_tray_point' WHERE _NAME = 'part_b_tray_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_b', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_b_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_b_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_b_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_b_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'work_table_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='work_table_x_axis', hasPoseLocation_ZAxis= 'work_table_z_axis', hasPoseLocation_Point= 'work_table_point' WHERE _NAME = 'work_table_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_1_pose' WHERE _NAME = 'part_b_1';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_1';

UPDATE Part
 SET  hadByPart_PartsVessel='part_b_tray' WHERE _NAME = 'part_b_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_2_pose' WHERE _NAME = 'part_b_2';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_2';

UPDATE Part
 SET  hadByPart_PartsVessel='part_b_tray' WHERE _NAME = 'part_b_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_5_pose' WHERE _NAME = 'part_b_5';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_5';

UPDATE Part
 SET  hadByPart_PartsVessel='part_b_tray' WHERE _NAME = 'part_b_5';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_6_pose' WHERE _NAME = 'part_b_6';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_6';

UPDATE Part
 SET  hadByPart_PartsVessel='part_b_tray' WHERE _NAME = 'part_b_6';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_3_pose' WHERE _NAME = 'part_b_3';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_3';

UPDATE Part
 SET  hadByPart_PartsVessel='part_b_tray' WHERE _NAME = 'part_b_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_4_pose' WHERE _NAME = 'part_b_4';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_4';

UPDATE Part
 SET  hadByPart_PartsVessel='part_b_tray' WHERE _NAME = 'part_b_4';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_7_pose' WHERE _NAME = 'part_b_7';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_7';

UPDATE Part
 SET  hadByPart_PartsVessel='part_b_tray' WHERE _NAME = 'part_b_7';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_6_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_b_6_x_axis', hasPoseLocation_ZAxis= 'part_b_6_z_axis', hasPoseLocation_Point= 'part_b_6_point' WHERE _NAME = 'part_b_6_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_b_8_pose' WHERE _NAME = 'part_b_8';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_b' WHERE _NAME = 'part_b_8';

UPDATE Part
 SET  hadByPart_PartsVessel='part_b_tray' WHERE _NAME = 'part_b_8';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_4_pose' WHERE _NAME = 'part_gear_4';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_gear' WHERE _NAME = 'part_gear_4';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_5_pose' WHERE _NAME = 'part_gear_5';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_gear' WHERE _NAME = 'part_gear_5';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_supply_pose' WHERE _NAME = 'empty_kit_tray_supply';

UPDATE LargeBoxWithEmptyKitTrays
 SET  hasLargeBoxWithEmptyKitTrays_LargeContainer='empty_kit_tray_box' WHERE _NAME = 'empty_kit_tray_supply';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_2_pose' WHERE _NAME = 'part_gear_2';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_gear' WHERE _NAME = 'part_gear_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_3_pose' WHERE _NAME = 'part_gear_3';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_gear' WHERE _NAME = 'part_gear_3';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_7_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_c_7_x_axis', hasPoseLocation_ZAxis= 'part_c_7_z_axis', hasPoseLocation_Point= 'part_c_7_point' WHERE _NAME = 'part_c_7_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_base_pose' WHERE _NAME = 'part_gear_base';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_gear_base' WHERE _NAME = 'part_gear_base';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_1_pose' WHERE _NAME = 'part_gear_1';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_gear' WHERE _NAME = 'part_gear_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_b_tray' WHERE _NAME = 'part_b_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_b_1_x_axis', hasPoseLocation_ZAxis= 'part_b_1_z_axis', hasPoseLocation_Point= 'part_b_1_point' WHERE _NAME = 'part_b_1_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_c_tray_pose' WHERE _NAME = 'part_c_tray';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_parts_tray_c' WHERE _NAME = 'part_c_tray';

UPDATE PartsVessel
 SET  hasPartsVessel_PartSku='stock_keeping_unit_part_c' WHERE _NAME = 'part_c_tray';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_8_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_c_8_x_axis', hasPoseLocation_ZAxis= 'part_c_8_z_axis', hasPoseLocation_Point= 'part_c_8_point' WHERE _NAME = 'part_c_8_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_box_pose' WHERE _NAME = 'finished_kit_box';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_kit_box' WHERE _NAME = 'finished_kit_box';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_5_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_c_5_x_axis', hasPoseLocation_ZAxis= 'part_c_5_z_axis', hasPoseLocation_Point= 'part_c_5_point' WHERE _NAME = 'part_c_5_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='kit_tray_3_x_axis', hasPoseLocation_ZAxis= 'kit_tray_3_z_axis', hasPoseLocation_Point= 'kit_tray_3_point' WHERE _NAME = 'kit_tray_3_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_3_pose' WHERE _NAME = 'kit_tray_3';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_tray_3';

UPDATE KitTray
 SET  hadByKitTray_LargeBoxWithEmptyKitTrays='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_2_pose' WHERE _NAME = 'kit_tray_2';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_tray_2';

UPDATE KitTray
 SET  hadByKitTray_LargeBoxWithEmptyKitTrays='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='kit_tray_1_pose' WHERE _NAME = 'kit_tray_1';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_tray_1';

UPDATE KitTray
 SET  hadByKitTray_LargeBoxWithEmptyKitTrays='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='empty_kit_tray_box_pose' WHERE _NAME = 'empty_kit_tray_box';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_kit_box' WHERE _NAME = 'empty_kit_tray_box';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_boss_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gear_boss_x_axis', hasPoseLocation_ZAxis= 'part_gear_boss_z_axis', hasPoseLocation_Point= 'part_gear_boss_point' WHERE _NAME = 'part_gear_boss_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_shaft_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gear_shaft_2_x_axis', hasPoseLocation_ZAxis= 'part_gear_shaft_2_z_axis', hasPoseLocation_Point= 'part_gear_shaft_2_point' WHERE _NAME = 'part_gear_shaft_2_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_shaft_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gear_shaft_4_x_axis', hasPoseLocation_ZAxis= 'part_gear_shaft_4_z_axis', hasPoseLocation_Point= 'part_gear_shaft_4_point' WHERE _NAME = 'part_gear_shaft_4_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='finished_kit_receiver_pose' WHERE _NAME = 'finished_kit_receiver';

UPDATE LargeBoxWithKits
 SET  hasLargeBoxWithKits_LargeContainer='finished_kit_box', hasLargeBoxWithKits_KitDesign= 'kit_design_a2b1c1' WHERE _NAME = 'finished_kit_receiver';

UPDATE ExternalShape
 SET  hadByExternalShape_StockKeepingUnit='stock_keeping_unit_kit_tray' WHERE _NAME = 'shape_kit_tray';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_c_tray_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_c_tray_x_axis', hasPoseLocation_ZAxis= 'part_c_tray_z_axis', hasPoseLocation_Point= 'part_c_tray_point' WHERE _NAME = 'part_c_tray_pose';

UPDATE ExternalShape
 SET  hadByExternalShape_StockKeepingUnit='stock_keeping_unit_part_gear_holder' WHERE _NAME = 'ext_shape_gear_holder';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_c_grasp_pose';

UPDATE PoseLocation
 SET  hadByGraspPose_ShapeDesign='shape_part_c', hasPoseLocation_XAxis= 'part_c_grasp_x_axis', hasPoseLocation_ZAxis= 'part_c_grasp_z_axis', hasPoseLocation_Point= 'part_c_grasp_point' WHERE _NAME = 'part_c_grasp_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='kit_tray_1_x_axis', hasPoseLocation_ZAxis= 'kit_tray_1_z_axis', hasPoseLocation_Point= 'kit_tray_1_point' WHERE _NAME = 'kit_tray_1_pose';

UPDATE ExternalShape
 SET  hadByExternalShape_StockKeepingUnit='stock_keeping_unit_parts_tray_a' WHERE _NAME = 'shape_parts_tray_a';

UPDATE ExternalShape
 SET  hadByExternalShape_StockKeepingUnit='stock_keeping_unit_parts_tray_b' WHERE _NAME = 'shape_parts_tray_b';

UPDATE ExternalShape
 SET  hadByExternalShape_StockKeepingUnit='stock_keeping_unit_parts_tray_c' WHERE _NAME = 'shape_parts_tray_c';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='work_table_pose' WHERE _NAME = 'work_table_1';

UPDATE NoSkuObject
 SET  hasNoSkuObject_InternalShape='shape_work_table' WHERE _NAME = 'work_table_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'relative_location_in_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_shaft_1_pose' WHERE _NAME = 'part_gear_shaft_1';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_gear_shaft' WHERE _NAME = 'part_gear_shaft_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_shaft_2_pose' WHERE _NAME = 'part_gear_shaft_2';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_gear_shaft' WHERE _NAME = 'part_gear_shaft_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_shaft_3_pose' WHERE _NAME = 'part_gear_shaft_3';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_gear_shaft' WHERE _NAME = 'part_gear_shaft_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_gear_shaft_4_pose' WHERE _NAME = 'part_gear_shaft_4';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_gear_shaft' WHERE _NAME = 'part_gear_shaft_4';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_shaft_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gear_shaft_3_x_axis', hasPoseLocation_ZAxis= 'part_gear_shaft_3_z_axis', hasPoseLocation_Point= 'part_gear_shaft_3_point' WHERE _NAME = 'part_gear_shaft_3_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='trash_table_pose' WHERE _NAME = 'trash_table';

UPDATE NoSkuObject
 SET  hasNoSkuObject_InternalShape='shape_trash_table' WHERE _NAME = 'trash_table';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='work_table_1' WHERE _NAME = 'kit_a2b2c1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='kit_a2b2c1_x_axis', hasPoseLocation_ZAxis= 'kit_a2b2c1_z_axis', hasPoseLocation_Point= 'kit_a2b2c1_point' WHERE _NAME = 'kit_a2b2c1_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_c_2_x_axis', hasPoseLocation_ZAxis= 'part_c_2_z_axis', hasPoseLocation_Point= 'part_c_2_point' WHERE _NAME = 'part_c_2_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_c', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_c_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_c_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_c_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_c_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='tray_gripper_holder_pose' WHERE _NAME = 'tray_gripper_holder';

UPDATE EndEffectorHolder
 SET  hadByEndEffectorHolder_EndEffectorChangingStation='changing_station_1' WHERE _NAME = 'tray_gripper_holder';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_6_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_c_6_x_axis', hasPoseLocation_ZAxis= 'part_c_6_z_axis', hasPoseLocation_Point= 'part_c_6_point' WHERE _NAME = 'part_c_6_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_c', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b1c1_c_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b1c1', hasPartRefAndPose_Point= 'point_kit_a2b1c1_c_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b1c1_c_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b1c1_c_1';

UPDATE BoxVolume
 SET  hadByWorkVolume_Robot='robot_1', hasBoxVolume_MaximumPoint= 'point_max', hasBoxVolume_MinimumPoint= 'point_min' WHERE _NAME = 'box_volume_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_tray' WHERE _NAME = 'part_a_4_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_a_4_x_axis', hasPoseLocation_ZAxis= 'part_a_4_z_axis', hasPoseLocation_Point= 'part_a_4_point' WHERE _NAME = 'part_a_4_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_c_3_x_axis', hasPoseLocation_ZAxis= 'part_c_3_z_axis', hasPoseLocation_Point= 'part_c_3_point' WHERE _NAME = 'part_c_3_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='changing_station_1' WHERE _NAME = 'changing_station_base_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='changing_station_base_x_axis', hasPoseLocation_ZAxis= 'changing_station_base_z_axis', hasPoseLocation_Point= 'changing_station_base_point' WHERE _NAME = 'changing_station_base_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_a_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_a_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_a_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_a_1';

UPDATE ExternalShape
 SET  hadByExternalShape_StockKeepingUnit='stock_keeping_unit_part_gear' WHERE _NAME = 'ext_shape_gear';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_a', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_a_2', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_a_2', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_a_2' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_a_2';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_a_tray' WHERE _NAME = 'part_a_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_a_3_x_axis', hasPoseLocation_ZAxis= 'part_a_3_z_axis', hasPoseLocation_Point= 'part_a_3_point' WHERE _NAME = 'part_a_3_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='finished_kit_receiver' WHERE _NAME = 'finished_kit_box_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='finished_kit_box_x_axis', hasPoseLocation_ZAxis= 'finished_kit_box_z_axis', hasPoseLocation_Point= 'finished_kit_box_point' WHERE _NAME = 'finished_kit_box_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_shaft_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gear_shaft_1_x_axis', hasPoseLocation_ZAxis= 'part_gear_shaft_1_z_axis', hasPoseLocation_Point= 'part_gear_shaft_1_point' WHERE _NAME = 'part_gear_shaft_1_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_holder_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gear_holder_x_axis', hasPoseLocation_ZAxis= 'part_gear_holder_z_axis', hasPoseLocation_Point= 'part_gear_holder_point' WHERE _NAME = 'part_gear_holder_pose';

UPDATE ExternalShape
 SET  hadByExternalShape_StockKeepingUnit='stock_keeping_unit_part_gear_base' WHERE _NAME = 'ext_shape_gear_base';

UPDATE ExternalShape
 SET  hadByExternalShape_StockKeepingUnit='stock_keeping_unit_part_gear_shaft' WHERE _NAME = 'ext_shape_gear_shaft';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'changing_station_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='changing_station_x_axis', hasPoseLocation_ZAxis= 'changing_station_z_axis', hasPoseLocation_Point= 'changing_station_point' WHERE _NAME = 'changing_station_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='robot_1' WHERE _NAME = 'relative_location_on_1';

UPDATE KitDesign
 SET  hadByKitDesign_KittingWorkstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_design_a2b1c1';

UPDATE KitDesign
 SET  hadByKitDesign_KittingWorkstation='kitting_workstation_1', hasKitDesign_KitTraySku= 'stock_keeping_unit_kit_tray' WHERE _NAME = 'kit_design_a2b2c1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'empty_kit_tray_box_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='empty_kit_tray_box_x_axis', hasPoseLocation_ZAxis= 'empty_kit_tray_box_z_axis', hasPoseLocation_Point= 'empty_kit_tray_box_point' WHERE _NAME = 'empty_kit_tray_box_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_base_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gear_base_x_axis', hasPoseLocation_ZAxis= 'part_gear_base_z_axis', hasPoseLocation_Point= 'part_gear_base_point' WHERE _NAME = 'part_gear_base_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'empty_kit_tray_supply_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='empty_kit_tray_supply_x_axis', hasPoseLocation_ZAxis= 'empty_kit_tray_supply_z_axis', hasPoseLocation_Point= 'empty_kit_tray_supply_point' WHERE _NAME = 'empty_kit_tray_supply_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='robot_pose' WHERE _NAME = 'robot_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='relative_location_in_1' WHERE _NAME = 'kitting_workstation_1';

UPDATE KittingWorkstation
 SET  hasKittingWorkstation_ChangingStation='changing_station_1', hasKittingWorkstation_Robot= 'robot_1' WHERE _NAME = 'kitting_workstation_1';

UPDATE Slot
 SET  hadBySlot_Kit='kit_a2b2c1', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_a2b2c1_b_2' WHERE _NAME = 'kit_a2b2c1_slot_4';

UPDATE Slot
 SET  hadBySlot_Kit='kit_a2b2c1', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_a2b2c1_c_1' WHERE _NAME = 'kit_a2b2c1_slot_5';

UPDATE Slot
 SET  hadBySlot_Kit='kit_a2b2c1', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_a2b2c1_a_2' WHERE _NAME = 'kit_a2b2c1_slot_2';

UPDATE Slot
 SET  hadBySlot_Kit='kit_a2b2c1', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_a2b2c1_b_1' WHERE _NAME = 'kit_a2b2c1_slot_3';

UPDATE Slot
 SET  hadBySlot_Kit='kit_a2b2c1', hasSlot_PartRefAndPose= 'part_ref_and_pose_kit_a2b2c1_a_1' WHERE _NAME = 'kit_a2b2c1_slot_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_1_pose' WHERE _NAME = 'part_a_1';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_a' WHERE _NAME = 'part_a_1';

UPDATE Part
 SET  hadByPart_PartsVessel='part_a_tray' WHERE _NAME = 'part_a_1';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_3_pose' WHERE _NAME = 'part_a_3';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_a' WHERE _NAME = 'part_a_3';

UPDATE Part
 SET  hadByPart_PartsVessel='part_a_tray' WHERE _NAME = 'part_a_3';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_2_pose' WHERE _NAME = 'part_a_2';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_a' WHERE _NAME = 'part_a_2';

UPDATE Part
 SET  hadByPart_PartsVessel='part_a_tray' WHERE _NAME = 'part_a_2';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='part_a_4_pose' WHERE _NAME = 'part_a_4';

UPDATE SkuObject
 SET  hasSkuObject_Sku='stock_keeping_unit_part_a' WHERE _NAME = 'part_a_4';

UPDATE Part
 SET  hadByPart_PartsVessel='part_a_tray' WHERE _NAME = 'part_a_4';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_3_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gear_3_x_axis', hasPoseLocation_ZAxis= 'part_gear_3_z_axis', hasPoseLocation_Point= 'part_gear_3_point' WHERE _NAME = 'part_gear_3_pose';

UPDATE SolidObject
 SET  hasSolidObject_PrimaryLocation='changing_station_pose' WHERE _NAME = 'changing_station_1';

UPDATE EndEffectorChangingStation
 SET  hasEndEffectorChangingStation_Base='changing_station_base' WHERE _NAME = 'changing_station_1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='kitting_workstation_1' WHERE _NAME = 'part_gear_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_gear_1_x_axis', hasPoseLocation_ZAxis= 'part_gear_1_z_axis', hasPoseLocation_Point= 'part_gear_1_point' WHERE _NAME = 'part_gear_1_pose';

UPDATE SolidObject
 SET  hadByObjectOnTable_WorkTable='work_table_1', hasSolidObject_PrimaryLocation= 'kit_a2b2c1_pose' WHERE _NAME = 'kit_a2b2c1';

UPDATE Kit
 SET  hasKit_KitTray='kit_tray_1', hasKit_Design= 'kit_design_a2b2c1' WHERE _NAME = 'kit_a2b2c1';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='part_c_tray' WHERE _NAME = 'part_c_1_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='part_c_1_x_axis', hasPoseLocation_ZAxis= 'part_c_1_z_axis', hasPoseLocation_Point= 'part_c_1_point' WHERE _NAME = 'part_c_1_pose';

UPDATE PhysicalLocation
 SET  hasPhysicalLocation_RefObject='empty_kit_tray_supply' WHERE _NAME = 'kit_tray_2_pose';

UPDATE PoseLocation
 SET  hasPoseLocation_XAxis='kit_tray_2_x_axis', hasPoseLocation_ZAxis= 'kit_tray_2_z_axis', hasPoseLocation_Point= 'kit_tray_2_point' WHERE _NAME = 'kit_tray_2_pose';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_b', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_b_2', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_b_2', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_b_2' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_b_2';

UPDATE PartRefAndPose
 SET  hasPartRefAndPose_Sku='stock_keeping_unit_part_b', hasPartRefAndPose_ZAxis= 'z_axis_kit_a2b2c1_b_1', hadByPartRefAndPose_KitDesign= 'kit_design_a2b2c1', hasPartRefAndPose_Point= 'point_kit_a2b2c1_b_1', hasPartRefAndPose_XAxis= 'x_axis_kit_a2b2c1_b_1' WHERE _NAME = 'part_ref_and_pose_kit_a2b2c1_b_1';