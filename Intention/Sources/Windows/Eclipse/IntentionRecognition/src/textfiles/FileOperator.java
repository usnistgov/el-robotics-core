/**
 * 
 */
package textfiles;

import gui.Chart;
import gui.OptionFrame;
import intention.Intention;
import intention.Metric;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import ontology.Ontology;

/**
 * @author zeid
 *
 */
public class FileOperator {

	/**
	 * 
	 */
	public FileOperator() {
		// TODO Auto-generated constructor stub
	}
	
	public String[] openFile(String path) throws IOException{
		FileReader fr = new FileReader(path);
		BufferedReader textReader = new BufferedReader(fr);
		
		int numberOfLines = readLines(path);
		String[] textData = new String[numberOfLines];
		
		for (int i=0; i <numberOfLines; i++){
			textData[i] = textReader.readLine();
		}
		
		textReader.close();
		
		return textData;
	}
	
	public int readLines(String path) throws IOException{
		FileReader file_to_read = new FileReader(path);
		BufferedReader bf = new BufferedReader(file_to_read);
		
		String aLine;
		int numberOfLines=0;
		
		while((aLine = bf.readLine()) != null){
			numberOfLines++;
		}
		bf.close();
		
		return numberOfLines;
	}

	public static void saveAllKitsData(String file_path_, FileWriter writer, String kit_, String plan_) throws IOException{
		
		//String metric_info = Metric.get_AM1_Weight() +"-"+ Metric.get_AM2_Weight() +"-"+Metric.get_AM3_Weight()+"-"+Metric.get_AM4_Weight()+"-"+Metric.get_AM5_Weight();
		String metric_info = Metric.get_AM1_Weight() +"-"+ Metric.get_AM2_Weight() +"-"+Metric.get_AM3_Weight()+"-"+Metric.get_AM4_Weight();
		
		String kit_build = null;
		if (kit_.toLowerCase().contains("a4b3c3"))
			kit_build="1";
		else if (kit_.toLowerCase().contains("a4b4c2"))
			kit_build="2";
		else if (kit_.toLowerCase().contains("a2b3c5"))
			kit_build="3";
		else if (kit_.toLowerCase().contains("a4b3c2d1"))
			kit_build="4";
		else if (kit_.toLowerCase().contains("a2b3c3d1e1"))
			kit_build="5";

		//String kit_build = "kit "+Intention.getM_built_kit();
		String plan_selected = null;

		
		String plan_name = plan_.substring(plan_.lastIndexOf('\\') + 1);




		if (plan_name.toLowerCase().contains("1-"))
			plan_selected="1";
		else if (plan_name.toLowerCase().contains("2-"))
			plan_selected="2";
		else if (plan_name.toLowerCase().contains("3-"))
			plan_selected="3";
		else if (plan_name.toLowerCase().contains("4-"))
			plan_selected="4";
		else if (plan_name.toLowerCase().contains("5-"))
			plan_selected="5";
		
		double likelihood;
		String kit = null;

		ArrayList<Double> kit_likelihood_list = null;
		
		ArrayList<ArrayList<Double>> list_of_list_of_likelihood = new ArrayList<ArrayList<Double>>(); 
		ArrayList<String> list_of_kit = new ArrayList<String>();
		for (int j = 0; j < Chart.m_LH_Dataset.getRowCount(); j++) {//--5
			kit_likelihood_list = new ArrayList<Double>(); 
			kit = Chart.m_LH_Dataset.getRowKey(j).toString();

			// -- Return the number of states in Chart.m_LH_Dataset
			for (int k = 0; k < Chart.m_LH_Dataset.getColumnCount(); k++) {//--10
				likelihood = (Double) Chart.m_LH_Dataset.getValue(j, k);
				kit_likelihood_list.add(likelihood);
			}
			list_of_list_of_likelihood.add(j, kit_likelihood_list);
			list_of_kit.add(j,kit);
		}
		
		ArrayList<Double> likelihoodList = list_of_list_of_likelihood.get(0);
		writer.write(metric_info+"\t"+1+"\t"+likelihoodList.get(0)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(1);
		writer.write(likelihoodList.get(0)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(2);
		writer.write(likelihoodList.get(0)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(3);
		writer.write(likelihoodList.get(0)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(4);
		writer.write(likelihoodList.get(0)+"\t");
		writer.write(kit_build+"\t"+plan_selected+"\n");
		
		//------------------------------------------------- 1
		likelihoodList = list_of_list_of_likelihood.get(0);
		writer.write(metric_info+"\t"+2+"\t"+likelihoodList.get(1)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(1);
		writer.write(likelihoodList.get(1)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(2);
		writer.write(likelihoodList.get(1)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(3);
		writer.write(likelihoodList.get(1)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(4);
		writer.write(likelihoodList.get(1)+"\t");
		writer.write(kit_build+"\t"+plan_selected+"\n");
		//------------------------------------------------- 2
		likelihoodList = list_of_list_of_likelihood.get(0);
		writer.write(metric_info+"\t"+3+"\t"+likelihoodList.get(2)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(1);
		writer.write(likelihoodList.get(2)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(2);
		writer.write(likelihoodList.get(2)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(3);
		writer.write(likelihoodList.get(2)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(4);
		writer.write(likelihoodList.get(2)+"\t");
		writer.write(kit_build+"\t"+plan_selected+"\n");
		//------------------------------------------------- 3
		likelihoodList = list_of_list_of_likelihood.get(0);
		writer.write(metric_info+"\t"+4+"\t"+likelihoodList.get(3)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(1);
		writer.write(likelihoodList.get(3)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(2);
		writer.write(likelihoodList.get(3)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(3);
		writer.write(likelihoodList.get(3)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(4);
		writer.write(likelihoodList.get(3)+"\t");
		writer.write(kit_build+"\t"+plan_selected+"\n");
		//------------------------------------------------- 4
		likelihoodList = list_of_list_of_likelihood.get(0);
		writer.write(metric_info+"\t"+5+"\t"+likelihoodList.get(4)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(1);
		writer.write(likelihoodList.get(4)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(2);
		writer.write(likelihoodList.get(4)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(3);
		writer.write(likelihoodList.get(4)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(4);
		writer.write(likelihoodList.get(4)+"\t");
		writer.write(kit_build+"\t"+plan_selected+"\n");
		//------------------------------------------------- 5
		likelihoodList = list_of_list_of_likelihood.get(0);
		writer.write(metric_info+"\t"+6+"\t"+likelihoodList.get(5)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(1);
		writer.write(likelihoodList.get(5)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(2);
		writer.write(likelihoodList.get(5)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(3);
		writer.write(likelihoodList.get(5)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(4);
		writer.write(likelihoodList.get(5)+"\t");
		writer.write(kit_build+"\t"+plan_selected+"\n");
		//------------------------------------------------- 6
		likelihoodList = list_of_list_of_likelihood.get(0);
		writer.write(metric_info+"\t"+7+"\t"+likelihoodList.get(6)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(1);
		writer.write(likelihoodList.get(6)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(2);
		writer.write(likelihoodList.get(6)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(3);
		writer.write(likelihoodList.get(6)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(4);
		writer.write(likelihoodList.get(6)+"\t");
		writer.write(kit_build+"\t"+plan_selected+"\n");
		//------------------------------------------------- 7
		likelihoodList = list_of_list_of_likelihood.get(0);
		writer.write(metric_info+"\t"+8+"\t"+likelihoodList.get(7)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(1);
		writer.write(likelihoodList.get(7)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(2);
		writer.write(likelihoodList.get(7)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(3);
		writer.write(likelihoodList.get(7)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(4);
		writer.write(likelihoodList.get(7)+"\t");
		writer.write(kit_build+"\t"+plan_selected+"\n");
		//------------------------------------------------- 8
		likelihoodList = list_of_list_of_likelihood.get(0);
		writer.write(metric_info+"\t"+9+"\t"+likelihoodList.get(8)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(1);
		writer.write(likelihoodList.get(8)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(2);
		writer.write(likelihoodList.get(8)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(3);
		writer.write(likelihoodList.get(8)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(4);
		writer.write(likelihoodList.get(8)+"\t");
		writer.write(kit_build+"\t"+plan_selected+"\n");
		//------------------------------------------------- 9
		likelihoodList = list_of_list_of_likelihood.get(0);
		writer.write(metric_info+"\t"+10+"\t"+likelihoodList.get(9)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(1);
		writer.write(likelihoodList.get(9)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(2);
		writer.write(likelihoodList.get(9)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(3);
		writer.write(likelihoodList.get(9)+"\t");

		likelihoodList = list_of_list_of_likelihood.get(4);
		writer.write(likelihoodList.get(9)+"\t");
		writer.write(kit_build+"\t"+plan_selected+"\n\n");
		
	}
	
	public ArrayList<ArrayList<ArrayList<String>>> translatePlanToStateRelation(String[] plan){
		//-- list that contains a set of states
		ArrayList<ArrayList<ArrayList<String>>> States = new ArrayList<ArrayList<ArrayList<String>>>();
		
		int i_red = 0; 
		int i_green = 0; 
		int i_blue = 0;
		int i_yellow = 0; 
		int i_orange = 0;
		
		String part_individual = null;
		String sku_individual = null;
		String state_relation = "PartiallyIn";
		String kit_tray_individual = "kit_tray_1_ir";
		String kit_tray_Class = "KitTray";
		
		for (int i=0; i<plan.length; i++){
			if (plan[i].matches(".*\\b"+ "red"+ "\\b.*")){
				i_red++;
				part_individual = "part_a_"+i_red+"_ir"; 
				sku_individual="stock_keeping_unit_parts_a_tray_ir";
			}
			else if (plan[i].matches(".*\\b"+ "green"+ "\\b.*")){
				i_green++;
				part_individual = "part_b_"+i_green+"_ir";
				sku_individual="stock_keeping_unit_parts_b_tray_ir";
			}
			else if (plan[i].matches(".*\\b"+ "blue"+ "\\b.*")){
				i_blue++;
				part_individual = "part_c_"+i_blue+"_ir";
				sku_individual="stock_keeping_unit_parts_c_tray_ir";
			}
			else if (plan[i].matches(".*\\b"+ "yellow"+ "\\b.*")){
				i_yellow++;
				part_individual = "part_e_"+i_yellow+"_ir";
				sku_individual="stock_keeping_unit_parts_e_tray_ir";
			}
			else if (plan[i].matches(".*\\b"+ "orange"+ "\\b.*")){
				i_orange++;
				part_individual = "part_d_"+i_orange+"_ir";
				sku_individual="stock_keeping_unit_parts_d_tray_ir";
			}
			//-- list that contains elements of a state relation
			ArrayList<String> list_state_relation_element = new ArrayList<String>();
			//-- list that contains a state relation
			ArrayList<ArrayList<String>> list_of_state_relation = new ArrayList<ArrayList<String>>();
			
			list_state_relation_element.add(state_relation);
			list_state_relation_element.add(part_individual);
			list_state_relation_element.add(sku_individual);
			list_state_relation_element.add(kit_tray_individual);
			list_state_relation_element.add(kit_tray_Class);
			System.out.println(
					list_state_relation_element.get(0)
					+","
					+list_state_relation_element.get(1)
					+","
					+list_state_relation_element.get(2)
					+","
					+list_state_relation_element.get(3)
					+","
					+list_state_relation_element.get(4)
					);
			
			list_of_state_relation.add(list_state_relation_element);
			States.add(list_of_state_relation);
		}
		return States;
	}
}
