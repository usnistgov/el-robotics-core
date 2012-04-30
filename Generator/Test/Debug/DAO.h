
#ifndef DAO_H_
#define DAO_H_
#include <cstdlib>
#include <iostream>

#include "PartsBin.h"
#include "LargeContainer.h"
#include "SolidObject.h"
#include "KittingWorkstation.h"
#include "BoxyObject.h"
#include "GripperEffector.h"
#include "PhysicalLocation.h"
#include "ShapeDesign.h"
#include "RelativeLocationIn.h"
#include "KitInstance.h"
#include "Part.h"
#include "PartsTrayWithParts.h"
#include "PartsTray.h"
#include "Pose.h"
#include "Robot.h"
#include "LargeBoxWithKits.h"
#include "PartRefAndPose.h"
#include "VacuumEffectorMultiCup.h"
#include "EndEffectorChangingStation.h"
#include "RelativeLocation.h"
#include "Vector.h"
#include "KitTray.h"
#include "StockKeepingUnit.h"
#include "Point.h"
#include "WorkTable.h"
#include "LargeBoxWithEmptyKitTrays.h"
#include "BoxVolume.h"
#include "VacuumEffectorSingleCup.h"
#include "DataThing.h"
#include "EndEffector.h"
#include "KitDesign.h"
#include "VacuumEffector.h"
#include "EndEffectorHolder.h"
#include "RelativeLocationOn.h"
#include "RollPitchYaw.h"
#include "Connect.h"
class DAO {
private:
std::string className;
public:
 DAO(std::string classeName);
std::string getclassName();
void setclassName(std::string _className);
}; 
#endif /* DAO_H_ */