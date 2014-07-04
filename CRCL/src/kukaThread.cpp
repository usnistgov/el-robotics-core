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
#include "CRCL/kukaThread.hh"
#include "CRCL/crclDefs.hh"

KukaThread::KukaThread(const char *toKukaXML, 
		       const char *fromKukaXML, 
		       double cycleTimeIn)
{
  debug = 1;
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
}

void KukaThread::threadStart(KukaThreadArgs *argsIn)
{
  int kukaServer;
  int kukaConnection;
  
  args = argsIn;
  ulapi_mutex_init(&args->poseCorrectionMutex, 1);  
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

  ulapi_mutex_give(&args->poseCorrectionMutex);

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
	break;
      }
    else
      inbuf[nchars] = '\0';

    ulapi_mutex_take(&args->poseCorrectionMutex);
    krcIPOC = setStatus(inbuf);
    stringToKuka = setCorrections(krcIPOC);
    zeroCorrections();
    //    printf( "New message\n%s\n", stringToKuka.c_str());
    ulapi_socket_write(kukaConnection, stringToKuka.c_str(), stringToKuka.length());
    ulapi_mutex_give(&args->poseCorrectionMutex);
    kukaThreadBlock->wait();
    }
}

void KukaThread::zeroCorrections()
{
  args->poseCorrection.x = 0;
  args->poseCorrection.y = 0;
  args->poseCorrection.z = 0;
  args->poseCorrection.xrot = 0;
  args->poseCorrection.yrot = 0;
  args->poseCorrection.zrot = 0;
}

std::string KukaThread::setCorrections(std::string krcIPOC)
{
  TiXmlHandle kukaCmdHandle (&toKuka);
  std::string returnString;
  TiXmlElement *cartesianCmd;
  TiXmlElement *jointCmd;
  TiXmlElement *externalCmd;
  TiXmlElement *cmdIPOC;

  cartesianCmd =
    kukaCmdHandle.FirstChild("Sen").FirstChild("Dat").Child(1).ToElement();
  jointCmd =
    kukaCmdHandle.FirstChild("Sen").FirstChild("Dat").Child(2).ToElement();
  externalCmd =
    kukaCmdHandle.FirstChild("Sen").FirstChild("Dat").Child(3).ToElement();
  cmdIPOC =
    kukaCmdHandle.FirstChild("Sen").FirstChild("Dat").Child(6).ToElement();
  *cmdIPOC = krcIPOC.c_str();
  cartesianCmd->SetDoubleAttribute("X", args->poseCorrection.x);
  cartesianCmd->SetDoubleAttribute("Y", args->poseCorrection.y);
  cartesianCmd->SetDoubleAttribute("Z", args->poseCorrection.z);
  cartesianCmd->SetDoubleAttribute("A", args->poseCorrection.xrot);
  cartesianCmd->SetDoubleAttribute("B", args->poseCorrection.yrot);
  cartesianCmd->SetDoubleAttribute("C", args->poseCorrection.zrot);
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
  returnString << toKuka;
  if(debug)
    printf( "\x1b[32mkukaThread corrections sent: <%3.1f, %3.1f, %3.1f> <%3.1f, %3.1f, %3.1f>\x1b[0m\n",
	    args->poseCorrection.x,
	    args->poseCorrection.y,
	    args->poseCorrection.z,
	    args->poseCorrection.xrot,
	    args->poseCorrection.yrot,
	    args->poseCorrection.zrot);
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
  //  printf( "%s\n\n", buf );
  statusIn.Parse(buf);
  cartesian =
    kukaStatusHandle.FirstChild("Rob").FirstChild("Dat").Child(1).ToElement();
  joint =
    kukaStatusHandle.FirstChild("Rob").FirstChild("Dat").Child(3).ToElement();
  external =
    kukaStatusHandle.FirstChild("Rob").FirstChild("Dat").Child(5).ToElement();
  krcIPOC =
    kukaStatusHandle.FirstChild("Rob").FirstChild("Dat").Child(9).ToElement();

  cartesian->QueryDoubleAttribute("X", &(args->currentState.cartesian[0]));
  cartesian->QueryDoubleAttribute("Y", &(args->currentState.cartesian[1]));
  cartesian->QueryDoubleAttribute("Z", &(args->currentState.cartesian[2]));
  cartesian->QueryDoubleAttribute("A", &(args->currentState.cartesian[3]));
  cartesian->QueryDoubleAttribute("B", &(args->currentState.cartesian[4]));
  cartesian->QueryDoubleAttribute("C", &(args->currentState.cartesian[5]));
  joint->Attribute("A1", &(args->currentState.joint[0]));
  joint->Attribute("A2", &(args->currentState.joint[1]));
  joint->Attribute("A3", &(args->currentState.joint[2]));
  joint->Attribute("A4", &(args->currentState.joint[3]));
  joint->Attribute("A5", &(args->currentState.joint[4]));
  joint->Attribute("A6", &(args->currentState.joint[5]));
  external->Attribute("E1", &(args->currentState.external[0]));
  external->Attribute("E2", &(args->currentState.external[1]));
  external->Attribute("E3", &(args->currentState.external[2]));
  external->Attribute("E4", &(args->currentState.external[3]));
  external->Attribute("E5", &(args->currentState.external[4]));
  external->Attribute("E6", &(args->currentState.external[5]));
  if( debug )
    printf( "\x1b[32mkukaThread Read Status: <%3.1f, %3.1f, %3.1f> <%3.1f, %3.1f, %3.1f>\x1b[0m\n",
	    args->currentState.cartesian[0],
	    args->currentState.cartesian[1],
	    args->currentState.cartesian[2],
	    args->currentState.cartesian[3],
	    args->currentState.cartesian[4],
	    args->currentState.cartesian[5]);
  return krcIPOC->GetText();
}
