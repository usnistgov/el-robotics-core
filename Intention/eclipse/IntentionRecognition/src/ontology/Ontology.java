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
 * \file      Ontology.java
 * \author    Anthony Pietromartire \a pietromartire.anthony\@nist.gov
 * \version   1.0
 * \date      29 June 2012
 * \brief     Class for the ontology.
 *
 * \details   This class is used to manipulate the ontology and extract the data in it.  
 */

/**
 * \class 	Ontology.Ontology
 * \brief     Class for the ontology.
 * \details   This class is used to manipulate the ontology and extract the data in it.  
 */

package ontology;



import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;

import javax.swing.JOptionPane;

import org.semanticweb.owlapi.apibinding.OWLManager;
import org.semanticweb.owlapi.io.OWLFunctionalSyntaxOntologyFormat;
import org.semanticweb.owlapi.model.AddAxiom;
import org.semanticweb.owlapi.model.IRI;
import org.semanticweb.owlapi.model.OWLAxiom;
import org.semanticweb.owlapi.model.OWLClass;
import org.semanticweb.owlapi.model.OWLClassExpression;
import org.semanticweb.owlapi.model.OWLDataFactory;
import org.semanticweb.owlapi.model.OWLDataProperty;
import org.semanticweb.owlapi.model.OWLDatatype;
import org.semanticweb.owlapi.model.OWLIndividual;
import org.semanticweb.owlapi.model.OWLLiteral;
import org.semanticweb.owlapi.model.OWLNamedIndividual;
import org.semanticweb.owlapi.model.OWLObjectProperty;
import org.semanticweb.owlapi.model.OWLOntology;
import org.semanticweb.owlapi.model.OWLOntologyCreationException;
import org.semanticweb.owlapi.model.OWLOntologyManager;
import org.semanticweb.owlapi.model.OWLOntologyStorageException;
import org.semanticweb.owlapi.model.RemoveAxiom;
import org.semanticweb.owlapi.util.OWLOntologyMerger;
import org.semanticweb.owlapi.vocab.OWL2Datatype;

public class Ontology {
	/**
	 * \brief Separator between URL and the class' name in the ontology.
	 */
	private static final char SEPARATOR = '#';
	/**
	 * \brief Path of the ontology.
	 */
	private String path;
	/**
	 * \brief Where we are going to save the file.
	 */
	private String pathSave;
	/**
	 * \brief Our ontology.
	 */
	private OWLOntology ontology;
	/**
	 * \brief Instance of DataProperty.
	 */
	private DataProperty dp;
	/**
	 * \brief Instance of ObjectProperty.
	 */
	private ObjectProperty op;

	/**
	 * \brief Ontology Manager - Used to load the ontology.
	 */
	private OWLOntologyManager manager;
	/**
	 * \brief List of classes in the ontology.
	 */
	private ArrayList<OWLClass> classes;
	/**
	 * \brief List of classes without the URL before their name.
	 */
	private ArrayList<String> classesClean;
	/**
	 * \brief List of the super classes in the ontology. \details
	 * Classe1=<SuperClasse1,SuperClasse2>,Classe2=<SuperClasse1,SuperClasse2>
	 */
	private HashMap<OWLClass, ArrayList<OWLClassExpression>> superclasses;
	/**
	 * \brief List of the super classes without the URL before their name in the
	 * ontology. \details
	 * Classe1=<SuperClasse1,SuperClasse2>,Classe2=<SuperClasse1,SuperClasse2>
	 */
	private HashMap<String, ArrayList<String>> superClassesClean;

	/**
	 * \brief Constructor \details Constructor of the Ontology class. \param p
	 * Path of the ontology. \param p2 Path where we are going to save the sql
	 * files.
	 */
	public Ontology(String p) {
		path = p;
		ontology = null;
		manager = OWLManager.createOWLOntologyManager();
		classes = null;
		classesClean = new ArrayList<String>();
		superClassesClean = new HashMap<String, ArrayList<String>>();
		superclasses = null;
		loadFromFile(); // Load the ontology from a local file
		addClasses(); // Fill up the classes list - add the classes
		cleanClasses(); // delete the url before the name of the class
		addSuperClasses(); // Fill up the superclasses list - add the
							// SuperClasses
		cleanSuperClasses(); // delete the url before the name of the SuperClass
		dp = new DataProperty(classes, classesClean, ontology);
		op = new ObjectProperty(classes, classesClean, ontology);
	}

	/**
	 * \brief Load the ontology from a file.
	 */
	public void loadFromFile() {
		File file = new File(this.path);
		try {
			// this.ontology = manager.loadOntologyFromOntologyDocument(file);
			// begin merge
			manager.loadOntologyFromOntologyDocument(file).getImports();
			OWLOntologyMerger merger = new OWLOntologyMerger(manager);
			ontology = merger.createMergedOntology(manager, null);
			// end merge
			System.out.println("Loaded ontology: " + this.ontology);

		} catch (OWLOntologyCreationException e) {
			e.printStackTrace();
			JOptionPane.showMessageDialog(null, e.getStackTrace());

		}
	}

	/**
	 * \brief Give the owl IRI for the value of a data property. \param unit
	 * unit of the value. \return IRI of the unit.
	 */
	public OWLDatatype getDataPropertyType(String unit) {
		OWLDataFactory df = manager.getOWLDataFactory();
		unit = unit.toLowerCase();
		if (unit.equals("short"))
			return df.getOWLDatatype(OWL2Datatype.XSD_SHORT.getIRI());
		if (unit.equals("unsignedshort"))
			return df.getOWLDatatype(OWL2Datatype.XSD_UNSIGNED_SHORT.getIRI());
		if (unit.equals("integer"))
			return df.getOWLDatatype(OWL2Datatype.XSD_INTEGER.getIRI());
		if (unit.equals("positiveinteger"))
			return df
					.getOWLDatatype(OWL2Datatype.XSD_POSITIVE_INTEGER.getIRI());
		if (unit.equals("negativeinteger"))
			return df
					.getOWLDatatype(OWL2Datatype.XSD_NEGATIVE_INTEGER.getIRI());
		if (unit.equals("nonpositiveinteger"))
			return df.getOWLDatatype(OWL2Datatype.XSD_NON_POSITIVE_INTEGER
					.getIRI());
		if (unit.equals("nonnegativeinteger"))
			return df.getOWLDatatype(OWL2Datatype.XSD_NON_NEGATIVE_INTEGER
					.getIRI());
		if (unit.equals("int"))
			return df.getOWLDatatype(OWL2Datatype.XSD_INT.getIRI());
		if (unit.equals("unsignedint"))
			return df.getOWLDatatype(OWL2Datatype.XSD_UNSIGNED_INT.getIRI());
		if (unit.equals("long"))
			return df.getOWLDatatype(OWL2Datatype.XSD_LONG.getIRI());
		if (unit.equals("unsignedlong"))
			return df.getOWLDatatype(OWL2Datatype.XSD_UNSIGNED_LONG.getIRI());
		if (unit.equals("decimal"))
			return df.getOWLDatatype(OWL2Datatype.XSD_DECIMAL.getIRI());
		if (unit.equals("float"))
			return df.getOWLDatatype(OWL2Datatype.XSD_FLOAT.getIRI());
		if (unit.equals("double"))
			return df.getOWLDatatype(OWL2Datatype.XSD_DOUBLE.getIRI());
		if (unit.equals("string"))
			return df.getOWLDatatype(OWL2Datatype.XSD_STRING.getIRI());
		if (unit.equals("normalizedstring"))
			return df.getOWLDatatype(OWL2Datatype.XSD_NORMALIZED_STRING
					.getIRI());
		if (unit.equals("nmtoken"))
			return df.getOWLDatatype(OWL2Datatype.XSD_NMTOKEN.getIRI());
		if (unit.equals("token"))
			return df.getOWLDatatype(OWL2Datatype.XSD_TOKEN.getIRI());
		if (unit.equals("language"))
			return df.getOWLDatatype(OWL2Datatype.XSD_LANGUAGE.getIRI());
		if (unit.equals("name"))
			return df.getOWLDatatype(OWL2Datatype.XSD_NAME.getIRI());
		if (unit.equals("ncname"))
			return df.getOWLDatatype(OWL2Datatype.XSD_NCNAME.getIRI());
		if (unit.equals("datetime"))
			return df.getOWLDatatype(OWL2Datatype.XSD_DATE_TIME.getIRI());
		if (unit.equals("boolean"))
			return df.getOWLDatatype(OWL2Datatype.XSD_BOOLEAN.getIRI());
		if (unit.equals("hexbinary"))
			return df.getOWLDatatype(OWL2Datatype.XSD_HEX_BINARY.getIRI());
		if (unit.equals("anyuri"))
			return df.getOWLDatatype(OWL2Datatype.XSD_ANY_URI.getIRI());
		else
			return df.getOWLDatatype(OWL2Datatype.XSD_STRING.getIRI());
	}

	/**
	 * \brief Update value of an object property. \param instance name of the
	 * entity concerned.\param oldValue old value \param newValue new value
	 * \param oProp name of the object property
	 */
	/*
	public void updateObjectPropertyValue(String instance, String oldValue,
			String newValue, String oProp) {
		delObjectPropertyValue(instance, oldValue, oProp);
		addObjectPropertyValue(instance, newValue, oProp);
	}
	*/

	/**
	 * \brief Add a value of an object property. \param instance name of the
	 * entity concerned. \param value new value \param oProp name of the object
	 * property
	 */
	/*
	public void addObjectPropertyValue(String instance, String value,
			String oProp) {
		String url = "";
		if (!ind.getIndividuals().isEmpty())
			if (ind.getIndividuals().get(0) != null)
				url = ind
						.getIndividuals()
						.get(0)
						.toString()
						.substring(
								1,
								ind.getIndividuals().get(0).toString()
										.indexOf(SEPARATOR));
		IRI iri = null;
		if (url.isEmpty())
			iri = IRI
					.create("http://www.nist.gov/el/ontologies/kittingClasses.owl");
		else
			iri = IRI.create(url);

		File file = new File(this.path);
		OWLDataFactory df = manager.getOWLDataFactory();
		OWLIndividual ins = df.getOWLNamedIndividual(IRI.create(iri + "#"
				+ instance));
		OWLIndividual val = df.getOWLNamedIndividual(IRI.create(iri + "#"
				+ value));
		OWLObjectProperty oprop = df.getOWLObjectProperty(IRI.create(iri + "#"
				+ oProp));
		OWLAxiom assertion = df.getOWLObjectPropertyAssertionAxiom(oprop, ins,
				val);
		AddAxiom addAxiomChange = new AddAxiom(ontology, assertion);
		manager.applyChange(addAxiomChange);
		try {
			manager.saveOntology(ontology,
					new OWLFunctionalSyntaxOntologyFormat(),
					IRI.create(file.toURI()));
		} catch (OWLOntologyStorageException e) {
			e.printStackTrace();
		}

	}
	*/

	/**
	 * \brief Delete value of an object property. \param instance name of the
	 * entity concerned. \param value new value \param oProp name of the object
	 * property
	 */
	/*
	public void delObjectPropertyValue(String instance, String value,
			String oProp) {
		String url = "";
		if (!ind.getIndividuals().isEmpty())
			if (ind.getIndividuals().get(0) != null)
				url = ind
						.getIndividuals()
						.get(0)
						.toString()
						.substring(
								1,
								ind.getIndividuals().get(0).toString()
										.indexOf(SEPARATOR));
		IRI iri = null;
		if (url.isEmpty())
			iri = IRI
					.create("http://www.nist.gov/el/ontologies/kittingClasses.owl");
		else
			iri = IRI.create(url);

		File file = new File(this.path);
		OWLDataFactory df = manager.getOWLDataFactory();
		OWLIndividual ins = df.getOWLNamedIndividual(IRI.create(iri + "#"
				+ instance));
		OWLIndividual val = df.getOWLNamedIndividual(IRI.create(iri + "#"
				+ value));
		OWLObjectProperty oprop = df.getOWLObjectProperty(IRI.create(iri + "#"
				+ oProp));
		OWLAxiom assertion = df.getOWLObjectPropertyAssertionAxiom(oprop, ins,
				val);
		RemoveAxiom removeAxiom = new RemoveAxiom(ontology, assertion);
		manager.applyChange(removeAxiom);
		try {
			manager.saveOntology(ontology,
					new OWLFunctionalSyntaxOntologyFormat(),
					IRI.create(file.toURI()));
		} catch (OWLOntologyStorageException e) {
			e.printStackTrace();
		}

	}
	*/

	/**
	 * \brief Update value of a data property. \param instance name of the
	 * entity concerned.\param oldValue old value \param newValue new value
	 * \param dProp name of the data property
	 */
//	public void updateDataPropertyValue(String instance, String oldValue,
//			String newValue, String dProp) {
//		delDataPropertyValue(instance, oldValue, dProp);
//		addDataPropertyValue(instance, newValue, dProp);
//	}

	/**
	 * \brief Add a value of a data property. \param instance name of the entity
	 * concerned. \param value new value \param dProp name of the data property
	 */
//	public void addDataPropertyValue(String instance, String value, String dProp) {
//		String url = "";
//		if (!ind.getIndividuals().isEmpty())
//			if (ind.getIndividuals().get(0) != null)
//				url = ind
//						.getIndividuals()
//						.get(0)
//						.toString()
//						.substring(
//								1,
//								ind.getIndividuals().get(0).toString()
//										.indexOf(SEPARATOR));
//		IRI iri = null;
//		if (url.isEmpty())
//			iri = IRI
//					.create("http://www.nist.gov/el/ontologies/kittingClasses.owl");
//		else
//			iri = IRI.create(url);
//
//		File file = new File(this.path);
//		OWLDataFactory df = manager.getOWLDataFactory();
//		OWLIndividual ins = df.getOWLNamedIndividual(IRI.create(iri + "#"
//				+ instance));
//		int index = -1;
//		for (int i = 0; i < dp.getDataPropertyRanges().size(); i++) {
//			if (dp.getDataPropertyRanges().get(i).get(0).equals(dProp))
//				index = i;
//		}
//		OWLLiteral val;
//		if (index != -1 && !dp.getDataPropertyRanges().get(index).isEmpty())
//			val = df.getOWLLiteral(value, getDataPropertyType(dp
//					.getDataPropertyRanges().get(index).get(1)));
//		else
//			val = df.getOWLLiteral(value);
//
//		OWLDataProperty dprop = df.getOWLDataProperty(IRI.create(iri + "#"
//				+ dProp));
//		OWLAxiom assertion = df.getOWLDataPropertyAssertionAxiom(dprop, ins,
//				val);
//		AddAxiom addAxiomChange = new AddAxiom(ontology, assertion);
//		manager.applyChange(addAxiomChange);
//		try {
//			manager.saveOntology(ontology,
//					new OWLFunctionalSyntaxOntologyFormat(),
//					IRI.create(file.toURI()));
//		} catch (OWLOntologyStorageException e) {
//			e.printStackTrace();
//		}
//
//	}

	/**
	 * \brief Delete value of a data property. \param instance name of the
	 * entity concerned. \param value new value \param dProp name of the data
	 * property
	 */
	/*
	public void delDataPropertyValue(String instance, String value, String dProp) {
		String url = "";
		if (!ind.getIndividuals().isEmpty())
			if (ind.getIndividuals().get(0) != null)
				url = ind
						.getIndividuals()
						.get(0)
						.toString()
						.substring(
								1,
								ind.getIndividuals().get(0).toString()
										.indexOf(SEPARATOR));
		IRI iri = null;
		if (url.isEmpty())
			iri = IRI
					.create("http://www.nist.gov/el/ontologies/kittingClasses.owl");
		else
			iri = IRI.create(url);

		File file = new File(this.path);
		OWLDataFactory df = manager.getOWLDataFactory();
		OWLIndividual ins = df.getOWLNamedIndividual(IRI.create(iri + "#"
				+ instance));
		int index = -1;
		for (int i = 0; i < dp.getDataPropertyRanges().size(); i++) {
			if (dp.getDataPropertyRanges().get(i).get(0).equals(dProp))
				index = i;
		}
		OWLLiteral val;
		if (index != -1 && !dp.getDataPropertyRanges().get(index).isEmpty())
			val = df.getOWLLiteral(value, getDataPropertyType(dp
					.getDataPropertyRanges().get(index).get(1)));
		else
			val = df.getOWLLiteral(value);
		OWLDataProperty dprop = df.getOWLDataProperty(IRI.create(iri + "#"
				+ dProp));
		OWLAxiom assertion = df.getOWLDataPropertyAssertionAxiom(dprop, ins,
				val);
		RemoveAxiom removeAxiom = new RemoveAxiom(ontology, assertion);
		manager.applyChange(removeAxiom);
		try {
			manager.saveOntology(ontology,
					new OWLFunctionalSyntaxOntologyFormat(),
					IRI.create(file.toURI()));
		} catch (OWLOntologyStorageException e) {
			e.printStackTrace();
		}
	}
	*/



	/**
	 * \brief Load the ontology from an URL.
	 */
	public void loadFromURL() {
		IRI iri = IRI.create(this.path);
		try {
			// this.ontology = manager.loadOntologyFromOntologyDocument(iri);
			// begin merge
			manager.loadOntology(iri).getImports();
			OWLOntologyMerger merger = new OWLOntologyMerger(manager);
			ontology = merger.createMergedOntology(manager, null);
			// end merge
			System.out.println("Loaded ontology: " + this.ontology);

		} catch (OWLOntologyCreationException e) {
			e.printStackTrace();
			JOptionPane.showMessageDialog(null, e.getStackTrace());

		}
	}

	/**
	 * \brief List all the classes. \details Fill the classes list.
	 */
	public void addClasses() {
		classes = new ArrayList<OWLClass>(ontology.getClassesInSignature());
		for (int i = 0; i < classes.size(); i++) {
			if (classes.get(i).toString().equals("owl:Thing")) {
				classes.remove(i);
				break;
			}
		}
	}

	/**
	 * \brief List all the super classes. \details Fill the superclasses list.
	 */
	public void addSuperClasses() {
		superclasses = new HashMap<OWLClass, ArrayList<OWLClassExpression>>();
		for (int i = 0; i < classes.size(); i++) {
			superclasses.put(classes.get(i), new ArrayList<OWLClassExpression>(
					classes.get(i).getSuperClasses(ontology)));
		}
	}

	/**
	 * \brief Delete the url before the name of the classes.
	 */
	public void cleanClasses() {
		for (int i = 0; i < classes.size(); i++) {
			classesClean.add(classes
					.get(i)
					.toString()
					.substring(
							classes.get(i).toString().indexOf(SEPARATOR) + 1,
							classes.get(i).toString().length() - 1));
		}

	}

	/**
	 * \brief Delete the url before the name of the super classes.
	 */
	public void cleanSuperClasses() {
		for (int i = 0; i < classes.size(); i++) {
			ArrayList<String> temp = new ArrayList<String>();
			for (int j = 0; j < superclasses.get(classes.get(i)).size(); j++) {
				if (!superclasses.get(classes.get(i)).get(j).toString()
						.equals("owl:Thing"))
					temp.add(superclasses
							.get(classes.get(i))
							.get(j)
							.toString()
							.substring(
									superclasses.get(classes.get(i)).get(j)
											.toString().indexOf(SEPARATOR) + 1,
									superclasses.get(classes.get(i)).get(j)
											.toString().length() - 1));
			}
			if (temp.size() > 0)
				superClassesClean.put(classesClean.get(i).toString(), temp);
		}
	}

	/**
	 * \brief Simple getter. \return SEPARATOR
	 */
	public static char getSeparator() {
		return SEPARATOR;
	}

	/**
	 * \brief Simple getter. \return path
	 */
	public String getPath() {
		return path;
	}

	/**
	 * \brief Simple setter. \param path
	 */
	public void setPath(String path) {
		this.path = path;
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
	 * \brief Simple getter. \return manager
	 */
	public OWLOntologyManager getManager() {
		return manager;
	}

	/**
	 * \brief Simple setter. \param manager
	 */
	public void setManager(OWLOntologyManager manager) {
		this.manager = manager;
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
	 * \brief Simple getter. \return superclasses
	 */
	public HashMap<OWLClass, ArrayList<OWLClassExpression>> getSuperclasses() {
		return superclasses;
	}

	/**
	 * \brief Simple setter. \param superclasses
	 */
	public void setSuperclasses(
			HashMap<OWLClass, ArrayList<OWLClassExpression>> superclasses) {
		this.superclasses = superclasses;
	}

	/**
	 * \brief Simple getter. \return superClassesClean
	 */
	public HashMap<String, ArrayList<String>> getSuperClassesClean() {
		return superClassesClean;
	}

	/**
	 * \brief Simple setter. \param superClassesClean
	 */
	public void setSuperClassesClean(
			HashMap<String, ArrayList<String>> superClassesClean) {
		this.superClassesClean = superClassesClean;
	}

	/**
	 * \brief Simple getter. \return dp
	 */
	public DataProperty getDp() {
		return dp;
	}

	/**
	 * \brief Simple setter. \param dp
	 */
	public void setDp(DataProperty dp) {
		this.dp = dp;
	}

	/**
	 * \brief Simple getter. \return op
	 */
	public ObjectProperty getOp() {
		return op;
	}

	/**
	 * \brief Simple setter. \param op
	 */
	public void setOp(ObjectProperty op) {
		this.op = op;
	}

	
}
