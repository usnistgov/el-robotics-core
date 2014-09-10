package DataBase;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashMap;

import org.semanticweb.owlapi.model.OWLOntology;

public class Triggers {
	/**
	 * \brief Separator between URL and the individuals' name in the ontology.
	 */
	private static final char SEPARATOR = '#';
	/**
	 * \brief List of super classes. \details Used to know where insert data
	 * when there is a hierarchy.
	 */
	private OWLOntology ontology;
	/**
	 * \brief Where we are going to save the script.
	 */
	private String path;
	/**
	 * \brief Attributes for a given table. \details <Table1 =>
	 * <Attribute1,Attribute2,TableForeignKey/ForeignKey...>
	 */
	private HashMap<String, ArrayList<String>> tables;

	/**
	 * \brief Save the sql script on the disk. \param s Data to write.
	 */
	public void write(String s) throws IOException {
		Writer fstream = new FileWriter(path + "CreateTriggers.sql");
		BufferedWriter out = new BufferedWriter(fstream);
		out.write(s);
		out.close();
	}

	/**
	 * \brief Constructor \details Constructor of the Triggers class. \param
	 * tables Collections of the tables and attributes. \param ontology Our
	 * ontology. \param path Where we are going to save the script.
	 */
	public Triggers(HashMap<String, ArrayList<String>> tables,
			OWLOntology ontology, String path) {
		this.tables = tables;
		this.ontology = ontology;
		this.path = path;
		try {
			write(generateTriggers());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private String generateTriggers() {
		String result = "CREATE TABLE ChangesInTables(\nid INT NOT NULL AUTO_INCREMENT, \nName_of_Table varchar(255) NOT NULL, \nDescription varchar(255) NOT NULL,";
		result += "\nName_of_Object_Changed varchar(255) NOT NULL, \nDate DATE NOT NULL, \nTime TIME NOT NULL, \nattribute_modified varchar(255) NOT NULL,";
		result += "\nold_value varchar(255) NOT NULL, \nnew_value varchar(255) NOT NULL, \nPRIMARY KEY (id) \n)ENGINE=InnoDB;";
		result += trigOnInsert() + trigOnupdate() + trigOnDelete();
		return result;
	}

	private String trigOnDelete() {
		String result = "";
		for (int i = 0; i < tables.size(); i++) {
			result += "\n\nDELIMITER $$\ncreate trigger " + tables.keySet().toArray()[i]
					+ "_trig_delete before delete on "
					+ tables.keySet().toArray()[i];
			result += "\nfor each row \nbegin\n";
			result += "insert into ChangesInTables (Name_of_Table,Description,Name_of_Object_Changed,Date,Time,attribute_modified,old_value,new_value) \n";
			result += "values('";
			result += tables.keySet().toArray()[i]
					+ "', 'Delete', old._NAME,current_date, now(), 'none', 'none', 'none');";
			result += "end$$ \nDELIMITER ; \n";
		}

		return result;
	}

	private String trigOnupdate() {
		String result = "";
		for (int i = 0; i < tables.size(); i++) {
			result += "\n\nDELIMITER $$\ncreate trigger " + tables.keySet().toArray()[i]
					+ "_trig_update before update on "
					+ tables.keySet().toArray()[i];
			result += "\nfor each row \nbegin\n";

			for (int j = 0; j < tables.get(tables.keySet().toArray()[i]).size(); j++) {
				if (!tables.get(tables.keySet().toArray()[i]).get(j)
						.contains("/")
						&& !tables.get(tables.keySet().toArray()[i]).get(j)
								.equals(tables.keySet().toArray()[i] + "ID")) {
					result += "if (new."
							+ tables.get(tables.keySet().toArray()[i]).get(j)
							+ "<>old."
							+ tables.get(tables.keySet().toArray()[i]).get(j)
							+ ") then \n";
					result += "insert into ChangesInTables (Name_of_Table,Description,Name_of_Object_Changed,Date,Time,attribute_modified,old_value,new_value)\n";
					result += "values";
					result += "('" + tables.keySet().toArray()[i]
							+ "','Update',new._NAME,current_date,now(),'"
							+ tables.get(tables.keySet().toArray()[i]).get(j)
							+ "',old."
							+ tables.get(tables.keySet().toArray()[i]).get(j)
							+ ",new."
							+ tables.get(tables.keySet().toArray()[i]).get(j)
							+ ");\n";
					result += "end if;\n";
				}
			}
			result += "end$$ \nDELIMITER ; \n";

		}
		return result;
	}

	private String trigOnInsert() {
		String result = "";
		for (int i = 0; i < tables.size(); i++) {
			result += "\n\nDELIMITER $$\ncreate trigger " + tables.keySet().toArray()[i]
					+ "_trig_insert before insert on "
					+ tables.keySet().toArray()[i];
			result += "\nfor each row \nbegin\n";
			result += "insert into ChangesInTables (Name_of_Table,Description,Name_of_Object_Changed,Date,Time,attribute_modified,old_value,new_value) \n";
			result += "values('";
			result += tables.keySet().toArray()[i]
					+ "', 'Insertion', new._NAME,current_date, now(), 'none', 'none', 'none');";
			result += "end$$ \nDELIMITER ; \n";
		}

		return result;
	}
}
