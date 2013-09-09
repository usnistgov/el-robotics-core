kage gui;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.ComponentOrientation;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Point;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.image.BufferedImage;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileFilter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.lang.reflect.InvocationTargetException;
import java.net.MalformedURLException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import javax.swing.Action;
import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JDialog;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.UIManager;
import javax.swing.WindowConstants;
import javax.swing.border.Border;
import javax.swing.border.TitledBorder;
import javax.swing.plaf.ColorUIResource;
import javax.swing.text.PlainDocument;
import org.jfree.ui.RefineryUtilities;
import org.semanticweb.owlapi.model.OWLClass;
import org.semanticweb.owlapi.model.OWLException;
import org.semanticweb.owlapi.model.OWLOntology;
import org.semanticweb.owlapi.reasoner.NodeSet;
import ontology.Ontology;
import tools.UI;
import gui.MainFrame.DisplayMetrics;
import intention.Intention;
import tools.Configuration;
import intention.Metric;
import com.lowagie.text.Image;
import component.MyIntFilter;

public class OptionFrame extends WindowAdapter{
	final static boolean shouldFill = false;
	final static boolean shouldWeightX = true;
	final static boolean RIGHT_TO_LEFT = false;
	static boolean m_bool_allKits = false;
	private static Metric m_metric;
	public static JTextField m_instance_txt_field, m_save_file_txt_field, m_field_AM1, m_field_AM2, m_field_AM3, m_field_AM4, m_field_AM5;
	public static JButton m_browse_soap, m_browse_instance, m_browse_classes, m_validate_button, m_browse_path;
	public static JFrame m_frame;
	public static Boolean m_validate;
	public static JTextArea m_textArea;
	public static Container contentPane;
	public static List<String> m_subkitlist;
	public static JLabel picture;
	private JPopupMenu m_popupMenu;
	private static JComboBox m_kitComboBox, m_planComboBox;
	private static ArrayList<String> m_planStrings= new ArrayList<String>();
	public static JRadioButton singleKitButton, allKitsButton;

	// the main frame's default button
	//private static JButton defaultButton;

	// constants for action commands
	protected final static String NO_DECORATIONS = "no_dec";
	protected final static String LF_DECORATIONS = "laf_dec";
	protected final static String WS_DECORATIONS = "ws_dec";
	protected final static String CREATE_WINDOW = "new_win";
	protected final static String DEFAULT_ICON = "def_icon";
	protected final static String FILE_ICON = "file_icon";
	protected final static String PAINT_ICON = "paint_icon";

	public OptionFrame() {
		m_frame = new JFrame("Intentions for Kitting");
		m_frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		m_validate = false;
		//defaultButton = null;
	}

	private static void add(Component c, GridBagLayout gbl,
			GridBagConstraints gbc, int x, int y, int w, int h)
	{
		gbc.gridx = x; gbc.gridy = y;
		gbc.gridwidth = w; gbc.gridheight = h;
		gbl.setConstraints(c, gbc);
		contentPane.add(c);
	}

	/**
	 * @brief Retrieve all the kit directories in the directory kit
	 * @return
	 */
	public static ArrayList<String> getKitList(){
		ArrayList<String> kitStrings = new ArrayList<String>();

		//-- Get all the sub directories in "etc/kits/"
		//File kit_directory = new File("C:\\Users\\kalucard\\Desktop\\zeid\\workspace\\etc\\kits\\");  
		//File kit_directory = new File("../kits/");
		File kit_directory = new File("kits/");
		
		File[] subDirs = kit_directory.listFiles(new FileFilter() {  
			public boolean accept(File pathname) {  
				return pathname.isDirectory();  
			}  
		}); 

		for (File subDir : subDirs) {  
			String path = subDir.getPath();
			String idStr = path.substring(path.lastIndexOf('\\') + 1);
			
			kitStrings.add(idStr);
			System.out.println(idStr);
		} 

		return kitStrings;
	}

	public static JButton createButtonFromTemplate(JButton _button){
		JButton button = _button;
		button.setBackground(UI.chartPanelColor);
		button.setOpaque(true);
		button.setForeground(Color.black);

		return button;
	}


	public  void addComponentsToPane(Container pane,final Ontology onto) {
		
		if (RIGHT_TO_LEFT) {
			pane.setComponentOrientation(ComponentOrientation.RIGHT_TO_LEFT);
		}

		GridBagLayout gbl = new GridBagLayout();
		pane.setLayout(gbl);
		GridBagConstraints gbc = new GridBagConstraints();
		gbc.weightx = 0; gbc.weighty = 0;
		gbc.fill = GridBagConstraints.HORIZONTAL;


		
		
		String allKitsString = "<html><b><font color='a0bc88'>All Kits</font></b><br></html>";
		allKitsButton = new JRadioButton(allKitsString);
		allKitsButton.setActionCommand(allKitsString);
		allKitsButton.setBackground(Color.white);
		allKitsButton.setSelected(false);
		
		
		String singleKitString = "<html><b><font color='a0bc88'>Single Kit</font></b><br></html>";
		singleKitButton = new JRadioButton(singleKitString);
		singleKitButton.setActionCommand(singleKitString);
		singleKitButton.setBackground(Color.white);
		singleKitButton.setSelected(true);
		
		ButtonGroup group = new ButtonGroup();
        group.add(allKitsButton);
        group.add(singleKitButton);
        
        //-- Display
        add(new JLabel("<html><b>1. <font color=rgb(160, 188, 136)>Generate Data for all kits or a single kit?</font></b><br></html>"),gbl,gbc,0,0,1,1);
        add(allKitsButton,gbl,gbc,1,1,1,1);
		add(singleKitButton,gbl,gbc,0,1,1,1);
		
		
		//-- Disable Kit and Plan selection when allKitsButton is selected
		allKitsButton.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent e) {
				m_kitComboBox.setEnabled(false);
				m_planComboBox.setEnabled(false);
				m_save_file_txt_field.setEnabled(true);
				m_browse_path.setEnabled(true);
			}
		});
		
		//-- Enable Kit and Plan selection when allKitsButton is selected
		singleKitButton.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent e) {
				m_kitComboBox.setEnabled(true);
				m_planComboBox.setEnabled(true);
				m_save_file_txt_field.setEnabled(false);
				m_browse_path.setEnabled(false);
			}
		});
		
		
		
		//+++++ INSTANCE Ontology
		
		m_instance_txt_field = new JTextField();
		m_instance_txt_field.setEditable(true);
		m_instance_txt_field.setColumns(25);
		this.createPopupMenu();
		m_instance_txt_field.addMouseListener(new MouseHandler(this.m_popupMenu));
		
		

		m_browse_instance = createButtonFromTemplate(new JButton("Browse"));
		
		//-- Display
		//add(new JLabel("<html><b>2. <font color=rgb(160, 188, 136)>Select the Instance file.</font></b><br></html>"),gbl,gbc,0,2,1,1);
		//add(m_instance_txt_field,gbl,gbc,0,3,1,1);
		//add(m_browse_instance,gbl,gbc,1,3,1,1);

		add(new JLabel("---------------------------------------------------------------------------------------------------------------"),gbl,gbc,0,8,3,1);
		//+++++ Kit to build
		add(new JLabel("<html><b>2. <font color=rgb(160, 188, 136)>Select a kit to build.</font></b><br></html>"),gbl,gbc,0,9,1,1);

		ArrayList<String> kitStrings = getKitList();
		
		//-- Let's sort tmpList
		m_subkitlist = kitStrings.subList(0, kitStrings.size());
		Collections.sort(m_subkitlist);
		
		
		m_kitComboBox = new JComboBox();
		for (int i=0; i<m_subkitlist.size(); i++)
		{
			//System.out.println(sublist.get(i));
			m_kitComboBox.addItem(m_subkitlist.get(i));
		}
		
		
		//m_kitComboBox = new JComboBox(kitStrings.toArray());
		
		
		//m_kitComboBox.setSelectedIndex(0);

		
		//IntentionListener intentionListener = new IntentionListener();
		//KitComboBoxListener kitCombBoxListener = new KitComboBoxListener();

		//m_kitComboBox.addActionListener(intentionListener);

		m_kitComboBox.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//-- Auto-generated method stub
				m_planStrings.clear();
				m_planComboBox.removeAllItems();
				String x = m_kitComboBox.getSelectedItem().toString();

				//System.out.println(x);
				
				//String plan_path = "C:\\Users\\kalucard\\Desktop\\zeid\\workspace\\etc\\kits\\"+x+"\\";
				//String plan_path = "../kits/"+x+"/";
				String plan_path = "kits/"+x+"/";
				
				//Ontology.m_kitToBuild=plan_path;

				File plan_directory = new File(plan_path);  

				File[] subFiles = plan_directory.listFiles(new FileFilter() {  
					public boolean accept(File pathname) {  
						return pathname.isFile();  
					}  
				}); 
				ArrayList<String> tmpList = new ArrayList<String>();

				for (File subFile : subFiles) {  
					String path = subFile.getPath();

					String idStr = path.substring(path.lastIndexOf('\\') + 1);
					//System.out.println(idStr.substring(0, idStr.lastIndexOf('.')));
					//System.out.println("\n\n");
					String cleaned_idStr = idStr.substring(0, idStr.lastIndexOf('.')).toString();
					tmpList.add(cleaned_idStr);
					//m_planComboBox.addItem(cleaned_idStr);
					//m_planStrings.add(idStr.substring(0, idStr.lastIndexOf('.')).toString());
				} 

				//-- Let's sort tmpList
				List<String> sublist = tmpList.subList(0, tmpList.size());
				Collections.sort(sublist);
				for (int i=0; i<sublist.size(); i++)
				{
					//System.out.println(sublist.get(i));
					m_planComboBox.addItem(sublist.get(i));
					m_planStrings.add(sublist.get(i));
				}
			}
		});


		m_kitComboBox.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JComboBox cb = (JComboBox)e.getSource();
				String kitName = (String)cb.getSelectedItem();
				updateLabel(kitName);
			}
		});

		add(m_kitComboBox,gbl,gbc,1,9,1,1);


		//+++++ Plan to build
		add(new JLabel("<html><b>3. <font color=rgb(160, 188, 136)>Select a plan.</font></b><br></html>"),gbl,gbc,0,11,1,1);
		//System.out.println(m_kitComboBox.getSelectedItem().toString());
		
		findFilesinDirectory(m_kitComboBox.getSelectedItem().toString());
		m_planComboBox = new JComboBox(m_planStrings.toArray());
		m_planComboBox.setSelectedIndex(0);
		add(m_planComboBox,gbl,gbc,1,11,1,1);
		Ontology.m_kitToBuild=m_planComboBox.getSelectedItem().toString();

		//+++++ Picture
		picture = new JLabel();
		picture.setFont(picture.getFont().deriveFont(Font.ITALIC));
		picture.setHorizontalAlignment(JLabel.CENTER);

		//-- Update the picture based on the selection
		updateLabel(kitStrings.toArray()[m_kitComboBox.getSelectedIndex()].toString());
		picture.setBackground(Color.WHITE);
		picture.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
		add(picture,gbl,gbc,2,9,1,1);


		add(new JLabel("---------------------------------------------------------------------------------------------------------------"),gbl,gbc,0,12,3,1);
		//add(new JSeparator(SwingConstants.VERTICAL), gbl, gbc, 0, 12, 5, 1);
		add(new JLabel("<html><b>4. <font color=rgb(160, 188, 136)>Metrics Weights.</font></b><br></html>"),gbl,gbc,0,13,1,1);
		m_field_AM1 = new JTextField(5);
		
		//File f = new File("../config.ini");
		File f = new File("config.ini");
		if(f.exists()) {
			//List<String> list = readConfigFile("../config.ini");
			List<String> list = readConfigFile("config.ini");
			String am1_value= list.get(1).toString();
			m_field_AM1.setText(am1_value);
		}
		else{
			m_field_AM1.setText("30");	
		}
		
		add(new JLabel("<html><font color='a0bc88'>AM1 </font><br></html>"),gbl,gbc,0,14,1,1);
		add(m_field_AM1,gbl,gbc,1,14,1,1);
		
	

		m_field_AM2 = new JTextField(5);
		if(f.exists()) {
			//List<String> list = readConfigFile("../config.ini");
			List<String> list = readConfigFile("config.ini");
			String am2_value= list.get(2).toString();
			m_field_AM2.setText(am2_value);
		}
		else{
			m_field_AM2.setText("10");	
		}
		
		add(new JLabel("<html><font color='a0bc88'>AM2 </font></html>"),gbl,gbc,0,15,1,1);
		add(m_field_AM2,gbl,gbc,1,15,1,1);


		m_field_AM3 = new JTextField(5);
		if(f.exists()) {
			//List<String> list = readConfigFile("../config.ini");
			List<String> list = readConfigFile("config.ini");
			String am3_value= list.get(3).toString();
			m_field_AM3.setText(am3_value);
		}
		else{
			m_field_AM3.setText("20");	
		}
		add(new JLabel("<html><font color='a0bc88'>AM3 </font></html>"),gbl,gbc,0,16,1,1);
		add(m_field_AM3,gbl,gbc,1,16,1,1);

		m_field_AM4 = new JTextField(5);
		if(f.exists()) {
			//List<String> list = readConfigFile("../config.ini");
			List<String> list = readConfigFile("config.ini");
			String am4_value= list.get(4).toString();
			m_field_AM4.setText(am4_value);
		}
		else{
			m_field_AM4.setText("40");	
		}
		add(new JLabel("<html><font color='a0bc88'>AM4 </font></html>"),gbl,gbc,0,17,1,1);
		add(m_field_AM4,gbl,gbc,1,17,1,1);

		m_field_AM5 = new JTextField(5);
		m_field_AM5.setText("50");
		//add(new JLabel("<html><font color='a0bc88'>AM5 </font><br></html>"),gbl,gbc,0,18,1,1);
		//add(m_field_AM5,gbl,gbc,1,18,1,1);
		
		m_validate_button = new JButton("Validate");
		//button.setBackground(UI.chartLeftPaneColor);
		m_validate_button.setActionCommand(CREATE_WINDOW);
		//m_validate_button.addActionListener(this);
		m_validate_button.setBackground(UI.chartPanelColor);
		m_validate_button.setOpaque(true);
		m_validate_button.setForeground(Color.black);
		
		add(new JLabel("<html><b>5. <font color=rgb(160, 188, 136)>Select where to save the CSV file.</font></b><br></html>"),gbl,gbc,0,19,1,1);
		m_save_file_txt_field=new JTextField();
		m_save_file_txt_field.setEditable(true);
		m_save_file_txt_field.setColumns(25);
		this.createPopupMenu();
		m_save_file_txt_field.addMouseListener(new MouseHandler(this.m_popupMenu));
		m_browse_path = createButtonFromTemplate(new JButton("Browse"));
		add(m_save_file_txt_field,gbl,gbc,0,20,1,1);
		add(m_browse_path,gbl,gbc,1,20,1,1);
		

		//-- Check if config.ini exists and get the first line
		//File f = new File("../config.ini");
		if(f.exists()) {
			//List<String> list = readConfigFile("../config.ini");
			List<String> list = readConfigFile("config.ini");
			String save_path= list.get(5).toString();
			m_save_file_txt_field.setText(save_path);
		}
		
		//-- Make sure they are disabled by default
		m_save_file_txt_field.setEnabled(false);
		m_browse_path.setEnabled(false);
		
		
		m_field_AM1.getDocument().addDocumentListener(new DocumentListener() {
			  public void changedUpdate(DocumentEvent e) {
			    //warn();
			  }
			  public void removeUpdate(DocumentEvent e) {
			   // warn();
			  }
			  public void insertUpdate(DocumentEvent e) {
			    update_save_file();
			  }

			  public void update_save_file() {
			     if (m_save_file_txt_field.isEnabled()){
			    	 if (!m_save_file_txt_field.equals("")){
			    		 String path = m_save_file_txt_field.getText().toString();
			    		 int index_underscore = path.indexOf("_");
			    		 int index_first_dash = path.indexOf("-",index_underscore);
			    	 }
			     }
			  }
			});
		//add(new JLabel(" "),gbl,gbc,1,19,1,1);
		add(new JLabel("---------------------------------------------------------------------------------------------------------------"),gbl,gbc,0,21,3,1);
		add(m_validate_button,gbl,gbc,1,22,1,1);


		//-- Making sure that the user enters only integers
		PlainDocument doc_AM1 = (PlainDocument) m_field_AM1.getDocument();
		//doc_AM1.setDocumentFilter(new MyIntFilter());

		PlainDocument doc_AM2 = (PlainDocument) m_field_AM2.getDocument();
		//doc_AM2.setDocumentFilter(new MyIntFilter());

		PlainDocument doc_AM3 = (PlainDocument) m_field_AM3.getDocument();
		//doc_AM3.setDocumentFilter(new MyIntFilter());

		PlainDocument doc_AM4 = (PlainDocument) m_field_AM4.getDocument();
		//doc_AM4.setDocumentFilter(new MyIntFilter());
		
		//PlainDocument doc_AM5 = (PlainDocument) m_field_AM5.getDocument();
		//doc_AM5.setDocumentFilter(new MyIntFilter());

		m_validate_button.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String command = e.getActionCommand();

				String kit = m_kitComboBox.getSelectedItem().toString();
				String plan = m_planComboBox.getSelectedItem().toString();

				Ontology.m_kitToBuild=kit;
				Ontology.m_planToBuild=plan;

				// Handle the button
				if (CREATE_WINDOW.equals(command)) {
					Metric.set_AM1_Weight(Integer.parseInt(m_field_AM1.getText()));
					Metric.set_AM2_Weight(Integer.parseInt(m_field_AM2.getText()));
					Metric.set_AM3_Weight(Integer.parseInt(m_field_AM3.getText()));
					Metric.set_AM4_Weight(Integer.parseInt(m_field_AM4.getText()));
					//Metric.set_AM5_Weight(Integer.parseInt(m_field_AM5.getText()));
					Intention.setM_built_kit(m_kitComboBox.getSelectedItem().toString());
					Intention.setM_selected_plan(m_planComboBox.getSelectedItem().toString());
					
					if (!m_kitComboBox.isEnabled())
						m_bool_allKits = true;
					m_validate = true;
					
					
					
					try {
						createAndUpdateConfigFile("config data");
					} catch (FileNotFoundException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					} catch (UnsupportedEncodingException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
					
					try {
						updateConfigFile(m_field_AM1.getText().toString());
					} catch (IOException e2) {
						// TODO Auto-generated catch block
						e2.printStackTrace();
					}
					try {
						updateConfigFile(m_field_AM2.getText().toString());
					} catch (IOException e2) {
						// TODO Auto-generated catch block
						e2.printStackTrace();
					}
					try {
						updateConfigFile(m_field_AM3.getText().toString());
					} catch (IOException e2) {
						// TODO Auto-generated catch block
						e2.printStackTrace();
					}
					try {
						updateConfigFile(m_field_AM4.getText().toString());
					} catch (IOException e2) {
						// TODO Auto-generated catch block
						e2.printStackTrace();
					}
					
					try {
						updateConfigFile(m_save_file_txt_field.getText().toString());
					} catch (IOException e2) {
						// TODO Auto-generated catch block
						e2.printStackTrace();
					}
				}
			}
		});

		//-- Action Listeners for the button browsing the SOAP ontology
		/*
		m_browse_soap.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				JFileChooser jfc = new JFileChooser();
				if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
					m_soap_txt_field
					.setText(jfc.getSelectedFile().getAbsolutePath());
				}
			}
		});
		*/

		//-- Action Listeners for the button browsing the Instance file
		
		m_browse_instance.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				JFileChooser jfc = new JFileChooser();
				if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
					m_instance_txt_field.setText(jfc.getSelectedFile().getAbsolutePath());
					Ontology.setInstanceFilePath(jfc.getSelectedFile().getAbsolutePath().toString());
				}
			}
		});
		

		m_browse_path.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				JFileChooser jfc = new JFileChooser();
				String am1_value = m_field_AM1.getText();
				String am2_value = m_field_AM2.getText();
				String am3_value = m_field_AM3.getText();
				String am4_value = m_field_AM4.getText();
				String am5_value = m_field_AM5.getText();
				jfc.setSelectedFile(new File("_"+am1_value+"-"+am2_value+"-"+am3_value+"-"+am4_value+"-"+"-"+"data-kits.csv"));
				
				if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION)
					m_save_file_txt_field.setText(jfc.getSelectedFile().getAbsolutePath());
			}
		});
	}
	
	public void updateConfigFile(String text) throws IOException{
		PrintWriter out = null;
		try {
			//out = new PrintWriter(new BufferedWriter(new FileWriter("../config.ini", true)));
			out = new PrintWriter(new BufferedWriter(new FileWriter("config.ini", true)));
		    out.println(text);
		} catch (IOException e) {
		    //oh noes!
		} finally {
		    if (out != null) {
		        out.close();
		    }
		}
	}

	public List<String> readConfigFile(String configFile){
		List<String> list= new ArrayList<String>();
		File file = new File(configFile);
		BufferedReader reader = null;
		
		try {
		    reader = new BufferedReader(new FileReader(file));
		    String text = null;

		    while ((text = reader.readLine()) != null) {
		        list.add(text);
		    }
		} catch (FileNotFoundException e) {
		    e.printStackTrace();
		} catch (IOException e) {
		    e.printStackTrace();
		} finally {
		    try {
		        if (reader != null) {
		            reader.close();
		        }
		    } catch (IOException e) {
		    }
		}
		
		return list;
	}
	
	public void createAndUpdateConfigFile(String text) throws FileNotFoundException, UnsupportedEncodingException{
		//PrintWriter writer = new PrintWriter("../config.ini", "UTF-8");
		PrintWriter writer = new PrintWriter("config.ini", "UTF-8");
		writer.println(text);
		//writer.println("The second line");
		writer.close();
	}
	
	
	/**
	 * @brief Create a popup menu when right-click on a JTextField
	 */
	public void createPopupMenu(){
		JMenuItem copy = new JMenuItem("copy");
		JMenuItem paste = new JMenuItem("paste");
		JMenuItem selectAll = new JMenuItem("select all");

		this.m_popupMenu = new JPopupMenu();
		this.m_popupMenu.add(copy);
		this.m_popupMenu.add(paste);
		this.m_popupMenu.add(selectAll);
		
		copy.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String cmd = e.getActionCommand();
				if (cmd.equals("copy"))
					m_instance_txt_field.copy();
			}
		});
		
		
	    paste.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String cmd = e.getActionCommand();
				if (cmd.equals("paste"))
					m_instance_txt_field.paste();
			}
		});
	    
	    selectAll.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String cmd = e.getActionCommand();
				if (cmd.equals("select all"))
					m_instance_txt_field.selectAll();
			}
		});
	}

	protected static void updateLabel(String name) {
		
		//picture.setIcon(new ImageIcon(((new ImageIcon("../img/"+name+".png")).getImage()).getScaledInstance(90, 80, java.awt.Image.SCALE_SMOOTH)));
		picture.setIcon(new ImageIcon(((new ImageIcon("img/"+name+".png")).getImage()).getScaledInstance(90, 80, java.awt.Image.SCALE_SMOOTH)));
		//=new JLabel(new ImageIcon(((new ImageIcon("img/"+name+".png")).getImage()).getScaledInstance(70, 60, java.awt.Image.SCALE_SMOOTH))); 
		picture.setToolTipText("Kit design for Kit " + name.toLowerCase());
	}

	/**
	 * Create the GUI and show it. For thread safety, this method should be
	 * invoked from the event-dispatching thread.
	 */
	public  void createAndShowGUI(Ontology onto) {

		// Use the Java look and feel.
		try {
			UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName());

		} catch (Exception e) {
		}
		// Make sure we have nice window decorations.
		JFrame.setDefaultLookAndFeelDecorated(true);
		JDialog.setDefaultLookAndFeelDecorated(true);


		m_frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// Add components to it.
		contentPane = m_frame.getContentPane();
		contentPane.setBackground(Color.white);
		this.addComponentsToPane(contentPane,onto) ;
		m_frame.setSize(new Dimension(700,500));
		m_frame.setPreferredSize(new Dimension(700,500));
		Dimension dim = Toolkit.getDefaultToolkit().getScreenSize();
		m_frame.setLocation(dim.width/2-m_frame.getSize().width/2, dim.height/2-m_frame.getSize().height/2);
		m_frame.pack();
		//m_metricFrame.setPreferredSize(new Dimension(400,300));
		m_frame.setVisible(true);

	}

	public void setMetric(Metric metric) {
		m_metric = metric;
	}

	public Metric getMetric() {
		return m_metric;
	}

	public static void findFilesinDirectory(String plan_path) {
		//plan_path="file:///Users/kalucard/Desktop/zeid/workspace/etc/kits/"+plan_path;
		//plan_path="C:\\Users\\kalucard\\Desktop\\zeid\\workspace\\etc\\kits\\"+plan_path+"\\";
		//plan_path="../kits/"+plan_path+"/";
		plan_path="kits/"+plan_path+"/";
		
		File plan_directory = new File(plan_path);  

		File[] subFiles = plan_directory.listFiles(new FileFilter() {  
			public boolean accept(File pathname) {  
				return pathname.isFile();  
			}  
		}); 
		ArrayList<String> tmpList = new ArrayList<String>();
		for (File subFile : subFiles) {  
			String path = subFile.getPath();

			String idStr = path.substring(path.lastIndexOf('\\') + 1);
			String cleaned_idStr = idStr.substring(0, idStr.lastIndexOf('.')).toString();
			tmpList.add(cleaned_idStr);
			//m_planStrings.add(idStr.substring(0, idStr.lastIndexOf('.')).toString());
		} 

		List<String> sublist = tmpList.subList(0, tmpList.size());
		Collections.sort(sublist);
		for (int i=0; i<sublist.size(); i++)
		{
			//System.out.println(sublist.get(i));
			//m_planComboBox.addItem(sublist.get(i));
			m_planStrings.add(sublist.get(i));
		}
	}


	public class PlanComboBoxListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			JComboBox cb = (JComboBox)e.getSource();
			String planName = (String)cb.getSelectedItem();
			Ontology.m_kitToBuild=planName;
		}}

	
	class MouseHandler extends java.awt.event.MouseAdapter
	{
		private javax.swing.JPopupMenu popupMenu;

		public MouseHandler(javax.swing.JPopupMenu popup)
		{
			this.popupMenu = popup;
		}

		public void mousePressed(java.awt.event.MouseEvent e)
		{
			if (e.isPopupTrigger())
				popupMenu.show(e.getComponent(), e.getX(), e.getY());
		}

		public void mouseReleased(java.awt.event.MouseEvent e )
		{
			if (e.isPopupTrigger())
				popupMenu.show(e.getComponent(), e.getX(), e.getY());
		}

	}
}
