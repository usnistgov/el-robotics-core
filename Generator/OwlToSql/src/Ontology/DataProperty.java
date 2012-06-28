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

package Ontology;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map.Entry;

import org.semanticweb.owlapi.model.OWLClass;
import org.semanticweb.owlapi.model.OWLClassExpression;
import org.semanticweb.owlapi.model.OWLDataExactCardinality;
import org.semanticweb.owlapi.model.OWLDataHasValue;
import org.semanticweb.owlapi.model.OWLDataMaxCardinality;
import org.semanticweb.owlapi.model.OWLDataMinCardinality;
import org.semanticweb.owlapi.model.OWLDataProperty;
import org.semanticweb.owlapi.model.OWLDataRange;
import org.semanticweb.owlapi.model.OWLDataSomeValuesFrom;
import org.semanticweb.owlapi.model.OWLOntology;
import org.semanticweb.owlapi.util.OWLOntologyWalker;
import org.semanticweb.owlapi.util.OWLOntologyWalkerVisitor;

public class DataProperty {
	static final char SEPARATOR = '#';
	private ArrayList<OWLClass> classes;
	private ArrayList<String> classesClean; // list of classes
	private OWLOntology ontology;
	private HashMap<OWLClassExpression, ArrayList<OWLDataProperty>> dataProperties;
	private ArrayList<ArrayList<String>> dataPropertiesClean;
	// <<Classe1, DataPropertyName1,DataPropertyName2>,<Classe2,
	// DataPropertyName1,DataPropertyName2>>
	private HashMap<String, String> dataSingleValued; // dataPropertyName =>
														// true or false
	private HashMap<String, String> dataRequired; // dataPropertyName => true or
													// false
	private ArrayList<ArrayList<String>> dataPropertyRanges;

	// <<DataPropertyName1,Range1,Range2...,<DataPropertyName2,Range1,Range2...>>

	public DataProperty(ArrayList<OWLClass> c, ArrayList<String> cc,
			OWLOntology ont) {
		dataPropertiesClean = new ArrayList<ArrayList<String>>();
		dataProperties = new HashMap<OWLClassExpression, ArrayList<OWLDataProperty>>();
		dataSingleValued = new HashMap<String, String>();
		dataRequired = new HashMap<String, String>();
		dataPropertyRanges = new ArrayList<ArrayList<String>>();
		classes = c;
		classesClean = cc;
		ontology = ont;
		addDataProperties(); // add the data properties in the corresponding
								// list
		cleanDataProperties(); // delete the url before the name of the property
		singleValuedDataProperties(); // precise which properties are
										// singleValued - fill the
										// dataSingleValued Map
		requiredValueDataProperties(); // precise which properties are required
										// - fill the dataRequired Map
		addTypes(); // fill up the dataPropertyRanges list - add the ranges
	}

	// delete the url before the name of the property
	public void cleanDataProperties() {
		for (int i = 0; i < classes.size(); i++) {
			ArrayList<String> temp = new ArrayList<String>();
			temp.add(classesClean.get(i).toString());
			if (dataProperties.containsKey(classes.get(i))) {
				for (int j = 0; j < dataProperties.get(classes.get(i)).size(); j++) {
					temp.add(dataProperties
							.get(classes.get(i))
							.get(j)
							.toString()
							.substring(
									dataProperties.get(classes.get(i)).get(j)
											.toString().indexOf(SEPARATOR) + 1,
									dataProperties.get(classes.get(i)).get(j)
											.toString().length() - 1));

				}
			}
			dataPropertiesClean.add(temp);
		}
	}

	// precise which properties are singleValued - fill the dataSingleValued Map
	public void singleValuedDataProperties() {
		for (Entry<OWLClassExpression, ArrayList<OWLDataProperty>> currentEntry : dataProperties
				.entrySet()) {
			ArrayList<OWLDataProperty> value = currentEntry.getValue();
			for (OWLDataProperty d : value) {
				if (d.isFunctional(ontology))
					dataSingleValued.put(
							d.toString().substring(
									d.toString().indexOf(SEPARATOR) + 1,
									d.toString().length() - 1), "true");
				else
					dataSingleValued.put(
							d.toString().substring(
									d.toString().indexOf(SEPARATOR) + 1,
									d.toString().length() - 1), "false");
			}
		}
		OWLOntologyWalker walker = new OWLOntologyWalker(
				Collections.singleton(ontology));
		OWLOntologyWalkerVisitor<Object> visitor = new OWLOntologyWalkerVisitor<Object>(
				walker) {

			public Object visit(OWLDataExactCardinality desc) {
				if (desc.getCardinality() == 1) {
					String nameClean = desc
							.getDataPropertiesInSignature()
							.toString()
							.substring(
									desc.getDataPropertiesInSignature()
											.toString().toString()
											.indexOf(SEPARATOR) + 1,
									desc.getDataPropertiesInSignature()
											.toString().toString().length() - 1);
					dataSingleValued.put(nameClean, "true");
				}
				return null;
			}
		};

		OWLOntologyWalkerVisitor<Object> visitor2 = new OWLOntologyWalkerVisitor<Object>(
				walker) {

			public Object visit(OWLDataMaxCardinality desc) {
				if (desc.getCardinality() == 1) {
					String nameClean = desc
							.getDataPropertiesInSignature()
							.toString()
							.substring(
									desc.getDataPropertiesInSignature()
											.toString().toString()
											.indexOf(SEPARATOR) + 1,
									desc.getDataPropertiesInSignature()
											.toString().toString().length() - 1);
					dataSingleValued.put(nameClean, "true");
				}
				return null;
			}
		};
		walker.walkStructure(visitor);
		walker.walkStructure(visitor2);
	}

	// precise which properties are required - fill the dataRequired Map
	public void requiredValueDataProperties() {
		for (Entry<OWLClassExpression, ArrayList<OWLDataProperty>> currentEntry : dataProperties
				.entrySet()) {
			ArrayList<OWLDataProperty> value = currentEntry.getValue();
			for (OWLDataProperty d : value) {
				String nameClean = d.toString().substring(
						d.toString().indexOf(SEPARATOR) + 1,
						d.toString().length() - 1);

				dataRequired.put(nameClean, "false");
			}
		}
		OWLOntologyWalker walker = new OWLOntologyWalker(
				Collections.singleton(ontology));
		OWLOntologyWalkerVisitor<Object> visitor = new OWLOntologyWalkerVisitor<Object>(
				walker) {
			public Object visit(OWLDataExactCardinality desc) {
				if (desc.getCardinality() > 0) {
					String nameClean = desc
							.getDataPropertiesInSignature()
							.toString()
							.substring(
									desc.getDataPropertiesInSignature()
											.toString().toString()
											.indexOf(SEPARATOR) + 1,
									desc.getDataPropertiesInSignature()
											.toString().toString().length() - 2);
					dataRequired.put(nameClean, "true");
				}
				return null;
			}
		};
		OWLOntologyWalkerVisitor<Object> visitor2 = new OWLOntologyWalkerVisitor<Object>(
				walker) {

			public Object visit(OWLDataMinCardinality desc) {

				if (desc.getCardinality() > 0) {
					String nameClean = desc
							.getDataPropertiesInSignature()
							.toString()
							.substring(
									desc.getDataPropertiesInSignature()
											.toString().toString()
											.indexOf(SEPARATOR) + 1,
									desc.getDataPropertiesInSignature()
											.toString().toString().length() - 2);
					dataRequired.put(nameClean, "true");
				}
				return null;
			}
		};

		OWLOntologyWalkerVisitor<Object> visitor3 = new OWLOntologyWalkerVisitor<Object>(
				walker) {

			public Object visit(OWLDataHasValue desc) {
				if (desc.getValue() != null) {
					String nameClean = desc
							.getDataPropertiesInSignature()
							.toString()
							.substring(
									desc.getDataPropertiesInSignature()
											.toString().toString()
											.indexOf(SEPARATOR) + 1,
									desc.getDataPropertiesInSignature()
											.toString().toString().length() - 2);
					dataRequired.put(nameClean, "true");
				}
				return null;
			}
		};

		OWLOntologyWalkerVisitor<Object> visitor4 = new OWLOntologyWalkerVisitor<Object>(
				walker) {

			public Object visit(OWLDataSomeValuesFrom desc) {
				if (desc != null) {
					String nameClean = desc
							.getDataPropertiesInSignature()
							.toString()
							.substring(
									desc.getDataPropertiesInSignature()
											.toString().toString()
											.indexOf(SEPARATOR) + 1,
									desc.getDataPropertiesInSignature()
											.toString().toString().length() - 2);
					dataRequired.put(nameClean, "true");
				}
				return null;
			}
		};

		walker.walkStructure(visitor);
		walker.walkStructure(visitor2);
		walker.walkStructure(visitor3);
		walker.walkStructure(visitor4);
	}

	// add the data properties in the corresponding list
	public void addDataProperties() {
		ArrayList<OWLDataProperty> l = new ArrayList<OWLDataProperty>(
				ontology.getDataPropertiesInSignature());
		ArrayList<OWLDataProperty> thing = new ArrayList<OWLDataProperty>();
		thing.clear();
		for (int i = 0; i < l.size(); i++) {
			String s = l.get(i).getDomains(ontology).toString();
			if (s.equals("[owl:Thing]") || s.equals("[]"))
				thing.add(l.get(i));
			for (int j = 0; j < l.get(i).getDomains(ontology).size(); j++) {
				if (dataProperties
						.containsKey(new ArrayList<OWLClassExpression>(l.get(i)
								.getDomains(ontology)).get(j))) {
					dataProperties.get(
							new ArrayList<OWLClassExpression>(l.get(i)
									.getDomains(ontology)).get(j))
							.add(l.get(i));
				} else {
					ArrayList<OWLDataProperty> temp = new ArrayList<OWLDataProperty>();
					temp.add(l.get(i));
					dataProperties.put(
							new ArrayList<OWLClassExpression>(l.get(i)
									.getDomains(ontology)).get(j), temp);
				}
			}
		}
		for (Entry<OWLClassExpression, ArrayList<OWLDataProperty>> entry : dataProperties
				.entrySet()) {
			for (int i = 0; i < thing.size(); i++)
				entry.getValue().add(thing.get(i));
		}
	}

	// fill up the dataPropertyRanges list - add the ranges
	public void addTypes() {
		for (Entry<OWLClassExpression, ArrayList<OWLDataProperty>> currentEntry : dataProperties
				.entrySet()) {
			for (int i = 0; i < currentEntry.getValue().size(); i++) {
				String dp = currentEntry
						.getValue()
						.get(i)
						.toString()
						.substring(
								currentEntry.getValue().get(i).toString()
										.indexOf(SEPARATOR) + 1,
								currentEntry.getValue().get(i).toString()
										.length() - 1);
				ArrayList<OWLDataRange> dpr = new ArrayList<OWLDataRange>(
						currentEntry.getValue().get(i).getRanges(ontology));
				String dprs = "";
				for (int j = 0; j < dpr.size(); j++) {
					if (j != 0)
						dprs = dprs + "," + dpr.get(j).toString();
					else
						dprs = dpr.get(j).toString();

				}
				ArrayList<String> temp = new ArrayList<String>();
				temp.add(dp);
				String[] dprss;
				if (dprs.startsWith("xsd:")) {
					dprss = dprs.substring(4).split("xsd:");
				} else
					dprss = dprs.split("xsd:");
				String t = "";
				for (int q = 0; q < dprss.length; q++)
					t = t + dprss[q];
				dprss = t.split(",");
				for (int k = 0; k < dprss.length; k++)
					if (dprss[k].contains("http"))
						temp.add(dprss[k].substring(
								dprss[k].indexOf(SEPARATOR) + 1,
								dprss[k].length() - 1));
					else
						temp.add(dprss[k]);
				dataPropertyRanges.add(temp);
			}
		}
	}

	// Getter and Setter
	public HashMap<OWLClassExpression, ArrayList<OWLDataProperty>> getDataProperties() {
		return dataProperties;
	}

	public void setDataProperties(
			HashMap<OWLClassExpression, ArrayList<OWLDataProperty>> dataProperties) {
		this.dataProperties = dataProperties;
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

	public ArrayList<ArrayList<String>> getDataPropertyRanges() {
		return dataPropertyRanges;
	}

	public void setDataPropertyRanges(
			ArrayList<ArrayList<String>> dataPropertyRanges) {
		this.dataPropertyRanges = dataPropertyRanges;
	}

}
