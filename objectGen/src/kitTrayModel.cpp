/*****************************************************************************
------------------------------------------------------------------------------
--  Copyright 2012-2013
--  Georgia Tech Research Institute
--  505 10th Street
--  Atlanta, Georgia 30332
--
--  This material may be reproduced by or for the U.S. Government
--  pursuant to the copyright license under the clause at DFARS
--  252.227-7013 (October 1988).
------------------------------------------------------------------------------

 DISCLAIMER:
 This software was originally produced by the National Institute of Standards
 and Technology (NIST), an agency of the U.S. government, and by statute is
 not subject to copyright in the United States.  

 Modifications to the code have been made by Georgia Tech Research Institute
 and these modifications are subject to the copyright shown above
 *****************************************************************************/
#include "kitTrayModel.h"

KitTrayModel::KitTrayModel()
{
  kitTray = NULL;
}

KitTrayModel::KitTrayModel( KitTray *kitTrayIn )
{
  setKitTray(kitTrayIn);
}

void KitTrayModel::setKitTray( KitTray *kitTrayIn )
{
  kitTray = kitTrayIn;
}

std::string KitTrayModel::getModel()
{
  StockKeepingUnit *sku;
  SkuObject *skuObject = new SkuObject("foo");

  skuObject->get(kitTray->getname());
  sku = skuObject->gethasSkuObject_Sku();
  return (GenericModel::getModel(sku));
}
