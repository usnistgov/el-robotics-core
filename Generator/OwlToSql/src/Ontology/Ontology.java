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

package Ontology;

import DataBase.*;
import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;

import javax.swing.JOptionPane;

import org.semanticweb.owlapi.apibinding.OWLManager;
import org.semanticweb.owlapi.model.IRI;
import org.semanticweb.owlapi.model.OWLClass;
import org.semanticweb.owlapi.model.OWLClassExpression;
import org.semanticweb.owlapi.model.OWLOntology;
import org.semanticweb.owlapi.model.OWLOntologyCreationException;
import org.semanticweb.owlapi.model.OWLOntologyManager;
import org.semanticweb.owlapi.util.OWLOntologyMerger;

public class Ontology {
	/**
	 * \brief     Separator between URL and the class' name in the ontology.
	 */
	private static final char SEPARATOR = '#';
	/**
	 * \brief      Path of the ontology.
	 */
	private String path;
	/**
	 * \brief      Where we are going to save the file.
	 */
	private String pathSave;
	/**
	 * \brief      Our ontology.
	 */
	private OWLOntology ontology;
	/**
	 * \brief      Instance of DataProperty.
	 */
	private DataProperty dp;
	/**
	 * \brief      Instance of ObjectProperty.
	 */
	private ObjectProperty op;
	/**
	 * \brief      Instance of Individuals.
	 */
	private Individuals ind;
	/**
	 * \brief      Instance of Tables.
	 */
	private Tables tables;
	/**
	 * \brief      Ontology Manager - Used to load the ontology.
	 */
	private OWLOntologyManager manager;
	/**
	 * \brief      List of classes in the ontology.
	 */
	private ArrayList<OWLClass> classes;
	/**
	 * \brief      List of classes without the URL before their name.
	 */
	private ArrayList<String> classesClean;
	/**
	 * \brief      List of the super classes in the ontology.
	 * \detail Classe1=<SuperClasse1,SuperClasse2>,Classe2=<SuperClasse1,SuperClasse2>
	 */
	private HashMap<OWLClass, ArrayList<OWLClassExpression>> superclasses;
	/**
	 * \brief      List of the super classes without the URL before their name in the ontology.
	 * \detail Classe1=<SuperClasse1,SuperClasse2>,Classe2=<SuperClasse1,SuperClasse2>
	 */
	private HashMap<String, ArrayList<String>> superClassesClean;
	
	/**
     *  \brief Constructor
     *  \details Constructor of the Ontology class.
     *  \param p 	Path of the ontology.
     *  \param p2 	Path where we are going to save the sql files.
     *  \param ont 	Our ontology.
     */
	public Ontology(String p, String p2) {
		path = p;
		pathSave = p2
				+ path.substring(path.lastIndexOf(File.separatorChar),
						path.length());
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
		tables = new Tables(pathSave, classesClean,
				dp.getDataPropertiesClean(), dp.getDataSingleValued(),
				dp.getDataRequired(), dp.getDataPropertyRanges(),
				op.getObjectPropertiesClean(), op.getObjectSingleValued(),
				op.getObjectRequired(), op.getObjectPropertyRanges(),
				superClassesClean, op.getObjectPropertyInverse());
		ind = new Individuals(tables.getTables(), ontology, pathSave,
				superClassesClean);

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
	 * \brief List all the classes.
	 * \details Fill the classes list.
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
	 * \brief List all the super classes.
	 * \details Fill the superclasses list.
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

	// Getter and Setter
	public static char getSeparator() {
		return SEPARATOR;
	}

	public String getPath() {
		return path;
	}

	public void setPath(String path) {
		this.path = path;
	}

	public OWLOntology getOntology() {
		return ontology;
	}

	public void setOntology(OWLOntology ontology) {
		this.ontology = ontology;
	}

	public OWLOntologyManager getManager() {
		return manager;
	}

	public void setManager(OWLOntologyManager manager) {
		this.manager = manager;
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

	public HashMap<OWLClass, ArrayList<OWLClassExpression>> getSuperclasses() {
		return superclasses;
	}

	public void setSuperclasses(
			HashMap<OWLClass, ArrayList<OWLClassExpression>> superclasses) {
		this.superclasses = superclasses;
	}

	public HashMap<String, ArrayList<String>> getSuperClassesClean() {
		return superClassesClean;
	}

	public void setSuperClassesClean(
			HashMap<String, ArrayList<String>> superClassesClean) {
		this.superClassesClean = superClassesClean;
	}

	public DataProperty getDp() {
		return dp;
	}

	public void setDp(DataProperty dp) {
		this.dp = dp;
	}

	public ObjectProperty getOp() {
		return op;
	}

	public void setOp(ObjectProperty op) {
		this.op = op;
	}

	public Tables getTables() {
		return tables;
	}

	public void setTables(Tables tables) {
		this.tables = tables;
	}

	public Individuals getInd() {
		return ind;
	}

	public void setInd(Individuals ind) {
		this.ind = ind;
	}
}
