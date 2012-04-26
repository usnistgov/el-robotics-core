package Ontology;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map.Entry;

import org.semanticweb.owlapi.model.OWLClass;
import org.semanticweb.owlapi.model.OWLClassExpression;
import org.semanticweb.owlapi.model.OWLObjectExactCardinality;
import org.semanticweb.owlapi.model.OWLObjectHasValue;
import org.semanticweb.owlapi.model.OWLObjectMaxCardinality;
import org.semanticweb.owlapi.model.OWLObjectMinCardinality;
import org.semanticweb.owlapi.model.OWLObjectProperty;
import org.semanticweb.owlapi.model.OWLObjectSomeValuesFrom;
import org.semanticweb.owlapi.model.OWLOntology;
import org.semanticweb.owlapi.util.OWLOntologyWalker;
import org.semanticweb.owlapi.util.OWLOntologyWalkerVisitor;

public class ObjectProperty {

	static final char SEPARATOR = '#';
	private ArrayList<OWLClass> classes;
	private ArrayList<String> classesClean; // list of classes
	private OWLOntology ontology;
	private HashMap<OWLClassExpression, ArrayList<OWLObjectProperty>> objectProperties;
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
	private HashMap<String, String> objectPropertyInverse; // property =>
															// inverse

	public ObjectProperty(ArrayList<OWLClass> c, ArrayList<String> cc,
			OWLOntology ont) {
		objectPropertiesClean = new ArrayList<ArrayList<String>>();
		objectProperties = new HashMap<OWLClassExpression, ArrayList<OWLObjectProperty>>();
		objectSingleValued = new HashMap<String, String>();
		objectRequired = new HashMap<String, String>();
		objectPropertyRanges = new HashMap<String, ArrayList<String>>();
		classes = c;
		classesClean = cc;
		ontology = ont;
		objectPropertyInverse = new HashMap<String, String>();
		addObjectProperties(); // add the object properties in the corresponding
								// list
		cleanObjectProperties(); // delete the url before the name of the
									// property
		singleValuedObjectProperties(); // precise which properties are
										// singleValued - fill the
										// objectSingleValued Map
		requiredValueObjectProperties(); // precise which properties are
											// required - fill the
											// objectRequired Map
		addInverse(); // fill up the objectPropertyInverse list
		addTypes(); // fill up the objectPropertyRanges list - add the ranges
		System.out.println();
	}

	// fill up the objectPropertyInverse list
	private void addInverse() {
		for (int i = 0; i < classes.size(); i++) {
			if (objectProperties.containsKey(classes.get(i))) {
				for (int j = 0; j < objectProperties.get(classes.get(i)).size(); j++) {
					if (!objectProperties.get(classes.get(i)).get(j)
							.getInverses(ontology).toString().equals("[]")) {
						objectPropertyInverse
								.put(objectProperties
										.get(classes.get(i))
										.get(j)
										.toString()
										.substring(
												objectProperties
														.get(classes.get(i))
														.get(j).toString()
														.indexOf(SEPARATOR) + 1,
												objectProperties
														.get(classes.get(i))
														.get(j).toString()
														.length() - 1),
										objectProperties
												.get(classes.get(i))
												.get(j)
												.getInverses(ontology)
												.toString()
												.substring(
														objectProperties
																.get(classes
																		.get(i))
																.get(j)
																.getInverses(
																		ontology)
																.toString()
																.indexOf(
																		SEPARATOR) + 1,
														objectProperties
																.get(classes
																		.get(i))
																.get(j)
																.getInverses(
																		ontology)
																.toString()
																.length() - 2));
				} 
//						else {
//						objectPropertyInverse
//								.put(objectProperties
//										.get(classes.get(i))
//										.get(j)
//										.toString()
//										.substring(
//												objectProperties
//														.get(classes.get(i))
//														.get(j).toString()
//														.indexOf(SEPARATOR) + 1,
//												objectProperties
//														.get(classes.get(i))
//														.get(j).toString()
//														.length() - 1),
//										"InverseOf("
//												+ objectProperties
//														.get(classes.get(i))
//														.get(j)
//														.toString()
//														.substring(
//																objectProperties
//																		.get(classes
//																				.get(i))
//																		.get(j)
//																		.toString()
//																		.indexOf(
//																				SEPARATOR) + 1,
//																objectProperties
//																		.get(classes
//																				.get(i))
//																		.get(j)
//																		.toString()
//																		.length() - 1)
//												+ ")");
//
//					}
				}
			}
		}
	}

	// add the object properties in the corresponding list
	public void addObjectProperties() {
		ArrayList<OWLObjectProperty> l = new ArrayList<OWLObjectProperty>(
				ontology.getObjectPropertiesInSignature(true));
		ArrayList<OWLObjectProperty> thing = new ArrayList<OWLObjectProperty>();
		for (int i = 0; i < l.size(); i++) {
			String s = l.get(i).getDomains(ontology).toString();
			if (s.equals("[]") || s.equals("[owl:Thing]"))
				thing.add(l.get(i));
			for (int j = 0; j < l.get(i).getDomains(ontology).size(); j++) {
				if (!l.get(i).getDomains(ontology).toString()
						.equals("[owl:Thing]")) {
					if (objectProperties
							.containsKey(new ArrayList<OWLClassExpression>(l
									.get(i).getDomains(ontology)).get(j))) {
						objectProperties.get(
								new ArrayList<OWLClassExpression>(l.get(i)
										.getDomains(ontology)).get(j)).add(
								l.get(i));
					} else {
						ArrayList<OWLObjectProperty> temp = new ArrayList<OWLObjectProperty>();
						temp.add(l.get(i));
						objectProperties.put(new ArrayList<OWLClassExpression>(
								l.get(i).getDomains(ontology)).get(j), temp);
					}
				}
			}
		}
		for (Entry<OWLClassExpression, ArrayList<OWLObjectProperty>> entry : objectProperties
				.entrySet()) {
			for (int i = 0; i < thing.size(); i++)
				entry.getValue().add(thing.get(i));
		}
	}

	// delete the url before the name of the property
	public void cleanObjectProperties() {
		for (int i = 0; i < classes.size(); i++) {
			ArrayList<String> temp = new ArrayList<String>();
			if (objectProperties.containsKey(classes.get(i))) {
				temp.add(classesClean.get(i).toString());
				for (int j = 0; j < objectProperties.get(classes.get(i)).size(); j++) {
					temp.add(objectProperties
							.get(classes.get(i))
							.get(j)
							.toString()
							.substring(
									objectProperties.get(classes.get(i)).get(j)
											.toString().indexOf(SEPARATOR) + 1,
									objectProperties.get(classes.get(i)).get(j)
											.toString().length() - 1));
				}
				objectPropertiesClean.add(temp);
			}
		}
		System.out.println();
	}

	// precise which properties are singleValued - fill the objectSingleValued
	// Map
	public void singleValuedObjectProperties() {
		for (Entry<OWLClassExpression, ArrayList<OWLObjectProperty>> currentEntry : objectProperties
				.entrySet()) {
			ArrayList<OWLObjectProperty> value = currentEntry.getValue();
			for (OWLObjectProperty d : value) {
				if (d.isFunctional(ontology) || d.isInverseFunctional(ontology))
					objectSingleValued.put(
							d.toString().substring(
									d.toString().indexOf(SEPARATOR) + 1,
									d.toString().length() - 1), "true");
				else
					objectSingleValued.put(
							d.toString().substring(
									d.toString().indexOf(SEPARATOR) + 1,
									d.toString().length() - 1), "false");
			}
		}
		OWLOntologyWalker walker = new OWLOntologyWalker(
				Collections.singleton(ontology));
		OWLOntologyWalkerVisitor<Object> visitor = new OWLOntologyWalkerVisitor<Object>(
				walker) {

			public Object visit(OWLObjectExactCardinality desc) {
				if (desc.getCardinality() == 1) {
					String nameClean = desc
							.getObjectPropertiesInSignature()
							.toString()
							.substring(
									desc.getObjectPropertiesInSignature()
											.toString().toString()
											.indexOf(SEPARATOR) + 1,
									desc.getObjectPropertiesInSignature()
											.toString().toString().length() - 1);
					objectSingleValued.put(nameClean, "true");
				}
				return null;
			}
		};

		OWLOntologyWalkerVisitor<Object> visitor2 = new OWLOntologyWalkerVisitor<Object>(
				walker) {

			public Object visit(OWLObjectMaxCardinality desc) {
				if (desc.getCardinality() == 1) {
					String nameClean = desc
							.getObjectPropertiesInSignature()
							.toString()
							.substring(
									desc.getObjectPropertiesInSignature()
											.toString().toString()
											.indexOf(SEPARATOR) + 1,
									desc.getObjectPropertiesInSignature()
											.toString().toString().length() - 1);
					objectSingleValued.put(nameClean, "true");
				}
				return null;
			}
		};
		walker.walkStructure(visitor);
		walker.walkStructure(visitor2);
	}

	// precise which properties are requiredValued - fill the
	// objectRequiredValued Map
	public void requiredValueObjectProperties() {
		for (Entry<OWLClassExpression, ArrayList<OWLObjectProperty>> currentEntry : objectProperties
				.entrySet()) {
			ArrayList<OWLObjectProperty> value = currentEntry.getValue();
			for (OWLObjectProperty d : value) {
				String nameClean = d.toString().substring(
						d.toString().indexOf(SEPARATOR) + 1,
						d.toString().length() - 1);
				objectRequired.put(nameClean, "false");
			}
		}
		OWLOntologyWalker walker = new OWLOntologyWalker(
				Collections.singleton(ontology));
		OWLOntologyWalkerVisitor<Object> visitor = new OWLOntologyWalkerVisitor<Object>(
				walker) {
			public Object visit(OWLObjectExactCardinality desc) {
				if (desc.getCardinality() >= 0) {
					String[] nameClean = desc.getObjectPropertiesInSignature()
							.toString().split(String.valueOf(","));
					for (int i = 0; i < nameClean.length; i++) {
						objectRequired.put(nameClean[i].substring(
								nameClean[i].indexOf(SEPARATOR) + 1,
								nameClean[i].length() - 2), "true");
					}

				}
				return null;
			}
		};
		OWLOntologyWalkerVisitor<Object> visitor2 = new OWLOntologyWalkerVisitor<Object>(
				walker) {

			public Object visit(OWLObjectMinCardinality desc) {

				if (desc.getCardinality() >= 0) {
					String[] nameClean = desc.getObjectPropertiesInSignature()
							.toString().split(String.valueOf(","));
					for (int i = 0; i < nameClean.length; i++) {
						objectRequired.put(nameClean[i].substring(
								nameClean[i].indexOf(SEPARATOR) + 1,
								nameClean[i].length() - 2), "true");
					}

				}
				return null;
			}
		};

		OWLOntologyWalkerVisitor<Object> visitor3 = new OWLOntologyWalkerVisitor<Object>(
				walker) {

			public Object visit(OWLObjectHasValue desc) {
				if (desc.getValue() != null) {
					String[] nameClean = desc.getObjectPropertiesInSignature()
							.toString().split(String.valueOf(","));
					for (int i = 0; i < nameClean.length; i++) {
						objectRequired.put(nameClean[i].substring(
								nameClean[i].indexOf(SEPARATOR) + 1,
								nameClean[i].length() - 2), "true");
					}

				}
				return null;
			}
		};

		OWLOntologyWalkerVisitor<Object> visitor4 = new OWLOntologyWalkerVisitor<Object>(
				walker) {

			public Object visit(OWLObjectSomeValuesFrom desc) {
				if (desc != null) {
					String[] nameClean = desc.getObjectPropertiesInSignature()
							.toString().split(String.valueOf(","));
					for (int i = 0; i < nameClean.length; i++) {
						objectRequired.put(nameClean[i].substring(
								nameClean[i].indexOf(SEPARATOR) + 1,
								nameClean[i].length() - 2), "true");
					}
					// .substring(
					// desc.getObjectPropertiesInSignature()
					// .toString().toString()
					// .indexOf(SEPARATOR) + 1,
					// desc.getObjectPropertiesInSignature()
					// .toString().toString().length() - 2);

				}
				return null;
			}
		};

		walker.walkStructure(visitor);
		walker.walkStructure(visitor2);
		walker.walkStructure(visitor3);
		walker.walkStructure(visitor4);
	}

	// fill up the objectPropertyRanges list - add the ranges
	public void addTypes() {
		for (Entry<OWLClassExpression, ArrayList<OWLObjectProperty>> currentEntry : objectProperties
				.entrySet()) {
			for (int i = 0; i < currentEntry.getValue().size(); i++) {
				objectPropertyRanges
						.put(currentEntry
								.getValue()
								.get(i)
								.toString()
								.substring(
										currentEntry.getValue().get(i)
												.toString().indexOf(SEPARATOR) + 1,
										currentEntry.getValue().get(i)
												.toString().length() - 1),
								new ArrayList<String>());
				ArrayList<OWLClassExpression> dpr = new ArrayList<OWLClassExpression>(
						currentEntry.getValue().get(i).getRanges(ontology));
				if (currentEntry.getValue().get(i).getRanges(ontology)
						.toString().equals("[owl:Thing]")
						|| currentEntry.getValue().get(i).getRanges(ontology)
								.toString().equals("[]")) {
					for (int q = 0; q < classes.size(); q++) {
						if (!classes.get(q).toString().equals("owl:Thing"))
							dpr.add(classes.get(q));
					}

				}
				ArrayList<String> temp = new ArrayList<String>();
				for (int n = 0; n < dpr.size(); n++) {
					if (!dpr.get(n).toString().equals("[]")
							|| !dpr.get(n).toString().equals("owl:Thing")) {
						if (dpr.get(n).toString().contains("ObjectUnionOf")) {
							String[] dprbis = dpr.get(n).toString().split(" ");
							for (int p = 0; p < dprbis.length; p++) {
								if (p == dprbis.length - 1) {
									temp.add(dprbis[p].substring(
											dprbis[p].indexOf(SEPARATOR) + 1,
											dprbis[p].length() - 2));
								} else {
									temp.add(dprbis[p].substring(
											dprbis[p].indexOf(SEPARATOR) + 1,
											dprbis[p].length() - 1));
								}
							}
						} else {
							temp.add(dpr
									.get(n)
									.toString()
									.substring(
											dpr.get(n).toString()
													.indexOf(SEPARATOR) + 1,
											dpr.get(n).toString().length() - 1));
						}

					}
				}
				objectPropertyRanges
						.put(currentEntry
								.getValue()
								.get(i)
								.toString()
								.substring(
										currentEntry.getValue().get(i)
												.toString().indexOf(SEPARATOR) + 1,
										currentEntry.getValue().get(i)
												.toString().length() - 1), temp);
			}
		}
	}

	// Getter and Setter
	public HashMap<OWLClassExpression, ArrayList<OWLObjectProperty>> getObjectProperties() {
		return objectProperties;
	}

	public void setObjectProperties(
			HashMap<OWLClassExpression, ArrayList<OWLObjectProperty>> objectProperties) {
		this.objectProperties = objectProperties;
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

	public ArrayList<OWLClass> getClasses() {
		return classes;
	}

	public void setClasses(ArrayList<OWLClass> classes) {
		this.classes = classes;
	}

	public ArrayList<String> getClassesClean() {
		return classesClean;
	}

	public void setClassesClean(ArrayList<String> classesClean) {
		this.classesClean = classesClean;
	}

	public OWLOntology getOntology() {
		return ontology;
	}

	public void setOntology(OWLOntology ontology) {
		this.ontology = ontology;
	}

	public static char getSeparator() {
		return SEPARATOR;
	}

	public HashMap<String, ArrayList<String>> getObjectPropertyRanges() {
		return objectPropertyRanges;
	}

	public void setObjectPropertyRanges(
			HashMap<String, ArrayList<String>> objectPropertyRanges) {
		this.objectPropertyRanges = objectPropertyRanges;
	}

	public HashMap<String, String> getObjectPropertyInverse() {
		return objectPropertyInverse;
	}

	public void setObjectPropertyInverse(
			HashMap<String, String> objectPropertyInverse) {
		this.objectPropertyInverse = objectPropertyInverse;
	}
}
