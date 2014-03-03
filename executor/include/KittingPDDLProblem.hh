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
/*!
 *  \brief     Class for the Kitting PDDL Problem
 *  \details   This class is used to manipulate the Kitting PDDL Problem File
 *  \author    <a href="http://www.nist.gov/el/isd/ks/kootbally.cfm">Zeid Kootbally</a> \a zeid.kootbally\@nist.gov
 *  \version   1.0
 *  \date      May 17, 2012
 *  \pre       The kitting PDDL Problem file must be in the etc directory.
 *  \pre       Only one object per line in the Problem PDDL file:
 *             r1 - robot
 *		       kt1 - kittray
 */


#ifndef KITTINGPDDLPROBLEM_H_
#define KITTINGPDDLPROBLEM_H_

#include "Tools.hh"
#include <vector>
#include <map>
#include "FileOperator.hh"
#include "KittingPlan.hh"


class KittingPDDLProblem {
public:
  //-- Member Function
  KittingPDDLProblem();
  virtual ~KittingPDDLProblem();
  int readFluents(const char* filename);
  void parsePDDLProblem(KittingPlan *kittingplan);
  map<string,int> findParam(vector<string> myVector);
  void findParamType(map<string,int> myMap, KittingPlan *kittingplan);
  //-- Member Data
  //map<string,string> m_ParamTypeList;
  /*!< \brief Contains the parameters found in the PDDL Problem File (#PDDL_PROBLEM) and their type.
   *
   *  For example: <<robot_1 Robot> <kit_tray_1 KitTray>>
   * */
private:
  string fluents;
};

#endif /* KITTINGPDDLPROBLEM_H_ */
