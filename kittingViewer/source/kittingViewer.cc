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
  \date March 14, 2013

*/

/* TODO

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

11. Use shape data from an external file (identified by an ExternalShape).

12. Expand functionality to include collision checking. Use a solid modeler.

13. Implement other gripper types and geometries.

14. Make the graphics fancier (lighting, textures, etc.)

15. Give some credit in the metrics when an object has the correct secondary
location (i.e. is at the correct place in the workstation) even if the
primary location is incorrect. Currently there is no credit for that.

*/

/*

What the Kitting Viewer Does
----------------------------

See Users Manual.

Units
-----

Kitting Viewer internal values for length units are always millimeters.
Internal values for angle units are always degrees. Internal values
for weight units are always grams.

The robot has a robotLengthUnits, a robotLengthFactor, a
robotAngleUnits, and a robotAngleFactor. Initially, the Kitting Viewer
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
Kitting Viewer, the location of the robot is the location of the quill
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

Kinematics, Speed, and Acceleration
-----------------------------------

Kinematics are built into the Kitting Viewer for a gantry robot that can
hold a gripper of fixed length, can rotate the axis of the gripper and
can rotate the gripper around its axis. The ROBOTDEFAULTMAXACCEL and 
ROBOTDEFAULTMAXSPEED apply to the end of the quill of the robot (whether
a gripper is attached or not). The GRIPPERDEFAULTMAXROTATE applies to
both gripper rotations.

There are no canonical robot commands for gripper rotational speed, so the
Kitting Viewer sets the gripper rotational speed to a fraction of the maximum
rotational speed that is the same as the fraction used for the robot speed.

The gripper is treated as having a built-in X axis that is perpendicular
to the gripper Z axis. The X axis of the gripper is parallel to the X-axis
of the holder when the gripper is in a gripper holder. If a gripper starts
out on the robot, its Z axis is assumed to be antiparallel to the robot Z
axis, and its X axis is assumed to be parallel to the robot X axis.

Any change of position may include a translation and two rotations. The time
for a change of position is calculated as the longest time for any of the
three.

Command Execution
-----------------

Command execution is handled by the executeCommand function, which in most
cases calls a subordinate function that handles the specific type of 
command.

Several of these commands run sanity checks on their arguments. The three
move commands trigger the Kitting Viewer to save data for animation. If a
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

Dealing with Identical Objects
------------------------------

It is often desirable to treat objects as being identical. For
example, we may want two part A's in a kit in particular places, but we
don't care which part A is in which place. On other occasions we may care
which part A is where. The Kitting Viewer deals with this by having the
swap boolean which the user may set. If swap is set to true, kits with
the same DesignName and other objects with the same SkuName are
treated as identical for purposes of checking locations. This is
implemented as follows.

In handleExecute, after executing all the commands, if swap is true, a
map, skuGoalMap, is made from SkuNames to lists of the locations of
goal objects with the same SkuName. Another map, kitGoalMap is made
from kit DesignNames to lists of the locations of goal kits with the
same DesignName.

Later, when the location of an object is being checked, if swap is
true and the object has a SkuName or is a kit, the location is checked
against the list of locations for items of that name. It is an error
if a nearly identical location is not on the list. If a nearly
identical location is on the list, it is removed from the list.

This method does not deal with LargeBoxWithEmptyKitTrays, LargeBoxWithKits,
or PartsTrayWithParts.

Changing the Speed of Animation
-------------------------------

To change the speed of the animation, the user may use the 'f' (faster) and
's' (slower) keys. Two taps of the 'f' key doubles the apparent speed of
the robot, and two taps of the 's' key cuts the speed in half. The
programmed speed of the robot is not changed. The speed up is done by
changing the speed of a pseudo elapsed time clock. Changing the speed
of the animation has no effect on the metrics and settings (including
the execution time).

The variable speed pseudo elapsed time clock is implemented in the
getPseudoElapsedTime function. This is done by maintaining (1) a
timeFactor whose initial value is 1, (2) the last real elapsed time
(in glutElapsedTime), and (3) the last pseudo elapsed time (in
pseudoElapsedTime). To find the current pseudo elapsed time,
getPseudoElapsedTime gets the current real elapsed time, subtracts
the last real elapsed time, multiplies the difference by the timeFactor,
and adds the product to the last saved pseudo elapsed time.

Position Checking
-----------------

For checking the position of objects there is a distance tolerance and a
vector tolerance for unit vectors and orthogonality. The distance tolerance
may be set using the -t option in the command that starts the Kitting Viewer.
The default value is TINYDISTANCE, a #define in this file currently set to
two tenths of a millimeter. The vector tolerance is not settable. Its value
is TINYVAL, also a #define in this file. It is currently set to 0.0001.

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
double              KittingViewer::anglesX[MAXPOSES]; // X rots corresp to poses
double              KittingViewer::anglesZ[MAXPOSES]; // Z rots corresp to poses
char                KittingViewer::angleUnits[TEXTSIZE]; // degree, radian
VectorIJK           KittingViewer::axlesZ[MAXPOSES]; //rot axes corresp to poses
bool                KittingViewer::checkingNotStarted; // true = not started
char *              KittingViewer::commandFile; // name of command file
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
double              KittingViewer::glutElapsedTime; //real elapsed time, secs
KittingWorkstationType * KittingViewer::goalModel; // model built from goal file
int                 KittingViewer::gripperUseErrors; // num gripper use errors
KittingWorkstationType * KittingViewer::initModel; // model built from init file
std::map<std::string, std::list<PoseLocationType *>*> KittingViewer::kitGoalMap;
char *              KittingViewer::kittingBuiltFile; // name of as-built file
char *              KittingViewer::kittingGoalFile; // name of goal state file
char *              KittingViewer::kittingInitFile; // name of init state file
double              KittingViewer::lengthFactor; // factor for length conversion
char                KittingViewer::lengthUnits[TEXTSIZE]; // meter, millim, inch
int                 KittingViewer::locationErrors; //number errors in obj loc'n
int                 KittingViewer::locationGoods; // number objs in right loc'n
int                 KittingViewer::motionErrors; //number of errors in motion
int                 KittingViewer::movableObjects; // number of movable objects
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
int                 KittingViewer::poseIndex; // index of poses and times arrays
Pose                KittingViewer::poses[MAXPOSES];// array of poses to move to
int                 KittingViewer::posesTotal; // total number poses to move to
double              KittingViewer::pseudoElapsedTime; //fake elapsed time, secs
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
PointType *         KittingViewer::robotPoint; // point at end of quill
double              KittingViewer::robotRelAccel; // relative acceleration
double              KittingViewer::robotRelSpeed; // relative speed setting
double              KittingViewer::robotSpeed;  // speed set in length units/sec
bool                KittingViewer::robotToolChangerOpen; // true=open, false=clo
bool                KittingViewer::swap; //true=same name obs may swap positions
float               KittingViewer::scale;     // scale to use to convert mm
double              KittingViewer::score;     // score for the command file
char *              KittingViewer::scoringFile; // name of scoring file, maybe 0
char                KittingViewer::scoringFileName[TEXTSIZE];//name scoring file
std::map<std::string, std::list<PoseLocationType *>*> KittingViewer::skuGoalMap;
float               KittingViewer::spacing;   // grid line spacing in meters
double              KittingViewer::timeFactor; //factor 4 speeding, slowing time
double              KittingViewer::times[MAXPOSES]; // times corresp. to poses
double              KittingViewer::tolerance; // location tolerance
int                 KittingViewer::toolChangeErrors; // total tool change errors
double              KittingViewer::totalExecutionTime; // total execution time
double              KittingViewer::totalGoalDistance; // total goal object dist
int                 KittingViewer::uselessCommands; // numbr cmds with no effect
double              KittingViewer::weightFactor; // factor for weight conversion
char                KittingViewer::weightUnits[TEXTSIZE]; // gram, pound, etc.

/********************************************************************/

extern KittingWorkstationFile * KittingWorkstationTree;
extern ScoreKittingFile * scoreKittingTree; // from scoreKittingYACC.cc
extern FILE * yyin;     // for init file and goal file
extern FILE * yyscin;   // for scoring file
extern int yyparse();   // for init file and goal file
extern int yyscparse(); // for scoring file

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

The goalObject here is a solid object from the goalModel.
If the goalObject is any of:
 KitType (DesignName)
 KitTrayType (SkuName)
 LargeBoxWithEmptyKitTraysType
 LargeBoxWithKitsType
 LargeContainerType (SkuName)
 PartType (SkuName)
 PartsTrayType (SkuName)
 PartsTrayWithPartsType
then its location is compared with that of the object of the same name
(nowObject) in the nowModel.

If any of the following errors occurs, this prints an error message and
increases locationErrors by 1.
1. There is no nowObject (i.e., no object of the same name in the nowModel).
2. The nowObject is a different type from the goalObject.
3a. The nowObject and goalObject have SkuNames and the names differ.
3b. The nowObject and goalObject are kits with different DesignNames.
4. The nowObject location cannot be matched with a goalObject location.

Otherwise, this increases locationGoods by 1.

This is called only to check on goal objects. This is not checking for
objects in the current environment that are not goal objects.

The location matching process differs according to the value of swap for
kits and objects with SkuNames. See documentation at the top of this file.

*/

void KittingViewer::checkLocation( /* ARGUMENTS                             */
 SolidObjectType * goalObject)     /* goal object to compare with nowObject */
{
  SolidObjectType * nowObject;       // now object to compare with goalObject
  std::map<std::string, SolidObjectType *>::iterator iter;
  std::string nowName;
  std::string goalName;

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
      nowName = dynamic_cast<PartType *>(nowObject)->SkuName->val;
      goalName = dynamic_cast<PartType *>(goalObject)->SkuName->val;
      if (nowName != goalName)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: sku name %s of goal part %s differs "
		   "from sku name %s of same-name current part",
		   goalName.c_str(), goalObject->Name->val.c_str(),
		   nowName.c_str());
	  locationErrors++;
	  return;
	}
      if (swap)
	checkLocationIdentical(nowObject, &skuGoalMap, nowName);
      else
	checkLocationUnique(goalObject, nowObject);
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
      nowName = dynamic_cast<KitType *>(nowObject)->DesignName->val;
      goalName = dynamic_cast<KitType *>(goalObject)->DesignName->val;
      if (nowName != goalName)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: design name %s of goal kit %s differs from "
		   "design name %s of same-name current kit",
		   goalName.c_str(), goalObject->Name->val.c_str(),
		   nowName.c_str());
	  locationErrors++;
	  return;
	}
      if (swap)
	checkLocationIdentical(nowObject, &kitGoalMap, nowName);
      else
	checkLocationUnique(goalObject, nowObject);
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
      nowName = dynamic_cast<KitTrayType *>(nowObject)->SkuName->val;
      goalName = dynamic_cast<KitTrayType *>(goalObject)->SkuName->val;
      if (nowName != goalName)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: sku name %s of goal kit tray %s differs "
		   "from sku name %s of same-name current kit tray",
		   goalName.c_str(), goalObject->Name->val.c_str(),
		   nowName.c_str());
	  locationErrors++;
	  return;
	}
      if (swap)
	checkLocationIdentical(nowObject, &skuGoalMap, nowName);
      else
	checkLocationUnique(goalObject, nowObject);
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
      nowName = dynamic_cast<PartsTrayType *>(nowObject)->SkuName->val;
      goalName = dynamic_cast<PartsTrayType *>(goalObject)->SkuName->val;
      if (nowName != goalName)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: sku name %s of goal parts tray %s differs "
		   "from sku name %s of same-name current parts tray",
		   goalName.c_str(), goalObject->Name->val.c_str(),
		   nowName.c_str());
	  locationErrors++;
	  return;
	}
      if (swap)
	checkLocationIdentical(nowObject, &skuGoalMap, nowName);
      else
	checkLocationUnique(goalObject, nowObject);
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
      checkLocationUnique(goalObject, nowObject);
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
      checkLocationUnique(goalObject, nowObject);
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
      checkLocationUnique(goalObject, nowObject);
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
      nowName = dynamic_cast<LargeContainerType *>(nowObject)->SkuName->val;
      goalName = dynamic_cast<LargeContainerType *>(goalObject)->SkuName->val;
      if (nowName != goalName)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: sku name %s of goal large container %s differs "
		   "from sku name %s of same-name current large container",
		   goalName.c_str(), goalObject->Name->val.c_str(),
		   nowName.c_str());
	  locationErrors++;
	  return;
	}
      if (swap)
	checkLocationIdentical(nowObject, &skuGoalMap, nowName);
       else
	checkLocationUnique(goalObject, nowObject);
    }
  else
    return;
}

/********************************************************************/

/* KittingViewer::checkLocationIdentical

Returned Value: none

Called By: KittingViewer::checkLocation

This looks through the goalMap (for kits or skus) for the list of
locations whose key is the given name.

If no list is found, that is a bug since the name is known to have a
corresponding list, so this prints an error message.

If a list is found and the location of the nowObject is nearly
identical to a location on the list, that location is removed from the
list, a success message is printed, and locationGoods is increased by
one. Otherwise, this prints an error message and adds one to
locationErrors.

*/

void KittingViewer::checkLocationIdentical(      /* ARGUMENTS            */
 SolidObjectType * nowObject,                    /* now object to check  */
 std::map<std::string, std::list<PoseLocationType *>*> * goalMap, /* map */
 std::string name)                               /* name to use for key  */
{
  std::map<std::string, std::list<PoseLocationType *>*>::iterator iter;
  std::list<PoseLocationType *> * locations;
  std::list<PoseLocationType *>::iterator ator;
  PoseLocationType * goalLocation;
  PoseLocationType * actualLocation;

  iter = goalMap->find(name);
  if (iter == goalMap->end())
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Bug: location list for %s is missing", name.c_str());
      return;
    }
  actualLocation = findPrimaryPose(nowObject);
  locations = iter->second;
  if (locations->size() == 0)
    {
      snprintf(commandString[0], TEXTSIZE, "Error: more current "
	       "objects than goal objects of the same type");
      locationErrors++;
      return;
    }
  for (ator = locations->begin(); ator != locations->end(); ator++)
    {
      goalLocation = *ator;
      if ((actualLocation->RefObject->val == goalLocation->RefObject->val) &&
	  checkPointAndAxes(goalLocation->Point, actualLocation->Point,
			    goalLocation->XAxis, actualLocation->XAxis,
			    goalLocation->ZAxis, actualLocation->ZAxis, 0))
	{ // found a matching location
	  locations->remove(goalLocation);
	  snprintf(commandString[0], TEXTSIZE, "%s is located correctly",
		   nowObject->Name->val.c_str());
	  locationGoods++;
	  return;
	}
    }
  snprintf(commandString[0], TEXTSIZE, "Error: %s is not located correctly",
	   nowObject->Name->val.c_str());
  locationErrors++;
}

/********************************************************************/

/* KittingViewer::checkLocationUnique

Returned Value: none

Called By:  KittingViewer::checkLocation

This checks the location of a unique object, i.e., an object that is
regarded as different from other objects with the same SKU.

*/

void KittingViewer::checkLocationUnique( /*  ARGUMENTS                   */
 SolidObjectType * goalObject,           /* goal object to check against */
 SolidObjectType * nowObject)            /* now object to chck           */
{
  PoseLocationType * goalLocation;
  PoseLocationType * actualLocation;

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
  nearly equal, this returns true. Otherwise, it returns false. If name
  is not null, this will also print an error message describing the
  first difference found and increase locationErrors by 1.

Called By:  KittingViewer::checkLocationUnique

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
  if ((fabs(actualPoint->X->val - goalPoint->X->val) > tolerance) ||
      (fabs(actualPoint->Y->val - goalPoint->Y->val) > tolerance) ||
      (fabs(actualPoint->Z->val - goalPoint->Z->val) > tolerance))
    {
      if (name)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: goal location Point (%.6f,%.6f,%.6f) of %s "
		   "differs from current location Point (%.6f,%.6f,%.6f)",
		   goalPoint->X->val, goalPoint->Y->val, goalPoint->Z->val,
		   name, actualPoint->X->val, actualPoint->Y->val,
		   actualPoint->Z->val);
	  locationErrors++;
	}
      return false;
    }
  if ((fabs(actualXAxis->I->val - goalXAxis->I->val) > TINYVAL) ||
      (fabs(actualXAxis->J->val - goalXAxis->J->val) > TINYVAL) ||
      (fabs(actualXAxis->K->val - goalXAxis->K->val) > TINYVAL))
    {
      if (name)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: goal location XAxis (%.6f,%.6f,%.6f) of %s "
		   "differs from current location XAxis (%.6f,%.6f,%.6f)",
		   goalXAxis->I->val, goalXAxis->J->val, goalXAxis->K->val,
		   name, actualXAxis->I->val, actualXAxis->J->val,
		   actualXAxis->K->val);
	  locationErrors++;
	}
      return false;
    }
  if ((fabs(actualZAxis->I->val - goalZAxis->I->val) > TINYVAL) ||
      (fabs(actualZAxis->J->val - goalZAxis->J->val) > TINYVAL) ||
      (fabs(actualZAxis->K->val - goalZAxis->K->val) > TINYVAL))
    {
      if (name)
	{
	  snprintf(commandString[0], TEXTSIZE,
		   "Error: goal location ZAxis (%.6f,%.6f,%.6f) of %s "
		   "differs from current location ZAxis (%.6f,%.6f,%.6f)",
		   goalZAxis->I->val, goalZAxis->J->val, goalZAxis->K->val,
		   name, actualZAxis->I->val, actualZAxis->J->val,
		   actualZAxis->K->val);
	  locationErrors++;
	}
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
is checked. That happens each time the e key is pressed until all
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
  static int n;                 // number of times this is called

  if (movableObjects == -1)
    { // reset to usable initial values
      n = 0;
      movableObjects = countMovableObjects();
    }
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
	      parseErrors + motionErrors + toolChangeErrors));
  totalGoalDistance += findDistance(object);
  fraction = ((double)n / (double)movableObjects);
  distanceValue = (((distanceTotal * fraction) == 0) ? 0 :
		   ((2.0 * totalGoalDistance) / (distanceTotal * fraction)));
  distanceValue = ((distanceValue > 1.0) ? 1.0 : distanceValue);
  timeValue = (((totalExecutionTime * fraction) == 0) ? 0 :
	       (((2.0 * totalGoalDistance) / robotMaxSpeed) /
		(totalExecutionTime * fraction)));
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
  setWorkstationLocation(newKit, nowModel->allSolids);
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

/* KittingViewer::drawMetricsAndSettings

Returned Value: none

Called By: displayMetricsWindow (in viewKitting.cc)

This draws the metrics, robot settings, and Kitting Viewer settings.
The text is drawn in the metricsWindow. The size and position of the
text do not change if the size of the metricsWindow is changed.
Instead, if the window is made larger there is more blank space, and
if the window is made smaller, some of the text is no longer visible.
The text is anchored at the upper left corner of the metrics window.

*/

void KittingViewer::drawMetricsAndSettings( /* ARGUMENTS                 */
 int height)                                /* side of screen, in pixels */
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

  snprintf(str, TEXTSIZE, "total robot distance moved: %.4lf %s",
	   (distanceTotal / robotLengthFactor), robotLengthUnits);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "total execution time: %.2lf seconds",
	   totalExecutionTime);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "useless commands executed: %d", uselessCommands);
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

  snprintf(str, TEXTSIZE, "motion errors: %d", motionErrors);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "total errors: %d",
	   (rangeErrors + commandSequenceErrors + gripperUseErrors + 
	    parseErrors + toolChangeErrors + motionErrors + locationErrors));
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  if (commands.size() == 0)
    {
      snprintf(str, TEXTSIZE, "object location errors: %d", locationErrors);
      drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

      snprintf(str, TEXTSIZE, "objects located correctly: %d", locationGoods);
      drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

      snprintf(str, TEXTSIZE,
	       "total basic goal object distance moved: %.4lf %s",
	       (totalGoalDistance / robotLengthFactor), robotLengthUnits);
      drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

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

  snprintf(str, TEXTSIZE, "same-SKU equivalent: %s",
	   (swap ? "true" : "false"));
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "tolerance: %.4f millimeter", tolerance);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

  snprintf(str, TEXTSIZE, "time factor: %.4f", timeFactor);
  drawString(20.0f, (wy -= 15.0f), GLUT_BITMAP_HELVETICA_10, str);

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
  col color;
  double robotX;
  double robotY;
  double robotZ;

  color = nowModel->Robot->color;
  robotX = robotPoint->X->val;
  robotY = robotPoint->Y->val;
  robotZ = robotPoint->Z->val;
  // gantry crossbar
  insertBox(color, 0, (robotY - thick2), (robotHeight - thick2),
            WORKSTATIONLENGTH, (robotY + thick2), (robotHeight + thick2),
	    true);
  // gantry -X side support
  insertBox(color, 0, (robotY - wide2), 0,
            thick, (robotY + wide2), (robotHeight + thick2), true);
  // gantry +X side support
  insertBox(color, (WORKSTATIONLENGTH - thick), (robotY - wide2), 0,
            WORKSTATIONLENGTH, (robotY + wide2), (robotHeight + thick2),
	    true);
  // draw quill with no effector
  insertBox(color, (robotX - thick4), (robotY - thick4), robotZ,
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

Called By: KittingViewer::drawMetricsAndSettings

This draws one line of text starting at the given (x,y) location (in
currently active screen coordinates). The text is drawn left to right
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
  PoseLocationType * robotPose;

  robotPose = findPrimaryPose(nowModel->Robot);
  if (nowModel->Robot->EndEffector)
    {
      vacEffector =
	dynamic_cast<VacuumEffectorType *>(nowModel->Robot->EndEffector);
      if (vacEffector)
	{
	  length = vacEffector->Length->val;
	  robotPoint->X->val = (nowX - (length * nowZAxisI));
	  robotPoint->Y->val = (nowY - (length * nowZAxisJ));
	  robotPoint->Z->val = (nowZ - (length * nowZAxisK));
	}
      else
	{
	  fprintf(stderr,
		  "Fatal error: cannot handle non-vacuum end effector\n");
	  exit(1);
	}
    }
  else
    {
      robotPoint->X->val = nowX;
      robotPoint->Y->val = nowY;
      robotPoint->Z->val = nowZ;
    }
  for (iter = nowModel->Robot->refFor.begin();
       iter != nowModel->Robot->refFor.end(); iter++)
    updateWorkstationPosition(*iter, robotPose);
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

  start = getPseudoElapsedTime();
  while ((getPseudoElapsedTime() - start) < seconds);
}


/********************************************************************/

/* KittingViewer::enhancePoses

Returned Value: none

Called By: KittingViewer::enterPoseTargets

*/

void KittingViewer::enhancePoses() /* NO ARGUMENTS */
{
  int n;
  Pose * poseA;       // previous pose
  Pose * poseB;       // current pose
  Point * pointA;     // previous controlled point location
  Point * pointB;     // current controlled point location
  VectorIJK newXAxis; // X axis after Z rotation
  VectorIJK newZAxis; // Z axis after Z rotation
  double qTime;       // quill motion time
  double zTime;       // gripper Z axis motion time
  double xTime;       // gripper X axis motion time
  double qAx;         // quill X coordinate at point A
  double qAy;         // quill Y coordinate at point A
  double qAz;         // quill Z coordinate at point A
  double qBx;         // quill X coordinate at point B
  double qBy;         // quill Y coordinate at point B
  double qBz;         // quill Z coordinate at point B
  EndEffectorType * effector; // end effector
  VacuumEffectorType * vacEffector; // vacuum gripper
  double qDist;    // distance between quill location points
  double length;   // length of vacuum effector
  
  //set poses[0] to the current location
  poseB = &(poses[0]);
  pointB = &(poseB->origin);
  pointB->x = nowX;
  pointB->y = nowY;
  pointB->z = nowZ;
  poseB->xAxis.i = nowXAxisI;
  poseB->xAxis.j = nowXAxisJ;
  poseB->xAxis.k = nowXAxisK;
  poseB->zAxis.i = nowZAxisI;
  poseB->zAxis.j = nowZAxisJ;
  poseB->zAxis.k = nowZAxisK;
  for (n = 1; n < posesTotal; n++)
    {
      poseA = poseB;
      pointA = pointB;
      poseB = poses + n;
      pointB = &(poseB->origin);
      distancesX[n] = pointB->x - pointA->x;
      distancesY[n] = pointB->y - pointA->y;
      distancesZ[n] = pointB->z - pointA->z;
      distances[n] = hypot3(distancesX[n], distancesY[n], distancesZ[n]);
      if ((effector = nowModel->Robot->EndEffector) && 
	  (vacEffector = dynamic_cast<VacuumEffectorType *>(effector)))
	{
	  length = vacEffector->Length->val;
	  qAx = pointA->x - (length * poseA->zAxis.i);
	  qAy = pointA->y - (length * poseA->zAxis.j);
	  qAz = pointA->z - (length * poseA->zAxis.k);
	  qBx = pointB->x - (length * poseB->zAxis.i);
	  qBy = pointB->y - (length * poseB->zAxis.j);
	  qBz = pointB->z - (length * poseB->zAxis.k);
	  qDist = hypot3((qBx - qAx), (qBy - qAy), (qBz - qAz));
	  qTime = ((robotSpeed == 0.0) ? (10 * qDist / robotMaxSpeed) :
		   (qDist / robotSpeed));
	  if ((poseA->zAxis.i == poseB->zAxis.i) &&
	      (poseA->zAxis.j == poseB->zAxis.j) &&
	      (poseA->zAxis.k == poseB->zAxis.k))
	    {
	      zTime = 0.0;
	      anglesZ[n] = 0.0;
	      if ((poseA->xAxis.i == poseB->xAxis.i) &&
		  (poseA->xAxis.j == poseB->xAxis.j) &&
		  (poseA->xAxis.k == poseB->xAxis.k))
		{
		  xTime = 0.0;
		  anglesZ[n] = 0.0;
		}
	      else
		{
		  findAngleX(poseA->xAxis, poseB->xAxis, poseA->zAxis, n);
		  xTime =
		    fabs(anglesX[n])/(GRIPPERDEFAULTMAXROTATE * robotRelSpeed);
		}
	    }
	  else
	    {
	      findAngleAndAxleZ(poseA->zAxis, poseB->zAxis, n);
	      zTime = anglesZ[n]/(GRIPPERDEFAULTMAXROTATE * robotRelSpeed);
	      newXAxis = rotate(poseA->xAxis, axlesZ[n], anglesZ[n]);
	      if ((fabs(newXAxis.i - poseB->xAxis.i) > TINYVAL) ||
		  (fabs(newXAxis.j - poseB->xAxis.j) > TINYVAL) ||
		  (fabs(newXAxis.k - poseB->xAxis.k) > TINYVAL))
		{
		  newZAxis = rotate(poseA->zAxis, axlesZ[n], anglesZ[n]);
		  findAngleX(newXAxis, poseB->xAxis, newZAxis, n);
		  xTime =
		    fabs(anglesX[n])/(GRIPPERDEFAULTMAXROTATE * robotRelSpeed);
		}
	      else
		{
		  xTime = 0.0;
		  anglesX[n] = 0.0;		  
		}
	    }
	}
      else
	{
	  if (effector)
	    {
	      fprintf(stderr, "Fatal error: can handle only vacuum effector\n");
	      exit(1);
	    }
	  if ((poseB->xAxis.i != 1.0) ||
	      (poseB->xAxis.j != 0.0) ||
	      (poseB->xAxis.k != 0.0) ||
	      (poseB->zAxis.i != 0.0) ||
	      (poseB->zAxis.j != 0.0) ||
	      (poseB->zAxis.k != -1.0))
	    {
	      snprintf(commandString[0], TEXTSIZE,
		       "Error: attempt to reorient without a gripper; "
		       "setting Z axis 0,0,-1, X axis 1,0,0\n");
	      poseB->xAxis.i = 1.0;
	      poseB->xAxis.j = 0.0;
	      poseB->xAxis.k = 0.0;
	      poseB->zAxis.i = 0.0;
	      poseB->zAxis.j = 0.0;
	      poseB->zAxis.k = -1.0;
	      motionErrors++;
	    }
	  zTime = 0.0;
	  xTime = 0.0;
	  anglesZ[n] = 0;
	  anglesX[n] = 0;
	  qTime = ((robotSpeed == 0.0) ? (10 * distances[n] / robotMaxSpeed) :
		   (distances[n] / robotSpeed));
	}
      times[n] = times[n-1] + max(max(qTime, zTime), xTime);
    }
}

/********************************************************************/

/* KittingViewer::enterPoseTargets

Returned Value: none

Called By:
  KittingViewer::executeMoveStraightToCommand
  KittingViewer::executeMoveThroughToCommand
  KittingViewer::executeMoveToCommand

This is converting positions in the robot command to millimeters before
using the positions.

The calls to checkYAxis normalize the xAxis and aAxis vectors of each
Pose and check that they are orthogonal.

To calculate the time required for a move from one pose to another
when there is a gripper on the robot, this calculates three times.
The first is the distance moved by the quill between poses divided by
the robot speed. The second is the angle through which the Z axis of
the gripper moves divided by the gripper rotational speed. The third
is the amount of rotation of the X axis of the gripper around the
the Z axis of the gripper divided by the gripper rotational speed.
The maximum of the three times is used.

FIX - Maybe add a check that no two successive poses are the same. Or
maybe change the logic to live with that by throwing away all but one
of any group of consecutive identical poses.

*/

void KittingViewer::enterPoseTargets( /* ARGUMENTS                  */
 Pose ** posesIn,                     /* poses in command           */
 int num)                             /* number of poses in command */
{
  int n;
  Point * pointB;  // current controlled point location

  if (num > MAXPOSES)
    {
      fprintf(stderr, "too many poses in command");
      exit(1);
    }
  times[0] = getPseudoElapsedTime();
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
      pointB = &(poses[n].origin);
      pointB->x *= robotLengthFactor;
      pointB->y *= robotLengthFactor;
      pointB->z *= robotLengthFactor;
    }
  if (robotSpeed == 0.0)
    {
      snprintf(commandString[0], TEXTSIZE,
	       "Error: motion with robot speed set to zero; "
	       "speed for move reset to 0.1 maximum\n");
      motionErrors++;
    }
  posesTotal = (num + 1);
  enhancePoses();
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

The enterPoseTargets function may increase the motionErrors, possibly
more than once. We want to count only one error per command, so the
three commands for executing motion each save the value of
motionErrors before calling enterPoseTargets. If the value has
increased afterwards, it is set to one more than the old value.
Otherwise, the command has executed successfully, so one is added to
actionCommandsExecuted.

*/

void KittingViewer::executeMoveStraightToCommand( /* ARGUMENTS               */
 MoveStraightToMsg * moveStraightTo)    /* moveStraightTo command to execute */
{
  int oldMotionErrors;

  oldMotionErrors = motionErrors;
  enterPoseTargets(&(moveStraightTo->pose), 1);
  if (motionErrors > oldMotionErrors)
    motionErrors = oldMotionErrors + 1;
  else
    actionCommandsExecuted++;
  resetFlag = true;
}

/********************************************************************/

/* KittingViewer::executeMoveThroughToCommand

Returned Value: none

Called By: KittingViewer::executeCommand

See executeMoveStraightToCommand regarding motionErrors.

*/

void KittingViewer::executeMoveThroughToCommand( /* ARGUMENTS               */
 MoveThroughToMsg * moveThroughTo)      /* moveThroughTo command to execute */
{
  int oldMotionErrors;

  oldMotionErrors = motionErrors;
  enterPoseTargets(moveThroughTo->poses, moveThroughTo->num);
  if (motionErrors > oldMotionErrors)
    motionErrors = oldMotionErrors + 1;
  else
    actionCommandsExecuted++;
  resetFlag = true;
}

/********************************************************************/

/* KittingViewer::executeMoveToCommand

Returned Value: none

Called By: KittingViewer::executeCommand

See executeMoveStraightToCommand regarding motionErrors.

*/

void KittingViewer::executeMoveToCommand( /* ARGUMENTS                 */
 MoveToMsg * moveTo)                      /* moveTo command to execute */
{
  int oldMotionErrors;

  oldMotionErrors = motionErrors;
  enterPoseTargets(&(moveTo->pose), 1);
  if (motionErrors > oldMotionErrors)
    motionErrors = oldMotionErrors + 1;
  else
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
      rangeErrors++;
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

/* KittingViewer::findAngleX

Returned Value: none

Called By: KittingViewer::enhancePoses

This finds the angle of rotation around the given zAxis that rotates
xAxisA to xAxisB and stores it in anglesX[n].

The X axis may rotate around the Z axis by 180 degrees, so that the
cross product is the zero vector. If this happens, it does not matter
in which direction the rotation occurs. In general, the axle should be
either the Z axis or its negative and the direction of rotation does
matter.

*/

void KittingViewer::findAngleX( /* ARGUMENTS                    */
 VectorIJK xAxisA,              /* initial X axis               */
 VectorIJK xAxisB,              /* final X axis                 */
 VectorIJK zAxis,               /* Z axis for setting direction */
 int n)                         /* index of final X axis        */
{
  double dot;
  VectorIJK cross;
  double s;
  

  dot = (xAxisA.i * xAxisB.i) + (xAxisA.j * xAxisB.j) + (xAxisA.k * xAxisB.k);
  cross.i = (xAxisA.j * xAxisB.k) - (xAxisB.j * xAxisA.k);
  cross.j = (xAxisA.k * xAxisB.i) - (xAxisB.k * xAxisA.i);
  cross.k = (xAxisA.i * xAxisB.j) - (xAxisB.i * xAxisA.j);
  s = hypot3(cross.i, cross.j, cross.k);
  if (s < TINYVAL)
    anglesX[n] = M_PI;
  else if (((fabs((cross.i / s) - zAxis.i)) < TINYVAL) &&
	   ((fabs((cross.j / s) - zAxis.j)) < TINYVAL) &&
	   ((fabs((cross.k / s) - zAxis.k)) < TINYVAL))
    anglesX[n] = atan2(s, dot); // always positive
  else if (((fabs((cross.i / s) + zAxis.i)) < TINYVAL) &&
	   ((fabs((cross.j / s) + zAxis.j)) < TINYVAL) &&
	   ((fabs((cross.k / s) + zAxis.k)) < TINYVAL))
    anglesX[n] = -atan2(s, dot); // axle is opposite zAxis
  else
    { // axle is neither parallel nor antiparallel to Z axis
      fprintf(stderr, "Bug in finding axle for X axis rotation\n");
      exit(1);
    }
}

/********************************************************************/

/* KittingViewer::findAngleAndAxleZ

Returned Value: none

Called By: KittingViewer::enhancePoses

This finds the angle of rotation and the axle around which the
rotation takes place that rotates zAxisA to zAxisB. The angle is
stored in anglesZ[n]. The axle is stored in axlesZ[n].

The Z axis rotation is always positive and not more than 180 degrees.
This checks for the angle being 180 degrees since the cross product is
zero in that case. In this case, the axle is set to the line where the
plane normal to the Z vectors intersects the XY plane, unless that IS
the XY plane, in which case the axle is set to the X axis.

*/

void KittingViewer::findAngleAndAxleZ( /* ARGUMENTS             */
 VectorIJK zAxisA,                     /* initial Z axis        */
 VectorIJK zAxisB,                     /* final Z axis          */
 int n)                                /* index of final Z axis */
{
  double dot;
  VectorIJK cross;
  double s;
  double length;

  if ((fabs(zAxisA.i + zAxisB.i) < TINYVAL) &&
      (fabs(zAxisA.j + zAxisB.j) < TINYVAL) &&
      (fabs(zAxisA.k + zAxisB.k) < TINYVAL))
    {
      anglesZ[n] = M_PI;
      if ((fabs(zAxisA.i) < TINYVAL) && (fabs(zAxisA.j) < TINYVAL))
	{
	  axlesZ[n].i = 1.0;
	  axlesZ[n].j = 0.0;
	  axlesZ[n].k = 0.0;
	}
      else
	{
	  length = hypot(zAxisA.i, zAxisA.j);
	  axlesZ[n].i = -zAxisA.j / length;
	  axlesZ[n].j = zAxisA.i / length;
	  axlesZ[n].k = 0.0;
	}
    }
  else
    {
      dot = ((zAxisA.i * zAxisB.i) +
	     (zAxisA.j * zAxisB.j) +
	     (zAxisA.k * zAxisB.k));
      cross.i = (zAxisA.j * zAxisB.k) - (zAxisB.j * zAxisA.k);
      cross.j = (zAxisA.k * zAxisB.i) - (zAxisB.k * zAxisA.i);
      cross.k = (zAxisA.i * zAxisB.j) - (zAxisB.i * zAxisA.j);
      s = hypot3(cross.i, cross.j, cross.k);
      axlesZ[n].i = cross.i / s;
      axlesZ[n].j = cross.j / s;
      axlesZ[n].k = cross.k / s;
      anglesZ[n] = atan2(s, dot);
    }
}

/********************************************************************/

/* KittingViewer::findDistance

Returned Value: double

Called By: computeScore

goalObject is a basic solid object in the goalModel.

This finds the objects in the initModel and the nowModel with the same
name as the goalObject. Then it finds the distance between the
workstation locations of those two objects.

It also checks that all three objects are the same type.

*/

double KittingViewer::findDistance( /* ARGUMENTS                           */
 SolidObjectType * goalObject)      /* movable object to find distance for */
{
  std::map<std::string, SolidObjectType *>::iterator iter;
  SolidObjectType * nowObject;
  SolidObjectType * initObject;
  PointType * initPoint; 
  PointType * nowPoint;

  if (!(dynamic_cast<PartType *>(goalObject)      ||
	dynamic_cast<KitTrayType *>(goalObject)   ||
        dynamic_cast<PartsTrayType *>(goalObject) ||
        dynamic_cast<LargeContainerType *>(goalObject)))
    return 0;
  iter = initModel->allSolids.find(goalObject->Name->val);
  if (iter == initModel->allSolids.end())
    {
      fprintf(stderr, "object missing from initModel in findDistance\n");
      exit(1);
    }
  initObject = iter->second;
  iter = nowModel->allSolids.find(goalObject->Name->val);
  if (iter == nowModel->allSolids.end())
    {
      fprintf(stderr, "object missing from nowModel in findDistance\n");
      exit(1);
    }
  nowObject = iter->second;
  if ((dynamic_cast<PartType *>(goalObject) &&
       (!dynamic_cast<PartType *>(initObject) ||
	!dynamic_cast<PartType *>(nowObject))) ||
      (dynamic_cast<KitTrayType *>(goalObject) &&
       (!dynamic_cast<KitTrayType *>(initObject) ||
	!dynamic_cast<KitTrayType *>(nowObject))) ||
      (dynamic_cast<PartsTrayType *>(goalObject) &&
       (!dynamic_cast<PartsTrayType *>(initObject) ||
	!dynamic_cast<PartsTrayType *>(nowObject))) ||
      (dynamic_cast<LargeContainerType *>(goalObject) &&
       (!dynamic_cast<LargeContainerType *>(initObject) ||
	!dynamic_cast<LargeContainerType *>(nowObject))))
    {
      fprintf(stderr, 
	      "goal object %s has different type in inital or current model\n",
	      goalObject->Name->val.c_str());
      exit(1);
    }
  initPoint = findSecondaryPose(initObject)->Point;
  nowPoint = findSecondaryPose(nowObject)->Point;
  return hypot3((nowPoint->X->val - initPoint->X->val),
		(nowPoint->Y->val - initPoint->Y->val),
		(nowPoint->Z->val - initPoint->Z->val));
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
5A. If B is a part, the point argument is within tolerance of
    the top of the part.
5B. If B is a tray, P is within tolerance of the bottom
    of the tray (assumes the tray bottom has no thickness - yuck).
6. P is within 1 millimeter in X and Y from the origin of B
   (the origin of a boxy shape is in the middle of the bottom). This is
   required so that that there will be little torque on a gripper that lifts
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
	       tolerance))
		return object;
	}
      else if (dynamic_cast<PartsTrayType *>(object))
	{
	  if ((boxy = dynamic_cast<BoxyShapeType *>(object->sku->Shape)) &&
	      (boxy->HasTop->val == false) &&
	      (fabs(pose->Point->Z->val - Z) < tolerance))
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
	      (fabs(pose->Point->Z->val - Z) < tolerance))
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

/* KittingViewer::findPrimaryPose

Returned Value: PoseLocationType *

Called By:
  KittingViewer::checkLocationUnique
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
      fprintf(stderr, "bad PrimaryLocation for %s; must be PoseLocation\n",
	      solid->Name->val.c_str());
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
      fprintf(stderr, "Fatal error: cannot find a required SKU named %s\n",
	      skuName->val.c_str());
      exit(1);
    }
  return 0;
}

/********************************************************************/

/*  KittingViewer::findSkuName

Returned Value: std::string *

Called By:
  KittingViewer::makeLocationMaps

*/

std::string * KittingViewer::findSkuName( /* ARGUMENTS                */
 SolidObjectType * solid)                 /* the solid object to test */
{
  if (dynamic_cast<PartType *>(solid))
    return &(dynamic_cast<PartType *>(solid)->SkuName->val);
  else if (dynamic_cast<KitTrayType *>(solid))
    return &(dynamic_cast<KitTrayType *>(solid)->SkuName->val);
  else if (dynamic_cast<PartsTrayType *>(solid))
    return &(dynamic_cast<PartsTrayType *>(solid)->SkuName->val);
  else if (dynamic_cast<LargeContainerType *>(solid))
    return &(dynamic_cast<LargeContainerType *>(solid)->SkuName->val);
  return 0;
}

/********************************************************************/

/* KittingViewer::findSurface

Returned Value: PoseLocationType *

Called By: KittingViewer::releaseObject

This finds and returns a pointer to a solid object (if there is one)
called object such that the given xyz point is somewhere on a
horizontal upward-facing surface of the object. object must be the
work table, a part, a parts tray, a kit tray, or a large container. If
there is no such object, this returns 0. The upward-facing surface is
the top for a work table or part. The upward-facing surface is the
bottom for a kit tray, a parts tray, or a large container.

This works by going through allSolids of the now model, calling each
one "test" and seeing if the conditions described above for object are met.
There may be more than one qualifying test since the bottoms of
objects currently have zero thickness.
When there is more than one qualifying test, object is picked as follows

- If "solid" is a part, test1 is a tray, and test2 is the worktable,
  object is set to the tray.

- If "solid" is a kit, test1 is a kit tray (the kit's own kit tray will
  qualify), and test2 is a large container, object is set to the large
  container.

- Otherwise, object is set to whichever qualifying object is found first.
  It may be useful to have additional special cases.

The offsets are set to the offsets from the point in the location of
the object to the given xyz point.

The actual check on the Z value is that z is within tolerance of
a surface.

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
  SolidObjectType * test;
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
  double xOff;             // test X offset
  double yOff;             // test Y offset

  object = 0;
  for (iter = nowModel->allSolids.begin();
       iter != nowModel->allSolids.end(); iter++)
    {
      test = iter->second;
      // don't locate the solid with respect to itself
      if (test == solid)
	continue;
      pose = findSecondaryPose(test);
      // check that surface is horizontal
      if ((fabs(pose->ZAxis->I->val) > TINYVAL)     ||
	  (fabs(pose->ZAxis->J->val) > TINYVAL)     ||
	  (fabs(pose->ZAxis->K->val - 1) > TINYVAL))
	continue;
      // find length, width, and height
      if (dynamic_cast<PartType *>(test))
	{
	  boxy = dynamic_cast<BoxyShapeType *>(test->sku->Shape);
	  if ((!boxy) || (boxy->HasTop->val == false))
	    continue;
	  length = boxy->Length->val;
	  width  = boxy->Width->val;
	  height = boxy->Height->val;
	}
      else if (dynamic_cast<PartsTrayType *>(test) ||
	       dynamic_cast<KitTrayType *>(test))
	{
	  boxy = dynamic_cast<BoxyShapeType *>(test->sku->Shape);
	  if ((!boxy) || (boxy->HasTop->val == true))
	    continue;
	  length = boxy->Length->val;
	  width  = boxy->Width->val;
	  height = 0;
	}
      else if ((table = dynamic_cast<WorkTableType *>(test)))
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
      else if (dynamic_cast<LargeContainerType *>(test))
	{
	  boxy = dynamic_cast<BoxyShapeType *>(test->sku->Shape);
	  if ((!boxy) || (boxy->HasTop->val == true))
	    continue;
	  length = boxy->Length->val;
	  width  = boxy->Width->val;
	  height = 0;
	}
      else
	continue;
      // check height
      if (fabs((pose->Point->Z->val + height) - Z) > tolerance)
	continue;
      // check that point is inside test rectangle
      vi = (X - pose->Point->X->val);
      vj = (Y - pose->Point->Y->val);
      xi = pose->XAxis->I->val;
      xj = pose->XAxis->J->val;
      xOff = ((vi * xi) + (vj * xj));
      yOff = ((xi * vj) - (vi * xj));
      if ((fabs(xOff) < (length / 2.0)) &&
	  (fabs(yOff) < (width / 2.0)))
	{
	  if (object == 0)
	    {
	      *xOffset = xOff;
	      *yOffset = yOff;
	      *zOffset = height;
	      object = test;
	    }
	  else if (dynamic_cast<PartType *>(solid) &&
		   dynamic_cast<WorkTableType *>(object) &&
		   (dynamic_cast<PartsTrayType *>(test) ||
		    dynamic_cast<KitTrayType *>(test)))
	    {
	      *xOffset = xOff;
	      *yOffset = yOff;
	      *zOffset = height;
	      object = test;
	    }
	  else if (dynamic_cast<KitType *>(solid) &&
		   dynamic_cast<KitTrayType *>(object) &&
		   dynamic_cast<LargeContainerType *>(test))

	    {
	      *xOffset = xOff;
	      *yOffset = yOff;
	      *zOffset = height;
	      object = test;
	    }	   
	}
    }
  return object;
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
      if ((fabs(point->X->val - pose->Point->X->val) < tolerance) &&
	  (fabs(point->Y->val - pose->Point->Y->val) < tolerance) &&
	  (fabs(point->Z->val - pose->Point->Z->val) < tolerance))
	return *iter;
    }
  return 0;
}

/********************************************************************/

/* KittingViewer::getPseudoElapsedTime

Returned Value: double

Called By:
  animate (in viewKitting.cc)
  void KittingViewer::dwell
  KittingViewer::enterPoseTargets
  KittingViewer::handleResets

This updates and returns the pseudo elapsed time. The update is to
increase the last pseudo elapsed time by ([the difference between the
real last time and the real current time] times the timeFactor). If the
time factor is less than one, time will seem to pass more slowly, so
the animation will run more slowly. If the time factor is greater than
one, time will seem to pass faster, so the animation will run faster.

*/

double KittingViewer::getPseudoElapsedTime()
{
  double glutLastTime;

  glutLastTime = glutElapsedTime;
  glutElapsedTime = (glutGet(GLUT_ELAPSED_TIME) / 1000.0); // convert to seconds
  pseudoElapsedTime += (glutElapsedTime - glutLastTime) * timeFactor;
  return pseudoElapsedTime;
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
  if (checkingNotStarted)
    {
      iter = goalModel->allSolids.begin();
      checkingNotStarted = false;
      makeLocationMaps();
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
resetFlag is true. All position data here is in workstation coordinates.

Data for the motion command that is executing has been saved in
six arrays, all indexed by the number of legs in the motion: 
 - poses (the pose at the end of the leg)
 - times (the time at which the end of the leg should be reached)
 - distances (the length of the leg)
 - anglesZ (the angle through which the Z axis must rotate in this leg)
 - axlesZ (the line around which the Z axis must rotate in this leg)
 - anglesX (the angle through which the X axis must rotate in this leg)

Let W be the current target waypoint. W is poses[poseIndex].

1. If it is time for W to have been passed, act as though W has just
been reached. Even if it is time to have passed more waypoints, this
will pass only one waypoint, so that at least one frame of the
animation will show the robot at each waypoint.

1A. Use the times and distances arrays to update the total time used
and the total distance travelled.

1B. Set the now point to the point of W, and set the xAxis and zAxis
local variables to those of W.

1C. Add one to the poses index.

1D. If the poseIndex is now posesTotal, the end of the move has been
reached, so set the reset flag to false.

2. Otherwise, a motion command is in progress and is not supposed to
be complete. Let P denote the waypoint before W. Find the fraction of
time from P to W represented by the current time.

2A. Set the current point to the point that is that fraction of the way
from P to W.

2B. Set the current Z axis by rotating the Z axis at P about the Z axle
for this leg by fraction times the Z angle for this leg.

2C. Set the current X axis by rotating the X axis at P about the Z
axle for this leg by fraction times the Z angle for this leg. Then
rotate the new X axis about the new Z axis by fraction times the X
angle for this leg. If the Z axis does not move, only the last step is
needed.

3. Call resetPositions to set the poses of the robot and the gripper (if
there is one).

*/

void KittingViewer::handleResets() /* NO ARGUMENTS  */
{
  Point point;     // (Point from Pose.h)
  VectorIJK xAxis; // (VectorIJK from Pose.h)
  VectorIJK zAxis; // (VectorIJK from Pose.h)
  VectorIJK axle;  // (VectorIJK from Pose.h)
  double fraction; 
  int n;
  double timeNow;

  timeNow = getPseudoElapsedTime();
  if (timeNow > times[poseIndex])
    { // at this time, the next waypoint should have been reached, so go there
      distanceTotal += distances[poseIndex];
      totalExecutionTime += (times[poseIndex] - times[poseIndex - 1]);
      point = poses[poseIndex].origin;
      nowX = point.x;
      nowY = point.y;
      nowZ = point.z;
      xAxis = poses[poseIndex].xAxis;
      zAxis = poses[poseIndex].zAxis;
      poseIndex++;
      if (poseIndex == posesTotal)
	{ // the end of the move has been reached
	  resetFlag = false;
	}
    }
  else
    {
      n = poseIndex - 1;
      fraction = (((double)(timeNow - times[n])) /
		  ((double)(times[poseIndex] - times[n])));
      if (fraction > 1.0)
	fraction = 1.0;
      point = poses[n].origin;
      nowX = (point.x + (fraction * distancesX[poseIndex]));
      nowY = (point.y + (fraction * distancesY[poseIndex]));
      nowZ = (point.z + (fraction * distancesZ[poseIndex]));
      xAxis = poses[poseIndex - 1].xAxis;
      zAxis = poses[poseIndex - 1].zAxis;
      if (anglesZ[poseIndex] != 0)
	{
	  zAxis =
	    rotate(zAxis, axlesZ[poseIndex], fraction * anglesZ[poseIndex]);
	  xAxis =
	    rotate(xAxis, axlesZ[poseIndex], fraction * anglesZ[poseIndex]);
	  if (anglesX[poseIndex] != 0)
	    {
	      xAxis =
		rotate(xAxis, zAxis, fraction * anglesX[poseIndex]);
	    }
	}
      else if (anglesX[poseIndex] != 0)
	{
	  xAxis = rotate(xAxis, zAxis, fraction * anglesX[poseIndex]);
	}
    }
  resetPositions(xAxis.i, xAxis.j, xAxis.k, zAxis.i, zAxis.j, zAxis.k);
}

/********************************************************************/

/* KittingViewer::hypot3

Returned Value: double

Called By:
  KittingViewer::enhancePoses
  KittingViewer::findAngleX
  KittingViewer::findAngleAndAxleZ
  KittingViewer::findDistance

This finds the length of a line segment from its components.

*/

double KittingViewer::hypot3( /* ARGUMENTS   */
 double x,                    /* x component */
 double y,                    /* y component */
 double z)                    /* z component */
{
  return sqrt((x*x) + (y*y) + (z*z));
}

/********************************************************************/

/* KittingViewer::init

Returned Value: none

Called By: main

This initializes the kittingViewer. Specifically:
 - sets up the initModel:
   * reads the initial configuration file
   * puts the workstation model just read into the initModel
   * converts units in the initModel
   * puts initial positions with respect to the workstation into the
     secondary positions list of each basic movable object in the initModel
 - if there is a command file:
   * reads the command file
   * reads the initial configuration file again 
 - otherwise (there must be kittingBuiltFile)
   * reads the kittingBuiltFile
 - sets up the nowModel
   * puts the workstation model just read (either initial or as-built)
     into the nowModel
   * converts units in the nowModel
   * sets locations and colors in the nowModel
   * calculates the positions of all solid objects in the nowModel
     configuration relative to the workstation
   * makes colors for the solid objects in the nowModel that have their
     own colors
 - sets up the goalModel
   * reads the goal configuration file
   * puts the workstation model just read into the goalModel
   * converts units in the goalModel
 - reads the scoring file if there is one, otherwise sets default scoring
 - initializes the data in the kittingViewer world model
 - sets the grid spacing for the workstation drawing
 - sets the scale for the workstation drawing 

The scale to use is calculated by having the larger of the length and
width of the workstation being used fit exactly into 20 grid squares,
which is 1.0 unit in picture space.

*/

void KittingViewer::init() /* NO ARGUMENTS */
{
  readInitFile(true);
  initModel = KittingWorkstationTree->KittingWorkstation;
  initModel->convertUnits(true);
  recordInitialPositions(initModel->allSolids);
  if (commandFile)
    {
      readCommandFile();
      readInitFile(false);
    }
  else // if (kittingBuiltFile)
    readBuiltFile();
  nowModel = KittingWorkstationTree->KittingWorkstation;
  nowModel->convertUnits(true);
  setLocationsAndColors(nowModel->allSolids);
  readGoalFile();
  goalModel = KittingWorkstationTree->KittingWorkstation;
  goalModel->convertUnits(false);
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
  // anglesX set when needed
  // anglesZ set when needed
  // angleUnits set when initial state read
  // axlesZ set when needed
  checkingNotStarted = true;
  // commandFile set in readArguments
  // commands set when command file read
  commandSequenceErrors = 0;
  // commandString set in canonicalMsgView.cc used in viewKitting.cc
  distanceTotal = 0.0;
  // distances set when needed
  // distancesX set when needed
  // distancesY set when needed
  // distancesZ set when needed
  // executeFlag
  executionState = unready;
  // fraction
  glutElapsedTime = 0.0;
  // goalModel built when goal state file read
  gripperUseErrors = 0;
  // initModel built when initial state file read
  // kitGoalMap populated by makeLocationMaps
  // kittingBuiltFile set when arguments read
  // kittingGoalFile set when arguments read
  // kittingInitFile set when arguments read
  // lengthFactor set when initial state read
  // lengthUnits set when initial state read
  locationErrors = 0;
  locationGoods = 0;
  motionErrors = 0;
  movableObjects = -1; // indicates unset
  // nowModel set when initial state read, updated during command execution
  if ((effector = nowModel->Robot->EndEffector) &&
      (vacEffector = dynamic_cast<VacuumEffectorType *>(effector)))
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
  poseIndex = 1;
  poses[0].origin.x = nowX;
  poses[0].origin.y = nowY;
  poses[0].origin.z = nowZ;
  poses[1].origin.x = nowX;
  poses[1].origin.y = nowY;
  poses[1].origin.z = nowZ;
  posesTotal = 2;
  pseudoElapsedTime = 0.0;
  rangeErrors = 0;
  resetFlag = false;
  robotAccel = (robotMaxAccel * robotRelAccel) / 100.0;
  robotAngleFactor = 1.0;
  strncpy(robotAngleUnits, "degree", TEXTSIZE);
  robotEndAngleTol = 0.0;
  robotEndPointTol = 0.0;
  robotGripperOpen = false;
  robotIntPointTol = 0.0;
  robotLengthFactor = 1.0;
  strncpy(robotLengthUnits, "millimeter", TEXTSIZE);
  robotMaxAccel = ROBOTDEFAULTMAXACCEL;
  robotMaxSpeed = ROBOTDEFAULTMAXSPEED;
  robotPoint = (findPrimaryPose(nowModel->Robot))->Point;
  robotRelAccel = 10.0;
  robotRelSpeed = 10.0;
  robotSpeed = (robotMaxSpeed * robotRelSpeed) / 100.0;
  robotToolChangerOpen = false;
  // scale set when initial state read
  score = 0;
  // scoringFile set in readArguments
  // scoringFileName set in readScoringFile
  // skuGoalMap populated by makeLocationMaps
  // spacing set when initial state read
  // swap set in main
  timeFactor = 1.0;
  times[0] = 0.0;
  times[1] = 0.001;
  // tolerance set in readArguments
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

Called By:
  KittingViewer::resetViewer
  KittingViewer::setColorAndSku

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

This may be reset by calling it with color == 0;

*/

void KittingViewer::makeBlueColor( /* ARGUMENTS    */
 col * color)                      /* color to set */
{
  static int index = 1;
  int n;      // total number of colors at end of last go-around
  float jump; // how far to move
  int octant;

  if (color == 0)
    { // reset
      index = 1;
      return;
    }
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

Called By:
  KittingViewer::resetViewer
  KittingViewer::setColorAndSku

This makes greenish colors by picking points in the RGB cube and
selecting the ones that are greenish. See documentation of makeBlueColor.
This is identical except that it selects greenish colors.

*/

void KittingViewer::makeGreenColor( /* ARGUMENTS    */
 col * color)                       /* color to set */
{
  static int index = 1;
  int n;      // total number of colors at end of last go-around
  float jump; // how far to move
  int octant;

  if (color == 0)
    { // reset
      index = 1;
      return;
    }
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

Called By:
  KittingViewer::resetViewer
  KittingViewer::setColorAndSku

This makes reddish colors by picking points in the RGB cube and
selecting the ones that are greenish. See documentation of makeBlueColor.
This is identical except that it selects reddish colors.

*/

void KittingViewer::makeRedColor( /* ARGUMENTS    */
 col * color)                     /* color to set */
{
  static int index = 1;
  int n;      // total number of colors at end of last go-around
  float jump; // how far to move
  int octant;

  if (color == 0)
    { // reset
      index = 1;
      return;
    }
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

/* KittingViewer::makeLocationMaps

Returned Value: none

Called By: KittingViewer::handleExecute

This goes through all the goal objects paying attention to those that
are kits or have a SkuName. 

Those that are kits have a DesignName. This makes the kitGoalMap using
the DesignName as the key and the list of all locations of instances
of kits with that DesignName as the data.

Those with a SkuName also have a sku that is not null. This makes the
skuGoalMap using the sku name as the key and the list of all locations
of instances of the sku as the data.

*/

void KittingViewer::makeLocationMaps()  /* NO ARGUMENTS */
{
  static std::map<std::string, SolidObjectType *>::iterator iter;
  SolidObjectType * object;
  std::map<std::string, std::list<PoseLocationType *>*>::iterator ator;
  std::list<PoseLocationType *> * poseList;
  KitType * kit;
  std::string * skuName;

  for (iter = goalModel->allSolids.begin();
       iter != goalModel->allSolids.end(); iter++)
    {
      object = iter->second;
      if ((kit = dynamic_cast<KitType *>(object)))
	{
	  ator = kitGoalMap.find(kit->DesignName->val);
	  if (ator == kitGoalMap.end())
	    { // there's no list for this kit design; make one; add kit's pose
	      poseList = new std::list<PoseLocationType *>;
	      poseList->push_back(findPrimaryPose(kit));
	      kitGoalMap.insert(std::pair<std::string,
				std::list<PoseLocationType *>*>
				(kit->DesignName->val, poseList));
	    }
	  else
	    { // there's a list for this kit design; add kit's pose
	      poseList = ator->second;
	      poseList->push_back(findPrimaryPose(kit));
	    }
	}
      else if ((skuName = findSkuName(object)))
	{
	  ator = skuGoalMap.find(*skuName);
	  if (ator == skuGoalMap.end())
	    { // there's no list for this sku; make one; add object's pose
	      poseList = new std::list<PoseLocationType *>;
	      poseList->push_back(findPrimaryPose(object));
	      skuGoalMap.insert(std::pair<std::string,
				std::list<PoseLocationType *>*>
				(*skuName, poseList));
	    }
	  else
	    { // there's a list for this sku; add object's pose
	      poseList = ator->second;
	      poseList->push_back(findPrimaryPose(object));
	    }
	}
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

/* KittingViewer::printInstructions

Returned Value: none

Called By: main

This prints instructions for using the mouse and keyboard to run the
Kitting Viewer.

*/

void KittingViewer::printInstructions() /* NO ARGUMENTS */
{
  printf("\n");
  printf("Press r to toggle left mouse button "
	 "between translating and rotating\n");
  printf("Hold down left mouse button and move mouse "
	 "to translate or rotate workstation\n");
  printf("Hold down middle mouse button and move mouse "
	 "to rotate workstation\n");
  printf("Hold down right mouse button and move mouse "
	 "up/dn to zoom workstation\n");
  printf("Press f to make the animation run faster\n");
  printf("Press s to make the animation run slower\n");
  printf("Press v to return to the default view\n");
  printf("Press e to execute the next command\n");
  printf("Press d to dump the current image in a ppm file\n");
  printf("Press t to to print metrics and settings in a text file\n");
  printf("Press D to dump image and print text file\n");
  printf("Press a to run the simulation over\n");
  printf("Press Esc to exit\n");
  printf("\n");
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

/* KittingViewer::readArguments

Returned Value: none

Called By: main

This reads the command arguments and requires that one of the following
forms be used. If neither form is matched, it calls usageMessage, which
prints a usage message and exits.

KittingViewer <-c commandFile> <-i initFile> <-g goalFile> <-e equiv> [<-s scoringFile>] [<-t tolerance>]

KittingViewer <-b asBuiltFile> <-i initFile> <-g goalFile> <-e equiv> [<-s scoringFile>] [<-t tolerance>]

*/

void KittingViewer::readArguments( /* ARGUMENTS                          */
 int argc,                         /* number of command arguments plus 1 */
 char * argv[])                    /* array of command and arguments     */
{

  int commandIndex = 0;
  int initIndex = 0;
  int goalIndex = 0;
  int equivIndex = 0;
  int scoreIndex = 0;
  int builtIndex = 0;
  int tolIndex = 0;
  int n;

  if ((argc != 9) &&
      (argc != 11) &&
      (argc != 13))
    {
      usageMessage(argv[0]);
    }
  for (n = 1; n < argc; n += 2)
    {
      if (strcmp(argv[n], "-b") == 0)
	{
	  if (builtIndex)
	    usageMessage(argv[0]);
	  else
	    builtIndex = n+1;
	}
      else if (strcmp(argv[n], "-c") == 0)
	{
	  if (commandIndex)
	    usageMessage(argv[0]);
	  else
	    commandIndex = n+1;
	}
      else if (strcmp(argv[n], "-e") == 0)
	{
	  if (equivIndex)
	    usageMessage(argv[0]);
	  else
	    equivIndex = n+1;
	}
      else if (strcmp(argv[n], "-g") == 0)
	{
	  if (goalIndex)
	    usageMessage(argv[0]);
	  else
	    goalIndex = n+1;
	}
      else if (strcmp(argv[n], "-i") == 0)
	{
	  if (initIndex)
	    usageMessage(argv[0]);
	  else
	    initIndex = n+1;
	}
      else if (strcmp(argv[n], "-s") == 0)
	{
	  if (scoreIndex)
	    usageMessage(argv[0]);
	  else
	    scoreIndex = n+1;
	}
      else if (strcmp(argv[n], "-t") == 0)
	{
	  if (tolIndex)
	    usageMessage(argv[0]);
	  else
	    tolIndex = n+1;
	}
      else
	usageMessage(argv[0]);
    }
  if ((goalIndex == 0) ||
      (equivIndex == 0) ||
      (initIndex == 0) ||
      (builtIndex && commandIndex) ||
      ((builtIndex == 0) && (commandIndex == 0)))
    usageMessage(argv[0]);
  
  if (strcmp(argv[equivIndex], "true") == 0)
    swap = true;
  else if (strcmp(argv[equivIndex], "false") == 0)
    swap = false;
  else
    usageMessage(argv[0]);
  kittingGoalFile = argv[goalIndex];
  kittingInitFile = argv[initIndex];
  if (commandIndex)
    {
      commandFile = argv[commandIndex];
      kittingBuiltFile = 0;
    }
  else // if (builtIndex)
    {
      kittingBuiltFile = argv[builtIndex];
      commandFile = 0;
    }
  scoringFile = (scoreIndex ? argv[scoreIndex] : 0);
  if (tolIndex)
    {
      if (sscanf(argv[tolIndex], "%lf", &tolerance) == 0)
	usageMessage(argv[0]);
    }
  else
    tolerance = TINYDISTANCE;
}

/********************************************************************/

/* KittingViewer::readBuiltFile

Returned Value: none

Called By: KittingViewer::init

This reads the as-built workstation state file.

*/

void KittingViewer::readBuiltFile() /* NO ARGUMENTS */
{
  yyin = fopen(kittingBuiltFile, "r");
  if (yyin == 0)
    {
      fprintf(stderr, "Fatal error: unable to open file %s for reading\n",
	      kittingBuiltFile);
      exit(1);
    }
  clearLists();
  yyparse();
  fclose(yyin);
  printf("Kitting workstation as-built file read\n");
}

/********************************************************************/

/* KittingViewer::readCommandFile

Returned Value: none

Called By: KittingViewer::init

This reads the command file.

*/

void KittingViewer::readCommandFile() /* NO ARGUMENTS */
{
  FILE * inFile;
  CommandParser commandParser;

  inFile = fopen(commandFile, "r");
  if (inFile == 0)
    {
      fprintf(stderr, "Fatal error: unable to open file %s for reading\n",
	      commandFile);
      exit(1);
    }
  commandParser.readCommandFile(inFile, &commands);
  fclose(inFile);
  printf("Command file read\n");
}

/********************************************************************/

/* KittingViewer::readGoalFile

Returned Value: none

Called By: KittingViewer::init

This reads the goal workstation state file.

*/

void KittingViewer::readGoalFile() /* NO ARGUMENTS */
{
  yyin = fopen(kittingGoalFile, "r");
  if (yyin == 0)
    {
      fprintf(stderr, "Fatal error: unable to open file %s for reading\n",
	      kittingGoalFile);
      exit(1);
    }
  clearLists(); // goalModel will have new lists
  yyparse();
  fclose(yyin);
  XmlID::allIDs.clear(); // to prevent duplicate ID messages later
  XmlIDREF::allIDREFs.clear(); // to prevent missing IDREF messages later
  printf("Kitting workstation goal configuration file read\n");
}

/********************************************************************/

/* KittingViewer::readInitFile

Returned Value: none

Called By: KittingViewer::init

This reads the initial workstation state file.

*/

void KittingViewer::readInitFile( /* ARGUMENTS                            */
 bool printMessage)               /* true=print read message, false=don't */
{
  yyin = fopen(kittingInitFile, "r");
  if (yyin == 0)
    {
      fprintf(stderr, "Fatal error: unable to open file %s for reading\n",
	      kittingInitFile);
      exit(1);
    }
  clearLists();
  yyparse();
  fclose(yyin);
  if (printMessage)
    printf("Kitting workstation initial configuration file read\n");
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
	  fprintf(stderr, "Fatal error: unable to open file %s for reading\n",
		  scoringFile);
	  exit(1);
	}
      yyscparse();
      fclose(yyscin);
      printf("Scoring file read\n\n");
      scorer = scoreKittingTree->scoreKitting;
      if ((scorer->rightStuff->weight->val       == 0) &&
	  (scorer->commandExecution->weight->val == 0) &&
	  (scorer->uselessCommands->weight->val  == 0) &&
	  (scorer->distance->weight->val         == 0) &&
	  (scorer->time->weight->val             == 0))
	{
	  fprintf(stderr, "Fatal error: at least one scoring weight "
		  "must be positive\n");
	  exit(1);
	}
    }
  else if (commandFile)
    { // equal weights, right stuff is multiplicative, others additive
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
  else // if asBuiltFile
    { // only right stuff is used
      strncpy(scoringFileName, "none, using default scoring", TEXTSIZE);
      scoreKittingTree =
	new ScoreKittingFile
	(new XmlVersion(false),
	 new XmlHeaderForScoreKitting (new SchemaLocation(0,0)),
	 new scoreKittingType
	 (new factorValueOptType(new XmlBoolean("true"),
				 new XmlUnsignedInt("1"), 0),
	  new factorValueOptType(new XmlBoolean("true"),
				 new XmlUnsignedInt("0"), 0),
	  new factorValueOptType(new XmlBoolean("true"),
				 new XmlUnsignedInt("0"), 0),
	  new factorValueOptType(new XmlBoolean("true"),
				 new XmlUnsignedInt("0"), 0),
	  new factorValueReqType(new XmlBoolean("true"),
				 new XmlUnsignedInt("0"), 0)));
    }
}

/********************************************************************/

/* KittingViewer::recordInitialPositions

Returned Value: none

Called By:  KittingViewer::init

This records the initial positions of each basic object in allSolids. A
basic object is a solid object that is not comprised of other solid
objects. That is each Part, PartsTray, KitTray, or LargeContainer. The
allSolids argument is the init objects when this is called by init.

*/

void KittingViewer::recordInitialPositions(          /* ARGUMENTS       */
 std::map<std::string, SolidObjectType *> allSolids) /* list of objects */
{
  std::map<std::string, SolidObjectType *>::iterator iter;

  for (iter = allSolids.begin(); iter != allSolids.end(); iter++)
    {
      if (dynamic_cast<PartType *>(iter->second) ||
	  dynamic_cast<PartsTrayType *>(iter->second) ||
	  dynamic_cast<KitTrayType *>(iter->second) ||
	  dynamic_cast<LargeContainerType *>(iter->second))
	setWorkstationLocation(iter->second, allSolids);
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

This implements the effects of releasing a solid object "solid" from a
single cup gripper. The gripper is holding solid when the function
starts.

If findSurface finds a surface R on which the the coordinate
system of solid is resting, then:
 - The primary location of solid is made relative to R.
 - The point of solid is located relative to R as found in findSurface.
 - The I component of the X axis of solid relative to R is found by taking
   the dot product of the X axis of R relative to the workstation with the
   X axis of solid relative to the workstation.
 - The J component of the X axis of solid relative to R is found by taking
   the cross product of the X axis of R relative to the workstation with
   the X axis of solid relative to the workstation.
 - The K component of the X axis of solid relative to R is 0 and the
   Z axis of solid is (0,0,1) relative to R, since findSurface would
   not have found a surface otherwise.

Otherwise, the primary location of solid is made relative to the
workstation in the same place as solid's secondary location.

Finally:
a. if solid is a part, the location of solid is adjusted if necessary.
See the documentation of adjustPartLocation.
b. otherwise, if solid is a kit, the location of solid is adjusted if
   necessary. See the documentation of adjustKitLocation.
c. otherwise, if solid is not a tray, an error is reported, since only
   parts, kits, and trays can be held by the robot.

This is putting solid directly on the surface it is near.

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
  else if (dynamic_cast<PartsTrayType *>(solid));
  else if (dynamic_cast<KitTrayType *>(solid));
  else
    {
      fprintf(stderr,
	      "Bug in releaseObject; object %s released not liftable\n",
	      solid->Name->val.c_str());
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

Called By: KittingViewer::handleResets

The incoming data here is in workstation coordinates.

This sets the current position and the primary position of the robot;
both are in workstation coordinates If the robot is holding a gripper,
this also sets the primary position of that gripper (which is relative
to the robot). The position of the gripper relative to the workstation
will be found in updateWorkstationPosition when drawWorkstation
starts.

The primary position of a gripper on the robot is always relative to
the robot and has its point at (0,0,0), so that point is not reset.
The Z axis of the robot is always (0,0,-1) while the X axis is always
(1,0,0), so the signs of the K components of the gripper Z axis need
to be reversed to be relative to the robot.

*/

void KittingViewer::resetPositions( /*  ARGUMENTS                   */
 double xi,                         /* I value of controlled X axis */
 double xj,                         /* J value of controlled X axis */
 double xk,                         /* K value of controlled X axis */
 double zi,                         /* I value of controlled Z axis */
 double zj,                         /* J value of controlled Z axis */
 double zk)                         /* K value of controlled Z axis */
 
{
  EndEffectorType * effector;
  VacuumEffectorType * vacEffector;
  PoseLocationType * vacEffectorPose; // pose of gripper wrt quill
  double length;

  nowXAxisI = xi;
  nowXAxisJ = xj;
  nowXAxisK = xk;
  nowZAxisI = zi;
  nowZAxisJ = zj;
  nowZAxisK = zk;
  if ((effector = nowModel->Robot->EndEffector) && 
      (vacEffector = dynamic_cast<VacuumEffectorType *>(effector)))
    {
      length = vacEffector->Length->val;
      vacEffectorPose = findPrimaryPose(vacEffector);
      // vacEffectorPose Point is always (0,0,0)
      vacEffectorPose->XAxis->I->val = nowXAxisI;
      vacEffectorPose->XAxis->J->val = -nowXAxisJ;
      vacEffectorPose->XAxis->K->val = -nowXAxisK;
      vacEffectorPose->ZAxis->I->val = nowZAxisI;
      vacEffectorPose->ZAxis->J->val = -nowZAxisJ;
      vacEffectorPose->ZAxis->K->val = -nowZAxisK;
      // robotPose XAxis is always (1,0,0)
      // robotPose ZAxis is always (0,0,-1)
      robotPoint->X->val = (nowX - (length * nowZAxisI));
      robotPoint->Y->val = (nowY - (length * nowZAxisJ));
      robotPoint->Z->val = (nowZ - (length * nowZAxisK));
    }
  else
    { // controlled point is end point of robot quill
      robotPoint->X->val = nowX;
      robotPoint->Y->val = nowY;
      robotPoint->Z->val = nowZ;	      
    }
}

/********************************************************************/

/* KittingViewer::resetViewer

Returned Value: none

Called By: KittingViewer::runAgain

void KittingViewer::resetViewer

This resets the kittingViewer model so that a simulation can be run over
again. The destructors this calls currently do not delete the components
of the things that get destructed, so resetting leaks a lot of memory.

*/

void KittingViewer::resetViewer() /* NO ARGUMENTS */
{
  clearLists();
  commands.clear();
  kitGoalMap.clear();
  skuGoalMap.clear();
  delete goalModel;
  delete nowModel;
  delete scoreKittingTree;
  makeBlueColor(0);
  makeGreenColor(0);
  makeRedColor(0);
}

/********************************************************************/

/* KittingViewer::rotate

Returned Value:  VectorIJK 

Called By:
  KittingViewer::enhancePoses
  KittingViewer::handleResets

This rotates the point (or vector) x,y,z by an angle theta about a
unit vector u,v,w through the origin.

Formula from http://inside.mines.edu/~gmurray/ArbitraryAxisRotation/

X= u*(u*x + v*y + w*z)*(1 - cos(theta)) + x*cos(theta) + (v*z - w*y)*sin(theta)
Y= v*(u*x + v*y + w*z)*(1 - cos(theta)) + y*cos(theta) + (w*x - u*z)*sin(theta)
Z= w*(u*x + v*y + w*z)*(1 - cos(theta)) + z*cos(theta) + (u*y - v*x)*sin(theta)

This appears to be numerically stable regardless of the values of the input
variables.

letting
dot = u*x + v*y + w*z
c = cos(theta)
d = (1 - cos(theta))
s = sin(theta)

this becomes

X = u*dot*d + x*c + (v*z - w*y)*s
Y = v*dot*d + y*c + (w*x - u*z)*s
Z = w*dot*d + z*c + (u*y - v*x)*s

*/

VectorIJK KittingViewer::rotate( /* ARGUMENTS                             */
 VectorIJK vec,                  /* vector to rotate                      */
 VectorIJK axle,                 /* unit vector about which to rotate vec */
 double theta)                   /* angle by which to rotate vec          */
{
  double x;
  double y;
  double z;
  double u;
  double v;
  double w;
  VectorIJK ret;
  double dot;
  double c;
  double d;
  double s;

  x = vec.i;
  y = vec.j;
  z = vec.k;
  u = axle.i;
  v = axle.j;
  w = axle.k;
  dot = u*x + v*y + w*z;
  c = cos(theta);
  d = 1 - c;
  s = sin(theta);
  ret.i = u*dot*d + x*c + (v*z - w*y)*s;
  ret.j = v*dot*d + y*c + (w*x - u*z)*s;
  ret.k = w*dot*d + z*c + (u*y - v*x)*s;
  return ret;
}

/********************************************************************/

/* KittingViewer::runAgain

Returned Value: none

Called By: keyboard (in viewKitting.cc)

This runs the simulation over again from the beginning. All stored values
that need to be cleared are cleared, and the files are reread. This is
called if the user presses the 'a' (again) key.

*/

void KittingViewer::runAgain() /* NO ARGUMENTS */
{
  resetViewer();
  init();
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
      setWorkstationLocation(iter->second, allSolids);
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

Called By:
  KittingViewer::createKit
  KittingViewer::recordInitialPositions
  KittingViewer::setLocationsAndColors

This finds the chain of primary locations (locationStack) leading from
the object back to the workstation and uses it to find the location of
the object relative to the workstation. That location is inserted as
the first element of the object's list of secondary locations.

If a location found while tracing the chain is a relative location, a
pose location with same origin and orientation as the reference object
is put on the stack instead of the relative location.

While the function is constructing the locationStack, it also adds the
object to the refFor list of the refThing and sets object->refThing
to refThing.

This function will not return if there is a loop of reference objects.
Might add a check for that. The locationStack would grow until memory
is exhausted.

*/

void KittingViewer::setWorkstationLocation(          /* ARGUMENTS        */
 SolidObjectType * object,                           /* object to locate */
 std::map<std::string, SolidObjectType *> allSolids) /* map of solid objects */
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
  iter = allSolids.find(refObjectName);
  refThing = iter->second;
  refThing->refFor.push_back(object);
  object->refThing = refThing;
  while (dynamic_cast<KittingWorkstationType *>(refThing) == 0)
    {
      locationStack.push_front(refThing->PrimaryLocation);
      ref = refThing->PrimaryLocation->RefObject;
      refObjectName = ref->val;
      iter = allSolids.find(refObjectName);
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

/* KittingViewer::usageMessage

Returned Value: none

Called By: KittingViewer::readArguments

This prints a message about how to use kittingViewer. The command must match
one of the two following templates. 

KittingViewer -c <commandFile> -i <initFile> -g <goalFile> -e <equiv> [-s <scoringFile>] [-t <tolerance>]

KittingViewer -b <asBuiltFile> -i <initFile> -g <goalFile> -e <equiv> [-s <scoringFile>] [-t <tolerance>]

*/

void KittingViewer::usageMessage( /* ARGUMENTS                              */
 char * command)   /* command with which the user started the kittingViewer */
{
  fprintf(stderr, "usage is either of the following\n\n");
  fprintf(stderr,
	  "%s -c <commandFile> -i <initFile> -g <goalFile> "
	  "-e <equiv> [-s <scoringFile>] [-t <tolerance>]\n\n",
	  command);
  fprintf(stderr,
	  "%s -b <asBuiltFile> -i <initFile> -g <goalFile> "
	  "-e <equiv> [-s <scoringFile>] [-t <tolerance>]\n\n",
	  command);
  fprintf(stderr,
	  "commandFile is the name of a file of canonical robot commands\n");
  fprintf(stderr,
	  "asBuiltFile, initFile, and goalFile are names of XML "
	  "kitting workstation files\n");
  fprintf(stderr,
	  "equiv = true or false; true = "
	  "same design goal objects are equivalent\n");
  fprintf(stderr,
	  "scoringFile is the name of an XML file for scoring\n");
  fprintf(stderr,
	  "tolerance is location tolerance in millimeters, default is %lf\n\n",
	  TINYDISTANCE);
  fprintf(stderr, "Example1:\n");
  fprintf(stderr,
	  "%s -c commands -i init.xml -g goal.xml -e true -t 1.5\n\n",
	  command);
  fprintf(stderr,
	  "Example2:\n");
  fprintf(stderr,
	  "%s -b built.xml -i init.xml -g goal.xml -e false -s score.xml\n\n",
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
      fprintf(stderr, "Fatal error: bad taperSide %s in a valueFunctionType\n",
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
  KittingViewer::readArguments(argc, argv);
  KittingViewer::init();
  KittingViewer::printInstructions();
  glInit(argc, argv, "Kitting Viewer");
  glutMainLoop();
  
  return 0;
}

/********************************************************************/

