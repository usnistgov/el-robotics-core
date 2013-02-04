package orderingconstruct;

import intention.IntentionKitting;

import java.util.Vector;


public class AnyOrderOrderingConstruct {
	
	public AnyOrderOrderingConstruct(String name) {
		this.setName(name);
	}

	private String oc_name;
	public Vector<IntentionKitting>  intention_list;
	public Vector _ordering_construct_list = new Vector();
	private Vector<CountOrderingConstruct>  countOC_list;

	public void setName(final String name){
		this.oc_name = name;
	}
	
	public String getName(AnyOrderOrderingConstruct oc){
		return (oc.oc_name);
	}
	
	public String toString() {
		return oc_name;
	}
}