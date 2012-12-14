#ifndef __usarSimInf
#define __usarSimInf

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <unistd.h>
#include "ulapi.hh"
#include "recurseLocation.h"

class UsarSimInf{
 private:
  int PORT;
  ulapi_integer socket_fd;

 public:
  UsarSimInf();
  int placeObject( std::string className, std::string name, RecLoc *where );
};
#endif
