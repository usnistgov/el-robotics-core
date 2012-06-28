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
import DataBase.*;
import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;

import javax.swing.JOptionPane;

import org.semanticweb.owlapi.apibinding.OWLManager;
import org.semanticweb.owlapi.model.IRI;
import org.semanticweb.owlapi.model.OWLClass;
import org.semanticweb.owlapi.model.OWLClassExpression;
import org.semanticweb.owlapi.model.OWLHasKeyAxiom;
import org.semanticweb.owlapi.model.OWLOntology;
import org.semanticweb.owlapi.model.OWLOntologyCreationException;
import org.semanticweb.owlapi.model.OWLOntologyManager;
import org.semanticweb.owlapi.util.OWLOntologyMerger;

public class Ontology {
	static final char SEPARATOR = '#';
	private String path;
	private String pathSave;
	private OWLOntology ontology;
	private DataProperty dp;
	private ObjectProperty op;
	private Individuals ind;
	private Tables tables;
	private OWLOntologyManager manager;
	private ArrayList<OWLClass> classes;
	private ArrayList<String> classesClean;
	// list of classes
	private HashMap<String, String> classesId;
	// Class => Id
	private HashMap<OWLClass, ArrayList<OWLClassExpression>> superclasses;
	// Class => <SuperClass1, SuperClass2, ...>
	private HashMap<String, ArrayList<String>> superClassesClean;

	// Classe1=<SuperClasse1,SuperClasse2>,Classe2=<SuperClasse1,SuperClasse2>

	public Ontology(String p, String p2) {
		path = p;
		pathSave=p2+path.substring(path.lastIndexOf(File.separatorChar),path.length());
		ontology = null;
		manager = OWLManager.createOWLOntologyManager();
		classes = null;
		classesClean = new ArrayList<String>();
		superClassesClean = new HashMap<String, ArrayList<String>>();
		superclasses = null;
		classesId = new HashMap<String, String>();
		loadFromFile(); // Load the ontology from a local file
		addClasses(); // Fill up the classes list - add the classes
		cleanClasses(); // delete the url before the name of the class
		addSuperClasses(); // Fill up the superclasses list - add the
							// SuperClasses
		cleanSuperClasses(); // delete the url before the name of the SuperClass
		addId(); // Fill up the classesId map - add the id of a class
		dp = new DataProperty(classes, classesClean, ontology);
		op = new ObjectProperty(classes, classesClean, ontology);
		tables = new Tables(pathSave, classesClean, dp.getDataPropertiesClean(),
				dp.getDataSingleValued(), dp.getDataRequired(),
				dp.getDataPropertyRanges(), op.getObjectPropertiesClean(),
				op.getObjectSingleValued(), op.getObjectRequired(),
				op.getObjectPropertyRanges(), superClassesClean, classesId,
				op.getObjectPropertyInverse());
		ind = new Individuals(tables.getTables(), ontology, pathSave, superClassesClean);

	}

	// Fill up the classesId map - add the id of a class
	private void addId() {
		for (int i = 0; i < classes.size(); i++) {
			ArrayList<OWLHasKeyAxiom> a = new ArrayList<OWLHasKeyAxiom>(
					ontology.getHasKeyAxioms(classes.get(i)));
			if (a.size() > 0) {
				for (int j = 0; j < a.size(); j++) {
					String s[] = a.get(j).toString().split("owl");
					String result = "";
					int cpt = 0;
					for (int k = 1; k < s.length; k++) {
						if (s[k].contains(String.valueOf(SEPARATOR))) {
							if (cpt == 1) {
								result = s[k].substring(
										s[k].indexOf(SEPARATOR) + 1,
										s[k].indexOf(">"));
								cpt++;
							} else if (cpt > 1)
								result = result
										+ " ,"
										+ s[k].substring(
												s[k].indexOf(SEPARATOR) + 1,
												s[k].indexOf(">"));
							cpt++;
						}
						if (result.length() > 0)
							classesId.put(classesClean.get(i), result);
					}
				}
			}
		}
	}

	// Load the ontology from a local file
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
			JOptionPane.showMessageDialog(null,
					e.getStackTrace());

		}
	}

	// Load the ontology from an URL
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
			JOptionPane.showMessageDialog(null,
					e.getStackTrace());


		}
	}

	// Fill up the classes list - add the classes
	public void addClasses() {
		classes = new ArrayList<OWLClass>(ontology.getClassesInSignature());
		for (int i = 0; i < classes.size(); i++) {
			if (classes.get(i).toString().equals("owl:Thing")) {
				classes.remove(i);
				break;
			}
		}
	}

	// Fill up the list superclasses - add the Super classes
	public void addSuperClasses() {
		superclasses = new HashMap<OWLClass, ArrayList<OWLClassExpression>>();
		for (int i = 0; i < classes.size(); i++) {
			superclasses.put(classes.get(i), new ArrayList<OWLClassExpression>(
					classes.get(i).getSuperClasses(ontology)));
		}
	}

	// delete the url before the name of the class
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

	// delete the url before the name of the SuperClass
	public void cleanSuperClasses() {
		for (int i = 0; i < classes.size(); i++) {
			ArrayList<String> temp = new ArrayList<String>();
			for (int j = 0; j < superclasses.get(classes.get(i)).size(); j++) {
				if(!superclasses
						.get(classes.get(i))
						.get(j)
						.toString().equals("owl:Thing"))
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

	public HashMap<String, String> getClassesId() {
		return classesId;
	}

	public void setClassesId(HashMap<String, String> classesId) {
		this.classesId = classesId;
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
