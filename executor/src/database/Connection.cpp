#include "Connection.h"
Connection::Connection(std::string url, std::string user, std::string pass,std::string name) {
try {
driver = sql::mysql::get_mysql_driver_instance();
} catch (sql::SQLException e) {
std::cout << "Could not get a database driver. Error message: "<< e.what() << std::endl;
exit(1);
}
con = driver->connect(url, user, pass);
con->setSchema(name);
//std::cout << "Connected to : " << name << std::endl;
}
Connection::~Connection() {
delete con;
}
sql::Connection *Connection::getCon() const {
return con;
}
sql::mysql::MySQL_Driver *Connection::getDriver() const {
return driver;
}
void Connection::setCon(sql::Connection *con) {	
this->con = con;	
	}
void Connection::setDriver(sql::mysql::MySQL_Driver *driver) 
{	this->driver = driver;

}
