package ClassesCPP;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class Types extends ClassGenerator {

	public Types(String className) {
		this.className = className;
		fillUnit();
	}

	public String generateHeader(String className,
			ArrayList<String> classParentName, ArrayList<String> attributes,
			ArrayList<String> unit) {
		String result = "";
		String include = "";
		include = include + "\n#ifndef " + className.toUpperCase()
				+ "_H_\n#define " + className.toUpperCase() + "_H_\n";
		include = include + "#include <cstdlib>\n#include <iostream>\n";

		if (classParentName != null)
			for (String parent : classParentName) {
				include = include + "\n#include \"" + parent + ".h\"";
			}

		ArrayList<String> units = (ArrayList<String>) new ArrayList<String>(
				super.unit.values());

		Set<String> set = new HashSet<String>();
		set.addAll(unit);
		ArrayList<String> includeUnit = new ArrayList<String>(set);

		if (units.size() >= 0)
			for (String sunit : includeUnit)
				if (!units.contains(sunit)) {
					if (sunit.endsWith("*"))
						sunit = sunit.substring(0, sunit.length() - 1);
					include = include + "\n #include \"" + sunit + ".h\"";
				}

		include = include + "\nclass " + className;
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
		pub = pub + "\n" + className + "(std::string name);";
		pub = pub + "\n void get(int id);";
		pub = pub + "\n void get(std::string name);";
		pub = pub + "\nvoid set(int id, " + className + "* obj);";
		pub = pub + "\nvoid set(std::string name, " + className + "* obj);";
		for (int i = 0; i < attributes.size(); i++) {
			pub = pub + "\n" + unit.get(i) + " get" + attributes.get(i) + "();";
			if (!attributes.get(i).endsWith("[]"))
				pub = pub + "\nvoid set" + attributes.get(i) + "("
						+ unit.get(i) + " _" + attributes.get(i) + ");";
			else
				pub = pub
						+ "\nvoid set"
						+ attributes.get(i).substring(0,
								attributes.get(i).length() - 2) + "("
						+ unit.get(i) + " _" + attributes.get(i) + ");";

		}
		pub = pub + "\nvoid copy(" + className + " const& object);";

		pub = pub + "\n}; \n#endif /* " + className.toUpperCase() + "_H_ */";

		if (classParentName != null)
			for (int i = 0; i < classParentName.size(); i++) {
				if (i == 0)
					include = include + ": public " + classParentName.get(i);
				else
					include = include + ", public " + classParentName.get(i);

			}

		include = include + " {";
		result = result + include + priv + pub;

		return result;
	}

	public String generateCpp(String className,
			ArrayList<String> classParentName, ArrayList<String> attributes,
			ArrayList<String> unit) {
		String result = "";
		String include = "#include \"" + className + ".h\"\n\n";

		String constructor = className + "::" + className;
		String paramConstruct = "(std::string name)";

		if (classParentName != null)
			for (int i = 0; i < classParentName.size(); i++) {
				if (i == 0)
					paramConstruct = paramConstruct + " : "
							+ classParentName.get(i) + "(name)";
				else
					paramConstruct = paramConstruct + " , "
							+ classParentName.get(i) + "(name)";

			}

		paramConstruct = paramConstruct
				+ "{\nthis->name=name;\nthis->get(this->name);\n}";

		String get = "";
		for (int i = 0; i < attributes.size(); i++) {
			get = get + unit.get(i) + " " + className + "::get"
					+ attributes.get(i) + "(){\n";
			get = get + "return this->" + attributes.get(i) + ";\n}\n";
		}
		String set = "";
		for (int i = 0; i < attributes.size(); i++) {
			if (!attributes.get(i).endsWith("[]"))
				set = set + "void " + className + "::set" + attributes.get(i)
						+ "(" + unit.get(i) + " _" + attributes.get(i) + "){\n";
			else
				set = set
						+ "void "
						+ className
						+ "::set"
						+ attributes.get(i).substring(0,
								attributes.get(i).length() - 2) + "("
						+ unit.get(i) + " _" + attributes.get(i) + "){\n";

			set = set + "this->" + attributes.get(i) + "= _"
					+ attributes.get(i) + ";\n}\n";
		}
		String globalGet = "void " + className + "::get(std::string name){";
		globalGet = globalGet + "\n *dao  = DAO(\"" + className + "\");";
		globalGet = globalGet + "\n const " + className
				+ " temp = dao->get(name);";
		globalGet = globalGet + "\n copy(temp);\n}";

		String globalSet = " void " + className + "::set(std::string name, "
				+ className + "* obj){";
		globalSet = globalSet + "\n *dao  = DAO(\"" + className + "\");";
		globalSet = globalSet + "\n dao->set(name, obj);\n}";

		String copy = "";
		copy = copy + "\nvoid " + className + "::copy(" + className
				+ " const& object){";
		copy = copy + "\n if(this != &object){";
		for (int i = 0; i < attributes.size(); i++) {
			copy = copy + "\n" + attributes.get(i) + " = object."
					+ attributes.get(i) + ";";
		}
		copy = copy + "\n}\n}";

		result = result + include + constructor + paramConstruct + get + set
				+ globalGet + globalSet + copy;
		return result;
	}
}
