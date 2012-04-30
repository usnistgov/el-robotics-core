#include "Connect.h"

Connect::Connect(std::string url, std::string user, std::string pass,
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
	std::cout << "Connected to : " << name << std::endl;
}

Connect::~Connect() {
	delete con;
}
sql::Connection *Connect::getCon() const {
	return con;
}
sql::mysql::MySQL_Driver *Connect::getDriver() const {
	return driver;
}
void Connect::setCon(sql::Connection *con) {
	this->con = con;
}
void Connect::setDriver(sql::mysql::MySQL_Driver *driver) {
	this->driver = driver;
}

int main() {
	Connect c("localhost", "root", "mypassword", "owl");
	return 0;
}
