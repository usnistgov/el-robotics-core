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
 * \file      Tables.java
 * \author    Anthony Pietromartire \a pietromartire.anthony\@nist.gov
 * \version   1.0
 * \date      29 June 2012
 * \brief     Class for the tables.
 *
 */

/**
 * \class 	DataBase.Tables
 * \brief     Class for the tables.
 * \details   This class is used to manipulate the classes from the ontology 
 * 			  and generate the SQL script to create the tables associated to this classes in the MySQL DB. 
 */
package DataBase;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;

public class Tables {

	/**
	 * \brief      Map - Link between owl and sql unit
	 * \details OWLUnit=>SQLUnit
	 */
	private HashMap<String, String> unit = new HashMap<String, String>();
	/**
	 * \brief     Separator between URL and the class' name in the ontology.
	 */
	private static final char SEPARATOR = '#';
	/**
	 * \brief      Where we are going to save the script.
	 */
	private String path;
	/**
	 * \brief      List of classes in the ontology.
	 */
	private ArrayList<String> classesClean;
	/**
	 * \brief      List of the super classes without the URL before their name in the ontology.
	 * \details Classe1=<SuperClasse1,SuperClasse2>,Classe2=<SuperClasse1,SuperClasse2>
	 */
	private HashMap<String, ArrayList<String>> superClassesClean;
	/**
	 * \brief      List of the data properties without the URL before their name in the ontology.
	 * \details <<Classe1, DataPropertyName1,DataPropertyName2>,<Classe2,DataPropertyName1,DataPropertyName2>>
	 */
	private ArrayList<ArrayList<String>> dataPropertiesClean;
	/**
	 * \brief      Map - Used to know if a data property is single or multi valued
	 * \details dataPropertyName => true or false
	 */
	private HashMap<String, String> dataSingleValued; 
	/**
	 * \brief      Map - Used to know if a data property is required or optional valued
	 * \details dataPropertyName => true or false
	 */
	private HashMap<String, String> dataRequired; 
	/**
	 * \brief      List of the ranges for a given data property
	 * \details 	 <<DataPropertyName1,Range1,Range2...,<DataPropertyName2,Range1,Range2...>>
	 */
	private ArrayList<ArrayList<String>> dataPropertyRanges;
	/**
	 * \brief      List of the object properties without the URL before their name in the ontology.
	 * \details <<Classe1, ObjectPropertyName1,ObjectPropertyName2>
	 */
	private ArrayList<ArrayList<String>> objectPropertiesClean;
	/**
	 * \brief      Map - Used to know if a object property is single or multi valued
	 * \details ObjectPropertyName => true or false
	 */
	private HashMap<String, String> objectSingleValued; 
	/**
	 * \brief      Map - Used to know if an object property is required or optional valued
	 * \details ObjectPropertyName => true or false
	 */
	private HashMap<String, String> objectRequired; 
	/**
	 * \brief      List of the ranges for a given object property
	 * \details 	 <<ObjectPropertyName1,Range1,Range2...,<ObjectName2,Range1,Range2...>>
	 */
	private HashMap<String, ArrayList<String>> objectPropertyRanges;
	/**
	 * \brief      List of the inverse properties for a given one.
	 * \details 	 property => inverse
	 */	
	private HashMap<String, String> objectPropertyInverse; 
	/**
	 * \brief      Attributes for a given table.
	 * \details <Table1 => <Attribute1,Attribute2,TableForeignKey/ForeignKey...>
	 */
	private HashMap<String, ArrayList<String>> tables;

	/**
     *  \brief Constructor
     *  \details Constructor of the Individuals class.
     *  \param path 	Where we will save the create tables script file.
     *  \param cc 	List of the classes.
     *  \param dataPropertiesClean 	List of the data properties.
     *  \param dataSingleValued 	List of the data properties single valued or not.
     *  \param dataRequired 	List of the data properties required or not.
     *  \param dataPropertyRanges 	Ranges of the data properties.
     *  \param objectPropertiesClean 	List of the object properties.
     *  \param objectSingleValued 	List of the object properties single valued or not.
     *  \param objectRequired 	List of the object properties required or not.
     *  \param objectPropertyRanges 	Ranges of the object properties.
     *  \param superClassesClean 	List of the super classes.
     *  \param objectPropertyInverse 	List of the object inverse properties.
     */
	public Tables(String path, ArrayList<String> cc,
			ArrayList<ArrayList<String>> dataPropertiesClean,
			HashMap<String, String> dataSingleValued,
			HashMap<String, String> dataRequired,
			ArrayList<ArrayList<String>> dataPropertyRanges,
			ArrayList<ArrayList<String>> objectPropertiesClean,
			HashMap<String, String> objectSingleValued,
			HashMap<String, String> objectRequired,
			HashMap<String, ArrayList<String>> objectPropertyRanges,
			HashMap<String, ArrayList<String>> superClassesClean,
			HashMap<String, String> objectPropertyInverse) {
		fillUnit(); // fill the unit map - link the owl unit with the SQL ones
		classesClean = cc;
		tables = new HashMap<String, ArrayList<String>>();
		this.dataPropertiesClean = dataPropertiesClean;
		this.dataSingleValued = dataSingleValued;
		this.dataRequired = dataRequired;
		this.dataPropertyRanges = dataPropertyRanges;
		this.objectPropertiesClean = objectPropertiesClean;
		this.objectSingleValued = objectSingleValued;
		this.objectRequired = objectRequired;
		this.objectPropertyRanges = objectPropertyRanges;
		this.superClassesClean = superClassesClean;
		this.path = path;
		this.objectPropertyInverse = objectPropertyInverse;
		create(); // generate the SQL script used to create the tables
	}

	/**
	 * \brief Generate the SQL script used to create the tables.
	 */
	public void create() {
		ArrayList<String> temp;
		String s = "";
		for (int i = 0; i < classesClean.size(); i++) {
			if (!classesClean.get(i).equals("owl:Thing")) {
				if (superClassesClean.containsKey(classesClean.get(i))) {
					s = s + "CREATE TABLE " + classesClean.get(i) + "(\n"
							+ classesClean.get(i) + "ID INT NOT NULL,";
				} else {
					s = s + "CREATE TABLE " + classesClean.get(i) + "(\n"
							+ classesClean.get(i)
							+ "ID INT NOT NULL AUTO_INCREMENT, ";
				}
				if (tables.containsKey(classesClean.get(i))) {
					temp = tables.get(classesClean.get(i));
				} else {
					temp = new ArrayList<String>();
				}
				if (superClassesClean.containsKey(classesClean.get(i)))
					temp.add(classesClean.get(i) + "ID");
				temp.add("_NAME");
				tables.put(classesClean.get(i), temp);

				s = s + attributes(classesClean.get(i)) + "PRIMARY KEY ("
						+ classesClean.get(i) + "ID, _NAME" + ")\n)ENGINE=InnoDB;\n\n";
				// }
			}
		}
		// dataProperty multi valued => rule 3 in the OWL to SQL Paper
		for (Entry<String, String> currentEntry : dataSingleValued.entrySet()) {
			if (currentEntry.getValue().equals("false")) {
				String c = "";
				String u = "";
				for (int i = 0; i < dataPropertiesClean.size(); i++) {
					for (int j = 1; j < dataPropertiesClean.get(i).size(); j++) {
						if (dataPropertiesClean.get(i).get(j)
								.equals(currentEntry.getKey()))
							c = dataPropertiesClean.get(i).get(0);
					}
				}
				for (int i = 0; i < dataPropertyRanges.size(); i++) {
					for (int j = 0; j < dataPropertyRanges.get(i).size(); j++) {
						if (dataPropertyRanges.get(i).get(0)
								.equals(currentEntry.getKey())) {
							u = dataPropertyRanges.get(i).get(1);
							break;
						}
					}
				}
				s = s + "CREATE TABLE " + currentEntry.getKey() + "Value(\n"
						+ c + "ID INT NOT NULL,\n" + currentEntry.getKey()
						+ " " + unit(u) + " NOT NULL, " + "\nPRIMARY KEY (" + c
						+ "ID," + currentEntry.getKey() + ")\n);\n\n";

				if (tables.containsKey(currentEntry.getKey() + "Value")) {
					temp = tables.get(currentEntry.getKey() + "Value");
				} else {
					temp = new ArrayList<String>();
				}
				temp.add(c + "ID");
				temp.add(currentEntry.getKey());
				tables.put(currentEntry.getKey() + "Value", temp);

				if (tables.containsKey(c)) {
					temp = tables.get(c);
				} else {
					temp = new ArrayList<String>();
				}
				temp.add(currentEntry.getKey() + "Value/" + c + "ID");
				temp.add(currentEntry.getKey() + "Value/"
						+ currentEntry.getKey());
				tables.put(c, temp);

			}
		}
		// End rule 3

		try {
			write(s + foreignKey());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * \brief Generate the foreign keys constraints. 
	 * \return A String with the alter tables corresponding to these constraints.
	 */
	@SuppressWarnings("unchecked")
	public String foreignKey() {
		ArrayList<ArrayList<String>> opClean = new ArrayList<ArrayList<String>>();

		for (int i = 0; i < objectPropertiesClean.size(); i++) {
			opClean.add((ArrayList<String>) objectPropertiesClean.get(i)
					.clone());

		}

		String result = "";
		ArrayList<String> temp;
		for (int i = 0; i < opClean.size(); i++) {
			if (opClean.get(i).size() > 1) {
				for (int j = 1; j < opClean.get(i).size(); j++) {
					// deleting the inverse to not add useless properties
					for (int d = 0; d < objectPropertyRanges.get(
							opClean.get(i).get(j)).size(); d++) {
						for (int s = 0; s < opClean.size(); s++) {
							if (opClean
									.get(s)
									.get(0)
									.equals(objectPropertyRanges.get(
											opClean.get(i).get(j)).get(d))) {
								opClean.get(s).remove(
										objectPropertyInverse.get(opClean
												.get(i).get(j)));
								break;
							}
						}
					}

					if (objectSingleValued.get(opClean.get(i).get(j)).equals(
							"true")) {
						// rule 4 in the OWL to SQL Paper => one to zero or
						// one
						if (objectPropertyInverse.containsKey(opClean.get(i)
								.get(j))
								&& objectSingleValued
										.containsKey(objectPropertyInverse
												.get(opClean.get(i).get(j)))
								&& objectSingleValued.get(
										objectPropertyInverse.get(opClean
												.get(i).get(j))).equals("true")
								&& objectRequired.containsKey(opClean.get(i)
										.get(j))
								&& objectRequired.get(opClean.get(i).get(j))
										.equals("false")) {

							if (objectPropertyRanges.containsKey(opClean.get(i)
									.get(j))) {
								ArrayList<String> value = objectPropertyRanges
										.get(opClean.get(i).get(j));
								for (int p = 0; p < value.size(); p++) {
									result = result
											+ "\n\nALTER TABLE "
											+ value.get(p)
											+ "\nADD "
											+ objectPropertyInverse.get(opClean
													.get(i).get(j))
											+ " VARCHAR(255),"
											+ "\nADD CONSTRAINT fk"
											+ objectPropertyInverse.get(opClean
													.get(i).get(j))
											+ "\nFOREIGN KEY("
											+ objectPropertyInverse.get(opClean
													.get(i).get(j))
											+ ") REFERENCES "
											+ opClean.get(i).get(0)
											+ "(_NAME);";

									if (tables.containsKey(value.get(p))) {
										temp = tables.get(value.get(p));
									} else {
										temp = new ArrayList<String>();
									}

									if (!temp.contains(objectPropertyInverse
											.get(opClean.get(i).get(j))))
										temp.add(objectPropertyInverse
												.get(opClean.get(i).get(j)));

									tables.put(value.get(p), temp);

									if (tables.containsKey(opClean.get(i)
											.get(0))) {
										temp = tables
												.get(opClean.get(i).get(0));
									} else {
										temp = new ArrayList<String>();
									}

									if (!temp.contains(value.get(p)
											+ "/"
											+ objectPropertyInverse.get(opClean
													.get(i).get(j))))
										temp.add(value.get(p)
												+ "/"
												+ objectPropertyInverse
														.get(opClean.get(i)
																.get(j)));

									tables.put(opClean.get(i).get(0), temp);

								}

							}
						}
						// End rule 4
						else {
							// rule 5 in the OWL to SQL Paper => zero or one
							// to
							// one - many to one

							ArrayList<String> value = objectPropertyRanges
									.get(opClean.get(i).get(j));
							for (int p = 0; p < value.size(); p++) {
								result = result + "\n\nALTER TABLE "
										+ opClean.get(i).get(0) + "\nADD "
										+ opClean.get(i).get(j)
										+ " VARCHAR(255),"
										+ "\nADD CONSTRAINT fk"

										+ opClean.get(i).get(j)
										+ "\nFOREIGN KEY("
										+ opClean.get(i).get(j)
										+ ") REFERENCES " + value.get(p)
										+ "(_NAME);";
								if (tables.containsKey(opClean.get(i).get(0))) {
									temp = tables.get(opClean.get(i).get(0));
								} else {
									temp = new ArrayList<String>();
								}
								if (!temp.contains(opClean.get(i).get(j)))
									temp.add(opClean.get(i).get(j));
								tables.put(opClean.get(i).get(0), temp);

							}
						}

					}
					// End rule 5
					else if (objectSingleValued.get(opClean.get(i).get(j))
							.equals("false")) {
						// rule 6 in the OWL to SQL Paper => one to many
						if (objectPropertyInverse.containsKey(opClean.get(i)
								.get(j))
								&& objectSingleValued
										.containsKey(objectPropertyInverse
												.get(opClean.get(i).get(j)))
								&& objectSingleValued.get(
										objectPropertyInverse.get(opClean
												.get(i).get(j))).equals("true")) {

							if (objectPropertyRanges.containsKey(opClean.get(i)
									.get(j))) {

								ArrayList<String> value = objectPropertyRanges
										.get(opClean.get(i).get(j));
								for (int p = 0; p < value.size(); p++) {

									result = result
											+ "\n\nALTER TABLE "
											+ value.get(p)
											+ "\nADD "
											+ objectPropertyInverse.get(opClean
													.get(i).get(j))
											+ " VARCHAR(255),"
											+ "\nADD CONSTRAINT fk"

											+ objectPropertyInverse.get(opClean
													.get(i).get(j))
											+ "\nFOREIGN KEY("
											+ objectPropertyInverse.get(opClean
													.get(i).get(j))
											+ ") REFERENCES "
											+ opClean.get(i).get(0)
											+ "(_NAME);";
									if (tables.containsKey(value.get(p))) {
										temp = tables.get(value.get(p));
									} else {
										temp = new ArrayList<String>();
									}

									temp.add(objectPropertyInverse.get(opClean
											.get(i).get(j)));
									tables.put(value.get(p), temp);

									if (tables.containsKey(opClean.get(i)
											.get(0))) {
										temp = tables
												.get(opClean.get(i).get(0));
									} else {
										temp = new ArrayList<String>();
									}

									temp.add(value.get(p)
											+ "/"
											+ objectPropertyInverse.get(opClean
													.get(i).get(j)));
									tables.put(opClean.get(i).get(0), temp);
								}

							}
						}
						// End rule 6
						else {
							// rule 7 => many to many => assoctiation table
							if (objectPropertyRanges.containsKey(opClean.get(i)
									.get(j))) {
								ArrayList<String> value = objectPropertyRanges
										.get(opClean.get(i).get(j));
								for (int p = 0; p < value.size(); p++) {
									if (p == 0) {
										if (!value.get(p).equals(
												opClean.get(i).get(0))) {
											result = result
													+ "\n\nCREATE TABLE "
													+ opClean.get(i).get(j)
													+ "(\n"
													+ opClean.get(i).get(0)
													+ "ID INT NOT NULL,\n"
													+ value.get(p)
													+ "ID INT NOT NULL,"

													+ "\nPRIMARY KEY ("
													+ opClean.get(i).get(0)
													+ "ID," + value.get(p)
													+ "ID)\n);";
											if (tables.containsKey(opClean.get(
													i).get(j))) {
												temp = tables.get(opClean
														.get(i).get(j));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(opClean.get(i).get(0)
													+ "ID");
											temp.add(value.get(p) + "ID");
											tables.put(opClean.get(i).get(j),
													temp);

											if (tables.containsKey(opClean.get(
													i).get(0))) {
												temp = tables.get(opClean
														.get(i).get(0));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(opClean.get(i).get(j)
													+ "/"
													+ opClean.get(i).get(0)
													+ "ID");
											temp.add(opClean.get(i).get(j)
													+ "/" + value.get(p) + "ID");
											tables.put(opClean.get(i).get(0),
													temp);

										} else {
											// case if the ids of the
											// association table have the
											// same
											// type
											result = result
													+ "\n\nCREATE TABLE "
													+ opClean.get(i).get(j)
													+ "(\n"
													+ opClean.get(i).get(0)
													+ "ID INT NOT NULL,\n"
													+ value.get(p)
													+ "2ID INT NOT NULL,"

													+ "\nPRIMARY KEY ("
													+ opClean.get(i).get(0)
													+ "ID," + value.get(p)
													+ "2ID)\n);";
											if (tables.containsKey(opClean.get(
													i).get(j))) {
												temp = tables.get(opClean
														.get(i).get(j));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(opClean.get(i).get(0)
													+ "ID");

											temp.add(value.get(p) + "2ID");

											tables.put(opClean.get(i).get(j),
													temp);

											if (tables.containsKey(opClean.get(
													i).get(0))) {
												temp = tables.get(opClean
														.get(i).get(0));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(opClean.get(i).get(j)
													+ "/"
													+ opClean.get(i).get(0)
													+ "ID");

											temp.add(opClean.get(i).get(j)
													+ "/" + value.get(p)
													+ "2ID");
											tables.put(opClean.get(i).get(0),
													temp);

										}
									} else {
										// case if the association exist for
										// multiple ranges or domain
										// we must make severals association
										// and distinct tables
										if (!value.get(p).equals(
												opClean.get(i).get(0))) {
											result = result
													+ "\n\nCREATE TABLE "
													+ opClean.get(i).get(j)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p) + "(\n"
													+ opClean.get(i).get(0)
													+ "ID INT NOT NULL,\n"
													+ value.get(p)
													+ "ID INT NOT NULL,"

													+ "\nPRIMARY KEY ("
													+ opClean.get(i).get(0)
													+ "ID," + value.get(p)
													+ "ID)\n);";
											if (tables.containsKey(opClean.get(
													i).get(j)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p))) {
												temp = tables.get(opClean
														.get(i).get(j)
														+ String.valueOf(i)
														+ String.valueOf(j)
														+ String.valueOf(p));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(opClean.get(i).get(0)
													+ "ID");

											temp.add(value.get(p) + "ID");
											tables.put(opClean.get(i).get(j)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p), temp);
											if (tables.containsKey(opClean.get(
													i).get(0)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p))) {
												temp = tables.get(opClean
														.get(i).get(0)
														+ String.valueOf(i)
														+ String.valueOf(j)
														+ String.valueOf(p));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(opClean.get(i).get(j)
													+ "/"
													+ opClean.get(i).get(0)
													+ "ID");

											temp.add(opClean.get(i).get(j)
													+ "/" + value.get(p) + "ID");
											tables.put(opClean.get(i).get(0)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p), temp);
										} else {
											// case if the association exist
											// for
											// multiple ranges or domain
											// we must make severals
											// association
											// and distinct tables
											// and the 2 id have the same
											// range
											// or domain
											result = result
													+ "\n\nCREATE TABLE "
													+ opClean.get(i).get(j)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p) + "(\n"
													+ opClean.get(i).get(0)
													+ "ID INT NOT NULL,\n"
													+ value.get(p)
													+ "2ID INT NOT NULL,"

													+ "\nPRIMARY KEY ("
													+ opClean.get(i).get(0)
													+ "ID," + value.get(p)
													+ "2ID)\n);";
											if (tables.containsKey(opClean.get(
													i).get(j)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p))) {
												temp = tables.get(opClean
														.get(i).get(j)
														+ String.valueOf(i)
														+ String.valueOf(j)
														+ String.valueOf(p));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(opClean.get(i).get(0)
													+ "ID");

											temp.add(value.get(p) + "2ID");
											tables.put(opClean.get(i).get(j)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p), temp);

											if (tables.containsKey(opClean.get(
													i).get(0)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p))) {
												temp = tables.get(opClean
														.get(i).get(0)
														+ String.valueOf(i)
														+ String.valueOf(j)
														+ String.valueOf(p));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(opClean.get(i).get(j)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p) + "/"
													+ opClean.get(i).get(0)
													+ "ID");

											temp.add(opClean.get(i).get(j)
													+ "/" + value.get(p)
													+ "2ID");
											tables.put(opClean.get(i).get(0)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p), temp);
										}
									}
								}
							}
						}
						// End rule 7
					}
				}
			}
		}

		return result;
	}

	/**
	 * \brief Save the sql script on the disk. 
	 * \param s Data to write.
	 */
	public void write(String s) throws IOException {
		Writer fstream = new FileWriter(path + "CreateTable.sql");
		BufferedWriter out = new BufferedWriter(fstream);
		out.write(s);
		out.close();
	}

	/**
	 * \brief Give the attributes for a given table
	 *  \param c Class we want the attributes. 
	 * \return A String with these attributes.
	 */
	public String attributes(String c) {
		ArrayList<String> temp;
		String s = "\n";
		s = s + "_NAME varchar(255), INDEX (_NAME),\n";
		ArrayList<String[]> checkUnit = new ArrayList<String[]>();
		for (int i = 0; i < dataPropertiesClean.size(); i++) {
			if (dataPropertiesClean.get(i).get(0).equals(c)) {
				for (int j = 1; j < dataPropertiesClean.get(i).size(); j++) {
					if (dataSingleValued.containsKey(dataPropertiesClean.get(i)
							.get(j))
							&& dataSingleValued.get(
									dataPropertiesClean.get(i).get(j)).equals(
									"true")) {
						for (int k = 0; k < dataPropertyRanges.size(); k++) {
							if (dataPropertyRanges.get(k).get(0)
									.equals(dataPropertiesClean.get(i).get(j))) {
								for (int l = 1; l < dataPropertyRanges.get(k)
										.size(); l++) {

									s = s + dataPropertiesClean.get(i).get(j);
									if (tables.containsKey(c)) {
										temp = tables.get(c);
									} else {
										temp = new ArrayList<String>();
									}
									temp.add(dataPropertiesClean.get(i).get(j));
									tables.put(c, temp);
									s = s
											+ " "
											+ unit(dataPropertyRanges.get(k)
													.get(l));
									if ((dataPropertyRanges.get(k).get(l)
											.startsWith("positive") || (dataPropertyRanges
											.get(k).get(l)
											.startsWith("unsigned")))
											|| (dataPropertyRanges.get(k)
													.get(l)
													.startsWith("nonNegative"))) {
										String[] ts = {
												dataPropertiesClean.get(i).get(
														j), ">= 0", };
										checkUnit.add(ts);
									}
									if ((dataPropertyRanges.get(k).get(l)
											.startsWith("negative") || (dataPropertyRanges
											.get(k).get(l)
											.startsWith("nonPositive")))) {
										String[] ts = {
												dataPropertiesClean.get(i).get(
														j), "=< 0", };
										checkUnit.add(ts);
									}

									if (dataRequired
											.containsKey(dataPropertiesClean
													.get(i).get(j))
											&& dataRequired.get(
													dataPropertiesClean.get(i)
															.get(j)).equals(
													"true")) {
										s = s + " NOT NULL,\n";
									} else {
										s = s + ",\n";
									}

								}
							}
						}
					}
				}
			}
		}

		for (int q = 0; q < checkUnit.size(); q++) {
			s = s + "CHECK(" + checkUnit.get(q)[0] + " " + checkUnit.get(q)[1]
					+ "),\n";
		}
		return s;
	}

	/**
	 * \brief Give the corresponding SQL unit of an OWL one.
	 */
	public String unit(String a) {
		if (!unit.containsKey(a))
			return "varchar(255)";

		return unit.get(a);
	}

	/**
	 * \brief Fill the map used to link the owl unit and the SQL ones
	 */
	public void fillUnit() {
		unit.put("Short", "SMALLINT");
		unit.put("unsignedShort", "SMALLINT");
		unit.put("integer", "INTEGER");
		unit.put("positiveInteger", "INTEGER");
		unit.put("negativeInteger", "INTEGER");
		unit.put("nonPositiveInteger", "INTEGER");
		unit.put("nonNegativeInteger", "INTEGER");
		unit.put("int", "INTEGER");
		unit.put("unsignedInt", "INTEGER");
		unit.put("long", "INTEGER");
		unit.put("unsignedLong", "INTEGER");
		unit.put("decimal", "DOUBLE");
		unit.put("float", "FLOAT");
		unit.put("double", "DOUBLE PRECISION");
		unit.put("string", "varchar(255)");
		unit.put("normalizedString", "varchar(255)");
		unit.put("token", "varchar(100)");
		unit.put("language", "varchar(100)");
		unit.put("NMTOKEN", "varchar(100)");
		unit.put("Name", "varchar(100)");
		unit.put("NCName", "varchar(100)");
		unit.put("time", "TIME");
		unit.put("date", "DATE");
		unit.put("datetime", "TIMESTAMP");
		unit.put("gYearMonth", "DATE");
		unit.put("gMonthDay", "DATE");
		unit.put("gDay", "DATE");
		unit.put("gMonth", "DATE");
		unit.put("boolean", "boolean");
		unit.put("hexBinary", "varchar(100)");
		unit.put("hexBinary", "varchar(100)");
		unit.put("anyURI", "varchar(100)");
		unit.put("angleUnit", "varchar(20)");
		unit.put("lengthUnit", "varchar(20)");
		unit.put("weightUnit", "varchar(20)");
		unit.put("positiveDecimal", "DOUBLE");
	}

	/**
	 * \brief Simple getter.
	 * \return ObjectPropertyInverse
	 */
	public HashMap<String, String> getObjectPropertyInverse() {
		return objectPropertyInverse;
	}
	/**
	 * \brief Simple setter.
	 * \param objectPropertyInverse
	 */
	public void setObjectPropertyInverse(
			HashMap<String, String> objectPropertyInverse) {
		this.objectPropertyInverse = objectPropertyInverse;
	}
	/**
	 * \brief Simple setter.
	 * \param unit
	 */
	public void setUnit(HashMap<String, String> unit) {
		this.unit = unit;
	}
	/**
	 * \brief Simple getter.
	 * \return Path
	 */
	public String getPath() {
		return path;
	}
	/**
	 * \brief Simple setter.
	 * \param path
	 */
	public void setPath(String path) {
		this.path = path;
	}
	/**
	 * \brief Simple getter.
	 * \return ClassesClean
	 */
	public ArrayList<String> getClassesClean() {
		return classesClean;
	}
	/**
	 * \brief Simple setter.
	 * \param classesClean
	 */
	public void setClassesClean(ArrayList<String> classesClean) {
		this.classesClean = classesClean;
	}
	/**
	 * \brief Simple getter.
	 * \return SuperClassesClean
	 */
	public HashMap<String, ArrayList<String>> getSuperClassesClean() {
		return superClassesClean;
	}
	/**
	 * \brief Simple setter.
	 * \param superClassesClean
	 */
	public void setSuperClassesClean(
			HashMap<String, ArrayList<String>> superClassesClean) {
		this.superClassesClean = superClassesClean;
	}
	/**
	 * \brief Simple getter.
	 * \return DataPropertiesClean
	 */
	public ArrayList<ArrayList<String>> getDataPropertiesClean() {
		return dataPropertiesClean;
	}
	/**
	 * \brief Simple setter.
	 * \param dataPropertiesClean
	 */
	public void setDataPropertiesClean(
			ArrayList<ArrayList<String>> dataPropertiesClean) {
		this.dataPropertiesClean = dataPropertiesClean;
	}
	/**
	 * \brief Simple getter.
	 * \return DataSingleValued
	 */
	public HashMap<String, String> getDataSingleValued() {
		return dataSingleValued;
	}
	/**
	 * \brief Simple setter.
	 * \param dataSingleValued
	 */
	public void setDataSingleValued(HashMap<String, String> dataSingleValued) {
		this.dataSingleValued = dataSingleValued;
	}
	/**
	 * \brief Simple getter.
	 * \return DataRequired
	 */
	public HashMap<String, String> getDataRequired() {
		return dataRequired;
	}
	/**
	 * \brief Simple setter.
	 * \param dataRequired
	 */
	public void setDataRequired(HashMap<String, String> dataRequired) {
		this.dataRequired = dataRequired;
	}
	/**
	 * \brief Simple getter.
	 * \return DataPropertyRanges
	 */
	public ArrayList<ArrayList<String>> getDataPropertyRanges() {
		return dataPropertyRanges;
	}
	/**
	 * \brief Simple setter.
	 * \param dataPropertyRanges
	 */
	public void setDataPropertyRanges(
			ArrayList<ArrayList<String>> dataPropertyRanges) {
		this.dataPropertyRanges = dataPropertyRanges;
	}
	/**
	 * \brief Simple getter.
	 * \return ObjectPropertiesClean
	 */
	public ArrayList<ArrayList<String>> getObjectPropertiesClean() {
		return objectPropertiesClean;
	}
	/**
	 * \brief Simple setter.
	 * \param objectPropertiesClean
	 */
	public void setObjectPropertiesClean(
			ArrayList<ArrayList<String>> objectPropertiesClean) {
		this.objectPropertiesClean = objectPropertiesClean;
	}
	/**
	 * \brief Simple getter.
	 * \return ObjectSingleValued
	 */
	public HashMap<String, String> getObjectSingleValued() {
		return objectSingleValued;
	}
	/**
	 * \brief Simple setter.
	 * \param objectSingleValued
	 */
	public void setObjectSingleValued(HashMap<String, String> objectSingleValued) {
		this.objectSingleValued = objectSingleValued;
	}
	/**
	 * \brief Simple getter.
	 * \return ObjectRequired
	 */
	public HashMap<String, String> getObjectRequired() {
		return objectRequired;
	}
	/**
	 * \brief Simple setter.
	 * \param objectRequired
	 */
	public void setObjectRequired(HashMap<String, String> objectRequired) {
		this.objectRequired = objectRequired;
	}
	/**
	 * \brief Simple getter.
	 * \return ObjectPropertyRanges
	 */
	public HashMap<String, ArrayList<String>> getObjectPropertyRanges() {
		return objectPropertyRanges;
	}
	/**
	 * \brief Simple setter.
	 * \param objectPropertyRanges
	 */
	public void setObjectPropertyRanges(
			HashMap<String, ArrayList<String>> objectPropertyRanges) {
		this.objectPropertyRanges = objectPropertyRanges;
	}
	/**
	 * \brief Simple getter.
	 * \return Separator
	 */
	public static char getSeparator() {
		return SEPARATOR;
	}
	/**
	 * \brief Simple getter.
	 * \return Tables
	 */
	public HashMap<String, ArrayList<String>> getTables() {
		return tables;
	}
	/**
	 * \brief Simple setter.
	 * \param tables
	 */
	public void setTables(HashMap<String, ArrayList<String>> tables) {
		this.tables = tables;
	}

}
