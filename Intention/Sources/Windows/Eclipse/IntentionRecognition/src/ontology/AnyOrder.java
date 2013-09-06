/****************************************************************************************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards and Technology (NIST), an agency of the U.S. government, and by 
   statute is not subject to copyright in the United States.  
   Recipients of this software assume all responsibility associated with its operation, modification, maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 ****************************************************************************************************************************************************/

package ontology;

import java.util.ArrayList;
import org.semanticweb.owlapi.model.OWLIndividual;

public class AnyOrder {

	public AnyOrder() {
		m_count_list = new ArrayList<Count>();
	}

	private ArrayList<Count> m_count_list;
	private OWLIndividual m_individual;
	private int m_position;
	private int m_total_number;

	public void addCountToList(Count c) {
		this.m_count_list.add(c);
	}

	public ArrayList<Count> getCountList() {
		return this.m_count_list;
	}

	public OWLIndividual getIndividual() {
		return this.m_individual;
	}

	public int getPosition() {
		return this.m_position;
	}

	public int getTotalNumber() {
		return this.m_total_number;
	}

	public void setIndividual(OWLIndividual i) {
		this.m_individual = i;
	}

	public void setPosition(int p) {
		this.m_position = p;
	}

	public void setTotalNumber(int i) {
		this.m_total_number = i;
	}

}