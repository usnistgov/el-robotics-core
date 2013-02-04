/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I.
*****************************************************************************/

/*! \mainpage Plan generator
 * This file builds a plan file by permuting the order of parts handling (take and place) by the robot. For instance, if 3 parts have to be in the final kit, the generator builds 3! files 
 * where the order of placing the parts in the kit is different in each file.
 */

using namespace std;
#include <iostream>
#include <string>
#include <string.h>
#include <dirent.h>
#include <vector>
#include <sstream> // to concatenate strings
#include <fstream>
#include<sys/stat.h>
#include <stdlib.h>
#include<sys/types.h>
//int array[10] = {0,1,2,3,4,5,6,7,8,9};

const char * directory;
int factorial;
string robot;
string parttray;
string traygripper;
string traygripperholder;
string partgripper;
string partgripperholder;
string worktable;
string kittray;
string lbwekt;
string lbwk;
string kit;
vector<string> v1;
string header, footer;
//string parts[] = { "part_a_1", "part_a_2" };
vector<string> partVector;
int count = 0;

/*!
@brief Check if a directory exists
@param path Path of the directory
@return true if the directory exists, false otherwise
*/
bool directoryExists(const char* path) {
	if (path == NULL)
		return false;

	DIR *pDir;
	bool bExists = false;

	pDir = opendir(path);

	if (pDir != NULL) {
		bExists = true;
		(void) closedir(pDir);
	}

	return bExists;
}

/*!
@brief Build the first section of a PDDL plan file.
The first section is common to all plan files and consists of the following PDDL actions:
\li \c attach-eff Attach the tray gripper to the robot
\li \c take-kit-tray Take the kit tray from the box of empty kit trays
\li \c put-kit-tray Put the kit tray on the work table
\li \c create-kit Create a kit from the kit tray on the work table
\li \c remove-eff Remove the current end effector
\li \c attach-eff Attach the end effector that can handle parts
@return A string that contains all the elements of this first section.
*/
string buildHeader() {
	std::stringstream ss;
	ss << "(attach-eff " << robot << " " << traygripper << " "
			<< traygripperholder << ")\n" << "(take-kit-tray " << robot << " "
			<< kittray << " " << lbwekt << " " << traygripper << " "
			<< worktable << ")\n" << "(put-kit-tray " << robot << " "
			<< kittray << " " << worktable << ")\n" << "(create-kit " << kit
			<< " " << kittray << " " << worktable << ")\n" << "(remove-eff "
			<< robot << " " << traygripper << " " << traygripperholder << ")\n"
			<< "(attach-eff " << robot << " " << partgripper << " "
			<< partgripperholder << ")\n";

	header = ss.str();
	return header;
}

/*!
@brief Build the last section of a PDDL plan file.
The last part for all plan files for kitting is the same. This function builds this section and returns the result in a string.
@return The built section.
*/
string buildFooter() {
	std::stringstream ss;
	ss << "(remove-eff " << robot << " " << partgripper << " "
			<< partgripperholder << ")\n" << "(attach-eff " << robot << " "
			<< traygripper << " " << traygripperholder << ")\n" << "(take-kit "
			<< robot << " " << kit << " " << worktable << " " << traygripper
			<< ")\n" << "(put-kit " << robot << " " << kit
			<< " " << lbwk << ")";

	footer = ss.str();
	//cout << footer << endl;
	return footer;
}

/*!
@brief Swap two elements
@param x First element
@param y Second element
*/
void swap(int x, int y) {
	string temp = partVector[x];
	partVector[x] = partVector[y];
	partVector[y] = temp;
}

/*!
 @brief Read and display elements of a vector
 @param myVector The vector to read
 */
void readVector(vector<string> myVector) {
	int vectLength;
	vectLength = (int) myVector.size();

	for (vector<string>::size_type i = 0; i < vectLength; i++)
		cout << myVector[i] << " ";
	cout << endl;
}

void printArray(int size) {
	int i;

	for (i = 0; i < size; i++)
		std::cout << partVector[i] << " ";
	std::cout << std::endl;
}

string buildPlan(string core) {
	string header, footer, plan;
	std::stringstream plan_ss;

	header = buildHeader();
	footer = buildFooter();

	plan_ss << header << core << footer;
	plan = plan_ss.str();

	// cout << plan << "\n\n";

	return plan;
}

string getsubstring(string s) {
	size_t pos;
	string s1;
	pos = s.find("_"); // position of "_" in str
	s1 = s.substr(pos + 1); // get from "_" to the end
	return s1;
}

string removecharacter(string s, string character) {
	size_t pos;
	string s1, s2, s3;
	std::stringstream s3_ss;
	pos = s.find(character); // position of a character in str
	//cout << "position: "<< pos<<endl;
	s1 = s.substr(0, pos); // get the substring before "character"
	s2 = s.substr(pos + 1); // get from "character" to the end
	s3_ss << s1 << s2;
	s3 = s3_ss.str();

	return s3;
}

void writeOutput(string core, string title) {
	string plan, filename_s, directory_s, path_s;
	char* filename;
	ofstream output;
	std::stringstream filename_ss, directory_ss, path_ss;

	plan = buildPlan(core);
	filename_ss << title << ".txt";
	//directory_ss << directory;

	//filename_s=filename_ss.str();
	//directory_s=directory_ss.str();
	//path_ss << directory_s<<"/"<<filename_s;
	//path_s=path_ss.str();

	
	//-- Problem here
	//cout << "Filename: " << filename_ss.str().c_str() << endl;
	//strcpy(filename, filename_ss.str().c_str());
	
	//filename=path_s.c_str();
	ofstream outputFile;
	outputFile.open(filename_ss.str().c_str(), ios::out | ios::app);
	outputFile << plan;
	outputFile.close();
}

void buildCorePlan(vector<string> myVector) {
	int vectLength;
	vectLength = (int) myVector.size();
	string takepart, putpart, core, title, finaltitle;
	std::stringstream core_ss;
	string partname;
	std::stringstream title_ss, finaltitle_ss;

	for (vector<string>::size_type i = 0; i < vectLength; i++) {
		std::stringstream takepart_ss;
		std::stringstream putpart_ss;

		partname = getsubstring(myVector[i]); // e.g., read part_a_1 and return a_1

		//cout <<myVector[i]<< " ";
		title_ss << removecharacter(partname, "_");
		if (std::string::npos != myVector[i].find("part_a"))
			parttray = "part_a_tray";
		else if (std::string::npos != myVector[i].find("part_b"))
			parttray = "part_b_tray";
		else if (std::string::npos != myVector[i].find("part_c"))
			parttray = "part_c_tray";

		takepart_ss << "(take-part " << robot << " " << myVector[i] << " "
				<< parttray << " " << partgripper << " " << worktable << " "
				<< kit << ")\n";
		takepart = takepart_ss.str();

		putpart_ss << "(put-part " << robot << " " << myVector[i] << " " << kit
				<< " " << worktable << ")\n";
		putpart = putpart_ss.str();

		core_ss << takepart << putpart;
		title = title_ss.str();

	}
	finaltitle_ss << kit << "-" << title;
	finaltitle = finaltitle_ss.str();
	//cout << "Title: " << finaltitle << endl;

	//cout<< "\n\n";
	core = core_ss.str();
	writeOutput(core, finaltitle);
	//buildPlan(core);
}


void buildVectorPart(int size) {
	for (vector<string>::size_type i = 0; i < size; i++)
		v1.push_back(partVector[i]);

	buildCorePlan(v1);
	v1.clear();
}

/*!
 @brief Generate all the possible permutations of a set
 @param k Number of elements to be permutated
 @param size Size of the permutation
 */
void permute(int k, int size, int numberOfFile) {
	if (k == 0)
	{
		count ++;
		buildVectorPart(size);

		if (count==numberOfFile)
			exit(0);
	}
	
	else {
		for (int i = k - 1; i >= 0; i--) {
			swap(i, k - 1);
			permute(k - 1, size, numberOfFile);
			swap(i, k - 1);
		}
	}
	//printArray(size);

}

int fact(int n) {
	for (int i = 0; i <= n; i++)
		if (i == 0)
			factorial = 1;
		else
			factorial = factorial * i;

	return factorial;
}

int main(int argc, char *argv[]) {
	std::stringstream kit_ss, path_ss;
	string path;
	int partVectorSize;
	int size;
	robot = "robot_1";
	traygripper = "tray_gripper";
	traygripperholder = "tray_gripper_holder";
	partgripper = "part_gripper";
	partgripperholder = "part_gripper_holder";
	worktable = "work_table_1";
	lbwekt = "empty_kit_tray_supply_ir";
	lbwk = "finished_kit_receiver_ir";
	
	//-- Change this number to generate numberOfFile files.
	int numberOfFile = 20;

	int kit_number=5;

	if (kit_number==1)
	{
	kit = "kit_a4b3c3";
	kittray = "kit_tray_1_ir";
	partVector.push_back("part_a_1_ir");
	partVector.push_back("part_a_2_ir");
	partVector.push_back("part_a_3_ir");
	partVector.push_back("part_a_4_ir");
	partVector.push_back("part_b_1_ir");
	partVector.push_back("part_b_2_ir");
	partVector.push_back("part_b_3_ir");
	partVector.push_back("part_c_1_ir");
	partVector.push_back("part_c_2_ir");
	partVector.push_back("part_c_3_ir");
	size=10;
	partVectorSize = partVector.size();
	permute(10,size,numberOfFile);	
	}
	else if (kit_number==2)
	{
	count = 0;
	kit = "kit_a4b4c2";
	kittray = "kit_tray_2_ir";
	partVector.push_back("part_a_1_ir");
	partVector.push_back("part_a_2_ir");
	partVector.push_back("part_a_3_ir");
	partVector.push_back("part_a_4_ir");
	partVector.push_back("part_b_1_ir");
	partVector.push_back("part_b_2_ir");
	partVector.push_back("part_b_3_ir");
	partVector.push_back("part_b_4_ir");
	partVector.push_back("part_c_1_ir");
	partVector.push_back("part_c_2_ir");
	partVectorSize = partVector.size();
	size=10;
	permute(10,size,numberOfFile);
	
	}
	else if (kit_number==3)
	{
	count = 0;
	size=10;
	kit = "kit_a2b3c5";
	kittray = "kit_tray_3_ir";
	partVector.push_back("part_a_1_ir");
	partVector.push_back("part_a_2_ir");
	partVector.push_back("part_b_1_ir");
	partVector.push_back("part_b_2_ir");
	partVector.push_back("part_b_3_ir");
	partVector.push_back("part_c_1_ir");
	partVector.push_back("part_c_2_ir");
	partVector.push_back("part_c_3_ir");
	partVector.push_back("part_c_4_ir");
	partVector.push_back("part_c_5_ir");
	partVectorSize = partVector.size();
	permute(10,size,numberOfFile);
	}
	else if (kit_number==4)
	{
	count = 0;
	size=10;
	kit = "kit_a4b3c2d1";
	kittray = "kit_tray_4_ir";
	partVector.push_back("part_a_1_ir");
	partVector.push_back("part_a_2_ir");
	partVector.push_back("part_a_3_ir");
	partVector.push_back("part_a_4_ir");
	partVector.push_back("part_b_1_ir");
	partVector.push_back("part_b_2_ir");
	partVector.push_back("part_b_3_ir");
	partVector.push_back("part_c_1_ir");
	partVector.push_back("part_c_2_ir");
	partVector.push_back("part_d_1_ir");
	partVectorSize = partVector.size();
	permute(10,size,numberOfFile);
	}
	else if(kit_number==5)
	{
	count = 0;
	size=10;
	kit = "kit_a2b3c3d1e1";
	kittray = "kit_tray_5_ir";
	partVector.push_back("part_a_1_ir");
	partVector.push_back("part_a_2_ir");
	partVector.push_back("part_b_1_ir");
	partVector.push_back("part_b_2_ir");
	partVector.push_back("part_b_3_ir");
	partVector.push_back("part_c_1_ir");
	partVector.push_back("part_c_2_ir");
	partVector.push_back("part_c_3_ir");
	partVector.push_back("part_d_1_ir");
	partVector.push_back("part_e_1_ir");
	partVectorSize = partVector.size();
	permute(10,size,numberOfFile);
	}
	return 0;
	
	
}
