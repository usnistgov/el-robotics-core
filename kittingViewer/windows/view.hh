#ifndef VIEW_HH
#define VIEW_HH

#include "glut.h"

#ifdef WIN32
#define snprintf sprintf_s
#define strncpy strncpy_s
#endif

void glInit(int argc, char * argv[], const char * win_name);

#endif /* VIEW_HH */
