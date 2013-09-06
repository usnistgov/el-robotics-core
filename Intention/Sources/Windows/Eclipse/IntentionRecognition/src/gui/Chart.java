/****************************************************************************************************************************************************
 * DISCLAIMER:
 * This software was produced by the National Institute of Standards and Technology (NIST), an
 * agency of the U.S. government, and by
 * statute is not subject to copyright in the United States.
 * Recipients of this software assume all responsibility associated with its operation,
 * modification, maintenance, and subsequent redistribution.
 * 
 * See NIST Administration Manual 4.09.07 b and Appendix I.
 ****************************************************************************************************************************************************/

package gui;

import intention.Intention;

import java.awt.Color;
import java.awt.Font;
import java.awt.Paint;
import java.awt.event.ActionEvent;
import java.util.List;
import javax.swing.AbstractAction;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.ChartUtilities;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.LegendItemCollection;
import org.jfree.chart.LegendItemSource;
import org.jfree.chart.axis.CategoryAxis;
import org.jfree.chart.axis.NumberAxis;
import org.jfree.chart.axis.NumberTickUnit;
import org.jfree.chart.axis.ValueAxis;
import org.jfree.chart.block.GridArrangement;
import org.jfree.chart.labels.ItemLabelAnchor;
import org.jfree.chart.labels.ItemLabelPosition;
import org.jfree.chart.labels.StandardCategoryToolTipGenerator;
import org.jfree.chart.plot.CategoryPlot;
import org.jfree.chart.plot.CombinedDomainCategoryPlot;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.plot.XYPlot;
import org.jfree.chart.renderer.category.BarRenderer;
import org.jfree.chart.renderer.category.CategoryItemRenderer;
import org.jfree.chart.renderer.category.LineAndShapeRenderer;
import org.jfree.chart.renderer.xy.XYSplineRenderer;
import org.jfree.chart.title.LegendTitle;
import org.jfree.chart.title.TextTitle;
import org.jfree.data.category.CategoryDataset;
import org.jfree.data.category.DefaultCategoryDataset;
import org.jfree.data.xy.XYDataset;
import org.jfree.data.xy.XYSeries;
import org.jfree.ui.RectangleEdge;
import org.jfree.ui.RectangleInsets;
import org.jfree.ui.TextAnchor;
import org.jfree.util.ShapeUtilities;

import tools.UI;

public class Chart {

	private static final String m_LH_Chart_Title = "Likelihoods";
	private static final String m_Metric_Chart_Title = "Metrics";
	//public static int m_state;
	public static DefaultCategoryDataset m_LH_Dataset = new DefaultCategoryDataset();
	public static DefaultCategoryDataset m_Metric_Dataset = new DefaultCategoryDataset();
	public ChartPanel m_LH_chartPanel = createChart_likelihood();
	public ChartPanel m_Metric_chartPanel = createChart_metrics();
	public ChartPanel m_tmp_Metric_ChartPanel;
	public ChartPanel m_tmp_LH_ChartPanel;

	static Paint[] m_colors = new Paint[] { UI.intentionColor9,
		UI.intentionColor2, UI.intentionColor3, UI.intentionColor10,
		UI.intentionColor1, UI.intentionColor6, UI.intentionColor7,
		UI.intentionColor8 };

	static class CustomRenderer extends BarRenderer {
		private static final long serialVersionUID = 1L;
		private Paint[] colors;

		public CustomRenderer() {
			// -- set the list of colors for this CustomRendered
			this.colors = m_colors;
			// -- Match the color of each element in the legend with the color
			// of each bar in the chart
			for (int i = 0; i < this.colors.length; i++) {
				this.setSeriesPaint(i, this.colors[i]);
			}

		}

		public Paint getItemPaint(final int row, final int column) {
			// returns color for each column
			return (this.colors[row % this.colors.length]);
		}
	}

	static class CustomRendererLine extends LineAndShapeRenderer {
		private static final long serialVersionUID = 1L;
		private Paint[] colors;

		public CustomRendererLine() {
			this.colors = m_colors;
		}

		public Paint getItemPaint(final int row, final int column) {
			// returns color for each column
			return (this.colors[row % this.colors.length]);
		}
	}

	public Chart() {
		m_LH_chartPanel.setMouseWheelEnabled(true);
		m_LH_chartPanel.setAutoscrolls(true);
		m_Metric_chartPanel.setMouseWheelEnabled(true);
		m_Metric_chartPanel.setAutoscrolls(true);
	}

	/**
	 * This function enables and disables the trace on the chart
	 * 
	 * @return JComboBox A box that enables/disables the trace function
	 */
	/*
	 * private JComboBox createTrace() { final JComboBox trace = new
	 * JComboBox(); final String[] traceCmds = {"Disable Trace","Enable Trace"};
	 * trace.setModel(new DefaultComboBoxModel(traceCmds));
	 * trace.setBackground(Color.white);
	 * chartPanel.setHorizontalAxisTrace(false);
	 * chartPanel.setVerticalAxisTrace(false);
	 * //chartPanel.setBackground(Color.white); chartPanel.repaint();
	 * 
	 * trace.addActionListener(new ActionListener() {
	 * 
	 * @Override public void actionPerformed(ActionEvent e) { if
	 * (traceCmds[1].equals(trace.getSelectedItem())) {
	 * chartPanel.setHorizontalAxisTrace(true);
	 * chartPanel.setVerticalAxisTrace(true); chartPanel.repaint(); } else {
	 * chartPanel.setHorizontalAxisTrace(false);
	 * chartPanel.setVerticalAxisTrace(false); chartPanel.repaint(); } } });
	 * return trace; }
	 */

	/**
	 * @brief Returns a collection of legend items for one of the subplot of a
	 * CombinedDomainCategoryPlot
	 * 
	 * @param combineddomaincategoryplot
	 *            Instance of CombinedDomainCategoryPlot
	 * @return The legend items.
	 */
	public LegendItemCollection getLegendItems(
			CombinedDomainCategoryPlot combineddomaincategoryplot) {
		LegendItemCollection result = new LegendItemCollection();
		List subplots = combineddomaincategoryplot.getSubplots();
		if (subplots != null) {
			CategoryPlot plot = (CategoryPlot) subplots.get(1);
			LegendItemCollection more = plot.getLegendItems();
			result.addAll(more);
		}
		return result;
	}

	public ChartPanel updateChart_metrics(DefaultCategoryDataset metricsDataset) {;

	JFreeChart jfreechart = ChartFactory.createLineChart(m_Metric_Chart_Title, "State", "Value", metricsDataset, PlotOrientation.VERTICAL, true, true, false);   

	TextTitle tt = jfreechart.getTitle();
	tt.setFont(UI.m_titleFont);
	jfreechart.setTitle(tt);

	jfreechart.setBackgroundPaint(UI.JFreeChartBackground);
	jfreechart.removeLegend();
	CategoryPlot categoryplot = (CategoryPlot)jfreechart.getPlot();   
	categoryplot.setDomainCrosshairVisible(true);
	categoryplot.setRangeCrosshairLockedOnData(true);
	categoryplot.setRangePannable(true);
	categoryplot.setBackgroundPaint(Color.WHITE);   
	categoryplot.setRangeGridlinePaint(Color.black);   
	categoryplot.setDomainGridlinesVisible(true);
	categoryplot.setRangeMinorGridlinesVisible(true);

	//-- TODO
	//-- This line is used to arrange the legend in a grid of 5 x 5
	LegendTitle legend = new LegendTitle(categoryplot, new GridArrangement(5, 5), new GridArrangement(5, 5));
	legend.setPosition(RectangleEdge.BOTTOM);
	jfreechart.addLegend(legend);


	NumberAxis numberaxis = (NumberAxis)categoryplot.getRangeAxis();   

	numberaxis.setStandardTickUnits(NumberAxis.createIntegerTickUnits());   
	numberaxis.setTickUnit(new NumberTickUnit(0.1));

	LineAndShapeRenderer lineandshaperenderer = (LineAndShapeRenderer)categoryplot.getRenderer();   
	lineandshaperenderer.setBaseToolTipGenerator(new StandardCategoryToolTipGenerator());
	lineandshaperenderer.setBaseLegendTextFont(UI.m_legendFont);
	lineandshaperenderer.setSeriesShapesVisible(0, true);   
	lineandshaperenderer.setSeriesShapesVisible(1, true);   
	lineandshaperenderer.setSeriesShapesVisible(2, true);   
	lineandshaperenderer.setSeriesLinesVisible(2, true);   
	//lineandshaperenderer.setSeriesShape(2, ShapeUtilities.createDiagonalCross(3, 1));   
	lineandshaperenderer.setDrawOutlines(true);   
	lineandshaperenderer.setUseFillPaint(true);   
	return new ChartPanel(jfreechart);   
	}

	public static ChartPanel createChart_metrics() {
		JFreeChart jfreechart = ChartFactory.createLineChart(m_Metric_Chart_Title, "State", "Value", m_Metric_Dataset, PlotOrientation.VERTICAL, true, true, false);   
		TextTitle tt = jfreechart.getTitle();
		tt.setFont(UI.m_titleFont);
		jfreechart.setTitle(tt);

		jfreechart.setBackgroundPaint(UI.JFreeChartBackground);
		jfreechart.removeLegend();
		CategoryPlot categoryplot = (CategoryPlot)jfreechart.getPlot();   
		categoryplot.setDomainCrosshairVisible(true);
		categoryplot.setRangeCrosshairLockedOnData(true);
		categoryplot.setRangePannable(true);
		categoryplot.setBackgroundPaint(Color.WHITE);   
		categoryplot.setRangeGridlinePaint(Color.black);   
		categoryplot.setDomainGridlinesVisible(true);
		categoryplot.setRangeMinorGridlinesVisible(true);

		//-- TODO
		//-- This line is used to arrange the legend in a grid of 5 x 5
		LegendTitle legend = new LegendTitle(categoryplot, new GridArrangement(5, 5), new GridArrangement(5, 5));
		legend.setPosition(RectangleEdge.BOTTOM);
		jfreechart.addLegend(legend);


		NumberAxis numberaxis = (NumberAxis)categoryplot.getRangeAxis();   

		numberaxis.setStandardTickUnits(NumberAxis.createIntegerTickUnits());   
		numberaxis.setTickUnit(new NumberTickUnit(0.1));

		LineAndShapeRenderer lineandshaperenderer = (LineAndShapeRenderer)categoryplot.getRenderer();   
		lineandshaperenderer.setBaseToolTipGenerator(new StandardCategoryToolTipGenerator());
		lineandshaperenderer.setBaseLegendTextFont(UI.m_legendFont);
		lineandshaperenderer.setSeriesShapesVisible(0, true);   
		lineandshaperenderer.setSeriesShapesVisible(1, true);   
		lineandshaperenderer.setSeriesShapesVisible(2, true);   
		lineandshaperenderer.setSeriesLinesVisible(2, true);   
		//lineandshaperenderer.setSeriesShape(2, ShapeUtilities.createDiagonalCross(3, 1));   
		lineandshaperenderer.setDrawOutlines(true);   
		lineandshaperenderer.setUseFillPaint(true);   
		return new ChartPanel(jfreechart);   
	}


	ChartPanel updateChart_likelihood(DefaultCategoryDataset dataset) {
		JFreeChart jfreechart = ChartFactory.createLineChart(m_LH_Chart_Title, "State", "Value (%)", dataset, PlotOrientation.VERTICAL, true, true, false);   
		TextTitle tt = jfreechart.getTitle();
		tt.setFont(UI.m_titleFont);
		jfreechart.setTitle(tt);
		jfreechart.setBackgroundPaint(UI.JFreeChartBackground);
		jfreechart.removeLegend();
		CategoryPlot categoryplot = (CategoryPlot)jfreechart.getPlot();   
		categoryplot.setDomainCrosshairVisible(true);
		categoryplot.setRangeCrosshairLockedOnData(true);
		categoryplot.setRangePannable(true);
		categoryplot.setBackgroundPaint(Color.WHITE);   
		categoryplot.setRangeGridlinePaint(Color.black);   
		categoryplot.setDomainGridlinesVisible(true);
		categoryplot.setRangeMinorGridlinesVisible(true);

		//-- TODO
		//-- This line is used to arrange the legend in a grid of 5 x 5
		LegendTitle legend = new LegendTitle(categoryplot, new GridArrangement(1, 5), new GridArrangement(1, 5));
		legend.setPosition(RectangleEdge.BOTTOM);
		jfreechart.addLegend(legend);


		NumberAxis numberaxis = (NumberAxis)categoryplot.getRangeAxis();   

		numberaxis.setStandardTickUnits(NumberAxis.createIntegerTickUnits());   
		//numberaxis.setTickUnit(new NumberTickUnit(0.1));

		LineAndShapeRenderer lineandshaperenderer = (LineAndShapeRenderer)categoryplot.getRenderer();   
		lineandshaperenderer.setBaseToolTipGenerator(new StandardCategoryToolTipGenerator());
		lineandshaperenderer.setBaseLegendTextFont(UI.m_legendFont);
		lineandshaperenderer.setSeriesShapesVisible(0, true);   
		lineandshaperenderer.setSeriesShapesVisible(1, true);   
		lineandshaperenderer.setSeriesShapesVisible(2, true);   
		lineandshaperenderer.setSeriesLinesVisible(2, true);   
		//lineandshaperenderer.setSeriesShape(2, ShapeUtilities.createDiagonalCross(3, 1));   
		lineandshaperenderer.setDrawOutlines(true);   
		lineandshaperenderer.setUseFillPaint(true);   

		return new ChartPanel(jfreechart); 

	}
	private ChartPanel createChart_likelihood() {
		JFreeChart jfreechart = ChartFactory.createLineChart(m_LH_Chart_Title, "State", "Value (%)", m_LH_Dataset, PlotOrientation.VERTICAL, true, true, false);   
		TextTitle tt = jfreechart.getTitle();
		tt.setFont(UI.m_titleFont);
		jfreechart.setTitle(tt);
		jfreechart.setBackgroundPaint(UI.JFreeChartBackground);
		jfreechart.removeLegend();
		CategoryPlot categoryplot = (CategoryPlot)jfreechart.getPlot();   
		categoryplot.setDomainCrosshairVisible(true);
		categoryplot.setRangeCrosshairLockedOnData(true);
		categoryplot.setRangePannable(true);
		categoryplot.setBackgroundPaint(Color.WHITE);   
		categoryplot.setRangeGridlinePaint(Color.black);   
		categoryplot.setDomainGridlinesVisible(true);
		categoryplot.setRangeMinorGridlinesVisible(true);

		//-- TODO
		//-- This line is used to arrange the legend in a grid of 5 x 5
		LegendTitle legend = new LegendTitle(categoryplot, new GridArrangement(1, 5), new GridArrangement(1, 5));
		legend.setPosition(RectangleEdge.BOTTOM);
		jfreechart.addLegend(legend);


		NumberAxis numberaxis = (NumberAxis)categoryplot.getRangeAxis();   

		numberaxis.setStandardTickUnits(NumberAxis.createIntegerTickUnits());   
		//numberaxis.setTickUnit(new NumberTickUnit(0.1));

		LineAndShapeRenderer lineandshaperenderer = (LineAndShapeRenderer)categoryplot.getRenderer();   
		lineandshaperenderer.setBaseToolTipGenerator(new StandardCategoryToolTipGenerator());
		lineandshaperenderer.setBaseLegendTextFont(UI.m_legendFont);
		lineandshaperenderer.setSeriesShapesVisible(0, true);   
		lineandshaperenderer.setSeriesShapesVisible(1, true);   
		lineandshaperenderer.setSeriesShapesVisible(2, true);   
		lineandshaperenderer.setSeriesLinesVisible(2, true);   
		//lineandshaperenderer.setSeriesShape(2, ShapeUtilities.createDiagonalCross(3, 1));   
		lineandshaperenderer.setDrawOutlines(true);   
		lineandshaperenderer.setUseFillPaint(true);   


		return new ChartPanel(jfreechart); 

	}

	public static void createLikelihoodDataset(double _likelihood, Intention _intention, int _state) {
		
		if (_state>1)
		{
			String state_s = "State " + (int)(_state-1);
			//m_state = _state;

			//System.out.println(_likelihood);
			//System.out.println(state_s);
			//System.out.println(_intention);
			m_LH_Dataset.addValue(_likelihood,_intention.getM_intention_number()+"--"+_intention.getIntentionName(), state_s);
		}
	}

	/**
	 * @brief Create a data set for metrics
	 * @param _intention The intention from which we will retrieve the metrics
	 * @param _state The current state
	 */
	public static void createMetricsDataset(Intention _intention, int _state) {
		//m_Metric_Dataset.clear();
		//DefaultCategoryDataset defaultcategorydataset = new DefaultCategoryDataset();  

		//-- TODO Remove this condition when we receive real data
		//-- For now, we don't want the very first state relation to appear anywhere
		if (_state>1)
		{
			String state_s = "State " + (int)(_state-1);
			//System.out.println(state_s);
			//System.exit(0);

			double am1 = _intention.getM_am1();
			double am2 = _intention.getM_am2();
			double am3 = _intention.getM_am3();
			double am4 = _intention.getM_am4();
			double mm1 = _intention.getM_mm1();

			String am1_s = _intention.getIntentionName() +" -- AM1";
			String am2_s = _intention.getIntentionName() +" -- AM2";
			String am3_s = _intention.getIntentionName() +" -- AM3";
			String am4_s = _intention.getIntentionName() +" -- AM4";
			String mm1_s = _intention.getIntentionName() +" -- MM1";

			m_Metric_Dataset.addValue(am1, am1_s.toString(), state_s.toString());
			m_Metric_Dataset.addValue(am2, am2_s.toString(), state_s.toString());
			m_Metric_Dataset.addValue(am3, am3_s.toString(), state_s.toString());
			m_Metric_Dataset.addValue(am4, am4_s.toString(), state_s.toString());
			m_Metric_Dataset.addValue(mm1, mm1_s.toString(), state_s.toString());
		}
	}
}









