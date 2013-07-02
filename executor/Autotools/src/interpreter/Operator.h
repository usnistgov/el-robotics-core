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
 *  \brief     Class for operations on files
 *  \details   This class is used to manipulate files (open, substract, concat, etc).
 *  \author    <a href="http://www.nist.gov/el/isd/ks/kootbally.cfm">Zeid Kootbally</a> \a zeid.kootbally\@nist.gov
 *  \version   1.0
 *  \date      May 17, 2012
 */

#ifndef FILEOPERATOR_H_
#define FILEOPERATOR_H_

#include "Tools.h"
#include "KittingPDDLProblem.h"
#include <vector>
#include <map>
#include <functional>

class FileOperator {
public:
	FileOperator();
	virtual ~FileOperator();

	//-- Member Data
	char* getCanonFile();
	ifstream openFile(const char* filename);
	string removeParentheses(std::string s);
	vector<string> splitString(string s);
	void readVector(vector<string> myVector);
	void readMapOfVector(map<string,vector<string> > myMap);
	void readMap(map<string,string> myMap);
	void readVectorOfVector(vector<vector<string> > myVector);
	void removeDuplicates(vector<string>& myVector);
	vector<string> copyVector(vector<string> myVector);
	//string findParamType(string parameter, KittingPDDLProblem *);
	void stripSpace(string &str);
	void writeData(string message);
	void createOutputFile();
	void setCRCLFile(string file_name);
	string getCRCLFileName();

private:
	string m_crcl_file;
};

#endif /* FILEOPERATOR_H_ */
