/*
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*/

/*!
  \file kittingViewer.cc

  \brief Displays a representation of executing canonical robot commands.
  \code CVS Status:
  $Author: tomrkramer $
  $Revision: 1.0 $
  $Date: 2012/07/02 20:49:22 $
  \endcode

  \author Tom Kramer
  \date October 11, 2012

*/

/* TODO

1. Add an option to base location metrics on SKUs rather than on specific
objects. The data files would still use specific objects. For example,
if there are two instances of part_a it is OK if the locations of
part_a_1 and part_a_2 are switched when the robot program is finished
executing.

2. Implement fixes described in enterPoseTargets.

3. Get gripper to rotate while translating (or rotate without translating)

4. Write a user guide for the kittingViewer

*/

/* MAYBE TODO

1. Use OWL instance files as input. Using an OWL file as input might be
done as follows. Steps a, c, and d are already done.
a. Read the OWL instance file into the MySQL database for kitting.
b. Use the MySQL interface functions to build a tree of instances of the
   XML C++ kittingClasses for kitting.
c. Print the XML C++ class tree into an XML file.
d. Use the XML file for input as is currently done.

2. Print changes in metrics in yellow in the metrics window. They would
revert to white the next time the g key is pressed. 

3. Print error messages in red.

4. Refine elapsed time calculations by using acceleration.

5. Check moves against robot work volume.

6. Add destroying LargeBoxWithEmptyKitTrays when last kit tray is
removed (similar to the way PartsTrayWithParts is destroyed when the last
part is removed).

7. Add creating LargeBoxWithKits when the first kit is put into a
large box (similar to the way a Kit is created when the first part is
put into the kit tray).

8. Use a graphical user interface for the kittingViewer.

9. Use a graphical user interface for editing the scoring file.

10. Use grasp point information in deciding whether a close gripper command
results in an object being held by the gripper.

11. Use shape data fom an external file (identified by an ExternalShape).

*/

/*

Units
-----

KittingViewer internal values for length units are always millimeters.
Internal values for angle units are always degrees. Internal values
for weight units are always grams.

The robot has a robotLengthUnits, a robotLengthFactor, a
robotAngleUnits, and a robotAngleFactor. Initially, the kittingViewer
sets the robotLengthUnits to millimeters and sets the robotAngleUnits
to degrees. The units may be changed by a setLengthUnits or
setAngleUnits canonical robot command. The robotLengthFactor is reset
when the robotLengthUnit is reset. The robotAngleFactor is reset when
the robotAngleUnit is reset. Output values for the robot (the ones
printed in the Metrics and Settings window) are converted to current
robotLengthUnits and current robotAngleUnits. Conversion is done on
input (from a robot canonical command) by multiplying by the
robotLengthFactor or the robotAngleFactor. Input conversion is done
just before a command is executed, not when it is read, since the
units for a particular command are not known at read time. Conversion
is done on output by dividing by the robotLengthFactor or the
robotAngleFactor. Robot commands do not use weight units.

The kitting workstation has its own angleUnits, lengthUnits,
angleFactor, and lengthFactor. In addition, it has weightUnits and a
weightFactor. The workstation's units are set in the workstation
initial conditions file and may not be reset. The only output value
for the workstation is the length unit for grid spacing printed in the
Metrics and Settings window. Input values for the workstation are
converted to millimeters, grams, or degrees immediately after the
workstation initial model is read and do not change. Conversion is
done on input by multiplying by the lengthFactor, the weightFactor, or
the angleFactor. Conversion of the grid spacing is done on output by
dividing by the lengthFactor.

Robot
-----

The robot model in the kitting workstation model currently has no
shape. To deal with that, this file has shape for the robot, as
described in documentation of the drawRobot function. In the
kittingViewer, the location of the robot is the location of the quill
of the robot (the last arm). The coordinate system of the quill has
its origin at the end of the quill, its Z axis on the axis of the
quill pointing away from the quill (always 0,0,-1 in workstation
coordinates) and its X axis parallel to the X axis of the workstation
(always 1,0,0 in workstation coordinates). If a gripper is attached to
the quill, the origin of the gripper coordinate system is on the
origin of the quill coordinate system.

Drawing Changing Station and Tool Holders
-----------------------------------------

The changing station consists of a base with and tool holders. The
base and tool holders have their own shape, color, and location.
The changing station is drawn by drawing its component parts.

Drawing End Effectors
---------------------

The end effector models currently have no shape. To deal with that,
this file has shape for them, as described in documentation of the
drawVacuumGripper function. Only single cup vacuum end effectors are
drawn.

Controlled Pose and Controlled Point
------------------------------------

The canonical robot motion commands specify poses to move to in terms
of the coordinate system of the kitting workstation. The commands are
directed to a movable pose (a pose is essentially the specification of
the position and orientation of a coordinate system). That pose is
called the controlled pose, and the point in the pose (the origin of
the coordinate system represented by the pose) is called the
controlled point.

When there is no gripper on the quill of the robot, the controlled point
is the origin of the quill, the Z axis of the controlled pose is always
(0,0,-1), and the X axis of the controlled pose is always (1,0,0). It is
an error to execute a command that moves the Z or X axis when there is no
gripper.

When there is a gripper on the quill, the controlled pose is at the middle
of the end of the gripper, and the Z axis and X axis may take on different
values. The range of allowed orientations of the Z axis may be limited.
The range of allowed orientations of the X axis is not limited (except that
the X axis must be perpendicular to the Z axis). The controlled pose is in
the same orientation as the coordinate system of the gripper, and its
origin is located on the positive Z axis of the gripper a distance
from the origin of the gripper coordinate system equal to the length
of the gripper.

Command Execution
-----------------

Command execution is handled by the executeCommand function, which in most
cases calls a subordinate function that handles the specific type of 
command.

Several of these commands run sanity checks on their arguments. The three
move commands trigger the kittingViewer to save data for animation. If a
command sets something to what it already is, one is added to the number
of useless commands; this applies to angle units, length units, and opening
or closing of gripper or tool changer. If a command sets a value out of
range, 1 is added to rangeErrors.

This is not currently checking that the destination point of a move is
inside the robot work volume. That might be added since the work volume
is available at planning time.


Command and Command Execution Error Handling
--------------------------------------------
When a command is processed, the command is always printed at the top of the 
Kitting Command & Messages window. If there is an error in processing the
command, an error message is printed after the command. Also if there is
an error, the command has no effect, so the existing state of the kitting
workstation is unchanged. Text to be printed in the Kitting Command & Messages
window is placed into the commandMessages array of strings by functions
in this file and functions in the canonicalMsgView.cc file. If there is an
error message, it is placed in commandMessages[0]. All error messages fit
on one line, and there is never more than one error message. The command
being processed starts in commandMessages[1] and may cover many lines.
Command execution error detection is handled here.

Total Execution Time
--------------------

The three move commands each cause time to be added to the total execution
time. The InitCanon, EndCanon, Message, and SetXXX commands take no time.
Dwell takes the given dwell time. OpenGripper, CloseGripper, OpenToolChanger,
and CloseToolChanger are assigned 0.2 seconds each.

Tool Holder and End Effector Constraints
-----------------------------------------

The requirements in effect here for tool holders and end effectors are:
- The coordinate system of a tool holder in workstation coordinates
  always has (1,0,0) for its X axis and (0,0,1) for its Z axis.
- When an end effector is in a tool holder, the origin of the end effector
  coordinate system must be in the same place as the origin of the tool
  holder, and the end effector's X axis and Z axis must be (1,0,0) and
  (0,0,-1) respectively (in both workstation coordinates and tool holder
  coordinates). It is an error if the robot puts an end effector into a
  tool holder in any other position.
- For the robot to attach to an end effector in a tool holder, the
  coordinate system of the robot (which is at the end of the quill)
  must be in the same location (point and axes) as the coordinate
  system of the end effector.
- When an end effector is attached to the robot, the Z component of the
  the Z axis of the end effector coordinate system must be negative in
  workstation coordinates (positive in robot coordinates). This allows
  the end effector to turn so that it is not vertical, but the end
  effector must always point somewhat down.

*/

#include <stdlib.h>         // exit
#include <stdio.h>          // fgets
#include <map>              // map
#include <list>             // list
#include <string.h>         // strncmp
#include <ctype.h>          // isalpha
#include <math.h>           // sqrt
#include <string>
#include "kittingViewer.hh"
#include "kittingClassesView.hh"
#include "view.hh"
#include "canonicalMsg.hh"
#include "commandParser.hh"
#include "scoreKittingClasses.hh"

#define STR_LENGTH 200
#define max(x,y) (((y) > (x)) ? (y) : (x))
#define TINYVAL 0.0001
// TINYVAL is for checking components of unit vectors
#define TINYDISTANCE 0.2
// TINYDISTANCE is two tenths of a millimeter

/********************************************************************/

// KittingViewer static variables

int                 KittingViewer::actionCommandsExecuted; // action cmds exec'd
double              KittingViewer::angleFactor; // factor for angle conversion
char                KittingViewer::angleUnits[TEXTSIZE]; // degree, radian
std::list<CanonicalMsg *> KittingViewer::commands;  // commands
int                 KittingViewer::commandSequenceErrors; // num sequence errors
char                KittingViewer::commandString[MAXPOSES][TEXTSIZE]; //cmd str
double              KittingViewer::distanceTotal; // total distance moved
double              KittingViewer::distances[MAXPOSES];// array of distances
double              KittingViewer::distancesX[MAXPOSES];// array of X distances
double              KittingViewer::distancesY[MAXPOSES];// array of Y distances
double              KittingViewer::distancesZ[MAXPOSES];// array of Z distances
bool                KittingViewer::executeFlag; // true = execute next command
int                 KittingViewer::executionState; // unready, ready, or ended
double              KittingViewer::fraction;  // proportion of motion done
KittingWorkstationType * KittingViewer::goalModel; // model built from goal file
int                 KittingViewer::gripperUseErrors; // num gripper use errors
double              KittingViewer::lengthFactor; // factor for length conversion
char                KittingViewer::lengthUnits[TEXTSIZE]; // meter, millim, inch
KittingWorkstationType * KittingViewer::nowModel; //model from init file updated
double              KittingViewer::nowX;   // controlled point X position now
double              KittingViewer::nowXAxisI; // X component of cntrld pt X axis
double              KittingViewer::nowXAxisJ; // Y component of cntrld pt X axis
double              KittingViewer::nowXAxisK; // Z component of cntrld pt X axis
double              KittingViewer::nowY;   // controlled point Y position now
double              KittingViewer::nowZ;   // controlled point Z position now
double              KittingViewer::nowZAxisI; // X component of cntrld pt Z axis
double              KittingViewer::nowZAxisJ; // Y component of cntrld pt Z axis
double              KittingViewer::nowZAxisK; // Z component of cntrld pt Z axis
int                 KittingViewer::otherCommandsExecuted; // other cmds executed
int                 KittingViewer::parseErrors; // number errors in parsing file
int                 KittingViewer::locationErrors; //number errors in obj loc'n
int                 KittingViewer::locationGoods; // number objs in right loc'n
int                 KittingViewer::poseIndex; // index of poses and times arrays
Pose                KittingViewer::poses[MAXPOSES];// array of poses to move to
int                 KittingViewer::posesTotal; // total number poses to move to
int                 KittingViewer::rangeErrors; // total out-of-range errors
bool                KittingViewer::resetFlag; // true = execute next command
double              KittingViewer::robotAccel; // acceleration setting
double              KittingViewer::robotAngleFactor; // factor for angle conver
char                KittingViewer::robotAngleUnits[TEXTSIZE]; // degree, radian
double              KittingViewer::robotEndAngleTol; // end angle tolerance
double              KittingViewer::robotEndPointTol; // end point tolerance
bool                KittingViewer::robotGripperOpen; // true=open, false=closed
double              KittingViewer::robotIntPointTol; // intermediate point tol
double              KittingViewer::robotLengthFactor; // factor 4 length conver
char                KittingViewer::robotLengthUnits[TEXTSIZE]; // m, mm, inch
double              KittingViewer::robotMaxAccel; // maximum robot acceleration
double              KittingViewer::robotMaxSpeed; // maximum robot speed
double              KittingViewer::robotRelAccel; // relative acceleration
double              KittingViewer::robotRelSpeed; // relative speed setting
double              KittingViewer::robotSpeed;  // speed set in length units/sec
bool                KittingViewer::robotToolChangerOpen; // true=open, false=clo
float               KittingViewer::scale;     // scale to use to convert mm
double              KittingViewer::score;     // score for the command file
char                KittingViewer::scoringFileName[TEXTSIZE];//name scoring file
float               KittingViewer::spacing;   // grid line spacing in meters
double              KittingViewer::times[MAXPOSES]; // times corresp. to poses
int                 KittingViewer::toolChangeErrors; // total tool change errors
double              KittingViewer::totalExecutionTime; // total execution time
double              KittingViewer::totalGoalDistance; // total goal object dist
int                 KittingViewer::uselessCommands; // numbr cmds with no effect
double              KittingViewer::weightFactor; // factor for weight conversion
char                KittingViewer::weightUnits[TEXTSIZE]; // gram, pound, etc.

/********************************************************************/

extern KittingWorkstationFile * KittingWorkstationTree;
extern ScoreKittingFile * scoreKittingTree; 
extern FILE * yyin;
extern FILE * yyscin;
extern int yyparse();
extern int yyscparse();

/********************************************************************/

/* KittingViewer::adjustKitLocation

Returned Value: none

Called By: KittingViewer::releaseObject

Let R be a short name for the refSolid and let parent be the refThing of R.

If R is a LargeContainer
1. If parent is a LargeBoxWithKits,
   Then, make the refThing (and the refObject) of the kit be parent rather
   than R, since that is convention for Kits in a LargeBoxWithKits.
2. [not implemented] Otherwise, if there is a LargeBoxWithKits L in the
   goalModel that has a LargeContainer with the same name as R:
2a. Create a LargeBoxWithKits with the same name as L in the nowModel,
2b. Put the LargeBoxWithKits where R is.
2c. Put R in the LargeBoxWithKits.
2d. Do the same things as in 1.  

*/

void KittingViewer::adjustKitLocation( /*  ARGUMENTS                     */
 KitType * kit,                        /* kit that might change location */
 SolidObjectType * refSolid,           /* thing on which kit was placed  */
 PoseLocationType * kitPrimaryPose)    /* primary pose of kit            */
 {
   SolidObjectType * parent;    // new refThing for kit

   parent = refSolid->refThing;
   if (dynamic_cast<LargeContainerType *>(refSolid))
     {
       if (dynamic_cast<LargeBoxWithKitsType *>(parent))
	 {
	   refSolid->refFor.remove(kit);
	   parent->refFor.push_back(kit);
	   kit->refThing = parent;
	   kitPrimaryPose->RefObject->val = parent->Name->val;
	 }
       else
	 {
	   
	 }
     }
 }

/********************************************************************/

/* KittingViewer::adjustPartLocation

Returned Value: none

Called By: KittingViewer::releaseObject

Let R be a short name for the refSolid and let parent be the refThing of R.

A. If R is a PartsTray
A1. If parent is a PartsTrayWithParts,
   Then, make the refThing (and the refObject) of the part be parent rather
   than R, since that is convention for Parts in a PartsTrayWithParts.
A2. [not implemented] Otherwise, if there is a PartsTrayWithParts in the
   goalModel that has a PartsTray with the same name as R:
A2a. Create a PartsTrayWithParts with that name in the nowModel,
A2b. Put the PartsTrayWithParts where R is.
A2c. Put R in the PartsTrayWithParts.
A2d. Do the same things as in A1.  

B. Otherwise, if R is a KitTray
B1. If parent is a Kit,
   Then, make the refThing (and the refObject) of the part be parent rather
   than R, since that is convention for Parts in Kits.
B2. Otherwise, call createKit to possibly create a kit consisting of the
   part and the KitTray, with all locations adjusted correctly.

*/

void KittingViewer::adjustPartLocation( /*  ARGUMENTS                      */
 PartType * part,                       /* part that might change location */
 SolidObjectType * refSolid,            /* thing on which part was placed  */
 PoseLocationType * partPrimaryPose)    /* primary pose of part            */
 {
   SolidObjectType * parent;    // new refThing for part

   parent = refSolid->refThing;
   if (dynamic_cast<PartsTrayType *>(refSolid))
     {
       if (dynamic_cast<PartsTrayWithPartsType *>(parent))
	 {
	   refSolid->refFor.remove(part);
	   parent->refFor.push_back(part);
	   part->refThing = parent;
	   partPrimaryPose->RefObject->val = parent->Name->val;
	 }
       else
	 {
	   
	 }
     }
   else if (dynamic_cast<KitTrayType *>(refSolid))
     {
       if (dynamic_cast<KitType *>(parent))
	 {
	   refSolid->refFor.remove(part);
	   parent->refFor.push_back(part);
	   part->refThing = parent;
	   partPrimaryPose->RefObject->val = parent->Name->val;
	 }
       else
	 {
	   createKit(part, dynamic_cast<KitTrayType *>(refSolid), parent);
	 }
     }
 }

/********************************************************************/

/* KittingViewer::checkLocation

Returned Value: none

Called By: KittingViewer::handleExecute

The goalObject here is a solid object from the goalModel. If the
goalObject is a part, a parts tray, a kit, a kit tray, or a large container
(the movable objects that should not disappear), its location is
compared with that of the object of the same name (nowObject) in the
nowModel. If there is no nowObject, if the nowObject is a different
type from the goalObject, or if the nowObject is in a different location
from the goalObject, this increases locationErrors by 1. Otherwise,
it increases locationGoods by 1.

This is called only to check on goal objects. This is not checking for
objects in the current environment that are not goal objects.

*/

void KittingViewer::checkLocation( /* ARGUMENTS                             */
 SolidObjectType * goalObject)     /* goal object to compare with nowObject */
{
  SolidObjectType * nowObject;       // now object to compare with goalObject
  PoseLocationType * actualLocation;
  PoseLocationType * goalLocation;
  std::map<std::string, SolidObjectType *>::iterator iter;

  iter = nowModel->allSolids.find(goalObject->Name->val);
  if (iter == nowModel->allSolids.end())
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: goal object %s is missing from current environment",
	       goalObject->Name->val.c_str());
      locationErrors++;
      return;
    }
  nowObject = iter->second;
  if (dynamic_cast<PartType *>(goalObject))
    {
      if (dynamic_cast<PartType *>(nowObject) == 0)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: goal object %s is a part but "
		   "current object %s is not", goalObject->Name->val.c_str(),
		   goalObject->Name->val.c_str());
	  locationErrors++;
	  return;
	}
    }
  else if (dynamic_cast<KitType *>(goalObject))
    {
      if (dynamic_cast<KitType *>(nowObject) == 0)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: goal object %s is a kit but "
		   "current object %s is not", goalObject->Name->val.c_str(),
		   goalObject->Name->val.c_str());
	  locationErrors++;
	  return;
	}
    }
  else if (dynamic_cast<KitTrayType *>(goalObject))
    {
      if (dynamic_cast<KitTrayType *>(nowObject) == 0)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: goal object %s is a kit tray but "
		   "current object %s is not", goalObject->Name->val.c_str(),
		   goalObject->Name->val.c_str());
	  locationErrors++;
	  return;
	}
    }
  else if (dynamic_cast<PartsTrayType *>(goalObject))
    {
      if (dynamic_cast<PartsTrayType *>(nowObject) == 0)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: goal object %s is a parts tray but "
		   "current object %s is not", goalObject->Name->val.c_str(),
		   goalObject->Name->val.c_str());
	  locationErrors++;
	  return;      
	}
    }
  else if (dynamic_cast<PartsTrayWithPartsType *>(goalObject))
    {
      if (dynamic_cast<PartsTrayWithPartsType *>(nowObject) == 0)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: goal object %s is a parts tray with parts but "
		   "current object %s is not", goalObject->Name->val.c_str(),
		   goalObject->Name->val.c_str());
	  locationErrors++;
	  return;      
	}
    }
  else if (dynamic_cast<LargeBoxWithKitsType *>(goalObject))
    {
      if (dynamic_cast<LargeBoxWithKitsType *>(nowObject) == 0)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: goal object %s is a large box with kits but "
		   "current object %s is not", goalObject->Name->val.c_str(),
		   goalObject->Name->val.c_str());
	  locationErrors++;
	  return;
	}
    }
  else if (dynamic_cast<LargeBoxWithEmptyKitTraysType *>(goalObject))
    {
      if (dynamic_cast<LargeBoxWithEmptyKitTraysType *>(nowObject) == 0)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: goal object %s is a large box with empty kit "
		   "trays but current object %s is not",
		   goalObject->Name->val.c_str(),
		   goalObject->Name->val.c_str());
	  locationErrors++;
	  return;
	}
    }
  else if (dynamic_cast<LargeContainerType *>(goalObject))
    {
      if (dynamic_cast<LargeContainerType *>(nowObject) == 0)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: goal object %s is a large container but "
		   "current object %s is not", goalObject->Name->val.c_str(),
		   goalObject->Name->val.c_str());
	  locationErrors++;
	  return;
	}
    }
  else
    return;
  goalLocation = findPrimaryPose(goalObject);
  actualLocation = findPrimaryPose(nowObject);
  if (goalLocation->RefObject->val != actualLocation->RefObject->val)
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: refObject %s of goal object %s differs from "
	       "refObject %s of current object %s",
	       goalLocation->RefObject->val.c_str(),
	       goalObject->Name->val.c_str(),
	       actualLocation->RefObject->val.c_str(),
	       goalObject->Name->val.c_str());
      locationErrors++;
      return;
    }
  if (checkPointAndAxes(goalLocation->Point, actualLocation->Point,
			goalLocation->XAxis, actualLocation->XAxis,
			goalLocation->ZAxis, actualLocation->ZAxis,
			goalObject->Name->val.c_str()))
    {
      snprintf(commandString[0], TEXTSIZE, "%s is located correctly",
	       goalObject->Name->val.c_str());
      locationGoods++;
    }
}

/********************************************************************/

/* KittingViewer::checkPointAndAxes

Returned Value: bool
  If the point and axis values of the goal and actual objects are very
  nearly equal, this returns true. Otherwise, it returns false.

Called By:  KittingViewer::checkLocation

*/

bool KittingViewer::checkPointAndAxes( /*  ARGUMENTS                      */
 PointType * goalPoint,                /* goal Point of object location   */
 PointType * actualPoint,              /* actual Point of object location */
 VectorType * goalXAxis,               /* goal XAxis of object location   */
 VectorType * actualXAxis,             /* actual XAxis of object location */
 VectorType * goalZAxis,               /* goal ZAxis of object location   */
 VectorType * actualZAxis,             /* actual ZAxis of object location */
 const char * name)                    /* name of object                  */
{
  if ((fabs(actualPoint->X->val - goalPoint->X->val) > TINYDISTANCE) ||
      (fabs(actualPoint->Y->val - goalPoint->Y->val) > TINYDISTANCE) ||
      (fabs(actualPoint->Z->val - goalPoint->Z->val) > TINYDISTANCE))
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: goal location Point (%.6f,%.6f,%.6f) of %s "
	       "differs from current location Point (%.6f,%.6f,%.6f)",
	       goalPoint->X->val, goalPoint->Y->val, goalPoint->Z->val, name,
	       actualPoint->X->val, actualPoint->Y->val, actualPoint->Z->val);
      locationErrors++;
      return false;
    }
  if ((fabs(actualXAxis->I->val - goalXAxis->I->val) > TINYVAL) ||
      (fabs(actualXAxis->J->val - goalXAxis->J->val) > TINYVAL) ||
      (fabs(actualXAxis->K->val - goalXAxis->K->val) > TINYVAL))
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: goal location XAxis (%.6f,%.6f,%.6f) of %s "
	       "differs from current location XAxis (%.6f,%.6f,%.6f)",
	       goalXAxis->I->val, goalXAxis->J->val, goalXAxis->K->val, name,
	       actualXAxis->I->val, actualXAxis->J->val, actualXAxis->K->val);
      locationErrors++;
      return false;
    }
  if ((fabs(actualZAxis->I->val - goalZAxis->I->val) > TINYVAL) ||
      (fabs(actualZAxis->J->val - goalZAxis->J->val) > TINYVAL) ||
      (fabs(actualZAxis->K->val - goalZAxis->K->val) > TINYVAL))
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: goal location ZAxis (%.6f,%.6f,%.6f) of %s "
	       "differs from current location ZAxis (%.6f,%.6f,%.6f)",
	       goalZAxis->I->val, goalZAxis->J->val, goalZAxis->K->val, name,
	       actualZAxis->I->val, actualZAxis->J->val, actualZAxis->K->val);
      locationErrors++;
      return false;
    }
  return true;
}

/********************************************************************/

/* KittingViewer::clearLists

Returned Value: none

Called By: KittingViewer::init

This empties all the lists of items that are built during parsing.
These lists are static class attributes. This function is called
immediately before parsing the init file and immediately before
parsing the goal file. The lists are copied and saved in the
constructor for KittingWorkstationType (which is the last function
that runs before parsing is finished).

*/

void KittingViewer::clearLists() /* NO ARGUMENTS */
{
  BoxyShapeType::allBoxys.clear();
  XmlID::allIDs.clear();
  XmlIDREF::allIDREFs.clear();
  KitType::allKits.clear();
  VacuumEffectorMultiCupType::allMulti.clear();
  PointType::allPoints.clear();
  VacuumEffectorSingleCupType::allSingle.clear();
  StockKeepingUnitType::allSkus.clear();
  SolidObjectType::objectMap.clear();
}

/********************************************************************/

/* KittingViewer::computeScore

Returned Value: none

Called By: KittingViewer::handleExecute

This is called after all commands have been executed, and is only
called if a movable goal object is being processed by handleExecute.

This is called only after all commands have been executed since the
values for rightStuff, distance, and time are computed using the goal
state, and comparisons using the goal state do not make much sense
until all commands are executed. It also would not make much sense to
compute values for those factors before the goal state is reached. The
computations might be done after each command using only the
commandExecution and uselessCommands values, but that would be
confusing because the score would jump to a very different value when
the other three factors come into play.

After all commands have been executed, the commandExecution and
uselessCommands commands values are fixed, but the rightStuff,
distance, and time change each time another object in the goal state
is checked. That happens each time the g key is pressed until all
objects in the goal state have been checked. Showing the current score
after each object has been checked makes the display more interesting.

This finds the score for a command file using the scoring configuration
read from the scoring file.

It uses the following five data factors to compute the score.

Factor Name           Factor Value
-----------           ------------
rightStuff            rightStuffValue (local variable computed here)
commandExecution      commandExecutionValue (local variable computed here)
distance              distanceValue (local variable computed here)
time                  timeValue  (local variable computed here)
uselessCommands       KittingViewer::uselessCommands


Each factor is designated as additive or multiplicative. A factor
value Vi between 0 and 1 is found for each additive factor and a
factor value Ui between 0 and 1 is found for each multiplicative
factor. Each additive factor is assigned a non-negative weight Wi. An
additive score Sa is produced by multiplying each additive value by
its weight, adding the products together, and dividing by the sum of the
weights. If there are no additive factors or their weights are all
zero, Sa = 1.

Sa = (((V1 x W1) + (V2 x W2) ... + (Vn x Wn)) / (W1 + W2 + ... + Wn))

The value of Sa will be between 0 and 1 since all the components of the
equation are positive and the largest the numerator can be is the size
of the denominator.

Then the total score S is found by finding the product of Sa, 100, and
all the multiplicative factors.

S = (100 x Sa x U1 x U2 ... x Um)

In the code below "score" serves for both Sa and S.

Each Vi or Ui factor may be converted to a value between 0 and 1 by
a value function before being used as described above. See documentation
of the valuate function.

In the descriptions that follow, a basic object is a movable object
that is not a composite object and is not the robot. Gripper, Part,
PartTray, KitTray, and LargeContainer are basic. Kit, LargeBoxWithKits,
LargeBoxWithEmptyKitTrays, and PartsTrayWithParts are not basic.

The rightStuffValue is [(the number of objects in the goal file placed
correctly so far) minus (the number of objects in the goal file placed
incorrectly so far)] divided by [the number of objects in the goal
file checked so far]. If that is less than zero, it is set to zero. 

The commandExecutionValue is the fraction of all commands in the
command file that were executed correctly. That is [(the total number
of commands executed successfully) divided by (the total number of
commands executed successfully plus all errors except location errors)].

The distanceValue is [(two times the total distance moved from initial
position to goal position by all basic goal objects that have been
checked so far) divided by (the total distance moved by the robot
times the fraction of movable objects that have been checked)].
If the calculated distanceValue is greater than 1, it is set to 1. The
calculated total distance is a crude measure of a short distance to
move the robot in order to change the initial state to the goal state.
The "two times" is used because the robot will need to move while not
holding anything about as much as it will need to move while holding
something. The calculated total distance underestimates the a lower
bound on the minimum required distance by (1) using straight lines and
(2) ignoring the need to use the work table. It overestimates the
minimum required distance by ignoring the fact that several objects
may be moved simultaneously when parts are in kit trays or parts trays.

The timeValue is [(the teleport time) divided by (the total execution
time multiplied by the fraction of movable objects that have been
checked)]. If the calculated timeValue is greater than 1, it is set to
1. The teleport time is [(two times the total distance moved from initial
position to goal position by all basic goal objects that have been
checked so far) divided by (the robot maximum speed)]. The teleport
time is a crude measure of a fast time for changing the initial state
to the goal state. It underestimates the time by (1) using straight
lines, (2) using robot maximum speed, and (3) ignoring the need to use
the work table. It overestimates the time by ignoring the fact that
several objects may be moved simultaneously when parts are in kits or
kit trays.

This checks that at least one weight in the scoring system is non-zero.
It prints an error message and exits if that is not the case.

This function is "used up" when the kittingViewer is done because
n increases to the total number of movable objects.

It has been checked that there is at least one positive weight before
this is called.

*/

void KittingViewer::computeScore( /* ARGUMENTS               */
 SolidObjectType * object)        /* the next movable object */
{
  double rightStuffValue;       // value to be input to rightStuff
  double commandExecutionValue; // value to be input to commandExecution
  double distanceValue;         // value to be input to distance
  double timeValue;             // value to be input to time
  scoreKittingType * scorer;    // scoring method
  int weight;                   // the weight of a factor
  unsigned totalWeight = 0;     // sum of weights for additive factors
  valueFunctionType * fun;      // a value function
  double fraction;              // fraction of movable objects checked
  static int movableObjects;    // total number of movable objects
  static int n = 0;             // number of times this is called

  if (n == 0)
    movableObjects = countMovableObjects();
  n++;
  score = 0; // score is a kittingViewer attribute
  scorer = scoreKittingTree->scoreKitting;
  rightStuffValue = ((double)(locationGoods - locationErrors) /
		     (double)(locationGoods + locationErrors));
  if (rightStuffValue < 0.0)
    rightStuffValue = 0.0;
  commandExecutionValue =
    ((double)(actionCommandsExecuted + otherCommandsExecuted) /
     (double)(actionCommandsExecuted + otherCommandsExecuted + 
	      rangeErrors + commandSequenceErrors + gripperUseErrors + 
	      parseErrors + toolChangeErrors));
  totalGoalDistance += findDistance(object);
  fraction = ((double)n / (double)movableObjects);
  distanceValue = ((2.0 * totalGoalDistance) / (distanceTotal * fraction));
  distanceValue = ((distanceValue > 1.0) ? 1.0 : distanceValue);
  timeValue = (((2.0 * totalGoalDistance) / robotMaxSpeed) /
	       (totalExecutionTime * fraction));
  timeValue = ((timeValue > 1.0) ? 1.0 : timeValue);
  weight = scorer->rightStuff->weight->val;
  if (weight && scorer->rightStuff->isAdditive->val)
    {
      totalWeight += weight;
      if ((fun = scorer->rightStuff->valueFunction))
	score += (weight * valuate(fun, rightStuffValue));
      else
	score += (weight * rightStuffValue);
    }
  weight = scorer->commandExecution->weight->val;
  if (weight && scorer->commandExecution->isAdditive->val)
    {
      totalWeight += weight;
      if ((fun = scorer->commandExecution->valueFunction))
	score += (weight * valuate(fun, commandExecutionValue));
      else
	score += (weight * commandExecutionValue);
    }
  weight = scorer->distance->weight->val;
  if (weight && scorer->distance->isAdditive->val)
    {
      totalWeight += weight;
      if ((fun = scorer->distance->valueFunction))
	score += (weight * valuate(fun, distanceValue));
      else
	score += (weight * distanceValue);
    }
  weight = scorer->time->weight->val;
  if (weight && scorer->time->isAdditive->val)
    {
      totalWeight += weight;
      if ((fun = scorer->time->valueFunction))
	score += (weight * valuate(fun, timeValue));
      else
	score += (weight * timeValue);
    }
  weight = scorer->uselessCommands->weight->val;
  if (weight && scorer->uselessCommands->isAdditive->val)
    {
      totalWeight += weight;
      if ((fun = scorer->uselessCommands->valueFunction))
	score += (weight * valuate(fun, uselessCommands));
      else
	score += (weight * uselessCommands);
    }
  if (totalWeight)
    score /= totalWeight;
  else
    score = 1.0;
  score *= 100.0;

  if ((scorer->rightStuff->weight->val) &&
      (!(scorer->rightStuff->isAdditive->val)))
    {
      if ((fun = scorer->rightStuff->valueFunction))
	score *= valuate(fun, rightStuffValue);
      else
	score *= rightStuffValue;
    }
  if ((scorer->commandExecution->weight->val) &&
      (!(scorer->commandExecution->isAdditive->val)))
    {
      if ((fun = scorer->commandExecution->valueFunction))
	score *= valuate(fun, commandExecutionValue);
      else
	score *= commandExecutionValue;
    }
  if ((scorer->distance->weight->val) &&
      (!(scorer->distance->isAdditive->val)))
    {
      if ((fun = scorer->distance->valueFunction))
	score *= valuate(fun, distanceValue);
      else
	score *= distanceValue;
    }
  if ((scorer->time->weight->val) &&
      (!(scorer->time->isAdditive->val)))
    {
      if ((fun = scorer->time->valueFunction))
	score *= valuate(fun, timeValue);
      else
	score *= timeValue;
    }
  if ((scorer->uselessCommands->weight->val) &&
      (!(scorer->uselessCommands->isAdditive->val)))
    {
      if ((fun = scorer->uselessCommands->valueFunction))
	score *= valuate(fun, uselessCommands);
      else
	score *= uselessCommands;
    }
}

/********************************************************************/

/* KittingViewer::countMovableObjects

Returned Value: int

Called By:  KittingViewer::computeScore

This counts and returns the number of movable objects in the kitting
workstation. Grippers are not included.

*/

int KittingViewer::countMovableObjects() /* NO ARGUMENTS */ 
{
  static std::map<std::string, SolidObjectType *>::iterator iter;
  int total = 0;

  for (iter = goalModel->allSolids.begin();
       iter != goalModel->allSolids.end(); iter++)
    if (solidIsMovable(iter->second))
      total++;
  return total;
}

/********************************************************************/

/* KittingViewer::createKit

Returned Value: none

Called By: KittingViewer::adjustPartLocation

The part has just been placed in the tray in the now model, and the
tray is not yet a constituent of a kit. If there is a Kit in the
goalModel that has a KitTray with the same name as the tray, then:
 - create a kit of that name in the now model
 - put the kit where the tray is
 - change the part location to be relative to the kit
 - change the tray location to be relative to the kit

*/

void KittingViewer::createKit( /* ARGUMENTS                   */
 PartType * part,              /* part to be put into new kit */
 KitTrayType * tray,           /* tray to be put into new kit */
 SolidObjectType * parent)     /* refThing for new kit        */
{
  PoseLocationType * partPrimaryPose; // primary pose of part
  PoseLocationType * trayPrimaryPose; // primary pose of tray
  KitType * kitWithTray;              // goal kit containing same-name tray
  KitType * newKit;                   // new kit
  PoseLocationType * newPose;         // new pose for new kit

  kitWithTray = findKitWithTray(tray->Name->val, &(goalModel->allKits));
  if (kitWithTray == 0)
    return;
  partPrimaryPose = findPrimaryPose(part);
  trayPrimaryPose = findPrimaryPose(tray);
  newPose = new PoseLocationType();
  newPose->Name =
    new XmlID((char *)kitWithTray->PrimaryLocation->Name->val.c_str());
  newPose->RefObject = new XmlIDREF((char *)parent->Name->val.c_str());
  putInOtherPosition(newPose, trayPrimaryPose);
  newKit =
    new KitType(new XmlID((char *)kitWithTray->Name->val.c_str()),
		newPose, new std::list<PhysicalLocationType *>, 0, 0,
		new XmlIDREF((char *)kitWithTray->DesignName->val.c_str()),
		tray, new std::list<PartType *>, 
		new XmlBoolean((char *)"false"));
  newKit->refThing = parent;
  newKit->refFor.push_back(part);
  newKit->refFor.push_back(tray);
  setWorkstationLocation(newKit);
  nowModel->allKits.push_back(newKit);
  nowModel->allSolids.insert
    (std::pair<std::string, SolidObjectType *>(newKit->Name->val, newKit));
  trayPrimaryPose->RefObject->val = newKit->Name->val;
  putInDefaultPosition(trayPrimaryPose);
  tray->refThing = newKit;
  tray->refFor.remove(part);
  part->refThing = newKit;
  partPrimaryPose->RefObject->val = newKit->Name->val;
  parent->refFor.push_back(newKit);
  parent->refFor.remove(tray);
}

/********************************************************************/

/* KittingViewer::drawBoxyShape

Returned Value: none

Called By: KittingViewer::drawSolidObject

A boxy shape has its location point in the middle of the bottom.

*/

void KittingViewer::drawBoxyShape( /* ARGUMENTS                         */
 BoxyShapeType * boxy,             /* boxy shape to draw                */
 col color,                        /* color to draw with                */
 PoseLocationType * pose)          /* pose of boxy shape in workstation */
{
  insertBoxTransformed(color,
	    pose->Point->X->val, pose->Point->Y->val, pose->Point->Z->val,
	    boxy->Length->val, boxy->Width->val, boxy->Height->val,
	    pose->XAxis->I->val, pose->XAxis->J->val, pose->XAxis->K->val,
	    pose->ZAxis->I->val, pose->ZAxis->J->val, pose->ZAxis->K->val,
	    boxy->HasTop->val, true);
}

/********************************************************************/

/* KittingViewer::drawChangingStation

Returned Value: none

Called By:  KittingViewer::drawWorkstation

This is drawing the base and end effector holders of the changing station.

*/

void KittingViewer::drawChangingStation(   /* ARGUMENTS                */
 EndEffectorChangingStationType * station) /* changing station to draw */
{
  std::list<EndEffectorHolderType *>::iterator iter;

  station->Base->color = station->color;
  drawSolidObject(station->Base);
  for (iter = station->EndEffectorHolders->begin();
       iter != station->EndEffectorHolders->end(); iter++)
    drawSolidObject(*iter);
}

/********************************************************************/

/* KittingViewer::drawRobot

Returned Value: none

Called By:  KittingViewer::drawWorkstation

This draws the robot in the kitting workstation. The robot is shown as
a gantry robot with its vertical supports at the sides of the
workstation. The crossbar goes between the tops of the sides. The
quill hangs down from the crossbar. The length of the quill is the
height of the robot.

When the robot does not have a gripper mounted on the quill, the Z
axis of the robot is the axis of the quill, pointing away from the
quill at the bottom end, and the controlled point is on the Z axis
at the end of the quill. When a gripper is mounted on the quill, it is
considered to be part of the robot, so that the controlled point is on
the Z axis at the end of the gripper, and the Z axis of the gripper is
the Z axis of the robot.

In drawing a single cup vacuum effector, the cup is shown as an
annulus whose inner radius is a quarter the radius of the cup. The
body of the effector is a cone truncated at the cup end. The radius at
the top end of the cone is the radius of the cup. The small end of the
truncated cone is attached to the inside of the annulus. The Z axis of
the effector is the axis of the cone pointing away from the effector
at the cup end.

The origin of the coordinate system of the gripper is on the axis at the
large end of the cone.

The axis of the quill is vertical at all times. Might add a check that
the Z axis of the robot is vertical when no gripper is mounted.

*/

void KittingViewer::drawRobot() /* NO ARGUMENTS */
{
  static double wide2 = 200.0; // half the width of a robot component
  static double thick = 100.0; // thickness of a robot component
  static double thick2 = 50.0; // half of the thickness of a robot component
  static double thick4 = 25.0; // quarter of the thickness of a robot component
  static double robotHeight = 3000.0; // height of the robot (max z)
  RobotType * robot;
  PoseLocationType * robotPose;
  double robotX;
  double robotY;
  double robotZ;

  robot = nowModel->Robot;
  robotPose = findPrimaryPose(robot);
  robotX = robotPose->Point->X->val;
  robotY = robotPose->Point->Y->val;
  robotZ = robotPose->Point->Z->val;
  // gantry crossbar
  insertBox(robot->color, 0, (robotY - thick2), (robotHeight - thick2),
            WORKSTATIONLENGTH, (robotY + thick2), (robotHeight + thick2),
	    true);
  // gantry -X side support
  insertBox(robot->color, 0, (robotY - wide2), 0,
            thick, (robotY + wide2), (robotHeight + thick2), true);
  // gantry +X side support
  insertBox(robot->color, (WORKSTATIONLENGTH - thick), (robotY - wide2), 0,
            WORKSTATIONLENGTH, (robotY + wide2), (robotHeight + thick2),
	    true);
  // draw quill with no effector
  insertBox(robot->color, (robotX - thick4), (robotY - thick4), robotZ,
	    (robotX + thick4), (robotY + thick4), (robotZ + robotHeight), true);
}

/********************************************************************/

/* KittingViewer::drawSingleCupGripper

Returned Value: none

Called By: KittingViewer::drawVacuumGripper

This draws a single cup Gripper as a truncated cone closed at the
large end (which attaches to the robot's end effector holder) with an
annulus representing the vacuum cup at the small end. The radius of
the large end of the cone is the cup radius. The radius of the small
end of the cone is 1/4 of the cup radius. The inner radius of the
annulus is also 1/4 cup radius.

*/

void KittingViewer::drawSingleCupGripper(/* ARGUMENTS */
 col color,        /* color of gripper                */
 double x,         /* X coordinate of center of base  */
 double y,         /* Y coordinate of center of base  */
 double z,         /* Z coordinate of center of base  */
 double cupRadius, /* radius of gripper cup           */
 double length,    /* length of gripper               */
 double xI,        /* I component of gripper X axis   */
 double xJ,        /* J component of gripper X axis   */
 double xK,        /* K component of gripper X axis   */
 double zI,        /* I component of gripper Z axis   */
 double zJ,        /* J component of gripper Z axis   */
 double zK)        /* K component of gripper Z axis   */
{
  insertDiskTransformed(color, x, y, z, cupRadius, xI, xJ, xK, zI, zJ, zK);
  insertConeTransformed(color, x, y, z, cupRadius, (cupRadius / 4.0),
			length, xI, xJ, xK, zI, zJ, zK);
  insertConeTransformed(color, (x + (length * zI)), (y + (length * zJ)),
			(z + (length * zK)), cupRadius, (cupRadius / 4.0),
			0.0, xI, xJ, xK, zI, zJ, zK);
}

/********************************************************************/

/* KittingViewer::drawSolidObject

Returned Value: none

Called By:
  KittingViewer::drawChangingStation
  KittingViewer::drawSolidObject (recursively)
  KittingViewer::drawWorkstation

This draws any solid objects whose location is relative to the given
solid object (and any solid objects relative to them, etc.). Then it
draws the given solid object. In other words, it works its way depth
first down the relative location hierarchy of solid objects. Drawing
order is not significant. The picture looks the same regardless of the
order in which objects are drawn.

*/

void KittingViewer::drawSolidObject(/* ARGUMENTS            */
 SolidObjectType * object)          /* solid object to draw */
{
  PoseLocationType * pose;    // pose of object in workstation
  BoxyShapeType * boxy;       // shape to draw if object shape is boxy
  std::list<SolidObjectType *>::iterator iter;

  for (iter = object->refFor.begin(); iter != object->refFor.end(); iter++)
    drawSolidObject(*iter);
  pose = findSecondaryPose(object);
  if (dynamic_cast<RobotType *>(object))
    drawRobot();
  else if (dynamic_cast<KitTrayType *>(object)        ||
	   dynamic_cast<LargeContainerType *>(object) ||
	   dynamic_cast<PartsTrayType *>(object)      ||
	   dynamic_cast<PartType *>(object))
    {
      if ((boxy = dynamic_cast<BoxyShapeType *>(object->sku->Shape)))
	drawBoxyShape(boxy, object->sku->color, pose);
    }
  else if (object->InternalShape &&
	   dynamic_cast<BoxyShapeType *>(object->InternalShape))
    drawBoxyShape(dynamic_cast<BoxyShapeType *>(object->InternalShape),
		  object->color, pose);
  else if (dynamic_cast<EndEffectorChangingStationType *>(object))
    drawChangingStation(dynamic_cast<EndEffectorChangingStationType *>(object));
  else if (dynamic_cast<VacuumEffectorType *>(object))
    drawVacuumGripper(dynamic_cast<VacuumEffectorType *>(object), pose);
}

/********************************************************************/

/* KittingViewer::drawString

Returned Value: none

Called By: KittingViewer::printMetricsAndSettings

This prints one line of text starting at the given (x,y) location (in
currently active screen coordinates). The text is printed left to right
in the normal fashion for the English language.

The font argument is actually a symbol such as GLUT_BITMAP_HELVETICA_10.

*/

void KittingViewer::drawString(/* ARGUMENTS                   */
 float x,                      /* X location of start of text */
 float y,                      /* Y location of start of text */
 void * font,                  /* the font to use             */
 char* string)                 /* the text to print           */
{
  char * c;

  glRasterPos2f(x, y);
  for (c = string; *c != '\0'; c++)
    {
      glutBitmapCharacter(font, *c);
    }
}

/********************************************************************/

/* KittingViewer::drawVacuumGripper

Returned Value: none

Called By:  KittingViewer::drawSolidObject

This draws a vacuum gripper in the kitting workstation.

Currently, only single cup vacuum grippers are being drawn.

*/

void KittingViewer::drawVacuumGripper( /*  ARGUMENTS                     */
 VacuumEffectorType * gripper,         /* vacuum gripper to draw         */
 PoseLocationType * pose)              /* pose of gripper in workstation */
{
  double cupRadius;
  VacuumEffectorSingleCupType * single;

  single = dynamic_cast<VacuumEffectorSingleCupType *>(gripper);
  if (single)
    {
      cupRadius = (single->CupDiameter->val / 2.0);
      drawSingleCupGripper(single->color, pose->Point->X->val,
			   pose->Point->Y->val, pose->Point->Z->val,
			   cupRadius, single->Length->val,
			   pose->XAxis->I->val, pose->XAxis->J->val,
			   pose->XAxis->K->val, pose->ZAxis->I->val,
			   pose->ZAxis->J->val, pose->ZAxis->K->val);
    }
}

/********************************************************************/

/* KittingViewer::drawWorkstation

Returned Value: none

Called By: KittingViewer::redraw

This:
1. Sets the pose point of the robot based on the current location of
   the controlled point (nowX, nowY, nowZ). If the robot is holding a
   gripper, the pose point of the robot is offset from the controlled point.
2. For each object in the refFor list of the robot, calls
   updateWorkstationPosition to update the secondary location.
   UpdateWorkstationPosition calls itself recursively, so that
   the secondary location is updated for any objects that will move
   if the robot moves. The secondary locations of any objects not in the
   hierarchy of objects that will move if the robot moves are fixed and do
   not need updating.
3. Calls drawSolidObject for each object (other than the workstation
   itself) in the refFors of the workstation. drawSolidObject calls
   itself recursively so that all objects in the workstation are drawn.

*/

void KittingViewer::drawWorkstation() /* NO ARGUMENTS */
{
  std::list<SolidObjectType *>::iterator iter;
  VacuumEffectorType * vacEffector;
  double length;
  PoseLocationType * pose;

  pose = findPrimaryPose(nowModel->Robot);
  if (nowModel->Robot->EndEffector)
    {
      vacEffector =
	dynamic_cast<VacuumEffectorType *>(nowModel->Robot->EndEffector);
      if (vacEffector)
	{
	  length = vacEffector->Length->val;
	  pose->Point->X->val = (nowX - (length * nowZAxisI));
	  pose->Point->Y->val = (nowY - (length * nowZAxisJ));
	  pose->Point->Z->val = (nowZ - (length * nowZAxisK));
	}
      else
	{
	  fprintf(stderr, "cannot handle non-vacuum end effector\n");
	  exit(1);
	}
    }
  else
    {
      pose->Point->X->val = nowX;
      pose->Point->Y->val = nowY;
      pose->Point->Z->val = nowZ;
    }
  for (iter = nowModel->Robot->refFor.begin();
       iter != nowModel->Robot->refFor.end(); iter++)
    updateWorkstationPosition(*iter, pose);
  for (iter = nowModel->refFor.begin(); iter != nowModel->refFor.end(); iter++)
    {
      if (*iter != nowModel)
	drawSolidObject(*iter);
    }
}

/********************************************************************/

/* KittingViewer::dwell

Returned Value: none

Called By: KittingViewer::executeDwellCommand

This does nothing for the given amount of time in seconds. It is not
efficient since it is wasting time rather than sleeping, but since it
uses glut, it is platform independent. Might replace it with platform
dependent sleep code inside #ifdefs (Sleep for Windows, usleep for
Linux and unix).

*/

void KittingViewer::dwell( /* ARGUMENTS                    */
 double seconds)           /* how long to dwell in seconds */
{
  int start;

  start = glutGet(GLUT_ELAPSED_TIME);
  while ((glutGet(GLUT_ELAPSED_TIME) - start) < (1000.0 * seconds));
}


/********************************************************************/

/* KittingViewer::enterPoseTarget

Returned Value: none

Called By:
  KittingViewer::executeMoveStraightToCommand
  KittingViewer::executeMoveToCommand

In order to make computations simpler, this is putting:
 - the current time into times[0]
 - the target finish time into times[1]
 - the current position into poses[0].origin
 - the target position into poses[1].origin

This is converting positions in the robot command to millimeters before
using the positions.

The call to checkYAxis normalizes the xAxis and zAxis vectors in the
Pose and checks that they are orthogonal.

FIX - see fixes in enterPoseTargets.

*/

void KittingViewer::enterPoseTarget( /* ARGUMENTS                   */
 Pose * pose)                        /* pose from the robot command */
{
  Point * point0;
  Point * point1;

  times[0] = (glutGet(GLUT_ELAPSED_TIME) / 1000.0);
  point0 = &(poses[0].origin);
  point0->x = nowX;
  point0->y = nowY;
  point0->z = nowZ;
  poses[1] = *pose;
  poses[1].checkYAxis();
  point1 = &(poses[1].origin);
  point1->x *= robotLengthFactor;
  point1->y *= robotLengthFactor;
  point1->z *= robotLengthFactor;
  posesTotal = 2;
  distancesX[1] = point1->x - nowX;
  distancesY[1] = point1->y - nowY;
  distancesZ[1] = point1->z - nowZ;
  distances[1] = hypot3(distancesX[1], distancesY[1], distancesZ[1]);
  if (robotSpeed == 0.0)
    {
      fprintf(stderr, "Warning: robot speed for move is zero\n");
      fprintf(stderr, "Time for move set to one minute\n");
      times[1] = (times[0] + 60.0);
    }
  else
    {
      times[1] = (times[0] + (distances[1] / robotSpeed));
    }
  poseIndex = 1;
}

/********************************************************************/

/* KittingViewer::enterPoseTargets

Returned Value: none

Called By: 
  MoveThroughToMsg::process (in viewerCanonicalMsg.cc)

This is converting positions in the robot command to millimeters before
using the positions.

The calls to checkYAxis normalize the xAxis and aAxis vectors of each
Pose and check that they are orthogonal.

To calculate the time required for a move from one pose to another
when there is an end effector on the robot, this calculates two
distances. The first is the distance moved by the quill between poses.
The second is the distance moved by the controlled point (at the tip
of the end effector). The larger of the two distances is used for
finding the time required for the move. Otherwise, if the same point
is used in two successive poses (with Z axis and/or X axis
motion), the time required will be zero, and calculations will fail.
Also if the points are only a tiny distance apart but the axis motion
is large, the speed of the end of the quill will be very large if only
the distance between controlled points is used.

FIX - Make the preceding paragraph be true.

FIX - Add a check that if there is no gripper, the Z axis of each pose
is 0,0,-1.

FIX - Try to handle "too many poses" some way other than exiting.

FIX - Try to handle zero speed as a range error. Zero speed is an error only
when trying to move.

FIX - Maybe add a check that no two successive poses are the same.
That would mess up the calculations. Or maybe change the logic to live
with that by throwing away all but one of any group of consecutive
identical poses.

*/

void KittingViewer::enterPoseTargets( /* ARGUMENTS                  */
 Pose ** posesIn,                     /* poses in command           */
 int num)                             /* number of poses in command */
{
  int n;
  Pose * poseA;    // previous pose
  Point * pointA;  // previous controlled point location
  Point * pointB;  // current controlled point location
  //Point * pointAQ; // previous quill location
  //Point * pointBQ; // current quill location

  if (num > MAXPOSES)
    {
      fprintf(stderr, "too many poses in command");
      exit(1);
    }
  times[0] = (glutGet(GLUT_ELAPSED_TIME) / 1000.0);
  //set poses[0] to the current location
  poseA = &(poses[0]);
  pointA = &(poseA->origin);
  pointA->x = nowX;
  pointA->y = nowY;
  pointA->z = nowZ;
  poseA->xAxis.i = nowXAxisI;
  poseA->xAxis.j = nowXAxisJ;
  poseA->xAxis.k = nowXAxisK;
  poseA->zAxis.i = nowZAxisI;
  poseA->zAxis.j = nowZAxisJ;
  poseA->zAxis.k = nowZAxisK;
  // copy each incoming pose into the poses array
  // and check each copy for Z axis orthogonal to X axis
  for (n = 1; n <= num; n++)
    {
      poses[n] = *posesIn[n-1];
      poses[n].checkYAxis();
    }
  // convert units for lengths in poses to millimeters.
  for (n = 1; n <= num; n++)
    {
      pointA = &(poses[n].origin);
      pointA->x *= robotLengthFactor;
      pointA->y *= robotLengthFactor;
      pointA->z *= robotLengthFactor;
    }
  if (robotSpeed == 0.0)
    {
      fprintf(stderr, "Warning: robot speed for move is zero\n");
      fprintf(stderr, "Time for move set to one minute per leg\n");
    }
  posesTotal = (num + 1);
  pointB = &(poses[0].origin);
  for (n = 1; n < posesTotal; n++)
    {
      pointA = pointB;
      pointB = &(poses[n].origin);
      distancesX[n] = pointB->x - pointA->x;
      distancesY[n] = pointB->y - pointA->y;
      distancesZ[n] = pointB->z - pointA->z;
      distances[n] = hypot3(distancesX[n], distancesY[n], distancesZ[n]);
      if (robotSpeed == 0.0)
	times[n] = (times[n-1] + 60.0);
      else
	times[n] = (times[n-1] + (distances[n] / robotSpeed));
    }
  poseIndex = 1;
}

/********************************************************************/

/* KittingViewer::executeCloseGripperCommand

Returned Value: none

Called By: KittingViewer::executeCommand

Overview: The gripper attaches to an object.

Details: If all of the following hold:
1. The robot is holding an end effector (checked in kittingViewer.cc)
2. The end effector is a single cup vacuum gripper.
3. Either:
3A. There is a parts tray or kit tray with a topless boxy shape
    such that the gripper cup is within 0.1 mm of the bottom of the
    tray and is within 1 mm of the XY location of the origin of the tray. OR
3B. There is a part with a boxy shape with top such that the gripper cup
    is within 0.1 mm of the top of the part and is within 1 mm of the XY
    location of the middle of the top of the part.
4. The gripper is able to pick up that type of part or tray.
5. The Z axis of the gripper is 0,0,-1 and the Z axis of the object is 0,0,1.
6. The gripper is open (implying the gripper is not holding anything).

Then the gripper will attach to an object. Call it B.
 - if 3B above occurred, then B is a part
 - if 3A above occurred with a parts tray in a parts tray with parts,
   then B is the parts tray with parts.
 - if 3A above occurred with a parts tray not in a parts tray with parts,
   then B is the parts tray.
 - if 3A above occurred with a kit tray in a kit, then B is the kit.
 - if 3A above occurred with a kit tray not in a kit, then B is the kit tray.


Call the primary location of B P. Then the RefObject of P becomes the
gripper, and its relative pose is changed. The before I and J
components of the Z axis of B are known to be zero in workstation
coordinates, and the before I and J components of the Z axis of the
gripper are also 0 in workstation coordinates, so the after I and J
components of the Z axis of P are set to 0 in gripper coordinates. The
before K component of the Z axis of the gripper is -1 in workstation
coordinates and the before K component of the Z axis of B is 1 in
workstation coordinates, so the after K component of the Z axis of P
is set to -1 in gripper coordinates.

If B is a part, the Z value of the point of P is set to the length of
the gripper plus the height of the part (since the part is gripped at
the top). If B is a not a part, the Z value is set to the length of the
gripper (since the tray is gripped on the upper surface of the bottom
of the tray).

This is checking that the X axis of the gripper is 1,0,0 in
workstation coordinates, so the after X axis of P in gripper
coordinates is set to the negative of the before X axis of B in
workstation coordinates. It will be necessary to deal with the X axis
of the gripper if the gripper is rotated in any way.

The gripper is closed as long as the robot is holding the gripper
regardless of anything else.

Might add checking that:
1. the load capacity of the gripper is not exceeded
2. the load capacity of the robot is not exceeded
3. the cup of the gripper fits entirely within the XY rectangle of the
   tray or part with 1 mm clearance.
Since the gripper is known to be able to pick up the Sku of which the part
or tray in 3A or 3B is an instance, item 1 is presumably covered (unless
B is a kit or parts tray with parts, since then it will be heavier than
its tray) and item 3 is sort of covered.

This is checking whether the gripper can handle a kit or parts tray
with parts by checking whether its tray can be handled. The middle of
the tray should be left open so that the gripper can grip it there.

This does not reset the location of B in workstation coordinates (the
first secondary location of B). That is not necessary since it will be
reset before drawing.

IMPROVE - Improve the destructor for PartsTrayWithPartsType. Currently
when one of those is deleted, it is orphaning everything hanging from
it, hence leaking memory. Need to delete those things also.

*/

void KittingViewer::executeCloseGripperCommand() /* NO ARGUMENTS  */
{
  VacuumEffectorSingleCupType * single;
  PoseLocationType * singlePose;
  PoseLocationType * solidPose;
  SolidObjectType * solid;
  PartType * part;
  BoxyShapeType * boxy;
  PartsTrayWithPartsType * supply;
  StockKeepingUnitType * testSku;
  KitType * kit;
  PartsTrayWithPartsType * withParts;

  if (nowModel->Robot->EndEffector == 0)
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: cannot close gripper when robot holds no end effector");
      gripperUseErrors++;
    }
  else if (robotToolChangerOpen == true)
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: cannot close gripper when tool changer is open");
      gripperUseErrors++;
    }
  else if (robotGripperOpen == false)
    { // gripper is already closed
      uselessCommands++;
      actionCommandsExecuted++;
      totalExecutionTime += 0.2;
    }
  else if ((single = dynamic_cast<VacuumEffectorSingleCupType *>
	    (nowModel->Robot->EndEffector)))
    {
      solid = findGripped(nowX, nowY, nowZ);
      if (solid)
	{
	  singlePose = findSecondaryPose(single);
	  solidPose = findPrimaryPose(solid);
	  part = dynamic_cast<PartType *>(solid);
	  testSku = ((kit = dynamic_cast<KitType *>(solid)) ? kit->Tray->sku :
		     (withParts =
		      dynamic_cast<PartsTrayWithPartsType *>(solid)) ?
		     withParts->PartsTray->sku : solid->sku);
	}
      if (solid &&
	  solidPose &&
	  gripperCanHandleSku(single->Name, testSku) &&
	  (singlePose->XAxis->I->val == 1.0) &&
	  (singlePose->XAxis->J->val == 0.0) &&
	  (singlePose->XAxis->K->val == 0.0) &&
	  (singlePose->ZAxis->I->val == 0.0) &&
	  (singlePose->ZAxis->J->val == 0.0) &&
	  (singlePose->ZAxis->K->val == -1.0))
	{
	  solid->refThing->refFor.remove(solid);
	  solidPose->RefObject->val = single->Name->val;
	  solidPose->Point->X->val = 0;
	  solidPose->Point->Y->val = 0;
	  solidPose->Point->Z->val = single->Length->val;
	  if (part)
	    {
	      boxy = dynamic_cast<BoxyShapeType *>(part->sku->Shape);
	      if (boxy)
		solidPose->Point->Z->val += boxy->Height->val;
	      else
		{
		  fprintf(stderr, "cannot handle non-boxy part\n");
		  exit(1);
		}
	      if ((supply =
		   dynamic_cast<PartsTrayWithPartsType *>(solid->refThing)) &&
		  (supply->refFor.size() == 1)) // supply still has tray
		{
		  relocateTray(supply);
		  delete supply;
		}
	    }
	  solidPose->ZAxis->I->val = 0.0;
	  solidPose->ZAxis->J->val = 0.0;
	  solidPose->ZAxis->K->val = -1.0;
	  solidPose->XAxis->J->val *= -1.0;
	  solid->refThing = single;
	  single->refFor.push_back(solid);
	}
      robotGripperOpen = false;
      actionCommandsExecuted++;
      totalExecutionTime += 0.2;
    }
  else
    {
      robotGripperOpen = false;
      actionCommandsExecuted++;
      totalExecutionTime += 0.2;
    }
}

/********************************************************************/

/* KittingViewer::executeCloseToolChangerCommand

Returned Value: none

Called By: KittingViewer::executeCommand

Overview: The robot attaches to an end effector in a tool holder.

Details: If all of the following hold:
1. The robot is not holding an end effector.
2. The tool changer is open.
3. The point of the controlled pose of the robot is the same as the
   coordinate system origin of a tool holder. For this to make sense, the
   coordinate system of a tool holder must be located so that the correct
   position for attaching the gripper to the robot occurs when the origin
   of the tool holder coordinate system is at the controlled point.
4. There is an end effector in the tool holder.
5. The end effector origin is at the tool holder origin.
6. The end effector Z axis relative to the tool holder is 0,0,-1.
7. The end effector is a vacuum effector (so it has a length).

Then:
1. The location of the end effector becomes relative to the robot at 0,0,0.
2. The robot is now holding an end effector.
3. The current position of the controlled point becomes the same as the
   position of the end of the end effector.
4. The tool holder no longer has a tool in it.
5. The X axis of the end effector becomes 1,0,0.

Error Checks:
If any of the following errors occurs, an error message is recorded and
the number of tool change errors is increased by 1.
1. The tool changer is open and the robot is holding an end effector.

Might add a check that the holder is oriented correctly (but
"correctly" depends on the shape of the holder).

When this finishes executing, the tool changer has been closed
regardless of anything else.

Notes:
Several other checks might be added

*/

void KittingViewer::executeCloseToolChangerCommand() /* NO ARGUMENTS  */
{
  EndEffectorHolderType * holder;
  XmlDecimal x;
  XmlDecimal y;
  XmlDecimal z;
  PointType point;
  VacuumEffectorType * vacEffector;
  PoseLocationType * pose;

  if (nowModel->Robot->EndEffector && robotToolChangerOpen)
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: tool changer open but robot holds end effector\n");
      toolChangeErrors++;
      return;
    }
  x.val = nowX;
  y.val = nowY;
  z.val = nowZ;
  point.X = &x;
  point.Y = &y;
  point.Z = &z;
  if ((nowModel->Robot->EndEffector == 0) &&
      ((holder = findToolHolder(&point))) &&
      robotToolChangerOpen &&
      holder->EndEffector &&
      (vacEffector = dynamic_cast<VacuumEffectorType *>(holder->EndEffector)) &&
      (pose = findPrimaryPose(vacEffector)) &&
      (pose->Point->X->val == 0.0) && (pose->Point->Y->val == 0.0) && 
      (pose->Point->Z->val == 0.0) && (pose->ZAxis->I->val == 0.0) &&
      (pose->ZAxis->J->val == 0.0) &&(pose->ZAxis->K->val == -1.0))
    { // the Point and ZAxis of the pose do not change
      nowModel->Robot->EndEffector = vacEffector;
      nowModel->Robot->refFor.push_back(vacEffector);
      holder->EndEffector = 0;
      holder->refFor.remove(vacEffector);
      vacEffector->refThing = nowModel->Robot;
      nowModel->Robot->refFor.push_back(vacEffector);
      nowZ -= vacEffector->Length->val;
      pose->RefObject->val = nowModel->Robot->Name->val;
      pose->XAxis->I->val = 1.0;
      pose->XAxis->J->val = 0.0;
      pose->XAxis->K->val = 0.0;
      pose->ZAxis->K->val = 1.0;
    }
  if (robotToolChangerOpen == false)
    uselessCommands++;
  actionCommandsExecuted++;
  totalExecutionTime += 0.2;
  robotToolChangerOpen = false;
}

/********************************************************************/

/* KittingViewer::executeCommand

Returned Value: none

Called By: KittingViewer::redraw

All workstation state changes are handled by the functions in this
file. The "process" functions (defined in canonicalMsgView.cc) just
print the command.

Useless commands are commands whose execution does not change the
state of the workstation, such as giving an OpenGripper command when
the gripper is already open. Useless commands are not errors.

Command processing always includes printing the command, even if there
is an error.

*/

void KittingViewer::executeCommand( /* ARGUMENTS          */
 CanonicalMsg * command)            /* command to execute */
{
  static DwellMsg * dwell;
  static MoveStraightToMsg * moveStraightTo;
  static MoveThroughToMsg * moveThroughTo;
  static MoveToMsg * moveTo;
  static SetAbsoluteAccelerationMsg * setAbsAccel;
  static SetAbsoluteSpeedMsg * setAbsSpeed;
  static SetAngleUnitsMsg * setAngleUnits;
  static SetEndAngleToleranceMsg * setEndAngleTol;
  static SetEndPointToleranceMsg * setEndPointTol;
  static SetIntermediatePointToleranceMsg * setIntPointTol;
  static SetLengthUnitsMsg * setLengthUnits;
  static SetRelativeAccelerationMsg * setRelAccel;
  static SetRelativeSpeedMsg * setRelSpeed;

  commandString[0][0] = 0;
  if (executionState == ended)
    {
      strncpy(commandString[0],
	      "Error: cannot execute commands when ended", TEXTSIZE);
      commandSequenceErrors++;
    }
  else if (executionState == unready)
    {
      if (dynamic_cast<InitCanonMsg *>(command))
	{
	  (dynamic_cast<InitCanonMsg *>(command))->process();
	  otherCommandsExecuted++;
	  executionState = ready;
	  return;
	}
      else
	{
	  strncpy(commandString[0], "Error: workstation not ready", TEXTSIZE);
	  commandSequenceErrors++;
	}
    }
  // below here executionState is ready
  if (dynamic_cast<CloseGripperMsg *>(command))
    { 
      if (commandString[0][0] == 0) // no error yet
	executeCloseGripperCommand();
      (dynamic_cast<CloseGripperMsg *>(command))->process();
    }
  else if (dynamic_cast<CloseToolChangerMsg *>(command))
    {
      if (commandString[0][0] == 0) // no error yet
	executeCloseToolChangerCommand();
      (dynamic_cast<CloseToolChangerMsg *>(command))->process();
    }
  else if ((dwell = dynamic_cast<DwellMsg *>(command)))
    {
      if (commandString[0][0] == 0) // no error yet
	executeDwellCommand(dwell);
      dwell->process();
    }
  else if (dynamic_cast<EndCanonMsg *>(command))
    {
      if (commandString[0][0] == 0) // no error yet
	{
	  otherCommandsExecuted++;
	  executionState = ended;
	}
      (dynamic_cast<EndCanonMsg *>(command))->process();
    }
  else if (dynamic_cast<InitCanonMsg *>(command))
    {
      if (commandString[0][0] == 0) // no error yet
	{ // don't get here if unitialized, so error
	  strncpy(commandString[0],
		  "Error: workstation already initialized", TEXTSIZE);
	  commandSequenceErrors++;
	}
      (dynamic_cast<InitCanonMsg *>(command))->process();
    }
  else if (dynamic_cast<MessageMsg *>(command))
    {
      if (commandString[0][0] == 0) //no error yet
	otherCommandsExecuted++;
      (dynamic_cast<MessageMsg *>(command))->process();
    }
  else if ((moveStraightTo = dynamic_cast<MoveStraightToMsg *>(command)))
    {
      if (commandString[0][0] == 0) // no error yet
	executeMoveStraightToCommand(moveStraightTo);
      moveStraightTo->process();
    }
  else if ((moveThroughTo = dynamic_cast<MoveThroughToMsg *>(command)))
    {
      if (commandString[0][0] == 0) //no error yet
	executeMoveThroughToCommand(moveThroughTo);
      moveThroughTo->process();
    }
  else if ((moveTo = dynamic_cast<MoveToMsg *>(command)))
    {
      if (commandString[0][0] == 0) // no error yet
	executeMoveToCommand(moveTo);
      moveTo->process();
    }
  else if (dynamic_cast<OpenGripperMsg *>(command))
    {
      if (commandString[0][0] == 0) // no error yet
	executeOpenGripperCommand();
      (dynamic_cast<OpenGripperMsg *>(command))->process();
    }
  else if (dynamic_cast<OpenToolChangerMsg *>(command))
    {
      if (commandString[0][0] == 0) // no error yet
	executeOpenToolChangerCommand();
      (dynamic_cast<OpenToolChangerMsg *>(command))->process();
    }
  else if ((setAbsAccel = dynamic_cast<SetAbsoluteAccelerationMsg *>(command)))
    {
      if (commandString[0][0] == 0) // no error yet
	executeSetAbsoluteAccelerationCommand(setAbsAccel);
      setAbsAccel->process();
    }
  else if ((setAbsSpeed = dynamic_cast<SetAbsoluteSpeedMsg *>(command)))
    {
      if (commandString[0][0] == 0) // no error yet
	executeSetAbsoluteSpeedCommand(setAbsSpeed);
      setAbsSpeed->process();
    }
  else if ((setAngleUnits = dynamic_cast<SetAngleUnitsMsg *>(command)))
    {
      if (commandString[0][0] == 0) // no error yet
	executeSetAngleUnitsCommand(setAngleUnits);
      setAngleUnits->process();
    }
  else if ((setEndAngleTol = dynamic_cast<SetEndAngleToleranceMsg *>(command)))
    {
      if (commandString[0][0] == 0) // no error yet
	executeSetEndAngleToleranceCommand(setEndAngleTol);
      setEndAngleTol->process();
    }
  else if ((setEndPointTol = dynamic_cast<SetEndPointToleranceMsg *>(command)))
    {
      if (commandString[0][0] == 0) // no error yet
	executeSetEndPointToleranceCommand(setEndPointTol);
      setEndPointTol->process();
    }
  else if ((setIntPointTol =
	    dynamic_cast<SetIntermediatePointToleranceMsg *>(command)))
    {
      if (commandString[0][0] == 0) // no error yet
	executeSetIntermediatePointToleranceCommand(setIntPointTol);
      setIntPointTol->process();
    }
  else if ((setLengthUnits = dynamic_cast<SetLengthUnitsMsg *>(command)))
    {
      if (commandString[0][0] == 0) // no error yet
	executeSetLengthUnitsCommand(setLengthUnits);
      setLengthUnits->process();
    }
  else if ((setRelAccel = dynamic_cast<SetRelativeAccelerationMsg *>(command)))
    {
      if (commandString[0][0] == 0) // no error yet
	executeSetRelativeAccelerationCommand(setRelAccel);
      setRelAccel->process();
    }
  else if ((setRelSpeed = dynamic_cast<SetRelativeSpeedMsg *>(command)))
    {
      if (commandString[0][0] == 0) // no error yet
	executeSetRelativeSpeedCommand(setRelSpeed);
      setRelSpeed->process();
    }
  else if (dynamic_cast<UnreadableMsg *>(command))
    {
      if (commandString[0][0] == 0) // no error yet
	{
	  snprintf(commandString[0], TEXTSIZE, "Error: unreadable command");
	  parseErrors++;
	}
      (dynamic_cast<UnreadableMsg *>(command))->process();
    }
  else // cannot normally reach here
    {
      fprintf(stderr, "bug in KittingViewer::executeCommand\n");
      exit(1);
    }
}

/********************************************************************/

/* KittingViewer::executeDwellCommand

Returned Value: none

Called By: KittingViewer::executeCommand

*/

void KittingViewer::executeDwellCommand( /* ARGUMENTS                */
 DwellMsg * dwellMsg)                    /* dwell command to execute */
{
  if (dwellMsg->time < 0)
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: negative dwell time %f", dwellMsg->time);
      rangeErrors++;
    }
  else
    {
      dwell(dwellMsg->time);
      actionCommandsExecuted++;
      totalExecutionTime += dwellMsg->time;
    }
}

/********************************************************************/

/* KittingViewer::executeMoveStraightToCommand

Returned Value: none

Called By: KittingViewer::executeCommand

*/

void KittingViewer::executeMoveStraightToCommand( /* ARGUMENTS               */
 MoveStraightToMsg * moveStraightTo)    /* moveStraightTo command to execute */
{
  enterPoseTarget(moveStraightTo->pose);
  actionCommandsExecuted++;
  resetFlag = true;
}

/********************************************************************/

/* KittingViewer::executeMoveThroughToCommand

Returned Value: none

Called By: KittingViewer::executeCommand

*/

void KittingViewer::executeMoveThroughToCommand( /* ARGUMENTS               */
 MoveThroughToMsg * moveThroughTo)      /* moveThroughTo command to execute */
{
  enterPoseTargets(moveThroughTo->poses, moveThroughTo->num);
  actionCommandsExecuted++;
  resetFlag = true;
}

/********************************************************************/

/* KittingViewer::executeMoveToCommand

Returned Value: none

Called By: KittingViewer::executeCommand

*/

void KittingViewer::executeMoveToCommand( /* ARGUMENTS                 */
 MoveToMsg * moveTo)                      /* moveTo command to execute */
{
  enterPoseTarget(moveTo->pose);
  actionCommandsExecuted++;
  resetFlag = true;
}

/********************************************************************/

/* KittingViewer::executeOpenGripperCommand

Returned Value: none

Called By: KittingViewer::executeCommand

Overview: The gripper opens. If the gripper was holding an object it is
released. See the documentation of releaseObject and findSurface regarding
what happens when the object is released.

*/

void KittingViewer::executeOpenGripperCommand() /* NO ARGUMENTS */
{
  VacuumEffectorSingleCupType * single;

  if (nowModel->Robot->EndEffector == 0)
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: cannot open gripper when robot holds no end effector");
      gripperUseErrors++;
    }
  else if (robotToolChangerOpen == true)
    {
      snprintf(commandString[0], TEXTSIZE,
	      "Error: cannot open gripper when tool changer is open");
      gripperUseErrors++;
    }
  else if (robotGripperOpen == true)
    {
      uselessCommands++;
      actionCommandsExecuted++;
      totalExecutionTime += 0.2;
    }
  else if ((single = dynamic_cast<VacuumEffectorSingleCupType *>
	    (nowModel->Robot->EndEffector)))
    {
      if (single->refFor.size())
	releaseObject(single, single->refFor.front());
      robotGripperOpen = true;
      actionCommandsExecuted++;
      totalExecutionTime += 0.2;
    }
  else
    {
      robotGripperOpen = true;
      actionCommandsExecuted++;
      totalExecutionTime += 0.2;
    }  
}

/********************************************************************/

/* KittingViewer::executeOpenToolChangerCommand

Returned Value: none

Called By: KittingViewer::executeCommand

Overview: The robot puts the end effector in the tool holder.

Details: If all of the following hold:
1. The robot is holding an end effector.
2. The tool changer is closed.
3. The current position (adjusted by the length of the end effector)
   is the same as the position of a tool holder.
4. The gripper axis is 0,0,-1 (so it is pointing into the tool holder).
5. The tool holder is empty.
6. The gripper is open.

Then:
1. The location of the gripper becomes relative to the tool holder at
   0,0,0.
2. The robot is no longer holding an end effector.
3. The current position (NOT adjusted by the length of the end effector)
   becomes the same as the position of the tool holder.

If the robot is not holding an end effector, there is no error, but
none of the three items above is changed.

Error Checks:
If the robot is holding an end effector and any of the following errors
occurs, an error message is recorded and the number of tool change errors
is increased by 1.
1. The tool changer is open and the robot is holding an end effector.
2. The current position is not the same as the position of a tool holder
3. The gripper is not open.
4. The tool holder is not empty.
5. The gripper axis is not 0,0,-1.

The tool changer is opened regardless of anything else.

Might add a check that the gripper is not holding anything (but that is
unlikely if the gripper is open). Might add a check that the holder is
oriented correctly (but "correctly" depends on the shape of the holder).

nowX, nowY, and nowZ are set to the location in the workstation of the
origin of the gripper since the now point becomes the end of the quill,
and the end of the quill is at the origin of the gripper before the tool
changer is opened.

*/
 
void KittingViewer::executeOpenToolChangerCommand() /* NO ARGUMENTS */
{
  PoseLocationType * pose;
  EndEffectorHolderType * holder;
  VacuumEffectorType * vacEffector;

  if (nowModel->Robot->EndEffector &&
      (vacEffector =
       dynamic_cast<VacuumEffectorType *>(nowModel->Robot->EndEffector)))
    {
      if (robotToolChangerOpen == true)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: tool changer open but robot holds end effector\n");
	  toolChangeErrors++;
	}
      else if (robotGripperOpen != true)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: gripper not open while opening tool changer\n");
	  toolChangeErrors++;
	}
      else if (((pose = findSecondaryPose(vacEffector)) == 0) ||
	       (pose->ZAxis->I->val != 0.0) ||
	       (pose->ZAxis->J->val != 0.0) ||
	       (pose->ZAxis->K->val != -1.0))
	{
	  snprintf(commandString[0], TEXTSIZE,
	       "Error: gripper axis not 0,0,-1 while opening tool changer\n");
	  toolChangeErrors++;
	}
      else if ((holder = findToolHolder(pose->Point)) == 0)
	{
	  snprintf(commandString[0], TEXTSIZE,
	     "Error: gripper not at tool holder while opening tool changer\n");
	  toolChangeErrors++;
	}
      else if (holder->EndEffector)
	{
	  snprintf(commandString[0], TEXTSIZE,
	     "Error: tool holder not empty while opening tool changer\n");
	  toolChangeErrors++;
	}
      else // all OK
	{ // robot no effector, controlled pt moves, effector located wrt holder
	  nowModel->Robot->EndEffector = 0;
	  nowModel->Robot->refFor.remove(vacEffector);
	  nowX = pose->Point->X->val;
	  nowY = pose->Point->Y->val;
	  nowZ = pose->Point->Z->val;
	  vacEffector->refThing = holder;
	  holder->refFor.push_back(vacEffector);
	  holder->EndEffector = vacEffector;
	  pose = findPrimaryPose(vacEffector);
	  pose->RefObject->val = holder->Name->val;
	  pose->Point->X->val = 0;
	  pose->Point->Y->val = 0;
	  pose->Point->Z->val = 0;
	  pose->ZAxis->K->val = -1;
	  robotToolChangerOpen = true;
	  actionCommandsExecuted++;
	  totalExecutionTime += 0.2;
	}
    }
  else
    {
      if (robotToolChangerOpen == true)
	uselessCommands++;
      robotToolChangerOpen = true;
      actionCommandsExecuted++;
      totalExecutionTime += 0.2;
    }
}

/********************************************************************/

/* KittingViewer::executeSetAbsoluteAccelerationCommand

Returned Value: none

Called By: KittingViewer::executeCommand

*/

void KittingViewer::executeSetAbsoluteAccelerationCommand( /* ARGUMENTS     */
 SetAbsoluteAccelerationMsg * setAbsAccel) /* set abs accel cmnd to execute */
{
  double acceleration;

  acceleration = setAbsAccel->acceleration;
  if (acceleration < 0)
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: negative acceleration (%.4f)", acceleration);
      rangeErrors++;
    }
  else if (acceleration > (robotMaxAccel / robotLengthFactor))
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: acceleration (%.4f) larger than maximum (%.4f)",
	       acceleration, (robotMaxAccel / robotLengthFactor));
    }
  else
    {
      robotAccel = (acceleration * robotLengthFactor);
      robotRelAccel = ((robotAccel / robotMaxAccel) * 100.0);
      otherCommandsExecuted++;
    }
}

/********************************************************************/

/* KittingViewer::executeSetAbsoluteSpeedCommand

Returned Value: none

Called By: KittingViewer::executeCommand

*/

void KittingViewer::executeSetAbsoluteSpeedCommand( /* ARGUMENTS             */
 SetAbsoluteSpeedMsg * setAbsSpeed) /* set absolute speed command to execute */
{
  double speed;

  speed = setAbsSpeed->speed;
  if (speed < 0)
    {
      snprintf(commandString[0],
	       TEXTSIZE, "Error: negative speed (%.4f)", speed);
      rangeErrors++;
    }
  else if (speed > (robotMaxSpeed / robotLengthFactor))
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: speed (%.4f) larger than maximum (%.4f)",
	       speed, (robotMaxSpeed / robotLengthFactor));
    }
  else
    {
      robotSpeed = (speed * robotLengthFactor);
      robotRelSpeed = ((robotSpeed / robotMaxSpeed) * 100.0);
      otherCommandsExecuted++;
    }
}

/********************************************************************/

/* KittingViewer::executeSetAngleUnitsCommand

Returned Value: none

Called By: KittingViewer::executeCommand

*/

void KittingViewer::executeSetAngleUnitsCommand( /* ARGUMENTS             */
 SetAngleUnitsMsg * setAngleUnits)  /* set angle units command to execute */
{
  std::string unitName;

  unitName = setAngleUnits->unitName;
  if (unitName == "degree")
    {
      if (strcmp(robotAngleUnits, "degree") == 0)
	uselessCommands++;
      else
	{
	  robotAngleFactor = 1.0;
	  strncpy(robotAngleUnits, "degree", TEXTSIZE);
	}
      otherCommandsExecuted++;
    }
  else if (unitName == "radian")
    {
      if (strcmp(robotAngleUnits, "radian") == 0)
	uselessCommands++;
      else
	{
	  robotAngleFactor = 57.2957795;
	  strncpy(robotAngleUnits, "radian", TEXTSIZE);
	}
      otherCommandsExecuted++;
    }
  else // not normally possible to get here
    {
      fprintf(stderr, "Error: angle unit (%s) must be degree or radian",
	      unitName.c_str());
      rangeErrors++;
    }
}

/********************************************************************/

/* KittingViewer::executeSetEndAngleToleranceCommand

Returned Value: none

Called By: KittingViewer::executeCommand

*/

void KittingViewer::executeSetEndAngleToleranceCommand( /* ARGUMENTS          */
 SetEndAngleToleranceMsg * setEndAngleTolerance) /* set end angle tol command */
{
  double tolerance;

  tolerance = setEndAngleTolerance->tolerance;
  if (tolerance < 0)
    {
      snprintf(commandString[0],
	       TEXTSIZE, "Error: negative tolerance (%.4f)", tolerance);
      rangeErrors++;
    }
  else
    {
      robotEndAngleTol = (tolerance * robotAngleFactor);
      otherCommandsExecuted++;
    }
}

/********************************************************************/

/* KittingViewer::executeSetEndPointToleranceCommand

Returned Value: none

Called By: KittingViewer::executeCommand

*/

void KittingViewer::executeSetEndPointToleranceCommand( /* ARGUMENTS          */
 SetEndPointToleranceMsg * setEndPointTolerance) /* set end point tol command */
{
  double tolerance;

  tolerance = setEndPointTolerance->tolerance;
  if (tolerance < 0)
    {
      snprintf(commandString[0],
	       TEXTSIZE, "Error: negative tolerance (%.4f)", tolerance);
      rangeErrors++;
    }
  else
    {
      robotEndPointTol = (tolerance * robotLengthFactor);
      otherCommandsExecuted++;
    }
}

/********************************************************************/

/* KittingViewer::executeSetIntermediatePointToleranceCommand

Returned Value: none

Called By: KittingViewer::executeCommand

*/

void KittingViewer::executeSetIntermediatePointToleranceCommand( /* ARGUMENTS */
 SetIntermediatePointToleranceMsg * setIntPointTolerance)/*set int pt tol cmnd*/
{
  double tolerance;

  tolerance = setIntPointTolerance->tolerance;
  if (tolerance < 0)
    {
      snprintf(commandString[0],
	       TEXTSIZE, "Error: negative tolerance (%.4f)", tolerance);
      rangeErrors++;
    }
  else
    {
      robotIntPointTol = (tolerance * robotLengthFactor);
      otherCommandsExecuted++;
    }
}

/********************************************************************/

/* KittingViewer::executeSetLengthUnitsCommand

Returned Value: none

Called By: KittingViewer::executeCommand

*/

void KittingViewer::executeSetLengthUnitsCommand( /* ARGUMENTS              */
 SetLengthUnitsMsg * setLengthUnits) /* set length units command to execute */
{
  std::string unitName;

  unitName = setLengthUnits->unitName;
  if (unitName == "meter")
    {
      if (strcmp(robotLengthUnits, "meter") == 0)
	uselessCommands++;
      else
	{
	  robotLengthFactor = 1000.0;
	  strncpy(robotLengthUnits, "meter", TEXTSIZE);
	}
      otherCommandsExecuted++;
    }
  else if (unitName == "millimeter")
    {
      if (strcmp(robotLengthUnits, "millimeter") == 0)
	uselessCommands++;
      else
	{
	  robotLengthFactor = 1.0;
	  strncpy(robotLengthUnits, "millimeter", TEXTSIZE);
	}
      otherCommandsExecuted++;
    }
  else if (unitName == "inch")
    {
      if (strcmp(robotLengthUnits, "inch") == 0)
	uselessCommands++;
      else
	{
	  robotLengthFactor = 25.4;
	  strncpy(robotLengthUnits, "inch", TEXTSIZE);
	}
      otherCommandsExecuted++;
    }
  else // not normally possible to get here
    {
      fprintf(stderr, 
	      "Error: length unit (%s) must be meter, millimeter, or inch",
	      unitName.c_str());
      rangeErrors++;
    }
}

/********************************************************************/

/* KittingViewer::executeSetRelativeAccelerationCommand

Returned Value: none

Called By: KittingViewer::executeCommand

*/

void KittingViewer::executeSetRelativeAccelerationCommand( /* ARGUMENTS     */
 SetRelativeAccelerationMsg * setRelAccel) /* set rel accel cmnd to execute */
{
  double percent;

  percent = setRelAccel->percent;
  if (percent < 0)
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: negative relative acceleration (%.4f)", percent);
      rangeErrors++;
    }
  else if (percent > 100.0)
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: relative acceleration (%.4f) exceeds 100 percent",
	       percent);
      rangeErrors++;
    }
  else
    {
      if (percent < 1.0)
	snprintf(commandString[0], TEXTSIZE, "Warning: relative "
		 "acceleration set to less than 1.0; range is 0 to 100");
      robotAccel = ((robotMaxAccel * percent) / 100.0);
      robotRelAccel = percent;
      otherCommandsExecuted++;
    }
}

/********************************************************************/

/* KittingViewer::executeSetRelativeSpeedCommand

Returned Value: none

Called By: KittingViewer::executeCommand

*/

void KittingViewer::executeSetRelativeSpeedCommand( /* ARGUMENTS             */
 SetRelativeSpeedMsg * setRelSpeed) /* set relative speed command to execute */
{
  double percent;

  percent = setRelSpeed->percent;
  if (percent < 0)
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: negative relative speed (%.4f)", percent);
      rangeErrors++;
    }
  else if (percent > 100.0)
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: relative speed (%.4f) exceeds 100 percent", percent);
      rangeErrors++;
    }
  else
    {
      if (percent < 1.0)
	snprintf(commandString[0], TEXTSIZE, "Warning: relative "
		 "speed set to less than 1.0; range is 0 to 100");
      robotSpeed = ((robotMaxSpeed * percent) / 100.0);
      robotRelSpeed = percent;
      otherCommandsExecuted++;
    }
}

/********************************************************************/

/* KittingViewer::findKitWithTray

Returned Value: SolidObjectType

Called By: KittingViewer::createKit

This looks through the allKits list for a Kit that has a tray with the
given trayName. If one is found a pointer to it is returned. If not, a
null pointer is returned.

*/ 

KitType * KittingViewer::findKitWithTray( /* ARGUMENTS                 */
 std::string trayName,                    /* name of tray to look for  */
 std::list<KitType *> * allKits)          /* a list of kits to look in */
{
  std::list<KitType *>::iterator iter;

  for (iter = allKits->begin(); iter != allKits->end(); iter++)
    {
      if ((*iter)->Tray->Name->val == trayName)
	return *iter;
    }
  return 0;
}

/********************************************************************/

/* KittingViewer::findGripped

Returned Value: SolidObjectType
  This may return a null pointer or a pointer to a part, a parts tray,
  a kit tray, a kit, or a parts tray with parts.

Called By: KittingViewer::executeCloseGripperCommand

If all of the following conditions are met for a SolidObject B in the
kitting workstation, then a pointer to a solid object is returned.
Otherwise, a 0 pointer is returned. The X, Y, and Z arguments identify
a point P.

1. B is a part, a parts tray, or a kit tray.
2. The shape of B is a BoxyShape.
3. In kittingWorkstation coordinates, the Z axis of B is 0,0,1.
4A. If B is a part, the shape has a top.
4B. If B is a tray, the shape has no top.
5A. If B is a part, the point argument is within TINYDISTANCE of
    the top of the part.
5B. If B is a tray, P is within TINYDISTANCE of the bottom
    of the tray (assumes the tray bottom has no thickness - yuck).
6. P is within 1 millimeter in X and Y from the origin of B
   (the origin of a boxy shape is in the middle of the bottom). This is
   required so that that there will be little torque on a gipper that lifts
   B and so that it will be easy to determine if the gripper fits B.

Returned pointer rules:
1. If B is a kit tray
1A. If the refThing of B is a kit K, then a pointer to K is returned.
1B. Otherwise, a pointer to B is returned.
2. If B is a parts tray
2A. If the refThing of B is a parts tray with parts T, then a pointer
    to T is returned.
2B. Otherwise, a pointer to B is returned.
3. If B is a part, a pointer to B is returned.

*/

SolidObjectType * KittingViewer::findGripped( /* ARGUMENTS                   */
 double X,                                    /* X value of point to look at */
 double Y,                                    /* Y value of point to look at */
 double Z)                                    /* Z value of point to look at */
{
  SolidObjectType * object;
  std::map<std::string, SolidObjectType *>::iterator iter;
  PoseLocationType * pose;
  BoxyShapeType * boxy;

  for (iter = nowModel->allSolids.begin();
       iter != nowModel->allSolids.end(); iter++)
    {
      object = iter->second;
      pose = findSecondaryPose(object);
      if ((fabs(X - pose->Point->X->val) > 1)       ||
	  (fabs(Y - pose->Point->Y->val) > 1)       ||
	  (fabs(pose->ZAxis->I->val) > TINYVAL)     ||
	  (fabs(pose->ZAxis->J->val) > TINYVAL)     ||
	  (fabs(pose->ZAxis->K->val - 1) > TINYVAL))
	continue;
      if (dynamic_cast<PartType *>(object))
	{
	  if ((boxy = dynamic_cast<BoxyShapeType *>(object->sku->Shape)) &&
	      (boxy->HasTop->val == true) &&
	      (fabs((pose->Point->Z->val + boxy->Height->val) - Z) <
	       TINYDISTANCE))
		return object;
	}
      else if (dynamic_cast<PartsTrayType *>(object))
	{
	  if ((boxy = dynamic_cast<BoxyShapeType *>(object->sku->Shape)) &&
	      (boxy->HasTop->val == false) &&
	      (fabs(pose->Point->Z->val - Z) < TINYDISTANCE))
	    {
	      if (dynamic_cast<PartsTrayWithPartsType *>(object->refThing))
		return object->refThing;
	      else
		return object;
	    }
	}
      else if (dynamic_cast<KitTrayType *>(object))
	{
	  if ((boxy = dynamic_cast<BoxyShapeType *>(object->sku->Shape)) &&
	      (boxy->HasTop->val == false) &&
	      (fabs(pose->Point->Z->val - Z) < TINYDISTANCE))
	    {
	      if (dynamic_cast<KitType *>(object->refThing))
		return object->refThing;
	      else
		return object;
	    }
	}
    }
  return 0;
}

/********************************************************************/

/* KittingViewer::findPrimaryPose

Returned Value: PoseLocationType *

Called By:
  KittingViewer::checkLocation
  KittingViewer::createKit
  KittingViewer::drawRobot
  KittingViewer::drawWorkstation
  KittingViewer::executeCloseGripperCommand
  KittingViewer::executeCloseToolChangerCommand
  KittingViewer::executeOpenToolChangerCommand
  KittingViewer::initData
  KittingViewer::releaseObject
  KittingViewer::relocateTray
  KittingViewer::resetPositions
  KittingViewer::updateWorkstationPosition

This returns a pointer to the primary pose of the solid, if the
primary pose is a PoseLocationType. This never returns a null pointer.
It exits instead if the pointer does not exist.

*/

PoseLocationType * KittingViewer::findPrimaryPose(/*  ARGUMENTS              */
 SolidObjectType * solid)                         /* object to find pose for */
{
  PoseLocationType * pose;
  
  if ((pose = dynamic_cast<PoseLocationType *>(solid->PrimaryLocation)) == 0)
    {
      fprintf(stderr, "bug: bad PrimaryLocation for solid object\n");
      exit(1);
    }
  return pose;
}

/********************************************************************/

/* KittingViewer::findSecondaryPose

Returned Value: PoseLocationType *

Called By:
  KittingViewer::drawSolidObject
  KittingViewer::executeCloseGripperCommand
  KittingViewer::executeOpenToolChangerCommand
  KittingViewer::findGripped
  KittingViewer::findToolHolder
  KittingViewer::findSurface
  KittingViewer::findToolHolder
  KittingViewer::initData
  KittingViewer::releaseObject
  KittingViewer::updateWorkstationPosition

This returns a pointer to the first secondary pose of the solid, if
that exists and is a PoseLocationType. This never returns a null
pointer. It exits instead if the pointer does not exist. The first
secondary pose should always exist because setWorkstationLocation
inserts a secondary pose (at the front of the list) for all solid objects.

*/

PoseLocationType * KittingViewer::findSecondaryPose(/*  ARGUMENTS             */
 SolidObjectType * solid)                           /* object to find pose for*/
{
  PoseLocationType * pose;
  
  if ((solid->SecondaryLocation->size() == 0) ||
      ((pose = dynamic_cast<PoseLocationType *>
	(solid->SecondaryLocation->front())) == 0))
    {
      fprintf(stderr, "bug: bad SecondaryLocation for solid object\n");
      exit(1);
    }
  return pose;
}

/********************************************************************/

/* KittingViewer::findSku

Returned Value: StockKeepingUnitType 
  If there is an instance of StockKeepingUnitType with the given skuName
  in the Skus of the kitting workstation, a pointer to it is returned.
  Otherwise, a 0 pointer is returned.

Called By:
  KittingViewer::setColorAndSku

*/

StockKeepingUnitType * KittingViewer::findSku( /* ARGUMENTS           */
 XmlIDREF * skuName,                           /* name of sku to find */
 std::list<StockKeepingUnitType *> * Skus)     /* skus to look in     */
{
  std::list<StockKeepingUnitType *>::iterator iter;

  for (iter = Skus->begin(); iter != Skus->end(); iter++)
    {
      if ((*iter)->Name->val == skuName->val)
	return *iter;
    }
  if (iter == Skus->end())
    {
      fprintf(stderr, "cannot find a required SKU named %s\n",
	      skuName->val.c_str());
      exit(1);
    }
  return 0;
}

/********************************************************************/

/* KittingViewer::findSurface

Returned Value: PoseLocationType *

Called By: KittingViewer::releaseObject

This finds and returns a pointer to a solid object (if there is one)
such that the given xyz point is somewhere on a horizontal
upward-facing surface of the object. The solid object must be the work
table, a part, a parts tray, or a kit tray. If there is no such
object, this returns 0. The upward-facing surface is the top for a
work table or part. The upward-facing surface is the bottom for a
tray.

The offsets are set to the offsets from the point in the location of
the object to the given xyz point.

The actual check on the Z value is that z is within TINYDISTANCE of
a surface.

This is similar to KittingViewer::findGripped.

This returns when it finds the first qualifying object. This could
make a problem if there is more than one qualifying object. There can
be more than one when the bottoms of objects have zero thickness, as
is currently the case. For example, if a part is placed in a kit tray
which is on the work table, both the kit tray and the work table will
qualify. Fortunately, the solid object map is kept in alphabetical
order by object name. kit_tray_xxx comes before work_table_xxx, so the
correct object will be chosen by accident in most normal kitting
scenarios. It would probably be a good idea to add a thickness to the
bottoms of objects. That would ensure the problem would not arise.

*/

SolidObjectType * KittingViewer::findSurface( /* ARGUMENTS                   */
 double X,          /* X value of point to look at, workstation coords       */
 double Y,          /* Y value of point to look at, workstation coords       */
 double Z,          /* Z value of point to look at, workstation coords       */
 SolidObjectType * solid, /* the object being located                        */
 double * xOffset,  /* X offset from object location to point, object coords */
 double * yOffset,  /* Y offset from object location to point, object coords */
 double * zOffset)  /* Z offset from object location to point, object coords */
{
  SolidObjectType * object;
  std::map<std::string, SolidObjectType *>::iterator iter;
  PoseLocationType * pose;
  BoxyShapeType * boxy;
  WorkTableType * table;
  double xi;               // I component of pose X axis in workstation coords
  double xj;               // J component of pose X axis in workstation coords
  double vi;               // X offset in workstation coords
  double vj;               // Y offset in workstation coords
  double length;           // length of target rectangle
  double width;            // width of target rectangle
  double height;           // height of target object

  for (iter = nowModel->allSolids.begin();
       iter != nowModel->allSolids.end(); iter++)
    {
      object = iter->second;
      // don't located the solid with respect to itself
      if (object == solid)
	continue;
      pose = findSecondaryPose(object);
      // check that surface is horizontal
      if ((fabs(pose->ZAxis->I->val) > TINYVAL)     ||
	  (fabs(pose->ZAxis->J->val) > TINYVAL)     ||
	  (fabs(pose->ZAxis->K->val - 1) > TINYVAL))
	continue;
      // find length, width, and height
      if (dynamic_cast<PartType *>(object))
	{
	  boxy = dynamic_cast<BoxyShapeType *>(object->sku->Shape);
	  if ((!boxy) || (boxy->HasTop->val == false))
	    continue;
	  length = boxy->Length->val;
	  width  = boxy->Width->val;
	  height = boxy->Height->val;
	}
      else if (dynamic_cast<PartsTrayType *>(object) ||
	       dynamic_cast<KitTrayType *>(object))
	{
	  boxy = dynamic_cast<BoxyShapeType *>(object->sku->Shape);
	  if ((!boxy) || (boxy->HasTop->val == true))
	    continue;
	  length = boxy->Length->val;
	  width  = boxy->Width->val;
	  height = 0;
	}
      else if ((table = dynamic_cast<WorkTableType *>(object)))
	{
	  if (table->InternalShape == 0)
	    continue;
	  boxy = dynamic_cast<BoxyShapeType *>(table->InternalShape);
	  if ((!boxy) || (boxy->HasTop->val == false))
	    continue;
	  length = boxy->Length->val;
	  width  = boxy->Width->val;
	  height = boxy->Height->val;
	}
      // check height
      if (fabs((pose->Point->Z->val + height) - Z) > TINYDISTANCE)
	continue;
      // check that point is inside object rectangle
      vi = (X - pose->Point->X->val);
      vj = (Y - pose->Point->Y->val);
      xi = pose->XAxis->I->val;
      xj = pose->XAxis->J->val;
      *xOffset = ((vi * xi) + (vj * xj));
      *yOffset = ((xi * vj) - (vi * xj));
      if ((fabs(*xOffset) < (length / 2.0)) &&
	  (fabs(*yOffset) < (width / 2.0)))
	{
	  *zOffset = height;
	  return object;
	}
    }
  return 0;
}

/********************************************************************/

/* KittingViewer::findToolHolder

Returned Value: EndEffectorHolderType

Called By:
  KittingViewer::executeCloseToolChangerCommand
  KittingViewer::executeOpenToolChangerCommand

This looks through the tool holders in the kitting workstation. If one is
found whose coordinate system origin is in the same place as the point
argument, a pointer to that tool holder is returned. Otherwise, a null
pointer is returned.

*/

EndEffectorHolderType * KittingViewer::findToolHolder( /* ARGUMENTS        */
 PointType * point)                                    /* point to look at */
{
  std::list<EndEffectorHolderType *> * holders;
  std::list<EndEffectorHolderType *>::iterator iter;
  PoseLocationType * pose;

  holders = nowModel->ChangingStation->EndEffectorHolders;
  for (iter = holders->begin(); iter != holders->end(); iter++)
    {
      pose = findSecondaryPose(*iter);
      if ((fabs(point->X->val - pose->Point->X->val) < TINYDISTANCE) &&
	  (fabs(point->Y->val - pose->Point->Y->val) < TINYDISTANCE) &&
	  (fabs(point->Z->val - pose->Point->Z->val) < TINYDISTANCE))
	return *iter;
    }
  return 0;
}

/********************************************************************/

/* KittingViewer::findDistance

Returned Value: double

Called By: computeScore

This finds the distance moved by a basic solid object in the goalModel
that has a counterpart (same name and type) in the initial model. Only
those have a secondary location in the goalModel.

*/

double KittingViewer::findDistance( /* ARGUMENTS                           */
 SolidObjectType * goalObject)      /* movable object to find distance for */
{
  std::map<std::string, SolidObjectType *>::iterator iter;
  SolidObjectType * nowObject;
  PointType * initPoint; 
  PointType * nowPoint;

  if (goalObject->SecondaryLocation &&
      goalObject->SecondaryLocation->size())
    {
      iter = nowModel->allSolids.find(goalObject->Name->val);
      if (iter == nowModel->allSolids.end())
	{
	  fprintf(stderr, "bug in findDistance\n");
	  exit(1);
	}
      nowObject = iter->second;
      nowPoint = findSecondaryPose(nowObject)->Point;
      initPoint = findSecondaryPose(goalObject)->Point;
      return hypot3((nowPoint->X->val - initPoint->X->val),
		    (nowPoint->Y->val - initPoint->Y->val),
		    (nowPoint->Z->val - initPoint->Z->val));
    }
  else
    return 0.0;
}

/********************************************************************/

/* KittingViewer::gripperCanHandleSku

Returned Value: bool
  If the gripperName is among the EndEffectorName/s of the sku, this
  returns true. Otherwise, it returns false.

Called By: KittingViewer::executeCloseGripperCommand

*/

bool KittingViewer::gripperCanHandleSku( /* ARGUMENTS       */
 XmlID * gripperName,                    /* name of gripper */
 StockKeepingUnitType * sku)             /* SKU to check    */
{
  std::list<XmlIDREF *>::iterator iter;
  
  for (iter = sku->EndEffectorName->begin();
       iter != sku->EndEffectorName->end(); iter++)
    {
      if ((*iter)->val == gripperName->val)
	return true;
    }
  return false;
}

/********************************************************************/

/*  KittingViewer::handleExecute

Returned Value:  none

Called By: KittingViewer::redraw

When this is called, executeFlag is true and no motion command is in
progress.

1. If there is another command to execute, execute it.

2. Otherwise (all commands are executed), if the location checks have
not yet started, initialize making location checks. Before location
checks start, the locationErrors and locationGoods are set to 0. The 0
setting prevents these items from appearing in the metrics window.
They do not appear until location checks start because they would be
misleading. Set those four items to -1 so that they will appear in the
metrics window. The first time each of those should be increased, it
will be reset to 1.

3. Otherwise (all commands are executed, and location checking is
initialized), if location checking is not completed, check the
location of the next object in the list of all solid objects. This
skips the work table and the robot.

4. Otherwise (all commands are executed, and location checking is
completed), print a "kittingViewer done" message.

5. Set the executeFlag to false.

This function is "used up" when the kittingViewer is done because the
first half of the function pops commands off the commands list until
it is reduced to nothing, and the second half of the function keeps
moving iter along allSolids in the goalModel until it reaches the end.

*/

void KittingViewer::handleExecute() /* NO ARGUMENTS   */
{
  static std::map<std::string, SolidObjectType *>::iterator iter;
  static bool iterUnset = true;
  SolidObjectType * object;

  if (commands.size())
    {
      executeCommand(commands.front());
      commands.pop_front();
      if ((commands.size() == 0) && (executionState != ended))
	{
	  fprintf(stderr, "command sequence error; no EndCanon command\n");
	  commandSequenceErrors++;
	}
      executeFlag = false;
      return;
    }
  if (iterUnset)
    {
      iter = goalModel->allSolids.begin();
      iterUnset = false;
    }
  if (iter != goalModel->allSolids.end())
    {
      for ( ; iter != goalModel->allSolids.end(); iter++)
	{
	  object = iter->second;
	  if (solidIsMovable(object))
	    break;
	}
      if (iter == goalModel->allSolids.end())
	{
	  strncpy(commandString[0], "kittingViewer done", TEXTSIZE);
	  commandString[1][0] = 0;
	}
      else
	{
	  checkLocation(object);
	  computeScore(object);
	  iter++;
	}
    }
  else
    {
      strncpy(commandString[0], "kittingViewer done", TEXTSIZE);
      commandString[1][0] = 0;
    }
  executeFlag = false;
}


/********************************************************************/

/* KittingViewer::handleResets

Returned Value: none

Called By: KittingViewer::redraw

This is called if a motion command is in progress, in which case the
resetFlag is true;

Data for the most recently executed motion command has been saved in
three arrays, all indexed by the number of legs in the motion: 
 - poses (the pose at the end of the leg)
 - times (the time at which the end of the leg should be reached)
 - distances (the length of the leg)

1. If it is time for the most recent waypoint to have been passed,
find the index of the poses array for the next waypoint W based on
what time it is; the times for waypoints have been recorded previously
in the times array. Also use the times and distances arrays to update
the total time used and the total distance travelled. Then add one to
the poses index.

2. If the poses index is now out of range, W is the last point of the
move, and the move should be complete but might not be. In this case,
set the resetFlag to false, and call resetPositions to set things
representing that W has been reached.

3. Otherwise, a motion command is in progress and is not supposed to
be complete. Let P denote the waypoint before W. Find the fraction of
time from P to W represented by the current time. Then set the current
point to the point that is that fraction of the way from P to W.

*/

void KittingViewer::handleResets() /* NO ARGUMENTS  */
{
  Point point;     // Point from Pose.h
  VectorIJK xAxis; // VectorIJK from Pose.h
  VectorIJK zAxis; // VectorIJK from Pose.h
  double fraction;
  int n;
  double timeNow;

  timeNow = (glutGet(GLUT_ELAPSED_TIME) / 1000.0);
  while ((timeNow > times[poseIndex]) && (poseIndex < posesTotal))
    {
      distanceTotal += distances[poseIndex];
      totalExecutionTime += (times[poseIndex] - times[poseIndex - 1]);
      poseIndex++;
    }
  if (poseIndex == posesTotal)
    {
      resetFlag = false;
      point = poses[posesTotal - 1].origin;
      xAxis = poses[posesTotal - 1].xAxis;
      zAxis = poses[posesTotal - 1].zAxis;
      resetPositions(point.x, point.y, point.z, xAxis.i, xAxis.j, xAxis.k,
		     zAxis.i, zAxis.j, zAxis.k);
    }
  else
    {
      n = poseIndex - 1;
      fraction = (((double)(timeNow - times[n])) /
		  ((double)(times[poseIndex] - times[n])));
      point = poses[n].origin;
      nowX = (point.x + (fraction * distancesX[poseIndex]));
      nowY = (point.y + (fraction * distancesY[poseIndex]));
      nowZ = (point.z + (fraction * distancesZ[poseIndex]));
    }
}

/********************************************************************/

/* KittingViewer::hypot3

Returned Value: double

Called By:
  KittingViewer::enterPoseTarget
  KittingViewer::enterPoseTargets
  KittingViewer::findDistance

This returns the distance between two points from the differences in
their x, y, and z values.

*/

double KittingViewer::hypot3( /* ARGUMENTS  */
 double x,                    /* x distance */
 double y,                    /* y distance */
 double z)                    /* z distance */
{
  return sqrt((x*x) + (y*y) + (z*z));
}

/********************************************************************/

/* KittingViewer::init

Returned Value: none

Called By: main

This initializes the kittingViewer. Specifically, it:
 - reads the command file
 - reads the initial configuration file
 - reads the goal configuration file
 - reads the scoring file if there is one
 - converts units in the initial configuration and the goal configuration
 - sets the nowModel and the goalModel
 - calculates the positions of all solid objects in the initial
   configuration relative to the workstation
 - makes colors for the solid objects that have their own colors
 - initializes the data in the kittingViewer world model
 - sets the scale for the drawing 

The scale to use is calculated by having the larger of the length and
width of the workstation being used fit exactly into 20 grid squares,
which is 1.0 unit in picture space.

*/

void KittingViewer::init( /* ARGUMENTS                                  */
 char * commandFile,      /* name of file of canonical robot commands   */
 char * kittingInitFile,  /* name of file describing initial conditions */
 char * kittingGoalFile,  /* name of file describing goal conditions    */
 char * scoringFile)      /* name of file describing how to score       */
{
  FILE * inFile;
  CommandParser commandParser;

  inFile = fopen(commandFile, "r");
  if (inFile == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n", commandFile);
      exit(1);
    }
  commandParser.readCommandFile(inFile, &commands);
  fclose(inFile);
  printf("Command file read\n");
  yyin = fopen(kittingInitFile, "r");
  if (yyin == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n", kittingInitFile);
      exit(1);
    }
  clearLists();
  yyparse();
  fclose(yyin);
  printf("Kitting workstation initial configuration file read\n");
  nowModel = KittingWorkstationTree->KittingWorkstation;
  nowModel->convertUnits(true);
  setLocationsAndColors(nowModel->allSolids);
  yyin = fopen(kittingGoalFile, "r");
  if (yyin == 0)
    {
      fprintf(stderr, "unable to open file %s for reading\n", kittingGoalFile);
      exit(1);
    }
  clearLists(); // goalModel will have new lists
  yyparse();
  fclose(yyin);
  XmlID::allIDs.clear(); // to prevent duplicate ID messages later
  XmlIDREF::allIDREFs.clear(); // to prevent missing IDREF messages later
  printf("Kitting workstation goal configuration file read\n");
  goalModel = KittingWorkstationTree->KittingWorkstation;
  goalModel->convertUnits(false);
  recordInitialPositions(goalModel->allSolids);
  readScoringFile(scoringFile);
  scale = 1.0 / max(WORKSTATIONLENGTH, WORKSTATIONWIDTH);
  spacing =  (max(WORKSTATIONLENGTH, WORKSTATIONWIDTH) / 20.0);
  initData();
  executeFlag = false;
}

/********************************************************************/

/* KittingViewer::initData

Returned Value: none

Called By: KittingViewer::init

This initializes the data in the kittingViewer's local world model.

This assumes that the robot position given in the initial setup file
is the position of the quill of the robot. 

*/

void KittingViewer::initData() /* NO ARGUMENTS */
{
  PoseLocationType * pose;
  EndEffectorType * effector;
  VacuumEffectorType * vacEffector;
  double length;

  actionCommandsExecuted = 0;
  // angleFactor set when initial state read
  // angleUnits set when initial state read
  // commands set when command file read
  commandSequenceErrors = 0;
  // commandString set in canonicalMsgView.cc used in viewKitting.cc
  distanceTotal = 0.0;
  // distances
  // distancesX
  // distancesY
  // distancesZ
  // executeFlag
  executionState = unready;
  // fraction
  // goalModel built when goal state file read
  gripperUseErrors = 0;
  // lengthFactor set when initial state read
  // lengthUnits set when initial state read
  // nowModel set when initial state read, updated during command execution
  effector = nowModel->Robot->EndEffector;
  if (effector && (vacEffector = dynamic_cast<VacuumEffectorType *>(effector)))
    { // controlled point at end of effector
      pose = findSecondaryPose(effector);
      length = vacEffector->Length->val;
      nowX = (pose->Point->X->val + (length * pose->ZAxis->I->val));
      nowY = (pose->Point->Y->val + (length * pose->ZAxis->J->val));
      nowZ = (pose->Point->Z->val + (length * pose->ZAxis->K->val));
    }
  else
    { // controlled point at end of quill of robot
      pose = findPrimaryPose(nowModel->Robot);
      nowX = pose->Point->X->val;
      nowY = pose->Point->Y->val;
      nowZ = pose->Point->Z->val;
    }
  nowXAxisI = pose->XAxis->I->val;
  nowXAxisJ = pose->XAxis->J->val;
  nowXAxisK = pose->XAxis->K->val;
  nowZAxisI = pose->ZAxis->I->val;
  nowZAxisJ = pose->ZAxis->J->val;
  nowZAxisK = pose->ZAxis->K->val;
  otherCommandsExecuted = 0;
  parseErrors = 0;
  locationErrors = 0;
  locationGoods = 0;
  poseIndex = 1;
  poses[0].origin.x = nowX;
  poses[0].origin.y = nowY;
  poses[0].origin.z = nowZ;
  poses[1].origin.x = nowX;
  poses[1].origin.y = nowY;
  poses[1].origin.z = nowZ;
  posesTotal = 2;
  rangeErrors = 0;
  resetFlag = false;
  robotAngleFactor = 1.0;
  robotAccel = (robotMaxAccel * robotRelAccel) / 100.0;
  strncpy(robotAngleUnits, "degree", TEXTSIZE);
  robotEndAngleTol = 0.0;
  robotEndPointTol = 0.0;
  robotGripperOpen = false;
  robotIntPointTol = 0.0;
  robotLengthFactor = 1.0;
  strncpy(robotLengthUnits, "millimeter", TEXTSIZE);
  robotMaxAccel = ROBOTDEFAULTMAXACCEL;
  robotMaxSpeed = ROBOTDEFAULTMAXSPEED;
  robotRelAccel = 10.0;
  robotRelSpeed = 10.0;
  robotSpeed = (robotMaxSpeed * robotRelSpeed) / 100.0;
  robotToolChangerOpen = false;
  score = 0;
  // scale set when initial state read
  // spacing set when initial state read
  times[0] = 0.0;
  times[1] = 0.001;
  toolChangeErrors = 0;
  totalExecutionTime = 0;
  totalGoalDistance = 0;
  uselessCommands = 0;
  // weightFactor set when initial state read
  // weightUnits set when initial state read
}

/********************************************************************/

/* KittingViewer::insertBox

Returned Value: none

Called By:  KittingViewer::drawRobot

This draws a box at the given position using a method that will work
in a display list. The display area is actually 1 unit wide (to work
well with the camera and openGL) while the area it represents depends
on the size of the workstation. in the picture on the screen, the +X
axis is to the right, the +Y axis is up, the +Z axis sticks out of the
screen towards the viewer, and the origin is in the middle of the
screen (so the left side is at X = -0.5 and the right at +0.5).
The scale is currently being calculated so that the larger of the length
and width of the workstation fits in 0.9 picture units.

*/

void KittingViewer::insertBox( /* ARGUMENTS                                  */
 col boxColor,                 /* color of box                               */
 double minX,                  /* minimum value of X on box in millimeters   */
 double minY,                  /* minimum value of Y on box in millimeters   */
 double minZ,                  /* minimum value of Z on box in millimeters   */
 double maxX,                  /* maximum value of X on box in millimeters   */
 double maxY,                  /* maximum value of Y on box in millimeters   */
 double maxZ,                  /* maximum value of Z on box in millimeters   */
 bool solid)                   /* true = faces and edges, false = edges only */
{
  static GLubyte allIndices[] = {4,5,6,7, 1,2,6,5, 0,1,5,4,
				 0,3,2,1, 0,4,7,3, 2,3,7,6};
  static GLfloat vertices[] = {0,0,0, 0,0,0, 0,0,0, 0,0,0,
			       0,0,0, 0,0,0, 0,0,0, 0,0,0};
  
  glEnableClientState(GL_VERTEX_ARRAY);
  minX *= scale;
  minY *= scale;
  minZ *= scale;
  maxX *= scale;
  maxY *= scale;
  maxZ *= scale;
  vertices[0]  = (GLfloat)(minX - 0.5);
  vertices[1]  = (GLfloat)(minY - 0.5);
  vertices[2]  = (GLfloat)minZ;
  vertices[3]  = (GLfloat)(minX - 0.5);
  vertices[4]  = (GLfloat)(maxY - 0.5);
  vertices[5]  = (GLfloat)minZ;
  vertices[6]  = (GLfloat)(minX - 0.5);
  vertices[7]  = (GLfloat)(maxY - 0.5);
  vertices[8]  = (GLfloat)maxZ;
  vertices[9]  = (GLfloat)(minX - 0.5);
  vertices[10] = (GLfloat)(minY - 0.5);
  vertices[11] = (GLfloat)maxZ;
  vertices[12] = (GLfloat)(maxX - 0.5);
  vertices[13] = (GLfloat)(minY - 0.5);
  vertices[14] = (GLfloat)minZ;
  vertices[15] = (GLfloat)(maxX - 0.5);
  vertices[16] = (GLfloat)(maxY - 0.5);
  vertices[17] = (GLfloat)minZ;
  vertices[18] = (GLfloat)(maxX - 0.5);
  vertices[19] = (GLfloat)(maxY - 0.5);
  vertices[20] = (GLfloat)maxZ;
  vertices[21] = (GLfloat)(maxX - 0.5);
  vertices[22] = (GLfloat)(minY - 0.5);
  vertices[23] = (GLfloat)maxZ;
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glColor3f(boxColor.r, boxColor.g, boxColor.b);
  if (solid)
    {
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices);
      glColor3f(0.0f, 0.0f, 0.0f);
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices);
    }
  else
    {
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices);
    }
}

/********************************************************************/

/* KittingViewer::insertBoxTransformed

Returned Value: none

Called By:  KittingViewer::drawBoxyShape

This may be used for drawing BoxyShapeTypes. The point used for
locating a BoxyShapeType is in the center of the bottom. The xAxis
and zAxis vectors here are assumed to be normalized.

The top of the box has the the last 4 vertices in allIndices. It is
easy to leave the top off by omitting using those vertices.

*/

void KittingViewer::insertBoxTransformed( /* ARGUMENTS                       */
 col boxColor,                 /* color of box                               */
 double pointX,                /* X value of box location point              */
 double pointY,                /* Y value of box location point              */
 double pointZ,                /* Z value of box location point              */
 double length,                /* length of box                              */
 double width,                 /* width of box                               */
 double height,                /* height of box                              */
 double xAxisX,                /* X coordinate of direction of length of box */
 double xAxisY,                /* Y coordinate of direction of length of box */
 double xAxisZ,                /* Z coordinate of direction of length of box */
 double zAxisX,                /* X coordinate of direction of height of box */
 double zAxisY,                /* Y coordinate of direction of height of box */
 double zAxisZ,                /* Z coordinate of direction of height of box */
 bool hasTop,                  /* true=box has top, false=no top             */
 bool solid)                   /* true = faces and edges, false = edges only */
{
  static GLubyte allIndices[] = {4,5,6,7, 1,2,6,5, 0,1,5,4,
				 0,3,2,1, 0,4,7,3, 2,3,7,6};
  static GLfloat vertices[] = {0,0,0, 0,0,0, 0,0,0, 0,0,0,
			       0,0,0, 0,0,0, 0,0,0, 0,0,0};
  static GLfloat matrix[] = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
  static GLfloat l2;
  static GLfloat w2;
  static GLfloat h;

  l2 = (GLfloat)(scale * (length / 2.0));
  w2 = (GLfloat)(scale * (width / 2.0));
  h  = (GLfloat)(scale * height);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glEnableClientState(GL_VERTEX_ARRAY);
  vertices[0]  = -l2;
  vertices[1]  = -w2;
  vertices[2]  = (GLfloat)0;
  vertices[3]  = -l2;
  vertices[4]  = w2;
  vertices[5]  = (GLfloat)0;
  vertices[6]  = -l2;
  vertices[7]  = w2;
  vertices[8]  = h;
  vertices[9]  = -l2;
  vertices[10] = -w2;
  vertices[11] = h;
  vertices[12] = l2;
  vertices[13] = -w2;
  vertices[14] = (GLfloat)0;
  vertices[15] = l2;
  vertices[16] = w2;
  vertices[17] = (GLfloat)0;
  vertices[18] = l2;
  vertices[19] = w2;
  vertices[20] = h;
  vertices[21] = l2;
  vertices[22] = -w2;
  vertices[23] = h;
  matrix[0] = (GLfloat)xAxisX;
  matrix[1] = (GLfloat)xAxisY;
  matrix[2] = (GLfloat)xAxisZ;
  matrix[8] = (GLfloat)zAxisX;
  matrix[9] = (GLfloat)zAxisY;
  matrix[10] = (GLfloat)zAxisZ;
  matrix[4] = ((matrix[9] * matrix[2]) - (matrix[1] * matrix[10]));
  matrix[5] = ((matrix[10] * matrix[0]) - (matrix[2] * matrix[8]));
  matrix[6] = ((matrix[8] * matrix[1]) - (matrix[0] * matrix[9]));
  matrix[12] = (GLfloat)((scale * pointX) - 0.5);
  matrix[13] = (GLfloat)((scale * pointY) - 0.5);
  matrix[14] = (GLfloat)(scale * pointZ);
  glMultMatrixf(matrix);
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glColor3f(boxColor.r, boxColor.g, boxColor.b);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glDrawElements(GL_QUADS, (hasTop ? 24 : 20), GL_UNSIGNED_BYTE, allIndices);
  if (solid)
    {
      glColor3f((0.5f * boxColor.r), (0.5f * boxColor.g), (0.5f * boxColor.b));
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      glDrawElements(GL_QUADS, (hasTop ? 24 : 20), GL_UNSIGNED_BYTE,allIndices);
    }
  glPopMatrix();
}

/********************************************************************/

/* KittingViewer::insertConeTransformed

Returned Value: none

Called By:  KittingViewer::drawSingleCupGripper

This may be used for drawing cones, cylinders, and annuluses. The
point used for locating the surface is in the center of the bottom. The
axis of the surface is the zAxis vector. The xAxis and zAxis vectors here
are assumed to be normalized. For a cylinder, radius1 = radius2. For an
annulus, height = 0;

This will also make a disk (an annulus with radius2 = 0), but it
is better to use the insertDiskTransformed function for that, since a disk
needs much less data.

This makes the cone by drawing 16 polygons for the sides plus darker
polylines around the top and bottom, each with 16 segments. The cone
is open at the top and bottom.

The 64 vertices settings are X and Y values that are r*cos(angle) and
r*sin(angle). Because of symmetry, only five different numbers are
needed.

It would be nice to GLUquadricObj, but that draws a wire frame instead of
a filled polygon when GL_FILL is used, which seems to be a drawing error.

*/

void KittingViewer::insertConeTransformed( /* ARGUMENTS                  */
 col color,               /* color of cone                               */
 double pointX,           /* X value of cone location point              */
 double pointY,           /* Y value of cone location point              */
 double pointZ,           /* Z value of cone location point              */
 double radius1,          /* radius of the bottom                        */
 double radius2,          /* radius of the top                           */
 double height,           /* height of the cone (zero for a disk)        */
 double xAxisX,           /* X coordinate of direction of X axis of cone */
 double xAxisY,           /* Y coordinate of direction of X axis of cone */
 double xAxisZ,           /* Z coordinate of direction of X axis of cone */
 double zAxisX,           /* X coordinate of direction of Z axis of cone */
 double zAxisY,           /* Y coordinate of direction of Z axis of cone */
 double zAxisZ)           /* Z coordinate of direction of Z axis of cone */
//bool hasTop,            /* true=cone has top, false=no top             */
{
  int n;

  static GLubyte allIndices[] =
    { 0, 2, 3, 1,   2, 4, 5, 3,   4, 6, 7, 5,   6, 8, 9, 7,   8,10,11, 9,
     10,12,13,11,  12,14,15,13,  14,16,17,15,  16,18,19,17,  18,20,21,19,
     20,22,23,21,  22,24,25,23,  24,26,27,25,  26,28,29,27,  28,30,31,29,
     30, 0, 1,31};
  static GLubyte topIndices[] =
    {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31};
  static GLubyte bottomIndices[] =
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
  static GLfloat vertices[96] = {0};
  static GLfloat matrix[] = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
  static GLfloat r1;
  static GLfloat r2;
  static GLfloat h;

  r1 = (GLfloat)(scale * radius1);
  r2 = (GLfloat)(scale * radius2);
  h  = (GLfloat)(scale * height);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glEnableClientState(GL_VERTEX_ARRAY);
  for (n = 5; n < 96; n += 6) // set top Z values (bottom Z stays zero)
    vertices[n] = h;

  vertices[0]  = r1;
  vertices[1]  = (GLfloat)0.000000;
  vertices[3]  = r2;
  vertices[4]  = (GLfloat)0.000000;
  vertices[6]  = r1 *  (GLfloat)0.923880;
  vertices[7]  = r1 *  (GLfloat)0.382683;
  vertices[9]  = r2 *  (GLfloat)0.923880;
  vertices[10] = r2 *  (GLfloat)0.382683;
  vertices[12] = r1 *  (GLfloat)0.707107;
  vertices[13] = vertices[12];
  vertices[15] = r2 *  (GLfloat)0.707107;
  vertices[16] = vertices[15];
  vertices[18] = vertices[7];
  vertices[19] = vertices[6];
  vertices[21] = vertices[10];
  vertices[22] = vertices[9];
  vertices[24] = vertices[1];
  vertices[25] = vertices[0];
  vertices[27] = vertices[4];
  vertices[28] = vertices[3];
  vertices[30] = -vertices[7];
  vertices[31] = vertices[6];
  vertices[33] = -vertices[10];
  vertices[34] = vertices[9];
  vertices[36] = -vertices[12];
  vertices[37] = vertices[12];
  vertices[39] = -vertices[15];
  vertices[40] = vertices[15];
  vertices[42] = -vertices[6];
  vertices[43] = vertices[7];
  vertices[45] = -vertices[9];
  vertices[46] = vertices[10];
  vertices[48] = -vertices[0];
  vertices[49] = vertices[1];
  vertices[51] = -vertices[3];
  vertices[52] = vertices[4];
  vertices[54] = vertices[42];
  vertices[55] = vertices[30];
  vertices[57] = vertices[45];
  vertices[58] = vertices[33];
  vertices[60] = vertices[36];
  vertices[61] = vertices[36];
  vertices[63] = vertices[39];
  vertices[64] = vertices[39];
  vertices[66] = vertices[30];
  vertices[67] = vertices[42];
  vertices[69] = vertices[33];
  vertices[70] = vertices[45];
  vertices[72] = vertices[1];
  vertices[73] = vertices[48];
  vertices[75] = vertices[4];
  vertices[76] = vertices[51];
  vertices[78] = vertices[7];
  vertices[79] = vertices[42];
  vertices[81] = vertices[10];
  vertices[82] = vertices[45];
  vertices[84] = vertices[12];
  vertices[85] = vertices[36];
  vertices[87] = vertices[15];
  vertices[88] = vertices[39];
  vertices[90] = vertices[6];
  vertices[91] = vertices[30];
  vertices[93] = vertices[9];
  vertices[94] = vertices[33];

  matrix[0] = (GLfloat)xAxisX;
  matrix[1] = (GLfloat)xAxisY;
  matrix[2] = (GLfloat)xAxisZ;
  matrix[8] = (GLfloat)zAxisX;
  matrix[9] = (GLfloat)zAxisY;
  matrix[10] = (GLfloat)zAxisZ;
  matrix[4] = ((matrix[9] * matrix[2]) - (matrix[1] * matrix[10]));
  matrix[5] = ((matrix[10] * matrix[0]) - (matrix[2] * matrix[8]));
  matrix[6] = ((matrix[8] * matrix[1]) - (matrix[0] * matrix[9]));
  matrix[12] = (GLfloat)((scale * pointX) - 0.5);
  matrix[13] = (GLfloat)((scale * pointY) - 0.5);
  matrix[14] = (GLfloat)(scale * pointZ);
  glMultMatrixf(matrix);
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glColor3f(color.r, color.g, color.b);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glDrawElements(GL_QUADS, 64, GL_UNSIGNED_BYTE, allIndices);
  glColor3f((0.5f * color.r), (0.5f * color.g), (0.5f * color.b));
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glDrawElements(GL_LINE_LOOP, 16, GL_UNSIGNED_BYTE, topIndices);
  glDrawElements(GL_LINE_LOOP, 16, GL_UNSIGNED_BYTE, bottomIndices);
  glPopMatrix();
}

/********************************************************************/

/* KittingViewer::insertDiskTransformed

Returned Value: none

Called By:  KittingViewer::drawSingleCupGripper

This makes a 16-sided disk using seven quadrilaterals. The location point
of the disk is in the center. The axis of the disk is the Z axis.

The 32 vertices settings are X and Y values that are r*cos(angle) and
r*sin(angle). Because of symmetry, only five different numbers are
needed.

*/

void KittingViewer::insertDiskTransformed( /* ARGUMENTS                  */
 col color,               /* color of disk                               */
 double pointX,           /* X value of disk location point              */
 double pointY,           /* Y value of disk location point              */
 double pointZ,           /* Z value of disk location point              */
 double radius,           /* radius of the disk                          */
 double xAxisX,           /* X coordinate of direction of X axis of disk */
 double xAxisY,           /* Y coordinate of direction of X axis of disk */
 double xAxisZ,           /* Z coordinate of direction of X axis of disk */
 double zAxisX,           /* X coordinate of direction of Z axis of disk */
 double zAxisY,           /* Y coordinate of direction of Z axis of disk */
 double zAxisZ)           /* Z coordinate of direction of Z axis of disk */
{
  static GLubyte allIndices[] = {0, 1,14,15,  1, 2,13,14,  2, 3,12,13,
				 3, 4,11,12,  4, 5,10,11,  5, 6, 9,10,
				 6, 7, 8, 9};
  static GLubyte edgeIndices[] =
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  static GLfloat vertices[48] = {0};
  static GLfloat matrix[] = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
  static GLfloat r;

  r = (GLfloat)(scale * radius);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glEnableClientState(GL_VERTEX_ARRAY);
  vertices[0]  = r;
  vertices[1]  = (GLfloat)0.000000;
  vertices[3]  = r *  (GLfloat)0.923880;
  vertices[4]  = r *  (GLfloat)0.382683;
  vertices[6]  = r *  (GLfloat)0.707107;
  vertices[7]  = vertices[6];
  vertices[9]  = vertices[4];
  vertices[10] = vertices[3];
  vertices[12] = vertices[1];
  vertices[13] = vertices[0];
  vertices[15] = -vertices[4];
  vertices[16] = vertices[3];
  vertices[18] = -vertices[6];
  vertices[19] = vertices[6];
  vertices[21] = -vertices[3];
  vertices[22] = vertices[4];
  vertices[24] = -vertices[0];
  vertices[25] = vertices[1];
  vertices[27] = vertices[21];
  vertices[28] = vertices[15];
  vertices[30] = vertices[18];
  vertices[31] = vertices[18];
  vertices[33] = vertices[15];
  vertices[34] = vertices[21];
  vertices[36] = vertices[1];
  vertices[37] = vertices[24];
  vertices[39] = vertices[4];
  vertices[40] = vertices[21];
  vertices[42] = vertices[6];
  vertices[43] = vertices[18];
  vertices[45] = vertices[3];
  vertices[46] = vertices[15];

  matrix[0] = (GLfloat)xAxisX;
  matrix[1] = (GLfloat)xAxisY;
  matrix[2] = (GLfloat)xAxisZ;
  matrix[8] = (GLfloat)zAxisX;
  matrix[9] = (GLfloat)zAxisY;
  matrix[10] = (GLfloat)zAxisZ;
  matrix[4] = ((matrix[9] * matrix[2]) - (matrix[1] * matrix[10]));
  matrix[5] = ((matrix[10] * matrix[0]) - (matrix[2] * matrix[8]));
  matrix[6] = ((matrix[8] * matrix[1]) - (matrix[0] * matrix[9]));
  matrix[12] = (GLfloat)((scale * pointX) - 0.5);
  matrix[13] = (GLfloat)((scale * pointY) - 0.5);
  matrix[14] = (GLfloat)(scale * pointZ);
  glMultMatrixf(matrix);
  glVertexPointer(3, GL_FLOAT, 0, vertices);
  glColor3f(color.r, color.g, color.b);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glDrawElements(GL_QUADS, 28, GL_UNSIGNED_BYTE, allIndices);
  glColor3f((0.5f * color.r), (0.5f * color.g), (0.5f * color.b));
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glDrawElements(GL_LINE_LOOP, 16, GL_UNSIGNED_BYTE, edgeIndices);
  glPopMatrix();
}

/********************************************************************/

/* kittingViewer::makeBlueColor

Returned Value: none

Called By: KittingViewer::setColorAndSku

This makes bluish colors by picking points in the RGB cube and
selecting the ones that are bluish. Each time this is called, it
generates a new bluish color. The picked points gradually become
dense in the cube. Colors that are dim (i.e. the sum of the components
is less than 0.4) are not used. Colors that are picked successively
are far apart in the cube.

The function remembers how many points it has tried (in the static
index variable).

The inner loop picks points in the RGB cube. The idea is to distribute
points around the cube so that as the cube fills up, the density of
points is roughly the same in all parts of the cube. This is done by
recursively dividing the cube into eight sub-cubes and putting points
in the center of the subcubes. The position of the Nth point is
calculated by finding successive offsets, each half as large as the
preceding one.  The first point is at the center of the RGB cube (side
length 1).  The first offset is 0.5 so that the bright colors at the
corners of the RGB cube are used. As a side effect of setting the
first offset at 0.5, the inner loop generates points in a cube whose
side length is 2, so many of them are outside the RGB cube and they
are rejected.

The outer loop rejects three kinds of points:
 - points outside the RGB cube
   (any value negative or greater than 1)
 - points representing colors that are not mostly blue
   (blue value must be at least twice as large as red value and green value)
 - points that are dim
   (total value from all three colors must be at least 0.4)

The octants are numbered as follows, according to the direction in which
the offsets are made. 

octant  R G B
------  - - -
0       + + +
1       + + -
2       + - +
3       + - -
4       - + +
5       - + -
6       - - +
7       - - -


*/

void KittingViewer::makeBlueColor( /* ARGUMENTS    */
 col * color)                      /* color to set */
{
  static int index = 1;
  int n;      // total number of colors at end of last go-around
  float jump; // how far to moveq
  int octant;

  while (1)
    {
      color->r = 0.5f;
      color->g = 0.5f;
      color->b = 0.5f;
      for (n = index-1, jump = 0.5;  n > 0; n = (n / 8), jump = (jump / 2))
	{
	  octant = (n % 8);
	  if (octant < 4)
	    color->r += jump;
	  else
	    color->r -= jump;
	  if ((octant % 4) < 2)
	    color->g += jump;
	  else
	    color->g -= jump;
	  if ((octant % 2) == 0)
	    color->b += jump;
	  else
	    color->b -= jump;
	}
      index++;
      if ((color->r >= 0) && (color->g >= 0) && (color->b >= 0) &&
	  (color->r <= 1) && (color->g <= 1) && (color->b <= 1) &&
	  ((color->r + color->g + color->b) > 0.4) &&
	  (color->b >= (2 * color->r)) && (color->b >= (2 * color->g)))
	return;
    }
}

/********************************************************************/

/* kittingViewer::makeGreenColor

Returned Value: none

Called By: KittingViewer::setColorAndSku

This makes greenish colors by picking points in the RGB cube and
selecting the ones that are greenish. See documentation of makeBlueColor.
This is identical except that it selects greenish colors.

*/

void KittingViewer::makeGreenColor( /* ARGUMENTS    */
 col * color)                       /* color to set */
{
  static int index = 1;
  int n;      // total number of colors at end of last go-around
  float jump; // how far to moveq
  int octant;

  while (1)
    {
      color->r = 0.5f;
      color->g = 0.5f;
      color->b = 0.5f;
      for (n = index-1, jump = 0.5;  n > 0; n = (n / 8), jump = (jump / 2))
	{
	  octant = (n % 8);
	  if (octant < 4)
	    color->r += jump;
	  else
	    color->r -= jump;
	  if ((octant % 4) < 2)
	    color->g += jump;
	  else
	    color->g -= jump;
	  if ((octant % 2) == 0)
	    color->b += jump;
	  else
	    color->b -= jump;
	}
      index++;
      if ((color->r >= 0) && (color->g >= 0) && (color->b >= 0) &&
	  (color->r <= 1) && (color->g <= 1) && (color->b <= 1) &&
	  ((color->r + color->g + color->b) > 0.4) &&
	  (color->g >= (2 * color->r)) && (color->g >= (2 * color->b)))
	return;
    }
}

/********************************************************************/

/* kittingViewer::makeRedColor

Returned Value: none

Called By: KittingViewer::setColorAndSku

This makes reddish colors by picking points in the RGB cube and
selecting the ones that are greenish. See documentation of makeBlueColor.
This is identical except that it selects reddish colors.

*/

void KittingViewer::makeRedColor( /* ARGUMENTS    */
 col * color)                     /* color to set */
{
  static int index = 1;
  int n;      // total number of colors at end of last go-around
  float jump; // how far to moveq
  int octant;

  while (1)
    {
      color->r = 0.5f;
      color->g = 0.5f;
      color->b = 0.5f;
      for (n = index-1, jump = 0.5;  n > 0; n = (n / 8), jump = (jump / 2))
	{
	  octant = (n % 8);
	  if (octant < 4)
	    color->r += jump;
	  else
	    color->r -= jump;
	  if ((octant % 4) < 2)
	    color->g += jump;
	  else
	    color->g -= jump;
	  if ((octant % 2) == 0)
	    color->b += jump;
	  else
	    color->b -= jump;
	}
      index++;
      if ((color->r >= 0) && (color->g >= 0) && (color->b >= 0) &&
	  (color->r <= 1) && (color->g <= 1) && (color->b <= 1) &&
	  ((color->r + color->g + color->b) > 0.4) &&
	  (color->r >= (2 * color->g)) && (color->r >= (2 * color->b)))
	return;
    }
}

/********************************************************************/

/* KittingViewer::poseProduct

Returned Value: none

Called By:
  KittingViewer::setNetTransform
  KittingViewer::updateWorkstationPosition

This computes and sets the Point, XAxis, and ZAxis for poseToSet as
the product of pose1 and pose2, treating all the poses as homogeneous
matrices, and assuming the XAxis and ZAxis of pose1 and pose2 are
normalized. A set of Y axis values are calculated for pose1 and pose2
as an intermediate step, but those values are not saved.

This may be used, for example, as follows.
poseToSet = pose of kid object in workstation coordinates
pose1     = pose of parent object in workstation coordinates
pose2     = pose of kid object in parent coordinates

poseToSet may point to the same pose as pose1 or pose2 since all the data
in pose1 and pose2 is recorded separately before any data is written into
poseToSet, and the values placed into poseToSet are calculated from the
separate recorded data.

*/

void KittingViewer::poseProduct( /* ARGUMENTS       */
 PoseLocationType * poseToSet,   /* the pose to set */
 PoseLocationType * pose1,       /* the first pose  */
 PoseLocationType * pose2)       /* the second pose */
{
  
  double x1i = pose1->XAxis->I->val;
  double x1j = pose1->XAxis->J->val;
  double x1k = pose1->XAxis->K->val;
  double y1i;
  double y1j;
  double y1k;
  double z1i = pose1->ZAxis->I->val;
  double z1j = pose1->ZAxis->J->val;
  double z1k = pose1->ZAxis->K->val;
  double x2i = pose2->XAxis->I->val;
  double x2j = pose2->XAxis->J->val;
  double x2k = pose2->XAxis->K->val;
  double y2i;
  double y2j;
  double y2k;
  double z2i = pose2->ZAxis->I->val;
  double z2j = pose2->ZAxis->J->val;
  double z2k = pose2->ZAxis->K->val;
  double o1x = pose1->Point->X->val;
  double o1y = pose1->Point->Y->val;
  double o1z = pose1->Point->Z->val;
  double o2x = pose2->Point->X->val;
  double o2y = pose2->Point->Y->val;
  double o2z = pose2->Point->Z->val;
  
  y1i = ((z1j * x1k) - (x1j * z1k));
  y1j = ((z1k * x1i) - (x1k * z1i));
  y1k = ((z1i * x1j) - (x1i * z1j));
  y2i = ((z2j * x2k) - (x2j * z2k));
  y2j = ((z2k * x2i) - (x2k * z2i));
  y2k = ((z2i * x2j) - (x2i * z2j));
  poseToSet->XAxis->I->val = ((x1i * x2i) + (y1i * x2j) + (z1i * x2k));
  poseToSet->XAxis->I->bad = false;
  poseToSet->XAxis->J->val = ((x1j * x2i) + (y1j * x2j) + (z1j * x2k));
  poseToSet->XAxis->J->bad = false;
  poseToSet->XAxis->K->val = ((x1k * x2i) + (y1k * x2j) + (z1k * x2k));
  poseToSet->XAxis->K->bad = false;
  poseToSet->ZAxis->I->val = ((x1i * z2i) + (y1i * z2j) + (z1i * z2k));
  poseToSet->ZAxis->I->bad = false;
  poseToSet->ZAxis->J->val = ((x1j * z2i) + (y1j * z2j) + (z1j * z2k));
  poseToSet->ZAxis->J->bad = false;
  poseToSet->ZAxis->K->val = ((x1k * z2i) + (y1k * z2j) + (z1k * z2k));
  poseToSet->ZAxis->K->bad = false;
  poseToSet->Point->X->val = ((x1i * o2x) + (y1i * o2y) + (z1i * o2z) + o1x);
  poseToSet->Point->X->bad = false;
  poseToSet->Point->Y->val = ((x1j * o2x) + (y1j * o2y) + (z1j * o2z) + o1y);
  poseToSet->Point->Y->bad = false;
  poseToSet->Point->Z->val = ((x1k * o2x) + (y1k * o2y) + (z1k * o2z) + o1z);
  poseToSet->Point->Z->bad = false;
}

/********************************************************************/

/* KittingViewer::printMetricsAndSettings

Returned Value: none

Called By: displayMetricsWindow (in viewKitting.cc)

This prints the metrics The text is printed in the metricsWindow. The
size and position of the text do not change if the size of the
metricsWindow is changed. Instead, if the window is made larger there
is more blank space, and if the window is made smaller, some of the
text is no longer visible. The text is anchored at the upper left
corner of the metrics window.

*/

void KittingViewer::printMetricsAndSettings( /* ARGUMENTS                 */
 int height)                                 /* side of screen, in pixels */
{
  char str[TEXTSIZE];   // string to print in
  float wy;             // Y value of line being printed

  glColor3f(1.0f, 1.0f, 1.0f);
  wy = (float)height;

  snprintf(str, TEXTSIZE, "METRICS");
  drawString(20.0f, (wy -= 20.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "action commands executed successfully: %d",
	   actionCommandsExecuted);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "other commands executed successfully: %d",
	   otherCommandsExecuted);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  if (commands.size() == 0)
    {
      snprintf(str, TEXTSIZE, "objects located correctly: %d", locationGoods);
      drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);
    }
  snprintf(str, TEXTSIZE, "total robot distance moved: %.4lf %s",
	   (distanceTotal / robotLengthFactor), robotLengthUnits);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  if (commands.size() == 0)
    {
      snprintf(str, TEXTSIZE,
	       "total basic goal object distance moved: %.4lf %s",
	       (totalGoalDistance / robotLengthFactor), robotLengthUnits);
      drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);
    }

  snprintf(str, TEXTSIZE, "total execution time: %.2lf seconds",
	   totalExecutionTime);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "range errors: %d", rangeErrors);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "parse errors: %d", parseErrors);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "command sequence errors: %d", commandSequenceErrors);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "gripper use errors: %d", gripperUseErrors);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "tool change errors: %d", toolChangeErrors);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  if (commands.size() == 0)
    {
      snprintf(str, TEXTSIZE, "object location errors: %d", locationErrors);
      drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);
    }
  snprintf(str, TEXTSIZE, "total errors: %d",
	   (rangeErrors + commandSequenceErrors + gripperUseErrors + 
	    parseErrors + toolChangeErrors + locationErrors));
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "useless commands executed: %d", uselessCommands);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  if (commands.size() == 0)
    {
      snprintf(str, TEXTSIZE, "score: %f", score);
      drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);
    }

  snprintf(str, TEXTSIZE, "ROBOT SETTINGS");
  drawString(20.0f, (wy -= 20.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "robot length units: %s", robotLengthUnits);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "robot angle units: %s", robotAngleUnits);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "robot speed: %.4f %s/s",
	   (robotSpeed / robotLengthFactor), robotLengthUnits);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE,
	   "robot maximum speed: %.4f %s/s",
	   (robotMaxSpeed / robotLengthFactor), robotLengthUnits );
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "robot relative speed: %.2f%%",
	   robotRelSpeed);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE,
	   "robot acceleration: %.4f %s/s*s",
	   (robotAccel / robotLengthFactor), robotLengthUnits );
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE,
	   "robot maximum acceleration: %.4f %s/s*s",
	   (robotMaxAccel / robotLengthFactor), robotLengthUnits);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "robot relative acceleration: %.2f%%",
	   robotRelAccel);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "robot end angle tolerance: %.4f %s",
	   (robotEndAngleTol / robotAngleFactor), robotAngleUnits);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "robot end point tolerance : %.4f %s",
	   (robotEndPointTol / robotLengthFactor), robotLengthUnits);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "robot intermediate point tolerance : %.4f %s",
	   (robotIntPointTol / robotLengthFactor), robotLengthUnits);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "gripper is: %s",
	   ((nowModel->Robot->EndEffector == 0) ? "not on robot" :
	    robotGripperOpen ? "open" : "closed"));
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "tool changer is: %s",
	   (robotToolChangerOpen ? "open" : "closed"));
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "KITTING VIEWER SETTINGS");
  drawString(20.0f, (wy -= 20.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "grid spacing: %.4f %s",
	   (spacing / lengthFactor), lengthUnits);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "scoring file: %s", scoringFileName);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

}

/********************************************************************/

/* KittingViewer::putInDefaultPosition

Returned Value: none

Called By: KittingViewer::createKit

This sets the Point, XAxis, and ZAxis of the pose to (0,0,0), (1,0,0),
and (0,0,1), respectively.

*/

void KittingViewer::putInDefaultPosition( /* ARGUMENTS         */
 PoseLocationType * pose)                 /* the pose to reset */
{
  pose->Point->X->val = 0.0;
  pose->Point->Y->val = 0.0;
  pose->Point->Z->val = 0.0;
  pose->XAxis->I->val = 1.0;
  pose->XAxis->J->val = 0.0;
  pose->XAxis->K->val = 0.0;
  pose->ZAxis->I->val = 0.0;
  pose->ZAxis->J->val = 0.0;
  pose->ZAxis->K->val = 1.0;
}

/********************************************************************/

/* KittingViewer::putInOtherPosition

Returned Value: none

Called By:  KittingViewer::createKit

This sets the Point, XAxis, and ZAxis of the pose to those of the source.

*/

void KittingViewer::putInOtherPosition( /* ARGUMENTS                          */
 PoseLocationType * pose,               /* the pose to reset                  */
 PoseLocationType * source)             /* the source of values for resetting */
{
  pose->Point->X->val = source->Point->X->val;
  pose->Point->Y->val = source->Point->Y->val;
  pose->Point->Z->val = source->Point->Z->val;
  pose->XAxis->I->val = source->XAxis->I->val;
  pose->XAxis->J->val = source->XAxis->J->val;
  pose->XAxis->K->val = source->XAxis->K->val;
  pose->ZAxis->I->val = source->ZAxis->I->val;
  pose->ZAxis->J->val = source->ZAxis->J->val;
  pose->ZAxis->K->val = source->ZAxis->K->val;
}

/********************************************************************/

/* KittingViewer::readScoringFile

Returned Value: none

Called By: KittingViewer::init

This reads the scoring file if there is one and builds the
scoreKittingTree. If there is no scoring file, this sets up a default
scoreKittingTree.

*/

void KittingViewer::readScoringFile( /* ARGUMENTS                        */
 char * scoringFile)                 /* name of the scoring file to read */
{
  scoreKittingType * scorer;

  if (scoringFile)
    {
      strncpy(scoringFileName, scoringFile, TEXTSIZE);
      yyscin = fopen(scoringFile, "r");
      if (yyscin == 0)
	{
	  fprintf(stderr, "unable to open file %s for reading\n", scoringFile);
	  exit(1);
	}
      yyscparse();
      fclose(yyscin);
      printf("Scoring file read\n\n");
      scorer = scoreKittingTree->scoreKitting;
      if ((scorer->rightStuff->weight->val       <= 0) ||
	  (scorer->commandExecution->weight->val <= 0) ||
	  (scorer->uselessCommands->weight->val  <= 0) ||
	  (scorer->distance->weight->val         <= 0) ||
	  (scorer->time->weight->val             <= 0))
	{
	  fprintf(stderr, "At least one scoring weight must be positive\n");
	  exit(1);
	}
    }
  else
    {
      strncpy(scoringFileName, "none, using default scoring", TEXTSIZE);
      scoreKittingTree =
	new ScoreKittingFile
	(new XmlVersion(false),
	 new XmlHeaderForScoreKitting (new SchemaLocation(0,0)),
	 new scoreKittingType
	 (new factorValueOptType(new XmlBoolean("false"),
				 new XmlUnsignedInt("1"), 0),
	  new factorValueOptType(new XmlBoolean("true"),
				 new XmlUnsignedInt("1"), 0),
	  new factorValueOptType(new XmlBoolean("true"),
				 new XmlUnsignedInt("1"), 0),
	  new factorValueOptType(new XmlBoolean("true"),
				 new XmlUnsignedInt("1"), 0),
	  new factorValueReqType(new XmlBoolean("true"),
				 new XmlUnsignedInt("1"),
				 new valueFunctionType
				 (new XmlDouble("0.0"),
				  new nonNegativeReal(strdup("0.0")),
				  new nonNegativeReal(strdup("3.0")), 
				  new taperSideType(strdup("plus"))))));
    }
}

/********************************************************************/

/* KittingViewer::recordInitialPosition

Returned Value: none

Called By:KittingViewer::recordInitialPositions

This finds the initial position of a goal object if there is an object
in the initial objects with the same name and type. The initial
position is saved in the goal object as the first secondary position.
Only the point is saved.

The goalObject is known to be a part, parts tray, kit tray, or large
container.

*/

void KittingViewer::recordInitialPosition( /* ARGUMENTS                    */
 SolidObjectType * goalObject)             /* object to find initial pos for */
{
  SolidObjectType * initObject;   // initial object to compare with goalObject
  PointType * point;
  std::map<std::string, SolidObjectType *>::iterator iter;
  PoseLocationType * initPose;
  PoseLocationType * initPoseSave;
  
  iter = nowModel->allSolids.find(goalObject->Name->val);
  if (iter == nowModel->allSolids.end())
    return;
  initObject = iter->second;
  if ((dynamic_cast<PartType *>(goalObject) &&
       !dynamic_cast<PartType *>(initObject)) ||
      (dynamic_cast<PartsTrayType *>(goalObject) &&
       !dynamic_cast<PartsTrayType *>(initObject)) ||
      (dynamic_cast<KitTrayType *>(goalObject) &&
       !dynamic_cast<KitTrayType *>(initObject)) ||
      (dynamic_cast<LargeContainerType *>(goalObject) &&
       !dynamic_cast<LargeContainerType *>(initObject)))
    return;
  initPose = findSecondaryPose(initObject);
  initPoseSave = new PoseLocationType(); // makes a valid pose
  point = initPoseSave->Point;
  point->X->val = initPose->Point->X->val;
  point->Y->val = initPose->Point->Y->val;
  point->Z->val = initPose->Point->Z->val;
  goalObject->SecondaryLocation->push_back(initPoseSave);
}

/********************************************************************/

/* KittingViewer::recordInitialPosition

Returned Value: none

Called By:KittingViewer::init

This finds the initial positions of each basic object in allSolids. A
basic object is a solid object that is not comprised of other solid
objects. That is each Part, PartsTray, KitTray, or LargeContainer. The
allSolids argument is the goal objects when this is called by init.

*/

void KittingViewer::recordInitialPositions(
 std::map<std::string, SolidObjectType *> allSolids)
{
  std::map<std::string, SolidObjectType *>::iterator iter;

  for (iter = allSolids.begin(); iter != allSolids.end(); iter++)
    {
      if (dynamic_cast<PartType *>(iter->second) ||
	  dynamic_cast<PartsTrayType *>(iter->second) ||
	  dynamic_cast<KitTrayType *>(iter->second) ||
	  dynamic_cast<LargeContainerType *>(iter->second))
      recordInitialPosition(iter->second);
    }
}

/********************************************************************/

/* KittingViewer::redraw

Returned Value: none

Called By: buildDisplayList (in viewKitting.cc)

When this function is called, if a motion command is in progress, the
executeFlag will be false and the resetFlag will be true. If no motion
command is in progress, the executeFlag may be true or false and the
resetFlag will be false. If the execute flag is true, the call to
handleExecute may set the resetFlag to true.

*/

void KittingViewer::redraw() /* NO ARGUMENTS   */
{
  if (executeFlag)
    handleExecute();
  if (resetFlag)
    handleResets();
  drawWorkstation();
}

/********************************************************************/

/* KittingViewer::releaseObject

Returned Value: none

Called By: KittingViewer::executeOpenGripperCommand

This implements the effects of releasing a solid object B from a single cup
gripper. The gripper is holding the object when the function starts.

If all of the following hold:
1. The Z axis of B relative to the workstation is close to (0,0,1).
2. The bottom of B is at very nearly the same height as one of
   - the top of the worktable
   - the top of a part
   - the bottom of a large container
   - the bottom of a parts tray
   - the bottom of kit tray
3. B is a part, parts tray, or kit tray.
4. The shape of B is a BoxyShape.
5. The XY outline of B fits within the XY outline of the object R found
   in step 2 above.
6. The Z axis of R relative to the workstation is close to (0,0,1).

Then the primary location of B is made relative to R. The I component
of the X axis of B relative to R is found by taking the dot product of
the X axis of R relative to the workstation with the X axis of B
relative to the workstation. The J component of the X axis of B
relative to R is found by taking the cross product of the X axis of R
relative to the workstation with the X axis of B relative to the
workstation.

Otherwise, the primary location of B is made relative to the
workstation in the same place as B's secondary location.

Finally, if B is a part, the location of B is adjusted if necessary.
See the documentation of adjustPartLocation

This is putting the object directly on the surface it is near.

*/

void KittingViewer::releaseObject(     /*  ARGUMENTS                  */
 VacuumEffectorSingleCupType * single, /* gripper releasing object    */
 SolidObjectType * solid)              /* solid object being released */
{
  PoseLocationType * refSecondaryPose;
  PoseLocationType * solidPrimaryPose;
  PoseLocationType * solidSecondaryPose;
  double xOffset; // X offset of solid from refSolid origin in refSolid coords
  double yOffset; // Y offset of solid from refSolid origin in refSolid coords
  double zOffset; // Z offset of solid from refSolid origin in refSolid coords
  SolidObjectType * refSolid;     // new refThing for solid
  double solidXI;     // I component of solid X axis in workstation coords
  double solidXJ;     // J component of solid X axis in workstation coords
  double refXI;       // I component of refSolid X axis in workstation coords
  double refXJ;       // J component of refSolid X axis in workstation coords
  
  solidSecondaryPose = findSecondaryPose(solid); // never 0
  solidPrimaryPose = findPrimaryPose(solid);
  
  single->refFor.remove(solid);
  if (solidPrimaryPose &&
      (refSolid = findSurface(solidSecondaryPose->Point->X->val,
			      solidSecondaryPose->Point->Y->val,
			      solidSecondaryPose->Point->Z->val,
			      solid, &xOffset, &yOffset, &zOffset)))
    {
      refSecondaryPose = findSecondaryPose(refSolid); // never 0
      refXI = refSecondaryPose->XAxis->I->val;
      refXJ = refSecondaryPose->XAxis->J->val;
      solidXI = solidSecondaryPose->XAxis->I->val;
      solidXJ = solidSecondaryPose->XAxis->J->val;
      solid->refThing = refSolid;
      refSolid->refFor.push_back(solid);
      solidPrimaryPose->RefObject->val = refSolid->Name->val;
      solidPrimaryPose->Point->X->val = xOffset;
      solidPrimaryPose->Point->Y->val = yOffset;
      solidPrimaryPose->Point->Z->val = zOffset;
      solidPrimaryPose->ZAxis->I->val = 0.0;
      solidPrimaryPose->ZAxis->J->val = 0.0;
      solidPrimaryPose->ZAxis->K->val = 1.0;
      solidPrimaryPose->XAxis->I->val = ((refXI * solidXI)+(refXJ * solidXJ));
      solidPrimaryPose->XAxis->J->val = ((refXI * solidXJ)-(refXJ * solidXI));
      solidPrimaryPose->XAxis->K->val = 0;
    }
  else
    {
      solid->refThing = nowModel;
      nowModel->refFor.push_back(solid);
      solidPrimaryPose->RefObject->val = solidSecondaryPose->RefObject->val;
      solidPrimaryPose->Point->X->val = solidSecondaryPose->Point->X->val;
      solidPrimaryPose->Point->Y->val = solidSecondaryPose->Point->Y->val;
      solidPrimaryPose->Point->Z->val = solidSecondaryPose->Point->Z->val;
      solidPrimaryPose->ZAxis->I->val = solidSecondaryPose->ZAxis->I->val;
      solidPrimaryPose->ZAxis->J->val = solidSecondaryPose->ZAxis->J->val;
      solidPrimaryPose->ZAxis->K->val = solidSecondaryPose->ZAxis->K->val;
      solidPrimaryPose->XAxis->I->val = solidSecondaryPose->XAxis->I->val;
      solidPrimaryPose->XAxis->J->val = solidSecondaryPose->XAxis->J->val;
      solidPrimaryPose->XAxis->K->val = solidSecondaryPose->XAxis->K->val;
    }
  if (dynamic_cast<PartType *>(solid))
    {
      adjustPartLocation(dynamic_cast<PartType *>(solid),
			 refSolid, solidPrimaryPose);
    }
  else if (dynamic_cast<KitType *>(solid))
    {
      adjustKitLocation(dynamic_cast<KitType *>(solid),
			refSolid, solidPrimaryPose);
    }
}

/********************************************************************/

/* KittingViewer::relocateTray

Returned Value: none

Called By: KittingViewer::executeCloseGripperCommand

When this is called, a portion of the location chain looks like

    something --> supply --> tray

This cuts the supply out of the chain so that when the function is done
the chain is:

    something --> tray

The tray is in the same place with respect to the something as the supply,
so the details for the supply location are copied into the tray location.

*/

void KittingViewer::relocateTray( /*  ARGUMENTS                   */
 PartsTrayWithPartsType * supply) /* empty part supply to cut out */
{
  PartsTrayType * tray;
  PoseLocationType * trayPose;
  PoseLocationType * supplyPose;

  tray = supply->PartsTray;
  supply->refThing->refFor.push_back(tray);
  tray->refThing = supply->refThing;
  supply->refThing->refFor.remove(supply);
  nowModel->allSolids.erase(supply->Name->val);
  trayPose = findPrimaryPose(tray);
  supplyPose = findPrimaryPose(supply);
  trayPose->RefObject->val = supplyPose->RefObject->val;
  trayPose->Point->X->val = supplyPose->Point->X->val;
  trayPose->Point->Y->val = supplyPose->Point->Y->val;
  trayPose->Point->Z->val = supplyPose->Point->Z->val;
  trayPose->XAxis->I->val = supplyPose->XAxis->I->val;
  trayPose->XAxis->J->val = supplyPose->XAxis->J->val;
  trayPose->XAxis->K->val = supplyPose->XAxis->K->val;
  trayPose->ZAxis->I->val = supplyPose->ZAxis->I->val;
  trayPose->ZAxis->J->val = supplyPose->ZAxis->J->val;
  trayPose->ZAxis->K->val = supplyPose->ZAxis->K->val;
}

/********************************************************************/

/* KittingViewer::resetPositions

Returned Value: none

Called By: KittingViewer::redraw

This sets the current position and the primary position of the robot.
If the robot is holding a gripper, this also sets the primary postion
of that gripper. The position of the gripper relative to the
workstation will be found in updateWorkstationPosition when
drawWorkstation starts. This function is called only when a robot
motion command has just finished executing.

The primary position of a gripper on the robot is always relative to
the robot and has its point at (0,0,0), so that point is not reset.
The Z axis of the robot is always (0,0,-1) while the X axis is always
(1,0,0), so the signs of the K components of the gripper X axis and Z
axis need to be reversed to be relative to the robot.

*/

void KittingViewer::resetPositions( /*  ARGUMENTS                   */
 double x,                          /* X value of controlled point  */
 double y,                          /* Y value of controlled point  */
 double z,                          /* Z value of controlled point  */
 double xi,                         /* I value of controlled X axis */
 double xj,                         /* J value of controlled X axis */
 double xk,                         /* K value of controlled X axis */
 double zi,                         /* I value of controlled Z axis */
 double zj,                         /* J value of controlled Z axis */
 double zk)                         /* K value of controlled Z axis */
 
{
  EndEffectorType * effector;
  VacuumEffectorType * vacEffector;
  PoseLocationType * vacEffectorPose;
  PoseLocationType * robotPose;
  double length;

  nowX = x;
  nowY = y;
  nowZ = z;
  nowXAxisI = xi;
  nowXAxisJ = xj;
  nowXAxisK = xk;
  nowZAxisI = zi;
  nowZAxisJ = zj;
  nowZAxisK = zk;
  robotPose = findPrimaryPose(nowModel->Robot);
  if ((effector = nowModel->Robot->EndEffector) && 
      (vacEffector = dynamic_cast<VacuumEffectorType *>(effector)))
    {
      length = vacEffector->Length->val;
      vacEffectorPose = findPrimaryPose(vacEffector);
      vacEffectorPose->XAxis->I->val = nowXAxisI;
      vacEffectorPose->XAxis->J->val = nowXAxisJ;
      vacEffectorPose->XAxis->K->val = -nowXAxisK;
      vacEffectorPose->ZAxis->I->val = nowZAxisI;
      vacEffectorPose->ZAxis->J->val = nowZAxisJ;
      vacEffectorPose->ZAxis->K->val = -nowZAxisK;
      robotPose->Point->X->val = (nowX - (length * nowZAxisI));
      robotPose->Point->Y->val = (nowY - (length * nowZAxisJ));
      robotPose->Point->Z->val = (nowZ - (length * nowZAxisK));
    }
  else
    { // controlled point is end point of robot quill
      robotPose->Point->X->val = nowX;
      robotPose->Point->Y->val = nowY;
      robotPose->Point->Z->val = nowZ;	      
    }
}

/********************************************************************/

/* KittingViewer::setExecuteFlag

Returned Value: none

Called By: keyboard (in viewKitting.cc)

*/

void KittingViewer::setExecuteFlag( /* ARGUMENTS                             */
 bool setting)                      /* true=execute next command, false=wait */
{
  executeFlag = setting;
}

/********************************************************************/

/* KittingViewer::setColorAndSku

Returned Value: none

Called By: KittingViewer::setLocationsAndColors

Fixed SolidObjectTypes (except the robot) have a bluish color.
 - WorkTableType
 - EndEffectorChangingStationType
 - EndEffectorHolderType

Active SolidObjectTypes have a reddish color.
 - RobotType (but its color is not assigned here)
 - EndEffectorType

Movable SolidObjectTypes that are not composed of other solid objects have
a greenish color.
 - PartType, PartsTrayType, PartsBinType, LargeContainerType, and KitTrayType

SolidObjectTypes that are composed of other SolidObjectTypes do not
have their own color.

The OtherObstacles of a KittingWorkstationType are not SolidObjectTypes.

Those SolidObjectTypes that are instances of the same SKU are given the
same color. This includes: KitTrayType, PartsTrayType, LargeContainerType,
and PartType. To implement this, each StockKeepingUnitType has a color,
and its green component is initialized to zero in the constructor.
If the SKU of the object already has a color with its green component
greater than zero, the object is given that color. Otherwise, another
greenish color is made, and that color is assigned to both the object
and its SKU. The PartsBinType does not have a SKU.

*/

void KittingViewer::setColorAndSku(        /* ARGUMENTS                     */
 SolidObjectType * object,                 /* object for which to set color */
 std::list<StockKeepingUnitType *> * Skus) /* all SKUs in nowModel          */
{
  XmlIDREF * skuName;
  KitTrayType * kitTray;
  PartsTrayType * partsTray;
  LargeContainerType * largeContainer;
  PartType * part;
  StockKeepingUnitType * sku;

  if ((dynamic_cast<WorkTableType *>(object)) ||
      (dynamic_cast<EndEffectorChangingStationType *>(object)) ||
      (dynamic_cast<EndEffectorHolderType *>(object)))
    makeBlueColor(&(object->color));
  else if (dynamic_cast<PartsBinType *>(object))
    makeGreenColor(&(object->color));
  else if ((((kitTray = dynamic_cast<KitTrayType *>(object))) &&
	    ((skuName = kitTray->SkuName))) ||
	   (((partsTray = dynamic_cast<PartsTrayType *>(object))) &&
	    ((skuName = partsTray->SkuName))) ||
	   (((largeContainer = dynamic_cast<LargeContainerType *>(object))) &&
	    ((skuName = largeContainer->SkuName))) ||
	   (((part = dynamic_cast<PartType *>(object))) &&
	    ((skuName = part->SkuName))))
    {
      sku = findSku(skuName, Skus); // never null
      object->sku = sku;
      if (sku->color.g > 0.0f)
	object->color = sku->color;
      else
	{
	  makeGreenColor(&(object->color));
	  sku->color = object->color;
	}
    }
  else if (dynamic_cast<EndEffectorType *>(object))
    makeRedColor(&(object->color));
  else if (dynamic_cast<RobotType *>(object))
    makeRedColor(&(object->color));
}

/********************************************************************/

/* KittingViewer::setLocationsAndColors

Returned Value: none

Called By:  KittingViewer::init

This adds the location of each solid object in the allSolids relative to the
workstation to the beginning of the solid object's secondary locations
list. This is done so that the graphics system does not need to do
a lot of transformations. This also assigns a color to each solid object
in the allSolids that is supposed to have one.

*/

void KittingViewer::setLocationsAndColors(           /* ARGUMENTS            */
 std::map<std::string, SolidObjectType *> allSolids) /* map of solid objects */
{
  std::map<std::string, SolidObjectType *>::iterator iter;
  for (iter = allSolids.begin(); iter != allSolids.end(); iter++)
    {
      setWorkstationLocation(iter->second);
      setColorAndSku(iter->second, nowModel->Sku);
    }
}

/********************************************************************/

/* KittingViewer::setNetTransform

Returned Value: none

Called By: KittingViewer::setWorkstationLocation

This finds the origin, xAxis, and zAxis for the newPose that are the
net effect of the locations in the location stack. This is a product
of pose matrices representing rigid transformations. The newPose has
the workstation as its reference object. If an element of the
locationStack is a relativePosition, then the no move pose is
imagined to represent it, and no matrix multiplication is required
for that element. The poses on the locationStack are used left to right.

It is assumed that when this is called, newPose is set to the no-move
pose (origin=(0,0,0), xAxis=(1,0,0), zAxis=(0,0,1)).

If there are three or more elements on the locationStack, there is a
minor problem in dealing with intermediate poses. Hence, a place to
store an intermediate pose (idler) is used, and results are placed
alternately in either newPose or idler. If the number of elements is
even, newPose is used first, and if the number of elements is odd,
idler is used first. That way the final result is in newPose where we
want it. The swapping back and forth is done using the poseToSet
pointer and makes the function a bit baroque.

The function is also baroque because the locationStack has
PhysicalLocationType elements that may be poses, and it necessary to
cast them into poses if they are poses. A PhysicalLocationType is
always either a PoseLocationType (i.e., a pose) or a RelativeLocationType
(i.e., it is relative).

1. If there is only one element on the locationStack, then the reference
   object is the workstation and:
1A. If the element is a pose, copy it into newPose.
1B. Otherwise (the element is relative) do nothing. The numbers for the
    no-move pose are already in the newPose.
1C. Return.

2. Otherwise, go on.

3. There are at least two elements on the locationStack.
3A. Set poseToSet to newPose if the number of elements is even and to
    &idler if the number of elements is odd.
3B. If the first element of the locationStack is a pose, set pose1
    to the first element of the locationStack, pop the location stack and
3B1. If the new first element is a pose, set pose2 to the new
     first element, and set poseToSet to the product of pose1 and pose2.
3B2. Otherwise (the new first element of the location stack (which was
     formerly the second element) is relative), set poseToSet to pose1.
3C. Otherwise (the first element of the locationStack is relative),
    pop it off the locationStack and:
3C1. If the new first element is a pose) copy it into poseToSet.
3C2. Otherwise (the new first element of the location stack (which was formerly
     the second element) is relative, copy the no-move pose into poseToSet.
3D. Pop the new first element off the locationStack.

4. While there are more elements on the stack:
4A. Set pose1 to poseToSet.
4B. Set poseToSet to the other one of newPose and &idler.
4C1. If the first element of the locationStack is a pose, set pose2 
     to the first element of the locationStack and set poseToSet
     to the product of pose1 and pose2.
4C2. Otherwise (the first element of the locationStack is a relative
     position), copy pose1 into poseToSet.
4D. Pop the locationStack.

This is currently assuming that the axis vectors are normalized.

This is duplicating the names of points and vectors, which are xs:ID
in XML data files. It is also assigning null names. Hence, the
modified model should not be printed back into an XML data file.

*/

void KittingViewer::setNetTransform(                /* ARGUMENTS            */
 PoseLocationType * newPose,                        /* pose to set          */
 std::list<PhysicalLocationType *> * locationStack) /* locations to compose */
{
  PoseLocationType * poseToSet; // set alternately to newPose or &idler
  PoseLocationType * pose1;     // first pose for finding product pose
  PoseLocationType * pose2;     // second pose for finding product pose
  static XmlDecimal px(0.0);
  static XmlDecimal py(0.0);
  static XmlDecimal pz(0.0);
  static XmlDecimal xi(1.0);
  static XmlDecimal xj(0.0);
  static XmlDecimal xk(0.0);
  static XmlDecimal zi(0.0);
  static XmlDecimal zj(0.0);
  static XmlDecimal zk(1.0);
  static PointType point(0, &px, &py, &pz);
  static VectorType xAxis(0, &xi, &xj, &xk);
  static VectorType zAxis(0, &zi, &zj, &zk);
  static PoseLocationType idler(0, 0, &point, &xAxis, &zAxis); // see above
  int n; // use int since size_T not working normally with % (mod)

  if (locationStack->size() == 0)
    {
      fprintf(stderr, "bug in setNetTransform\n");
      exit(1);
    }
  if (locationStack->size() == 1)
    { // the pose is relative to the workstation when stack size is 1
      if ((pose1 = dynamic_cast<PoseLocationType *>(locationStack->front())))
	{
	  *(newPose->Point) = *(pose1->Point);
	  *(newPose->XAxis) = *(pose1->XAxis);
	  *(newPose->ZAxis) = *(pose1->ZAxis);
	} // if not, the newPose is already set to the no move pose
      return;
    }
  n = locationStack->size();
  poseToSet = ((n % 2) ? &idler : newPose);
  if ((pose1 = dynamic_cast<PoseLocationType *>(locationStack->front())))
    { // the first element is a pose
      locationStack->pop_front();
      if ((pose2 = dynamic_cast<PoseLocationType *>(locationStack->front())))
	{ // the second element is a pose
	  poseProduct(poseToSet, pose1, pose2);
	}
      else
	{ // the second element is a relative position
	  *(poseToSet->Point) = *(pose1->Point);
	  *(poseToSet->XAxis) = *(pose1->XAxis);
	  *(poseToSet->ZAxis) = *(pose1->ZAxis);
	}
    }
  else
    { // the first element is a relative position
      locationStack->pop_front();
      if ((pose2 = dynamic_cast<PoseLocationType *>(locationStack->front())))
	{ // the second element is a pose
	  *(poseToSet->Point) = *(pose2->Point);
	  *(poseToSet->XAxis) = *(pose2->XAxis);
	  *(poseToSet->ZAxis) = *(pose2->ZAxis);
	}
      else
	{ // the second element is a relative position
	  *(poseToSet->Point) = point;
	  *(poseToSet->XAxis) = xAxis;
	  *(poseToSet->ZAxis) = zAxis;
	}
    }
  locationStack->pop_front();
  while (locationStack->size())
    {
      pose1 = poseToSet;
      poseToSet = ((poseToSet == newPose) ? &idler : newPose);
      if ((pose2 = dynamic_cast<PoseLocationType *>(locationStack->front())))
	{
           poseProduct(poseToSet, pose1, pose2);
	}
      else
	{ // the first element of the locationStack is a relative position
	  *(poseToSet->Point) = *(pose1->Point);
	  *(poseToSet->XAxis) = *(pose1->XAxis);
	  *(poseToSet->ZAxis) = *(pose1->ZAxis);
	}
      locationStack->pop_front();
    }
}

/********************************************************************/

/* KittingViewer::setWorkstationLocation

Returned Value: none

Called By:  KittingViewer::setLocationsAndColors

This finds the chain of primary locations leading from the object back
to the workstation (locationStack) and uses it to find the location of
the object relative to the workstation. That location is inserted as
the first element of the object's list of secondary locations.

If a location found while tracing the chain is a relative location, a
pose location with same origin and orientation as the reference object
is put on the stack instead of the relative location.

While the function is constructing the locationStack, it also adds the
object to the refFor list of the refThing and sets object->refThing
to refThing.

This function might be moved to kittingClassesView.cc since it deals
only with kittingClasses information. On the other hand, it is the
kittingViewer that needs the information.

This function will not return if there is a loop of reference objects.
Might add a check for that. The locationStack would grow until memory
is exhausted.

*/

void KittingViewer::setWorkstationLocation( /* ARGUMENTS        */
 SolidObjectType * object)                  /* object to locate */
{
  std::list<PhysicalLocationType *> locationStack;
  std::map<std::string, SolidObjectType *>::iterator iter;
  SolidObjectType * refThing;
  std::string refObjectName;
  XmlIDREF * ref;
  PoseLocationType * newPose;
  
  locationStack.push_front(object->PrimaryLocation);
  ref = object->PrimaryLocation->RefObject;
  refObjectName = ref->val;
  iter = nowModel->allSolids.find(refObjectName);
  refThing = iter->second;
  refThing->refFor.push_back(object);
  object->refThing = refThing;
  while (dynamic_cast<KittingWorkstationType *>(refThing) == 0)
    {
      locationStack.push_front(refThing->PrimaryLocation);
      ref = refThing->PrimaryLocation->RefObject;
      refObjectName = ref->val;
      iter = nowModel->allSolids.find(refObjectName);
      refThing = iter->second;
    }
  newPose = new PoseLocationType();
  newPose->RefObject = ref;
  setNetTransform(newPose, &locationStack);
  object->SecondaryLocation->push_front(newPose);
}

/********************************************************************/

/*  KittingViewer::solidIsMovable

Returned Value: none

Called By:
  KittingViewer::handleExecute

*/

bool KittingViewer::solidIsMovable( /* ARGUMENTS                */
 SolidObjectType * solid)           /* the solid object to test */
{
  return (dynamic_cast<PartType *>(solid)                      ||
	  dynamic_cast<KitType *>(solid)                       ||
	  dynamic_cast<KitTrayType *>(solid)                   ||
	  dynamic_cast<PartsTrayType *>(solid)                 ||
	  dynamic_cast<PartsTrayWithPartsType *>(solid)        ||
	  dynamic_cast<LargeBoxWithKitsType *>(solid)          ||
	  dynamic_cast<LargeBoxWithEmptyKitTraysType *>(solid) ||
	  dynamic_cast<LargeContainerType *>(solid));
}

/********************************************************************/

/* KittingViewer::updateWorkstationPosition

Returned Value: none

Called By:
  KittingViewer::drawWorkstation
  KittingViewer::updateWorkstationPosition (recursively)

This updates the first SecondaryLocation of an object; that's the one
that gets inserted by setWorkstationLocation when kittingViewer starts up.
Then it calls itself recursively to update the secondary positions of all
objects in the refFor list of the object.

The first SecondaryLocation always gives the position of an object in
the workstation coordinate system.

The parentPose should be the pose of the refThing of the object.

*/

void KittingViewer::updateWorkstationPosition( /* ARGUMENTS                  */
 SolidObjectType * object,                /* object for which to update pose */
 PoseLocationType * parentPose)           /* pose of parent in workstation   */
{
  std::list<SolidObjectType *>::iterator iter;
  PoseLocationType * workstationPose;          // pose of object in workstation
  PoseLocationType * relativePose;             // pose of object rel to parent

  workstationPose = findSecondaryPose(object); // never 0
  relativePose = findPrimaryPose(object); // never 0
  poseProduct(workstationPose, parentPose, relativePose);
  /*
  printf("parent (Pt %.2f %.2f %.2f) (X %.2f %.2f %.2f) (Z %.2f %.2f %.2f)\n",
	 parentPose->Point->X->val, parentPose->Point->Y->val,
	 parentPose->Point->Z->val, parentPose->XAxis->I->val,
	 parentPose->XAxis->J->val, parentPose->XAxis->K->val,
	 parentPose->ZAxis->I->val, parentPose->ZAxis->J->val,
	 parentPose->ZAxis->K->val);
  printf("relative (Pt %.2f %.2f %.2f) (X %.2f %.2f %.2f) (Z %.2f %.2f %.2f)\n",
	 relativePose->Point->X->val, relativePose->Point->Y->val,
	 relativePose->Point->Z->val, relativePose->XAxis->I->val,
	 relativePose->XAxis->J->val, relativePose->XAxis->K->val,
	 relativePose->ZAxis->I->val, relativePose->ZAxis->J->val,
	 relativePose->ZAxis->K->val);
  printf("workstation (Pt %.2f %.2f %.2f) (X %.2f %.2f %.2f) (Z %.2f %.2f %.2f)\n\n",
	 workstationPose->Point->X->val, workstationPose->Point->Y->val,
	 workstationPose->Point->Z->val, workstationPose->XAxis->I->val,
	 workstationPose->XAxis->J->val, workstationPose->XAxis->K->val,
	 workstationPose->ZAxis->I->val, workstationPose->ZAxis->J->val,
	 workstationPose->ZAxis->K->val);
  */
  for (iter = object->refFor.begin(); iter != object->refFor.end(); iter++)
    {
      updateWorkstationPosition(*iter, workstationPose);
    }
}

/********************************************************************/

/* usageMessage

Returned Value: none

Called By: main

This prints a message about how to use kittingViewer.

*/

void usageMessage( /* ARGUMENTS                                             */
 char * command)   /* command with which the user started the kittingViewer */
{
  fprintf(stderr,
	  "usage: %s <commandFile> <initFile> <goalFile> [<scoringFile>]\n",
	  command);
  fprintf(stderr,
	  "commandFile is the name of a file of canonical robot commands\n");
  fprintf(stderr,
	  "initFile and goalFile are the names of XML "
	  "kitting workstation files\n");
  fprintf(stderr,
	  "scoringFile is the name of an XML file for scoring\n");
  fprintf(stderr,
	  "Example1: %s commands init.xml goal.xml\n",
	  command);
  fprintf(stderr,
	  "Example2: %s commands init.xml goal.xml scoring.xml\n",
	  command);
  exit(1);
}

/********************************************************************/

/* KittingViewer::valuate

Returned Value: double
  This returns the result of applying the valueFunction to the val.

Called By: KittingViewer::computeScore

A value function has one of the following three forms (graphs on a
standard Cartesian plane), depending on the value of taperSide. In all
three, the upper value is 1, and the lower value is zero.

              ____
minus    ____/

         ____
plus         \____

          ___
both ____/   \____


The slope of the slopes in the functions is controlled by the value of
taper in the value function.

For "plus" and "minus", the "best" value is is the X value of the
point at the upper end of the slope. For "both" the "best" value is
the X value of the point in the middle of the mesa.

*/

double KittingViewer::valuate( /* ARGUMENTS                 */
 valueFunctionType * fun,      /* the value function to use */
 double val)                   /* the input X value         */
{
  static double best;
  static double taper;
  static double right;
  static double left;

  best = fun->bestValue->val;
  taper = fun->taper->val;
  if (strcmp(fun->taperSide->val.c_str(), "minus") == 0)
    {
      if (taper == 0.0)
	return ((val >= best) ? 1.0 : 0.0);
      else if (val < (best - taper))
	return 0.0;
      else if (val > best)
	return 1.0;
      else // in between
	return (1.0 - ((best - val) / taper));
    }
  else if (strcmp(fun->taperSide->val.c_str(), "plus") == 0)
    {
      if (taper == 0.0)
	return ((val <= best) ? 1.0 : 0.0);
      else if (val < best)
	return 1.0;
      else if (val > (best + taper))
	return 0.0;
      else // in between
	return (1.0 - ((val - best) / taper));
    }
  else if (strcmp(fun->taperSide->val.c_str(), "both") == 0)
    {
      right = (best + (fun->width->val / 2));
      left  = (best - (fun->width->val / 2));
      if (taper == 0.0)
	return ((val < left) ? 0.0 : (val > right) ? 0.0 : 1.0);
      else if (val < (left - taper))
	return 0.0;
      else if (val < left)
	return (1.0 - ((left - val) / taper));
      else if (val < right)
	return 1.0;
      else if (val < (right + taper))
	return (1.0 - ((val - right) / taper));
      else // if (val >= (right + taper))
	return 0.0;
    }
  else
    {
      fprintf(stderr, "bad taperSide %s in a valueFunctionType\n",
	      fun->taperSide->val.c_str());
      exit(1);
    }
  return 0.0;
}

/********************************************************************/

/* main

Returned Value: int

This is the main function for the kittingViewer. It:
1. reads the arguments.
2. calls kittingViewer::init, which reads the command file, the initial
   state file and the goal state file; init also sets up the initial
   kittingViewer model.
3. prints information about how to use kittingViewer.
4. calls glInit, which sets up the three windows and their initial contents.
5. enters the glutMainLoop, which handles all user interaction and draws
   the display.

If the command is bad, a usage message is printed and kittingViewer exits.

*/

int main(       /* ARGUMENTS                              */
 int argc,      /* number of command arguments plus one   */
 char * argv[]) /* array of command and command arguments */
{
  if (argc == 4) 
    KittingViewer::init(argv[1], argv[2], argv[3], 0);
  else if (argc == 5)
    KittingViewer::init(argv[1], argv[2], argv[3], argv[4]);
  else
    usageMessage(argv[0]);
  printf("Press r to toggle left mouse button "
	 "between translating and rotating\n");
  printf("Hold down left mouse button and move mouse "
	 "to translate or rotate workstation\n");
  printf("Hold down middle mouse button and move mouse "
	 "to rotate workstation\n");
  printf("Hold down right mouse button and move mouse "
	 "up/dn to zoom workstation\n");
  printf("Press h to return to the default view\n");
  printf("Press g to execute the next command\n");
  printf("Press t to save the current image in a ppm file\n");
  printf("Press z or q to exit\n");
  glInit(argc, argv, "Kitting Viewer");
  glutMainLoop();
  
  return 0;
}

/********************************************************************/

