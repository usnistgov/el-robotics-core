/*

The KittingViewer class is used to encapsulate (as static class variables)
variables that would otherwise be global. Making the functions static
helps avoid name conflicts and makes it unnecessary to have an instance
of a KittingViewer.

See kittingViewer.cc for documentation of what the functions do and what
the variables are for. Since the variables are static, they are
initialized in that file.

*/

#ifndef KITTINGVIEWER_HH
#define KITTINGVIEWER

// WORKSTATIONLENGTH is in millimeters
// WORKSTATIONWIDTH  is in millimeters
// ROBOTDEFAULTMAXACCEL is in millimeters per second per second
// ROBOTDEFAULTMAXSPEED is in millimeters per second

#define WORKSTATIONLENGTH 10000.0f
#define WORKSTATIONWIDTH 5000.0f
#define ROBOTDEFAULTMAXACCEL 10000.0f
#define ROBOTDEFAULTMAXSPEED 1000.0f
#define TEXTSIZE 200
#define PATHSIZE 100
#define MAXPOSES 100

#include <list>
#include <map>
#include "canonicalMsg.hh"
#include "kittingClassesView.hh"
#include "scoreKittingClasses.hh"

class KittingViewer
{
 public:
  static void adjustKitLocation(KitType * kit, SolidObjectType * refSolid,
				PoseLocationType * kitPrimaryPose); 
  static void adjustPartLocation(PartType * part, SolidObjectType * refSolid,
				 PoseLocationType * partPrimaryPose); 
  static void checkLocation(SolidObjectType * object1);
  static bool checkPointAndAxes(PointType * goalPoint, PointType * actualPoint,
		   VectorType * goalXAxis, VectorType * actualXAxis,
		   VectorType * goalZAxis, VectorType * actualZAxis,
		   const char * name);
  static void clearLists();
  static void computeScore(SolidObjectType * object);
  static int countMovableObjects();
  static void createKit(PartType * part, KitTrayType * tray,
			SolidObjectType * parent);
  static void drawBoxyShape(BoxyShapeType * boxy, col color,
			    PoseLocationType * pose);
  static void drawChangingStation(EndEffectorChangingStationType * station);
  static void drawVacuumGripper(VacuumEffectorType * gripper,
				PoseLocationType * pose);
  static void drawRobot();
  static void drawSingleCupGripper(col color, double x, double y, double z,
		   double cupRadius, double length, double xI, double xJ,
                   double xK, double zI, double zJ, double zK);
  static void drawSolidObject(SolidObjectType * object);
  static void drawString(float x, float y, void * font, char * string);
  static void drawWorkstation();
  static void dwell(double seconds);
  static void enterPoseTarget(Pose * pose);
  static void enterPoseTargets(Pose ** posesIn, int num);
  static void executeCloseGripperCommand();
  static void executeCloseToolChangerCommand();
  static void executeCommand(CanonicalMsg * command);
  static void executeDwellCommand(DwellMsg * dwell);
  static void executeMoveStraightToCommand(MoveStraightToMsg * moveStraightTo);
  static void executeMoveThroughToCommand(MoveThroughToMsg * moveThroughTo);
  static void executeMoveToCommand(MoveToMsg * moveTo);
  static void executeOpenGripperCommand();
  static void executeOpenToolChangerCommand();
  static void executeSetAbsoluteAccelerationCommand(
                  SetAbsoluteAccelerationMsg * setAbsAccel);
  static void executeSetAbsoluteSpeedCommand(
                  SetAbsoluteSpeedMsg * setAbsSpeed);
  static void executeSetAngleUnitsCommand(SetAngleUnitsMsg * setAngleUnits);
  static void executeSetEndAngleToleranceCommand(
                  SetEndAngleToleranceMsg * setEndAngleTolerance);
  static void executeSetEndPointToleranceCommand(
	          SetEndPointToleranceMsg * setEndPointTolerance);
  static void executeSetIntermediatePointToleranceCommand(
	          SetIntermediatePointToleranceMsg * setIntPointTolerance);
  static void executeSetLengthUnitsCommand(SetLengthUnitsMsg * setLengthUnits);
  static void executeSetRelativeAccelerationCommand(
		  SetRelativeAccelerationMsg * setRelAccel);
  static void executeSetRelativeSpeedCommand(
		  SetRelativeSpeedMsg * setRelSpeed);
  static double findDistance(SolidObjectType * object);
  static SolidObjectType * findGripped(double X, double Y, double Z);
  static KitType * findKitWithTray(
                  std::string trayName, std::list<KitType *> * allKits);
  static PoseLocationType * findPrimaryPose(SolidObjectType * solid);
  static PoseLocationType * findSecondaryPose(SolidObjectType * solid);
  static SolidObjectType * findSurface(double x, double y, double z,
		  SolidObjectType * solid, double * xOffset,
		  double * yOffset, double * zOffset);
  static StockKeepingUnitType * findSku(XmlIDREF * skuName,
				  std::list<StockKeepingUnitType *> * Skus);
  static EndEffectorHolderType * findToolHolder(PointType * point);
  static bool gripperCanHandleSku(XmlID * gripperName,
				  StockKeepingUnitType * sku);
  static void handleExecute();
  static void handleResets();
  static double hypot3(double x, double y, double z);
  static void init(char * commandFile, char * kittingInitFile,
                   char * kittingGoalFile, char * scoringFile);
  static void initData();
  static void insertBox(col boxColor, double minX, double minY, double minZ,
			double maxX, double maxY, double maxZ, bool solid);
  static void insertBoxTransformed(col boxColor, double pointX, double pointY,
		  double pointZ, double length, double width, double height,
                  double xAxisX, double xAxisY, double xAxisZ, double zAxisX,
		  double zAxisY, double zAxisZ, bool hasTop, bool solid);
  static void insertConeTransformed(col color, double pointX, double pointY,
		  double pointZ, double radius1, double radius2, double height,
		  double xAxisX, double xAxisY, double xAxisZ, double zAxisX,
                  double zAxisY, double zAxisZ);
  static void insertDiskTransformed(col color, double pointX, double pointY,
		  double pointZ, double radius, double xAxisX, double xAxisY,
                  double xAxisZ, double zAxisX, double zAxisY, double zAxisZ);
  static void makeBlueColor(col * color);
  static void makeGreenColor(col * color);
  static void makeRedColor(col * color);
  static void poseProduct(PoseLocationType * poseToSet,
			  PoseLocationType * pose1, PoseLocationType * pose2);
  static void printMetricsAndSettings(int height);
  static void putInDefaultPosition(PoseLocationType * pose);
  static void putInOtherPosition(
                  PoseLocationType * pose, PoseLocationType * source);
  static void readScoringFile(char * scoringFile);
  static void recordInitialPosition(SolidObjectType * goalObject);
  static void recordInitialPositions(
                  std::map<std::string, SolidObjectType *> allSolids);
  static void redraw();
  static void releaseObject(VacuumEffectorSingleCupType * single,
			    SolidObjectType * solid);
  static void relocateTray(PartsTrayWithPartsType * supply);
  static void resetPositions(double x, double y, double z, double xi, double xj,
			     double xk, double zi, double zj, double zk);
  static void setColorAndSku(SolidObjectType * object,
			     std::list<StockKeepingUnitType *> * Skus);
  static void setExecuteFlag(bool setting);
  static void setLocationsAndColors(
                  std::map<std::string, SolidObjectType *> allSolids);
  static void setNetTransform(PoseLocationType * newPose,
		  std::list<PhysicalLocationType *> * locationStack);
  static void setWorkstationLocation(SolidObjectType * object);
  static bool solidIsMovable(SolidObjectType * solid);
  static void updateWorkstationPosition(SolidObjectType * object,
					PoseLocationType * parentPose);
  static double valuate(valueFunctionType * fun, double val);

  // private: // might make this private again. Need access functions if so.

  enum execStateE {unready, ready, ended};

  static int                 actionCommandsExecuted; // num action cmds executed
  static double              angleFactor; // factor for angle conversion
  static char                angleUnits[TEXTSIZE]; // degree, radian
  static std::list<CanonicalMsg *> commands; //commands read from file
  static int                 commandSequenceErrors; // number of sequence errors
  static char                commandString[MAXPOSES][TEXTSIZE]; //command string
  static double              distanceTotal; // total distance moved by robot
  static double              distances[MAXPOSES];// array of distances
  static double              distancesX[MAXPOSES];// array of X distances
  static double              distancesY[MAXPOSES];// array of Y distances
  static double              distancesZ[MAXPOSES];// array of Z distances
  static bool                executeFlag; // true = execute next command
  static int                 executionState; // unready, ready, or ended
  static double              fraction;    // proportion of motion done
  static KittingWorkstationType * goalModel; // model built from goal file
  static int                 gripperUseErrors; // number of gripper use errors
  static double              lengthFactor; // factor for length conversion
  static char                lengthUnits[TEXTSIZE]; // meter, millim, inch
  static KittingWorkstationType * nowModel; // model from init file & updated
  static double              nowX;   // controlled point X position now
  static double              nowXAxisI; // X component of controlled pt X axis
  static double              nowXAxisJ; // Y component of controlled pt X axis
  static double              nowXAxisK; // Z component of controlled pt X axis
  static double              nowY;   // controlled point Y position now
  static double              nowZ;   // controlled point Z position now
  static double              nowZAxisI; // X component of controlled pt Z axis
  static double              nowZAxisJ; // Y component of controlled pt Z axis
  static double              nowZAxisK; // Z component of controlled pt Z axis
  static int                 otherCommandsExecuted; // num other cmds executed
  static int                 parseErrors; // number of errors in parsing file
  static int                 locationErrors; //number of errors in part location
  static int                 locationGoods; // number objects in right location
  static int                 poseIndex;   // index of poses and times arrays
  static Pose                poses[MAXPOSES]; // array of poses to move to
  static int                 posesTotal;  // total number of poses to move to
  static int                 rangeErrors; // total out-of-range errors
  static bool                resetFlag; // true = update positions
  static double              robotAccel; // acceleration setting
  static double              robotAngleFactor; // factor for angle conversion
  static char                robotAngleUnits[TEXTSIZE]; // degree, radian
  static double              robotEndAngleTol; // end angle tolerance
  static double              robotEndPointTol; // end point tolerance
  static bool                robotGripperOpen; // true=open, false=closed
  static double              robotIntPointTol; // intermediate point tolerance
  static double              robotLengthFactor; // factor for length conversion
  static char                robotLengthUnits[TEXTSIZE]; // meter, millim, inch
  static double              robotMaxAccel; // maximum robot acceleration
  static double              robotMaxSpeed; // maximum robot speed
  static double              robotRelAccel; // relative acceleration setting
  static double              robotRelSpeed; // relative speed setting
  static double              robotSpeed;  // speed setting in length units/sec
  static bool                robotToolChangerOpen; // true=open, false=closed
  static double              score;   // the score for the command file
  static float               scale;   // scale to use to convert mm to picture
  static char                scoringFileName[TEXTSIZE]; // name of scoring file
  static float               spacing; // grid line spacing in meters
  static double              times[MAXPOSES]; // times corresponding to poses
  static int                 toolChangeErrors; // total tool change errors
  static double              totalExecutionTime; // total execution time
  static double              totalGoalDistance; // total goal object distance
  static int                 uselessCommands; // number commands with no effect
  static double              weightFactor; // factor for weight conversion
  static char                weightUnits[TEXTSIZE]; // gram, pound, etc.
};

#endif //KITTINGVIEWER_HH
