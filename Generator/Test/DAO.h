
#ifndef DAO_H_
#define DAO_H_
#include <cstdlib>
#include <iostream>

#include "Connect.h"
class DAO {
private:
std::string className;
public:
 DAO(std::string classeName);
std::string getclassName();
void setclassName(std::string _className);
}; 
#endif /* DAO_H_ */