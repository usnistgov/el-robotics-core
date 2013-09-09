/****************************************************************************************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards and Technology (NIST), an agency of the U.S. government, and by 
   statute is not subject to copyright in the United States.  
   Recipients of this software assume all responsibility associated with its operation, modification, maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 ****************************************************************************************************************************************************/

package ontology;

import java.util.ArrayList;
import java.util.HashMap;

import org.semanticweb.owlapi.model.OWLIndividual;

public class OrderedList {

	public OrderedList() {
	}

	public HashMap<String, ArrayList<String>> orderedlist_l;
	private String orderedlist_name;
	private Exist m_exist;
	private AnyOrder m_anyorder;
	private OWLIndividual m_individual;

	public Exist getExist() {
		return this.m_exist;
	}

	public void setExist(Exist e) {
		this.m_exist = e;
	}

	public AnyOrder getAnyOrder() {
		return this.m_anyorder;
	}

	public void setAnyOrder(AnyOrder ao) {
		this.m_anyorder = ao;
	}

	public OWLIndividual getIndividual() {
		return this.m_individual;
	}

	public void setIndividual(OWLIndividual i) {
		this.m_individual = i;
	}
}