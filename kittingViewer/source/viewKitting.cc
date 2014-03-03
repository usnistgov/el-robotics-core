/*
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*/

/*!
  \file viewKitting.cc

  \brief Graphics functions for kittingViewer. Uses OpenGL.
  \code CVS Status:
  $Author: tomrkramer $
  $Revision: 1.2 $
  $Date: 2011/06/09 20:49:22 $
  \endcode

  \author Stephen Balakirsky
  \date March 23, 2010
*/

/*

This includes the glInit function and the functions that are called
by callbacks in the glMainLoop.

All motions of the display are performed using the mouse.

No time delays are used because they are not needed. Unless the user is
interacting with the display using the keyboard or mouse, this just sits
there and uses no processing time.

*/

#include <stdlib.h>         // exit
#include <stdio.h>          // printf, etc.
#include "kittingViewer.hh" // KittingViewer::redraw
#include "view.hh"          // glInit
#include "mouse.hh"

#define IMAGE_SIZE 4000000
#define FILENAME_SIZE 32
#define max(x,y) (((y) > (x)) ? (y) : (x))

static void animate(void);
static void buildDisplayList(void);
static void displayCommandWindow(void);
static void displayMetricsWindow(void);
static void displayPictureWindow(void);
void glInit(int argc, char* argv[], const char * winName);
static void keyboard(unsigned char key, int x, int y);
static void makeGrid(void);
static void motion(int x, int y);
static void mouse(int button, int state, int x, int y);
static void reshapeCommandWindow(int width, int height);
static void reshapeMetricsWindow(int width, int height);
static void reshapePictureWindow(int width, int height);
static int textDump(void);
static int windowDump(void);

/********************************************************************/

static int dump = 0;            // whether to dump image
static int dumpIndex = 0;       // number of dump
static int commandHeight = 100; // height of command window
static int commandWidth = 908;  // width of command window
static int commandWindow = 0;   // id of command window
static int metricsHeight = 600; // height of metrics window
static int metricsWidth = 300;  // width of metrics window
static int metricsWindow = 0;   // id of metrics window
static int pictureExtent = 600; // width and height of picture window
static int pictureWindow = 0;   // id of picture window
static int text = 0;            // whether to write text file
static GLuint drawList = 0;     // display list for grid and all objects

int rotate = 0;         // whether mouse button 1 rotates, used by mouse.cc

/********************************************************************/

/* animate

Returned Value: none

Called By: glInit (as glutIdleFunction for the pictureWindow)

1. If "dump" is non-zero, dump the three windows and set "dump" to 0.

2. If "text" is non-zero, print metrics and settings, and set "text" to 0.

3. If it is not time for the last move command to be fully executed or
if not all poses have been reached, redraw the picture window.

*/

static void animate()
{
  if (dump && text)
    {
      windowDump();
      textDump();
      dump = 0;
      text = 0;
      dumpIndex++;
    }
  else if (dump)
    {
      windowDump();
      dump = 0;
      dumpIndex++;
    }
  else if (text)
    {
      textDump();
      text = 0;
      dumpIndex++;
    }
  if ((KittingViewer::getPseudoElapsedTime() <
       KittingViewer::times[KittingViewer::posesTotal - 1]) ||
      (KittingViewer::poseIndex < KittingViewer::posesTotal))
    {
      buildDisplayList();
      glutPostRedisplay();
    }
}

/********************************************************************/

/* buildDisplayList

Returned Value: none

Called By:
  animate
  glInit
  keyboard

This makes the display list named drawList that includes the background
grid and the contents of the kitting workstation.

*/

static void buildDisplayList(void) /* NO ARGUMENTS */
{
  // destroy any previous lists
  if (drawList)
    glDeleteLists(drawList, 1);
  // generate a display list
  drawList = glGenLists(1);
  glNewList(drawList, GL_COMPILE);
  makeGrid();
  KittingViewer::redraw();
  glEndList();
}
  
/***********************************************************************/

/* displayCommandWindow

Returned Value: none

Called By: glInit (as glutDisplayFunc for commandWindow)

This draws the commandWindow.

*/

static void displayCommandWindow(void) /* NO ARGUMENTS */
{
  int n;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0f, 1.0f, 1.0f);
  for (n = 1; ((n < MAXPOSES) && (KittingViewer::commandString[n][0])); n++)
    {
      KittingViewer::drawString(10.0f, (float)(commandHeight - (20 + (n * 15))),
				GLUT_BITMAP_HELVETICA_10,
				KittingViewer::commandString[n]);
      glutPostRedisplay();
    }
  if (KittingViewer::commandString[0][0])
    KittingViewer::drawString(10.0f, (float)(commandHeight - (20 + (n * 15))),
			      GLUT_BITMAP_HELVETICA_10,
			      KittingViewer::commandString[0]);
  glutSwapBuffers();
}

/***********************************************************************/

/* displayMetricsWindow

Returned Value: none

Called By: glInit (as glutDisplayFunc for metricsWindow)

This draws the metricsWindow.

*/

static void displayMetricsWindow(void) /* NO ARGUMENTS */
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  KittingViewer::drawMetricsAndSettings(metricsHeight);
  glutSwapBuffers();
}

/***********************************************************************/

/* displayPictureWindow

Returned Value: none

Called By: glInit (as glutDisplayFunc for pictureWindow)

This is also posting a redisplay for the metricsWindow if the
distanceTotal changes.

*/

static void displayPictureWindow(void) /* NO ARGUMENTS */
{
  static double distance = 0;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
  msMove(0);
  glColor3f(1.0, 1.0, 1.0);
  glCallList(drawList);
  glPopMatrix();
  glutSwapBuffers();
  if (distance != KittingViewer::distanceTotal)
    {
      glutSetWindow(metricsWindow);
      glutPostRedisplay();
      glutSetWindow(pictureWindow);
      distance = KittingViewer::distanceTotal;
    }
}

/***********************************************************************/

/* glInit

Returned Value: none

Called By: main (in main.cc)

This:
1. initializes openGL.

2. initializes the metrics window and registers the callback functions
   for it.

3. initializes the kitting command and messages window and registers
   the callback functions for it.

4. initializes the picture window and registers the callback functions
   for it.

5. initializes mouse parameters.

6. builds the original display list.

The graphics window is created last so that it is the active window
when the kittingViewer starts.

*/

void glInit(           /* ARGUMENTS                              */
 int argc,             /* number of arguments to the executable  */
 char* argv[],         /* array of executable name and arguments */
 const char * winName) /* name for graphics window               */
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(metricsWidth, metricsHeight);
  metricsWindow = glutCreateWindow("Metrics & Settings");
  glutReshapeFunc(reshapeMetricsWindow);
  glutDisplayFunc(displayMetricsWindow);

  glutInitWindowPosition(0, (pictureExtent + 64));
  glutInitWindowSize(commandWidth, commandHeight);
  commandWindow = glutCreateWindow("Kitting Command & Messages");
  glutReshapeFunc(reshapeCommandWindow);
  glutDisplayFunc(displayCommandWindow);

  glutInitWindowPosition((metricsWidth + 8), 0);
  glutInitWindowSize(pictureExtent, pictureExtent);
  pictureWindow = glutCreateWindow(winName);
  glShadeModel(GL_SMOOTH);
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_COLOR_MATERIAL);
  glDisable(GL_LIGHTING);
  glutDisplayFunc(displayPictureWindow);
  glutReshapeFunc(reshapePictureWindow);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutIdleFunc(animate);

  msInit();
  buildDisplayList();
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

/********************************************************************/

/* keyboard

Returned Value: none

Called By: glInit (as glutKeyboardFunc)

If Esc (escape) is pressed, this exits.

If a (again) is pressed, this starts the simulation over from the
     beginning

If d (dump) is pressed, the dump variable is set to 1, indicating that
     the current image should be dumped to a ppm file.

If D (dump) is pressed, the dump variable is set to 1, indicating that
     the current image should be dumped to a ppm file and the text
     variable is set to 1, indicating that the current metrics,
     settings, and command should be written to a text file.

If e (execute) is pressed, and the kittingViewer's resetFlag is false,
     this sets the kittingViewer's executeFlag to true. This will
     cause the kittingViewer to execute the next command if there is
     one; otherwise, if not all movable objects have been checked, this
     will cause the position of the next movable object to be checked.

If f (faster) is pressed, the kittingViewer's timeFactor is multiplied
     by the square root of 2, causing the animation to run faster.

If r (rotate) is pressed, using mouse button 1 to rotate instead of
     translate is toggled.

If s (slower) is pressed, the kittingViewer's timeFactor is divided
     by the square root of 2, causing the animation to run slower.

If t (text) is pressed, the text variable is set to 1, indicating that
     the current metrics, settings, and command should be written to a
     text file.

If T (text) is pressed, the dump variable is set to 1, indicating that
     the current image should be dumped to a ppm file and the text
     variable is set to 1, indicating that the current metrics,
     settings, and command should be written to a text file.

If v (view) is pressed, the view is returned to its original position.

*/

static void keyboard(
 unsigned char key,
 int x,
 int y)
{
  switch (key)
    {
    case 27:  // Esc
      exit(0);
      break;
    case 'a':
      KittingViewer::runAgain();
      break;
    case 'd':
      dump = 1;
      break;
    case 'D':
      dump = 1;
      text = 1;
      break;
    case 'e':
      glutSetWindow(commandWindow);
      glutPostRedisplay();
      glutSetWindow(metricsWindow);
      glutPostRedisplay();
      glutSetWindow(pictureWindow);
      if (!KittingViewer::resetFlag)
	KittingViewer::setExecuteFlag(true);
      buildDisplayList();
      glutPostRedisplay();
      break;
    case 'f':
      KittingViewer::timeFactor *= 1.414213562;
      glutSetWindow(metricsWindow);
      glutPostRedisplay();
      glutSetWindow(pictureWindow);
      break;
    case 'r' :
      rotate = ((rotate == 0) ? 1 : 0);
      break;
    case 's':
      KittingViewer::timeFactor /= 1.414213562;
      glutSetWindow(metricsWindow);
      glutPostRedisplay();
      glutSetWindow(pictureWindow);
      break;
    case 't':
      text = 1;
      break;
    case 'T':
      dump = 1;
      text = 1;
      break;
    case 'v':
      msInit();
      break;
    }
  glutPostRedisplay();
}

/********************************************************************/

/* makeGrid

Returned Value: none

Called By: buildDisplayList

This makes a square grid of light grey lines just below the XY plane
(so that the grid does not show through polygons on the XY plane).
The grid is 1 by 1 in view space. There are 21 lines in X and
Y directions, separated by 0.05.

*/

static void makeGrid(void) /* NO ARGUMENTS */
{
  static GLfloat t;
  static GLfloat k = (GLfloat)0.5;
  static GLfloat c = (GLfloat)0.05;

  glColor3f((GLfloat)0.4, (GLfloat)0.4, (GLfloat)0.4);
  glBegin(GL_LINES);
  for (t = -k; t <= (k + 0.01); t += c)
    {
      glVertex3f(t, k, (GLfloat)-0.0005);
      glVertex3f(t, -k, (GLfloat)-0.0005);
      glVertex3f(k, t, (GLfloat)-0.0005);
      glVertex3f(-k, t, (GLfloat)-0.0005);
    }
  glEnd();
}

/********************************************************************/

/* motion

Returned Value: none

Called By: glInit (as glutMotionFunc)

This changes the display when a mouse button is held down and the
mouse is moved over the display.

If the left button is held down:
a. If the "rotate" variable is non-zero, the left button does what
the middle button does (see next paragraph)
b. If the "rotate" variable is zero and the mouse is moved, the grid and
box stacks move with the cursor.

If the middle button is held down and the mouse is moved, the grid and
box stacks rotate around an axis perpendicular to the direction of cursor
motion.

If the right button is held down and the mouse is moved, the grid and
box stacks zoom away when the cursor moves up. They zoom in when the cursor
moves down. Sideways motion of the cursor does nothing. This is zooming,
not moving the point of view, so the eye never goes through boxes.

*/

static void motion( /* ARGUMENTS                                  */
 int x,             /* X location of cursor in screen coordinates */
 int y)             /* Y location of cursor in screen coordinates */
{
  msMotion(x, y, 0);
  glutPostRedisplay();
}

/***********************************************************************/

/* mouse

Returned Value: none

Called By: glInit (as glutMouseFunc)

See documentation of the motion function.

*/

static void mouse(  /* ARGUMENTS                                  */
 int button,        /* the mouse button that went up or down      */
 int state,         /* up or down                                 */
 int x,             /* X location of cursor in screen coordinates */
 int y)             /* Y location of cursor in screen coordinates */
{
  msMouse(button, state, x, y);
  glutPostRedisplay();
}

/***********************************************************************/

/* reshapeCommandWindow

Returned Value: none

Called By: glInit (as glutReshapeFunc for the commandWindow)

This reshapes the commandWindow.

*/

static void reshapeCommandWindow( /* ARGUMENTS                */
 int width,                       /* window width, in pixels  */
 int height)                      /* window height, in pixels */
{
  glViewport(0, 0, (GLsizei)width, (GLsizei)height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble)width, 0.0, (GLdouble)height);
  commandHeight = height;
  commandWidth = width;
}

/***********************************************************************/

/* reshapeMetricsWindow

Returned Value: none

Called By: glInit (as glutReshapeFunc for the metricsWindow)

This reshapes the metricsWindow.

*/

static void reshapeMetricsWindow( /* ARGUMENTS                */
 int width,                       /* window width, in pixels  */
 int height)                      /* window height, in pixels */
{
  glViewport(0, 0, (GLsizei)width, (GLsizei)height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (GLdouble)width, 0.0, (GLdouble)height);
  metricsHeight = height;
  metricsWidth = width;
}

/***********************************************************************/

/* reshapePictureWindow

Returned Value: none

Called By: glInit (as glutReshapeFunc for pictureWindow)

This reshapes the picture window. The aspect ratio of the window may
change, but the aspect ratio of the picture in the window will stay
the same.

*/

static void reshapePictureWindow( /* ARGUMENTS                */
 int width,                       /* window width, in pixels  */
 int height)                      /* window height, in pixels */
{
  pictureExtent = ((width < height) ? width : height);
  msReshape(pictureExtent, 0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -2.0);
}

/***********************************************************************/

/* windowDump

Returned Value: int
If this file is written successfully, this returns 0.
Otherwise, it prints an error message to the terminal and returns 1.

Called By: animate
  This was formerly called by displayPictureWindow, but that did not
  work. Possibly, animate was interfering with glReadPixels since
  animate is the glutIdleFunction for the picture window and may have
  been swapping buffers at the same time the buffers were being copied.
  That could happen if different windows are in different threads.

This writes a ppm file containing an image that combines the
metricsWindow, the pictureWindow, and the commandWindow. The
metricsWindow is on the left side of the image, the pictureWindow on
the right, and the commandWindow on the bottom.

This gets copies the three windows, combines them, and writes out the
ppm file. Each window is first saved in the tempImage array and then
transferred to the allImage array. 

The indexing for making allImage (the contents of the ppm file) is
complex since (1) glReadPixels writes pixels left to right and
bottom to top, while ppm files are read left to right and top to
bottom, (2) three windows are being combined into one image, and (3)
there are 3 chars for each pixel. The critical variables are:
 i is the index for rows of allImage. For copying a window from tempImage
   into allImage, its value is set initially to the row of allImage into
   which the lowest row of the window is to be copied. Then i is
   decreased by 1 each time around the row loop, to move upwards in
   allImage.
 k is the index for lines of whatever window is being copied into
   allImage. It starts at 0 and is increased by 1 each time around
   the row loop to move upwards in tempImage.
 j is the index for chars on a row.
 start is the char index of place on a line of allImage at which to
   start copying in a line from the tempImage.
 stop is the length in chars of a line of the tempImage.

The default value for GL_PACK_ALIGNMENT is 4 rather than 1. If the
value is not set to 1 and the window width is not divisible by 4, the
dumped image is skewed. The "glPixelStorei(GL_PACK_ALIGNMENT, 1);"
which sets the value to 1 needs to be repeated for each window.

This function is unreliable. Sometimes the picture it makes has black
or white areas that should be images. It appears that the glReadPixels
function is unreliable. It is not clear why glReadBuffer(GL_FRONT) is
necessary with the metrics window and the command window. The picture
was not being generated correctly when glReadBuffer(GL_BACK) was being
used with those windows.

*/

static int windowDump(void) // NO ARGUMENTS
{
  FILE * outFile;         // file pointer for dumped image
  char fileName[FILENAME_SIZE]; // name of dumped image
  static char ppmImage[IMAGE_SIZE];  // storage for dumped image
  static char tempImage[IMAGE_SIZE]; // storage for image of one window
  int allWidth;     // entire width of dumped image, in chars
  int allHeight;    // entire height of dumped image, in lines of pixels
  int i;            // index for lines of ppmImage
  int j;            // index for columns of tempImage and ppmImage
  int k;            // index for lines of tempImage
  int start;        // starting point on line of ppmImage
  int stop;         // length of run or upper bound of index value
  int imageSize;    // number of chars in image (3 times number of pixels)
  
  allHeight = (max(pictureExtent, metricsHeight) + commandHeight);
  allWidth = (3 * (pictureExtent + metricsWidth));
  imageSize = (allWidth * allHeight);
  if (imageSize > IMAGE_SIZE)
    {
      fprintf(stderr, "WindowDump - Image too large for window dump\n");
      return 1;
    }

  // handle the picture window
  glutSetWindow(pictureWindow);
  glPixelStorei(GL_PACK_ALIGNMENT, 1);
  glReadBuffer(GL_BACK);
  glReadPixels(0, 0, pictureExtent, pictureExtent,
  	       GL_RGB, GL_UNSIGNED_BYTE, tempImage);
  start = (3 * metricsWidth);
  stop = (3 * pictureExtent);
  i = (max(metricsHeight, pictureExtent) - 1);
  for (k=0; i > (pictureExtent - 1); i--, k++)
    { // put black under picture window if necessary
      for (j = 0;  j < stop; j++)
	ppmImage[(i * allWidth) + start + j] = 0;
    }
  i =  (pictureExtent - 1);
  for (k=0; i >= 0; i--, k++)
    { // copy in the picture window
      for (j = 0; j < stop; j++)
	ppmImage[(i * allWidth) + start + j] = tempImage[(k * stop) + j];
    }

  // handle the metrics window
  glutSetWindow(metricsWindow);
  glPixelStorei(GL_PACK_ALIGNMENT, 1);
  glReadBuffer(GL_FRONT);
  glReadPixels(0, 0, metricsWidth, metricsHeight,
	       GL_RGB, GL_UNSIGNED_BYTE, tempImage);
  stop = (3 * metricsWidth);
  i = (max(metricsHeight, pictureExtent) - 1);
  for (k=0; i > (metricsHeight - 1); i--, k++)
    { // put black under metrics window if necessary
      for (j = 0;  j < stop; j++)
	ppmImage[(i * allWidth) + j] = 0;
    }
  i = (metricsHeight - 1);
  for (k=0; i >= 0; i--, k++)
    { // copy in the metrics window
      for (j = 0;  j < stop; j++)
	ppmImage[(i * allWidth) + j] = tempImage[(k * stop) + j];
    }

  // handle the command window
  glutSetWindow(commandWindow);
  glPixelStorei(GL_PACK_ALIGNMENT, 1);
  glReadBuffer(GL_FRONT);
  glReadPixels(0, 0, commandWidth, commandHeight,
	       GL_RGB, GL_UNSIGNED_BYTE, tempImage);
  if ((3 * commandWidth) < allWidth)
    { // put black to the right of the command window if necessary
      start = (3 * commandWidth);
      stop = allWidth;
      i = (allHeight - 1);
      for (k = 0; i > (max(pictureExtent, metricsHeight) - 1); i--)
	{
	  for (j = start; j < stop; j++)
	    ppmImage[(i * allWidth) + j] = 0;
	}
    }
  stop = (((3 * commandWidth) < allWidth) ? (3 * commandWidth) : allWidth);
  i = (allHeight - 1);
  for (k = 0; i > (max(pictureExtent, metricsHeight) - 1); i--, k++)
    { // copy in the command window; truncate on the right if necessary
      for (j = 0;  j < stop; j++)
	ppmImage[(i * allWidth) + j] = tempImage[(3 * k * commandWidth) + j];
    }

  glutSetWindow(pictureWindow);
  snprintf(fileName, FILENAME_SIZE, "kittingViewer_%04d.ppm", dumpIndex);
  if ((outFile = fopen(fileName, "w")) == NULL)
    {
      fprintf(stderr, "windowDump - failed to open file %s\n", fileName);
      return 1;
    }
  fprintf(outFile, "P6\n%d %d\n255\n", (allWidth / 3), allHeight);
  if (fwrite(ppmImage, imageSize * sizeof(char), 1, outFile) != 1)
    {
      fprintf(stderr, "windowDump - failed to write in file %s\n", fileName);
      fclose(outFile);
      return 1;
    }
  fclose(outFile);
  printf("dumped kittingViewer windows in file %s\n", fileName);
  return 0;
}

/********************************************************************/

/* textDump

Returned Value: int
If this file is written successfully, this returns 0.
Otherwise, it prints an error message to the terminal and returns 1.

Called By: animate

This prints to a text file the information in the Metrics and Settings
window and the information in the Kitting Command and Messages window.

*/

static int textDump(void) // NO ARGUMENTS
{
  FILE * outFile;         // file pointer for dumped image
  char fileName[FILENAME_SIZE]; // name of dumped image
  int n;

  snprintf(fileName, FILENAME_SIZE, "kittingViewer_%04d.txt", dumpIndex);
  outFile = fopen(fileName, "w");
  if (outFile == NULL)
    {
      fprintf(stderr, "textDump - failed to open file %s\n", fileName);
      return 1;
    }
  fprintf(outFile, "METRICS\n");
  fprintf(outFile, "action commands executed successfully: %d\n",
	  KittingViewer::actionCommandsExecuted);
  fprintf(outFile, "other commands executed successfully: %d\n",
	  KittingViewer::otherCommandsExecuted);
  fprintf(outFile, "total robot distance moved: %.4lf %s\n",
	  (KittingViewer::distanceTotal / KittingViewer::robotLengthFactor),
	  KittingViewer::robotLengthUnits);
  fprintf(outFile, "total execution time: %.2lf seconds\n",
	  KittingViewer::totalExecutionTime);
  fprintf(outFile, "useless commands executed: %d\n",
	  KittingViewer::uselessCommands);
  fprintf(outFile, "range errors: %d\n",
	  KittingViewer::rangeErrors);
  fprintf(outFile, "parse errors: %d\n",
	  KittingViewer::parseErrors);
  fprintf(outFile, "command sequence errors: %d\n",
	  KittingViewer::commandSequenceErrors);
  fprintf(outFile, "gripper use errors: %d\n",
	  KittingViewer::gripperUseErrors);
  fprintf(outFile, "tool change errors: %d\n",
	  KittingViewer::toolChangeErrors);
  fprintf(outFile, "motion errors: %d\n",
	  KittingViewer::motionErrors);
  fprintf(outFile, "total errors: %d\n",
	  (KittingViewer::rangeErrors + KittingViewer::commandSequenceErrors +
	   KittingViewer::gripperUseErrors + KittingViewer::parseErrors +
	   KittingViewer::toolChangeErrors + KittingViewer::motionErrors +
	   KittingViewer::locationErrors));
  if (KittingViewer::commands.size() == 0)
    {
      fprintf(outFile, "object location errors: %d\n",
	      KittingViewer::locationErrors);
      fprintf(outFile, "objects located correctly: %d\n",
	      KittingViewer::locationGoods);
      fprintf(outFile, "total basic goal object distance moved: %.4lf %s\n",
	      (KittingViewer::totalGoalDistance /
	       KittingViewer::robotLengthFactor),
	      KittingViewer::robotLengthUnits);
      fprintf(outFile, "score: %f\n", KittingViewer::score);
    }

  fprintf(outFile, "\n");
  fprintf(outFile, "ROBOT SETTINGS\n");
  fprintf(outFile, "robot length units: %s\n",
	  KittingViewer::robotLengthUnits);
  fprintf(outFile, "robot angle units: %s\n",
	  KittingViewer::robotAngleUnits);
  fprintf(outFile, "robot speed: %.4f %s/s\n",
	  (KittingViewer::robotSpeed / KittingViewer::robotLengthFactor),
	  KittingViewer::robotLengthUnits);
  fprintf(outFile, "robot maximum speed: %.4f %s/s\n",
	  (KittingViewer::robotMaxSpeed / KittingViewer::robotLengthFactor),
	  KittingViewer::robotLengthUnits );
  fprintf(outFile, "robot relative speed: %.2f%%\n",
	  KittingViewer::robotRelSpeed);
  fprintf(outFile, "robot acceleration: %.4f %s/s*s\n",
	  (KittingViewer::robotAccel / KittingViewer::robotLengthFactor),
	  KittingViewer::robotLengthUnits );
  fprintf(outFile, "robot maximum acceleration: %.4f %s/s*s\n",
	  (KittingViewer::robotMaxAccel / KittingViewer::robotLengthFactor),
	  KittingViewer::robotLengthUnits);
  fprintf(outFile, "robot relative acceleration: %.2f%%\n",
	  KittingViewer::robotRelAccel);
  fprintf(outFile, "robot end angle tolerance: %.4f %s\n",
	  (KittingViewer::robotEndAngleTol / KittingViewer::robotAngleFactor),
	  KittingViewer::robotAngleUnits);
  fprintf(outFile, "robot end point tolerance : %.4f %s\n",
	  (KittingViewer::robotEndPointTol / KittingViewer::robotLengthFactor),
	  KittingViewer::robotLengthUnits);
  fprintf(outFile, "robot intermediate point tolerance : %.4f %s\n",
	  (KittingViewer::robotIntPointTol / KittingViewer::robotLengthFactor),
	  KittingViewer::robotLengthUnits);
  fprintf(outFile, "gripper is: %s\n",
	   ((KittingViewer::nowModel->Robot->EndEffector == 0) ? "not on robot"
	    : KittingViewer::robotGripperOpen ? "open"
	    : "closed"));
  fprintf(outFile, "tool changer is: %s\n\n",
	  (KittingViewer::robotToolChangerOpen ? "open" : "closed"));

  fprintf(outFile, "KITTING VIEWER SETTINGS\n");
  fprintf(outFile, "grid spacing: %.4f %s\n",
	  (KittingViewer::spacing / KittingViewer::lengthFactor),
	  KittingViewer::lengthUnits);
  fprintf(outFile, "scoring file: %s\n", KittingViewer::scoringFileName);
  fprintf(outFile, "same-SKU equivalent: %s\n",
	  (KittingViewer::swap ? "true" : "false"));
  fprintf(outFile, "tolerance: %.4f millimeter\n", KittingViewer::tolerance);
  fprintf(outFile, "time factor: %.4f\n\n", KittingViewer::timeFactor);

  for (n = 1; ((n < MAXPOSES) && (KittingViewer::commandString[n][0])); n++)
    {
      fprintf(outFile, "%s\n", KittingViewer::commandString[n]);
    }
  if (KittingViewer::commandString[0][0])
    {
      if (KittingViewer::commandString[1][0])
	fprintf(outFile, "\n");
      fprintf(outFile, "%s\n", KittingViewer::commandString[0]);
    }
  fclose(outFile);
  printf("dumped kittingViewer metrics and settings in file %s\n", fileName);
  return 0;
}

/********************************************************************/

