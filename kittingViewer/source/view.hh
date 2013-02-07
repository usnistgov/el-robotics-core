#ifndef VIEW_HH
#define VIEW_HH

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#ifdef WIN32
#define snprintf sprintf_s
#define strncpy strncpy_s
#endif

void glInit(int argc, char * argv[], const char * win_name);

#endif /* VIEW_HH */
