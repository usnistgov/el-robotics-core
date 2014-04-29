#ifndef CRCL_ROBOT_H
#define CRCL_ROBOT_H

/*!
  \defgroup CRCL_ROBOT The CRCL Robot Interface

  The CRCL is centered on the observation that a common syntax is needed
  for describing industrial robot programs without relying on
  platform-specific languages or proprietary planning formats.  The
  result is a minimal collection of functions that every robot is
  expected to be able to interpret.

  A robot system capable of interpreting CRCL syntax is expected to
  consist of 1) a robot controller that accepts and executes CRCL
  functions, 2) a plan interpreter that reads a planning domain
  definition language (PDDL) file and outputs one or more CRCL commands
  to the controller, and 3) a world state database for the robot system.
  The plan interpreter issues commands to the robot controller in the
  form of CRCL syntax.  The robot controller updates the world state,
  while both the robot controller and the plan interpreter can receive
  information from the world state.  Visually, the topology of the robot
  system is illustrated in Figure 2, where the arrows indicate the flow
  of information between system components.

  \image html crcl-fig-02.png
  Figure 2: The canonical robot command topology.  The plan
  interpreter extracts a plan from a PDDL file, defines a series of
  CRCL syntax commands that achieve the plan and submits them to the
  robot controller.  The robot controller then executes the CRCL
  program, updating the world state as necessary.

  From the original canonical robot command perspective, a physical
  robot system consists of a single industrial robot arm capable of
  positioning itself within its Cartesian work volume (within some set
  level of tolerance).  The speed and acceleration of the robot’s
  motions are controllable, and a single end effector (presumably some
  form of simple gripper) can be attached to the robot’s tool flange at
  a time.  Additional end effectors are stored on a tool changing
  station.  It is assumed that the robot can move the arm or the gripper
  at any time, but not both simultaneously.

  Although there is not a perfect one-to-one mapping between CRCL and
  the set of all industrial robot application commands, a sufficient
  analogue can be derived through creative interpretation.  For example,
  a planner may employ the CloseGripper and OpenGripper functions to
  toggle the active state of a robot’s welding tip.  Similarly, certain
  CRCL functionalities are interpreted liberally.  For example, the
  original CRCL description specified robot poses in terms of 6 degrees
  of freedom (6DOF) Cartesian coordinates of the tool relative to the
  robot’s workstation.  If no tool is attached, then the system
  interprets the motion commands to be relative to the tool flange.  We
  relax this definition slightly such that poses are in terms of the
  tool center point (TCP), which, for AGVs and associated onboard
  equipment, is defined to be relative to the AGV’s origin.

  When given commands that they are otherwise unable to execute (e.g.,
  sending CloseToolChanger to a robot without a tool flange), the robot
  controller is expected to take appropriate action.  No specific
  actions are given, however, and it is generally expected that the
  remainder of the plan will be ignored.
*/

#include "crcl.h"		/* robotPose, robotAxes, CRCLProgramParams */

class CRCL_Robot {
 public:
  CRCL_Robot() {};
  ~CRCL_Robot() {};

  CanonReturn Couple (char *targetID) {};
  CanonReturn Dwell (int *events, double *params, int numEvents) {};
  CanonReturn EndCanon (int reason) {};
  CanonReturn InitCanon () {};
  CanonReturn Message (char *message) {};
  CanonReturn MoveStraightTo (robotPose pose) {};
  CanonReturn MoveThroughTo (robotPose *poses,
			     int numPoses,
			     robotPose *accelerations = NULL,
			     robotPose *speeds = NULL,
			     robotPose *tolerances = NULL) {};
  CanonReturn Decouple (char *targetID) {};
  CanonReturn GetRobotAxes (robotAxes *axes) {};
  CanonReturn GetRobotPose (robotPose *pose) {};
  CanonReturn MoveAttractor (robotPose pose) {};
  CanonReturn MoveToAxisTarget (robotAxes axes) {};
  CanonReturn RunProgram (char *programName, CRCLProgramParams params) {};
  CanonReturn SetAbsoluteAcceleration (double acceleration) {};
  CanonReturn SetAbsoluteSpeed (double speed) {};
  CanonReturn SetAngleUnits (char *unitName) {};
  CanonReturn SetAxialSpeeds (double *speeds) {};
  CanonReturn SetAxialUnits (char **unitNames) {};
  CanonReturn SetEndPoseTolerance (robotPose tolerance) {};
  CanonReturn SetIntermediatePoseTolerance (robotPose *tolerances) {};
  CanonReturn SetLengthUnits (char *unitName) {};
  CanonReturn SetParameter (char *paramName, void *paramVal) {};
  CanonReturn SetTool (double percent) {};
  // consider a GetTool (double *percent) method
  CanonReturn SetRelativeSpeed (double percent) {};
  CanonReturn StopMotion (int condition) {};
};

#endif	/* CRCL_ROBOT_H */

