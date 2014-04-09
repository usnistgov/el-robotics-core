///////////////////////////////////////////////////////////////////////////////
//
//  Original System: Neural Tissue
//  Subsystem:       Unit Test
//  Workfile:        main.cpp
//  Revision:        8 August, 2008
//  Author:          J. Marvel
//
//  Description
//  ===========
//
///////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <iostream>
#include <string>
#include "../../portable.h"
//#include "../../Libraries/XML/xml.h"
#include "../../Libraries/Robot/robot.h"

using namespace Reporter;
using namespace Robot;
using namespace std;


void main ()
{
  int i;

  //! Create a new logger object for storing event/error logs during trials
  Logger *logger = new Logger();
  logger->log("begin test");

  //! Valid robots include:
  //!   Kuka_LWR
  //!   Robotiq
  //!   Schunk_SDH
  //!   DemoHack (combination of Kuka_LWR + Robotiq

  //! "dummy text" is placeholder until Robotiq interface is finished
  CRCL_Robot<Robotiq> JoesHand (logger, "dummy text");

  //! Tell the robot to go to "home" position of [0, 0, 0, 0]
  //! Robotiq hand only has 4 degree of freedom
  //! Note:  this value should be stored in some URDF/configuration file
  robotAxes robAxes (4);
  for (i = 0; i < robAxes.axes; ++i)
  {
    robAxes.axis[i] = 0.0f;
  }
  
  if (JoesHand.MoveToAxisTarget (robAxes) != SUCCESS)
  {
    logger->error ("UnitTest::main.cpp error calling MoveToAxisTarget");
  }

  logger->log("all done");

  //! Wait indefinitely...
  i = 0;
  while (true)
  {
	  Sleep (1000);
	  cout << i++ << endl;
  }
}