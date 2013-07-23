

import java.io.File;
import java.util.ArrayList;

import ClassesCPP.Connection;
import ClassesCPP.DaoGenerator;
import ClassesCPP.Types;
import Ontology.Ontology;

public class CodeGenerator {
	private String cppPath;
	public CodeGenerator(String cppPath)
	{
		this.cppPath = cppPath;
	}
	/**
	 * \brief Generate the DAO files \param o Our ontology. \param url Host of
	 * your DB. \param user User name in the DB. \param pass Password of the
	 * user in the DB. \param nameDb DB Schema.
	 */
	public void generateDao(Ontology o, String url, String user, String pass,
			String nameDb) {
		DaoGenerator dao = new DaoGenerator(o.getTables().getTables(),
				o.getSuperClassesClean(), o.getClassesClean(), o.getOp()
						.getObjectPropertyInverse(), o.getOp()
						.getObjectSingleValued(), o.getOp()
						.getObjectPropertyRanges(), o.getDp()
						.getDataSingleValued());
		ArrayList<String> attributes = new ArrayList<String>();
		attributes.add("className");
		attributes.add("connection");
		ArrayList<String> unit = new ArrayList<String>();
		unit.add("std::vector<std::string>");
		unit.add("Connection*");
		dao.writeHeader(
				dao.generateHeader(attributes, unit, url, user, pass, nameDb),
				cppPath + File.separator);
		dao.writeClass(
				dao.generateCpp(attributes, unit, url, user, pass, nameDb),
				cppPath + File.separator);
	}

	/**
	 * \brief Generate the C++ Connection files
	 */
	public void generateConnection() {
		new Connection(cppPath + File.separator);
	}
	/**
	 * \brief Generate the C++ classes \details Fill the attributes and unit
	 * collections based on the info from our ontology. \param o Our ontology.
	 */
	@SuppressWarnings("unchecked")
	public void generateClasses(Ontology o) {
		for (int i = 0; i < o.getClassesClean().size(); i++) {
			Types typesGen = new Types(o.getClassesClean().get(i),o.getSuperClassesClean());
			ArrayList<String> attributes = new ArrayList<String>();
			ArrayList<String> unit = new ArrayList<String>();
			for (int j = 0; j < o.getDp().getDataPropertiesClean().size(); j++) {
				if (o.getDp().getDataPropertiesClean().get(j).get(0)
						.equals(o.getClassesClean().get(i))) {
					attributes = (ArrayList<String>) o.getDp()
							.getDataPropertiesClean().get(j).clone();
					attributes.remove(0);
					break;
				}
			}
			// Add the data Properties
			for (int k = 0; k < attributes.size(); k++) {
				for (int j = 0; j < o.getDp().getDataPropertyRanges().size(); j++) {
					if (o.getDp().getDataPropertyRanges().get(j).get(0)
							.equals(attributes.get(k))) {
						if (o.getDp().getDataSingleValued()
								.containsKey(attributes.get(k)))
							if (o.getDp().getDataSingleValued()
									.get(attributes.get(k)).equals("false"))
								unit.add("std::vector<"
										+ typesGen
												.getUnit(o
														.getTables()
														.unit(o.getDp()
																.getDataPropertyRanges()
																.get(j).get(1)))
										+ ">");
							else
								unit.add(typesGen.getUnit(o.getTables().unit(
										o.getDp().getDataPropertyRanges()
												.get(j).get(1))));
					}
				}
			}
			attributes.add("name");
			unit.add("std::string");
			attributes.add(o.getClassesClean().get(i) + "ID");
			unit.add("int");
			attributes.add("dao");
			unit.add("DAO*");

			// Add the Object Properties
			ArrayList<String> properties = o.getTables().getTables()
					.get(o.getClassesClean().get(i));
			String prop;
			for (int p = 0; p < properties.size(); p++) {
				if (properties.get(p).contains("/")) {
					prop = properties.get(p).substring(0,
							properties.get(p).indexOf("/"));

				} else {
					prop = properties.get(p);
				}
				boolean contains = false;
				for (ArrayList<String> oproperties : o.getOp()
						.getObjectPropertiesClean()) {
					if (oproperties.contains(prop)
							&& oproperties.indexOf(prop) > 0) {
						contains = true;
						for (int s = 0; s < o.getOp().getObjectPropertyRanges()
								.get(prop).size(); s++) {
							if (!attributes.contains(prop)) {
								attributes.add(prop);
								if (o.getOp().getObjectSingleValued().get(prop)
										.equals("false"))
									unit.add("std::vector<"
											+ o.getOp()
													.getObjectPropertyRanges()
													.get(prop).get(s) + "*>");
								else

									unit.add(o.getOp()
											.getObjectPropertyRanges()
											.get(prop).get(s)
											+ "*");
							}
						}
					}

				}

				// Add the remote Object Properties (to have the property for
				// both objects : range and domain)
				if (properties.get(p).contains("/")
						&& !contains
						&& !properties.get(p).contains("Value/")
						&& !attributes.contains(properties.get(p).substring(
								properties.get(p).indexOf("/") + 1,
								properties.get(p).length()))) {
					attributes.add(properties.get(p).substring(
							properties.get(p).indexOf("/") + 1,
							properties.get(p).length()));
					if (!o.getOp()
							.getObjectPropertyInverse()
							.containsKey(
									properties.get(p).substring(
											properties.get(p).indexOf("/") + 1,
											properties.get(p).length())))
						unit.add("std::vector<"
								+ properties.get(p).substring(0,
										properties.get(p).indexOf("/")) + "*>");

					else if (o
							.getOp()
							.getObjectSingleValued()
							.get(o.getOp()
									.getObjectPropertyInverse()
									.get(properties.get(p).substring(
											properties.get(p).indexOf("/") + 1,
											properties.get(p).length())))
							.equals("false")) {
						unit.add("std::vector<"
								+ properties.get(p).substring(0,
										properties.get(p).indexOf("/")) + "*>");
					}

					else {
						unit.add(properties.get(p).substring(0,
								properties.get(p).indexOf("/"))
								+ "*");
					}
				}

			}

			// Add the Object Properties (to have the property for both
			// objects : range and domain)
			for (int ind = 0; ind < o.getClassesClean().size(); ind++) {
				ArrayList<String> localProperties = (ArrayList<String>) o
						.getTables().getTables()
						.get(o.getClassesClean().get(ind)).clone();
				for (int indLp = 0; indLp < localProperties.size(); indLp++) {
					if (localProperties.get(indLp).contains("/")) {
						localProperties.set(
								indLp,
								localProperties.get(indLp)
										.substring(
												0,
												localProperties.get(indLp)
														.indexOf("/")));

					}
					if (o.getOp().getObjectPropertyRanges()
							.containsKey(localProperties.get(indLp))) {
						for (int a = 0; a < o.getOp().getObjectPropertyRanges()
								.get(localProperties.get(indLp)).size(); a++) {
							if (o.getOp().getObjectPropertyRanges()
									.get(localProperties.get(indLp)).get(a)
									.equals(o.getClassesClean().get(i))
									&& !attributes.contains(localProperties
											.get(indLp))) {
								attributes.add(localProperties.get(indLp));
								if (!o.getOp()
										.getObjectPropertyInverse()
										.containsKey(localProperties.get(indLp)))
									unit.add("std::vector<"
											+ o.getClassesClean().get(ind)
											+ "*>");

								else if (o
										.getOp()
										.getObjectSingleValued()
										.get(o.getOp()
												.getObjectPropertyInverse()
												.get(localProperties.get(indLp)))
										.equals("false"))
									unit.add("std::vector<"
											+ o.getClassesClean().get(ind)
											+ "*>");
								else

									unit.add(o.getClassesClean().get(ind) + "*");

							}
						}
					}
				}
			}

			// Write the header and class files
			typesGen.writeHeader(typesGen.generateHeader(o.getClassesClean()
					.get(i),
					o.getSuperClassesClean().get(o.getClassesClean().get(i)),
					attributes, unit), cppPath + File.separator);
			typesGen.writeClass(typesGen.generateCpp(
					o.getClassesClean().get(i),
					o.getSuperClassesClean().get(o.getClassesClean().get(i)),
					attributes, unit), cppPath + File.separator);

		}
	}
}
