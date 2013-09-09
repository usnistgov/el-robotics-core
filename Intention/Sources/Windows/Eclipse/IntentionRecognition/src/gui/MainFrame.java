// Decompiled by Jad v1.5.8e2. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://kpdus.tripod.com/jad.html
// Decompiler options: packimports(3) fieldsfirst ansi space 

package gui;


import intention.Intention;
import intention.Metric;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Toolkit;
import java.awt.datatransfer.Clipboard;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JComponent;
import javax.swing.JEditorPane;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JButton;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JTabbedPane;
import javax.swing.JTextPane;
import javax.swing.JTree;
import javax.swing.UIManager;
import javax.swing.WindowConstants;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.text.BadLocationException;
import javax.swing.text.DefaultCaret;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeCellRenderer;
import javax.swing.tree.TreePath;
import javax.swing.tree.TreeSelectionModel;

import ontology.Ontology;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.ChartTransferable;
import org.jfree.chart.ChartUtilities;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.StandardChartTheme;
import org.jfree.data.category.DefaultCategoryDataset;
import org.jfree.ui.ApplicationFrame;
import org.jfree.util.StringUtils;




import tools.UI;
import treecheckbox.CheckTreeManager;

// Referenced classes of package demo:
//			MemoryUsageDemo, DemoPanel, DemoDescription

public class MainFrame extends JFrame implements ActionListener {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1384873058265918162L;


	private static StyledDocument _sd;
	public static final String EXIT_COMMAND = "EXIT";
	private JPanel likelihood_displayPanel;
	private JPanel likelihood_chartContainer;
	private JPanel likelihood_stateContainer;
	public static JTextPane likelihood_bottomRightPane = new JTextPane();
	public static JTextPane metrics_statePane = new JTextPane();
	private JEditorPane editorPane;
	public static JTextPane likelihoodLeft_JTextPane = new JTextPane();
	public static JTextPane metricsLeft_JTextPane = new JTextPane();
	public static JScrollPane metricsLeft_JScrollPane = new JScrollPane();
	public static JPanel metricsLeft_JPanel = new JPanel();
	public static JPanel m_LH_Left_Panel = new JPanel();
	public static JPanel metrics_chartContainer;
	private Chart m_likelihood_barchart = new Chart();
	private Chart m_metrics_barchart = new Chart();
	private static JSplitPane metrics_jsplitpane;
	private static JSplitPane m_LH_SplitPane;
	private static JScrollPane m_metrics_jscrollpane = new JScrollPane();
	private static JScrollPane m_LH_ScrollPane = new JScrollPane();
	CheckTreeManager m_metricCheckTreeManager;
	CheckTreeManager m_likelihoodCheckTreeManager;
	public static JButton m_metricsSelectionButton;
	public static JButton m_LH_Selection_Button;
	public static JTree m_metricTree;
	public static JTree m_likelihoodTree;

	public static JMenuItem m_csvitem = new JMenuItem("Export to CSV...", 112);

	public MainFrame(String s, JTree metricTree, JTree likelihoodTree) {
		super(s);
		m_metricTree=metricTree;
		m_likelihoodTree=likelihoodTree;
		setDefaultCloseOperation(WindowConstants.HIDE_ON_CLOSE);
		setContentPane(createContent(m_metricTree,m_likelihoodTree));
		setJMenuBar(createMenuBar());

		/*
		WindowListener exitListener = new WindowAdapter() {

            @Override
            public void windowClosing(WindowEvent e) {
                int confirm = JOptionPane.showOptionDialog(null, "Are You Sure to Close Application?", "Exit Confirmation", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE, null, null, null);
                if (confirm == 0) {
                   dispose();
                }
            }
        };
        this.addWindowListener(exitListener);
		 */
		/*
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent we) {
				System.out.println(getTitle() +" says Bye-Bye!  " +new java.util.Date());
				OptionFrame.m_frame.setVisible(true);
				setVisible(false);
			}
		});
		 */
	}


	private JPanel buildMetricPanel(JTree metricTree){
		JPanel metrics_jpanel = new JPanel(new BorderLayout());
		metrics_jpanel.setBackground(UI.chartPanelColor);
		metrics_jpanel.setBorder(BorderFactory.createEmptyBorder(4, 4, 4, 4));

		metrics_jsplitpane = new JSplitPane(1);
		metrics_jsplitpane.setBackground(UI.JTabbedPaneColor);

		metricTree.setBackground(UI.chartLeftPaneColor);
		metricTree.setBorder(BorderFactory.createLineBorder(UI.JTabbedPaneColor));

		//-- Select colors for the JTree
		if (metricTree.getCellRenderer() instanceof DefaultTreeCellRenderer)
		{
			final DefaultTreeCellRenderer renderer = 
					(DefaultTreeCellRenderer)(metricTree.getCellRenderer());
			renderer.setBackgroundNonSelectionColor(Color.WHITE);
			renderer.setBackgroundSelectionColor(UI.chartPanelColor);
			renderer.setTextNonSelectionColor(Color.BLACK);
			renderer.setTextSelectionColor(Color.BLACK);
		}



		m_metricCheckTreeManager = new CheckTreeManager(metricTree); 
		metricTree.setEnabled(false);

		metricTree.setFont(new Font("Times",Font.PLAIN, 11));

		for(int i=0; i<metricTree.getRowCount(); i++) {
			metricTree.expandRow(i);

		}

		// Add the tree to a scrolling pane
		m_metrics_jscrollpane = new JScrollPane();
		m_metrics_jscrollpane.setPreferredSize(new Dimension(350, 680));
		m_metrics_jscrollpane.setBorder(BorderFactory.createLineBorder(UI.chartLeftPaneColor));
		m_metrics_jscrollpane.getViewport().add(metricTree);

		JLabel information = new JLabel();
		information.setText("<html><b><center><font color=rgb(160, 188, 136)>Select the metrics you want to display.<br>Press the OK button.</font></center></b></html>");
		metricsLeft_JPanel.setPreferredSize(new Dimension(350, 700));
		metricsLeft_JPanel.setBackground(UI.chartLeftPaneColor);
		metricsLeft_JPanel.add(information, BorderLayout.CENTER );
		metricsLeft_JPanel.add(m_metrics_jscrollpane, BorderLayout.CENTER );
		m_metricsSelectionButton = new JButton("OK");
		DisplayMetrics metricsButtonListener = new DisplayMetrics();
		m_metricsSelectionButton.addActionListener(metricsButtonListener);
		m_metricsSelectionButton.setBackground(UI.chartPanelColor);
		m_metricsSelectionButton.setForeground(Color.BLACK);
		m_metricsSelectionButton.setEnabled(false);
		metricsLeft_JPanel.add(m_metricsSelectionButton, BorderLayout.CENTER);

		metrics_jsplitpane.setLeftComponent(metricsLeft_JPanel);
		metrics_jsplitpane.setRightComponent(createMetricsChartPanel());

		metrics_jpanel.add(metrics_jsplitpane);

		return metrics_jpanel;
	}

	/**
	 * @brief Build the main panel that contains components for the likelihoods
	 * @param likelihoodTree The JTree that displays intentions
	 * @return
	 */
	private JPanel buildLikelihoodPanel(JTree likelihoodTree){

		//------------------------------------------------------
		// MAIN PANEL
		//------------------------------------------------------
		JPanel LH_Main_Panel = new JPanel(new BorderLayout());
		LH_Main_Panel.setBackground(UI.chartPanelColor);
		LH_Main_Panel.setBorder(BorderFactory.createEmptyBorder(4, 4, 4, 4));

		//------------------------------------------------------
		// SPLIT PANE
		//------------------------------------------------------
		m_LH_SplitPane = new JSplitPane(1);
		m_LH_SplitPane.setBackground(UI.JTabbedPaneColor);

		//------------------------------------------------------
		// JTREE
		//------------------------------------------------------
		likelihoodTree.setBackground(UI.chartLeftPaneColor);
		likelihoodTree.setBorder(BorderFactory.createLineBorder(UI.JTabbedPaneColor));
		likelihoodTree.setFont(new Font("Times",Font.PLAIN, 11));
		likelihoodTree.setEnabled(false);

		//-- Set the appearance of the tree
		if (likelihoodTree.getCellRenderer() instanceof DefaultTreeCellRenderer)
		{
			final DefaultTreeCellRenderer renderer = 
					(DefaultTreeCellRenderer)(likelihoodTree.getCellRenderer());
			renderer.setBackgroundNonSelectionColor(Color.WHITE);
			renderer.setBackgroundSelectionColor(UI.chartPanelColor);
			renderer.setTextNonSelectionColor(Color.BLACK);
			renderer.setTextSelectionColor(Color.BLACK);
		}


		m_likelihoodCheckTreeManager = new CheckTreeManager(likelihoodTree); 

		//-- Expand the whole tree
		for(int i=0; i<likelihoodTree.getRowCount(); i++) {
			likelihoodTree.expandRow(i);

		}

		// -- These next 2 lines allow the JScrollPane to scroll
		// -- automatically when new text is added
		//DefaultCaret LH_tree_caret = (DefaultCaret) likelihoodLeft_JTextPane.getCaret();
		//likelihoods_caret.setUpdatePolicy(DefaultCaret.ALWAYS_UPDATE);

		//------------------------------------------------------
		// SCROLL PANE
		//------------------------------------------------------
		m_LH_ScrollPane = new JScrollPane();
		m_LH_ScrollPane.setPreferredSize(new Dimension(350, 680));
		m_LH_ScrollPane.setBorder(BorderFactory.createLineBorder(UI.chartLeftPaneColor));
		m_LH_ScrollPane.getViewport().add(likelihoodTree);

		//-- Instructions
		JLabel JlikelihoodLabel = new JLabel();
		JlikelihoodLabel.setText("<html><b><center><font color=rgb(160, 188, 136)>Select the intention(s) you want to display.<br>Press the OK button.</font></center></b></html>");

		m_LH_Left_Panel.setPreferredSize(new Dimension(350, 700));
		m_LH_Left_Panel.setBackground(UI.chartLeftPaneColor);

		m_LH_Selection_Button = new JButton("OK");
		m_LH_Selection_Button.setBackground(UI.chartPanelColor);
		m_LH_Selection_Button.setForeground(Color.BLACK);
		m_LH_Selection_Button.setEnabled(false);
		m_LH_Selection_Button.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				lh_Button_ActionPerformed(evt);
			}
		});

		//-- Add everything in likelihoodLeft_JPanel 
		m_LH_Left_Panel.add(JlikelihoodLabel, BorderLayout.CENTER );
		m_LH_Left_Panel.add(m_LH_ScrollPane, BorderLayout.CENTER );
		m_LH_Left_Panel.add(m_LH_Selection_Button, BorderLayout.CENTER);

		//-- Build components for the JSplitPane
		m_LH_SplitPane.setLeftComponent(m_LH_Left_Panel);
		m_LH_SplitPane.setRightComponent(createLikelihoodChartPanel());

		//-- Build the main panel to display all the components
		//-- for the likelihood
		LH_Main_Panel.add(m_LH_SplitPane);

		return LH_Main_Panel;
	}

	private JComponent createContent(JTree metricTree, JTree likelihoodTree) {
		JPanel jpanel = new JPanel(new BorderLayout());
		jpanel.setBackground(UI.chartPanelColor);
		UIManager.put("TabbedPane.selected", UI.JFreeChartBackground);
		JTabbedPane jtabbedpane = new JTabbedPane();

		JPanel LH_Main_Panel = buildLikelihoodPanel(likelihoodTree);
		JPanel M_Main_Panel = buildMetricPanel(metricTree);

		//-- Create a tab for Likelihoods and Metrics
		jtabbedpane.add("Likelihoods", LH_Main_Panel);
		jtabbedpane.add("Metrics", M_Main_Panel);
		jtabbedpane.setBackground(UI.tabColor);
		jtabbedpane.setBorder(BorderFactory.createEmptyBorder(4, 4, 4, 4));
		jpanel.add(jtabbedpane);

		return jpanel;
	}

	private void lh_Button_ActionPerformed(java.awt.event.ActionEvent evt) {
		// TODO add your handling code here:
		DefaultCategoryDataset likelihoodDataset = new DefaultCategoryDataset();
		TreePath checkedPaths[] = m_likelihoodCheckTreeManager
				.getSelectionModel()
				.getSelectionPaths();

		// -- if no selection is made
		if (checkedPaths == null) {
			showErrorMessage(
					"Intention Selection Alert !",
					"<html><b><font color=#151b8d>Please select at least one intention !!</font></b></html>");
		} else {
			ArrayList<Object> list = m_likelihoodCheckTreeManager.getAllCheckedPaths(m_likelihoodCheckTreeManager, m_likelihoodTree);

			for (int i = 0; i < list.size(); i++) {
				TreePath p = (TreePath) list.get(i);

				if (p.getPathCount() > 1) {

					for (int j = 0; j < Chart.m_LH_Dataset
							.getRowCount(); j++) {


						//System.out.println("m_LH_Dataset Rowkey "+ Chart.m_LH_Dataset.getRowKey(j));
						//System.out.println("p.getPathComponent(1).toString() "+ p.getPathComponent(1).toString());


						// -- Retrieve Chart.m_LH_Dataset information from the results of p

						if (Chart.m_LH_Dataset.getRowKey(j).toString().matches(".*\\b"+ p.getPathComponent(1).toString()+ "\\b.*")) {

							// -- Return the number of states in Chart.m_metricDataset
							for (int k = 0; k < Chart.m_LH_Dataset.getColumnCount(); k++) {
								//System.out.println("m_metricDataset Value "+ Chart.m_metricsDataset.getValue(j, k));
								//System.out.println("m_metricDataset Column Key "+ Chart.m_metricsDataset.getColumnKey(k));
								likelihoodDataset.addValue(Chart.m_LH_Dataset.getValue(j, k),
										Chart.m_LH_Dataset.getRowKey(j).toString(),
										Chart.m_LH_Dataset.getColumnKey(k).toString());
							}
						}

					}

				}
			}



			likelihood_chartContainer.removeAll();
			likelihood_chartContainer.repaint();
			m_likelihood_barchart.m_tmp_LH_ChartPanel = m_likelihood_barchart.updateChart_likelihood(likelihoodDataset);
			m_likelihood_barchart.m_tmp_LH_ChartPanel.setMouseWheelEnabled(true);
			m_likelihood_barchart.m_tmp_LH_ChartPanel.setAutoscrolls(true);
			likelihood_chartContainer.add(m_likelihood_barchart.m_tmp_LH_ChartPanel, BorderLayout.CENTER);
			m_LH_SplitPane.repaint();
			likelihood_chartContainer.repaint();
			likelihood_chartContainer.updateUI();
			m_LH_SplitPane.updateUI();
		}
	}

	public static void updateStateRelationPanel(String s, Color c, JTextPane textpane) {
		_sd = textpane.getStyledDocument();
		Style style = textpane.addStyle("Red", null);
		StyleConstants.setForeground(style, c);

		try {
			_sd.insertString(_sd.getLength(), s, style);
		} catch (BadLocationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private JMenuBar createMenuBar() {
		JMenuBar jmenubar = new JMenuBar();
		jmenubar.setBackground(Color.white);
		JMenu jmenu = new JMenu("File", true);
		jmenu.setBackground(Color.white);
		jmenu.setMnemonic('F');

		JMenuItem pdfitem = new JMenuItem("Export to PDF...", 112);
		pdfitem.setActionCommand("EXPORT_TO_PDF");
		pdfitem.setEnabled(false);
		pdfitem.addActionListener(this);

		m_csvitem.setActionCommand("EXPORT_TO_CSV");
		m_csvitem.setEnabled(false);
		m_csvitem.addActionListener(this);


		jmenu.add(pdfitem);
		jmenu.addSeparator();
		jmenu.add(m_csvitem);
		jmenu.addSeparator();
		JMenuItem jmenuitem1 = new JMenuItem("Exit", 120);
		jmenuitem1.setActionCommand("EXIT");
		jmenuitem1.addActionListener(this);
		jmenu.add(jmenuitem1);
		jmenubar.add(jmenu);
		JMenu jmenu1 = new JMenu("Edit", false);
		jmenu1.setBackground(Color.white);
		jmenubar.add(jmenu1);
		JMenuItem jmenuitem2 = new JMenuItem("Copy", 67);
		jmenuitem2.setActionCommand("COPY");
		jmenuitem2.addActionListener(this);
		jmenu1.add(jmenuitem2);

		return jmenubar;
	}

	/*
	 * private void updateSourceCodePanel(String s) { }
	 */
	private void copyToClipboard() {
		JFreeChart jfreechart = null;
		int i = 0;
		int j = 0;
		java.awt.Component component = likelihood_chartContainer.getComponent(0);
		if (component instanceof ChartPanel) {
			ChartPanel chartpanel = (ChartPanel) component;
			jfreechart = chartpanel.getChart();
			i = chartpanel.getWidth();
			j = chartpanel.getHeight();
		} else if (component instanceof DemoPanel) {
			DemoPanel demopanel = (DemoPanel) component;
			jfreechart = (JFreeChart) demopanel.charts.get(0);
			i = demopanel.getWidth();
			j = demopanel.getHeight();
		}
		if (jfreechart != null) {
			Clipboard clipboard = Toolkit.getDefaultToolkit()
					.getSystemClipboard();
			ChartTransferable charttransferable = new ChartTransferable(
					jfreechart, i, j);
			clipboard.setContents(charttransferable, null);
		}
	}

	public void actionPerformed(ActionEvent actionevent) {
		String s = actionevent.getActionCommand();
		if (s.equals("EXPORT_TO_PDF"))
			exportToPDF();
		else if (s.equals("EXPORT_TO_CSV"))
			exportToCSV();
		else if (s.equals("COPY"))
			copyToClipboard();
		else if (s.equals("LEGACY_THEME")) {
			ChartFactory.setChartTheme(StandardChartTheme.createLegacyTheme());
			applyThemeToChart();
		} else if (s.equals("JFREE_THEME")) {
			ChartFactory.setChartTheme(StandardChartTheme.createJFreeTheme());
			applyThemeToChart();
		} else if (s.equals("DARKNESS_THEME")) {
			ChartFactory
			.setChartTheme(StandardChartTheme.createDarknessTheme());
			applyThemeToChart();
		} else if (s.equals("EXIT"))
			attemptExit();
	}

	private void applyThemeToChart() {
		java.awt.Component component = likelihood_chartContainer.getComponent(0);
		if (component instanceof ChartPanel) {
			ChartPanel chartpanel = (ChartPanel) component;
			ChartUtilities.applyCurrentTheme(chartpanel.getChart());
		} else if (component instanceof DemoPanel) {
			DemoPanel demopanel = (DemoPanel) component;
			JFreeChart ajfreechart[] = demopanel.getCharts();
			for (int i = 0; i < ajfreechart.length; i++)
				ChartUtilities.applyCurrentTheme(ajfreechart[i]);

		}
	}

	private void exportToPDF() {
	}

	/**
	 * @brief Create the file @a file and write intention dataset
	 * @param file
	 */
	public void saveToCSV(String path){
		BufferedWriter writer = null;
		//String metric_info = Metric.get_AM1_Weight() +"-"+ Metric.get_AM2_Weight() +"-"+Metric.get_AM3_Weight()+"-"+Metric.get_AM4_Weight()+"-"+Metric.get_AM5_Weight();
		String metric_info = Metric.get_AM1_Weight() +"-"+ Metric.get_AM2_Weight() +"-"+Metric.get_AM3_Weight()+"-"+Metric.get_AM4_Weight();

		String kit_build = null;
		if (Intention.getM_built_kit().toLowerCase().contains("a4b3c3"))
			kit_build="1";
		else if (Intention.getM_built_kit().toLowerCase().contains("a4b4c2"))
			kit_build="2";
		else if (Intention.getM_built_kit().toLowerCase().contains("a2b3c5"))
			kit_build="3";
		else if (Intention.getM_built_kit().toLowerCase().contains("a4b3c2d1"))
			kit_build="4";
		else if (Intention.getM_built_kit().toLowerCase().contains("a2b3c3d1e1"))
			kit_build="5";

		//String kit_build = "kit "+Intention.getM_built_kit();
		String plan_selected = null;


		if (Intention.getM_selected_plan().toLowerCase().contains("1-"))
			plan_selected="1";
		else if (Intention.getM_selected_plan().toLowerCase().contains("2-"))
			plan_selected="2";
		else if (Intention.getM_selected_plan().toLowerCase().contains("3-"))
			plan_selected="3";
		else if (Intention.getM_selected_plan().toLowerCase().contains("4-"))
			plan_selected="4";
		else if (Intention.getM_selected_plan().toLowerCase().contains("5-"))
			plan_selected="5";

		double likelihood;
		String kit = null;

		Map<String, ArrayList<Double> > kit_likelihood = new HashMap<String, ArrayList<Double> >();
		ArrayList<Double> kit_likelihood_list = null;


		try {
			writer = new BufferedWriter(new FileWriter(path));
			writer.write("AM Weight\t"+"State\t");

			//-- Build an array list that contains intention's name
			/*
			for (int k = 0; k < Ontology.m_intention_list.size(); k++) {
				Intention intention = Ontology.m_intention_list.get(k);

				writer.write(intention.getM_intention_number()+"\t");
				//System.out.print(intention.getIntentionName()+"\t");
				//intention_list.add(intention.getIntentionName());
			}
			*/
			
			for (int j = 0; j < Chart.m_LH_Dataset.getRowCount(); j++) {
				//System.out.println(Chart.m_LH_Dataset.getRowKey(j));
				writer.write(Chart.m_LH_Dataset.getRowKey(j).toString()+"\t");
			}
			
			
			//System.out.println("Kit Built \t Plan #");
			//System.exit(0);
			writer.write("Kit # \t Plan #");
			writer.write("\n");
			//System.out.println(Chart.m_LH_Dataset.getRowCount()); //-- 5
			//System.out.println(Chart.m_LH_Dataset.getColumnCount()); //-- 10

			ArrayList<ArrayList<Double>> list_of_list_of_likelihood = new ArrayList<ArrayList<Double>>(); 
			ArrayList<String> list_of_kit = new ArrayList<String>();
			for (int j = 0; j < Chart.m_LH_Dataset.getRowCount(); j++) {//--5
				kit_likelihood_list = new ArrayList<Double>(); 

				kit = Chart.m_LH_Dataset.getRowKey(j).toString();


				// -- Return the number of states in Chart.m_LH_Dataset
				for (int k = 0; k < Chart.m_LH_Dataset.getColumnCount(); k++) {//--10
					likelihood = (Double) Chart.m_LH_Dataset.getValue(j, k);

					//System.out.print(kit+"\t"+likelihood +"\n");
					//state = Chart.m_LH_Dataset.getColumnKey(k).toString();
					kit_likelihood_list.add(likelihood);

					//System.out.print(kit+"\t"+metric_info+"\t"+likelihood +"\n");
					//System.out.print(kit+"\n");
					//System.exit(0);
				}
				//System.out.print("\n\n");
				//System.out.print("++ "+kit+"\n");
				kit_likelihood.put(kit, kit_likelihood_list);
				list_of_list_of_likelihood.add(j, kit_likelihood_list);
				list_of_kit.add(j,kit);
			}

			/*
			for (int i = 0; i < list_of_kit.size(); i++) {
					System.out.println(list_of_kit.get(i).toString());
			}
			*/
			
			
			//for (int i = 0; i < list_of_list_of_likelihood.size(); i++) {//--5
			//------------------------------------------------- 0
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
				
				
				//for (int j = 0; j < likelihoodList.size(); j++) {//--10
				//	System.out.print(likelihoodList.get(0).toString()+"\n");
				//}
				//System.out.print("\n");
			//}
			
			
			
			/*
			//for (int i = 0; i < list_of_list_of_likelihood.size(); i++) {//--5 kits
				for (int j = 0; j < list_of_list_of_likelihood.get(0).size(); j++) {//--10 states
					System.out.print(metric_info+"\t"+((int)j+1)+"\t");
					//System.out.print(list_of_kit.get(i).toString()+"\t");
					//writer.write(metric_info+"\t"+((int)j+1)+"\t");
					//writer.write(list_of_list_of_likelihood.get(i).get(j).toString()+"\t");
					
					ArrayList likelihood_list = list_of_list_of_likelihood.get(j);
					
					for (int k = 0; k < likelihood_list.size(); k++) {
						System.out.print(likelihood_list.get(k).toString()+"\t");
					}
					System.out.print("\n");
					//System.out.println(list_of_list_of_likelihood.get(j).get(k).toString());
					//if ((int)j==list_of_list_of_likelihood.get(i).size()-1)
						//System.out.print(kit_build+"\t"+plan_selected);
						//writer.write(kit_build+"\t"+plan_selected);
				}
				
				*/
				//writer.write("\n");
			//}
			/*
			Iterator map_it = kit_likelihood.entrySet().iterator();
			while (map_it.hasNext()) {
				Map.Entry e = (Map.Entry) map_it.next ();
				ArrayList list_likelihood = kit_likelihood.get(e.getKey());
				System.out.print(e.getKey() +"\n");
				for (int j=0; j < list_likelihood.size(); j++) {
					//System.out.print(e.getKey()+"\t"+list_likelihood.get(j) +"\n");
					//System.out.print(e.getKey() +"\n");
					//writer.write(metric_info+"\t"+((int)j+1)+"\t");
					//writer.write(list_likelihood.get(j)+"\t");
				}
				System.out.print("\n");
			}*/
			
			/*
			System.exit(0);
			//System.out.println(Chart.m_LH_Dataset.getColumnCount());
			//System.exit(0);

			for (int i=0; i<Chart.m_LH_Dataset.getColumnCount(); i++){

				int counter=0;
				//System.out.print(metric_info+"\t"+((int)i+1)+"\t");
				writer.write(metric_info+"\t"+((int)i+1)+"\t");
				Iterator map_iterator = kit_likelihood.entrySet().iterator();
				while (map_iterator.hasNext()) {
					Map.Entry e = (Map.Entry) map_iterator.next ( ) ;
					ArrayList list_likelihood = kit_likelihood.get(e.getKey());
					counter++;

					writer.write(list_likelihood.get(i)+"\t");
					
					if (counter== kit_likelihood.size())
						writer.write(kit_build+"\t"+plan_selected);
				}
				writer.write("\n");
				
			}
			*/

		} catch (IOException e) {
			System.err.println(e);
		} finally {
			if (writer != null) {
				try {
					writer.close();
				} catch (IOException e) {
					System.err.println(e);
				}
			}
		}
	}

	/**
	 * @brief Export likelihoods result to a csv file
	 */
	private void exportToCSV() {
		JFileChooser jFileChooser = new JFileChooser();
		String metric_info = Metric.get_AM1_Weight() +"-"+ Metric.get_AM2_Weight() +"-"+Metric.get_AM3_Weight()+"-"+Metric.get_AM4_Weight()+"-";
		String plan_selected = Intention.getM_selected_plan();

		jFileChooser.setSelectedFile(new File(metric_info.toString()+"--"+Intention.getM_built_kit()+"--"+plan_selected+".csv"));
		if (jFileChooser.showSaveDialog(this) == JFileChooser.APPROVE_OPTION){
			saveToCSV(jFileChooser.getSelectedFile().getAbsolutePath());
		}
	}



	private void attemptExit() {
		String s = "Confirm";
		String s1 = "Are you sure you want to exit this window?";
		int i = JOptionPane.showConfirmDialog(this, s1, s, 0, 3);
		if (i == 0) {
			dispose();
			//System.exit(0);
		}
	}

	/**
	 * @brief Create the chart panel that will contain the likelihood chart.
	 * @return The likelihood panel.
	 */
	private JPanel createLikelihoodChartPanel() {
		likelihood_displayPanel = new JPanel(new BorderLayout());
		likelihood_displayPanel.setBackground(UI.chartPanelColor);

		// -- Add a barcharupdate in chartContainer
		likelihood_chartContainer = new JPanel(new BorderLayout());
		likelihood_chartContainer.setBackground(UI.chartPanelColor);
		likelihood_chartContainer.setBorder(BorderFactory.createCompoundBorder(
				BorderFactory.createEmptyBorder(4, 4, 4, 4),
				BorderFactory.createLineBorder(Color.black)));
		likelihood_chartContainer.add(m_likelihood_barchart.m_LH_chartPanel, BorderLayout.CENTER);

		likelihood_stateContainer = new JPanel(new BorderLayout());
		likelihood_stateContainer.setBackground(UI.chartPanelColor);
		likelihood_stateContainer.setBorder(BorderFactory.createEmptyBorder(4, 4, 4, 4));
		likelihood_stateContainer.setPreferredSize(new Dimension(1000, 400));


		//-- The JTextPane that displays information on state relations
		likelihood_bottomRightPane.setEditable(false);
		likelihood_bottomRightPane.setFont(UI.m_stateRelationFont);
		// -- These next 2 lines allow the JScrollPane to scroll
		// -- automatically when new text is added
		DefaultCaret caret = (DefaultCaret) likelihood_bottomRightPane.getCaret();
		caret.setUpdatePolicy(DefaultCaret.ALWAYS_UPDATE);

		JScrollPane jscrollpane = new JScrollPane(likelihood_bottomRightPane, 20, 31);
		likelihood_stateContainer.add(jscrollpane);

		JSplitPane jsplitpane = new JSplitPane(0);
		jsplitpane.setTopComponent(likelihood_chartContainer);
		jsplitpane.setBottomComponent(likelihood_stateContainer);
		likelihood_displayPanel.add(jsplitpane);
		jsplitpane.setDividerLocation(0.75D);

		return likelihood_displayPanel;
	}

	/**
	 * @brief Build the JPanel that will contain the chart displaying metrics values.
	 * @return The JPanel that will contain the chart displaying metrics values.
	 */
	private JPanel createMetricsChartPanel() {
		JPanel metrics_displayPanel = new JPanel(new BorderLayout());

		// -- Add a barcharupdate in chartContainer
		metrics_chartContainer = new JPanel(new BorderLayout());
		metrics_chartContainer.setBorder(BorderFactory.createCompoundBorder(
				BorderFactory.createEmptyBorder(4, 4, 4, 4),
				BorderFactory.createLineBorder(UI.JFreeChartBackground)));
		metrics_chartContainer.add(m_metrics_barchart.m_Metric_chartPanel, BorderLayout.CENTER);
		metrics_chartContainer.setBackground(UI.JFreeChartBackground);

		JPanel metrics_stateContainer = new JPanel(new BorderLayout());
		//metrics_stateContainer.setBackground(Color.BLACK);
		metrics_stateContainer.setBorder(BorderFactory.createEmptyBorder(4, 4, 4, 4));
		metrics_stateContainer.setPreferredSize(new Dimension(1000, 200));


		metrics_statePane.setEditable(false);
		//metrics_statePane.setBackground(Color.BLACK);
		// -- These next 2 lines allow the JScrollPane to scroll
		// -- automatically when new text is added
		DefaultCaret caret = (DefaultCaret) metrics_statePane.getCaret();
		caret.setUpdatePolicy(DefaultCaret.ALWAYS_UPDATE);

		JScrollPane jscrollpane = new JScrollPane(metrics_statePane);
		metrics_stateContainer.add(jscrollpane);


		metrics_displayPanel.add(metrics_chartContainer);

		return metrics_displayPanel;
	}


	public void showErrorMessage(String title, String message){
		JOptionPane.showMessageDialog(this, message,title, 0);

	}


	/**
	 * Listener for the metrics selection in the JTree of checkboxes
	 */
	public class DisplayMetrics implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			DefaultCategoryDataset metricsDataset = new DefaultCategoryDataset();
			TreePath checkedPaths[] = m_metricCheckTreeManager.getSelectionModel()
					.getSelectionPaths();

			// -- if no selection is made
			if (checkedPaths == null) {
				showErrorMessage(
						"Metric Selection Alert !",
						"<html><b><font color=#151b8d>Please select at least one metric !!</font></b></html>");
			} else {
				ArrayList<Object> list = m_metricCheckTreeManager.getAllCheckedPaths(m_metricCheckTreeManager, m_metricTree);

				for (int i = 0; i < list.size(); i++) {
					TreePath p = (TreePath) list.get(i);

					if (p.getPathCount() > 2) {

						for (int j = 0; j < Chart.m_Metric_Dataset
								.getRowCount(); j++) {
							// -- Retrieve Chart.m_metricDataset information from the results of p
							if (Chart.m_Metric_Dataset.getRowKey(j).toString().matches(".*\\b"+ p.getPathComponent(1).toString()+ "\\b.*")) {
								if (Chart.m_Metric_Dataset.getRowKey(j).toString().matches(".*\\b"+ p.getPathComponent(2).toString()+ "\\b.*")) {
									//System.out.println("m_metricDataset Rowkey "+ Chart.m_metricsDataset.getRowKey(j));

									// -- Return the number of states in Chart.m_metricDataset
									for (int k = 0; k < Chart.m_Metric_Dataset.getColumnCount(); k++) {
										//System.out.println("m_metricDataset Value "+ Chart.m_metricsDataset.getValue(j, k));
										//System.out.println("m_metricDataset Column Key "+ Chart.m_metricsDataset.getColumnKey(k));
										metricsDataset.addValue(Chart.m_Metric_Dataset.getValue(j, k),
												Chart.m_Metric_Dataset.getRowKey(j).toString(),
												Chart.m_Metric_Dataset.getColumnKey(k).toString());
									}
								}
							}

						}

					}
				}
				metrics_chartContainer.removeAll();
				metrics_chartContainer.repaint();
				m_metrics_barchart.m_tmp_Metric_ChartPanel = m_metrics_barchart.updateChart_metrics(metricsDataset);
				m_metrics_barchart.m_tmp_Metric_ChartPanel.setMouseWheelEnabled(true);
				m_metrics_barchart.m_tmp_Metric_ChartPanel.setAutoscrolls(true);
				metrics_chartContainer.add(m_metrics_barchart.m_tmp_Metric_ChartPanel, BorderLayout.CENTER);
				metrics_jsplitpane.repaint();
				metrics_chartContainer.repaint();
				metrics_chartContainer.updateUI();
				metrics_jsplitpane.updateUI();
				//updateChartPanel(metricsDataset);
			}
		}
	}

}
