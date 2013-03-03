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



import fancygui.SuperDemo;
import gui.BarChartUpdate;
import intention.Intention;

import java.awt.Color;
import java.awt.EventQueue;
import java.io.File;
import java.io.PrintStream;
import java.lang.reflect.Array;
import java.net.MalformedURLException;
import java.text.DecimalFormat;
import java.text.Normalizer;
import java.text.Normalizer.Form;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import javax.swing.JOptionPane;
import javax.swing.text.BadLocationException;

import orderingconstruct.AnyOrder;
import orderingconstruct.Count;
import orderingconstruct.Exist;
import orderingconstruct.OrderedList;

import org.jfree.data.category.CategoryDataset;
import org.jfree.ui.RefineryUtilities;
import org.semanticweb.owlapi.apibinding.OWLManager;
import org.semanticweb.owlapi.io.OWLFunctionalSyntaxOntologyFormat;
import org.semanticweb.owlapi.model.AddAxiom;
import org.semanticweb.owlapi.model.IRI;
import org.semanticweb.owlapi.model.OWLAnnotation;
import org.semanticweb.owlapi.model.OWLAnnotationObjectVisitorEx;
import org.semanticweb.owlapi.model.OWLAxiom;
import org.semanticweb.owlapi.model.OWLClass;
import org.semanticweb.owlapi.model.OWLClassAssertionAxiom;
import org.semanticweb.owlapi.model.OWLClassExpression;
import org.semanticweb.owlapi.model.OWLDataFactory;
import org.semanticweb.owlapi.model.OWLDataProperty;
import org.semanticweb.owlapi.model.OWLDatatype;
import org.semanticweb.owlapi.model.OWLEntity;
import org.semanticweb.owlapi.model.OWLEquivalentClassesAxiom;
import org.semanticweb.owlapi.model.OWLException;
import org.semanticweb.owlapi.model.OWLIndividual;
import org.semanticweb.owlapi.model.OWLLiteral;
import org.semanticweb.owlapi.model.OWLNamedIndividual;
import org.semanticweb.owlapi.model.OWLObjectProperty;
import org.semanticweb.owlapi.model.OWLObjectSomeValuesFrom;
import org.semanticweb.owlapi.model.OWLOntology;
import org.semanticweb.owlapi.model.OWLOntologyCreationException;
import org.semanticweb.owlapi.model.OWLOntologyManager;
import org.semanticweb.owlapi.model.OWLOntologyStorageException;
import org.semanticweb.owlapi.model.OWLSubClassOfAxiom;
import org.semanticweb.owlapi.model.PrefixManager;
import org.semanticweb.owlapi.model.RemoveAxiom;
import org.semanticweb.owlapi.reasoner.NodeSet;
import org.semanticweb.owlapi.util.DefaultPrefixManager;
import org.semanticweb.owlapi.util.OWLObjectVisitorExAdapter;
import org.semanticweb.owlapi.util.OWLOntologyMerger;
import org.semanticweb.owlapi.util.OWLOntologyWalker;
import org.semanticweb.owlapi.util.OWLOntologyWalkerVisitor;
import org.semanticweb.owlapi.vocab.OWL2Datatype;
import org.semanticweb.owlapi.reasoner.*;
import org.semanticweb.owlapi.reasoner.structural.StructuralReasonerFactory;

import org.semanticweb.owlapi.model.OWLObjectPropertyExpression;

import component.BarChart;

import Predicate.Predicate;

public class Ontology {
	//private ArrayList<OWLNamedIndividual> intention_list;
	private ArrayList<Intention> intention_list;
	private HashMap<OWLNamedIndividual, ArrayList<OWLNamedIndividual>> orderedlist_orderingconstruct_list;

	private final String ontology_IRI = "http://www.semanticweb.org/ontologies/2013/0/soap.owl";
	private static final char SEPARATOR = '#';
	private OWLDataFactory datafactory;
	private String path;
	public OWLOntology ontology;
	//private ObjectProperty op;
	private OWLOntologyManager manager;
	private BarChartUpdate m_barcharupdate;
	private OWLReasoner reasoner;
	private String hasIntention_OrderingConstruct = "#hasIntention_OrderingConstruct";
	private String hasOrderingConstruct_Predicate = "#hasOrderingConstruct_Predicate";
	private String hasOrderingConstruct_OrderingConstruct = "#hasOrderingConstruct_OrderingConstruct";
	private String hasOrderingConstruct_Position = "#hasOrderingConstruct_Position";
	private String hasPredicate_TargetObject = "#hasPredicate_TargetObject";
	private String hasIntention_Name = "#hasIntention_Name";
	private String hasPredicate_ReferenceObject = "#hasPredicate_ReferenceObject";
	private String hasCount_Occurrence = "#hasCount_Occurrence";
	private String hasPart_Sku = "#hasPart_Sku";
	public String s_ontopath = "/home/zeid/workspace/IntentionRecognition/etc/kittingInstances_ir.owl";
	//public String s_ontopath = "C:/Users/kalucard/workspace/IntentionRecognition/etc/kittingInstances_ir.owl";
	public String s_rootClass = "Intention";
	public String s_subClass = "Kitting";



	/**
	 * \brief Constructor \details Constructor of the Ontology class. \param p
	 * Path of the ontology. \param p2 Path where we are going to save the sql
	 * files.
	 * @throws OWLException 
	 * @throws MalformedURLException 
	 */
	public Ontology(){


	}

	public void setManager(){
		this.manager = OWLManager.createOWLOntologyManager();
	}


	/**
	 * Parse the class @a myClass and store data in arrays (HashMap and ArrayList).
	 * @param myClass Class to parse
	 * @throws InterruptedException 
	 */
	public void parseIntention(NodeSet<OWLClass> myClass) throws InterruptedException{
		/*
		OWLClass clsA = datafactory.getOWLClass(IRI.create("http://www.nist.gov/el/ontologies/kittingClasses.owl" + "#Part"));
		//System.out.println(clsA);
		NodeSet<OWLNamedIndividual> part_instances_NodeSet = reasoner.getInstances(clsA, true);

		if(!part_instances_NodeSet.isEmpty())
			System.out.println("OK");
		for (OWLNamedIndividual part_instance : part_instances_NodeSet.getFlattened()){
			System.out.println(part_instance);

		}
		 */

		/*
		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				BarChartUpdate barcharupdate = new BarChartUpdate();
				m_barcharupdate=barcharupdate;
			}
		});
		 */

		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				SuperDemo superdemo = new SuperDemo("Intention Recognition");
				superdemo.pack();
				RefineryUtilities.centerFrameOnScreen(superdemo);
				superdemo.setVisible(true);
			}
		});

		build_intention_list(myClass);
		//read_intention_list();

		//-- Choose which kit to build
		//ArrayList state = buildStates("a2b3c5");
		ArrayList state = buildStates("a4b3c2d1");
		//ArrayList state = buildStates("a4b3c3");
		//ArrayList state = buildStates("a4b4c2");
		try {
			findIntentionStateRelation(state);
		} catch (BadLocationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}



	private ArrayList<String> input(String state_relation, String target_object, String target_class, String reference_object, String reference_class){
		ArrayList list = new ArrayList();
		list.add(state_relation);
		list.add(target_object);
		list.add(target_class);
		list.add(reference_object);
		list.add(reference_class);

		return list;
	}

	public void initializeList(){
		this.intention_list = new ArrayList<Intention>();
		this.orderedlist_orderingconstruct_list = new HashMap<OWLNamedIndividual, ArrayList<OWLNamedIndividual>>();
	}

	public void setDataFactory(){
		this.datafactory = manager.getOWLDataFactory();
	}

	private void searchList(String individual){
		ArrayList<Integer> indices = new ArrayList<Integer>();

		for (int i = 0; i < intention_list.size(); i++) {
			if(cleanIRI(intention_list.get(i).toString()).equalsIgnoreCase(individual)) {
				System.out.println("Index: "+i);
			}
		}
	}

	private void findIntentionStateRelation(ArrayList list) throws InterruptedException, BadLocationException{
		for (int i=0; i<list.size(); i++){
			int number = 0;
			ArrayList state_list = (ArrayList) list.get(i);
			Thread.sleep(1000);

			//System.out.println("------------------------------- State -------------------------------");
			fancygui.SuperDemo.updateStateRelationPanel("\nState "+(i+1)+"\n", Color.red,fancygui.SuperDemo.text);
			fancygui.SuperDemo.updateStateRelationPanel("\nState "+(i+1)+"\n", Color.red,fancygui.SuperDemo.statePane);
			//-- Read each state relation in state_list
			for (int j=0; j<state_list.size(); j++){
				ArrayList state_relation_list = (ArrayList) state_list.get(j);
				matchStateRelationToIntention(state_relation_list);
			}

			//-- Compute the number of state relations of a state that have been found for each intention
			for (int k = 0; k < intention_list.size(); k++){
				Intention intention=intention_list.get(k);
				number=number+intention.get_number_state_relation();
				//System.out.println("+State Relations matching for "+cleanIRI(intention.getIndividual()).toString()+":"+intention.getNumberStateRelation());
				//System.out.println("+Total State Relations found: "+number);		
			}

			computeProbability(number,(i+1));
		}
	}

	private void computeProbability(int state_relation_total, int state) throws BadLocationException{
		for (int i = 0; i < intention_list.size(); i++){
			//System.out.println("+STATE: "+ state_relation_total);
			Intention intention=intention_list.get(i);
			double intention_state_relation = intention.get_number_state_relation();
			//System.out.println("+Total State Relations found: "+intention.getNumberStateRelation());

			double intention_proba=roundTwoDecimals((intention_state_relation/state_relation_total)*100);
			//System.out.println(cleanIRI(intention.getIndividual()).toString()+": "+intention_proba+" %");

			//-- Display information in SuperDemo
			fancygui.SuperDemo.updateStateRelationPanel(intention.get_intention_name()+": ", Color.black, fancygui.SuperDemo.text);
			fancygui.SuperDemo.updateStateRelationPanel(intention.get_number_state_relation()+"\n", Color.blue, fancygui.SuperDemo.text);

			//m_barcharupdate.setDataSet();
			BarChartUpdate.createDataset(intention_proba,intention.get_intention_name(), state);
		}

	}

	double roundTwoDecimals(double d) {
		DecimalFormat twoDForm = new DecimalFormat("#.##");
		return Double.valueOf(twoDForm.format(d));
	}

	private void matchStateRelationToIntention(ArrayList list) throws BadLocationException{
		String state_relation =list.get(0).toString();
		String target_object = list.get(1).toString();
		String target_object_class = list.get(2).toString();
		String reference_object = list.get(3).toString();
		String reference_object_class = list.get(4).toString();
		//-- build the message we want to display in fancygui.SuperDemo.statePane
		String infolist = state_relation+","+target_object+","+target_object_class+","+reference_object+","+reference_object_class;

		//System.out.println("+++++ "+state_relation+","+target_object+","+target_object_class+","+reference_object+","+reference_object_class+" +++++");
		//-- Write this message in fancygui.SuperDemo.statePane
		fancygui.SuperDemo.updateStateRelationPanel(infolist+"\n", Color.black,fancygui.SuperDemo.statePane);

		int number=0;
		//-- Parse intention_list
		for (int i = 0; i < intention_list.size(); i++){
			Intention intention=intention_list.get(i);
			//-- Get the intention
			OWLIndividual intention_individual = intention_list.get(i).getIndividual();
			//-- How many state relations match the current Intention
			int intention_number_state_relation = intention_list.get(i).get_number_state_relation();
			//-- Get OrderedList
			OrderedList orderedlist = intention_list.get(i).getOrderedList();
			OWLIndividual orderedlist_individual = orderedlist.getIndividual();

			//-- Get AnyOrder from OrderedList
			AnyOrder anyorder = orderedlist.getAnyOrder(); 
			OWLIndividual anyorder_individual = anyorder.getIndividual();

			//-- Get Exist from OrderedList
			Exist exist = orderedlist.getExist(); 

			int anyorder_position=anyorder.getPosition();
			int exist_position=exist.getPosition();

			//-- Check the first element in orderedlist
			if (exist_position<anyorder_position){
				//-- If occurrence of exist > 0 it means that the predicate in exist has not been true yet
				if (exist.getOccurrence()>0){
					//System.out.println("Exist");
					//-- Get the individual for Exist
					OWLIndividual exist_individual = exist.getIndividual();
					//-- Get Predicate from Exist
					Predicate predicate_exist = exist.getPredicate();
					//-- Get the Predicate OWLIndividual
					OWLIndividual predicate_exist_individual = predicate_exist.getIndividual();
					//-- Get the Predicate ReferenceObject
					OWLIndividual predicate_reference_object = predicate_exist.getReference();
					//-- Get the Predicate TargetObject
					OWLIndividual predicate_target_object = predicate_exist.getTarget();
					//-- Get the Predicate StateRelation
					String predicate_state_relation = predicate_exist.getStateRelation();
					//-- Get the Class for ReferenceObject
					String predicate_reference_class = predicate_exist.getReferenceObjectClass();
					//-- Get the Class for TargetObject
					String predicate_target_class = predicate_exist.getTargetObjectClass();

					//-- Check if the input read matches this Predicate
					if (predicate_state_relation.equalsIgnoreCase(state_relation)){
						if (predicate_reference_class.equalsIgnoreCase(reference_object_class)){
							if (predicate_target_class.equalsIgnoreCase(target_object_class)){
								//-- Increment the number of state relation found for the current Intention
								intention_number_state_relation++;
								intention.set_number_state_relation(intention_number_state_relation);
								//-- Decrement the number of occurrence for the current Exist
								exist.setOccurrence((exist.getOccurrence())-1);
								number++;
							}
						}
					}
				}
				//-- If Exist has been satisfied, lets move to AnyOrder
				else{
					//-- Get the list of Count from AnyOrder
					ArrayList<Count> count_list = anyorder.getCountList();

					for (int j = 0; j < count_list.size(); j++){
						Count count = count_list.get(j);
						//-- Occurrence for Count
						int count_occurence=count.getOccurence();
						if (count_occurence>0){
							OWLIndividual count_individual = count.getIndividual();

							Predicate predicate_count = count.getPredicate();
							OWLIndividual predicate_individual = predicate_count.getIndividual();
							//-- Get ReferenceObject for the Predicate
							OWLIndividual predicate_count_reference_object = predicate_count.getReference();
							//-- Get TargetObject for the Predicate
							OWLIndividual predicate_count_target_object = predicate_count.getTarget();
							//-- Get the StateRelation
							String predicate_count_state_relation = predicate_count.getStateRelation();
							//-- Get the Class for ReferenceObject
							String predicate_count_reference_class = predicate_count.getReferenceObjectClass();
							//-- Get the Class for TargetObject
							String predicate_count_target_class = predicate_count.getTargetObjectClass();

							//System.out.println(cleanIRI(predicate_count_target_object.getTypes(ontology)).toString());
							if (cleanIRI(predicate_count_target_object.getTypes(ontology)).toString().equalsIgnoreCase("StockKeepingUnit")){
								//-- Check if the input read matches this Predicate
								if (predicate_count_state_relation.equalsIgnoreCase(state_relation)){
									if (cleanIRI(predicate_count_target_object).toString().equalsIgnoreCase(target_object_class)){
										if (predicate_count_reference_class.equalsIgnoreCase(reference_object_class)){
											//-- Increment the number of state relation found for the current Intention
											intention_number_state_relation++;
											//System.out.println("+-------+"+intention_number_state_relation);
											intention.set_number_state_relation(intention_number_state_relation);
											//-- Decrement the number of occurrence for the current Count
											count.setOccurrence(count_occurence-1);
										}

									}
								}
							}
						}
					}
				}
			}
			else {
				System.out.println("AnyOrder comes before Exist?");
				System.out.println("Check your Ontology Man !!");
			}
		}
	}

	/**
	 * Return The state relation for a given instance of Predicate
	 * @param individual An instance of Predicate
	 * @return The state relation
	 */
	private String getStateRelation(OWLNamedIndividual individual){
		String sr = null;

		if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("Kit-Location-Worktable"))
			sr = "OnTopWithContact";
		else if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("Kit-Location-Lbwk"))
			sr = "PartiallyIn";
		else if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("On-Worktable-Kit"))
			sr = "OnTopWithContact";
		else if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("Part-Type-Location-Kit"))
			sr = "PartiallyIn";
		else if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("Worktable-Empty"))
			sr = "OnTopWithContact";

		return sr;
	}

	/**
	 * Return The class of the target object for a given instance of Predicate
	 * @param individual An instance of Predicate
	 * @return The class of the target object
	 */
	private String getTargetObjectClass(OWLNamedIndividual individual){
		String sr = null;

		if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("Kit-Location-Worktable"))
			sr = "KitTray";
		else if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("Kit-Location-Lbwk"))
			sr = "LargeBoxWithEmptyKitTrays";
		else if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("On-Worktable-Kit"))
			sr = "KitTray";
		else if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("Part-Type-Location-Kit"))
			sr = "StockKeepingUnit";
		else if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("Worktable-Empty"))
			sr = "";

		return sr;
	}

	/**
	 * Return The class of the reference object for a given instance of Predicate
	 * @param individual An instance of Predicate
	 * @return The class of the reference object
	 */
	private String getReferenceObjectClass(OWLNamedIndividual individual){
		String sr = null;

		if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("Kit-Location-Worktable"))
			sr = "WorkTable";
		else if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("Kit-Location-Lbwk"))
			sr = "KitTray";
		else if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("On-Worktable-Kit"))
			sr = "WorkTable";
		else if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("Part-Type-Location-Kit"))
			sr = "KitTray";
		else if (cleanIRI(individual.getTypes(ontology).toString()).equalsIgnoreCase("Worktable-Empty"))
			sr = "WorkTable";
		return sr;
	}

	/**
	 * @brief Parse the ontology and retrieve all the elements associated to each intention.
	 * Each element found is stored in an attribute of their corresponding Java class.
	 * 
	 * @param myClass
	 */
	private void build_intention_list(NodeSet<OWLClass> myClass){
		//-- Building Object and Data properties needed in this function
		OWLObjectProperty OWLOP_hasIntention_OrderingConstruct = datafactory.getOWLObjectProperty(
				IRI.create(ontology_IRI + hasIntention_OrderingConstruct));

		OWLObjectProperty OWLOP_hasOrderingConstruct_OrderingConstruct = datafactory.getOWLObjectProperty(
				IRI.create(ontology_IRI + hasOrderingConstruct_OrderingConstruct));
		OWLObjectProperty OWLOP_hasOrderingConstruct_Predicate = datafactory.getOWLObjectProperty(
				IRI.create(ontology_IRI + hasOrderingConstruct_Predicate));
		OWLObjectProperty OWLOP_hasPredicate_TargetObject = datafactory.getOWLObjectProperty(
				IRI.create(ontology_IRI + hasPredicate_TargetObject));
		OWLObjectProperty OWLOP_hasPredicate_ReferenceObject = datafactory.getOWLObjectProperty(
				IRI.create(ontology_IRI + hasPredicate_ReferenceObject));
		OWLDataProperty OWLDP_hasCount_Occurrence = datafactory.getOWLDataProperty( IRI.create(ontology_IRI + hasCount_Occurrence));
		OWLDataProperty OWLDP_hasIntention_Name = datafactory.getOWLDataProperty( IRI.create(ontology_IRI + hasIntention_Name));
		OWLDataProperty OWLDP_hasOrderingConstruct_Position = datafactory.getOWLDataProperty( IRI.create(ontology_IRI + hasOrderingConstruct_Position));

		Set<OWLClass> myClass_flat = myClass.getFlattened();
		for (OWLClass clazz : myClass_flat) {
			//-- We are checking if we are in the subclass "Kitting" from the class "Intention"
			if (cleanIRI(clazz).equalsIgnoreCase(s_subClass)){
				NodeSet<OWLNamedIndividual> intention_instances_NodeSet = reasoner.getInstances(clazz, true);
				for (OWLNamedIndividual intention_instance : intention_instances_NodeSet.getFlattened()){
					//-- Create a new intention and add the individual to the list
					Intention intention = new Intention();
					intention.setIndividual(intention_instance);
					intention.setPercentage(0.0);
					intention.set_number_state_relation(0);
					//intention_list.add(intention);

					//-- Get the individuals for the object property hasIntention_OrderingConstruct
					NodeSet<OWLNamedIndividual> hasIntention_OrderingConstruct_nodeset = 
							reasoner.getObjectPropertyValues(intention_instance,OWLOP_hasIntention_OrderingConstruct);

					//----------------------------------------------------------------------------------------------//
					//-- Get the individuals that have the negative object property hasIntention_OrderingConstruct --
					//-- Then store the individual in the intention's m_forbidden_list
					//----------------------------------------------------------------------------------------------//
					Map<OWLObjectPropertyExpression, Set<OWLIndividual>> negativeObjectPropertiesMap = 
							intention_instance.getNegativeObjectPropertyValues(ontology);

					//System.out.println("+"+cleanIRI(intention_instance).toString());
					if (!negativeObjectPropertiesMap.isEmpty()){
						for(Entry<OWLObjectPropertyExpression, Set<OWLIndividual>> entry:negativeObjectPropertiesMap.entrySet()) {
							for(OWLIndividual owlIndividual:entry.getValue()) {
								if (getIndividualClassString(owlIndividual).endsWith("Exist")){
									Exist forbidden_exist = new Exist();
									forbidden_exist.setIndividual(owlIndividual);


									//********************************************//
									//-- Find the predicate for forbidden_exist --//
									//********************************************//
									NodeSet<OWLNamedIndividual> pfe_nodeset = reasoner.getObjectPropertyValues((OWLNamedIndividual) owlIndividual,OWLOP_hasOrderingConstruct_Predicate);
									for (OWLNamedIndividual pfe_instance : pfe_nodeset.getFlattened()){
										Predicate pfe = new Predicate();
										pfe.setIndividual(pfe_instance);

										//***********************************//
										//-- Retrieve the reference object --//
										//***********************************//
										NodeSet<OWLNamedIndividual> ref_nodeset = reasoner.getObjectPropertyValues(pfe_instance,OWLOP_hasPredicate_ReferenceObject);
										if (!ref_nodeset.isEmpty()){
											for (OWLNamedIndividual ref_instance : ref_nodeset.getFlattened())
												pfe.setReference(ref_instance);
										}
										//********************************//
										//-- Retrieve the target object --//
										//********************************//
										NodeSet<OWLNamedIndividual> tg_nodeset = reasoner.getObjectPropertyValues(pfe_instance,OWLOP_hasPredicate_TargetObject);
													if (!tg_nodeset.isEmpty()){
														for (OWLNamedIndividual tg_instance : tg_nodeset.getFlattened())
															pfe.setTarget(tg_instance);
													}
													pfe.setStateRelation(getStateRelation(pfe_instance));
																pfe.setTargetObjectClass(getTargetObjectClass(pfe_instance));
																pfe.setReferenceObjectClass(getReferenceObjectClass(pfe_instance));

																forbidden_exist.setPredicate(pfe);
																//****************************************************//
																//-- Added the object Exist in the m_forbidden_list --//
																//****************************************************//
																intention.buildForbiddenList(forbidden_exist);
									}
								}
							}
						}
					}

					//----------------------------------------------//
					//-- Get and store the name of each intention --
					//----------------------------------------------//
					Set<OWLLiteral> intentionName_owlliteralset = reasoner.getDataPropertyValues(intention_instance, OWLDP_hasIntention_Name);
					for(OWLLiteral intentionName_owlliteral : intentionName_owlliteralset){
						//System.out.println("Intention name: "+intentionName_owlliteral.getLiteral());	
						intention.set_intention_name(intentionName_owlliteral.getLiteral());
					}



					//-- For each individual of hasIntention_OrderingConstruct
					for (OWLNamedIndividual ordering_construct_instance : hasIntention_OrderingConstruct_nodeset.getFlattened()){
						//System.out.println("++"+cleanIRI(intention.getIndividual()).toString());
						//-- Check the individual is from OrderedList
						if (getIndividualClassString(ordering_construct_instance).endsWith("OrderedList")){
							//-- Create a new object from the class OrderedList
							OrderedList orderedlist = new OrderedList();
							orderedlist.setIndividual(ordering_construct_instance);
							intention.setOrderedList(orderedlist);

							NodeSet<OWLNamedIndividual> hasOrderingConstruct_OrderingConstruct_nodeset = 
									reasoner.getObjectPropertyValues(ordering_construct_instance,OWLOP_hasOrderingConstruct_OrderingConstruct);

							for (OWLNamedIndividual orderingconstruct_instance : hasOrderingConstruct_OrderingConstruct_nodeset.getFlattened()){
								Set<OWLLiteral> orderingconstruct_position = reasoner.getDataPropertyValues(orderingconstruct_instance, OWLDP_hasOrderingConstruct_Position);
								int position = cleanDataPropertyInteger(orderingconstruct_position.toString());

								//-- Check the individual is from AnyOrder
								if (getIndividualClassString(orderingconstruct_instance).endsWith("AnyOrder")){
									AnyOrder anyorder = new AnyOrder();
									anyorder.setIndividual(orderingconstruct_instance);	
									anyorder.setPosition(position);


									//-- Get all the individuals of type Count
									NodeSet<OWLNamedIndividual> hasOrderingConstruct_OrderingConstruct_Count_nodeset = 
											reasoner.getObjectPropertyValues(orderingconstruct_instance,OWLOP_hasOrderingConstruct_OrderingConstruct);

									int anyorder_total = 0;
									for (OWLNamedIndividual count_instance : hasOrderingConstruct_OrderingConstruct_Count_nodeset.getFlattened()){
										//-- Making sure we are getting only instances of the class Count
										if (getIndividualClassString(count_instance).endsWith("Count")){
											//-- Get the value associated to the count instance
											Set<OWLLiteral> count_number_literal = reasoner.getDataPropertyValues(count_instance, OWLDP_hasCount_Occurrence);
											int count_number = cleanDataPropertyInteger(count_number_literal.toString());

											anyorder_total=anyorder_total+count_number;

											Count count = new Count();
											count.setIndividual(count_instance);
											count.setOccurrence(count_number);


											//-- Getting the predicate node set for count_instance
											NodeSet<OWLNamedIndividual> predicate_nodeset = 
													reasoner.getObjectPropertyValues(count_instance,OWLOP_hasOrderingConstruct_Predicate);
											//-- Reading each predicate individual
											for (OWLNamedIndividual predicate_instance : predicate_nodeset.getFlattened()){

												Predicate predicate = new Predicate();
												predicate.setIndividual(predicate_instance);

												//-- Retrieve the reference object
												NodeSet<OWLNamedIndividual> referenceobject_nodeset = 
														reasoner.getObjectPropertyValues(predicate_instance,OWLOP_hasPredicate_ReferenceObject);
												//-- Retrieve the target object
												NodeSet<OWLNamedIndividual> targetobject_nodeset = 
														reasoner.getObjectPropertyValues(predicate_instance,OWLOP_hasPredicate_TargetObject);

												if (!referenceobject_nodeset.isEmpty()){
													for (OWLNamedIndividual reference_instance : referenceobject_nodeset.getFlattened()){
														predicate.setReference(reference_instance);
													}
												}
												if (!targetobject_nodeset.isEmpty()){
													for (OWLNamedIndividual target_instance : targetobject_nodeset.getFlattened()){
														predicate.setTarget(target_instance);
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
								//-- Check the individual is from Exist
								else if (getIndividualClassString(orderingconstruct_instance).endsWith("Exist")){
									Exist exist = new Exist();
									exist.setIndividual(orderingconstruct_instance);
									exist.setPosition(position);

									int exist_total=0;

									//-- Get all the individuals of type Count
									NodeSet<OWLNamedIndividual> predicate_nodeset = 
											reasoner.getObjectPropertyValues(orderingconstruct_instance,OWLOP_hasOrderingConstruct_Predicate);

									for (OWLNamedIndividual predicate_instance : predicate_nodeset.getFlattened()){
										exist_total++;

										Predicate predicate = new Predicate();
										predicate.setIndividual(predicate_instance);

										//-- Retrieve the reference object
										NodeSet<OWLNamedIndividual> referenceobject_nodeset = 
												reasoner.getObjectPropertyValues(predicate_instance,OWLOP_hasPredicate_ReferenceObject);

										if (!referenceobject_nodeset.isEmpty()){
											for (OWLNamedIndividual reference_instance : referenceobject_nodeset.getFlattened())
												predicate.setReference(reference_instance);
										}

										//-- Retrieve the target object
										NodeSet<OWLNamedIndividual> targetobject_nodeset = 
												reasoner.getObjectPropertyValues(predicate_instance,OWLOP_hasPredicate_TargetObject);

													if (!targetobject_nodeset.isEmpty()){
														for (OWLNamedIndividual target_instance : targetobject_nodeset.getFlattened())
															predicate.setTarget(target_instance);
													}
													predicate.setStateRelation(getStateRelation(predicate_instance));
																predicate.setTargetObjectClass(getTargetObjectClass(predicate_instance));
																predicate.setReferenceObjectClass(getReferenceObjectClass(predicate_instance));

																exist.setPredicate(predicate);
																exist.setTotalNumber(exist_total);
																exist.setOccurrence(1);
																orderedlist.setExist(exist);
									}
								}

							}
							intention.setOrderedList(orderedlist);	
							intention_list.add(intention);
						}
					}

				}
			}
		}
	}

	private void read_intention_list(){
		System.out.println(intention_list.size());
		for (int i = 0; i < intention_list.size(); i++){
			OWLIndividual intention_individual = intention_list.get(i).getIndividual();
			OrderedList orderedlist = intention_list.get(i).getOrderedList();
			OWLIndividual orderedlist_individual = orderedlist.getIndividual();
			AnyOrder anyorder = orderedlist.getAnyOrder(); 
			OWLIndividual anyorder_individual = anyorder.getIndividual();
			Exist exist = orderedlist.getExist(); 
			OWLIndividual exist_individual = exist.getIndividual();
			Predicate predicate_exist = exist.getPredicate();
			OWLIndividual predicate_exist_individual = predicate_exist.getIndividual();
			ArrayList<Count> count_list = anyorder.getCountList();

			System.out.println("-Intention: "+cleanIRI(intention_individual).toString());
			System.out.println("  +OrderedList: "+cleanIRI(orderedlist_individual).toString());
			System.out.println("    +AnyOrder: "+cleanIRI(anyorder_individual).toString() +"::"+anyorder.getTotalNumber());

			for (int j = 0; j < count_list.size(); j++){
				Count count = count_list.get(j);
				OWLIndividual count_individual = count.getIndividual();

				Predicate predicate_count = count.getPredicate();
				System.out.print("      +Count: "+cleanIRI(count_individual).toString());
				System.out.println(": "+count.getOccurence());
				System.out.println("        +Predicate: "+cleanIRI(predicate_count.getIndividual()).toString());
				System.out.println("          +Reference: "+cleanIRI(predicate_count.getReference()).toString());
				System.out.println("          +Target: "+cleanIRI(predicate_count.getTarget()).toString());
				System.out.println("          +State Relation: "+predicate_count.getStateRelation());
				System.out.println("          +Reference Class: "+predicate_count.getReferenceObjectClass());
				System.out.println("          +Target Class: "+predicate_count.getTargetObjectClass());
			}

			System.out.println("    +Exist: "+cleanIRI(exist_individual).toString()+"::"+exist.getTotalNumber());
			System.out.println("      +Predicate: "+cleanIRI(predicate_exist_individual).toString());
			System.out.println("        +Reference: "+cleanIRI(predicate_exist.getReference()).toString());
			System.out.println("        +Target: "+cleanIRI(predicate_exist.getTarget()).toString());
			System.out.println("        +State Relation: "+predicate_exist.getStateRelation());
			System.out.println("        +Reference Class: "+predicate_exist.getReferenceObjectClass());
			System.out.println("        +Target Class: "+predicate_exist.getTargetObjectClass());
		}
	}

	public String getIndividualClassString (OWLNamedIndividual individual){
		//System.out.println(cleanIRI(individual.getTypes(ontology).toString()));
		return (cleanIRI(individual.getTypes(ontology).toString()));
	}

	public String getIndividualClassString (OWLIndividual individual){
		//System.out.println(cleanIRI(individual.getTypes(ontology).toString()));
		return (cleanIRI(individual.getTypes(ontology).toString()));
	}

	public Set<OWLClassExpression> getIndividualClass (OWLNamedIndividual individual){
		//System.out.println(cleanIRI(individual.getTypes(ontology).toString()));
		return individual.getTypes(ontology);
	}

	private int cleanDataPropertyInteger(String s){
		StringBuilder myNumbers = new StringBuilder();
		for (int i = 0; i < s.length(); i++) {
			if (Character.isDigit(s.charAt(i))) {
				myNumbers.append(s.charAt(i));
			}
		}
		String myNumbers_s =  myNumbers.toString();
		//System.out.println("Your numbers: " + myNumbers.toString());
		return Integer.parseInt(myNumbers_s);

	}

	/**
	 * \brief Simple getter. \return manager
	 */
	public OWLOntologyManager getManager() {
		return this.manager;
	}

	/**
	 * \brief Simple getter. \return ontology
	 */
	public OWLOntology getOntology() {
		return ontology;
	}

	/**
	 * \brief Simple getter. \return path
	 */
	public String getPath() {
		return path;
	}


	/**
	 * \brief Simple getter. \return SEPARATOR
	 */
	public static char getSeparator() {
		return SEPARATOR;
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
	 * \brief Simple setter. \param path
	 */
	public void setPath(String path) {
		this.path = path;
	}



	/**
	 * \brief Simple setter. \param ontology
	 */
	public void setOntology(OWLOntology ontology) {
		this.ontology = ontology;
	}



	/**
	 * \brief Simple setter. \param manager
	 */
	public void setManager(OWLOntologyManager manager) {
		this.manager = manager;
	}


	/**
	 * \brief Return the name of the entity without the IRI
	 * 
	 * For example, if @a entity = [<http://www.semanticweb.org/ontologies/2013/0/soap.owl#Kitting>], this function returns @a Kitting. 
	 * This function operates as follows:
	 *  - Identify the index of the separator @a SEPARATOR
	 *  - Keep only what is after the SEPARATOR
	 *  - Remove characters that are not alphanumeric
	 * \param entity_ Entity to be trimmed
	 * \return The name of the entity without the IRI
	 */
	public String cleanIRI(Object entity) {
		int index = entity.toString().indexOf(SEPARATOR);
		String new_entity = entity.toString().substring(index+1);
		String normalized = Normalizer.normalize(new_entity.toString(), Form.NFD);
		String result = normalized.replaceAll("[^A-Za-z0-9-_]", "");

		return result;
	}



	private static OWLReasoner createReasoner(OWLOntology myOntology){
		OWLReasonerFactory reasonerFactory = new StructuralReasonerFactory();
		return reasonerFactory.createReasoner(myOntology);
	}

	public void setReasoner(OWLOntology myOntology){
		OWLReasonerFactory reasonerFactory = new StructuralReasonerFactory();
		ConsoleProgressMonitor progressMonitor = new ConsoleProgressMonitor();
		OWLReasonerConfiguration config = new SimpleConfiguration(progressMonitor);
		myOntology=this.getOntology();
		this.reasoner = reasonerFactory.createReasoner(myOntology, config);		
	}

	public  void loadOntologyFromPath(String myPath) throws MalformedURLException, OWLException{
		File file = new File(myPath);
		OWLOntology myOntology;
		myOntology = manager.loadOntologyFromOntologyDocument(file);
		setOntology(myOntology);

		System.out.println("Loaded ontology: " + myOntology);
		setOntology(myOntology);
	}

	public NodeSet<OWLClass> getSubclasses(String myClassName){
		OWLDataFactory factory = this.manager.getOWLDataFactory();
		//OWLClass myClass = factory.getOWLClass(IRI.create(ontology_IRI.concat("#Intention")));
		OWLClass myClass = factory.getOWLClass(IRI.create(ontology_IRI.concat("#"+myClassName)));

		ConsoleProgressMonitor progressMonitor = new ConsoleProgressMonitor();
		OWLReasonerConfiguration config = new SimpleConfiguration(progressMonitor);

		NodeSet<OWLClass> subclasses_of_myClass = this.reasoner.getSubClasses(myClass, true);

		return subclasses_of_myClass;
	}

	private static void printProperties(OWLOntologyManager man, OWLOntology ont,
			OWLReasoner reasoner, OWLClass cls) {
		if (!ont.containsClassInSignature(cls.getIRI())) {
			throw new RuntimeException("Class not in signature of the ontology");
		}
		// Note that the following code could be optimized... if we find that
		// instances of the specified class do not have a property, then we
		// don't need to check the sub properties of this property
		System.out.println("Properties of " + cls);
		for (OWLObjectPropertyExpression prop : ont.getObjectPropertiesInSignature()) {
			boolean sat = hasProperty(man, reasoner, cls, prop);
			if (sat) {
				System.out.println("Instances of " + cls
						+ " necessarily have the property " + prop);
			}
		}
	}

	private static boolean hasProperty(OWLOntologyManager man, OWLReasoner reasoner,
			OWLClass cls, OWLObjectPropertyExpression prop) {
		// To test whether the instances of a class must have a property we
		// create a some values from restriction and then ask for the
		// satisfiability of the class intersected with the complement of this
		// some values from restriction. If the intersection is satisfiable then
		// the instances of the class don't have to have the property,
		// otherwise, they do.
		OWLDataFactory dataFactory = man.getOWLDataFactory();
		OWLClassExpression restriction = dataFactory.getOWLObjectSomeValuesFrom(prop,
				dataFactory.getOWLThing());
		// Now we see if the intersection of the class and the complement of
		// this restriction is satisfiable
		OWLClassExpression complement = dataFactory.getOWLObjectComplementOf(restriction);
		OWLClassExpression intersection = dataFactory.getOWLObjectIntersectionOf(cls,
				complement);
		return !reasoner.isSatisfiable(intersection);
	}

	/**
	 * This function builds all the states for a given kit
	 * @param kit The kit to build
	 * @return An ArrayList that contains all the states for the given kit
	 */
	private ArrayList buildStates(String kit){
		ArrayList l1 = input("OntopWithContact","kit_tray_1_ir","KitTray","work_table_1","WorkTable");
		ArrayList State1 = new ArrayList();
		State1.add(l1);

		ArrayList States = new ArrayList();

		//-------------------------------------------------------------------------------------------------------------------------//
		//-- BUILD a4b3c2d1
		//-------------------------------------------------------------------------------------------------------------------------//
		if (kit.equalsIgnoreCase("a4b3c2d1")){

			ArrayList l6 = input("OntopWithContact","part_a_1_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l7 = input("OntopWithContact","part_a_2_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l8 = input("OntopWithContact","part_a_3_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l9 = input("OntopWithContact","part_a_4_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l10 = input("OntopWithContact","part_b_1_ir","stock_keeping_unit_parts_b_tray_ir","work_table_1","WorkTable");
			ArrayList l11 = input("OntopWithContact","part_b_2_ir","stock_keeping_unit_parts_b_tray_ir","work_table_1","WorkTable");
			ArrayList l12 = input("OntopWithContact","part_b_3_ir","stock_keeping_unit_parts_b_tray_ir","work_table_1","WorkTable");
			ArrayList l13 = input("OntopWithContact","part_c_3_ir","stock_keeping_unit_parts_c_tray_ir","work_table_1","WorkTable");
			ArrayList l14 = input("OntopWithContact","part_c_4_ir","stock_keeping_unit_parts_c_tray_ir","work_table_1","WorkTable");
			ArrayList l15 = input("OntopWithContact","part_d_1_ir","stock_keeping_unit_parts_d_tray_ir","work_table_1","WorkTable");

			ArrayList State2 = new ArrayList();
			State2.add(l6);
			State2.add(l7);
			State2.add(l8);
			State2.add(l9);
			State2.add(l10);
			State2.add(l11);
			State2.add(l12);
			State2.add(l13);
			State2.add(l14);
			State2.add(l15);

			ArrayList l16 = input("PartiallyIn","part_a_1_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l17 = input("PartiallyIn","part_a_2_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l18 = input("PartiallyIn","part_a_3_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l19 = input("PartiallyIn","part_a_4_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l20 = input("PartiallyIn","part_b_4_ir","stock_keeping_unit_parts_b_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l21 = input("PartiallyIn","part_b_1_ir","stock_keeping_unit_parts_b_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l22 = input("PartiallyIn","part_b_2_ir","stock_keeping_unit_parts_b_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l23 = input("PartiallyIn","part_c_3_ir","stock_keeping_unit_parts_c_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l24 = input("PartiallyIn","part_c_4_ir","stock_keeping_unit_parts_c_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l25 = input("PartiallyIn","part_d_1_ir","stock_keeping_unit_parts_d_tray_ir","kit_tray_1_ir","KitTray");

			ArrayList State3 = new ArrayList();
			ArrayList State4 = new ArrayList();
			ArrayList State5 = new ArrayList();
			ArrayList State6 = new ArrayList();
			ArrayList State7 = new ArrayList();
			ArrayList State8 = new ArrayList();
			ArrayList State9 = new ArrayList();
			ArrayList State10 = new ArrayList();
			ArrayList State11 = new ArrayList();
			ArrayList State12 = new ArrayList();

			State3.add(l16);
			State4.add(l17);
			State5.add(l18);
			State6.add(l19);
			State7.add(l20);
			State8.add(l21);
			State9.add(l22);
			State10.add(l23);
			State11.add(l24);
			State12.add(l25);

			//-- Kit tray on the table
			States.add(State1);
			States.add(State2);
			States.add(State8);
			States.add(State9);
			States.add(State10);
			States.add(State11);
			States.add(State12);
			States.add(State3);
			States.add(State4);
			States.add(State5);
			States.add(State6);
			States.add(State7);

		}
		//-------------------------------------------------------------------------------------------------------------------------//
		//-- BUILD a4b4c2
		//-------------------------------------------------------------------------------------------------------------------------//
		else if (kit.equalsIgnoreCase("a4b4c2")){
			ArrayList l6 = input("OntopWithContact","part_a_1_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l7 = input("OntopWithContact","part_a_2_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l8 = input("OntopWithContact","part_a_3_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l9 = input("OntopWithContact","part_a_4_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l10 = input("OntopWithContact","part_b_3_ir","stock_keeping_unit_parts_b_tray_ir","work_table_1","WorkTable");
			ArrayList l11 = input("OntopWithContact","part_b_1_ir","stock_keeping_unit_parts_b_tray_ir","work_table_1","WorkTable");
			ArrayList l12 = input("OntopWithContact","part_b_2_ir","stock_keeping_unit_parts_b_tray_ir","work_table_1","WorkTable");
			ArrayList l13 = input("OntopWithContact","part_b_4_ir","stock_keeping_unit_parts_b_tray_ir","work_table_1","WorkTable");
			ArrayList l14 = input("OntopWithContact","part_c_4_ir","stock_keeping_unit_parts_c_tray_ir","work_table_1","WorkTable");
			ArrayList l15 = input("OntopWithContact","part_c_5_ir","stock_keeping_unit_parts_c_tray_ir","work_table_1","WorkTable");

			ArrayList State2 = new ArrayList();
			State2.add(l6);
			State2.add(l7);
			State2.add(l8);
			State2.add(l9);
			State2.add(l10);
			State2.add(l11);
			State2.add(l12);
			State2.add(l13);
			State2.add(l14);
			State2.add(l15);

			ArrayList l16 = input("PartiallyIn","part_a_1_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l17 = input("PartiallyIn","part_a_2_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l18 = input("PartiallyIn","part_a_4_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l19 = input("PartiallyIn","part_a_3_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l20 = input("PartiallyIn","part_b_3_ir","stock_keeping_unit_parts_b_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l21 = input("PartiallyIn","part_b_1_ir","stock_keeping_unit_parts_b_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l22 = input("PartiallyIn","part_b_2_ir","stock_keeping_unit_parts_b_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l23 = input("PartiallyIn","part_b_4_ir","stock_keeping_unit_parts_b_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l24 = input("PartiallyIn","part_c_4_ir","stock_keeping_unit_parts_c_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l25 = input("PartiallyIn","part_c_5_ir","stock_keeping_unit_parts_c_tray_ir","kit_tray_1_ir","KitTray");

			ArrayList State3 = new ArrayList();
			ArrayList State4 = new ArrayList();
			ArrayList State5 = new ArrayList();
			ArrayList State6 = new ArrayList();
			ArrayList State7 = new ArrayList();
			ArrayList State8 = new ArrayList();
			ArrayList State9 = new ArrayList();
			ArrayList State10 = new ArrayList();
			ArrayList State11 = new ArrayList();
			ArrayList State12 = new ArrayList();

			State3.add(l16);
			State4.add(l17);
			State5.add(l18);
			State6.add(l19);
			State7.add(l20);
			State8.add(l21);
			State9.add(l22);
			State10.add(l23);
			State11.add(l24);
			State12.add(l25);

			//-- Kit tray on the table
			States.add(State1);
			States.add(State2);
			States.add(State8);
			States.add(State9);
			States.add(State10);
			States.add(State11);
			States.add(State12);
			States.add(State3);
			States.add(State4);
			States.add(State5);
			States.add(State6);
			States.add(State7);
		}
		//-------------------------------------------------------------------------------------------------------------------------//
		//-- BUILD a4b3c3
		//-------------------------------------------------------------------------------------------------------------------------//
		else if (kit.equalsIgnoreCase("a4b3c3")){
			ArrayList l6 = input("OntopWithContact","part_a_1_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l7 = input("OntopWithContact","part_a_2_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l8 = input("OntopWithContact","part_a_3_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l9 = input("OntopWithContact","part_a_4_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l10 = input("OntopWithContact","part_b_3_ir","stock_keeping_unit_parts_b_tray_ir","work_table_1","WorkTable");
			ArrayList l11 = input("OntopWithContact","part_b_1_ir","stock_keeping_unit_parts_b_tray_ir","work_table_1","WorkTable");
			ArrayList l12 = input("OntopWithContact","part_b_2_ir","stock_keeping_unit_parts_b_tray_ir","work_table_1","WorkTable");
			ArrayList l13 = input("OntopWithContact","part_c_3_ir","stock_keeping_unit_parts_c_tray_ir","work_table_1","WorkTable");
			ArrayList l14 = input("OntopWithContact","part_c_4_ir","stock_keeping_unit_parts_c_tray_ir","work_table_1","WorkTable");
			ArrayList l15 = input("OntopWithContact","part_c_5_ir","stock_keeping_unit_parts_c_tray_ir","work_table_1","WorkTable");

			ArrayList State2 = new ArrayList();
			State2.add(l6);
			State2.add(l7);
			State2.add(l8);
			State2.add(l9);
			State2.add(l10);
			State2.add(l11);
			State2.add(l12);
			State2.add(l13);
			State2.add(l14);
			State2.add(l15);

			ArrayList l16 = input("PartiallyIn","part_a_1_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l17 = input("PartiallyIn","part_a_2_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l18 = input("PartiallyIn","part_a_4_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l19 = input("PartiallyIn","part_a_3_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l20 = input("PartiallyIn","part_b_3_ir","stock_keeping_unit_parts_b_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l21 = input("PartiallyIn","part_b_1_ir","stock_keeping_unit_parts_b_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l22 = input("PartiallyIn","part_b_2_ir","stock_keeping_unit_parts_b_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l23 = input("PartiallyIn","part_c_3_ir","stock_keeping_unit_parts_c_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l24 = input("PartiallyIn","part_c_4_ir","stock_keeping_unit_parts_c_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l25 = input("PartiallyIn","part_c_5_ir","stock_keeping_unit_parts_c_tray_ir","kit_tray_1_ir","KitTray");

			ArrayList State3 = new ArrayList();
			ArrayList State4 = new ArrayList();
			ArrayList State5 = new ArrayList();
			ArrayList State6 = new ArrayList();
			ArrayList State7 = new ArrayList();
			ArrayList State8 = new ArrayList();
			ArrayList State9 = new ArrayList();
			ArrayList State10 = new ArrayList();
			ArrayList State11 = new ArrayList();
			ArrayList State12 = new ArrayList();

			State3.add(l16);
			State4.add(l17);
			State5.add(l18);
			State6.add(l19);
			State7.add(l20);
			State8.add(l21);
			State9.add(l22);
			State10.add(l23);
			State11.add(l24);
			State12.add(l25);

			//-- Kit tray on the table
			States.add(State1);
			States.add(State2);
			States.add(State8);
			States.add(State9);
			States.add(State10);
			States.add(State11);
			States.add(State12);
			States.add(State3);
			States.add(State4);
			States.add(State5);
			States.add(State6);
			States.add(State7);
		}
		//-------------------------------------------------------------------------------------------------------------------------//
		//-- BUILD a2b3c5
		//-------------------------------------------------------------------------------------------------------------------------//
		else if (kit.equalsIgnoreCase("a2b3c5")){
			ArrayList l6 = input("OntopWithContact","part_a_1_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l7 = input("OntopWithContact","part_a_2_ir","stock_keeping_unit_parts_a_tray_ir","work_table_1","WorkTable");
			ArrayList l8 = input("OntopWithContact","part_b_1_ir","stock_keeping_unit_parts_b_tray_ir","work_table_1","WorkTable");
			ArrayList l9 = input("OntopWithContact","part_b_2_ir","stock_keeping_unit_parts_b_tray_ir","work_table_1","WorkTable");
			ArrayList l10 = input("OntopWithContact","part_b_3_ir","stock_keeping_unit_parts_b_tray_ir","work_table_1","WorkTable");
			ArrayList l11 = input("OntopWithContact","part_c_1_ir","stock_keeping_unit_parts_c_tray_ir","work_table_1","WorkTable");
			ArrayList l12 = input("OntopWithContact","part_c_2_ir","stock_keeping_unit_parts_c_tray_ir","work_table_1","WorkTable");
			ArrayList l13 = input("OntopWithContact","part_c_3_ir","stock_keeping_unit_parts_c_tray_ir","work_table_1","WorkTable");
			ArrayList l14 = input("OntopWithContact","part_c_4_ir","stock_keeping_unit_parts_c_tray_ir","work_table_1","WorkTable");
			ArrayList l15 = input("OntopWithContact","part_c_5_ir","stock_keeping_unit_parts_c_tray_ir","work_table_1","WorkTable");

			ArrayList State2 = new ArrayList();
			State2.add(l6);
			State2.add(l7);
			State2.add(l8);
			State2.add(l9);
			State2.add(l10);
			State2.add(l11);
			State2.add(l12);
			State2.add(l13);
			State2.add(l14);
			State2.add(l15);

			ArrayList l16 = input("PartiallyIn","part_a_1_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l17 = input("PartiallyIn","part_a_2_ir","stock_keeping_unit_parts_a_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l18 = input("PartiallyIn","part_b_1_ir","stock_keeping_unit_parts_b_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l19 = input("PartiallyIn","part_b_2_ir","stock_keeping_unit_parts_b_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l20 = input("PartiallyIn","part_b_4_ir","stock_keeping_unit_parts_b_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l21 = input("PartiallyIn","part_c_1_ir","stock_keeping_unit_parts_c_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l22 = input("PartiallyIn","part_c_2_ir","stock_keeping_unit_parts_c_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l23 = input("PartiallyIn","part_c_3_ir","stock_keeping_unit_parts_c_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l24 = input("PartiallyIn","part_c_4_ir","stock_keeping_unit_parts_c_tray_ir","kit_tray_1_ir","KitTray");
			ArrayList l25 = input("PartiallyIn","part_c_5_ir","stock_keeping_unit_parts_c_tray_ir","kit_tray_1_ir","KitTray");

			ArrayList State3 = new ArrayList();
			ArrayList State4 = new ArrayList();
			ArrayList State5 = new ArrayList();
			ArrayList State6 = new ArrayList();
			ArrayList State7 = new ArrayList();
			ArrayList State8 = new ArrayList();
			ArrayList State9 = new ArrayList();
			ArrayList State10 = new ArrayList();
			ArrayList State11 = new ArrayList();
			ArrayList State12 = new ArrayList();

			State3.add(l16);
			State4.add(l17);
			State5.add(l18);
			State6.add(l19);
			State7.add(l20);
			State8.add(l21);
			State9.add(l22);
			State10.add(l23);
			State11.add(l24);
			State12.add(l25);

			//-- Kit tray on the table
			States.add(State1);
			States.add(State2);
			States.add(State8);
			States.add(State9);
			States.add(State10);
			States.add(State11);
			States.add(State12);
			States.add(State3);
			States.add(State4);
			States.add(State5);
			States.add(State6);
			States.add(State7);
		}
		else if (kit.equalsIgnoreCase("a2b3c3d1e1")){

		}
		return States;
	}
}

