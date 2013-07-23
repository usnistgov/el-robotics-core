/*****************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards
   and Technology (NIST), an agency of the U.S. government, and by 
statute is
   not subject to copyright in the United States.  Recipients of this 
software
   assume all responsibility associated with its operation, modification,
   maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 *****************************************************************************/

/**
 * \file      Gui.java
 * \author    Anthony Pietromartire \a pietromartire.anthony\@nist.gov
 * \version   1.0
 * \date      29 June 2012
 * \brief     Class for the GUI.
 */

/**
 * \class Gui
 * \brief The GUI class.
 * \details Build the frame and handle the events on it.
 */
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.io.File;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTabbedPane;
import javax.swing.JTextField;
import javax.swing.border.Border;
import javax.swing.filechooser.FileNameExtensionFilter;

import Ontology.Ontology;

public class Gui extends JFrame {

	private static final long serialVersionUID = 3136170074025065903L;
	private JTabbedPane tabbedPane;
	private JPanel panOtS;
	private JPanel panStO;
	private JPanel panXtO;
	private JPanel panCreate;
	private JPanel panGenerate;
	private JPanel panSave;
	private JPanel panOtoCpp;
	private JPanel panCreateCpp;
	private JPanel panGenerateCpp;
	private JPanel panDb;
	private JPanel panDbUrl;
	private JPanel panDbUser;
	private JPanel panDbPass;
	private JPanel panDbName;
	private JPanel panXOpenOnto;
	private JPanel panImport;
	private JPanel panSaveCpp;
	private JPanel panXOpenXls;
	private JLabel jlUser;
	private JLabel jlUrl;
	private JLabel jlPass;
	private JLabel jlName;
	private JTextField url;
	private JTextField user;
	private JPasswordField pass;
	private JTextField nameDb;
	private JTextField path;
	private JTextField pathSave;
	private JTextField pathXls;
	private JTextField pathXlsOnto;
	private JTextField pathCpp;
	private JTextField pathSaveCpp;
	private JButton browseCreate;
	private JButton browseSave;
	private JButton browseCreateCpp;
	private JButton browseSaveCpp;
	private JButton generateSql;
	private JButton generateCpp;
	private JButton browseXls;
	private JButton browseXlsOnto;
	private JButton importTerms;
	
	private CodeGenerator codeGen;

	/**
	 * \brief Constructor \details Constructor of the Gui class. Build the
	 * Frame.
	 */
	public Gui() {
		setResizable(false);
		setTitle("OWL to SQL");
		setSize(450, 400);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		tabbedPane = new JTabbedPane();
		panOtS = new JPanel();
		panStO = new JPanel();
		panXtO = new JPanel();
		panOtoCpp = new JPanel();
		panCreate = new JPanel();
		panXOpenOnto = new JPanel();
		panXOpenXls = new JPanel();
		panImport = new JPanel();
		panCreateCpp = new JPanel();
		panGenerate = new JPanel();
		panGenerateCpp = new JPanel();
		panDb = new JPanel();
		panDbUrl = new JPanel();
		panDbUser = new JPanel();
		panDbPass = new JPanel();
		panDbName = new JPanel();
		panSave = new JPanel();
		panSaveCpp = new JPanel();
		path = new JTextField();
		pathSave = new JTextField();
		pathCpp = new JTextField();
		pathSaveCpp = new JTextField();
		pathXls = new JTextField();
		pathXlsOnto = new JTextField();
		user = new JTextField();
		jlUrl = new JLabel("            Host :");
		url = new JTextField();
		jlUser = new JLabel("User name :");
		pass = new JPasswordField();
		jlPass = new JLabel(" Password :");
		nameDb = new JTextField();
		jlName = new JLabel("     Schema :");
		url.setColumns(25);
		user.setColumns(25);
		pass.setColumns(25);
		nameDb.setColumns(25);
		browseCreate = new JButton("Browse");
		browseSave = new JButton("Browse");
		browseCreateCpp = new JButton("Browse");
		browseSaveCpp = new JButton("Browse");
		generateSql = new JButton("Generate SQL");
		generateCpp = new JButton("Generate C++ Classes");
		importTerms = new JButton("Import terms");
		browseXls = new JButton("Browse");
		browseXlsOnto = new JButton("Browse");
		tabbedPane = new JTabbedPane();
		panXtO.add(panXOpenOnto);
		panXtO.add(panXOpenXls);
		panXtO.add(panImport);
		panXOpenOnto.add(pathXlsOnto);
		panXOpenOnto.add(browseXlsOnto);
		panXOpenXls.add(pathXls);
		panXOpenXls.add(browseXls);
		panImport.add(importTerms);
		panOtS.add(panCreate);
		panOtS.add(panSave);
		panOtS.add(panGenerate);
		panOtoCpp.add(panCreateCpp);
		panOtoCpp.add(panSaveCpp);
		//panOtoCpp.add(panDb);
		panOtoCpp.add(panGenerateCpp);
		pathSaveCpp.setColumns(25);
		panSaveCpp.add(pathSaveCpp);
		pathCpp.setColumns(25);
		pathXls.setColumns(25);
		pathXlsOnto.setColumns(25);
		panCreateCpp.add(pathCpp);
		pathSave.setColumns(25);
		panSave.add(pathSave);
		panSave.add(browseSave);
		panSaveCpp.add(browseSaveCpp);
		panGenerate.add(generateSql);
		panGenerateCpp.add(generateCpp);
		panDb.setLayout(new GridLayout(4, 1));
		panDb.add(panDbUrl);
		panDb.add(panDbUser);
		panDb.add(panDbPass);
		panDb.add(panDbName);
		panDbUrl.add(jlUrl);
		panDbUrl.add(url);
		panDbUser.add(jlUser);
		panDbUser.add(user);
		panDbPass.add(jlPass);
		panDbPass.add(pass);
		panDbName.add(jlName);
		panDbName.add(nameDb);
		Border borderCreate = BorderFactory.createTitledBorder("Ontology Path");
		Border borderXls = BorderFactory.createTitledBorder("Excel file Path");
		Border borderSave = BorderFactory.createTitledBorder("Saves Path");
		Border borderCreateCpp = BorderFactory
				.createTitledBorder("Ontology Path");
		Border borderSaveCpp = BorderFactory.createTitledBorder("Saves Path");
		Border borderDb = BorderFactory.createTitledBorder("Info DataBase");
		panXOpenXls.setBorder(borderXls);
		panCreate.setBorder(borderCreate);
		panSave.setBorder(borderSave);
		panCreateCpp.setBorder(borderCreateCpp);
		panSaveCpp.setBorder(borderSaveCpp);
		panDb.setBorder(borderDb);
		panXOpenOnto.setBorder(borderCreate);
		path.setColumns(25);
		panCreate.add(path);
		panCreate.add(browseCreate);
		panCreateCpp.add(browseCreateCpp);

		path.setEditable(false);
		pathCpp.setEditable(false);
		pathSave.setEditable(false);
		pathSaveCpp.setEditable(false);
		pathXls.setEditable(false);
		pathXlsOnto.setEditable(false);

		// Add tab to the main pane
		tabbedPane.addTab("Owl to SQL", null, panOtS,
				"Generate your SQL database");
		tabbedPane.addTab("SQL to Owl", null, panStO,
				"Generate your Owl individuals");
		tabbedPane.addTab("Owl to C++", null, panOtoCpp,
				"Generate your C++ Classes");
		//tabbedPane.addTab("XLS(X) to OWL", null, panXtO,
			//	"Import terms from spreadsheet into your ontology");

		setContentPane(tabbedPane);
		// browse
		browseSave.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (arg0.getSource() != browseSave) {
					JFileChooser jfc = new JFileChooser();
					if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
						path.setText(jfc.getSelectedFile().getAbsolutePath());
						pathSave.setText(path.getText().substring(0,
								path.getText().lastIndexOf(File.separatorChar)));
					}
				} else {
					JFileChooser jfc = new JFileChooser();
					jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
					if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
						pathSave.setText(jfc.getSelectedFile()
								.getAbsolutePath());
					}
				}
			}
		});
		browseCreate.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (arg0.getSource() != browseSave) {
					JFileChooser jfc = new JFileChooser();
					if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
						path.setText(jfc.getSelectedFile().getAbsolutePath());
						pathSave.setText(path.getText().substring(0,
								path.getText().lastIndexOf(File.separatorChar)));
					}
				} else {
					JFileChooser jfc = new JFileChooser();
					jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
					if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
						pathSave.setText(jfc.getSelectedFile()
								.getAbsolutePath());
					}
				}
			}
		});
		browseXls.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				JFileChooser jfc = new JFileChooser();
				FileNameExtensionFilter xls = new FileNameExtensionFilter(
						"Excel file (.xls)", "xls");
				jfc.addChoosableFileFilter(xls);
				FileNameExtensionFilter xlsx = new FileNameExtensionFilter(
						"Excel file (.xlsx)", "xlsx");
				jfc.addChoosableFileFilter(xlsx);
				if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
					pathXls.setText(jfc.getSelectedFile().getAbsolutePath());
				}
			}
		});
		browseXlsOnto.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				JFileChooser jfc = new JFileChooser();
				if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
					pathXlsOnto
							.setText(jfc.getSelectedFile().getAbsolutePath());
				}
			}
		});
		// 2 cpp
		browseSaveCpp.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (arg0.getSource() != browseSaveCpp) {
					JFileChooser jfc = new JFileChooser();
					if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
						pathCpp.setText(jfc.getSelectedFile().getAbsolutePath());
						pathSaveCpp.setText(pathCpp.getText().substring(
								0,
								pathCpp.getText().lastIndexOf(
										File.separatorChar)));
					}
				} else {
					JFileChooser jfc = new JFileChooser();
					jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
					if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
						pathSaveCpp.setText(jfc.getSelectedFile()
								.getAbsolutePath());
					}
				}
			}
		});
		browseCreateCpp.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (arg0.getSource() != browseSaveCpp) {
					JFileChooser jfc = new JFileChooser();
					if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
						pathCpp.setText(jfc.getSelectedFile().getAbsolutePath());
						pathSaveCpp.setText(pathCpp.getText().substring(
								0,
								pathCpp.getText().lastIndexOf(
										File.separatorChar)));
					}
				} else {
					JFileChooser jfc = new JFileChooser();
					jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
					if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
						pathSaveCpp.setText(jfc.getSelectedFile()
								.getAbsolutePath());
					}
				}
			}
		});
		generateSql.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(final java.awt.event.ActionEvent evt) {
				try {
					if (path.getText().length() > 0
							&& pathSave.getText().length() > 0) {
						new Ontology(path.getText(), pathSave.getText());
						JOptionPane.showMessageDialog(getParent(),
								"Success\n\n" + "See your files in the folder "
										+ pathSave.getText());
					} else {
						JOptionPane.showMessageDialog(getParent(),
								"You must specify the paths");

					}

				} catch (Exception e) {
					e.printStackTrace();
					JOptionPane.showMessageDialog(getParent(),
							e.getStackTrace());
				}
			}
		});
		generateCpp.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(final java.awt.event.ActionEvent evt) {
				try {
					if (pathCpp.getText().length() > 0
							&& pathSaveCpp.getText().length() > 0) {
						Ontology o = new Ontology(pathCpp.getText(),
								pathSaveCpp.getText());
						codeGen = new CodeGenerator(pathSaveCpp.getText());
						codeGen.generateClasses(o);
						codeGen.generateDao(o, url.getText(), user.getText(),
								new String(pass.getPassword()),
								nameDb.getText());
						codeGen.generateConnection();

						JOptionPane.showMessageDialog(getParent(),
								"Success\n\n" + "See your files in the folder "
										+ pathSaveCpp.getText());
					} else {
						JOptionPane.showMessageDialog(getParent(),
								"You must specify the paths");

					}
				}

				catch (Exception e) {
					e.printStackTrace();
					JOptionPane.showMessageDialog(getParent(),
							e.getStackTrace());

				}

			}

		});
		/*importTerms.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(final java.awt.event.ActionEvent evt) {
				if (pathXls.getText().endsWith(".xls"))
					new ReadFileXLS(new File(pathXls.getText()), new Ontology(
							pathXlsOnto.getText(), pathXls.getText().substring(
									0,
									pathXls.getText().lastIndexOf(
											File.separatorChar))));
				else if (pathXls.getText().endsWith(".xlsx"))
					new ReadFileXLSX(new File(pathXls.getText()), new Ontology(
							pathXlsOnto.getText(), pathXls.getText().substring(
									0,
									pathXls.getText().lastIndexOf(
											File.separatorChar))));

			}
		});*/
		setVisible(true);
	}
	
	/**
	 * \brief Launcher
	 */
	public static void main(String[] args) {
		new Gui();
	}
}
