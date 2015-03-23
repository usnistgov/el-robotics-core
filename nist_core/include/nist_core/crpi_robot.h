///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRPI
//  Subsystem:       Robot Interface
//  Workfile:        Robot.h
//  Revision:        1.0 - 11 March, 2014
//                   1.1 - 30 January, 2015 - Updated with formal IO definitions
//                   2.0 - 20 February, 2015 - Transition from CRCL to CRPI.
//                                             Added CRCL XML handler.
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Robot interface declarations.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef crpi_robot_H
#define crpi_robot_H

#include <stddef.h>

#include "nist_core/nist_core.h"
#include "nist_core/crpi.h"
#include "nist_core/crcl_xml.h"
#include "nist_core/matrix.h"
#include "nist_core/vector.h"

using namespace std;
using namespace Xml;

namespace crpi_robot
{

  //! @ingroup Robot
  //!
  //! @brief Common template interface for the various robot subtypes
  //!
  template <class T> class LIBRARY_API CrpiRobot
  {
  public:

    //! @brief Default constructor
    //!
    //! @param initPath Path to the file containing the robot's initialization parameters
    //!
    CrpiRobot (char *initPath);

    //! @brief Default destructor
    //!
    ~CrpiRobot ();

    //! @brief Dock with a specified target object
    //!
    //! @param targetID The name of the object with which the robot should dock
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn Couple (const char *targetID);

    //! @brief Undock with a specified target object
    //!
    //! @param targetID The name of the object from which the robot should undock
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn Decouple (const char *targetID);

    //! @brief Stay motionless until an event occurs
    //!
    //! @param events    An array of event identifiers to signal that motions is to resume.  Refer to
    //!                  CRPI documentation for description and paramters for these events.
    //! @param params    An array of parameters associated with the array of events that bounds the
    //                   response to different events
    //! @param numEvents The size of the events array and the parameters array
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn Dwell (int *events, double *params, int numEvents);

    //! @brief Stop executing canonical robot commands
    //!
    //! @param reason Numerical representation of enumerated reasons for halting execution.
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn EndCanon (int reason);

    //! @brief Get feedback from the robot regarding its current axis configuration
    //!
    //! @param axes Axis array to be populated by the method
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn GetRobotAxes (robotAxes *axes);

    //! @brief Get I/O feedback from the robot
    //!
    //! @Param io Digital and analog I/O data structure to be populated by the method
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn GetRobotIO (robotIO *io);

    //! @brief Get feedback from the robot regarding its current position in Cartesian space
    //!
    //! @param pose Cartesian pose data structure to be populated by the method
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn GetRobotPose (robotPose *pose);

    //! @brief Do whatever is necessary to get ready to move
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn InitCanon ();

    //! @brief Display a message on the operator console
    //!
    //! @param message The plain-text message to be displayed on the operator console
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn Message (const char *message);
    
    //! @brief Move a virtual attractor to a specified coordinate in Cartesian space for force control
    //!
    //! @param pose The 6DOF destination of the virtual attractor 
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn MoveAttractor (robotPose pose);

    //! @brief Move the robot in a straight line from the current pose to a new pose and stop there
    //!
    //! @param pose The target 6DOF pose for the robot
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn MoveStraightTo (robotPose pose);

    //! @brief Move the controlled point along a trajectory passing through or near all but the last
    //!        of a series of poses, and then stop at the last pose
    //!
    //! @param poses         An array of 6DOF poses through/near which the robot is expected to pass
    //! @param numPoses      The number of sub-poses in the submitted array
    //! @param accelerations (optional) An array of 6DOF accelaration profiles for each motion
    //!                      associated with the target poses
    //! @param speeds        (optional) An array of 6DOF speed profiles for each motion assiciated
    //!                      with the target poses
    //! @param tolerances    (optional) An array of 6DOF tolerances in length and angle units for the
    //!                      specified target poses
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    //! @note The length of the optional parameter arrays, if provided, must be equal to numPoses.
    //! @note Defining accerlations, speeds, and tolerances does not overwrite the defined default
    //!       values
    //!
    CanonReturn MoveThroughTo (robotPose *poses,
                               int numPoses,
                               robotPose *accelerations = NULL,
                               robotPose *speeds = NULL,
                               robotPose *tolerances = NULL);

    //! @brief Move the controlled pose along any convenient trajectory from the current pose to the
    //!        target pose, and then stop.
    //!
    //! @param pose The target 6DOF Cartesian pose for the robot's TCP in Cartesian space coordinates
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn MoveTo (robotPose pose);

    //! @brief Move the robot axes to the specified target values
    //!
    //! @param axes An array of target axis values specified in the current axial unit
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn MoveToAxisTarget (robotAxes axes);

    //! @brief Run a specific, pre-written program or function on the robot
    //!
    //! @param programName The name of the program function to be executed by the robot
    //! @param params      The pre-specified parameters to be passed to the function
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn RunProgram (const char *programName, CRPIProgramParams params);

    //! @brief Set the accerlation for the controlled pose to the given value in length units per
    //!        second per second
    //!
    //! @param acceleration The target TCP acceleration 
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn SetAbsoluteAcceleration (double acceleration);

    //! @brief Set the speed for the controlled pose to the given value in length units per second
    //!
    //! @param speed The target Cartesian speed
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn SetAbsoluteSpeed (double speed);

    //! @brief Set angel units to the unit specified
    //!
    //! @param unitName The name of the angle units in plain text ("degree" or "radian")
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn SetAngleUnits (const char *unitName);

    //! @brief Set the axis-specific speeds for the motion of axis-space motions
    //!
    //! @param speeds Array of target axial motion speeds
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn SetAxialSpeeds (double *speeds);

    //! @brief Set specific axial units to the specified values
    //!
    //! @param unitNames Array of axis-specific names of the axis units in plain text
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn SetAxialUnits (const char **unitNames);

    //! @brief Set the default 6DOF tolerances for the pose of the robot in current length and angle
    //!        units
    //!
    //! @param tolerances Tolerances of the 6DOF end pose during Cartesian motion commands
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn SetEndPoseTolerance (robotPose tolerance);

    //! @brief Set the default 6DOF tolerance for smooth motion near intermediate points
    //!
    //! @param tolerances Tolerances of the 6DOF poses during multi-pose motions
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn SetIntermediatePoseTolerance (robotPose *tolerances);

    //! @brief Set length units to the unit specified
    //!
    //! @param unitName The name of the length units in plain text ("inch," "mm," and "meter")
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn SetLengthUnits (const char *unitName);

    //! @brief Set a robot-specific parameter (handling of parameter type casting to be handled by the
    //!        robot interface)
    //!
    //! @param paramName The name of the parameter variable to set
    //! @param paramVal  The value to be set to the specified robot parameter
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn SetParameter (const char *paramName, void *paramVal);

    //! @brief Set the accerlation for the controlled pose to the given percentage of the robot's
    //!        maximum acceleration
    //!
    //! @param percent The percentage of the robot's maximum acceration in the range of [0, 1]
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn SetRelativeAcceleration (double percent);

    //! @brief Set the speed for the controlled point to the given percentage of the robot's maximum
    //!        speed
    //!
    //! @param percent The percentage of the robot's maximum speed in the range of [0, 1]
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn SetRelativeSpeed (double percent);

    //! @brief Set the digital and analog outputs
    //!
    //! @Param io Digital and analog I/O outputs to set
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn SetRobotIO (robotIO io);

    //! @brief Set the attached tool to a defined output rate.
    //!
    //! @param percent The desired output rate for the robot's tool as a percentage of maximum output.
    //!                If using a gripper, 0 is all the way open, 1 is all the way closed.
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn SetTool (double percent);

    //! @brief Stop the robot's motions based on robot stopping rules
    //!
    //! @param condition The rule by which the robot is expected to stop (Estop category 0, 1, or 2);
    //!                  Estop category 2 is default
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn StopMotion (int condition = 2);

    //! @brief Convert CRCL XML to CRPI function calls
    //!
    //! @param str TODO
    //!
    //! @return SUCCESS if command is accepted and is executed successfully, REJECT if the command is
    //!         not accepted, and FAILURE if the command is accepted but not executed successfully
    //!
    CanonReturn XmlHandler (std::string &str);

      bool matrixRPYconvert (matrix &m, robotPose &pose);
    bool RPYMatrixConvert (const robotPose &pose, matrix &m);

  private:
    //! @brief Interface object for the different supported robots
    //!
    T *robInterface_;

    //! @brief TODO
    CrclXmlParams *params_;

    //! @brief TODO
    CrclXml *xml_;

    matrix *rotMatrix_;
    vector3D *v1_;
    vector3D *v2_;
    vector3D *v3_;

  }; // CrpiRobot
} // crpi_robot

#endif
