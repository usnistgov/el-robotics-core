#ifndef __genericModel
#define __genericyModel
#include "database/ShapeDesign.h"
#include "database/StockKeepingUnit.h"
#include "database/ExternalShape.h"
#include <stdio.h> // printf
#include <string>

class GenericModel{
 public:
  GenericModel();
  std::string getModel(StockKeepingUnit *sku);
};

#endif
