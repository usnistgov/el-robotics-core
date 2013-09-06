/****************************************************************************************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards and Technology (NIST), an agency of the U.S. government, and by 
   statute is not subject to copyright in the United States.  
   Recipients of this software assume all responsibility associated with its operation, modification, maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 ****************************************************************************************************************************************************/

package ontology;

import org.semanticweb.owlapi.model.OWLIndividual;

public class Predicate {

	public Predicate() {
	}

	private OWLIndividual m_individual;
	private OWLIndividual m_reference;
	private String m_reference_class;
	private String m_staterelation;
	private OWLIndividual m_target;
	private String m_target_class;

	public OWLIndividual getIndividual() {
		return this.m_individual;
	}

	public OWLIndividual getReference() {
		return this.m_reference;
	}

	public String getReferenceObjectClass() {
		return this.m_reference_class;
	}

	public String getStateRelation() {
		return this.m_staterelation;
	}

	public OWLIndividual getTarget() {
		return this.m_target;
	}

	public String getTargetObjectClass() {
		return this.m_target_class;
	}

	public void setIndividual(OWLIndividual i) {
		this.m_individual = i;
	}

	public void setReference(OWLIndividual i) {
		this.m_reference = i;
	}

	public void setReferenceObjectClass(String s) {
		this.m_reference_class = s;
	}

	public void setStateRelation(String s) {
		this.m_staterelation = s;
	}

	public void setTarget(OWLIndividual i) {
		this.m_target = i;
	}

	public void setTargetObjectClass(String s) {
		this.m_target_class = s;
	}
}
