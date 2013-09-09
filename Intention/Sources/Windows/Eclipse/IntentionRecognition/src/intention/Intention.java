/****************************************************************************************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards and Technology (NIST), an agency of the U.S. government, and by 
   statute is not subject to copyright in the United States.  
   Recipients of this software assume all responsibility associated with its operation, modification, maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 ****************************************************************************************************************************************************/

/**
 * \defgroup intention Intention Structure
 */
package intention;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

import ontology.AnyOrder;
import ontology.Exist;
import ontology.OrderedList;

import org.semanticweb.owlapi.model.OWLIndividual;

/**
 * \class Intention
 * 
 * \ingroup intention
 * 
 * 
 * \brief Representation of intentions from their definition in the ontology.
 * 
 * This class consists of functions to represent intentions from their
 * definition in the ontology. The ontology is read using OWL API tools and the
 * description of each intention is stored in a list.
 * 
 * \author zeidk
 * 
 * \date 2013/01/01
 * 
 * Contact: zeid.kootbally@nist.gov
 * 
 */
public class Intention {

	// public String intention_name;
	public HashMap<String, String> m_intention_orderingConstruct_list;

	private ArrayList<Exist> m_detrimental_list;
	private Exist m_exist;
	private String m_intention_name;
	private AnyOrder m_anyorder;
	private OrderedList m_orderedlist;
	private OWLIndividual m_individual;
	private double m_percentage;
	private int m_number_state_relation;
	private int m_SR_Total;
	private int m_Si;
	private int m_found_detrimental_SR;
	private double m_am1;
	private double m_am2;
	private double m_am3;
	private double m_am4;
	private double m_am5;
	private double m_mm1;
	private double m_percentComplete_i_s;
	private double m_percentProductive_i_s;
	private int m_SR_i_s;
	private int m_SR_i_r_s;
	private static String m_built_kit;
	private static String m_selected_plan;
	private int m_intention_number;
	
	
	
	private Map<Integer, Integer> m_SRirs = new HashMap<Integer, Integer>();

	/**
	 * \brief Class constructor.
	 * 
	 * Instantiate the list of ordering constructs for an intention.<br>
	 * Instantiate a list of forbidden ordering constructs.
	 */
	public Intention() {
		m_intention_orderingConstruct_list = new HashMap();
		setDetrimentalList(new ArrayList<Exist>());
	}

	/**
	 * Add an ordering construct of type Exist to the list of detrimental state relations.
	 * @param _exist An ordering construct of type Exist
	 */
	public void builDetrimentalList(Exist _exist) {
		this.m_detrimental_list.add(_exist);
	}

	
	public Exist getExist() {
		return this.m_exist;
	}

	/**
	 * @return The list of detrimental state relations
	 */
	public ArrayList<Exist> getDetrimentalList() {
		return m_detrimental_list;
	}

	public OWLIndividual getIndividual() {
		return this.m_individual;
	}

	public HashMap<String, String> getIntentionList() {
		return this.m_intention_orderingConstruct_list;
	}

	public String getIntentionName() {
		return m_intention_name;
	}
	

	public int getNumberStateRelation() {
		return m_number_state_relation;
	}

	public OrderedList getOrderedList() {
		return this.m_orderedlist;
	}

	public double getPercentage() {
		return this.m_percentage;
	}


	public void setExist(Exist e) {
		this.m_exist = e;
	}

	public void setIntentionName(String m_intention_name) {
		this.m_intention_name = m_intention_name;
	}

	/**
	 * @brief Set the list of detrimental state relations
	 * @param _list List of detrimental state relations 
	 */
	public void setDetrimentalList(ArrayList<Exist> _list) {
		this.m_detrimental_list = _list;
	}

	public void setIndividual(OWLIndividual i) {
		this.m_individual = i;
	}

	public void setNumberStateRelation(int m_number_state_relation) {
		this.m_number_state_relation = m_number_state_relation;
	}



	public void setOrderedList(OrderedList ol) {
		this.m_orderedlist = ol;
	}

	public void setPercentage(double p) {
		this.m_percentage = p;
	}

	public int getM_found_detrimental_SR() {
		return m_found_detrimental_SR;
	}

	public void setM_found_detrimental_SR(int m_found_detrimental_SR) {
		this.m_found_detrimental_SR = m_found_detrimental_SR;
	}

	public AnyOrder getM_anyorder() {
		return m_anyorder;
	}

	public void setM_anyorder(AnyOrder m_anyorder) {
		this.m_anyorder = m_anyorder;
	}

	/**
	 * @return the m_am1
	 */
	public double getM_am1() {
		return m_am1;
	}

	/**
	 * @param m_am1 the m_am1 to set
	 */
	public void setM_am1(double m_am1) {
		this.m_am1 = m_am1;
	}

	/**
	 * @return the m_am2
	 */
	public double getM_am2() {
		return m_am2;
	}

	/**
	 * @param m_am2 the m_am2 to set
	 */
	public void setM_am2(double m_am2) {
		this.m_am2 = m_am2;
	}

	/**
	 * @return the m_am4
	 */
	public double getM_am4() {
		return m_am4;
	}

	/**
	 * @param m_am4 the m_am4 to set
	 */
	public void setM_am4(double m_am4) {
		this.m_am4 = m_am4;
	}

	/**
	 * @return the m_am5
	 */
	public double getM_am5() {
		return m_am5;
	}

	/**
	 * @param m_am5 the m_am5 to set
	 */
	public void setM_am5(double m_am5) {
		this.m_am5 = m_am5;
	}
	/**
	 * @return the m_am3
	 */
	public double getM_am3() {
		return m_am3;
	}

	/**
	 * @param m_am3 the m_am3 to set
	 */
	public void setM_am3(double m_am3) {
		this.m_am3 = m_am3;
	}

	/**
	 * @return the m_mm1
	 */
	public double getM_mm1() {
		return m_mm1;
	}

	/**
	 * @param m_mm1 the m_mm1 to set
	 */
	public void setM_mm1(double m_mm1) {
		this.m_mm1 = m_mm1;
	}

	/**
	 * @return the m_percentComplete_i_s
	 */
	public double getM_percentComplete_i_s() {
		return m_percentComplete_i_s;
	}

	/**
	 * @param m_percentComplete_i_s the m_percentComplete_i_s to set
	 */
	public void setM_percentComplete_i_s(double m_percentComplete_i_s) {
		this.m_percentComplete_i_s = m_percentComplete_i_s;
	}

	/**
	 * @return the m_percentProductive_i_s
	 */
	public double getM_percentProductive_i_s() {
		return m_percentProductive_i_s;
	}

	/**
	 * @param m_percentProductive_i_s the m_percentProductive_i_s to set
	 */
	public void setM_percentProductive_i_s(double m_percentProductive_i_s) {
		this.m_percentProductive_i_s = m_percentProductive_i_s;
	}
	

	/**
	 * @return the m_SR_i_s
	 */
	public int getM_SR_i_s() {
		return m_SR_i_s;
	}

	/**
	 * @param m_SR_i_s the m_SR_i_s to set
	 */
	public void setM_SR_i_s(int m_SR_i_s) {
		this.m_SR_i_s = m_SR_i_s;
	}

	/**
	 * @return the m_SR_Total
	 */
	public int getM_SR_Total() {
		return m_SR_Total;
	}

	/**
	 * @param m_SR_Total the m_SR_Total to set
	 */
	public void setM_SR_Total(int m_SR_Total) {
		this.m_SR_Total = m_SR_Total;
	}

	/**
	 * @return the m_Si
	 */
	public int getM_Si() {
		return m_Si;
	}

	/**
	 * @param m_Si the m_Si to set
	 */
	public void setM_Si(int m_Si) {
		this.m_Si = m_Si;
	}

	/**
	 * @return the m_SRirs
	 */
	public Map<Integer, Integer> getM_map_SRirs() {
		return m_SRirs;
	}

	/**
	 * @param m_SRirs the m_SRirs to set
	 */
	public void setM_map_SRirs(Map<Integer, Integer> m_SRirs) {
		this.m_SRirs = m_SRirs;
	}

	/**
	 * @return the m_SR_i_r_s
	 */
	public int getM_SR_i_r_s() {
		return m_SR_i_r_s;
	}

	/**
	 * @param m_SR_i_r_s the m_SR_i_r_s to set
	 */
	public void setM_SR_i_r_s(int m_SR_i_r_s) {
		this.m_SR_i_r_s = m_SR_i_r_s;
	}

	public static String getM_built_kit() {
		return m_built_kit;
	}

	public static void setM_built_kit(String built_kit) {
		m_built_kit = built_kit;
	}

	public static String getM_selected_plan() {
		return m_selected_plan;
	}

	public static void setM_selected_plan(String selected_plan) {
		m_selected_plan = selected_plan;
	}

	public int getM_intention_number() {
		return m_intention_number;
	}

	public void setM_intention_number(int intention_number) {
		m_intention_number = intention_number;
	}
}