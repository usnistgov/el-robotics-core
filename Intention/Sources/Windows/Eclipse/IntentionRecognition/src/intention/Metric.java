/****************************************************************************************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards and Technology (NIST), an agency of the U.S. government, and by 
   statute is not subject to copyright in the United States.  
   Recipients of this software assume all responsibility associated with its operation, modification, maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 ****************************************************************************************************************************************************/

package intention;


/**
 * \class Metric
 * 
 * \ingroup Likelihood
 * 
 * 
 * \brief Definition of additive and multiplicative metrics
 * 
 * This class consists of additive and multiplicative metrics definitions
 * 
 * \author zeidk
 * 
 * \date 2013/01/01
 * 
 * Contact: zeid.kootbally@nist.gov
 * 
 */
public class Metric {
	private static int m_AM1_weight;
	private static int m_AM2_weight;
	private static int m_AM3_weight;
	private static int m_AM4_weight;
	private static int m_AM5_weight;
	private static int m_MM1_weight;

	/**
	 * Get the weight for AM1.
	 * 
	 * @return The weight for AM1.
	 */
	public static int get_AM1_Weight() {
		return m_AM1_weight;
	}

	/**
	 * Get the weight for AM2.
	 * 
	 * @return The weight for AM2.
	 */
	public static int get_AM2_Weight() {
		return m_AM2_weight;
	}

	/**
	 * Get the weight for AM3.
	 * 
	 * @return The weight for AM3.
	 */
	public static int get_AM3_Weight() {
		return m_AM3_weight;
	}

	/**
	 * Get the weight for AM4.
	 * 
	 * @return The weight for AM4.
	 */
	public static int get_AM4_Weight() {
		return m_AM4_weight;
	}

	/**
	 * Get the weight for AM5.
	 * 
	 * @return The weight for AM5.
	 */
	public static int get_AM5_Weight() {
		return m_AM5_weight;
	}
	
	/**
	 * Get the weight for MM1.
	 * 
	 * @return The weight for MM1.
	 */
	private int get_MM1_Weight() {
		return this.m_MM1_weight;
	}

	/**
	 * Set the weight for AM1.
	 * 
	 * @param weight
	 *            Value set to the weight for AM1.
	 */
	public static void set_AM1_Weight(int weight) {
		m_AM1_weight = weight;
	}

	/**
	 * Set the weight for AM2.
	 * 
	 * @param weight
	 *            Value set to the weight for AM2.
	 */
	public static void set_AM2_Weight(int weight) {
		m_AM2_weight = weight;
	}

	/**
	 * Set the weight for AM3.
	 * 
	 * @param weight
	 *            Value set to the weight for AM3.
	 */
	public static void set_AM3_Weight(int weight) {
		m_AM3_weight = weight;
	}

	/**
	 * Set the weight for AM4.
	 * 
	 * @param weight
	 *            Value set to the weight for AM4.
	 */
	public static void set_AM4_Weight(int weight) {
		m_AM4_weight = weight;
	}

	/**
	 * Set the weight for AM5.
	 * 
	 * @param weight
	 *            Value set to the weight for AM5.
	 */
	public static void set_AM5_Weight(int weight) {
		m_AM5_weight = weight;
	}
	/**
	 * Set the weight for MM1.
	 * 
	 * @param weight
	 *            Value set to the weight for MM1.
	 */
	private void set_MM1_Weight(int weight) {
		m_MM1_weight = weight;
	}

}
