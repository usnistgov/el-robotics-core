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
 *  \brief     Class for operations on files
 *  \details   This class is used to manipulate files (open, substract, concat, etc).
 *  \author    <a href="http://www.nist.gov/el/isd/ks/kootbally.cfm">Zeid Kootbally</a> \a zeid.kootbally\@nist.gov
 *  \version   1.0
 *  \date      May 17, 2012
 */

#ifndef FILEOPERATOR_H_
#define FILEOPERATOR_H_

#include "Tools.hh"
#include "KittingPDDLProblem.hh"
#include <vector>
#include <map>
#include <functional>

class FileOperator {
public:
  FileOperator();
  virtual ~FileOperator();

  //-- Member Data
  ifstream openFile(const char* filename);
  static string removeParentheses(std::string s);
  static vector<string> splitString(string s);
  void readVector(vector<string> myVector);
  void readMapOfVector(map<string,vector<string> > myMap);
  void readMap(map<string,string> myMap);
  void readVectorOfVector(vector<vector<string> > myVector);
  static void removeDuplicates(vector<string>& myVector);
  vector<string> copyVector(vector<string> myVector);
  //string findParamType(string parameter, KittingPDDLProblem *);
  static void stripSpace(string &str);
  void writeData(string message);
  void createOutputFile();
  void setCRCLFile(string file_name);
  string getCRCLFileName();

private:
  string m_crcl_file;
  int file_valid;
};

#endif /* FILEOPERATOR_H_ */
