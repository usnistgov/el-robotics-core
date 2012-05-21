#include "DAO.h"
#include "Robot.h"

int main() {
	Robot * r = new Robot("Robot1");
	r->get("Robot1");
	std::cout << r->gethadByRobot_Workstation()->getKittingWorkstationID()
			<< std::endl;
	std::cout
				<< r->gethasRobot_WorkVolume().back()->gethasBoxVolume_MaximumPoint()->getname()
				<< std::endl;
	std::cout
				<< r->gethasSolidObject_PhysicalLocation()->getname()
				<< std::endl;

	return 0;
}

DAO::DAO(std::string name) {
	this->className.push_back(name);
	connection = new Connection("127.0.0.1", "root", "mypassword", "owl");
	this->fillGetSqlQueries();
}
std::map<std::string, std::string> DAO::getSqlQueriesDataSingle;
std::map<std::string, std::vector<std::string> > DAO::getSqlQueriesDataMulti;
std::map<std::string, std::vector<std::string> > DAO::getSqlQueriesObjectSingle;
std::map<std::string, std::vector<std::string> > DAO::getSqlQueriesObjectMulti;

void DAO::fillGetSqlQueries() {
	std::vector<std::string> temp;
	DAO::getSqlQueriesDataSingle["Robot"]
			= "SELECT Robot.RobotID AS 'Robot.RobotID', Robot._NAME AS 'Robot._NAME', Robot.hasRobot_Id AS 'Robot.hasRobot_Id', Robot.hasRobot_MaximumLoadWeight AS 'Robot.hasRobot_MaximumLoadWeight', Robot.hasRobot_Description AS 'Robot.hasRobot_Description' FROM Robot, SolidObject WHERE  Robot.RobotID = ? AND SolidObject.SolidObjectID = Robot.RobotID";
	DAO::getSqlQueriesDataSingle["PhysicalLocation"]
			= "SELECT PhysicalLocation.PhysicalLocationID AS 'PhysicalLocation.PhysicalLocationID', PhysicalLocation._NAME AS 'PhysicalLocation._NAME' FROM PhysicalLocation, DataThing WHERE  PhysicalLocation.PhysicalLocationID = ? AND DataThing.DataThingID = PhysicalLocation.PhysicalLocationID";
	DAO::getSqlQueriesDataSingle["LargeBoxWithKits"]
			= "SELECT LargeBoxWithKits.LargeBoxWithKitsID AS 'LargeBoxWithKits.LargeBoxWithKitsID', LargeBoxWithKits._NAME AS 'LargeBoxWithKits._NAME', LargeBoxWithKits.hasLargeBoxWithKits_Capacity AS 'LargeBoxWithKits.hasLargeBoxWithKits_Capacity', LargeBoxWithKits.hasLargeBoxWithKits_KitDesignRef AS 'LargeBoxWithKits.hasLargeBoxWithKits_KitDesignRef' FROM LargeBoxWithKits, SolidObject WHERE  LargeBoxWithKits.LargeBoxWithKitsID = ? AND SolidObject.SolidObjectID = LargeBoxWithKits.LargeBoxWithKitsID";
	DAO::getSqlQueriesDataSingle["RelativeLocation"]
			= "SELECT RelativeLocation.RelativeLocationID AS 'RelativeLocation.RelativeLocationID', RelativeLocation._NAME AS 'RelativeLocation._NAME' FROM RelativeLocation, PhysicalLocation, DataThing WHERE  RelativeLocation.RelativeLocationID = ? AND PhysicalLocation.PhysicalLocationID = RelativeLocation.RelativeLocationID AND DataThing.DataThingID = RelativeLocation.RelativeLocationID";
	DAO::getSqlQueriesDataSingle["SolidObject"]
			= "SELECT SolidObject.SolidObjectID AS 'SolidObject.SolidObjectID', SolidObject._NAME AS 'SolidObject._NAME' FROM SolidObject WHERE  SolidObject.SolidObjectID = ?";
	DAO::getSqlQueriesDataSingle["RelativeLocationIn"]
			= "SELECT RelativeLocationIn.RelativeLocationInID AS 'RelativeLocationIn.RelativeLocationInID', RelativeLocationIn._NAME AS 'RelativeLocationIn._NAME', RelativeLocationIn.hasRelativeLocationIn_Description AS 'RelativeLocationIn.hasRelativeLocationIn_Description' FROM RelativeLocationIn, RelativeLocation, PhysicalLocation, DataThing WHERE  RelativeLocationIn.RelativeLocationInID = ? AND RelativeLocation.RelativeLocationID = RelativeLocationIn.RelativeLocationInID AND PhysicalLocation.PhysicalLocationID = RelativeLocationIn.RelativeLocationInID AND DataThing.DataThingID = RelativeLocationIn.RelativeLocationInID";
	DAO::getSqlQueriesDataSingle["ShapeDesign"]
			= "SELECT ShapeDesign.ShapeDesignID AS 'ShapeDesign.ShapeDesignID', ShapeDesign._NAME AS 'ShapeDesign._NAME', ShapeDesign.hasShapeDesign_Description AS 'ShapeDesign.hasShapeDesign_Description' FROM ShapeDesign, DataThing WHERE  ShapeDesign.ShapeDesignID = ? AND DataThing.DataThingID = ShapeDesign.ShapeDesignID";
	DAO::getSqlQueriesDataSingle["PartRefAndPose"]
			= "SELECT PartRefAndPose.PartRefAndPoseID AS 'PartRefAndPose.PartRefAndPoseID', PartRefAndPose._NAME AS 'PartRefAndPose._NAME', PartRefAndPose.hasPartRefAndPose_Ref AS 'PartRefAndPose.hasPartRefAndPose_Ref' FROM PartRefAndPose, DataThing WHERE  PartRefAndPose.PartRefAndPoseID = ? AND DataThing.DataThingID = PartRefAndPose.PartRefAndPoseID";
	DAO::getSqlQueriesDataSingle["Part"]
			= "SELECT Part.PartID AS 'Part.PartID', Part._NAME AS 'Part._NAME', Part.hasPart_SerialNumber AS 'Part.hasPart_SerialNumber', Part.hasPart_SkuRef AS 'Part.hasPart_SkuRef' FROM Part, SolidObject WHERE  Part.PartID = ? AND SolidObject.SolidObjectID = Part.PartID";
	DAO::getSqlQueriesDataSingle["Point"]
			= "SELECT Point.PointID AS 'Point.PointID', Point._NAME AS 'Point._NAME', Point.hasPoint_X AS 'Point.hasPoint_X', Point.hasPoint_Y AS 'Point.hasPoint_Y', Point.hasPoint_Z AS 'Point.hasPoint_Z' FROM Point, DataThing WHERE  Point.PointID = ? AND DataThing.DataThingID = Point.PointID";
	DAO::getSqlQueriesDataSingle["KitInstance"]
			= "SELECT KitInstance.KitInstanceID AS 'KitInstance.KitInstanceID', KitInstance._NAME AS 'KitInstance._NAME', KitInstance.isKitInstance_Finished AS 'KitInstance.isKitInstance_Finished', KitInstance.hasKitInstance_DesignRef AS 'KitInstance.hasKitInstance_DesignRef' FROM KitInstance, SolidObject WHERE  KitInstance.KitInstanceID = ? AND SolidObject.SolidObjectID = KitInstance.KitInstanceID";
	DAO::getSqlQueriesDataSingle["BoxVolume"]
			= "SELECT BoxVolume.BoxVolumeID AS 'BoxVolume.BoxVolumeID', BoxVolume._NAME AS 'BoxVolume._NAME' FROM BoxVolume, DataThing WHERE  BoxVolume.BoxVolumeID = ? AND DataThing.DataThingID = BoxVolume.BoxVolumeID";
	DAO::getSqlQueriesDataSingle["EndEffectorHolder"]
			= "SELECT EndEffectorHolder.EndEffectorHolderID AS 'EndEffectorHolder.EndEffectorHolderID', EndEffectorHolder._NAME AS 'EndEffectorHolder._NAME' FROM EndEffectorHolder, SolidObject WHERE  EndEffectorHolder.EndEffectorHolderID = ? AND SolidObject.SolidObjectID = EndEffectorHolder.EndEffectorHolderID";
	DAO::getSqlQueriesDataSingle["RollPitchYaw"]
			= "SELECT RollPitchYaw.RollPitchYawID AS 'RollPitchYaw.RollPitchYawID', RollPitchYaw._NAME AS 'RollPitchYaw._NAME', RollPitchYaw.hasRpy_Roll AS 'RollPitchYaw.hasRpy_Roll', RollPitchYaw.hasRpy_Pitch AS 'RollPitchYaw.hasRpy_Pitch', RollPitchYaw.hasRpy_Yaw AS 'RollPitchYaw.hasRpy_Yaw' FROM RollPitchYaw, DataThing WHERE  RollPitchYaw.RollPitchYawID = ? AND DataThing.DataThingID = RollPitchYaw.RollPitchYawID";
	DAO::getSqlQueriesDataSingle["Pose"]
			= "SELECT Pose.PoseID AS 'Pose.PoseID', Pose._NAME AS 'Pose._NAME' FROM Pose, PhysicalLocation, DataThing WHERE  Pose.PoseID = ? AND PhysicalLocation.PhysicalLocationID = Pose.PoseID AND DataThing.DataThingID = Pose.PoseID";
	DAO::getSqlQueriesDataSingle["VacuumEffectorSingleCup"]
			= "SELECT VacuumEffectorSingleCup.VacuumEffectorSingleCupID AS 'VacuumEffectorSingleCup.VacuumEffectorSingleCupID', VacuumEffectorSingleCup._NAME AS 'VacuumEffectorSingleCup._NAME', VacuumEffector.hasVacuumEffector_CupDiameter AS 'VacuumEffector.hasVacuumEffector_CupDiameter', VacuumEffector.hasVacuumEffector_Length AS 'VacuumEffector.hasVacuumEffector_Length', EndEffector.hasEndEffector_Weight AS 'EndEffector.hasEndEffector_Weight', EndEffector.hasEffector_MaximumLoadWeight AS 'EndEffector.hasEffector_MaximumLoadWeight', EndEffector.hasEndEffector_Description AS 'EndEffector.hasEndEffector_Description', EndEffector.hasEndEffector_Id AS 'EndEffector.hasEndEffector_Id' FROM VacuumEffectorSingleCup, VacuumEffector, EndEffector, SolidObject WHERE  VacuumEffectorSingleCup.VacuumEffectorSingleCupID = ? AND VacuumEffector.VacuumEffectorID = VacuumEffectorSingleCup.VacuumEffectorSingleCupID AND EndEffector.EndEffectorID = VacuumEffectorSingleCup.VacuumEffectorSingleCupID AND SolidObject.SolidObjectID = VacuumEffectorSingleCup.VacuumEffectorSingleCupID";
	DAO::getSqlQueriesDataSingle["VacuumEffectorMultiCup"]
			= "SELECT VacuumEffectorMultiCup.VacuumEffectorMultiCupID AS 'VacuumEffectorMultiCup.VacuumEffectorMultiCupID', VacuumEffectorMultiCup._NAME AS 'VacuumEffectorMultiCup._NAME', VacuumEffectorMultiCup.hasMultiCup_ArrayNumber AS 'VacuumEffectorMultiCup.hasMultiCup_ArrayNumber', VacuumEffectorMultiCup.hasMultiCup_ArrayRadius AS 'VacuumEffectorMultiCup.hasMultiCup_ArrayRadius', VacuumEffector.hasVacuumEffector_CupDiameter AS 'VacuumEffector.hasVacuumEffector_CupDiameter', VacuumEffector.hasVacuumEffector_Length AS 'VacuumEffector.hasVacuumEffector_Length', EndEffector.hasEndEffector_Weight AS 'EndEffector.hasEndEffector_Weight', EndEffector.hasEffector_MaximumLoadWeight AS 'EndEffector.hasEffector_MaximumLoadWeight', EndEffector.hasEndEffector_Description AS 'EndEffector.hasEndEffector_Description', EndEffector.hasEndEffector_Id AS 'EndEffector.hasEndEffector_Id' FROM VacuumEffectorMultiCup, VacuumEffector, EndEffector, SolidObject WHERE  VacuumEffectorMultiCup.VacuumEffectorMultiCupID = ? AND VacuumEffector.VacuumEffectorID = VacuumEffectorMultiCup.VacuumEffectorMultiCupID AND EndEffector.EndEffectorID = VacuumEffectorMultiCup.VacuumEffectorMultiCupID AND SolidObject.SolidObjectID = VacuumEffectorMultiCup.VacuumEffectorMultiCupID";
	DAO::getSqlQueriesDataSingle["PartsBin"]
			= "SELECT PartsBin.PartsBinID AS 'PartsBin.PartsBinID', PartsBin._NAME AS 'PartsBin._NAME', PartsBin.hasBin_PartQuantity AS 'PartsBin.hasBin_PartQuantity', PartsBin.hasBin_PartSkuRef AS 'PartsBin.hasBin_PartSkuRef', BoxyObject.hasBox_Width AS 'BoxyObject.hasBox_Width', BoxyObject.hasBox_Height AS 'BoxyObject.hasBox_Height', BoxyObject.hasBox_Length AS 'BoxyObject.hasBox_Length' FROM PartsBin, BoxyObject, SolidObject WHERE  PartsBin.PartsBinID = ? AND BoxyObject.BoxyObjectID = PartsBin.PartsBinID AND SolidObject.SolidObjectID = PartsBin.PartsBinID";
	DAO::getSqlQueriesDataSingle["StockKeepingUnit"]
			= "SELECT StockKeepingUnit.StockKeepingUnitID AS 'StockKeepingUnit.StockKeepingUnitID', StockKeepingUnit._NAME AS 'StockKeepingUnit._NAME', StockKeepingUnit.hasSku_Description AS 'StockKeepingUnit.hasSku_Description', StockKeepingUnit.hasSku_Id AS 'StockKeepingUnit.hasSku_Id', StockKeepingUnit.hasSku_Weight AS 'StockKeepingUnit.hasSku_Weight' FROM StockKeepingUnit, DataThing WHERE  StockKeepingUnit.StockKeepingUnitID = ? AND DataThing.DataThingID = StockKeepingUnit.StockKeepingUnitID";
	DAO::getSqlQueriesDataSingle["GripperEffector"]
			= "SELECT GripperEffector.GripperEffectorID AS 'GripperEffector.GripperEffectorID', GripperEffector._NAME AS 'GripperEffector._NAME', EndEffector.hasEndEffector_Weight AS 'EndEffector.hasEndEffector_Weight', EndEffector.hasEffector_MaximumLoadWeight AS 'EndEffector.hasEffector_MaximumLoadWeight', EndEffector.hasEndEffector_Description AS 'EndEffector.hasEndEffector_Description', EndEffector.hasEndEffector_Id AS 'EndEffector.hasEndEffector_Id' FROM GripperEffector, EndEffector, SolidObject WHERE  GripperEffector.GripperEffectorID = ? AND EndEffector.EndEffectorID = GripperEffector.GripperEffectorID AND SolidObject.SolidObjectID = GripperEffector.GripperEffectorID";
	DAO::getSqlQueriesDataSingle["EndEffector"]
			= "SELECT EndEffector.EndEffectorID AS 'EndEffector.EndEffectorID', EndEffector._NAME AS 'EndEffector._NAME', EndEffector.hasEndEffector_Weight AS 'EndEffector.hasEndEffector_Weight', EndEffector.hasEffector_MaximumLoadWeight AS 'EndEffector.hasEffector_MaximumLoadWeight', EndEffector.hasEndEffector_Description AS 'EndEffector.hasEndEffector_Description', EndEffector.hasEndEffector_Id AS 'EndEffector.hasEndEffector_Id' FROM EndEffector, SolidObject WHERE  EndEffector.EndEffectorID = ? AND SolidObject.SolidObjectID = EndEffector.EndEffectorID";
	DAO::getSqlQueriesDataSingle["WorkTable"]
			= "SELECT WorkTable.WorkTableID AS 'WorkTable.WorkTableID', WorkTable._NAME AS 'WorkTable._NAME', BoxyObject.hasBox_Width AS 'BoxyObject.hasBox_Width', BoxyObject.hasBox_Height AS 'BoxyObject.hasBox_Height', BoxyObject.hasBox_Length AS 'BoxyObject.hasBox_Length' FROM WorkTable, BoxyObject, SolidObject WHERE  WorkTable.WorkTableID = ? AND BoxyObject.BoxyObjectID = WorkTable.WorkTableID AND SolidObject.SolidObjectID = WorkTable.WorkTableID";
	DAO::getSqlQueriesDataSingle["LargeBoxWithEmptyKitTrays"]
			= "SELECT LargeBoxWithEmptyKitTrays.LargeBoxWithEmptyKitTraysID AS 'LargeBoxWithEmptyKitTrays.LargeBoxWithEmptyKitTraysID', LargeBoxWithEmptyKitTrays._NAME AS 'LargeBoxWithEmptyKitTrays._NAME' FROM LargeBoxWithEmptyKitTrays, SolidObject WHERE  LargeBoxWithEmptyKitTrays.LargeBoxWithEmptyKitTraysID = ? AND SolidObject.SolidObjectID = LargeBoxWithEmptyKitTrays.LargeBoxWithEmptyKitTraysID";
	DAO::getSqlQueriesDataSingle["EndEffectorChangingStation"]
			= "SELECT EndEffectorChangingStation.EndEffectorChangingStationID AS 'EndEffectorChangingStation.EndEffectorChangingStationID', EndEffectorChangingStation._NAME AS 'EndEffectorChangingStation._NAME' FROM EndEffectorChangingStation, SolidObject WHERE  EndEffectorChangingStation.EndEffectorChangingStationID = ? AND SolidObject.SolidObjectID = EndEffectorChangingStation.EndEffectorChangingStationID";
	DAO::getSqlQueriesDataSingle["PartsTray"]
			= "SELECT PartsTray.PartsTrayID AS 'PartsTray.PartsTrayID', PartsTray._NAME AS 'PartsTray._NAME', PartsTray.hasPartsTray_SkuRef AS 'PartsTray.hasPartsTray_SkuRef', PartsTray.hasPartsTray_SerialNumber AS 'PartsTray.hasPartsTray_SerialNumber', BoxyObject.hasBox_Width AS 'BoxyObject.hasBox_Width', BoxyObject.hasBox_Height AS 'BoxyObject.hasBox_Height', BoxyObject.hasBox_Length AS 'BoxyObject.hasBox_Length' FROM PartsTray, BoxyObject, SolidObject WHERE  PartsTray.PartsTrayID = ? AND BoxyObject.BoxyObjectID = PartsTray.PartsTrayID AND SolidObject.SolidObjectID = PartsTray.PartsTrayID";
	DAO::getSqlQueriesDataSingle["DataThing"]
			= "SELECT DataThing.DataThingID AS 'DataThing.DataThingID', DataThing._NAME AS 'DataThing._NAME' FROM DataThing WHERE  DataThing.DataThingID = ?";
	DAO::getSqlQueriesDataSingle["KittingWorkstation"]
			= "SELECT KittingWorkstation.KittingWorkstationID AS 'KittingWorkstation.KittingWorkstationID', KittingWorkstation._NAME AS 'KittingWorkstation._NAME', KittingWorkstation.hasWorkstation_LengthUnit AS 'KittingWorkstation.hasWorkstation_LengthUnit', KittingWorkstation.hasWorkstation_WeightUnit AS 'KittingWorkstation.hasWorkstation_WeightUnit', KittingWorkstation.hasWorkstation_AngleUnit AS 'KittingWorkstation.hasWorkstation_AngleUnit' FROM KittingWorkstation, SolidObject WHERE  KittingWorkstation.KittingWorkstationID = ? AND SolidObject.SolidObjectID = KittingWorkstation.KittingWorkstationID";
	DAO::getSqlQueriesDataSingle["KitTray"]
			= "SELECT KitTray.KitTrayID AS 'KitTray.KitTrayID', KitTray._NAME AS 'KitTray._NAME', KitTray.hasKitTray_SerialNumber AS 'KitTray.hasKitTray_SerialNumber', KitTray.hasKitTray_SkuRef AS 'KitTray.hasKitTray_SkuRef', BoxyObject.hasBox_Width AS 'BoxyObject.hasBox_Width', BoxyObject.hasBox_Height AS 'BoxyObject.hasBox_Height', BoxyObject.hasBox_Length AS 'BoxyObject.hasBox_Length' FROM KitTray, BoxyObject, SolidObject WHERE  KitTray.KitTrayID = ? AND BoxyObject.BoxyObjectID = KitTray.KitTrayID AND SolidObject.SolidObjectID = KitTray.KitTrayID";
	DAO::getSqlQueriesDataSingle["RelativeLocationOn"]
			= "SELECT RelativeLocationOn.RelativeLocationOnID AS 'RelativeLocationOn.RelativeLocationOnID', RelativeLocationOn._NAME AS 'RelativeLocationOn._NAME', RelativeLocationOn.hasRelativeLocationOn_Description AS 'RelativeLocationOn.hasRelativeLocationOn_Description' FROM RelativeLocationOn, RelativeLocation, PhysicalLocation, DataThing WHERE  RelativeLocationOn.RelativeLocationOnID = ? AND RelativeLocation.RelativeLocationID = RelativeLocationOn.RelativeLocationOnID AND PhysicalLocation.PhysicalLocationID = RelativeLocationOn.RelativeLocationOnID AND DataThing.DataThingID = RelativeLocationOn.RelativeLocationOnID";
	DAO::getSqlQueriesDataSingle["PartsTrayWithParts"]
			= "SELECT PartsTrayWithParts.PartsTrayWithPartsID AS 'PartsTrayWithParts.PartsTrayWithPartsID', PartsTrayWithParts._NAME AS 'PartsTrayWithParts._NAME' FROM PartsTrayWithParts, SolidObject WHERE  PartsTrayWithParts.PartsTrayWithPartsID = ? AND SolidObject.SolidObjectID = PartsTrayWithParts.PartsTrayWithPartsID";
	DAO::getSqlQueriesDataSingle["KitDesign"]
			= "SELECT KitDesign.KitDesignID AS 'KitDesign.KitDesignID', KitDesign._NAME AS 'KitDesign._NAME', KitDesign.hasKitDesign_Id AS 'KitDesign.hasKitDesign_Id', KitDesign.hasKitDesign_KitTraySkuRef AS 'KitDesign.hasKitDesign_KitTraySkuRef' FROM KitDesign, DataThing WHERE  KitDesign.KitDesignID = ? AND DataThing.DataThingID = KitDesign.KitDesignID";
	DAO::getSqlQueriesDataSingle["BoxyObject"]
			= "SELECT BoxyObject.BoxyObjectID AS 'BoxyObject.BoxyObjectID', BoxyObject._NAME AS 'BoxyObject._NAME', BoxyObject.hasBox_Width AS 'BoxyObject.hasBox_Width', BoxyObject.hasBox_Height AS 'BoxyObject.hasBox_Height', BoxyObject.hasBox_Length AS 'BoxyObject.hasBox_Length' FROM BoxyObject, SolidObject WHERE  BoxyObject.BoxyObjectID = ? AND SolidObject.SolidObjectID = BoxyObject.BoxyObjectID";
	DAO::getSqlQueriesDataSingle["VacuumEffector"]
			= "SELECT VacuumEffector.VacuumEffectorID AS 'VacuumEffector.VacuumEffectorID', VacuumEffector._NAME AS 'VacuumEffector._NAME', VacuumEffector.hasVacuumEffector_CupDiameter AS 'VacuumEffector.hasVacuumEffector_CupDiameter', VacuumEffector.hasVacuumEffector_Length AS 'VacuumEffector.hasVacuumEffector_Length', EndEffector.hasEndEffector_Weight AS 'EndEffector.hasEndEffector_Weight', EndEffector.hasEffector_MaximumLoadWeight AS 'EndEffector.hasEffector_MaximumLoadWeight', EndEffector.hasEndEffector_Description AS 'EndEffector.hasEndEffector_Description', EndEffector.hasEndEffector_Id AS 'EndEffector.hasEndEffector_Id' FROM VacuumEffector, EndEffector, SolidObject WHERE  VacuumEffector.VacuumEffectorID = ? AND EndEffector.EndEffectorID = VacuumEffector.VacuumEffectorID AND SolidObject.SolidObjectID = VacuumEffector.VacuumEffectorID";
	DAO::getSqlQueriesDataSingle["Vector"]
			= "SELECT Vector.VectorID AS 'Vector.VectorID', Vector._NAME AS 'Vector._NAME', Vector.hasVector_K AS 'Vector.hasVector_K', Vector.hasVector_J AS 'Vector.hasVector_J', Vector.hasVector_I AS 'Vector.hasVector_I' FROM Vector, DataThing WHERE  Vector.VectorID = ? AND DataThing.DataThingID = Vector.VectorID";
	DAO::getSqlQueriesDataSingle["LargeContainer"]
			= "SELECT LargeContainer.LargeContainerID AS 'LargeContainer.LargeContainerID', LargeContainer._NAME AS 'LargeContainer._NAME', LargeContainer.hasLargeContainer_SkuRef AS 'LargeContainer.hasLargeContainer_SkuRef', LargeContainer.hasLargeContainer_SerialNumber AS 'LargeContainer.hasLargeContainer_SerialNumber', BoxyObject.hasBox_Width AS 'BoxyObject.hasBox_Width', BoxyObject.hasBox_Height AS 'BoxyObject.hasBox_Height', BoxyObject.hasBox_Length AS 'BoxyObject.hasBox_Length' FROM LargeContainer, BoxyObject, SolidObject WHERE  LargeContainer.LargeContainerID = ? AND BoxyObject.BoxyObjectID = LargeContainer.LargeContainerID AND SolidObject.SolidObjectID = LargeContainer.LargeContainerID";
	temp.clear();
	temp.push_back(
			"SELECT hasSku_EndEffectorRefs FROM hasSku_EndEffectorRefsValue WHERE StockKeepingUnitID = ?");
	DAO::getSqlQueriesDataMulti["StockKeepingUnit"] = temp;
	temp.clear();
	temp.push_back("-PartRefAndPose/hasPartRefAndPose_Rpy");
	temp.push_back("-Pose/hasPose_Rpy");
	DAO::getSqlQueriesObjectSingle["RollPitchYaw"] = temp;
	temp.clear();
	temp.push_back("KittingWorkstation/hadByRobot_Workstation");
	DAO::getSqlQueriesObjectSingle["Robot"] = temp;
	temp.clear();
	temp.push_back("Point/hasPose_Point");
	temp.push_back("RollPitchYaw/hasPose_Rpy");
	DAO::getSqlQueriesObjectSingle["Pose"] = temp;
	temp.clear();
	temp.push_back("-SolidObject/hasSolidObject_PhysicalLocation");
	temp.push_back("SolidObject/hasPhysicalLocation_RefObject");
	DAO::getSqlQueriesObjectSingle["PhysicalLocation"] = temp;
	temp.clear();
	temp.push_back("-LargeContainer/hadByLargeContainer_LargeBoxWithKits");
	DAO::getSqlQueriesObjectSingle["LargeBoxWithKits"] = temp;
	temp.clear();
	temp.push_back("ShapeDesign/hasSku_Shape");
	DAO::getSqlQueriesObjectSingle["StockKeepingUnit"] = temp;
	temp.clear();
	temp.push_back("PhysicalLocation/hasSolidObject_PhysicalLocation");
	temp.push_back("-PhysicalLocation/hasPhysicalLocation_RefObject");
	DAO::getSqlQueriesObjectSingle["SolidObject"] = temp;
	temp.clear();
	temp.push_back("-StockKeepingUnit/hasSku_Shape");
	DAO::getSqlQueriesObjectSingle["ShapeDesign"] = temp;
	temp.clear();
	temp.push_back("KittingWorkstation/hadByWorkTable_Workstation");
	DAO::getSqlQueriesObjectSingle["WorkTable"] = temp;
	temp.clear();
	temp.push_back("KittingWorkstation/hadByChangingStation_Workstation");
	DAO::getSqlQueriesObjectSingle["EndEffectorChangingStation"] = temp;
	temp.clear();
	temp.push_back(
			"-LargeContainer/hadByLargeContainer_LargeBoxWithEmptyKitTrays");
	DAO::getSqlQueriesObjectSingle["LargeBoxWithEmptyKitTrays"] = temp;
	temp.clear();
	temp.push_back("RollPitchYaw/hasPartRefAndPose_Rpy");
	temp.push_back("Point/hasPartRefAndPose_Point");
	DAO::getSqlQueriesObjectSingle["PartRefAndPose"] = temp;
	temp.clear();
	temp.push_back("PartsTrayWithParts/hadByPartsTray_PartsTrayWithParts");
	DAO::getSqlQueriesObjectSingle["PartsTray"] = temp;
	temp.clear();
	temp.push_back("-Robot/hadByRobot_Workstation");
	temp.push_back("-WorkTable/hadByWorkTable_Workstation");
	temp.push_back(
			"-EndEffectorChangingStation/hadByChangingStation_Workstation");
	DAO::getSqlQueriesObjectSingle["KittingWorkstation"] = temp;
	temp.clear();
	temp.push_back("KitInstance/hadByKitTray_KitInstance");
	DAO::getSqlQueriesObjectSingle["KitTray"] = temp;
	temp.clear();
	temp.push_back("-PartsTray/hadByPartsTray_PartsTrayWithParts");
	DAO::getSqlQueriesObjectSingle["PartsTrayWithParts"] = temp;
	temp.clear();
	temp.push_back("-PartRefAndPose/hasPartRefAndPose_Point");
	temp.push_back("-BoxVolume/hasBoxVolume_MaximumPoint");
	temp.push_back("-BoxVolume/hasBoxVolume_MinimumPoint");
	temp.push_back("-Pose/hasPose_Point");
	DAO::getSqlQueriesObjectSingle["Point"] = temp;
	temp.clear();
	temp.push_back("Point/hasBoxVolume_MaximumPoint");
	temp.push_back("Point/hasBoxVolume_MinimumPoint");
	DAO::getSqlQueriesObjectSingle["BoxVolume"] = temp;
	temp.clear();
	temp.push_back("-KitTray/hadByKitTray_KitInstance");
	DAO::getSqlQueriesObjectSingle["KitInstance"] = temp;
	temp.clear();
	temp.push_back("LargeBoxWithKits/hadByLargeContainer_LargeBoxWithKits");
	temp.push_back(
			"LargeBoxWithEmptyKitTrays/hadByLargeContainer_LargeBoxWithEmptyKitTrays");
	DAO::getSqlQueriesObjectSingle["LargeContainer"] = temp;
	temp.clear();
	temp.push_back("BoxVolume/hasRobot_WorkVolume");
	DAO::getSqlQueriesObjectMulti["Robot"] = temp;
	temp.clear();
	temp.push_back("BoxVolume/hasWorkstation_OtherObstacles");
	DAO::getSqlQueriesObjectMulti["KittingWorkstation"] = temp;
	temp.clear();
	temp.push_back("Robot/hasRobot_WorkVolume");
	temp.push_back("KittingWorkstation/hasWorkstation_OtherObstacles");
	DAO::getSqlQueriesObjectMulti["BoxVolume"] = temp;
}

std::vector<std::string> DAO::getclassName() {
	return this->className;
}
Connection* DAO::getconnection() {
	return this->connection;
}
void DAO::setclassName(std::vector<std::string> _className) {
	this->className = _className;
}
void DAO::setconnection(Connection* _connection) {
	this->connection = _connection;
}
std::map<std::string, std::string> DAO::get(std::string name) {
	nameDone.push_back(className.back() + "+" + name);
	try {
		sql::PreparedStatement *prep_stmt;
		sql::ResultSet *res;// get the ID with the name
		prep_stmt = connection->getCon()->prepareStatement("SELECT "
				+ className.back() + "ID FROM " + className.back()
				+ " WHERE _Name = ?");
		prep_stmt->setString(1, name);
		res = prep_stmt->executeQuery();
		res->next();
		int id = res->getInt(1);
		delete (res);
		delete (prep_stmt);
		// get the data Single
		sql::ResultSetMetaData *res_meta;
		prep_stmt = connection->getCon()->prepareStatement(
				DAO::getSqlQueriesDataSingle[className.back()]);
		prep_stmt->setInt(1, id);
		res = prep_stmt->executeQuery();
		res->next();
		res_meta = res -> getMetaData();
		for (int i = 0; i < (int) res_meta -> getColumnCount(); ++i) {
			map[res_meta -> getColumnLabel(i + 1)] = res->getString(i + 1);
		}
		delete (res);
		delete (prep_stmt);
		// get the data multi
		std::string temp = "";
		for (int unsigned i = 0; i
				< DAO::getSqlQueriesDataMulti[className.back()].size(); i++) {
			prep_stmt = connection->getCon()->prepareStatement(
					DAO::getSqlQueriesDataMulti[className.back()][i]);
			prep_stmt->setInt(1, id);
			res = prep_stmt->executeQuery();
			while (res->next()) {
				if (!res->last())
					temp = temp + res->getString(1) + " ";
				else
					temp = temp + res->getString(1);
			}
			res_meta = res -> getMetaData();
			map[res_meta -> getColumnLabel(1)] = temp;
			delete (res);
			delete (prep_stmt);
		}
		// get the Object Single
		temp = "";
		sql::ResultSet *restemp;
		sql::Statement *stmt;
		std::string newName = "";
		std::string newTable = "";
		for (int unsigned i = 0; i
				< DAO::getSqlQueriesObjectSingle[className.back()].size(); i++) {
			stmt = connection->getCon()->createStatement();
			if (getSqlQueriesObjectSingle[className.back()][i].substr(0, 1)
					!= "-") {
				restemp
						= stmt->executeQuery(
								"SELECT "
										+ getSqlQueriesObjectSingle[className.back()][i].substr(
												0,
												getSqlQueriesObjectSingle[className.back()][i].find(
														"/")) + "ID FROM "
										+ getSqlQueriesObjectSingle[className.back()][i].substr(
												0,
												getSqlQueriesObjectSingle[className.back()][i].find(
														"/")) + ", "
										+ className.back() + " WHERE "
										+ className.back() + "._Name = '"
										+ name + "' AND "
										+ getSqlQueriesObjectSingle[className.back()][i].substr(
												getSqlQueriesObjectSingle[className.back()][i].find(
														"/") + 1) + " = "
										+ getSqlQueriesObjectSingle[className.back()][i].substr(
												0,
												getSqlQueriesObjectSingle[className.back()][i].find(
														"/")) + "._Name");
				prep_stmt
						= connection->getCon()->prepareStatement(
								DAO::getSqlQueriesDataSingle[getSqlQueriesObjectSingle[className.back()][i].substr(
										0,
										getSqlQueriesObjectSingle[className.back()][i].find(
												"/"))]);
			} else {

				restemp
						= stmt->executeQuery(
								"SELECT "
										+ getSqlQueriesObjectSingle[className.back()][i].substr(
												1,
												getSqlQueriesObjectSingle[className.back()][i].find(
														"/") - 1) + "ID FROM "
										+ getSqlQueriesObjectSingle[className.back()][i].substr(
												1,
												getSqlQueriesObjectSingle[className.back()][i].find(
														"/") - 1) + ", "
										+ className.back() + " WHERE "
										+ className.back() + "._Name = '"
										+ name + "' AND "
										+ getSqlQueriesObjectSingle[className.back()][i].substr(
												getSqlQueriesObjectSingle[className.back()][i].find(
														"/") + 1) + " = "
										+ className.back() + "._Name");
				prep_stmt
						= connection->getCon()->prepareStatement(
								DAO::getSqlQueriesDataSingle[getSqlQueriesObjectSingle[className.back()][i].substr(
										1,
										getSqlQueriesObjectSingle[className.back()][i].find(
												"/") - 1)]);
			}
			restemp->next();

			prep_stmt->setInt(1, restemp->getInt(1));
			res = prep_stmt->executeQuery();
			res->next();
			res_meta = res -> getMetaData();
			for (int j = 0; j < (int) res_meta -> getColumnCount(); ++j) {
				map[path
						+ getSqlQueriesObjectSingle[className.back()][i].substr(
								getSqlQueriesObjectSingle[className.back()][i].find(
										"/") + 1) + "/"
						+ res_meta -> getColumnLabel(j + 1)] = res->getString(j
						+ 1);
			}
			if (getSqlQueriesObjectSingle[className.back()][i].substr(0, 1)
					!= "-")
				newName
						= res->getString(
								getSqlQueriesObjectSingle[className.back()][i].substr(
										0,
										getSqlQueriesObjectSingle[className.back()][i].find(
												"/")) + "._NAME");
			else
				newName
						= res->getString(
								getSqlQueriesObjectSingle[className.back()][i].substr(
										1,
										getSqlQueriesObjectSingle[className.back()][i].find(
												"/") - 1) + "._NAME");
			path
					= path
							+ getSqlQueriesObjectSingle[className.back()][i].substr(
									getSqlQueriesObjectSingle[className.back()][i].find(
											"/") + 1) + "/";

			if (getSqlQueriesObjectSingle[className.back()][i].substr(0, 1)
					!= "-")
				newTable
						= getSqlQueriesObjectSingle[className.back()][i].substr(
								0,
								getSqlQueriesObjectSingle[className.back()][i].find(
										"/"));
			else
				newTable
						= getSqlQueriesObjectSingle[className.back()][i].substr(
								1,
								getSqlQueriesObjectSingle[className.back()][i].find(
										"/") - 1);

			delete (res);
			delete (restemp);
			delete (prep_stmt);
			delete (stmt);
			if (getSqlQueriesObjectSingle.find(newName)
					== getSqlQueriesObjectSingle.end()) {
				if (std::find(nameDone.begin(), nameDone.end(), newTable + "+"
						+ newName) == nameDone.end()) {
					className.push_back(newTable);
					DAO::get(newName);
				} else {
					path
							= path.substr(
									0,
									path.length()
											- (getSqlQueriesObjectSingle[className.back()][i].substr(
													getSqlQueriesObjectSingle[className.back()][i].find(
															"/") + 1) + "/").length());

				}
			}
		}

		//get the Object multi
		sql::ResultSet *restempmulti;
		sql::Statement *stmtmulti;
		for (int unsigned m = 0; m
				< DAO::getSqlQueriesObjectMulti[className.back()].size(); m++) {
			//convert id to string
			std::string sid;
			std::stringstream out;
			out << id;
			sid = out.str();
			//end convert id
			stmtmulti = connection->getCon()->createStatement();
			restempmulti = stmtmulti->executeQuery("SELECT "
					+ getSqlQueriesObjectMulti[className.back()][m].substr(0,
							getSqlQueriesObjectMulti[className.back()][m].find(
									"/")) + "ID FROM "
					+ getSqlQueriesObjectMulti[className.back()][m].substr(
							getSqlQueriesObjectMulti[className.back()][m].find(
									"/") + 1) + " WHERE " + className.back()
					+ "ID = " + sid);
			while (restempmulti->next()) {
				std::string
						table =
								getSqlQueriesObjectMulti[className.back()][m].substr(
										0,
										getSqlQueriesObjectMulti[className.back()][m].find(
												"/"));
				if (m > 0)
					pathmulti
							= pathmulti.substr(
									0,
									pathmulti.length()
											- (getSqlQueriesObjectMulti[className.back()][m
													- 1].substr(
													getSqlQueriesObjectMulti[className.back()][m
															- 1].find("/") + 1)
													+ "/").length())
									+ getSqlQueriesObjectMulti[className.back()][m].substr(
											getSqlQueriesObjectMulti[className.back()][m].find(
													"/") + 1) + "/";
				else
					pathmulti
							= pathmulti
									+ getSqlQueriesObjectMulti[className.back()][m].substr(
											getSqlQueriesObjectMulti[className.back()][m].find(
													"/") + 1) + "/";
				//Add the data
				prep_stmt
						= connection->getCon()->prepareStatement(
								DAO::getSqlQueriesDataSingle[getSqlQueriesObjectMulti[className.back()][m].substr(
										0,
										getSqlQueriesObjectMulti[className.back()][m].find(
												"/"))]);

				prep_stmt->setInt(1, restempmulti->getInt(1));
				res = prep_stmt->executeQuery();
				res->next();
				res_meta = res -> getMetaData();
				for (int i = 0; i < (int) res_meta -> getColumnCount(); ++i) {
					map[pathmulti + res_meta -> getColumnLabel(i + 1)]
							= res->getString(i + 1);
				}
				delete (prep_stmt);
				delete (res);
				//End Add the Data
				//Add the Data multi
				std::string temp = "";
				for (int unsigned i = 0; i
						< DAO::getSqlQueriesDataMulti[getSqlQueriesObjectMulti[className.back()][m].substr(
								0,
								getSqlQueriesObjectMulti[className.back()][m].find(
										"/"))].size(); i++) {
					prep_stmt
							= connection->getCon()->prepareStatement(
									DAO::getSqlQueriesDataMulti[getSqlQueriesObjectMulti[className.back()][m].substr(
											0,
											getSqlQueriesObjectMulti[className.back()][m].find(
													"/"))][i]);
					prep_stmt->setInt(1, restempmulti->getInt(1));
					res = prep_stmt->executeQuery();
					while (res->next()) {
						if (!res->last())
							temp = temp + res->getString(1) + " ";
						else
							temp = temp + res->getString(1);
					}
					res_meta = res -> getMetaData();
					map[pathmulti + res_meta -> getColumnLabel(1)] = temp;
					delete (res);
					delete (prep_stmt);
				}
				//End Add Data Multi

				for (int unsigned i = 0; i
						< DAO::getSqlQueriesObjectSingle[table].size(); i++) {
					stmt = connection->getCon()->createStatement();
					if (getSqlQueriesObjectSingle[table][i].substr(0, 1) != "-") {
						restemp
								= stmt->executeQuery(
										"SELECT "
												+ getSqlQueriesObjectSingle[table][i].substr(
														0,
														getSqlQueriesObjectSingle[table][i].find(
																"/"))
												+ "ID FROM "
												+ getSqlQueriesObjectSingle[table][i].substr(
														0,
														getSqlQueriesObjectSingle[table][i].find(
																"/")) + ", "
												+ table + " WHERE " + table
												+ "ID = "
												+ restempmulti->getString(1)
												+ " AND "
												+ getSqlQueriesObjectSingle[table][i].substr(
														getSqlQueriesObjectSingle[table][i].find(
																"/") + 1)
												+ " = "
												+ getSqlQueriesObjectSingle[table][i].substr(
														0,
														getSqlQueriesObjectSingle[table][i].find(
																"/"))
												+ "._Name");
						prep_stmt
								= connection->getCon()->prepareStatement(
										DAO::getSqlQueriesDataSingle[getSqlQueriesObjectSingle[table][i].substr(
												0,
												getSqlQueriesObjectSingle[table][i].find(
														"/"))]);
					} else {
						restemp
								= stmt->executeQuery(
										"SELECT "
												+ getSqlQueriesObjectSingle[table][i].substr(
														1,
														getSqlQueriesObjectSingle[table][i].find(
																"/") - 1)
												+ "ID FROM "
												+ getSqlQueriesObjectSingle[table][i].substr(
														1,
														getSqlQueriesObjectSingle[table][i].find(
																"/") - 1)
												+ ", " + table + " WHERE "
												+ table + "ID = "
												+ restempmulti->getString(1)
												+ " AND "
												+ getSqlQueriesObjectSingle[table][i].substr(
														getSqlQueriesObjectSingle[table][i].find(
																"/") + 1)
												+ " = "
												+ getSqlQueriesObjectSingle[table][i].substr(
														1,
														getSqlQueriesObjectSingle[table][i].find(
																"/") - 1)
												+ "._Name");
						prep_stmt
								= connection->getCon()->prepareStatement(
										DAO::getSqlQueriesDataSingle[getSqlQueriesObjectSingle[table][i].substr(
												1,
												getSqlQueriesObjectSingle[table][i].find(
														"/") - 1)]);
					}
					restemp->next();

					prep_stmt->setInt(1, restemp->getInt(1));
					res = prep_stmt->executeQuery();
					res->next();
					res_meta = res -> getMetaData();
					for (int j = 0; j < (int) res_meta -> getColumnCount(); ++j) {
						if (res->last())
							map[pathmulti
									+ getSqlQueriesObjectSingle[table][i].substr(
											getSqlQueriesObjectSingle[table][i].find(
													"/") + 1) + "/"
									+ res_meta -> getColumnLabel(j + 1)]
									= res->getString(j + 1);
						else
							map[pathmulti
									+ getSqlQueriesObjectSingle[table][i].substr(
											getSqlQueriesObjectSingle[table][i].find(
													"/") + 1) + "/"
									+ res_meta -> getColumnLabel(j + 1)]
									= map[pathmulti
											+ getSqlQueriesObjectSingle[table][i].substr(
													getSqlQueriesObjectSingle[table][i].find(
															"/") + 1) + "/"
											+ res_meta -> getColumnLabel(j + 1)]
											+ " " + res->getString(j + 1);

					}
					if (getSqlQueriesObjectSingle[table][i].substr(0, 1) != "-") {
						newName
								= res->getString(
										getSqlQueriesObjectSingle[table][i].substr(
												0,
												getSqlQueriesObjectSingle[table][i].find(
														"/")) + "._NAME");

						newTable = getSqlQueriesObjectSingle[table][i].substr(
								0,
								getSqlQueriesObjectSingle[table][i].find("/"));
					} else {
						newName
								= res->getString(
										getSqlQueriesObjectSingle[table][i].substr(
												1,
												getSqlQueriesObjectSingle[table][i].find(
														"/") - 1) + "._NAME");

						newTable = getSqlQueriesObjectSingle[table][i].substr(
								1,
								getSqlQueriesObjectSingle[table][i].find("/")
										- 1);
					}
					delete (res);
					delete (restemp);
					delete (prep_stmt);
					delete (stmt);
					if (getSqlQueriesObjectSingle.find(newName)
							== getSqlQueriesObjectSingle.end()) {
						if (std::find(nameDone.begin(), nameDone.end(),
								newTable + "+" + newName) == nameDone.end()) {
							className.push_back(newTable);
							DAO::get(newName);
						} else {
							//pathmulti = "";
							pathmulti
									= pathmulti.substr(
											0,
											pathmulti.length()
													- (getSqlQueriesObjectMulti[className.back()][m].substr(
															getSqlQueriesObjectMulti[className.back()][m].find(
																	"/") + 1)
															+ "/").length());
						}
					}
				}
			}
		}
	} catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__
				<< std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
	className.pop_back();
	return map;
}

void DAO::set(std::string name) {
}
;
