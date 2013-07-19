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
 * \file      DaoGenerator.java
 * \author    Anthony Pietromartire \a pietromartire.anthony\@nist.gov
 * \version   1.0
 * \date      29 June 2012
 * \brief     Class for the C++ Data Access Object.
 */

/**
 * \class ClassesCPP.DaoGenerator
 * \brief Class for the C++ Data Access Object.
 * \details   This class is used to generate the C++ specific file used to interact with the DB.
 */

package ClassesCPP;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;

public class DaoGenerator {
	/**
	 * \brief Map - Key : table name => Value : attributes names. \details
	 * <Table1 => <Attribute1,Attribute2,TableForeignKey/ForeignKey...>
	 */
	private HashMap<String, ArrayList<String>> tables;
	/**
	 * \brief Map - Key : class name => Value : super classes names. \details
	 * Classe1=<SuperClasse1,SuperClasse2>,Classe2=<SuperClasse1,SuperClasse2>
	 */
	private HashMap<String, ArrayList<String>> superClasses;
	/**
	 * \brief List of classes.
	 */
	private ArrayList<String> classes;
	/**
	 * \brief Map - Key : property name => Value : inverse property name.
	 */
	private HashMap<String, String> objectPropertiesInverse;
	/**
	 * \brief Map - Key : object property name => Value : true or false.
	 */
	private HashMap<String, String> objectPropertiesSingleValued;
	/**
	 * \brief Map - Key : object property name => Value : Range(s).
	 */
	private HashMap<String, ArrayList<String>> objectPropertyRanges;
	/**
	 * \brief Map - Key : Type => Value : query.
	 */
	private HashMap<String, String> getDataSingleSql;
	/**
	 * \brief Map - Key : Type => Value : (-)name of table / attribute : if in
	 * relation in (not) the DB.
	 */
	private HashMap<String, ArrayList<String>> getObjectSingleSql;
	/**
	 * \brief Map - Key : Type => Value : query.
	 */
	private HashMap<String, ArrayList<String>> getDataMultiSql;
	/**
	 * \brief Map - Key : Type => Value : name of table / attribute.
	 */
	private HashMap<String, ArrayList<String>> getObjectMultiSql;

	/**
	 * \brief Constructor \details Constructor of the DaoGenerator class. \param
	 * tables Collections of the tables and attributes. \param superClasses
	 * Collections of the superclasses. \param classes List of the classes.
	 * \param objectPropertiesInverse List of the object inverse properties.
	 * \param objectPropertiesSingleValued List of the object properties single
	 * valued or not. \param objectPropertyRanges Ranges of the object
	 * properties. \param dataPropertiesSingleValued List of the data properties
	 * single valued or not.
	 */
	public DaoGenerator(HashMap<String, ArrayList<String>> tables,
			HashMap<String, ArrayList<String>> superClasses,
			ArrayList<String> classes,
			HashMap<String, String> objectPropertiesInverse,
			HashMap<String, String> objectPropertiesSingleValued,
			HashMap<String, ArrayList<String>> objectPropertyRanges,
			HashMap<String, String> dataPropertiesSingleValued) {
		this.tables = tables;
		this.superClasses = superClasses;
		this.classes = classes;
		this.objectPropertiesSingleValued = objectPropertiesSingleValued;
		this.objectPropertiesInverse = objectPropertiesInverse;
		this.objectPropertyRanges = objectPropertyRanges;
		getDataSingleSql = new HashMap<String, String>();
		getObjectMultiSql = new HashMap<String, ArrayList<String>>();
		getObjectSingleSql = new HashMap<String, ArrayList<String>>();
		getDataMultiSql = new HashMap<String, ArrayList<String>>();

	}

	/**
	 * \brief Generate the header file for the data access object. \param
	 * attributes List of the attributes. \param unit List of the units of the
	 * attributes. \param url Host of your DB. \param user User name in the DB.
	 * \param pass Password of the user in the DB. \param nameDb DB Schema.
	 * \return A String with the whole header file
	 */
	public String generateHeader(ArrayList<String> attributes,
			ArrayList<String> unit, String url, String user, String pass,
			String nameDb) {
		generateGetSQL();
		String result = "";
		String include = "";
		include = include
				+ "/*****************************************************************************\n";
		include = include + "   DISCLAIMER:\n";
		include = include
				+ "   This software was produced by the National Institute of Standards\n";
		include = include
				+ "   and Technology (NIST), an agency of the U.S. government, and by \n\n";
		include = include + "statute is\n";
		include = include
				+ "   not subject to copyright in the United States.  Recipients of this \n\n";
		include = include + "software\n";
		include = include
				+ "   assume all responsibility associated with its operation, modification,\n";
		include = include + "   maintenance, and subsequent redistribution.\n";
		include = include + "\n";
		include = include
				+ "   See NIST Administration Manual 4.09.07 b and Appendix I.\n";
		include = include
				+ " *****************************************************************************/\n\n";
		include = include + "\n#ifndef DAO_H_\n#define DAO_H_\n";
		include = include + "#include <cstdlib>\n#include <iostream>\n";
		include = include + "\n#include <map>";
		include = include + "\n#include <vector>";
		include = include + "\n#include <sstream>";
		include = include + "\n#include \"Connection.h\"";
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
		priv = priv + "std::vector<std::string> nameDone;\n"
				+ "std::map<std::string, std::string> map;\n"
				+ "std::string path;\n" + "std::string pathmulti;\n";

		priv = priv + "\nstatic std::map<std::string,std::string>"
				+ "getSqlQueriesDataSingle;"
				+ "\nstatic std::map<std::string,std::vector<std::string> > "
				+ "getSqlQueriesDataMulti;"
				+ "\nstatic std::map<std::string,std::vector<std::string> > "
				+ "getSqlQueriesObjectSingle;"
				+ "\nstatic std::map<std::string,std::vector<std::string> > "
				+ "getSqlQueriesObjectMulti;"
				+ "\nstatic std::map<std::string,std::vector<std::string> > "
				+ "setSqlQueries;"
				+ "\nstatic std::map<std::string,std::vector<std::string> > "
				+ "updateSqlQueries;";

		priv = priv + "\nvoid fillGetSqlQueries();";
		String pub = "public:";
		pub = pub + "\n DAO(std::string name);";
		pub = pub + "\n ~DAO();";
		for (int i = 0; i < attributes.size(); i++) {
			pub = pub + "\n" + unit.get(i) + " get" + attributes.get(i) + "();";
			pub = pub + "\nvoid set" + attributes.get(i) + "(" + unit.get(i)
					+ " _" + attributes.get(i) + ");";

		}

		pub = pub
				+ "\n	std::map<std::string, std::string> get(std::string name);";
		pub = pub + "\nvoid set(std::map<std::string,std::string> data);";
		pub = pub
				+ "\nstd::vector<std::string> Explode(const std::string & str, char separator);";
		pub = pub
				+ "\nstd::map<std::string, std::vector<std::string> > getAll(std::vector<std::string> attributesList, std::string table);";
		pub = pub + "\n}; \n#endif /* DAO_H_ */";

		result = include + priv + pub;

		return result;
	}

	/**
	 * \brief Generate the queries used to interact with the DB. \details Fill
	 * out 4 differents std vectors :
	 * <ul>
	 * <li>One for the data single valued</li>
	 * <li>One for the data multi valued</li>
	 * <li>One for the object single valued : foreign keys</li>
	 * <li>One for the object multi valued : association tables</li>
	 * </ul>
	 */
	public void fillGetSqlQueries() {
		String querie = "";
		String table = "";

		for (Entry<String, ArrayList<String>> currentEntry : tables.entrySet()) {
			String select = "SELECT ";
			String from = " FROM";
			String where = " WHERE ";
			table = currentEntry.getKey();
			if (classes.contains(table)) {
				querie = "";
				String queryAttributesDataSingle = "";
				String queryAttributesDataMulti = "";
				String queryTables = "";
				String temp = table + " " + getParent(table);
				String[] dbtables = temp.split(" ");

				for (int i = 0; i < dbtables.length; i++) {
					if (i == 0)
						queryTables = queryTables + " " + dbtables[i];
					else
						queryTables = queryTables + ", " + dbtables[i];

					if (!tables.get(dbtables[i]).get(0).contains("ID"))
						tables.get(dbtables[i]).add(0, dbtables[i] + "ID");

					for (String attribute : tables.get(dbtables[i])) {
						if (!attribute.contains("/")) {
							// Data Single Valued or Object Property
							if (!objectPropertiesSingleValued
									.containsKey(attribute)) {
								// Data Single Valued
								if (queryAttributesDataSingle.length() == 0)
									queryAttributesDataSingle = queryAttributesDataSingle
											+ dbtables[i]
											+ "."
											+ attribute
											+ " AS '"
											+ dbtables[i]
											+ "."
											+ attribute + "'";
								else if (attribute.equals("_NAME")
										&& !queryAttributesDataSingle
												.contains("_NAME"))
									queryAttributesDataSingle = queryAttributesDataSingle
											+ ", "
											+ dbtables[i]
											+ "."
											+ attribute
											+ " AS '"
											+ dbtables[i]
											+ "." + attribute + "'";
								else if (attribute.equals(dbtables[i] + "ID")
										&& !queryAttributesDataSingle
												.contains("ID"))
									queryAttributesDataSingle = queryAttributesDataSingle
											+ ", "
											+ dbtables[i]
											+ "."
											+ attribute
											+ " AS '"
											+ dbtables[i]
											+ "." + attribute + "'";
								else if (!(attribute.equals(dbtables[i] + "ID") || attribute
										.equals("_NAME")))
									queryAttributesDataSingle = queryAttributesDataSingle
											+ ", "
											+ dbtables[i]
											+ "."
											+ attribute
											+ " AS '"
											+ dbtables[i]
											+ "." + attribute + "'";

							}
							// Object property single valued
							else if (objectPropertiesSingleValued
									.get(attribute).equals("true")) {

								if (!objectPropertyRanges.get(attribute).get(0)
										.equals(dbtables[i])) {

									if (!getObjectSingleSql
											.containsKey(dbtables[i]))
										getObjectSingleSql.put(dbtables[i],
												new ArrayList<String>());
									if (!getObjectSingleSql.get(dbtables[i])
											.contains(
													objectPropertyRanges.get(
															attribute).get(0)
															+ "/" + attribute))
										getObjectSingleSql.get(dbtables[i])
												.add(objectPropertyRanges.get(
														attribute).get(0)
														+ "/" + attribute);
									if (!getObjectSingleSql
											.containsKey(objectPropertyRanges
													.get(attribute).get(0)))
										getObjectSingleSql.put(
												objectPropertyRanges.get(
														attribute).get(0),
												new ArrayList<String>());
									if (!getObjectSingleSql.get(
											objectPropertyRanges.get(attribute)
													.get(0))
											.contains(
													"-" + dbtables[i] + "/"
															+ attribute))
										getObjectSingleSql.get(
												objectPropertyRanges.get(
														attribute).get(0)).add(
												"-" + dbtables[i] + "/"
														+ attribute);
								}
							}

						} else {
							// Data Property Multi Valued
							if (!objectPropertiesSingleValued
									.containsKey(attribute.substring(0,
											attribute.indexOf("/")))
									&& !objectPropertiesInverse
											.containsKey(attribute
													.substring(attribute
															.indexOf("/") + 1))) {
								queryAttributesDataMulti = attribute;

							}

							else {
								// object Property Multi Valued
								if (objectPropertiesSingleValued
										.containsKey(attribute.substring(0,
												attribute.indexOf("/")))) {
									if (objectPropertiesSingleValued.get(
											attribute.substring(0,
													attribute.indexOf("/")))
											.equals(("false"))) {
										if (!getObjectMultiSql
												.containsKey(dbtables[i]))
											getObjectMultiSql.put(dbtables[i],
													new ArrayList<String>());
										if (!getObjectMultiSql
												.get(dbtables[i])
												.contains(
														objectPropertyRanges
																.get(attribute
																		.substring(
																				0,
																				attribute
																						.indexOf("/")))
																.get(0)
																+ "/"
																+ attribute
																		.substring(
																				0,
																				attribute
																						.indexOf("/")))) {
											getObjectMultiSql
													.get(dbtables[i])
													.add(objectPropertyRanges
															.get(attribute
																	.substring(
																			0,
																			attribute
																					.indexOf("/")))
															.get(0)
															+ "/"
															+ attribute
																	.substring(
																			0,
																			attribute
																					.indexOf("/")));
										}

										if (!getObjectMultiSql
												.containsKey(objectPropertyRanges
														.get(attribute
																.substring(
																		0,
																		attribute
																				.indexOf("/")))
														.get(0)))
											getObjectMultiSql
													.put(objectPropertyRanges
															.get(attribute
																	.substring(
																			0,
																			attribute
																					.indexOf("/")))
															.get(0),
															new ArrayList<String>());
										if (!getObjectMultiSql
												.get(objectPropertyRanges
														.get(attribute
																.substring(
																		0,
																		attribute
																				.indexOf("/")))
														.get(0))
												.contains(
														dbtables[i]
																+ "/"
																+ attribute
																		.substring(
																				0,
																				attribute
																						.indexOf("/")))) {
											getObjectMultiSql
													.get(objectPropertyRanges
															.get(attribute
																	.substring(
																			0,
																			attribute
																					.indexOf("/")))
															.get(0))
													.add(dbtables[i]
															+ "/"
															+ attribute
																	.substring(
																			0,
																			attribute
																					.indexOf("/")));
										}
									}
								}

								// object Property Single Valued
								else {

									if (objectPropertyRanges
											.get(attribute.substring(attribute
													.indexOf("/") + 1)).get(0)
											.equals(dbtables[i])) {
										if (!getObjectSingleSql
												.containsKey(dbtables[i]))
											getObjectSingleSql.put(dbtables[i],
													new ArrayList<String>());

										if (!getObjectSingleSql
												.get(dbtables[i])
												.contains(
														"-"
																+ attribute
																		.substring(
																				0,
																				attribute
																						.indexOf("/"))
																+ "/"
																+ attribute
																		.substring(attribute
																				.indexOf("/") + 1)))
											getObjectSingleSql
													.get(dbtables[i])
													.add("-"
															+ attribute
																	.substring(
																			0,
																			attribute
																					.indexOf("/"))
															+ "/"
															+ attribute
																	.substring(attribute
																			.indexOf("/") + 1));

									} else {
										if (!getObjectSingleSql
												.containsKey(dbtables[i]))
											getObjectSingleSql.put(dbtables[i],
													new ArrayList<String>());
										if (!getObjectSingleSql
												.get(dbtables[i])
												.contains(
														objectPropertyRanges
																.get(attribute
																		.substring(attribute
																				.indexOf("/") + 1))
																.get(0)
																+ "/"
																+ attribute
																		.substring(attribute
																				.indexOf("/") + 1)))
											getObjectSingleSql
													.get(dbtables[i])
													.add(objectPropertyRanges
															.get(attribute
																	.substring(attribute
																			.indexOf("/") + 1))
															.get(0)
															+ "/"
															+ attribute
																	.substring(attribute
																			.indexOf("/") + 1));
									}
								}
							}
						}
					}
					if (i == 0) {
						where = where + " " + dbtables[i] + "." + table
								+ "ID = ?";
					} else
						where = where + " AND " + dbtables[i] + "."
								+ dbtables[i] + "ID = " + table + "." + table
								+ "ID";
				}

				if (queryAttributesDataSingle.length() > 0) {
					select = select + queryAttributesDataSingle;
					from = from + queryTables;

					querie = select + from + where;
					getDataSingleSql.put(table, querie);
				}

				if (queryAttributesDataMulti.length() > 0) {
					select = "SELECT "
							+ queryAttributesDataMulti.substring(
									queryAttributesDataMulti.indexOf("/") + 1,
									queryAttributesDataMulti.length());
					from = " FROM "
							+ queryAttributesDataMulti.substring(0,
									queryAttributesDataMulti.indexOf("/"));
					where = " WHERE " + table + "ID = ?";
					querie = select + from + where;

					if (!getDataMultiSql.containsKey(table))
						getDataMultiSql.put(table, new ArrayList<String>());
					getDataMultiSql.get(table).add(querie);
				}

			}

		}
	}

	/**
	 * \brief Retrieve the super classes for a given one. \param table The type
	 * we want to get his super classes. \return A String with all the super
	 * classes seperated by a space
	 */
	public String getParent(String table) {
		if (superClasses.get(table) != null) {
			for (String parents : superClasses.get(table)) {
				return parents + " " + getParent(parents);
			}
		}
		return "";

	}

	/**
	 * \brief Generate the C++ file for the data access object. \param
	 * attributes List of the attributes. \param unit List of the units of the
	 * attributes. \param url Host of your DB. \param user User name in the DB.
	 * \param pass Password of the user in the DB. \param nameDb DB Schema.
	 * \return A String with the whole C++ file
	 */
	public String generateCpp(ArrayList<String> attributes,
			ArrayList<String> unit, String url, String user, String pass,
			String nameDb) {
		String result = "";
		result = result
				+ "/*****************************************************************************\n";
		result = result + "   DISCLAIMER:\n";
		result = result
				+ "   This software was produced by the National Institute of Standards\n";
		result = result
				+ "   and Technology (NIST), an agency of the U.S. government, and by \n";
		result = result + "statute is\n";
		result = result
				+ "   not subject to copyright in the United States.  Recipients of this \n";
		result = result + "software\n";
		result = result
				+ "   assume all responsibility associated with its operation, modification,\n";
		result = result + "   maintenance, and subsequent redistribution.\n";
		result = result + "\n";
		result = result
				+ "   See NIST Administration Manual 4.09.07 b and Appendix I.\n";
		result = result
				+ " *****************************************************************************/\n\n";

		String include = "#include \"DAO.h\"\n\n";

		String constructor = "DAO::DAO";
		String paramConstruct = "(std::string name)";

		paramConstruct = paramConstruct
				+ "{\nthis->className.push_back(name);\n"
				+ "if(getenv(\"MysqlDefaultHost\") && getenv(\"MysqlDefaultUser\")&& getenv(\"MysqlDefaultPassword\")&& getenv(\"MysqlDefaultSchema\")){\n"
			    +"connection = Connection::getInstance(getenv(\"MysqlDefaultHost\"), getenv(\"MysqlDefaultUser\"), getenv(\"MysqlDefaultPassword\"), getenv(\"MysqlDefaultSchema\"));\n"
			    +"this->fillGetSqlQueries();}\n"
			    +"else\n"
			    +"std::cout<<\"Check the readme file to know which environment variables to assign\"<<std::endl;\n}\n";

		String fillGetSqlQueries = "std::map<std::string, std::string> "
				+ "DAO::getSqlQueriesDataSingle;"
				+ "std::map<std::string,std::vector<std::string> > "
				+ "DAO::getSqlQueriesDataMulti;"
				+ "std::map<std::string,std::vector<std::string> > "
				+ "DAO::getSqlQueriesObjectSingle;"
				+ "std::map<std::string,std::vector<std::string> > "
				+ "DAO::getSqlQueriesObjectMulti;"
				+ "\n\nvoid DAO::fillGetSqlQueries(){";
		fillGetSqlQueries = fillGetSqlQueries
				+ "std::vector<std::string> temp;";
		for (Entry<String, String> currentEntry : getDataSingleSql.entrySet()) {
			fillGetSqlQueries = fillGetSqlQueries
					+ "DAO::getSqlQueriesDataSingle[\"" + currentEntry.getKey()
					+ "\"] = \"" + currentEntry.getValue() + "\";\n";
		}
		for (Entry<String, ArrayList<String>> currentEntry : getDataMultiSql
				.entrySet()) {
			fillGetSqlQueries = fillGetSqlQueries + "temp.clear();";

			for (int i = 0; i < currentEntry.getValue().size(); i++) {
				fillGetSqlQueries = fillGetSqlQueries + "temp.push_back(\""
						+ currentEntry.getValue().get(i) + "\");\n";
			}
			fillGetSqlQueries = fillGetSqlQueries
					+ "DAO::getSqlQueriesDataMulti[\"" + currentEntry.getKey()
					+ "\"] = temp;\n";
		}
		for (Entry<String, ArrayList<String>> currentEntry : getObjectSingleSql
				.entrySet()) {
			fillGetSqlQueries = fillGetSqlQueries + "temp.clear();";

			for (int i = 0; i < currentEntry.getValue().size(); i++) {
				fillGetSqlQueries = fillGetSqlQueries + "temp.push_back(\""
						+ currentEntry.getValue().get(i) + "\");\n";
			}
			fillGetSqlQueries = fillGetSqlQueries
					+ "DAO::getSqlQueriesObjectSingle[\""
					+ currentEntry.getKey() + "\"] = temp;\n";
		}
		for (Entry<String, ArrayList<String>> currentEntry : getObjectMultiSql
				.entrySet()) {
			fillGetSqlQueries = fillGetSqlQueries + "temp.clear();";

			for (int i = 0; i < currentEntry.getValue().size(); i++) {
				fillGetSqlQueries = fillGetSqlQueries + "temp.push_back(\""
						+ currentEntry.getValue().get(i) + "\");\n";
			}
			fillGetSqlQueries = fillGetSqlQueries
					+ "DAO::getSqlQueriesObjectMulti[\""
					+ currentEntry.getKey() + "\"] = temp;\n";
		}

		fillGetSqlQueries = fillGetSqlQueries + "}\n\n";
		String get = "";
		for (int i = 0; i < attributes.size(); i++) {
			get = get + unit.get(i) + " DAO::get" + attributes.get(i) + "(){\n";
			get = get + "return this->" + attributes.get(i) + ";\n}\n";
		}
		String set = "";
		for (int i = 0; i < attributes.size(); i++) {
			set = set + "void DAO::set" + attributes.get(i) + "(" + unit.get(i)
					+ " _" + attributes.get(i) + "){\n";
			set = set + "this->" + attributes.get(i) + "= _"
					+ attributes.get(i) + ";\n}\n";
		}

		result = result + include + constructor + paramConstruct
				+ fillGetSqlQueries + get + set;

		String getGlobal = "	std::map<std::string, std::string> DAO::get(std::string name) {\n";
		getGlobal = getGlobal
				+ "nameDone.push_back(className.back() + \"+\" + name);\n";
		getGlobal = getGlobal + "	try {\n";
		getGlobal = getGlobal + "		sql::PreparedStatement *prep_stmt;\n";
		getGlobal = getGlobal
				+ "		sql::ResultSet *res;// get the ID with the name\n";
		getGlobal = getGlobal
				+ "		prep_stmt = connection->getCon()->prepareStatement(\"SELECT \"\n";
		getGlobal = getGlobal
				+ "				+ className.back() + \"ID FROM \" + className.back()\n";
		getGlobal = getGlobal + "				+ \" WHERE _Name = ?\");\n";
		getGlobal = getGlobal + "		prep_stmt->setString(1, name);\n";
		getGlobal = getGlobal + "		res = prep_stmt->executeQuery();\n";
		getGlobal = getGlobal + "		res->next();\n";
		getGlobal = getGlobal + "		int id = res->getInt(1);\n";
		getGlobal = getGlobal + "		delete (res);\n";
		getGlobal = getGlobal + "		delete (prep_stmt);\n";
		getGlobal = getGlobal + "		// get the data Single\n";
		getGlobal = getGlobal + "		sql::ResultSetMetaData *res_meta;\n";
		getGlobal = getGlobal
				+ "		prep_stmt = connection->getCon()->prepareStatement(\n";
		getGlobal = getGlobal
				+ "				DAO::getSqlQueriesDataSingle[className.back()]);\n";
		getGlobal = getGlobal + "		prep_stmt->setInt(1, id);\n";
		getGlobal = getGlobal + "		res = prep_stmt->executeQuery();\n";
		getGlobal = getGlobal + "		res->next();\n";
		getGlobal = getGlobal + "		res_meta = res -> getMetaData();\n";
		getGlobal = getGlobal
				+ "		for (int i = 0; i < (int) res_meta -> getColumnCount(); ++i) {\n";
		getGlobal = getGlobal
				+ "			map[res_meta -> getColumnLabel(i + 1)] = res->getString(i + 1);\n";
		getGlobal = getGlobal + "		}\n";
		getGlobal = getGlobal + "		delete (res);\n";
		getGlobal = getGlobal + "		delete (prep_stmt);\n";
		getGlobal = getGlobal + "		// get the data multi\n";
		getGlobal = getGlobal + "		std::string temp = \"\";\n";
		getGlobal = getGlobal + "		for (int unsigned i = 0; i\n";
		getGlobal = getGlobal
				+ "				< DAO::getSqlQueriesDataMulti[className.back()].size(); i++) {\n";
		getGlobal = getGlobal + "			try {\n";
		getGlobal = getGlobal
				+ "				prep_stmt = connection->getCon()->prepareStatement(\n";
		getGlobal = getGlobal
				+ "						DAO::getSqlQueriesDataMulti[className.back()][i]);\n";
		getGlobal = getGlobal + "				prep_stmt->setInt(1, id);\n";
		getGlobal = getGlobal + "				res = prep_stmt->executeQuery();\n";
		getGlobal = getGlobal + "				while (res->next()) {\n";
		getGlobal = getGlobal + "					if (!res->isLast())\n";
		getGlobal = getGlobal
				+ "						temp = temp + res->getString(1) + \" \";\n";
		getGlobal = getGlobal + "					else\n";
		getGlobal = getGlobal + "						temp = temp + res->getString(1);\n";
		getGlobal = getGlobal + "				}\n";
		getGlobal = getGlobal + "				res_meta = res -> getMetaData();\n";
		getGlobal = getGlobal
				+ "				map[res_meta -> getColumnLabel(1)] = temp;\n";
		getGlobal = getGlobal + "				delete (res);\n";
		getGlobal = getGlobal + "				delete (prep_stmt);\n";
		getGlobal = getGlobal + "			} catch (sql::SQLException &e) {\n";
		getGlobal = getGlobal
				+ "				std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getGlobal = getGlobal
				+ "				std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		getGlobal = getGlobal + "						<< std::endl;\n";
		getGlobal = getGlobal + "				std::cout << \"# ERR: \" << e.what();\n";
		getGlobal = getGlobal
				+ "				std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		getGlobal = getGlobal
				+ "				std::cout << \", SQLState: \" << e.getSQLState() << \" )\"\n";
		getGlobal = getGlobal + "						<< std::endl;\n";
		getGlobal = getGlobal + "			}\n";
		getGlobal = getGlobal + "		}\n";
		getGlobal = getGlobal + "		// get the Object Single\n";
		getGlobal = getGlobal + "		temp = \"\";\n";
		getGlobal = getGlobal + "		sql::ResultSet *restemp;\n";
		getGlobal = getGlobal + "		sql::Statement *stmt;\n";
		getGlobal = getGlobal + "		std::string newName = \"\";\n";
		getGlobal = getGlobal + "		std::string newTable = \"\";\n";
		getGlobal = getGlobal + "		for (int unsigned i = 0; i\n";
		getGlobal = getGlobal
				+ "				< DAO::getSqlQueriesObjectSingle[className.back()].size(); i++) {\n";
		getGlobal = getGlobal + "			try {\n";
		getGlobal = getGlobal
				+ "				stmt = connection->getCon()->createStatement();\n";
		getGlobal = getGlobal
				+ "				if (getSqlQueriesObjectSingle[className.back()][i].substr(0, 1)\n";
		getGlobal = getGlobal + "						!= \"-\") {\n";
		getGlobal = getGlobal + "					restemp\n";
		getGlobal = getGlobal + "							= stmt->executeQuery(\n";
		getGlobal = getGlobal + "									\"SELECT \"\n";
		getGlobal = getGlobal
				+ "											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal + "													0,\n";
		getGlobal = getGlobal
				+ "													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "															\"/\")) + \"ID FROM \"\n";
		getGlobal = getGlobal
				+ "											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal + "													0,\n";
		getGlobal = getGlobal
				+ "													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "															\"/\")) + \", \"\n";
		getGlobal = getGlobal + "											+ className.back() + \" WHERE \"\n";
		getGlobal = getGlobal
				+ "											+ className.back() + \"._Name = '\"\n";
		getGlobal = getGlobal + "											+ name + \"' AND \"\n";
		getGlobal = getGlobal
				+ "											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal
				+ "													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "															\"/\") + 1) + \" = \"\n";
		getGlobal = getGlobal
				+ "											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal + "													0,\n";
		getGlobal = getGlobal
				+ "													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "															\"/\")) + \"._Name\");\n";
		getGlobal = getGlobal + "					prep_stmt\n";
		getGlobal = getGlobal
				+ "							= connection->getCon()->prepareStatement(\n";
		getGlobal = getGlobal
				+ "									DAO::getSqlQueriesDataSingle[getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal + "											0,\n";
		getGlobal = getGlobal
				+ "											getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "													\"/\"))]);\n";
		getGlobal = getGlobal + "				} else {\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "					restemp\n";
		getGlobal = getGlobal + "							= stmt->executeQuery(\n";
		getGlobal = getGlobal + "									\"SELECT \"\n";
		getGlobal = getGlobal
				+ "											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal + "													1,\n";
		getGlobal = getGlobal
				+ "													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "															\"/\") - 1)\n";
		getGlobal = getGlobal + "											+ \"ID FROM \"\n";
		getGlobal = getGlobal
				+ "											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal + "													1,\n";
		getGlobal = getGlobal
				+ "													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "															\"/\") - 1) + \", \"\n";
		getGlobal = getGlobal + "											+ className.back() + \" WHERE \"\n";
		getGlobal = getGlobal
				+ "											+ className.back() + \"._Name = '\"\n";
		getGlobal = getGlobal + "											+ name + \"' AND \"\n";
		getGlobal = getGlobal
				+ "											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal
				+ "													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "															\"/\") + 1) + \" = \"\n";
		getGlobal = getGlobal
				+ "											+ className.back() + \"._Name\");\n";
		getGlobal = getGlobal + "					prep_stmt\n";
		getGlobal = getGlobal
				+ "							= connection->getCon()->prepareStatement(\n";
		getGlobal = getGlobal
				+ "									DAO::getSqlQueriesDataSingle[getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal + "											1,\n";
		getGlobal = getGlobal
				+ "											getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "													\"/\") - 1)]);\n";
		getGlobal = getGlobal + "				}\n";
		getGlobal = getGlobal + "				do {\n";
		getGlobal = getGlobal + "					restemp->next();\n";
		getGlobal = getGlobal
				+ "					prep_stmt->setInt(1, restemp->getInt(1));\n";
		getGlobal = getGlobal + "					res = prep_stmt->executeQuery();\n";
		getGlobal = getGlobal + "					do {\n";
		getGlobal = getGlobal + "						res->next();\n";
		getGlobal = getGlobal + "						res_meta = res -> getMetaData();\n";
		getGlobal = getGlobal
				+ "						for (int j = 0; j < (int) res_meta -> getColumnCount(); ++j) {\n";
		getGlobal = getGlobal
				+ "							if (map[getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal
				+ "									getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "											\"/\") + 1) + \"/\"\n";
		getGlobal = getGlobal
				+ "									+ res_meta -> getColumnLabel(j + 1)] == \"\") {\n";
		getGlobal = getGlobal
				+ "								map[getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal
				+ "										getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "												\"/\") + 1) + \"/\"\n";
		getGlobal = getGlobal
				+ "										+ res_meta -> getColumnLabel(j + 1)]\n";
		getGlobal = getGlobal + "										= res->getString(j + 1);\n";
		getGlobal = getGlobal + "							} else {\n";
		getGlobal = getGlobal
				+ "								map[getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal
				+ "										getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "												\"/\") + 1) + \"/\"\n";
		getGlobal = getGlobal
				+ "										+ res_meta -> getColumnLabel(j + 1)]\n";
		getGlobal = getGlobal + "										+= \" \" + res->getString(j + 1);\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "							}\n";
		getGlobal = getGlobal + "						}\n";
		getGlobal = getGlobal
				+ "						if (getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal + "								0, 1) != \"-\") {\n";
		getGlobal = getGlobal + "							newName\n";
		getGlobal = getGlobal + "									= res->getString(\n";
		getGlobal = getGlobal
				+ "											getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal + "													0,\n";
		getGlobal = getGlobal
				+ "													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "															\"/\")) + \"._NAME\");\n";
		getGlobal = getGlobal + "						} else {\n";
		getGlobal = getGlobal + "							newName\n";
		getGlobal = getGlobal + "									= res->getString(\n";
		getGlobal = getGlobal
				+ "											getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal + "													1,\n";
		getGlobal = getGlobal
				+ "													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "															\"/\") - 1)\n";
		getGlobal = getGlobal + "													+ \"._NAME\");\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "						}\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal
				+ "						if (getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal + "								0, 1) != \"-\") {\n";
		getGlobal = getGlobal + "							newTable\n";
		getGlobal = getGlobal
				+ "									= getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal + "											0,\n";
		getGlobal = getGlobal
				+ "											getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "													\"/\"));\n";
		getGlobal = getGlobal + "						} else {\n";
		getGlobal = getGlobal + "							newTable\n";
		getGlobal = getGlobal
				+ "									= getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal = getGlobal + "											1,\n";
		getGlobal = getGlobal
				+ "											getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal = getGlobal + "													\"/\") - 1);\n";
		getGlobal = getGlobal + "						}\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "					} while (!res->isLast());\n";
		getGlobal = getGlobal + "					delete (res);\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "				} while (!restemp->isLast());\n";
		getGlobal = getGlobal + "				delete (restemp);\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "				delete (prep_stmt);\n";
		getGlobal = getGlobal + "				delete (stmt);\n";
		getGlobal = getGlobal + "			} catch (sql::SQLException &e) {\n";
		getGlobal = getGlobal
				+ "				std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getGlobal = getGlobal
				+ "				std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		getGlobal = getGlobal + "						<< std::endl;\n";
		getGlobal = getGlobal + "				std::cout << \"# ERR: \" << e.what();\n";
		getGlobal = getGlobal
				+ "				std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		getGlobal = getGlobal
				+ "				std::cout << \", SQLState: \" << e.getSQLState() << \" )\"\n";
		getGlobal = getGlobal + "						<< std::endl;\n";
		getGlobal = getGlobal + "			}\n";
		getGlobal = getGlobal + "		}\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "		//get the Object multi\n";
		getGlobal = getGlobal + "		sql::ResultSet *restempmulti;\n";
		getGlobal = getGlobal + "		sql::Statement *stmtmulti;\n";
		getGlobal = getGlobal + "		for (int unsigned m = 0; m\n";
		getGlobal = getGlobal
				+ "				< DAO::getSqlQueriesObjectMulti[className.back()].size(); m++) {\n";
		getGlobal = getGlobal + "			try {\n";
		getGlobal = getGlobal + "				//convert id to string\n";
		getGlobal = getGlobal + "				std::string sid;\n";
		getGlobal = getGlobal + "				std::stringstream out;\n";
		getGlobal = getGlobal + "				out << id;\n";
		getGlobal = getGlobal + "				sid = out.str();\n";
		getGlobal = getGlobal + "				//end convert id\n";
		getGlobal = getGlobal
				+ "				stmtmulti = connection->getCon()->createStatement();\n";
		getGlobal = getGlobal + "				restempmulti\n";
		getGlobal = getGlobal + "						= stmtmulti->executeQuery(\n";
		getGlobal = getGlobal + "								\"SELECT \"\n";
		getGlobal = getGlobal
				+ "										+ getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal = getGlobal + "												0,\n";
		getGlobal = getGlobal
				+ "												getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal = getGlobal + "														\"/\")) + \"ID FROM \"\n";
		getGlobal = getGlobal
				+ "										+ getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal = getGlobal
				+ "												getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal = getGlobal + "														\"/\") + 1) + \" WHERE \"\n";
		getGlobal = getGlobal
				+ "										+ className.back() + \"ID = \" + sid);\n";
		getGlobal = getGlobal + "				do {\n";
		getGlobal = getGlobal + "					restempmulti->next();\n";
		getGlobal = getGlobal + "					std::string\n";
		getGlobal = getGlobal + "							table =\n";
		getGlobal = getGlobal
				+ "									getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal = getGlobal + "											0,\n";
		getGlobal = getGlobal
				+ "											getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal = getGlobal + "													\"/\"));\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "					//Add the data\n";
		getGlobal = getGlobal + "					prep_stmt\n";
		getGlobal = getGlobal
				+ "							= connection->getCon()->prepareStatement(\n";
		getGlobal = getGlobal
				+ "									DAO::getSqlQueriesDataSingle[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal = getGlobal + "											0,\n";
		getGlobal = getGlobal
				+ "											getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal = getGlobal + "													\"/\"))]);\n";
		getGlobal = getGlobal
				+ "					prep_stmt->setInt(1, restempmulti->getInt(1));\n";
		getGlobal = getGlobal + "					res = prep_stmt->executeQuery();\n";
		getGlobal = getGlobal + "					res->next();\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "					res_meta = res -> getMetaData();\n";
		getGlobal = getGlobal
				+ "					for (int i = 0; i < (int) res_meta -> getColumnCount(); ++i) {\n";
		getGlobal = getGlobal
				+ "						if (map[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal = getGlobal
				+ "								getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal = getGlobal + "										\"/\") + 1) + \"/\"\n";
		getGlobal = getGlobal
				+ "								+ res_meta -> getColumnLabel(i + 1)] == \"\")\n";
		getGlobal = getGlobal
				+ "							map[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal = getGlobal
				+ "									getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal = getGlobal + "											\"/\") + 1) + \"/\"\n";
		getGlobal = getGlobal
				+ "									+ res_meta -> getColumnLabel(i + 1)]\n";
		getGlobal = getGlobal + "									= res->getString(i + 1);\n";
		getGlobal = getGlobal + "						else\n";
		getGlobal = getGlobal
				+ "							map[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal = getGlobal
				+ "									getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal = getGlobal + "											\"/\") + 1) + \"/\"\n";
		getGlobal = getGlobal
				+ "									+ res_meta -> getColumnLabel(i + 1)] += \" \"\n";
		getGlobal = getGlobal + "									+ res->getString(i + 1);\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "					}\n";
		getGlobal = getGlobal + "					delete (prep_stmt);\n";
		getGlobal = getGlobal + "					delete (res);\n";
		getGlobal = getGlobal + "					//End Add the Data\n";
		getGlobal = getGlobal + "					//Add the Data multi\n";
		getGlobal = getGlobal + "					std::string temp = \"\";\n";
		getGlobal = getGlobal + "					for (int unsigned i = 0; i\n";
		getGlobal = getGlobal
				+ "							< DAO::getSqlQueriesDataMulti[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal = getGlobal + "									0,\n";
		getGlobal = getGlobal
				+ "									getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal = getGlobal + "											\"/\"))].size(); i++) {\n";
		getGlobal = getGlobal + "						try {\n";
		getGlobal = getGlobal + "							prep_stmt\n";
		getGlobal = getGlobal
				+ "									= connection->getCon()->prepareStatement(\n";
		getGlobal = getGlobal
				+ "											DAO::getSqlQueriesDataMulti[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal = getGlobal + "													0,\n";
		getGlobal = getGlobal
				+ "													getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal = getGlobal + "															\"/\"))][i]);\n";
		getGlobal = getGlobal
				+ "							prep_stmt->setInt(1, restempmulti->getInt(1));\n";
		getGlobal = getGlobal + "							res = prep_stmt->executeQuery();\n";
		getGlobal = getGlobal + "							while (res->next()) {\n";
		getGlobal = getGlobal + "								if (!res->isLast())\n";
		getGlobal = getGlobal
				+ "									temp = temp + res->getString(1) + \" \";\n";
		getGlobal = getGlobal + "								else\n";
		getGlobal = getGlobal + "									temp = temp + res->getString(1);\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "							}\n";
		getGlobal = getGlobal + "							res_meta = res -> getMetaData();\n";
		getGlobal = getGlobal
				+ "							map[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal = getGlobal
				+ "									getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal = getGlobal + "											\"/\") + 1) + \"/\"\n";
		getGlobal = getGlobal
				+ "									+ res_meta -> getColumnLabel(1)] = temp;\n";
		getGlobal = getGlobal + "							delete (res);\n";
		getGlobal = getGlobal + "							delete (prep_stmt);\n";
		getGlobal = getGlobal + "						} catch (sql::SQLException &e) {\n";
		getGlobal = getGlobal
				+ "							std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getGlobal = getGlobal
				+ "							std::cout << \"(\" << __FUNCTION__ << \") on line \"\n";
		getGlobal = getGlobal + "									<< __LINE__ << std::endl;\n";
		getGlobal = getGlobal
				+ "							std::cout << \"# ERR: \" << e.what();\n";
		getGlobal = getGlobal
				+ "							std::cout << \" (MySQL error code: \"\n";
		getGlobal = getGlobal + "									<< e.getErrorCode();\n";
		getGlobal = getGlobal
				+ "							std::cout << \", SQLState: \" << e.getSQLState()\n";
		getGlobal = getGlobal + "									<< \" )\" << std::endl;\n";
		getGlobal = getGlobal + "						}\n";
		getGlobal = getGlobal + "					}\n";
		getGlobal = getGlobal + "					//End Add Data Multi\n";
		getGlobal = getGlobal + "					// Add Object Single\n";
		getGlobal = getGlobal + "					for (int unsigned i = 0; i\n";
		getGlobal = getGlobal
				+ "							< DAO::getSqlQueriesObjectSingle[table].size(); i++) {\n";
		getGlobal = getGlobal + "						try {\n";
		getGlobal = getGlobal
				+ "							stmt = connection->getCon()->createStatement();\n";
		getGlobal = getGlobal
				+ "							if (getSqlQueriesObjectSingle[table][i].substr(0, 1)\n";
		getGlobal = getGlobal + "									!= \"-\") {\n";
		getGlobal = getGlobal + "								restemp\n";
		getGlobal = getGlobal + "										= stmt->executeQuery(\n";
		getGlobal = getGlobal + "												\"SELECT \"\n";
		getGlobal = getGlobal
				+ "														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal + "																0,\n";
		getGlobal = getGlobal
				+ "																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "																		\"/\"))\n";
		getGlobal = getGlobal + "														+ \"ID FROM \"\n";
		getGlobal = getGlobal
				+ "														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal + "																0,\n";
		getGlobal = getGlobal
				+ "																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "																		\"/\"))\n";
		getGlobal = getGlobal + "														+ \", \" + table\n";
		getGlobal = getGlobal + "														+ \" WHERE \" + table\n";
		getGlobal = getGlobal + "														+ \"._Name = '\" + name\n";
		getGlobal = getGlobal + "														+ \"' AND \"\n";
		getGlobal = getGlobal
				+ "														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal
				+ "																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "																		\"/\")\n";
		getGlobal = getGlobal + "																		+ 1)\n";
		getGlobal = getGlobal + "														+ \" = \"\n";
		getGlobal = getGlobal
				+ "														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal + "																0,\n";
		getGlobal = getGlobal
				+ "																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "																		\"/\"))\n";
		getGlobal = getGlobal + "														+ \"._Name\");\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "								prep_stmt\n";
		getGlobal = getGlobal
				+ "										= connection->getCon()->prepareStatement(\n";
		getGlobal = getGlobal
				+ "												DAO::getSqlQueriesDataSingle[getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal + "														0,\n";
		getGlobal = getGlobal
				+ "														getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "																\"/\"))]);\n";
		getGlobal = getGlobal + "							} else {\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "								restemp\n";
		getGlobal = getGlobal + "										= stmt->executeQuery(\n";
		getGlobal = getGlobal + "												\"SELECT \"\n";
		getGlobal = getGlobal
				+ "														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal + "																1,\n";
		getGlobal = getGlobal
				+ "																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "																		\"/\")\n";
		getGlobal = getGlobal + "																		- 1)\n";
		getGlobal = getGlobal + "														+ \"ID FROM \"\n";
		getGlobal = getGlobal
				+ "														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal + "																1,\n";
		getGlobal = getGlobal
				+ "																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "																		\"/\")\n";
		getGlobal = getGlobal + "																		- 1)\n";
		getGlobal = getGlobal + "														+ \", \" + table\n";
		getGlobal = getGlobal + "														+ \" WHERE \" + table\n";
		getGlobal = getGlobal + "														+ \"._Name = '\" + name\n";
		getGlobal = getGlobal + "														+ \"' AND \"\n";
		getGlobal = getGlobal
				+ "														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal
				+ "																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "																		\"/\")\n";
		getGlobal = getGlobal + "																		+ 1)\n";
		getGlobal = getGlobal + "														+ \" = \" + table\n";
		getGlobal = getGlobal + "														+ \"._Name\");\n";
		getGlobal = getGlobal + "								prep_stmt\n";
		getGlobal = getGlobal
				+ "										= connection->getCon()->prepareStatement(\n";
		getGlobal = getGlobal
				+ "												DAO::getSqlQueriesDataSingle[getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal + "														1,\n";
		getGlobal = getGlobal
				+ "														getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "																\"/\") - 1)]);\n";
		getGlobal = getGlobal + "							}\n";
		getGlobal = getGlobal + "							do {\n";
		getGlobal = getGlobal + "								restemp->next();\n";
		getGlobal = getGlobal
				+ "								prep_stmt->setInt(1, restemp->getInt(1));\n";
		getGlobal = getGlobal + "								res = prep_stmt->executeQuery();\n";
		getGlobal = getGlobal + "								do {\n";
		getGlobal = getGlobal + "									res->next();\n";
		getGlobal = getGlobal + "									res_meta = res -> getMetaData();\n";
		getGlobal = getGlobal + "									for (int j = 0; j\n";
		getGlobal = getGlobal
				+ "											< (int) res_meta -> getColumnCount(); ++j) {\n";
		getGlobal = getGlobal
				+ "										if (map[getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal
				+ "												getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "														\"/\") + 1) + \"/\"\n";
		getGlobal = getGlobal + "												+ res_meta -> getColumnLabel(j\n";
		getGlobal = getGlobal + "														+ 1)] == \"\")\n";
		getGlobal = getGlobal
				+ "											map[getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal
				+ "													getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "															\"/\") + 1) + \"/\"\n";
		getGlobal = getGlobal + "													+ res_meta -> getColumnLabel(\n";
		getGlobal = getGlobal + "															j + 1)]\n";
		getGlobal = getGlobal + "													= res->getString(j + 1);\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "										else\n";
		getGlobal = getGlobal
				+ "											map[getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal
				+ "													getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "															\"/\") + 1) + \"/\"\n";
		getGlobal = getGlobal + "													+ res_meta -> getColumnLabel(\n";
		getGlobal = getGlobal + "															j + 1)] += \" \"\n";
		getGlobal = getGlobal + "													+ res->getString(j + 1);\n";
		getGlobal = getGlobal + "									}\n";
		getGlobal = getGlobal
				+ "									if (getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal + "											0, 1) != \"-\") {\n";
		getGlobal = getGlobal + "										newName\n";
		getGlobal = getGlobal + "												= res->getString(\n";
		getGlobal = getGlobal
				+ "														getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal + "																0,\n";
		getGlobal = getGlobal
				+ "																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "																		\"/\"))\n";
		getGlobal = getGlobal + "																+ \"._NAME\");\n";
		getGlobal = getGlobal + "									} else {\n";
		getGlobal = getGlobal + "										newName\n";
		getGlobal = getGlobal + "												= res->getString(\n";
		getGlobal = getGlobal
				+ "														getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal + "																1,\n";
		getGlobal = getGlobal
				+ "																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "																		\"/\")\n";
		getGlobal = getGlobal + "																		- 1)\n";
		getGlobal = getGlobal + "																+ \"._NAME\");\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "									}\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal
				+ "									if (getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal + "											0, 1) != \"-\") {\n";
		getGlobal = getGlobal + "										newTable\n";
		getGlobal = getGlobal
				+ "												= getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal + "														0,\n";
		getGlobal = getGlobal
				+ "														getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "																\"/\"));\n";
		getGlobal = getGlobal + "									} else {\n";
		getGlobal = getGlobal + "										newTable\n";
		getGlobal = getGlobal
				+ "												= getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal = getGlobal + "														1,\n";
		getGlobal = getGlobal
				+ "														getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal = getGlobal + "																\"/\") - 1);\n";
		getGlobal = getGlobal + "									}\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "								} while (!res->isLast());\n";
		getGlobal = getGlobal + "								delete (res);\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "							} while (!restemp->isLast());\n";
		getGlobal = getGlobal + "							delete (restemp);\n";
		getGlobal = getGlobal + "\n";
		getGlobal = getGlobal + "							delete (prep_stmt);\n";
		getGlobal = getGlobal + "							delete (stmt);\n";
		getGlobal = getGlobal + "						} catch (sql::SQLException &e) {\n";
		getGlobal = getGlobal
				+ "							std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getGlobal = getGlobal
				+ "							std::cout << \"(\" << __FUNCTION__ << \") on line \"\n";
		getGlobal = getGlobal + "									<< __LINE__ << std::endl;\n";
		getGlobal = getGlobal
				+ "							std::cout << \"# ERR: \" << e.what();\n";
		getGlobal = getGlobal
				+ "							std::cout << \" (MySQL error code: \"\n";
		getGlobal = getGlobal + "									<< e.getErrorCode();\n";
		getGlobal = getGlobal
				+ "							std::cout << \", SQLState: \" << e.getSQLState()\n";
		getGlobal = getGlobal + "									<< \" )\" << std::endl;\n";
		getGlobal = getGlobal + "						}\n";
		getGlobal = getGlobal + "					}\n";
		getGlobal = getGlobal + "				} while (!restempmulti->isLast());\n";
		getGlobal = getGlobal + "				delete (restempmulti);\n";
		getGlobal = getGlobal + "			} catch (sql::SQLException &e) {\n";
		getGlobal = getGlobal
				+ "				std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getGlobal = getGlobal
				+ "				std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		getGlobal = getGlobal + "						<< std::endl;\n";
		getGlobal = getGlobal + "				std::cout << \"# ERR: \" << e.what();\n";
		getGlobal = getGlobal
				+ "				std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		getGlobal = getGlobal
				+ "				std::cout << \", SQLState: \" << e.getSQLState() << \" )\"\n";
		getGlobal = getGlobal + "						<< std::endl;\n";
		getGlobal = getGlobal + "			}\n";
		getGlobal = getGlobal + "		}\n";
		getGlobal = getGlobal + "	} catch (sql::SQLException &e) {\n";
		getGlobal = getGlobal
				+ "		std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getGlobal = getGlobal
				+ "		std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		getGlobal = getGlobal + "				<< std::endl;\n";
		getGlobal = getGlobal + "		std::cout << \"# ERR: \" << e.what();\n";
		getGlobal = getGlobal
				+ "		std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		getGlobal = getGlobal
				+ "		std::cout << \", SQLState: \" << e.getSQLState() << \" )\" << std::endl;\n";
		getGlobal = getGlobal + "	}\n";
		getGlobal = getGlobal + "	className.pop_back();\n";
		getGlobal = getGlobal + "	return map;\n";
		getGlobal = getGlobal + "	}\n";

		String setGlobal = "void DAO::set(std::map<std::string,std::string> data){";
		setGlobal = setGlobal + "	try {\n";
		setGlobal = setGlobal + "		// DATA SINGLE\n";
		setGlobal = setGlobal + "		sql::Statement *stmt;\n";
		setGlobal = setGlobal
				+ "		stmt = connection->getCon()->createStatement();\n";
		setGlobal = setGlobal
				+ "		std::string query = \"UPDATE \" + this->className.back();\n";
		setGlobal = setGlobal + "		query = query + \" SET \";\n";
		setGlobal = setGlobal
				+ "		for (std::map<std::string, std::string>::iterator it = data.begin(); it\n";
		setGlobal = setGlobal + "				!= data.end(); it++) {\n";
		setGlobal = setGlobal
				+ "			if (DAO::getSqlQueriesDataSingle[this->className.back()].find(\n";
		setGlobal = setGlobal
				+ "					this->className.back() + \".\" + it->first)\n";
		setGlobal = setGlobal + "					!= std::string::npos) {\n";
		setGlobal = setGlobal + "				int val;\n";
		setGlobal = setGlobal + "				std::stringstream stream(it->second);\n";
		setGlobal = setGlobal + "				if (!(stream >> val)) {\n";
		setGlobal = setGlobal
				+ "					query = query + it->first + \"='\" + it->second + \"', \";\n";
		setGlobal = setGlobal + "				} else {\n";
		setGlobal = setGlobal
				+ "					query = query + it->first + \"=\" + it->second + \", \";\n";
		setGlobal = setGlobal + "				}\n";
		setGlobal = setGlobal + "			}\n";
		setGlobal = setGlobal + "		}\n";
		setGlobal = setGlobal
				+ "		query = query.substr(0, query.length() - 2) + \" \";//to delete the last ,\n";
		setGlobal = setGlobal
				+ "		query = query + \"WHERE _NAME='\" + data[\"name\"] + \"' \";\n";
		setGlobal = setGlobal
				+ "		query = query + \"AND \" + this->className.back() + \"ID=\"\n";
		setGlobal = setGlobal
				+ "				+ data[this->className.back() + \"ID\"];\n";
		setGlobal = setGlobal + "		stmt->executeUpdate(query);\n";
		setGlobal = setGlobal + "		delete (stmt);\n";
		setGlobal = setGlobal + "	}\n";
		setGlobal = setGlobal + "\n";
		setGlobal = setGlobal + "	catch (sql::SQLException &e) {\n";
		setGlobal = setGlobal
				+ "		std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		setGlobal = setGlobal
				+ "		std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		setGlobal = setGlobal + "				<< std::endl;\n";
		setGlobal = setGlobal + "		std::cout << \"# ERR: \" << e.what();\n";
		setGlobal = setGlobal
				+ "		std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		setGlobal = setGlobal
				+ "		std::cout << \", SQLState: \" << e.getSQLState() << \" )\" << std::endl;\n";
		setGlobal = setGlobal + "	}\n";
		setGlobal = setGlobal + "	// DATA MULTI\n";
		setGlobal = setGlobal + "\n";
		setGlobal = setGlobal + "	for (int unsigned i = 0; i\n";
		setGlobal = setGlobal
				+ "			< DAO::getSqlQueriesDataMulti[className.back()].size(); i++) {\n";
		setGlobal = setGlobal + "		try {\n";
		setGlobal = setGlobal + "			sql::Statement *stmt;\n";
		setGlobal = setGlobal
				+ "			stmt = connection->getCon()->createStatement();\n";
		setGlobal = setGlobal + "			std::string query;\n";
		setGlobal = setGlobal + "			query = \"DELETE FROM \";\n";
		setGlobal = setGlobal + "			query\n";
		setGlobal = setGlobal + "					= query\n";
		setGlobal = setGlobal
				+ "							+ DAO::getSqlQueriesDataMulti[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "									DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "											\"FROM\") + 5);\n";
		setGlobal = setGlobal
				+ "			query = query.substr(0, query.length() - 2) + \" \";//to delete the last ?\n";
		setGlobal = setGlobal
				+ "			query = query + data[this->className.back() + \"ID\"];\n";
		setGlobal = setGlobal + "			stmt->execute(query);\n";
		setGlobal = setGlobal + "\n";
		setGlobal = setGlobal + "			std::vector<std::string>\n";
		setGlobal = setGlobal + "					multi =\n";
		setGlobal = setGlobal + "							Explode(\n";
		setGlobal = setGlobal
				+ "									data[DAO::getSqlQueriesDataMulti[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "											DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "													\"SELECT\") + 7,\n";
		setGlobal = setGlobal
				+ "											DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "													\"FROM\")\n";
		setGlobal = setGlobal
				+ "													- (DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "															\"SELECT\") + 8))],\n";
		setGlobal = setGlobal + "									' ');\n";
		setGlobal = setGlobal
				+ "			if (!data[DAO::getSqlQueriesDataMulti[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "					DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "							\"SELECT\") + 7,\n";
		setGlobal = setGlobal
				+ "					DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "							\"FROM\")\n";
		setGlobal = setGlobal
				+ "							- (DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "									\"SELECT\") + 8))].empty())\n";
		setGlobal = setGlobal
				+ "				for (int unsigned i = 0; i < multi.size(); i++) {\n";
		setGlobal = setGlobal + "					query\n";
		setGlobal = setGlobal + "							= \"INSERT INTO \"\n";
		setGlobal = setGlobal
				+ "									+ DAO::getSqlQueriesDataMulti[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "											DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "													\"FROM\") + 5,\n";
		setGlobal = setGlobal
				+ "											DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "													\"WHERE\")\n";
		setGlobal = setGlobal
				+ "													- (DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "															\"FROM\") + 5));\n";
		setGlobal = setGlobal + "					query\n";
		setGlobal = setGlobal
				+ "							= query + \"(\" + this->className.back() + \"ID\"\n";
		setGlobal = setGlobal + "									+ \", \"\n";
		setGlobal = setGlobal
				+ "									+ DAO::getSqlQueriesDataMulti[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "											DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "													\"SELECT\") + 7,\n";
		setGlobal = setGlobal
				+ "											DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "													\"FROM\")\n";
		setGlobal = setGlobal
				+ "													- (DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "															\"SELECT\") + 8))\n";
		setGlobal = setGlobal + "									+ \")\";\n";
		setGlobal = setGlobal + "					int val;\n";
		setGlobal = setGlobal + "					std::stringstream stream(multi[i]);\n";
		setGlobal = setGlobal + "					if (!(stream >> val)) {\n";
		setGlobal = setGlobal + "						query = query + \" VALUES(\"\n";
		setGlobal = setGlobal
				+ "								+ data[this->className.back() + \"ID\"] + \", '\"\n";
		setGlobal = setGlobal + "								+ multi[i] + \"')\";\n";
		setGlobal = setGlobal + "					} else {\n";
		setGlobal = setGlobal + "						query = query + \" VALUES(\"\n";
		setGlobal = setGlobal
				+ "								+ data[this->className.back() + \"ID\"] + \", \"\n";
		setGlobal = setGlobal + "								+ multi[i] + \")\";\n";
		setGlobal = setGlobal + "					}\n";
		setGlobal = setGlobal + "					stmt->execute(query);\n";
		setGlobal = setGlobal + "\n";
		setGlobal = setGlobal + "				}\n";
		setGlobal = setGlobal + "			delete (stmt);\n";
		setGlobal = setGlobal + "		} catch (sql::SQLException &e) {\n";
		setGlobal = setGlobal
				+ "			std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		setGlobal = setGlobal
				+ "			std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		setGlobal = setGlobal + "					<< std::endl;\n";
		setGlobal = setGlobal + "			std::cout << \"# ERR: \" << e.what();\n";
		setGlobal = setGlobal
				+ "			std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		setGlobal = setGlobal
				+ "			std::cout << \", SQLState: \" << e.getSQLState() << \" )\" << std::endl;\n";
		setGlobal = setGlobal + "		}\n";
		setGlobal = setGlobal + "	}\n";
		setGlobal = setGlobal + "\n";
		setGlobal = setGlobal + "	// OBJECT SINGLE\n";
		setGlobal = setGlobal + "\n";
		setGlobal = setGlobal + "	for (int unsigned i = 0; i\n";
		setGlobal = setGlobal
				+ "			< DAO::getSqlQueriesObjectSingle[className.back()].size(); i++) {\n";
		setGlobal = setGlobal + "		try {\n";
		setGlobal = setGlobal + "			sql::Statement *stmt;\n";
		setGlobal = setGlobal
				+ "			stmt = connection->getCon()->createStatement();\n";
		setGlobal = setGlobal + "			std::string query;\n";
		setGlobal = setGlobal
				+ "			if (DAO::getSqlQueriesObjectSingle[className.back()][i].substr(0, 1)\n";
		setGlobal = setGlobal + "					!= \"-\") {\n";
		setGlobal = setGlobal
				+ "				query = \"UPDATE \" + className.back() + \" \";\n";
		setGlobal = setGlobal + "				query\n";
		setGlobal = setGlobal + "						= query + \"SET \"\n";
		setGlobal = setGlobal
				+ "								+ DAO::getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "										DAO::getSqlQueriesObjectSingle[className.back()][i].find(\n";
		setGlobal = setGlobal + "												\"/\") + 1) + \"='\"\n";
		setGlobal = setGlobal
				+ "								+ data[DAO::getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "										DAO::getSqlQueriesObjectSingle[className.back()][i].find(\n";
		setGlobal = setGlobal + "												\"/\") + 1)];\n";
		setGlobal = setGlobal
				+ "				query = query + \"' WHERE \" + this->className.back() + \"ID=\"\n";
		setGlobal = setGlobal
				+ "						+ data[this->className.back() + \"ID\"];\n";
		setGlobal = setGlobal
				+ "				if (!data[DAO::getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "						DAO::getSqlQueriesObjectSingle[className.back()][i].find(\n";
		setGlobal = setGlobal + "								\"/\") + 1)].empty())\n";
		setGlobal = setGlobal + "\n";
		setGlobal = setGlobal + "					stmt->execute(query);\n";
		setGlobal = setGlobal + "\n";
		setGlobal = setGlobal + "			} else {\n";
		setGlobal = setGlobal + "				query\n";
		setGlobal = setGlobal + "						= \"UPDATE \"\n";
		setGlobal = setGlobal
				+ "								+ DAO::getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		setGlobal = setGlobal + "										1,\n";
		setGlobal = setGlobal
				+ "										DAO::getSqlQueriesObjectSingle[className.back()][i].find(\n";
		setGlobal = setGlobal + "												\"/\") - 1);\n";
		setGlobal = setGlobal + "				query\n";
		setGlobal = setGlobal + "						= query + \" SET \"\n";
		setGlobal = setGlobal
				+ "								+ DAO::getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "										DAO::getSqlQueriesObjectSingle[className.back()][i].find(\n";
		setGlobal = setGlobal
				+ "												\"/\") + 1) + \"='\" + data[\"name\"];\n";
		setGlobal = setGlobal + "				query\n";
		setGlobal = setGlobal + "						= query + \"' WHERE _NAME='\"\n";
		setGlobal = setGlobal
				+ "								+ data[DAO::getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "										DAO::getSqlQueriesObjectSingle[className.back()][i].find(\n";
		setGlobal = setGlobal + "												\"/\") + 1)] + \"'\";\n";
		setGlobal = setGlobal
				+ "				if (!data[DAO::getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "						DAO::getSqlQueriesObjectSingle[className.back()][i].find(\n";
		setGlobal = setGlobal + "								\"/\") + 1)].empty())\n";
		setGlobal = setGlobal + "					stmt->execute(query);\n";
		setGlobal = setGlobal + "			}\n";
		setGlobal = setGlobal + "			delete (stmt);\n";
		setGlobal = setGlobal + "		} catch (sql::SQLException &e) {\n";
		setGlobal = setGlobal
				+ "			std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		setGlobal = setGlobal
				+ "			std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		setGlobal = setGlobal + "					<< std::endl;\n";
		setGlobal = setGlobal + "			std::cout << \"# ERR: \" << e.what();\n";
		setGlobal = setGlobal
				+ "			std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		setGlobal = setGlobal
				+ "			std::cout << \", SQLState: \" << e.getSQLState() << \" )\" << std::endl;\n";
		setGlobal = setGlobal + "		}\n";
		setGlobal = setGlobal + "	}\n";
		setGlobal = setGlobal + "\n";
		setGlobal = setGlobal + "	// OBJECT MULTI\n";
		setGlobal = setGlobal + "\n";
		setGlobal = setGlobal + "	for (int unsigned i = 0; i\n";
		setGlobal = setGlobal
				+ "			< DAO::getSqlQueriesObjectMulti[className.back()].size(); i++) {\n";
		setGlobal = setGlobal + "		try {\n";
		setGlobal = setGlobal + "			sql::Statement *stmt;\n";
		setGlobal = setGlobal
				+ "			stmt = connection->getCon()->createStatement();\n";
		setGlobal = setGlobal + "			std::string query;\n";
		setGlobal = setGlobal + "			query = \"DELETE FROM \";\n";
		setGlobal = setGlobal + "			query\n";
		setGlobal = setGlobal + "					= query\n";
		setGlobal = setGlobal
				+ "							+ DAO::getSqlQueriesObjectMulti[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "									DAO::getSqlQueriesObjectMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "											\"/\") + 1);\n";
		setGlobal = setGlobal
				+ "			query = query + \" WHERE \" + this->className.back() + \"ID=\"\n";
		setGlobal = setGlobal
				+ "					+ data[this->className.back() + \"ID\"];\n";
		setGlobal = setGlobal + "			stmt->execute(query);\n";
		setGlobal = setGlobal + "			std::vector<std::string>\n";
		setGlobal = setGlobal + "					multi =\n";
		setGlobal = setGlobal + "							Explode(\n";
		setGlobal = setGlobal
				+ "									data[DAO::getSqlQueriesObjectMulti[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "											DAO::getSqlQueriesObjectMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "													\"/\") + 1)], ' ');\n";
		setGlobal = setGlobal
				+ "			if(!data[DAO::getSqlQueriesObjectMulti[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "					DAO::getSqlQueriesObjectMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "							\"/\") + 1)].empty())\n";
		setGlobal = setGlobal
				+ "			for (int unsigned i = 0; i < multi.size(); i++) {\n";
		setGlobal = setGlobal + "				query\n";
		setGlobal = setGlobal + "						= \"INSERT INTO \"\n";
		setGlobal = setGlobal
				+ "								+ DAO::getSqlQueriesObjectMulti[className.back()][i].substr(\n";
		setGlobal = setGlobal
				+ "										DAO::getSqlQueriesObjectMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "												\"/\") + 1);\n";
		setGlobal = setGlobal + "				query\n";
		setGlobal = setGlobal
				+ "						= query + \" (\" + this->className.back() + \"ID\" + \",\"\n";
		setGlobal = setGlobal
				+ "								+ DAO::getSqlQueriesObjectMulti[className.back()][i].substr(\n";
		setGlobal = setGlobal + "										0,\n";
		setGlobal = setGlobal
				+ "										DAO::getSqlQueriesObjectMulti[className.back()][i].find(\n";
		setGlobal = setGlobal + "												\"/\")) + \"ID)\";\n";
		setGlobal = setGlobal + "\n";
		setGlobal = setGlobal + "				query = query + \" VALUES(\"\n";
		setGlobal = setGlobal
				+ "						+ data[this->className.back() + \"ID\"] + \", \" + multi[i]\n";
		setGlobal = setGlobal + "						+ \")\";\n";
		setGlobal = setGlobal + "				stmt->execute(query);\n";
		setGlobal = setGlobal + "			}\n";
		setGlobal = setGlobal + "			delete (stmt);\n";
		setGlobal = setGlobal + "\n";
		setGlobal = setGlobal + "		} catch (sql::SQLException &e) {\n";
		setGlobal = setGlobal
				+ "			std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		setGlobal = setGlobal
				+ "			std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		setGlobal = setGlobal + "					<< std::endl;\n";
		setGlobal = setGlobal + "			std::cout << \"# ERR: \" << e.what();\n";
		setGlobal = setGlobal
				+ "			std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		setGlobal = setGlobal
				+ "			std::cout << \", SQLState: \" << e.getSQLState() << \" )\" << std::endl;\n";
		setGlobal = setGlobal + "		}\n";
		setGlobal = setGlobal + "	}\n";
		setGlobal = setGlobal + "		}\n";

		String explode = "";
		explode = explode + "std::vector<std::string> DAO"
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
		
		String getAll="\n\n";
		getAll=getAll+"std::map<std::string, std::vector<std::string> > DAO::getAll(std::vector<\n";
		getAll=getAll+"		std::string> attributesList, std::string table) {\n";
		getAll=getAll+"	std::map<std::string, std::vector<std::string> > result;\n";
		getAll=getAll+"	try {\n";
		getAll=getAll+"		sql::ResultSetMetaData *res_meta;\n";
		getAll=getAll+"		sql::ResultSet *res;\n";
		getAll=getAll+"		sql::Statement *stmt;\n";
		getAll=getAll+"		std::string attributes = \"\";\n";
		getAll=getAll+"		for (int i = 0; i < (int) attributesList.size(); i++) {\n";
		getAll=getAll+"			attributes = attributes + \", \" + attributesList[i];\n";
		getAll=getAll+"		}\n";
		getAll=getAll+"		std::string query = \"SELECT \" + attributes.substr(2) + \" FROM \" + table;\n";
		getAll=getAll+"		stmt = connection->getCon()->createStatement();\n";
		getAll=getAll+"		res = stmt->executeQuery(query);\n";
		getAll=getAll+"		res_meta = res -> getMetaData();\n";
		getAll=getAll+"		while (res->next()) {\n";
		getAll=getAll+"			for (int i = 0; i < (int) res_meta -> getColumnCount(); ++i) {\n";
		getAll=getAll+"				std::vector<std::string> temp =\n";
		getAll=getAll+"						result[res_meta -> getColumnLabel(i + 1)];\n";
		getAll=getAll+"				temp.push_back(res->getString(i + 1));\n";
		getAll=getAll+"				result[res_meta -> getColumnLabel(i + 1)] = temp;\n";
		getAll=getAll+"			}\n";
		getAll=getAll+"		}\n";
		getAll=getAll+"		delete (res);\n";
		getAll=getAll+"		delete (stmt);\n";
		getAll=getAll+"\n";
		getAll=getAll+"	} catch (sql::SQLException &e) {\n";
		getAll=getAll+"		std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getAll=getAll+"		std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		getAll=getAll+"				<< std::endl;\n";
		getAll=getAll+"		std::cout << \"# ERR: \" << e.what();\n";
		getAll=getAll+"		std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		getAll=getAll+"		std::cout << \", SQLState: \" << e.getSQLState() << \" )\" << std::endl;\n";
		getAll=getAll+"	}\n";
		getAll=getAll+"	return result;\n";
		getAll=getAll+"}\n";
		getAll=getAll+"\n";

		String destructor = "DAO::~DAO() {\n\n}";

		return result + destructor + getGlobal + setGlobal + explode + getAll;
	}

	/**
	 * \brief Method used to generate the Select queries.
	 */
	public void generateGetSQL() {
		fillGetSqlQueries();
	}

	/**
	 * \brief Write the header file on the Disk. \param data Data you want to
	 * write. \param path Path of your file
	 */
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

	/**
	 * \brief Write the C++ file on the Disk. \param data Data you want to
	 * write. \param path Path of your file
	 */
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
