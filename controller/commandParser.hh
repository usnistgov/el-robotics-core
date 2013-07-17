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
  static int  readCommandFile(FILE * inFile,
			      Controller *ctrl );
  static int  readDoubleArgCommand(const char * commandName, int length,
				   char * line, double * doubleVal);
  static int  readIntArgCommand(const char * commandName, int length,
				char * line, int * intVal);
  static int  readMoveThroughTo(char * lineIn, PoseLocation *** poseLocations,
				int * poseLocationCount, FILE * inFile);
  static int  readNoArgCommand(const char * commandName,  int length,
			       char * line);
  static int  readPoseLocation(char * lineIn, PoseLocation * poseLocation, int * chars);
  static int  readPoseLocationArgCommand(const char * commandName,  int length,
				 char * line, PoseLocation ** poseLocation);
  static int  readStringArgCommand(const char * commandName, int length,
				   char * line, char * buffer);
  			   
};
#endif //COMMANDPARSER_HH
