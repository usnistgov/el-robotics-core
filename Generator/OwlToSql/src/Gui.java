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
import Ontology.*;
import ClassesCPP.*;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.io.File;
import java.util.ArrayList;

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

public class Gui extends JFrame {

	private static final long serialVersionUID = 3136170074025065903L;
	private JTabbedPane tabbedPane;
	private JPanel panOtS;
	private JPanel panStO;
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
	private JLabel jlUser;
	private JLabel jlUrl;
	private JLabel jlPass;
	private JLabel jlName;
	private JTextField url;
	private JTextField user;
	private JPasswordField pass;
	private JTextField nameDb;
	private JPanel panSaveCpp;
	private JTextField path;
	private JTextField pathSave;
	private JButton browseCreate;
	private JButton browseSave;
	private JTextField pathCpp;
	private JTextField pathSaveCpp;
	private JButton browseCreateCpp;
	private JButton browseSaveCpp;
	private JButton generateSql;
	private JButton generateCpp;

	/**
     *  \brief Constructor
     *  \details Constructor of the Gui class. Build the Frame.
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
		panOtoCpp = new JPanel();
		panCreate = new JPanel();
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
		tabbedPane = new JTabbedPane();
		panOtS.add(panCreate);
		panOtS.add(panSave);
		panOtS.add(panGenerate);
		panOtoCpp.add(panCreateCpp);
		panOtoCpp.add(panSaveCpp);
		panOtoCpp.add(panDb);
		panOtoCpp.add(panGenerateCpp);
		pathSaveCpp.setColumns(25);
		panSaveCpp.add(pathSaveCpp);
		pathCpp.setColumns(25);
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
		Border borderSave = BorderFactory.createTitledBorder("Saves Path");
		Border borderCreateCpp = BorderFactory
				.createTitledBorder("Ontology Path");
		Border borderSaveCpp = BorderFactory.createTitledBorder("Saves Path");
		Border borderDb = BorderFactory.createTitledBorder("Info DataBase");
		panCreate.setBorder(borderCreate);
		panSave.setBorder(borderSave);
		panCreateCpp.setBorder(borderCreateCpp);
		panSaveCpp.setBorder(borderSaveCpp);
		panDb.setBorder(borderDb);
		path.setColumns(25);
		panCreate.add(path);
		panCreate.add(browseCreate);
		panCreateCpp.add(browseCreateCpp);
		path.setEditable(false);
		pathCpp.setEditable(false);
		pathSave.setEditable(false);
		pathSaveCpp.setEditable(false);
		// Add tab to the main pane
		tabbedPane.addTab("Owl to SQL", null, panOtS,
				"Generate your SQL database");
		tabbedPane.addTab("SQL to Owl", null, panStO,
				"Generate your Owl individuals");
		tabbedPane.addTab("Owl to C++", null, panOtoCpp,
				"Generate your C++ Classes");
		setContentPane(tabbedPane);
		//2 browse
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
						pathSave.setText(jfc.getSelectedFile().getAbsolutePath());
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
						pathSave.setText(jfc.getSelectedFile().getAbsolutePath());
					}
				}
			}
		});
		//2 cpp
		browseSaveCpp.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (arg0.getSource() != browseSaveCpp) {
					JFileChooser jfc = new JFileChooser();
					if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
						pathCpp.setText(jfc.getSelectedFile().getAbsolutePath());
						pathSaveCpp.setText(pathCpp.getText().substring(0,
								pathCpp.getText().lastIndexOf(File.separatorChar)));
					}
				} else {
					JFileChooser jfc = new JFileChooser();
					jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
					if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
						pathSaveCpp
								.setText(jfc.getSelectedFile().getAbsolutePath());
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
						pathSaveCpp.setText(pathCpp.getText().substring(0,
								pathCpp.getText().lastIndexOf(File.separatorChar)));
					}
				} else {
					JFileChooser jfc = new JFileChooser();
					jfc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
					if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
						pathSaveCpp
								.setText(jfc.getSelectedFile().getAbsolutePath());
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
						generateClasses(o);
						generateDao(o, url.getText(), user.getText(),
								new String(pass.getPassword()),
								nameDb.getText());
						generateConnection();

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
		setVisible(true);
	}

	/**
     *  \brief Generate the C++ classes
     *  \details Fill the attributes and unit collections based on the info from our ontology.
     *  \param o 	Our ontology.
     */
	@SuppressWarnings("unchecked")
	public void generateClasses(Ontology o) {
		for (int i = 0; i < o.getClassesClean().size(); i++) {
			Types typesGen = new Types(o.getClassesClean().get(i));
			ArrayList<String> attributes = new ArrayList<String>();
			ArrayList<String> unit = new ArrayList<String>();
			for (int j = 0; j < o.getDp().getDataPropertiesClean().size(); j++) {
				if (o.getDp().getDataPropertiesClean().get(j).get(0)
						.equals(o.getClassesClean().get(i))) {
					attributes = (ArrayList<String>) o.getDp()
							.getDataPropertiesClean().get(j).clone();
					attributes.remove(0);
					break;
				}
			}
			// Add the data Properties
			for (int k = 0; k < attributes.size(); k++) {
				for (int j = 0; j < o.getDp().getDataPropertyRanges().size(); j++) {
					if (o.getDp().getDataPropertyRanges().get(j).get(0)
							.equals(attributes.get(k))) {
						if (o.getDp().getDataSingleValued()
								.containsKey(attributes.get(k)))
							if (o.getDp().getDataSingleValued()
									.get(attributes.get(k)).equals("false"))
								unit.add("std::vector<"
										+ typesGen
												.getUnit(o
														.getTables()
														.unit(
																o.getDp()
																		.getDataPropertyRanges()
																		.get(j)
																		.get(1)))
										+ ">");
							else
								unit.add(typesGen
										.getUnit(o
												.getTables()
												.unit(
														o.getDp()
																.getDataPropertyRanges()
																.get(j).get(1))));
					}
				}
			}
			attributes.add("name");
			unit.add("std::string");
			attributes.add(o.getClassesClean().get(i) + "ID");
			unit.add("int");
			attributes.add("dao");
			unit.add("DAO*");

			// Add the Object Properties
			ArrayList<String> properties = o.getTables().getTables()
					.get(o.getClassesClean().get(i));
			String prop;
			for (int p = 0; p < properties.size(); p++) {
				if (properties.get(p).contains("/")) {
					prop = properties.get(p).substring(0,
							properties.get(p).indexOf("/"));

				} else {
					prop = properties.get(p);
				}
				boolean contains = false;
				for (ArrayList<String> oproperties : o.getOp()
						.getObjectPropertiesClean()) {
					if (oproperties.contains(prop)
							&& oproperties.indexOf(prop) > 0) {
						contains = true;
						for (int s = 0; s < o.getOp().getObjectPropertyRanges()
								.get(prop).size(); s++) {
							if (!attributes.contains(prop)) {
								attributes.add(prop);
								if (o.getOp().getObjectSingleValued().get(prop)
										.equals("false"))
									unit.add("std::vector<"
											+ o.getOp()
													.getObjectPropertyRanges()
													.get(prop).get(s) + "*>");
								else

									unit.add(o.getOp()
											.getObjectPropertyRanges()
											.get(prop).get(s)
											+ "*");
							}
						}
					}

				}

				// Add the remote Object Properties (to have the property for
				// both objects : range and domain)
				if (properties.get(p).contains("/")
						&& !contains
						&& !properties.get(p).contains("Value/")
						&& !attributes.contains(properties.get(p).substring(
								properties.get(p).indexOf("/") + 1,
								properties.get(p).length()))) {
					attributes.add(properties.get(p).substring(
							properties.get(p).indexOf("/") + 1,
							properties.get(p).length()));
					if (!o.getOp()
							.getObjectPropertyInverse()
							.containsKey(
									properties.get(p).substring(
											properties.get(p).indexOf("/") + 1,
											properties.get(p).length())))
						unit.add("std::vector<"
								+ properties.get(p).substring(0,
										properties.get(p).indexOf("/")) + "*>");

					else if (o
							.getOp()
							.getObjectSingleValued()
							.get(o.getOp()
									.getObjectPropertyInverse()
									.get(properties.get(p).substring(
											properties.get(p).indexOf("/") + 1,
											properties.get(p).length())))
							.equals("false")) {
						unit.add("std::vector<"
								+ properties.get(p).substring(0,
										properties.get(p).indexOf("/")) + "*>");
					}

					else {
						unit.add(properties.get(p).substring(0,
								properties.get(p).indexOf("/"))
								+ "*");
					}
				}

			}

			// Add the Object Properties (to have the property for both
			// objects : range and domain)
			for (int ind = 0; ind < o.getClassesClean().size(); ind++) {
				ArrayList<String> localProperties = (ArrayList<String>) o
						.getTables().getTables()
						.get(o.getClassesClean().get(ind)).clone();
				for (int indLp = 0; indLp < localProperties.size(); indLp++) {
					if (localProperties.get(indLp).contains("/")) {
						localProperties.set(
								indLp,
								localProperties.get(indLp)
										.substring(
												0,
												localProperties.get(indLp)
														.indexOf("/")));

					}
					if (o.getOp().getObjectPropertyRanges()
							.containsKey(localProperties.get(indLp))) {
						for (int a = 0; a < o.getOp().getObjectPropertyRanges()
								.get(localProperties.get(indLp)).size(); a++) {
							if (o.getOp().getObjectPropertyRanges()
									.get(localProperties.get(indLp)).get(a)
									.equals(o.getClassesClean().get(i))
									&& !attributes.contains(localProperties
											.get(indLp))) {
								attributes.add(localProperties.get(indLp));
								if (!o.getOp()
										.getObjectPropertyInverse()
										.containsKey(localProperties.get(indLp)))
									unit.add("std::vector<"
											+ o.getClassesClean().get(ind)
											+ "*>");

								else if (o
										.getOp()
										.getObjectSingleValued()
										.get(o.getOp()
												.getObjectPropertyInverse()
												.get(localProperties.get(indLp)))
										.equals("false"))
									unit.add("std::vector<"
											+ o.getClassesClean().get(ind)
											+ "*>");
								else

									unit.add(o.getClassesClean().get(ind) + "*");

							}
						}
					}
				}
			}

			// Write the header and class files
			typesGen.writeHeader(typesGen.generateHeader(o.getClassesClean()
					.get(i),
					o.getSuperClassesClean().get(o.getClassesClean().get(i)),
					attributes, unit), pathSaveCpp.getText() + File.separator);
			typesGen.writeClass(typesGen.generateCpp(o.getClassesClean().get(i), o
					.getSuperClassesClean().get(o.getClassesClean().get(i)),
					attributes, unit), pathSaveCpp.getText() + File.separator);

		}
	}

	/**
     *  \brief Generate the DAO files
     *  \param o 	Our ontology.
	 *  \param    url 	Host of your DB.
	 *  \param    user 	User name in the DB.
	 *  \param    pass 	Password of the user in the DB.
	 *  \param    nameDb 	DB Schema.
     */
	private void generateDao(Ontology o, String url, String user, String pass,
			String nameDb) {
		DaoGenerator dao = new DaoGenerator(o.getTables().getTables(),
				o.getSuperClassesClean(), o.getClassesClean(), o.getOp()
						.getObjectPropertyInverse(), o.getOp()
						.getObjectSingleValued(), o.getOp()
						.getObjectPropertyRanges(), o.getDp()
						.getDataSingleValued());
		ArrayList<String> attributes = new ArrayList<String>();
		attributes.add("className");
		attributes.add("connection");
		ArrayList<String> unit = new ArrayList<String>();
		unit.add("std::vector<std::string>");
		unit.add("Connection*");
		dao.writeHeader(
				dao.generateHeader(attributes, unit, url, user, pass, nameDb),
				pathSaveCpp.getText() + File.separator);
		dao.writeClass(
				dao.generateCpp(attributes, unit, url, user, pass, nameDb),
				pathSaveCpp.getText() + File.separator);
	}

	/**
     *  \brief Generate the C++ Connection files 
     */
	private void generateConnection() {
		new Connection(pathSaveCpp.getText() + File.separator);
	}
	/**
     *  \brief Launcher 
     */
	public static void main(String[] args) {
		new Gui();
	}
}
