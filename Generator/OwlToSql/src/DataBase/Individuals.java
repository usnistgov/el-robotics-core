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
 * \file      Individuals.java
 * \author    Anthony Pietromartire \a pietromartire.anthony\@nist.gov
 * \version   1.0
 * \date      29 June 2012
 * \brief     Class for the individuals.
 *
 */

/**
 * \class 	DataBase.Individuals
 * \brief     Class for the individuals.
 * \details   This class is used to manipulate the individuals from the ontology 
 * 				and generate the SQL script to insert them into the MySQL DB. 
 */
package DataBase;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import org.semanticweb.owlapi.model.OWLClassExpression;
import org.semanticweb.owlapi.model.OWLDataPropertyExpression;
import org.semanticweb.owlapi.model.OWLIndividual;
import org.semanticweb.owlapi.model.OWLLiteral;
import org.semanticweb.owlapi.model.OWLObjectPropertyExpression;
import org.semanticweb.owlapi.model.OWLOntology;

public class Individuals {
	/**
	 * \brief     Update queries.
	 */
	private String resultUpdate = "";
	/**
	 * \brief     Separator between URL and the individuals' name in the ontology.
	 */
	private static final char SEPARATOR = '#';
	/**
	 * \brief      List of super classes.
	 * \detail Used to know where insert data when there is a hierarchy.
	 */
	private ArrayList<String> parent;
	/**
	 * \brief      Our ontology
	 */
	private OWLOntology ontology;
	/**
	 * \brief      Where we are going to save the script.
	 */
	private String path;
	/**
	 * \brief      Number of insertion for a given table.
	 * \Map - Key: Type => Value : # of insertion.
	 */
	private HashMap<String, Integer> nbInsert; 
	/**
	 * \brief      Attributes for a given table.
	 * \detail <Table1 => <Attribute1,Attribute2,TableForeignKey/ForeignKey...>
	 */
	private HashMap<String, ArrayList<String>> tables; 
	/**
	 * \brief      List of the individuals in the ontology.
	 */
	private ArrayList<OWLIndividual> individuals;
	/**
	 * \brief      List of the individuals without the URL before their name.
	 */
	private ArrayList<String> individualsClean;
	/**
	 * \brief      Collection of the types and individuals associated.
	 * \detail Type1 => <Individual1, Individual2>, Type2 => <Individual3, Individual4>
	 */
	private HashMap<String, ArrayList<String>> individualsType; 
	/**
	 * \brief      List of the super classes without the URL before their name in the ontology.
	 * \detail Classe1=<SuperClasse1,SuperClasse2>,Classe2=<SuperClasse1,SuperClasse2>
	 */
	private HashMap<String, ArrayList<String>> superClassesClean;

	/**
     *  \brief Constructor
     *  \details Constructor of the Individuals class.
     *  \param tables 	Collections of the tables and attributes.
     *  \param ontology 	Our ontology.
     *  \param path 	Where we are going to save the script.
     *  \param superClassesClean 	List of the super classes.
     */
	public Individuals(HashMap<String, ArrayList<String>> tables,
			OWLOntology ontology, String path,
			HashMap<String, ArrayList<String>> superClassesClean) {
		this.tables = tables;
		this.ontology = ontology;
		this.path = path;
		this.superClassesClean = superClassesClean;
		parent = new ArrayList<String>();
		individuals = null;
		nbInsert =new HashMap<String, Integer>();
		individualsType = new HashMap<String, ArrayList<String>>();
		addIndividuals(); // Extract the individuals of the ontology - Fill up
		// the Individuals list
		individualsClean = new ArrayList<String>();
		cleanIndividuals(); // delete the url before the name of the individual
		addTypes();
		insert();
	}

	/**
	 * \brief      Test if a String is a number.
	 * \param    s			   String we want to test.
	 * \return   A boolean : true if the String can be cast in a number, false if it can't.
	 */
	public boolean isNumber(String s) {
		try {
			Double.valueOf(s);
			return true;
		} catch (NumberFormatException nfe) {
			return false;
		}
	}

	/**
	 * \brief      Make all the call to generate the SQL script used for the insertions.
	 */
	public void insert() {
		write(insertInto() + resultUpdate);
	}

	/**
	 * \brief      Fill a map whith the different classes in the ontology, and their indivuals.
	 * \details   The key is the name of the class in the ontology, and the value a list which contains the names of the individuals of this class
	 */
	private void addTypes() {
		for (int i = 0; i < individualsClean.size(); i++) {
			ArrayList<String> temp = new ArrayList<String>();

			Set<OWLClassExpression> types = individuals.get(i).getTypes(
					ontology);
			for (OWLClassExpression type : types) {
				if (!type.toString().equals("owl:Thing")) {
					if (individualsType.containsKey(individualsClean.get(i))) {
						temp = individualsType.get(individualsClean.get(i));
					}
					if (!type.toString().contains(String.valueOf(SEPARATOR)))
						temp.add(type.toString());
					else
						temp.add(type.toString().substring(
								type.toString().indexOf(SEPARATOR) + 1,
								type.toString().length() - 1));
				}
			}
			individualsType.put(individualsClean.get(i), temp);
		}
	}

	/**
	 * \brief      Fill a list whith the name of the individuals from the ontology
	 * \details   It cleans the name by removing the URI from it.
	 */
	public void cleanIndividuals() {
		for (int i = 0; i < individuals.size(); i++) {
			individualsClean
					.add(individuals
							.get(i)
							.toString()
							.substring(
									individuals.get(i).toString()
											.indexOf(SEPARATOR) + 1,
									individuals.get(i).toString().length() - 1));
		}
	}

	/**
	 * \brief   Extract the individuals of the ontology and fill up the Individuals list
	 */	
	public void addIndividuals() {
		individuals = new ArrayList<OWLIndividual>(
				ontology.getIndividualsInSignature());
	}

	/**
	 * \brief      Add the local data properties in the SQL script for a given individual.
	 * \param    i		Position of the individual in the list.
	 * \param    attributesTab		Tab with all the attributes.
	 * \param    attributes		Conversion of the tab in a single string.
	 * \param    name		To know if the name is added in order to do it only once.
	 * \return    A tab with in position 0 the values corresponding to the attributes and in position 1 if the name is added.
	 */
	public Object[] insertIntoData(int i, String[] attributesTab,
			String attributes, boolean name) {
		String result = "";
		Map<OWLDataPropertyExpression, Set<OWLLiteral>> valuesData = individuals
				.get(i).getDataPropertyValues(ontology);
		// There is only an ID and a name
		if (valuesData.size() == 0 && !name) {
			result = result + "'" + individualsClean.get(i) + "'";
			name = true;
		}
		for (int l = 1; l < attributesTab.length; l++) {
			for (Entry<OWLDataPropertyExpression, Set<OWLLiteral>> value : valuesData
					.entrySet()) {
				if (attributesTab[l].endsWith("_NAME") && !name) {
					result = result + "'" + individualsClean.get(i) + "'";
					name = true;
					if (l != attributesTab.length - 1)
						result = result + ", ";
				}
				if (value.getKey().toString()
						.contains(attributesTab[l].substring(1))) {
					// The attribute type = a xsd type
					if (value.getValue().toString().contains("^")) {

						if (isNumber(value
								.getValue()
								.toString()
								.substring(
										2,
										value.getValue().toString()
												.indexOf("^") - 1)))
							result = result
									+ value.getValue()
											.toString()
											.substring(
													2,
													value.getValue().toString()
															.indexOf("^") - 1);
						else
							result = result
									+ "'"
									+ value.getValue()
											.toString()
											.substring(
													2,
													value.getValue().toString()
															.indexOf("^") - 1)
									+ "'";

					}
					// The attribute is a reference
					else if (value.getValue().toString()
							.contains(String.valueOf(SEPARATOR))) {
						if (isNumber(value
								.getValue()
								.toString()
								.substring(
										value.getValue().toString()
												.lastIndexOf(SEPARATOR) + 1,
										value.getValue().toString().length() - 2)))
							result = result
									+ value.getValue()
											.toString()
											.substring(
													value.getValue()
															.toString()
															.lastIndexOf(
																	SEPARATOR) + 1,
													value.getValue().toString()
															.length() - 2);
						else
							result = result
									+ "'"
									+ value.getValue()
											.toString()
											.substring(
													value.getValue()
															.toString()
															.lastIndexOf(
																	SEPARATOR) + 1,
													value.getValue().toString()
															.length() - 2)
									+ "'";
					}
					// The attribute is a part of an enumeration
					else {

						if (isNumber(value
								.getValue()
								.toString()
								.substring(
										2,
										value.getValue().toString().length() - 2)))
							result = result

									+ value.getValue()
											.toString()
											.substring(
													2,
													value.getValue().toString()
															.length() - 2);
						else
							result = result
									+ "'"
									+ value.getValue()
											.toString()
											.substring(
													2,
													value.getValue().toString()
															.length() - 2)
									+ "'";

					}
					if (attributes.substring(2).contains(",")
							&& l != attributesTab.length - 1)
						result = result + ", ";

				}

			}
		}
		Object[] resultTab = new Object[2];
		resultTab[0] = result;
		resultTab[1] = name;
		return resultTab;
	}

	/**
	 * \brief      Add the local object properties in the SQL script for a given individual.
	 * \param    i		Position of the individual in the list.
	 * \param    attributesTab		Tab with all the attributes.
	 * \param    attributes		Conversion of the tab in a single string.
	 * \param    name		To know if the name is added in order to do it only once.
	 * \return    A tab with in position 0 the values corresponding to the attributes and in position 1 if the name is added.
	 */
	public Object[] insertIntoObject(int i, String[] attributesTab,
			String attributes, boolean name) {
		String result = "";
		Map<OWLObjectPropertyExpression, Set<OWLIndividual>> valuesObject = individuals
				.get(i).getObjectPropertyValues(ontology);
		for (int l = 1; l < attributesTab.length; l++) {
			for (Entry<OWLObjectPropertyExpression, Set<OWLIndividual>> value : valuesObject
					.entrySet()) {
				// There is only an ID and a name

				if (attributesTab[l].endsWith("_NAME") && !name) {
					result = result + "'" + individualsClean.get(i) + "'";
					name = true;
					if (l != attributesTab.length - 1)
						result = result + ", ";

				}
				if (value.getKey().toString()
						.contains(attributesTab[l].substring(1))) {

					// The attribute type = a xsd type

					if (value.getValue().toString().contains("^")) {
						if (isNumber(value
								.getValue()
								.toString()
								.substring(
										2,
										value.getValue().toString()
												.indexOf("^") - 1)))
							result = result
									+ value.getValue()
											.toString()
											.substring(
													2,
													value.getValue().toString()
															.indexOf("^") - 1);
						else
							result = result
									+ "'"
									+ value.getValue()
											.toString()
											.substring(
													2,
													value.getValue().toString()
															.indexOf("^") - 1)
									+ "'";

					} // The attribute is a reference

					else if (value.getValue().toString()
							.contains(String.valueOf(SEPARATOR))) {
						if (isNumber(value
								.getValue()
								.toString()
								.substring(
										value.getValue().toString()
												.lastIndexOf(SEPARATOR) + 1,
										value.getValue().toString().length() - 2)))
							result = result
									+ value.getValue()
											.toString()
											.substring(
													value.getValue()
															.toString()
															.lastIndexOf(
																	SEPARATOR) + 1,
													value.getValue().toString()
															.length() - 2);
						else
							result = result
									+ "'"
									+ value.getValue()
											.toString()
											.substring(
													value.getValue()
															.toString()
															.lastIndexOf(
																	SEPARATOR) + 1,
													value.getValue().toString()
															.length() - 2)
									+ "'";

					} else {
						// The attribute is a part of an
						// enumeration
						if (isNumber(value
								.getValue()
								.toString()
								.substring(
										2,
										value.getValue().toString().length() - 2)))
							result = result

									+ value.getValue()
											.toString()
											.substring(
													2,
													value.getValue().toString()
															.length() - 2);
						else
							result = result
									+ "'"
									+ value.getValue()
											.toString()
											.substring(
													2,
													value.getValue().toString()
															.length() - 2)
									+ "'";

					}
					if (attributes.substring(2).contains(",")
							&& l != attributesTab.length - 1)
						result = result + ", ";

				}
			}

		}
		Object[] resultTab = new Object[2];
		resultTab[0] = result;
		resultTab[1] = name;
		return resultTab;
	}

	/**
	 * \brief      Add the data properties from other tables in the SQL script for a given individual.
	 * \param    i		Position of the individual in the list.
	 * \param    i		Position of the attribute in the tab.
	 * \param    attributesTab		Tab with all the attributes.
	 * \param    name		To know if the name is added in order to do it only once.
	 * \return    A tab with in position 0 the values corresponding to the attributes and in position 1 if the name is added.
	 */
	public Object[] insertIntoDataForeign(int i, int l, String[] attributesTab,
			boolean name) {
		String result = "";

		Map<OWLDataPropertyExpression, Set<OWLLiteral>> valuesData = individuals
				.get(i).getDataPropertyValues(ontology);
		if (valuesData.size() == 0 && !name) {
			result = result + "'" + individualsClean.get(i) + "'";
			name = true;
		}

		if (attributesTab[l].toString().endsWith("ID")) {
			if (nbInsert.get(attributesTab[l].toString().substring(
					attributesTab[l].toString().indexOf("/") + 1,
					attributesTab[l].toString().length() - 2)) != null)
				result = result
						+ String.valueOf(nbInsert
								.get(attributesTab[l].toString()
										.substring(
												attributesTab[l].toString()
														.indexOf("/") + 1,
												attributesTab[l].toString()
														.length() - 2)) - 1);
			else
				result = result + 1;
		}
		for (Entry<OWLDataPropertyExpression, Set<OWLLiteral>> value : valuesData
				.entrySet()) {
			// There is only an ID and a name
			if (attributesTab[l].endsWith("_NAME") && !name) {
				result = result + "'" + individualsClean.get(i) + "'";
				name = true;
				if (l != attributesTab.length - 1)
					result = result + ", ";
			}

			if (value
					.getKey()
					.toString()
					.contains(
							attributesTab[l].toString()
									.substring(
											attributesTab[l].toString()
													.indexOf("/") + 1,
											attributesTab[l].toString()
													.length()))) {

				// The attribute type = a xsd type
				if (value.getValue().toString().contains("^")) {
					if (isNumber(value
							.getValue()
							.toString()
							.substring(
									2,
									value.getValue().toString().indexOf("^") - 1)))
						result = result
								+ value.getValue()
										.toString()
										.substring(
												2,
												value.getValue().toString()
														.indexOf("^") - 1);
					else
						result = result
								+ "'"
								+ value.getValue()
										.toString()
										.substring(
												2,
												value.getValue().toString()
														.indexOf("^") - 1)
								+ "'";

				} else if (value.getValue().toString()
						.contains(String.valueOf(SEPARATOR))) {
					if (isNumber(value
							.getValue()
							.toString()
							.substring(
									value.getValue().toString()
											.lastIndexOf(SEPARATOR) + 1,
									value.getValue().toString().length() - 2)))
						result = result
								+ value.getValue()
										.toString()
										.substring(
												value.getValue().toString()
														.lastIndexOf(SEPARATOR) + 1,
												value.getValue().toString()
														.length() - 2);
					else
						result = result
								+ "'"
								+ value.getValue()
										.toString()
										.substring(
												value.getValue().toString()
														.lastIndexOf(SEPARATOR) + 1,
												value.getValue().toString()
														.length() - 2) + "'";

				} else {
					if (isNumber(value
							.getValue()
							.toString()
							.substring(2,
									value.getValue().toString().length() - 2)))
						result = result

								+ value.getValue()
										.toString()
										.substring(
												2,
												value.getValue().toString()
														.length() - 2);
					else
						result = result
								+ "'"
								+ value.getValue()
										.toString()
										.substring(
												2,
												value.getValue().toString()
														.length() - 2) + "'";

				}
				if (attributesTab[l]
						.toString()
						.substring(
								attributesTab[l].toString().indexOf("/") + 1,
								attributesTab[l].toString().length())
						.contains(",")
						&& l != attributesTab.length - 1)
					result = result + ", ";

			}
		}
		Object[] resultTab = new Object[2];
		resultTab[0] = result;
		resultTab[1] = name;
		return resultTab;
	}

	// Add the remote object properties in the SQL script
	/**
	 * \brief      Add the object properties from other tables in the SQL script for a given individual.
	 * \param    i		Position of the individual in the list.
	 * \param    i		Position of the attribute in the tab.
	 * \param    attributesTab		Tab with all the attributes.
	 * \param    name		To know if the name is added in order to do it only once.
	 * \param    name		To know if the name is added in order to do it only once.
	 * \return    A tab with in position 0 the values corresponding to the attributes and in position 1 if the name is added.
	 */
	public Object[] insertIntoObjectForeign(int i, int l,
			String[] attributesTab, boolean name) {
		String result = "";

		Map<OWLObjectPropertyExpression, Set<OWLIndividual>> valuesObject = individuals
				.get(i).getObjectPropertyValues(ontology);

		for (Entry<OWLObjectPropertyExpression, Set<OWLIndividual>> value : valuesObject
				.entrySet()) {
			if (attributesTab[l].endsWith("_NAME") && !name) {
				result = result + "'" + individualsClean.get(i) + "'";
				name = true;
				if (l != attributesTab.length - 1)
					result = result + ", ";
			}

			if (value
					.getKey()
					.toString()
					.contains(
							attributesTab[l].toString()
									.substring(
											attributesTab[l].toString()
													.indexOf("/") + 1,
											attributesTab[l].toString()
													.length()))) {

				// The attribute is a reference
				if (value.getValue().toString()
						.contains(String.valueOf(SEPARATOR))) {
					result = result
							+ value.getValue()
									.toString()
									.substring(
											value.getValue().toString()
													.lastIndexOf(SEPARATOR) + 1,
											value.getValue().toString()
													.length());

				} else {
					result = result
							+ "'"
							+ value.getValue()
									.toString()
									.substring(
											2,
											value.getValue().toString()
													.length() - 2) + "'";

				}
				if (attributesTab[l]
						.toString()
						.substring(
								attributesTab[l].toString().indexOf("/") + 1,
								attributesTab[l].toString().length())
						.contains(",")
						&& l != attributesTab.length - 1)
					result = result + ", ";
			}
		}
		Object[] resultTab = new Object[2];
		resultTab[0] = result;
		resultTab[1] = name;
		return resultTab;
	}

	/**
	 * \brief      Manage the call to the insertSuper method to generate the script and populate the tables issued from multi valued properties.
	 * \return    A String with the insert into queries.
	 */
	public String insertInto() {
		Object[] resultTab = new Object[2];
		boolean name;
		String result = "";
		for (int i = 0; i < individualsType.size(); i++) {
			name = false;
			ArrayList<String> attributes;
			String attributesLocal = "";
			String attributesRemote = "";
			String[] attributesLocalTab;
			String[] attributesRemoteTab;
			if (individualsType.containsKey(individualsClean.get(i))) {
				// IndividualType != owl:Thing
				for (int j = 0; j < individualsType
						.get(individualsClean.get(i)).size(); j++) {
					attributes = tables.get(individualsType.get(
							individualsClean.get(i)).get(j));
					// Split local (in his table) and remote (in another table)
					// attributes
					for (int k = 0; k < attributes.size(); k++) {
						if (!attributes.get(k).contains("/")) {
							attributesLocal = attributesLocal + ", "
									+ attributes.get(k);
						} else {
							attributesRemote = attributesRemote + ", "
									+ attributes.get(k);
						}
					}
					attributesLocalTab = attributesLocal.split(",");
					if (attributesLocal.length() != 0) {
						parent = new ArrayList<String>();
						result = result
								+ insertSuper(
										i,
										individualsType
												.get(individualsClean.get(i))
												.toString()
												.substring(
														1,
														individualsType
																.get(individualsClean
																		.get(i))
																.toString()
																.length() - 1),
										attributesLocalTab, attributesLocal,
										name);
					}
				}
			}

			// Association tables + xValue Tables
			attributesRemoteTab = attributesRemote.split(",");

			ArrayList<Integer> temp;
			HashMap<String, ArrayList<Integer>> remotePosition = new HashMap<String, ArrayList<Integer>>();
			for (int c = 1; c < attributesRemoteTab.length; c++) {
				if (remotePosition
						.containsKey(attributesRemoteTab[c].toString()
								.substring(
										1,
										attributesRemoteTab[c].toString()
												.indexOf("/")))) {
					temp = remotePosition.get(attributesRemoteTab[c].toString()
							.substring(
									1,
									attributesRemoteTab[c].toString().indexOf(
											"/")));
				} else {
					temp = new ArrayList<Integer>();
				}
				temp.add(c);
				remotePosition
						.put(attributesRemoteTab[c].toString().substring(1,
								attributesRemoteTab[c].toString().indexOf("/")),
								temp);
			}

			if (!remotePosition.isEmpty()) {
				for (Entry<String, ArrayList<Integer>> currentEntry : remotePosition
						.entrySet()) {
					Map<OWLObjectPropertyExpression, Set<OWLIndividual>> valuesObject = individuals
							.get(i).getObjectPropertyValues(ontology);
					Map<OWLDataPropertyExpression, Set<OWLLiteral>> valuesData = individuals
							.get(i).getDataPropertyValues(ontology);
					ArrayList<String> dataKeys = new ArrayList<String>();
					ArrayList<String> objectKeys = new ArrayList<String>();
					ArrayList<OWLDataPropertyExpression> valuesDataKeys = new ArrayList<OWLDataPropertyExpression>(
							valuesData.keySet());
					ArrayList<OWLObjectPropertyExpression> valuesObjectKeys = new ArrayList<OWLObjectPropertyExpression>(
							valuesObject.keySet());
					for (int a = 0; a < valuesDataKeys.size(); a++)
						dataKeys.add(valuesDataKeys
								.get(a)
								.toString()
								.substring(
										valuesDataKeys.get(a).toString()
												.indexOf(SEPARATOR) + 1,
										valuesDataKeys.get(a).toString()
												.length() - 1));

					for (int a = 0; a < valuesObjectKeys.size(); a++)
						objectKeys.add(valuesObjectKeys
								.get(a)
								.toString()
								.substring(
										valuesObjectKeys.get(a).toString()
												.indexOf(SEPARATOR) + 1,
										valuesObjectKeys.get(a).toString()
												.length() - 1));
					String table = currentEntry.getKey();
					String tablebis = "";
					if (table.length() > "Value".length())
						tablebis = table.substring(0,
								table.length() - "Value".length());
					if (objectKeys.contains(table)
							|| dataKeys.contains(tablebis)) {

						ArrayList<Integer> value = currentEntry.getValue();
						result = result + "INSERT INTO " + table + "\n(";

						for (int v = 0; v < value.size(); v++) {
							result = result
									+ attributesRemoteTab[value.get(v)]
											.toString()
											.substring(
													attributesRemoteTab[value
															.get(v)].toString()
															.indexOf("/") + 1,
													attributesRemoteTab[value
															.get(v)].toString()
															.length());

							if (v != value.size() - 1) {
								result = result + ", ";

							}

						}

						result = result + ")\nVALUES(";
						for (int v = 0; v < value.size(); v++) {
							resultTab = insertIntoDataForeign(i, value.get(v),
									attributesRemoteTab, name);
							result = result + resultTab[0];
							name = (Boolean) resultTab[1];

							if (((String) resultTab[0]).length() > 0
									&& v != value.size() - 1) {
								result = result + ", ";
							}

							resultTab = insertIntoObjectForeign(i,
									value.get(v), attributesRemoteTab, name);
							result = result + resultTab[0];
							name = (Boolean) resultTab[1];

							if (((String) resultTab[0]).length() > 0
									&& v != value.size() - 1) {
								result = result + ", ";
							}

						}
						result = result + ");\n\n";
					}
				}
			}
		}

		return result;
	}

	/**
	 * \brief      Generate the sql script used to populate the tables (INSERT and UPDATE).
	 * * \return    A String with the insert into queries.
	 */
	@SuppressWarnings("unchecked")
	public String insertSuper(int i, String table, String[] attributesLocalTab,
			String attributesLocal, boolean name) {
		Object[] resultTab = new Object[2];
		String result = "";
		if (superClassesClean.containsKey(table)) {
			parent = superClassesClean.get(table);
			String[] attributesLocalTabSplit = new String[attributesLocalTab.length - 1];
			String attributesLocalSplit = "";
			for (int parent = 0; parent < superClassesClean.get(table).size(); parent++)
				if (attributesLocalTab[1] != null) {
					if (attributesLocalTab[1].contains("ID")) {
						for (int j = 0; j < attributesLocalTab.length; j++) {
							if (j == 0) {
								attributesLocalTabSplit[j] = attributesLocalTab[j];
								attributesLocalSplit = attributesLocalSplit
										+ attributesLocalTab[j];
							} else if (j != 1) {
								attributesLocalTabSplit[j - 1] = attributesLocalTab[j];
								attributesLocalSplit = attributesLocalSplit
										+ attributesLocalTab[j];
							}
						}

						result = result
								+ insertSuper(i, superClassesClean.get(table)
										.get(parent), attributesLocalTabSplit,
										attributesLocalSplit, name);
					} else
						result = result
								+ insertSuper(i, superClassesClean.get(table)
										.get(parent), attributesLocalTab,
										attributesLocal, name);
				}
		}
		int indice_max = 0;
		if (parent.size() == 0) {
			if (nbInsert.get(table) != null)
				nbInsert.put(table, nbInsert.get(table) + 1);
			else
				nbInsert.put(table, 1);
		} else if (nbInsert.get(parent.get(indice_max)) != null) {
			int max = 0;
			indice_max = 0;
			for (int c = 0; c < parent.size(); c++) {
				if (nbInsert.get(parent.get(c)) > max)
					indice_max = c;
			}
			nbInsert.put(table, nbInsert.get(parent.get(indice_max)) + 1);
		} else
			nbInsert.put(table, 1);

		Map<OWLDataPropertyExpression, Set<OWLLiteral>> valuesData = individuals
				.get(i).getDataPropertyValues(ontology);
		ArrayList<String> attributes = new ArrayList<String>();
		ArrayList<String> dataKeys = new ArrayList<String>();
		ArrayList<String> objectKeys = new ArrayList<String>();
		attributes = (ArrayList<String>) tables.get(table).clone();

		ArrayList<OWLDataPropertyExpression> valuesDataKeys = new ArrayList<OWLDataPropertyExpression>(
				valuesData.keySet());
		for (int a = 0; a < valuesDataKeys.size(); a++)
			dataKeys.add(valuesDataKeys
					.get(a)
					.toString()
					.substring(
							valuesDataKeys.get(a).toString().indexOf(SEPARATOR) + 1,
							valuesDataKeys.get(a).toString().length() - 1));
		Map<OWLObjectPropertyExpression, Set<OWLIndividual>> valuesObject = individuals
				.get(i).getObjectPropertyValues(ontology);
		ArrayList<OWLObjectPropertyExpression> valuesObjectKeys = new ArrayList<OWLObjectPropertyExpression>(
				valuesObject.keySet());
		for (int a = 0; a < valuesObjectKeys.size(); a++)
			objectKeys.add(valuesObjectKeys
					.get(a)
					.toString()
					.substring(
							valuesObjectKeys.get(a).toString()
									.indexOf(SEPARATOR) + 1,
							valuesObjectKeys.get(a).toString().length() - 1));

		for (int a = 0; a < attributes.size(); a++) {
			if (!dataKeys.contains(attributes.get(a))
					&& !objectKeys.contains(attributes.get(a))
					&& !attributes.get(a).contains("/")) {
				attributes.remove(a);
				a--;
			}
		}

		if (!superClassesClean.containsKey(table)) {
			attributes.add(0, "_NAME");

		} else {
			attributes.add(0, table + "ID");
			attributes.add(1, "_NAME");

		}

		String attributesLocalBis = "";
		for (int k = 0; k < attributes.size(); k++) {
			if (!attributes.get(k).contains("/")) {
				attributesLocalBis = attributesLocalBis + ", "
						+ attributes.get(k);
			}
		}
		String[] attributesLocalTabBis = attributesLocalBis.split(",");
		result = result + "INSERT INTO " + table + "\n("
				+ attributesLocalBis.substring(2) + ")\nVALUES(";
		String att = "";
		for (int lll = 0; lll < attributesLocalBis.substring(2).split(",").length; lll++) {
			if (objectKeys
					.contains(attributesLocalBis.substring(2).split(",")[lll]
							.replace(" ", ""))) {
				att = att + attributesLocalBis.substring(2).split(",")[lll]
						+ "=,";
			}
		}
		if (!att.equals("")) {
			resultUpdate = resultUpdate + "\n\nUPDATE " + table + "\n SET ";
		}

		if (superClassesClean.containsKey(table))
			result = result + nbInsert.get(parent.get(indice_max)) + ", ";
		// Adding data properties
		resultTab = insertIntoData(i, attributesLocalTabBis,
				attributesLocalBis, name);
		result = result + resultTab[0];
		name = (Boolean) resultTab[1];
		String where = "";
		if (!resultTab[0].toString().contains(","))
			where = resultTab[0].toString();
		else {
			where = resultTab[0].toString().substring(0,
					resultTab[0].toString().indexOf(","));

		}
		// Object properties
		resultTab = insertIntoObject(i, attributesLocalTabBis,
				attributesLocalBis, name);
		if (((String) resultTab[0]).length() > 0 && !result.endsWith(", "))
			result = result + ", ";
		if (!resultTab[0].equals("") && !att.equals("")) {

			for (int lll = 0; lll < resultTab[0].toString().split(",").length; lll++) {
				if (lll > 0)
					att = att.substring(att.indexOf("=,") + 2);

				if (lll < resultTab[0].toString().split(",").length - 1) {

					result = result + "NULL, ";// resultTab[0];
					resultUpdate = resultUpdate
							+ att.substring(0, att.indexOf("=,") + 2)
									.replaceFirst(
											"=,",
											"="
													+ resultTab[0].toString()
															.split(",")[lll])
							+ ",";
				} else {
					result = result + "NULL";// resultTab[0];
					resultUpdate = resultUpdate
							+ att.substring(0, att.indexOf("=,") + 2)
									.replaceFirst(
											"=,",
											"="
													+ resultTab[0].toString()
															.split(",")[lll]);
				}
			}
			resultTab = insertIntoData(i, attributesLocalTabBis,
					attributesLocalBis, name);

			resultUpdate = resultUpdate + " WHERE _NAME = " + where;
			resultUpdate = resultUpdate + ";";
		}
		result = result + ");\n\n";

		return result;
	}

	/**
	 * \brief      Write the script on the disk.
	 * \param    s	Data to write.
	 */
	public void write(String s) {
		Writer fstream;
		try {
			fstream = new FileWriter(path + "InsertInto.sql");

			BufferedWriter out = new BufferedWriter(fstream);
			out.write(s);
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	// Getter and Setter
	// Getter and setter
	public HashMap<String, ArrayList<String>> getTables() {
		return tables;
	}

	public void setTables(HashMap<String, ArrayList<String>> tables) {
		this.tables = tables;
	}

	public ArrayList<OWLIndividual> getIndividuals() {
		return individuals;
	}

	public void setIndividuals(ArrayList<OWLIndividual> individuals) {
		this.individuals = individuals;
	}

	public ArrayList<String> getIndividualsClean() {
		return individualsClean;
	}

	public void setIndividualsClean(ArrayList<String> individualsClean) {
		this.individualsClean = individualsClean;
	}

	public String getPath() {
		return path;
	}

	public void setPath(String path) {
		this.path = path;
	}

	public HashMap<String, Integer> getNbInsert() {
		return nbInsert;
	}

	public void setNbInsert(HashMap<String, Integer> nbInsert) {
		this.nbInsert = nbInsert;
	}

	public HashMap<String, ArrayList<String>> getSuperClassesClean() {
		return superClassesClean;
	}

	public void setSuperClassesClean(
			HashMap<String, ArrayList<String>> superClassesClean) {
		this.superClassesClean = superClassesClean;
	}
}
