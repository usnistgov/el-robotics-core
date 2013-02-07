#ifndef __partModel
#define __partModel
#include "database/ExternalShape.h"
#include "database/InternalShape.h"
#include "database/Part.h"
#include "database/ShapeDesign.h"
#include "database/StockKeepingUnit.h"
#include "genericModel.h"
#include <stdio.h> // printf
#include <string>

class PartModel: public GenericModel{
 private:
  Part *part;
 public:
  PartModel();
  PartModel( Part *partIn );
  std::string getModel();
  void setPart( Part *partIn );
};

#endif
