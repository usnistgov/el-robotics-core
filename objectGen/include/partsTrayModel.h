#ifndef __partsTrayModel
#define __partsTrayModel
#include "database/PartsTray.h"
#include "database/ShapeDesign.h"
#include "database/StockKeepingUnit.h"
#include <stdio.h> // printf
#include <string>

class PartsTrayModel{
 private:
  PartsTray *partsTray;
 public:
  PartsTrayModel();
  PartsTrayModel( PartsTray *partsTrayIn );
  std::string getModel();
  void setPartsTray( PartsTray *partsTrayIn );
};

#endif
