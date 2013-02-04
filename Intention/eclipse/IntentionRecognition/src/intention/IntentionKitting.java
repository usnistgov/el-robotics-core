package intention;

import java.util.Vector;

import ontology.Ontology;
import orderingconstruct.AnyOrderOrderingConstruct;
import orderingconstruct.CountOrderingConstruct;
import orderingconstruct.ExistOrderingConstruct;
import orderingconstruct.OrderedListOrderingConstruct;

import org.jgrapht.DirectedGraph;
import org.jgrapht.UndirectedGraph;
import org.jgrapht.graph.DefaultEdge;

import staterelation.OnTopWithContactStateRelation;
import staterelation.PartiallyInStateRelation;

import component.Graph;
import component.Tree;
import component.TreeDemo;


public class IntentionKitting {

	public IntentionKitting() {
	}

	private String name;
	private Vector<ExistOrderingConstruct>  existOC_list;
	private Vector<AnyOrderOrderingConstruct>  anyorderOC_list;
	private Vector<CountOrderingConstruct>  countOC_list;
	private Vector<OrderedListOrderingConstruct>  orderedlistOC_list;
	private Vector<Object> intention_kitting_list;

	/**
	 * Main method
	 * @param args
	 */
//	public static void main(String[] args){
//		IntentionKitting intention_kitting = new IntentionKitting();
//		
//		//-- Define all state relationships
//		OnTopWithContactStateRelation sr1 = new OnTopWithContactStateRelation();
//		sr1.setName("SR1");
//		PartiallyInStateRelation sr2 = new PartiallyInStateRelation();
//		sr2.setName("SR2");
//		PartiallyInStateRelation sr3 = new PartiallyInStateRelation();
//		sr3.setName("SR3");
//		PartiallyInStateRelation sr4 = new PartiallyInStateRelation();
//		sr4.setName("SR4");
//		PartiallyInStateRelation sr5 = new PartiallyInStateRelation();
//		sr5.setName("SR5");
//		PartiallyInStateRelation sr6 = new PartiallyInStateRelation();
//		sr6.setName("SR6");
//		PartiallyInStateRelation sr7 = new PartiallyInStateRelation();
//		sr7.setName("SR7");
//		
//		//-- Define all Ordering Constructs for ExistOrderingConstruct
//		ExistOrderingConstruct oc1 = new ExistOrderingConstruct();
//		oc1.setName("OC1");
//		ExistOrderingConstruct oc2 = new ExistOrderingConstruct();
//		oc2.setName("OC2");
//		ExistOrderingConstruct oc4 = new ExistOrderingConstruct();
//		oc4.setName("OC4");
//		ExistOrderingConstruct oc6 = new ExistOrderingConstruct();
//		oc6.setName("OC6");
//		ExistOrderingConstruct oc8 = new ExistOrderingConstruct();
//		oc8.setName("OC8");
//		ExistOrderingConstruct oc11 = new ExistOrderingConstruct();
//		oc11.setName("OC11");
//		ExistOrderingConstruct oc12 = new ExistOrderingConstruct();
//		oc12.setName("OC12");
//		
//		//-- Define all Ordering Constructs for OrderedListOrderingConstruct
//		OrderedListOrderingConstruct oc13 = new OrderedListOrderingConstruct();
//		oc13.setName("OC13");
//		
//		//-- Define all Ordering Constructs for CountOrderingConstruct
//		CountOrderingConstruct oc5 = new CountOrderingConstruct();
//		oc5.setName("OC5");
//		CountOrderingConstruct oc3 = new CountOrderingConstruct();
//		oc3.setName("OC3");
//		CountOrderingConstruct oc7 = new CountOrderingConstruct();
//		oc7.setName("OC7");
//		CountOrderingConstruct oc9 = new CountOrderingConstruct();
//		oc9.setName("OC9");
//		
//		//-- Define all Ordering Constructs for CountOrderingConstruct
//		AnyOrderOrderingConstruct oc10 = new AnyOrderOrderingConstruct();
//		oc10.setName("OC10");
//		AnyOrderOrderingConstruct oc14 = new AnyOrderOrderingConstruct();
//		oc14.setName("OC14");
//		
//		//--Build the Ordering Constructs
//		//-- OC13 contains OC11 and OC10
//		
//		
//		oc13._ordering_construct_list.add(oc10);
//		oc13._ordering_construct_list.add(oc11);
//	}
	
//    public static void main(String [] args)
//    {
//    	javax.swing.SwingUtilities.invokeLater(new Runnable() {
//            public void run() {
//                TreeDemo.createAndShowGUI();
//            }
//        });
//    }
	
    public static void main(String [] args)
    {
    	Ontology ont = new Ontology("etc/intention.owl");
    }
}