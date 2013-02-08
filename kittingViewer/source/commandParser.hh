#ifndef COMMANDPARSER_HH
#define COMMANDPARSER_HH

#include <list>
#include "canonicalMsg.hh"

#define TEXTSIZE 200

class CommandParser
{
 public:
  static int  readCommandFile(FILE * inFile,
			      std::list<CanonicalMsg *> * commands);
  static int  readDoubleArgCommand(const char * commandName, int length,
				   char * line, double * doubleVal);
  static int  readIntArgCommand(const char * commandName, int length,
				char * line, int * intVal);
  static int  readMoveThroughTo(char * lineIn, Pose *** poses,
				int * poseCount, FILE * inFile);
  static int  readNoArgCommand(const char * commandName,  int length,
			       char * line);
  static int  readPose(char * lineIn, Pose * pose, int * chars);
  static int  readPoseArgCommand(const char * commandName,  int length,
				 char * line, Pose ** pose);
  static int  readStringArgCommand(const char * commandName, int length,
				   char * line, char * buffer);
  			   
};
#endif //COMMANDPARSER_HH
