package ClassesCPP;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class Connection {

	String path;

	public Connection(String path) {

		this.path = path;

		writeHeader(generateHeader(), path);
		writeClass(generateCpp(), path);
	}

	public String generateHeader() {
		String header = "";
		header = header + "#ifndef CONNEXION_H_\n" + "#define CONNEXION_H_\n"
				+ "#include <cstdlib>\n" + "#include \"mysql_connection.h\"\n"
				+ "#include \"mysql_driver.h\"\n"
				+ "#include <cppconn/driver.h>\n"
				+ "#include <cppconn/driver.h>\n"
				+ "#include <cppconn/exception.h>\n"
				+ "#include <cppconn/resultset.h>\n"
				+ "#include <cppconn/statement.h>\n"
				+ "#include <cppconn/prepared_statement.h>\n"
				+ "#include <cppconn/resultset_metadata.h>\n";
		

		header = header
				+ "class Connection {\n"
				+ "public:\n"
				+ "Connection(std::string url, "
				+ "std::string user, std::string pass,std::string name);\n"
				+ "virtual ~Connection();\n"
				+ "sql::Connection *getCon() const;\n"
				+ "sql::mysql::MySQL_Driver *getDriver() const;\nvoid setCon(sql::Connection *con);\n"
				+ "void setDriver(sql::mysql::MySQL_Driver *driver);\n"
				+ "private:sql::mysql::MySQL_Driver *driver;"
				+ "sql::Connection *con;\n};\n#endif /* CONNEXION_H_ */";

		return header;
	}

	public String generateCpp() {
		String generatedClass = "";

		generatedClass = generatedClass + "#include \"Connection.h\"\n";
		generatedClass = generatedClass
				+ "Connection::Connection(std::string url, "
				+ "std::string user, std::string pass,"
				+ "std::string name) {\n"
				+ "try {\n"
				+ "driver = sql::mysql::get_mysql_driver_instance();"
				+ "\n} catch (sql::SQLException e) {\n"
				+ "std::cout << \"Could not get a database driver. Error message: \""
				+ "<< e.what() << std::endl;\n"
				+ "exit(1);\n"
				+ "}\n"
				+ "con = driver->connect(url, user, pass);\n"
				+ "con->setSchema(name);\n"
				+ "std::cout << \"Connected to : \" << name << std::endl;\n"
				+ "}\n"
				+ "Connection::~Connection() {\n"
				+ "delete con;\n"
				+ "}\n"
				+ "sql::Connection *Connection::getCon() const {\n"
				+ "return con;\n"
				+ "}\n"
				+ "sql::mysql::MySQL_Driver *Connection::getDriver() const {\n"
				+ "return driver;\n"
				+ "}\n"
				+ "void Connection::setCon(sql::Connection *con) {	\n"
				+ "this->con = con;	\n"
				+ "	}\n"
				+ "void Connection::setDriver(sql::mysql::MySQL_Driver *driver) \n{	"
				+ "this->driver = driver;\n" + "\n}";
		return generatedClass;
	}

	public void writeHeader(String data, String path) {
		Writer fstream;
		try {
			fstream = new FileWriter(path + this.getClass().getSimpleName()
					+ ".h");
			BufferedWriter out = new BufferedWriter(fstream);
			out.write(data);
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	public void writeClass(String data, String path) {
		Writer fstream;
		try {
			fstream = new FileWriter(path + this.getClass().getSimpleName()
					+ ".cpp");
			BufferedWriter out = new BufferedWriter(fstream);
			out.write(data);
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
