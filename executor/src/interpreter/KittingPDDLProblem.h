/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
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

#include "Tools.h"
#include <vector>
#include <map>
#include "FileOperator.h"
#include "KittingPlan.h"


class KittingPDDLProblem {
public:
	//-- Member Function
	KittingPDDLProblem();
	virtual ~KittingPDDLProblem();
	void parsePDDLProblem(const char* filename, KittingPlan *kittingplan);
	map<string,int> findParam(string myString, vector<string> myVector);
	void findParamType(std::ifstream &inputfile,map<string,int> myMap, KittingPlan *kittingplan);
	//-- Member Data
	//map<string,string> m_ParamTypeList;
	/*!< \brief Contains the parameters found in the PDDL Problem File (#PDDL_PROBLEM) and their type.
	 *
	 *  For example: <<robot_1 Robot> <kit_tray_1 KitTray>>
	 * */
};

#endif /* KITTINGPDDLPROBLEM_H_ */
