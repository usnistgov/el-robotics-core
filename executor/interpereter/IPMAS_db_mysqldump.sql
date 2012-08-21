-- MySQL dump 10.13  Distrib 5.5.24, for debian-linux-gnu (i686)
--
-- Host: localhost    Database: IPMAS
-- ------------------------------------------------------
-- Server version	5.5.24-0ubuntu0.12.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `BoxVolume`
--

DROP TABLE IF EXISTS `BoxVolume`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `BoxVolume` (
  `BoxVolumeID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasBoxVolume_MaximumPoint` varchar(255) DEFAULT NULL,
  `hasBoxVolume_MinimumPoint` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`BoxVolumeID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasBoxVolume_MaximumPoint` (`hasBoxVolume_MaximumPoint`),
  KEY `fkhasBoxVolume_MinimumPoint` (`hasBoxVolume_MinimumPoint`),
  CONSTRAINT `fkhasBoxVolume_MaximumPoint` FOREIGN KEY (`hasBoxVolume_MaximumPoint`) REFERENCES `Point` (`_NAME`),
  CONSTRAINT `fkhasBoxVolume_MinimumPoint` FOREIGN KEY (`hasBoxVolume_MinimumPoint`) REFERENCES `Point` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `BoxVolume`
--

LOCK TABLES `BoxVolume` WRITE;
/*!40000 ALTER TABLE `BoxVolume` DISABLE KEYS */;
INSERT INTO `BoxVolume` VALUES (146,'box_volume_1','point_max','point_min');
/*!40000 ALTER TABLE `BoxVolume` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `BoxyObject`
--

DROP TABLE IF EXISTS `BoxyObject`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `BoxyObject` (
  `BoxyObjectID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasBox_Height` double NOT NULL,
  `hasBox_Width` double NOT NULL,
  `hasBox_Length` double NOT NULL,
  PRIMARY KEY (`BoxyObjectID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `BoxyObject`
--

LOCK TABLES `BoxyObject` WRITE;
/*!40000 ALTER TABLE `BoxyObject` DISABLE KEYS */;
INSERT INTO `BoxyObject` VALUES (1,'part_b_tray',0.2,0.3,0.6),(13,'part_a_tray',0.2,0.3,0.6),(24,'part_c_tray',0.2,0.3,0.6),(25,'finished_kit_box',0.8,0.7,0.9),(26,'kit_tray_3',0.15,0.3,0.5),(27,'kit_tray_2',0.15,0.3,0.5),(28,'kit_tray_1',0.15,0.3,0.5),(29,'empty_kit_tray_box',0.8,0.7,0.9),(33,'work_table_1',0.5,0.8,1.6);
/*!40000 ALTER TABLE `BoxyObject` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `DataThing`
--

DROP TABLE IF EXISTS `DataThing`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `DataThing` (
  `DataThingID` int(11) NOT NULL AUTO_INCREMENT,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`DataThingID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB AUTO_INCREMENT=214 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `DataThing`
--

LOCK TABLES `DataThing` WRITE;
/*!40000 ALTER TABLE `DataThing` DISABLE KEYS */;
INSERT INTO `DataThing` VALUES (146,'box_volume_1'),(205,'changing_station_point'),(169,'changing_station_pose'),(69,'changing_station_x_axis'),(57,'changing_station_z_axis'),(200,'empty_kit_tray_box_point'),(177,'empty_kit_tray_box_pose'),(192,'empty_kit_tray_box_x_axis'),(149,'empty_kit_tray_box_z_axis'),(70,'empty_kit_tray_supply_point'),(187,'empty_kit_tray_supply_pose'),(6,'empty_kit_tray_supply_x_axis'),(163,'empty_kit_tray_supply_z_axis'),(92,'finished_kit_box_point'),(160,'finished_kit_box_pose'),(34,'finished_kit_box_x_axis'),(188,'finished_kit_box_z_axis'),(179,'finished_kit_receiver_point'),(7,'finished_kit_receiver_pose'),(123,'finished_kit_receiver_x_axis'),(162,'finished_kit_receiver_z_axis'),(212,'kit_a2b2c1'),(213,'kit_a2b2c1_pose'),(172,'kit_design_a2b1c1'),(174,'kit_design_a2b2c1'),(198,'kit_tray_1_point'),(113,'kit_tray_1_pose'),(71,'kit_tray_1_x_axis'),(199,'kit_tray_1_z_axis'),(134,'kit_tray_2_point'),(209,'kit_tray_2_pose'),(73,'kit_tray_2_x_axis'),(67,'kit_tray_2_z_axis'),(111,'kit_tray_3_point'),(87,'kit_tray_3_pose'),(128,'kit_tray_3_x_axis'),(18,'kit_tray_3_z_axis'),(63,'part_a_1_point'),(26,'part_a_1_pose'),(183,'part_a_1_x_axis'),(157,'part_a_1_z_axis'),(194,'part_a_2_point'),(43,'part_a_2_pose'),(180,'part_a_2_x_axis'),(50,'part_a_2_z_axis'),(145,'part_a_3_point'),(155,'part_a_3_pose'),(101,'part_a_3_x_axis'),(164,'part_a_3_z_axis'),(119,'part_a_4_point'),(147,'part_a_4_pose'),(156,'part_a_4_x_axis'),(25,'part_a_4_z_axis'),(207,'part_a_supply_point'),(178,'part_a_supply_pose'),(62,'part_a_supply_x_axis'),(127,'part_a_supply_z_axis'),(167,'part_a_tray_point'),(19,'part_a_tray_pose'),(40,'part_a_tray_x_axis'),(91,'part_a_tray_z_axis'),(51,'part_b_1_point'),(79,'part_b_1_pose'),(168,'part_b_1_x_axis'),(141,'part_b_1_z_axis'),(88,'part_b_2_point'),(1,'part_b_2_pose'),(30,'part_b_2_x_axis'),(29,'part_b_2_z_axis'),(118,'part_b_3_point'),(5,'part_b_3_pose'),(159,'part_b_3_x_axis'),(78,'part_b_3_z_axis'),(102,'part_b_4_point'),(9,'part_b_4_pose'),(131,'part_b_4_x_axis'),(27,'part_b_4_z_axis'),(208,'part_b_5_point'),(8,'part_b_5_pose'),(133,'part_b_5_x_axis'),(106,'part_b_5_z_axis'),(55,'part_b_6_point'),(68,'part_b_6_pose'),(100,'part_b_6_x_axis'),(152,'part_b_6_z_axis'),(165,'part_b_7_point'),(37,'part_b_7_pose'),(53,'part_b_7_x_axis'),(117,'part_b_7_z_axis'),(130,'part_b_8_point'),(54,'part_b_8_pose'),(136,'part_b_8_x_axis'),(104,'part_b_8_z_axis'),(124,'part_b_supply_point'),(14,'part_b_supply_pose'),(33,'part_b_supply_x_axis'),(114,'part_b_supply_z_axis'),(148,'part_b_tray_point'),(59,'part_b_tray_pose'),(184,'part_b_tray_x_axis'),(195,'part_b_tray_z_axis'),(80,'part_c_1_point'),(204,'part_c_1_pose'),(58,'part_c_1_x_axis'),(182,'part_c_1_z_axis'),(132,'part_c_2_point'),(140,'part_c_2_pose'),(107,'part_c_2_x_axis'),(13,'part_c_2_z_axis'),(47,'part_c_3_point'),(150,'part_c_3_pose'),(176,'part_c_3_x_axis'),(65,'part_c_3_z_axis'),(96,'part_c_4_point'),(12,'part_c_4_pose'),(44,'part_c_4_x_axis'),(2,'part_c_4_z_axis'),(105,'part_c_5_point'),(86,'part_c_5_pose'),(190,'part_c_5_x_axis'),(151,'part_c_5_z_axis'),(28,'part_c_6_point'),(143,'part_c_6_pose'),(20,'part_c_6_x_axis'),(139,'part_c_6_z_axis'),(137,'part_c_7_point'),(75,'part_c_7_pose'),(116,'part_c_7_x_axis'),(108,'part_c_7_z_axis'),(99,'part_c_8_point'),(85,'part_c_8_pose'),(82,'part_c_8_x_axis'),(94,'part_c_8_z_axis'),(158,'part_c_supply_point'),(166,'part_c_supply_pose'),(191,'part_c_supply_x_axis'),(161,'part_c_supply_z_axis'),(110,'part_c_tray_point'),(109,'part_c_tray_pose'),(197,'part_c_tray_x_axis'),(112,'part_c_tray_z_axis'),(135,'part_gripper_holder_point'),(21,'part_gripper_holder_pose'),(48,'part_gripper_holder_x_axis'),(76,'part_gripper_holder_z_axis'),(89,'part_gripper_point'),(23,'part_gripper_pose'),(22,'part_gripper_x_axis'),(77,'part_gripper_z_axis'),(56,'part_ref_and_pose_kit_a2b1c1_a_1'),(49,'part_ref_and_pose_kit_a2b1c1_a_2'),(60,'part_ref_and_pose_kit_a2b1c1_b_1'),(144,'part_ref_and_pose_kit_a2b1c1_c_1'),(153,'part_ref_and_pose_kit_a2b2c1_a_1'),(154,'part_ref_and_pose_kit_a2b2c1_a_2'),(211,'part_ref_and_pose_kit_a2b2c1_b_1'),(210,'part_ref_and_pose_kit_a2b2c1_b_2'),(142,'part_ref_and_pose_kit_a2b2c1_c_1'),(17,'point_kit_a2b1c1_a_1'),(16,'point_kit_a2b1c1_a_2'),(196,'point_kit_a2b1c1_b_1'),(129,'point_kit_a2b1c1_c_1'),(66,'point_kit_a2b2c1_a_1'),(64,'point_kit_a2b2c1_a_2'),(126,'point_kit_a2b2c1_b_1'),(125,'point_kit_a2b2c1_b_2'),(74,'point_kit_a2b2c1_c_1'),(138,'point_max'),(38,'point_min'),(122,'relative_location_in_1'),(171,'relative_location_on_1'),(189,'robot_point'),(3,'robot_pose'),(81,'robot_x_axis'),(193,'robot_z_axis'),(46,'shape_kit_box'),(103,'shape_kit_tray'),(24,'shape_parts_tray'),(41,'shape_part_a'),(42,'shape_part_b'),(45,'shape_part_c'),(35,'stock_keeping_unit_kit_box'),(15,'stock_keeping_unit_kit_tray'),(93,'stock_keeping_unit_parts_tray'),(4,'stock_keeping_unit_part_a'),(32,'stock_keeping_unit_part_b'),(31,'stock_keeping_unit_part_c'),(84,'tray_gripper_holder_point'),(11,'tray_gripper_holder_pose'),(115,'tray_gripper_holder_x_axis'),(39,'tray_gripper_holder_z_axis'),(202,'work_table_point'),(61,'work_table_pose'),(10,'work_table_x_axis'),(52,'work_table_z_axis'),(98,'x_axis_kit_a2b1c1_a_1'),(97,'x_axis_kit_a2b1c1_a_2'),(90,'x_axis_kit_a2b1c1_b_1'),(83,'x_axis_kit_a2b1c1_c_1'),(173,'x_axis_kit_a2b2c1_a_1'),(175,'x_axis_kit_a2b2c1_a_2'),(186,'x_axis_kit_a2b2c1_b_1'),(185,'x_axis_kit_a2b2c1_b_2'),(181,'x_axis_kit_a2b2c1_c_1'),(121,'z_axis_kit_a2b1c1_a_1'),(120,'z_axis_kit_a2b1c1_a_2'),(170,'z_axis_kit_a2b1c1_b_1'),(36,'z_axis_kit_a2b1c1_c_1'),(95,'z_axis_kit_a2b2c1_a_1'),(72,'z_axis_kit_a2b2c1_a_2'),(201,'z_axis_kit_a2b2c1_b_1'),(203,'z_axis_kit_a2b2c1_b_2'),(206,'z_axis_kit_a2b2c1_c_1');
/*!40000 ALTER TABLE `DataThing` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `EndEffector`
--

DROP TABLE IF EXISTS `EndEffector`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `EndEffector` (
  `EndEffectorID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasEndEffector_Description` varchar(255) NOT NULL,
  `hasEndEffector_Weight` double NOT NULL,
  `hasEffector_MaximumLoadWeight` double NOT NULL,
  `hasEndEffector_Id` varchar(100) NOT NULL,
  `hadByEndEffector_Robot` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`EndEffectorID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByEndEffector_Robot` (`hadByEndEffector_Robot`),
  CONSTRAINT `fkhadByEndEffector_Robot` FOREIGN KEY (`hadByEndEffector_Robot`) REFERENCES `Robot` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `EndEffector`
--

LOCK TABLES `EndEffector` WRITE;
/*!40000 ALTER TABLE `EndEffector` DISABLE KEYS */;
INSERT INTO `EndEffector` VALUES (3,'part_gripper','small single cup vacuum effector',0.01,0,'Thepart_gripper',NULL),(14,'tray_gripper','large single cup vacuum effector',0.04,0,'TheTrayGripper',NULL);
/*!40000 ALTER TABLE `EndEffector` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `EndEffectorChangingStation`
--

DROP TABLE IF EXISTS `EndEffectorChangingStation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `EndEffectorChangingStation` (
  `EndEffectorChangingStationID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`EndEffectorChangingStationID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `EndEffectorChangingStation`
--

LOCK TABLES `EndEffectorChangingStation` WRITE;
/*!40000 ALTER TABLE `EndEffectorChangingStation` DISABLE KEYS */;
INSERT INTO `EndEffectorChangingStation` VALUES (41,'changing_station_1');
/*!40000 ALTER TABLE `EndEffectorChangingStation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `EndEffectorHolder`
--

DROP TABLE IF EXISTS `EndEffectorHolder`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `EndEffectorHolder` (
  `EndEffectorHolderID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hadByEndEffectorHolder_ChangingStation` varchar(255) DEFAULT NULL,
  `hasEndEffectorHolder_EndEffector` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`EndEffectorHolderID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByEndEffectorHolder_ChangingStation` (`hadByEndEffectorHolder_ChangingStation`),
  KEY `fkhasEndEffectorHolder_EndEffector` (`hasEndEffectorHolder_EndEffector`),
  CONSTRAINT `fkhadByEndEffectorHolder_ChangingStation` FOREIGN KEY (`hadByEndEffectorHolder_ChangingStation`) REFERENCES `EndEffectorChangingStation` (`_NAME`),
  CONSTRAINT `fkhasEndEffectorHolder_EndEffector` FOREIGN KEY (`hasEndEffectorHolder_EndEffector`) REFERENCES `EndEffector` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `EndEffectorHolder`
--

LOCK TABLES `EndEffectorHolder` WRITE;
/*!40000 ALTER TABLE `EndEffectorHolder` DISABLE KEYS */;
INSERT INTO `EndEffectorHolder` VALUES (2,'part_gripper_holder',NULL,'part_gripper'),(34,'tray_gripper_holder',NULL,NULL);
/*!40000 ALTER TABLE `EndEffectorHolder` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `GripperEffector`
--

DROP TABLE IF EXISTS `GripperEffector`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `GripperEffector` (
  `GripperEffectorID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`GripperEffectorID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `GripperEffector`
--

LOCK TABLES `GripperEffector` WRITE;
/*!40000 ALTER TABLE `GripperEffector` DISABLE KEYS */;
/*!40000 ALTER TABLE `GripperEffector` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Kit`
--

DROP TABLE IF EXISTS `Kit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Kit` (
  `KitID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasKit_DesignRef` varchar(100) DEFAULT NULL,
  `isKit_Finished` tinyint(1) NOT NULL,
  `hadByKit_LargeBoxWithKits` varchar(255) DEFAULT NULL,
  `hasKit_Tray` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`KitID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByKit_LargeBoxWithKits` (`hadByKit_LargeBoxWithKits`),
  KEY `fkhasKit_Tray` (`hasKit_Tray`),
  CONSTRAINT `fkhadByKit_LargeBoxWithKits` FOREIGN KEY (`hadByKit_LargeBoxWithKits`) REFERENCES `LargeBoxWithKits` (`_NAME`),
  CONSTRAINT `fkhasKit_Tray` FOREIGN KEY (`hasKit_Tray`) REFERENCES `KitTray` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Kit`
--

LOCK TABLES `Kit` WRITE;
/*!40000 ALTER TABLE `Kit` DISABLE KEYS */;
INSERT INTO `Kit` VALUES (44,'kit_a2b2c1','kit_design_a2b2c1',0,'finished_kit_receiver','kit_tray_1');
/*!40000 ALTER TABLE `Kit` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `KitDesign`
--

DROP TABLE IF EXISTS `KitDesign`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `KitDesign` (
  `KitDesignID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasKitDesign_Id` varchar(100) NOT NULL,
  `hasKitDesign_KitTraySkuRef` varchar(100) DEFAULT NULL,
  `hadByKitDesign_Workstation` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`KitDesignID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByKitDesign_Workstation` (`hadByKitDesign_Workstation`),
  CONSTRAINT `fkhadByKitDesign_Workstation` FOREIGN KEY (`hadByKitDesign_Workstation`) REFERENCES `KittingWorkstation` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `KitDesign`
--

LOCK TABLES `KitDesign` WRITE;
/*!40000 ALTER TABLE `KitDesign` DISABLE KEYS */;
INSERT INTO `KitDesign` VALUES (172,'kit_design_a2b1c1','kit_design_a2b1c1','SkuIdKitTray',NULL),(174,'kit_design_a2b2c1','kit_design_a2b2c1','SkuIdKitTray',NULL);
/*!40000 ALTER TABLE `KitDesign` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `KitTray`
--

DROP TABLE IF EXISTS `KitTray`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `KitTray` (
  `KitTrayID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasKitTray_SkuRef` varchar(100) DEFAULT NULL,
  `hasKitTray_SerialNumber` varchar(100) DEFAULT NULL,
  `hadByKitTray_LargeBoxWithEmptyKitTrays` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`KitTrayID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByKitTray_LargeBoxWithEmptyKitTrays` (`hadByKitTray_LargeBoxWithEmptyKitTrays`),
  CONSTRAINT `fkhadByKitTray_LargeBoxWithEmptyKitTrays` FOREIGN KEY (`hadByKitTray_LargeBoxWithEmptyKitTrays`) REFERENCES `LargeBoxWithEmptyKitTrays` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `KitTray`
--

LOCK TABLES `KitTray` WRITE;
/*!40000 ALTER TABLE `KitTray` DISABLE KEYS */;
INSERT INTO `KitTray` VALUES (26,'kit_tray_3','SkuIdKitTray','3',NULL),(27,'kit_tray_2','SkuIdKitTray','2',NULL),(28,'kit_tray_1','SkuIdKitTray','1',NULL);
/*!40000 ALTER TABLE `KitTray` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `KittingWorkstation`
--

DROP TABLE IF EXISTS `KittingWorkstation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `KittingWorkstation` (
  `KittingWorkstationID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasWorkstation_LengthUnit` varchar(20) NOT NULL,
  `hasWorkstation_AngleUnit` varchar(20) NOT NULL,
  `hasWorkstation_WeightUnit` varchar(20) NOT NULL,
  `hasWorkstation_ChangingStation` varchar(255) DEFAULT NULL,
  `hasWorkstation_WorkTable` varchar(255) DEFAULT NULL,
  `hasWorkstation_Robot` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`KittingWorkstationID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasWorkstation_ChangingStation` (`hasWorkstation_ChangingStation`),
  KEY `fkhasWorkstation_WorkTable` (`hasWorkstation_WorkTable`),
  KEY `fkhasWorkstation_Robot` (`hasWorkstation_Robot`),
  CONSTRAINT `fkhasWorkstation_ChangingStation` FOREIGN KEY (`hasWorkstation_ChangingStation`) REFERENCES `EndEffectorChangingStation` (`_NAME`),
  CONSTRAINT `fkhasWorkstation_Robot` FOREIGN KEY (`hasWorkstation_Robot`) REFERENCES `Robot` (`_NAME`),
  CONSTRAINT `fkhasWorkstation_WorkTable` FOREIGN KEY (`hasWorkstation_WorkTable`) REFERENCES `WorkTable` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `KittingWorkstation`
--

LOCK TABLES `KittingWorkstation` WRITE;
/*!40000 ALTER TABLE `KittingWorkstation` DISABLE KEYS */;
INSERT INTO `KittingWorkstation` VALUES (36,'kitting_workstation_1','meter','degree','kilogram','changing_station_1','work_table_1','robot_1');
/*!40000 ALTER TABLE `KittingWorkstation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `LargeBoxWithEmptyKitTrays`
--

DROP TABLE IF EXISTS `LargeBoxWithEmptyKitTrays`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `LargeBoxWithEmptyKitTrays` (
  `LargeBoxWithEmptyKitTraysID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasLargeBoxWithEmptyKitTrays_LargeContainer` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`LargeBoxWithEmptyKitTraysID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasLargeBoxWithEmptyKitTrays_LargeContainer` (`hasLargeBoxWithEmptyKitTrays_LargeContainer`),
  CONSTRAINT `fkhasLargeBoxWithEmptyKitTrays_LargeContainer` FOREIGN KEY (`hasLargeBoxWithEmptyKitTrays_LargeContainer`) REFERENCES `LargeContainer` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `LargeBoxWithEmptyKitTrays`
--

LOCK TABLES `LargeBoxWithEmptyKitTrays` WRITE;
/*!40000 ALTER TABLE `LargeBoxWithEmptyKitTrays` DISABLE KEYS */;
INSERT INTO `LargeBoxWithEmptyKitTrays` VALUES (23,'empty_kit_tray_supply','empty_kit_tray_box');
/*!40000 ALTER TABLE `LargeBoxWithEmptyKitTrays` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `LargeBoxWithKits`
--

DROP TABLE IF EXISTS `LargeBoxWithKits`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `LargeBoxWithKits` (
  `LargeBoxWithKitsID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasLargeBoxWithKits_Capacity` int(11) DEFAULT NULL,
  `hasLargeBoxWithKits_KitDesignRef` varchar(100) DEFAULT NULL,
  `hasLargeBoxWithKits_LargeContainer` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`LargeBoxWithKitsID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasLargeBoxWithKits_LargeContainer` (`hasLargeBoxWithKits_LargeContainer`),
  CONSTRAINT `fkhasLargeBoxWithKits_LargeContainer` FOREIGN KEY (`hasLargeBoxWithKits_LargeContainer`) REFERENCES `LargeContainer` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `LargeBoxWithKits`
--

LOCK TABLES `LargeBoxWithKits` WRITE;
/*!40000 ALTER TABLE `LargeBoxWithKits` DISABLE KEYS */;
INSERT INTO `LargeBoxWithKits` VALUES (31,'finished_kit_receiver',12,'kit_design_a2b1c1','finished_kit_box');
/*!40000 ALTER TABLE `LargeBoxWithKits` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `LargeContainer`
--

DROP TABLE IF EXISTS `LargeContainer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `LargeContainer` (
  `LargeContainerID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasLargeContainer_SkuRef` varchar(100) DEFAULT NULL,
  `hasLargeContainer_SerialNumber` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`LargeContainerID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `LargeContainer`
--

LOCK TABLES `LargeContainer` WRITE;
/*!40000 ALTER TABLE `LargeContainer` DISABLE KEYS */;
INSERT INTO `LargeContainer` VALUES (25,'finished_kit_box','SkuIdKitBox','5'),(29,'empty_kit_tray_box','SkuIdKitBox','4');
/*!40000 ALTER TABLE `LargeContainer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Part`
--

DROP TABLE IF EXISTS `Part`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Part` (
  `PartID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasPart_SkuRef` varchar(100) DEFAULT NULL,
  `hasPart_SerialNumber` varchar(100) DEFAULT NULL,
  `hadByPart_Kit` varchar(255) DEFAULT NULL,
  `hadByPart_PartsTrayWithParts` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`PartID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByPart_Kit` (`hadByPart_Kit`),
  KEY `fkhadByPart_PartsTrayWithParts` (`hadByPart_PartsTrayWithParts`),
  CONSTRAINT `fkhadByPart_Kit` FOREIGN KEY (`hadByPart_Kit`) REFERENCES `Kit` (`_NAME`),
  CONSTRAINT `fkhadByPart_PartsTrayWithParts` FOREIGN KEY (`hadByPart_PartsTrayWithParts`) REFERENCES `PartsTrayWithParts` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Part`
--

LOCK TABLES `Part` WRITE;
/*!40000 ALTER TABLE `Part` DISABLE KEYS */;
INSERT INTO `Part` VALUES (4,'part_c_5','SkuIdPartC','c5',NULL,NULL),(5,'part_c_4','SkuIdPartC','c4',NULL,NULL),(6,'part_c_3','SkuIdPartC','c3',NULL,NULL),(7,'part_c_2','SkuIdPartC','c2',NULL,NULL),(8,'part_c_1','SkuIdPartC','c1',NULL,NULL),(9,'part_c_8','SkuIdPartC','c8',NULL,NULL),(10,'part_c_7','SkuIdPartC','c7',NULL,NULL),(11,'part_c_6','SkuIdPartC','c6',NULL,NULL),(15,'part_b_1','SkuIdPartB','b1',NULL,NULL),(16,'part_b_2','SkuIdPartB','b2',NULL,NULL),(17,'part_b_5','SkuIdPartB','b5',NULL,NULL),(18,'part_b_6','SkuIdPartB','b6',NULL,NULL),(19,'part_b_3','SkuIdPartB','b3',NULL,NULL),(20,'part_b_4','SkuIdPartB','b4',NULL,NULL),(21,'part_b_7','SkuIdPartB','b7',NULL,NULL),(22,'part_b_8','SkuIdPartB','b8',NULL,NULL),(37,'part_a_1','SkuIdPartA','a1',NULL,NULL),(38,'part_a_3','SkuIdPartA','a3',NULL,NULL),(39,'part_a_2','SkuIdPartA','a2',NULL,NULL),(40,'part_a_4','SkuIdPartA','a4',NULL,NULL);
/*!40000 ALTER TABLE `Part` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PartRefAndPose`
--

DROP TABLE IF EXISTS `PartRefAndPose`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PartRefAndPose` (
  `PartRefAndPoseID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasPartRefAndPose_Ref` varchar(100) NOT NULL,
  `hasPartRefAndPose_ZAxis` varchar(255) DEFAULT NULL,
  `hadByPartRefAndPose_KitDesign` varchar(255) DEFAULT NULL,
  `hasPartRefAndPose_Point` varchar(255) DEFAULT NULL,
  `hasPartRefAndPose_XAxis` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`PartRefAndPoseID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasPartRefAndPose_ZAxis` (`hasPartRefAndPose_ZAxis`),
  KEY `fkhadByPartRefAndPose_KitDesign` (`hadByPartRefAndPose_KitDesign`),
  KEY `fkhasPartRefAndPose_Point` (`hasPartRefAndPose_Point`),
  KEY `fkhasPartRefAndPose_XAxis` (`hasPartRefAndPose_XAxis`),
  CONSTRAINT `fkhadByPartRefAndPose_KitDesign` FOREIGN KEY (`hadByPartRefAndPose_KitDesign`) REFERENCES `KitDesign` (`_NAME`),
  CONSTRAINT `fkhasPartRefAndPose_Point` FOREIGN KEY (`hasPartRefAndPose_Point`) REFERENCES `Point` (`_NAME`),
  CONSTRAINT `fkhasPartRefAndPose_XAxis` FOREIGN KEY (`hasPartRefAndPose_XAxis`) REFERENCES `Vector` (`_NAME`),
  CONSTRAINT `fkhasPartRefAndPose_ZAxis` FOREIGN KEY (`hasPartRefAndPose_ZAxis`) REFERENCES `Vector` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PartRefAndPose`
--

LOCK TABLES `PartRefAndPose` WRITE;
/*!40000 ALTER TABLE `PartRefAndPose` DISABLE KEYS */;
INSERT INTO `PartRefAndPose` VALUES (49,'part_ref_and_pose_kit_a2b1c1_a_2','SkuIdPartA','z_axis_kit_a2b1c1_a_2',NULL,'point_kit_a2b1c1_a_2','x_axis_kit_a2b1c1_a_2'),(56,'part_ref_and_pose_kit_a2b1c1_a_1','SkuIdPartA','z_axis_kit_a2b1c1_a_1',NULL,'point_kit_a2b1c1_a_1','x_axis_kit_a2b1c1_a_1'),(60,'part_ref_and_pose_kit_a2b1c1_b_1','SkuIdPartB','z_axis_kit_a2b1c1_b_1',NULL,'point_kit_a2b1c1_b_1','x_axis_kit_a2b1c1_b_1'),(142,'part_ref_and_pose_kit_a2b2c1_c_1','SkuIdPartC','z_axis_kit_a2b2c1_c_1','kit_design_a2b2c1','point_kit_a2b2c1_c_1','x_axis_kit_a2b2c1_c_1'),(144,'part_ref_and_pose_kit_a2b1c1_c_1','SkuIdPartC','z_axis_kit_a2b1c1_c_1',NULL,'point_kit_a2b1c1_c_1','x_axis_kit_a2b1c1_c_1'),(153,'part_ref_and_pose_kit_a2b2c1_a_1','SkuIdPartA','z_axis_kit_a2b2c1_a_1','kit_design_a2b2c1','point_kit_a2b2c1_a_1','x_axis_kit_a2b2c1_a_1'),(154,'part_ref_and_pose_kit_a2b2c1_a_2','SkuIdPartA','z_axis_kit_a2b2c1_a_2','kit_design_a2b2c1','point_kit_a2b2c1_a_2','x_axis_kit_a2b2c1_a_2'),(210,'part_ref_and_pose_kit_a2b2c1_b_2','SkuIdPartB','z_axis_kit_a2b2c1_b_2','kit_design_a2b2c1','point_kit_a2b2c1_b_2','x_axis_kit_a2b2c1_b_2'),(211,'part_ref_and_pose_kit_a2b2c1_b_1','SkuIdPartB','z_axis_kit_a2b2c1_b_1','kit_design_a2b2c1','point_kit_a2b2c1_b_1','x_axis_kit_a2b2c1_b_1');
/*!40000 ALTER TABLE `PartRefAndPose` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PartsBin`
--

DROP TABLE IF EXISTS `PartsBin`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PartsBin` (
  `PartsBinID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasBin_PartQuantity` int(11) NOT NULL,
  `hasBin_PartSkuRef` varchar(100) NOT NULL,
  PRIMARY KEY (`PartsBinID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PartsBin`
--

LOCK TABLES `PartsBin` WRITE;
/*!40000 ALTER TABLE `PartsBin` DISABLE KEYS */;
/*!40000 ALTER TABLE `PartsBin` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PartsTray`
--

DROP TABLE IF EXISTS `PartsTray`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PartsTray` (
  `PartsTrayID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasPartsTray_SkuRef` varchar(100) DEFAULT NULL,
  `hasPartsTray_SerialNumber` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`PartsTrayID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PartsTray`
--

LOCK TABLES `PartsTray` WRITE;
/*!40000 ALTER TABLE `PartsTray` DISABLE KEYS */;
INSERT INTO `PartsTray` VALUES (1,'part_b_tray','SkuIdPartsTray','7'),(13,'part_a_tray','SkuIdPartsTray','6'),(24,'part_c_tray','SkuIdPartsTray','8');
/*!40000 ALTER TABLE `PartsTray` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PartsTrayWithParts`
--

DROP TABLE IF EXISTS `PartsTrayWithParts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PartsTrayWithParts` (
  `PartsTrayWithPartsID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasPartsTrayWithParts_Tray` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`PartsTrayWithPartsID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasPartsTrayWithParts_Tray` (`hasPartsTrayWithParts_Tray`),
  CONSTRAINT `fkhasPartsTrayWithParts_Tray` FOREIGN KEY (`hasPartsTrayWithParts_Tray`) REFERENCES `PartsTray` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PartsTrayWithParts`
--

LOCK TABLES `PartsTrayWithParts` WRITE;
/*!40000 ALTER TABLE `PartsTrayWithParts` DISABLE KEYS */;
INSERT INTO `PartsTrayWithParts` VALUES (30,'part_a_supply','part_a_tray'),(32,'part_b_supply','part_b_tray'),(12,'part_c_supply','part_c_tray');
/*!40000 ALTER TABLE `PartsTrayWithParts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PhysicalLocation`
--

DROP TABLE IF EXISTS `PhysicalLocation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PhysicalLocation` (
  `PhysicalLocationID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasPhysicalLocation_RefObject` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`PhysicalLocationID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasPhysicalLocation_RefObject` (`hasPhysicalLocation_RefObject`),
  CONSTRAINT `fkhasPhysicalLocation_RefObject` FOREIGN KEY (`hasPhysicalLocation_RefObject`) REFERENCES `SolidObject` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PhysicalLocation`
--

LOCK TABLES `PhysicalLocation` WRITE;
/*!40000 ALTER TABLE `PhysicalLocation` DISABLE KEYS */;
INSERT INTO `PhysicalLocation` VALUES (11,'tray_gripper_holder_pose','changing_station_1'),(21,'part_gripper_holder_pose','changing_station_1'),(87,'kit_tray_3_pose','empty_kit_tray_box'),(113,'kit_tray_1_pose','empty_kit_tray_box'),(209,'kit_tray_2_pose','empty_kit_tray_box'),(177,'empty_kit_tray_box_pose','empty_kit_tray_supply'),(160,'finished_kit_box_pose','finished_kit_receiver'),(3,'robot_pose','kitting_workstation_1'),(7,'finished_kit_receiver_pose','kitting_workstation_1'),(14,'part_b_supply_pose','kitting_workstation_1'),(61,'work_table_pose','kitting_workstation_1'),(122,'relative_location_in_1','kitting_workstation_1'),(166,'part_c_supply_pose','kitting_workstation_1'),(169,'changing_station_pose','kitting_workstation_1'),(178,'part_a_supply_pose','kitting_workstation_1'),(187,'empty_kit_tray_supply_pose','kitting_workstation_1'),(210,'kit_a2b2c1_pose','kit_a2b2c1'),(19,'part_a_tray_pose','part_a_supply'),(26,'part_a_1_pose','part_a_tray'),(43,'part_a_2_pose','part_a_tray'),(147,'part_a_4_pose','part_a_tray'),(155,'part_a_3_pose','part_a_tray'),(59,'part_b_tray_pose','part_b_supply'),(1,'part_b_2_pose','part_b_tray'),(5,'part_b_3_pose','part_b_tray'),(8,'part_b_5_pose','part_b_tray'),(9,'part_b_4_pose','part_b_tray'),(37,'part_b_7_pose','part_b_tray'),(54,'part_b_8_pose','part_b_tray'),(68,'part_b_6_pose','part_b_tray'),(79,'part_b_1_pose','part_b_tray'),(109,'part_c_tray_pose','part_c_supply'),(12,'part_c_4_pose','part_c_tray'),(75,'part_c_7_pose','part_c_tray'),(85,'part_c_8_pose','part_c_tray'),(86,'part_c_5_pose','part_c_tray'),(140,'part_c_2_pose','part_c_tray'),(143,'part_c_6_pose','part_c_tray'),(150,'part_c_3_pose','part_c_tray'),(204,'part_c_1_pose','part_c_tray'),(23,'part_gripper_pose','part_gripper_holder'),(171,'relative_location_on_1','robot_1');
/*!40000 ALTER TABLE `PhysicalLocation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Point`
--

DROP TABLE IF EXISTS `Point`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Point` (
  `PointID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasPoint_X` double NOT NULL,
  `hasPoint_Y` double NOT NULL,
  `hasPoint_Z` double NOT NULL,
  PRIMARY KEY (`PointID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Point`
--

LOCK TABLES `Point` WRITE;
/*!40000 ALTER TABLE `Point` DISABLE KEYS */;
INSERT INTO `Point` VALUES (16,'point_kit_a2b1c1_a_2',0.4,0.3,0),(17,'point_kit_a2b1c1_a_1',0.2,0.3,0),(28,'part_c_6_point',0.33,-0.216,0.035),(38,'point_min',-1,-1,0),(47,'part_c_3_point',-0.11,0.216,0.035),(51,'part_b_1_point',-0.08,0.12,0.0675),(55,'part_b_6_point',-0.24,-0.12,0.0675),(63,'part_a_1_point',0.159,0.159,0.0275),(64,'point_kit_a2b2c1_a_2',-0.159,-0.149,0.036),(66,'point_kit_a2b2c1_a_1',-0.159,0.145,0.036),(70,'empty_kit_tray_supply_point',0.5,0,0),(74,'point_kit_a2b2c1_c_1',0.06,-0.09,0.045),(80,'part_c_1_point',0.11,0.216,0.035),(84,'tray_gripper_holder_point',-0.25,0,0.5),(88,'part_b_2_point',-0.24,0.12,0.0675),(89,'part_gripper_point',0,0,0),(92,'finished_kit_box_point',0,0,0),(96,'part_c_4_point',-0.33,0.216,0.035),(99,'part_c_8_point',-0.33,-0.216,0.035),(102,'part_b_4_point',0.24,0.12,0.0675),(105,'part_c_5_point',0.11,-0.216,0.035),(110,'part_c_tray_point',0,0,0),(111,'kit_tray_3_point',0,0,0.3),(118,'part_b_3_point',0.08,0.12,0.0675),(119,'part_a_4_point',-0.159,0.159,0.0275),(124,'part_b_supply_point',5.5,0,0),(125,'point_kit_a2b2c1_b_2',0.171,0.215,0.08),(126,'point_kit_a2b2c1_b_1',0.219,-0.166,0.08),(129,'point_kit_a2b1c1_c_1',0.4,0.5,0),(130,'part_b_8_point',0.24,-0.12,0.0675),(132,'part_c_2_point',0.33,0.216,0.035),(134,'kit_tray_2_point',0,0,0.15),(135,'part_gripper_holder_point',0.25,0,0.5),(137,'part_c_7_point',-0.11,-0.216,0.035),(138,'point_max',1,1,2),(145,'part_a_3_point',-0.159,-0.159,0.0275),(148,'part_b_tray_point',0,0,0),(158,'part_c_supply_point',6.5,0,0),(165,'part_b_7_point',0.08,-0.12,0.0675),(167,'part_a_tray_point',0,0,0),(179,'finished_kit_receiver_point',1.5,0,0),(189,'robot_point',3,0,2),(194,'part_a_2_point',0.159,-0.159,0.0275),(196,'point_kit_a2b1c1_b_1',0.2,0.5,0),(198,'kit_tray_1_point',0,0,0),(200,'empty_kit_tray_box_point',0.5,0,0),(202,'work_table_point',3,0,0),(205,'changing_station_point',7.5,0,0),(207,'part_a_supply_point',4.5,0,0),(208,'part_b_5_point',-0.08,-0.12,0.0675);
/*!40000 ALTER TABLE `Point` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PoseLocation`
--

DROP TABLE IF EXISTS `PoseLocation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PoseLocation` (
  `PoseLocationID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasPoseLocation_Point` varchar(255) DEFAULT NULL,
  `hasPoseLocation_ZAxis` varchar(255) DEFAULT NULL,
  `hasPoseLocation_XAxis` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`PoseLocationID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasPoseLocation_Point` (`hasPoseLocation_Point`),
  KEY `fkhasPoseLocation_ZAxis` (`hasPoseLocation_ZAxis`),
  KEY `fkhasPoseLocation_XAxis` (`hasPoseLocation_XAxis`),
  CONSTRAINT `fkhasPoseLocation_Point` FOREIGN KEY (`hasPoseLocation_Point`) REFERENCES `Point` (`_NAME`),
  CONSTRAINT `fkhasPoseLocation_XAxis` FOREIGN KEY (`hasPoseLocation_XAxis`) REFERENCES `Vector` (`_NAME`),
  CONSTRAINT `fkhasPoseLocation_ZAxis` FOREIGN KEY (`hasPoseLocation_ZAxis`) REFERENCES `Vector` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PoseLocation`
--

LOCK TABLES `PoseLocation` WRITE;
/*!40000 ALTER TABLE `PoseLocation` DISABLE KEYS */;
INSERT INTO `PoseLocation` VALUES (1,'part_b_2_pose','part_b_2_point','part_b_2_z_axis','part_b_2_x_axis'),(3,'robot_pose','robot_point','robot_z_axis','robot_x_axis'),(5,'part_b_3_pose','part_b_3_point','part_b_3_z_axis','part_b_3_x_axis'),(7,'finished_kit_receiver_pose','finished_kit_receiver_point','finished_kit_receiver_z_axis','finished_kit_receiver_x_axis'),(8,'part_b_5_pose','part_b_5_point','part_b_5_z_axis','part_b_5_x_axis'),(9,'part_b_4_pose','part_b_4_point','part_b_4_z_axis','part_b_4_x_axis'),(11,'tray_gripper_holder_pose','tray_gripper_holder_point','tray_gripper_holder_z_axis','tray_gripper_holder_x_axis'),(12,'part_c_4_pose','part_c_4_point','part_c_4_z_axis','part_c_4_x_axis'),(14,'part_b_supply_pose','part_b_supply_point','part_b_supply_z_axis','part_b_supply_x_axis'),(19,'part_a_tray_pose','part_a_tray_point','part_a_tray_z_axis','part_a_tray_x_axis'),(21,'part_gripper_holder_pose','part_gripper_holder_point','part_gripper_holder_z_axis','part_gripper_holder_x_axis'),(23,'part_gripper_pose','part_gripper_point','part_gripper_z_axis','part_gripper_x_axis'),(26,'part_a_1_pose','part_a_1_point','part_a_1_z_axis','part_a_1_x_axis'),(37,'part_b_7_pose','part_b_7_point','part_b_7_z_axis','part_b_7_x_axis'),(43,'part_a_2_pose','part_a_2_point','part_a_2_z_axis','part_a_2_x_axis'),(54,'part_b_8_pose','part_b_8_point','part_b_8_z_axis','part_b_8_x_axis'),(59,'part_b_tray_pose','part_b_tray_point','part_b_tray_z_axis','part_b_tray_x_axis'),(61,'work_table_pose','work_table_point','work_table_z_axis','work_table_x_axis'),(68,'part_b_6_pose','part_b_6_point','part_b_6_z_axis','part_b_6_x_axis'),(75,'part_c_7_pose','part_c_7_point','part_c_7_z_axis','part_c_7_x_axis'),(79,'part_b_1_pose','part_b_1_point','part_b_1_z_axis','part_b_1_x_axis'),(85,'part_c_8_pose','part_c_8_point','part_c_8_z_axis','part_c_8_x_axis'),(86,'part_c_5_pose','part_c_5_point','part_c_5_z_axis','part_c_5_x_axis'),(87,'kit_tray_3_pose','kit_tray_3_point','kit_tray_3_z_axis','kit_tray_3_x_axis'),(109,'part_c_tray_pose','part_c_tray_point','part_c_tray_z_axis','part_c_tray_x_axis'),(113,'kit_tray_1_pose','kit_tray_1_point','kit_tray_1_z_axis','kit_tray_1_x_axis'),(140,'part_c_2_pose','part_c_2_point','part_c_2_z_axis','part_c_2_x_axis'),(143,'part_c_6_pose','part_c_6_point','part_c_6_z_axis','part_c_6_x_axis'),(147,'part_a_4_pose','part_a_4_point','part_a_4_z_axis','part_a_4_x_axis'),(150,'part_c_3_pose','part_c_3_point','part_c_3_z_axis','part_c_3_x_axis'),(155,'part_a_3_pose','part_a_3_point','part_a_3_z_axis','part_a_3_x_axis'),(160,'finished_kit_box_pose','finished_kit_box_point','finished_kit_box_z_axis','finished_kit_box_x_axis'),(166,'part_c_supply_pose','part_c_supply_point','part_c_supply_z_axis','part_c_supply_x_axis'),(169,'changing_station_pose','changing_station_point','changing_station_z_axis','changing_station_x_axis'),(177,'empty_kit_tray_box_pose','empty_kit_tray_box_point','empty_kit_tray_box_z_axis','empty_kit_tray_box_x_axis'),(178,'part_a_supply_pose','part_a_supply_point','part_a_supply_z_axis','part_a_supply_x_axis'),(187,'empty_kit_tray_supply_pose','empty_kit_tray_supply_point','empty_kit_tray_supply_z_axis','empty_kit_tray_supply_x_axis'),(204,'part_c_1_pose','part_c_1_point','part_c_1_z_axis','part_c_1_x_axis'),(209,'kit_tray_2_pose','kit_tray_2_point','kit_tray_2_z_axis','kit_tray_2_x_axis');
/*!40000 ALTER TABLE `PoseLocation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PoseLocationIn`
--

DROP TABLE IF EXISTS `PoseLocationIn`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PoseLocationIn` (
  `PoseLocationInID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`PoseLocationInID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PoseLocationIn`
--

LOCK TABLES `PoseLocationIn` WRITE;
/*!40000 ALTER TABLE `PoseLocationIn` DISABLE KEYS */;
INSERT INTO `PoseLocationIn` VALUES (26,'part_a_1_pose'),(43,'part_a_2_pose'),(155,'part_a_3_pose'),(147,'part_a_4_pose'),(79,'part_b_1_pose'),(1,'part_b_2_pose'),(5,'part_b_3_pose'),(9,'part_b_4_pose'),(8,'part_b_5_pose'),(68,'part_b_6_pose'),(37,'part_b_7_pose'),(54,'part_b_8_pose'),(204,'part_c_1_pose'),(140,'part_c_2_pose'),(150,'part_c_3_pose'),(12,'part_c_4_pose'),(86,'part_c_5_pose'),(143,'part_c_6_pose'),(75,'part_c_7_pose'),(85,'part_c_8_pose');
/*!40000 ALTER TABLE `PoseLocationIn` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PoseLocationOn`
--

DROP TABLE IF EXISTS `PoseLocationOn`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PoseLocationOn` (
  `PoseLocationOnID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`PoseLocationOnID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PoseLocationOn`
--

LOCK TABLES `PoseLocationOn` WRITE;
/*!40000 ALTER TABLE `PoseLocationOn` DISABLE KEYS */;
/*!40000 ALTER TABLE `PoseLocationOn` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PoseOnlyLocation`
--

DROP TABLE IF EXISTS `PoseOnlyLocation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PoseOnlyLocation` (
  `PoseOnlyLocationID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`PoseOnlyLocationID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PoseOnlyLocation`
--

LOCK TABLES `PoseOnlyLocation` WRITE;
/*!40000 ALTER TABLE `PoseOnlyLocation` DISABLE KEYS */;
INSERT INTO `PoseOnlyLocation` VALUES (169,'changing_station_pose'),(177,'empty_kit_tray_box_pose'),(187,'empty_kit_tray_supply_pose'),(160,'finished_kit_box_pose'),(7,'finished_kit_receiver_pose'),(113,'kit_tray_1_pose'),(209,'kit_tray_2_pose'),(87,'kit_tray_3_pose'),(178,'part_a_supply_pose'),(19,'part_a_tray_pose'),(14,'part_b_supply_pose'),(59,'part_b_tray_pose'),(166,'part_c_supply_pose'),(109,'part_c_tray_pose'),(21,'part_gripper_holder_pose'),(23,'part_gripper_pose'),(3,'robot_pose'),(11,'tray_gripper_holder_pose'),(61,'work_table_pose');
/*!40000 ALTER TABLE `PoseOnlyLocation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `RelativeLocation`
--

DROP TABLE IF EXISTS `RelativeLocation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `RelativeLocation` (
  `RelativeLocationID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasRelativeLocation_Description` varchar(255) NOT NULL,
  PRIMARY KEY (`RelativeLocationID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `RelativeLocation`
--

LOCK TABLES `RelativeLocation` WRITE;
/*!40000 ALTER TABLE `RelativeLocation` DISABLE KEYS */;
INSERT INTO `RelativeLocation` VALUES (122,'relative_location_in_1','The  KittingWorkstation is in kitting_workstation_1'),(171,'relative_location_on_1','The tray_gripper is on robot_1');
/*!40000 ALTER TABLE `RelativeLocation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `RelativeLocationIn`
--

DROP TABLE IF EXISTS `RelativeLocationIn`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `RelativeLocationIn` (
  `RelativeLocationInID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`RelativeLocationInID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `RelativeLocationIn`
--

LOCK TABLES `RelativeLocationIn` WRITE;
/*!40000 ALTER TABLE `RelativeLocationIn` DISABLE KEYS */;
INSERT INTO `RelativeLocationIn` VALUES (122,'relative_location_in_1');
/*!40000 ALTER TABLE `RelativeLocationIn` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `RelativeLocationOn`
--

DROP TABLE IF EXISTS `RelativeLocationOn`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `RelativeLocationOn` (
  `RelativeLocationOnID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`RelativeLocationOnID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `RelativeLocationOn`
--

LOCK TABLES `RelativeLocationOn` WRITE;
/*!40000 ALTER TABLE `RelativeLocationOn` DISABLE KEYS */;
INSERT INTO `RelativeLocationOn` VALUES (171,'relative_location_on_1');
/*!40000 ALTER TABLE `RelativeLocationOn` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Robot`
--

DROP TABLE IF EXISTS `Robot`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Robot` (
  `RobotID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasRobot_Description` varchar(255) NOT NULL,
  `hasRobot_Id` varchar(100) NOT NULL,
  `hasRobot_MaximumLoadWeight` double NOT NULL,
  PRIMARY KEY (`RobotID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Robot`
--

LOCK TABLES `Robot` WRITE;
/*!40000 ALTER TABLE `Robot` DISABLE KEYS */;
INSERT INTO `Robot` VALUES (35,'robot_1','this is the robot','robot_1',7);
/*!40000 ALTER TABLE `Robot` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ShapeDesign`
--

DROP TABLE IF EXISTS `ShapeDesign`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ShapeDesign` (
  `ShapeDesignID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasShapeDesign_Description` varchar(255) NOT NULL,
  PRIMARY KEY (`ShapeDesignID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ShapeDesign`
--

LOCK TABLES `ShapeDesign` WRITE;
/*!40000 ALTER TABLE `ShapeDesign` DISABLE KEYS */;
INSERT INTO `ShapeDesign` VALUES (24,'shape_parts_tray','Shape of PartsTrays'),(41,'shape_part_a','Shape of PartA'),(42,'shape_part_b','Shape of PartB'),(45,'shape_part_c','Shape of PartC'),(46,'shape_kit_box','Shape of boxes to hold kits and kit trays'),(103,'shape_kit_tray','Shape of KitTrays');
/*!40000 ALTER TABLE `ShapeDesign` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `SolidObject`
--

DROP TABLE IF EXISTS `SolidObject`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `SolidObject` (
  `SolidObjectID` int(11) NOT NULL AUTO_INCREMENT,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasSolidObject_PrimaryLocation` varchar(255) DEFAULT NULL,
  `hadBySolidObject_WorkTable` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`SolidObjectID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasSolidObject_PrimaryLocation` (`hasSolidObject_PrimaryLocation`),
  KEY `fkhadBySolidObject_WorkTable` (`hadBySolidObject_WorkTable`),
  CONSTRAINT `fkhadBySolidObject_WorkTable` FOREIGN KEY (`hadBySolidObject_WorkTable`) REFERENCES `WorkTable` (`_NAME`),
  CONSTRAINT `fkhasSolidObject_PrimaryLocation` FOREIGN KEY (`hasSolidObject_PrimaryLocation`) REFERENCES `PhysicalLocation` (`_NAME`)
) ENGINE=InnoDB AUTO_INCREMENT=45 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `SolidObject`
--

LOCK TABLES `SolidObject` WRITE;
/*!40000 ALTER TABLE `SolidObject` DISABLE KEYS */;
INSERT INTO `SolidObject` VALUES (1,'part_b_tray','part_b_tray_pose',NULL),(2,'part_gripper_holder','part_gripper_holder_pose',NULL),(3,'part_gripper','part_gripper_pose',NULL),(4,'part_c_5','part_c_5_pose',NULL),(5,'part_c_4','part_c_4_pose',NULL),(6,'part_c_3','part_c_3_pose',NULL),(7,'part_c_2','part_c_2_pose',NULL),(8,'part_c_1','part_c_1_pose',NULL),(9,'part_c_8','part_c_8_pose',NULL),(10,'part_c_7','part_c_7_pose',NULL),(11,'part_c_6','part_c_6_pose',NULL),(12,'part_c_supply','part_c_supply_pose',NULL),(13,'part_a_tray','part_a_tray_pose',NULL),(14,'tray_gripper','relative_location_on_1',NULL),(15,'part_b_1','part_b_1_pose',NULL),(16,'part_b_2','part_b_2_pose',NULL),(17,'part_b_5','part_b_5_pose',NULL),(18,'part_b_6','part_b_6_pose',NULL),(19,'part_b_3','part_b_3_pose',NULL),(20,'part_b_4','part_b_4_pose',NULL),(21,'part_b_7','part_b_7_pose',NULL),(22,'part_b_8','part_b_8_pose',NULL),(23,'empty_kit_tray_supply','empty_kit_tray_supply_pose',NULL),(24,'part_c_tray','part_c_tray_pose',NULL),(25,'finished_kit_box','finished_kit_box_pose',NULL),(26,'kit_tray_3','kit_tray_3_pose',NULL),(27,'kit_tray_2','kit_tray_2_pose',NULL),(28,'kit_tray_1','kit_tray_1_pose',NULL),(29,'empty_kit_tray_box','empty_kit_tray_box_pose',NULL),(30,'part_a_supply','part_a_supply_pose',NULL),(31,'finished_kit_receiver','finished_kit_receiver_pose',NULL),(32,'part_b_supply','part_b_supply_pose',NULL),(33,'work_table_1','work_table_pose',NULL),(34,'tray_gripper_holder','tray_gripper_holder_pose',NULL),(35,'robot_1','robot_pose',NULL),(36,'kitting_workstation_1','relative_location_in_1',NULL),(37,'part_a_1','part_a_1_pose',NULL),(38,'part_a_3','part_a_3_pose',NULL),(39,'part_a_2','part_a_2_pose',NULL),(40,'part_a_4','part_a_4_pose',NULL),(41,'changing_station_1','changing_station_pose',NULL),(44,'kit_a2b2c1','kit_a2b2c1_pose','work_table_1');
/*!40000 ALTER TABLE `SolidObject` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `StockKeepingUnit`
--

DROP TABLE IF EXISTS `StockKeepingUnit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `StockKeepingUnit` (
  `StockKeepingUnitID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasSku_Description` varchar(255) NOT NULL,
  `hasSku_Id` varchar(100) NOT NULL,
  `hasSku_Weight` double NOT NULL,
  `hadBySku_Workstation` varchar(255) DEFAULT NULL,
  `hasSku_Shape` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`StockKeepingUnitID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadBySku_Workstation` (`hadBySku_Workstation`),
  KEY `fkhasSku_Shape` (`hasSku_Shape`),
  CONSTRAINT `fkhadBySku_Workstation` FOREIGN KEY (`hadBySku_Workstation`) REFERENCES `KittingWorkstation` (`_NAME`),
  CONSTRAINT `fkhasSku_Shape` FOREIGN KEY (`hasSku_Shape`) REFERENCES `ShapeDesign` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `StockKeepingUnit`
--

LOCK TABLES `StockKeepingUnit` WRITE;
/*!40000 ALTER TABLE `StockKeepingUnit` DISABLE KEYS */;
INSERT INTO `StockKeepingUnit` VALUES (4,'stock_keeping_unit_part_a','SKU for Part A','SkuIdPartA',0.18,NULL,'shape_part_a'),(15,'stock_keeping_unit_kit_tray','SKU for KitTrays','SkuIdKitTray',0.2,NULL,'shape_kit_tray'),(31,'stock_keeping_unit_part_c','SKU for PartC','SkuIdPartC',0.18,NULL,'shape_part_c'),(32,'stock_keeping_unit_part_b','SKU for PartB','SkuIdPartB',0.18,NULL,'shape_part_b'),(35,'stock_keeping_unit_kit_box','SKU for Boxes for Kits and KitTrays','SkuIdKitBox',1.2,NULL,'shape_kit_box'),(93,'stock_keeping_unit_parts_tray','SKU for PartsTrays','SkuIdPartsTray',0.2,NULL,'shape_parts_tray');
/*!40000 ALTER TABLE `StockKeepingUnit` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `VacuumEffector`
--

DROP TABLE IF EXISTS `VacuumEffector`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `VacuumEffector` (
  `VacuumEffectorID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasVacuumEffector_CupDiameter` double NOT NULL,
  `hasVacuumEffector_Length` double NOT NULL,
  PRIMARY KEY (`VacuumEffectorID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `VacuumEffector`
--

LOCK TABLES `VacuumEffector` WRITE;
/*!40000 ALTER TABLE `VacuumEffector` DISABLE KEYS */;
INSERT INTO `VacuumEffector` VALUES (3,'part_gripper',0.02,0.025),(14,'tray_gripper',0.04,0.1);
/*!40000 ALTER TABLE `VacuumEffector` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `VacuumEffectorMultiCup`
--

DROP TABLE IF EXISTS `VacuumEffectorMultiCup`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `VacuumEffectorMultiCup` (
  `VacuumEffectorMultiCupID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasMultiCup_ArrayNumber` int(11) NOT NULL,
  `hasMultiCup_ArrayRadius` double NOT NULL,
  PRIMARY KEY (`VacuumEffectorMultiCupID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `VacuumEffectorMultiCup`
--

LOCK TABLES `VacuumEffectorMultiCup` WRITE;
/*!40000 ALTER TABLE `VacuumEffectorMultiCup` DISABLE KEYS */;
/*!40000 ALTER TABLE `VacuumEffectorMultiCup` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `VacuumEffectorSingleCup`
--

DROP TABLE IF EXISTS `VacuumEffectorSingleCup`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `VacuumEffectorSingleCup` (
  `VacuumEffectorSingleCupID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`VacuumEffectorSingleCupID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `VacuumEffectorSingleCup`
--

LOCK TABLES `VacuumEffectorSingleCup` WRITE;
/*!40000 ALTER TABLE `VacuumEffectorSingleCup` DISABLE KEYS */;
INSERT INTO `VacuumEffectorSingleCup` VALUES (3,'part_gripper'),(14,'tray_gripper');
/*!40000 ALTER TABLE `VacuumEffectorSingleCup` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Vector`
--

DROP TABLE IF EXISTS `Vector`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Vector` (
  `VectorID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasVector_K` double NOT NULL,
  `hasVector_J` double NOT NULL,
  `hasVector_I` double NOT NULL,
  PRIMARY KEY (`VectorID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Vector`
--

LOCK TABLES `Vector` WRITE;
/*!40000 ALTER TABLE `Vector` DISABLE KEYS */;
INSERT INTO `Vector` VALUES (2,'part_c_4_z_axis',1,0,0),(6,'empty_kit_tray_supply_x_axis',0,0,1),(10,'work_table_x_axis',0,0,1),(13,'part_c_2_z_axis',1,0,0),(18,'kit_tray_3_z_axis',1,0,0),(20,'part_c_6_x_axis',0,0,1),(22,'part_gripper_x_axis',0,0,1),(25,'part_a_4_z_axis',1,0,0),(27,'part_b_4_z_axis',1,0,0),(29,'part_b_2_z_axis',1,0,0),(30,'part_b_2_x_axis',0,0,1),(33,'part_b_supply_x_axis',0,0,1),(34,'finished_kit_box_x_axis',0,0,1),(36,'z_axis_kit_a2b1c1_c_1',1,0,0),(39,'tray_gripper_holder_z_axis',1,0,0),(40,'part_a_tray_x_axis',0,0,1),(44,'part_c_4_x_axis',0,0,1),(48,'part_gripper_holder_x_axis',0,0,1),(50,'part_a_2_z_axis',1,0,0),(52,'work_table_z_axis',1,0,0),(53,'part_b_7_x_axis',0,0,1),(57,'changing_station_z_axis',1,0,0),(58,'part_c_1_x_axis',0,0,1),(62,'part_a_supply_x_axis',0,0,1),(65,'part_c_3_z_axis',1,0,0),(67,'kit_tray_2_z_axis',1,0,0),(69,'changing_station_x_axis',0,0,1),(71,'kit_tray_1_x_axis',0,0,1),(72,'z_axis_kit_a2b2c1_a_2',1,0,0),(73,'kit_tray_2_x_axis',0,0,1),(76,'part_gripper_holder_z_axis',1,0,0),(77,'part_gripper_z_axis',1,0,0),(78,'part_b_3_z_axis',1,0,0),(81,'robot_x_axis',0,0,1),(82,'part_c_8_x_axis',0,0,1),(83,'x_axis_kit_a2b1c1_c_1',0,0,1),(90,'x_axis_kit_a2b1c1_b_1',0,0,1),(91,'part_a_tray_z_axis',1,0,0),(94,'part_c_8_z_axis',1,0,0),(95,'z_axis_kit_a2b2c1_a_1',1,0,0),(97,'x_axis_kit_a2b1c1_a_2',0,0,1),(98,'x_axis_kit_a2b1c1_a_1',0,0,1),(100,'part_b_6_x_axis',0,0,1),(101,'part_a_3_x_axis',0,0,1),(104,'part_b_8_z_axis',1,0,0),(106,'part_b_5_z_axis',1,0,0),(107,'part_c_2_x_axis',0,0,1),(108,'part_c_7_z_axis',1,0,0),(112,'part_c_tray_z_axis',1,0,0),(114,'part_b_supply_z_axis',1,0,0),(115,'tray_gripper_holder_x_axis',0,0,1),(116,'part_c_7_x_axis',0,0,1),(117,'part_b_7_z_axis',1,0,0),(120,'z_axis_kit_a2b1c1_a_2',1,0,0),(121,'z_axis_kit_a2b1c1_a_1',1,0,0),(123,'finished_kit_receiver_x_axis',0,0,1),(127,'part_a_supply_z_axis',1,0,0),(128,'kit_tray_3_x_axis',0,0,1),(131,'part_b_4_x_axis',0,0,1),(133,'part_b_5_x_axis',0,0,1),(136,'part_b_8_x_axis',0,0,1),(139,'part_c_6_z_axis',1,0,0),(141,'part_b_1_z_axis',1,0,0),(149,'empty_kit_tray_box_z_axis',1,0,0),(151,'part_c_5_z_axis',1,0,0),(152,'part_b_6_z_axis',1,0,0),(156,'part_a_4_x_axis',0,0,1),(157,'part_a_1_z_axis',1,0,0),(159,'part_b_3_x_axis',0,0,1),(161,'part_c_supply_z_axis',1,0,0),(162,'finished_kit_receiver_z_axis',1,0,0),(163,'empty_kit_tray_supply_z_axis',1,0,0),(164,'part_a_3_z_axis',1,0,0),(168,'part_b_1_x_axis',0,0,1),(170,'z_axis_kit_a2b1c1_b_1',1,0,0),(173,'x_axis_kit_a2b2c1_a_1',0,0,1),(175,'x_axis_kit_a2b2c1_a_2',0,0,1),(176,'part_c_3_x_axis',0,0,1),(180,'part_a_2_x_axis',0,0,1),(181,'x_axis_kit_a2b2c1_c_1',0,0,1),(182,'part_c_1_z_axis',1,0,0),(183,'part_a_1_x_axis',0,0,1),(184,'part_b_tray_x_axis',0,0,1),(185,'x_axis_kit_a2b2c1_b_2',0,1,0),(186,'x_axis_kit_a2b2c1_b_1',0,0,1),(188,'finished_kit_box_z_axis',1,0,0),(190,'part_c_5_x_axis',0,0,1),(191,'part_c_supply_x_axis',0,0,1),(192,'empty_kit_tray_box_x_axis',0,0,1),(193,'robot_z_axis',1,0,0),(195,'part_b_tray_z_axis',1,0,0),(197,'part_c_tray_x_axis',0,0,1),(199,'kit_tray_1_z_axis',1,0,0),(201,'z_axis_kit_a2b2c1_b_1',1,0,0),(203,'z_axis_kit_a2b2c1_b_2',1,0,0),(206,'z_axis_kit_a2b2c1_c_1',1,0,0);
/*!40000 ALTER TABLE `Vector` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `WorkTable`
--

DROP TABLE IF EXISTS `WorkTable`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `WorkTable` (
  `WorkTableID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`WorkTableID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `WorkTable`
--

LOCK TABLES `WorkTable` WRITE;
/*!40000 ALTER TABLE `WorkTable` DISABLE KEYS */;
INSERT INTO `WorkTable` VALUES (33,'work_table_1');
/*!40000 ALTER TABLE `WorkTable` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `hasEffector_MaximimLoadWeightValue`
--

DROP TABLE IF EXISTS `hasEffector_MaximimLoadWeightValue`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hasEffector_MaximimLoadWeightValue` (
  `VacuumEffectorID` int(11) NOT NULL,
  `hasEffector_MaximimLoadWeight` varchar(255) NOT NULL,
  PRIMARY KEY (`VacuumEffectorID`,`hasEffector_MaximimLoadWeight`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hasEffector_MaximimLoadWeightValue`
--

LOCK TABLES `hasEffector_MaximimLoadWeightValue` WRITE;
/*!40000 ALTER TABLE `hasEffector_MaximimLoadWeightValue` DISABLE KEYS */;
/*!40000 ALTER TABLE `hasEffector_MaximimLoadWeightValue` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `hasRobot_WorkVolume`
--

DROP TABLE IF EXISTS `hasRobot_WorkVolume`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hasRobot_WorkVolume` (
  `RobotID` int(11) NOT NULL,
  `BoxVolumeID` int(11) NOT NULL,
  PRIMARY KEY (`RobotID`,`BoxVolumeID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hasRobot_WorkVolume`
--

LOCK TABLES `hasRobot_WorkVolume` WRITE;
/*!40000 ALTER TABLE `hasRobot_WorkVolume` DISABLE KEYS */;
INSERT INTO `hasRobot_WorkVolume` VALUES (35,146);
/*!40000 ALTER TABLE `hasRobot_WorkVolume` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `hasSku_EndEffectorRefsValue`
--

DROP TABLE IF EXISTS `hasSku_EndEffectorRefsValue`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hasSku_EndEffectorRefsValue` (
  `StockKeepingUnitID` int(11) NOT NULL,
  `hasSku_EndEffectorRefs` varchar(100) NOT NULL,
  PRIMARY KEY (`StockKeepingUnitID`,`hasSku_EndEffectorRefs`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hasSku_EndEffectorRefsValue`
--

LOCK TABLES `hasSku_EndEffectorRefsValue` WRITE;
/*!40000 ALTER TABLE `hasSku_EndEffectorRefsValue` DISABLE KEYS */;
INSERT INTO `hasSku_EndEffectorRefsValue` VALUES (4,'ThePartGripper'),(15,'TheTrayGripper'),(31,'ThePartGripper'),(32,'ThePartGripper'),(93,'TheTrayGripper');
/*!40000 ALTER TABLE `hasSku_EndEffectorRefsValue` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `hasSolidObject_SecondaryLocation`
--

DROP TABLE IF EXISTS `hasSolidObject_SecondaryLocation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hasSolidObject_SecondaryLocation` (
  `SolidObjectID` int(11) NOT NULL,
  `PhysicalLocationID` int(11) NOT NULL,
  PRIMARY KEY (`SolidObjectID`,`PhysicalLocationID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hasSolidObject_SecondaryLocation`
--

LOCK TABLES `hasSolidObject_SecondaryLocation` WRITE;
/*!40000 ALTER TABLE `hasSolidObject_SecondaryLocation` DISABLE KEYS */;
/*!40000 ALTER TABLE `hasSolidObject_SecondaryLocation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `hasWorkstation_OtherObstacles`
--

DROP TABLE IF EXISTS `hasWorkstation_OtherObstacles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hasWorkstation_OtherObstacles` (
  `KittingWorkstationID` int(11) NOT NULL,
  `BoxVolumeID` int(11) NOT NULL,
  PRIMARY KEY (`KittingWorkstationID`,`BoxVolumeID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hasWorkstation_OtherObstacles`
--

LOCK TABLES `hasWorkstation_OtherObstacles` WRITE;
/*!40000 ALTER TABLE `hasWorkstation_OtherObstacles` DISABLE KEYS */;
/*!40000 ALTER TABLE `hasWorkstation_OtherObstacles` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2012-08-19  1:42:07
