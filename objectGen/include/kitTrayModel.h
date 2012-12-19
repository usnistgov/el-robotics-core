#ifndef __kitTrayModel
#define __kitTrayModel
#include "database/KitTray.h"
#include "database/ShapeDesign.h"
#include "database/StockKeepingUnit.h"
#include <stdio.h> // printf
#include <string>

class KitTrayModel{
 private:
  KitTray *kitTray;
 public:
  KitTrayModel();
  KitTrayModel( KitTray *kitTrayIn );
  std::string getModel();
  void setKitTray( KitTray *kitTrayIn );
};

#endif
