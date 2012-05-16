
#ifndef DAO_H_
#define DAO_H_
#include <cstdlib>
#include <iostream>

#include "Connection.h"
 class IObject{
};
class DAO {
private:
std::string className;
public:
 DAO(std::string classeName);
std::string getclassName();
void setclassName(std::string _className);
IObject* get(std::string name);
void set(std::string name, IObject obj);
}; 
#endif /* DAO_H_ */