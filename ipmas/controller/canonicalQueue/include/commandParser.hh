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

 DISCLAIMER:
 This software was originally produced by the National Institute of Standards
 and Technology (NIST), an agency of the U.S. government, and by statute is
 not subject to copyright in the United States.  

 Modifications to the code have been made by Georgia Tech Research Institute
 and these modifications are subject to the copyright shown above
 *****************************************************************************/
#ifndef COMMANDPARSER_HH
#define COMMANDPARSER_HH

#include <list>
#include "database/Point.h"
#include "database/Vector.h"
#include "canonicalMsg.hh"
#include "controller.hh"
#define TEXTSIZE 200

class CommandParser
{
public:
  CommandParser(Controller *ctrlIn);
  int  readCommandFile(FILE * inFile);
  int queueCommand(std::string command);
  int readDoubleArgCommand(const char * commandName, int length,
			   char * line, double * doubleVal);
  int readIntArgCommand(const char * commandName, int length,
			char * line, int * intVal);
  int readMoveThroughTo(char * lineIn, PoseLocation *** poseLocations,
			int * poseLocationCount, FILE * inFile);
  int readNoArgCommand(const char * commandName,  int length,
		       char * line);
  int readPoseLocation(char * lineIn, PoseLocation * poseLocation, int * chars);
  int readPoseLocationArgCommand(const char * commandName,  int length,
				 char * line, PoseLocation ** poseLocation);
  int readStringArgCommand(const char * commandName, int length,
			   char * line, char * buffer);
private:
  int poseNumber; // global counter for pose number.
  Controller *ctrl; // ros controllerine
};
#endif //COMMANDPARSER_HH
