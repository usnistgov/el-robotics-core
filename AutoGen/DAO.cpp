/*****************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards
   and Technology (NIST), an agency of the U.S. government, and by 
statute is
   not subject to copyright in the United States.  Recipients of this 
software
   assume all responsibility associated with its operation, modification,
   maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 *****************************************************************************/

#include "DAO.h"

DAO::DAO(std::string name){
this->className.push_back(name);
if(getenv("MysqlDefaultHost") && getenv("MysqlDefaultUser")&& getenv("MysqlDefaultPassword")&& getenv("MysqlDefaultSchema")){
connection = Connection::getInstance(getenv("MysqlDefaultHost"), getenv("MysqlDefaultUser"), getenv("MysqlDefaultPassword"), getenv("MysqlDefaultSchema"));
this->fillGetSqlQueries();}
else
std::cout<<"Check the readme file to know which environment variables to assign"<<std::endl;
}
std::map<std::string, std::string> DAO::getSqlQueriesDataSingle;std::map<std::string,std::vector<std::string> > DAO::getSqlQueriesDataMulti;std::map<std::string,std::vector<std::string> > DAO::getSqlQueriesObjectSingle;std::map<std::string,std::vector<std::string> > DAO::getSqlQueriesObjectMulti;

void DAO::fillGetSqlQueries(){std::vector<std::string> temp;DAO::getSqlQueriesDataSingle["Robot"] = "SELECT Robot.RobotID AS 'Robot.RobotID', Robot._NAME AS 'Robot._NAME', Robot.hasRobot_Description AS 'Robot.hasRobot_Description', Robot.hasRobot_MaximumLoadWeight AS 'Robot.hasRobot_MaximumLoadWeight' FROM Robot, SolidObject WHERE  Robot.RobotID = ? AND SolidObject.SolidObjectID = Robot.RobotID";
DAO::getSqlQueriesDataSingle["MechanicalComponent"] = "SELECT MechanicalComponent.MechanicalComponentID AS 'MechanicalComponent.MechanicalComponentID', MechanicalComponent._NAME AS 'MechanicalComponent._NAME' FROM MechanicalComponent, SolidObject WHERE  MechanicalComponent.MechanicalComponentID = ? AND SolidObject.SolidObjectID = MechanicalComponent.MechanicalComponentID";
DAO::getSqlQueriesDataSingle["Kit"] = "SELECT Kit.KitID AS 'Kit.KitID', Kit._NAME AS 'Kit._NAME', Kit.hasKit_Finished AS 'Kit.hasKit_Finished' FROM Kit, SolidObject WHERE  Kit.KitID = ? AND SolidObject.SolidObjectID = Kit.KitID";
DAO::getSqlQueriesDataSingle["Human"] = "SELECT Human.HumanID AS 'Human.HumanID', Human._NAME AS 'Human._NAME' FROM Human, SolidObject WHERE  Human.HumanID = ? AND SolidObject.SolidObjectID = Human.HumanID";
DAO::getSqlQueriesDataSingle["PhysicalLocation"] = "SELECT PhysicalLocation.PhysicalLocationID AS 'PhysicalLocation.PhysicalLocationID', PhysicalLocation._NAME AS 'PhysicalLocation._NAME', PhysicalLocation.hasPhysicalLocation_Timestamp AS 'PhysicalLocation.hasPhysicalLocation_Timestamp' FROM PhysicalLocation, DataThing WHERE  PhysicalLocation.PhysicalLocationID = ? AND DataThing.DataThingID = PhysicalLocation.PhysicalLocationID";
DAO::getSqlQueriesDataSingle["LargeBoxWithKits"] = "SELECT LargeBoxWithKits.LargeBoxWithKitsID AS 'LargeBoxWithKits.LargeBoxWithKitsID', LargeBoxWithKits._NAME AS 'LargeBoxWithKits._NAME', LargeBoxWithKits.hasLargeBoxWithKits_Capacity AS 'LargeBoxWithKits.hasLargeBoxWithKits_Capacity' FROM LargeBoxWithKits, SolidObject WHERE  LargeBoxWithKits.LargeBoxWithKitsID = ? AND SolidObject.SolidObjectID = LargeBoxWithKits.LargeBoxWithKitsID";
DAO::getSqlQueriesDataSingle["RelativeLocation"] = "SELECT RelativeLocation.RelativeLocationID AS 'RelativeLocation.RelativeLocationID', RelativeLocation._NAME AS 'RelativeLocation._NAME', RelativeLocation.hasRelativeLocation_Description AS 'RelativeLocation.hasRelativeLocation_Description', PhysicalLocation.hasPhysicalLocation_Timestamp AS 'PhysicalLocation.hasPhysicalLocation_Timestamp' FROM RelativeLocation, PhysicalLocation, DataThing WHERE  RelativeLocation.RelativeLocationID = ? AND PhysicalLocation.PhysicalLocationID = RelativeLocation.RelativeLocationID AND DataThing.DataThingID = RelativeLocation.RelativeLocationID";
DAO::getSqlQueriesDataSingle["SolidObject"] = "SELECT SolidObject.SolidObjectID AS 'SolidObject.SolidObjectID', SolidObject._NAME AS 'SolidObject._NAME' FROM SolidObject WHERE  SolidObject.SolidObjectID = ?";
DAO::getSqlQueriesDataSingle["RelativeLocationIn"] = "SELECT RelativeLocationIn.RelativeLocationInID AS 'RelativeLocationIn.RelativeLocationInID', RelativeLocationIn._NAME AS 'RelativeLocationIn._NAME', RelativeLocation.hasRelativeLocation_Description AS 'RelativeLocation.hasRelativeLocation_Description', PhysicalLocation.hasPhysicalLocation_Timestamp AS 'PhysicalLocation.hasPhysicalLocation_Timestamp' FROM RelativeLocationIn, RelativeLocation, PhysicalLocation, DataThing WHERE  RelativeLocationIn.RelativeLocationInID = ? AND RelativeLocation.RelativeLocationID = RelativeLocationIn.RelativeLocationInID AND PhysicalLocation.PhysicalLocationID = RelativeLocationIn.RelativeLocationInID AND DataThing.DataThingID = RelativeLocationIn.RelativeLocationInID";
DAO::getSqlQueriesDataSingle["ExternalShape"] = "SELECT ExternalShape.ExternalShapeID AS 'ExternalShape.ExternalShapeID', ExternalShape._NAME AS 'ExternalShape._NAME', ExternalShape.hasExternalShape_ModelTypeName AS 'ExternalShape.hasExternalShape_ModelTypeName', ExternalShape.hasExternalShape_ModelName AS 'ExternalShape.hasExternalShape_ModelName', ExternalShape.hasExternalShape_ModelFileName AS 'ExternalShape.hasExternalShape_ModelFileName', ShapeDesign.hasShapeDesign_Description AS 'ShapeDesign.hasShapeDesign_Description' FROM ExternalShape, ShapeDesign, DataThing WHERE  ExternalShape.ExternalShapeID = ? AND ShapeDesign.ShapeDesignID = ExternalShape.ExternalShapeID AND DataThing.DataThingID = ExternalShape.ExternalShapeID";
DAO::getSqlQueriesDataSingle["InternalShape"] = "SELECT InternalShape.InternalShapeID AS 'InternalShape.InternalShapeID', InternalShape._NAME AS 'InternalShape._NAME', ShapeDesign.hasShapeDesign_Description AS 'ShapeDesign.hasShapeDesign_Description' FROM InternalShape, ShapeDesign, DataThing WHERE  InternalShape.InternalShapeID = ? AND ShapeDesign.ShapeDesignID = InternalShape.InternalShapeID AND DataThing.DataThingID = InternalShape.InternalShapeID";
DAO::getSqlQueriesDataSingle["ShapeDesign"] = "SELECT ShapeDesign.ShapeDesignID AS 'ShapeDesign.ShapeDesignID', ShapeDesign._NAME AS 'ShapeDesign._NAME', ShapeDesign.hasShapeDesign_Description AS 'ShapeDesign.hasShapeDesign_Description' FROM ShapeDesign, DataThing WHERE  ShapeDesign.ShapeDesignID = ? AND DataThing.DataThingID = ShapeDesign.ShapeDesignID";
DAO::getSqlQueriesDataSingle["PoseLocation"] = "SELECT PoseLocation.PoseLocationID AS 'PoseLocation.PoseLocationID', PoseLocation._NAME AS 'PoseLocation._NAME', PoseLocation.hasPoseLocation_OrientationStandardDeviation AS 'PoseLocation.hasPoseLocation_OrientationStandardDeviation', PoseLocation.hasPoseLocation_PositionStandardDeviation AS 'PoseLocation.hasPoseLocation_PositionStandardDeviation', PhysicalLocation.hasPhysicalLocation_Timestamp AS 'PhysicalLocation.hasPhysicalLocation_Timestamp' FROM PoseLocation, PhysicalLocation, DataThing WHERE  PoseLocation.PoseLocationID = ? AND PhysicalLocation.PhysicalLocationID = PoseLocation.PoseLocationID AND DataThing.DataThingID = PoseLocation.PoseLocationID";
DAO::getSqlQueriesDataSingle["PartRefAndPose"] = "SELECT PartRefAndPose.PartRefAndPoseID AS 'PartRefAndPose.PartRefAndPoseID', PartRefAndPose._NAME AS 'PartRefAndPose._NAME' FROM PartRefAndPose, DataThing WHERE  PartRefAndPose.PartRefAndPoseID = ? AND DataThing.DataThingID = PartRefAndPose.PartRefAndPoseID";
DAO::getSqlQueriesDataSingle["Slot"] = "SELECT Slot.SlotID AS 'Slot.SlotID', Slot._NAME AS 'Slot._NAME' FROM Slot, DataThing WHERE  Slot.SlotID = ? AND DataThing.DataThingID = Slot.SlotID";
DAO::getSqlQueriesDataSingle["BoxyShape"] = "SELECT BoxyShape.BoxyShapeID AS 'BoxyShape.BoxyShapeID', BoxyShape._NAME AS 'BoxyShape._NAME', BoxyShape.hasBoxyShape_Width AS 'BoxyShape.hasBoxyShape_Width', BoxyShape.hasBoxyShape_Height AS 'BoxyShape.hasBoxyShape_Height', BoxyShape.hasBoxyShape_Length AS 'BoxyShape.hasBoxyShape_Length', BoxyShape.hasBoxyShape_HasTop AS 'BoxyShape.hasBoxyShape_HasTop', ShapeDesign.hasShapeDesign_Description AS 'ShapeDesign.hasShapeDesign_Description' FROM BoxyShape, InternalShape, ShapeDesign, DataThing WHERE  BoxyShape.BoxyShapeID = ? AND InternalShape.InternalShapeID = BoxyShape.BoxyShapeID AND ShapeDesign.ShapeDesignID = BoxyShape.BoxyShapeID AND DataThing.DataThingID = BoxyShape.BoxyShapeID";
DAO::getSqlQueriesDataSingle["Part"] = "SELECT Part.PartID AS 'Part.PartID', Part._NAME AS 'Part._NAME', Part.hasPart_SerialNumber AS 'Part.hasPart_SerialNumber' FROM Part, SolidObject WHERE  Part.PartID = ? AND SolidObject.SolidObjectID = Part.PartID";
DAO::getSqlQueriesDataSingle["BoxVolume"] = "SELECT BoxVolume.BoxVolumeID AS 'BoxVolume.BoxVolumeID', BoxVolume._NAME AS 'BoxVolume._NAME' FROM BoxVolume, DataThing WHERE  BoxVolume.BoxVolumeID = ? AND DataThing.DataThingID = BoxVolume.BoxVolumeID";
DAO::getSqlQueriesDataSingle["Point"] = "SELECT Point.PointID AS 'Point.PointID', Point._NAME AS 'Point._NAME', Point.hasPoint_X AS 'Point.hasPoint_X', Point.hasPoint_Y AS 'Point.hasPoint_Y', Point.hasPoint_Z AS 'Point.hasPoint_Z' FROM Point, DataThing WHERE  Point.PointID = ? AND DataThing.DataThingID = Point.PointID";
DAO::getSqlQueriesDataSingle["EndEffectorHolder"] = "SELECT EndEffectorHolder.EndEffectorHolderID AS 'EndEffectorHolder.EndEffectorHolderID', EndEffectorHolder._NAME AS 'EndEffectorHolder._NAME' FROM EndEffectorHolder, SolidObject WHERE  EndEffectorHolder.EndEffectorHolderID = ? AND SolidObject.SolidObjectID = EndEffectorHolder.EndEffectorHolderID";
DAO::getSqlQueriesDataSingle["CylindricalShape"] = "SELECT CylindricalShape.CylindricalShapeID AS 'CylindricalShape.CylindricalShapeID', CylindricalShape._NAME AS 'CylindricalShape._NAME', CylindricalShape.hasCylindricalShape_Height AS 'CylindricalShape.hasCylindricalShape_Height', CylindricalShape.hasCylindricalShape_HasTop AS 'CylindricalShape.hasCylindricalShape_HasTop', CylindricalShape.hasCylindricalShape_Diameter AS 'CylindricalShape.hasCylindricalShape_Diameter', ShapeDesign.hasShapeDesign_Description AS 'ShapeDesign.hasShapeDesign_Description' FROM CylindricalShape, InternalShape, ShapeDesign, DataThing WHERE  CylindricalShape.CylindricalShapeID = ? AND InternalShape.InternalShapeID = CylindricalShape.CylindricalShapeID AND ShapeDesign.ShapeDesignID = CylindricalShape.CylindricalShapeID AND DataThing.DataThingID = CylindricalShape.CylindricalShapeID";
DAO::getSqlQueriesDataSingle["VacuumEffectorSingleCup"] = "SELECT VacuumEffectorSingleCup.VacuumEffectorSingleCupID AS 'VacuumEffectorSingleCup.VacuumEffectorSingleCupID', VacuumEffectorSingleCup._NAME AS 'VacuumEffectorSingleCup._NAME', VacuumEffector.hasVacuumEffector_CupDiameter AS 'VacuumEffector.hasVacuumEffector_CupDiameter', VacuumEffector.hasVacuumEffector_Length AS 'VacuumEffector.hasVacuumEffector_Length', EndEffector.hasEndEffector_Description AS 'EndEffector.hasEndEffector_Description', EndEffector.hasEndEffector_Weight AS 'EndEffector.hasEndEffector_Weight', EndEffector.hasEndEffector_MaximumLoadWeight AS 'EndEffector.hasEndEffector_MaximumLoadWeight' FROM VacuumEffectorSingleCup, VacuumEffector, EndEffector, SolidObject WHERE  VacuumEffectorSingleCup.VacuumEffectorSingleCupID = ? AND VacuumEffector.VacuumEffectorID = VacuumEffectorSingleCup.VacuumEffectorSingleCupID AND EndEffector.EndEffectorID = VacuumEffectorSingleCup.VacuumEffectorSingleCupID AND SolidObject.SolidObjectID = VacuumEffectorSingleCup.VacuumEffectorSingleCupID";
DAO::getSqlQueriesDataSingle["VacuumEffectorMultiCup"] = "SELECT VacuumEffectorMultiCup.VacuumEffectorMultiCupID AS 'VacuumEffectorMultiCup.VacuumEffectorMultiCupID', VacuumEffectorMultiCup._NAME AS 'VacuumEffectorMultiCup._NAME', VacuumEffectorMultiCup.hasVacuumEffectorMultiCup_ArrayRadius AS 'VacuumEffectorMultiCup.hasVacuumEffectorMultiCup_ArrayRadius', VacuumEffectorMultiCup.hasVacuumEffectorMultiCup_ArrayNumber AS 'VacuumEffectorMultiCup.hasVacuumEffectorMultiCup_ArrayNumber', VacuumEffector.hasVacuumEffector_CupDiameter AS 'VacuumEffector.hasVacuumEffector_CupDiameter', VacuumEffector.hasVacuumEffector_Length AS 'VacuumEffector.hasVacuumEffector_Length', EndEffector.hasEndEffector_Description AS 'EndEffector.hasEndEffector_Description', EndEffector.hasEndEffector_Weight AS 'EndEffector.hasEndEffector_Weight', EndEffector.hasEndEffector_MaximumLoadWeight AS 'EndEffector.hasEndEffector_MaximumLoadWeight' FROM VacuumEffectorMultiCup, VacuumEffector, EndEffector, SolidObject WHERE  VacuumEffectorMultiCup.VacuumEffectorMultiCupID = ? AND VacuumEffector.VacuumEffectorID = VacuumEffectorMultiCup.VacuumEffectorMultiCupID AND EndEffector.EndEffectorID = VacuumEffectorMultiCup.VacuumEffectorMultiCupID AND SolidObject.SolidObjectID = VacuumEffectorMultiCup.VacuumEffectorMultiCupID";
DAO::getSqlQueriesDataSingle["PoseLocationOn"] = "SELECT PoseLocationOn.PoseLocationOnID AS 'PoseLocationOn.PoseLocationOnID', PoseLocationOn._NAME AS 'PoseLocationOn._NAME', PoseLocation.hasPoseLocation_OrientationStandardDeviation AS 'PoseLocation.hasPoseLocation_OrientationStandardDeviation', PoseLocation.hasPoseLocation_PositionStandardDeviation AS 'PoseLocation.hasPoseLocation_PositionStandardDeviation', PhysicalLocation.hasPhysicalLocation_Timestamp AS 'PhysicalLocation.hasPhysicalLocation_Timestamp' FROM PoseLocationOn, PoseLocation, PhysicalLocation, DataThing WHERE  PoseLocationOn.PoseLocationOnID = ? AND PoseLocation.PoseLocationID = PoseLocationOn.PoseLocationOnID AND PhysicalLocation.PhysicalLocationID = PoseLocationOn.PoseLocationOnID AND DataThing.DataThingID = PoseLocationOn.PoseLocationOnID";
DAO::getSqlQueriesDataSingle["StockKeepingUnit"] = "SELECT StockKeepingUnit.StockKeepingUnitID AS 'StockKeepingUnit.StockKeepingUnitID', StockKeepingUnit._NAME AS 'StockKeepingUnit._NAME', StockKeepingUnit.hasStockKeepingUnit_Description AS 'StockKeepingUnit.hasStockKeepingUnit_Description', StockKeepingUnit.hasStockKeepingUnit_Weight AS 'StockKeepingUnit.hasStockKeepingUnit_Weight' FROM StockKeepingUnit, DataThing WHERE  StockKeepingUnit.StockKeepingUnitID = ? AND DataThing.DataThingID = StockKeepingUnit.StockKeepingUnitID";
DAO::getSqlQueriesDataSingle["PartsBin"] = "SELECT PartsBin.PartsBinID AS 'PartsBin.PartsBinID', PartsBin._NAME AS 'PartsBin._NAME', PartsBin.hasPartsBin_PartQuantity AS 'PartsBin.hasPartsBin_PartQuantity', PartsBin.hasPartsBin_SerialNumber AS 'PartsBin.hasPartsBin_SerialNumber' FROM PartsBin, SolidObject WHERE  PartsBin.PartsBinID = ? AND SolidObject.SolidObjectID = PartsBin.PartsBinID";
DAO::getSqlQueriesDataSingle["GripperEffector"] = "SELECT GripperEffector.GripperEffectorID AS 'GripperEffector.GripperEffectorID', GripperEffector._NAME AS 'GripperEffector._NAME', EndEffector.hasEndEffector_Description AS 'EndEffector.hasEndEffector_Description', EndEffector.hasEndEffector_Weight AS 'EndEffector.hasEndEffector_Weight', EndEffector.hasEndEffector_MaximumLoadWeight AS 'EndEffector.hasEndEffector_MaximumLoadWeight' FROM GripperEffector, EndEffector, SolidObject WHERE  GripperEffector.GripperEffectorID = ? AND EndEffector.EndEffectorID = GripperEffector.GripperEffectorID AND SolidObject.SolidObjectID = GripperEffector.GripperEffectorID";
DAO::getSqlQueriesDataSingle["PoseLocationIn"] = "SELECT PoseLocationIn.PoseLocationInID AS 'PoseLocationIn.PoseLocationInID', PoseLocationIn._NAME AS 'PoseLocationIn._NAME', PoseLocation.hasPoseLocation_OrientationStandardDeviation AS 'PoseLocation.hasPoseLocation_OrientationStandardDeviation', PoseLocation.hasPoseLocation_PositionStandardDeviation AS 'PoseLocation.hasPoseLocation_PositionStandardDeviation', PhysicalLocation.hasPhysicalLocation_Timestamp AS 'PhysicalLocation.hasPhysicalLocation_Timestamp' FROM PoseLocationIn, PoseLocation, PhysicalLocation, DataThing WHERE  PoseLocationIn.PoseLocationInID = ? AND PoseLocation.PoseLocationID = PoseLocationIn.PoseLocationInID AND PhysicalLocation.PhysicalLocationID = PoseLocationIn.PoseLocationInID AND DataThing.DataThingID = PoseLocationIn.PoseLocationInID";
DAO::getSqlQueriesDataSingle["EndEffector"] = "SELECT EndEffector.EndEffectorID AS 'EndEffector.EndEffectorID', EndEffector._NAME AS 'EndEffector._NAME', EndEffector.hasEndEffector_Description AS 'EndEffector.hasEndEffector_Description', EndEffector.hasEndEffector_Weight AS 'EndEffector.hasEndEffector_Weight', EndEffector.hasEndEffector_MaximumLoadWeight AS 'EndEffector.hasEndEffector_MaximumLoadWeight' FROM EndEffector, SolidObject WHERE  EndEffector.EndEffectorID = ? AND SolidObject.SolidObjectID = EndEffector.EndEffectorID";
DAO::getSqlQueriesDataSingle["PoseOnlyLocation"] = "SELECT PoseOnlyLocation.PoseOnlyLocationID AS 'PoseOnlyLocation.PoseOnlyLocationID', PoseOnlyLocation._NAME AS 'PoseOnlyLocation._NAME', PoseLocation.hasPoseLocation_OrientationStandardDeviation AS 'PoseLocation.hasPoseLocation_OrientationStandardDeviation', PoseLocation.hasPoseLocation_PositionStandardDeviation AS 'PoseLocation.hasPoseLocation_PositionStandardDeviation', PhysicalLocation.hasPhysicalLocation_Timestamp AS 'PhysicalLocation.hasPhysicalLocation_Timestamp' FROM PoseOnlyLocation, PoseLocation, PhysicalLocation, DataThing WHERE  PoseOnlyLocation.PoseOnlyLocationID = ? AND PoseLocation.PoseLocationID = PoseOnlyLocation.PoseOnlyLocationID AND PhysicalLocation.PhysicalLocationID = PoseOnlyLocation.PoseOnlyLocationID AND DataThing.DataThingID = PoseOnlyLocation.PoseOnlyLocationID";
DAO::getSqlQueriesDataSingle["WorkTable"] = "SELECT WorkTable.WorkTableID AS 'WorkTable.WorkTableID', WorkTable._NAME AS 'WorkTable._NAME' FROM WorkTable, SolidObject WHERE  WorkTable.WorkTableID = ? AND SolidObject.SolidObjectID = WorkTable.WorkTableID";
DAO::getSqlQueriesDataSingle["EndEffectorChangingStation"] = "SELECT EndEffectorChangingStation.EndEffectorChangingStationID AS 'EndEffectorChangingStation.EndEffectorChangingStationID', EndEffectorChangingStation._NAME AS 'EndEffectorChangingStation._NAME' FROM EndEffectorChangingStation, SolidObject WHERE  EndEffectorChangingStation.EndEffectorChangingStationID = ? AND SolidObject.SolidObjectID = EndEffectorChangingStation.EndEffectorChangingStationID";
DAO::getSqlQueriesDataSingle["LargeBoxWithEmptyKitTrays"] = "SELECT LargeBoxWithEmptyKitTrays.LargeBoxWithEmptyKitTraysID AS 'LargeBoxWithEmptyKitTrays.LargeBoxWithEmptyKitTraysID', LargeBoxWithEmptyKitTrays._NAME AS 'LargeBoxWithEmptyKitTrays._NAME' FROM LargeBoxWithEmptyKitTrays, SolidObject WHERE  LargeBoxWithEmptyKitTrays.LargeBoxWithEmptyKitTraysID = ? AND SolidObject.SolidObjectID = LargeBoxWithEmptyKitTrays.LargeBoxWithEmptyKitTraysID";
DAO::getSqlQueriesDataSingle["PartsTray"] = "SELECT PartsTray.PartsTrayID AS 'PartsTray.PartsTrayID', PartsTray._NAME AS 'PartsTray._NAME', PartsTray.hasPartsTray_SerialNumber AS 'PartsTray.hasPartsTray_SerialNumber' FROM PartsTray, SolidObject WHERE  PartsTray.PartsTrayID = ? AND SolidObject.SolidObjectID = PartsTray.PartsTrayID";
DAO::getSqlQueriesDataSingle["DataThing"] = "SELECT DataThing.DataThingID AS 'DataThing.DataThingID', DataThing._NAME AS 'DataThing._NAME' FROM DataThing WHERE  DataThing.DataThingID = ?";
DAO::getSqlQueriesDataSingle["KittingWorkstation"] = "SELECT KittingWorkstation.KittingWorkstationID AS 'KittingWorkstation.KittingWorkstationID', KittingWorkstation._NAME AS 'KittingWorkstation._NAME', KittingWorkstation.hasKittingWorkstation_LengthUnit AS 'KittingWorkstation.hasKittingWorkstation_LengthUnit', KittingWorkstation.hasKittingWorkstation_WeightUnit AS 'KittingWorkstation.hasKittingWorkstation_WeightUnit', KittingWorkstation.hasKittingWorkstation_AngleUnit AS 'KittingWorkstation.hasKittingWorkstation_AngleUnit' FROM KittingWorkstation, SolidObject WHERE  KittingWorkstation.KittingWorkstationID = ? AND SolidObject.SolidObjectID = KittingWorkstation.KittingWorkstationID";
DAO::getSqlQueriesDataSingle["KitTray"] = "SELECT KitTray.KitTrayID AS 'KitTray.KitTrayID', KitTray._NAME AS 'KitTray._NAME', KitTray.hasKitTray_SerialNumber AS 'KitTray.hasKitTray_SerialNumber' FROM KitTray, SolidObject WHERE  KitTray.KitTrayID = ? AND SolidObject.SolidObjectID = KitTray.KitTrayID";
DAO::getSqlQueriesDataSingle["RelativeLocationOn"] = "SELECT RelativeLocationOn.RelativeLocationOnID AS 'RelativeLocationOn.RelativeLocationOnID', RelativeLocationOn._NAME AS 'RelativeLocationOn._NAME', RelativeLocation.hasRelativeLocation_Description AS 'RelativeLocation.hasRelativeLocation_Description', PhysicalLocation.hasPhysicalLocation_Timestamp AS 'PhysicalLocation.hasPhysicalLocation_Timestamp' FROM RelativeLocationOn, RelativeLocation, PhysicalLocation, DataThing WHERE  RelativeLocationOn.RelativeLocationOnID = ? AND RelativeLocation.RelativeLocationID = RelativeLocationOn.RelativeLocationOnID AND PhysicalLocation.PhysicalLocationID = RelativeLocationOn.RelativeLocationOnID AND DataThing.DataThingID = RelativeLocationOn.RelativeLocationOnID";
DAO::getSqlQueriesDataSingle["PartsTrayWithParts"] = "SELECT PartsTrayWithParts.PartsTrayWithPartsID AS 'PartsTrayWithParts.PartsTrayWithPartsID', PartsTrayWithParts._NAME AS 'PartsTrayWithParts._NAME' FROM PartsTrayWithParts, SolidObject WHERE  PartsTrayWithParts.PartsTrayWithPartsID = ? AND SolidObject.SolidObjectID = PartsTrayWithParts.PartsTrayWithPartsID";
DAO::getSqlQueriesDataSingle["KitDesign"] = "SELECT KitDesign.KitDesignID AS 'KitDesign.KitDesignID', KitDesign._NAME AS 'KitDesign._NAME' FROM KitDesign, DataThing WHERE  KitDesign.KitDesignID = ? AND DataThing.DataThingID = KitDesign.KitDesignID";
DAO::getSqlQueriesDataSingle["VacuumEffector"] = "SELECT VacuumEffector.VacuumEffectorID AS 'VacuumEffector.VacuumEffectorID', VacuumEffector._NAME AS 'VacuumEffector._NAME', VacuumEffector.hasVacuumEffector_CupDiameter AS 'VacuumEffector.hasVacuumEffector_CupDiameter', VacuumEffector.hasVacuumEffector_Length AS 'VacuumEffector.hasVacuumEffector_Length', EndEffector.hasEndEffector_Description AS 'EndEffector.hasEndEffector_Description', EndEffector.hasEndEffector_Weight AS 'EndEffector.hasEndEffector_Weight', EndEffector.hasEndEffector_MaximumLoadWeight AS 'EndEffector.hasEndEffector_MaximumLoadWeight' FROM VacuumEffector, EndEffector, SolidObject WHERE  VacuumEffector.VacuumEffectorID = ? AND EndEffector.EndEffectorID = VacuumEffector.VacuumEffectorID AND SolidObject.SolidObjectID = VacuumEffector.VacuumEffectorID";
DAO::getSqlQueriesDataSingle["Vector"] = "SELECT Vector.VectorID AS 'Vector.VectorID', Vector._NAME AS 'Vector._NAME', Vector.hasVector_K AS 'Vector.hasVector_K', Vector.hasVector_J AS 'Vector.hasVector_J', Vector.hasVector_I AS 'Vector.hasVector_I' FROM Vector, DataThing WHERE  Vector.VectorID = ? AND DataThing.DataThingID = Vector.VectorID";
DAO::getSqlQueriesDataSingle["LargeContainer"] = "SELECT LargeContainer.LargeContainerID AS 'LargeContainer.LargeContainerID', LargeContainer._NAME AS 'LargeContainer._NAME', LargeContainer.hasLargeContainer_SerialNumber AS 'LargeContainer.hasLargeContainer_SerialNumber' FROM LargeContainer, SolidObject WHERE  LargeContainer.LargeContainerID = ? AND SolidObject.SolidObjectID = LargeContainer.LargeContainerID";
temp.clear();temp.push_back("-EndEffector/hadByEndEffector_Robot");
temp.push_back("-BoxVolume/hadByWorkVolume_Robot");
temp.push_back("-KittingWorkstation/hasKittingWorkstation_Robot");
DAO::getSqlQueriesObjectSingle["Robot"] = temp;
temp.clear();temp.push_back("-EndEffectorChangingStation/hasEndEffectorChangingStation_Base");
DAO::getSqlQueriesObjectSingle["MechanicalComponent"] = temp;
temp.clear();temp.push_back("LargeBoxWithKits/hadByKit_LargeBoxWithKits");
temp.push_back("KitTray/hasKit_KitTray");
temp.push_back("KitDesign/hasKit_Design");
temp.push_back("-Slot/hadBySlot_Kit");
temp.push_back("-Part/hadByPart_Kit");
DAO::getSqlQueriesObjectSingle["Kit"] = temp;
temp.clear();temp.push_back("-SolidObject/hasSolidObject_PrimaryLocation");
temp.push_back("SolidObject/hadBySecondaryLocation_SolidObject");
temp.push_back("SolidObject/hasPhysicalLocation_RefObject");
DAO::getSqlQueriesObjectSingle["PhysicalLocation"] = temp;
temp.clear();temp.push_back("-Kit/hadByKit_LargeBoxWithKits");
temp.push_back("LargeContainer/hasLargeBoxWithKits_LargeContainer");
temp.push_back("KitDesign/hasLargeBoxWithKits_KitDesign");
DAO::getSqlQueriesObjectSingle["LargeBoxWithKits"] = temp;
temp.clear();temp.push_back("SolidObject/hadByExternalShape_SolidObject");
DAO::getSqlQueriesObjectSingle["ExternalShape"] = temp;
temp.clear();temp.push_back("-PhysicalLocation/hadBySecondaryLocation_SolidObject");
temp.push_back("KittingWorkstation/hadByObject_KittingWorkstation");
temp.push_back("-InternalShape/hadByInternalShape_SolidObject");
temp.push_back("PhysicalLocation/hasSolidObject_PrimaryLocation");
temp.push_back("WorkTable/hadBySolidObject_WorkTable");
temp.push_back("-ExternalShape/hadByExternalShape_SolidObject");
temp.push_back("-EndEffector/hasEndEffector_HeldObject");
temp.push_back("-PhysicalLocation/hasPhysicalLocation_RefObject");
DAO::getSqlQueriesObjectSingle["SolidObject"] = temp;
temp.clear();temp.push_back("SolidObject/hadByInternalShape_SolidObject");
DAO::getSqlQueriesObjectSingle["InternalShape"] = temp;
temp.clear();temp.push_back("-PoseLocation/hadByGraspPose_ShapeDesign");
temp.push_back("-StockKeepingUnit/hasStockKeepingUnit_Shape");
DAO::getSqlQueriesObjectSingle["ShapeDesign"] = temp;
temp.clear();temp.push_back("ShapeDesign/hadByGraspPose_ShapeDesign");
temp.push_back("Vector/hasPoseLocation_XAxis");
temp.push_back("Vector/hasPoseLocation_ZAxis");
temp.push_back("Point/hasPoseLocation_Point");
DAO::getSqlQueriesObjectSingle["PoseLocation"] = temp;
temp.clear();temp.push_back("StockKeepingUnit/hasPartRefAndPose_Sku");
temp.push_back("Vector/hasPartRefAndPose_ZAxis");
temp.push_back("KitDesign/hadByPartRefAndPose_KitDesign");
temp.push_back("Point/hasPartRefAndPose_Point");
temp.push_back("Vector/hasPartRefAndPose_XAxis");
temp.push_back("-Slot/hasSlot_PartRefAndPose");
DAO::getSqlQueriesObjectSingle["PartRefAndPose"] = temp;
temp.clear();temp.push_back("Kit/hadBySlot_Kit");
temp.push_back("PartRefAndPose/hasSlot_PartRefAndPose");
temp.push_back("Part/hasSlot_Part");
DAO::getSqlQueriesObjectSingle["Slot"] = temp;
temp.clear();temp.push_back("-Slot/hasSlot_Part");
temp.push_back("Kit/hadByPart_Kit");
temp.push_back("PartsTrayWithParts/hadByPart_PartsTrayWithParts");
temp.push_back("StockKeepingUnit/hasPart_Sku");
DAO::getSqlQueriesObjectSingle["Part"] = temp;
temp.clear();temp.push_back("-PoseLocation/hasPoseLocation_Point");
temp.push_back("-PartRefAndPose/hasPartRefAndPose_Point");
temp.push_back("-BoxVolume/hasBoxVolume_MaximumPoint");
temp.push_back("-BoxVolume/hasBoxVolume_MinimumPoint");
DAO::getSqlQueriesObjectSingle["Point"] = temp;
temp.clear();temp.push_back("KittingWorkstation/hadByOtherObstacle_KittingWorkstation");
temp.push_back("Robot/hadByWorkVolume_Robot");
temp.push_back("Point/hasBoxVolume_MaximumPoint");
temp.push_back("Point/hasBoxVolume_MinimumPoint");
DAO::getSqlQueriesObjectSingle["BoxVolume"] = temp;
temp.clear();temp.push_back("EndEffectorChangingStation/hadByEndEffectorHolder_EndEffectorChangingStation");
temp.push_back("EndEffector/hasEndEffectorHolder_EndEffector");
DAO::getSqlQueriesObjectSingle["EndEffectorHolder"] = temp;
temp.clear();temp.push_back("StockKeepingUnit/hasPartsBin_Sku");
temp.push_back("StockKeepingUnit/hasPartsBin_PartSku");
DAO::getSqlQueriesObjectSingle["PartsBin"] = temp;
temp.clear();temp.push_back("-PartRefAndPose/hasPartRefAndPose_Sku");
temp.push_back("-Part/hasPart_Sku");
temp.push_back("-PartsBin/hasPartsBin_Sku");
temp.push_back("-PartsBin/hasPartsBin_PartSku");
temp.push_back("KittingWorkstation/hadBySku_KittingWorkstation");
temp.push_back("ShapeDesign/hasStockKeepingUnit_Shape");
temp.push_back("-PartsTray/hasPartsTray_Sku");
temp.push_back("-KitTray/hasKitTray_Sku");
temp.push_back("-KitDesign/hasKitDesign_KitTraySku");
temp.push_back("-LargeContainer/hasLargeContainer_Sku");
DAO::getSqlQueriesObjectSingle["StockKeepingUnit"] = temp;
temp.clear();temp.push_back("-EndEffectorHolder/hasEndEffectorHolder_EndEffector");
temp.push_back("SolidObject/hasEndEffector_HeldObject");
temp.push_back("Robot/hadByEndEffector_Robot");
DAO::getSqlQueriesObjectSingle["EndEffector"] = temp;
temp.clear();temp.push_back("-SolidObject/hadBySolidObject_WorkTable");
DAO::getSqlQueriesObjectSingle["WorkTable"] = temp;
temp.clear();temp.push_back("LargeContainer/hasLargeBoxWithEmptyKitTrays_LargeContainer");
temp.push_back("-KitTray/hadByKitTray_LargeBoxWithEmptyKitTrays");
DAO::getSqlQueriesObjectSingle["LargeBoxWithEmptyKitTrays"] = temp;
temp.clear();temp.push_back("-EndEffectorHolder/hadByEndEffectorHolder_EndEffectorChangingStation");
temp.push_back("MechanicalComponent/hasEndEffectorChangingStation_Base");
temp.push_back("-KittingWorkstation/hasKittingWorkstation_ChangingStation");
DAO::getSqlQueriesObjectSingle["EndEffectorChangingStation"] = temp;
temp.clear();temp.push_back("StockKeepingUnit/hasPartsTray_Sku");
temp.push_back("-PartsTrayWithParts/hasPartsTrayWithParts_PartsTray");
DAO::getSqlQueriesObjectSingle["PartsTray"] = temp;
temp.clear();temp.push_back("-SolidObject/hadByObject_KittingWorkstation");
temp.push_back("-BoxVolume/hadByOtherObstacle_KittingWorkstation");
temp.push_back("-StockKeepingUnit/hadBySku_KittingWorkstation");
temp.push_back("-KitDesign/hadByKitDesign_KittingWorkstation");
temp.push_back("EndEffectorChangingStation/hasKittingWorkstation_ChangingStation");
temp.push_back("Robot/hasKittingWorkstation_Robot");
DAO::getSqlQueriesObjectSingle["KittingWorkstation"] = temp;
temp.clear();temp.push_back("-Kit/hasKit_KitTray");
temp.push_back("StockKeepingUnit/hasKitTray_Sku");
temp.push_back("LargeBoxWithEmptyKitTrays/hadByKitTray_LargeBoxWithEmptyKitTrays");
DAO::getSqlQueriesObjectSingle["KitTray"] = temp;
temp.clear();temp.push_back("-Kit/hasKit_Design");
temp.push_back("-LargeBoxWithKits/hasLargeBoxWithKits_KitDesign");
temp.push_back("-PartRefAndPose/hadByPartRefAndPose_KitDesign");
temp.push_back("KittingWorkstation/hadByKitDesign_KittingWorkstation");
temp.push_back("StockKeepingUnit/hasKitDesign_KitTraySku");
DAO::getSqlQueriesObjectSingle["KitDesign"] = temp;
temp.clear();temp.push_back("-Part/hadByPart_PartsTrayWithParts");
temp.push_back("PartsTray/hasPartsTrayWithParts_PartsTray");
DAO::getSqlQueriesObjectSingle["PartsTrayWithParts"] = temp;
temp.clear();temp.push_back("-PoseLocation/hasPoseLocation_XAxis");
temp.push_back("-PoseLocation/hasPoseLocation_ZAxis");
temp.push_back("-PartRefAndPose/hasPartRefAndPose_ZAxis");
temp.push_back("-PartRefAndPose/hasPartRefAndPose_XAxis");
DAO::getSqlQueriesObjectSingle["Vector"] = temp;
temp.clear();temp.push_back("-LargeBoxWithKits/hasLargeBoxWithKits_LargeContainer");
temp.push_back("-LargeBoxWithEmptyKitTrays/hasLargeBoxWithEmptyKitTrays_LargeContainer");
temp.push_back("StockKeepingUnit/hasLargeContainer_Sku");
DAO::getSqlQueriesObjectSingle["LargeContainer"] = temp;
temp.clear();temp.push_back("EndEffector/hasStockKeepingUnit_EndEffector");
DAO::getSqlQueriesObjectMulti["StockKeepingUnit"] = temp;
temp.clear();temp.push_back("StockKeepingUnit/hasStockKeepingUnit_EndEffector");
DAO::getSqlQueriesObjectMulti["EndEffector"] = temp;
}

std::vector<std::string> DAO::getclassName(){
return this->className;
}
Connection* DAO::getconnection(){
return this->connection;
}
void DAO::setclassName(std::vector<std::string> _className){
this->className= _className;
}
void DAO::setconnection(Connection* _connection){
this->connection= _connection;
}
DAO::~DAO() {

}	std::map<std::string, std::string> DAO::get(std::string name) {
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
			try {
				prep_stmt = connection->getCon()->prepareStatement(
						DAO::getSqlQueriesDataMulti[className.back()][i]);
				prep_stmt->setInt(1, id);
				res = prep_stmt->executeQuery();
				while (res->next()) {
					if (!res->isLast())
						temp = temp + res->getString(1) + " ";
					else
						temp = temp + res->getString(1);
				}
				res_meta = res -> getMetaData();
				map[res_meta -> getColumnLabel(1)] = temp;
				delete (res);
				delete (prep_stmt);
			} catch (sql::SQLException &e) {
				std::cout << "# ERR: SQLException in " << __FILE__;
				std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__
						<< std::endl;
				std::cout << "# ERR: " << e.what();
				std::cout << " (MySQL error code: " << e.getErrorCode();
				std::cout << ", SQLState: " << e.getSQLState() << " )"
						<< std::endl;
			}
		}
		// get the Object Single
		temp = "";
		sql::ResultSet *restemp;
		sql::Statement *stmt;
		std::string newName = "";
		std::string newTable = "";
		for (int unsigned i = 0; i
				< DAO::getSqlQueriesObjectSingle[className.back()].size(); i++) {
			try {
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
															"/") - 1)
											+ "ID FROM "
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
				do {
					restemp->next();
					prep_stmt->setInt(1, restemp->getInt(1));
					res = prep_stmt->executeQuery();
					do {
						res->next();
						res_meta = res -> getMetaData();
						for (int j = 0; j < (int) res_meta -> getColumnCount(); ++j) {
							if (map[getSqlQueriesObjectSingle[className.back()][i].substr(
									getSqlQueriesObjectSingle[className.back()][i].find(
											"/") + 1) + "/"
									+ res_meta -> getColumnLabel(j + 1)] == "") {
								map[getSqlQueriesObjectSingle[className.back()][i].substr(
										getSqlQueriesObjectSingle[className.back()][i].find(
												"/") + 1) + "/"
										+ res_meta -> getColumnLabel(j + 1)]
										= res->getString(j + 1);
							} else {
								map[getSqlQueriesObjectSingle[className.back()][i].substr(
										getSqlQueriesObjectSingle[className.back()][i].find(
												"/") + 1) + "/"
										+ res_meta -> getColumnLabel(j + 1)]
										+= " " + res->getString(j + 1);

							}
						}
						if (getSqlQueriesObjectSingle[className.back()][i].substr(
								0, 1) != "-") {
							newName
									= res->getString(
											getSqlQueriesObjectSingle[className.back()][i].substr(
													0,
													getSqlQueriesObjectSingle[className.back()][i].find(
															"/")) + "._NAME");
						} else {
							newName
									= res->getString(
											getSqlQueriesObjectSingle[className.back()][i].substr(
													1,
													getSqlQueriesObjectSingle[className.back()][i].find(
															"/") - 1)
													+ "._NAME");

						}

						if (getSqlQueriesObjectSingle[className.back()][i].substr(
								0, 1) != "-") {
							newTable
									= getSqlQueriesObjectSingle[className.back()][i].substr(
											0,
											getSqlQueriesObjectSingle[className.back()][i].find(
													"/"));
						} else {
							newTable
									= getSqlQueriesObjectSingle[className.back()][i].substr(
											1,
											getSqlQueriesObjectSingle[className.back()][i].find(
													"/") - 1);
						}

					} while (!res->isLast());
					delete (res);

				} while (!restemp->isLast());
				delete (restemp);

				delete (prep_stmt);
				delete (stmt);
			} catch (sql::SQLException &e) {
			  /*
				std::cout << "# ERR: SQLException in " << __FILE__;
				std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__
						<< std::endl;
				std::cout << "# ERR: " << e.what();
				std::cout << " (MySQL error code: " << e.getErrorCode();
				std::cout << ", SQLState: " << e.getSQLState() << " )"
						<< std::endl;
			  */
			}
		}

		//get the Object multi
		sql::ResultSet *restempmulti;
		sql::Statement *stmtmulti;
		for (int unsigned m = 0; m
				< DAO::getSqlQueriesObjectMulti[className.back()].size(); m++) {
			try {
				//convert id to string
				std::string sid;
				std::stringstream out;
				out << id;
				sid = out.str();
				//end convert id
				stmtmulti = connection->getCon()->createStatement();
				restempmulti
						= stmtmulti->executeQuery(
								"SELECT "
										+ getSqlQueriesObjectMulti[className.back()][m].substr(
												0,
												getSqlQueriesObjectMulti[className.back()][m].find(
														"/")) + "ID FROM "
										+ getSqlQueriesObjectMulti[className.back()][m].substr(
												getSqlQueriesObjectMulti[className.back()][m].find(
														"/") + 1) + " WHERE "
										+ className.back() + "ID = " + sid);
				do {
					restempmulti->next();
					std::string
							table =
									getSqlQueriesObjectMulti[className.back()][m].substr(
											0,
											getSqlQueriesObjectMulti[className.back()][m].find(
													"/"));

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
						if (map[getSqlQueriesObjectMulti[className.back()][m].substr(
								getSqlQueriesObjectMulti[className.back()][m].find(
										"/") + 1) + "/"
								+ res_meta -> getColumnLabel(i + 1)] == "")
							map[getSqlQueriesObjectMulti[className.back()][m].substr(
									getSqlQueriesObjectMulti[className.back()][m].find(
											"/") + 1) + "/"
									+ res_meta -> getColumnLabel(i + 1)]
									= res->getString(i + 1);
						else
							map[getSqlQueriesObjectMulti[className.back()][m].substr(
									getSqlQueriesObjectMulti[className.back()][m].find(
											"/") + 1) + "/"
									+ res_meta -> getColumnLabel(i + 1)] += " "
									+ res->getString(i + 1);

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
						try {
							prep_stmt
									= connection->getCon()->prepareStatement(
											DAO::getSqlQueriesDataMulti[getSqlQueriesObjectMulti[className.back()][m].substr(
													0,
													getSqlQueriesObjectMulti[className.back()][m].find(
															"/"))][i]);
							prep_stmt->setInt(1, restempmulti->getInt(1));
							res = prep_stmt->executeQuery();
							while (res->next()) {
								if (!res->isLast())
									temp = temp + res->getString(1) + " ";
								else
									temp = temp + res->getString(1);

							}
							res_meta = res -> getMetaData();
							map[getSqlQueriesObjectMulti[className.back()][m].substr(
									getSqlQueriesObjectMulti[className.back()][m].find(
											"/") + 1) + "/"
									+ res_meta -> getColumnLabel(1)] = temp;
							delete (res);
							delete (prep_stmt);
						} catch (sql::SQLException &e) {
							std::cout << "# ERR: SQLException in " << __FILE__;
							std::cout << "(" << __FUNCTION__ << ") on line "
									<< __LINE__ << std::endl;
							std::cout << "# ERR: " << e.what();
							std::cout << " (MySQL error code: "
									<< e.getErrorCode();
							std::cout << ", SQLState: " << e.getSQLState()
									<< " )" << std::endl;
						}
					}
					//End Add Data Multi
					// Add Object Single
					for (int unsigned i = 0; i
							< DAO::getSqlQueriesObjectSingle[table].size(); i++) {
						try {
							stmt = connection->getCon()->createStatement();
							if (getSqlQueriesObjectSingle[table][i].substr(0, 1)
									!= "-") {
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
																		"/"))
														+ ", " + table
														+ " WHERE " + table
														+ "._Name = '" + name
														+ "' AND "
														+ getSqlQueriesObjectSingle[table][i].substr(
																getSqlQueriesObjectSingle[table][i].find(
																		"/")
																		+ 1)
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
																		"/")
																		- 1)
														+ "ID FROM "
														+ getSqlQueriesObjectSingle[table][i].substr(
																1,
																getSqlQueriesObjectSingle[table][i].find(
																		"/")
																		- 1)
														+ ", " + table
														+ " WHERE " + table
														+ "._Name = '" + name
														+ "' AND "
														+ getSqlQueriesObjectSingle[table][i].substr(
																getSqlQueriesObjectSingle[table][i].find(
																		"/")
																		+ 1)
														+ " = " + table
														+ "._Name");
								prep_stmt
										= connection->getCon()->prepareStatement(
												DAO::getSqlQueriesDataSingle[getSqlQueriesObjectSingle[table][i].substr(
														1,
														getSqlQueriesObjectSingle[table][i].find(
																"/") - 1)]);
							}
							do {
								restemp->next();
								prep_stmt->setInt(1, restemp->getInt(1));
								res = prep_stmt->executeQuery();
								do {
									res->next();
									res_meta = res -> getMetaData();
									for (int j = 0; j
											< (int) res_meta -> getColumnCount(); ++j) {
										if (map[getSqlQueriesObjectSingle[table][i].substr(
												getSqlQueriesObjectSingle[table][i].find(
														"/") + 1) + "/"
												+ res_meta -> getColumnLabel(j
														+ 1)] == "")
											map[getSqlQueriesObjectSingle[table][i].substr(
													getSqlQueriesObjectSingle[table][i].find(
															"/") + 1) + "/"
													+ res_meta -> getColumnLabel(
															j + 1)]
													= res->getString(j + 1);

										else
											map[getSqlQueriesObjectSingle[table][i].substr(
													getSqlQueriesObjectSingle[table][i].find(
															"/") + 1) + "/"
													+ res_meta -> getColumnLabel(
															j + 1)] += " "
													+ res->getString(j + 1);
									}
									if (getSqlQueriesObjectSingle[table][i].substr(
											0, 1) != "-") {
										newName
												= res->getString(
														getSqlQueriesObjectSingle[table][i].substr(
																0,
																getSqlQueriesObjectSingle[table][i].find(
																		"/"))
																+ "._NAME");
									} else {
										newName
												= res->getString(
														getSqlQueriesObjectSingle[table][i].substr(
																1,
																getSqlQueriesObjectSingle[table][i].find(
																		"/")
																		- 1)
																+ "._NAME");

									}

									if (getSqlQueriesObjectSingle[table][i].substr(
											0, 1) != "-") {
										newTable
												= getSqlQueriesObjectSingle[table][i].substr(
														0,
														getSqlQueriesObjectSingle[table][i].find(
																"/"));
									} else {
										newTable
												= getSqlQueriesObjectSingle[table][i].substr(
														1,
														getSqlQueriesObjectSingle[table][i].find(
																"/") - 1);
									}

								} while (!res->isLast());
								delete (res);

							} while (!restemp->isLast());
							delete (restemp);

							delete (prep_stmt);
							delete (stmt);
						} catch (sql::SQLException &e) {
							std::cout << "# ERR: SQLException in " << __FILE__;
							std::cout << "(" << __FUNCTION__ << ") on line "
									<< __LINE__ << std::endl;
							std::cout << "# ERR: " << e.what();
							std::cout << " (MySQL error code: "
									<< e.getErrorCode();
							std::cout << ", SQLState: " << e.getSQLState()
									<< " )" << std::endl;
						}
					}
				} while (!restempmulti->isLast());
				delete (restempmulti);
			} catch (sql::SQLException &e) {
				std::cout << "# ERR: SQLException in " << __FILE__;
				std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__
						<< std::endl;
				std::cout << "# ERR: " << e.what();
				std::cout << " (MySQL error code: " << e.getErrorCode();
				std::cout << ", SQLState: " << e.getSQLState() << " )"
						<< std::endl;
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
void DAO::set(std::map<std::string,std::string> data){	try {
		// DATA SINGLE
		sql::Statement *stmt;
		stmt = connection->getCon()->createStatement();
		std::string query = "UPDATE " + this->className.back();
		query = query + " SET ";
		for (std::map<std::string, std::string>::iterator it = data.begin(); it
				!= data.end(); it++) {
			if (DAO::getSqlQueriesDataSingle[this->className.back()].find(
					this->className.back() + "." + it->first)
					!= std::string::npos) {
				int val;
				std::stringstream stream(it->second);
				if (!(stream >> val)) {
					query = query + it->first + "='" + it->second + "', ";
				} else {
					query = query + it->first + "=" + it->second + ", ";
				}
			}
		}
		query = query.substr(0, query.length() - 2) + " ";//to delete the last ,
		query = query + "WHERE _NAME='" + data["name"] + "' ";
		query = query + "AND " + this->className.back() + "ID="
				+ data[this->className.back() + "ID"];
		stmt->executeUpdate(query);
		delete (stmt);
	}

	catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__
				<< std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
	// DATA MULTI

	for (int unsigned i = 0; i
			< DAO::getSqlQueriesDataMulti[className.back()].size(); i++) {
		try {
			sql::Statement *stmt;
			stmt = connection->getCon()->createStatement();
			std::string query;
			query = "DELETE FROM ";
			query
					= query
							+ DAO::getSqlQueriesDataMulti[className.back()][i].substr(
									DAO::getSqlQueriesDataMulti[className.back()][i].find(
											"FROM") + 5);
			query = query.substr(0, query.length() - 2) + " ";//to delete the last ?
			query = query + data[this->className.back() + "ID"];
			stmt->execute(query);

			std::vector<std::string>
					multi =
							Explode(
									data[DAO::getSqlQueriesDataMulti[className.back()][i].substr(
											DAO::getSqlQueriesDataMulti[className.back()][i].find(
													"SELECT") + 7,
											DAO::getSqlQueriesDataMulti[className.back()][i].find(
													"FROM")
													- (DAO::getSqlQueriesDataMulti[className.back()][i].find(
															"SELECT") + 8))],
									' ');
			if (!data[DAO::getSqlQueriesDataMulti[className.back()][i].substr(
					DAO::getSqlQueriesDataMulti[className.back()][i].find(
							"SELECT") + 7,
					DAO::getSqlQueriesDataMulti[className.back()][i].find(
							"FROM")
							- (DAO::getSqlQueriesDataMulti[className.back()][i].find(
									"SELECT") + 8))].empty())
				for (int unsigned i = 0; i < multi.size(); i++) {
					query
							= "INSERT INTO "
									+ DAO::getSqlQueriesDataMulti[className.back()][i].substr(
											DAO::getSqlQueriesDataMulti[className.back()][i].find(
													"FROM") + 5,
											DAO::getSqlQueriesDataMulti[className.back()][i].find(
													"WHERE")
													- (DAO::getSqlQueriesDataMulti[className.back()][i].find(
															"FROM") + 5));
					query
							= query + "(" + this->className.back() + "ID"
									+ ", "
									+ DAO::getSqlQueriesDataMulti[className.back()][i].substr(
											DAO::getSqlQueriesDataMulti[className.back()][i].find(
													"SELECT") + 7,
											DAO::getSqlQueriesDataMulti[className.back()][i].find(
													"FROM")
													- (DAO::getSqlQueriesDataMulti[className.back()][i].find(
															"SELECT") + 8))
									+ ")";
					int val;
					std::stringstream stream(multi[i]);
					if (!(stream >> val)) {
						query = query + " VALUES("
								+ data[this->className.back() + "ID"] + ", '"
								+ multi[i] + "')";
					} else {
						query = query + " VALUES("
								+ data[this->className.back() + "ID"] + ", "
								+ multi[i] + ")";
					}
					stmt->execute(query);

				}
			delete (stmt);
		} catch (sql::SQLException &e) {
			std::cout << "# ERR: SQLException in " << __FILE__;
			std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__
					<< std::endl;
			std::cout << "# ERR: " << e.what();
			std::cout << " (MySQL error code: " << e.getErrorCode();
			std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		}
	}

	// OBJECT SINGLE

	for (int unsigned i = 0; i
			< DAO::getSqlQueriesObjectSingle[className.back()].size(); i++) {
		try {
			sql::Statement *stmt;
			stmt = connection->getCon()->createStatement();
			std::string query;
			if (DAO::getSqlQueriesObjectSingle[className.back()][i].substr(0, 1)
					!= "-") {
				query = "UPDATE " + className.back() + " ";
				query
						= query + "SET "
								+ DAO::getSqlQueriesObjectSingle[className.back()][i].substr(
										DAO::getSqlQueriesObjectSingle[className.back()][i].find(
												"/") + 1) + "='"
								+ data[DAO::getSqlQueriesObjectSingle[className.back()][i].substr(
										DAO::getSqlQueriesObjectSingle[className.back()][i].find(
												"/") + 1)];
				query = query + "' WHERE " + this->className.back() + "ID="
						+ data[this->className.back() + "ID"];
				if (!data[DAO::getSqlQueriesObjectSingle[className.back()][i].substr(
						DAO::getSqlQueriesObjectSingle[className.back()][i].find(
								"/") + 1)].empty())

					stmt->execute(query);

			} else {
				query
						= "UPDATE "
								+ DAO::getSqlQueriesObjectSingle[className.back()][i].substr(
										1,
										DAO::getSqlQueriesObjectSingle[className.back()][i].find(
												"/") - 1);
				query
						= query + " SET "
								+ DAO::getSqlQueriesObjectSingle[className.back()][i].substr(
										DAO::getSqlQueriesObjectSingle[className.back()][i].find(
												"/") + 1) + "='" + data["name"];
				query
						= query + "' WHERE _NAME='"
								+ data[DAO::getSqlQueriesObjectSingle[className.back()][i].substr(
										DAO::getSqlQueriesObjectSingle[className.back()][i].find(
												"/") + 1)] + "'";
				if (!data[DAO::getSqlQueriesObjectSingle[className.back()][i].substr(
						DAO::getSqlQueriesObjectSingle[className.back()][i].find(
								"/") + 1)].empty())
					stmt->execute(query);
			}
			delete (stmt);
		} catch (sql::SQLException &e) {
			std::cout << "# ERR: SQLException in " << __FILE__;
			std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__
					<< std::endl;
			std::cout << "# ERR: " << e.what();
			std::cout << " (MySQL error code: " << e.getErrorCode();
			std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		}
	}

	// OBJECT MULTI

	for (int unsigned i = 0; i
			< DAO::getSqlQueriesObjectMulti[className.back()].size(); i++) {
		try {
			sql::Statement *stmt;
			stmt = connection->getCon()->createStatement();
			std::string query;
			query = "DELETE FROM ";
			query
					= query
							+ DAO::getSqlQueriesObjectMulti[className.back()][i].substr(
									DAO::getSqlQueriesObjectMulti[className.back()][i].find(
											"/") + 1);
			query = query + " WHERE " + this->className.back() + "ID="
					+ data[this->className.back() + "ID"];
			stmt->execute(query);
			std::vector<std::string>
					multi =
							Explode(
									data[DAO::getSqlQueriesObjectMulti[className.back()][i].substr(
											DAO::getSqlQueriesObjectMulti[className.back()][i].find(
													"/") + 1)], ' ');
			if(!data[DAO::getSqlQueriesObjectMulti[className.back()][i].substr(
					DAO::getSqlQueriesObjectMulti[className.back()][i].find(
							"/") + 1)].empty())
			for (int unsigned i = 0; i < multi.size(); i++) {
				query
						= "INSERT INTO "
								+ DAO::getSqlQueriesObjectMulti[className.back()][i].substr(
										DAO::getSqlQueriesObjectMulti[className.back()][i].find(
												"/") + 1);
				query
						= query + " (" + this->className.back() + "ID" + ","
								+ DAO::getSqlQueriesObjectMulti[className.back()][i].substr(
										0,
										DAO::getSqlQueriesObjectMulti[className.back()][i].find(
												"/")) + "ID)";

				query = query + " VALUES("
						+ data[this->className.back() + "ID"] + ", " + multi[i]
						+ ")";
				stmt->execute(query);
			}
			delete (stmt);

		} catch (sql::SQLException &e) {
			std::cout << "# ERR: SQLException in " << __FILE__;
			std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__
					<< std::endl;
			std::cout << "# ERR: " << e.what();
			std::cout << " (MySQL error code: " << e.getErrorCode();
			std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		}
	}
		}
std::vector<std::string> DAO::Explode(const std::string & str, char separator )
{
   std::vector< std::string > result;
   std::size_t pos1 = 0;
   std::size_t pos2 = 0;
   while ( pos2 != str.npos )
   {
      pos2 = str.find(separator, pos1);
      if ( pos2 != str.npos )
      {
         if ( pos2 > pos1 )
            result.push_back( str.substr(pos1, pos2-pos1) );
         pos1 = pos2+1;
      }
   }
   result.push_back( str.substr(pos1, str.size()-pos1) );
   return result;
}


std::map<std::string, std::vector<std::string> > DAO::getAll(std::vector<
		std::string> attributesList, std::string table) {
	std::map<std::string, std::vector<std::string> > result;
	try {
		sql::ResultSetMetaData *res_meta;
		sql::ResultSet *res;
		sql::Statement *stmt;
		std::string attributes = "";
		for (int i = 0; i < (int) attributesList.size(); i++) {
			attributes = attributes + ", " + attributesList[i];
		}
		std::string query = "SELECT " + attributes.substr(2) + " FROM " + table;
		stmt = connection->getCon()->createStatement();
		res = stmt->executeQuery(query);
		res_meta = res -> getMetaData();
		while (res->next()) {
			for (int i = 0; i < (int) res_meta -> getColumnCount(); ++i) {
				std::vector<std::string> temp =
						result[res_meta -> getColumnLabel(i + 1)];
				temp.push_back(res->getString(i + 1));
				result[res_meta -> getColumnLabel(i + 1)] = temp;
			}
		}
		delete (res);
		delete (stmt);

	} catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__
				<< std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
	return result;
}

