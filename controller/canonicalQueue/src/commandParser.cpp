#include <string.h>         // strncmp
#include <ctype.h>          // isalpha
#include "commandParser.hh"

int poseNumber; // global counter for pose number.

/********************************************************************/

/* CommandParser::readCommandFile

Returned Value: 0 on success
                1 on failure

Called By:  CommandParser::init

*/

int CommandParser::readCommandFile( /* ARGUMENTS   */
 FILE * inFile,
 Controller * ctrl )
{
  char lineIn[TEXTSIZE];
  char buffer[TEXTSIZE];
  char * readHere;
  double doubleVal;
  PoseLocation * poseLocation;
  PoseLocation ** poseLocations;
  int intVal;
  std::string text;
  int returnVal = 0;
  int length;

  poseNumber = 0;
  for (; fgets(lineIn, TEXTSIZE, inFile); )
    {
      for (length = 0;
	   ((lineIn[length] == ' ') || (lineIn[length] == '\t'));
	   length++);
      readHere = (lineIn + length);
      if ((*readHere == 10) || (*readHere == 13)) // allow blank lines
	continue;
      for (length = 0; isalpha(readHere[length]); length++);
      if (readNoArgCommand("CloseGripper", length, readHere))
	{
	  ctrl->queueMsgLow(new CloseGripperMsg);
	}
      else if (readNoArgCommand("CloseToolChanger", length, readHere))
	{
	  ctrl->queueMsgLow(new CloseToolChangerMsg);
	}
      else if (readDoubleArgCommand("Dwell", length, readHere, &doubleVal))
	{
	  ctrl->queueMsgLow(new DwellMsg(doubleVal));
	}
      else if (readIntArgCommand("EndCanon", length, readHere, &intVal))
	{
	  ctrl->queueMsgLow(new EndCanonMsg(intVal));
	  return returnVal;
	}
      else if (readNoArgCommand("InitCanon", length, readHere))
	{
	  ctrl->queueMsgLow(new InitCanonMsg);
	}
      else if (readStringArgCommand("Message", length, readHere, buffer))
	{
	  text = buffer;
	  ctrl->queueMsgLow(new MessageMsg(text));
	}
      else if (readPoseLocationArgCommand("MoveStraightTo", length, readHere, 
					  &poseLocation))
	{
	  ctrl->queueMsgLow(new MoveStraightToMsg(poseLocation));
	}
      else if (readMoveThroughTo(lineIn, &poseLocations, &intVal, inFile))
	{
	  ctrl->queueMsgLow(new MoveThroughToMsg(poseLocations, intVal));
	}
      else if (readPoseLocationArgCommand("MoveTo", length, readHere, 
					  &poseLocation))
	{
	  ctrl->queueMsgLow(new MoveToMsg(poseLocation));
	}
      else if (readNoArgCommand("OpenGripper", length, readHere))
	{
	  ctrl->queueMsgLow(new OpenGripperMsg);
	}
      else if (readNoArgCommand("OpenToolChanger", length, readHere))
	{
	  ctrl->queueMsgLow(new OpenToolChangerMsg);
	}
      else if (readDoubleArgCommand("SetAbsoluteAcceleration", length, 
				    readHere, &doubleVal))
	{
	  ctrl->queueMsgLow(new SetAbsoluteAccelerationMsg(doubleVal));
	}
      else if (readDoubleArgCommand("SetAbsoluteSpeed", length,
				    readHere, &doubleVal))
	{
	  ctrl->queueMsgLow(new SetAbsoluteSpeedMsg(doubleVal));
	}
      else if (readStringArgCommand("SetAngleUnits", length, readHere, buffer))
	{
	  if ((strcmp(buffer, "radian")) &&
	      (strcmp(buffer, "degree")))
	    {
	      fprintf(stderr, "angle unit must be radian or degree\n");
	      returnVal = 1;
	    }
	  else
	    {
	      text = buffer;
	      ctrl->queueMsgLow(new SetAngleUnitsMsg(text));
	    }
	}
      else if (readDoubleArgCommand("SetEndAngleTolerance", length, 
			       readHere, &doubleVal))
	{
	  ctrl->queueMsgLow(new SetEndAngleToleranceMsg(doubleVal));
	}
      else if (readDoubleArgCommand("SetEndPointTolerance", length, 
				    readHere, &doubleVal))
	{
	  ctrl->queueMsgLow(new SetEndPointToleranceMsg(doubleVal));
	}
      else if (readDoubleArgCommand("SetIntermediatePointTolerance", length, 
				    readHere, &doubleVal))
	{
	  ctrl->queueMsgLow (new SetIntermediatePointToleranceMsg(doubleVal));
	}
      else if (readStringArgCommand("SetLengthUnits", length, readHere, buffer))
	{
	  if ((strcmp(buffer, "inch")) &&
	      (strcmp(buffer, "mm")) &&
	      (strcmp(buffer, "meter")))
	    {
	      fprintf(stderr, "length unit must be inch, mm, or meter\n");
	      returnVal = 1;
	    }
	  else
	    {
	      text = buffer;
	      ctrl->queueMsgLow(new SetLengthUnitsMsg(text));
	    }	  
	}
      else if (readDoubleArgCommand("SetRelativeAcceleration", length, 
				    readHere, &doubleVal))
	{
	  ctrl->queueMsgLow(new SetRelativeAccelerationMsg(doubleVal));
	}
      else if (readDoubleArgCommand("SetRelativeSpeed", length, 
				    readHere, &doubleVal))
	{
	  ctrl->queueMsgLow(new SetRelativeSpeedMsg(doubleVal));
	}
	  else if (readStringArgCommand("StartObjectScan", length, readHere, 
					buffer))
	{
	  text = buffer;
	  ctrl->queueMsgLow(new StartObjectScanMsg(text));
	}
      else if (readIntArgCommand("StopMotion", length, readHere, &intVal))
	{
	  ctrl->queueMsgLow(new StopMotionMsg(intVal));
	}
	  else if (readNoArgCommand("StopObjectScan", length, readHere))
	{
	  ctrl->queueMsgLow(new StopObjectScanMsg);
	}
      else
	{
	  fprintf(stderr, "unknown command (shown below) "
		  "in CommandParser::readCommandFile\n");
	  fprintf(stderr, "%s", lineIn);
	  returnVal = 1;
	}
    }
  // don't leave if stdin
  if( inFile == stdin )
    readCommandFile(inFile, ctrl);
  printf( "commandParser leaving file read loop\n" );
  return returnVal;
}

/********************************************************************/

/* CommandParser::readDoubleArgCommand

Returned Value: int

Called By: CommandParser::readCommandFile

*/

int CommandParser::readDoubleArgCommand(
 const char * commandName,
 int length,
 char * line,
 double * doubleVal)
{
  char junk[TEXTSIZE];

  junk[0] = 0;
  return ((strncmp(line, commandName, length) == 0) &&
	  (sscanf(line+length, " ( %lf ) %s", doubleVal, junk) == 1) &&
	  (junk[0] == 0));
}

/********************************************************************/

/* CommandParser::readIntArgCommand

Returned Value: int

Called By: CommandParser::readCommandFile

*/

int CommandParser::readIntArgCommand(
 const char * commandName,
 int length,
 char * line,
 int * intVal)
{
  char junk[TEXTSIZE];

  junk[0] = 0;
  return ((strncmp(line, commandName, length) == 0) &&
	  (sscanf(line+length, " ( %d ) %s", intVal, junk) == 1) &&
	  (junk[0] == 0));
}

/********************************************************************/

/* CommandParser::readMoveThroughTo



If the beginning of lineIn is MoveThroughTo followed by a left parenthese
followed by a left curly brace (possible with white space between),
this reads poses starting with one pose already on lineIn, and then
getting more from the inFile if there are more.

Each pose is required to be on a separate line. An example of file text
follows. It has two poses. Extra spaces and tabs may appear before and
after parentheses, curly braces, and commas.

MoveThroughTo({{{7,0,0},{0,0,1},{1,0,0}},
               {{7,8,0},{0,0,1},{1,0,0}}},2)

Since the number of poses is not known at the beginning, the poses are
put on a poseList. At the end, an array of Pose pointers of the
correct size is built, and the pose pointers are copied into the
array.  This also checks that the number at the end of the command
(2 in the example) is the same as the size of the poseList.

*/

int CommandParser::readMoveThroughTo(
 char * lineIn,
 PoseLocation *** poseLocations,
 int * poseLocationCount,
 FILE * inFile)
{
  PoseLocation * poseLocation;
  char * readHere;             // line index
  char aChar;
  std::list<PoseLocation *> poseLocationList;
  int chars;
  int n;
  std::stringstream tempSS;
  
  if ((sscanf(lineIn, " MoveThroughTo ( %c %n", &aChar, &chars) != 1) ||
      (aChar != '{'))
    return 0;
  readHere = (lineIn + chars);
  tempSS.str("");
  tempSS << poseNumber++;
  poseLocation = new PoseLocation(std::string("Pose_") + tempSS.str ());
  if (readPoseLocation(readHere, poseLocation, &chars))
    { // read the first poseLocation
      poseLocationList.push_back(poseLocation);
    }
  readHere += chars;
  while ((sscanf(readHere, " %c ", &aChar) == 1) && (aChar == ','))
    { // read the rest of the poseLocations
      if ((readHere[1] != 10) && (readHere[1] != 13))
	{
	  fprintf(stderr, "a newline must follow the comma after each poseLocation\n");
	  return 0;
	}
      if (!fgets(lineIn, TEXTSIZE, inFile))
	{
	  fprintf(stderr, "premature file end in CommandParser::readPoseLocations\n");
	  return 0;
	}
      tempSS.str("");
      tempSS << poseNumber++;
      poseLocation = new PoseLocation(std::string("Pose_") + tempSS.str ());
      if (readPoseLocation(lineIn, poseLocation, &chars))
	{ // read the next poseLocation
	  poseLocationList.push_back(poseLocation);
	}
      else
	return 0;
      readHere = (lineIn + chars);
    }
  if (sscanf(readHere, "} , %d )", poseLocationCount) != 1)
    {
      fprintf(stderr, "bad end of MoveThroughTo command\n");
      return 0;
    }
  if ((int)(poseLocationList.size()) != *poseLocationCount)
    {
      fprintf(stderr, "bad poseLocation count in MoveThroughTo command\n");
      return 0;
    }
  *poseLocations = new PoseLocation *[*poseLocationCount];
  for (n = 0; n < *poseLocationCount; n++)
    {
      (*poseLocations)[n] = poseLocationList.front();
      poseLocationList.pop_front();
    }
  return 1;
}

/********************************************************************/

/* CommandParser::readNoArgCommand

Returned Value: int

Called By: CommandParser::readCommandFile

*/

int CommandParser::readNoArgCommand(
 const char * commandName,
 int length,
 char * line)
{
  char rightParen;
  char junk[TEXTSIZE];

  junk[0] = 0;
  return ((strncmp(line, commandName, length) == 0) &&
	  (sscanf(line+length, " ( %c %s", &rightParen, junk) == 1) &&
	  (rightParen == ')') && (junk[0] == 0));
}

/********************************************************************/

/* CommandParser::readPoseLocation

Returned Value: int

Called By:
  CommandParser:::readPoseLocationArgCommand
  CommandParser:::readMoveThroughTo

*/

int CommandParser::readPoseLocation(
 char * lineIn,
 PoseLocation * poseLocation,
 int * chars)
{
  int n;   // line counter
  int m;   // scanf character counter
  Point * point;
  Vector *axis;
  std::stringstream tempSS;
  double x, y, z;

  
  tempSS.str("");
  tempSS << poseNumber++;
  point = new Point(std::string("Pose_") + tempSS.str ());

  if (sscanf(lineIn, " { { %lf , %lf , %lf } , %n", &x, &y, &z, &m) != 3 )
    return 0;
  point->sethasPoint_X(x);
  point->sethasPoint_Y(y);
  point->sethasPoint_Z(z);
  poseLocation->sethasPoseLocation_Point(point);
  n = m;

  tempSS.str("");
  tempSS << poseNumber++;
  axis = new Vector(std::string("Pose_") + tempSS.str ());

  if (sscanf(lineIn+n, " { %lf , %lf , %lf } , %n", &x, &y, &z, &m) != 3 )
    return 0;
  axis->sethasVector_I(x);
  axis->sethasVector_J(y);
  axis->sethasVector_K(z);
  poseLocation->sethasPoseLocation_ZAxis( axis );
  n += m;
  tempSS.str("");
  tempSS << poseNumber++;
  axis = new Vector(std::string("Pose_") + tempSS.str ());

  if (sscanf(lineIn+n, " { %lf , %lf , %lf } } %n", &x, &y, &z, &m) != 3 )
    return 0;
  axis->sethasVector_I(x);
  axis->sethasVector_J(y);
  axis->sethasVector_K(z);
  poseLocation->sethasPoseLocation_XAxis( axis );

  *chars = (n + m);
  return 1;
}

/********************************************************************/

int CommandParser::readPoseLocationArgCommand(
 const char * commandName,
 int length,
 char * line,
 PoseLocation ** poseLocation)
{
  char leftParen;
  char rightParen;
  int chars;
  char junk[TEXTSIZE];
  std::stringstream tempSS;

  if (strncmp(line, commandName, length) ||
      (sscanf(line+length, " %c %n", &leftParen, &chars) != 1) ||
      (leftParen != '('))
    return 0;
  tempSS.str("");
  tempSS << poseNumber++;
  *poseLocation = new PoseLocation(std::string("Pose_") + tempSS.str ());
  length += chars;
  if (!readPoseLocation(line+length, *poseLocation, &chars))
    return 0;
  junk[0] = 0;
  if ((sscanf(line+length+chars, " %c %s", &rightParen, junk) != 1) ||
      (rightParen != ')') || (junk[0] != 0))
    return 0;
  return 1;
}

/********************************************************************/

/* CommandParser::readStringArgCommand

Returned Value: int

Called By: 

If the commandName is the expected command name, this checks the rest
of "line" for a string of characters of the following form
  ("XXXX")
where the XXXX may be any string of characters not including a double quote.
There may be extra spaces and/or tabs before and after the parentheses.
The sscanf function reads whatever the XXXX is into the buffer.

If the command name is not as expected, or if the string in
parentheses is not in correct form, or there is junk (more characters)
after the right parenthesis, this returns 0. Otherwise, everything is
OK and this returns 1.

*/

int CommandParser::readStringArgCommand(
 const char * commandName,
 int length,
 char * line,
 char * buffer)
{
  char junk[TEXTSIZE];

  junk[0] = 0;
  return ((strncmp(line, commandName, length) == 0) &&
	  (sscanf(line+length, " ( \"%[^\"]\" ) %s",
		  buffer, junk) == 1) && (junk[0] == 0));
}

/********************************************************************/
