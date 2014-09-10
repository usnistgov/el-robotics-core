-- MySQL dump 10.13  Distrib 5.5.32, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: OWL
-- ------------------------------------------------------
-- Server version	5.5.32-0ubuntu0.12.04.1

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
  `hadByOtherObstacle_KittingWorkstation` varchar(255) DEFAULT NULL,
  `hadByWorkVolume_Robot` varchar(255) DEFAULT NULL,
  `hasBoxVolume_MaximumPoint` varchar(255) DEFAULT NULL,
  `hasBoxVolume_MinimumPoint` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`BoxVolumeID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByOtherObstacle_KittingWorkstation` (`hadByOtherObstacle_KittingWorkstation`),
  KEY `fkhadByWorkVolume_Robot` (`hadByWorkVolume_Robot`),
  KEY `fkhasBoxVolume_MaximumPoint` (`hasBoxVolume_MaximumPoint`),
  KEY `fkhasBoxVolume_MinimumPoint` (`hasBoxVolume_MinimumPoint`),
  CONSTRAINT `fkhasBoxVolume_MinimumPoint` FOREIGN KEY (`hasBoxVolume_MinimumPoint`) REFERENCES `Point` (`_NAME`),
  CONSTRAINT `fkhadByOtherObstacle_KittingWorkstation` FOREIGN KEY (`hadByOtherObstacle_KittingWorkstation`) REFERENCES `KittingWorkstation` (`_NAME`),
  CONSTRAINT `fkhadByWorkVolume_Robot` FOREIGN KEY (`hadByWorkVolume_Robot`) REFERENCES `Robot` (`_NAME`),
  CONSTRAINT `fkhasBoxVolume_MaximumPoint` FOREIGN KEY (`hasBoxVolume_MaximumPoint`) REFERENCES `Point` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `BoxVolume`
--

LOCK TABLES `BoxVolume` WRITE;
/*!40000 ALTER TABLE `BoxVolume` DISABLE KEYS */;
INSERT INTO `BoxVolume` VALUES (142,'box_volume_1',NULL,'robot_1','point_max','point_min');
/*!40000 ALTER TABLE `BoxVolume` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `BoxyShape`
--

DROP TABLE IF EXISTS `BoxyShape`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `BoxyShape` (
  `BoxyShapeID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasBoxyShape_Width` double NOT NULL,
  `hasBoxyShape_Height` double NOT NULL,
  `hasBoxyShape_Length` double NOT NULL,
  `hasBoxyShape_HasTop` tinyint(1) NOT NULL,
  PRIMARY KEY (`BoxyShapeID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `BoxyShape`
--

LOCK TABLES `BoxyShape` WRITE;
/*!40000 ALTER TABLE `BoxyShape` DISABLE KEYS */;
INSERT INTO `BoxyShape` VALUES (89,'shape_parts_tray_c_ir',0.4572,0.0254,0.8636,0),(125,'shape_parts_tray_e_ir',0.4319,0.0254,0.8895,0),(251,'shape_changing_station_base',0.1,1,1,1),(474,'shape_work_table',0.8,0.5,1.6,1),(477,'shape_kit_box_ir',0.5,0.8,1,0),(539,'shape_parts_tray_b_ir',0.4576,0.0254,0.8124,0),(652,'shape_parts_tray_a_ir',0.4319,0.0254,0.8124,0),(664,'shape_kit_box',0.7,0.8,0.9,0),(730,'shape_parts_tray_d_ir',0.4319,0.0254,0.8895,0),(824,'shape_trash_table',0.8,0.5,1.6,1);
/*!40000 ALTER TABLE `BoxyShape` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `CylindricalShape`
--

DROP TABLE IF EXISTS `CylindricalShape`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `CylindricalShape` (
  `CylindricalShapeID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasCylindricalShape_Height` double NOT NULL,
  `hasCylindricalShape_HasTop` tinyint(1) NOT NULL,
  `hasCylindricalShape_Diameter` double NOT NULL,
  PRIMARY KEY (`CylindricalShapeID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `CylindricalShape`
--

LOCK TABLES `CylindricalShape` WRITE;
/*!40000 ALTER TABLE `CylindricalShape` DISABLE KEYS */;
/*!40000 ALTER TABLE `CylindricalShape` ENABLE KEYS */;
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
) ENGINE=InnoDB AUTO_INCREMENT=836 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `DataThing`
--

LOCK TABLES `DataThing` WRITE;
/*!40000 ALTER TABLE `DataThing` DISABLE KEYS */;
INSERT INTO `DataThing` VALUES (142,'box_volume_1'),(146,'changing_station_base_point'),(354,'changing_station_base_pose'),(432,'changing_station_base_x_axis'),(551,'changing_station_base_z_axis'),(600,'changing_station_point'),(376,'changing_station_pose'),(264,'changing_station_x_axis'),(678,'changing_station_z_axis'),(186,'empty_kit_tray_box_point'),(462,'empty_kit_tray_box_point_ir'),(799,'empty_kit_tray_box_pose'),(821,'empty_kit_tray_box_pose_ir'),(581,'empty_kit_tray_box_x_axis'),(489,'empty_kit_tray_box_x_axis_ir'),(351,'empty_kit_tray_box_z_axis'),(293,'empty_kit_tray_box_z_axis_ir'),(265,'empty_kit_tray_supply_point'),(476,'empty_kit_tray_supply_point_ir'),(808,'empty_kit_tray_supply_pose'),(440,'empty_kit_tray_supply_pose_ir'),(427,'empty_kit_tray_supply_x_axis'),(334,'empty_kit_tray_supply_x_axis_ir'),(781,'empty_kit_tray_supply_z_axis'),(493,'empty_kit_tray_supply_z_axis_ir'),(775,'ext_shape_gear'),(786,'ext_shape_gear_base'),(236,'ext_shape_gear_boss'),(314,'ext_shape_gear_holder'),(375,'ext_shape_gear_shaft'),(395,'ext_shape_parts_tray_a_ir'),(759,'ext_shape_parts_tray_b_ir'),(520,'ext_shape_parts_tray_c_ir'),(640,'ext_shape_parts_tray_d_ir'),(169,'ext_shape_parts_tray_e_ir'),(712,'finished_kit_box_point'),(777,'finished_kit_box_point_ir'),(555,'finished_kit_box_pose'),(557,'finished_kit_box_pose_ir'),(655,'finished_kit_box_x_axis'),(217,'finished_kit_box_x_axis_ir'),(393,'finished_kit_box_z_axis'),(229,'finished_kit_box_z_axis_ir'),(803,'finished_kit_receiver_point'),(363,'finished_kit_receiver_point_ir'),(10,'finished_kit_receiver_pose'),(202,'finished_kit_receiver_pose_ir'),(743,'finished_kit_receiver_x_axis'),(746,'finished_kit_receiver_x_axis_ir'),(365,'finished_kit_receiver_z_axis'),(796,'finished_kit_receiver_z_axis_ir'),(760,'kit_a2b2c1_point'),(340,'kit_a2b2c1_pose'),(585,'kit_a2b2c1_slot_1'),(582,'kit_a2b2c1_slot_2'),(583,'kit_a2b2c1_slot_3'),(578,'kit_a2b2c1_slot_4'),(579,'kit_a2b2c1_slot_5'),(442,'kit_a2b2c1_x_axis'),(418,'kit_a2b2c1_z_axis'),(797,'kit_design_a2b1c1'),(165,'kit_design_a2b2c1'),(213,'kit_design_a2b3c3d1e1_ir'),(349,'kit_design_a2b3c5_ir'),(544,'kit_design_a4b3c2d1_ir'),(137,'kit_design_a4b3c3_ir'),(153,'kit_design_a4b4c2_ir'),(590,'kit_tray_1_point'),(367,'kit_tray_1_point_ir'),(318,'kit_tray_1_pose'),(417,'kit_tray_1_pose_ir'),(82,'kit_tray_1_x_axis'),(475,'kit_tray_1_x_axis_ir'),(594,'kit_tray_1_z_axis'),(70,'kit_tray_1_z_axis_ir'),(337,'kit_tray_2_point'),(470,'kit_tray_2_point_ir'),(602,'kit_tray_2_pose'),(646,'kit_tray_2_pose_ir'),(268,'kit_tray_2_x_axis'),(15,'kit_tray_2_x_axis_ir'),(79,'kit_tray_2_z_axis'),(421,'kit_tray_2_z_axis_ir'),(114,'kit_tray_3_point'),(671,'kit_tray_3_point_ir'),(96,'kit_tray_3_pose'),(175,'kit_tray_3_pose_ir'),(521,'kit_tray_3_x_axis'),(511,'kit_tray_3_x_axis_ir'),(216,'kit_tray_3_z_axis'),(745,'kit_tray_3_z_axis_ir'),(162,'kit_tray_4_point_ir'),(331,'kit_tray_4_pose_ir'),(315,'kit_tray_4_x_axis_ir'),(547,'kit_tray_4_z_axis_ir'),(47,'kit_tray_5_point_ir'),(785,'kit_tray_5_pose_ir'),(18,'kit_tray_5_x_axis_ir'),(635,'kit_tray_5_z_axis_ir'),(20,'part_a_10_point_ir'),(54,'part_a_10_pose_ir'),(549,'part_a_10_x_axis_ir'),(231,'part_a_10_z_axis_ir'),(45,'part_a_11_point_ir'),(495,'part_a_11_pose_ir'),(614,'part_a_11_x_axis_ir'),(253,'part_a_11_z_axis_ir'),(688,'part_a_12_point_ir'),(576,'part_a_12_pose_ir'),(136,'part_a_12_x_axis_ir'),(667,'part_a_12_z_axis_ir'),(90,'part_a_13_point_ir'),(256,'part_a_13_pose_ir'),(606,'part_a_13_x_axis_ir'),(685,'part_a_13_z_axis_ir'),(423,'part_a_14_point_ir'),(771,'part_a_14_pose_ir'),(283,'part_a_14_x_axis_ir'),(57,'part_a_14_z_axis_ir'),(634,'part_a_15_point_ir'),(241,'part_a_15_pose_ir'),(623,'part_a_15_x_axis_ir'),(625,'part_a_15_z_axis_ir'),(228,'part_a_16_point_ir'),(225,'part_a_16_pose_ir'),(734,'part_a_16_x_axis_ir'),(773,'part_a_16_z_axis_ir'),(737,'part_a_17_point_ir'),(344,'part_a_17_pose_ir'),(222,'part_a_17_x_axis_ir'),(684,'part_a_17_z_axis_ir'),(509,'part_a_18_point_ir'),(686,'part_a_18_pose_ir'),(523,'part_a_18_x_axis_ir'),(167,'part_a_18_z_axis_ir'),(71,'part_a_1_point'),(668,'part_a_1_point_ir'),(643,'part_a_1_pose'),(502,'part_a_1_pose_ir'),(573,'part_a_1_x_axis'),(651,'part_a_1_x_axis_ir'),(151,'part_a_1_z_axis'),(793,'part_a_1_z_axis_ir'),(398,'part_a_2_point'),(131,'part_a_2_point_ir'),(56,'part_a_2_pose'),(827,'part_a_2_pose_ir'),(387,'part_a_2_x_axis'),(701,'part_a_2_x_axis_ir'),(244,'part_a_2_z_axis'),(598,'part_a_2_z_axis_ir'),(540,'part_a_3_point'),(397,'part_a_3_point_ir'),(359,'part_a_3_pose'),(356,'part_a_3_pose_ir'),(106,'part_a_3_x_axis'),(115,'part_a_3_x_axis_ir'),(783,'part_a_3_z_axis'),(99,'part_a_3_z_axis_ir'),(323,'part_a_4_point'),(542,'part_a_4_point_ir'),(144,'part_a_4_pose'),(104,'part_a_4_pose_ir'),(149,'part_a_4_x_axis'),(791,'part_a_4_x_axis_ir'),(28,'part_a_4_z_axis'),(663,'part_a_4_z_axis_ir'),(116,'part_a_5_point_ir'),(198,'part_a_5_pose_ir'),(369,'part_a_5_x_axis_ir'),(486,'part_a_5_z_axis_ir'),(514,'part_a_6_point_ir'),(718,'part_a_6_pose_ir'),(379,'part_a_6_x_axis_ir'),(526,'part_a_6_z_axis_ir'),(444,'part_a_7_point_ir'),(715,'part_a_7_pose_ir'),(587,'part_a_7_x_axis_ir'),(419,'part_a_7_z_axis_ir'),(482,'part_a_8_point_ir'),(755,'part_a_8_pose_ir'),(478,'part_a_8_x_axis_ir'),(23,'part_a_8_z_axis_ir'),(305,'part_a_9_point_ir'),(534,'part_a_9_pose_ir'),(97,'part_a_9_x_axis_ir'),(200,'part_a_9_z_axis_ir'),(607,'part_a_grasp_point'),(221,'part_a_grasp_pose'),(530,'part_a_grasp_x_axis'),(209,'part_a_grasp_z_axis'),(601,'part_a_supply_point'),(451,'part_a_supply_point_ir'),(571,'part_a_supply_pose'),(592,'part_a_supply_pose_ir'),(68,'part_a_supply_x_axis'),(345,'part_a_supply_x_axis_ir'),(329,'part_a_supply_z_axis'),(650,'part_a_supply_z_axis_ir'),(562,'part_a_tray_point'),(307,'part_a_tray_point_ir'),(21,'part_a_tray_pose'),(698,'part_a_tray_pose_ir'),(459,'part_a_tray_x_axis'),(181,'part_a_tray_x_axis_ir'),(100,'part_a_tray_z_axis'),(756,'part_a_tray_z_axis_ir'),(669,'part_b_10_point_ir'),(242,'part_b_10_pose_ir'),(183,'part_b_10_x_axis_ir'),(617,'part_b_10_z_axis_ir'),(275,'part_b_11_point_ir'),(456,'part_b_11_pose_ir'),(316,'part_b_11_x_axis_ir'),(274,'part_b_11_z_axis_ir'),(224,'part_b_12_point_ir'),(401,'part_b_12_pose_ir'),(126,'part_b_12_x_axis_ir'),(779,'part_b_12_z_axis_ir'),(676,'part_b_1_point'),(133,'part_b_1_point_ir'),(86,'part_b_1_pose'),(39,'part_b_1_pose_ir'),(565,'part_b_1_x_axis'),(311,'part_b_1_x_axis_ir'),(138,'part_b_1_z_axis'),(410,'part_b_1_z_axis_ir'),(287,'part_b_2_point'),(197,'part_b_2_point_ir'),(420,'part_b_2_pose'),(91,'part_b_2_pose_ir'),(36,'part_b_2_x_axis'),(467,'part_b_2_x_axis_ir'),(227,'part_b_2_z_axis'),(787,'part_b_2_z_axis_ir'),(123,'part_b_3_point'),(479,'part_b_3_point_ir'),(8,'part_b_3_pose'),(515,'part_b_3_pose_ir'),(554,'part_b_3_x_axis'),(49,'part_b_3_x_axis_ir'),(697,'part_b_3_z_axis'),(246,'part_b_3_z_axis_ir'),(719,'part_b_4_point'),(507,'part_b_4_point_ir'),(12,'part_b_4_pose'),(215,'part_b_4_pose_ir'),(132,'part_b_4_x_axis'),(658,'part_b_4_x_axis_ir'),(31,'part_b_4_z_axis'),(473,'part_b_4_z_axis_ir'),(192,'part_b_5_point'),(161,'part_b_5_point_ir'),(11,'part_b_5_pose'),(524,'part_b_5_pose_ir'),(134,'part_b_5_x_axis'),(788,'part_b_5_x_axis_ir'),(727,'part_b_5_z_axis'),(360,'part_b_5_z_axis_ir'),(66,'part_b_6_point'),(604,'part_b_6_point_ir'),(80,'part_b_6_pose'),(449,'part_b_6_pose_ir'),(301,'part_b_6_x_axis'),(804,'part_b_6_x_axis_ir'),(543,'part_b_6_z_axis'),(290,'part_b_6_z_axis_ir'),(371,'part_b_7_point'),(205,'part_b_7_point_ir'),(457,'part_b_7_pose'),(501,'part_b_7_pose_ir'),(675,'part_b_7_x_axis'),(396,'part_b_7_x_axis_ir'),(733,'part_b_7_z_axis'),(277,'part_b_7_z_axis_ir'),(757,'part_b_8_point'),(374,'part_b_8_point_ir'),(673,'part_b_8_pose'),(178,'part_b_8_pose_ir'),(762,'part_b_8_x_axis'),(254,'part_b_8_x_axis_ir'),(309,'part_b_8_z_axis'),(384,'part_b_8_z_axis_ir'),(645,'part_b_9_point_ir'),(83,'part_b_9_pose_ir'),(143,'part_b_9_x_axis_ir'),(269,'part_b_9_z_axis_ir'),(801,'part_b_grasp_point'),(19,'part_b_grasp_pose'),(14,'part_b_grasp_x_axis'),(639,'part_b_grasp_z_axis'),(744,'part_b_supply_point'),(310,'part_b_supply_point_ir'),(211,'part_b_supply_pose'),(76,'part_b_supply_pose_ir'),(234,'part_b_supply_x_axis'),(654,'part_b_supply_x_axis_ir'),(510,'part_b_supply_z_axis'),(772,'part_b_supply_z_axis_ir'),(350,'part_b_tray_point'),(447,'part_b_tray_point_ir'),(469,'part_b_tray_pose'),(780,'part_b_tray_pose_ir'),(575,'part_b_tray_x_axis'),(92,'part_b_tray_x_axis_ir'),(814,'part_b_tray_z_axis'),(644,'part_b_tray_z_axis_ir'),(87,'part_c_1_point'),(343,'part_c_1_point_ir'),(829,'part_c_1_pose'),(608,'part_c_1_pose_ir'),(248,'part_c_1_x_axis'),(324,'part_c_1_x_axis_ir'),(170,'part_c_1_z_axis'),(300,'part_c_1_z_axis_ir'),(335,'part_c_2_point'),(218,'part_c_2_point_ir'),(532,'part_c_2_pose'),(189,'part_c_2_pose_ir'),(729,'part_c_2_x_axis'),(361,'part_c_2_x_axis_ir'),(210,'part_c_2_z_axis'),(429,'part_c_2_z_axis_ir'),(240,'part_c_3_point'),(64,'part_c_3_point_ir'),(352,'part_c_3_pose'),(441,'part_c_3_pose_ir'),(385,'part_c_3_x_axis'),(784,'part_c_3_x_axis_ir'),(75,'part_c_3_z_axis'),(768,'part_c_3_z_axis_ir'),(295,'part_c_4_point'),(731,'part_c_4_point_ir'),(13,'part_c_4_pose'),(101,'part_c_4_pose_ir'),(460,'part_c_4_x_axis'),(707,'part_c_4_x_axis_ir'),(3,'part_c_4_z_axis'),(77,'part_c_4_z_axis_ir'),(728,'part_c_5_point'),(259,'part_c_5_point_ir'),(95,'part_c_5_pose'),(500,'part_c_5_pose_ir'),(811,'part_c_5_x_axis'),(403,'part_c_5_x_axis_ir'),(357,'part_c_5_z_axis'),(308,'part_c_5_z_axis_ir'),(443,'part_c_6_point'),(179,'part_c_6_point_ir'),(347,'part_c_6_pose'),(127,'part_c_6_pose_ir'),(437,'part_c_6_x_axis'),(603,'part_c_6_x_axis_ir'),(341,'part_c_6_z_axis'),(680,'part_c_6_z_axis_ir'),(763,'part_c_7_point'),(391,'part_c_7_point_ir'),(270,'part_c_7_pose'),(130,'part_c_7_pose_ir'),(122,'part_c_7_x_axis'),(98,'part_c_7_x_axis_ir'),(312,'part_c_7_z_axis'),(292,'part_c_7_z_axis_ir'),(497,'part_c_8_point'),(404,'part_c_8_point_ir'),(706,'part_c_8_pose'),(124,'part_c_8_pose_ir'),(484,'part_c_8_x_axis'),(388,'part_c_8_x_axis_ir'),(103,'part_c_8_z_axis'),(431,'part_c_8_z_axis_ir'),(512,'part_c_grasp_point'),(117,'part_c_grasp_pose'),(589,'part_c_grasp_x_axis'),(605,'part_c_grasp_z_axis'),(550,'part_c_supply_point'),(642,'part_c_supply_point_ir'),(558,'part_c_supply_pose'),(140,'part_c_supply_pose_ir'),(394,'part_c_supply_x_axis'),(319,'part_c_supply_x_axis_ir'),(154,'part_c_supply_z_axis'),(426,'part_c_supply_z_axis_ir'),(113,'part_c_tray_point'),(649,'part_c_tray_point_ir'),(111,'part_c_tray_pose'),(487,'part_c_tray_pose_ir'),(176,'part_c_tray_x_axis'),(612,'part_c_tray_x_axis_ir'),(317,'part_c_tray_z_axis'),(299,'part_c_tray_z_axis_ir'),(717,'part_d_1_point_ir'),(62,'part_d_1_pose_ir'),(273,'part_d_1_x_axis_ir'),(595,'part_d_1_z_axis_ir'),(525,'part_d_2_point_ir'),(436,'part_d_2_pose_ir'),(159,'part_d_2_x_axis_ir'),(689,'part_d_2_z_axis_ir'),(572,'part_d_3_point_ir'),(566,'part_d_3_pose_ir'),(704,'part_d_3_x_axis_ir'),(69,'part_d_3_z_axis_ir'),(85,'part_d_4_point_ir'),(399,'part_d_4_pose_ir'),(742,'part_d_4_x_axis_ir'),(112,'part_d_4_z_axis_ir'),(552,'part_d_5_point_ir'),(560,'part_d_5_pose_ir'),(665,'part_d_5_x_axis_ir'),(370,'part_d_5_z_axis_ir'),(303,'part_d_6_point_ir'),(615,'part_d_6_pose_ir'),(333,'part_d_6_x_axis_ir'),(593,'part_d_6_z_axis_ir'),(284,'part_d_7_point_ir'),(815,'part_d_7_pose_ir'),(835,'part_d_7_x_axis_ir'),(819,'part_d_7_z_axis_ir'),(145,'part_d_8_point_ir'),(750,'part_d_8_pose_ir'),(29,'part_d_8_x_axis_ir'),(72,'part_d_8_z_axis_ir'),(679,'part_d_9_point_ir'),(498,'part_d_9_pose_ir'),(26,'part_d_9_x_axis_ir'),(60,'part_d_9_z_axis_ir'),(708,'part_d_supply_point_ir'),(817,'part_d_supply_pose_ir'),(67,'part_d_supply_x_axis_ir'),(567,'part_d_supply_z_axis_ir'),(425,'part_d_tray_point_ir'),(34,'part_d_tray_pose_ir'),(591,'part_d_tray_x_axis_ir'),(191,'part_d_tray_z_axis_ir'),(508,'part_e_1_point_ir'),(408,'part_e_1_pose_ir'),(609,'part_e_1_x_axis_ir'),(226,'part_e_1_z_axis_ir'),(353,'part_e_2_point_ir'),(288,'part_e_2_pose_ir'),(834,'part_e_2_x_axis_ir'),(185,'part_e_2_z_axis_ir'),(699,'part_e_3_point_ir'),(194,'part_e_3_pose_ir'),(637,'part_e_3_x_axis_ir'),(155,'part_e_3_z_axis_ir'),(30,'part_e_4_point_ir'),(753,'part_e_4_pose_ir'),(380,'part_e_4_x_axis_ir'),(230,'part_e_4_z_axis_ir'),(522,'part_e_5_point_ir'),(377,'part_e_5_pose_ir'),(1,'part_e_5_x_axis_ir'),(152,'part_e_5_z_axis_ir'),(261,'part_e_6_point_ir'),(584,'part_e_6_pose_ir'),(446,'part_e_6_x_axis_ir'),(424,'part_e_6_z_axis_ir'),(406,'part_e_supply_point_ir'),(659,'part_e_supply_pose_ir'),(50,'part_e_supply_x_axis_ir'),(173,'part_e_supply_z_axis_ir'),(184,'part_e_tray_point_ir'),(386,'part_e_tray_pose_ir'),(823,'part_e_tray_x_axis_ir'),(255,'part_e_tray_z_axis_ir'),(4,'part_gear_1_point'),(826,'part_gear_1_pose'),(622,'part_gear_1_x_axis'),(452,'part_gear_1_z_axis'),(588,'part_gear_2_point'),(648,'part_gear_2_pose'),(193,'part_gear_2_x_axis'),(683,'part_gear_2_z_axis'),(638,'part_gear_3_point'),(820,'part_gear_3_pose'),(223,'part_gear_3_x_axis'),(690,'part_gear_3_z_axis'),(586,'part_gear_4_point'),(647,'part_gear_4_pose'),(88,'part_gear_4_x_axis'),(250,'part_gear_4_z_axis'),(472,'part_gear_5_point'),(239,'part_gear_5_pose'),(433,'part_gear_5_x_axis'),(38,'part_gear_5_z_axis'),(631,'part_gear_base_point'),(390,'part_gear_base_pose'),(496,'part_gear_base_x_axis'),(74,'part_gear_base_z_axis'),(279,'part_gear_boss_point'),(302,'part_gear_boss_pose'),(720,'part_gear_boss_x_axis'),(455,'part_gear_boss_z_axis'),(266,'part_gear_holder_point'),(156,'part_gear_holder_pose'),(471,'part_gear_holder_x_axis'),(563,'part_gear_holder_z_axis'),(503,'part_gear_shaft_1_point'),(782,'part_gear_shaft_1_pose'),(422,'part_gear_shaft_1_x_axis'),(157,'part_gear_shaft_1_z_axis'),(6,'part_gear_shaft_2_point'),(723,'part_gear_shaft_2_pose'),(666,'part_gear_shaft_2_x_axis'),(372,'part_gear_shaft_2_z_axis'),(373,'part_gear_shaft_3_point'),(330,'part_gear_shaft_3_pose'),(657,'part_gear_shaft_3_x_axis'),(364,'part_gear_shaft_3_z_axis'),(740,'part_gear_shaft_4_point'),(504,'part_gear_shaft_4_pose'),(306,'part_gear_shaft_4_x_axis'),(724,'part_gear_shaft_4_z_axis'),(338,'part_gripper_holder_point'),(630,'part_gripper_holder_pose'),(61,'part_gripper_holder_x_axis'),(480,'part_gripper_holder_z_axis'),(289,'part_gripper_point'),(438,'part_gripper_pose'),(220,'part_gripper_x_axis'),(271,'part_gripper_z_axis'),(245,'part_ref_and_pose_kit_a2b1c1_a_1'),(243,'part_ref_and_pose_kit_a2b1c1_a_2'),(681,'part_ref_and_pose_kit_a2b1c1_b_1'),(538,'part_ref_and_pose_kit_a2b1c1_c_1'),(774,'part_ref_and_pose_kit_a2b2c1_a_1'),(776,'part_ref_and_pose_kit_a2b2c1_a_2'),(416,'part_ref_and_pose_kit_a2b2c1_b_1'),(415,'part_ref_and_pose_kit_a2b2c1_b_2'),(767,'part_ref_and_pose_kit_a2b2c1_c_1'),(677,'part_ref_and_pose_kit_a2b3c3d1e1_a_1_ir'),(621,'part_ref_and_pose_kit_a2b3c3d1e1_a_2_ir'),(492,'part_ref_and_pose_kit_a2b3c3d1e1_b_1_ir'),(568,'part_ref_and_pose_kit_a2b3c3d1e1_b_2_ir'),(190,'part_ref_and_pose_kit_a2b3c3d1e1_b_3_ir'),(174,'part_ref_and_pose_kit_a2b3c3d1e1_c_1_ir'),(409,'part_ref_and_pose_kit_a2b3c3d1e1_c_2_ir'),(597,'part_ref_and_pose_kit_a2b3c3d1e1_c_3_ir'),(366,'part_ref_and_pose_kit_a2b3c3d1e1_d_1_ir'),(187,'part_ref_and_pose_kit_a2b3c3d1e1_e_1_ir'),(758,'part_ref_and_pose_kit_a2b3c5_a_1_ir'),(705,'part_ref_and_pose_kit_a2b3c5_a_2_ir'),(516,'part_ref_and_pose_kit_a2b3c5_b_1_ir'),(499,'part_ref_and_pose_kit_a2b3c5_b_2_ir'),(368,'part_ref_and_pose_kit_a2b3c5_b_3_ir'),(180,'part_ref_and_pose_kit_a2b3c5_c_1_ir'),(529,'part_ref_and_pose_kit_a2b3c5_c_2_ir'),(710,'part_ref_and_pose_kit_a2b3c5_c_3_ir'),(596,'part_ref_and_pose_kit_a2b3c5_c_4_ir'),(414,'part_ref_and_pose_kit_a2b3c5_c_5_ir'),(798,'part_ref_and_pose_kit_a4b3c2d1_a_1_ir'),(574,'part_ref_and_pose_kit_a4b3c2d1_a_2_ir'),(5,'part_ref_and_pose_kit_a4b3c2d1_a_3_ir'),(700,'part_ref_and_pose_kit_a4b3c2d1_a_4_ir'),(653,'part_ref_and_pose_kit_a4b3c2d1_b_1_ir'),(262,'part_ref_and_pose_kit_a4b3c2d1_b_2_ir'),(160,'part_ref_and_pose_kit_a4b3c2d1_b_3_ir'),(44,'part_ref_and_pose_kit_a4b3c2d1_c_1_ir'),(807,'part_ref_and_pose_kit_a4b3c2d1_c_2_ir'),(709,'part_ref_and_pose_kit_a4b3c2d1_d_1_ir'),(281,'part_ref_and_pose_kit_a4b3c3_a_1_ir'),(481,'part_ref_and_pose_kit_a4b3c3_a_2_ir'),(166,'part_ref_and_pose_kit_a4b3c3_a_3_ir'),(405,'part_ref_and_pose_kit_a4b3c3_a_4_ir'),(24,'part_ref_and_pose_kit_a4b3c3_b_1_ir'),(559,'part_ref_and_pose_kit_a4b3c3_b_2_ir'),(546,'part_ref_and_pose_kit_a4b3c3_b_3_ir'),(59,'part_ref_and_pose_kit_a4b3c3_c_1_ir'),(267,'part_ref_and_pose_kit_a4b3c3_c_2_ir'),(531,'part_ref_and_pose_kit_a4b3c3_c_3_ir'),(63,'part_ref_and_pose_kit_a4b4c2_a_1_ir'),(790,'part_ref_and_pose_kit_a4b4c2_a_2_ir'),(238,'part_ref_and_pose_kit_a4b4c2_a_3_ir'),(616,'part_ref_and_pose_kit_a4b4c2_a_4_ir'),(362,'part_ref_and_pose_kit_a4b4c2_b_1_ir'),(105,'part_ref_and_pose_kit_a4b4c2_b_2_ir'),(628,'part_ref_and_pose_kit_a4b4c2_b_3_ir'),(164,'part_ref_and_pose_kit_a4b4c2_b_4_ir'),(468,'part_ref_and_pose_kit_a4b4c2_c_1_ir'),(326,'part_ref_and_pose_kit_a4b4c2_c_2_ir'),(17,'point_kit_a2b1c1_a_1'),(16,'point_kit_a2b1c1_a_2'),(818,'point_kit_a2b1c1_b_1'),(332,'point_kit_a2b1c1_c_1'),(260,'point_kit_a2b2c1_a_1'),(257,'point_kit_a2b2c1_a_2'),(749,'point_kit_a2b2c1_b_1'),(747,'point_kit_a2b2c1_b_2'),(84,'point_kit_a2b2c1_c_1'),(778,'point_kit_a2b3c3d1e1_a_1_ir'),(214,'point_kit_a2b3c3d1e1_a_2_ir'),(81,'point_kit_a2b3c3d1e1_b_1_ir'),(627,'point_kit_a2b3c3d1e1_b_2_ir'),(569,'point_kit_a2b3c3d1e1_b_3_ir'),(195,'point_kit_a2b3c3d1e1_c_1_ir'),(382,'point_kit_a2b3c3d1e1_c_2_ir'),(831,'point_kit_a2b3c3d1e1_c_3_ir'),(249,'point_kit_a2b3c3d1e1_d_1_ir'),(618,'point_kit_a2b3c3d1e1_e_1_ir'),(355,'point_kit_a2b3c5_a_1_ir'),(219,'point_kit_a2b3c5_a_2_ir'),(822,'point_kit_a2b3c5_b_1_ir'),(402,'point_kit_a2b3c5_b_2_ir'),(280,'point_kit_a2b3c5_b_3_ir'),(561,'point_kit_a2b3c5_c_1_ir'),(770,'point_kit_a2b3c5_c_2_ir'),(7,'point_kit_a2b3c5_c_3_ir'),(802,'point_kit_a2b3c5_c_4_ir'),(789,'point_kit_a2b3c5_c_5_ir'),(147,'point_kit_a4b3c2d1_a_1_ir'),(535,'point_kit_a4b3c2d1_a_2_ir'),(163,'point_kit_a4b3c2d1_a_3_ir'),(128,'point_kit_a4b3c2d1_a_4_ir'),(722,'point_kit_a4b3c2d1_b_1_ir'),(537,'point_kit_a4b3c2d1_b_2_ir'),(736,'point_kit_a4b3c2d1_b_3_ir'),(809,'point_kit_a4b3c2d1_c_1_ir'),(201,'point_kit_a4b3c2d1_c_2_ir'),(32,'point_kit_a4b3c2d1_d_1_ir'),(41,'point_kit_a4b3c3_a_1_ir'),(237,'point_kit_a4b3c3_a_2_ir'),(171,'point_kit_a4b3c3_a_3_ir'),(548,'point_kit_a4b3c3_a_4_ir'),(313,'point_kit_a4b3c3_b_1_ir'),(536,'point_kit_a4b3c3_b_2_ir'),(37,'point_kit_a4b3c3_b_3_ir'),(148,'point_kit_a4b3c3_c_1_ir'),(519,'point_kit_a4b3c3_c_2_ir'),(610,'point_kit_a4b3c3_c_3_ir'),(517,'point_kit_a4b4c2_a_1_ir'),(794,'point_kit_a4b4c2_a_2_ir'),(541,'point_kit_a4b4c2_a_3_ir'),(40,'point_kit_a4b4c2_a_4_ir'),(661,'point_kit_a4b4c2_b_1_ir'),(107,'point_kit_a4b4c2_b_2_ir'),(518,'point_kit_a4b4c2_b_3_ir'),(660,'point_kit_a4b4c2_b_4_ir'),(272,'point_kit_a4b4c2_c_1_ir'),(816,'point_kit_a4b4c2_c_2_ir'),(135,'point_max'),(48,'point_min'),(325,'relative_location_in_1'),(795,'relative_location_on_1'),(392,'robot_point'),(611,'robot_pose'),(276,'robot_x_axis'),(812,'robot_z_axis'),(251,'shape_changing_station_base'),(664,'shape_kit_box'),(477,'shape_kit_box_ir'),(506,'shape_kit_tray'),(528,'shape_kit_tray_1_ir'),(43,'shape_kit_tray_2_ir'),(825,'shape_kit_tray_3_ir'),(407,'shape_kit_tray_4_ir'),(466,'shape_kit_tray_5_ir'),(320,'shape_parts_tray_a'),(652,'shape_parts_tray_a_ir'),(321,'shape_parts_tray_b'),(539,'shape_parts_tray_b_ir'),(322,'shape_parts_tray_c'),(89,'shape_parts_tray_c_ir'),(730,'shape_parts_tray_d_ir'),(125,'shape_parts_tray_e_ir'),(52,'shape_part_a'),(33,'shape_part_a_ir'),(53,'shape_part_b'),(27,'shape_part_b_ir'),(55,'shape_part_c'),(599,'shape_part_c_ir'),(139,'shape_part_d_ir'),(448,'shape_part_e_ir'),(824,'shape_trash_table'),(474,'shape_work_table'),(656,'stock_keeping_unit_kit_box'),(252,'stock_keeping_unit_kit_box_ir'),(212,'stock_keeping_unit_kit_tray'),(93,'stock_keeping_unit_kit_tray_1_ir'),(346,'stock_keeping_unit_kit_tray_2_ir'),(110,'stock_keeping_unit_kit_tray_3_ir'),(641,'stock_keeping_unit_kit_tray_4_ir'),(2,'stock_keeping_unit_kit_tray_5_ir'),(258,'stock_keeping_unit_parts_a_tray_ir'),(206,'stock_keeping_unit_parts_b_tray_ir'),(348,'stock_keeping_unit_parts_c_tray_ir'),(102,'stock_keeping_unit_parts_d_tray_ir'),(748,'stock_keeping_unit_parts_e_tray_ir'),(670,'stock_keeping_unit_parts_tray_a'),(674,'stock_keeping_unit_parts_tray_b'),(672,'stock_keeping_unit_parts_tray_c'),(204,'stock_keeping_unit_part_a'),(629,'stock_keeping_unit_part_a_ir'),(233,'stock_keeping_unit_part_b'),(726,'stock_keeping_unit_part_b_ir'),(232,'stock_keeping_unit_part_c'),(94,'stock_keeping_unit_part_c_ir'),(73,'stock_keeping_unit_part_d_ir'),(445,'stock_keeping_unit_part_e_ir'),(158,'stock_keeping_unit_part_gear'),(439,'stock_keeping_unit_part_gear_base'),(754,'stock_keeping_unit_part_gear_boss'),(46,'stock_keeping_unit_part_gear_holder'),(491,'stock_keeping_unit_part_gear_shaft'),(721,'trash_table_point'),(633,'trash_table_pose'),(182,'trash_table_x_axis'),(696,'trash_table_z_axis'),(485,'tray_gripper_holder_point'),(620,'tray_gripper_holder_pose'),(121,'tray_gripper_holder_x_axis'),(51,'tray_gripper_holder_z_axis'),(828,'work_table_point'),(682,'work_table_pose'),(207,'work_table_x_axis'),(464,'work_table_z_axis'),(298,'x_axis_kit_a2b1c1_a_1'),(296,'x_axis_kit_a2b1c1_a_2'),(711,'x_axis_kit_a2b1c1_b_1'),(278,'x_axis_kit_a2b1c1_c_1'),(381,'x_axis_kit_a2b2c1_a_1'),(383,'x_axis_kit_a2b2c1_a_2'),(806,'x_axis_kit_a2b2c1_b_1'),(805,'x_axis_kit_a2b2c1_b_2'),(389,'x_axis_kit_a2b2c1_c_1'),(172,'x_axis_kit_a2b3c3d1e1_a_1_ir'),(577,'x_axis_kit_a2b3c3d1e1_a_2_ir'),(458,'x_axis_kit_a2b3c3d1e1_b_1_ir'),(765,'x_axis_kit_a2b3c3d1e1_b_2_ir'),(465,'x_axis_kit_a2b3c3d1e1_b_3_ir'),(118,'x_axis_kit_a2b3c3d1e1_c_1_ir'),(413,'x_axis_kit_a2b3c3d1e1_c_2_ir'),(556,'x_axis_kit_a2b3c3d1e1_c_3_ir'),(662,'x_axis_kit_a2b3c3d1e1_d_1_ir'),(120,'x_axis_kit_a2b3c3d1e1_e_1_ir'),(454,'x_axis_kit_a2b3c5_a_1_ir'),(339,'x_axis_kit_a2b3c5_a_2_ir'),(694,'x_axis_kit_a2b3c5_b_1_ir'),(400,'x_axis_kit_a2b3c5_b_2_ir'),(703,'x_axis_kit_a2b3c5_b_3_ir'),(813,'x_axis_kit_a2b3c5_c_1_ir'),(177,'x_axis_kit_a2b3c5_c_2_ir'),(702,'x_axis_kit_a2b3c5_c_3_ir'),(430,'x_axis_kit_a2b3c5_c_4_ir'),(235,'x_axis_kit_a2b3c5_c_5_ir'),(327,'x_axis_kit_a4b3c2d1_a_1_ir'),(533,'x_axis_kit_a4b3c2d1_a_2_ir'),(109,'x_axis_kit_a4b3c2d1_a_3_ir'),(505,'x_axis_kit_a4b3c2d1_a_4_ir'),(564,'x_axis_kit_a4b3c2d1_b_1_ir'),(141,'x_axis_kit_a4b3c2d1_b_2_ir'),(545,'x_axis_kit_a4b3c2d1_b_3_ir'),(490,'x_axis_kit_a4b3c2d1_c_1_ir'),(291,'x_axis_kit_a4b3c2d1_c_2_ir'),(766,'x_axis_kit_a4b3c2d1_d_1_ir'),(282,'x_axis_kit_a4b3c3_a_1_ir'),(35,'x_axis_kit_a4b3c3_a_2_ir'),(761,'x_axis_kit_a4b3c3_a_3_ir'),(129,'x_axis_kit_a4b3c3_a_4_ir'),(461,'x_axis_kit_a4b3c3_b_1_ir'),(553,'x_axis_kit_a4b3c3_b_2_ir'),(78,'x_axis_kit_a4b3c3_b_3_ir'),(810,'x_axis_kit_a4b3c3_c_1_ir'),(832,'x_axis_kit_a4b3c3_c_2_ir'),(65,'x_axis_kit_a4b3c3_c_3_ir'),(624,'x_axis_kit_a4b4c2_a_1_ir'),(263,'x_axis_kit_a4b4c2_a_2_ir'),(735,'x_axis_kit_a4b4c2_a_3_ir'),(196,'x_axis_kit_a4b4c2_a_4_ir'),(108,'x_axis_kit_a4b4c2_b_1_ir'),(453,'x_axis_kit_a4b4c2_b_2_ir'),(800,'x_axis_kit_a4b4c2_b_3_ir'),(619,'x_axis_kit_a4b4c2_b_4_ir'),(494,'x_axis_kit_a4b4c2_c_1_ir'),(833,'x_axis_kit_a4b4c2_c_2_ir'),(739,'z_axis_kit_a2b1c1_a_1'),(738,'z_axis_kit_a2b1c1_a_2'),(378,'z_axis_kit_a2b1c1_b_1'),(42,'z_axis_kit_a2b1c1_c_1'),(714,'z_axis_kit_a2b2c1_a_1'),(692,'z_axis_kit_a2b2c1_a_2'),(411,'z_axis_kit_a2b2c1_b_1'),(412,'z_axis_kit_a2b2c1_b_2'),(830,'z_axis_kit_a2b2c1_c_1'),(632,'z_axis_kit_a2b3c3d1e1_a_1_ir'),(751,'z_axis_kit_a2b3c3d1e1_a_2_ir'),(328,'z_axis_kit_a2b3c3d1e1_b_1_ir'),(570,'z_axis_kit_a2b3c3d1e1_b_2_ir'),(695,'z_axis_kit_a2b3c3d1e1_b_3_ir'),(488,'z_axis_kit_a2b3c3d1e1_c_1_ir'),(741,'z_axis_kit_a2b3c3d1e1_c_2_ir'),(199,'z_axis_kit_a2b3c3d1e1_c_3_ir'),(626,'z_axis_kit_a2b3c3d1e1_d_1_ir'),(435,'z_axis_kit_a2b3c3d1e1_e_1_ir'),(304,'z_axis_kit_a2b3c5_a_1_ir'),(691,'z_axis_kit_a2b3c5_a_2_ir'),(208,'z_axis_kit_a2b3c5_b_1_ir'),(769,'z_axis_kit_a2b3c5_b_2_ir'),(119,'z_axis_kit_a2b3c5_b_3_ir'),(294,'z_axis_kit_a2b3c5_c_1_ir'),(188,'z_axis_kit_a2b3c5_c_2_ir'),(286,'z_axis_kit_a2b3c5_c_3_ir'),(450,'z_axis_kit_a2b3c5_c_4_ir'),(285,'z_axis_kit_a2b3c5_c_5_ir'),(297,'z_axis_kit_a4b3c2d1_a_1_ir'),(150,'z_axis_kit_a4b3c2d1_a_2_ir'),(25,'z_axis_kit_a4b3c2d1_a_3_ir'),(636,'z_axis_kit_a4b3c2d1_a_4_ir'),(336,'z_axis_kit_a4b3c2d1_b_1_ir'),(764,'z_axis_kit_a4b3c2d1_b_2_ir'),(342,'z_axis_kit_a4b3c2d1_b_3_ir'),(687,'z_axis_kit_a4b3c2d1_c_1_ir'),(247,'z_axis_kit_a4b3c2d1_c_2_ir'),(527,'z_axis_kit_a4b3c2d1_d_1_ir'),(358,'z_axis_kit_a4b3c3_a_1_ir'),(693,'z_axis_kit_a4b3c3_a_2_ir'),(580,'z_axis_kit_a4b3c3_a_3_ir'),(713,'z_axis_kit_a4b3c3_a_4_ir'),(732,'z_axis_kit_a4b3c3_b_1_ir'),(613,'z_axis_kit_a4b3c3_b_2_ir'),(203,'z_axis_kit_a4b3c3_b_3_ir'),(9,'z_axis_kit_a4b3c3_c_1_ir'),(752,'z_axis_kit_a4b3c3_c_2_ir'),(428,'z_axis_kit_a4b3c3_c_3_ir'),(168,'z_axis_kit_a4b4c2_a_1_ir'),(513,'z_axis_kit_a4b4c2_a_2_ir'),(58,'z_axis_kit_a4b4c2_a_3_ir'),(463,'z_axis_kit_a4b4c2_a_4_ir'),(792,'z_axis_kit_a4b4c2_b_1_ir'),(22,'z_axis_kit_a4b4c2_b_2_ir'),(725,'z_axis_kit_a4b4c2_b_3_ir'),(434,'z_axis_kit_a4b4c2_b_4_ir'),(483,'z_axis_kit_a4b4c2_c_1_ir'),(716,'z_axis_kit_a4b4c2_c_2_ir');
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
  `hasEndEffector_MaximumLoadWeight` double NOT NULL,
  `hasEndEffector_HeldObject` varchar(255) DEFAULT NULL,
  `hadByEndEffector_Robot` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`EndEffectorID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasEndEffector_HeldObject` (`hasEndEffector_HeldObject`),
  KEY `fkhadByEndEffector_Robot` (`hadByEndEffector_Robot`),
  CONSTRAINT `fkhadByEndEffector_Robot` FOREIGN KEY (`hadByEndEffector_Robot`) REFERENCES `Robot` (`_NAME`),
  CONSTRAINT `fkhasEndEffector_HeldObject` FOREIGN KEY (`hasEndEffector_HeldObject`) REFERENCES `SolidObject` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `EndEffector`
--

LOCK TABLES `EndEffector` WRITE;
/*!40000 ALTER TABLE `EndEffector` DISABLE KEYS */;
INSERT INTO `EndEffector` VALUES (78,'tray_gripper','large single cup vacuum effector',0.04,0.5,NULL,'robot_1'),(101,'part_gripper','small single cup vacuum effector',0.01,0.4,NULL,NULL);
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
  `hasEndEffectorChangingStation_Base` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`EndEffectorChangingStationID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasEndEffectorChangingStation_Base` (`hasEndEffectorChangingStation_Base`),
  CONSTRAINT `fkhasEndEffectorChangingStation_Base` FOREIGN KEY (`hasEndEffectorChangingStation_Base`) REFERENCES `MechanicalComponent` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `EndEffectorChangingStation`
--

LOCK TABLES `EndEffectorChangingStation` WRITE;
/*!40000 ALTER TABLE `EndEffectorChangingStation` DISABLE KEYS */;
INSERT INTO `EndEffectorChangingStation` VALUES (128,'changing_station_1','changing_station_base');
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
  `hadByEndEffectorHolder_EndEffectorChangingStation` varchar(255) DEFAULT NULL,
  `hasEndEffectorHolder_EndEffector` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`EndEffectorHolderID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByEndEffectorHolder_EndEffectorChangingStation` (`hadByEndEffectorHolder_EndEffectorChangingStation`),
  KEY `fkhasEndEffectorHolder_EndEffector` (`hasEndEffectorHolder_EndEffector`),
  CONSTRAINT `fkhasEndEffectorHolder_EndEffector` FOREIGN KEY (`hasEndEffectorHolder_EndEffector`) REFERENCES `EndEffector` (`_NAME`),
  CONSTRAINT `fkhadByEndEffectorHolder_EndEffectorChangingStation` FOREIGN KEY (`hadByEndEffectorHolder_EndEffectorChangingStation`) REFERENCES `EndEffectorChangingStation` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `EndEffectorHolder`
--

LOCK TABLES `EndEffectorHolder` WRITE;
/*!40000 ALTER TABLE `EndEffectorHolder` DISABLE KEYS */;
INSERT INTO `EndEffectorHolder` VALUES (72,'part_gripper_holder','changing_station_1','part_gripper'),(120,'tray_gripper_holder','changing_station_1',NULL);
/*!40000 ALTER TABLE `EndEffectorHolder` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ExternalShape`
--

DROP TABLE IF EXISTS `ExternalShape`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ExternalShape` (
  `ExternalShapeID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hasExternalShape_ModelTypeName` varchar(255) NOT NULL,
  `hasExternalShape_ModelName` varchar(255) DEFAULT NULL,
  `hasExternalShape_ModelFileName` varchar(255) NOT NULL,
  `hadByExternalShape_SolidObject` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`ExternalShapeID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByExternalShape_SolidObject` (`hadByExternalShape_SolidObject`),
  CONSTRAINT `fkhadByExternalShape_SolidObject` FOREIGN KEY (`hadByExternalShape_SolidObject`) REFERENCES `SolidObject` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ExternalShape`
--

LOCK TABLES `ExternalShape` WRITE;
/*!40000 ALTER TABLE `ExternalShape` DISABLE KEYS */;
INSERT INTO `ExternalShape` VALUES (27,'shape_part_b_ir','USARSim','BlockB','USARPhysObj',NULL),(33,'shape_part_a_ir','USARSim','BlockA','USARPhysObj',NULL),(43,'shape_kit_tray_2_ir','USARSim','KitTray2','USARPhysObj',NULL),(52,'shape_part_a','USARSim','PartA','USARPhysObj',NULL),(53,'shape_part_b','USARSim','PartB','USARPhysObj',NULL),(55,'shape_part_c','USARSim','PartC','USARPhysObj',NULL),(139,'shape_part_d_ir','USARSim','BlockD','USARPhysObj',NULL),(169,'ext_shape_parts_tray_e_ir','USARSim','PartTrayE','USARPhysObj',NULL),(236,'ext_shape_gear_boss','USARSim','gear_boss','USARPhysObj',NULL),(314,'ext_shape_gear_holder','USARSim','gear_holder','USARPhysObj',NULL),(320,'shape_parts_tray_a','USARSim','PartATray','USARPhysObj',NULL),(321,'shape_parts_tray_b','USARSim','PartBTray','USARPhysObj',NULL),(322,'shape_parts_tray_c','USARSim','PartCTray','USARPhysObj',NULL),(375,'ext_shape_gear_shaft','USARSim','gear_shaft','USARPhysObj',NULL),(395,'ext_shape_parts_tray_a_ir','USARSim','PartTrayA','USARPhysObj',NULL),(407,'shape_kit_tray_4_ir','USARSim','KitTray4','USARPhysObj',NULL),(448,'shape_part_e_ir','USARSim','BlockE','USARPhysObj',NULL),(466,'shape_kit_tray_5_ir','USARSim','KitTray5','USARPhysObj',NULL),(506,'shape_kit_tray','USARSim','WCKitTraySmall','USARPhysObj',NULL),(520,'ext_shape_parts_tray_c_ir','USARSim','PartTrayC','USARPhysObj',NULL),(528,'shape_kit_tray_1_ir','USARSim','KitTray1','USARPhysObj',NULL),(599,'shape_part_c_ir','USARSim','BlockC','USARPhysObj',NULL),(640,'ext_shape_parts_tray_d_ir','USARSim','PartTrayD','USARPhysObj',NULL),(759,'ext_shape_parts_tray_b_ir','USARSim','PartTrayB','USARPhysObj',NULL),(775,'ext_shape_gear','USARSim','gear','USARPhysObj',NULL),(786,'ext_shape_gear_base','USARSim','gear_base','USARPhysObj',NULL),(825,'shape_kit_tray_3_ir','USARSim','KitTray3','USARPhysObj',NULL);
/*!40000 ALTER TABLE `ExternalShape` ENABLE KEYS */;
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
-- Table structure for table `Human`
--

DROP TABLE IF EXISTS `Human`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Human` (
  `HumanID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`HumanID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Human`
--

LOCK TABLES `Human` WRITE;
/*!40000 ALTER TABLE `Human` DISABLE KEYS */;
/*!40000 ALTER TABLE `Human` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `InternalShape`
--

DROP TABLE IF EXISTS `InternalShape`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `InternalShape` (
  `InternalShapeID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hadByInternalShape_SolidObject` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`InternalShapeID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByInternalShape_SolidObject` (`hadByInternalShape_SolidObject`),
  CONSTRAINT `fkhadByInternalShape_SolidObject` FOREIGN KEY (`hadByInternalShape_SolidObject`) REFERENCES `SolidObject` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `InternalShape`
--

LOCK TABLES `InternalShape` WRITE;
/*!40000 ALTER TABLE `InternalShape` DISABLE KEYS */;
INSERT INTO `InternalShape` VALUES (89,'shape_parts_tray_c_ir',NULL),(125,'shape_parts_tray_e_ir',NULL),(477,'shape_kit_box_ir',NULL),(539,'shape_parts_tray_b_ir',NULL),(652,'shape_parts_tray_a_ir',NULL),(664,'shape_kit_box',NULL),(730,'shape_parts_tray_d_ir',NULL),(251,'shape_changing_station_base','changing_station_base'),(824,'shape_trash_table','trash_table'),(474,'shape_work_table','work_table_1');
/*!40000 ALTER TABLE `InternalShape` ENABLE KEYS */;
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
  `hasKit_Finished` tinyint(1) NOT NULL,
  `hadByKit_LargeBoxWithKits` varchar(255) DEFAULT NULL,
  `hasKit_KitTray` varchar(255) DEFAULT NULL,
  `hasKit_Design` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`KitID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByKit_LargeBoxWithKits` (`hadByKit_LargeBoxWithKits`),
  KEY `fkhasKit_KitTray` (`hasKit_KitTray`),
  KEY `fkhasKit_Design` (`hasKit_Design`),
  CONSTRAINT `fkhasKit_Design` FOREIGN KEY (`hasKit_Design`) REFERENCES `KitDesign` (`_NAME`),
  CONSTRAINT `fkhadByKit_LargeBoxWithKits` FOREIGN KEY (`hadByKit_LargeBoxWithKits`) REFERENCES `LargeBoxWithKits` (`_NAME`),
  CONSTRAINT `fkhasKit_KitTray` FOREIGN KEY (`hasKit_KitTray`) REFERENCES `KitTray` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Kit`
--

LOCK TABLES `Kit` WRITE;
/*!40000 ALTER TABLE `Kit` DISABLE KEYS */;
INSERT INTO `Kit` VALUES (49,'kit_a2b2c1',0,NULL,'kit_tray_1','kit_design_a2b2c1');
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
  `hadByKitDesign_KittingWorkstation` varchar(255) DEFAULT NULL,
  `hasKitDesign_KitTraySku` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`KitDesignID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByKitDesign_KittingWorkstation` (`hadByKitDesign_KittingWorkstation`),
  KEY `fkhasKitDesign_KitTraySku` (`hasKitDesign_KitTraySku`),
  CONSTRAINT `fkhasKitDesign_KitTraySku` FOREIGN KEY (`hasKitDesign_KitTraySku`) REFERENCES `StockKeepingUnit` (`_NAME`),
  CONSTRAINT `fkhadByKitDesign_KittingWorkstation` FOREIGN KEY (`hadByKitDesign_KittingWorkstation`) REFERENCES `KittingWorkstation` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `KitDesign`
--

LOCK TABLES `KitDesign` WRITE;
/*!40000 ALTER TABLE `KitDesign` DISABLE KEYS */;
INSERT INTO `KitDesign` VALUES (137,'kit_design_a4b3c3_ir','kitting_workstation_1','stock_keeping_unit_kit_tray_1_ir'),(153,'kit_design_a4b4c2_ir','kitting_workstation_1','stock_keeping_unit_kit_tray_2_ir'),(165,'kit_design_a2b2c1','kitting_workstation_1','stock_keeping_unit_kit_tray'),(213,'kit_design_a2b3c3d1e1_ir','kitting_workstation_1','stock_keeping_unit_kit_tray_5_ir'),(349,'kit_design_a2b3c5_ir','kitting_workstation_1','stock_keeping_unit_kit_tray_3_ir'),(544,'kit_design_a4b3c2d1_ir','kitting_workstation_1','stock_keeping_unit_kit_tray_4_ir'),(797,'kit_design_a2b1c1','kitting_workstation_1','stock_keeping_unit_kit_tray');
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
  `hasKitTray_SerialNumber` varchar(100) NOT NULL,
  `hasKitTray_Sku` varchar(255) DEFAULT NULL,
  `hadByKitTray_LargeBoxWithEmptyKitTrays` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`KitTrayID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasKitTray_Sku` (`hasKitTray_Sku`),
  KEY `fkhadByKitTray_LargeBoxWithEmptyKitTrays` (`hadByKitTray_LargeBoxWithEmptyKitTrays`),
  CONSTRAINT `fkhadByKitTray_LargeBoxWithEmptyKitTrays` FOREIGN KEY (`hadByKitTray_LargeBoxWithEmptyKitTrays`) REFERENCES `LargeBoxWithEmptyKitTrays` (`_NAME`),
  CONSTRAINT `fkhasKitTray_Sku` FOREIGN KEY (`hasKitTray_Sku`) REFERENCES `StockKeepingUnit` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `KitTray`
--

LOCK TABLES `KitTray` WRITE;
/*!40000 ALTER TABLE `KitTray` DISABLE KEYS */;
INSERT INTO `KitTray` VALUES (40,'kit_tray_4_ir','31','stock_keeping_unit_kit_tray_4_ir',NULL),(68,'kit_tray_5_ir','32','stock_keeping_unit_kit_tray_5_ir',NULL),(70,'kit_tray_1_ir','30','stock_keeping_unit_kit_tray_1_ir',NULL),(112,'kit_tray_3','3','stock_keeping_unit_kit_tray','empty_kit_tray_supply'),(113,'kit_tray_2','2','stock_keeping_unit_kit_tray','empty_kit_tray_supply'),(114,'kit_tray_1','1','stock_keeping_unit_kit_tray','empty_kit_tray_supply'),(116,'kit_tray_2_ir','33','stock_keeping_unit_kit_tray_2_ir',NULL),(119,'kit_tray_3_ir','34','stock_keeping_unit_kit_tray_3_ir',NULL);
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
  `hasKittingWorkstation_LengthUnit` varchar(20) NOT NULL,
  `hasKittingWorkstation_WeightUnit` varchar(20) NOT NULL,
  `hasKittingWorkstation_AngleUnit` varchar(20) NOT NULL,
  `hasKittingWorkstation_ChangingStation` varchar(255) DEFAULT NULL,
  `hasKittingWorkstation_Robot` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`KittingWorkstationID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasKittingWorkstation_ChangingStation` (`hasKittingWorkstation_ChangingStation`),
  KEY `fkhasKittingWorkstation_Robot` (`hasKittingWorkstation_Robot`),
  CONSTRAINT `fkhasKittingWorkstation_Robot` FOREIGN KEY (`hasKittingWorkstation_Robot`) REFERENCES `Robot` (`_NAME`),
  CONSTRAINT `fkhasKittingWorkstation_ChangingStation` FOREIGN KEY (`hasKittingWorkstation_ChangingStation`) REFERENCES `EndEffectorChangingStation` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `KittingWorkstation`
--

LOCK TABLES `KittingWorkstation` WRITE;
/*!40000 ALTER TABLE `KittingWorkstation` DISABLE KEYS */;
INSERT INTO `KittingWorkstation` VALUES (98,'kitting_workstation_1','meter','kilogram','degree','changing_station_1','robot_1');
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
INSERT INTO `LargeBoxWithEmptyKitTrays` VALUES (108,'empty_kit_tray_supply','empty_kit_tray_box'),(69,'empty_kit_tray_supply_ir','empty_kit_tray_box_ir');
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
  `hasLargeBoxWithKits_Capacity` int(11) NOT NULL,
  `hasLargeBoxWithKits_LargeContainer` varchar(255) DEFAULT NULL,
  `hasLargeBoxWithKits_KitDesign` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`LargeBoxWithKitsID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasLargeBoxWithKits_LargeContainer` (`hasLargeBoxWithKits_LargeContainer`),
  KEY `fkhasLargeBoxWithKits_KitDesign` (`hasLargeBoxWithKits_KitDesign`),
  CONSTRAINT `fkhasLargeBoxWithKits_KitDesign` FOREIGN KEY (`hasLargeBoxWithKits_KitDesign`) REFERENCES `KitDesign` (`_NAME`),
  CONSTRAINT `fkhasLargeBoxWithKits_LargeContainer` FOREIGN KEY (`hasLargeBoxWithKits_LargeContainer`) REFERENCES `LargeContainer` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `LargeBoxWithKits`
--

LOCK TABLES `LargeBoxWithKits` WRITE;
/*!40000 ALTER TABLE `LargeBoxWithKits` DISABLE KEYS */;
INSERT INTO `LargeBoxWithKits` VALUES (63,'finished_kit_receiver_ir',12,'finished_kit_box_ir','kit_design_a4b3c3_ir'),(90,'finished_kit_receiver',12,'finished_kit_box','kit_design_a2b1c1');
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
  `hasLargeContainer_SerialNumber` varchar(100) NOT NULL,
  `hasLargeContainer_Sku` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`LargeContainerID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasLargeContainer_Sku` (`hasLargeContainer_Sku`),
  CONSTRAINT `fkhasLargeContainer_Sku` FOREIGN KEY (`hasLargeContainer_Sku`) REFERENCES `StockKeepingUnit` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `LargeContainer`
--

LOCK TABLES `LargeContainer` WRITE;
/*!40000 ALTER TABLE `LargeContainer` DISABLE KEYS */;
INSERT INTO `LargeContainer` VALUES (64,'empty_kit_tray_box','4','stock_keeping_unit_kit_box'),(88,'finished_kit_box','5','stock_keeping_unit_kit_box'),(106,'empty_kit_tray_box_ir','4','stock_keeping_unit_kit_box_ir'),(117,'finished_kit_box_ir','5','stock_keeping_unit_kit_box_ir');
/*!40000 ALTER TABLE `LargeContainer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `MechanicalComponent`
--

DROP TABLE IF EXISTS `MechanicalComponent`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `MechanicalComponent` (
  `MechanicalComponentID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`MechanicalComponentID`,`_NAME`),
  KEY `_NAME` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `MechanicalComponent`
--

LOCK TABLES `MechanicalComponent` WRITE;
/*!40000 ALTER TABLE `MechanicalComponent` DISABLE KEYS */;
INSERT INTO `MechanicalComponent` VALUES (102,'changing_station_base');
/*!40000 ALTER TABLE `MechanicalComponent` ENABLE KEYS */;
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
  `hasPart_SerialNumber` varchar(100) NOT NULL,
  `hadByPart_Kit` varchar(255) DEFAULT NULL,
  `hadByPart_PartsTrayWithParts` varchar(255) DEFAULT NULL,
  `hasPart_Sku` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`PartID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByPart_Kit` (`hadByPart_Kit`),
  KEY `fkhadByPart_PartsTrayWithParts` (`hadByPart_PartsTrayWithParts`),
  KEY `fkhasPart_Sku` (`hasPart_Sku`),
  CONSTRAINT `fkhasPart_Sku` FOREIGN KEY (`hasPart_Sku`) REFERENCES `StockKeepingUnit` (`_NAME`),
  CONSTRAINT `fkhadByPart_Kit` FOREIGN KEY (`hadByPart_Kit`) REFERENCES `Kit` (`_NAME`),
  CONSTRAINT `fkhadByPart_PartsTrayWithParts` FOREIGN KEY (`hadByPart_PartsTrayWithParts`) REFERENCES `PartsTrayWithParts` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Part`
--

LOCK TABLES `Part` WRITE;
/*!40000 ALTER TABLE `Part` DISABLE KEYS */;
INSERT INTO `Part` VALUES (1,'part_d_6_ir','d6_ir',NULL,'part_d_supply_ir','stock_keeping_unit_part_d_ir'),(2,'part_d_4_ir','d4_ir',NULL,'part_d_supply_ir','stock_keeping_unit_part_d_ir'),(5,'part_gear_holder','gearholder',NULL,NULL,'stock_keeping_unit_part_gear_holder'),(6,'part_b_9_ir','b9_ir',NULL,'part_b_supply_ir','stock_keeping_unit_part_b_ir'),(7,'part_c_5','c5',NULL,NULL,'stock_keeping_unit_part_c'),(8,'part_c_4','c4',NULL,'part_c_supply','stock_keeping_unit_part_c'),(9,'part_c_3','c3',NULL,'part_c_supply','stock_keeping_unit_part_c'),(10,'part_c_2','c2',NULL,'part_c_supply','stock_keeping_unit_part_c'),(11,'part_c_1','c1',NULL,'part_c_supply','stock_keeping_unit_part_c'),(12,'part_c_8','c8',NULL,'part_c_supply','stock_keeping_unit_part_c'),(13,'part_a_7_ir','a7_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(14,'part_c_7','c7',NULL,'part_c_supply','stock_keeping_unit_part_c'),(15,'part_c_6','c6',NULL,'part_c_supply','stock_keeping_unit_part_c'),(17,'part_gear_boss','gearboss',NULL,NULL,'stock_keeping_unit_part_gear_boss'),(19,'part_a_11_ir','a11_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(20,'part_b_6_ir','b6',NULL,'part_b_supply_ir','stock_keeping_unit_part_b_ir'),(21,'part_gear_4','gear4',NULL,NULL,'stock_keeping_unit_part_gear'),(22,'part_gear_5','gear5',NULL,NULL,'stock_keeping_unit_part_gear'),(23,'part_gear_2','gear2',NULL,NULL,'stock_keeping_unit_part_gear'),(24,'part_gear_3','gear3',NULL,NULL,'stock_keeping_unit_part_gear'),(25,'part_e_2_ir','e2_ir',NULL,'part_e_supply_ir','stock_keeping_unit_part_e_ir'),(26,'part_c_2_ir','c2_ir',NULL,'part_c_supply_ir','stock_keeping_unit_part_c_ir'),(27,'part_gear_base','gearbase',NULL,NULL,'stock_keeping_unit_part_gear_base'),(28,'part_gear_1','gear1',NULL,NULL,'stock_keeping_unit_part_gear'),(29,'part_a_9_ir','a9_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(30,'part_b_8_ir','b8_ir',NULL,'part_b_supply_ir','stock_keeping_unit_part_b_ir'),(31,'part_d_2_ir','d2_ir',NULL,'part_d_supply_ir','stock_keeping_unit_part_d_ir'),(33,'part_b_4_ir','b4_ir',NULL,'part_b_supply_ir','stock_keeping_unit_part_b_ir'),(34,'part_d_8_ir','d8_ir',NULL,'part_d_supply_ir','stock_keeping_unit_part_d_ir'),(35,'part_gear_shaft_1','gear1',NULL,NULL,'stock_keeping_unit_part_gear_shaft'),(36,'part_gear_shaft_2','gear2',NULL,NULL,'stock_keeping_unit_part_gear_shaft'),(37,'part_gear_shaft_3','gear3',NULL,NULL,'stock_keeping_unit_part_gear_shaft'),(38,'part_gear_shaft_4','gear4',NULL,NULL,'stock_keeping_unit_part_gear_shaft'),(39,'part_a_4_ir','a4_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(42,'part_a_10_ir','a10_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(43,'part_b_10_ir','b10_ir',NULL,'part_b_supply_ir','stock_keeping_unit_part_b_ir'),(45,'part_a_1_ir','a1_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(46,'part_c_4_ir','c4_ir',NULL,'part_c_supply_ir','stock_keeping_unit_part_c_ir'),(47,'part_b_11_ir','b11_ir',NULL,'part_b_supply_ir','stock_keeping_unit_part_b_ir'),(48,'part_e_3_ir','e3_ir',NULL,'part_e_supply_ir','stock_keeping_unit_part_e_ir'),(50,'part_d_3_ir','d3_ir',NULL,'part_d_supply_ir','stock_keeping_unit_part_d_ir'),(52,'part_a_3_ir','a3_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(53,'part_a_18_ir','a18_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(54,'part_a_16_ir','a16_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(55,'part_d_7_ir','d7_ir',NULL,'part_d_supply_ir','stock_keeping_unit_part_d_ir'),(56,'part_c_7_ir','c7_ir',NULL,'part_c_supply_ir','stock_keeping_unit_part_c_ir'),(57,'part_a_15_ir','a15_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(58,'part_a_6_ir','a6_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(60,'part_e_4_ir','e4_ir',NULL,'part_e_supply_ir','stock_keeping_unit_part_e_ir'),(62,'part_b_7_ir','b7',NULL,'part_b_supply_ir','stock_keeping_unit_part_b_ir'),(65,'part_a_12_ir','a12_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(67,'part_d_1_ir','d1_ir',NULL,'part_d_supply_ir','stock_keeping_unit_part_d_ir'),(71,'part_a_8_ir','a8_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(74,'part_c_6_ir','c6_ir',NULL,'part_c_supply_ir','stock_keeping_unit_part_c_ir'),(75,'part_c_8_ir','c8_ir',NULL,'part_c_supply_ir','stock_keeping_unit_part_c_ir'),(76,'part_a_17_ir','a17_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(77,'part_b_3_ir','b3_ir',NULL,'part_b_supply_ir','stock_keeping_unit_part_b_ir'),(79,'part_b_1','b1',NULL,NULL,'stock_keeping_unit_part_b'),(80,'part_b_2','b2',NULL,NULL,'stock_keeping_unit_part_b'),(81,'part_b_5','b5',NULL,'part_b_supply','stock_keeping_unit_part_b'),(82,'part_b_6','b6',NULL,'part_b_supply','stock_keeping_unit_part_b'),(83,'part_b_3','b3',NULL,'part_b_supply','stock_keeping_unit_part_b'),(84,'part_b_4','b4',NULL,'part_b_supply','stock_keeping_unit_part_b'),(85,'part_b_7','b7',NULL,'part_b_supply','stock_keeping_unit_part_b'),(86,'part_b_8','b8',NULL,'part_b_supply','stock_keeping_unit_part_b'),(87,'part_d_5_ir','d5_ir',NULL,'part_d_supply_ir','stock_keeping_unit_part_d_ir'),(89,'part_e_6_ir','e6_ir',NULL,'part_e_supply_ir','stock_keeping_unit_part_e_ir'),(93,'part_c_3_ir','c3_ir',NULL,'part_c_supply_ir','stock_keeping_unit_part_c_ir'),(94,'part_e_1_ir','e1_ir',NULL,'part_e_supply_ir','stock_keeping_unit_part_e_ir'),(95,'part_d_9_ir','d9_ir',NULL,'part_d_supply_ir','stock_keeping_unit_part_d_ir'),(96,'part_a_5_ir','a5_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(97,'part_b_12_ir','b12_ir',NULL,'part_b_supply_ir','stock_keeping_unit_part_b_ir'),(99,'part_c_1_ir','c1_ir',NULL,'part_c_supply_ir','stock_keeping_unit_part_c_ir'),(100,'part_c_5_ir','c5_ir',NULL,'part_c_supply_ir','stock_keeping_unit_part_c_ir'),(105,'part_b_5_ir','b5_ir',NULL,'part_b_supply_ir','stock_keeping_unit_part_b_ir'),(107,'part_a_14_ir','a14_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(109,'part_a_2_ir','a2_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(110,'part_e_5_ir','e5_ir',NULL,'part_e_supply_ir','stock_keeping_unit_part_e_ir'),(111,'part_b_1_ir','b1_ir',NULL,'part_b_supply_ir','stock_keeping_unit_part_b_ir'),(118,'part_a_13_ir','a13_ir',NULL,'part_a_supply_ir','stock_keeping_unit_part_a_ir'),(122,'part_b_2_ir','b2_ir',NULL,'part_b_supply_ir','stock_keeping_unit_part_b_ir'),(124,'part_a_1','a1',NULL,NULL,'stock_keeping_unit_part_a'),(125,'part_a_3','a3',NULL,NULL,'stock_keeping_unit_part_a'),(126,'part_a_2','a2',NULL,'part_a_supply','stock_keeping_unit_part_a'),(127,'part_a_4','a4',NULL,'part_a_supply','stock_keeping_unit_part_a');
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
  `hasPartRefAndPose_Sku` varchar(255) DEFAULT NULL,
  `hasPartRefAndPose_ZAxis` varchar(255) DEFAULT NULL,
  `hadByPartRefAndPose_KitDesign` varchar(255) DEFAULT NULL,
  `hasPartRefAndPose_Point` varchar(255) DEFAULT NULL,
  `hasPartRefAndPose_XAxis` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`PartRefAndPoseID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasPartRefAndPose_Sku` (`hasPartRefAndPose_Sku`),
  KEY `fkhasPartRefAndPose_ZAxis` (`hasPartRefAndPose_ZAxis`),
  KEY `fkhadByPartRefAndPose_KitDesign` (`hadByPartRefAndPose_KitDesign`),
  KEY `fkhasPartRefAndPose_Point` (`hasPartRefAndPose_Point`),
  KEY `fkhasPartRefAndPose_XAxis` (`hasPartRefAndPose_XAxis`),
  CONSTRAINT `fkhasPartRefAndPose_XAxis` FOREIGN KEY (`hasPartRefAndPose_XAxis`) REFERENCES `Vector` (`_NAME`),
  CONSTRAINT `fkhadByPartRefAndPose_KitDesign` FOREIGN KEY (`hadByPartRefAndPose_KitDesign`) REFERENCES `KitDesign` (`_NAME`),
  CONSTRAINT `fkhasPartRefAndPose_Point` FOREIGN KEY (`hasPartRefAndPose_Point`) REFERENCES `Point` (`_NAME`),
  CONSTRAINT `fkhasPartRefAndPose_Sku` FOREIGN KEY (`hasPartRefAndPose_Sku`) REFERENCES `StockKeepingUnit` (`_NAME`),
  CONSTRAINT `fkhasPartRefAndPose_ZAxis` FOREIGN KEY (`hasPartRefAndPose_ZAxis`) REFERENCES `Vector` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PartRefAndPose`
--

LOCK TABLES `PartRefAndPose` WRITE;
/*!40000 ALTER TABLE `PartRefAndPose` DISABLE KEYS */;
INSERT INTO `PartRefAndPose` VALUES (5,'part_ref_and_pose_kit_a4b3c2d1_a_3_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a4b3c2d1_a_3_ir','kit_design_a4b3c2d1_ir','point_kit_a4b3c2d1_a_3_ir','x_axis_kit_a4b3c2d1_a_3_ir'),(24,'part_ref_and_pose_kit_a4b3c3_b_1_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a4b3c3_b_1_ir','kit_design_a4b3c3_ir','point_kit_a4b3c3_b_1_ir','x_axis_kit_a4b3c3_b_1_ir'),(44,'part_ref_and_pose_kit_a4b3c2d1_c_1_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a4b3c2d1_c_1_ir','kit_design_a4b3c2d1_ir','point_kit_a4b3c2d1_c_1_ir','x_axis_kit_a4b3c2d1_c_1_ir'),(59,'part_ref_and_pose_kit_a4b3c3_c_1_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a4b3c3_c_1_ir','kit_design_a4b3c3_ir','point_kit_a4b3c3_c_1_ir','x_axis_kit_a4b3c3_c_1_ir'),(63,'part_ref_and_pose_kit_a4b4c2_a_1_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a4b4c2_a_1_ir','kit_design_a4b4c2_ir','point_kit_a4b4c2_a_1_ir','x_axis_kit_a4b4c2_a_1_ir'),(105,'part_ref_and_pose_kit_a4b4c2_b_2_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a4b4c2_b_2_ir','kit_design_a4b4c2_ir','point_kit_a4b4c2_b_2_ir','x_axis_kit_a4b4c2_b_2_ir'),(160,'part_ref_and_pose_kit_a4b3c2d1_b_3_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a4b3c2d1_b_3_ir','kit_design_a4b3c2d1_ir','point_kit_a4b3c2d1_b_3_ir','x_axis_kit_a4b3c2d1_b_3_ir'),(164,'part_ref_and_pose_kit_a4b4c2_b_4_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a4b4c2_b_4_ir','kit_design_a4b4c2_ir','point_kit_a4b4c2_b_4_ir','x_axis_kit_a4b4c2_b_4_ir'),(166,'part_ref_and_pose_kit_a4b3c3_a_3_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a4b3c3_a_3_ir','kit_design_a4b3c3_ir','point_kit_a4b3c3_a_3_ir','x_axis_kit_a4b3c3_a_3_ir'),(174,'part_ref_and_pose_kit_a2b3c3d1e1_c_1_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a2b3c3d1e1_c_1_ir','kit_design_a2b3c3d1e1_ir','point_kit_a2b3c3d1e1_c_1_ir','x_axis_kit_a2b3c3d1e1_c_1_ir'),(180,'part_ref_and_pose_kit_a2b3c5_c_1_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a2b3c5_c_1_ir','kit_design_a2b3c5_ir','point_kit_a2b3c5_c_1_ir','x_axis_kit_a2b3c5_c_1_ir'),(187,'part_ref_and_pose_kit_a2b3c3d1e1_e_1_ir','stock_keeping_unit_parts_e_tray_ir','z_axis_kit_a2b3c3d1e1_e_1_ir','kit_design_a2b3c3d1e1_ir','point_kit_a2b3c3d1e1_e_1_ir','x_axis_kit_a2b3c3d1e1_e_1_ir'),(190,'part_ref_and_pose_kit_a2b3c3d1e1_b_3_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a2b3c3d1e1_b_3_ir','kit_design_a2b3c3d1e1_ir','point_kit_a2b3c3d1e1_b_3_ir','x_axis_kit_a2b3c3d1e1_b_3_ir'),(238,'part_ref_and_pose_kit_a4b4c2_a_3_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a4b4c2_a_3_ir','kit_design_a4b4c2_ir','point_kit_a4b4c2_a_3_ir','x_axis_kit_a4b4c2_a_3_ir'),(243,'part_ref_and_pose_kit_a2b1c1_a_2','stock_keeping_unit_part_a','z_axis_kit_a2b1c1_a_2','kit_design_a2b1c1','point_kit_a2b1c1_a_2','x_axis_kit_a2b1c1_a_2'),(245,'part_ref_and_pose_kit_a2b1c1_a_1','stock_keeping_unit_part_a','z_axis_kit_a2b1c1_a_1','kit_design_a2b1c1','point_kit_a2b1c1_a_1','x_axis_kit_a2b1c1_a_1'),(262,'part_ref_and_pose_kit_a4b3c2d1_b_2_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a4b3c2d1_b_2_ir','kit_design_a4b3c2d1_ir','point_kit_a4b3c2d1_b_2_ir','x_axis_kit_a4b3c2d1_b_2_ir'),(267,'part_ref_and_pose_kit_a4b3c3_c_2_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a4b3c3_c_2_ir','kit_design_a4b3c3_ir','point_kit_a4b3c3_c_2_ir','x_axis_kit_a4b3c3_c_2_ir'),(281,'part_ref_and_pose_kit_a4b3c3_a_1_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a4b3c3_a_1_ir','kit_design_a4b3c3_ir','point_kit_a4b3c3_a_1_ir','x_axis_kit_a4b3c3_a_1_ir'),(326,'part_ref_and_pose_kit_a4b4c2_c_2_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a4b4c2_c_2_ir','kit_design_a4b4c2_ir','point_kit_a4b4c2_c_2_ir','x_axis_kit_a4b4c2_c_2_ir'),(362,'part_ref_and_pose_kit_a4b4c2_b_1_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a4b4c2_b_1_ir','kit_design_a4b4c2_ir','point_kit_a4b4c2_b_1_ir','x_axis_kit_a4b4c2_b_1_ir'),(366,'part_ref_and_pose_kit_a2b3c3d1e1_d_1_ir','stock_keeping_unit_parts_d_tray_ir','z_axis_kit_a2b3c3d1e1_d_1_ir','kit_design_a2b3c3d1e1_ir','point_kit_a2b3c3d1e1_d_1_ir','x_axis_kit_a2b3c3d1e1_d_1_ir'),(368,'part_ref_and_pose_kit_a2b3c5_b_3_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a2b3c5_b_3_ir','kit_design_a2b3c5_ir','point_kit_a2b3c5_b_3_ir','x_axis_kit_a2b3c5_b_3_ir'),(405,'part_ref_and_pose_kit_a4b3c3_a_4_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a4b3c3_a_4_ir','kit_design_a4b3c3_ir','point_kit_a4b3c3_a_4_ir','x_axis_kit_a4b3c3_a_4_ir'),(409,'part_ref_and_pose_kit_a2b3c3d1e1_c_2_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a2b3c3d1e1_c_2_ir','kit_design_a2b3c3d1e1_ir','point_kit_a2b3c3d1e1_c_2_ir','x_axis_kit_a2b3c3d1e1_c_2_ir'),(414,'part_ref_and_pose_kit_a2b3c5_c_5_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a2b3c5_c_5_ir','kit_design_a2b3c5_ir','point_kit_a2b3c5_c_5_ir','x_axis_kit_a2b3c5_c_5_ir'),(415,'part_ref_and_pose_kit_a2b2c1_b_2','stock_keeping_unit_part_b','z_axis_kit_a2b2c1_b_2','kit_design_a2b2c1','point_kit_a2b2c1_b_2','x_axis_kit_a2b2c1_b_2'),(416,'part_ref_and_pose_kit_a2b2c1_b_1','stock_keeping_unit_part_b','z_axis_kit_a2b2c1_b_1','kit_design_a2b2c1','point_kit_a2b2c1_b_1','x_axis_kit_a2b2c1_b_1'),(468,'part_ref_and_pose_kit_a4b4c2_c_1_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a4b4c2_c_1_ir','kit_design_a4b4c2_ir','point_kit_a4b4c2_c_1_ir','x_axis_kit_a4b4c2_c_1_ir'),(481,'part_ref_and_pose_kit_a4b3c3_a_2_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a4b3c3_a_2_ir','kit_design_a4b3c3_ir','point_kit_a4b3c3_a_2_ir','x_axis_kit_a4b3c3_a_2_ir'),(492,'part_ref_and_pose_kit_a2b3c3d1e1_b_1_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a2b3c3d1e1_b_1_ir','kit_design_a2b3c3d1e1_ir','point_kit_a2b3c3d1e1_b_1_ir','x_axis_kit_a2b3c3d1e1_b_1_ir'),(499,'part_ref_and_pose_kit_a2b3c5_b_2_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a2b3c5_b_2_ir','kit_design_a2b3c5_ir','point_kit_a2b3c5_b_2_ir','x_axis_kit_a2b3c5_b_2_ir'),(516,'part_ref_and_pose_kit_a2b3c5_b_1_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a2b3c5_b_1_ir','kit_design_a2b3c5_ir','point_kit_a2b3c5_b_1_ir','x_axis_kit_a2b3c5_b_1_ir'),(529,'part_ref_and_pose_kit_a2b3c5_c_2_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a2b3c5_c_2_ir','kit_design_a2b3c5_ir','point_kit_a2b3c5_c_2_ir','x_axis_kit_a2b3c5_c_2_ir'),(531,'part_ref_and_pose_kit_a4b3c3_c_3_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a4b3c3_c_3_ir','kit_design_a4b3c3_ir','point_kit_a4b3c3_c_3_ir','x_axis_kit_a4b3c3_c_3_ir'),(538,'part_ref_and_pose_kit_a2b1c1_c_1','stock_keeping_unit_part_c','z_axis_kit_a2b1c1_c_1','kit_design_a2b1c1','point_kit_a2b1c1_c_1','x_axis_kit_a2b1c1_c_1'),(546,'part_ref_and_pose_kit_a4b3c3_b_3_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a4b3c3_b_3_ir','kit_design_a4b3c3_ir','point_kit_a4b3c3_b_3_ir','x_axis_kit_a4b3c3_b_3_ir'),(559,'part_ref_and_pose_kit_a4b3c3_b_2_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a4b3c3_b_2_ir','kit_design_a4b3c3_ir','point_kit_a4b3c3_b_2_ir','x_axis_kit_a4b3c3_b_2_ir'),(568,'part_ref_and_pose_kit_a2b3c3d1e1_b_2_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a2b3c3d1e1_b_2_ir','kit_design_a2b3c3d1e1_ir','point_kit_a2b3c3d1e1_b_2_ir','x_axis_kit_a2b3c3d1e1_b_2_ir'),(574,'part_ref_and_pose_kit_a4b3c2d1_a_2_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a4b3c2d1_a_2_ir','kit_design_a4b3c2d1_ir','point_kit_a4b3c2d1_a_2_ir','x_axis_kit_a4b3c2d1_a_2_ir'),(596,'part_ref_and_pose_kit_a2b3c5_c_4_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a2b3c5_c_4_ir','kit_design_a2b3c5_ir','point_kit_a2b3c5_c_4_ir','x_axis_kit_a2b3c5_c_4_ir'),(597,'part_ref_and_pose_kit_a2b3c3d1e1_c_3_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a2b3c3d1e1_c_3_ir','kit_design_a2b3c3d1e1_ir','point_kit_a2b3c3d1e1_c_3_ir','x_axis_kit_a2b3c3d1e1_c_3_ir'),(616,'part_ref_and_pose_kit_a4b4c2_a_4_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a4b4c2_a_4_ir','kit_design_a4b4c2_ir','point_kit_a4b4c2_a_4_ir','x_axis_kit_a4b4c2_a_4_ir'),(621,'part_ref_and_pose_kit_a2b3c3d1e1_a_2_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a2b3c3d1e1_a_2_ir','kit_design_a2b3c3d1e1_ir','point_kit_a2b3c3d1e1_a_2_ir','x_axis_kit_a2b3c3d1e1_a_2_ir'),(628,'part_ref_and_pose_kit_a4b4c2_b_3_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a4b4c2_b_3_ir','kit_design_a4b4c2_ir','point_kit_a4b4c2_b_3_ir','x_axis_kit_a4b4c2_b_3_ir'),(653,'part_ref_and_pose_kit_a4b3c2d1_b_1_ir','stock_keeping_unit_parts_b_tray_ir','z_axis_kit_a4b3c2d1_b_1_ir','kit_design_a4b3c2d1_ir','point_kit_a4b3c2d1_b_1_ir','x_axis_kit_a4b3c2d1_b_1_ir'),(677,'part_ref_and_pose_kit_a2b3c3d1e1_a_1_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a2b3c3d1e1_a_1_ir','kit_design_a2b3c3d1e1_ir','point_kit_a2b3c3d1e1_a_1_ir','x_axis_kit_a2b3c3d1e1_a_1_ir'),(681,'part_ref_and_pose_kit_a2b1c1_b_1','stock_keeping_unit_part_b','z_axis_kit_a2b1c1_b_1','kit_design_a2b1c1','point_kit_a2b1c1_b_1','x_axis_kit_a2b1c1_b_1'),(700,'part_ref_and_pose_kit_a4b3c2d1_a_4_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a4b3c2d1_a_4_ir','kit_design_a4b3c2d1_ir','point_kit_a4b3c2d1_a_4_ir','x_axis_kit_a4b3c2d1_a_4_ir'),(705,'part_ref_and_pose_kit_a2b3c5_a_2_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a2b3c5_a_2_ir','kit_design_a2b3c5_ir','point_kit_a2b3c5_a_2_ir','x_axis_kit_a2b3c5_a_2_ir'),(709,'part_ref_and_pose_kit_a4b3c2d1_d_1_ir','stock_keeping_unit_parts_d_tray_ir','z_axis_kit_a4b3c2d1_d_1_ir','kit_design_a4b3c2d1_ir','point_kit_a4b3c2d1_d_1_ir','x_axis_kit_a4b3c2d1_d_1_ir'),(710,'part_ref_and_pose_kit_a2b3c5_c_3_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a2b3c5_c_3_ir','kit_design_a2b3c5_ir','point_kit_a2b3c5_c_3_ir','x_axis_kit_a2b3c5_c_3_ir'),(758,'part_ref_and_pose_kit_a2b3c5_a_1_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a2b3c5_a_1_ir','kit_design_a2b3c5_ir','point_kit_a2b3c5_a_1_ir','x_axis_kit_a2b3c5_a_1_ir'),(767,'part_ref_and_pose_kit_a2b2c1_c_1','stock_keeping_unit_part_c','z_axis_kit_a2b2c1_c_1','kit_design_a2b2c1','point_kit_a2b2c1_c_1','x_axis_kit_a2b2c1_c_1'),(774,'part_ref_and_pose_kit_a2b2c1_a_1','stock_keeping_unit_part_a','z_axis_kit_a2b2c1_a_1','kit_design_a2b2c1','point_kit_a2b2c1_a_1','x_axis_kit_a2b2c1_a_1'),(776,'part_ref_and_pose_kit_a2b2c1_a_2','stock_keeping_unit_part_a','z_axis_kit_a2b2c1_a_2','kit_design_a2b2c1','point_kit_a2b2c1_a_2','x_axis_kit_a2b2c1_a_2'),(790,'part_ref_and_pose_kit_a4b4c2_a_2_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a4b4c2_a_2_ir','kit_design_a4b4c2_ir','point_kit_a4b4c2_a_2_ir','x_axis_kit_a4b4c2_a_2_ir'),(798,'part_ref_and_pose_kit_a4b3c2d1_a_1_ir','stock_keeping_unit_parts_a_tray_ir','z_axis_kit_a4b3c2d1_a_1_ir','kit_design_a4b3c2d1_ir','point_kit_a4b3c2d1_a_1_ir','x_axis_kit_a4b3c2d1_a_1_ir'),(807,'part_ref_and_pose_kit_a4b3c2d1_c_2_ir','stock_keeping_unit_parts_c_tray_ir','z_axis_kit_a4b3c2d1_c_2_ir','kit_design_a4b3c2d1_ir','point_kit_a4b3c2d1_c_2_ir','x_axis_kit_a4b3c2d1_c_2_ir');
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
  `hasPartsBin_PartQuantity` int(11) NOT NULL,
  `hasPartsBin_SerialNumber` varchar(100) NOT NULL,
  `hasPartsBin_Sku` varchar(255) DEFAULT NULL,
  `hasPartsBin_PartSku` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`PartsBinID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasPartsBin_Sku` (`hasPartsBin_Sku`),
  KEY `fkhasPartsBin_PartSku` (`hasPartsBin_PartSku`),
  CONSTRAINT `fkhasPartsBin_PartSku` FOREIGN KEY (`hasPartsBin_PartSku`) REFERENCES `StockKeepingUnit` (`_NAME`),
  CONSTRAINT `fkhasPartsBin_Sku` FOREIGN KEY (`hasPartsBin_Sku`) REFERENCES `StockKeepingUnit` (`_NAME`)
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
  `hasPartsTray_PartQuantity` int(11) NOT NULL,
  `hasPartsTray_SerialNumber` varchar(100) NOT NULL,
  `hasPartsTray_Sku` varchar(255) DEFAULT NULL,
  `hasPartsTray_PartSku` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`PartsTrayID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasPartsTray_Sku` (`hasPartsTray_Sku`),
  KEY `fkhasPartsTray_PartSku` (`hasPartsTray_PartSku`),
  CONSTRAINT `fkhasPartsTray_PartSku` FOREIGN KEY (`hasPartsTray_PartSku`) REFERENCES `StockKeepingUnit` (`_NAME`),
  CONSTRAINT `fkhasPartsTray_Sku` FOREIGN KEY (`hasPartsTray_Sku`) REFERENCES `StockKeepingUnit` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PartsTray`
--

LOCK TABLES `PartsTray` WRITE;
/*!40000 ALTER TABLE `PartsTray` DISABLE KEYS */;
INSERT INTO `PartsTray` VALUES (3,'part_d_tray_ir',0,'9','stock_keeping_unit_parts_d_tray_ir','stock_keeping_unit_part_d_ir'),(4,'part_b_tray_ir',0,'7','stock_keeping_unit_parts_b_tray_ir','stock_keeping_unit_part_b_ir'),(18,'part_a_tray',0,'6','stock_keeping_unit_parts_tray_a','stock_keeping_unit_part_a'),(41,'part_a_tray_ir',0,'6','stock_keeping_unit_parts_a_tray_ir','stock_keeping_unit_part_a_ir'),(51,'part_b_tray',0,'7','stock_keeping_unit_parts_tray_b','stock_keeping_unit_part_b'),(59,'part_c_tray_ir',0,'8','stock_keeping_unit_parts_c_tray_ir','stock_keeping_unit_part_c_ir'),(61,'part_c_tray',0,'8','stock_keeping_unit_parts_tray_c','stock_keeping_unit_part_c'),(103,'part_e_tray_ir',0,'10','stock_keeping_unit_parts_e_tray_ir','stock_keeping_unit_part_e_ir');
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
  `hasPartsTrayWithParts_PartsTray` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`PartsTrayWithPartsID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhasPartsTrayWithParts_PartsTray` (`hasPartsTrayWithParts_PartsTray`),
  CONSTRAINT `fkhasPartsTrayWithParts_PartsTray` FOREIGN KEY (`hasPartsTrayWithParts_PartsTray`) REFERENCES `PartsTray` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PartsTrayWithParts`
--

LOCK TABLES `PartsTrayWithParts` WRITE;
/*!40000 ALTER TABLE `PartsTrayWithParts` DISABLE KEYS */;
INSERT INTO `PartsTrayWithParts` VALUES (115,'part_a_supply','part_a_tray'),(121,'part_a_supply_ir','part_a_tray_ir'),(91,'part_b_supply','part_b_tray'),(66,'part_b_supply_ir','part_b_tray_ir'),(16,'part_c_supply','part_c_tray'),(73,'part_c_supply_ir','part_c_tray_ir'),(104,'part_d_supply_ir','part_d_tray_ir'),(32,'part_e_supply_ir','part_e_tray_ir');
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
  `hasPhysicalLocation_Timestamp` varchar(255) DEFAULT NULL,
  `hadBySecondaryLocation_SolidObject` varchar(255) DEFAULT NULL,
  `hasPhysicalLocation_RefObject` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`PhysicalLocationID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadBySecondaryLocation_SolidObject` (`hadBySecondaryLocation_SolidObject`),
  KEY `fkhasPhysicalLocation_RefObject` (`hasPhysicalLocation_RefObject`),
  CONSTRAINT `fkhasPhysicalLocation_RefObject` FOREIGN KEY (`hasPhysicalLocation_RefObject`) REFERENCES `SolidObject` (`_NAME`),
  CONSTRAINT `fkhadBySecondaryLocation_SolidObject` FOREIGN KEY (`hadBySecondaryLocation_SolidObject`) REFERENCES `SolidObject` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PhysicalLocation`
--

LOCK TABLES `PhysicalLocation` WRITE;
/*!40000 ALTER TABLE `PhysicalLocation` DISABLE KEYS */;
INSERT INTO `PhysicalLocation` VALUES (8,'part_b_3_pose',NULL,NULL,'part_b_supply'),(10,'finished_kit_receiver_pose',NULL,NULL,'kitting_workstation_1'),(11,'part_b_5_pose',NULL,NULL,'part_b_supply'),(12,'part_b_4_pose',NULL,NULL,'part_b_supply'),(13,'part_c_4_pose',NULL,NULL,'part_c_supply'),(19,'part_b_grasp_pose',NULL,NULL,'kitting_workstation_1'),(21,'part_a_tray_pose',NULL,NULL,'part_a_supply'),(34,'part_d_tray_pose_ir',NULL,NULL,'part_d_supply_ir'),(39,'part_b_1_pose_ir',NULL,NULL,'part_b_supply_ir'),(54,'part_a_10_pose_ir',NULL,NULL,'part_a_supply_ir'),(56,'part_a_2_pose',NULL,NULL,'part_a_supply'),(62,'part_d_1_pose_ir',NULL,NULL,'part_d_supply_ir'),(76,'part_b_supply_pose_ir',NULL,NULL,'kitting_workstation_1'),(80,'part_b_6_pose',NULL,NULL,'part_b_supply'),(83,'part_b_9_pose_ir',NULL,NULL,'part_b_supply_ir'),(86,'part_b_1_pose','',NULL,'kit_a2b2c1'),(91,'part_b_2_pose_ir',NULL,NULL,'part_b_supply_ir'),(95,'part_c_5_pose','',NULL,'kit_a2b2c1'),(96,'kit_tray_3_pose',NULL,NULL,'empty_kit_tray_supply'),(101,'part_c_4_pose_ir',NULL,NULL,'part_c_supply_ir'),(104,'part_a_4_pose_ir',NULL,NULL,'part_a_supply_ir'),(111,'part_c_tray_pose',NULL,NULL,'part_c_supply'),(117,'part_c_grasp_pose',NULL,NULL,'kitting_workstation_1'),(124,'part_c_8_pose_ir',NULL,NULL,'part_c_supply_ir'),(127,'part_c_6_pose_ir',NULL,NULL,'part_c_supply_ir'),(130,'part_c_7_pose_ir',NULL,NULL,'part_c_supply_ir'),(140,'part_c_supply_pose_ir',NULL,NULL,'kitting_workstation_1'),(144,'part_a_4_pose',NULL,NULL,'part_a_supply'),(156,'part_gear_holder_pose',NULL,NULL,'kitting_workstation_1'),(175,'kit_tray_3_pose_ir',NULL,NULL,'empty_kit_tray_supply_ir'),(178,'part_b_8_pose_ir',NULL,NULL,'part_b_supply_ir'),(189,'part_c_2_pose_ir',NULL,NULL,'part_c_supply_ir'),(194,'part_e_3_pose_ir',NULL,NULL,'part_e_supply_ir'),(198,'part_a_5_pose_ir',NULL,NULL,'part_a_supply_ir'),(202,'finished_kit_receiver_pose_ir',NULL,NULL,'kitting_workstation_1'),(211,'part_b_supply_pose',NULL,NULL,'kitting_workstation_1'),(215,'part_b_4_pose_ir',NULL,NULL,'part_b_supply_ir'),(221,'part_a_grasp_pose',NULL,NULL,'kitting_workstation_1'),(225,'part_a_16_pose_ir',NULL,NULL,'part_a_supply_ir'),(239,'part_gear_5_pose',NULL,NULL,'kitting_workstation_1'),(241,'part_a_15_pose_ir',NULL,NULL,'part_a_supply_ir'),(242,'part_b_10_pose_ir',NULL,NULL,'part_b_supply_ir'),(256,'part_a_13_pose_ir',NULL,NULL,'part_a_supply_ir'),(270,'part_c_7_pose',NULL,NULL,'part_c_supply'),(288,'part_e_2_pose_ir',NULL,NULL,'part_e_supply_ir'),(302,'part_gear_boss_pose',NULL,NULL,'kitting_workstation_1'),(318,'kit_tray_1_pose',NULL,NULL,'empty_kit_tray_supply'),(325,'relative_location_in_1',NULL,NULL,'kitting_workstation_1'),(330,'part_gear_shaft_3_pose',NULL,NULL,'kitting_workstation_1'),(331,'kit_tray_4_pose_ir',NULL,NULL,'empty_kit_tray_supply_ir'),(340,'kit_a2b2c1_pose',NULL,NULL,'work_table_1'),(344,'part_a_17_pose_ir',NULL,NULL,'part_a_supply_ir'),(347,'part_c_6_pose',NULL,NULL,'part_c_supply'),(352,'part_c_3_pose',NULL,NULL,'part_c_supply'),(354,'changing_station_base_pose',NULL,NULL,'changing_station_1'),(356,'part_a_3_pose_ir',NULL,NULL,'part_a_supply_ir'),(359,'part_a_3_pose','',NULL,'kit_a2b2c1'),(376,'changing_station_pose',NULL,NULL,'kitting_workstation_1'),(377,'part_e_5_pose_ir',NULL,NULL,'part_e_supply_ir'),(386,'part_e_tray_pose_ir',NULL,NULL,'part_e_supply_ir'),(390,'part_gear_base_pose',NULL,NULL,'kitting_workstation_1'),(399,'part_d_4_pose_ir',NULL,NULL,'part_d_supply_ir'),(401,'part_b_12_pose_ir',NULL,NULL,'part_b_supply_ir'),(408,'part_e_1_pose_ir',NULL,NULL,'part_e_supply_ir'),(417,'kit_tray_1_pose_ir',NULL,NULL,'empty_kit_tray_supply_ir'),(420,'part_b_2_pose','',NULL,'kit_a2b2c1'),(436,'part_d_2_pose_ir',NULL,NULL,'part_d_supply_ir'),(438,'part_gripper_pose',NULL,NULL,'part_gripper_holder'),(440,'empty_kit_tray_supply_pose_ir',NULL,NULL,'kitting_workstation_1'),(441,'part_c_3_pose_ir',NULL,NULL,'part_c_supply_ir'),(449,'part_b_6_pose_ir',NULL,NULL,'part_b_supply_ir'),(456,'part_b_11_pose_ir',NULL,NULL,'part_b_supply_ir'),(457,'part_b_7_pose',NULL,NULL,'part_b_supply'),(469,'part_b_tray_pose',NULL,NULL,'part_b_supply'),(487,'part_c_tray_pose_ir',NULL,NULL,'part_c_supply_ir'),(495,'part_a_11_pose_ir',NULL,NULL,'part_a_supply_ir'),(498,'part_d_9_pose_ir',NULL,NULL,'part_d_supply_ir'),(500,'part_c_5_pose_ir',NULL,NULL,'part_c_supply_ir'),(501,'part_b_7_pose_ir',NULL,NULL,'part_b_supply_ir'),(502,'part_a_1_pose_ir',NULL,NULL,'part_a_supply_ir'),(504,'part_gear_shaft_4_pose',NULL,NULL,'kitting_workstation_1'),(515,'part_b_3_pose_ir',NULL,NULL,'part_b_supply_ir'),(524,'part_b_5_pose_ir',NULL,NULL,'part_b_supply_ir'),(532,'part_c_2_pose',NULL,NULL,'part_c_supply'),(534,'part_a_9_pose_ir',NULL,NULL,'part_a_supply_ir'),(555,'finished_kit_box_pose',NULL,NULL,'finished_kit_receiver'),(557,'finished_kit_box_pose_ir',NULL,NULL,'finished_kit_receiver_ir'),(558,'part_c_supply_pose',NULL,NULL,'kitting_workstation_1'),(560,'part_d_5_pose_ir',NULL,NULL,'part_d_supply_ir'),(566,'part_d_3_pose_ir',NULL,NULL,'part_d_supply_ir'),(571,'part_a_supply_pose',NULL,NULL,'kitting_workstation_1'),(576,'part_a_12_pose_ir',NULL,NULL,'part_a_supply_ir'),(584,'part_e_6_pose_ir',NULL,NULL,'part_e_supply_ir'),(592,'part_a_supply_pose_ir',NULL,NULL,'kitting_workstation_1'),(602,'kit_tray_2_pose',NULL,NULL,'empty_kit_tray_supply'),(608,'part_c_1_pose_ir',NULL,NULL,'part_c_supply_ir'),(611,'robot_pose',NULL,NULL,'kitting_workstation_1'),(615,'part_d_6_pose_ir',NULL,NULL,'part_d_supply_ir'),(620,'tray_gripper_holder_pose',NULL,NULL,'changing_station_1'),(630,'part_gripper_holder_pose',NULL,NULL,'changing_station_1'),(633,'trash_table_pose',NULL,NULL,'kitting_workstation_1'),(643,'part_a_1_pose','',NULL,'kit_a2b2c1'),(646,'kit_tray_2_pose_ir',NULL,NULL,'empty_kit_tray_supply_ir'),(647,'part_gear_4_pose',NULL,NULL,'kitting_workstation_1'),(648,'part_gear_2_pose',NULL,NULL,'kitting_workstation_1'),(659,'part_e_supply_pose_ir',NULL,NULL,'kitting_workstation_1'),(673,'part_b_8_pose',NULL,NULL,'part_b_supply'),(682,'work_table_pose',NULL,NULL,'kitting_workstation_1'),(686,'part_a_18_pose_ir',NULL,NULL,'part_a_supply_ir'),(698,'part_a_tray_pose_ir',NULL,NULL,'part_a_supply_ir'),(706,'part_c_8_pose',NULL,NULL,'part_c_supply'),(715,'part_a_7_pose_ir',NULL,NULL,'part_a_supply_ir'),(718,'part_a_6_pose_ir',NULL,NULL,'part_a_supply_ir'),(723,'part_gear_shaft_2_pose',NULL,NULL,'kitting_workstation_1'),(750,'part_d_8_pose_ir',NULL,NULL,'part_d_supply_ir'),(753,'part_e_4_pose_ir',NULL,NULL,'part_e_supply_ir'),(755,'part_a_8_pose_ir',NULL,NULL,'part_a_supply_ir'),(771,'part_a_14_pose_ir',NULL,NULL,'part_a_supply_ir'),(780,'part_b_tray_pose_ir',NULL,NULL,'part_b_supply_ir'),(782,'part_gear_shaft_1_pose',NULL,NULL,'kitting_workstation_1'),(785,'kit_tray_5_pose_ir',NULL,NULL,'empty_kit_tray_supply_ir'),(795,'relative_location_on_1',NULL,NULL,'robot_1'),(799,'empty_kit_tray_box_pose',NULL,NULL,'empty_kit_tray_supply'),(808,'empty_kit_tray_supply_pose',NULL,NULL,'kitting_workstation_1'),(815,'part_d_7_pose_ir',NULL,NULL,'part_d_supply_ir'),(817,'part_d_supply_pose_ir',NULL,NULL,'kitting_workstation_1'),(820,'part_gear_3_pose',NULL,NULL,'kitting_workstation_1'),(821,'empty_kit_tray_box_pose_ir',NULL,NULL,'empty_kit_tray_supply_ir'),(826,'part_gear_1_pose',NULL,NULL,'kitting_workstation_1'),(827,'part_a_2_pose_ir',NULL,NULL,'part_a_supply_ir'),(829,'part_c_1_pose',NULL,NULL,'part_c_supply');
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
INSERT INTO `Point` VALUES (4,'part_gear_1_point',0.8,0,-0.05),(6,'part_gear_shaft_2_point',0.6,-2,-0.05),(7,'point_kit_a2b3c5_c_3_ir',0.7872,0.3301,0.065),(16,'point_kit_a2b1c1_a_2',0.4,0.3,0),(17,'point_kit_a2b1c1_a_1',0.2,0.3,0),(20,'part_a_10_point_ir',0.4695,0.216,0.065),(30,'part_e_4_point_ir',0.1656,0.1274,0.065),(32,'point_kit_a4b3c2d1_d_1_ir',0.0888,0.292,0.065),(37,'point_kit_a4b3c3_b_3_ir',0.635,0.1147,0.065),(40,'point_kit_a4b4c2_a_4_ir',0.6227,0.2924,0.065),(41,'point_kit_a4b3c3_a_1_ir',0.5461,0.3687,0.065),(45,'part_a_11_point_ir',0.5965,0.216,0.065),(47,'kit_tray_5_point_ir',-0.5,-1,-0.32),(48,'point_min',-1,-1,-2),(64,'part_c_3_point_ir',0.5334,0.3302,0.065),(66,'part_b_6_point',-0.24,-0.12,0.05),(71,'part_a_1_point',-0.159,0.149,0.036),(81,'point_kit_a2b3c3d1e1_b_1_ir',0.1268,0.0893,0.065),(84,'point_kit_a2b2c1_c_1',0.06,0.09,0.045),(85,'part_d_4_point_ir',0.1656,0.216,0.065),(87,'part_c_1_point',0.11,0.216,0.035),(90,'part_a_13_point_ir',0.0885,0.089,0.065),(107,'point_kit_a4b4c2_b_2_ir',0.3306,0.2164,0.065),(113,'part_c_tray_point',0,0,0),(114,'kit_tray_3_point',2,0,-0.225),(116,'part_a_5_point_ir',0.5965,0.343,0.065),(123,'part_b_3_point',0.08,0.12,0.05),(128,'point_kit_a4b3c2d1_a_4_ir',0.0888,0.0888,0.065),(131,'part_a_2_point_ir',0.2155,0.343,0.065),(133,'part_b_1_point_ir',0.0885,0.3306,0.065),(135,'point_max',1,1,0),(145,'part_d_8_point_ir',0.445,0.089,0.065),(146,'changing_station_base_point',0,0,0),(147,'point_kit_a4b3c2d1_a_1_ir',0.6222,0.3682,0.065),(148,'point_kit_a4b3c3_c_1_ir',0.127,0.3306,0.065),(161,'part_b_5_point_ir',0.5965,0.3306,0.065),(162,'kit_tray_4_point_ir',-0.5,-1,-0.32),(163,'point_kit_a4b3c2d1_a_3_ir',0.6222,0.1142,0.065),(171,'point_kit_a4b3c3_a_3_ir',0.5461,0.2417,0.065),(179,'part_c_6_point_ir',0.3302,0.127,0.065),(184,'part_e_tray_point_ir',0,0,0),(186,'empty_kit_tray_box_point',0.5,0,0),(192,'part_b_5_point',-0.08,-0.12,0.05),(195,'point_kit_a2b3c3d1e1_c_1_ir',0.457,0.3306,0.065),(197,'part_b_2_point_ir',0.2155,0.3306,0.065),(201,'point_kit_a4b3c2d1_c_2_ir',0.2539,0.1269,0.065),(205,'part_b_7_point_ir',0.0885,0.1274,0.065),(214,'point_kit_a2b3c3d1e1_a_2_ir',0.8253,0.3687,0.065),(218,'part_c_2_point_ir',0.3302,0.3302,0.065),(219,'point_kit_a2b3c5_a_2_ir',0.2157,0.1142,0.065),(224,'part_b_12_point_ir',0.7235,0.1274,0.065),(228,'part_a_16_point_ir',0.4695,0.089,0.065),(237,'point_kit_a4b3c3_a_2_ir',0.6731,0.3687,0.065),(240,'part_c_3_point',-0.11,0.216,0.035),(249,'point_kit_a2b3c3d1e1_d_1_ir',0.2919,0.2925,0.065),(257,'point_kit_a2b2c1_a_2',-0.159,0.149,0.036),(259,'part_c_5_point_ir',0.127,0.127,0.065),(260,'point_kit_a2b2c1_a_1',-0.159,-0.145,0.036),(261,'part_e_6_point_ir',0.7244,0.1274,0.065),(265,'empty_kit_tray_supply_point',0.5,0,0),(266,'part_gear_holder_point',0.6,-2.3,-0.05),(272,'point_kit_a4b4c2_c_1_ir',0.1274,0.3813,0.065),(275,'part_b_11_point_ir',0.5965,0.1274,0.065),(279,'part_gear_boss_point',1.2,-0.2,-0.05),(280,'point_kit_a2b3c5_b_3_ir',0.7491,0.1269,0.065),(284,'part_d_7_point_ir',0.1656,0.089,0.065),(287,'part_b_2_point',0.219,0.166,0.08),(289,'part_gripper_point',0,0,0),(295,'part_c_4_point',-0.33,0.216,0.035),(303,'part_d_6_point_ir',0.7244,0.216,0.065),(305,'part_a_9_point_ir',0.3425,0.216,0.065),(307,'part_a_tray_point_ir',0,0,0),(310,'part_b_supply_point_ir',-3.4,-2.35,-0.32),(313,'point_kit_a4b3c3_b_1_ir',0.2921,0.128,0.065),(323,'part_a_4_point',-0.159,0.159,0.0275),(332,'point_kit_a2b1c1_c_1',0.4,0.5,0),(335,'part_c_2_point',0.33,0.216,0.035),(337,'kit_tray_2_point',0.75,0,-0.155),(338,'part_gripper_holder_point',0.25,0,-0.5),(343,'part_c_1_point_ir',0.127,0.3302,0.065),(350,'part_b_tray_point',0,0,0),(353,'part_e_2_point_ir',0.445,0.3306,0.065),(355,'point_kit_a2b3c5_a_1_ir',0.2157,0.2412,0.065),(363,'finished_kit_receiver_point_ir',1.5,0,0),(367,'kit_tray_1_point_ir',-0.5,-1,-0.32),(371,'part_b_7_point',0.08,-0.12,0.05),(373,'part_gear_shaft_3_point',0.6,-2.1,-0.05),(374,'part_b_8_point_ir',0.2155,0.1274,0.065),(382,'point_kit_a2b3c3d1e1_c_2_ir',0.6602,0.3306,0.065),(391,'part_c_7_point_ir',0.5334,0.127,0.065),(392,'robot_point',3,0,-2),(397,'part_a_3_point_ir',0.3425,0.343,0.065),(398,'part_a_2_point',0.159,-0.159,0.0275),(402,'point_kit_a2b3c5_b_2_ir',0.0887,0.2031,0.065),(404,'part_c_8_point_ir',0.7366,0.127,0.065),(406,'part_e_supply_point_ir',-0.25,-0.32,-0.32),(423,'part_a_14_point_ir',0.2155,0.089,0.065),(425,'part_d_tray_point_ir',0,0,0),(443,'part_c_6_point',0.33,-0.216,0.035),(444,'part_a_7_point_ir',0.0885,0.216,0.065),(447,'part_b_tray_point_ir',0,0,0),(451,'part_a_supply_point_ir',-0.25,-2.35,-0.32),(462,'empty_kit_tray_box_point_ir',0.5,0,0),(470,'kit_tray_2_point_ir',-0.5,-1,-0.32),(472,'part_gear_5_point',1,-0.2,-0.05),(476,'empty_kit_tray_supply_point_ir',0.5,0,0),(479,'part_b_3_point_ir',0.3425,0.3306,0.065),(482,'part_a_8_point_ir',0.2155,0.216,0.065),(485,'tray_gripper_holder_point',-0.25,0,-0.5),(497,'part_c_8_point',-0.33,-0.216,0.035),(503,'part_gear_shaft_1_point',0.6,-1.9,-0.05),(507,'part_b_4_point_ir',0.4695,0.3306,0.065),(508,'part_e_1_point_ir',0.1656,0.3306,0.065),(509,'part_a_18_point_ir',0.7235,0.089,0.065),(512,'part_c_grasp_point',0,0,0.0305),(514,'part_a_6_point_ir',0.7235,0.343,0.065),(517,'point_kit_a4b4c2_a_1_ir',0.4957,0.4194,0.065),(518,'point_kit_a4b4c2_b_3_ir',0.1274,0.08937,0.065),(519,'point_kit_a4b3c3_c_2_ir',0.3302,0.3306,0.065),(522,'part_e_5_point_ir',0.445,0.1274,0.065),(525,'part_d_2_point_ir',0.445,0.343,0.065),(535,'point_kit_a4b3c2d1_a_2_ir',0.6222,0.2412,0.065),(536,'point_kit_a4b3c3_b_2_ir',0.4191,0.1274,0.065),(537,'point_kit_a4b3c2d1_b_2_ir',0.4571,0.2412,0.065),(540,'part_a_3_point',-0.159,-0.145,0.036),(541,'point_kit_a4b4c2_a_3_ir',0.4957,0.2924,0.065),(542,'part_a_4_point_ir',0.4695,0.343,0.065),(548,'point_kit_a4b3c3_a_4_ir',0.6731,0.2417,0.065),(550,'part_c_supply_point',-3,-0.78,-0.28),(552,'part_d_5_point_ir',0.445,0.216,0.065),(561,'point_kit_a2b3c5_c_1_ir',0.3808,0.3301,0.065),(562,'part_a_tray_point',0,0,0),(569,'point_kit_a2b3c3d1e1_b_3_ir',0.8253,0.1274,0.065),(572,'part_d_3_point_ir',0.7244,0.343,0.065),(586,'part_gear_4_point',0.8,-0.2,-0.05),(588,'part_gear_2_point',1,0,-0.05),(590,'kit_tray_1_point',0.05,-0.75,-0.28),(600,'changing_station_point',7.5,0,0),(601,'part_a_supply_point',-2.85,-1.55,-0.3),(604,'part_b_6_point_ir',0.7235,0.3306,0.065),(607,'part_a_grasp_point',0,0,0.0219),(610,'point_kit_a4b3c3_c_3_ir',0.127,0.1274,0.065),(618,'point_kit_a2b3c3d1e1_e_1_ir',0.1268,0.2925,0.065),(627,'point_kit_a2b3c3d1e1_b_2_ir',0.6983,0.1274,0.065),(631,'part_gear_base_point',1,-2,-0.05),(634,'part_a_15_point_ir',0.3425,0.089,0.065),(638,'part_gear_3_point',1.2,0,-0.05),(642,'part_c_supply_point_ir',-3.4,-0.32,-0.32),(645,'part_b_9_point_ir',0.3425,0.1274,0.065),(649,'part_c_tray_point_ir',0,0,0),(660,'point_kit_a4b4c2_b_4_ir',0.3306,0.08937,0.065),(661,'point_kit_a4b4c2_b_1_ir',0.1274,0.2164,0.065),(668,'part_a_1_point_ir',0.0885,0.343,0.065),(669,'part_b_10_point_ir',0.4695,0.1274,0.065),(671,'kit_tray_3_point_ir',-0.5,-1,-0.32),(676,'part_b_1_point',0.171,-0.215,0.08),(679,'part_d_9_point_ir',0.7244,0.089,0.065),(688,'part_a_12_point_ir',0.7235,0.216,0.065),(699,'part_e_3_point_ir',0.7244,0.3306,0.065),(708,'part_d_supply_point_ir',0.4,-1.7,-0.32),(712,'finished_kit_box_point',0,0,0),(717,'part_d_1_point_ir',0.1656,0.343,0.065),(719,'part_b_4_point',0.24,0.12,0.05),(721,'trash_table_point',1,1,0),(722,'point_kit_a4b3c2d1_b_1_ir',0.4571,0.365,0.065),(728,'part_c_5_point',0.06,0.09,0.045),(731,'part_c_4_point_ir',0.7366,0.3302,0.065),(736,'point_kit_a4b3c2d1_b_3_ir',0.4571,0.1142,0.065),(737,'part_a_17_point_ir',0.5965,0.089,0.065),(740,'part_gear_shaft_4_point',0.6,-2.2,-0.05),(744,'part_b_supply_point',0.05,-1.5,-0.28),(747,'point_kit_a2b2c1_b_2',0.171,-0.215,0.08),(749,'point_kit_a2b2c1_b_1',0.219,0.166,0.08),(757,'part_b_8_point',0.24,-0.12,0.05),(760,'kit_a2b2c1_point',0.05,-0.75,-0.28),(763,'part_c_7_point',-0.11,-0.216,0.035),(770,'point_kit_a2b3c5_c_2_ir',0.584,0.3301,0.065),(777,'finished_kit_box_point_ir',0,0,0),(778,'point_kit_a2b3c3d1e1_a_1_ir',0.2919,0.0893,0.065),(789,'point_kit_a2b3c5_c_5_ir',0.584,0.1269,0.065),(794,'point_kit_a4b4c2_a_2_ir',0.6227,0.4194,0.065),(801,'part_b_grasp_point',0,0,0.0647),(802,'point_kit_a2b3c5_c_4_ir',0.3808,0.1269,0.065),(803,'finished_kit_receiver_point',1.5,0,0),(809,'point_kit_a4b3c2d1_c_1_ir',0.2539,0.3301,0.065),(816,'point_kit_a4b4c2_c_2_ir',0.3306,0.3813,0.065),(818,'point_kit_a2b1c1_b_1',0.2,0.5,0),(822,'point_kit_a2b3c5_b_1_ir',0.1268,0.3682,0.065),(828,'work_table_point',0.5,0,0),(831,'point_kit_a2b3c3d1e1_c_3_ir',0.457,0.1274,0.065);
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
  `hasPoseLocation_OrientationStandardDeviation` double DEFAULT NULL,
  `hasPoseLocation_PositionStandardDeviation` double DEFAULT NULL,
  `hadByGraspPose_ShapeDesign` varchar(255) DEFAULT NULL,
  `hasPoseLocation_XAxis` varchar(255) DEFAULT NULL,
  `hasPoseLocation_ZAxis` varchar(255) DEFAULT NULL,
  `hasPoseLocation_Point` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`PoseLocationID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByGraspPose_ShapeDesign` (`hadByGraspPose_ShapeDesign`),
  KEY `fkhasPoseLocation_XAxis` (`hasPoseLocation_XAxis`),
  KEY `fkhasPoseLocation_ZAxis` (`hasPoseLocation_ZAxis`),
  KEY `fkhasPoseLocation_Point` (`hasPoseLocation_Point`),
  CONSTRAINT `fkhasPoseLocation_Point` FOREIGN KEY (`hasPoseLocation_Point`) REFERENCES `Point` (`_NAME`),
  CONSTRAINT `fkhadByGraspPose_ShapeDesign` FOREIGN KEY (`hadByGraspPose_ShapeDesign`) REFERENCES `ShapeDesign` (`_NAME`),
  CONSTRAINT `fkhasPoseLocation_XAxis` FOREIGN KEY (`hasPoseLocation_XAxis`) REFERENCES `Vector` (`_NAME`),
  CONSTRAINT `fkhasPoseLocation_ZAxis` FOREIGN KEY (`hasPoseLocation_ZAxis`) REFERENCES `Vector` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PoseLocation`
--

LOCK TABLES `PoseLocation` WRITE;
/*!40000 ALTER TABLE `PoseLocation` DISABLE KEYS */;
INSERT INTO `PoseLocation` VALUES (8,'part_b_3_pose',NULL,NULL,NULL,'part_b_3_x_axis','part_b_3_z_axis','part_b_3_point'),(10,'finished_kit_receiver_pose',NULL,NULL,NULL,'finished_kit_receiver_x_axis','finished_kit_receiver_z_axis','finished_kit_receiver_point'),(11,'part_b_5_pose',NULL,NULL,NULL,'part_b_5_x_axis','part_b_5_z_axis','part_b_5_point'),(12,'part_b_4_pose',NULL,NULL,NULL,'part_b_4_x_axis','part_b_4_z_axis','part_b_4_point'),(13,'part_c_4_pose',NULL,NULL,NULL,'part_c_4_x_axis','part_c_4_z_axis','part_c_4_point'),(19,'part_b_grasp_pose',NULL,NULL,'shape_part_b','part_b_grasp_x_axis','part_b_grasp_z_axis','part_b_grasp_point'),(21,'part_a_tray_pose',NULL,NULL,NULL,'part_a_tray_x_axis','part_a_tray_z_axis','part_a_tray_point'),(34,'part_d_tray_pose_ir',NULL,NULL,NULL,'part_d_tray_x_axis_ir','part_d_tray_z_axis_ir','part_d_tray_point_ir'),(39,'part_b_1_pose_ir',NULL,NULL,NULL,'part_b_1_x_axis_ir','part_b_1_z_axis_ir','part_b_1_point_ir'),(54,'part_a_10_pose_ir',NULL,NULL,NULL,'part_a_10_x_axis_ir','part_a_10_z_axis_ir','part_a_10_point_ir'),(56,'part_a_2_pose',NULL,NULL,NULL,'part_a_2_x_axis','part_a_2_z_axis','part_a_2_point'),(62,'part_d_1_pose_ir',NULL,NULL,NULL,'part_d_1_x_axis_ir','part_d_1_z_axis_ir','part_d_1_point_ir'),(76,'part_b_supply_pose_ir',NULL,NULL,NULL,'part_b_supply_x_axis_ir','part_b_supply_z_axis_ir','part_b_supply_point_ir'),(80,'part_b_6_pose',NULL,NULL,NULL,'part_b_6_x_axis','part_b_6_z_axis','part_b_6_point'),(83,'part_b_9_pose_ir',NULL,NULL,NULL,'part_b_9_x_axis_ir','part_b_9_z_axis_ir','part_b_9_point_ir'),(86,'part_b_1_pose',NULL,NULL,NULL,'part_b_1_x_axis','part_b_1_z_axis','part_b_1_point'),(91,'part_b_2_pose_ir',NULL,NULL,NULL,'part_b_2_x_axis_ir','part_b_2_z_axis_ir','part_b_2_point_ir'),(95,'part_c_5_pose',NULL,NULL,NULL,'part_c_5_x_axis','part_c_5_z_axis','part_c_5_point'),(96,'kit_tray_3_pose',NULL,NULL,NULL,'kit_tray_3_x_axis','kit_tray_3_z_axis','kit_tray_3_point'),(101,'part_c_4_pose_ir',NULL,NULL,NULL,'part_c_4_x_axis_ir','part_c_4_z_axis_ir','part_c_4_point_ir'),(104,'part_a_4_pose_ir',NULL,NULL,NULL,'part_a_4_x_axis_ir','part_a_4_z_axis_ir','part_a_4_point_ir'),(111,'part_c_tray_pose',NULL,NULL,NULL,'part_c_tray_x_axis','part_c_tray_z_axis','part_c_tray_point'),(117,'part_c_grasp_pose',NULL,NULL,'shape_part_c','part_c_grasp_x_axis','part_c_grasp_z_axis','part_c_grasp_point'),(124,'part_c_8_pose_ir',NULL,NULL,NULL,'part_c_8_x_axis_ir','part_c_8_z_axis_ir','part_c_8_point_ir'),(127,'part_c_6_pose_ir',NULL,NULL,NULL,'part_c_6_x_axis_ir','part_c_6_z_axis_ir','part_c_6_point_ir'),(130,'part_c_7_pose_ir',NULL,NULL,NULL,'part_c_7_x_axis_ir','part_c_7_z_axis_ir','part_c_7_point_ir'),(140,'part_c_supply_pose_ir',NULL,NULL,NULL,'part_c_supply_x_axis_ir','part_c_supply_z_axis_ir','part_c_supply_point_ir'),(144,'part_a_4_pose',NULL,NULL,NULL,'part_a_4_x_axis','part_a_4_z_axis','part_a_4_point'),(156,'part_gear_holder_pose',NULL,NULL,NULL,'part_gear_holder_x_axis','part_gear_holder_z_axis','part_gear_holder_point'),(175,'kit_tray_3_pose_ir',NULL,NULL,NULL,'kit_tray_3_x_axis_ir','kit_tray_3_z_axis_ir','kit_tray_3_point_ir'),(178,'part_b_8_pose_ir',NULL,NULL,NULL,'part_b_8_x_axis_ir','part_b_8_z_axis_ir','part_b_8_point_ir'),(189,'part_c_2_pose_ir',NULL,NULL,NULL,'part_c_2_x_axis_ir','part_c_2_z_axis_ir','part_c_2_point_ir'),(194,'part_e_3_pose_ir',NULL,NULL,NULL,'part_e_3_x_axis_ir','part_e_3_z_axis_ir','part_e_3_point_ir'),(198,'part_a_5_pose_ir',NULL,NULL,NULL,'part_a_5_x_axis_ir','part_a_5_z_axis_ir','part_a_5_point_ir'),(202,'finished_kit_receiver_pose_ir',NULL,NULL,NULL,'finished_kit_receiver_x_axis_ir','finished_kit_receiver_z_axis_ir','finished_kit_receiver_point_ir'),(211,'part_b_supply_pose',NULL,NULL,NULL,'part_b_supply_x_axis','part_b_supply_z_axis','part_b_supply_point'),(215,'part_b_4_pose_ir',NULL,NULL,NULL,'part_b_4_x_axis_ir','part_b_4_z_axis_ir','part_b_4_point_ir'),(221,'part_a_grasp_pose',NULL,NULL,'shape_part_a','part_a_grasp_x_axis','part_a_grasp_z_axis','part_a_grasp_point'),(225,'part_a_16_pose_ir',NULL,NULL,NULL,'part_a_16_x_axis_ir','part_a_16_z_axis_ir','part_a_16_point_ir'),(239,'part_gear_5_pose',NULL,NULL,NULL,'part_gear_5_x_axis','part_gear_5_z_axis','part_gear_5_point'),(241,'part_a_15_pose_ir',NULL,NULL,NULL,'part_a_15_x_axis_ir','part_a_15_z_axis_ir','part_a_15_point_ir'),(242,'part_b_10_pose_ir',NULL,NULL,NULL,'part_b_10_x_axis_ir','part_b_10_z_axis_ir','part_b_10_point_ir'),(256,'part_a_13_pose_ir',NULL,NULL,NULL,'part_a_13_x_axis_ir','part_a_13_z_axis_ir','part_a_13_point_ir'),(270,'part_c_7_pose',NULL,NULL,NULL,'part_c_7_x_axis','part_c_7_z_axis','part_c_7_point'),(288,'part_e_2_pose_ir',NULL,NULL,NULL,'part_e_2_x_axis_ir','part_e_2_z_axis_ir','part_e_2_point_ir'),(302,'part_gear_boss_pose',NULL,NULL,NULL,'part_gear_boss_x_axis','part_gear_boss_z_axis','part_gear_boss_point'),(318,'kit_tray_1_pose',NULL,NULL,NULL,'kit_tray_1_x_axis','kit_tray_1_z_axis','kit_tray_1_point'),(330,'part_gear_shaft_3_pose',NULL,NULL,NULL,'part_gear_shaft_3_x_axis','part_gear_shaft_3_z_axis','part_gear_shaft_3_point'),(331,'kit_tray_4_pose_ir',NULL,NULL,NULL,'kit_tray_4_x_axis_ir','kit_tray_4_z_axis_ir','kit_tray_4_point_ir'),(340,'kit_a2b2c1_pose',NULL,NULL,NULL,'kit_a2b2c1_x_axis','kit_a2b2c1_z_axis','kit_a2b2c1_point'),(344,'part_a_17_pose_ir',NULL,NULL,NULL,'part_a_17_x_axis_ir','part_a_17_z_axis_ir','part_a_17_point_ir'),(347,'part_c_6_pose',NULL,NULL,NULL,'part_c_6_x_axis','part_c_6_z_axis','part_c_6_point'),(352,'part_c_3_pose',NULL,NULL,NULL,'part_c_3_x_axis','part_c_3_z_axis','part_c_3_point'),(354,'changing_station_base_pose',NULL,NULL,NULL,'changing_station_base_x_axis','changing_station_base_z_axis','changing_station_base_point'),(356,'part_a_3_pose_ir',NULL,NULL,NULL,'part_a_3_x_axis_ir','part_a_3_z_axis_ir','part_a_3_point_ir'),(359,'part_a_3_pose',NULL,NULL,NULL,'part_a_3_x_axis','part_a_3_z_axis','part_a_3_point'),(376,'changing_station_pose',NULL,NULL,NULL,'changing_station_x_axis','changing_station_z_axis','changing_station_point'),(377,'part_e_5_pose_ir',NULL,NULL,NULL,'part_e_5_x_axis_ir','part_e_5_z_axis_ir','part_e_5_point_ir'),(386,'part_e_tray_pose_ir',NULL,NULL,NULL,'part_e_tray_x_axis_ir','part_e_tray_z_axis_ir','part_e_tray_point_ir'),(390,'part_gear_base_pose',NULL,NULL,NULL,'part_gear_base_x_axis','part_gear_base_z_axis','part_gear_base_point'),(399,'part_d_4_pose_ir',NULL,NULL,NULL,'part_d_4_x_axis_ir','part_d_4_z_axis_ir','part_d_4_point_ir'),(401,'part_b_12_pose_ir',NULL,NULL,NULL,'part_b_12_x_axis_ir','part_b_12_z_axis_ir','part_b_12_point_ir'),(408,'part_e_1_pose_ir',NULL,NULL,NULL,'part_e_1_x_axis_ir','part_e_1_z_axis_ir','part_e_1_point_ir'),(417,'kit_tray_1_pose_ir',NULL,NULL,NULL,'kit_tray_1_x_axis_ir','kit_tray_1_z_axis_ir','kit_tray_1_point_ir'),(420,'part_b_2_pose',NULL,NULL,NULL,'part_b_2_x_axis','part_b_2_z_axis','part_b_2_point'),(436,'part_d_2_pose_ir',NULL,NULL,NULL,'part_d_2_x_axis_ir','part_d_2_z_axis_ir','part_d_2_point_ir'),(438,'part_gripper_pose',NULL,NULL,NULL,'part_gripper_x_axis','part_gripper_z_axis','part_gripper_point'),(440,'empty_kit_tray_supply_pose_ir',NULL,NULL,NULL,'empty_kit_tray_supply_x_axis_ir','empty_kit_tray_supply_z_axis_ir','empty_kit_tray_supply_point_ir'),(441,'part_c_3_pose_ir',NULL,NULL,NULL,'part_c_3_x_axis_ir','part_c_3_z_axis_ir','part_c_3_point_ir'),(449,'part_b_6_pose_ir',NULL,NULL,NULL,'part_b_6_x_axis_ir','part_b_6_z_axis_ir','part_b_6_point_ir'),(456,'part_b_11_pose_ir',NULL,NULL,NULL,'part_b_11_x_axis_ir','part_b_11_z_axis_ir','part_b_11_point_ir'),(457,'part_b_7_pose',NULL,NULL,NULL,'part_b_7_x_axis','part_b_7_z_axis','part_b_7_point'),(469,'part_b_tray_pose',NULL,NULL,NULL,'part_b_tray_x_axis','part_b_tray_z_axis','part_b_tray_point'),(487,'part_c_tray_pose_ir',NULL,NULL,NULL,'part_c_tray_x_axis_ir','part_c_tray_z_axis_ir','part_c_tray_point_ir'),(495,'part_a_11_pose_ir',NULL,NULL,NULL,'part_a_11_x_axis_ir','part_a_11_z_axis_ir','part_a_11_point_ir'),(498,'part_d_9_pose_ir',NULL,NULL,NULL,'part_d_9_x_axis_ir','part_d_9_z_axis_ir','part_d_9_point_ir'),(500,'part_c_5_pose_ir',NULL,NULL,NULL,'part_c_5_x_axis_ir','part_c_5_z_axis_ir','part_c_5_point_ir'),(501,'part_b_7_pose_ir',NULL,NULL,NULL,'part_b_7_x_axis_ir','part_b_7_z_axis_ir','part_b_7_point_ir'),(502,'part_a_1_pose_ir',NULL,NULL,NULL,'part_a_1_x_axis_ir','part_a_1_z_axis_ir','part_a_1_point_ir'),(504,'part_gear_shaft_4_pose',NULL,NULL,NULL,'part_gear_shaft_4_x_axis','part_gear_shaft_4_z_axis','part_gear_shaft_4_point'),(515,'part_b_3_pose_ir',NULL,NULL,NULL,'part_b_3_x_axis_ir','part_b_3_z_axis_ir','part_b_3_point_ir'),(524,'part_b_5_pose_ir',NULL,NULL,NULL,'part_b_5_x_axis_ir','part_b_5_z_axis_ir','part_b_5_point_ir'),(532,'part_c_2_pose',NULL,NULL,NULL,'part_c_2_x_axis','part_c_2_z_axis','part_c_2_point'),(534,'part_a_9_pose_ir',NULL,NULL,NULL,'part_a_9_x_axis_ir','part_a_9_z_axis_ir','part_a_9_point_ir'),(555,'finished_kit_box_pose',NULL,NULL,NULL,'finished_kit_box_x_axis','finished_kit_box_z_axis','finished_kit_box_point'),(557,'finished_kit_box_pose_ir',NULL,NULL,NULL,'finished_kit_box_x_axis_ir','finished_kit_box_z_axis_ir','finished_kit_box_point_ir'),(558,'part_c_supply_pose',NULL,NULL,NULL,'part_c_supply_x_axis','part_c_supply_z_axis','part_c_supply_point'),(560,'part_d_5_pose_ir',NULL,NULL,NULL,'part_d_5_x_axis_ir','part_d_5_z_axis_ir','part_d_5_point_ir'),(566,'part_d_3_pose_ir',NULL,NULL,NULL,'part_d_3_x_axis_ir','part_d_3_z_axis_ir','part_d_3_point_ir'),(571,'part_a_supply_pose',NULL,NULL,NULL,'part_a_supply_x_axis','part_a_supply_z_axis','part_a_supply_point'),(576,'part_a_12_pose_ir',NULL,NULL,NULL,'part_a_12_x_axis_ir','part_a_12_z_axis_ir','part_a_12_point_ir'),(584,'part_e_6_pose_ir',NULL,NULL,NULL,'part_e_6_x_axis_ir','part_e_6_z_axis_ir','part_e_6_point_ir'),(592,'part_a_supply_pose_ir',NULL,NULL,NULL,'part_a_supply_x_axis_ir','part_a_supply_z_axis_ir','part_a_supply_point_ir'),(602,'kit_tray_2_pose',NULL,NULL,NULL,'kit_tray_2_x_axis','kit_tray_2_z_axis','kit_tray_2_point'),(608,'part_c_1_pose_ir',NULL,NULL,NULL,'part_c_1_x_axis_ir','part_c_1_z_axis_ir','part_c_1_point_ir'),(611,'robot_pose',NULL,NULL,NULL,'robot_x_axis','robot_z_axis','robot_point'),(615,'part_d_6_pose_ir',NULL,NULL,NULL,'part_d_6_x_axis_ir','part_d_6_z_axis_ir','part_d_6_point_ir'),(620,'tray_gripper_holder_pose',NULL,NULL,NULL,'tray_gripper_holder_x_axis','tray_gripper_holder_z_axis','tray_gripper_holder_point'),(630,'part_gripper_holder_pose',NULL,NULL,NULL,'part_gripper_holder_x_axis','part_gripper_holder_z_axis','part_gripper_holder_point'),(633,'trash_table_pose',NULL,NULL,NULL,'trash_table_x_axis','trash_table_z_axis','trash_table_point'),(643,'part_a_1_pose',NULL,NULL,NULL,'part_a_1_x_axis','part_a_1_z_axis','part_a_1_point'),(646,'kit_tray_2_pose_ir',NULL,NULL,NULL,'kit_tray_2_x_axis_ir','kit_tray_2_z_axis_ir','kit_tray_2_point_ir'),(647,'part_gear_4_pose',NULL,NULL,NULL,'part_gear_4_x_axis','part_gear_4_z_axis','part_gear_4_point'),(648,'part_gear_2_pose',NULL,NULL,NULL,'part_gear_2_x_axis','part_gear_2_z_axis','part_gear_2_point'),(659,'part_e_supply_pose_ir',NULL,NULL,NULL,'part_e_supply_x_axis_ir','part_e_supply_z_axis_ir','part_e_supply_point_ir'),(673,'part_b_8_pose',NULL,NULL,NULL,'part_b_8_x_axis','part_b_8_z_axis','part_b_8_point'),(682,'work_table_pose',NULL,NULL,NULL,'work_table_x_axis','work_table_z_axis','work_table_point'),(686,'part_a_18_pose_ir',NULL,NULL,NULL,'part_a_18_x_axis_ir','part_a_18_z_axis_ir','part_a_18_point_ir'),(698,'part_a_tray_pose_ir',NULL,NULL,NULL,'part_a_tray_x_axis_ir','part_a_tray_z_axis_ir','part_a_tray_point_ir'),(706,'part_c_8_pose',NULL,NULL,NULL,'part_c_8_x_axis','part_c_8_z_axis','part_c_8_point'),(715,'part_a_7_pose_ir',NULL,NULL,NULL,'part_a_7_x_axis_ir','part_a_7_z_axis_ir','part_a_7_point_ir'),(718,'part_a_6_pose_ir',NULL,NULL,NULL,'part_a_6_x_axis_ir','part_a_6_z_axis_ir','part_a_6_point_ir'),(723,'part_gear_shaft_2_pose',NULL,NULL,NULL,'part_gear_shaft_2_x_axis','part_gear_shaft_2_z_axis','part_gear_shaft_2_point'),(750,'part_d_8_pose_ir',NULL,NULL,NULL,'part_d_8_x_axis_ir','part_d_8_z_axis_ir','part_d_8_point_ir'),(753,'part_e_4_pose_ir',NULL,NULL,NULL,'part_e_4_x_axis_ir','part_e_4_z_axis_ir','part_e_4_point_ir'),(755,'part_a_8_pose_ir',NULL,NULL,NULL,'part_a_8_x_axis_ir','part_a_8_z_axis_ir','part_a_8_point_ir'),(771,'part_a_14_pose_ir',NULL,NULL,NULL,'part_a_14_x_axis_ir','part_a_14_z_axis_ir','part_a_14_point_ir'),(780,'part_b_tray_pose_ir',NULL,NULL,NULL,'part_b_tray_x_axis_ir','part_b_tray_z_axis_ir','part_b_tray_point_ir'),(782,'part_gear_shaft_1_pose',NULL,NULL,NULL,'part_gear_shaft_1_x_axis','part_gear_shaft_1_z_axis','part_gear_shaft_1_point'),(785,'kit_tray_5_pose_ir',NULL,NULL,NULL,'kit_tray_5_x_axis_ir','kit_tray_5_z_axis_ir','kit_tray_5_point_ir'),(799,'empty_kit_tray_box_pose',NULL,NULL,NULL,'empty_kit_tray_box_x_axis','empty_kit_tray_box_z_axis','empty_kit_tray_box_point'),(808,'empty_kit_tray_supply_pose',NULL,NULL,NULL,'empty_kit_tray_supply_x_axis','empty_kit_tray_supply_z_axis','empty_kit_tray_supply_point'),(815,'part_d_7_pose_ir',NULL,NULL,NULL,'part_d_7_x_axis_ir','part_d_7_z_axis_ir','part_d_7_point_ir'),(817,'part_d_supply_pose_ir',NULL,NULL,NULL,'part_d_supply_x_axis_ir','part_d_supply_z_axis_ir','part_d_supply_point_ir'),(820,'part_gear_3_pose',NULL,NULL,NULL,'part_gear_3_x_axis','part_gear_3_z_axis','part_gear_3_point'),(821,'empty_kit_tray_box_pose_ir',NULL,NULL,NULL,'empty_kit_tray_box_x_axis_ir','empty_kit_tray_box_z_axis_ir','empty_kit_tray_box_point_ir'),(826,'part_gear_1_pose',NULL,NULL,NULL,'part_gear_1_x_axis','part_gear_1_z_axis','part_gear_1_point'),(827,'part_a_2_pose_ir',NULL,NULL,NULL,'part_a_2_x_axis_ir','part_a_2_z_axis_ir','part_a_2_point_ir'),(829,'part_c_1_pose',NULL,NULL,NULL,'part_c_1_x_axis','part_c_1_z_axis','part_c_1_point');
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
INSERT INTO `PoseLocationIn` VALUES (54,'part_a_10_pose_ir'),(495,'part_a_11_pose_ir'),(576,'part_a_12_pose_ir'),(256,'part_a_13_pose_ir'),(771,'part_a_14_pose_ir'),(241,'part_a_15_pose_ir'),(225,'part_a_16_pose_ir'),(344,'part_a_17_pose_ir'),(686,'part_a_18_pose_ir'),(643,'part_a_1_pose'),(502,'part_a_1_pose_ir'),(56,'part_a_2_pose'),(827,'part_a_2_pose_ir'),(359,'part_a_3_pose'),(356,'part_a_3_pose_ir'),(144,'part_a_4_pose'),(104,'part_a_4_pose_ir'),(198,'part_a_5_pose_ir'),(718,'part_a_6_pose_ir'),(715,'part_a_7_pose_ir'),(755,'part_a_8_pose_ir'),(534,'part_a_9_pose_ir'),(242,'part_b_10_pose_ir'),(456,'part_b_11_pose_ir'),(401,'part_b_12_pose_ir'),(86,'part_b_1_pose'),(39,'part_b_1_pose_ir'),(420,'part_b_2_pose'),(91,'part_b_2_pose_ir'),(8,'part_b_3_pose'),(515,'part_b_3_pose_ir'),(12,'part_b_4_pose'),(215,'part_b_4_pose_ir'),(11,'part_b_5_pose'),(524,'part_b_5_pose_ir'),(80,'part_b_6_pose'),(449,'part_b_6_pose_ir'),(457,'part_b_7_pose'),(501,'part_b_7_pose_ir'),(673,'part_b_8_pose'),(178,'part_b_8_pose_ir'),(83,'part_b_9_pose_ir'),(829,'part_c_1_pose'),(608,'part_c_1_pose_ir'),(532,'part_c_2_pose'),(189,'part_c_2_pose_ir'),(352,'part_c_3_pose'),(441,'part_c_3_pose_ir'),(13,'part_c_4_pose'),(101,'part_c_4_pose_ir'),(95,'part_c_5_pose'),(500,'part_c_5_pose_ir'),(347,'part_c_6_pose'),(127,'part_c_6_pose_ir'),(270,'part_c_7_pose'),(130,'part_c_7_pose_ir'),(706,'part_c_8_pose'),(124,'part_c_8_pose_ir'),(62,'part_d_1_pose_ir'),(436,'part_d_2_pose_ir'),(566,'part_d_3_pose_ir'),(399,'part_d_4_pose_ir'),(560,'part_d_5_pose_ir'),(615,'part_d_6_pose_ir'),(815,'part_d_7_pose_ir'),(750,'part_d_8_pose_ir'),(498,'part_d_9_pose_ir'),(408,'part_e_1_pose_ir'),(288,'part_e_2_pose_ir'),(194,'part_e_3_pose_ir'),(753,'part_e_4_pose_ir'),(377,'part_e_5_pose_ir'),(584,'part_e_6_pose_ir'),(826,'part_gear_1_pose'),(648,'part_gear_2_pose'),(820,'part_gear_3_pose'),(647,'part_gear_4_pose'),(239,'part_gear_5_pose'),(390,'part_gear_base_pose'),(302,'part_gear_boss_pose'),(156,'part_gear_holder_pose'),(782,'part_gear_shaft_1_pose'),(723,'part_gear_shaft_2_pose'),(330,'part_gear_shaft_3_pose'),(504,'part_gear_shaft_4_pose');
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
INSERT INTO `PoseOnlyLocation` VALUES (354,'changing_station_base_pose'),(376,'changing_station_pose'),(799,'empty_kit_tray_box_pose'),(821,'empty_kit_tray_box_pose_ir'),(808,'empty_kit_tray_supply_pose'),(440,'empty_kit_tray_supply_pose_ir'),(555,'finished_kit_box_pose'),(557,'finished_kit_box_pose_ir'),(10,'finished_kit_receiver_pose'),(202,'finished_kit_receiver_pose_ir'),(340,'kit_a2b2c1_pose'),(318,'kit_tray_1_pose'),(417,'kit_tray_1_pose_ir'),(602,'kit_tray_2_pose'),(646,'kit_tray_2_pose_ir'),(96,'kit_tray_3_pose'),(175,'kit_tray_3_pose_ir'),(331,'kit_tray_4_pose_ir'),(785,'kit_tray_5_pose_ir'),(221,'part_a_grasp_pose'),(571,'part_a_supply_pose'),(592,'part_a_supply_pose_ir'),(21,'part_a_tray_pose'),(698,'part_a_tray_pose_ir'),(19,'part_b_grasp_pose'),(211,'part_b_supply_pose'),(76,'part_b_supply_pose_ir'),(469,'part_b_tray_pose'),(780,'part_b_tray_pose_ir'),(117,'part_c_grasp_pose'),(558,'part_c_supply_pose'),(140,'part_c_supply_pose_ir'),(111,'part_c_tray_pose'),(487,'part_c_tray_pose_ir'),(817,'part_d_supply_pose_ir'),(34,'part_d_tray_pose_ir'),(659,'part_e_supply_pose_ir'),(386,'part_e_tray_pose_ir'),(630,'part_gripper_holder_pose'),(438,'part_gripper_pose'),(611,'robot_pose'),(633,'trash_table_pose'),(620,'tray_gripper_holder_pose'),(682,'work_table_pose');
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
INSERT INTO `RelativeLocation` VALUES (325,'relative_location_in_1','The  KittingWorkstation is in kitting_workstation_1'),(795,'relative_location_on_1','The tray_gripper is on robot_1');
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
INSERT INTO `RelativeLocationIn` VALUES (325,'relative_location_in_1');
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
INSERT INTO `RelativeLocationOn` VALUES (795,'relative_location_on_1');
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
INSERT INTO `Robot` VALUES (123,'robot_1','this is the robot',7);
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
INSERT INTO `ShapeDesign` VALUES (27,'shape_part_b_ir','Shape of PartB_ir'),(33,'shape_part_a_ir','Shape of PartA_ir'),(43,'shape_kit_tray_2_ir','Shape of KitTray 2'),(52,'shape_part_a','Shape of PartA'),(53,'shape_part_b','Shape of PartB'),(55,'shape_part_c','Shape of PartC'),(89,'shape_parts_tray_c_ir','Shape of PartsTrays for parts of type C, used for Intention Recognition'),(125,'shape_parts_tray_e_ir','Shape of PartsTrays for parts of type E, used for Intention Recognition'),(139,'shape_part_d_ir','Shape of PartD_ir'),(169,'ext_shape_parts_tray_e_ir','Shape of PartsTray_E_ir'),(236,'ext_shape_gear_boss','Shape of the gear boss'),(251,'shape_changing_station_base','Shape of base of changing station'),(314,'ext_shape_gear_holder','Shape of the gear holder'),(320,'shape_parts_tray_a','Shape of PartsTray_A'),(321,'shape_parts_tray_b','Shape of PartsTray_B'),(322,'shape_parts_tray_c','Shape of PartsTray_C'),(375,'ext_shape_gear_shaft','Shape of the gear shaft'),(395,'ext_shape_parts_tray_a_ir','Shape of PartsTray_A_ir'),(407,'shape_kit_tray_4_ir','Shape of KitTray 3'),(448,'shape_part_e_ir','Shape of PartE_ir'),(466,'shape_kit_tray_5_ir','Shape of KitTray 5'),(474,'shape_work_table','Shape of the work table'),(477,'shape_kit_box_ir','Shape of boxes to hold kits and kit trays used for Intention Recognition'),(506,'shape_kit_tray','Shape of KitTrays'),(520,'ext_shape_parts_tray_c_ir','Shape of PartsTray_C_ir'),(528,'shape_kit_tray_1_ir','Shape of KitTray 1'),(539,'shape_parts_tray_b_ir','Shape of PartsTrays for parts of type B, used for Intention Recognition'),(599,'shape_part_c_ir','Shape of PartC_ir\n'),(640,'ext_shape_parts_tray_d_ir','Shape of PartsTray_D_ir'),(652,'shape_parts_tray_a_ir','Shape of PartsTrays for parts of type A, used for Intention Recognition'),(664,'shape_kit_box','Shape of boxes to hold kits and kit trays'),(730,'shape_parts_tray_d_ir','Shape of PartsTrays for parts of type D, used for Intention Recognition'),(759,'ext_shape_parts_tray_b_ir','Shape of PartsTray_B_ir'),(775,'ext_shape_gear','Shape of the gear'),(786,'ext_shape_gear_base','Shape of the gear base'),(824,'shape_trash_table','Shape of the trash table'),(825,'shape_kit_tray_3_ir','Shape of KitTray 3');
/*!40000 ALTER TABLE `ShapeDesign` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Slot`
--

DROP TABLE IF EXISTS `Slot`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Slot` (
  `SlotID` int(11) NOT NULL,
  `_NAME` varchar(255) NOT NULL DEFAULT '',
  `hadBySlot_Kit` varchar(255) DEFAULT NULL,
  `hasSlot_PartRefAndPose` varchar(255) DEFAULT NULL,
  `hasSlot_Part` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`SlotID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadBySlot_Kit` (`hadBySlot_Kit`),
  KEY `fkhasSlot_PartRefAndPose` (`hasSlot_PartRefAndPose`),
  KEY `fkhasSlot_Part` (`hasSlot_Part`),
  CONSTRAINT `fkhasSlot_Part` FOREIGN KEY (`hasSlot_Part`) REFERENCES `Part` (`_NAME`),
  CONSTRAINT `fkhadBySlot_Kit` FOREIGN KEY (`hadBySlot_Kit`) REFERENCES `Kit` (`_NAME`),
  CONSTRAINT `fkhasSlot_PartRefAndPose` FOREIGN KEY (`hasSlot_PartRefAndPose`) REFERENCES `PartRefAndPose` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Slot`
--

LOCK TABLES `Slot` WRITE;
/*!40000 ALTER TABLE `Slot` DISABLE KEYS */;
INSERT INTO `Slot` VALUES (578,'kit_a2b2c1_slot_4','kit_a2b2c1','part_ref_and_pose_kit_a2b2c1_b_2','part_b_1'),(579,'kit_a2b2c1_slot_5','kit_a2b2c1','part_ref_and_pose_kit_a2b2c1_c_1','part_c_5'),(582,'kit_a2b2c1_slot_2','kit_a2b2c1','part_ref_and_pose_kit_a2b2c1_a_2','part_a_1'),(583,'kit_a2b2c1_slot_3','kit_a2b2c1','part_ref_and_pose_kit_a2b2c1_b_1','part_b_2'),(585,'kit_a2b2c1_slot_1','kit_a2b2c1','part_ref_and_pose_kit_a2b2c1_a_1','part_a_3');
/*!40000 ALTER TABLE `Slot` ENABLE KEYS */;
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
  `hadByObject_KittingWorkstation` varchar(255) DEFAULT NULL,
  `hasSolidObject_PrimaryLocation` varchar(255) DEFAULT NULL,
  `hadBySolidObject_WorkTable` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`SolidObjectID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadByObject_KittingWorkstation` (`hadByObject_KittingWorkstation`),
  KEY `fkhasSolidObject_PrimaryLocation` (`hasSolidObject_PrimaryLocation`),
  KEY `fkhadBySolidObject_WorkTable` (`hadBySolidObject_WorkTable`),
  CONSTRAINT `fkhadBySolidObject_WorkTable` FOREIGN KEY (`hadBySolidObject_WorkTable`) REFERENCES `WorkTable` (`_NAME`),
  CONSTRAINT `fkhadByObject_KittingWorkstation` FOREIGN KEY (`hadByObject_KittingWorkstation`) REFERENCES `KittingWorkstation` (`_NAME`),
  CONSTRAINT `fkhasSolidObject_PrimaryLocation` FOREIGN KEY (`hasSolidObject_PrimaryLocation`) REFERENCES `PhysicalLocation` (`_NAME`)
) ENGINE=InnoDB AUTO_INCREMENT=129 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `SolidObject`
--

LOCK TABLES `SolidObject` WRITE;
/*!40000 ALTER TABLE `SolidObject` DISABLE KEYS */;
INSERT INTO `SolidObject` VALUES (1,'part_d_6_ir',NULL,'part_d_6_pose_ir',NULL),(2,'part_d_4_ir',NULL,'part_d_4_pose_ir',NULL),(3,'part_d_tray_ir',NULL,'part_d_tray_pose_ir',NULL),(4,'part_b_tray_ir',NULL,'part_b_tray_pose_ir',NULL),(5,'part_gear_holder',NULL,'part_gear_holder_pose',NULL),(6,'part_b_9_ir',NULL,'part_b_9_pose_ir',NULL),(7,'part_c_5',NULL,'part_c_5_pose',NULL),(8,'part_c_4',NULL,'part_c_4_pose',NULL),(9,'part_c_3',NULL,'part_c_3_pose',NULL),(10,'part_c_2',NULL,'part_c_2_pose',NULL),(11,'part_c_1',NULL,'part_c_1_pose',NULL),(12,'part_c_8',NULL,'part_c_8_pose',NULL),(13,'part_a_7_ir',NULL,'part_a_7_pose_ir',NULL),(14,'part_c_7',NULL,'part_c_7_pose',NULL),(15,'part_c_6',NULL,'part_c_6_pose',NULL),(16,'part_c_supply',NULL,'part_c_supply_pose',NULL),(17,'part_gear_boss',NULL,'part_gear_boss_pose',NULL),(18,'part_a_tray',NULL,'part_a_tray_pose',NULL),(19,'part_a_11_ir',NULL,'part_a_11_pose_ir',NULL),(20,'part_b_6_ir',NULL,'part_b_6_pose_ir',NULL),(21,'part_gear_4',NULL,'part_gear_4_pose',NULL),(22,'part_gear_5',NULL,'part_gear_5_pose',NULL),(23,'part_gear_2',NULL,'part_gear_2_pose',NULL),(24,'part_gear_3',NULL,'part_gear_3_pose',NULL),(25,'part_e_2_ir',NULL,'part_e_2_pose_ir',NULL),(26,'part_c_2_ir',NULL,'part_c_2_pose_ir',NULL),(27,'part_gear_base',NULL,'part_gear_base_pose',NULL),(28,'part_gear_1',NULL,'part_gear_1_pose',NULL),(29,'part_a_9_ir',NULL,'part_a_9_pose_ir',NULL),(30,'part_b_8_ir',NULL,'part_b_8_pose_ir',NULL),(31,'part_d_2_ir',NULL,'part_d_2_pose_ir',NULL),(32,'part_e_supply_ir',NULL,'part_e_supply_pose_ir',NULL),(33,'part_b_4_ir',NULL,'part_b_4_pose_ir',NULL),(34,'part_d_8_ir',NULL,'part_d_8_pose_ir',NULL),(35,'part_gear_shaft_1',NULL,'part_gear_shaft_1_pose',NULL),(36,'part_gear_shaft_2',NULL,'part_gear_shaft_2_pose',NULL),(37,'part_gear_shaft_3',NULL,'part_gear_shaft_3_pose',NULL),(38,'part_gear_shaft_4',NULL,'part_gear_shaft_4_pose',NULL),(39,'part_a_4_ir',NULL,'part_a_4_pose_ir',NULL),(40,'kit_tray_4_ir',NULL,'kit_tray_4_pose_ir',NULL),(41,'part_a_tray_ir',NULL,'part_a_tray_pose_ir',NULL),(42,'part_a_10_ir',NULL,'part_a_10_pose_ir',NULL),(43,'part_b_10_ir',NULL,'part_b_10_pose_ir',NULL),(44,'trash_table',NULL,'trash_table_pose',NULL),(45,'part_a_1_ir',NULL,'part_a_1_pose_ir',NULL),(46,'part_c_4_ir',NULL,'part_c_4_pose_ir',NULL),(47,'part_b_11_ir',NULL,'part_b_11_pose_ir',NULL),(48,'part_e_3_ir',NULL,'part_e_3_pose_ir',NULL),(49,'kit_a2b2c1',NULL,'kit_a2b2c1_pose','work_table_1'),(50,'part_d_3_ir',NULL,'part_d_3_pose_ir',NULL),(51,'part_b_tray',NULL,'part_b_tray_pose',NULL),(52,'part_a_3_ir',NULL,'part_a_3_pose_ir',NULL),(53,'part_a_18_ir',NULL,'part_a_18_pose_ir',NULL),(54,'part_a_16_ir',NULL,'part_a_16_pose_ir',NULL),(55,'part_d_7_ir',NULL,'part_d_7_pose_ir',NULL),(56,'part_c_7_ir',NULL,'part_c_7_pose_ir',NULL),(57,'part_a_15_ir',NULL,'part_a_15_pose_ir',NULL),(58,'part_a_6_ir',NULL,'part_a_6_pose_ir',NULL),(59,'part_c_tray_ir',NULL,'part_c_tray_pose_ir',NULL),(60,'part_e_4_ir',NULL,'part_e_4_pose_ir',NULL),(61,'part_c_tray',NULL,'part_c_tray_pose',NULL),(62,'part_b_7_ir',NULL,'part_b_7_pose_ir',NULL),(63,'finished_kit_receiver_ir',NULL,'finished_kit_receiver_pose_ir',NULL),(64,'empty_kit_tray_box',NULL,'empty_kit_tray_box_pose',NULL),(65,'part_a_12_ir',NULL,'part_a_12_pose_ir',NULL),(66,'part_b_supply_ir',NULL,'part_b_supply_pose_ir',NULL),(67,'part_d_1_ir',NULL,'part_d_1_pose_ir',NULL),(68,'kit_tray_5_ir',NULL,'kit_tray_5_pose_ir',NULL),(69,'empty_kit_tray_supply_ir',NULL,'empty_kit_tray_supply_pose_ir',NULL),(70,'kit_tray_1_ir',NULL,'kit_tray_1_pose_ir',NULL),(71,'part_a_8_ir',NULL,'part_a_8_pose_ir',NULL),(72,'part_gripper_holder',NULL,'part_gripper_holder_pose',NULL),(73,'part_c_supply_ir',NULL,'part_c_supply_pose_ir',NULL),(74,'part_c_6_ir',NULL,'part_c_6_pose_ir',NULL),(75,'part_c_8_ir',NULL,'part_c_8_pose_ir',NULL),(76,'part_a_17_ir',NULL,'part_a_17_pose_ir',NULL),(77,'part_b_3_ir',NULL,'part_b_3_pose_ir',NULL),(78,'tray_gripper',NULL,'relative_location_on_1',NULL),(79,'part_b_1',NULL,'part_b_1_pose',NULL),(80,'part_b_2',NULL,'part_b_2_pose',NULL),(81,'part_b_5',NULL,'part_b_5_pose',NULL),(82,'part_b_6',NULL,'part_b_6_pose',NULL),(83,'part_b_3',NULL,'part_b_3_pose',NULL),(84,'part_b_4',NULL,'part_b_4_pose',NULL),(85,'part_b_7',NULL,'part_b_7_pose',NULL),(86,'part_b_8',NULL,'part_b_8_pose',NULL),(87,'part_d_5_ir',NULL,'part_d_5_pose_ir',NULL),(88,'finished_kit_box',NULL,'finished_kit_box_pose',NULL),(89,'part_e_6_ir',NULL,'part_e_6_pose_ir',NULL),(90,'finished_kit_receiver',NULL,'finished_kit_receiver_pose',NULL),(91,'part_b_supply',NULL,'part_b_supply_pose',NULL),(92,'work_table_1',NULL,'work_table_pose',NULL),(93,'part_c_3_ir',NULL,'part_c_3_pose_ir',NULL),(94,'part_e_1_ir',NULL,'part_e_1_pose_ir',NULL),(95,'part_d_9_ir',NULL,'part_d_9_pose_ir',NULL),(96,'part_a_5_ir',NULL,'part_a_5_pose_ir',NULL),(97,'part_b_12_ir',NULL,'part_b_12_pose_ir',NULL),(98,'kitting_workstation_1',NULL,'relative_location_in_1',NULL),(99,'part_c_1_ir',NULL,'part_c_1_pose_ir',NULL),(100,'part_c_5_ir',NULL,'part_c_5_pose_ir',NULL),(101,'part_gripper',NULL,'part_gripper_pose',NULL),(102,'changing_station_base',NULL,'changing_station_base_pose',NULL),(103,'part_e_tray_ir',NULL,'part_e_tray_pose_ir',NULL),(104,'part_d_supply_ir',NULL,'part_d_supply_pose_ir',NULL),(105,'part_b_5_ir',NULL,'part_b_5_pose_ir',NULL),(106,'empty_kit_tray_box_ir',NULL,'empty_kit_tray_box_pose_ir',NULL),(107,'part_a_14_ir',NULL,'part_a_14_pose_ir',NULL),(108,'empty_kit_tray_supply',NULL,'empty_kit_tray_supply_pose',NULL),(109,'part_a_2_ir',NULL,'part_a_2_pose_ir',NULL),(110,'part_e_5_ir',NULL,'part_e_5_pose_ir',NULL),(111,'part_b_1_ir',NULL,'part_b_1_pose_ir',NULL),(112,'kit_tray_3',NULL,'kit_tray_3_pose',NULL),(113,'kit_tray_2',NULL,'kit_tray_2_pose',NULL),(114,'kit_tray_1',NULL,'kit_tray_1_pose',NULL),(115,'part_a_supply',NULL,'part_a_supply_pose',NULL),(116,'kit_tray_2_ir',NULL,'kit_tray_2_pose_ir',NULL),(117,'finished_kit_box_ir',NULL,'finished_kit_box_pose_ir',NULL),(118,'part_a_13_ir',NULL,'part_a_13_pose_ir',NULL),(119,'kit_tray_3_ir',NULL,'kit_tray_3_pose_ir',NULL),(120,'tray_gripper_holder',NULL,'tray_gripper_holder_pose',NULL),(121,'part_a_supply_ir',NULL,'part_a_supply_pose_ir',NULL),(122,'part_b_2_ir',NULL,'part_b_2_pose_ir',NULL),(123,'robot_1',NULL,'robot_pose',NULL),(124,'part_a_1',NULL,'part_a_1_pose',NULL),(125,'part_a_3',NULL,'part_a_3_pose',NULL),(126,'part_a_2',NULL,'part_a_2_pose',NULL),(127,'part_a_4',NULL,'part_a_4_pose',NULL),(128,'changing_station_1',NULL,'changing_station_pose',NULL);
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
  `hasStockKeepingUnit_Description` varchar(255) NOT NULL,
  `hasStockKeepingUnit_Weight` double NOT NULL,
  `hadBySku_KittingWorkstation` varchar(255) DEFAULT NULL,
  `hasStockKeepingUnit_Shape` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`StockKeepingUnitID`,`_NAME`),
  KEY `_NAME` (`_NAME`),
  KEY `fkhadBySku_KittingWorkstation` (`hadBySku_KittingWorkstation`),
  KEY `fkhasStockKeepingUnit_Shape` (`hasStockKeepingUnit_Shape`),
  CONSTRAINT `fkhasStockKeepingUnit_Shape` FOREIGN KEY (`hasStockKeepingUnit_Shape`) REFERENCES `ShapeDesign` (`_NAME`),
  CONSTRAINT `fkhadBySku_KittingWorkstation` FOREIGN KEY (`hadBySku_KittingWorkstation`) REFERENCES `KittingWorkstation` (`_NAME`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `StockKeepingUnit`
--

LOCK TABLES `StockKeepingUnit` WRITE;
/*!40000 ALTER TABLE `StockKeepingUnit` DISABLE KEYS */;
INSERT INTO `StockKeepingUnit` VALUES (2,'stock_keeping_unit_kit_tray_5_ir','SKU for KitTray 5',0.2,'kitting_workstation_1','shape_kit_tray_5_ir'),(46,'stock_keeping_unit_part_gear_holder','SKU for gear holder',1.2,NULL,'ext_shape_gear_holder'),(73,'stock_keeping_unit_part_d_ir','SKU for Part D_ir',0.18,NULL,'shape_part_d_ir'),(93,'stock_keeping_unit_kit_tray_1_ir','SKU for KitTray 1',0.2,'kitting_workstation_1','shape_kit_tray_1_ir'),(94,'stock_keeping_unit_part_c_ir','SKU for Part C_ir',0.18,NULL,'shape_part_c_ir'),(102,'stock_keeping_unit_parts_d_tray_ir','SKU for PartsTrays containing parts of type D, used for Intention Recognition',0.2,'kitting_workstation_1','ext_shape_parts_tray_d_ir'),(110,'stock_keeping_unit_kit_tray_3_ir','SKU for KitTray 3',0.2,'kitting_workstation_1','shape_kit_tray_3_ir'),(158,'stock_keeping_unit_part_gear','SKU for gears',1.2,NULL,'ext_shape_gear'),(204,'stock_keeping_unit_part_a','SKU for Part A',0.18,'kitting_workstation_1','shape_part_a'),(206,'stock_keeping_unit_parts_b_tray_ir','SKU for PartsTrays containing parts of type B, used for Intention Recognition',0.2,'kitting_workstation_1','ext_shape_parts_tray_b_ir'),(212,'stock_keeping_unit_kit_tray','SKU for KitTrays',0.2,'kitting_workstation_1','shape_kit_tray'),(232,'stock_keeping_unit_part_c','SKU for Part C',0.18,'kitting_workstation_1','shape_part_c'),(233,'stock_keeping_unit_part_b','SKU for Part B',0.18,'kitting_workstation_1','shape_part_b'),(252,'stock_keeping_unit_kit_box_ir','SKU for Boxes for Kits and KitTrays for Intention Recognition',1.2,'kitting_workstation_1','shape_kit_box_ir'),(258,'stock_keeping_unit_parts_a_tray_ir','SKU for PartsTrays containing parts of type A, used for Intention Recognition',0.2,'kitting_workstation_1','ext_shape_parts_tray_a_ir'),(346,'stock_keeping_unit_kit_tray_2_ir','SKU for KitTray 2',0.2,'kitting_workstation_1','shape_kit_tray_2_ir'),(348,'stock_keeping_unit_parts_c_tray_ir','SKU for PartsTrays containing parts of type C, used for Intention Recognition',0.2,'kitting_workstation_1','ext_shape_parts_tray_c_ir'),(439,'stock_keeping_unit_part_gear_base','SKU for gear base',1.2,NULL,'ext_shape_gear_base'),(445,'stock_keeping_unit_part_e_ir','SKU for Part E_ir',0.18,NULL,'shape_part_e_ir'),(491,'stock_keeping_unit_part_gear_shaft','SKU for gear shaft',1.2,NULL,'ext_shape_gear_shaft'),(629,'stock_keeping_unit_part_a_ir','SKU for Part A_ir',0.18,NULL,'shape_part_a_ir'),(641,'stock_keeping_unit_kit_tray_4_ir','SKU for KitTray 4',0.2,'kitting_workstation_1','shape_kit_tray_4_ir'),(656,'stock_keeping_unit_kit_box','SKU for Boxes for Kits and KitTrays',1.2,'kitting_workstation_1','shape_kit_box'),(670,'stock_keeping_unit_parts_tray_a','SKU for Part a PartsTray',0.2,'kitting_workstation_1','shape_parts_tray_a'),(672,'stock_keeping_unit_parts_tray_c','SKU for Part c PartsTrays',0.2,'kitting_workstation_1','shape_parts_tray_c'),(674,'stock_keeping_unit_parts_tray_b','SKU for Part b PartsTrays',0.2,'kitting_workstation_1','shape_parts_tray_b'),(726,'stock_keeping_unit_part_b_ir','SKU for Part B_ir',0.18,NULL,'shape_part_b_ir'),(748,'stock_keeping_unit_parts_e_tray_ir','SKU for PartsTrays containing parts of type E, used for Intention Recognition',0.2,'kitting_workstation_1','ext_shape_parts_tray_e_ir'),(754,'stock_keeping_unit_part_gear_boss','SKU for gear boss',1.2,NULL,'ext_shape_gear_boss');
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
INSERT INTO `VacuumEffector` VALUES (78,'tray_gripper',0.04,0.1),(101,'part_gripper',0.02,0.025);
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
  `hasVacuumEffectorMultiCup_ArrayRadius` double NOT NULL,
  `hasVacuumEffectorMultiCup_ArrayNumber` int(11) NOT NULL,
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
INSERT INTO `VacuumEffectorSingleCup` VALUES (101,'part_gripper'),(78,'tray_gripper');
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
INSERT INTO `Vector` VALUES (1,'part_e_5_x_axis_ir',0,0,1),(3,'part_c_4_z_axis',1,0,0),(9,'z_axis_kit_a4b3c3_c_1_ir',1,0,0),(14,'part_b_grasp_x_axis',0,0,1),(15,'kit_tray_2_x_axis_ir',0,0,1),(18,'kit_tray_5_x_axis_ir',0,0,1),(22,'z_axis_kit_a4b4c2_b_2_ir',1,0,0),(23,'part_a_8_z_axis_ir',1,0,0),(25,'z_axis_kit_a4b3c2d1_a_3_ir',1,0,0),(26,'part_d_9_x_axis_ir',0,0,1),(28,'part_a_4_z_axis',1,0,0),(29,'part_d_8_x_axis_ir',0,0,1),(31,'part_b_4_z_axis',1,0,0),(35,'x_axis_kit_a4b3c3_a_2_ir',0,0,1),(36,'part_b_2_x_axis',0,0,1),(38,'part_gear_5_z_axis',1,0,0),(42,'z_axis_kit_a2b1c1_c_1',1,0,0),(49,'part_b_3_x_axis_ir',0,0,1),(50,'part_e_supply_x_axis_ir',0,0,1),(51,'tray_gripper_holder_z_axis',1,0,0),(57,'part_a_14_z_axis_ir',1,0,0),(58,'z_axis_kit_a4b4c2_a_3_ir',1,0,0),(60,'part_d_9_z_axis_ir',1,0,0),(61,'part_gripper_holder_x_axis',0,0,1),(65,'x_axis_kit_a4b3c3_c_3_ir',0,0,1),(67,'part_d_supply_x_axis_ir',0,0,1),(68,'part_a_supply_x_axis',0,0,1),(69,'part_d_3_z_axis_ir',1,0,0),(70,'kit_tray_1_z_axis_ir',1,0,0),(72,'part_d_8_z_axis_ir',1,0,0),(74,'part_gear_base_z_axis',1,0,0),(75,'part_c_3_z_axis',1,0,0),(77,'part_c_4_z_axis_ir',1,0,0),(78,'x_axis_kit_a4b3c3_b_3_ir',0,1,0),(79,'kit_tray_2_z_axis',1,0,0),(82,'kit_tray_1_x_axis',0,0,1),(88,'part_gear_4_x_axis',0,0,1),(92,'part_b_tray_x_axis_ir',0,0,1),(97,'part_a_9_x_axis_ir',0,0,1),(98,'part_c_7_x_axis_ir',0,0,1),(99,'part_a_3_z_axis_ir',1,0,0),(100,'part_a_tray_z_axis',1,0,0),(103,'part_c_8_z_axis',1,0,0),(106,'part_a_3_x_axis',0,0,1),(108,'x_axis_kit_a4b4c2_b_1_ir',0,1,0),(109,'x_axis_kit_a4b3c2d1_a_3_ir',0,0,1),(112,'part_d_4_z_axis_ir',1,0,0),(115,'part_a_3_x_axis_ir',0,0,1),(118,'x_axis_kit_a2b3c3d1e1_c_1_ir',0,0,1),(119,'z_axis_kit_a2b3c5_b_3_ir',1,0,0),(120,'x_axis_kit_a2b3c3d1e1_e_1_ir',0,1,0),(121,'tray_gripper_holder_x_axis',0,0,1),(122,'part_c_7_x_axis',0,0,1),(126,'part_b_12_x_axis_ir',0,0,1),(129,'x_axis_kit_a4b3c3_a_4_ir',0,0,1),(132,'part_b_4_x_axis',0,0,1),(134,'part_b_5_x_axis',0,0,1),(136,'part_a_12_x_axis_ir',0,0,1),(138,'part_b_1_z_axis',1,0,0),(141,'x_axis_kit_a4b3c2d1_b_2_ir',0,1,0),(143,'part_b_9_x_axis_ir',0,0,1),(149,'part_a_4_x_axis',0,0,1),(150,'z_axis_kit_a4b3c2d1_a_2_ir',1,0,0),(151,'part_a_1_z_axis',1,0,0),(152,'part_e_5_z_axis_ir',1,0,0),(154,'part_c_supply_z_axis',1,0,0),(155,'part_e_3_z_axis_ir',1,0,0),(157,'part_gear_shaft_1_z_axis',1,0,0),(159,'part_d_2_x_axis_ir',0,0,1),(167,'part_a_18_z_axis_ir',1,0,0),(168,'z_axis_kit_a4b4c2_a_1_ir',1,0,0),(170,'part_c_1_z_axis',1,0,0),(172,'x_axis_kit_a2b3c3d1e1_a_1_ir',0,0,1),(173,'part_e_supply_z_axis_ir',1,0,0),(176,'part_c_tray_x_axis',0,0,1),(177,'x_axis_kit_a2b3c5_c_2_ir',0,0,1),(181,'part_a_tray_x_axis_ir',0,0,1),(182,'trash_table_x_axis',0,0,1),(183,'part_b_10_x_axis_ir',0,0,1),(185,'part_e_2_z_axis_ir',1,0,0),(188,'z_axis_kit_a2b3c5_c_2_ir',1,0,0),(191,'part_d_tray_z_axis_ir',1,0,0),(193,'part_gear_2_x_axis',0,0,1),(196,'x_axis_kit_a4b4c2_a_4_ir',0,0,1),(199,'z_axis_kit_a2b3c3d1e1_c_3_ir',1,0,0),(200,'part_a_9_z_axis_ir',1,0,0),(203,'z_axis_kit_a4b3c3_b_3_ir',1,0,0),(207,'work_table_x_axis',0,0,1),(208,'z_axis_kit_a2b3c5_b_1_ir',1,0,0),(209,'part_a_grasp_z_axis',-1,0,0),(210,'part_c_2_z_axis',1,0,0),(216,'kit_tray_3_z_axis',1,0,0),(217,'finished_kit_box_x_axis_ir',0,0,1),(220,'part_gripper_x_axis',0,0,1),(222,'part_a_17_x_axis_ir',0,0,1),(223,'part_gear_3_x_axis',0,0,1),(226,'part_e_1_z_axis_ir',1,0,0),(227,'part_b_2_z_axis',1,0,0),(229,'finished_kit_box_z_axis_ir',1,0,0),(230,'part_e_4_z_axis_ir',1,0,0),(231,'part_a_10_z_axis_ir',1,0,0),(234,'part_b_supply_x_axis',0,0,1),(235,'x_axis_kit_a2b3c5_c_5_ir',0,0,1),(244,'part_a_2_z_axis',1,0,0),(246,'part_b_3_z_axis_ir',1,0,0),(247,'z_axis_kit_a4b3c2d1_c_2_ir',1,0,0),(248,'part_c_1_x_axis',0,0,1),(250,'part_gear_4_z_axis',1,0,0),(253,'part_a_11_z_axis_ir',1,0,0),(254,'part_b_8_x_axis_ir',0,0,1),(255,'part_e_tray_z_axis_ir',1,0,0),(263,'x_axis_kit_a4b4c2_a_2_ir',0,0,1),(264,'changing_station_x_axis',0,0,1),(268,'kit_tray_2_x_axis',0,0,1),(269,'part_b_9_z_axis_ir',1,0,0),(271,'part_gripper_z_axis',1,0,0),(273,'part_d_1_x_axis_ir',0,0,1),(274,'part_b_11_z_axis_ir',1,0,0),(276,'robot_x_axis',0,0,1),(277,'part_b_7_z_axis_ir',1,0,0),(278,'x_axis_kit_a2b1c1_c_1',0,0,1),(282,'x_axis_kit_a4b3c3_a_1_ir',0,0,1),(283,'part_a_14_x_axis_ir',0,0,1),(285,'z_axis_kit_a2b3c5_c_5_ir',1,0,0),(286,'z_axis_kit_a2b3c5_c_3_ir',1,0,0),(290,'part_b_6_z_axis_ir',1,0,0),(291,'x_axis_kit_a4b3c2d1_c_2_ir',0,0,1),(292,'part_c_7_z_axis_ir',1,0,0),(293,'empty_kit_tray_box_z_axis_ir',1,0,0),(294,'z_axis_kit_a2b3c5_c_1_ir',1,0,0),(296,'x_axis_kit_a2b1c1_a_2',0,0,1),(297,'z_axis_kit_a4b3c2d1_a_1_ir',1,0,0),(298,'x_axis_kit_a2b1c1_a_1',0,0,1),(299,'part_c_tray_z_axis_ir',1,0,0),(300,'part_c_1_z_axis_ir',1,0,0),(301,'part_b_6_x_axis',0,0,1),(304,'z_axis_kit_a2b3c5_a_1_ir',1,0,0),(306,'part_gear_shaft_4_x_axis',0,0,1),(308,'part_c_5_z_axis_ir',1,0,0),(309,'part_b_8_z_axis',1,0,0),(311,'part_b_1_x_axis_ir',0,0,1),(312,'part_c_7_z_axis',1,0,0),(315,'kit_tray_4_x_axis_ir',0,0,1),(316,'part_b_11_x_axis_ir',0,0,1),(317,'part_c_tray_z_axis',1,0,0),(319,'part_c_supply_x_axis_ir',0,0,1),(324,'part_c_1_x_axis_ir',0,0,1),(327,'x_axis_kit_a4b3c2d1_a_1_ir',0,0,1),(328,'z_axis_kit_a2b3c3d1e1_b_1_ir',1,0,0),(329,'part_a_supply_z_axis',1,0,0),(333,'part_d_6_x_axis_ir',0,0,1),(334,'empty_kit_tray_supply_x_axis_ir',0,0,1),(336,'z_axis_kit_a4b3c2d1_b_1_ir',1,0,0),(339,'x_axis_kit_a2b3c5_a_2_ir',0,0,1),(341,'part_c_6_z_axis',1,0,0),(342,'z_axis_kit_a4b3c2d1_b_3_ir',1,0,0),(345,'part_a_supply_x_axis_ir',0,0,1),(351,'empty_kit_tray_box_z_axis',1,0,0),(357,'part_c_5_z_axis',1,0,0),(358,'z_axis_kit_a4b3c3_a_1_ir',1,0,0),(360,'part_b_5_z_axis_ir',1,0,0),(361,'part_c_2_x_axis_ir',0,0,1),(364,'part_gear_shaft_3_z_axis',1,0,0),(365,'finished_kit_receiver_z_axis',1,0,0),(369,'part_a_5_x_axis_ir',0,0,1),(370,'part_d_5_z_axis_ir',1,0,0),(372,'part_gear_shaft_2_z_axis',1,0,0),(378,'z_axis_kit_a2b1c1_b_1',1,0,0),(379,'part_a_6_x_axis_ir',0,0,1),(380,'part_e_4_x_axis_ir',0,0,1),(381,'x_axis_kit_a2b2c1_a_1',0,0,1),(383,'x_axis_kit_a2b2c1_a_2',0,0,1),(384,'part_b_8_z_axis_ir',1,0,0),(385,'part_c_3_x_axis',0,0,1),(387,'part_a_2_x_axis',0,0,1),(388,'part_c_8_x_axis_ir',0,0,1),(389,'x_axis_kit_a2b2c1_c_1',0,0,1),(393,'finished_kit_box_z_axis',1,0,0),(394,'part_c_supply_x_axis',0,0,1),(396,'part_b_7_x_axis_ir',0,0,1),(400,'x_axis_kit_a2b3c5_b_2_ir',0,0,1),(403,'part_c_5_x_axis_ir',0,0,1),(410,'part_b_1_z_axis_ir',1,0,0),(411,'z_axis_kit_a2b2c1_b_1',1,0,0),(412,'z_axis_kit_a2b2c1_b_2',1,0,0),(413,'x_axis_kit_a2b3c3d1e1_c_2_ir',0,0,1),(418,'kit_a2b2c1_z_axis',1,0,0),(419,'part_a_7_z_axis_ir',1,0,0),(421,'kit_tray_2_z_axis_ir',1,0,0),(422,'part_gear_shaft_1_x_axis',0,0,1),(424,'part_e_6_z_axis_ir',1,0,0),(426,'part_c_supply_z_axis_ir',1,0,0),(427,'empty_kit_tray_supply_x_axis',0,0,1),(428,'z_axis_kit_a4b3c3_c_3_ir',1,0,0),(429,'part_c_2_z_axis_ir',1,0,0),(430,'x_axis_kit_a2b3c5_c_4_ir',0,0,1),(431,'part_c_8_z_axis_ir',1,0,0),(432,'changing_station_base_x_axis',0,0,1),(433,'part_gear_5_x_axis',0,0,1),(434,'z_axis_kit_a4b4c2_b_4_ir',1,0,0),(435,'z_axis_kit_a2b3c3d1e1_e_1_ir',1,0,0),(437,'part_c_6_x_axis',0,0,1),(442,'kit_a2b2c1_x_axis',0,0,1),(446,'part_e_6_x_axis_ir',0,0,1),(450,'z_axis_kit_a2b3c5_c_4_ir',1,0,0),(452,'part_gear_1_z_axis',1,0,0),(453,'x_axis_kit_a4b4c2_b_2_ir',0,1,0),(454,'x_axis_kit_a2b3c5_a_1_ir',0,0,1),(455,'part_gear_boss_z_axis',1,0,0),(458,'x_axis_kit_a2b3c3d1e1_b_1_ir',0,1,0),(459,'part_a_tray_x_axis',0,0,1),(460,'part_c_4_x_axis',0,0,1),(461,'x_axis_kit_a4b3c3_b_1_ir',0,0,1),(463,'z_axis_kit_a4b4c2_a_4_ir',1,0,0),(464,'work_table_z_axis',1,0,0),(465,'x_axis_kit_a2b3c3d1e1_b_3_ir',0,1,0),(467,'part_b_2_x_axis_ir',0,0,1),(471,'part_gear_holder_x_axis',0,0,1),(473,'part_b_4_z_axis_ir',1,0,0),(475,'kit_tray_1_x_axis_ir',0,0,1),(478,'part_a_8_x_axis_ir',0,0,1),(480,'part_gripper_holder_z_axis',1,0,0),(483,'z_axis_kit_a4b4c2_c_1_ir',1,0,0),(484,'part_c_8_x_axis',0,0,1),(486,'part_a_5_z_axis_ir',1,0,0),(488,'z_axis_kit_a2b3c3d1e1_c_1_ir',1,0,0),(489,'empty_kit_tray_box_x_axis_ir',0,0,1),(490,'x_axis_kit_a4b3c2d1_c_1_ir',0,0,1),(493,'empty_kit_tray_supply_z_axis_ir',1,0,0),(494,'x_axis_kit_a4b4c2_c_1_ir',0,0,1),(496,'part_gear_base_x_axis',0,0,1),(505,'x_axis_kit_a4b3c2d1_a_4_ir',0,0,1),(510,'part_b_supply_z_axis',1,0,0),(511,'kit_tray_3_x_axis_ir',0,0,1),(513,'z_axis_kit_a4b4c2_a_2_ir',1,0,0),(521,'kit_tray_3_x_axis',0,0,1),(523,'part_a_18_x_axis_ir',0,0,1),(526,'part_a_6_z_axis_ir',1,0,0),(527,'z_axis_kit_a4b3c2d1_d_1_ir',1,0,0),(530,'part_a_grasp_x_axis',0,0,1),(533,'x_axis_kit_a4b3c2d1_a_2_ir',0,0,1),(543,'part_b_6_z_axis',1,0,0),(545,'x_axis_kit_a4b3c2d1_b_3_ir',0,1,0),(547,'kit_tray_4_z_axis_ir',1,0,0),(549,'part_a_10_x_axis_ir',0,0,1),(551,'changing_station_base_z_axis',1,0,0),(553,'x_axis_kit_a4b3c3_b_2_ir',0,0,1),(554,'part_b_3_x_axis',0,0,1),(556,'x_axis_kit_a2b3c3d1e1_c_3_ir',0,0,1),(563,'part_gear_holder_z_axis',1,0,0),(564,'x_axis_kit_a4b3c2d1_b_1_ir',0,1,0),(565,'part_b_1_x_axis',0,1,0),(567,'part_d_supply_z_axis_ir',1,0,0),(570,'z_axis_kit_a2b3c3d1e1_b_2_ir',1,0,0),(573,'part_a_1_x_axis',0,0,1),(575,'part_b_tray_x_axis',0,0,1),(577,'x_axis_kit_a2b3c3d1e1_a_2_ir',0,0,1),(580,'z_axis_kit_a4b3c3_a_3_ir',1,0,0),(581,'empty_kit_tray_box_x_axis',0,0,1),(587,'part_a_7_x_axis_ir',0,0,1),(589,'part_c_grasp_x_axis',0,0,1),(591,'part_d_tray_x_axis_ir',0,0,1),(593,'part_d_6_z_axis_ir',1,0,0),(594,'kit_tray_1_z_axis',1,0,0),(595,'part_d_1_z_axis_ir',1,0,0),(598,'part_a_2_z_axis_ir',1,0,0),(603,'part_c_6_x_axis_ir',0,0,1),(605,'part_c_grasp_z_axis',-1,0,0),(606,'part_a_13_x_axis_ir',0,0,1),(609,'part_e_1_x_axis_ir',0,0,1),(612,'part_c_tray_x_axis_ir',0,0,1),(613,'z_axis_kit_a4b3c3_b_2_ir',1,0,0),(614,'part_a_11_x_axis_ir',0,0,1),(617,'part_b_10_z_axis_ir',1,0,0),(619,'x_axis_kit_a4b4c2_b_4_ir',0,1,0),(622,'part_gear_1_x_axis',0,0,1),(623,'part_a_15_x_axis_ir',0,0,1),(624,'x_axis_kit_a4b4c2_a_1_ir',0,0,1),(625,'part_a_15_z_axis_ir',1,0,0),(626,'z_axis_kit_a2b3c3d1e1_d_1_ir',1,0,0),(632,'z_axis_kit_a2b3c3d1e1_a_1_ir',1,0,0),(635,'kit_tray_5_z_axis_ir',1,0,0),(636,'z_axis_kit_a4b3c2d1_a_4_ir',1,0,0),(637,'part_e_3_x_axis_ir',0,0,1),(639,'part_b_grasp_z_axis',-1,0,0),(644,'part_b_tray_z_axis_ir',1,0,0),(650,'part_a_supply_z_axis_ir',1,0,0),(651,'part_a_1_x_axis_ir',0,0,1),(654,'part_b_supply_x_axis_ir',0,0,1),(655,'finished_kit_box_x_axis',0,0,1),(657,'part_gear_shaft_3_x_axis',0,0,1),(658,'part_b_4_x_axis_ir',0,0,1),(662,'x_axis_kit_a2b3c3d1e1_d_1_ir',0,1,0),(663,'part_a_4_z_axis_ir',1,0,0),(665,'part_d_5_x_axis_ir',0,0,1),(666,'part_gear_shaft_2_x_axis',0,0,1),(667,'part_a_12_z_axis_ir',1,0,0),(675,'part_b_7_x_axis',0,0,1),(678,'changing_station_z_axis',1,0,0),(680,'part_c_6_z_axis_ir',1,0,0),(683,'part_gear_2_z_axis',1,0,0),(684,'part_a_17_z_axis_ir',1,0,0),(685,'part_a_13_z_axis_ir',1,0,0),(687,'z_axis_kit_a4b3c2d1_c_1_ir',1,0,0),(689,'part_d_2_z_axis_ir',1,0,0),(690,'part_gear_3_z_axis',1,0,0),(691,'z_axis_kit_a2b3c5_a_2_ir',1,0,0),(692,'z_axis_kit_a2b2c1_a_2',1,0,0),(693,'z_axis_kit_a4b3c3_a_2_ir',1,0,0),(694,'x_axis_kit_a2b3c5_b_1_ir',0,1,0),(695,'z_axis_kit_a2b3c3d1e1_b_3_ir',1,0,0),(696,'trash_table_z_axis',1,0,0),(697,'part_b_3_z_axis',1,0,0),(701,'part_a_2_x_axis_ir',0,0,1),(702,'x_axis_kit_a2b3c5_c_3_ir',0,0,1),(703,'x_axis_kit_a2b3c5_b_3_ir',0,0,1),(704,'part_d_3_x_axis_ir',0,0,1),(707,'part_c_4_x_axis_ir',0,0,1),(711,'x_axis_kit_a2b1c1_b_1',0,0,1),(713,'z_axis_kit_a4b3c3_a_4_ir',1,0,0),(714,'z_axis_kit_a2b2c1_a_1',1,0,0),(716,'z_axis_kit_a4b4c2_c_2_ir',1,0,0),(720,'part_gear_boss_x_axis',0,0,1),(724,'part_gear_shaft_4_z_axis',1,0,0),(725,'z_axis_kit_a4b4c2_b_3_ir',1,0,0),(727,'part_b_5_z_axis',1,0,0),(729,'part_c_2_x_axis',0,0,1),(732,'z_axis_kit_a4b3c3_b_1_ir',1,0,0),(733,'part_b_7_z_axis',1,0,0),(734,'part_a_16_x_axis_ir',0,0,1),(735,'x_axis_kit_a4b4c2_a_3_ir',0,0,1),(738,'z_axis_kit_a2b1c1_a_2',1,0,0),(739,'z_axis_kit_a2b1c1_a_1',1,0,0),(741,'z_axis_kit_a2b3c3d1e1_c_2_ir',1,0,0),(742,'part_d_4_x_axis_ir',0,0,1),(743,'finished_kit_receiver_x_axis',0,0,1),(745,'kit_tray_3_z_axis_ir',1,0,0),(746,'finished_kit_receiver_x_axis_ir',0,0,1),(751,'z_axis_kit_a2b3c3d1e1_a_2_ir',1,0,0),(752,'z_axis_kit_a4b3c3_c_2_ir',1,0,0),(756,'part_a_tray_z_axis_ir',1,0,0),(761,'x_axis_kit_a4b3c3_a_3_ir',0,0,1),(762,'part_b_8_x_axis',0,0,1),(764,'z_axis_kit_a4b3c2d1_b_2_ir',1,0,0),(765,'x_axis_kit_a2b3c3d1e1_b_2_ir',0,1,0),(766,'x_axis_kit_a4b3c2d1_d_1_ir',0,1,0),(768,'part_c_3_z_axis_ir',1,0,0),(769,'z_axis_kit_a2b3c5_b_2_ir',1,0,0),(772,'part_b_supply_z_axis_ir',1,0,0),(773,'part_a_16_z_axis_ir',1,0,0),(779,'part_b_12_z_axis_ir',1,0,0),(781,'empty_kit_tray_supply_z_axis',1,0,0),(783,'part_a_3_z_axis',1,0,0),(784,'part_c_3_x_axis_ir',0,0,1),(787,'part_b_2_z_axis_ir',1,0,0),(788,'part_b_5_x_axis_ir',0,0,1),(791,'part_a_4_x_axis_ir',0,0,1),(792,'z_axis_kit_a4b4c2_b_1_ir',1,0,0),(793,'part_a_1_z_axis_ir',1,0,0),(796,'finished_kit_receiver_z_axis_ir',1,0,0),(800,'x_axis_kit_a4b4c2_b_3_ir',0,1,0),(804,'part_b_6_x_axis_ir',0,0,1),(805,'x_axis_kit_a2b2c1_b_2',0,1,0),(806,'x_axis_kit_a2b2c1_b_1',0,0,1),(810,'x_axis_kit_a4b3c3_c_1_ir',0,0,1),(811,'part_c_5_x_axis',0,0,1),(812,'robot_z_axis',1,0,0),(813,'x_axis_kit_a2b3c5_c_1_ir',0,0,1),(814,'part_b_tray_z_axis',1,0,0),(819,'part_d_7_z_axis_ir',1,0,0),(823,'part_e_tray_x_axis_ir',0,0,1),(830,'z_axis_kit_a2b2c1_c_1',1,0,0),(832,'x_axis_kit_a4b3c3_c_2_ir',0,0,1),(833,'x_axis_kit_a4b4c2_c_2_ir',0,0,1),(834,'part_e_2_x_axis_ir',0,0,1),(835,'part_d_7_x_axis_ir',0,0,1);
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
INSERT INTO `WorkTable` VALUES (44,'trash_table'),(92,'work_table_1');
/*!40000 ALTER TABLE `WorkTable` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `hasStockKeepingUnit_EndEffector`
--

DROP TABLE IF EXISTS `hasStockKeepingUnit_EndEffector`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hasStockKeepingUnit_EndEffector` (
  `StockKeepingUnitID` int(11) NOT NULL,
  `EndEffectorID` int(11) NOT NULL,
  PRIMARY KEY (`StockKeepingUnitID`,`EndEffectorID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hasStockKeepingUnit_EndEffector`
--

LOCK TABLES `hasStockKeepingUnit_EndEffector` WRITE;
/*!40000 ALTER TABLE `hasStockKeepingUnit_EndEffector` DISABLE KEYS */;
INSERT INTO `hasStockKeepingUnit_EndEffector` VALUES (2,1),(46,1),(73,1),(93,1),(94,1),(102,1),(110,1),(158,1),(204,1),(206,1),(212,1),(232,1),(233,1),(258,1),(346,1),(348,1),(439,1),(445,1),(491,78),(629,101),(641,101),(670,101),(672,101),(674,101),(726,101),(748,101),(754,101);
/*!40000 ALTER TABLE `hasStockKeepingUnit_EndEffector` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2013-08-07 16:19:22
