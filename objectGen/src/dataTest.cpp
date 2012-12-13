/* test of database access */
#include <string>
#include <stdio.h> // printf
#include "database/DAO.h"
#include "database/Part.h"
#include "recurseLocation.h"
#include "partModel.h"

int main(int argc, char *argv[])
{
  std::string myPart = "part_b_1";
  Part *testPart = new Part("myPart");
  RecurseLocation recurseLocation;
  PartModel partModel;
  std::string USARModel;
  std::map<std::string, std::vector<std::string> > results;
  DAO* dao = new DAO("Part");
  std::vector<std::string> attributes;

  attributes.push_back("_NAME");
  // get the name of all of the parts
  results = dao->getAll(attributes, "Part");
  for(int i=0; (int) i<results["_NAME"].size();i++)
    {
      myPart = results["_NAME"][i];
      testPart->get(myPart);
      partModel.setPart(testPart);
      USARModel = partModel.getModel();
      printf( "partid for %s is %d with serial %s and model \"%s\"\n", 
	      myPart.c_str(), testPart->getPartID(),
	      testPart->gethasPart_SerialNumber().c_str(),
	      USARModel.c_str());
      recurseLocation.recurse(testPart);
      recurseLocation.computeGlobalLoc();
      recurseLocation.printMe(0);
    }
  return 0;
}
