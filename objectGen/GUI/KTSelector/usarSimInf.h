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
  int connected; // 1 if connected to USARSim, 0 else
  ulapi_integer socket_fd;

 public:
  UsarSimInf(int connectIn, std::string hostname, int portIn=3000);
  int placeObject( std::string className, std::string name, RecLoc where,
		   int permanent);
};
#endif
