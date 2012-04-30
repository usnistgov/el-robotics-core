import Ontology.*;
import ClassesCPP.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.ArrayList;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
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

	public Gui() {
		setResizable(false);
		setTitle("OWL to SQL");
		setSize(400, 300);
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
		panSave = new JPanel();
		panSaveCpp = new JPanel();
		path = new JTextField();
		pathSave = new JTextField();
		pathCpp = new JTextField();
		pathSaveCpp = new JTextField();
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
		panOtoCpp.add(panCreateCpp);
		panOtoCpp.add(panSaveCpp);
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
		Border borderCreate = BorderFactory.createTitledBorder("Ontology Path");
		Border borderSave = BorderFactory.createTitledBorder("Saves Path");
		Border borderCreateCpp = BorderFactory
				.createTitledBorder("Ontology Path");
		Border borderSaveCpp = BorderFactory.createTitledBorder("Saves Path");
		panCreate.setBorder(borderCreate);
		panSave.setBorder(borderSave);
		panCreateCpp.setBorder(borderCreateCpp);
		panSaveCpp.setBorder(borderSaveCpp);
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
		browseSave.addActionListener(new browseListener());
		browseCreate.addActionListener(new browseListener());
		browseSaveCpp.addActionListener(new browseListenerCpp());
		browseCreateCpp.addActionListener(new browseListenerCpp());
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
					JOptionPane
							.showMessageDialog(getParent(),
									"Error : Submit your ontology to a validator (on the W3C web site)");
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
						generateDao(o);

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
					JOptionPane
							.showMessageDialog(getParent(),
									"Error : Submit your ontology to a validator (on the W3C web site)");
				}

			}

		});

		setVisible(true);

	}

	public class browseListener implements ActionListener {

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

	}

	public class browseListenerCpp implements ActionListener {

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

	}

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
						if (o.getDp().getDataRequired()
								.containsKey(attributes.get(k)))
							if (o.getDp().getDataSingleValued()
									.get(attributes.get(k)).equals("false"))
								attributes.set(k, attributes.get(k) + "[]");
						unit.add(typesGen.getUnit(o.getTables()
								.getUnit(
										o.getDp().getDataPropertyRanges()
												.get(j).get(1))));
					}
				}
			}
			attributes.add("name");
			unit.add("std::string");
			attributes.add("id");
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
								unit.add(o.getOp().getObjectPropertyRanges()
										.get(prop).get(s)
										+ "*");
							}
						}
					}

				}
				if (properties.get(p).contains("/")
						&& !contains
						&& !properties.get(p).contains("Value/")
						&& !attributes.contains(properties.get(p).substring(
								properties.get(p).indexOf("/") + 1,
								properties.get(p).length()))) {
					attributes.add(properties.get(p).substring(
							properties.get(p).indexOf("/") + 1,
							properties.get(p).length()));
					unit.add(properties.get(p).substring(0,
							properties.get(p).indexOf("/"))
							+ "*");
				}

			}

			// Write the header and class files
			typesGen.writeHeader(typesGen.generateHeader(o.getClassesClean()
					.get(i),
					o.getSuperClassesClean().get(o.getClassesClean().get(i)),
					attributes, unit), pathSaveCpp.getText() + File.separator);
			typesGen.writeClass(typesGen.generateCpp(
					o.getClassesClean().get(i),
					o.getSuperClassesClean().get(o.getClassesClean().get(i)),
					attributes, unit), pathSaveCpp.getText() + File.separator);

		}
	}

	private void generateDao(Ontology o) {
		daoGenerator dao = new daoGenerator();
		ArrayList<String> className = new ArrayList<String>();

		className.add("Connect");

		ArrayList<String> attributes = new ArrayList<String>();
		attributes.add("className");
		ArrayList<String> unit = new ArrayList<String>();
		unit.add("std::string");
		dao.writeHeader(dao.generateHeader(className, attributes, unit),
				pathSaveCpp.getText() + File.separator);
		dao.writeClass(dao.generateCpp(className, attributes, unit),
				pathSaveCpp.getText() + File.separator);
	}

	public static void main(String[] args) {
		new Gui();
	}
}
