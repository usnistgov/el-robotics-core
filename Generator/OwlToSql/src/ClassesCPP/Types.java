package ClassesCPP;

import java.util.ArrayList;

public class Types extends ClassGenerator {

	public Types(String className) {
		this.className = className;
		fillUnit();
	}

	public String generateHeader(String className,
			ArrayList<String> classParentName, ArrayList<String> attributes,
			ArrayList<String> unit) {
		String result = "";
		String include = "#include <cstdlib>\n" + "#ifndef "
				+ className.toUpperCase() + "_H_\n#define "
				+ className.toUpperCase() + "_H_\n" + "class " + className;
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
		pub = pub + "\n" + className + "(" + paramConstruct + ");";
		pub = pub + "\n" + className + "* get(int id);";
		pub = pub + "\n" + className + "* get(std::string name);";
		pub = pub + "\nvoid set(int id, " + className + "* obj);";
		pub = pub + "\nvoid set(std::string name, " + className + "* obj);";

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

	public String generateCpp(String className, ArrayList<String> attributes,
			ArrayList<String> unit) {
		String result = "";
		String include = "#include \"" + className + ".h\"";

		String constructor = className + "::" + className + "(";
		String paramConstruct = "";
		for (int i = 0; i < attributes.size(); i++) {
			if (i < attributes.size() - 1)
				paramConstruct = paramConstruct + unit.get(i) + " "
						+ attributes.get(i) + ",";
			else
				paramConstruct = paramConstruct + unit.get(i) + " "
						+ attributes.get(i) + ")";
		}

		result = result + include + constructor;
		return result;
	}

}
