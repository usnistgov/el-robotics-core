package orderingconstruct;

import intention.IntentionKitting;

import java.util.Vector;


public class OrderedListOrderingConstruct {

	public OrderedListOrderingConstruct(String name) {
		this.setName(name);
	}

	private String oc_name;
	private Vector<IntentionKitting>  intention_list;
	private Vector  existOC_list;
	public Vector  _ordering_construct_list;

	public void setName(final String name){
		this.oc_name = name;
	}
	
	public String toString() {
		return oc_name;
	}
}