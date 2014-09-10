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
 * \file      ClassGenerator.java
 * \author    Anthony Pietromartire \a pietromartire.anthony\@nist.gov
 * \version   1.0
 * \date      29 June 2012
 * \brief     Abstract Class implemented for generating the C++ files.
 */

/**
 * \class ClassesCPP.ClassGenerator
 * \brief Abstract Class implemented for generating the C++ files.
 * \details   This class contain the methods to write the files on the disk 
 * 			and make the correspondence between the units from the DB and the C++ ones  
 */

package ClassesCPP;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashMap;

public abstract class ClassGenerator {

	/**
	 * \brief name of the generated class.
	 */
	protected String className = "";
	/**
	 * \brief Mapping between SQL units and C++ units.
	 */
	protected HashMap<String, String> unit = new HashMap<String, String>();

	/**
	 * \brief Give the unit in C++ corresponding to a type from the DB \param s
	 * Name of the DB unit. \return A String with C++ type corresponding
	 */
	public String getUnit(String s) {
		if (unit.containsKey(s))
			return unit.get(s);
		else
			return "std::string";
	}

	/**
	 * \brief Initialize the map with the correspondances between DB unit and
	 * C++ ones
	 */
	protected void fillUnit() {
		unit.put("TINYINT(1)", "bool");
		unit.put("boolean", "bool");
		unit.put("TINYINT", "char");
		unit.put("TINYINT UNSIGNED", "unsigned char");
		unit.put("SMALLINT", "short");
		unit.put("SMALLINT UNSIGNED", "unsigned short");
		unit.put("INT", "int");
		unit.put("INT UNSIGNED", "unsigned int");
		unit.put("BIGINT", "long");
		unit.put("BIGINT UNSIGNED", "unsigned long");
		unit.put("FLOAT", "float");
		unit.put("DOUBLE", "double");
		unit.put("DOUBLE PRECISION", "double");
		unit.put("DECIMAL", "float");
		unit.put("TEXT", "std::string");
		unit.put("varchar", "std::string");
		unit.put("DATE", "gregorian::date");
		unit.put("DATETIME", "posix_time::ptime");
		unit.put("TIME", "posix_time::time_duration");
	}

	/**
	 * \brief Skeleton of the C++ method to generate the header file for a given
	 * type \param className Name of the class. \param classParentName List of
	 * the super classes. \param attributes List of the attributes. \param unit
	 * List of the units of the attributes. \return null because not implemented
	 */
	protected String generateHeader(String className,
			ArrayList<String> classParentName, ArrayList<String> attributes,
			ArrayList<String> unit) {
		return null;
	}

	/**
	 * \brief Skeleton of the C++ method to generate the C++ file for a given
	 * type \param className Name of the class. \param classParentName List of
	 * the super classes. \param attributes List of the attributes. \param unit
	 * List of the units of the attributes. \return null because not implemented
	 */
	protected String generateCpp(String className,
			ArrayList<String> classParentName, ArrayList<String> attributes,
			ArrayList<String> unit) {
		return null;
	}

	/**
	 * \brief Write the header file on the Disk. \param data Data you want to
	 * write. \param path Path of your file
	 */
	public void writeHeader(String data, String path) {
		Writer fstream;
		try {
			fstream = new FileWriter(path + className + ".h");
			BufferedWriter out = new BufferedWriter(fstream);
			out.write(data);
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	/**
	 * \brief Write the C++ file on the Disk. \param data Data you want to
	 * write. \param path Path of your file
	 */
	public void writeClass(String data, String path) {
		Writer fstream;
		try {
			fstream = new FileWriter(path + className + ".cpp");
			BufferedWriter out = new BufferedWriter(fstream);
			out.write(data);
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
