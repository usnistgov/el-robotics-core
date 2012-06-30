/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
*****************************************************************************/
#include "FileOperator.h"



/*!
@brief Auto-generated constructor stub
*/
FileOperator::FileOperator() {
}

/*!
@brief Auto-generated destructor stub
*/
FileOperator::~FileOperator() {
}


void FileOperator::stripSpace(string &str) {
    for (int i=0;i<str.length();i++)
       if (str[i]==' ') {
         str.erase(i,1);
         i--;
        }
}

/*!
@brief Remove parentheses in a string
@param s String that contains parentheses
@return The string @a s without parentheses

The different steps are:
<ul>
<li>Find the position @a pos2 of the closing parenthesis ")"
<ul>
<li>Use @a pos2 and remove the closing parenthesis from @a s: use the string::erase function
</ul>
<li>Find the position @a pos2 of the opening parenthesis "("
<ul>
<li> Keep the string that starts after @a pos2: use the string::substr function
</ul>
</ul>
*/
string FileOperator::removeParentheses(std::string s){
	size_t pos1, pos2;
	std::string newLine;
	std::string::iterator it;

	pos2 = s.find(")");
	it=s.begin()+pos2;
	s.erase(it);

	pos1 = s.find("(");
	newLine=s.substr(pos1+1);

	//cout << newLine << "\n";
	return newLine;
}

/*!
@brief Split string @a s and store each element in a vector<string>
@param s The string that needs to be split
@return vector A vector that contains all elements from the string @a s

<b>Example</b>: Read the string "word1 word2 word3" and generates a vector vector<word1,word2,word3>
*/
vector<string> FileOperator::splitString(string s){
	 istringstream iss(s);
	 vector<string> tokens;

	 copy(istream_iterator<string>(iss),
	          istream_iterator<string>(),
	          back_inserter<vector<string> >(tokens));

	 return tokens;
}

/*!
@brief Read and display elements of a vector
@param myVector The vector to read
*/
void FileOperator::readVector(vector<string> myVector){
	int vectLength;
	vectLength=(int)myVector.size();

	for (vector<int>::size_type i = 0; i < vectLength; i++)
		cout <<myVector[i]<< " ";
	cout<< endl;
}

/*!
@brief Read the elements of a vector that contains a vector of string
@param myVector The vector to read
*/
void FileOperator::readVectorOfVector(vector<vector<string> > myVector){
	for (vector< vector<string> >::size_type u = 0; u < myVector.size(); u++) {
		for (vector<string>::size_type v = 0; v < myVector[u].size(); v++) {
			cout << myVector[u][v] << " ";
		}
		cout << endl;
	}
}

/*!
@brief Remove duplicate values in a vector
@param myVector The vector to read
*/
void FileOperator::removeDuplicates(vector<string>& myVector){
	sort(myVector.begin(), myVector.end());
	myVector.erase(unique(myVector.begin(), myVector.end()), myVector.end());
}

/*!
@brief Read the elements of a map that contains a vector as the second parameter
@param myMap The map to read
*/

void FileOperator::readMapOfVector(std::map<string,std::vector<string> > myMap){
	for(map<string, vector<string> >::iterator iter = myMap.begin(); iter != myMap.end(); ++iter ) {
		cout  << iter->first << " ";
		for (vector<string> ::size_type i = 0; i < iter->second.size(); i++)
			cout << iter->second[i] << " ";
		cout  << endl;
	}
}

/*!
@brief Read the elements of a map
@param myMap The map to read
*/
void FileOperator::readMap(map<string,string> myMap){
	for(map<string, string >::iterator iter = myMap.begin(); iter != myMap.end(); ++iter ) {
		cout  << iter->first << " ";
		cout  << iter->second << endl;
	}
}

/*!
@brief Find the type of the parameter @a myParameter by parsing #KittingPDDLProblem:m_ParamTypeList
@param myParameter The parameter for which the type is needed
*/
/*
string FileOperator::findParamType(string myParameter, KittingPDDLProblem *kittingProb){

	map<string,string> myMap;

	for(map<string, string >::iterator iter = myMap.begin(); iter != myMap.end(); ++iter ) {
		//string firstArg = iter->first;
		//cout  << myParameter << endl;
		//if (strcmp(myParameter.c_str(),firstArg.c_str()))
			cout  << iter->second << endl;

		//return (iter->second);
			//cout  << iter->first << " ";
			//cout  << iter->second << endl;
		}
}
*/
