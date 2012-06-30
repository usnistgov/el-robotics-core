/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
*****************************************************************************/
#include "KittingPDDLProblem.h"


/*!
@brief Auto-generated constructor stub
*/
KittingPDDLProblem::KittingPDDLProblem() {
}

/*!
@brief Auto-generated destructor stub
*/
KittingPDDLProblem::~KittingPDDLProblem() {
}


/*!
@brief Find the type of each parameter stored in @a myMap
@param inputfile An ifstream
@param myMap A map that stores a string and the corresponding line. @a myMap is the result from the function KittingPDDLProblem#findParam(string,vector<string>)
@return A map that contains each string from @a myVector and the line where it is found
@see KittingPDDLProblem#findParam(string,vector<string>)


The different steps are:
<ul>
<li>For each @a line in @a inputfile
<ul>
<li>For each @a element of @a myMap
<ul>
<li> If @a line equals the second @a element (line number) of @a myMap
<ul>
<li> Retrieves the last element of @a line, which is the @a type of the parameter
<li> Store the first @a element of @a myMap (parameter) and its @a type in a KittingPDDLProblem#m_ParamType
</ul>
</ul>
</ul>
</ul>
*/
void KittingPDDLProblem::findParamType(std::ifstream &inputfile,map<string,int> myMap, KittingPlan *kittingplan){
	int lineNumber = 0;


	//-- Read input file and retrieve the text at the line stored in the map paramLine
	if (inputfile.is_open()){
		string line;
		while(getline(inputfile, line)){
			lineNumber++;
				  for( map<string, int>::iterator ii=myMap.begin(); ii!=myMap.end(); ++ii){
					  //cout << (*ii).first << ": " << (*ii).second << endl;
					  if (lineNumber==(*ii).second)
					  {
						  line.erase(line.find_last_not_of(" \n\r\t")+1); //right-trim
						  std::size_t pos = line.size();
						  while (line[pos] == ' ' && pos > 0) --pos;
						  if (pos == 0) { /* string consists entirely of spaces */ }

						  std::string result = line.substr(line.find_last_of(' ', pos));
						  kittingplan->m_ParamTypeList.insert(std::pair<string,string>((*ii).first,result));

						  //cout << (*ii).first << " " << result << endl;
					  }
				  }
			  }
		  }
}

/*!
@brief Find each string of @a myVector in @a myString
@param myString String to be searched
@param myVector Vector of strings
@return A map that contains each string from @a myVector and the line where it is found

The different steps are:
<ul>
<li> For each string @s in @a myVector
<ul>
<li>Find @a s in @a myString
<li>Return the @a line where @a s was found
<li>Store @a s and the corresponding @a line in a map
</ul>
*/
map<string,int> KittingPDDLProblem::findParam(string myString, vector<string> myVector){

	map<string,int> paramLine;

	for (vector<string>::size_type i = 0; i < myVector.size(); i++){
		for (string::size_type index = myString.find(myVector[i], 0);
				index != string::npos;
				index = myString.find(myVector[i], index + 1 )){
			string::size_type line   = count(myString.begin(),myString.begin() + index, '\n' ) + 1;
			string::size_type column = index - myString.rfind( '\n', index );

			paramLine.insert(std::pair<string,int>(myVector[i],line));
			break;
		}
	}
	return paramLine;
}


/*!
@brief Match the type of each parameter in #KittingPlan::m_paramVector by looking into the PDDL Problem File
@param filename Location of the PDDL Problem File (#PDDL_PROBLEM)

The different steps are:
<ul>
<li>Copy the content of KittingPlan::m_paramVector in vector @a vectorTemp
<li>Open the PDDL Problem File
<li>Copy the content of the file in a string @a s
<li>For each element of @a vectorTemp
<ul>
<li> Find @a vectorTemp[i] in @a s and the corresponding line @a line
<li> Store @a vectorTemp[i] and @a line in a map<string, int> paramLine which looks like: paramLine=map<vectorTemp[i],line>
</ul>
<li>Parse the PDDL Problem File
<ul>
<li> For each element @a line in @a paramLine
<ul>
<li> When the parser reaches @a line, retrieve the whole line
<li> Get the last element of this line, which is basically the type of the parameter @a vectorTemp[i]
<li>Store each parameter vectorTemp[i] and its type in KittingPlan::m_ParamTypeList
</ul>
</ul>
</ul>
*/
void KittingPDDLProblem::parsePDDLProblem(const char* filename, KittingPlan *kittingplan){

	ifstream inputfile;
	inputfile.open(filename);
	size_t pos;
	vector<string> vectTemp;
	map<string, int> paramLine;//--paramLine is used to store the parameters and the line in inputfile where they first appear
	FileOperator *fileop = new FileOperator;

	//-- Copy kittingplan->m_paramVector to vectTemp for better manipulation
	vectTemp.reserve(kittingplan->m_paramList.size());
	copy(kittingplan->m_paramList.begin(),kittingplan->m_paramList.end(),back_inserter(vectTemp));

	ifstream f( filename );
	if (!f){
		cerr << "Could not open file " << filename << endl;
		exit(0);
	}


	// Read the entire file into memory
	  string s;
	  string t;
	  while (getline( f, t ))
	    s += t + '\n';
	  //f.close();

	  paramLine=findParam(s,vectTemp);
	  findParamType(inputfile,paramLine,kittingplan);
	  inputfile.close();
	  //fileop->readMap(m_ParamType);

	  }
