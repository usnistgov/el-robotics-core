package ClassesCPP;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class daoGenerator {
	public String generateHeader(ArrayList<String> className,
			ArrayList<String> attributes, ArrayList<String> unit) {
		String result = "";
		String include = "";
		include = include + "\n#ifndef DAO_H_\n#define DAO_H_\n";
		include = include + "#include <cstdlib>\n#include <iostream>\n";
		for (String classname : className) {
			include = include + "\n#include \"" + classname + ".h\"";
		}

		include = include + "\nclass DAO {\n";

		String priv = "private:\n";
		String paramConstruct = "";
		for (int i = 0; i < attributes.size(); i++) {
			priv = priv + unit.get(i) + " " + attributes.get(i) + ";\n";
			if (i < attributes.size() - 1)
				paramConstruct = paramConstruct + unit.get(i) + " "
						+ attributes.get(i) + ",";
			else
				paramConstruct = paramConstruct + unit.get(i) + " "
						+ attributes.get(i);
		}
		String pub = "public:";
		pub = pub + "\n DAO(std::string classeName);";
		for (int i = 0; i < attributes.size(); i++) {
			pub = pub + "\n" + unit.get(i) + " get" + attributes.get(i) + "();";
			pub = pub + "\nvoid set" + attributes.get(i) + "(" + unit.get(i)
					+ " _" + attributes.get(i) + ");";

		}

		pub = pub + "\n}; \n#endif /* DAO_H_ */";

		result = include + priv + pub;

		return result;
	}

	public String generateCpp(ArrayList<String> className,
			ArrayList<String> attributes, ArrayList<String> unit) {
		String result = "";
		String include = "#include \"DAO.h\"\n\n";

		String constructor = "DAO::DAO";
		String paramConstruct = "(std::string name)";

		paramConstruct = paramConstruct + "{\nthis->className=className;\n}";

		String get = "";
		for (int i = 0; i < attributes.size(); i++) {
			get = get + unit.get(i) + " DAO::get"
					+ attributes.get(i) + "(){\n";
			get = get + "return this->" + attributes.get(i) + ";\n}\n";
		}
		String set = "";
		for (int i = 0; i < attributes.size(); i++) {
			set = set + "void DAO::set" + attributes.get(i) + "("
					+ unit.get(i) + " _" + attributes.get(i) + "){\n";
			set = set + "this->" + attributes.get(i) + "= _"
					+ attributes.get(i) + ";\n}\n";
		}

		result = result + include + constructor + paramConstruct + get + set;
		return result;
	}

	public void writeHeader(String data, String path) {
		Writer fstream;
		try {
			fstream = new FileWriter(path + "DAO.h");
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
			fstream = new FileWriter(path + "DAO.cpp");
			BufferedWriter out = new BufferedWriter(fstream);
			out.write(data);
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
