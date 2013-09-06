/****************************************************************************************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards and Technology (NIST), an agency of the U.S. government, and by 
   statute is not subject to copyright in the United States.  
   Recipients of this software assume all responsibility associated with its operation, modification, maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 ****************************************************************************************************************************************************/

package ontology;

import intention.Intention;

import java.util.ArrayList;
import java.util.Vector;


import org.semanticweb.owlapi.model.OWLIndividual;


public class Count {
	public Count() {
	}

	private Predicate m_predicate;
	private Integer m_occurrence;
	private OWLIndividual m_individual;

	public Predicate getPredicate() {
		return this.m_predicate;
	}

	public OWLIndividual getIndividual() {
		return this.m_individual;
	}

	public Integer getOccurence() {
		return this.m_occurrence;
	}

	public void setPredicate(Predicate p) {
		this.m_predicate = p;
	}

	public void setIndividual(OWLIndividual i) {
		this.m_individual = i;
	}

	public void setOccurrence(Integer o) {
		this.m_occurrence = o;
	}
}