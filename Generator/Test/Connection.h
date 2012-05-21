#ifndef CONNEXION_H_
#define CONNEXION_H_
#include <cstdlib>
#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset_metadata.h>
class Connection {
public:
Connection(std::string url, std::string user, std::string pass,std::string name);
virtual ~Connection();
sql::Connection *getCon() const;
sql::mysql::MySQL_Driver *getDriver() const;
void setCon(sql::Connection *con);
void setDriver(sql::mysql::MySQL_Driver *driver);
private:sql::mysql::MySQL_Driver *driver;sql::Connection *con;
};
#endif /* CONNEXION_H_ */