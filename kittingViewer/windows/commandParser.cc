#define _CRT_SECURE_NO_DEPRECATE
#include <string.h>         // strncmp
#include <ctype.h>          // isalpha
#include "commandParser.hh"

/********************************************************************/

/* CommandParser::readCommandFile

Returned Value: int (the number of lines on which a parse error occurs)
  

Called By:
  This function is not called in this file. It is intended to be called
  by applications that need to read robot canonical command files.

This function reads commands from the inFile and puts them on the
"commands" list in order. Except for a MoveThroughTo command, each
command is expected to be on a single line of the file. Hence, this
reads and processes single lines of the file. The readMoveThroughTo
function may read additional lines of the file.

If the line being read does not contain a parsable command, this
prints an error message and puts an UnreadableMsg onto the commands
list.

*/

int CommandParser::readCommandFile(    /* ARGUMENTS                 */
 FILE * inFile,                        /* file to read from         */
 std::list<CanonicalMsg *> * commands) /* list of commands to build */
{
  char lineIn[TEXTSIZE]; // a line of the command file
  char buffer[TEXTSIZE]; // place to put command arguments that are strings
  char * readHere;       // pointer to first non-white character of the lineIn
  double doubleVal;
  Pose * pose;
  Pose ** poses;
  int intVal;
  std::string text;      // std::string to hold text from buffer
  int parseErrors = 0;
  int length;

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
	  commands->push_back(new CloseGripperMsg);
	}
      else if (readNoArgCommand("CloseToolChanger", length, readHere))
	{
	  commands->push_back(new CloseToolChangerMsg);
	}
      else if (readDoubleArgCommand("Dwell", length, readHere, &doubleVal))
	{
	  commands->push_back(new DwellMsg(doubleVal));
	}
      else if (readIntArgCommand("EndCanon", length, readHere, &intVal))
	{
	  commands->push_back(new EndCanonMsg(intVal));
	}
      else if (readNoArgCommand("InitCanon", length, readHere))
	{
	  commands->push_back(new InitCanonMsg);
	}
      else if (readStringArgCommand("Message", length, readHere, buffer))
	{
	  text = buffer;
	  commands->push_back(new MessageMsg(text));
	}
      else if (readPoseArgCommand("MoveStraightTo", length, readHere, &pose))
	{
	  commands->push_back(new MoveStraightToMsg(pose));
	}
      else if (readMoveThroughTo(lineIn, &poses, &intVal, inFile))
	{
	  commands->push_back(new MoveThroughToMsg(poses, intVal));
	}
      else if (readPoseArgCommand("MoveTo", length, readHere, &pose))
	{
	  commands->push_back(new MoveToMsg(pose));
	}
      else if (readNoArgCommand("OpenGripper", length, readHere))
	{
	  commands->push_back(new OpenGripperMsg);
	}
      else if (readNoArgCommand("OpenToolChanger", length, readHere))
	{
	  commands->push_back(new OpenToolChangerMsg);
	}
      else if (readDoubleArgCommand("SetAbsoluteAcceleration", length, 
				    readHere, &doubleVal))
	{
	  commands->push_back(new SetAbsoluteAccelerationMsg(doubleVal));
	}
      else if (readDoubleArgCommand("SetAbsoluteSpeed", length,
				    readHere, &doubleVal))
	{
	  commands->push_back(new SetAbsoluteSpeedMsg(doubleVal));
	}
      else if (readStringArgCommand("SetAngleUnits", length, readHere, buffer))
	{
	  if ((strcmp(buffer, "radian")) &&
	      (strcmp(buffer, "degree")))
	    {
	      fprintf(stderr, "angle unit must be radian or degree\n");
	      text = buffer;
	      commands->push_back(new UnreadableMsg(text));
	      parseErrors++;
	    }
	  else
	    {
	      text = buffer;
	      commands->push_back(new SetAngleUnitsMsg(text));
	    }
	}
      else if (readDoubleArgCommand("SetEndAngleTolerance", length, 
			       readHere, &doubleVal))
	{
	  commands->push_back(new SetEndAngleToleranceMsg(doubleVal));
	}
      else if (readDoubleArgCommand("SetEndPointTolerance", length, 
				    readHere, &doubleVal))
	{
	  commands->push_back(new SetEndPointToleranceMsg(doubleVal));
	}
      else if (readDoubleArgCommand("SetIntermediatePointTolerance", length, 
				    readHere, &doubleVal))
	{
	  commands->push_back (new SetIntermediatePointToleranceMsg(doubleVal));
	}
      else if (readStringArgCommand("SetLengthUnits", length, readHere, buffer))
	{
	  if ((strcmp(buffer, "inch")) &&
	      (strcmp(buffer, "millimeter")) &&
	      (strcmp(buffer, "meter")))
	    {
	      fprintf(stderr,
		      "length unit must be inch, millimeter, or meter\n");
	      text = buffer;
	      commands->push_back(new UnreadableMsg(text));
	      parseErrors++;
	    }
	  else
	    {
	      text = buffer;
	      commands->push_back(new SetLengthUnitsMsg(text));
	    }	  
	}
      else if (readDoubleArgCommand("SetRelativeAcceleration", length, 
				    readHere, &doubleVal))
	{
	  commands->push_back(new SetRelativeAccelerationMsg(doubleVal));
	}
      else if (readDoubleArgCommand("SetRelativeSpeed", length, 
				    readHere, &doubleVal))
	{
	  commands->push_back(new SetRelativeSpeedMsg(doubleVal));
	}
      else
	{
	  fprintf(stderr, "unreadable command (shown below) "
		  "in CommandParser::readCommandFile\n");
	  fprintf(stderr, "%s", lineIn);
	  text = lineIn;
	  commands->push_back(new UnreadableMsg(text));
	  parseErrors++;
	}
    }
  return parseErrors;
}

/********************************************************************/

/* CommandParser::readDoubleArgCommand

Returned Value: int

Called By: CommandParser::readCommandFile

This tries to read a command that takes a single argument that is a double.
It checks whether the beginning of the line contains the given command
name. If so, it tries to read the double that should follow, and then
it reads anything else that follows (which should be nothing). If
it finds the command it is looking for, and it reads the double, and
there is no junk on the line after the double, this return 1. Otherwise
it returns zero.

*/

int CommandParser::readDoubleArgCommand( /* ARGUMENTS                    */
 const char * commandName,               /* name of command  to look for */
 int length,                             /* length of name of command    */
 char * line,                            /* line of text to read from    */
 double * doubleVal)                     /* double to set                */
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

This tries to read a command that takes a single argument that is an integer.
It checks whether the beginning of the line contains the given command
name. If so, it tries to read the integer that should follow, and then
it reads anything else that follows (which should be nothing). If
it finds the command it is looking for, and it reads the integer, and
there is no junk on the line after the integer, this return 1. Otherwise
it returns zero.

*/

int CommandParser::readIntArgCommand( /* ARGUMENTS                   */
 const char * commandName,            /* name of command to look for */
 int length,                          /* length of name of command   */
 char * line,                         /* line of text to read from   */
 int * intVal)                        /* integer to set              */
{
  char junk[TEXTSIZE];

  junk[0] = 0;
  return ((strncmp(line, commandName, length) == 0) &&
	  (sscanf(line+length, " ( %d ) %s", intVal, junk) == 1) &&
	  (junk[0] == 0));
}

/********************************************************************/

/* CommandParser::readMoveThroughTo

Returned Value: int

Called By: CommandParser::readCommandFile

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

int CommandParser::readMoveThroughTo( /* ARGUMENTS                  */
 char * lineIn,                       /* line of text to read from  */
 Pose *** poses,                      /* array of poses to be built */
 int * poseCount,                     /* number of poses to be set  */
 FILE * inFile)                       /* file to read from          */
{
  Pose * pose;
  char * readHere;             // line index
  char aChar;
  std::list<Pose *> poseList;
  int chars;
  int n;
  
  if ((sscanf(lineIn, " MoveThroughTo ( %c %n", &aChar, &chars) != 1) ||
      (aChar != '{'))
    return 0;
  readHere = (lineIn + chars);
  pose = new Pose;
  if (readPose(readHere, pose, &chars))
    { // read the first pose
      poseList.push_back(pose);
    }
  readHere += chars;
  while ((sscanf(readHere, " %c ", &aChar) == 1) && (aChar == ','))
    { // read the rest of the poses
      if ((readHere[1] != 10) && (readHere[1] != 13))
	{
	  fprintf(stderr, "a newline must follow the comma after each pose\n");
	  return 0;
	}
      if (!fgets(lineIn, TEXTSIZE, inFile))
	{
	  fprintf(stderr, "premature file end in CommandParser::readPoses\n");
	  return 0;
	}
      pose = new Pose;
      if (readPose(lineIn, pose, &chars))
	{ // read the next pose
	  poseList.push_back(pose);
	}
      else
	return 0;
      readHere = (lineIn + chars);
    }
  if (sscanf(readHere, "} , %d )", poseCount) != 1)
    {
      fprintf(stderr, "bad end of MoveThroughTo command\n");
      return 0;
    }
  if ((int)(poseList.size()) != *poseCount)
    {
      fprintf(stderr, "bad pose count in MoveThroughTo command\n");
      return 0;
    }
  *poses = new Pose *[*poseCount];
  for (n = 0; n < *poseCount; n++)
    {
      (*poses)[n] = poseList.front();
      poseList.pop_front();
    }
  return 1;
}

/********************************************************************/

/* CommandParser::readNoArgCommand

Returned Value: int

Called By: CommandParser::readCommandFile

This tries to read a command that takes no arguments. It checks
whether the beginning of the line contains the given command name. If
so, it tries to read the empty set of parentheses that should follow,
and then it reads anything else that follows (which should be
nothing). If it finds the command it is looking for, and it reads the
empty parentheses, and there is no junk on the line after the
parentheses, this return 1. Otherwise it returns zero.

*/

int CommandParser::readNoArgCommand( /* ARGUMENTS                   */
 const char * commandName,           /* name of command to look for */
 int length,                         /* length of name of command   */
 char * line)                        /* line of text to read from   */
{
  char rightParen;
  char junk[TEXTSIZE];

  junk[0] = 0;
  return ((strncmp(line, commandName, length) == 0) &&
	  (sscanf(line+length, " ( %c %s", &rightParen, junk) == 1) &&
	  (rightParen == ')') && (junk[0] == 0));
}

/********************************************************************/

/* CommandParser::readPose

Returned Value: int

Called By:
  CommandParser:::readPoseArgCommand
  CommandParser:::readMoveThroughTo

This tries to read one Pose into the pose argument. If it succeeds, it
returns 1. Otherwise, it returns 0. It also puts the number of characters
read into the chars argument.

*/

int CommandParser::readPose( /* ARGUMENTS                           */
 char * lineIn,              /* line of text to read from           */
 Pose * pose,                /* pose to populate                    */
 int * chars)                /* number of characters read, set here */
{
  int n;   // line counter
  int m;   // scanf character counter

  if (sscanf(lineIn, " { { %lf , %lf , %lf } , %n", &(pose->origin.x),
	     &(pose->origin.y), &(pose->origin.z), &m) != 3)
    return 0;
  n = m;
  if (sscanf(lineIn+n, " { %lf , %lf , %lf } , %n", &(pose->zAxis.i),
	     &(pose->zAxis.j), &(pose->zAxis.k), &m) != 3)
    return 0;
  n += m;
  if (sscanf(lineIn+n, " { %lf , %lf , %lf } } %n", &(pose->xAxis.i),
	     &(pose->xAxis.j), &(pose->xAxis.k), &m) != 3)
    return 0;
  *chars = (n + m);
  return 1;
}

/********************************************************************/

/* CommandParser::readPoseArgCommand

Returned Value: int

Called By: CommandParser::readCommandFile

This tries to read a command that takes a single argument that is a pose.
It checks whether the beginning of the line contains the given command
name. If so, it tries to read the pose that should follow, and then
it reads anything else that follows (which should be nothing). If
it finds the command it is looking for, and it reads the pose, and
there is no junk on the line after the pose, this return 1. Otherwise
it returns zero.

*/

int CommandParser::readPoseArgCommand( /* ARGUMENTS                   */
 const char * commandName,             /* name of command to look for */
 int length,                           /* length of name of command   */
 char * line,                          /* line of text to read from   */
 Pose ** pose)                         /* pose to build               */
{
  char leftParen;
  char rightParen;
  int chars;
  char junk[TEXTSIZE];

  if (strncmp(line, commandName, length) ||
      (sscanf(line+length, " %c %n", &leftParen, &chars) != 1) ||
      (leftParen != '('))
    return 0;
  *pose = new Pose;
  length += chars;
  if (!readPose(line+length, *pose, &chars))
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

int CommandParser::readStringArgCommand( /* ARGUMENTS                   */
 const char * commandName,               /* name of command to look for */
 int length,                             /* length of name of command   */
 char * line,                            /* line of text to read from   */
 char * buffer)                          /* buffer to put string in     */
{
  char junk[TEXTSIZE];

  junk[0] = 0;
  return ((strncmp(line, commandName, length) == 0) &&
	  (sscanf(line+length, " ( \"%[^\"]\" ) %s",
		  buffer, junk) == 1) && (junk[0] == 0));
}

/********************************************************************/
