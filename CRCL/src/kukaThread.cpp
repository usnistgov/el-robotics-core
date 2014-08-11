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
 *	\file		kukaThread.cpp
 *	\brief 		Communicate over Kuka Ethernet XML to robot arm
 *	\class		KukaThread
 *	\author		Stephen Balakirsky, GTRI
 *	\date		July 02, 2014
 *      \copyright      Georgia Tech Research Institute
 */
#include <stdio.h>
#include <math.h>
#include "CRCL/kukaThread.hh"
#include "CRCL/crclDefs.hh"

KukaThread::KukaThread(const char *toKukaXML, 
		       const char *fromKukaXML, 
		       double cycleTimeIn)
{
  debug = 0;
  kukaThreadBlock = new RCS_TIMER(cycleTimeIn);
  if( !toKuka.LoadFile(toKukaXML))
    {
      printf( "kukaThread:: fatal error on load of %s\n", toKukaXML);
      exit(1);
    }
  if( !fromKuka.LoadFile(fromKukaXML))
    {
      printf( "kukaThread:: fatal error on load of %s\n", toKukaXML);
      exit(1);
    }
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

  kukaServer = -1;
}

void KukaThread::connectRobot()
{
  if( kukaServer < 0 )
    kukaServer = ulapi_socket_get_server_id(KUKA_PORT);
  if (kukaServer < 0) 
    {
      fprintf(stderr, "kukaThread: can't serve kuka port %d\n", KUKA_PORT);
      return;
    }
  if(debug)
    printf("kukaThread: serving kuka port %d, waiting...\n", KUKA_PORT);
  kukaConnection = ulapi_socket_get_connection_id(kukaServer);
  if (kukaConnection < 0) 
    {
      fprintf(stderr, "kukaThread:: can't get status client connecton\n");
      return;
    }
  if(debug) 
    printf("kukaThread: got a status client connection on id %d\n", 
	   kukaConnection);
}

void KukaThread::threadStart(KukaThreadArgs *argsIn)
{
  args = argsIn;

  connectRobot();
  while(true)
    {
    enum {INBUF_LEN = 2048};
    char inbuf[INBUF_LEN];
    std::string stringToKuka;
    int nchars;
    std::string krcIPOC;

    nchars = ulapi_socket_read(kukaConnection, inbuf, sizeof(inbuf)-1);
    if (nchars <= 0) 
      {
	if(debug) printf("kukaThread::status client disconnected\n");
	connectRobot();
      }
    else
      inbuf[nchars] = '\0';

    krcIPOC = setStatus(inbuf);
    //    printf("krcIPOC: %s\n", krcIPOC.c_str());
    stringToKuka = setCorrections(krcIPOC);
    //    zeroCorrections();
    //    if(debug)
    if(0)
      printf( "New message\n%s\n", stringToKuka.c_str());
    ulapi_socket_write(kukaConnection, stringToKuka.c_str(), 
		       stringToKuka.length());
    kukaThreadBlock->wait();
    }
}

void KukaThread::setDebug(int debugLevel)
{
  debug = debugLevel;
  printf( "kukaThread:: seting debug to %d\n", debug );
}

void KukaThread::zeroCorrections()
{
  robotPose poseCorrection;
  poseCorrection.x = 0;
  poseCorrection.y = 0;
  poseCorrection.z = 0;
  poseCorrection.xrot = 0;
  poseCorrection.yrot = 0;
  poseCorrection.zrot = 0;
  args->setPoseCorrection(poseCorrection);
}

std::string KukaThread::setCorrections(std::string krcIPOC)
{
  TiXmlHandle kukaCmdHandle (&toKuka);
  std::string returnString;
  TiXmlElement *cartesianCmd;
  TiXmlElement *jointCmd;
  TiXmlElement *externalCmd;
  TiXmlElement *cmdIPOC;
  robotPose poseCorrection;
  KukaState currentState;

  poseCorrection = args->getPoseCorrection(1); //zero after read
  currentState = args->getCurrentState();
  
  cartesianCmd =
    kukaCmdHandle.FirstChild("Sen").FirstChild("Dat").Child(1).ToElement();
  jointCmd =
    kukaCmdHandle.FirstChild("Sen").FirstChild("Dat").Child(2).ToElement();
  externalCmd =
    kukaCmdHandle.FirstChild("Sen").FirstChild("Dat").Child(3).ToElement();
  cmdIPOC =
    kukaCmdHandle.FirstChild("Sen").FirstChild("Dat").Child(6).ToElement();
  cmdIPOC->Clear();
  TiXmlText *text = new TiXmlText(krcIPOC.c_str());
  cmdIPOC->LinkEndChild(text);
  if( args->getCartesianMove() )
    {
      cartesianCmd->SetDoubleAttribute("X", poseCorrection.x);
      cartesianCmd->SetDoubleAttribute("Y", poseCorrection.y);
      cartesianCmd->SetDoubleAttribute("Z", poseCorrection.z);
      /* debug
      cartesianCmd->SetDoubleAttribute("A", poseCorrection.zrot);
      cartesianCmd->SetDoubleAttribute("B", poseCorrection.yrot);
      cartesianCmd->SetDoubleAttribute("C", poseCorrection.xrot);
      */
      cartesianCmd->SetDoubleAttribute("A", 0);
      cartesianCmd->SetDoubleAttribute("B", 0);
      cartesianCmd->SetDoubleAttribute("C", 0);

      // end of debug
      jointCmd->SetDoubleAttribute("A1", 0);
      jointCmd->SetDoubleAttribute("A2", 0);
      jointCmd->SetDoubleAttribute("A3", 0);
      jointCmd->SetDoubleAttribute("A4", 0);
      jointCmd->SetDoubleAttribute("A5", 0);
      jointCmd->SetDoubleAttribute("A6", 0);
      externalCmd->SetDoubleAttribute("E1", 0); 
      externalCmd->SetDoubleAttribute("E2", 0);
      externalCmd->SetDoubleAttribute("E3", 0);
      externalCmd->SetDoubleAttribute("E4", 0);
      externalCmd->SetDoubleAttribute("E5", 0);
      externalCmd->SetDoubleAttribute("E6", 0);
    }
  else
    {
      // set weird scales
      poseCorrection.x *= jointMotorScale[0]/cmdMotorScale[0];
      poseCorrection.y *= jointMotorScale[1]/cmdMotorScale[1];
      poseCorrection.z *= jointMotorScale[2]/cmdMotorScale[2];
      poseCorrection.xrot *= jointMotorScale[3]/cmdMotorScale[3];
      poseCorrection.yrot *= jointMotorScale[4]/cmdMotorScale[4];
      poseCorrection.zrot *= jointMotorScale[5]/cmdMotorScale[5];// *1.25;
      cartesianCmd->SetDoubleAttribute("X", 0.);
      cartesianCmd->SetDoubleAttribute("Y", 0.);
      cartesianCmd->SetDoubleAttribute("Z", 0.);
      cartesianCmd->SetDoubleAttribute("A", 0.);
      cartesianCmd->SetDoubleAttribute("B", 0.);
      cartesianCmd->SetDoubleAttribute("C", 0.);
      jointCmd->SetDoubleAttribute("A1", poseCorrection.x);
      jointCmd->SetDoubleAttribute("A2", poseCorrection.y);
      jointCmd->SetDoubleAttribute("A3", poseCorrection.z);
      jointCmd->SetDoubleAttribute("A4", poseCorrection.xrot);
      jointCmd->SetDoubleAttribute("A5", poseCorrection.yrot);
      jointCmd->SetDoubleAttribute("A6", poseCorrection.zrot);
      externalCmd->SetDoubleAttribute("E1", 0); 
      externalCmd->SetDoubleAttribute("E2", 0);
      externalCmd->SetDoubleAttribute("E3", 0);
      externalCmd->SetDoubleAttribute("E4", 0);
      externalCmd->SetDoubleAttribute("E5", 0);
      externalCmd->SetDoubleAttribute("E6", 0);
    }
  returnString << toKuka;
  //  if(debug)
  if(0)
    {
      printf( "\x1b[32mkukaThread Read Cart Status: <%3.1f, %3.1f, %3.1f> <%3.1f, %3.1f, %3.1f>\x1b[0m\n",
	      currentState.cartesian[0],
	      currentState.cartesian[1],
	      currentState.cartesian[2],
	      currentState.cartesian[3],
	      currentState.cartesian[4],
	      currentState.cartesian[5]);
      printf( "\x1b[32mkukaThread Read Joint Status: <%3.1f, %3.1f, %3.1f> <%3.1f, %3.1f, %3.1f>\x1b[0m\n",
	      currentState.joint[0],
	      currentState.joint[1],
	      currentState.joint[2],
	      currentState.joint[3],
	      currentState.joint[4],
	      currentState.joint[5]);
      printf( "\x1b[32mkukaThread Read External Status: <%3.1f, %3.1f, %3.1f> <%3.1f, %3.1f, %3.1f>\x1b[0m\n",
	      currentState.external[0],
	      currentState.external[1],
	      currentState.external[2],
	      currentState.external[3],
	      currentState.external[4],
	      currentState.external[5]);
      printf( "\x1b[32mkukaThread corrections sent: <%4.2f, %4.2f, %4.2f> <%4.2f, %4.2f, %4.2f>\x1b[0m\n",
	      poseCorrection.x,
	      poseCorrection.y,
	      poseCorrection.z,
	      poseCorrection.xrot,
	      poseCorrection.yrot,
	      poseCorrection.zrot);
    }
  return returnString;
}

/* this routine returns the IPOC value from the message
 * The IPOC identifies the request. The response must have the same IPOC value.
 */
std::string KukaThread::setStatus(char *buf)
{
  TiXmlElement *cartesian;
  TiXmlElement *joint;
  TiXmlElement *external;
  TiXmlElement *krcIPOC;
  TiXmlDocument statusIn;
  TiXmlHandle kukaStatusHandle(&statusIn);
  KukaState kukaState;

  statusIn.Parse(buf);
  
  kukaState = args->getCurrentState();
  cartesian =
    kukaStatusHandle.FirstChild("Rob").FirstChild("Dat").Child(1).ToElement();
  joint =
    kukaStatusHandle.FirstChild("Rob").FirstChild("Dat").Child(3).ToElement();
  external =
    kukaStatusHandle.FirstChild("Rob").FirstChild("Dat").Child(5).ToElement();
  krcIPOC =
    kukaStatusHandle.FirstChild("Rob").FirstChild("Dat").Child(9).ToElement();

  cartesian->QueryDoubleAttribute("X", &(kukaState.cartesian[0]));
  cartesian->QueryDoubleAttribute("Y", &(kukaState.cartesian[1]));
  cartesian->QueryDoubleAttribute("Z", &(kukaState.cartesian[2]));
  cartesian->QueryDoubleAttribute("A", &(kukaState.cartesian[5]));
  cartesian->QueryDoubleAttribute("B", &(kukaState.cartesian[4]));
  cartesian->QueryDoubleAttribute("C", &(kukaState.cartesian[3]));

  if( kukaState.cartesian[3] < 0 ) // make roll 0 - 360
    kukaState.cartesian[3] = 360 + kukaState.cartesian[3];
  /*
  if( kukaState.cartesian[4] < 0 ) // make 0 - 360
    kukaState.cartesian[4] = 360 + kukaState.cartesian[4];
  if( kukaState.cartesian[5] < 0 ) // make yaw 0 - 360
    kukaState.cartesian[5] = 360 + kukaState.cartesian[5];
  */

  joint->Attribute("A1", &(kukaState.joint[0]));
  joint->Attribute("A2", &(kukaState.joint[1]));
  joint->Attribute("A3", &(kukaState.joint[2]));
  joint->Attribute("A4", &(kukaState.joint[3]));
  joint->Attribute("A5", &(kukaState.joint[4]));
  joint->Attribute("A6", &(kukaState.joint[5]));
  external->Attribute("E1", &(kukaState.external[0]));
  external->Attribute("E2", &(kukaState.external[1]));
  external->Attribute("E3", &(kukaState.external[2]));
  external->Attribute("E4", &(kukaState.external[3]));
  external->Attribute("E5", &(kukaState.external[4]));
  external->Attribute("E6", &(kukaState.external[5]));
  args->setCurrentState(&kukaState);
  return krcIPOC->GetText();
}
