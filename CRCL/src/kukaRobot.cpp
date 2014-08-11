/*****************************************************************************
------------------------------------------------------------------------------
--  Copyright 2012-2013
--  Georgia Tech Research Institute
--  505 10th Street
--  Atlanta, Georgia 30332
--
--  This material may be reproduced by or for the U.S. Government
--  pursuant to the copyright license under the clause at DFARS
--  252.227-7013 (October 1988).
------------------------------------------------------------------------------
*****************************************************************************/
/*!
 *	\file		kukaRobot.cpp
 *	\brief 		Mimic kuka status reporting
 *                      This program receives corrections and immediately
 *                      applies them to a status buffer before sending
 *                      the buffer back out. It is designed to mimic
 *                      the motion of the kuka, but it will not timeout
 *                      if updates are not received in a timly mannor.
 *	\author		Stephen Balakirsky, GTRI
 *	\date		July 02, 2014
 *      \copyright      Georgia Tech Research Institute
 */
#include <tinyxml.h>
#include <stdio.h>		/* stdin, stderr */
#include <stddef.h>		/* NULL, sizeof */
#include <stdlib.h>		/* atoi, alloc */
#include <string>
#include <ctype.h>

#include <ulapi.h>

#include "CRCL/timer.hh"
#include "nist_core/crcl.h"
#include "CRCL/crclDefs.hh"

int main(int argc, char *argv[])
{
  double myJoints[ROBOT_DOF] = {1,2,3,4,5,6};
  double jointsIn[ROBOT_DOF];
  robotPose myPose, poseIn;
  int kukaConnection;
  RCS_TIMER *cycleBlock = new RCS_TIMER(KUKA_DEFAULT_CYCLE);
  TiXmlDocument kukaStatus;
  TiXmlHandle toSendHandle(&kukaStatus);
  TiXmlElement *cartesianStatus;
  TiXmlElement *cartesianUpdate;
  TiXmlElement *jointStatus;
  TiXmlElement *jointUpdate;
  TiXmlElement *IPOCUpdate;
  int nchars;
  TiXmlElement *cartesian;
  int debug = 0;
  int option;
  int counter = 0;
  double jointMotorScale[ROBOT_DOF], cmdMotorScale[ROBOT_DOF];

  jointMotorScale[0] = 80.;
  jointMotorScale[1] = 100.;
  jointMotorScale[2] = 80.;
  jointMotorScale[3] = 80.;
  jointMotorScale[4] = 80.;
  jointMotorScale[5] = 40.5;

  cmdMotorScale[0] = 1.4;
  cmdMotorScale[1] = 1.74;
  cmdMotorScale[2] = 1.4;
  cmdMotorScale[3] = 1.4;
  cmdMotorScale[4] = 1.4;
  cmdMotorScale[5] = 0.87;

  while (true) 
    {
      option = getopt(argc, argv, ":d");
      if (option == -1) break;
      switch (option) 
	{
	case 'd':
	  debug = 1;
	  break;
	case ':':
	  fprintf(stderr, "missing value for -%c\n", optopt);
	  return 1;
	  break;
	default:
	  fprintf (stderr, "unrecognized option -%c\n", optopt);
	  return 1;
	  break;
	} // switch (option)
    }   // while (true) for getopt


  if( !kukaStatus.LoadFile(DEFAULT_FROM_KUKA))
    {
      printf( "kukaRobot:: fatal error on load of %s\n", DEFAULT_FROM_KUKA);
      exit(1);
    }
  kukaConnection = ulapi_socket_get_client_id(KUKA_PORT, "localhost");
  if( kukaConnection < 0 )
    return -1;

  myPose.x = 0.1;
  myPose.y = 0.2;
  myPose.z = 0.3;
  myPose.xrot = 0.4;
  myPose.yrot = 0.5;
  myPose.zrot = 0.6;

  while(true)
    {
      TiXmlDocument kukaCorrections;
      TiXmlHandle correctionsHandle(&kukaCorrections);
      std::string str;
      enum {INBUF_LEN = 2048};
      char inbuf[INBUF_LEN];
      std::ostringstream s;
      cartesianStatus =
	toSendHandle.FirstChild("Rob").FirstChild("Dat").Child(1).ToElement();
      IPOCUpdate = toSendHandle.FirstChild("Rob").FirstChild("Dat").Child(9).
	ToElement();
      jointStatus =
	toSendHandle.FirstChild("Rob").FirstChild("Dat").Child(3).ToElement();
      cartesianStatus->SetDoubleAttribute("X", myPose.x); 
      cartesianStatus->SetDoubleAttribute ("Y", myPose.y);
      cartesianStatus->SetDoubleAttribute ("Z", myPose.z);
      cartesianStatus->SetDoubleAttribute ("A", myPose.xrot);
      cartesianStatus->SetDoubleAttribute ("B", myPose.yrot);
      cartesianStatus->SetDoubleAttribute ("C", myPose.zrot);
      jointStatus->SetDoubleAttribute("A1", myJoints[0]);
      jointStatus->SetDoubleAttribute("A2", myJoints[1]);
      jointStatus->SetDoubleAttribute("A3", myJoints[2]);
      jointStatus->SetDoubleAttribute("A4", myJoints[3]);
      jointStatus->SetDoubleAttribute("A5", myJoints[4]);
      jointStatus->SetDoubleAttribute("A6", myJoints[5]);

      s << counter++;
      s << '\0';
      TiXmlText *text = new TiXmlText((s.str()).c_str());
      IPOCUpdate->Clear();
      IPOCUpdate->LinkEndChild(text);
      //      kukaStatus.Print();
      str << kukaStatus;
      ulapi_socket_write(kukaConnection, str.c_str(), str.length());
      inbuf[0] = '\0';
      nchars = ulapi_socket_read(kukaConnection, inbuf, sizeof(inbuf)-1);
      if (nchars <= 0) 
	{
	  printf("kukaRobot::status client disconnected\n");
	  break;
	}
      else
	{
	inbuf[nchars] = '\0';
	}
      kukaCorrections.Parse(inbuf);
      //      kukaCorrections.Print();
      cartesianUpdate =
	correctionsHandle.FirstChild("Sen").FirstChild("Dat").
	Child(1).ToElement();
      jointUpdate =
	correctionsHandle.FirstChild("Sen").FirstChild("Dat").
	Child(2).ToElement();
      cartesianUpdate->QueryDoubleAttribute("X", &(poseIn.x));
      cartesianUpdate->QueryDoubleAttribute("Y", &(poseIn.y));
      cartesianUpdate->QueryDoubleAttribute("Z", &(poseIn.z));
      cartesianUpdate->QueryDoubleAttribute("A", &(poseIn.xrot));
      cartesianUpdate->QueryDoubleAttribute("B", &(poseIn.yrot));
      cartesianUpdate->QueryDoubleAttribute("C", &(poseIn.zrot));
      jointUpdate->QueryDoubleAttribute("A1", &(jointsIn[0]));
      jointUpdate->QueryDoubleAttribute("A2", &(jointsIn[1]));
      jointUpdate->QueryDoubleAttribute("A2", &(jointsIn[2]));
      jointUpdate->QueryDoubleAttribute("A4", &(jointsIn[3]));
      jointUpdate->QueryDoubleAttribute("A5", &(jointsIn[4]));
      jointUpdate->QueryDoubleAttribute("A6", &(jointsIn[5]));
      myPose.x += poseIn.x;
      myPose.y += poseIn.y;
      myPose.z += poseIn.z;
      myPose.xrot += poseIn.xrot;
      myPose.yrot += poseIn.yrot;
      myPose.zrot += poseIn.zrot;
      for( int i=0; i<ROBOT_DOF; i++ )
	myJoints[i] += jointsIn[i] * cmdMotorScale[i] / jointMotorScale[i];
      if(debug)
      printf( "kukaRobot Status: <%4.2f, %4.2f, %4.2f> <%4.2f, %4.2f, %4.2f>\n\n",
	      myPose.x,
	      myPose.y,
	      myPose.z,
	      myPose.xrot,
	      myPose.yrot,
	      myPose.zrot);
      cycleBlock->wait();
    }
}
