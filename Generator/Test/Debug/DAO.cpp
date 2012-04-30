#include "DAO.h"

DAO::DAO(std::string name){
this->className=className;
}std::string DAO::getclassName(){
return this->className;
}
void DAO::setclassName(std::string _className){
this->className= _className;
}
