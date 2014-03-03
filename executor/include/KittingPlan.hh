/*****************************************************************************
------------------------------------------------------------------------------
--  Copyright 2012-2014
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
/*!
 *  @class 	   KittingPlan KittingPlan.hh
 *  @brief     Class for the Kitting Plan
 *  @details   This class is used to manipulate the Kitting Plan File
 *  @author    <a href="http://www.nist.gov/el/isd/ks/kootbally.cfm">Zeid Kootbally</a> \a zeid.kootbally\@nist.gov
 *  @author    <a href="robotics.gatech.edu/team/faculty/balakirsky">Stephen Balakirsky</a> \a stephen.balakirsky\@gtri.gatech.edu
 *  @version   1.1
 *  @date      Feb 3, 2014
 *  @pre       Make sure the kitting Plan Instance file is in etc.
 *  @pre       Make sure the kitting Plan Instance file is not empty.
 */

#include "Tools.hh"
#include <vector>
#include <map>
#include "FileOperator.hh"

#ifndef KITTINGPLAN_H_
#define KITTINGPLAN_H_

class KittingPlan {
public:
  //-- Member Function
  KittingPlan();
  virtual ~KittingPlan();
  void clearPlan();
  void parsePlanInstance(const char* filename);
  void parseLinePlanInstance(string action);
  void storeParam();
  string matchParamType(string param);

  //-- Member Data
  vector<vector<string> > m_actionParamList;
  /*!< @brief Contains actions and parameters found in the plan file
   *
   *   For example: < <attach-eff robot_1 tray_gripper tray_gripper_holder> <create-kit kit_1 kit_tray_1 work_table_1>>
   * */
  vector<string> m_paramList;
  /*!< @brief Contains all the parameters found in the plan file
   *
   *  For example (r1, effh1, eff1, effh2, eff2, kt1)
   * */

  map<string,string> m_ParamTypeList;
};

#endif /* KITTINGPLAN_H_ */
