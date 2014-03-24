#include <string.h>
#include <iostream>
#include "database/Robot.h"
#include "database/EndEffector.h"

int main()
{
  std::string robotName = "robot_1";
  std::string solidObjectName = "part_c_1";
  Robot* robot = new Robot(robotName);
  SolidObject* solidObject = new SolidObject(solidObjectName);
  EndEffector* endEffector;
  EndEffector* endEffector2;

  // get the robot and solid object
  robot->get(robotName);
  solidObject->get(solidObjectName);

  // get gripper being used by robot and set held object
  endEffector = robot->gethadByEndEffector_Robot();
  std::cout<< "Setting effector named: " << endEffector->getname() << std::endl;
  endEffector->get(endEffector->getname());
  endEffector->sethadByHeldObject_EndEffector(solidObject);
  endEffector->set(endEffector->getname());

  endEffector2 = robot->gethadByEndEffector_Robot();
  std::cout<< "requesting effector named: " << endEffector2->getname() << std::endl;
  endEffector2->get(endEffector2->getname());
  // get what is being held
  solidObject = endEffector2->gethadByHeldObject_EndEffector();
  if( solidObject == NULL ) // robot must have dropped the part!
    {
      std::cout<< "CanonicalRobotCommand:: robot not holding anything and it should be!\n";
    }
  else
    std::cout << "Effector " << endEffector2->getname() << " holding " <<
      solidObject->getname() << std::endl;
}
