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

/**
 * \file      Connection.java
 * \author    Anthony Pietromartire \a pietromartire.anthony\@nist.gov
 * \version   1.0
 * \date      29 June 2012
 * \brief     Class for the connection to the DB.
 */

/**
 * \class ClassesCPP.Connection
 * \brief Class for the connection to the DB.
 * \details   This class is used to generate the C++ specific file used to create the connection with the DB.
 */

package ClassesCPP;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class Connection {

	/**
	 * \brief      Where we are going to save the file.
	 */
	private String path;

	/**
     *  \brief Constructor
     *  \details Constructor of the Connection class.
     *  \param path 	path of the file.
     */
	public Connection(String path) {

		this.setPath(path);

		writeHeader(generateHeader(), path);
		writeClass(generateCpp(), path);
	}

	/**
	 * \brief      Generate the header file for the connection with the DB.
	 */
	public String generateHeader() {
		String header = "";
		header = header
				+ "/*****************************************************************************\n";
		header = header + "   DISCLAIMER:\n";
		header = header
				+ "   This software was produced by the National Institute of Standards\n";
		header = header
				+ "   and Technology (NIST), an agency of the U.S. government, and by \n";
		header = header + "statute is\n";
		header = header
				+ "   not subject to copyright in the United States.  Recipients of this \n\n";
		header = header + "software\n";
		header = header
				+ "   assume all responsibility associated with its operation, modification,\n";
		header = header + "   maintenance, and subsequent redistribution.\n";
		header = header + "\n";
		header = header
				+ "   See NIST Administration Manual 4.09.07 b and Appendix I.\n";
		header = header
				+ " *****************************************************************************/\n\n";
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

	/**
	 * \brief      Generate the C++ file for the connection with the DB.
	 */
	public String generateCpp() {
		String generatedClass = "";
		generatedClass = generatedClass
				+ "/*****************************************************************************\n";
		generatedClass = generatedClass + "   DISCLAIMER:\n";
		generatedClass = generatedClass
				+ "   This software was produced by the National Institute of Standards\n";
		generatedClass = generatedClass
				+ "   and Technology (NIST), an agency of the U.S. government, and by \n";
		generatedClass = generatedClass + "statute is\n";
		generatedClass = generatedClass
				+ "   not subject to copyright in the United States.  Recipients of this \n";
		generatedClass = generatedClass + "software\n";
		generatedClass = generatedClass
				+ "   assume all responsibility associated with its operation, modification,\n";
		generatedClass = generatedClass
				+ "   maintenance, and subsequent redistribution.\n";
		generatedClass = generatedClass + "\n";
		generatedClass = generatedClass
				+ "   See NIST Administration Manual 4.09.07 b and Appendix I.\n";
		generatedClass = generatedClass
				+ " *****************************************************************************/\n\n";

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

	/**
	 * \brief      Write the header file on the Disk.
	 * \param    data		   	Data you want to write.
	 * \param    path			Path of your file
	 */
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

	/**
	 * \brief      Write the C++ file on the Disk.
	 * \param    data		   	Data you want to write.
	 * \param    path			Path of your file
	 */
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

	public String getPath() {
		return path;
	}

	public void setPath(String path) {
		this.path = path;
	}

}
