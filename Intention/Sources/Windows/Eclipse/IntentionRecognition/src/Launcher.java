/****************************************************************************************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards and Technology (NIST), an agency of the U.S. government, and by 
   statute is not subject to copyright in the United States.  
   Recipients of this software assume all responsibility associated with its operation, modification, maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 ****************************************************************************************************************************************************/

import gui.OptionFrame;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import javax.swing.UnsupportedLookAndFeelException;
import ontology.Ontology;
import org.semanticweb.owlapi.model.OWLClass;
import org.semanticweb.owlapi.model.OWLException;
import org.semanticweb.owlapi.model.OWLOntology;
import org.semanticweb.owlapi.reasoner.NodeSet;
/**
 * @author Zeid Kootbally (zeid.kootbally@nist.gov)
 * 
 */
public class Launcher {


	/**
	 * \brief Auto-generated constructor stub
	 */
	public Launcher() {

	}

	/**
	 * \brief Main of the project. The main file allows:
	 * <ul>
	 * <li>The creation of an object for the class Ontology.
	 * <li>Set the OWLAPI manager.
	 * <li>Initialize all the array lists that are used in the project.
	 * <li>Load the ontology.
	 * <li>Set the OWLAPI reasoner.
	 * <li>Set the OWLAPI data factory.
	 * <li>Parse the ontology to retrieve information on each intention.
	 * </ul>
	 * 
	 * @param args
	 * @throws OWLException
	 * @throws InterruptedException
	 * @throws InvocationTargetException
	 * @throws UnsupportedLookAndFeelException 
	 * @throws IllegalAccessException 
	 * @throws InstantiationException 
	 * @throws ClassNotFoundException 
	 * @throws IOException 
	 */

	public static void main(String[] args) throws OWLException, InterruptedException, InvocationTargetException, ClassNotFoundException, InstantiationException, IllegalAccessException, IOException{

		
		final Ontology onto = new Ontology();
		Ontology.m_ontology = null;
		onto.setManager();
		onto.initializeList();

		//final OptionFrame mf = new OptionFrame();
		final OptionFrame option = new OptionFrame();
		option.createAndShowGUI(onto);
		/*
		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				option.createAndShowGUI(onto);
			}
		});
		*/
		
		while (! OptionFrame.m_validate) {
			System.out.println("");
			
		}


		// -- Load the ontology
		String ontologyPath = onto.getOntologyPath();
		onto.loadOntologyFromPath(ontologyPath);

		OWLOntology myOntology = onto.getOntology();

		// -- Create a reasoner to be used everywhere needed
		onto.setReasoner(myOntology);
		onto.setDataFactory();
		// -- Choice of the subclass in the class Intention

		String rootClass = onto.getRootClass();
		NodeSet<OWLClass> mySubClass = onto.getSubclasses(rootClass);


		onto.parseIntention(mySubClass);	


		//-- Activate everything in the tree
		//-- TODO create a function to enable all the followings

		if (OptionFrame.singleKitButton.isSelected()){
			gui.MainFrame.m_metricTree.setEnabled(true);
			gui.MainFrame.m_likelihoodTree.setEnabled(true);
			gui.MainFrame.m_metricsSelectionButton.setEnabled(true);
			gui.MainFrame.m_LH_Selection_Button.setEnabled(true);
			gui.MainFrame.m_csvitem.setEnabled(true);
		}


	}
}