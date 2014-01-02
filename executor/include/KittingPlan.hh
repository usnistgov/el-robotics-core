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
 *  @class 	   KittingPlan KittingPlan.hh
 *  @brief     Class for the Kitting Plan
 *  @details   This class is used to manipulate the Kitting Plan File
 *  @author    <a href="http://www.nist.gov/el/isd/ks/kootbally.cfm">Zeid Kootbally</a> \a zeid.kootbally\@nist.gov
 *  @version   1.0
 *  @date      May 17, 2012
 *  @pre       Make sure the kitting Plan Instance file is in etc.
 *  @pre       Make sure the kitting Plan Instance file is not empty.
 */

#include "Tools.hh"
#include <vector>
#include <map>
#include "Operator.hh"

#ifndef KITTINGPLAN_H_
#define KITTINGPLAN_H_

class KittingPlan {
public:
	//-- Member Function
	KittingPlan();
	virtual ~KittingPlan();
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
