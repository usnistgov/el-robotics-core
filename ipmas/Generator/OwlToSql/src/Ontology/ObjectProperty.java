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
 * \file      ObjectProperty.java
 * \author    Anthony Pietromartire \a pietromartire.anthony\@nist.gov
 * \version   1.0
 * \date      29 June 2012
 * \brief     Class for the object properties.
 *
 */

/**
 * \class 	Ontology.ObjectProperty
 * \brief     Class for the object properties.
 * \details   This class is used to manipulate the object properties contained in the ontology  
 */

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
	/**
	 * \brief Separator between URL and the class' name in the ontology.
	 */
	private static final char SEPARATOR = '#';
	/**
	 * \brief List of classes in the ontology.
	 */
	private ArrayList<OWLClass> classes;
	/**
	 * \brief List of classes without the url before their name.
	 */
	private ArrayList<String> classesClean;
	/**
	 * \brief Our ontology.
	 */
	private OWLOntology ontology;
	/**
	 * \brief List of the object properties in the ontology. \details <<Classe1,
	 * ObjectPropertyName1,ObjectPropertyName2>
	 */
	private HashMap<OWLClassExpression, ArrayList<OWLObjectProperty>> objectProperties;
	/**
	 * \brief List of the object properties without the URL before their name in
	 * the ontology. \details <<Classe1,
	 * ObjectPropertyName1,ObjectPropertyName2>
	 */
	private ArrayList<ArrayList<String>> objectPropertiesClean;
	/**
	 * \brief Map - Used to know if a object property is single or multi valued
	 * \details ObjectPropertyName => true or false
	 */
	private HashMap<String, String> objectSingleValued;
	/**
	 * \brief Map - Used to know if an object property is required or optional
	 * valued \details ObjectPropertyName => true or false
	 */
	private HashMap<String, String> objectRequired;
	/**
	 * \brief List of the ranges for a given object property \details
	 * <<ObjectPropertyName1,Range1,Range2...,<ObjectName2,Range1,Range2...>>
	 */
	private HashMap<String, ArrayList<String>> objectPropertyRanges;
	/**
	 * \brief List of the inverse properties for a given one. \details property
	 * => inverse
	 */
	private HashMap<String, String> objectPropertyInverse;

	/**
	 * \brief Constructor \details Constructor of the ObjectProperty class.
	 * \param c List of the classes. \param cc List of the classes cleaned.
	 * \param ont Our ontology.
	 */
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
	}

	/**
	 * \brief List all the inverse properties for each object properties.
	 * \details Fill the objectPropertyInverse map
	 */
	public void addInverse() {
		for (int i = 0; i < classes.size(); i++) {
			if (objectProperties.containsKey(classes.get(i))) {
				for (int j = 0; j < objectProperties.get(classes.get(i)).size(); j++) {
					if (objectProperties.get(classes.get(i)).get(j)
							.getInverses(ontology).size() > 1) {
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
										objectProperties.get(classes.get(i))
												.get(j).getInverses(ontology)
												.toArray()[0].toString()
												.length()));
					}
				}
			}
		}
	}

	/**
	 * \brief List all the object properties for each class. \details Fill the
	 * objectProperties map
	 */
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

	/**
	 * \brief Delete the url before the name of the property.
	 */
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

	/**
	 * \brief Precise which properties are single valued. \details Fill the
	 * objectSingleValued map.
	 */
	public void singleValuedObjectProperties() {
		for (Entry<OWLClassExpression, ArrayList<OWLObjectProperty>> currentEntry : objectProperties
				.entrySet()) {
			ArrayList<OWLObjectProperty> value = currentEntry.getValue();
			for (OWLObjectProperty d : value) {
				if (d.isFunctional(ontology) /*
											 * ||
											 * d.isInverseFunctional(ontology)
											 */)
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

	/**
	 * \brief Precise which properties are required. \details Fill the
	 * objectRequired map.
	 */
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

	/**
	 * \brief List all the ranges for each object properties. \details Fill the
	 * objectPropertyRanges list
	 */
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

	/**
	 * \brief Simple getter. \return objectProperties
	 */
	public HashMap<OWLClassExpression, ArrayList<OWLObjectProperty>> getObjectProperties() {
		return objectProperties;
	}

	/**
	 * \brief Simple setter. \param objectProperties
	 */
	public void setObjectProperties(
			HashMap<OWLClassExpression, ArrayList<OWLObjectProperty>> objectProperties) {
		this.objectProperties = objectProperties;
	}

	/**
	 * \brief Simple getter. \return objectPropertiesClean
	 */
	public ArrayList<ArrayList<String>> getObjectPropertiesClean() {
		return objectPropertiesClean;
	}

	/**
	 * \brief Simple setter. \param objectPropertiesClean
	 */
	public void setObjectPropertiesClean(
			ArrayList<ArrayList<String>> objectPropertiesClean) {
		this.objectPropertiesClean = objectPropertiesClean;
	}

	/**
	 * \brief Simple getter. \return objectSingleValued
	 */
	public HashMap<String, String> getObjectSingleValued() {
		return objectSingleValued;
	}

	/**
	 * \brief Simple setter. \param objectSingleValued
	 */
	public void setObjectSingleValued(HashMap<String, String> objectSingleValued) {
		this.objectSingleValued = objectSingleValued;
	}

	/**
	 * \brief Simple getter. \return objectRequired
	 */
	public HashMap<String, String> getObjectRequired() {
		return objectRequired;
	}

	/**
	 * \brief Simple setter. \param objectRequired
	 */
	public void setObjectRequired(HashMap<String, String> objectRequired) {
		this.objectRequired = objectRequired;
	}

	/**
	 * \brief Simple getter. \return classes
	 */
	public ArrayList<OWLClass> getClasses() {
		return classes;
	}

	/**
	 * \brief Simple setter. \param classes
	 */
	public void setClasses(ArrayList<OWLClass> classes) {
		this.classes = classes;
	}

	/**
	 * \brief Simple getter. \return classesClean
	 */
	public ArrayList<String> getClassesClean() {
		return classesClean;
	}

	/**
	 * \brief Simple setter. \param classesClean
	 */
	public void setClassesClean(ArrayList<String> classesClean) {
		this.classesClean = classesClean;
	}

	/**
	 * \brief Simple getter. \return ontology
	 */
	public OWLOntology getOntology() {
		return ontology;
	}

	/**
	 * \brief Simple setter. \param ontology
	 */
	public void setOntology(OWLOntology ontology) {
		this.ontology = ontology;
	}

	/**
	 * \brief Simple getter. \return SEPARATOR
	 */
	public static char getSeparator() {
		return SEPARATOR;
	}

	/**
	 * \brief Simple getter. \return objectPropertyRanges
	 */
	public HashMap<String, ArrayList<String>> getObjectPropertyRanges() {
		return objectPropertyRanges;
	}

	/**
	 * \brief Simple setter. \param objectPropertyRanges
	 */
	public void setObjectPropertyRanges(
			HashMap<String, ArrayList<String>> objectPropertyRanges) {
		this.objectPropertyRanges = objectPropertyRanges;
	}

	/**
	 * \brief Simple getter. \return objectPropertyInverse
	 */
	public HashMap<String, String> getObjectPropertyInverse() {
		return objectPropertyInverse;
	}

	/**
	 * \brief Simple setter. \param objectPropertyInverse
	 */
	public void setObjectPropertyInverse(
			HashMap<String, String> objectPropertyInverse) {
		this.objectPropertyInverse = objectPropertyInverse;
	}
}
