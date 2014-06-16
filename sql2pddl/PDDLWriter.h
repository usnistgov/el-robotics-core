/**
 * @brief Worker class that generates problem file
 * @author Christopher Lawler
 * @version 1.0
 * @date 3 Jun 2014
 */
#ifndef PDDLWRITER_H_
#define PDDLWRITER_H_

#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <climits>
#include "../AutoGen/database/DAO.h"

/**
 * @class PDDLWriter
 */
class PDDLWriter {
public:
	PDDLWriter();
	virtual ~PDDLWriter();
	void writeObjectSection(std::ofstream&, std::ifstream&);
	void writeGoalSection(std::ofstream&, std::ifstream&);
	void writePredicate(std::ofstream&, std::string, std::vector<std::string>);
	void writeFunction(std::ofstream&, std::string, std::vector<std::string>);
	void writeGroupPredicates(std::ofstream&, std::string, std::vector<std::vector<std::string> >);
	void writeGroupFunctions(std::ofstream&, std::string, std::vector<std::vector<std::string> >);
	void parseAndWriteInit(std::ofstream&, std::ifstream&, std::ifstream&);

private:
	void writeVector(std::vector<std::string>);
	std::vector<std::string> split(std::string, char);
	int match(std::vector<std::string>, std::string);
	std::pair<std::string,std::string> parseTableAndAttribute(std::string);
	std::vector<std::string> getAllTableNames(void);
	std::vector<std::string> getSetOfObjectNames(DAO*, std::string, std::string);
	std::map<std::string, std::string> createMap(std::map<std::string, DAO*>, std::string, std::string);
	std::string extractPredicateName(std::string);
	std::vector<std::vector<std::string> > parseAndFetchPredicateData(std::string,std::vector<std::string>);
	std::vector<std::vector<std::string> > parseAndFetchFunctionData(std::string,std::vector<std::string>);
	std::map<std::string,DAO*> retrieveDAOs( std::vector<std::string>, std::vector<std::string>);
	std::vector<std::vector<std::string> > fillWithUnfilteredEntries(std::vector<std::string>, std::map<std::string,DAO*>);
	std::vector<std::vector<std::string> > filterTable(std::vector<std::string>, std::vector<std::vector<std::string> >,unsigned int, unsigned int, std::map<std::string,DAO*>);
	std::vector<std::vector<std::string> > evaluateFunctions(std::vector<std::string>, std::map<std::string,DAO*>);
	void writeLineFromOriginalFile(std::string, std::ofstream&, std::ifstream&, int);

};

#endif /* PDDLWRITER_H_ */
