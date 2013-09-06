/****************************************************************************************************************************************************
 * DISCLAIMER:
 * This software was produced by the National Institute of Standards and Technology (NIST), an
 * agency of the U.S. government, and by
 * statute is not subject to copyright in the United States.
 * Recipients of this software assume all responsibility associated with its operation,
 * modification, maintenance, and subsequent redistribution.
 * 
 * See NIST Administration Manual 4.09.07 b and Appendix I.
 ****************************************************************************************************************************************************/

/**
 * \class Ontology
 * 
 * \ingroup ontology
 * 
 * \brief Class for the ontology.
 * 
 * This class is used to manipulate the ontology and extract data from it.
 * 
 * \author zeidk
 * 
 * \date 2013/01/01
 * 
 * Contact: zeid.kootbally@nist.gov
 * 
 */
package ontology;

import gui.Chart;
import gui.MainFrame;
import gui.OptionFrame;
import gui.ProgressBar;
import intention.Intention;
import intention.Metric;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Toolkit;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileFilter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.InvocationTargetException;
import java.net.MalformedURLException;
import java.text.DecimalFormat;
import java.text.Normalizer;
import java.text.Normalizer.Form;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextPane;
import javax.swing.JTree;
import javax.swing.SwingUtilities;
import javax.swing.WindowConstants;
import javax.swing.text.BadLocationException;
import javax.swing.tree.DefaultMutableTreeNode;

import org.jfree.ui.RefineryUtilities;
import org.semanticweb.owlapi.apibinding.OWLManager;
import org.semanticweb.owlapi.model.IRI;
import org.semanticweb.owlapi.model.OWLClass;
import org.semanticweb.owlapi.model.OWLClassExpression;
import org.semanticweb.owlapi.model.OWLDataFactory;
import org.semanticweb.owlapi.model.OWLDataProperty;
import org.semanticweb.owlapi.model.OWLException;
import org.semanticweb.owlapi.model.OWLIndividual;
import org.semanticweb.owlapi.model.OWLLiteral;
import org.semanticweb.owlapi.model.OWLNamedIndividual;
import org.semanticweb.owlapi.model.OWLObjectProperty;
import org.semanticweb.owlapi.model.OWLOntology;
import org.semanticweb.owlapi.model.OWLOntologyCreationException;
import org.semanticweb.owlapi.model.OWLOntologyManager;
import org.semanticweb.owlapi.reasoner.NodeSet;
import org.semanticweb.owlapi.util.OWLOntologyMerger;
import org.semanticweb.owlapi.reasoner.*;
import org.semanticweb.owlapi.reasoner.structural.StructuralReasonerFactory;
import org.semanticweb.owlapi.model.OWLObjectPropertyExpression;
import textfiles.FileOperator;
import tools.UI;

import org.scilab.forge.jlatexmath.TeXConstants;
import org.scilab.forge.jlatexmath.TeXFormula;
import org.scilab.forge.jlatexmath.TeXIcon;

public class Ontology {
	// private ArrayList<OWLNamedIndividual> intention_list;
	private static OWLDataFactory m_datafactory;
	// private Chart m_barcharupdate;
	private static OWLReasoner m_reasoner;
	private static String m_hasIntention_OrderingConstruct = "#hasIntention_OrderingConstruct";
	private static String m_hasOrderingConstruct_Predicate = "#hasOrderingConstruct_Predicate";
	private static String m_hasOrderingConstruct_OrderingConstruct = "#hasOrderingConstruct_OrderingConstruct";
	private static String m_hasOrderingConstruct_Position = "#hasOrderingConstruct_Position";
	private static String m_hasPredicate_TargetObject = "#hasPredicate_TargetObject";
	private static String m_hasIntention_Name = "#hasIntention_Name";
	private static String m_hasPredicate_ReferenceObject = "#hasPredicate_ReferenceObject";
	private static String m_hasCount_Occurrence = "#hasCount_Occurrence";
	// private String m_hasPart_Sku = "#hasPart_Sku";
	public static ArrayList<Intention> m_intention_list;
	private OWLOntologyManager m_manager;
	public static OWLOntology m_ontology;
	private JFrame m_progress_frame;
	public static String m_kitToBuild;
	private ProgressBar m_progress_bar;
	public static String m_planToBuild;
	private final static String m_ontology_IRI = "http://www.semanticweb.org/ontologies/2013/0/soap.owl";

	// public String s_ontopath =
	// "/home/zeid/workspace/IntentionRecognition/etc/kittingInstances_ir.owl";
	private String m_path;
	//private String m_s_ontopath = "/Users/zeid/Documents/GIT/zeid/workspace/IntentionRecognition/etc/kittingInstances_ir.owl";
	private static String m_s_ontopath;// = "etc/kittingInstances_ir.owl";
	//private HashMap<OWLNamedIndividual, ArrayList<OWLNamedIndividual>> m_orderedlist_orderingconstruct_list;
	private static final char m_SEPARATOR = '#';
	public String m_s_rootClass = "Intention";
	public static String m_s_subClass = "Kitting";
	//public JTree m_metricTree;

	/**
	 * \brief Constructor of the Ontology class.
	 */
	public Ontology() {
	}

	public static void setInstanceFilePath(String _path){
		//m_s_ontopath=_path;
		//m_s_ontopath="/home/zeid/workspace/IntentionRecognition/etc/kittingInstances_ir.owl";
		m_s_ontopath=OptionFrame.m_instance_txt_field.getText().toString();
	}
	
	
	public String getOntologyPath() {
		return m_s_ontopath;
	}

	public String getRootClass() {
		return m_s_rootClass;
	}

	public void setRootClass(String rootClass) {
		m_s_rootClass = rootClass;
	}

	/**
	 * @brief Parse the ontology and retrieve all the elements associated to
	 *        each intention. Each element found is stored in an attribute of
	 *        their corresponding Java class.
	 * 
	 * @param myClass
	 */
	private static void buildIntentionList(NodeSet<OWLClass> myClass) {

		// -- This variable counts the number of state relations associated to
		// an intention
		int count_intention_state_relation = 0;

		// -- Building Object and Data properties needed in this function
		OWLObjectProperty OWLOP_hasIntention_OrderingConstruct = m_datafactory
				.getOWLObjectProperty(IRI.create(m_ontology_IRI
						+ m_hasIntention_OrderingConstruct));
		OWLObjectProperty OWLOP_hasOrderingConstruct_OrderingConstruct = m_datafactory
				.getOWLObjectProperty(IRI.create(m_ontology_IRI
						+ m_hasOrderingConstruct_OrderingConstruct));
		OWLObjectProperty OWLOP_hasOrderingConstruct_Predicate = m_datafactory
				.getOWLObjectProperty(IRI.create(m_ontology_IRI
						+ m_hasOrderingConstruct_Predicate));
		OWLObjectProperty OWLOP_hasPredicate_TargetObject = m_datafactory
				.getOWLObjectProperty(IRI.create(m_ontology_IRI
						+ m_hasPredicate_TargetObject));
		OWLObjectProperty OWLOP_hasPredicate_ReferenceObject = m_datafactory
				.getOWLObjectProperty(IRI.create(m_ontology_IRI
						+ m_hasPredicate_ReferenceObject));
		OWLDataProperty OWLDP_hasCount_Occurrence = m_datafactory
				.getOWLDataProperty(IRI.create(m_ontology_IRI
						+ m_hasCount_Occurrence));
		OWLDataProperty OWLDP_hasIntention_Name = m_datafactory
				.getOWLDataProperty(IRI.create(m_ontology_IRI
						+ m_hasIntention_Name));
		OWLDataProperty OWLDP_hasOrderingConstruct_Position = m_datafactory
				.getOWLDataProperty(IRI.create(m_ontology_IRI
						+ m_hasOrderingConstruct_Position));

		Set<OWLClass> myClass_flat = myClass.getFlattened();
		for (OWLClass clazz : myClass_flat) {
			// -- We are checking if we are in the subclass "Kitting" from the
			// class "Intention"
			if (cleanIRI(clazz).equalsIgnoreCase(m_s_subClass)) {
				NodeSet<OWLNamedIndividual> intention_instances_NodeSet = m_reasoner
						.getInstances(clazz, true);
				for (OWLNamedIndividual intention_instance : intention_instances_NodeSet
						.getFlattened()) {
					// -- Create a new intention and add the individual to the
					// list
					Intention intention = new Intention();
					intention.setIndividual(intention_instance);
					intention.setPercentage(0.0);
					intention.setNumberStateRelation(0);
					
					//System.out.println("----------------+++++++++++++++++++++++++++-----------------");
					
					// intention_list.add(intention);

					// -- Get the individuals for the object property
					// hasIntention_OrderingConstruct
					NodeSet<OWLNamedIndividual> hasIntention_OrderingConstruct_nodeset = m_reasoner
							.getObjectPropertyValues(intention_instance,
									OWLOP_hasIntention_OrderingConstruct);

					// ----------------------------------------------------------------------------------------------//
					// -- Get the individuals that have the negative object
					// property hasIntention_OrderingConstruct --
					// -- Then store the individual in the intention's
					// m_forbidden_list
					// ----------------------------------------------------------------------------------------------//
					Map<OWLObjectPropertyExpression, Set<OWLIndividual>> negativeObjectPropertiesMap = intention_instance
							.getNegativeObjectPropertyValues(m_ontology);

					// System.out.println("NEGATIVE for Intention "+cleanIRI(intention_instance).toString());
					if (!negativeObjectPropertiesMap.isEmpty()) {
						for (Entry<OWLObjectPropertyExpression, Set<OWLIndividual>> entry : negativeObjectPropertiesMap
								.entrySet()) {
							for (OWLIndividual owlIndividual : entry.getValue()) {
								if (getIndividualClassString(owlIndividual)
										.endsWith("Exist")) {
									Exist forbidden_exist = new Exist();
									forbidden_exist
									.setIndividual(owlIndividual);

									// ********************************************//
									// -- Find the predicate for forbidden_exist
									// --//
									// ********************************************//
									NodeSet<OWLNamedIndividual> pfe_nodeset = m_reasoner
											.getObjectPropertyValues(
													(OWLNamedIndividual) owlIndividual,
													OWLOP_hasOrderingConstruct_Predicate);
									for (OWLNamedIndividual pfe_instance : pfe_nodeset
											.getFlattened()) {
										Predicate pfe = new Predicate();
										pfe.setIndividual(pfe_instance);

										// ***********************************//
										// -- Retrieve the reference object --//
										// ***********************************//
										NodeSet<OWLNamedIndividual> ref_nodeset = m_reasoner
												.getObjectPropertyValues(
														pfe_instance,
														OWLOP_hasPredicate_ReferenceObject);
										if (!ref_nodeset.isEmpty()) {
											for (OWLNamedIndividual ref_instance : ref_nodeset
													.getFlattened())
												pfe.setReference(ref_instance);
										}
										// ********************************//
										// -- Retrieve the target object --//
										// ********************************//
										NodeSet<OWLNamedIndividual> tg_nodeset = m_reasoner
												.getObjectPropertyValues(
														pfe_instance,
														OWLOP_hasPredicate_TargetObject);
													if (!tg_nodeset.isEmpty()) {
														for (OWLNamedIndividual tg_instance : tg_nodeset
																.getFlattened())
															pfe.setTarget(tg_instance);
													}
													pfe.setStateRelation(getStateRelation(pfe_instance));
																pfe.setTargetObjectClass(getTargetObjectClass(pfe_instance));
																pfe.setReferenceObjectClass(getReferenceObjectClass(pfe_instance));

																forbidden_exist.setPredicate(pfe);
																// ****************************************************//
																// -- Added the object Exist in the
																// m_forbidden_list --//
																// ****************************************************//
																intention.builDetrimentalList(forbidden_exist);
									}
								}
							}
						}
					}

					// ----------------------------------------------//
					// -- Get and store the name of each intention --
					// ----------------------------------------------//
					Set<OWLLiteral> intentionName_owlliteralset = m_reasoner
							.getDataPropertyValues(intention_instance,
									OWLDP_hasIntention_Name);
					for (OWLLiteral intentionName_owlliteral : intentionName_owlliteralset) {
						// System.out.println("Intention name: "+intentionName_owlliteral.getLiteral());
						intention.setIntentionName(intentionName_owlliteral
								.getLiteral());
					}

					// -- For each individual of hasIntention_OrderingConstruct
					for (OWLNamedIndividual ordering_construct_instance : hasIntention_OrderingConstruct_nodeset
							.getFlattened()) {
						// System.out.println("++"+cleanIRI(intention.getIndividual()).toString());kit_tray_1_ir
						// -- Check the individual is from OrderedList
						if (getIndividualClassString(
								ordering_construct_instance).endsWith(
										"OrderedList")) {
							// -- Create a new object from the class OrderedList
							OrderedList orderedlist = new OrderedList();
							orderedlist
							.setIndividual(ordering_construct_instance);
							intention.setOrderedList(orderedlist);

							NodeSet<OWLNamedIndividual> hasOrderingConstruct_OrderingConstruct_nodeset = m_reasoner
									.getObjectPropertyValues(
											ordering_construct_instance,
											OWLOP_hasOrderingConstruct_OrderingConstruct);

							for (OWLNamedIndividual orderingconstruct_instance : hasOrderingConstruct_OrderingConstruct_nodeset
									.getFlattened()) {
								Set<OWLLiteral> orderingconstruct_position = m_reasoner
										.getDataPropertyValues(
												orderingconstruct_instance,
												OWLDP_hasOrderingConstruct_Position);
								int position = cleanDataPropertyInteger(orderingconstruct_position
										.toString());

								// -- Check the individual is from AnyOrder
								if (getIndividualClassString(
										orderingconstruct_instance).endsWith(
												"AnyOrder")) {
									AnyOrder anyorder = new AnyOrder();
									anyorder.setIndividual(orderingconstruct_instance);
									anyorder.setPosition(position);

									// -- Get all the individuals of type Count
									NodeSet<OWLNamedIndividual> hasOrderingConstruct_OrderingConstruct_Count_nodeset = m_reasoner
											.getObjectPropertyValues(
													orderingconstruct_instance,
													OWLOP_hasOrderingConstruct_OrderingConstruct);

									int anyorder_total = 0;
									for (OWLNamedIndividual count_instance : hasOrderingConstruct_OrderingConstruct_Count_nodeset
											.getFlattened()) {
										// -- Making sure we are getting only
										// instances of the class Count
										if (getIndividualClassString(
												count_instance).endsWith(
														"Count")) {
											// -- Get the value associated to
											// the count instance
											Set<OWLLiteral> count_number_literal = m_reasoner
													.getDataPropertyValues(
															count_instance,
															OWLDP_hasCount_Occurrence);
											int count_number = cleanDataPropertyInteger(count_number_literal
													.toString());

											anyorder_total = anyorder_total
													+ count_number;

											Count count = new Count();
											count.setIndividual(count_instance);
											count.setOccurrence(count_number);
											count_intention_state_relation += count_number;

											// -- Getting the predicate node set
											// for count_instance
											NodeSet<OWLNamedIndividual> predicate_nodeset = m_reasoner
													.getObjectPropertyValues(
															count_instance,
															OWLOP_hasOrderingConstruct_Predicate);
											// -- Reading each predicate
											// individual
											for (OWLNamedIndividual predicate_instance : predicate_nodeset
													.getFlattened()) {

												Predicate predicate = new Predicate();
												predicate
												.setIndividual(predicate_instance);

												// -- Retrieve the reference
												// object
												NodeSet<OWLNamedIndividual> referenceobject_nodeset = m_reasoner
														.getObjectPropertyValues(
																predicate_instance,
																OWLOP_hasPredicate_ReferenceObject);
												// -- Retrieve the target object
												NodeSet<OWLNamedIndividual> targetobject_nodeset = m_reasoner
														.getObjectPropertyValues(
																predicate_instance,
																OWLOP_hasPredicate_TargetObject);

												if (!referenceobject_nodeset
														.isEmpty()) {
													for (OWLNamedIndividual reference_instance : referenceobject_nodeset
															.getFlattened()) {
														predicate
														.setReference(reference_instance);
													}
												}
												if (!targetobject_nodeset
														.isEmpty()) {
													for (OWLNamedIndividual target_instance : targetobject_nodeset
															.getFlattened()) {
														predicate
														.setTarget(target_instance);
													}
												}
												predicate.setStateRelation(getStateRelation(predicate_instance));
												predicate.setTargetObjectClass(getTargetObjectClass(predicate_instance));
												predicate.setReferenceObjectClass(getReferenceObjectClass(predicate_instance));

												count.setPredicate(predicate);
												anyorder.addCountToList(count);
												anyorder.setTotalNumber(anyorder_total);
											}

										}
									}
									orderedlist.setAnyOrder(anyorder);
								}
								// -- Check the individual is from Exist
								else if (getIndividualClassString(
										orderingconstruct_instance).endsWith(
												"Exist")) {
									Exist exist = new Exist();
									exist.setIndividual(orderingconstruct_instance);
									exist.setPosition(position);

									int exist_total = 0;

									// -- Get all the individuals of type Count
									NodeSet<OWLNamedIndividual> predicate_nodeset = m_reasoner
											.getObjectPropertyValues(
													orderingconstruct_instance,
													OWLOP_hasOrderingConstruct_Predicate);

									for (OWLNamedIndividual predicate_instance : predicate_nodeset
											.getFlattened()) {
										exist_total++;

										Predicate predicate = new Predicate();
										predicate
										.setIndividual(predicate_instance);

										// -- Retrieve the reference object
										NodeSet<OWLNamedIndividual> referenceobject_nodeset = m_reasoner
												.getObjectPropertyValues(
														predicate_instance,
														OWLOP_hasPredicate_ReferenceObject);

										if (!referenceobject_nodeset.isEmpty()) {
											for (OWLNamedIndividual reference_instance : referenceobject_nodeset
													.getFlattened())
												predicate
												.setReference(reference_instance);
										}

										// -- Retrieve the target object
										NodeSet<OWLNamedIndividual> targetobject_nodeset = m_reasoner
												.getObjectPropertyValues(
														predicate_instance,
														OWLOP_hasPredicate_TargetObject);

													if (!targetobject_nodeset.isEmpty()) {
														for (OWLNamedIndividual target_instance : targetobject_nodeset
																.getFlattened())
															predicate
															.setTarget(target_instance);
													}
													predicate
													.setStateRelation(getStateRelation(predicate_instance));
																predicate
																.setTargetObjectClass(getTargetObjectClass(predicate_instance));
																predicate
																.setReferenceObjectClass(getReferenceObjectClass(predicate_instance));

																exist.setPredicate(predicate);
																exist.setTotalNumber(exist_total);
																exist.setOccurrence(1);
																orderedlist.setExist(exist);
									}
								}

							}
							/*
							 * System.out.println(intention.getIntentionName() +
							 * "number of state relations: " +
							 * count_intention_state_relation);
							 */
							intention.setOrderedList(orderedlist);
							
							intention.setM_SR_Total(count_intention_state_relation);
							//System.out.println("Total State relations for intention "+intention.getIntentionName()+":"+count_intention_state_relation);
							m_intention_list.add(intention);
							count_intention_state_relation = 0;
						}
					}

				}
			}
		}
	}

	/**
	 * This function builds all the states for a given intention.
	 * 
	 * @param kit
	 *            The kit to build
	 * @return An ArrayList that contains all the states for the given kit
	 */
	private static ArrayList<ArrayList<ArrayList<String>>> buildStates(String plan_path) {

		/*
		if (OptionFrame.singleKitButton.isSelected()){
			*/
		
			//-- Build the path to the plan
			
			String[] textData = null;

			FileOperator op = new FileOperator();

			try {
				textData = op.openFile(plan_path);
			} catch (IOException e) {
				
				e.printStackTrace();
			}

			// -- The following state should be the first one in each state list
			// -- If this is not the case, the program will not find any intention
			ArrayList<String> l1 = new ArrayList<String>();
			if (m_kitToBuild.toLowerCase().contains("a4b3c3"))
				l1 = input("OntopWithContact", "kit_tray_1_ir",
						"KitTray", "work_table_1", "WorkTable");
			else if (m_kitToBuild.toLowerCase().contains("a4b4c2"))
				l1 = input("OntopWithContact", "kit_tray_2_ir",
						"KitTray", "work_table_1", "WorkTable");
			else if (m_kitToBuild.toLowerCase().contains("a2b3c5"))
				l1 = input("OntopWithContact", "kit_tray_3_ir",
						"KitTray", "work_table_1", "WorkTable");
			else if (m_kitToBuild.toLowerCase().contains("a4b3c2d1"))
				l1 = input("OntopWithContact", "kit_tray_4_ir",
						"KitTray", "work_table_1", "WorkTable");
			else if (m_kitToBuild.toLowerCase().contains("a2b3c3d1e1"))
				l1 = input("OntopWithContact", "kit_tray_5_ir",
						"KitTray", "work_table_1", "WorkTable");

			ArrayList<ArrayList<String>> State1 = new ArrayList<ArrayList<String>>();
			State1.add(l1);

			//-- Translate each line of textData into a state relation
			ArrayList<ArrayList<ArrayList<String>>> States = op.translatePlanToStateRelation(textData);
			//-- We need to include the fact that the kit tray is on the worktable as the very first state relation
			States.add(0, State1);

			return States;
			/*
		}
		else{
			//-- Get all the kits that can be built from the etc directory
			ArrayList<String> tmp_kitList = OptionFrame.getKitList();
			//-- Let's sort this list (kit 1, 2, ...)
			List<String> kitList = tmp_kitList.subList(0, tmp_kitList.size());
			Collections.sort(kitList);
			ArrayList<ArrayList<ArrayList<String>>> States = new ArrayList();
			
			for (int i=0; i<kitList.size(); i++)
			{
				String kit_path = "etc/kits/"+kitList.get(i)+"/";
				
				System.out.println(kitList.get(i));
				File plan_directory = new File(kit_path);  

				File[] subFiles = plan_directory.listFiles(new FileFilter() {  
					public boolean accept(File pathname) {  
						return pathname.isFile();  
					}  
				}); 
				ArrayList<String> tmpList = new ArrayList<String>();

				for (File subFile : subFiles) {  
					String path = subFile.getPath();

					String idStr = path.substring(path.lastIndexOf('/') + 1);
					String cleaned_idStr = idStr.substring(0, idStr.lastIndexOf('.')).toString();
					tmpList.add(cleaned_idStr);
				} 

				//-- Let's sort tmpList
				List<String> planList = tmpList.subList(0, tmpList.size());
				Collections.sort(planList);
				for (int j=0; j<planList.size(); j++)
				{
					String plan_path ="etc/kits/"+kitList.get(i)+"/"+planList.get(j)+".txt";
				System.out.println(plan_path);
				String[] textData = null;
				FileOperator op = new FileOperator();

				try {
					textData = op.openFile(plan_path);
				} catch (IOException e) {
					
					e.printStackTrace();
				}
				// -- The following state should be the first one in each state list
				// -- If this is not the case, the program will not find any intention
				ArrayList<String> l1 = new ArrayList<String>();
				if (kitList.get(i).toLowerCase().contains("a4b3c3"))
					l1 = input("OntopWithContact", "kit_tray_1_ir",
							"KitTray", "work_table_1", "WorkTable");
				else if (kitList.get(i).toLowerCase().contains("a4b4c2"))
					l1 = input("OntopWithContact", "kit_tray_2_ir",
							"KitTray", "work_table_1", "WorkTable");
				else if (kitList.get(i).toLowerCase().contains("a2b3c5"))
					l1 = input("OntopWithContact", "kit_tray_3_ir",
							"KitTray", "work_table_1", "WorkTable");
				else if (kitList.get(i).toLowerCase().contains("a4b3c2d1"))
					l1 = input("OntopWithContact", "kit_tray_4_ir",
							"KitTray", "work_table_1", "WorkTable");
				else if (kitList.get(i).toLowerCase().contains("a2b3c3d1e1"))
					l1 = input("OntopWithContact", "kit_tray_5_ir",
							"KitTray", "work_table_1", "WorkTable");
				
				ArrayList<ArrayList<String>> State1 = new ArrayList<ArrayList<String>>();
				State1.add(l1);
				
				//-- Translate each line of textData into a state relation
				States = op.translatePlanToStateRelation(textData);
				//-- We need to include the fact that the kit tray is on the worktable as the very first state relation
				States.add(0, State1);

				
				}
			}
			return States;
		}
		*/
	}

	private static int cleanDataPropertyInteger(String s) {
		StringBuilder myNumbers = new StringBuilder();
		for (int i = 0; i < s.length(); i++) {
			if (Character.isDigit(s.charAt(i))) {
				myNumbers.append(s.charAt(i));
			}
		}
		String myNumbers_s = myNumbers.toString();
		// System.out.println("Your numbers: " + myNumbers.toString());
		return Integer.parseInt(myNumbers_s);

	}

	/**
	 * \brief Return the name of the entity without the IRI
	 * 
	 * For example, if @a entity =
	 * [<http://www.semanticweb.org/ontologies/2013/0/soap.owl#Kitting>], this
	 * function returns @a Kitting. This function operates as follows: -
	 * Identify the index of the separator @a SEPARATOR - Keep only what is
	 * after the SEPARATOR - Remove characters that are not alphanumeric \param
	 * entity Entity to be trimmed \return The name of the entity without the
	 * IRI
	 */
	public static String cleanIRI(Object entity) {
		int index = entity.toString().indexOf(m_SEPARATOR);
		String new_entity = entity.toString().substring(index + 1);
		String normalized = Normalizer.normalize(new_entity.toString(),
				Form.NFD);
		String result = normalized.replaceAll("[^A-Za-z0-9-_]", "");

		return result;
	}

	/**
	 * @brief Compute the additive metric \f$AM_1\f$.
	 * 
	 *        \f$AM_1\f$: <i>Number of observed state relations that are true in
	 *        an intention (compared to other intentions).</i><br>
	 *        The formula for this additive metric for intention \f$i\f$ in
	 *        state \f$s\f$ is: 
	 *        
	 *        \f[
	 *        AM_{1,i,s}=\frac{SR_{i,s}}{SR_{all,s}}=\frac{SR_{i,s}}{
	 *        \sum\nolimits_{i=1}^p SR_{i,s}} 
	 *        \f]
	 *        <ul>
	 *        <li>\f$SR_{i,s}\f$: The number of matched state relations (\f$SR\f$) in an intention
	 *        (\f$i\f$) as of the current state (\f$s\f$).
	 *        <li>\f$SR_{all,s}\f$: The number of matched state relations (\f$SR\f$) in all possible
	 *        intentions as of the current state (\f$s\f$).
	 *        </ul>
	 * 
	 *        This formula represents the ratio of true states that are in
	 *        intention \f$i\f$ to the sum of all of the true states in all of
	 *        intentions of interest. <br>
	 *        The variable \f$p\f$ represents the number of intentions of
	 *        interest. It is evaluated for every intention of interest at every
	 *        state.
	 * 
	 * @param _sr_i_s The number of matched state relations (\f$SR\f$) in an intention (\f$i\f$) as of the current state (\f$s\f$).
	 * @param _sr_all The number of matched state relations (\f$SR\f$) in all possible intentions as of the current state (\f$s\f$).
	 * 
	 */
	public static double computeMetricAM1(double _sr_i_s, double _sr_all) {
		double am1;
		if (_sr_all == 0)
			am1 = 0;
		else
			am1 = _sr_i_s/_sr_all;
		//System.out.println("AM1= " + am1);
		return am1;
	}

	/**
	 * @brief Compute the additive metric \f$AM_2\f$.
	 * 
	 *        \f$AM_2\f$: <i>Percentage of an intention that is complete.</i><br>
	 *        The formula for the percentage complete for intention \f$i\f$ in
	 *        state \f$s\f$ is: \f[
	 *        PercentComplete_{i,s}=\frac{SR_{i,s}}{SR_{i,total}} \f]
	 * 
	 *        We then normalize this for all intentions of interest to find the
	 *        additive metric 2 for intention <i>i</i> in state <i>s</i>. \f[
	 *        AM_{2,i,s}=\frac{PercentComplete_{i,s}}{\sum\nolimits_{i=1}^p
	 *        PercentComplete_{i,s}} \f]
	 *        
	 *@param _percentComplete_i_s Percent complete for intention (\f$i\f$) in state (\f$s\f$).
	 *@param _percent_complete_total Sum of percent complete for each intention in state (\f$s\f$).
	 */
	public static double computeMetricAM2(double _percentComplete_i_s, double _percent_complete_total) {
		double am2;
		if (_percent_complete_total == 0)
			am2 = 0;
		else
			am2 = _percentComplete_i_s / _percent_complete_total;

		return am2;
	}

	/**
	 * @brief Compute the additive metric \f$AM_3\f$.
	 * 
	 *        \f$AM_3\f$: <i>Number of productive states that have occurred
	 *        since the first productive state relation in an intention.</i><br>
	 *        The formula for the percentage complete for intention \f$i\f$ in
	 *        state \f$s\f$ is: \f[ PercentComplete_{i,s}=\frac{SR_{i,s}}{S_i}
	 *        \f]
	 * 
	 *        We then normalize this for all intentions by determining additive
	 *        metric 3 for intention \f$i\f$ in state \f$s\f$. \f[
	 *        AM_{3,i,s}=\frac{PercentProductive_{i,s}}{\sum\nolimits_{i=1}^p
	 *        PercentProductive_{i}} \f]
	 */
	public static double computeMetricAM3(double percent_productive_i_s, double percent_productive_i) {
		double am3;

		if (percent_productive_i == 0)
			am3 = 0;
		else
			am3 = percent_productive_i_s / percent_productive_i;

		return am3;
	}

	/**
	 * @brief Compute the number of true state relations (SR) in the past
	 *        \f$r\f$ states in intention \f$i\f$ as of the current state
	 *        \f$s\f$.
	 * @param _map
	 *            Map<Integer, Integer> for an intention \f$i\f$ where:
	 *            <ul>
	 *            <li>Key: The id of a state (0 for the first state, 1 for the second state, ...).
	 *            <li>Value: The number of state relations found for the intention \f$i\f$ in the
	 *            Key state.
	 *            </ul>
	 * @param _r
	 *            The last \f$r\f$ states
	 * @param _id_current_state
	 *            The current state
	 * @return The value of SR_i_r_s
	 */
	static int compute_SR_i_r_s(Map<Integer, Integer> _map, Integer _r, Integer _id_current_state) {
		int SR_i_r_s = 0;
		
		Set<Entry<Integer, Integer>> set = _map.entrySet();
		Iterator<Entry<Integer, Integer>> it = set.iterator();
		
		while (it.hasNext()) {
			Map.Entry me = (Map.Entry) it.next();

			// -- If the current state does not have _r previous state
			// -- Just retrieve what we have so far
			if (_id_current_state <= _r) {
				if ((Integer) me.getKey() <= _id_current_state) {
					SR_i_r_s += (Integer) me.getValue();
				}
			}
			// -- If the current state is > than _r
			else {
				if ((Integer) me.getKey() <= _id_current_state && (Integer) me.getKey() > (_id_current_state - _r)) {
					SR_i_r_s += (Integer) me.getValue();
				}
			}
		}
		return SR_i_r_s;
	}

	/**
	 * @brief Compute the additive metric \f$AM_4\f$.
	 * 
	 * \f$AM_4\f$ is the number of productive states that have occurred (recntly) in the past \f$r\f$ states.
	 * 
	 * The formula for \f$AM_4\f$ is:
	 * \f[
	 * AM_{4,i,s}=\frac{SR_{i,r,s}}{ \sum\nolimits_{i=1}^p SR_{i,r,s}}
	 * \f]
	 * @param sr_i_r_s The number of matched state relations (\f$SR\f$) in the past \f$r\f$ states in an intention (\f$i\f$) as of the current state (\f$s\f$).
	 * @param sum_sr_i_r_s The sum of all @a sr_i_r_s for each intention.
	 * @return
	 */
	public static double computeMetricAM4(double sr_i_r_s, double sum_sr_i_r_s) {
		double am4;

		if (sum_sr_i_r_s == 0)
			am4 = 0;
		else
			am4 = (double) sr_i_r_s/sum_sr_i_r_s;

		return am4;
	}

	public static double computeMetricMM1(int sr_i_s, int detrimental) {
		double mm1;
		
		if (sr_i_s == 0) {
			mm1=0;
		}
		else {
			mm1 = (double) (sr_i_s-detrimental)/sr_i_s;
		}
		
		return mm1;
	}

	/**
	 * @brief PercentComplete is the percentage complete for an intention in a
	 *        state.
	 * 
	 *        This formula is used by \f$AM_2\f$ and is computed as follows: \f[
	 *        PercentComplete_{i,s}=\frac{SR_{i,s}}{SR_{i,total}} \f]
	 * @param sr_i_s The Number of matched state relations (\f$SR\f$) in an intention (\f$i\f$) as of the current state (\f$s\f$).
	 * @param sr_i_total The number of states (\f$S\f$) that have occurred since observation began.
	 * @return
	 */
	public static double computePercentComplete(double sr_i_s, double sr_i_total) {
		double percentComplete;
		
		if (sr_i_total>0)
			percentComplete = (double) sr_i_s/sr_i_total;
		else 
			percentComplete = 0;
			//intention.setM_percentComplete_i_s(percentComplete);
		
		return percentComplete;
	}

	/**
	 * @brief The formula for the percent productive is used by \f$AM_3\f$ for an intention (\f$i\f$) as of state (\f$s\f$) is:
	 * 
	 *  \f[
	 *  PercentProductive_{i,s}=\frac{SR_{i,s}}{S_i}
	 *  \f]
	 * @param sr_i_s The Number of matched state relations (\f$SR\f$) in an intention (\f$i\f$) as of the current state (\f$s\f$).
	 * @param si The number of states (\f$S\f$) that have occurred since (and including) the first matched state relation in an intention (\f$i\f$).
	 * @return
	 */
	public static double computePercentProductive(double sr_i_s, double si) {
		return (sr_i_s / si);
	}

	/**
	 * @brief The overall equation that is used to determine the likelihood of
	 *        intentions is: \f[ L_i= \left[{\displaystyle\prod_{1\leq j\leq m}
	 *        MM_j}\right] \times \left[\frac{\sum\nolimits_{k=1}^n (AM_k \times
	 *        W_{AM_k})}{\sum\nolimits_{k=1}^n W_{AM_k}}\right] \times 100 \f]
	 *        Where:
	 *        <ul>
	 *        <li>\f$L_i\f$ is the likelihood of an intention \f$i\f$
	 *        <li>\f$MM_j\f$ is the multiplication metric \f$j\f$
	 *        <li>\f$AM_k\f$ is the additive metric \f$k\f$
	 *        <li>\f$W_{AM_k}\f$ is the weight of the additive metric \f$k\f$
	 *        <li>\f$m\f$ is the total number of multiplicative metrics
	 *        <li>\f$n\f$ is the total number of additive metrics
	 *        </ul>
	 * 
	 *        All metrics (whether multiplicative or additive) must contain a
	 *        value between 0 and 1, where 0 is the lowest value and 1 is the
	 *        highest value.<br>
	 *        Additive metrics (\f$AM_k\f$) along with their associated weights,
	 *        are added together and then divided by the sum of all their
	 *        weights.<br>
	 *        Weights are associated with the additive metrics to show the
	 *        relative importance of one metric over another.These weights can
	 *        contain any value greater than 0.<br>
	 *        Multiplicative metrics are significant enough in importance that
	 *        their value is multiplied in the likelihood equation to carry a
	 *        heavier effect on the overall likelihood.
	 *        
	 *@param _intention The intention for which the likelihood will be computed
	 *@param _state State
	 */
	public static double computeLikelihood(Intention _intention, int _state) {
		double likelihood;
		
		int weight_am1=Metric.get_AM1_Weight();
		int weight_am2=Metric.get_AM2_Weight();
		int weight_am3=Metric.get_AM3_Weight();
		int weight_am4=Metric.get_AM4_Weight();
		int weight_am5=Metric.get_AM5_Weight();
		
		double am1 = _intention.getM_am1();
		double am2 = _intention.getM_am2();
		double am3 = _intention.getM_am3();
		double am4 = _intention.getM_am4();
		double am5 = _intention.getM_am5();
		double mm1 = _intention.getM_mm1();
		
		likelihood= mm1 * ((am1*weight_am1 + am2*weight_am2 + am3*weight_am3 + am4*weight_am4)/(weight_am1+weight_am2+weight_am3+weight_am4))*100;
		
		// -- Display information in MainFrame
		//gui.MainFrame.updateStateRelationPanel(_intention.getIntentionName() + ": ", Color.black, gui.MainFrame.likelihoodLeft_JTextPane);
	
		Chart.createLikelihoodDataset(likelihood,_intention, _state);
		Chart.createMetricsDataset(_intention, _state);
		return likelihood;
	}

	
	private static int compute_SR_all_s(){
		int SR_all_s = 0;
		for (int i=0; i<m_intention_list.size(); i++) {
			Intention intention = m_intention_list.get(i);
			SR_all_s += intention.getNumberStateRelation();
		}
		
		return SR_all_s;
	}
	/**
	 * @brief Retrieve and compute the information required for metrics computation.
	 * 
	 * The following pieces of information are used to determine individual metrics:
	 * <ul>
	 * 	<li> \f$SR_{i,s}\f$: The number of matched state relations (\f$SR\f$) in an intention (\f$i\f$) as of the current state (\f$s\f$).
	 * 	<li> \f$SR_{i,total}\f$: The number of state relations (\f$SR\f$), whether matched or not, in an intention (\f$i\f$).
	 * 	<li> \f$SR_{all,s}\f$: The number of matched state relations (\f$SR\f$) in all possible intentions as of the current state (\f$s\f$).
	 * 	<li> \f$S_{total}\f$: The number of states (\f$S\f$) that have occurred since observation began.
	 * 	<li> \f$S_{i}\f$: The number of states (\f$S\f$) that have occurred since (and including) the first matched state relation in an intention (\f$i\f$).
	 * 	<li> \f$detrimentalSR_{i,s}\f$: The number of detrimental state relations (\f$detrimentalSR\f$) that have occurred in an intention (\f$i\f$) as of the current state (\f$s\f$).
	 * 	<li> \f$SR_{i,r,s}\f$: The number of matched state relations (\f$SR\f$) in the past \f$r\f$ states in an intention (\f$i\f$) as of the current state (\f$s\f$). In other words, 
	 * in the most recent \f$n\f$ states, how many true state relations for an intention exist?
	 * </ul>
	 * @param _states A list of states.
	 * @throws InterruptedException
	 * @throws BadLocationException
	 */
	public static void computeMetricsInformation(ArrayList<ArrayList<ArrayList<String>>> _states)
			throws InterruptedException, BadLocationException {

		// -- Get and compute data for each state
		for (int i = 0; i < _states.size(); i++) {

			//double percent_productive_i = 0;
			int sum_sr_i_r_s = 0;	
			double sum_percentComplete=0;
			double sum_percentProductive=0;

			//-- Initialize the number of detrimental state relations within the current state to 0.
			for (int k = 0; k < m_intention_list.size(); k++) {
				Intention intention = m_intention_list.get(k);
				intention.setM_found_detrimental_SR(0);
			}

			// -- state is a state among the states
			ArrayList state = (ArrayList) _states.get(i);

			// -- Put a pause timer so we can see what's going on on the screen
			// -- TODO Remove this timer once we get data in real time
			Thread.sleep(500);

			System.out.println("------------------------------- State "+(int)i +" -------------------------------");

			/*Update different panels of MainFrame to display the current state*/
			//gui.MainFrame.updateStateRelationPanel("\nState " + (i + 1) + "\n",UI.state_color, gui.MainFrame.likelihoodLeft_JTextPane);
			
			if (OptionFrame.singleKitButton.isSelected())
			{
				if (i>0)
					gui.MainFrame.updateStateRelationPanel("\n ----- State " + (i) + " -----\n",UI.m_state, gui.MainFrame.likelihood_bottomRightPane);
			}

			// -- For each state relation in the current state, match the state relation with any state relation for each intention
			for (int j = 0; j < state.size(); j++) {
				ArrayList state_relation = (ArrayList) state.get(j);
				matchStateRelationToIntention(state_relation, i);
				matchDetrimentalStateRelationToIntention(state_relation);
			}

			/*-------------------------------------------------
			--------------- Information for AM1 ---------------
			---------------------------------------------------*/
			//-- The number of matched state relations (SR) in all possible intentions as of the current state (s)
			
			int SR_all_s =compute_SR_all_s();
			
			System.out.println("SR_all_s: "+SR_all_s);
			/*
			for (int k = 0; k < m_intention_list.size(); k++) {
				Intention intention = m_intention_list.get(k);
				System.out.println(intention.getNumberStateRelation());
			}
			 */
			//System.exit(0);
			//-- Compute metrics information for each intention
			for (int k = 0; k < m_intention_list.size(); k++) {

				Intention intention = m_intention_list.get(k);

				/*-------------------------------------------------
				--------------- Information for AM2 ---------------
				---------------------------------------------------*/
				//int sr_i_s=intention.getM_SR_i_s();
				int sr_i_s=intention.getNumberStateRelation();
				int sr_i_total=intention.getM_SR_Total();

				double percentComplete = computePercentComplete(sr_i_s,sr_i_total);
				
				//System.out.println("sr_i_s = "+sr_i_s);
				//System.out.println("sr_i_total = "+sr_i_total);
				intention.setM_percentComplete_i_s(percentComplete);
				sum_percentComplete += percentComplete;


				/*-------------------------------------------------
				--------------- Information for AM3 ---------------
				---------------------------------------------------*/
				//-- Compute Si: the number of states that have occurred since (and including) 
				//-- the first matched state relation in an intention
				int si = intention.getM_Si();

				//-- If si=0 and SR,i,s>0 then si=1
				if (si==0) {
					if (intention.getNumberStateRelation() > 0)
						si = 1;
					//-- If si>0, we only increment si by 1 for each state
				} else if (si > 0)
					si += 1;
				//-- set si for the current intention
				//intention.setM_Si(si);


				double percentProductive;
				if (si>0)
					percentProductive = (double) sr_i_s/si;
				else
					percentProductive = 0;

				sum_percentProductive += percentProductive;
				intention.setM_percentProductive_i_s(percentProductive);


				/*-------------------------------------------------
				--------------- Information for AM4 ---------------
				---------------------------------------------------*/
				Map<Integer, Integer> _map = intention.getM_map_SRirs();
				_map.put((int) i,intention.getNumberStateRelation());
				intention.setM_map_SRirs(_map);

				//-- Compute the number of true state relations in the past r=5 states
				//-- Set the value for the current intention
				intention.setM_SR_i_r_s(compute_SR_i_r_s(_map, 5, (int) i));
				sum_sr_i_r_s +=compute_SR_i_r_s(_map, 5, (int) i);


				/*-------------------------------------------------
				--------------- Information for MM1 ---------------
				---------------------------------------------------*/

				// -- Get the number of detrimental state relations in the current state
				//int number_detrimental_SR = intention.getM_found_detrimental_SR();

			}

			//-- Computing metrics using metrics information previously gathered
			for (int k = 0; k < m_intention_list.size(); k++) {
				
				
				Intention intention = m_intention_list.get(k);
				
				//-- Compute the value of AM1
				double am1 = computeMetricAM1(intention.getNumberStateRelation(),SR_all_s);
				intention.setM_am1(am1);
				System.out.println("AM1 for "+intention.getIntentionName()+"("+intention.getNumberStateRelation()+","+SR_all_s+") = "+am1);

				//-- Compute the value of AM2
				double am2 = computeMetricAM2(intention.getM_percentComplete_i_s(),sum_percentComplete);
				intention.setM_am2(am2);
				System.out.println("AM2 for "+intention.getIntentionName()+"("+intention.getM_percentComplete_i_s()+","+sum_percentComplete+") = "+am2);

				//-- Compute the value of AM3
				double am3 = computeMetricAM3(intention.getM_percentProductive_i_s(),sum_percentProductive);
				intention.setM_am3(am3);
				System.out.println("AM3 for "+intention.getIntentionName()+"("+intention.getM_percentProductive_i_s()+","+sum_percentProductive+") = "+am3);

				//-- Compute the value of AM4
				double am4 = computeMetricAM4(intention.getM_SR_i_r_s(),sum_sr_i_r_s);
				intention.setM_am4(am4);
				System.out.println("AM4 for "+intention.getIntentionName()+"("+intention.getM_percentProductive_i_s()+","+sum_sr_i_r_s+") = "+am4);

				//-- Compute the value of MM1
				double mm1 = computeMetricMM1(intention.getNumberStateRelation(),intention.getM_found_detrimental_SR());
				intention.setM_mm1(mm1);
				System.out.println("MM1 for "+intention.getIntentionName()+"("+intention.getNumberStateRelation()+","+intention.getM_found_detrimental_SR()+") = "+mm1);

				//-- Compute the value for the likelihood
				System.out.println("Likelihood for "+intention.getIntentionName()+"="+computeLikelihood(intention, (Integer) (i + 1)));
				System.out.println("\n");

			}
			System.out.println("\n\n");

		}
	}

	public Set<OWLClassExpression> getIndividualClass(
			OWLNamedIndividual individual) {
		// System.out.println(cleanIRI(individual.getTypes(ontology).toString()));
		return individual.getTypes(m_ontology);
	}

	public static String getIndividualClassString(OWLNamedIndividual individual) {
		// System.out.println(cleanIRI(individual.getTypes(ontology).toString()));
		return (cleanIRI(individual.getTypes(m_ontology).toString()));
	}

	public static String getIndividualClassString(OWLIndividual individual) {
		// System.out.println(cleanIRI(individual.getTypes(ontology).toString()));
		return (cleanIRI(individual.getTypes(m_ontology).toString()));
	}

	/**
	 * \brief Simple getter. \return manager
	 */
	public OWLOntologyManager getManager() {
		return this.m_manager;
	}

	/**
	 * \brief Simple getter. \return ontology
	 */
	public OWLOntology getOntology() {
		return m_ontology;
	}

	/**
	 * \brief Simple getter. \return path
	 */
	public String getPath() {
		return m_path;
	}

	/**
	 * Return The class of the reference object for a given instance of
	 * predicate
	 * 
	 * @param individual
	 *            An instance of predicate
	 * @return The class of the reference object
	 */
	private static String getReferenceObjectClass(OWLNamedIndividual individual) {
		String sr = null;

		if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("Kit-Location-Worktable"))
			sr = "WorkTable";
		else if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("Kit-Location-Lbwk"))
			sr = "KitTray";
		else if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("On-Worktable-Kit"))
			sr = "WorkTable";
		else if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("Part-Type-Location-Kit"))
			sr = "KitTray";
		else if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("Worktable-Empty"))
			sr = "WorkTable";
		return sr;
	}

	/**
	 * \brief Simple getter. \return SEPARATOR
	 */
	public static char getSeparator() {
		return m_SEPARATOR;
	}

	/**
	 * Return The state relation for a given instance of predicate
	 * 
	 * @param individual
	 *            An instance of predicate
	 * @return The state relation
	 */
	private static String getStateRelation(OWLNamedIndividual individual) {
		String sr = null;

		if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("Kit-Location-Worktable"))
			sr = "OnTopWithContact";
		else if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("Kit-Location-Lbwk"))
			sr = "PartiallyIn";
		else if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("On-Worktable-Kit"))
			sr = "OnTopWithContact";
		else if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("Part-Type-Location-Kit"))
			sr = "PartiallyIn";
		else if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("Worktable-Empty"))
			sr = "OnTopWithContact";

		return sr;
	}

	/**
	 * Return The class of the target object for a given instance of predicate
	 * 
	 * @param individual
	 *            An instance of predicate
	 * @return The class of the target object
	 */
	private static String getTargetObjectClass(OWLNamedIndividual individual) {
		String sr = null;

		if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("Kit-Location-Worktable"))
			sr = "KitTray";
		else if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("Kit-Location-Lbwk"))
			sr = "LargeBoxWithEmptyKitTrays";
		else if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("On-Worktable-Kit"))
			sr = "KitTray";
		else if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("Part-Type-Location-Kit"))
			sr = "StockKeepingUnit";
		else if (cleanIRI(individual.getTypes(m_ontology).toString())
				.equalsIgnoreCase("Worktable-Empty"))
			sr = "";

		return sr;
	}

	public NodeSet<OWLClass> getSubclasses(String myClassName) {
		OWLDataFactory factory = this.m_manager.getOWLDataFactory();
		// OWLClass myClass =
		// factory.getOWLClass(IRI.create(ontology_IRI.concat("#Intention")));
		OWLClass myClass = factory.getOWLClass(IRI.create(m_ontology_IRI
				.concat("#" + myClassName)));

		ConsoleProgressMonitor progressMonitor = new ConsoleProgressMonitor();
		OWLReasonerConfiguration config = new SimpleConfiguration(
				progressMonitor);

		NodeSet<OWLClass> subclasses_of_myClass = this.m_reasoner
				.getSubClasses(myClass, true);

		return subclasses_of_myClass;
	}

	private static boolean hasProperty(OWLOntologyManager man,
			OWLReasoner reasoner, OWLClass cls, OWLObjectPropertyExpression prop) {
		// To test whether the instances of a class must have a property we
		// create a some values from restriction and then ask for the
		// satisfiability of the class intersected with the complement of this
		// some values from restriction. If the intersection is satisfiable then
		// the instances of the class don't have to have the property,
		// otherwise, they do.
		OWLDataFactory dataFactory = man.getOWLDataFactory();
		OWLClassExpression restriction = dataFactory
				.getOWLObjectSomeValuesFrom(prop, dataFactory.getOWLThing());
		// Now we see if the intersection of the class and the complement of
		// this restriction is satisfiable
		OWLClassExpression complement = dataFactory
				.getOWLObjectComplementOf(restriction);
		OWLClassExpression intersection = dataFactory
				.getOWLObjectIntersectionOf(cls, complement);
		return !reasoner.isSatisfiable(intersection);
	}

	public void initializeList() {
		this.m_intention_list = new ArrayList<Intention>();
		//this.m_orderedlist_orderingconstruct_list = new HashMap<OWLNamedIndividual, ArrayList<OWLNamedIndividual>>();
	}

	private static ArrayList<String> input(String state_relation,
			String target_object, String target_class, String reference_object,
			String reference_class) {
		ArrayList list = new ArrayList();
		list.add(state_relation);
		list.add(target_object);
		list.add(target_class);
		list.add(reference_object);
		list.add(reference_class);

		return list;
	}

	/**
	 * \brief Load the ontology from a file.
	 */
	public void loadFromFile() {
		File file = new File(this.m_path);
		try {
			// this.ontology = manager.loadOntologyFromOntologyDocument(file);
			// begin merge
			m_manager.loadOntologyFromOntologyDocument(file).getImports();
			OWLOntologyMerger merger = new OWLOntologyMerger(m_manager);
			m_ontology = merger.createMergedOntology(m_manager, null);
			// end merge
			System.out.println("Loaded ontology: " + this.m_ontology);

		} catch (OWLOntologyCreationException e) {
			e.printStackTrace();
			JOptionPane.showMessageDialog(null, e.getStackTrace());

		}
	}

	public void loadOntologyFromPath(String myPath)
			throws MalformedURLException, OWLException {
		//myPath="/home/zeid/workspace/IntentionRecognition/etc/kittingInstances_ir.owl";
		//myPath=OptionFrame.m_instance_txt_field.getText().toString();
		
		//myPath = myPath.replace("\\", "\\\\");
		
		//InputStream inputStream = Ontology.class.getClassLoader().getResourceAsStream("kittingInstances_ir.owl");
		//z//File file = new File("../kittingInstances_ir.owl");
		File file = new File("kittingInstances_ir.owl");
		
		OWLOntology myOntology;
		myOntology = m_manager.loadOntologyFromOntologyDocument(file);
		setOntology(myOntology);

		System.out.println("Loaded ontology: " + myOntology);
		setOntology(myOntology);
	}

	/**
	 * @brief Check for each intention if @a _state_relation is a detrimental
	 *        state relation.
	 * @param _state_relation
	 *            state relation of the form
	 *            "State Relation Name","Target Object"
	 *            ,"OWL CLass of the target object"
	 *            ,"Reference object","OWL CLass of the reference object"
	 */
	public static void matchDetrimentalStateRelationToIntention(
			ArrayList _state_relation) {

		String state_relation_name = _state_relation.get(0).toString();
		String target_object = _state_relation.get(1).toString();
		String target_object_class = _state_relation.get(2).toString();
		String reference_object = _state_relation.get(3).toString();
		String reference_object_class = _state_relation.get(4).toString();

		// -- For each intention
		for (int i = 0; i < m_intention_list.size(); i++) {
			Intention intention = m_intention_list.get(i);

			// -- Get the list of detrimental state relations
			ArrayList<Exist> detrimental_list = intention.getDetrimentalList();
			//System.out.println(intention.getIntentionName()+"---- >"+detrimental_list.size());
			
			if (detrimental_list.size() > 0) {

				// -- Get Exist objects in detrimental_list
				for (int j = 0; j < detrimental_list.size(); j++) {
					Exist exist = detrimental_list.get(j);

					// -- Get the individual for Exist
					OWLIndividual exist_individual = exist.getIndividual();
					// -- Get predicate from Exist
					Predicate predicate_exist = exist.getPredicate();
					// -- Get the predicate OWLIndividual
					OWLIndividual predicate_exist_individual = predicate_exist
							.getIndividual();
					// -- Get the predicate ReferenceObject
					OWLIndividual predicate_reference_object = predicate_exist
							.getReference();
					// -- Get the predicate TargetObject
					OWLIndividual predicate_target_object = predicate_exist
							.getTarget();
					// -- Get the predicate StateRelation
					String predicate_state_relation = predicate_exist
							.getStateRelation();
					// -- Get the Class for ReferenceObject
					String predicate_reference_class = predicate_exist
							.getReferenceObjectClass();
					// -- Get the Class for TargetObject
					String predicate_target_class = predicate_exist
							.getTargetObjectClass();

					if (cleanIRI(predicate_target_object.getTypes(m_ontology)).toString().equalsIgnoreCase("StockKeepingUnit")) {
						// -- Check if the input read matches this
						// predicate
						//System.out.println("predicate_state_relation "+ predicate_state_relation);
						//System.out.println("state_relation_name "+ state_relation_name+"\n");
						
						if (predicate_state_relation.equalsIgnoreCase(state_relation_name)) {
							//System.out.println("predicate_target_object "+ cleanIRI(predicate_target_object).toString());
							//System.out.println("target_object_class "+ target_object_class+"\n");
							if (cleanIRI(predicate_target_object).toString().equalsIgnoreCase(target_object_class)) {
								if (predicate_reference_class.equalsIgnoreCase(reference_object_class)) {
									int tmp_number = intention.getM_found_detrimental_SR();
									intention.setM_found_detrimental_SR(tmp_number+1);
									//System.out.println("Type: Found 1 detrimental state for "+intention.getIntentionName());
								}

							}
						}
					}
				}
			}
		}
	}

	
	private static Color getPartColor(String _string){
		Color part_color = Color.black;
		if (_string.matches(".*\\b"+ "red" + "\\b.*"))
			part_color=Color.red;
		else if (_string.matches(".*\\b"+ "blue" + "\\b.*"))
			part_color=Color.blue;
		else if (_string.matches(".*\\b"+ "green" + "\\b.*"))
			part_color=UI.m_part_green;
		else if (_string.matches(".*\\b"+ "yellow" + "\\b.*"))
			part_color=UI.m_part_yellow;
		else if (_string.matches(".*\\b"+ "orange" + "\\b.*"))
			part_color=UI.m_part_orange;
		
		return part_color;
	}
	
	private static String getPartType(String _string){
		String part_color = null;
		
		if (_string.matches(".*\\b"+ "red" + "\\b.*"))
			part_color = "red";
		else if (_string.matches(".*\\b"+ "blue" + "\\b.*"))
			part_color = "blue";
		else if (_string.matches(".*\\b"+ "green" + "\\b.*"))
			part_color = "green";
		else if (_string.matches(".*\\b"+ "yellow" + "\\b.*"))
			part_color = "yellow";
		else if (_string.matches(".*\\b"+ "orange" + "\\b.*"))
			part_color = "orange";
		
		return part_color;
	}
	
	private static String getStringHead(String _string){
		String head=null;
		if (_string.matches(".*\\b"+ "red" + "\\b.*")){
			head=_string.substring(0,_string.indexOf("red"));
		}
		else if (_string.matches(".*\\b"+ "blue" + "\\b.*")){
			head=_string.substring(0,_string.indexOf("blue"));
		}
		else if (_string.matches(".*\\b"+ "green" + "\\b.*")){
			head=_string.substring(0,_string.indexOf("green"));
		}
		else if (_string.matches(".*\\b"+ "yellow" + "\\b.*")){
			head=_string.substring(0,_string.indexOf("yellow"));
		}
		else if (_string.matches(".*\\b"+ "orange" + "\\b.*")){
			head=_string.substring(0,_string.indexOf("orange"));
		}			
		return head;
	}
	
	
	private static String getStringTail(String _string){
		String tail=null;
		if (_string.matches(".*\\b"+ "red" + "\\b.*")){
			tail=_string.substring(_string.indexOf("red")+3);
		}
		else if (_string.matches(".*\\b"+ "blue" + "\\b.*")){
			tail=_string.substring(_string.indexOf("blue")+4);
		}
		else if (_string.matches(".*\\b"+ "green" + "\\b.*")){
			tail=_string.substring(_string.indexOf("green")+5);
		}
		else if (_string.matches(".*\\b"+ "yellow" + "\\b.*")){
			tail=_string.substring(_string.indexOf("yellow")+6);
		}
		else if (_string.matches(".*\\b"+ "orange" + "\\b.*")){
			tail=_string.substring(_string.indexOf("orange")+6);
		}			
		return tail;	
	}
	
	/**
	 * @brief Display the current state relation in MainFrame
	 * @param _state_relation The state relation to display
	 */
	public static void updateMainFrame(ArrayList _state_relation, int num){
		String state_relation_name = _state_relation.get(0).toString();
		String target_object = _state_relation.get(1).toString();
		String target_object_class = _state_relation.get(2).toString();
		String reference_object = _state_relation.get(3).toString();
		String reference_object_class = _state_relation.get(4).toString();
		// -- build the message we want to display in
		// fancygui.SuperDemo.statePane
		String infolist = state_relation_name + "," + target_object + ","
				+ target_object_class + "," + reference_object + ","
				+ reference_object_class;

		//System.out.println("+++++ " + infolist + " +++++");

		// -- Update MainFrame to display infolist
		gui.MainFrame.updateStateRelationPanel(infolist + "\n", Color.black, gui.MainFrame.likelihood_bottomRightPane);
		
		//String plan_path = "../kits/"+m_kitToBuild+"/"+m_planToBuild+".txt";  z
		String plan_path = "kits/"+m_kitToBuild+"/"+m_planToBuild+".txt";
		String[] textData = null;
		
		FileOperator op = new FileOperator();
		
		try {
			textData = op.openFile(plan_path);
		} catch (IOException e) {
			e.printStackTrace();
		}
		//-- Displaying what is in the plan file.
		//-- We remove the number of the state, the period, and the empty space after the period (e.g., "1. ")
		String description_state_relation = textData[num-1].substring(textData[num-1].indexOf(".")+2);
		//Color part_color = getFontColor(description_state_relation);
		String head = getStringHead(description_state_relation);
		String tail = getStringTail(description_state_relation);
		String part = getPartType(description_state_relation);
		//gui.MainFrame.updateStateRelationPanel(textData[num-1].substring(textData[num-1].indexOf(".")+2) + "\n", Color.BLUE, gui.MainFrame.likelihood_bottomRightPane);
		gui.MainFrame.updateStateRelationPanel(head + " ", Color.BLACK, gui.MainFrame.likelihood_bottomRightPane);
		gui.MainFrame.updateStateRelationPanel(part + " ", getPartColor(part), gui.MainFrame.likelihood_bottomRightPane);
		gui.MainFrame.updateStateRelationPanel(tail+ "\n", Color.BLACK, gui.MainFrame.likelihood_bottomRightPane);
	}
	
	/**
	 * @brief Check for each intention if the state relation @a _state_relation
	 *        matches any of the intention state relations
	 * @param _state_relation
	 *            A state relation of the form
	 *            "State Relation Name","Target Object"
	 *            ,"OWL CLass of the target object"
	 *            ,"Reference object","OWL CLass of the reference object"
	 * @throws BadLocationException
	 */
	public static void matchStateRelationToIntention(ArrayList _state_relation, int num)
			throws BadLocationException {
		//-- This number is incremented each time a state relation is found in the current intention
		int number;
		
		String state_relation_name = _state_relation.get(0).toString();
		String target_object_class = _state_relation.get(2).toString();
		String reference_object_class = _state_relation.get(4).toString();		
		
		//-- Display _state_relation in MainFrame
		if (OptionFrame.singleKitButton.isSelected()){
			if (num>0)
				updateMainFrame(_state_relation, num);
		}

		// -- Parse intention_list
		for (int i = 0; i < m_intention_list.size(); i++) {
			//-- This variable is incremented each time a state relation is found in the current intention
			number = 0;
			//-- Get each intention
			Intention intention = m_intention_list.get(i);
			
			// -- Get the intention OWL individual
			OWLIndividual intention_individual = intention.getIndividual();

			// -- How many state relations are part of the current Intention
			int intention_number_state_relation = intention.getNumberStateRelation();
			//System.out.println("+++ intention_number_state_relation +++ "+intention_number_state_relation);

			// -------------------------------------------------------------//
			// ------- Read ordering constructs for each intention ------- //
			// -------------------------------------------------------------//

			// -- Get OrderedList
			OrderedList orderedlist = intention.getOrderedList();
			OWLIndividual orderedlist_individual = orderedlist.getIndividual();

			// -- Get AnyOrder from OrderedList
			AnyOrder anyorder = orderedlist.getAnyOrder();
			OWLIndividual anyorder_individual = anyorder.getIndividual();

			// -- Get Exist from OrderedList
			Exist exist = orderedlist.getExist();

			int anyorder_position = anyorder.getPosition();
			int exist_position = exist.getPosition();

			
			// -- Check the first element in orderedlist
			if (exist_position < anyorder_position) {
				// -- If occurrence of exist > 0 it means that the predicate in
				// exist has not been true yet
				if (exist.getOccurrence() > 0) {

					// -- Get the individual for Exist
					OWLIndividual exist_individual = exist.getIndividual();
					// -- Get predicate from Exist
					Predicate predicate_exist = exist.getPredicate();
					// -- Get the predicate OWLIndividual
					OWLIndividual predicate_exist_individual = predicate_exist
							.getIndividual();
					// -- Get the predicate ReferenceObject
					OWLIndividual predicate_reference_object = predicate_exist
							.getReference();
					// -- Get the predicate TargetObject
					OWLIndividual predicate_target_object = predicate_exist
							.getTarget();
					// -- Get the predicate StateRelation
					String predicate_state_relation = predicate_exist
							.getStateRelation();
					// -- Get the Class for ReferenceObject
					String predicate_reference_class = predicate_exist
							.getReferenceObjectClass();
					// -- Get the Class for TargetObject
					String predicate_target_class = predicate_exist
							.getTargetObjectClass();

					// -- Check if the input read matches this predicate
					if (predicate_state_relation
							.equalsIgnoreCase(state_relation_name)) {
						if (predicate_reference_class
								.equalsIgnoreCase(reference_object_class)) {
							if (predicate_target_class
									.equalsIgnoreCase(target_object_class)) {
								// -- Increment the number of state relation
								// found for the current Intention
								//-- TODO comment out the following line when we read real data
								//intention_number_state_relation++;
								intention.setNumberStateRelation(intention_number_state_relation);
								// -- Decrement the number of occurrence for the
								// current Exist
								exist.setOccurrence((exist.getOccurrence()) - 1);
								//-- TODO comment out the following line when we read real data
								//number++;
							}
						}
					}
				}
				// -- If Exist has been satisfied, lets move to AnyOrder
				else {
					// -- Get the list of Count from AnyOrder
					ArrayList<Count> count_list = anyorder.getCountList();

					for (int j = 0; j < count_list.size(); j++) {
						Count count = count_list.get(j);
						// -- Occurrence for Count
						int count_occurence = count.getOccurence();
							OWLIndividual count_individual = count
									.getIndividual();

							Predicate predicate_count = count.getPredicate();
							OWLIndividual predicate_individual = predicate_count
									.getIndividual();
							// -- Get ReferenceObject for the predicate
							OWLIndividual predicate_count_reference_object = predicate_count
									.getReference();
							// -- Get TargetObject for the predicate
							OWLIndividual predicate_count_target_object = predicate_count
									.getTarget();
							// -- Get the StateRelation
							String predicate_count_state_relation = predicate_count
									.getStateRelation();
							// -- Get the Class for ReferenceObject
							String predicate_count_reference_class = predicate_count
									.getReferenceObjectClass();
							// -- Get the Class for TargetObject
							String predicate_count_target_class = predicate_count
									.getTargetObjectClass();

							// System.out.println(cleanIRI(predicate_count_target_object.getTypes(ontology)).toString());
							if (cleanIRI(predicate_count_target_object.getTypes(m_ontology)).toString().equalsIgnoreCase("StockKeepingUnit")) {
								// -- Check if the input read matches this
								// predicate
								if (predicate_count_state_relation.equalsIgnoreCase(state_relation_name)) {
									if (cleanIRI(predicate_count_target_object).toString().equalsIgnoreCase(target_object_class)) {
										if (predicate_count_reference_class.equalsIgnoreCase(reference_object_class)) {
											if (count_occurence > 0) {
												intention_number_state_relation++;
												intention.setNumberStateRelation(intention_number_state_relation);
												// -- Decrement the number of
												// occurrence for the current Count
												count.setOccurrence(count_occurence - 1);
												number++;
											}else if (count_occurence == 0) {
												//System.out.println("Number: Found 1 detrimental state for "+intention.getIntentionName());
												int tmp_number = intention.getM_found_detrimental_SR();
												intention.setM_found_detrimental_SR(tmp_number+1);

											}
										}

									}
								}
							}
					}
				}
			} else {
				System.out.println("AnyOrder comes before Exist?");
				System.out.println("Check your Ontology Man !!");
			}
			//-- Set the number of state relations found for the current intention in the current state
			intention.setM_SR_i_s(number);
			// System.out.println("Intention "+intention.getIntentionName()+" in current state:"+number);
		}
	}

	/**
	 * @brief Read m_intention_list and re-arrange the list using a number for each intention.
	 * 
	 * The bubble sort algorithm is used to sort m_intention_list.
	 * 
	 * Among the 5 intentions in the ontology, numbers are associated to each intention in the following way:
	 * <ul>
	 * <li> a4b3c3 = 1
	 * <li> a4b4c2 = 2
	 * <li> a2b3c5 = 3
	 * <li> a4b2c2d1 = 4
	 * <li> a2b3c3d1e1 = 5
	 * </ul>
	 */
public void sortIntentionList(){	
	for (int i = 0; i < m_intention_list.size(); i++) {
		Intention intention = m_intention_list.get(i);
		//-- Get the name of the intention
		String intention_name = intention.getIntentionName();
		
		//-- Assign a number for each intention
		if (intention_name.equals("a4b3c3"))
			intention.setM_intention_number(1);
		
		if (intention_name.equals("a4b4c2"))
			intention.setM_intention_number(2);
		
		if (intention_name.equals("a2b3c5"))
			intention.setM_intention_number(3);
		
		if (intention_name.equals("a4b3c2d1"))
			intention.setM_intention_number(4);
		
		if (intention_name.equals("a2b3c3d1e1"))
			intention.setM_intention_number(5);
	}
	
	//-- Fill out tmp_list based on the number associated to each intention
	//-- Intention number 1 is put at the first place in tmp_list
	//-- Intention number 2 is put at the second place in tmp_list
	//-- ...
	
	//Bubble Sort
	Boolean bDone = false;
	
	while (!bDone)
	{
		bDone = true; // assume that the array is currently sorted

        for (int i=0; i != m_intention_list.size() - 1; ++i) // for every element in m_intention_list (notice: this can be a bit optimized, see http://en.wikipedia.org/wiki/Bubblesort#Optimizing_bubble_sort)
        {
            if ( m_intention_list.get(i).getM_intention_number() > m_intention_list.get(i+1).getM_intention_number() ) // compare the current element with the following one
            {
                // They are in the wrong order, swap them
                Intention tmp_intention = m_intention_list.get(i);
                m_intention_list.set(i,m_intention_list.get(i+1));
                m_intention_list.set(i+1,tmp_intention);

                bDone = false; // since we performed a swap, the array needs to be checked to see if it is sorted
                               // this is done in the next iteration of the while
            }
        }
	}
}
	/**
	 * Parse the class @a myClass and store data in arrays (HashMap and
	 * ArrayList). A user interface is run in order to display data in real
	 * time.
	 * 
	 * @param myClass
	 *            Class to be parsed
	 * @throws InterruptedException
	 * @throws InvocationTargetException
	 * @throws IOException 
	 */
	public void parseIntention(NodeSet<OWLClass> myClass)
			throws InterruptedException, InvocationTargetException, IOException {

		ArrayList<ArrayList<ArrayList<String>>> state = new ArrayList();
		


		//-- SINGLE KIT CHOSEN
		if (OptionFrame.singleKitButton.isSelected())
		{
			buildIntentionList(myClass);
			sortIntentionList();
			
			for (int i = 0; i < m_intention_list.size(); i++) {
				Intention intention = m_intention_list.get(i);
				intention.setM_Si(0);
			}
			
			EventQueue.invokeLater(new Runnable() {
				@Override
				public void run() {
					JTree metricTree = buildIntentionMetricsTree();
					JTree likelihoodTree = buildIntentionTree();
					MainFrame mainframe = new MainFrame("Intention Recognition", metricTree, likelihoodTree);
					mainframe.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
					mainframe.pack();
					RefineryUtilities.centerFrameOnScreen(mainframe);
					mainframe.setVisible(true);
				}
			});

			//String plan_path = "../kits/"+m_kitToBuild+"/"+m_planToBuild+".txt"; zeid
			String plan_path = "kits/"+m_kitToBuild+"/"+m_planToBuild+".txt";
			state = buildStates(plan_path);
			try {
				// -- Find the state relations associated to a state
				computeMetricsInformation(state);
			} catch (BadLocationException e) {
				e.printStackTrace();
			}	
		}
		//-- MULTIPLE KITS CHOSEN
		else{
			String file_path_ = OptionFrame.m_save_file_txt_field.getText().toString();
			
			file_path_=file_path_.replace("\\", "\\\\");
			FileWriter writer = new FileWriter(file_path_);
	
			//-- Get all the kits that can be built from the etc directory
			ArrayList<String> tmp_kitList = OptionFrame.getKitList();
			//-- Let's sort this list (kit 1, 2, ...)
			List<String> kitList = tmp_kitList.subList(0, tmp_kitList.size());
			Collections.sort(kitList);

			
			m_progress_bar = new ProgressBar();
			m_progress_bar.setBackground(Color.white);
			m_progress_bar.setForeground(UI.chartLeftPaneColor);
			m_progress_bar.setToolTipText("Data being generated, please wait...");
			m_progress_frame = new JFrame("Generating Data");
			m_progress_frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			m_progress_frame.setContentPane(m_progress_bar);
			final JLabel label = new JLabel("0%");
			m_progress_frame.add(label);
			m_progress_frame.setSize(new Dimension(300,70));
			m_progress_frame.setPreferredSize(new Dimension(300,70));
			Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
			m_progress_frame.setLocation(dim.width/2-m_progress_frame.getSize().width/2, dim.height/2-m_progress_frame.getSize().height/2);
			m_progress_frame.pack();
			m_progress_frame.setVisible(true);

		    
		   
			
		    // run a loop to demonstrate raising
		    //for (int i = MY_MINIMUM; i <= MY_MAXIMUM; i++) {}
		    
			for (int i=0; i<kitList.size(); i++)
			{	
			      
			    
				//String kit_path = "../kits/"+kitList.get(i)+"/"; zeid
				String kit_path = "kits/"+kitList.get(i)+"/";

				//System.out.println(kitList.get(i));
				File plan_directory = new File(kit_path);  

				File[] subFiles = plan_directory.listFiles(new FileFilter() {  
					public boolean accept(File pathname) {  
						return pathname.isFile();  
					}  
				}); 
				ArrayList<String> tmpList = new ArrayList<String>();

				for (File subFile : subFiles) {  
					String path = subFile.getPath();

					String idStr = path.substring(path.lastIndexOf('/') + 1);
					String cleaned_idStr = idStr.substring(0, idStr.lastIndexOf('.')).toString();
					tmpList.add(cleaned_idStr);
				} 

				//-- Let's sort tmpList
				List<String> planList = tmpList.subList(0, tmpList.size());
				Collections.sort(planList);


				for (int j=0; j<planList.size(); j++)
				{
					m_intention_list.clear();
					
					// -- Build a list for each intention
					buildIntentionList(myClass);
					sortIntentionList();

					// -- Set Si=0 for all intentions since we haven't started to read
					// -- State relations yet 
					for (int k = 0; k < m_intention_list.size(); k++) {
						Intention intention = m_intention_list.get(k);
						intention.setM_Si(0);
					}
			
					
					String plan_path =planList.get(j)+".txt";
					//System.out.println(plan_path);
					//System.exit(0);
					state = buildStates(plan_path);
					try {
						
						// -- Find the state relations associated to a state
						computeMetricsInformation(state);
						//-- Write all data into a file
						FileOperator.saveAllKitsData(file_path_,writer,kitList.get(i),planList.get(j));
					} catch (BadLocationException e) {
						e.printStackTrace();
					}	
				}
				
				//-- Update the progress bar
				final int percent = (i+1)*(100/m_intention_list.size());
			      try {
			        SwingUtilities.invokeLater(new Runnable() {
			          public void run() {
			            m_progress_bar.updateBar(percent);
			            
			            //-- convert int to string
			            StringBuilder sb = new StringBuilder();
			            sb.append("");
			            sb.append(percent);
			            String strI = sb.toString();
			            label.setText(strI+"%");
			          }
			        });
			        java.lang.Thread.sleep(500);
			      } catch (InterruptedException e) {
			        ;
			      }
			}
			if (writer != null) {
				try {
					writer.close();
				} catch (IOException e) {
					System.err.println(e);
					System.exit(0);
				}
			}
			showDialogBox();
		}
	}

	public void showDialogBox(){
		JOptionPane.showMessageDialog(OptionFrame.m_frame, "Data successfully created in "+OptionFrame.m_save_file_txt_field.getText(),"Data Generation",JOptionPane.INFORMATION_MESSAGE);
        OptionFrame.m_frame.dispatchEvent(new WindowEvent(OptionFrame.m_frame, WindowEvent.WINDOW_CLOSING));
        m_progress_bar.setVisible(false);
        m_progress_frame.dispatchEvent(new WindowEvent(m_progress_frame, WindowEvent.WINDOW_CLOSING));
	}
	
	
	public JTree buildIntentionTree() {
		DefaultMutableTreeNode top = new DefaultMutableTreeNode("Intentions");
		DefaultMutableTreeNode intentionName = null;
        
		for (int i = 0; i < m_intention_list.size(); i++) {
			Intention intention = m_intention_list.get(i);
			
			String intention_name = intention.getIntentionName();
			intentionName = new DefaultMutableTreeNode(intention_name);
	        top.add(intentionName);
		}
		
		//m_tree = new JTree(top);
		JTree tree = new JTree(top);
		return tree;
		//gui.MainFrame.updateTree(m_tree);
	}
	
	public JTree buildIntentionMetricsTree() {
		DefaultMutableTreeNode top = new DefaultMutableTreeNode("Intentions");
		DefaultMutableTreeNode intentionName = null;
        DefaultMutableTreeNode intentionMetricAM1 = null;
        DefaultMutableTreeNode intentionMetricAM2 = null;
        DefaultMutableTreeNode intentionMetricAM3 = null;
        DefaultMutableTreeNode intentionMetricAM4 = null;
        DefaultMutableTreeNode intentionMetricMM1 = null;
        
		for (int i = 0; i < m_intention_list.size(); i++) {
			Intention intention = m_intention_list.get(i);
			
			String intention_name = intention.getIntentionName();
			
			intentionName = new DefaultMutableTreeNode(intention_name);
	        top.add(intentionName);
	 
	        intentionMetricAM1 = new DefaultMutableTreeNode("AM1");
	        intentionName.add(intentionMetricAM1);
	        intentionMetricAM2 = new DefaultMutableTreeNode("AM2");
	        intentionName.add(intentionMetricAM2);
	        intentionMetricAM3 = new DefaultMutableTreeNode("AM3");
	        intentionName.add(intentionMetricAM3);
	        intentionMetricAM4 = new DefaultMutableTreeNode("AM4");
	        intentionName.add(intentionMetricAM4);
	        intentionMetricMM1 = new DefaultMutableTreeNode("MM1");
	        intentionName.add(intentionMetricMM1);
		}
		
		//m_tree = new JTree(top);
		JTree tree = new JTree(top);
		return tree;
		//gui.MainFrame.updateTree(m_tree);
	}
	/**
	 * @brief Print the properties that an instance has to have.
	 * 
	 * @param man
	 *            The manager
	 * @param ont
	 *            The ontology
	 * @param reasoner
	 *            The reasoner
	 * @param cls
	 *            The class for which we need to check the properties
	 */
	private static void printProperties(OWLOntologyManager man,
			OWLOntology ont, OWLReasoner reasoner, OWLClass cls) {
		if (!ont.containsClassInSignature(cls.getIRI())) {
			throw new RuntimeException("Class not in signature of the ontology");
		}
		// Note that the following code could be optimized... if we find that
		// instances of the specified class do not have a property, then we
		// don't need to check the sub properties of this property
		System.out.println("Properties of " + cls);
		for (OWLObjectPropertyExpression prop : ont
				.getObjectPropertiesInSignature()) {
			boolean sat = hasProperty(man, reasoner, cls, prop);
			if (sat) {
				System.out.println("Instances of " + cls
						+ " necessarily have the property " + prop);
			}
		}
	}

	/**
	 * @brief Read the intentions previously stored.
	 * 
	 *        Display intention individuals.
	 */

	private void readIntentionList() {
		//System.out.println(m_intention_list.size());
		for (int i = 0; i < m_intention_list.size(); i++) {
			OWLIndividual intention_individual = m_intention_list.get(i)
					.getIndividual();
			OrderedList orderedlist = m_intention_list.get(i).getOrderedList();
			OWLIndividual orderedlist_individual = orderedlist.getIndividual();
			AnyOrder anyorder = orderedlist.getAnyOrder();
			OWLIndividual anyorder_individual = anyorder.getIndividual();
			Exist exist = orderedlist.getExist();
			OWLIndividual exist_individual = exist.getIndividual();
			Predicate predicate_exist = exist.getPredicate();
			OWLIndividual predicate_exist_individual = predicate_exist
					.getIndividual();
			ArrayList<Count> count_list = anyorder.getCountList();

			System.out.println("-Intention: "
					+ cleanIRI(intention_individual).toString());
			System.out.println("  +OrderedList: "
					+ cleanIRI(orderedlist_individual).toString());
			System.out.println("    +AnyOrder: "
					+ cleanIRI(anyorder_individual).toString() + "::"
					+ anyorder.getTotalNumber());

			for (int j = 0; j < count_list.size(); j++) {
				Count count = count_list.get(j);
				OWLIndividual count_individual = count.getIndividual();

				Predicate predicate_count = count.getPredicate();
				System.out.print("      +Count: "
						+ cleanIRI(count_individual).toString());
				System.out.println(": " + count.getOccurence());
				System.out.println("        +predicate: "
						+ cleanIRI(predicate_count.getIndividual()).toString());
				System.out.println("          +Reference: "
						+ cleanIRI(predicate_count.getReference()).toString());
				System.out.println("          +Target: "
						+ cleanIRI(predicate_count.getTarget()).toString());
				System.out.println("          +State Relation: "
						+ predicate_count.getStateRelation());
				System.out.println("          +Reference Class: "
						+ predicate_count.getReferenceObjectClass());
				System.out.println("          +Target Class: "
						+ predicate_count.getTargetObjectClass());
			}

			System.out.println("    +Exist: "
					+ cleanIRI(exist_individual).toString() + "::"
					+ exist.getTotalNumber());
			System.out.println("      +predicate: "
					+ cleanIRI(predicate_exist_individual).toString());
			System.out.println("        +Reference: "
					+ cleanIRI(predicate_exist.getReference()).toString());
			System.out.println("        +Target: "
					+ cleanIRI(predicate_exist.getTarget()).toString());
			System.out.println("        +State Relation: "
					+ predicate_exist.getStateRelation());
			System.out.println("        +Reference Class: "
					+ predicate_exist.getReferenceObjectClass());
			System.out.println("        +Target Class: "
					+ predicate_exist.getTargetObjectClass());
		}
	}

	static double roundTwoDecimals(double d) {
		DecimalFormat twoDForm = new DecimalFormat("#.##");
		return Double.valueOf(twoDForm.format(d));
	}

	private void searchList(String individual) {
		ArrayList<Integer> indices = new ArrayList<Integer>();

		for (int i = 0; i < m_intention_list.size(); i++) {
			if (cleanIRI(m_intention_list.get(i).toString()).equalsIgnoreCase(
					individual)) {
				System.out.println("Index: " + i);
			}
		}
	}

	public void setDataFactory() {
		this.m_datafactory = m_manager.getOWLDataFactory();
	}

	public void setManager() {
		this.m_manager = OWLManager.createOWLOntologyManager();
	}

	/**
	 * \brief Simple setter. \param manager
	 */
	public void setManager(OWLOntologyManager manager) {
		this.m_manager = manager;
	}

	/**
	 * \brief Simple setter. \param ontology
	 */
	public void setOntology(OWLOntology ontology) {
		this.m_ontology = ontology;
	}

	/**
	 * \brief Simple setter. \param path
	 */
	public void setPath(String path) {
		this.m_path = path;
	}

	public void setReasoner(OWLOntology myOntology) {
		OWLReasonerFactory reasonerFactory = new StructuralReasonerFactory();
		ConsoleProgressMonitor progressMonitor = new ConsoleProgressMonitor();
		OWLReasonerConfiguration config = new SimpleConfiguration(
				progressMonitor);
		myOntology = this.getOntology();
		this.m_reasoner = reasonerFactory.createReasoner(myOntology, config);
	}

}
