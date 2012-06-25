package ClassesCPP;

import java.util.ArrayList;
import java.util.HashMap;
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

		include = include + "#include <map>\n";
		include = include + "#include <string>\n";
		include = include + "#include <vector>\n";
		include = include + "#include <sstream>\n";

		include = include + "\n";

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
			for (String sunit : includeUnit) {
				if (sunit.contains("std::")) {
					if (sunit.contains("<")) {
						if (!sunit.contains("<std::")) {
							// vector of objects
							String s = sunit.substring(sunit.indexOf("<") + 1,
									sunit.indexOf(">") - 1);
							if (!include.contains("class " + s))
								include = include + "\n class " + s + ";";

						}
					}
				} else if (!units.contains(sunit)) {
					// Class simple
					if (sunit.endsWith("*"))
						sunit = sunit.substring(0, sunit.length() - 1);
					if (!include.contains("class " + sunit))
						include = include + "\n class " + sunit + ";";
				}
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
		pub = pub + "\n~" + className + "();";
		pub = pub + "\n void get(int id);";
		pub = pub + "\n void get(std::string name);";
		pub = pub + "\nvoid set(int id, " + className + "* obj);";
		pub = pub + "\nvoid set(std::string name);";
		for (int i = 0; i < attributes.size(); i++) {
			if (unit.get(i).contains("vector"))
				pub = pub + "\n" + unit.get(i) + "* get" + attributes.get(i)
						+ "();";
			else
				pub = pub + "\n" + unit.get(i) + " get" + attributes.get(i)
						+ "();";
			if (!attributes.get(i).equals(className + "ID")
					&& !attributes.get(i).equals("name"))
				pub = pub + "\nvoid set" + attributes.get(i) + "("
						+ unit.get(i) + " _" + attributes.get(i) + ");";
		}
		pub = pub + "\nvoid copy(std::map<std::string,std::string> object);";
		pub = pub
				+ "std::vector<std::string> Explode(const std::string & str, char separator );";
		pub = pub + "\n}; \n#endif /* " + className.toUpperCase() + "_H_ */";

		if (classParentName != null)
			for (int i = 0; i < classParentName.size(); i++) {
				if (i == 0)
					include = include + ": public " + classParentName.get(i);
				else
					include = include + ", public " + classParentName.get(i);
			}

		include = include + "{";
		result = result + include + priv + pub;

		return result;
	}

	public String generateCpp(HashMap<String, ArrayList<String>> range,
			HashMap<String, String> inverse, HashMap<String, String> single,
			String className, ArrayList<String> classParentName,
			ArrayList<String> attributes, ArrayList<String> unit) {
		String result = "";
		String include = "#include \"" + className + ".h\"\n\n";
		ArrayList<String> units = (ArrayList<String>) new ArrayList<String>(
				super.unit.values());

		Set<String> setu = new HashSet<String>();
		setu.addAll(unit);
		ArrayList<String> includeUnit = new ArrayList<String>(setu);

		if (units.size() >= 0)
			for (String sunit : includeUnit) {
				if (sunit.contains("std::")) {
					if (sunit.contains("<")) {
						if (!sunit.contains("<std::")) {
							// vector of objects
							String s = sunit.substring(sunit.indexOf("<") + 1,
									sunit.indexOf(">") - 1);
							if (!include.contains(s + ".h"))
								include = include + "\n #include \"" + s
										+ ".h\"";
						}
					}
				} else if (!units.contains(sunit)) {
					// Class simple
					if (sunit.endsWith("*"))
						sunit = sunit.substring(0, sunit.length() - 1);
					if (!include.contains(sunit + ".h"))
						include = include + "\n #include \"" + sunit + ".h\"";
				}
			}
		include = include + "\n\n";
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

		paramConstruct = paramConstruct + "{\nthis->name=name;";
		String destructor = className + "::~" + className + "(){\n";
		for (int i = 0; i < unit.size(); i++) {
			if (unit.get(i).contains("*") && !unit.get(i).contains("std::")) {

				paramConstruct = paramConstruct + attributes.get(i)
						+ " = NULL;\n";

				destructor = destructor + "delete(" + attributes.get(i)
						+ ");\n";
			}
		}

		paramConstruct = paramConstruct + "\n}";

		for (int i = 0; i < unit.size(); i++) {
			if (unit.get(i).contains("*")
					&& unit.get(i).contains("std::vector")) {
				destructor = destructor + "for(std::size_t i = 0; i < "
						+ attributes.get(i) + ".size(); i++)\n";
				destructor = destructor + "delete(" + attributes.get(i)
						+ "[i]);\n";
			}
		}

		destructor = destructor + "}\n";

		String get = "";
		String set = "";

		for (int i = 0; i < attributes.size(); i++) {
			if (unit.get(i).contains("vector")) {
				get = get + unit.get(i) + "* " + className + "::get"
						+ attributes.get(i) + "(){\n";
				get = get + "return &" + attributes.get(i) + ";\n}\n";
			} else {
				get = get + unit.get(i) + " " + className + "::get"
						+ attributes.get(i) + "(){\n";
				get = get + "return " + attributes.get(i) + ";\n}\n";
			}
			if (!attributes.get(i).equals(className + "ID")
					&& !attributes.get(i).equals("name")) {
				set = set + "void " + className + "::set" + attributes.get(i)
						+ "(" + unit.get(i) + " _" + attributes.get(i) + "){\n";

				set = set + "this->" + attributes.get(i) + "= _"
						+ attributes.get(i) + ";\n}\n";
			}
		}
		String globalGet = "void " + className + "::get(std::string name){\n";
		globalGet = globalGet + "std::map<std::string,std::string> temp;\n";

		if (classParentName != null) {
			for (int i = 0; i < classParentName.size(); i++) {
				globalGet = globalGet + "dao  = new DAO(\""
						+ classParentName.get(i) + "\");";
				globalGet = globalGet + "\n temp = dao->get(name);";
				globalGet = globalGet + "delete (dao);";
				globalGet = globalGet + "\n " + classParentName.get(i)
						+ "::copy(temp);\n";
			}
		}

		globalGet = globalGet + "dao  = new DAO(\"" + className + "\");";
		globalGet = globalGet + "\n temp = dao->get(name);";
		globalGet = globalGet + "\ndelete (dao); \n";
		globalGet = globalGet + "copy(temp);\n}\n";

		String globalSet = " void " + className + "::set(std::string name){\n";
		globalSet = globalSet + "std::map<std::string, std::string> data;\n";
		globalSet = globalSet + "std::stringstream ss;\n";
		for (int i = 0; i < attributes.size(); i++) {
			// data property single
			if (!unit.get(i).contains("*")
					&& !unit.get(i).contains("std::vector"))
				globalSet = globalSet + "data[\"" + attributes.get(i) + "\"]="
						+ attributes.get(i) + ";\n";

			// data property multi
			if (!unit.get(i).contains("*")
					&& unit.get(i).contains("std::vector")) {
				globalSet = globalSet + "for(unsigned int i=0;i<"
						+ attributes.get(i) + ".size();++i){\n";
				globalSet = globalSet + "data[\"" + attributes.get(i)
						+ "\"]=data[\"" + attributes.get(i) + "\"]+\" \"+"
						+ attributes.get(i) + "[i];\n}\n";

			}
			// object property single
			if (unit.get(i).contains("*")
					&& !unit.get(i).contains("std::vector")
					&& !unit.get(i).equals("DAO*"))
				globalSet = globalSet + "data[\"" + attributes.get(i) + "\"]="
						+ attributes.get(i) + "->getname();\n";
			// object property multi
			if (unit.get(i).contains("*")
					&& unit.get(i).contains("std::vector")) {
				globalSet = globalSet + "for(unsigned int i=0;i<"
						+ attributes.get(i) + ".size();++i){\n";
				globalSet = globalSet + "ss.flush();\n";
				globalSet = globalSet
						+ "ss << "
						+ attributes.get(i)
						+ "[i]->get"
						+ unit.get(i).substring("std::vector<".length(),
								unit.get(i).length() - 2) + "ID();\n";
				globalSet = globalSet + "data[\"" + attributes.get(i)
						+ "\"]=data[\"" + attributes.get(i)
						+ "\"]+\" \"+ss.str();\n}\n";
			}
		}
		/*if (classParentName != null) {
			for (int i = 0; i < classParentName.size(); i++) {
				globalSet = globalSet + "dao  = new DAO(\""
						+ classParentName.get(i) + "\");\n";
				globalSet = globalSet + "dao->set(data);\n";
				globalSet = globalSet + "delete (dao);\n";
			}
		}*/
		globalSet = globalSet + "dao  = new DAO(\"" + className + "\");\n";
		globalSet = globalSet + "dao->set(data);\n";
		globalSet = globalSet + "delete (dao);\n}\n";

		String copy = "";
		copy = copy + "\nvoid " + className
				+ "::copy(std::map<std::string,std::string> object){";
		copy = copy + "std::vector<std::string> temp;\n";
		copy = copy + "std::map<std::string,std::string> mapTemp;\n";
		copy = copy + "std::map<std::string,std::string> mapTempBis;\n";
		copy = copy + "int nbVal=0;\n";
		copy = copy + "int nbValCurrent=0;\n";

		copy = copy + "std::vector<" + className + "*> tmp;\n";

		for (int i = 0; i < unit.size(); i++) {
			// Fill local attributes
			if (!unit.get(i).contains("*")
					&& !unit.get(i).contains("std::vector")) {
				if (attributes.get(i).equals("name"))
					copy = copy + "this->" + attributes.get(i) + " = object[\""
							+ className + "._NAME\"];\n";
				else {
					if (!unit.get(i).equals("std::string"))
						copy = copy + "this->" + attributes.get(i)
								+ " = std::atof(object[\"" + className + "."
								+ attributes.get(i) + "\"].c_str());\n";
					else
						copy = copy + "this->" + attributes.get(i)
								+ " = object[\"" + className + "."
								+ attributes.get(i) + "\"];\n";
				}
			}
			// Fill local collections

			else if (!unit.get(i).contains("*")
					&& unit.get(i).contains("std::vector")) {
				copy = copy + "temp = Explode(object[\"" + attributes.get(i)
						+ "\"], ' ' );\n";
				copy = copy + "for(unsigned int i=0; i<temp.size();i++){\n";
				copy = copy + "this->" + attributes.get(i)
						+ ".push_back(temp[i]);\n";
				copy = copy + "}\n";
			}

			// Create Objects
			if (unit.get(i).contains("*") && !unit.get(i).contains("std::")
					&& !unit.get(i).equals("DAO*")) {
				copy = copy + "if(this->" + attributes.get(i)
						+ "== NULL && object[\"" + attributes.get(i) + "/"
						+ unit.get(i).substring(0, unit.get(i).length() - 1)
						+ "." + "_NAME" + "\"]!=\"\"){\n";
				copy = copy + "this->" + attributes.get(i) + " = new "
						+ unit.get(i).substring(0, unit.get(i).length() - 1)
						+ "(object[\"" + attributes.get(i) + "/"
						+ unit.get(i).substring(0, unit.get(i).length() - 1)
						+ "." + "_NAME" + "\"]);\n";
				/*if (range.get(attributes.get(i)).contains(className)) {
					if (single.get(attributes.get(i)).equals("false")) {
						copy = copy + "this->" + attributes.get(i) + "->get"
								+ attributes.get(i) + "()->push_back(this);\n";

					} else {
						copy = copy + "this->" + attributes.get(i) + "->set"
								+ attributes.get(i) + "(this);\n";
					}

				} else {
					if (!inverse.containsKey(attributes.get(i))
							|| single.get(inverse.get(attributes.get(i)))
									.equals("false")) {
						copy = copy + "this->" + attributes.get(i) + "->get"
								+ attributes.get(i) + "()->push_back(this);\n";

					} else {
						copy = copy + "this->" + attributes.get(i) + "->set"
								+ attributes.get(i) + "(this);\n";
					}
				}
				
				  copy = copy + "this->" + attributes.get(i) +
				  "->get(object[\"" + attributes.get(i) + "/" +
				  unit.get(i).substring(0, unit.get(i).length() - 1) + "." +
				  "_NAME" + "\"]);\n";*/
				 
					copy = copy + "}\n";

				
			/*	copy = copy + "else {object[\"" + attributes.get(i) + "/"
						+ unit.get(i).substring(0, unit.get(i).length() - 1)
						+ "." + "_NAME" + "\"]=\"videOuNullError\";}\n";*/
			}

			// Fill the collections of objects

			if (unit.get(i).contains("*") && unit.get(i).contains("std::")) {
				copy = copy
						+ "if(this->"
						+ attributes.get(i)
						+ ".empty() && object[\""
						+ attributes.get(i)
						+ "/"
						+ unit.get(i).substring("std::vector<".length(),
								unit.get(i).length() - 2) + "." + "_NAME"
						+ "\"]!=\"\"){\n";

				copy = copy
						+ "temp = Explode(object[\""
						+ attributes.get(i)
						+ "/"
						+ unit.get(i).substring("std::vector<".length(),
								unit.get(i).length() - 2) + "." + "_NAME"
						+ "\"], ' ' );\n";
				copy = copy + "for(unsigned int i=0; i<temp.size();i++){\n";

				copy = copy
						+ "this->"
						+ attributes.get(i)
						+ ".push_back(new "
						+ unit.get(i).substring("std::vector<".length(),
								unit.get(i).length() - 2) + "(temp[i]));\n";
			/*	if (range.get(attributes.get(i)).contains(className)) {
					if (single.get(attributes.get(i)).equals("false")) {
						copy = copy + "this->" + attributes.get(i)
								+ ".back()->get" + attributes.get(i)
								+ "()->push_back(this);\n";

					} else {
						copy = copy + "this->" + attributes.get(i)
								+ ".back()->set" + attributes.get(i)
								+ "(this);\n";
					}

				} else {
					if (!inverse.containsKey(attributes.get(i))
							|| single.get(inverse.get(attributes.get(i)))
									.equals("false")) {
						copy = copy + "this->" + attributes.get(i)
								+ ".back()->get" + attributes.get(i)
								+ "()->push_back(this);\n";

					} else {
						copy = copy + "this->" + attributes.get(i)
								+ ".back()->set" + attributes.get(i)
								+ "(this);\n";
					}
				}

				copy = copy + "this->" + attributes.get(i)
						+ ".back()->get(temp[i]);\n";*/

				copy = copy + "}\n";

				copy = copy + "}\n";
				

			/*	copy = copy
						+ "else {object[\""
						+ attributes.get(i)
						+ "/"
						+ unit.get(i).substring("std::vector<".length(),
								unit.get(i).length() - 2) + "." + "_NAME"
						+ "\"]=\"videOuNullError\";}\n";*/

			}

		}
	/*	for (int i = 0; i < unit.size(); i++) {
			// get unique objet
			if (unit.get(i).contains("*") && !unit.get(i).contains("std::")
					&& !unit.get(i).equals("DAO*")) {
				copy = copy + "if(object[\"" + attributes.get(i) + "/"
						+ unit.get(i).substring(0, unit.get(i).length() - 1)
						+ "." + "_NAME" + "\"]!=\"videOuNullError\" )\n";
				copy = copy + "this->" + attributes.get(i) + "->get(object[\""
						+ attributes.get(i) + "/"
						+ unit.get(i).substring(0, unit.get(i).length() - 1)
						+ "." + "_NAME" + "\"]);\n";

			}
			// get collections of objects
			if (unit.get(i).contains("*") && unit.get(i).contains("std::")) {
				copy = copy
						+ "if(object[\""
						+ attributes.get(i)
						+ "/"
						+ unit.get(i).substring("std::vector<".length(),
								unit.get(i).length() - 2) + "." + "_NAME"
						+ "\"]!=\"videOuNullError\"){\n";

				copy = copy
						+ "temp = Explode(object[\""
						+ attributes.get(i)
						+ "/"
						+ unit.get(i).substring("std::vector<".length(),
								unit.get(i).length() - 2) + "." + "_NAME"
						+ "\"], ' ' );\n";
				copy = copy + "for(unsigned int i=0; i<temp.size();i++){\n";
				copy = copy + "this->" + attributes.get(i) + "["
						+ attributes.get(i)
						+ ".size()-temp.size()+i]->get(temp[i]);\n}\n";

				copy = copy + "}\n";

			}
		}*/
		// copy = copy + "}\n";

		copy = copy + "\n}";

		String explode = "";
		explode = explode + "std::vector<std::string> " + className
				+ "::Explode(const std::string & str, char separator )\n";
		explode = explode + "{\n";
		explode = explode + "   std::vector< std::string > result;\n";
		explode = explode + "   std::size_t pos1 = 0;\n";
		explode = explode + "   std::size_t pos2 = 0;\n";
		explode = explode + "   while ( pos2 != str.npos )\n";
		explode = explode + "   {\n";
		explode = explode + "      pos2 = str.find(separator, pos1);\n";
		explode = explode + "      if ( pos2 != str.npos )\n";
		explode = explode + "      {\n";
		explode = explode + "         if ( pos2 > pos1 )\n";
		explode = explode
				+ "            result.push_back( str.substr(pos1, pos2-pos1) );\n";
		explode = explode + "         pos1 = pos2+1;\n";
		explode = explode + "      }\n";
		explode = explode + "   }\n";
		explode = explode
				+ "   result.push_back( str.substr(pos1, str.size()-pos1) );\n";
		explode = explode + "   return result;\n";
		explode = explode + "}\n";

		result = result + include + constructor + paramConstruct + destructor
				+ get + set + globalGet + globalSet + copy + explode;
		return result;
	}
}
