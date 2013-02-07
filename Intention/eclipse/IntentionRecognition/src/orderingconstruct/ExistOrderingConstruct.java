package orderingconstruct;

import intention.IntentionKitting;

import java.util.Vector;

import staterelation.OnTopWithContactStateRelation;
import staterelation.PartiallyInStateRelation;
import staterelation.UnderWithContactStateRelation;


public class ExistOrderingConstruct {
	public ExistOrderingConstruct(String name) {
		this.setName(name);
	}
	
	private String oc_name;
	private String oc_type = "Exist";
	private Vector<IntentionKitting>  intention_list;
	private Vector<OrderedListOrderingConstruct>  orderedlistOC_list;
	private Vector<CountOrderingConstruct>  countOC_list;
	private OnTopWithContactStateRelation ontopwithcontactSR;
	private UnderWithContactStateRelation underwithContactSR;
	private PartiallyInStateRelation partiallyinSR;
	
	public void setName(final String name){
		this.oc_name = name;
	}
	
	
	public String toString() {
		return oc_name.concat(": ").concat(oc_type);
		//return oc_name.concat(oc_type);
	}
	
}