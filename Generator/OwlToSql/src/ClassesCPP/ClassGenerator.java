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

package ClassesCPP;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashMap;

public abstract class ClassGenerator {

	String className = "";
	protected HashMap<String, String> unit = new HashMap<String, String>();

	public String getUnit(String s) {
		if (unit.containsKey(s))
			return unit.get(s);
		else
			return "std::string";
	}

	public void fillUnit() {
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

	public String generateHeader(String className,
			ArrayList<String> classParentName, ArrayList<String> attributes,
			ArrayList<String> unit) {
		return null;
	}

	public String generateCpp(String className,
			ArrayList<String> classParentName, ArrayList<String> attributes,
			ArrayList<String> unit) {
		return null;
	}

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
