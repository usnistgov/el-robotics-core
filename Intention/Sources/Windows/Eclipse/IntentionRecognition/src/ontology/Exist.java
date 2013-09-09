/****************************************************************************************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards and Technology (NIST), an agency of the U.S. government, and by 
   statute is not subject to copyright in the United States.  
   Recipients of this software assume all responsibility associated with its operation, modification, maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 ****************************************************************************************************************************************************/

package ontology;

import intention.Intention;

import java.util.Vector;


import org.semanticweb.owlapi.model.OWLIndividual;



/**
 * This class manages the Ordering Construct Exist
 * 
 * @author Zeid Kootbally
 * 
 */
public class Exist {
	/**
	 * Default Constructor
	 */
	public Exist() {
	}

	/**
	 * Occurrence of an instance of Exist in an Intention
	 */
	private int occurrence;
	/**
	 * The OWLIndividual for an Instance Exist from the ontology
	 */
	private OWLIndividual m_individual;
	private int m_position;
	private int m_total_number;
	private Predicate m_predicate;

	public int getTotalNumber() {
		return this.m_total_number;
	}

	public void setTotalNumber(int i) {
		this.m_total_number = i;
	}

	public OWLIndividual getIndividual() {
		return this.m_individual;
	}

	public void setIndividual(OWLIndividual i) {
		this.m_individual = i;
	}

	public int getOccurrence() {
		return this.occurrence;
	}

	public void setOccurrence(int o) {
		this.occurrence = o;
	}

	public int getPosition() {
		return this.m_position;
	}

	public void setPosition(int p) {
		this.m_position = p;
	}

	public Predicate getPredicate() {
		return this.m_predicate;
	}

	public void setPredicate(Predicate p) {
		this.m_predicate = p;
	}
}