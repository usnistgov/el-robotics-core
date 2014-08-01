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
#ifndef __kukaThread
#define __kukaThread

#include <ulapi.h>
#include "CRCL/timer.hh"
#include "CRCL/kukaThreadArgs.hh"
#include <tinyxml.h>
#include "CRCL/crclDefs.hh"
class KukaThread
{
public:
  KukaThread(const char *toKukaXML = DEFAULT_TO_KUKA, 
	     const char *fromKukaXML = DEFAULT_TO_KUKA,
	     double cycleTimeIn = KUKA_DEFAULT_CYCLE);
  void setDebug(int debugLevel);
  void threadStart(KukaThreadArgs *argsIn);
private:
  KukaThreadArgs *args;
  int debug;
  TiXmlDocument toKuka;
  TiXmlDocument fromKuka;
  RCS_TIMER *kukaThreadBlock;
  std::string setStatus(char *buf);
  std::string setCorrections(std::string krcIOPC);
  void zeroCorrections();
};
#endif
