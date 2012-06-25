INSERT INTO DataThing
(_NAME)
VALUES('PartCTrayRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(1, 'PartCTrayRPY', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartA4Location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(2, 'PartA4Location', 'PartATray');

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME)
VALUES(2, 'PartA4Location');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME, hasRelativeLocationIn_Description)
VALUES(2, 'PartA4Location', 'PartA4 is in PartATray');

INSERT INTO DataThing
(_NAME)
VALUES('EmptyKitTraySupplyRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(3, 'EmptyKitTraySupplyRPY', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartBTrayRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(4, 'PartBTrayRPY', 0.0, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartC2', 'PartC2Location');

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_SkuRef, hadByPart_PartsTrayWithParts)
VALUES(1, 'PartC2', 16, 'SkuIdPartC', 'PartCSupply');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartC1', 'PartC1Location');

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_SkuRef, hadByPart_PartsTrayWithParts)
VALUES(2, 'PartC1', 15, 'SkuIdPartC', 'PartCSupply');

INSERT INTO DataThing
(_NAME)
VALUES('FinishedKitBoxPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(5, 'FinishedKitBoxPose', 'FinishedKitReceiver');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(5, 'FinishedKitBoxPose', 'FinishedKitBoxPoint', 'FinishedKitBoxRPY');

INSERT INTO DataThing
(_NAME)
VALUES('PartRefAndPoseC1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Ref, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Rpy, hasPartRefAndPose_Point)
VALUES(6, 'PartRefAndPoseC1', 'SkuIdPartC', 'KitDesignA2B1C1', 'RpyC1', 'PointC1');

INSERT INTO DataThing
(_NAME)
VALUES('RpyB1');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(7, 'RpyB1', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('KitTray1Pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(8, 'KitTray1Pose', 'EmptyKitTrayBox');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(8, 'KitTray1Pose', 'KitTray1Point', 'KitTray1RPY');

INSERT INTO DataThing
(_NAME)
VALUES('KitTray3Pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(9, 'KitTray3Pose', 'EmptyKitTrayBox');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(9, 'KitTray3Pose', 'KitTray3Point', 'KitTray3RPY');

INSERT INTO DataThing
(_NAME)
VALUES('PointB1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(10, 'PointB1', 0.2, 0.5, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartATrayPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(11, 'PartATrayPoint', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('EmptyKitTraySupplyPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(12, 'EmptyKitTraySupplyPose', 'KittingWorkstation1');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(12, 'EmptyKitTraySupplyPose', 'EmptyKitTraySupplyPoint', 'EmptyKitTraySupplyRPY');

INSERT INTO DataThing
(_NAME)
VALUES('PartGripperPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(13, 'PartGripperPoint', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartASupplyPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(14, 'PartASupplyPose', 'KittingWorkstation1');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(14, 'PartASupplyPose', 'PartASupplyPoint', 'PartASupplyRPY');

INSERT INTO DataThing
(_NAME)
VALUES('RelativeLocationIn1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(15, 'RelativeLocationIn1', 'KittingWorkstation1');

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME)
VALUES(15, 'RelativeLocationIn1');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME, hasRelativeLocationIn_Description)
VALUES(15, 'RelativeLocationIn1', 'The  KittingWorkstation is in KittingWorkstation1');

INSERT INTO DataThing
(_NAME)
VALUES('EmptyKitTrayBoxPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(16, 'EmptyKitTrayBoxPoint', 0.5, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('KitTray3Point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(17, 'KitTray3Point', 0.0, 0.0, 0.3);

INSERT INTO DataThing
(_NAME)
VALUES('PartBTrayPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(18, 'PartBTrayPose', 'PartBSupply');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(18, 'PartBTrayPose', 'PartBTrayPoint', 'PartBTrayRPY');

INSERT INTO DataThing
(_NAME)
VALUES('RobotPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(19, 'RobotPose', 'KittingWorkstation1');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(19, 'RobotPose', 'RobotPoint', 'RobotRPY');

INSERT INTO DataThing
(_NAME)
VALUES('PartC2Location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(20, 'PartC2Location', 'PartCTray');

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME)
VALUES(20, 'PartC2Location');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME, hasRelativeLocationIn_Description)
VALUES(20, 'PartC2Location', 'PartC2 is in PartCTray');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartGripper', 'PartGripperPose');

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Weight, hasEndEffector_Description, hasEndEffector_Id)
VALUES(3, 'PartGripper', 0.01, 'small single cup vacuum effector', 'ThePartGripper');

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(3, 'PartGripper', 0.02, 0.025);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(3, 'PartGripper');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartATray', 'PartATrayPose');

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Width, hasBox_Height, hasBox_Length)
VALUES(4, 'PartATray', 0.3, 0.2, 0.6);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SkuRef, hasPartsTray_SerialNumber)
VALUES(4, 'PartATray', 'SkuIdPartsTray', 6);

INSERT INTO DataThing
(_NAME)
VALUES('PartGripperRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(21, 'PartGripperRPY', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartRefAndPoseB1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Ref, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Rpy, hasPartRefAndPose_Point)
VALUES(22, 'PartRefAndPoseB1', 'SkuIdPartB', 'KitDesignA2B1C1', 'RpyB1', 'PointB1');

INSERT INTO DataThing
(_NAME)
VALUES('BoxVolume1');

INSERT INTO BoxVolume
(BoxVolumeID, _NAME, hasBoxVolume_MaximumPoint, hasBoxVolume_MinimumPoint)
VALUES(23, 'BoxVolume1', 'PointMax', 'PointMin');

INSERT INTO DataThing
(_NAME)
VALUES('PartASupplyRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(24, 'PartASupplyRPY', 0.0, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('ChangingStation1', 'ChangingStationPose');

INSERT INTO EndEffectorChangingStation
(EndEffectorChangingStationID, _NAME)
VALUES(5, 'ChangingStation1');

INSERT INTO DataThing
(_NAME)
VALUES('RpyC1');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(25, 'RpyC1', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PointC1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(26, 'PointC1', 0.4, 0.5, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartGripperHolderPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(27, 'PartGripperHolderPoint', 0.25, 0.0, 0.5);

INSERT INTO DataThing
(_NAME)
VALUES('EmptyKitTrayBoxPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(28, 'EmptyKitTrayBoxPose', 'EmptyKitTraySupply');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(28, 'EmptyKitTrayBoxPose', 'EmptyKitTrayBoxPoint', 'EmptyKitTrayBoxRPY');

INSERT INTO DataThing
(_NAME)
VALUES('KitTray3RPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(29, 'KitTray3RPY', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('FinishedKitReceiverPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(30, 'FinishedKitReceiverPose', 'KittingWorkstation1');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(30, 'FinishedKitReceiverPose', 'FinishedKitReceiverPoint', 'FinishedKitReceiverRPY');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartA3', 'PartA3Location');

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_SkuRef, hadByPart_PartsTrayWithParts)
VALUES(6, 'PartA3', 11, 'SkuIdPartA', 'PartASupply');

INSERT INTO DataThing
(_NAME)
VALUES('PartGripperPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(31, 'PartGripperPose', 'PartGripperHolder');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point)
VALUES(31, 'PartGripperPose', 'PartGripperPoint');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('KittingWorkstation1', 'RelativeLocationIn1');

INSERT INTO KittingWorkstation
(KittingWorkstationID, _NAME, hasWorkstation_LengthUnit, hasWorkstation_WeightUnit, hasWorkstation_AngleUnit, hasWorkstation_ChangingStation, hasWorkstation_WorkTable, hasWorkstation_Robot)
VALUES(7, 'KittingWorkstation1', 'meter', 'kilogram', 'degree', 'ChangingStation1', 'WorkTable1', 'Robot1');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartA2', 'PartA2Location');

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_SkuRef, hadByPart_PartsTrayWithParts)
VALUES(8, 'PartA2', 10, 'SkuIdPartA', 'PartASupply');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartA1', 'PartA1Location');

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_SkuRef, hadByPart_PartsTrayWithParts)
VALUES(9, 'PartA1', 9, 'SkuIdPartA', 'PartASupply');

INSERT INTO DataThing
(_NAME)
VALUES('PartRefAndPoseA1');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Ref, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Rpy, hasPartRefAndPose_Point)
VALUES(32, 'PartRefAndPoseA1', 'SkuIdPartA', 'KitDesignA2B1C1', 'RpyA1', 'PointA1');

INSERT INTO DataThing
(_NAME)
VALUES('PartRefAndPoseA2');

INSERT INTO PartRefAndPose
(PartRefAndPoseID, _NAME, hasPartRefAndPose_Ref, hadByPartRefAndPose_KitDesign, hasPartRefAndPose_Rpy, hasPartRefAndPose_Point)
VALUES(33, 'PartRefAndPoseA2', 'SkuIdPartA', 'KitDesignA2B1C1', 'RpyA2', 'PointA2');

INSERT INTO DataThing
(_NAME)
VALUES('KitTray2RPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(34, 'KitTray2RPY', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('RelativeLocationOn1');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(35, 'RelativeLocationOn1', 'Robot1');

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME)
VALUES(35, 'RelativeLocationOn1');

INSERT INTO RelativeLocationOn
(RelativeLocationOnID, _NAME, hasRelativeLocationOn_Description)
VALUES(35, 'RelativeLocationOn1', 'The TrayGripper is on Robot1');

INSERT INTO DataThing
(_NAME)
VALUES('ShapePartsTray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(36, 'ShapePartsTray', 'Shape of PartsTrays');

INSERT INTO DataThing
(_NAME)
VALUES('PointMax');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(37, 'PointMax', 1.0, 1.0, 2.0);

INSERT INTO DataThing
(_NAME)
VALUES('ChangingStationPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(38, 'ChangingStationPoint', 7.5, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('EmptyKitTraySupplyPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(39, 'EmptyKitTraySupplyPoint', 0.5, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartA2Location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(40, 'PartA2Location', 'PartATray');

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME)
VALUES(40, 'PartA2Location');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME, hasRelativeLocationIn_Description)
VALUES(40, 'PartA2Location', 'PartA2 is in PartATray');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartCSupply', 'PartCSupplyPose');

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_PartsTray)
VALUES(10, 'PartCSupply', 'PartCTray');

INSERT INTO DataThing
(_NAME)
VALUES('PartASupplyPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(41, 'PartASupplyPoint', 4.5, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('RobotRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(42, 'RobotRPY', 0.0, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartB2', 'PartB2Location');

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_SkuRef, hadByPart_PartsTrayWithParts)
VALUES(11, 'PartB2', 14, 'SkuIdPartB', 'PartBSupply');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartB1', 'PartB1Location');

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_SkuRef, hadByPart_PartsTrayWithParts)
VALUES(12, 'PartB1', 13, 'SkuIdPartB', 'PartBSupply');

INSERT INTO DataThing
(_NAME)
VALUES('KitTray1Point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(43, 'KitTray1Point', 0.0, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartA4', 'PartA4Location');

INSERT INTO Part
(PartID, _NAME, hasPart_SerialNumber, hasPart_SkuRef, hadByPart_PartsTrayWithParts)
VALUES(13, 'PartA4', 12, 'SkuIdPartA', 'PartASupply');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartBSupply', 'PartBSupplyPose');

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_PartsTray)
VALUES(14, 'PartBSupply', 'PartBTray');

INSERT INTO DataThing
(_NAME)
VALUES('ShapeKitTray');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(44, 'ShapeKitTray', 'Shape of KitTrays');

INSERT INTO DataThing
(_NAME)
VALUES('StockKeepingUnitKitBox');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Id, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(45, 'StockKeepingUnitKitBox', 'SKU for Boxes for Kits and KitTrays', 'SkuIdKitBox', 1.2, 'Workstation1', 'ShapeKitBox');

INSERT INTO DataThing
(_NAME)
VALUES('ShapePartA');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(46, 'ShapePartA', 'Shape of PartA');

INSERT INTO DataThing
(_NAME)
VALUES('PartCSupplyPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(47, 'PartCSupplyPoint', 6.5, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('FinishedKitReceiver', 'FinishedKitReceiverPose');

INSERT INTO LargeBoxWithKits
(LargeBoxWithKitsID, _NAME, hasLargeBoxWithKits_Capacity, hasLargeBoxWithKits_KitDesignRef, hasLargeBoxWithKits_LargeContainer)
VALUES(15, 'FinishedKitReceiver', 12, 'KitDesignA2B1C1', 'FinishedKitBox');

INSERT INTO DataThing
(_NAME)
VALUES('ChangingStationRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(48, 'ChangingStationRPY', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PointA1');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(49, 'PointA1', 0.2, 0.3, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PointA2');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(50, 'PointA2', 0.4, 0.3, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartA3Location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(51, 'PartA3Location', 'PartATray');

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME)
VALUES(51, 'PartA3Location');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME, hasRelativeLocationIn_Description)
VALUES(51, 'PartA3Location', 'PartA3 is in PartATray');

INSERT INTO DataThing
(_NAME)
VALUES('ChangingStationPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(52, 'ChangingStationPose', 'KittingWorkstation1');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(52, 'ChangingStationPose', 'ChangingStationPoint', 'ChangingStationRPY');

INSERT INTO DataThing
(_NAME)
VALUES('ShapePartC');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(53, 'ShapePartC', 'Shape of PartC');

INSERT INTO DataThing
(_NAME)
VALUES('ShapePartB');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(54, 'ShapePartB', 'Shape of PartB');

INSERT INTO DataThing
(_NAME)
VALUES('KitTray2Point');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(55, 'KitTray2Point', 0.0, 0.0, 0.15);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartASupply', 'PartASupplyPose');

INSERT INTO PartsTrayWithParts
(PartsTrayWithPartsID, _NAME, hasPartsTrayWithParts_PartsTray)
VALUES(16, 'PartASupply', 'PartATray');

INSERT INTO DataThing
(_NAME)
VALUES('StockKeepingUnitKitTray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Id, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(56, 'StockKeepingUnitKitTray', 'SKU for KitTrays', 'SkuIdKitTray', 0.2, 'Workstation1', 'ShapeKitTray');

INSERT INTO hasSku_EndEffectorRefsValue
(StockKeepingUnitID, hasSku_EndEffectorRefs)
VALUES(56, 'TheTrayGripper');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('TrayGripper', 'RelativeLocationOn1');

INSERT INTO EndEffector
(EndEffectorID, _NAME, hasEndEffector_Weight, hasEndEffector_Description, hasEndEffector_Id, hadByEndEffector_Robot)
VALUES(17, 'TrayGripper', 0.04, 'large single cup vacuum effector', 'TheTrayGripper', 'Robot1');

INSERT INTO VacuumEffector
(VacuumEffectorID, _NAME, hasVacuumEffector_CupDiameter, hasVacuumEffector_Length)
VALUES(17, 'TrayGripper', 0.04, 0.1);

INSERT INTO VacuumEffectorSingleCup
(VacuumEffectorSingleCupID, _NAME)
VALUES(17, 'TrayGripper');

INSERT INTO DataThing
(_NAME)
VALUES('ShapeKitBox');

INSERT INTO ShapeDesign
(ShapeDesignID, _NAME, hasShapeDesign_Description)
VALUES(57, 'ShapeKitBox', 'Shape of boxes to hold kits and kit trays');

INSERT INTO DataThing
(_NAME)
VALUES('PartA1Location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(58, 'PartA1Location', 'PartATray');

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME)
VALUES(58, 'PartA1Location');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME, hasRelativeLocationIn_Description)
VALUES(58, 'PartA1Location', 'PartA1 is in PartATray');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartGripperHolder', 'PartGripperHolderPose');

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_ChangingStation, hasEndEffectorHolder_EndEffector)
VALUES(18, 'PartGripperHolder', 'ChangingStation1', 'PartGripper');

INSERT INTO DataThing
(_NAME)
VALUES('PartGripperHolderRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(59, 'PartGripperHolderRPY', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('RobotPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(60, 'RobotPoint', 3.0, 0.0, 2.0);

INSERT INTO DataThing
(_NAME)
VALUES('WorkTableRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(61, 'WorkTableRPY', 0.0, 0.0, 90.0);

INSERT INTO DataThing
(_NAME)
VALUES('FinishedKitBoxRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(62, 'FinishedKitBoxRPY', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('KitTray1RPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(63, 'KitTray1RPY', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartCSupplyPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(64, 'PartCSupplyPose', 'KittingWorkstation1');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(64, 'PartCSupplyPose', 'PartCSupplyPoint', 'PartCSupplyRPY');

INSERT INTO DataThing
(_NAME)
VALUES('TrayGripperHolderRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(65, 'TrayGripperHolderRPY', 0.0, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('KitTray1', 'KitTray1Pose');

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Width, hasBox_Height, hasBox_Length)
VALUES(19, 'KitTray1', 0.3, 0.15, 0.5);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_SkuRef, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(19, 'KitTray1', 1, 'SkuIdKitTray', 'EmptyKitTraySupply');

INSERT INTO DataThing
(_NAME)
VALUES('PartBSupplyPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(66, 'PartBSupplyPoint', 5.5, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartCTrayPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(67, 'PartCTrayPoint', 0.0, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('EmptyKitTrayBox', 'EmptyKitTrayBoxPose');

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Width, hasBox_Height, hasBox_Length)
VALUES(20, 'EmptyKitTrayBox', 0.7, 0.8, 0.9);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SkuRef, hasLargeContainer_SerialNumber)
VALUES(20, 'EmptyKitTrayBox', 'SkuIdKitBox', 4);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('KitTray3', 'KitTray3Pose');

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Width, hasBox_Height, hasBox_Length)
VALUES(21, 'KitTray3', 0.3, 0.15, 0.5);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_SkuRef, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(21, 'KitTray3', 3, 'SkuIdKitTray', 'EmptyKitTraySupply');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('KitTray2', 'KitTray2Pose');

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Width, hasBox_Height, hasBox_Length)
VALUES(22, 'KitTray2', 0.3, 0.15, 0.5);

INSERT INTO KitTray
(KitTrayID, _NAME, hasKitTray_SerialNumber, hasKitTray_SkuRef, hadByKitTray_LargeBoxWithEmptyKitTrays)
VALUES(22, 'KitTray2', 2, 'SkuIdKitTray', 'EmptyKitTraySupply');

INSERT INTO DataThing
(_NAME)
VALUES('TrayGripperHolderPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(68, 'TrayGripperHolderPose', 'ChangingStation1');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(68, 'TrayGripperHolderPose', 'TrayGripperHolderPoint', 'TrayGripperHolderRPY');

INSERT INTO DataThing
(_NAME)
VALUES('PointMin');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(69, 'PointMin', -1.0, -1.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('KitDesignA2B1C1');

INSERT INTO KitDesign
(KitDesignID, _NAME, hasKitDesign_Id, hasKitDesign_KitTraySkuRef, hadByKitDesign_Workstation)
VALUES(70, 'KitDesignA2B1C1', 'KitDesignA2B1C1', 'SkuIdKitTray', 'Workstation1');

INSERT INTO DataThing
(_NAME)
VALUES('PartB2Location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(71, 'PartB2Location', 'PartBTray');

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME)
VALUES(71, 'PartB2Location');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME, hasRelativeLocationIn_Description)
VALUES(71, 'PartB2Location', 'PartB2 is in PartBTray');

INSERT INTO DataThing
(_NAME)
VALUES('PartBSupplyRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(72, 'PartBSupplyRPY', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('KitTray2Pose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(73, 'KitTray2Pose', 'EmptyKitTrayBox');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(73, 'KitTray2Pose', 'KitTray2Point', 'KitTray2RPY');

INSERT INTO DataThing
(_NAME)
VALUES('FinishedKitBoxPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(74, 'FinishedKitBoxPoint', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartBSupplyPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(75, 'PartBSupplyPose', 'KittingWorkstation1');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(75, 'PartBSupplyPose', 'PartBSupplyPoint', 'PartBSupplyRPY');

INSERT INTO DataThing
(_NAME)
VALUES('WorkTablePoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(76, 'WorkTablePoint', 3.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartATrayRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(77, 'PartATrayRPY', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('StockKeepingUnitPartC');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Id, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(78, 'StockKeepingUnitPartC', 'SKU for PartC', 'SkuIdPartC', 0.18, 'Workstation1', 'ShapePartC');

INSERT INTO hasSku_EndEffectorRefsValue
(StockKeepingUnitID, hasSku_EndEffectorRefs)
VALUES(78, 'ThePartGripper');

INSERT INTO DataThing
(_NAME)
VALUES('StockKeepingUnitPartB');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Id, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(79, 'StockKeepingUnitPartB', 'SKU for PartB', 'SkuIdPartB', 0.18, 'Workstation1', 'ShapePartB');

INSERT INTO hasSku_EndEffectorRefsValue
(StockKeepingUnitID, hasSku_EndEffectorRefs)
VALUES(79, 'ThePartGripper');

INSERT INTO DataThing
(_NAME)
VALUES('StockKeepingUnitPartA');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Id, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(80, 'StockKeepingUnitPartA', 'SKU for Part A', 'SkuIdPartA', 0.18, 'Workstation1', 'ShapePartA');

INSERT INTO hasSku_EndEffectorRefsValue
(StockKeepingUnitID, hasSku_EndEffectorRefs)
VALUES(80, 'ThePartGripper');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('TrayGripperHolder', 'TrayGripperHolderPose');

INSERT INTO EndEffectorHolder
(EndEffectorHolderID, _NAME, hadByEndEffectorHolder_ChangingStation)
VALUES(23, 'TrayGripperHolder', 'ChangingStation1');

INSERT INTO DataThing
(_NAME)
VALUES('PartC1Location');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(81, 'PartC1Location', 'PartCTray');

INSERT INTO RelativeLocation
(RelativeLocationID, _NAME)
VALUES(81, 'PartC1Location');

INSERT INTO RelativeLocationIn
(RelativeLocationInID, _NAME, hasRelativeLocationIn_Description)
VALUES(81, 'PartC1Location', 'PartC1 is in PartCTray');

INSERT INTO DataThing
(_NAME)
VALUES('PartGripperHolderPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(82, 'PartGripperHolderPose', 'ChangingStation1');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(82, 'PartGripperHolderPose', 'PartGripperHolderPoint', 'PartGripperHolderRPY');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('WorkTable1', 'WorkTablePose');

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Width, hasBox_Height, hasBox_Length)
VALUES(24, 'WorkTable1', 0.8, 0.5, 1.6);

INSERT INTO WorkTable
(WorkTableID, _NAME)
VALUES(24, 'WorkTable1');

INSERT INTO DataThing
(_NAME)
VALUES('FinishedKitReceiverRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(83, 'FinishedKitReceiverRPY', 0.0, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartCTray', 'PartCTrayPose');

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Width, hasBox_Height, hasBox_Length)
VALUES(25, 'PartCTray', 0.3, 0.2, 0.6);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SkuRef, hasPartsTray_SerialNumber)
VALUES(25, 'PartCTray', 'SkuIdPartsTray', 8);

INSERT INTO DataThing
(_NAME)
VALUES('FinishedKitReceiverPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(84, 'FinishedKitReceiverPoint', 1.5, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('Robot1', 'RobotPose');

INSERT INTO Robot
(RobotID, _NAME, hasRobot_Id, hasRobot_MaximumLoadWeight, hasRobot_Description)
VALUES(26, 'Robot1', 'Robot1', 7.0, 'this is the robot');

INSERT INTO hasRobot_WorkVolume
(RobotID, BoxVolumeID)
VALUES(26, 23);

INSERT INTO DataThing
(_NAME)
VALUES('StockKeepingUnitPartsTray');

INSERT INTO StockKeepingUnit
(StockKeepingUnitID, _NAME, hasSku_Description, hasSku_Id, hasSku_Weight, hadBySku_Workstation, hasSku_Shape)
VALUES(85, 'StockKeepingUnitPartsTray', 'SKU for PartsTrays', 'SkuIdPartsTray', 0.2, 'Workstation1', 'ShapePartsTray');

INSERT INTO hasSku_EndEffectorRefsValue
(StockKeepingUnitID, hasSku_EndEffectorRefs)
VALUES(85, 'TheTrayGripper');

INSERT INTO DataThing
(_NAME)
VALUES('PartCSupplyRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(86, 'PartCSupplyRPY', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartBTrayPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(87, 'PartBTrayPoint', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('WorkTablePose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(88, 'WorkTablePose', 'KittingWorkstation1');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(88, 'WorkTablePose', 'WorkTablePoint', 'WorkTableRPY');

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('EmptyKitTraySupply', 'EmptyKitTraySupplyPose');

INSERT INTO LargeBoxWithEmptyKitTrays
(LargeBoxWithEmptyKitTraysID, _NAME, hasLargeBoxWithEmptyKitTrays_LargeContainer)
VALUES(27, 'EmptyKitTraySupply', 'EmptyKitTrayBox');

INSERT INTO DataThing
(_NAME)
VALUES('EmptyKitTrayBoxRPY');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(89, 'EmptyKitTrayBoxRPY', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('PartATrayPose');

INSERT INTO PhysicalLocation
(PhysicalLocationID, _NAME, hasPhysicalLocation_RefObject)
VALUES(90, 'PartATrayPose', 'PartASupply');

INSERT INTO Pose
(PoseID, _NAME, hasPose_Point, hasPose_Rpy)
VALUES(90, 'PartATrayPose', 'PartATrayPoint', 'PartATrayRPY');

INSERT INTO DataThing
(_NAME)
VALUES('TrayGripperHolderPoint');

INSERT INTO Point
(PointID, _NAME, hasPoint_X, hasPoint_Y, hasPoint_Z)
VALUES(91, 'TrayGripperHolderPoint', -0.25, 0.0, 0.5);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('FinishedKitBox', 'FinishedKitBoxPose');

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Width, hasBox_Height, hasBox_Length)
VALUES(28, 'FinishedKitBox', 0.7, 0.8, 0.9);

INSERT INTO LargeContainer
(LargeContainerID, _NAME, hasLargeContainer_SkuRef, hasLargeContainer_SerialNumber)
VALUES(28, 'FinishedKitBox', 'SkuIdKitBox', 5);

INSERT INTO DataThing
(_NAME)
VALUES('RpyA2');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(92, 'RpyA2', 0.0, 0.0, 0.0);

INSERT INTO DataThing
(_NAME)
VALUES('RpyA1');

INSERT INTO RollPitchYaw
(RollPitchYawID, _NAME, hasRpy_Roll, hasRpy_Pitch, hasRpy_Yaw)
VALUES(93, 'RpyA1', 0.0, 0.0, 0.0);

INSERT INTO SolidObject
(_NAME, hasSolidObject_PhysicalLocation)
VALUES('PartBTray', 'PartBTrayPose');

INSERT INTO BoxyObject
(BoxyObjectID, _NAME, hasBox_Width, hasBox_Height, hasBox_Length)
VALUES(29, 'PartBTray', 0.3, 0.2, 0.6);

INSERT INTO PartsTray
(PartsTrayID, _NAME, hasPartsTray_SkuRef, hasPartsTray_SerialNumber)
VALUES(29, 'PartBTray', 'SkuIdPartsTray', 7);

