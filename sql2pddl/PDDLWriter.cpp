#include "PDDLWriter.h"

/*! \brief Constructor
 */
PDDLWriter::PDDLWriter() {
	// constructor
}

PDDLWriter::~PDDLWriter() {
	// destructor
}

/**
	 * @brief writes all the predicates related to each predicate prototype/line in input file
	 *
	 * This method loops through the input file. It takes the name of the predicate from the first line,
	 * and sends the information from the database information line to a parser which queries the relevant
	 * information. It sends the resulting columns to writeGroupPredicates or writeGroupFunctions, respectively.
	 * It stops parsing when it sees the line ":end".
	 *
	 * Data from the database is passed between functions in a two-dimensional vector of strings, where the
	 * top-level vector is a vector of columns pulled out of the database. The structure looks as follows:
	 * 	  columns = {<table><tr>
	 *	  <th>column1:</th>
	 *	  <th>column2:</th>
	 *	</tr>
	 *	<tr>
	 *	  <td>_NAME 1</td>
	 *	  <td>attribute 1</td>
	 *	</tr>
	 *	<tr>
	 *	  <td>_NAME 2</td>
	 *	  <td>attribute 2</td>
	 *	</tr>
	 *	<tr>
	 *	  <td>_NAME n</td>
	 *	  <td>attribute n</td>
	 *	</tr>
	 *	</table> }
	 *
	 *
	 * @param outFile the problem file
	 * @param mappingText the input file
	 */
void PDDLWriter::parseAndWriteInit(std::ofstream& problemFile, std::ifstream& oldProblemFile, std::ifstream& mappingText){
	std::string predicateName;
	std::string functionName;
	std::vector<std::vector<std::string> > columns;
	std::string line;
	std::vector<std::string> tableNames = getAllTableNames();
	// we need the names of all the tables to see which input tokens are names of Tables that could be selected from

	std::getline(mappingText,line); // :predicates
	std::getline(mappingText,line); // blank line
	std::getline(mappingText,line); // first input line

	problemFile << "\t(:init" << std::endl;

	//writing predicates
	while(line.compare(":functions")!=0){
		predicateName = extractPredicateName(line);
		// move from first content line to the second, which contains relational mappings
		std::getline(mappingText,line);

		columns = parseAndFetchPredicateData(line, tableNames);

		if(columns.size() > 0){
			writeGroupPredicates(problemFile, predicateName, columns);
		}

		std::getline(mappingText,line); // blank line
		std::getline(mappingText,line); // load next content line
	}

	writeLineFromOriginalFile("endEffector-is-for-partSKU",problemFile, oldProblemFile,0);

	std::getline(mappingText,line); // blank line
	std::getline(mappingText,line); // first input line in section

	//writing functions
	while(line.compare(":end")!=0){
		functionName = extractPredicateName(line);
		// move from first content line to the second, which contains relational mappings
		std::getline(mappingText,line);

		columns = parseAndFetchFunctionData(line,tableNames);

		if(columns.size() > 0){
			writeGroupFunctions(problemFile, functionName, columns);
		}

		std::getline(mappingText,line); // blank line
		std::getline(mappingText,line); // load next content line
	}

	// for now, these functions must be hard-coded
	writeLineFromOriginalFile("capacity-of-parts-in-kit",problemFile, oldProblemFile,1);
	writeLineFromOriginalFile("final-quantity-of-parts-in-kit",problemFile, oldProblemFile,1);
	problemFile << "\n\t\t(= (part-found-flag) 1)" << std::endl;

	problemFile << "\t)" << std::endl;

}

/**
 * @brief Writes the header and object section of the new problem file by copying it
 * from the original problem file - lists of objects are updated from database
 */
void PDDLWriter::writeObjectSection(std::ofstream& outFile, std::ifstream& referenceFile){
	std::string line;
	std::vector<std::string> tokens;
	std::vector<std::string> objects;

	// write the header using the referenceFile
	for(unsigned int i = 0; i<3; i++){
		std::getline(referenceFile, line);
		outFile << line << std::endl;
	}
	std::getline(referenceFile, line);
	// print object section: pick out all table names, create DAOs, get all _NAME
	while(line.compare(")") != 0){
		tokens = split(line,' ');
		objects = getSetOfObjectNames(new DAO(tokens.at(tokens.size() -1)), tokens.at(tokens.size() -1), "_NAME");
		if(objects.size() > 0){
			outFile << "\t\t";
			for(unsigned int j = 0;j<objects.size();j++){
				outFile << objects.at(j) << " ";
			}
			outFile << "- " << tokens.at(tokens.size()-1) << std::endl;
		}
		std::getline(referenceFile, line);
	}

	outFile << "\t)" << std::endl;
}

/**
 * @brief Writes the goal section of the new problem file by copying it directly
 * from the original problem file
 */
void PDDLWriter::writeGoalSection(std::ofstream& outFile, std::ifstream& referenceFile){
	std::string line;
	referenceFile.clear();
	referenceFile.seekg(0, referenceFile.beg);
	while(std::getline(referenceFile, line) && line.compare(	"	(:goal") != 0){
	}
	outFile << line << std::endl;
	while(std::getline(referenceFile, line)){
		outFile << line << std::endl;
	}
}

std::vector<std::vector<std::string> > PDDLWriter::parseAndFetchPredicateData(std::string line, std::vector<std::string> tables){
	std::vector<std::vector<std::string> > results;

	std::vector<std::string> tokens = split(line,' ');

	std::map<std::string,DAO*> fetchers = retrieveDAOs(tokens, tables);

	// Predicates are created in a subtractive process - first, all possible predicates are saved, then those that do not fit the conditions are taken out
	results = fillWithUnfilteredEntries(tokens, fetchers);

	if(results.size() > 0 || line.find('/') != std::string::npos){
		results = filterTable(tokens,results,match(tokens,":"), match(tokens,"print"), fetchers);
	}

	return results;
}

std::vector<std::vector<std::string> > PDDLWriter::parseAndFetchFunctionData(std::string line, std::vector<std::string> tables){
	std::vector<std::vector<std::string> > results;
	std::vector<std::string> tokens = split(line,' ');

	std::map<std::string,DAO*> fetchers = retrieveDAOs(tokens, tables);

	// Functions, however, are created in an additive manner, because they deal with summation
	results = evaluateFunctions(tokens, fetchers);

	return results;
}

std::vector<std::vector<std::string> > PDDLWriter::filterTable(std::vector<std::string> tokens, std::vector<std::vector<std::string> > raw, unsigned int begin, unsigned int end, std::map<std::string,DAO*> fetchers){
	std::vector<std::vector<std::string> > filtered = raw;
	std::vector<std::vector<std::string> > complement;
	std::map<std::string, std::vector<std::string> > rawGet;
	std::map<std::string, std::string> referencedMap;
	std::map<std::string, std::string> primaryMap;
	std::map<std::string, std::vector<std::string> >::iterator itex;
	std::vector<std::string> conditionColumn;
	std::vector<std::string> resultColumn;
	std::vector<std::string> attribute;
	std::vector<std::string> targets;
	std::vector<std::string> attributesToPrint;
	std::string current;
	std::pair<std::string,std::string> strippedPair;
	std::string::size_type slashPose;
	int filterBy;
	int wantComplement;

	for (int m = match(tokens,"print")+1; (unsigned int)m<tokens.size() ;m++){
		attributesToPrint.push_back(tokens.at(m));
	}

	for (unsigned int i = begin; i<end; i++){
		current = tokens.at(i);
		wantComplement = 0;
		if(current.compare("∃") == 0){
			filterBy = match(attributesToPrint,tokens.at(i+1));
			for(unsigned int j = filtered.at(filterBy).size()-1; j!= UINT_MAX;--j){
				if(filtered.at(filterBy).at(j).compare("") == 0){
					for(unsigned int k = 0; k < filtered.size(); k++){
						filtered.at(k).erase(filtered.at(k).begin() + j);
					}
				}
			}
		}
		else if(current.compare("∈") == 0){
			// building list whose membership objects will be compared to
			strippedPair = parseTableAndAttribute(tokens.at(i+1));
			targets = getSetOfObjectNames(fetchers.at(strippedPair.first),strippedPair.first,strippedPair.second);

			if(tokens.at(i-1).compare("!") == 0){
				wantComplement = 1;
			}
			if(wantComplement){
				filterBy = match(attributesToPrint,tokens.at(i-2));
			}
			else{
				filterBy = match(attributesToPrint,tokens.at(i-1));
			}
			conditionColumn.clear();
			for(unsigned int k = 0; k < filtered.size(); k++){
				complement.push_back(conditionColumn);
			}
			// this sections supports the '!' operator - if it is present, complement is returned instead of filtered entries
			for(unsigned int j = filtered.at(0).size()-1; j >= 0 && j!= UINT_MAX;--j){
				if(match(targets,filtered.at(filterBy).at(j)) == -1){
					// remove entry in each column
					for(unsigned int k = 0; k < filtered.size(); k++){
						// not sure if this preserves the order - may use front-insert
						complement.at(k).push_back(filtered.at(k).at(j));
					}
					for(unsigned int k = 0; k < filtered.size(); k++){
						filtered.at(k).erase(filtered.at(k).begin() + j);
					}
				}
			}
			if(wantComplement){
				filtered = complement;
			}
		}
		else if(current.compare("&&") == 0){
			// '&&' operator corresponds to recursive function call so both filters apply
			filtered = filterTable(tokens, filtered, i+1,end,fetchers);
		}
		else if(current.compare(">") == 0){
			// populating the list whose membership objects will be checked against
			strippedPair = parseTableAndAttribute(tokens.at(i+5));
			targets = getSetOfObjectNames(fetchers.at(strippedPair.first),strippedPair.first,strippedPair.second);

			// we need to create a mapping between two attributes in the referenced table
			referencedMap = createMap(fetchers,tokens.at(i+3), tokens.at(i+1));

			// filter entries according to ∈ clause
			for(std::map<std::string, std::string>::iterator it = referencedMap.begin(); it != referencedMap.end(); it++) {
				if(match(targets,it->first) == -1){
					referencedMap.erase(it);
				}
			}
			attribute.clear();
			// need to create mapping between two attributes in the final table, which is the first input word
			attribute.push_back(tokens.at(i - 1));
			slashPose = 0;
			unsigned int n = match(tokens,"print");
			while(n<tokens.size() && slashPose != std::string::npos){
				n++;
				slashPose = tokens.at(n).find('/');
			}
			attribute.push_back(tokens.at(n));

			rawGet = fetchers.at(tokens.at(1))->getAll(attribute,tokens.at(1));
			// we now have a map from attribute to list, but we want a map from list entry to other list entry
			itex = rawGet.begin();
			conditionColumn = itex->second;
			itex++;
			resultColumn = itex->second;
			for(unsigned int m = 0; m<conditionColumn.size(); m++){
				primaryMap.insert(std::pair<std::string,std::string>(conditionColumn.at(m),resultColumn.at(m)));
			}
			conditionColumn.clear();
			// now we go from one list to the other

			// instantiate filtered with blank columns
			for(unsigned int p = 0; p < attributesToPrint.size(); p++){
				filtered.push_back(conditionColumn);
			}
			// fill table that will be returned with requested and looked-up values
			// !! can only handle two output columns at this time
			unsigned int j = 0;
			for(std::map<std::string, std::string>::iterator it = referencedMap.begin(); it != referencedMap.end(); it++){
				filtered.at(0).push_back(it->first);
				filtered.at(1).push_back(primaryMap.find(it->second)->second);
				j++;
			}

			// sets parser to end of ">" statement
			i += 5;
		}
		attribute.clear();
	}
	return filtered;
}

std::vector<std::vector<std::string> > PDDLWriter::fillWithUnfilteredEntries(std::vector<std::string> input, std::map<std::string,DAO*> fetchers){
	std::vector<std::vector<std::string> > results;
	std::vector<std::vector<std::string> > rearranged;
	std::map<std::string, std::vector<std::string> > rawGet;
	std::vector<std::string> attributes;
	DAO* relevant;
	int wrongLocation;

	if(match(input,">") == -1){
	// we assume that all attributes requested will be from same table for simple predicate
	// only use subtractive method for simple predicates - ones that require table cross-reference are build with separate additive method
		for(unsigned int i = match(input,"print")+1;i<input.size(); i++){
			attributes.push_back(input.at(i));
		}
		// for simple predicates, all the output attributes are from the same table, declared as the first word in input
		relevant = fetchers.at(input.at(1));
		rawGet = relevant->getAll(attributes, input.at(1));
		attributes.clear();
		for(std::map<std::string, std::vector<std::string> >::iterator it = rawGet.begin(); it != rawGet.end(); it++) {
			attributes.push_back(it->first);
			results.push_back(it->second);
		}
		// rearrange the columns so that they are in the order we requested them - the map iterator above is unordered
		for(unsigned int j = 0; j<results.size(); j++){
			wrongLocation = match(attributes, input.at( match(input,"print")+1+ j));
			rearranged.push_back(results.at(wrongLocation));
		}
		results = rearranged;
	}
	return results;
}

std::vector<std::vector<std::string> > PDDLWriter::evaluateFunctions(std::vector<std::string> tokens, std::map<std::string,DAO*> fetchers){
	std::vector<std::vector<std::string> > results;
	std::map<std::string, std::vector<std::string> > rawGet;
	std::map<std::string, std::string> skuMap;
	std::map<std::string, std::string> smallerMap;
	std::vector<std::string> attributes;
	std::vector<std::string> targets;
	std::vector<std::string> outputColumn;
	std::vector<std::string> objects;
	std::vector<std::string> attributesToPrint;
	std::pair<std::string,std::string> strippedPair;
	int sum;
	int numAttributes;
	int sumLocation = match(tokens,"∑");

	for (int m = match(tokens,"print")+1; (unsigned int)m<tokens.size() ;m++){
		attributesToPrint.push_back(tokens.at(m));
	}

	if(sumLocation == -1){
		results = fillWithUnfilteredEntries(tokens, fetchers);
	}
	else if(match(tokens,"=") == -1){
		// fetching objects
		numAttributes = tokens.size() - match(tokens,"print")-2;
		for(unsigned int i = match(tokens,"print")+1;i<tokens.size()-1; i++){
					attributes.push_back(tokens.at(i));
		}
		rawGet = fetchers.at(tokens.at(1))->getAll(attributes,tokens.at(1));
		for(std::map<std::string, std::vector<std::string> >::iterator it = rawGet.begin(); it != rawGet.end(); it++) {
			outputColumn = it->second;
			results.push_back(outputColumn);
		}
		attributes.clear();
		// fetching target list
		strippedPair = parseTableAndAttribute(tokens.at(sumLocation + 1));
		targets = getSetOfObjectNames(fetchers.at(strippedPair.first),strippedPair.first,strippedPair.second);

		outputColumn.clear();
		results.push_back(outputColumn);
		for(unsigned int j = 0; j<results.at(0).size(); j++){
			sum = 0;
			for(unsigned int k = 0; k<targets.size(); k++){
				if(results.at(0).at(j).compare(targets.at(k)) == 0){
					sum++;
				}
			}
			// converting sum to string and inserting it
			// results.at(numAttributes) is the last column, where the computed sum will be printed
			results.at(numAttributes).push_back(std::string(static_cast<std::ostringstream*>( &(std::ostringstream() << sum) )->str()));
		}
	}
	else{

		objects = getSetOfObjectNames(new DAO(tokens.at(1)), tokens.at(1), "_NAME");

		outputColumn.clear();
		for(unsigned int m = 0;m < attributesToPrint.size();m++){
			results.push_back(outputColumn);
		}

		smallerMap = createMap(fetchers, tokens.at(sumLocation + 4), tokens.at(sumLocation + 6));
		skuMap = createMap(fetchers, tokens.at(sumLocation + 2), attributesToPrint.at(0));

		// nested iteration
		for(unsigned int i = 0; i<objects.size(); i++){
			for(std::map<std::string, std::string>::iterator it = skuMap.begin(); it != skuMap.end(); it++){
				// making sure sku_object belongs in part
				if(smallerMap.find(it->first) != smallerMap.end()){
					if(results.at(0).size() > 0 && results.at(0).at(results.at(0).size() - 1).compare(it->second) == 0){
						if(objects.at(i).compare(smallerMap.find(it->first)->second) == 0){
							sum++;
						}
						results.at(2).erase(results.at(2).end() - 1);
						results.at(2).push_back(std::string(static_cast<std::ostringstream*>( &(std::ostringstream() << sum) )->str()));
					}
					else{
						sum = 0;
						results.at(0).push_back(it->second);
						results.at(1).push_back(objects.at(i));
						if(objects.at(i).compare(smallerMap.find(it->first)->second) == 0){
							sum++;
						};
						results.at(2).push_back(std::string(static_cast<std::ostringstream*>( &(std::ostringstream() << sum) )->str()));
					}
				}
			}
		}
	}
	return results;
}

std::map<std::string,DAO*> PDDLWriter::retrieveDAOs(std::vector<std::string> args, std::vector<std::string> tables){
	std::map<std::string,DAO*> daos;
	std::string stripped;
	std::string::size_type slashPose;

	for(unsigned int i = 0; i<args.size();i++){
		slashPose = args.at(i).find('/');
		if(slashPose != std::string::npos){
			stripped = args.at(i).substr(0,slashPose);
		}
		if(match(tables,args.at(i)) != -1){
			daos.insert( std::pair<std::string,DAO*>(args.at(i), new DAO(args.at(i))) );
		}
		else if(slashPose != std::string::npos && match(tables,stripped) != -1){
			if(match(tables,stripped)){
				daos.insert( std::pair<std::string,DAO*>(stripped, new DAO(stripped)) );
			}
		}
	}

	return daos;
}

std::map<std::string, std::string> PDDLWriter::createMap(std::map<std::string, DAO*> fetchers, std::string path1, std::string path2){
	std::map<std::string, std::string> myMap;
	std::map<std::string, std::vector<std::string> > rawGet;
	std::vector<std::string> attributes;
	std::vector<std::string> outputColumn;
	std::vector<std::string> resultColumn;
	std::pair<std::string,std::string> strippedPair;
	std::map<std::string, std::vector<std::string> >::iterator itex;

	strippedPair = parseTableAndAttribute(path1);
	attributes.push_back(strippedPair.second);
	strippedPair = parseTableAndAttribute(path2);
	attributes.push_back(strippedPair.second);

	rawGet = fetchers.at(strippedPair.first)->getAll(attributes,strippedPair.first);
	attributes.clear();

	itex = rawGet.begin();
	outputColumn = itex->second;
	itex++;
	resultColumn = itex->second;
	for(unsigned int m = 0; m<outputColumn.size(); m++){
		myMap.insert(std::pair<std::string,std::string>(outputColumn.at(m),resultColumn.at(m)));
	}

	return myMap;
}

std::vector<std::string> PDDLWriter::getSetOfObjectNames(DAO* relevant, std::string tableName, std::string attribute){
	std::vector<std::string> attributes;
	std::vector<std::string> outputColumn;
	std::map<std::string, std::vector<std::string> > rawGet;

	attributes.push_back(attribute);
	rawGet = relevant->getAll(attributes,tableName);
	for(std::map<std::string, std::vector<std::string> >::iterator it = rawGet.begin(); it != rawGet.end(); it++) {
		outputColumn = it->second;
	}
	return outputColumn;
}

std::string PDDLWriter::extractPredicateName(std::string input){
	std::string predicate;
	predicate = split(input, ' ').at(0);
	predicate = predicate.erase(0,1);
	return predicate;
}

/**
	 * @brief writes all the predicates related to each predicate prototype/line in input file
	 * @param outFile the problem file
	 * @param predicateName read in from the input file
	 * @param columns contains the relevant columns taken from the database, sorted and filtered
	 */
void PDDLWriter::writeGroupPredicates(std::ofstream& outFile, std::string predicateName, std::vector<std::vector<std::string> > columns){
	std::vector<std::string> first = columns.at(0);
	std::vector<std::string> args;

	for(unsigned int i = 0; i<first.size();i++){
		for(unsigned int j = 0; j<columns.size();j++){
			args.push_back(columns.at(j).at(i));
		}
		writePredicate(outFile, predicateName, args);
		args.clear();
	}
}

/**
	 * @brief writes all the functions related to each function prototype/line in input file
	 * @param outFile the problem file
	 * @param functionName read in from the input file
	 * @param columns contains the relevant columns taken from the database, sorted and filtered
	 */
void PDDLWriter::writeGroupFunctions(std::ofstream& outFile, std::string functionName, std::vector<std::vector<std::string> > columns){
	std::vector<std::string> first = columns.at(0);
	std::vector<std::string> args;
	for(unsigned int i = 0; i<first.size();i++){
			for(unsigned int j = 0; j<columns.size();j++){
				args.push_back(columns.at(j).at(i));
			}
			writeFunction(outFile, functionName, args);
			args.clear();
	}
}

/**
	 * @brief writes quieried values in correct predicate syntax
	 * @param outFile the problem file
	 * @param predicateName read in from the input file
	 * @param args the list of tokens that will follow the predicate name
	 */
void PDDLWriter::writePredicate(std::ofstream& outFile, std::string predicateName, std::vector<std::string> args){
	outFile << "\t\t(" << predicateName;
	for (unsigned int i=0;i<args.size();i++){
		outFile << " " << args[i];
	}
	outFile << ")" << std::endl;
}

/**
	 * @brief writes quieried values in correct function syntax
	 * @param outFile the problem file
	 * @param functionName read in from the input file
	 * @param args the list of tokens that will follow the function name
	 */
void PDDLWriter::writeFunction(std::ofstream& outFile, std::string functionName, std::vector<std::string> args){
	outFile << std::endl;
	outFile << "\t\t(= (" << functionName;
	for (unsigned int i=0;i<args.size()-1;i++){
		outFile << " " << args[i];
	}
	outFile << ") " << args.at(args.size() - 1) << ")";
}

std::vector<std::string> PDDLWriter::getAllTableNames(void){
	std::vector<std::string> result;

	Connection *connection = Connection::getInstance(getenv("MysqlDefaultHost"),
			 				getenv("MysqlDefaultUser"), getenv("MysqlDefaultPassword"),
			 				getenv("MysqlDefaultSchema"));

	sql::PreparedStatement *prep_stmt;
	sql::ResultSet *res;
	prep_stmt = connection->getCon()->prepareStatement("show tables");
	res = prep_stmt->executeQuery();
	std::string temp;
	while (res->next()) {
		result.push_back(res->getString(1));
	}
	return result;
}

void PDDLWriter::writeLineFromOriginalFile(std::string functionName, std::ofstream& outFile, std::ifstream& referenceFile, int detailPose){
	std::string line;
	int substrBegin;
	if(detailPose == 1) substrBegin = 1;
	else substrBegin = 3;

	referenceFile.clear();
	referenceFile.seekg(0, referenceFile.beg);
	while(std::getline(referenceFile, line)){
		if(split(line, ' ').size() > 1 && split(line, ' ').at(detailPose).size()>2 && split(line, ' ').at(detailPose).substr(substrBegin,split(line, ' ').at(detailPose).size()-substrBegin).compare(functionName) == 0){
			if(detailPose == 1){
				outFile << "\n" << line;
			}
			else{
				outFile << line << std::endl;
			}
		}
	}
}

std::pair<std::string,std::string> PDDLWriter::parseTableAndAttribute(std::string path){
	int slashPose = path.find('/');
	return std::pair<std::string,std::string>(path.substr(0,slashPose), path.substr(slashPose+1,path.size()-slashPose));
}

std::vector<std::string> PDDLWriter::split(std::string str, char c){
    std::vector<std::string> result;
    int beginningSubString = 0;
    int endSubString = 1;
    int place = 0;

    for (std::string::iterator it=str.begin(); it<=str.end(); ++it){
    	place++;
    	if (*it == c || it == str.end()){
    		endSubString = place-1;
    		result.push_back(str.substr(beginningSubString,endSubString-beginningSubString));
    		beginningSubString = place;
    	}
    }

    return result;
}

void PDDLWriter::writeVector(std::vector<std::string> args){
	for (unsigned int i = 0;i<args.size();i++){
		std::cout << args.at(i) << std::endl;
	}
}

int PDDLWriter::match(std::vector<std::string> candidates, std::string sequence){
	for (unsigned int i = 0;i<candidates.size();i++){
		if(sequence.compare(candidates.at(i)) == 0){
			return i;
		}
	}
	return -1;
}
