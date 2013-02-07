package orderingconstruct;

import intention.IntentionKitting;

import java.util.Vector;



public class CountOrderingConstruct {
	
	public CountOrderingConstruct(String name) {
		this.setName(name);
	}

	private String oc_name;
	private Integer count_number;
	private Vector<IntentionKitting>  intention_list;
	private ExistOrderingConstruct existOC;
	private Vector<AnyOrderOrderingConstruct>  anyorderOC_list;

	public void setName(final String name){
		this.oc_name = name;
	}

	public String toString() {
		return oc_name;
	}
}