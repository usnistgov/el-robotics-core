/*****************************************************************************
------------------------------------------------------------------------------
--  Copyright 2012-2013
--  Georgia Tech Research Institute
--  505 10th Street
--  Atlanta, Georgia 30332
--
--  This material may be reproduced under the GNU Public license
------------------------------------------------------------------------------
*****************************************************************************/
/*!
 *     \file      USARTruth.hh
 *     \brief     Class for accessing ground truth from USARSim
 *                This class will connect to the USARSim engine and report
 *                location information on specific instances or general classes
 *     \author    Stephen Balakirsky, GTRI
 *     \date      18Dec13
 *     \copyright Georgia Tech Research Institute
 */
#ifndef __USARTruth
#define __USARTruth
#include <stdio.h>
//#include <stdlib.h>
#include <string>
#include "ulapi.hh"
#include "sensorReturn.hh"

#define USARTruth_Delimeter "\n"
#define MAX_TOKEN_LEN 1024

class USARTruth{
private:
  SensorReturn readUSARTruth();
  SensorReturn handle_message(const char *message);
  ulapi_integer port;
  std::string hostName;
  int initialized;
  SensorReturn truthReturn;
  int socketID;
  int debug;

public:
  USARTruth();
  int connect(std::string hostNameIn="localhost", ulapi_integer portIn=3989);
  void setDebug(int debugLevel);
  SensorReturn getTruth( std::string className, std::string instanceName );
  // string parsing utilities
  const char *getKey(const char *msg, char *key);
  const char *getValue(const char *msg, char *value);
  const char *expect(const char *expectString, const char *msg);
  const char *getInteger(const char *msg, int *intValue);
  const char *getDouble(const char *msg, double *dblValue);
  const char *getVector(const char *msg, double *dblArray, int length);
  const char *getBone(const char *msg, double *dblArray);
};
#endif
