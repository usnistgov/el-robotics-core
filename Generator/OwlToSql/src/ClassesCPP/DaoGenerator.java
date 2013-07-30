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
		include = include + "\n#include <typeinfo>\n";
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
		pub = pub + "\nvoid insert(std::map<std::string,std::string> data);";
		pub = pub
				+ "\nstd::vector<std::string> Explode(const std::string & str, char separator);";
		pub = pub + "\nbool toAdd(std::string s);";

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
		getGlobal+="nameDone.push_back(className.back() + \"+\" + name);\n";
		getGlobal+= "	try {\n";
		getGlobal+= "		sql::PreparedStatement *prep_stmt;\n";
		getGlobal+="		sql::ResultSet *res;// get the ID with the name\n";
		getGlobal+="		prep_stmt = connection->getCon()->prepareStatement(\"SELECT \"\n";
		getGlobal+="				+ className.back() + \"ID FROM \" + className.back()\n";
		getGlobal+= "				+ \" WHERE _Name = ?\");\n";
		getGlobal+= "		prep_stmt->setString(1, name);\n";
		getGlobal+= "		res = prep_stmt->executeQuery();\n";
		getGlobal+= "		res->next();\n";
		getGlobal+= "		int id = res->getInt(1);\n";
		getGlobal+= "		delete (res);\n";
		getGlobal+= "		delete (prep_stmt);\n";
		getGlobal+= "		// get the data Single\n";
		getGlobal+= "		sql::ResultSetMetaData *res_meta;\n";
		getGlobal+="		prep_stmt = connection->getCon()->prepareStatement(\n";
		getGlobal+="				DAO::getSqlQueriesDataSingle[className.back()]);\n";
		getGlobal+= "		prep_stmt->setInt(1, id);\n";
		getGlobal+= "		res = prep_stmt->executeQuery();\n";
		getGlobal+= "		res->next();\n";
		getGlobal+= "		res_meta = res -> getMetaData();\n";
		getGlobal+="		for (int i = 0; i < (int) res_meta -> getColumnCount(); ++i) {\n";
		getGlobal+="			map[res_meta -> getColumnLabel(i + 1)] = res->getString(i + 1);\n";
		getGlobal+= "		}\n";
		getGlobal+= "		delete (res);\n";
		getGlobal+= "		delete (prep_stmt);\n";
		getGlobal+= "		// get the data multi\n";
		getGlobal+= "		std::string temp = \"\";\n";
		getGlobal+= "		for (int unsigned i = 0; i\n";
		getGlobal+="				< DAO::getSqlQueriesDataMulti[className.back()].size(); i++) {\n";
		getGlobal+= "			try {\n";
		getGlobal+="				prep_stmt = connection->getCon()->prepareStatement(\n";
		getGlobal+="						DAO::getSqlQueriesDataMulti[className.back()][i]);\n";
		getGlobal+= "				prep_stmt->setInt(1, id);\n";
		getGlobal+= "				res = prep_stmt->executeQuery();\n";
		getGlobal+= "				while (res->next()) {\n";
		getGlobal+= "					if (!res->isLast())\n";
		getGlobal+="						temp = temp + res->getString(1) + \" \";\n";
		getGlobal+= "					else\n";
		getGlobal+= "						temp = temp + res->getString(1);\n";
		getGlobal+= "				}\n";
		getGlobal+= "				res_meta = res -> getMetaData();\n";
		getGlobal+="				map[res_meta -> getColumnLabel(1)] = temp;\n";
		getGlobal+= "				delete (res);\n";
		getGlobal+= "				delete (prep_stmt);\n";
		getGlobal+= "			} catch (sql::SQLException &e) {/*\n";
		getGlobal+="				std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getGlobal+="				std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		getGlobal+= "						<< std::endl;\n";
		getGlobal+= "				std::cout << \"# ERR: \" << e.what();\n";
		getGlobal+="				std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		getGlobal+="				std::cout << \", SQLState: \" << e.getSQLState() << \" )\"\n";
		getGlobal+= "						<< std::endl;\n";
		getGlobal+= "			*/}\n";
		getGlobal+= "		}\n";
		getGlobal+= "		// get the Object Single\n";
		getGlobal+= "		temp = \"\";\n";
		getGlobal+= "		sql::ResultSet *restemp;\n";
		getGlobal+= "		sql::Statement *stmt;\n";
		getGlobal+= "		std::string newName = \"\";\n";
		getGlobal+= "		std::string newTable = \"\";\n";
		getGlobal+= "		for (int unsigned i = 0; i\n";
		getGlobal+="				< DAO::getSqlQueriesObjectSingle[className.back()].size(); i++) {\n";
		getGlobal+= "			try {\n";
		getGlobal+="				stmt = connection->getCon()->createStatement();\n";
		getGlobal+="				if (getSqlQueriesObjectSingle[className.back()][i].substr(0, 1)\n";
		getGlobal+= "						!= \"-\") {\n";
		getGlobal+= "					restemp\n";
		getGlobal+= "							= stmt->executeQuery(\n";
		getGlobal+= "									\"SELECT \"\n";
		getGlobal+="											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+= "													0,\n";
		getGlobal+="													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "															\"/\")) + \"ID FROM \"\n";
		getGlobal+="											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+= "													0,\n";
		getGlobal+="													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "															\"/\")) + \", \"\n";
		getGlobal+= "											+ className.back() + \" WHERE \"\n";
		getGlobal+="											+ className.back() + \"._Name = '\"\n";
		getGlobal+= "											+ name + \"' AND \"\n";
		getGlobal+="											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+="													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "															\"/\") + 1) + \" = \"\n";
		getGlobal+="											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+= "													0,\n";
		getGlobal+="													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "															\"/\")) + \"._Name\");\n";
		getGlobal+= "					prep_stmt\n";
		getGlobal+="							= connection->getCon()->prepareStatement(\n";
		getGlobal+="									DAO::getSqlQueriesDataSingle[getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+= "											0,\n";
		getGlobal+="											getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "													\"/\"))]);\n";
		getGlobal+= "				} else {\n";
		getGlobal+= "\n";
		getGlobal+= "					restemp\n";
		getGlobal+= "							= stmt->executeQuery(\n";
		getGlobal+= "									\"SELECT \"\n";
		getGlobal+="											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+= "													1,\n";
		getGlobal+="													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "															\"/\") - 1)\n";
		getGlobal+= "											+ \"ID FROM \"\n";
		getGlobal+="											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+= "													1,\n";
		getGlobal+="													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "															\"/\") - 1) + \", \"\n";
		getGlobal+= "											+ className.back() + \" WHERE \"\n";
		getGlobal+="											+ className.back() + \"._Name = '\"\n";
		getGlobal+= "											+ name + \"' AND \"\n";
		getGlobal+="											+ getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+="													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "															\"/\") + 1) + \" = \"\n";
		getGlobal+="											+ className.back() + \"._Name\");\n";
		getGlobal+= "					prep_stmt\n";
		getGlobal+="							= connection->getCon()->prepareStatement(\n";
		getGlobal+="									DAO::getSqlQueriesDataSingle[getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+= "											1,\n";
		getGlobal+="											getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "													\"/\") - 1)]);\n";
		getGlobal+= "				}\n";
		getGlobal+= "				do {\n";
		getGlobal+= "					restemp->next();\n";
		getGlobal+="					prep_stmt->setInt(1, restemp->getInt(1));\n";
		getGlobal+= "					res = prep_stmt->executeQuery();\n";
		getGlobal+= "					do {\n";
		getGlobal+= "						res->next();\n";
		getGlobal+= "						res_meta = res -> getMetaData();\n";
		getGlobal+="						for (int j = 0; j < (int) res_meta -> getColumnCount(); ++j) {\n";
		getGlobal+="							if (map[getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+="									getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "											\"/\") + 1) + \"/\"\n";
		getGlobal+="									+ res_meta -> getColumnLabel(j + 1)] == \"\") {\n";
		getGlobal+="								map[getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+="										getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "												\"/\") + 1) + \"/\"\n";
		getGlobal+="										+ res_meta -> getColumnLabel(j + 1)]\n";
		getGlobal+= "										= res->getString(j + 1);\n";
		getGlobal+= "							} else {\n";
		getGlobal+="								map[getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+="										getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "												\"/\") + 1) + \"/\"\n";
		getGlobal+="										+ res_meta -> getColumnLabel(j + 1)]\n";
		getGlobal+= "										+= \" \" + res->getString(j + 1);\n";
		getGlobal+= "\n";
		getGlobal+= "							}\n";
		getGlobal+= "						}\n";
		getGlobal+="						if (getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+= "								0, 1) != \"-\") {\n";
		getGlobal+= "							newName\n";
		getGlobal+= "									= res->getString(\n";
		getGlobal+="											getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+= "													0,\n";
		getGlobal+="													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "															\"/\")) + \"._NAME\");\n";
		getGlobal+= "						} else {\n";
		getGlobal+= "							newName\n";
		getGlobal+= "									= res->getString(\n";
		getGlobal+="											getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+= "													1,\n";
		getGlobal+="													getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "															\"/\") - 1)\n";
		getGlobal+= "													+ \"._NAME\");\n";
		getGlobal+= "\n";
		getGlobal+= "						}\n";
		getGlobal+= "\n";
		getGlobal+="						if (getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+= "								0, 1) != \"-\") {\n";
		getGlobal+= "							newTable\n";
		getGlobal+="									= getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+= "											0,\n";
		getGlobal+="											getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "													\"/\"));\n";
		getGlobal+= "						} else {\n";
		getGlobal+= "							newTable\n";
		getGlobal+="									= getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		getGlobal+= "											1,\n";
		getGlobal+="											getSqlQueriesObjectSingle[className.back()][i].find(\n";
		getGlobal+= "													\"/\") - 1);\n";
		getGlobal+= "						}\n";
		getGlobal+= "\n";
		getGlobal+= "					} while (!res->isLast());\n";
		getGlobal+= "					delete (res);\n";
		getGlobal+= "\n";
		getGlobal+= "				} while (!restemp->isLast());\n";
		getGlobal+= "				delete (restemp);\n";
		getGlobal+= "\n";
		getGlobal+= "				delete (prep_stmt);\n";
		getGlobal+= "				delete (stmt);\n";
		getGlobal+= "			} catch (sql::SQLException &e) {/*\n";
		getGlobal+="				std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getGlobal+="				std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		getGlobal+= "						<< std::endl;\n";
		getGlobal+= "				std::cout << \"# ERR: \" << e.what();\n";
		getGlobal+="				std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		getGlobal+="				std::cout << \", SQLState: \" << e.getSQLState() << \" )\"\n";
		getGlobal+= "						<< std::endl;\n";
		getGlobal+= "			*/}\n";
		getGlobal+= "		}\n";
		getGlobal+= "\n";
		getGlobal+= "		//get the Object multi\n";
		getGlobal+= "		sql::ResultSet *restempmulti;\n";
		getGlobal+= "		sql::Statement *stmtmulti;\n";
		getGlobal+= "		for (int unsigned m = 0; m\n";
		getGlobal+="				< DAO::getSqlQueriesObjectMulti[className.back()].size(); m++) {\n";
		getGlobal+= "			try {\n";
		getGlobal+= "				//convert id to string\n";
		getGlobal+= "				std::string sid;\n";
		getGlobal+= "				std::stringstream out;\n";
		getGlobal+= "				out << id;\n";
		getGlobal+= "				sid = out.str();\n";
		getGlobal+= "				//end convert id\n";
		getGlobal+="				stmtmulti = connection->getCon()->createStatement();\n";
		getGlobal+= "				restempmulti\n";
		getGlobal+= "						= stmtmulti->executeQuery(\n";
		getGlobal+= "								\"SELECT \"\n";
		getGlobal+="										+ getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal+= "												0,\n";
		getGlobal+="												getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal+= "														\"/\")) + \"ID FROM \"\n";
		getGlobal+="										+ getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal+="												getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal+= "														\"/\") + 1) + \" WHERE \"\n";
		getGlobal+="										+ className.back() + \"ID = \" + sid);\n";
		getGlobal+= "				do {\n";
		getGlobal+= "					restempmulti->next();\n";
		getGlobal+= "					std::string\n";
		getGlobal+= "							table =\n";
		getGlobal+="									getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal+= "											0,\n";
		getGlobal+="											getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal+= "													\"/\"));\n";
		getGlobal+= "\n";
		getGlobal+= "					//Add the data\n";
		getGlobal+= "					prep_stmt\n";
		getGlobal+="							= connection->getCon()->prepareStatement(\n";
		getGlobal+="									DAO::getSqlQueriesDataSingle[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal+= "											0,\n";
		getGlobal+="											getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal+= "													\"/\"))]);\n";
		getGlobal+="					prep_stmt->setInt(1, restempmulti->getInt(1));\n";
		getGlobal+= "					res = prep_stmt->executeQuery();\n";
		getGlobal+= "					res->next();\n";
		getGlobal+= "\n";
		getGlobal+= "					res_meta = res -> getMetaData();\n";
		getGlobal+="					for (int i = 0; i < (int) res_meta -> getColumnCount(); ++i) {\n";
		getGlobal+="						if (map[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal+="								getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal+= "										\"/\") + 1) + \"/\"\n";
		getGlobal+="								+ res_meta -> getColumnLabel(i + 1)] == \"\")\n";
		getGlobal+="							map[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal+="									getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal+= "											\"/\") + 1) + \"/\"\n";
		getGlobal+="									+ res_meta -> getColumnLabel(i + 1)]\n";
		getGlobal+= "									= res->getString(i + 1);\n";
		getGlobal+= "						else\n";
		getGlobal+="							map[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal+="									getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal+= "											\"/\") + 1) + \"/\"\n";
		getGlobal+="									+ res_meta -> getColumnLabel(i + 1)] += \" \"\n";
		getGlobal+= "									+ res->getString(i + 1);\n";
		getGlobal+= "\n";
		getGlobal+= "					}\n";
		getGlobal+= "					delete (prep_stmt);\n";
		getGlobal+= "					delete (res);\n";
		getGlobal+= "					//End Add the Data\n";
		getGlobal+= "					//Add the Data multi\n";
		getGlobal+= "					std::string temp = \"\";\n";
		getGlobal+= "					for (int unsigned i = 0; i\n";
		getGlobal+="							< DAO::getSqlQueriesDataMulti[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal+= "									0,\n";
		getGlobal+="									getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal+= "											\"/\"))].size(); i++) {\n";
		getGlobal+= "						try {\n";
		getGlobal+= "							prep_stmt\n";
		getGlobal+="									= connection->getCon()->prepareStatement(\n";
		getGlobal+="											DAO::getSqlQueriesDataMulti[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal+= "													0,\n";
		getGlobal+="													getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal+= "															\"/\"))][i]);\n";
		getGlobal+="							prep_stmt->setInt(1, restempmulti->getInt(1));\n";
		getGlobal+= "							res = prep_stmt->executeQuery();\n";
		getGlobal+= "							while (res->next()) {\n";
		getGlobal+= "								if (!res->isLast())\n";
		getGlobal+="									temp = temp + res->getString(1) + \" \";\n";
		getGlobal+= "								else\n";
		getGlobal+= "									temp = temp + res->getString(1);\n";
		getGlobal+= "\n";
		getGlobal+= "							}\n";
		getGlobal+= "							res_meta = res -> getMetaData();\n";
		getGlobal+="							map[getSqlQueriesObjectMulti[className.back()][m].substr(\n";
		getGlobal+="									getSqlQueriesObjectMulti[className.back()][m].find(\n";
		getGlobal+= "											\"/\") + 1) + \"/\"\n";
		getGlobal+="									+ res_meta -> getColumnLabel(1)] = temp;\n";
		getGlobal+= "							delete (res);\n";
		getGlobal+= "							delete (prep_stmt);\n";
		getGlobal+= "						} catch (sql::SQLException &e) {/*\n";
		getGlobal+="							std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getGlobal+="							std::cout << \"(\" << __FUNCTION__ << \") on line \"\n";
		getGlobal+= "									<< __LINE__ << std::endl;\n";
		getGlobal+="							std::cout << \"# ERR: \" << e.what();\n";
		getGlobal+="							std::cout << \" (MySQL error code: \"\n";
		getGlobal+= "									<< e.getErrorCode();\n";
		getGlobal+="							std::cout << \", SQLState: \" << e.getSQLState()\n";
		getGlobal+= "									<< \" )\" << std::endl;\n";
		getGlobal+= "						*/}\n";
		getGlobal+= "					}\n";
		getGlobal+= "					//End Add Data Multi\n";
		getGlobal+= "					// Add Object Single\n";
		getGlobal+= "					for (int unsigned i = 0; i\n";
		getGlobal+="							< DAO::getSqlQueriesObjectSingle[table].size(); i++) {\n";
		getGlobal+= "						try {\n";
		getGlobal+="							stmt = connection->getCon()->createStatement();\n";
		getGlobal+="							if (getSqlQueriesObjectSingle[table][i].substr(0, 1)\n";
		getGlobal+= "									!= \"-\") {\n";
		getGlobal+= "								restemp\n";
		getGlobal+= "										= stmt->executeQuery(\n";
		getGlobal+= "												\"SELECT \"\n";
		getGlobal+="														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+= "																0,\n";
		getGlobal+="																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "																		\"/\"))\n";
		getGlobal+= "														+ \"ID FROM \"\n";
		getGlobal+="														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+= "																0,\n";
		getGlobal+="																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "																		\"/\"))\n";
		getGlobal+= "														+ \", \" + table\n";
		getGlobal+= "														+ \" WHERE \" + table\n";
		getGlobal+= "														+ \"._Name = '\" + name\n";
		getGlobal+= "														+ \"' AND \"\n";
		getGlobal+="														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+="																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "																		\"/\")\n";
		getGlobal+= "																		+ 1)\n";
		getGlobal+= "														+ \" = \"\n";
		getGlobal+="														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+= "																0,\n";
		getGlobal+="																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "																		\"/\"))\n";
		getGlobal+= "														+ \"._Name\");\n";
		getGlobal+= "\n";
		getGlobal+= "								prep_stmt\n";
		getGlobal+="										= connection->getCon()->prepareStatement(\n";
		getGlobal+="												DAO::getSqlQueriesDataSingle[getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+= "														0,\n";
		getGlobal+="														getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "																\"/\"))]);\n";
		getGlobal+= "							} else {\n";
		getGlobal+= "\n";
		getGlobal+= "								restemp\n";
		getGlobal+= "										= stmt->executeQuery(\n";
		getGlobal+= "												\"SELECT \"\n";
		getGlobal+="														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+= "																1,\n";
		getGlobal+="																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "																		\"/\")\n";
		getGlobal+= "																		- 1)\n";
		getGlobal+= "														+ \"ID FROM \"\n";
		getGlobal+="														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+= "																1,\n";
		getGlobal+="																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "																		\"/\")\n";
		getGlobal+= "																		- 1)\n";
		getGlobal+= "														+ \", \" + table\n";
		getGlobal+= "														+ \" WHERE \" + table\n";
		getGlobal+= "														+ \"._Name = '\" + name\n";
		getGlobal+= "														+ \"' AND \"\n";
		getGlobal+="														+ getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+="																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "																		\"/\")\n";
		getGlobal+= "																		+ 1)\n";
		getGlobal+= "														+ \" = \" + table\n";
		getGlobal+= "														+ \"._Name\");\n";
		getGlobal+= "								prep_stmt\n";
		getGlobal+="										= connection->getCon()->prepareStatement(\n";
		getGlobal+="												DAO::getSqlQueriesDataSingle[getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+= "														1,\n";
		getGlobal+="														getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "																\"/\") - 1)]);\n";
		getGlobal+= "							}\n";
		getGlobal+= "							do {\n";
		getGlobal+= "								restemp->next();\n";
		getGlobal+="								prep_stmt->setInt(1, restemp->getInt(1));\n";
		getGlobal+= "								res = prep_stmt->executeQuery();\n";
		getGlobal+= "								do {\n";
		getGlobal+= "									res->next();\n";
		getGlobal+= "									res_meta = res -> getMetaData();\n";
		getGlobal+= "									for (int j = 0; j\n";
		getGlobal+="											< (int) res_meta -> getColumnCount(); ++j) {\n";
		getGlobal+="										if (map[getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+="												getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "														\"/\") + 1) + \"/\"\n";
		getGlobal+= "												+ res_meta -> getColumnLabel(j\n";
		getGlobal+= "														+ 1)] == \"\")\n";
		getGlobal+="											map[getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+="													getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "															\"/\") + 1) + \"/\"\n";
		getGlobal+= "													+ res_meta -> getColumnLabel(\n";
		getGlobal+= "															j + 1)]\n";
		getGlobal+= "													= res->getString(j + 1);\n";
		getGlobal+= "\n";
		getGlobal+= "										else\n";
		getGlobal+="											map[getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+="													getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "															\"/\") + 1) + \"/\"\n";
		getGlobal+= "													+ res_meta -> getColumnLabel(\n";
		getGlobal+= "															j + 1)] += \" \"\n";
		getGlobal+= "													+ res->getString(j + 1);\n";
		getGlobal+= "									}\n";
		getGlobal+="									if (getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+= "											0, 1) != \"-\") {\n";
		getGlobal+= "										newName\n";
		getGlobal+= "												= res->getString(\n";
		getGlobal+="														getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+= "																0,\n";
		getGlobal+="																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "																		\"/\"))\n";
		getGlobal+= "																+ \"._NAME\");\n";
		getGlobal+= "									} else {\n";
		getGlobal+= "										newName\n";
		getGlobal+= "												= res->getString(\n";
		getGlobal+="														getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+= "																1,\n";
		getGlobal+="																getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "																		\"/\")\n";
		getGlobal+= "																		- 1)\n";
		getGlobal+= "																+ \"._NAME\");\n";
		getGlobal+= "\n";
		getGlobal+= "									}\n";
		getGlobal+= "\n";
		getGlobal+="									if (getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+= "											0, 1) != \"-\") {\n";
		getGlobal+= "										newTable\n";
		getGlobal+="												= getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+= "														0,\n";
		getGlobal+="														getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "																\"/\"));\n";
		getGlobal+= "									} else {\n";
		getGlobal+= "										newTable\n";
		getGlobal+="												= getSqlQueriesObjectSingle[table][i].substr(\n";
		getGlobal+= "														1,\n";
		getGlobal+="														getSqlQueriesObjectSingle[table][i].find(\n";
		getGlobal+= "																\"/\") - 1);\n";
		getGlobal+= "									}\n";
		getGlobal+= "\n";
		getGlobal+= "								} while (!res->isLast());\n";
		getGlobal+= "								delete (res);\n";
		getGlobal+= "\n";
		getGlobal+= "							} while (!restemp->isLast());\n";
		getGlobal+= "							delete (restemp);\n";
		getGlobal+= "\n";
		getGlobal+= "							delete (prep_stmt);\n";
		getGlobal+= "							delete (stmt);\n";
		getGlobal+= "						} catch (sql::SQLException &e) {/*\n";
		getGlobal+="							std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getGlobal+="							std::cout << \"(\" << __FUNCTION__ << \") on line \"\n";
		getGlobal+= "									<< __LINE__ << std::endl;\n";
		getGlobal+="							std::cout << \"# ERR: \" << e.what();\n";
		getGlobal+="							std::cout << \" (MySQL error code: \"\n";
		getGlobal+= "									<< e.getErrorCode();\n";
		getGlobal+="							std::cout << \", SQLState: \" << e.getSQLState()\n";
		getGlobal+= "									<< \" )\" << std::endl;\n";
		getGlobal+= "						*/}\n";
		getGlobal+= "					}\n";
		getGlobal+= "				} while (!restempmulti->isLast());\n";
		getGlobal+= "				delete (restempmulti);\n";
		getGlobal+= "			} catch (sql::SQLException &e) {/*\n";
		getGlobal+="				std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getGlobal+="				std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		getGlobal+= "						<< std::endl;\n";
		getGlobal+= "				std::cout << \"# ERR: \" << e.what();\n";
		getGlobal+="				std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		getGlobal+="				std::cout << \", SQLState: \" << e.getSQLState() << \" )\"\n";
		getGlobal+= "						<< std::endl;\n";
		getGlobal+= "			*/}\n";
		getGlobal+= "		}\n";
		getGlobal+= "	} catch (sql::SQLException &e) {/*\n";
		getGlobal+="		std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getGlobal+="		std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		getGlobal+= "				<< std::endl;\n";
		getGlobal+= "		std::cout << \"# ERR: \" << e.what();\n";
		getGlobal+= "		std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		getGlobal+="		std::cout << \", SQLState: \" << e.getSQLState() << \" )\" << std::endl;\n";
		getGlobal+= "	*/}\n";
		getGlobal+= "	className.pop_back();\n";
		getGlobal+= "	return map;\n";
		getGlobal+= "	}\n";

		String setGlobal = "void DAO::set(std::map<std::string,std::string> data){";
		setGlobal+= "	try {\n";
		setGlobal+= "		// DATA SINGLE\n";
		setGlobal+= "		sql::Statement *stmt;\n";
		setGlobal+="		stmt = connection->getCon()->createStatement();\n";
		setGlobal+="		std::string query = \"UPDATE \" + this->className.back();\n";
		setGlobal+= "		query = query + \" SET \";\n";
		setGlobal+="		for (std::map<std::string, std::string>::iterator it = data.begin(); it\n";
		setGlobal+= "				!= data.end(); it++) {\n";
		setGlobal+="			if (DAO::getSqlQueriesDataSingle[this->className.back()].find(\n";
		setGlobal+="					this->className.back() + \".\" + it->first)\n";
		setGlobal+= "					!= std::string::npos) {\n";
		setGlobal+="					query = query + it->first + \"=\" + it->second + \", \";\n";
		setGlobal+= "			}\n";
		setGlobal+= "		}\n";
		setGlobal+="		query = query.substr(0, query.length() - 2) + \" \";//to delete the last ,\n";
		setGlobal+="		query = query + \"WHERE _NAME=\" + data[\"name\"] + \" \";\n";
		setGlobal+="		query = query + \" AND \" + this->className.back() + \"ID=\"\n";
		setGlobal+="				+ data[this->className.back() + \"ID\"];\n";
		setGlobal+= "		stmt->executeUpdate(query);\n";
		setGlobal+= "		delete (stmt);\n";
		setGlobal+= "	}\n";
		setGlobal+= "\n";
		setGlobal+= "	catch (sql::SQLException &e) {/*\n";
		setGlobal+="		std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		setGlobal+="		std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		setGlobal+= "				<< std::endl;\n";
		setGlobal+= "		std::cout << \"# ERR: \" << e.what();\n";
		setGlobal+="		std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		setGlobal+="		std::cout << \", SQLState: \" << e.getSQLState() << \" )\" << std::endl;\n";
		setGlobal+= "	*/}\n";
		setGlobal+= "	// DATA MULTI\n";
		setGlobal+= "\n";
		setGlobal+= "	for (int unsigned i = 0; i\n";
		setGlobal+="			< DAO::getSqlQueriesDataMulti[className.back()].size(); i++) {\n";
		setGlobal+= "		try {\n";
		setGlobal+= "			sql::Statement *stmt;\n";
		setGlobal+="			stmt = connection->getCon()->createStatement();\n";
		setGlobal+= "			std::string query;\n";
		setGlobal+= "			query = \"DELETE FROM \";\n";
		setGlobal+= "			query\n";
		setGlobal+= "					= query\n";
		setGlobal+="							+ DAO::getSqlQueriesDataMulti[className.back()][i].substr(\n";
		setGlobal+="									DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal+= "											\"FROM\") + 5);\n";
		setGlobal+="			query = query.substr(0, query.length() - 2) + \" \";//to delete the last ?\n";
		setGlobal+="			query = query + data[this->className.back() + \"ID\"];\n";
		setGlobal+= "			stmt->execute(query);\n";
		setGlobal+= "\n";
		setGlobal+= "			std::vector<std::string>\n";
		setGlobal+= "					multi =\n";
		setGlobal+= "							Explode(\n";
		setGlobal+="									data[DAO::getSqlQueriesDataMulti[className.back()][i].substr(\n";
		setGlobal+="											DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal+= "													\"SELECT\") + 7,\n";
		setGlobal+="											DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal+= "													\"FROM\")\n";
		setGlobal+="													- (DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal+= "															\"SELECT\") + 8))],\n";
		setGlobal+= "									' ');\n";
		setGlobal+="			if (!data[DAO::getSqlQueriesDataMulti[className.back()][i].substr(\n";
		setGlobal+="					DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal+= "							\"SELECT\") + 7,\n";
		setGlobal+="					DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal+= "							\"FROM\")\n";
		setGlobal+="							- (DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal+= "									\"SELECT\") + 8))].empty())\n";
		setGlobal+="				for (int unsigned i = 0; i < multi.size(); i++) {\n";
		setGlobal+= "					query\n";
		setGlobal+= "							= \"INSERT INTO \"\n";
		setGlobal+="									+ DAO::getSqlQueriesDataMulti[className.back()][i].substr(\n";
		setGlobal+="											DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal+= "													\"FROM\") + 5,\n";
		setGlobal+="											DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal+= "													\"WHERE\")\n";
		setGlobal+="													- (DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal+= "															\"FROM\") + 5));\n";
		setGlobal+= "					query\n";
		setGlobal+="							= query + \"(\" + this->className.back() + \"ID\"\n";
		setGlobal+= "									+ \", \"\n";
		setGlobal+="									+ DAO::getSqlQueriesDataMulti[className.back()][i].substr(\n";
		setGlobal+="											DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal+= "													\"SELECT\") + 7,\n";
		setGlobal+="											DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal+= "													\"FROM\")\n";
		setGlobal+="													- (DAO::getSqlQueriesDataMulti[className.back()][i].find(\n";
		setGlobal+= "															\"SELECT\") + 8))\n";
		setGlobal+= "									+ \")\";\n";
		setGlobal+= "					int val;\n";
		setGlobal+= "					std::stringstream stream(multi[i]);\n";
		setGlobal+= "					if (!(stream >> val)) {\n";
		setGlobal+= "						query = query + \" VALUES(\"\n";
		setGlobal+="								+ data[this->className.back() + \"ID\"] + \", '\"\n";
		setGlobal+= "								+ multi[i] + \"')\";\n";
		setGlobal+= "					} else {\n";
		setGlobal+= "						query = query + \" VALUES(\"\n";
		setGlobal+="								+ data[this->className.back() + \"ID\"] + \", \"\n";
		setGlobal+= "								+ multi[i] + \")\";\n";
		setGlobal+= "					}\n";
		setGlobal+= "					stmt->execute(query);\n";
		setGlobal+= "\n";
		setGlobal+= "				}\n";
		setGlobal+= "			delete (stmt);\n";
		setGlobal+= "		} catch (sql::SQLException &e) {/*\n";
		setGlobal+="			std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		setGlobal+="			std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		setGlobal+= "					<< std::endl;\n";
		setGlobal+= "			std::cout << \"# ERR: \" << e.what();\n";
		setGlobal+="			std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		setGlobal+="			std::cout << \", SQLState: \" << e.getSQLState() << \" )\" << std::endl;\n";
		setGlobal+= "		*/}\n";
		setGlobal+= "	}\n";
		setGlobal+= "\n";
		setGlobal+= "	// OBJECT SINGLE\n";
		setGlobal+= "\n";
		setGlobal+= "	for (int unsigned i = 0; i\n";
		setGlobal+="			< DAO::getSqlQueriesObjectSingle[className.back()].size(); i++) {\n";
		setGlobal+= "		try {\n";
		setGlobal+= "			sql::Statement *stmt;\n";
		setGlobal+="			stmt = connection->getCon()->createStatement();\n";
		setGlobal+= "			std::string query;\n";
		setGlobal+="			if (DAO::getSqlQueriesObjectSingle[className.back()][i].substr(0, 1)\n";
		setGlobal+= "					!= \"-\") {\n";
		setGlobal+="				query = \"UPDATE \" + className.back() + \" \";\n";
		setGlobal+= "				query\n";
		setGlobal+= "						= query + \"SET \"\n";
		setGlobal+="								+ DAO::getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		setGlobal+="										DAO::getSqlQueriesObjectSingle[className.back()][i].find(\n";
		setGlobal+= "												\"/\") + 1) + \"=\"\n";
		setGlobal+="								+ data[DAO::getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		setGlobal+="										DAO::getSqlQueriesObjectSingle[className.back()][i].find(\n";
		setGlobal+= "												\"/\") + 1)];\n";
		setGlobal+="				query = query + \" WHERE \" + this->className.back() + \"ID=\"\n";
		setGlobal+="						+ data[this->className.back() + \"ID\"];\n";

		setGlobal+= "\n";
		setGlobal+= "					stmt->execute(query);\n";
		setGlobal+= "\n";
		setGlobal+= "			} else {\n";
		setGlobal+= "				query\n";
		setGlobal+= "						= \"UPDATE \"\n";
		setGlobal+="								+ DAO::getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		setGlobal+= "										1,\n";
		setGlobal+="										DAO::getSqlQueriesObjectSingle[className.back()][i].find(\n";
		setGlobal+= "												\"/\") - 1);\n";
		setGlobal+= "				query\n";
		setGlobal+= "						= query + \" SET \"\n";
		setGlobal+="								+ DAO::getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		setGlobal+="										DAO::getSqlQueriesObjectSingle[className.back()][i].find(\n";
		setGlobal+="												\"/\") + 1) + \"=\" + data[\"name\"];\n";
		setGlobal+= "				query\n";
		setGlobal+= "						= query + \" WHERE _NAME='\"\n";
		setGlobal+="								+ data[DAO::getSqlQueriesObjectSingle[className.back()][i].substr(\n";
		setGlobal+="										DAO::getSqlQueriesObjectSingle[className.back()][i].find(\n";
		setGlobal+= "												\"/\") + 1)] + \"'\";\n";
		setGlobal+= "					stmt->execute(query);\n";
		setGlobal+= "			}\n";
		setGlobal+= "			delete (stmt);\n";
		setGlobal+= "		} catch (sql::SQLException &e) {/*\n";
		setGlobal+="			std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		setGlobal+="			std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		setGlobal+= "					<< std::endl;\n";
		setGlobal+= "			std::cout << \"# ERR: \" << e.what();\n";
		setGlobal+="			std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		setGlobal+="			std::cout << \", SQLState: \" << e.getSQLState() << \" )\" << std::endl;\n";
		setGlobal+= "		*/}\n";
		setGlobal+= "	}\n";
		setGlobal+= "\n";
		setGlobal+= "	// OBJECT MULTI\n";
		setGlobal+= "\n";
		setGlobal+= "	for (int unsigned i = 0; i\n";
		setGlobal+="			< DAO::getSqlQueriesObjectMulti[className.back()].size(); i++) {\n";
		setGlobal+= "		try {\n";
		setGlobal+= "			sql::Statement *stmt;\n";
		setGlobal+="			stmt = connection->getCon()->createStatement();\n";
		setGlobal+= "			std::string query;\n";
		setGlobal+= "			query = \"DELETE FROM \";\n";
		setGlobal+= "			query\n";
		setGlobal+= "					= query\n";
		setGlobal+="							+ DAO::getSqlQueriesObjectMulti[className.back()][i].substr(\n";
		setGlobal+="									DAO::getSqlQueriesObjectMulti[className.back()][i].find(\n";
		setGlobal+= "											\"/\") + 1);\n";
		setGlobal+="			query = query + \" WHERE \" + this->className.back() + \"ID=\"\n";
		setGlobal+="					+ data[this->className.back() + \"ID\"];\n";
		setGlobal+= "			stmt->execute(query);\n";
		setGlobal+= "			std::vector<std::string>\n";
		setGlobal+= "					multi =\n";
		setGlobal+= "							Explode(\n";
		setGlobal+="									data[DAO::getSqlQueriesObjectMulti[className.back()][i].substr(\n";
		setGlobal+="											DAO::getSqlQueriesObjectMulti[className.back()][i].find(\n";
		setGlobal+= "													\"/\") + 1)], ' ');\n";
		setGlobal+="			if(!data[DAO::getSqlQueriesObjectMulti[className.back()][i].substr(\n";
		setGlobal+="					DAO::getSqlQueriesObjectMulti[className.back()][i].find(\n";
		setGlobal+= "							\"/\") + 1)].empty())\n";
		setGlobal+="			for (int unsigned i = 0; i < multi.size(); i++) {\n";
		setGlobal+= "				query\n";
		setGlobal+= "						= \"INSERT INTO \"\n";
		setGlobal+="								+ DAO::getSqlQueriesObjectMulti[className.back()][i].substr(\n";
		setGlobal+="										DAO::getSqlQueriesObjectMulti[className.back()][i].find(\n";
		setGlobal+= "												\"/\") + 1);\n";
		setGlobal+= "				query\n";
		setGlobal+="						= query + \" (\" + this->className.back() + \"ID\" + \",\"\n";
		setGlobal+="								+ DAO::getSqlQueriesObjectMulti[className.back()][i].substr(\n";
		setGlobal+= "										0,\n";
		setGlobal+="										DAO::getSqlQueriesObjectMulti[className.back()][i].find(\n";
		setGlobal+= "												\"/\")) + \"ID)\";\n";
		setGlobal+= "\n";
		setGlobal+= "				query = query + \" VALUES(\"\n";
		setGlobal+="						+ data[this->className.back() + \"ID\"] + \", \" + multi[i]\n";
		setGlobal+= "						+ \")\";\n";
		setGlobal+= "				stmt->execute(query);\n";
		setGlobal+= "			}\n";
		setGlobal+= "			delete (stmt);\n";
		setGlobal+= "\n";
		setGlobal+= "		} catch (sql::SQLException &e) {/*\n";
		setGlobal+="			std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		setGlobal+="			std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		setGlobal+= "					<< std::endl;\n";
		setGlobal+= "			std::cout << \"# ERR: \" << e.what();\n";
		setGlobal+="			std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		setGlobal+="			std::cout << \", SQLState: \" << e.getSQLState() << \" )\" << std::endl;\n";
		setGlobal+= "		*/}\n";
		setGlobal+= "	}\n";
		setGlobal+= "		}\n";
		
		String insert="";
		insert+="void DAO::insert(std::map<std::string, std::string> data) {\n";
		insert+="bool execute=false;\n";
		insert+="sql::Statement *stmt;\n";
		insert+="stmt = connection->getCon()->createStatement();\n";
		insert+="std::string query = \"INSERT INTO \" + this->className.back() +\"(\";\n";
		insert+="std::string queryEnd = \"VALUES(\";\n";
		insert+="for (std::map<std::string, std::string>::iterator it = data.begin();\n";
		insert+="it != data.end(); it++) {\n";
		insert+="if (toAdd(it->first)){\n";
		insert+="execute=true;\n";
		insert+="query = query + it->first + \", \";\n";
		insert+="queryEnd= queryEnd + it->second + \", \";\n";
		insert+="}\n";
		insert+="}\n";
		insert+="if(execute){\n";
		insert+="query = query.substr(0, query.length() - 2) + \") \"; //to delete the last ,\n";
		insert+="queryEnd = queryEnd.substr(0, queryEnd.length() - 2) + \") \"; //to delete the last ,\n";
		insert+="query = query + queryEnd;\n";
		insert+="stmt->execute(query);\n";
		insert+="delete (stmt);\n";
		insert+="}\n";
		insert+="}\n";
		
		String explode = "";
		explode+= "std::vector<std::string> DAO"
				+ "::Explode(const std::string & str, char separator )\n";
		explode+= "{\n";
		explode+= "   std::vector< std::string > result;\n";
		explode+= "   std::size_t pos1 = 0;\n";
		explode+= "   std::size_t pos2 = 0;\n";
		explode+= "   while ( pos2 != str.npos )\n";
		explode+= "   {\n";
		explode+= "      pos2 = str.find(separator, pos1);\n";
		explode+= "      if ( pos2 != str.npos )\n";
		explode+= "      {\n";
		explode+= "         if ( pos2 > pos1 )\n";
		explode = explode
				+ "            result.push_back( str.substr(pos1, pos2-pos1) );\n";
		explode+= "         pos1 = pos2+1;\n";
		explode+= "      }\n";
		explode+= "   }\n";
		explode = explode
				+ "   result.push_back( str.substr(pos1, str.size()-pos1) );\n";
		explode+= "   return result;\n";
		explode+= "}\n";
		
		String getAll="\n\n";
		getAll+="std::map<std::string, std::vector<std::string> > DAO::getAll(std::vector<\n";
		getAll+="		std::string> attributesList, std::string table) {\n";
		getAll+="	std::map<std::string, std::vector<std::string> > result;\n";
		getAll+="	try {\n";
		getAll+="		sql::ResultSetMetaData *res_meta;\n";
		getAll+="		sql::ResultSet *res;\n";
		getAll+="		sql::Statement *stmt;\n";
		getAll+="		std::string attributes = \"\";\n";
		getAll+="		for (int i = 0; i < (int) attributesList.size(); i++) {\n";
		getAll+="			attributes = attributes + \", \" + attributesList[i];\n";
		getAll+="		}\n";
		getAll+="		std::string query = \"SELECT \" + attributes.substr(2) + \" FROM \" + table;\n";
		getAll+="		stmt = connection->getCon()->createStatement();\n";
		getAll+="		res = stmt->executeQuery(query);\n";
		getAll+="		res_meta = res -> getMetaData();\n";
		getAll+="		while (res->next()) {\n";
		getAll+="			for (int i = 0; i < (int) res_meta -> getColumnCount(); ++i) {\n";
		getAll+="				std::vector<std::string> temp =\n";
		getAll+="						result[res_meta -> getColumnLabel(i + 1)];\n";
		getAll+="				temp.push_back(res->getString(i + 1));\n";
		getAll+="				result[res_meta -> getColumnLabel(i + 1)] = temp;\n";
		getAll+="			}\n";
		getAll+="		}\n";
		getAll+="		delete (res);\n";
		getAll+="		delete (stmt);\n";
		getAll+="\n";
		getAll+="	} catch (sql::SQLException &e) {/*\n";
		getAll+="		std::cout << \"# ERR: SQLException in \" << __FILE__;\n";
		getAll+="		std::cout << \"(\" << __FUNCTION__ << \") on line \" << __LINE__\n";
		getAll+="				<< std::endl;\n";
		getAll+="		std::cout << \"# ERR: \" << e.what();\n";
		getAll+="		std::cout << \" (MySQL error code: \" << e.getErrorCode();\n";
		getAll+="		std::cout << \", SQLState: \" << e.getSQLState() << \" )\" << std::endl;\n";
		getAll+="	*/}\n";
		getAll+="	return result;\n";
		getAll+="}\n";
		getAll+="\n";

		String check = "bool DAO::toAdd(std::string s) {\n";
		check+="	for (int unsigned i=0;i<DAO::getSqlQueriesObjectSingle[className.back()].size(); i++) {\n";
		check+="		std::string key = DAO::getSqlQueriesObjectSingle[className.back()][i];\n";
		check+="if (std::equal(key.begin() + key.size() - s.size(), key.end(),s.begin()) && key.substr(0, 1) == \"-\")\n";
		check+="	return false;\n";
		check+="}\n";
		check+="		return true;\n";
		check+="}\n";



		
		String destructor = "DAO::~DAO() {\n\n}";

		return result + destructor + getGlobal + setGlobal + insert + explode + check + getAll;
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
