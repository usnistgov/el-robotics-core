#include <cstdlib>
#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#ifndef CONNEXION_H_
#define CONNEXION_H_
class Connect {
public:
Connect(std::string url, std::string user, std::string pass,std::string name);
virtual ~Connect();
sql::Connection *getCon() const;
sql::mysql::MySQL_Driver *getDriver() const;void setCon(sql::Connection *con);
void setDriver(sql::mysql::MySQL_Driver *driver);
private:sql::mysql::MySQL_Driver *driver;sql::Connection *con;

};#endif /* CONNEXION_H_ */