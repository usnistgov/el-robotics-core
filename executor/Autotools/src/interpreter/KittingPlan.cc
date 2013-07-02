/*****************************************************************************
 DISCLAIMER:
 This software was produced by the National Institute of Standards
 and Technology (NIST), an agency of the U.S. government, and by statute is
 not subject to copyright in the United States.  Recipients of this software
 assume all responsibility associated with its operation, modification,
 maintenance, and subsequent redistribution.

 See NIST Administration Manual 4.09.07 b and Appendix I.
 *****************************************************************************/

#include "KittingPlan.h"
#include <stdio.h>
#include <string.h>

/*!
 @brief Auto-generated constructor stub
 */
KittingPlan::KittingPlan() {
}

/*!
 @brief Auto-generated destructor stub
 */
KittingPlan::~KittingPlan() {
}

/*!
 @brief Parse the Plan Instance File
 @param filename location of the Plan Instance File

 The different steps are:
 <ul>
 <li>Open the Plan Instance File
 <li>Parse the Plan Instance File
 <li>Retrieve each line
 <li>Parse each line
 <li>Remove the parentheses
 <li>Store each line in a list (vector<vector<string>>)
 </ul>
 */
void KittingPlan::parsePlanInstance(const char* filename) {

	ifstream inputfile;
	//FileOperator *fileop = new FileOperator;
	inputfile.open(filename);

	if( inputfile.fail() )
	  {
	    cout << "KittingPlan.cc::parsePlanInstance:Error on file open " 
		 << filename << endl;
	    exit(0);
	  }
	size_t pos;

		std::string line;
		while (getline(inputfile, line)) {
		  parseLinePlanInstance(line);
		}
	inputfile.close();
	//fileop->readVectorOfVector(m_actionParamList);
}

/*!
 @brief Parse an action and separate the action name to its parameters
The action name and parameters are put in a map <name,vector<string>>
 @param action Action to be parsed

 The different steps are:
 <ul>
 <li>Find the position of the closing parenthesis ")"
 <li>Remove it from \a s (erase)
 <li>Find the position of the opening parenthesis "("
 <li>Use its position to keep the rest of the string \a s (substr)
 </ul>

 Example:
 <ul>
 <li> Action to execute: (attach-eff robot_1 tray_gripper tray_gripper_holder)
 <li> Result: <attach-eff, <robot_1,tray_gripper,tray_gripper_holder>>
 </ul>
 */
void KittingPlan::parseLinePlanInstance(string action) {
	string simpAction;
	vector<string> vectTemp;
	FileOperator *fileop = new FileOperator;
	if( action.length() <=0 )return;
	simpAction = fileop->removeParentheses(action);
	vectTemp = fileop->splitString(simpAction);
	m_actionParamList.push_back(vectTemp);
}

/*!
 @brief Read #KittingPlan::m_actionParamList and create a vector containing only distinct parameters
 @return A vector of distinct parameters

 The different steps are:
 <ul>
 <li>Read #KittingPlan::m_actionParamList
 <li>Store all parameters in #KittingPlan::m_paramList
 <li>Remove duplicates in #KittingPlan::m_paramList
 <
 </ul>
 */
void KittingPlan::storeParam() {
	FileOperator *fileop = new FileOperator;

	for (vector<vector<string> >::size_type u = 0; u < m_actionParamList.size(); u++) {
		for (vector<string>::size_type v = 1; v < m_actionParamList[u].size(); v++) {
			m_paramList.push_back(m_actionParamList[u][v]);
		}
	}
	fileop->removeDuplicates(m_paramList);
}

/*!
 @brief Given a parameter @a param, look for the type of this parameter in #KittingPlan::m_ParamTypeList
 @param param The paremeter for which the type is to be found
 @return The type of the parameter @a param
 */
string KittingPlan::matchParamType(string param){
	for(map<string, string >::iterator iter = m_ParamTypeList.begin(); iter != m_ParamTypeList.end(); ++iter ) {
		string firstArg = iter->first;
		//cout  << "First Arg: " << firstArg << endl;
		//cout << "Param: " << param << endl;
		if (!strcmp(param.c_str(),firstArg.c_str()))
			return (iter->second);
		}
}
