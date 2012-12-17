/*****************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards
   and Technology (NIST), an agency of the U.S. government, and by 
statute is
   not subject to copyright in the United States.  Recipients of this 
software
   assume all responsibility associated with its operation, modification,
   maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 *****************************************************************************/

#include "Connection.h"
	Connection* Connection::instance; 
Connection* Connection::getInstance(std::string url, std::string user, 
		std::string pass, std::string name) {
		if (!Connection::instance)
			Connection::instance = new Connection(url, user, pass, name);
		return Connection::instance;
	}
	Connection::Connection(std::string url, std::string user, std::string pass,
			std::string name) {
		try {
			driver = sql::mysql::get_mysql_driver_instance();
		} catch (sql::SQLException e) {
			std::cout << "Could not get a database driver. Error message: "
					<< e.what() << std::endl;
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
	void Connection::setDriver(sql::mysql::MySQL_Driver *driver) {
		this->driver = driver;
	}
