package ClassesCPP;

import java.util.ArrayList;

public class Connection extends ClassGenerator {

	String path;
	ArrayList<String> attributes, unit;

	public Connection(String url, String user, String pass, String name,
			String path) {
		writeHeader(
				generateHeader(this.getClass().getName(), attributes, unit),
				path);
		writeClass(generateCpp(this.getClass().getName(), attributes, unit),
				path);
	}

	public String generateHeader(String className,
			ArrayList<String> attributes, ArrayList<String> unit) {
		String header = "";
		header = header + "#include <cstdlib>"
				+ "#include \"mysql_connection.h\""
				+ "#include \"mysql_driver.h\"" + "#include <cppconn/driver.h>"
				+ "#include <cppconn/driver.h>"
				+ "#include <cppconn/exception.h>" + "#ifndef CONNEXION_H_"
				+ "#define CONNEXION_H_";

		header = header
				+ "class Connect {public:Connect(std::string url, "
				+ "std::string user, std::string pass,std::string name);"
				+ "virtual ~Connect();sql::Connection *getCon() "
				+ "const;sql::mysql::MySQL_Driver *getDriver() "
				+ "const;void setCon(sql::Connection *con);"
				+ "void setDriver(sql::mysql::MySQL_Driver *driver);"
				+ "private:sql::mysql::MySQL_Driver *driver;sql::Connection *con;"
				+ "};#endif /* CONNEXION_H_ */";

		return header;
	}

	public String generateCpp(String className, ArrayList<String> attributes,
			ArrayList<String> unit) {
		String generatedClass = "";

		generatedClass = generatedClass + "#include \"Connect.h\"";
		generatedClass = generatedClass
				+ "Connect::Connect(std::string url, "
				+ "std::string user, std::string pass,"
				+ "std::string name) {"
				+ "try {"
				+ "driver = sql::mysql::get_mysql_driver_instance();"
				+ "} catch (sql::SQLException e) {"
				+ "std::cout << \"Could not get a database driver. Error message: \""
				+ "<< e.what() << std::endl;"
				+ "exit(1);"
				+ "}"
				+ "con = driver->connect(url, user, pass);"
				+ "con->setSchema(name);"
				+ "std::cout << \"Connected to : \" << name << std::endl;"
				+ "}"
				+ "Connect::~Connect() {"
				+ "delete con;"
				+ "}"
				+ "sql::Connection *Connect::getCon() const {"
				+ "return con;"
				+ "}"
				+ "sql::mysql::MySQL_Driver *Connect::getDriver() const {"
				+ "return driver;"
				+ "}"
				+ "void Connect::setCon(sql::Connection *con) {	"
				+ "this->con = con;	"
				+ "	}"
				+ "void Connect::setDriver(sql::mysql::MySQL_Driver *driver) {	"
				+ "this->driver = driver;" + "}";
		return generatedClass;
	}

}
