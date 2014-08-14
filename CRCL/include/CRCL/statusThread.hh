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
#ifndef __statusThread
#define __statusThread

#include <ulapi.h>
#include "CRCL/timer.hh"
#include "CRCL/kukaThreadArgs.hh"
#include "CRCL/crclDefs.hh"
#include "CRCL/crclStatus.hh"
class StatusThread
{
public:
  StatusThread(int isServer, double cycleTimeIn = KUKA_DEFAULT_CYCLE);
  void setDebug(int debugLevel);
  void threadStart(CRCLStatus *argsIn);
private:
  void connectClient();
  int isServer;
  CRCLStatus *args;
  int debug;
  RCS_TIMER *statusThreadBlock;
  int statusServer;
  int statusConnection;
};
#endif
