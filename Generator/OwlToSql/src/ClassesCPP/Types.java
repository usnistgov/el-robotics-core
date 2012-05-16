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

		include = include + "#include <map>\n";

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
							include = include + "\n #include \"" + s + ".h\"";
							include = include + "\n class " + s + ";";
							s = sunit.substring(5, sunit.indexOf("<"));
							include = include + "\n #include <" + s + ">";
						} else {
							// vector of string
							String s = sunit.substring(sunit.indexOf("<") + 1,
									sunit.indexOf(">"));
							s = s.substring(5);
							include = include + "\n #include <" + s + ">";
							s = sunit.substring(5, sunit.indexOf("<"));
							include = include + "\n #include <" + s + ">";
						}
					} else {
						// string
						String s = sunit.substring(5);
						include = include + "\n #include <" + s + ">";
					}
				} else if (!units.contains(sunit)) {
					// Class simple
					if (sunit.endsWith("*"))
						sunit = sunit.substring(0, sunit.length() - 1);
					include = include + "\n #include \"" + sunit + ".h\"";
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
			pub = pub + "\n" + unit.get(i) + " get" + attributes.get(i) + "();";
			pub = pub + "\nvoid set" + attributes.get(i) + "(" + unit.get(i)
					+ " _" + attributes.get(i) + ");";

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

		paramConstruct = paramConstruct + "{\nthis->name=name;\n}";
		String destructor = className + "::~" + className + "(){\n";
		for (int i = 0; i < unit.size(); i++) {
			if (unit.get(i).contains("*") && !unit.get(i).contains("std::")) {
				destructor = destructor + "delete(" + attributes.get(i)
						+ ");\n";
			}
		}
		for (int i = 0; i < unit.size(); i++) {
			if (unit.get(i).contains("*")
					&& unit.get(i).contains("std::vector")) {
				destructor = destructor + "for(size_t i = 0; i < "
						+ attributes.get(i) + ".size(); i++)\n";
				destructor = destructor + "delete(" + attributes.get(i)
						+ "[i]);\n";
			}
		}

		destructor = destructor + "}\n";

		String get = "";
		for (int i = 0; i < attributes.size(); i++) {
			get = get + unit.get(i) + " " + className + "::get"
					+ attributes.get(i) + "(){\n";
			get = get + "return this->" + attributes.get(i) + ";\n}\n";
		}
		String set = "";
		for (int i = 0; i < attributes.size(); i++) {

			set = set + "void " + className + "::set" + attributes.get(i) + "("
					+ unit.get(i) + " _" + attributes.get(i) + "){\n";

			set = set + "this->" + attributes.get(i) + "= _"
					+ attributes.get(i) + ";\n}\n";
		}
		String globalGet = "void " + className + "::get(std::string name){\n";
		globalGet = globalGet
				+ "std::map<std::string,std::string> temp;\n" ;
		if (classParentName != null) {
			for (int i = 0; i < classParentName.size(); i++) {
				globalGet = globalGet + "dao  = new DAO(\""
						+ classParentName.get(i) + "\");";
				globalGet = globalGet
						+ "\n temp = dao->get(name);";
				globalGet = globalGet + "\n " + classParentName.get(i)
						+ "::copy(temp);\n";
				globalGet = globalGet + "delete (dao);\n";
			}
		}

		globalGet = globalGet + "dao  = new DAO(\"" + className + "\");";
		globalGet = globalGet
				+ "\n temp = dao->get(name);";
		globalGet = globalGet + "\n copy(temp);\n";
		globalGet = globalGet + "delete (dao);\n}\n";

		String globalSet = " void " + className + "::set(std::string name){";
		globalSet = globalSet + "\n dao  = new DAO(\"" + className + "\");";
		globalSet = globalSet + "\n dao->set(name);\n";
		globalSet = globalSet + "delete (dao);\n}\n";

		String copy = "";
		copy = copy + "\nvoid " + className
				+ "::copy(std::map<std::string,std::string> object){";
		copy = copy + "std::vector<std::string> temp;\n";
		copy = copy + "std::map<std::string,std::string> mapTemp;\n";
		copy = copy + "std::map<std::string,std::string> mapTempBis;\n";
		copy = copy + "int nbVal=0;\n";
		copy = copy + "int nbValCurrent=0;\n";

		for (int i = 0; i < unit.size(); i++) {
			// Create Objects
			if (unit.get(i).contains("*") && !unit.get(i).contains("std::")
					&& !unit.get(i).equals("DAO*")) {
				copy = copy + "this->" + attributes.get(i) + " = new "
						+ unit.get(i).substring(0, unit.get(i).length() - 1)
						+ "(\" \");\n";
				copy = copy + "this->" + attributes.get(i) + "->set"
						+ attributes.get(i) + "(this);\n";
			}
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

			if (!unit.get(i).contains("*")
					&& unit.get(i).contains("std::vector")) {
				copy = copy + "temp = Explode(object[\"" + attributes.get(i)
						+ "\"], ' ' );\n";
				copy = copy + "for(unsigned int i=0; i<temp.size();i++){\n";
				copy = copy + "this->" + attributes.get(i)
						+ ".push_back(temp[i]);\n";
				copy = copy + "}\n";
			}

			if (unit.get(i).contains("*") && !unit.get(i).contains("std::")
					&& !unit.get(i).equals("DAO*")) {
				copy = copy + "mapTemp.clear();\n";
				copy = copy
						+ "for (std::map<std::string, std::string>::iterator it = object.begin(); it\n!= object.end(); it++) {\n";
				copy = copy + "if (it->first.substr(0,"
						+ (attributes.get(i) + "/").length() + ") == \""
						+ attributes.get(i) + "/\"){\n";
				copy = copy + "mapTemp[it->first.substr("
						+ (attributes.get(i) + "/").length()
						+ ",it->first.length())] = it->second;\n";
				copy = copy + "}\n";
				copy = copy + "}\n";

				copy = copy + "if(!mapTemp.empty())";
				copy = copy + "this->" + attributes.get(i)
						+ "->copy(mapTemp);\n";
			}
			// Fill the collections of objects

			if (unit.get(i).contains("*") && unit.get(i).contains("std::")) {
				copy = copy + "mapTemp.clear();\n";
				copy = copy + "mapTempBis.clear();\n";
				copy = copy
						+ "for (std::map<std::string, std::string>::iterator it = object.begin(); it\n!= object.end(); it++) {\n";
				copy = copy + "if (it->first.substr(0,"
						+ (attributes.get(i) + "/").length() + ") == \""
						+ attributes.get(i) + "/\"){\n";
				copy = copy + "mapTemp[it->first.substr("
						+ (attributes.get(i) + "/").length()
						+ ",it->first.length())] = it->second;\n";
				copy = copy + "nbVal=Explode(it->second,' ').size();\n";
				copy = copy + "}\n";
				copy = copy + "}\n";
				copy = copy + "nbValCurrent=0;\n";
				copy = copy + "if(nbValCurrent<=nbVal){\n";
				copy = copy
						+ "for (std::map<std::string, std::string>::iterator it = mapTemp.begin(); it\n!= mapTemp.end(); it++) {\n";
				copy = copy
						+ "mapTempBis[it->first]=Explode(it->second,' ')[nbValCurrent];\n";
				copy = copy + "if(!mapTempBis.empty()){\n";
				copy = copy
						+ "this->"
						+ attributes.get(i)
						+ ".push_back(new "
						+ unit.get(i).substring(unit.get(i).indexOf("<") + 1,
								unit.get(i).indexOf(">") - 1) + "(\" \"));\n";
				copy = copy + "this->" + attributes.get(i) + ".back()->get"
						+ attributes.get(i) + "().push_back(this);\n";
				copy = copy + "this->" + attributes.get(i)
						+ ".back()->copy(mapTempBis);\n";
				copy = copy + "}\n";
				copy = copy + "}\n";
				copy = copy + "nbValCurrent++;\n";
				copy = copy + "}\n";
			}

		}
		// copy = copy + "}\n";

		copy = copy + "\n}";

		String explode = "";
		explode = explode + "std::vector<std::string> " + className
				+ "::Explode(const std::string & str, char separator )\n";
		explode = explode + "{\n";
		explode = explode + "   std::vector< std::string > result;\n";
		explode = explode + "   size_t pos1 = 0;\n";
		explode = explode + "   size_t pos2 = 0;\n";
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
