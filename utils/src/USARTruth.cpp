/*****************************************************************************
------------------------------------------------------------------------------
--  Copyright 2012-2013
--  Georgia Tech Research Institute
--  505 10th Street
--  Atlanta, Georgia 30332
--
--  This material may be reproduced under the GNU Public license
------------------------------------------------------------------------------

 DISCLAIMER:
 This software was originally produced by the National Institute of Standards
 and Technology (NIST), an agency of the U.S. government, and by statute is
 not subject to copyright in the United States.  

 Modifications to the code have been made by Georgia Tech Research Institute
 and these modifications are subject to the copyright shown above
*****************************************************************************/

#include "USARTruth.hh"

USARTruth::USARTruth()
{
  debug = 0;
  initialized = 1;
  if (ulapi_init(UL_USE_DEFAULT)) 
    {
      fprintf(stderr, "USARTruth: ulapi_init error\n");
      initialized = 0;
      return;
    }
}

int USARTruth::connect(std::string hostNameIn, ulapi_integer portIn)
{
  hostName = hostNameIn;
  port = portIn;
  socketID = ulapi_socket_get_client_id(port, hostName.c_str());
  if (socketID == -1) 
    {
      initialized = 0;
      fprintf(stderr,
	      "USARTruthn: unable to open socket: %d host: %s port: %d\n",
	      socketID, hostName.c_str(), port);
      return -1;
    }
  if (debug)
    fprintf(stderr, "USARTruth: hostname: %s socketID: %d\n",
	    hostName.c_str(), socketID);
  return 1;
}

void USARTruth::setDebug(int debugLevel)
{
  debug = debugLevel;
}

SensorReturn USARTruth::handle_message(const char *message)
{
  const char *nextptr;
  char token[MAX_TOKEN_LEN];
  const char *ptr = message;
  double dbl[6];
  SensorReturn newTruth;
    
  if (!strncmp(ptr, "{End}", strlen("{End}"))) 
    {
      newTruth.valid = 0;
      return newTruth;
    }
  newTruth.valid = 1;
  while (1) 
    {
      nextptr = getKey(ptr, token);
      if (nextptr == ptr)
	break;
      ptr = nextptr;
      if (!strcmp(token, "Name")) 
	{
	  nextptr = getValue(ptr, token);
	  if (nextptr == ptr)
	    break;
	  ptr = nextptr;
	  newTruth.name = token;
	}

      else if (!strcmp(token, "Class")) 
	{
	  nextptr = getValue(ptr, token);
	  if (nextptr == ptr)
	    break;
	  ptr = nextptr;
	  newTruth.objectClass = token;
	}

      else if (!strcmp(token, "Time")) 
	{
	  nextptr = getDouble(ptr, &dbl[0]);
	  if (nextptr == ptr)
	    break;
	  ptr = nextptr;
	  newTruth.time = dbl[0];
	}

      else if (!strcmp(token, "Location")) 
	{
	  nextptr = getVector(ptr, dbl, 3);
	  if (nextptr == ptr)
	    break;
	  ptr = nextptr;
	  newTruth.pose.setPoint(dbl[0], -dbl[1], -dbl[2]); // swap axis (rotation about x)
	}

      else if (!strcmp(token, "Rotation")) 
	{
	  nextptr = getVector(ptr, dbl, 3);
	  if (nextptr == ptr)
	    break;
	  ptr = nextptr;
	  newTruth.pose.setRollPitchYaw(dbl[0], dbl[1], dbl[2]);
	}

      else if (!strcmp(token, "Bone")) 
	{

	  // only interested in 'Main'
	  nextptr = expect("Main", ptr);
	  if (nextptr != ptr)	// found it
	    {
	      ptr = nextptr;
	      nextptr = getBone(ptr, dbl);
	      if (nextptr == ptr)
		break;
	      newTruth.bone[0] = dbl[0];
	      newTruth.bone[1] = dbl[1];
	      newTruth.bone[2] = dbl[2];
	      newTruth.bone[3] = dbl[3];
	      newTruth.bone[4] = dbl[4];
	      newTruth.bone[5] = dbl[5];
	      break;		// this is the last thing that I want...
	    }
	}

      else 
	{
	  printf("unknown token from USARTruth: %s\n", token);
	  newTruth.valid = 0;
	  break;
	}
    }
}

SensorReturn USARTruth::getTruth(std::string className, std::string instanceName)
{
  int numBytes;
  std::string stringOut = "{class " + className + "} {name " +
    instanceName + "}\r\n";
  if (!initialized)
    {
      SensorReturn sensorReturn;
      if (debug )
	fprintf(stderr, "USARTruth::getTruth: not initialized\n");
      sensorReturn.valid = 0;
      return sensorReturn;
    }
  numBytes =
    ulapi_socket_write(socketID, stringOut.c_str(),
		       stringOut.length());
  if (debug)
    fprintf(stderr, "sent string %s of length %lu with return %d\n",
	    stringOut.c_str(), stringOut.length(), numBytes);
  return readUSARTruth();
}

SensorReturn USARTruth::readUSARTruth()
{
  std::string truthString;
  char buffer[256];
  int nchars;
  std::size_t found;
  SensorReturn truthValue;

  if (!initialized) 
    {
      fprintf(stderr,
	      "USARTruth: unable to read socket, not initialized\n");
      truthValue.valid = 0;
      return truthValue;
    }
  for (;;) 
    {
      nchars = ulapi_socket_read(socketID, buffer, sizeof(buffer) - 1);
      if (-1 == nchars) 
	{
	  fprintf(stderr, "USARTruth: connection closed\n");
	  initialized = 0;
	  truthValue.valid = 0;
	  return truthValue;
	}

      else if (0 == nchars) 
	{
	  fprintf(stderr, "USARTruth: end of file\n");
	  initialized = 0;
	  truthValue.valid = 0;
	  return truthValue;
	}

      else 
	{
	  found = truthString.length();
	  truthString = truthString + buffer;
	  found = truthString.find_first_of(USARTruth_Delimeter);
	  if (found != std::string::npos) 
	    {
	      if (debug)
		printf("USARTruth: going to handle message with string: %s\n",
		       truthString.c_str());
	      return handle_message(truthString.c_str());
	    }
	}
    }
  truthValue.valid = 0;
  return truthValue;
}
