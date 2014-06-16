#include "PDDLWriter.h"

int main(int argc, char* argv[]) {

	PDDLWriter* myWriter = new PDDLWriter();

	if(argc > 4 || argc < 3){
		std::cout << "Incorrect invocation. Input parameters are: mapping_file old_problem_file new_problem_file" << std::endl;
	}

	std::ifstream mappingText;
	std::ifstream oldProblemFile;
	std::ofstream problemFile;

	mappingText.open(argv[1]);
	oldProblemFile.open(argv[2]);
	problemFile.open(argv[3]);

	if (!mappingText.is_open() || !oldProblemFile.is_open()){
		std::cout << "Could not open input file! Exiting" << std::endl;
		exit(0);
	}
	problemFile.clear();

	myWriter->writeObjectSection(problemFile, oldProblemFile);
	myWriter->parseAndWriteInit(problemFile, oldProblemFile, mappingText);
	myWriter->writeGoalSection(problemFile, oldProblemFile);

	mappingText.close();
	problemFile.close();

	return 0;
}
