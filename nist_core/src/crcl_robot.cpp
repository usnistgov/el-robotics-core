
#include <stddef.h>
#include "nist_core/nist_core.h" // LIBRARY_API
#include "nist_core/crcl.h"
#include "nist_core/crcl_robot.h"

namespace crcl_robot {

  template <class T> LIBRARY_API CrclRobot<T>::CrclRobot(const char *init_path) {
    robInterface_ = new T();
  }

  template <class T> LIBRARY_API CrclRobot<T>::~CrclRobot() {
    delete robInterface_;
    robInterface_ = NULL;
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::SetTool(double percent) {
    return robInterface_->SetTool(percent);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::Couple(char *targetID) {
    return robInterface_->Couple(targetID);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::Dwell(int *events, double *params, int numEvents) {
    return robInterface_->Dwell(events, params, numEvents);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::EndCanon(int reason) {
    return robInterface_->EndCanon(reason);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::InitCanon() {
    return robInterface_->InitCanon();
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::Message(char *message) {
    return robInterface_->Message(message);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::MoveStraightTo(robotPose pose) {
    return robInterface_->MoveStraightTo(pose);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::MoveThroughTo(robotPose * poses, int numPoses,
		       robotPose * accelerations, robotPose * speeds,
		       robotPose * tolerances) {
    return robInterface_->MoveThroughTo(poses, numPoses, accelerations,
					speeds, tolerances);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::MoveTo(robotPose pose) {
    return robInterface_->MoveTo(pose);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::Decouple(char *targetID) {
    return robInterface_->Decouple(targetID);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::GetRobotAxes(robotAxes * axes) {
    return robInterface_->GetRobotAxes(axes);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::GetRobotPose(robotPose * pose) {
    return robInterface_->GetRobotPose(pose);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::MoveAttractor(robotPose pose) {
    return robInterface_->MoveAttractor(pose);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::MoveToAxisTarget(robotAxes axes) {
    return robInterface_->MoveToAxisTarget(axes);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::RunProgram(char *programName, CRCLProgramParams params) {
    return robInterface_->RunProgram(programName, params);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::SetAbsoluteAcceleration(double tolerance) {
    return robInterface_->SetAbsoluteAcceleration(tolerance);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::SetAbsoluteSpeed(double speed) {
    return robInterface_->SetAbsoluteSpeed(speed);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::SetAngleUnits(char *unitName) {
    return robInterface_->SetAngleUnits(unitName);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::SetAxialSpeeds(double *speeds) {
    return robInterface_->SetAxialSpeeds(speeds);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::SetAxialUnits(char **unitNames) {
    return robInterface_->SetAxialUnits(unitNames);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::SetEndPoseTolerance(robotPose tolerance) {
    return robInterface_->SetEndPoseTolerance(tolerance);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::SetIntermediatePoseTolerance(robotPose * tolerances) {
    return robInterface_->SetIntermediatePoseTolerance(tolerances);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::SetLengthUnits(char *unitName) {
    return robInterface_->SetLengthUnits(unitName);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::SetParameter(char *paramName, void *paramVal) {
    return robInterface_->SetParameter(paramName, paramVal);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::SetRelativeAcceleration(double percent) {
    return robInterface_->SetRelativeAcceleration(percent);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::SetRelativeSpeed(double percent) {
    return robInterface_->SetRelativeSpeed(percent);
  }

  template <class T> LIBRARY_API CanonReturn CrclRobot<T>::StopMotion(int condition) {
    return robInterface_->StopMotion(condition);
  }

}				// namespace crcl_robot
