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
  robotPose myPose, poseIn;
  int kukaConnection;
  RCS_TIMER *cycleBlock = new RCS_TIMER(.25);
  TiXmlDocument kukaStatus;
  TiXmlHandle toSendHandle(&kukaStatus);
  TiXmlElement *cartesianStatus;
  TiXmlElement *cartesianUpdate;
  int nchars;
  TiXmlElement *cartesian;
  int debug = 0;
  int option;

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

  myPose.x = 0.0;
  myPose.y = 0.0;
  myPose.z = 0.0;
  myPose.xrot = 0.0;
  myPose.yrot = 0.0;
  myPose.zrot = 0.0;

  while(true)
    {
      TiXmlDocument kukaCorrections;
      TiXmlHandle correctionsHandle(&kukaCorrections);
      std::string str;
      enum {INBUF_LEN = 2048};
      char inbuf[INBUF_LEN];
      cartesianStatus =
	toSendHandle.FirstChild("Rob").FirstChild("Dat").Child(1).ToElement();
      cartesianStatus->SetDoubleAttribute("X", myPose.x); 
      cartesianStatus->SetDoubleAttribute ("Y", myPose.y);
      cartesianStatus->SetDoubleAttribute ("Z", myPose.z);
      cartesianStatus->SetDoubleAttribute ("A", myPose.xrot);
      cartesianStatus->SetDoubleAttribute ("B", myPose.yrot);
      cartesianStatus->SetDoubleAttribute ("C", myPose.zrot);
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
      cartesianUpdate->QueryDoubleAttribute ("X", &(poseIn.x));
      cartesianUpdate->QueryDoubleAttribute ("Y", &(poseIn.y));
      cartesianUpdate->QueryDoubleAttribute ("Z", &(poseIn.z));
      cartesianUpdate->QueryDoubleAttribute ("A", &(poseIn.xrot));
      cartesianUpdate->QueryDoubleAttribute ("B", &(poseIn.yrot));
      cartesianUpdate->QueryDoubleAttribute ("C", &(poseIn.zrot));
      myPose.x += poseIn.x;
      myPose.y += poseIn.y;
      myPose.z += poseIn.z;
      myPose.xrot += poseIn.xrot;
      myPose.yrot += poseIn.yrot;
      myPose.zrot += poseIn.zrot;
      if(debug)
      printf( "kukaRobot Status: <%3.1f, %3.1f, %3.1f> <%3.1f, %3.1f, %3.1f>\n\n",
	      myPose.x,
	      myPose.y,
	      myPose.z,
	      myPose.xrot,
	      myPose.yrot,
	      myPose.zrot);
      cycleBlock->wait();
    }
}
