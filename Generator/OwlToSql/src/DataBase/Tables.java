package DataBase;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;

public class Tables {

	private HashMap<String, String> unit = new HashMap<String, String>(); // OWLUnit=>SQLUnit
	static final char SEPARATOR = '#';
	private String path;
	private ArrayList<String> classesClean; // list of classes
	private HashMap<String, ArrayList<String>> superClassesClean;
	// Classe1=<SuperClasse1,SuperClasse2>,Classe2=<SuperClasse1,SuperClasse2>
	private ArrayList<ArrayList<String>> dataPropertiesClean;
	// <<Classe1, DataPropertyName1,DataPropertyName2>,<Classe2,
	// DataPropertyName1,DataPropertyName2>>
	private HashMap<String, String> dataSingleValued; // dataPropertyName =>
														// true or false
	private HashMap<String, String> dataRequired; // dataPropertyName => true or
													// false
	private ArrayList<ArrayList<String>> dataPropertyRanges;
	// <<ObjectPropertyName1,Range1,Range2...,<ObjectPropertyName2,Range1,Range2...>>
	private ArrayList<ArrayList<String>> objectPropertiesClean;
	// <<Classe1, ObjectPropertyName1,ObjectPropertyName2>,<Classe2,
	// ObjectPropertyName1,ObjectPropertyName2>>
	private HashMap<String, String> objectSingleValued; // ObjectPropertyName =>
														// true or false
	private HashMap<String, String> objectRequired; // ObjectPropertyName =>true
													// or false
	private HashMap<String, ArrayList<String>> objectPropertyRanges; // ObjectPropertyName
																		// =>
																		// Range(s)
	private HashMap<String, String> classesId; // Class => Id
	private HashMap<String, String> objectPropertyInverse; // property =>
															// inverse
	private HashMap<String, ArrayList<String>> tables;// Map : TableName =>
														// Attributes names

	// <Table1 => <Attribute1,Attribute2,TableForeignKey/ForeignKey...>,Table2
	// => <Attribute1,Attribute2,...> >

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
			HashMap<String, String> classesId,
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
		this.setClassesId(classesId);
		this.objectPropertyInverse = objectPropertyInverse;
		create(); // generate the SQL script used to create the tables
	}

	// generate the SQL script used to create the tables

	public void create() {
		ArrayList<String> temp;
		String s = "";
		for (int i = 0; i < classesClean.size(); i++) {
			if (!classesClean.get(i).equals("owl:Thing")) {
				// if (classesId.containsKey(classesClean.get(i))) {
				// s = s + "CREATE TABLE " + classesClean.get(i) + "("
				// + attributes(classesClean.get(i)) + "PRIMARY KEY ("
				// + classesId.get(classesClean.get(i))
				// + ")\n);\n\n";

				// } else {
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
						+ classesClean.get(i) + "ID, _NAME" + ")\n);\n\n";
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

	// generate the SQL foreign keys in the SQL script
	private String foreignKey() {
		String result = "";
		ArrayList<String> temp;
		for (int i = 0; i < objectPropertiesClean.size(); i++) {
			if (objectPropertiesClean.get(i).size() > 1) {
				for (int j = 1; j < objectPropertiesClean.get(i).size(); j++) {
					if (objectSingleValued.get(
							objectPropertiesClean.get(i).get(j)).equals("true")) {
						// rule 4 in the OWL to SQL Paper => one to zero or one
						if (objectPropertyInverse
								.containsKey(objectPropertiesClean.get(i)
										.get(j))
								&& objectSingleValued
										.containsKey(objectPropertyInverse
												.get(objectPropertiesClean.get(
														i).get(j)))
								&& objectSingleValued.get(
										objectPropertyInverse
												.get(objectPropertiesClean.get(
														i).get(j))).equals(
										"true")
								&& objectRequired
										.containsKey(objectPropertiesClean.get(
												i).get(j))
								&& objectRequired.get(
										objectPropertiesClean.get(i).get(j))
										.equals("true")) {

							if (objectPropertyRanges
									.containsKey(objectPropertiesClean.get(i)
											.get(j))) {
								ArrayList<String> value = objectPropertyRanges
										.get(objectPropertiesClean.get(i)
												.get(j));
								for (int p = 0; p < value.size(); p++) {
									result = result
											+ "\n\nALTER TABLE "
											+ value.get(p)
											+ "\nADD "
											+ objectPropertyInverse
													.get(objectPropertiesClean
															.get(i).get(j))
											+ " VARCHAR(255),"
											+ "\nADD CONSTRAINT fk"
											+ objectPropertyInverse
													.get(objectPropertiesClean
															.get(i).get(j))
											+ "\nFOREIGN KEY("
											+ objectPropertyInverse
													.get(objectPropertiesClean
															.get(i).get(j))
											+ ") REFERENCES "
											+ objectPropertiesClean.get(i).get(
													0) + "(NAME);";

									if (tables.containsKey(value.get(p))) {
										temp = tables.get(value.get(p));
									} else {
										temp = new ArrayList<String>();
									}

									if (!temp.contains(objectPropertyInverse
											.get(objectPropertiesClean.get(i)
													.get(j))))
										temp.add(objectPropertyInverse
												.get(objectPropertiesClean.get(
														i).get(j)));

									tables.put(value.get(p), temp);

									if (tables
											.containsKey(objectPropertiesClean
													.get(i).get(0))) {
										temp = tables.get(objectPropertiesClean
												.get(i).get(0));
									} else {
										temp = new ArrayList<String>();
									}

									if (!temp.contains(value.get(p)
											+ "/"
											+ objectPropertyInverse
													.get(objectPropertiesClean
															.get(i).get(j))))
										temp.add(value.get(p)
												+ "/"
												+ objectPropertyInverse
														.get(objectPropertiesClean
																.get(i).get(j)));

									tables.put(objectPropertiesClean.get(i)
											.get(0), temp);

								}

							}
						}
						// End rule 4
						else if (objectSingleValued.get(
								objectPropertiesClean.get(i).get(j)).equals(
								"true")) {
							// rule 5 in the OWL to SQL Paper => zero or one to
							// one
							if (!objectPropertyInverse
									.containsValue(objectPropertiesClean.get(i)
											.get(j))
									&& objectPropertyRanges
											.containsKey(objectPropertiesClean
													.get(i).get(j))) {
								ArrayList<String> value = objectPropertyRanges
										.get(objectPropertiesClean.get(i)
												.get(j));
								for (int p = 0; p < value.size(); p++) {
									result = result
											+ "\n\nALTER TABLE "
											+ objectPropertiesClean.get(i).get(
													0)
											+ "\nADD "
											+ objectPropertiesClean.get(i).get(
													j)
											+ " VARCHAR(255),"
											+ "\nADD CONSTRAINT fk"

											+ objectPropertiesClean.get(i).get(
													j)
											+ "\nFOREIGN KEY("
											+ objectPropertiesClean.get(i).get(
													j) + ") REFERENCES "
											+ value.get(p) + "(_NAME);";
									if (tables
											.containsKey(objectPropertiesClean
													.get(i).get(0))) {
										temp = tables.get(objectPropertiesClean
												.get(i).get(0));
									} else {
										temp = new ArrayList<String>();
									}
									if (!temp.contains(objectPropertiesClean
											.get(i).get(j)))
										temp.add(objectPropertiesClean.get(i)
												.get(j));
									tables.put(objectPropertiesClean.get(i)
											.get(0), temp);

								}
							}
						}

					}
					// End rule 5
					else if (objectSingleValued.get(
							objectPropertiesClean.get(i).get(j))
							.equals("false")) {
						// rule 6 in the OWL to SQL Paper => one to many
						if (objectPropertyInverse
								.containsKey(objectPropertiesClean.get(i)
										.get(j))
								&& objectSingleValued
										.containsKey(objectPropertyInverse
												.get(objectPropertiesClean.get(
														i).get(j)))
								&& objectSingleValued.get(
										objectPropertyInverse
												.get(objectPropertiesClean.get(
														i).get(j))).equals(
										"true")) {

							if (objectPropertyRanges
									.containsKey(objectPropertiesClean.get(i)
											.get(j))) {

								ArrayList<String> value = objectPropertyRanges
										.get(objectPropertiesClean.get(i)
												.get(j));
								for (int p = 0; p < value.size(); p++) {

									result = result
											+ "\n\nALTER TABLE "
											+ value.get(p)
											+ "\nADD "
											+ objectPropertyInverse
													.get(objectPropertiesClean
															.get(i).get(j))
											+ " VARCHAR(255),"
											+ "\nADD CONSTRAINT fk"

											+ objectPropertiesClean.get(i).get(
													j)
											+ "\nFOREIGN KEY("
											+ objectPropertyInverse
													.get(objectPropertiesClean
															.get(i).get(j))
											+ ") REFERENCES "
											+ objectPropertiesClean.get(i).get(
													0) + "(_NAME);";
									if (tables.containsKey(value.get(p))) {
										temp = tables.get(value.get(p));
									} else {
										temp = new ArrayList<String>();
									}

									temp.add(objectPropertyInverse
											.get(objectPropertiesClean.get(i)
													.get(j)));
									tables.put(value.get(p), temp);

									if (tables
											.containsKey(objectPropertiesClean
													.get(i).get(0))) {
										temp = tables.get(objectPropertiesClean
												.get(i).get(0));
									} else {
										temp = new ArrayList<String>();
									}

									temp.add(value.get(p)
											+ "/"
											+ objectPropertyInverse
													.get(objectPropertiesClean
															.get(i).get(j)));
									tables.put(objectPropertiesClean.get(i)
											.get(0), temp);
								}

							}
						}
						// End rule 6
						else {
							// rule 7 => many to many => assoctiation table
							if (objectPropertyRanges
									.containsKey(objectPropertiesClean.get(i)
											.get(j))) {
								ArrayList<String> value = objectPropertyRanges
										.get(objectPropertiesClean.get(i)
												.get(j));
								for (int p = 0; p < value.size(); p++) {
									if (p == 0) {
										if (!value.get(p).equals(
												objectPropertiesClean.get(i)
														.get(0))) {
											result = result
													+ "\n\nCREATE TABLE "
													+ objectPropertiesClean
															.get(i).get(j)
													+ "(\n"
													+ objectPropertiesClean
															.get(i).get(0)
													+ "ID INT NOT NULL,\n"
													+ value.get(p)
													+ "ID INT NOT NULL,"

													+ "\nPRIMARY KEY ("
													+ objectPropertiesClean
															.get(i).get(0)
													+ "ID," + value.get(p)
													+ "ID)\n);";
											if (tables
													.containsKey(objectPropertiesClean
															.get(i).get(j))) {
												temp = tables
														.get(objectPropertiesClean
																.get(i).get(j));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(objectPropertiesClean.get(
													i).get(0)
													+ "ID");
											temp.add(value.get(p) + "ID");
											tables.put(objectPropertiesClean
													.get(i).get(j), temp);

											if (tables
													.containsKey(objectPropertiesClean
															.get(i).get(0))) {
												temp = tables
														.get(objectPropertiesClean
																.get(i).get(0));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(objectPropertiesClean.get(
													i).get(j)
													+ "/"
													+ objectPropertiesClean
															.get(i).get(0)
													+ "ID");
											temp.add(objectPropertiesClean.get(
													i).get(j)
													+ "/" + value.get(p) + "ID");
											tables.put(objectPropertiesClean
													.get(i).get(0), temp);

										} else {
											// case if the ids of the
											// association table have the same
											// type
											result = result
													+ "\n\nCREATE TABLE "
													+ objectPropertiesClean
															.get(i).get(j)
													+ "(\n"
													+ objectPropertiesClean
															.get(i).get(0)
													+ "ID INT NOT NULL,\n"
													+ value.get(p)
													+ "2ID INT NOT NULL,"

													+ "\nPRIMARY KEY ("
													+ objectPropertiesClean
															.get(i).get(0)
													+ "ID," + value.get(p)
													+ "2ID)\n);";
											if (tables
													.containsKey(objectPropertiesClean
															.get(i).get(j))) {
												temp = tables
														.get(objectPropertiesClean
																.get(i).get(j));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(objectPropertiesClean.get(
													i).get(0)
													+ "ID");

											temp.add(value.get(p) + "2ID");

											tables.put(objectPropertiesClean
													.get(i).get(j), temp);

											if (tables
													.containsKey(objectPropertiesClean
															.get(i).get(0))) {
												temp = tables
														.get(objectPropertiesClean
																.get(i).get(0));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(objectPropertiesClean.get(
													i).get(j)
													+ "/"
													+ objectPropertiesClean
															.get(i).get(0)
													+ "ID");

											temp.add(objectPropertiesClean.get(
													i).get(j)
													+ "/"
													+ value.get(p)
													+ "2ID");
											tables.put(objectPropertiesClean
													.get(i).get(0), temp);

										}
									} else {
										// case if the association exist for
										// multiple ranges or domain
										// we must make severals association
										// and distinct tables
										if (!value.get(p).equals(
												objectPropertiesClean.get(i)
														.get(0))) {
											result = result
													+ "\n\nCREATE TABLE "
													+ objectPropertiesClean
															.get(i).get(j)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p)
													+ "(\n"
													+ objectPropertiesClean
															.get(i).get(0)
													+ "ID INT NOT NULL,\n"
													+ value.get(p)
													+ "ID INT NOT NULL,"

													+ "\nPRIMARY KEY ("
													+ objectPropertiesClean
															.get(i).get(0)
													+ "ID," + value.get(p)
													+ "ID)\n);";
											if (tables
													.containsKey(objectPropertiesClean
															.get(i).get(j)
															+ String.valueOf(i)
															+ String.valueOf(j)
															+ String.valueOf(p))) {
												temp = tables
														.get(objectPropertiesClean
																.get(i).get(j)
																+ String.valueOf(i)
																+ String.valueOf(j)
																+ String.valueOf(p));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(objectPropertiesClean.get(
													i).get(0)
													+ "ID");

											temp.add(value.get(p) + "ID");
											tables.put(
													objectPropertiesClean
															.get(i).get(j)
															+ String.valueOf(i)
															+ String.valueOf(j)
															+ String.valueOf(p),
													temp);
											if (tables
													.containsKey(objectPropertiesClean
															.get(i).get(0)
															+ String.valueOf(i)
															+ String.valueOf(j)
															+ String.valueOf(p))) {
												temp = tables
														.get(objectPropertiesClean
																.get(i).get(0)
																+ String.valueOf(i)
																+ String.valueOf(j)
																+ String.valueOf(p));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(objectPropertiesClean.get(
													i).get(j)
													+ "/"
													+ objectPropertiesClean
															.get(i).get(0)
													+ "ID");

											temp.add(objectPropertiesClean.get(
													i).get(j)
													+ "/" + value.get(p) + "ID");
											tables.put(
													objectPropertiesClean
															.get(i).get(0)
															+ String.valueOf(i)
															+ String.valueOf(j)
															+ String.valueOf(p),
													temp);
										} else {
											// case if the association exist for
											// multiple ranges or domain
											// we must make severals association
											// and distinct tables
											// and the 2 id have the same range
											// or domain
											result = result
													+ "\n\nCREATE TABLE "
													+ objectPropertiesClean
															.get(i).get(j)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p)
													+ "(\n"
													+ objectPropertiesClean
															.get(i).get(0)
													+ "ID INT NOT NULL,\n"
													+ value.get(p)
													+ "2ID INT NOT NULL,"

													+ "\nPRIMARY KEY ("
													+ objectPropertiesClean
															.get(i).get(0)
													+ "ID," + value.get(p)
													+ "2ID)\n);";
											if (tables
													.containsKey(objectPropertiesClean
															.get(i).get(j)
															+ String.valueOf(i)
															+ String.valueOf(j)
															+ String.valueOf(p))) {
												temp = tables
														.get(objectPropertiesClean
																.get(i).get(j)
																+ String.valueOf(i)
																+ String.valueOf(j)
																+ String.valueOf(p));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(objectPropertiesClean.get(
													i).get(0)
													+ "ID");

											temp.add(value.get(p) + "2ID");
											tables.put(
													objectPropertiesClean
															.get(i).get(j)
															+ String.valueOf(i)
															+ String.valueOf(j)
															+ String.valueOf(p),
													temp);

											if (tables
													.containsKey(objectPropertiesClean
															.get(i).get(0)
															+ String.valueOf(i)
															+ String.valueOf(j)
															+ String.valueOf(p))) {
												temp = tables
														.get(objectPropertiesClean
																.get(i).get(0)
																+ String.valueOf(i)
																+ String.valueOf(j)
																+ String.valueOf(p));
											} else {
												temp = new ArrayList<String>();
											}

											temp.add(objectPropertiesClean.get(
													i).get(j)
													+ String.valueOf(i)
													+ String.valueOf(j)
													+ String.valueOf(p)
													+ "/"
													+ objectPropertiesClean
															.get(i).get(0)
													+ "ID");

											temp.add(objectPropertiesClean.get(
													i).get(j)
													+ "/"
													+ value.get(p)
													+ "2ID");
											tables.put(
													objectPropertiesClean
															.get(i).get(0)
															+ String.valueOf(i)
															+ String.valueOf(j)
															+ String.valueOf(p),
													temp);
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

	// Save the SQL script
	public void write(String s) throws IOException {
		Writer fstream = new FileWriter(path + "CreateTable.sql");
		BufferedWriter out = new BufferedWriter(fstream);
		out.write(s);
		out.close();
	}

	// generate the attributes for a given class in the SQL script
	public String attributes(String c) {
		ArrayList<String> temp;
		String s = "\n";
		s = s + "_NAME varchar(100),\n";
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

	public HashMap<String, String> getObjectPropertyInverse() {
		return objectPropertyInverse;
	}

	public void setObjectPropertyInverse(
			HashMap<String, String> objectPropertyInverse) {
		this.objectPropertyInverse = objectPropertyInverse;
	}

	// give the corresponding SQL unit of an OWL one
	public String unit(String a) {
		if (!unit.containsKey(a))
			return "varchar(255)";

		return unit.get(a);
	}

	// fill the unit map - link the owl unit with the SQL ones
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

	// Getter and Setter
	public String getUnit(String s) {
		if (unit.containsKey(s))
			return unit.get(s);
		else
			return "varchar(255)";
	}

	public void setUnit(HashMap<String, String> unit) {
		this.unit = unit;
	}

	public String getPath() {
		return path;
	}

	public void setPath(String path) {
		this.path = path;
	}

	public ArrayList<String> getClassesClean() {
		return classesClean;
	}

	public void setClassesClean(ArrayList<String> classesClean) {
		this.classesClean = classesClean;
	}

	public HashMap<String, ArrayList<String>> getSuperClassesClean() {
		return superClassesClean;
	}

	public void setSuperClassesClean(
			HashMap<String, ArrayList<String>> superClassesClean) {
		this.superClassesClean = superClassesClean;
	}

	public ArrayList<ArrayList<String>> getDataPropertiesClean() {
		return dataPropertiesClean;
	}

	public void setDataPropertiesClean(
			ArrayList<ArrayList<String>> dataPropertiesClean) {
		this.dataPropertiesClean = dataPropertiesClean;
	}

	public HashMap<String, String> getDataSingleValued() {
		return dataSingleValued;
	}

	public void setDataSingleValued(HashMap<String, String> dataSingleValued) {
		this.dataSingleValued = dataSingleValued;
	}

	public HashMap<String, String> getDataRequired() {
		return dataRequired;
	}

	public void setDataRequired(HashMap<String, String> dataRequired) {
		this.dataRequired = dataRequired;
	}

	public ArrayList<ArrayList<String>> getDataPropertyRanges() {
		return dataPropertyRanges;
	}

	public void setDataPropertyRanges(
			ArrayList<ArrayList<String>> dataPropertyRanges) {
		this.dataPropertyRanges = dataPropertyRanges;
	}

	public ArrayList<ArrayList<String>> getObjectPropertiesClean() {
		return objectPropertiesClean;
	}

	public void setObjectPropertiesClean(
			ArrayList<ArrayList<String>> objectPropertiesClean) {
		this.objectPropertiesClean = objectPropertiesClean;
	}

	public HashMap<String, String> getObjectSingleValued() {
		return objectSingleValued;
	}

	public void setObjectSingleValued(HashMap<String, String> objectSingleValued) {
		this.objectSingleValued = objectSingleValued;
	}

	public HashMap<String, String> getObjectRequired() {
		return objectRequired;
	}

	public void setObjectRequired(HashMap<String, String> objectRequired) {
		this.objectRequired = objectRequired;
	}

	public HashMap<String, ArrayList<String>> getObjectPropertyRanges() {
		return objectPropertyRanges;
	}

	public void setObjectPropertyRanges(
			HashMap<String, ArrayList<String>> objectPropertyRanges) {
		this.objectPropertyRanges = objectPropertyRanges;
	}

	public static char getSeparator() {
		return SEPARATOR;
	}

	public HashMap<String, String> getClassesId() {
		return classesId;
	}

	public void setClassesId(HashMap<String, String> classesId) {
		this.classesId = classesId;
	}

	public HashMap<String, ArrayList<String>> getTables() {
		return tables;
	}

	public void setTables(HashMap<String, ArrayList<String>> tables) {
		this.tables = tables;
	}

}
