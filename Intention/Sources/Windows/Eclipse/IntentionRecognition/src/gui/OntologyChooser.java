/****************************************************************************************************************************************************
   DISCLAIMER:
   This software was produced by the National Institute of Standards and Technology (NIST), an agency of the U.S. government, and by 
   statute is not subject to copyright in the United States.  
   Recipients of this software assume all responsibility associated with its operation, modification, maintenance, and subsequent redistribution.

   See NIST Administration Manual 4.09.07 b and Appendix I.
 ****************************************************************************************************************************************************/
package gui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

import javax.print.attribute.AttributeSet;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyleContext;
import javax.swing.text.StyledDocument;

/**
 * @author zeid This class consists of methods that allow the user to select the
 *         kittingInstances.owl file
 */
public class OntologyChooser extends JPanel implements ActionListener {
	static private final String newline = "\n";
	JButton openButton, saveButton;
	JTextArea log;
	JFileChooser fc;

	/**
	 * 
	 */
	public OntologyChooser() {
		super(new BorderLayout());
		// Create the log first, because the action listeners
		// need to refer to it.
		log = new JTextArea(5, 30);
		log.setMargin(new Insets(5, 5, 5, 5));
		log.setEditable(false);
		JScrollPane logScrollPane = new JScrollPane(log);

		// Create a file chooser
		fc = new JFileChooser();

		// Uncomment one of the following lines to try a different
		// file selection mode. The first allows just directories
		// to be selected (and, at least in the Java look and feel,
		// shown). The second allows both files and directories
		// to be selected. If you leave these lines commented out,
		// then the default mode (FILES_ONLY) will be used.
		//
		// fc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
		// fc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);

		// Create the open button. We use the image from the JLF
		// Graphics Repository (but we extracted it from the jar).
		openButton = new JButton("Open");
		openButton.addActionListener(this);

		/*
		 * //Create the save button. We use the image from the JLF //Graphics
		 * Repository (but we extracted it from the jar). saveButton = new
		 * JButton("Save a File...", createImageIcon("images/Save16.gif"));
		 * saveButton.addActionListener(this);
		 */

		// For layout purposes, put the buttons in a separate panel
		JPanel buttonPanel = new JPanel(); // use FlowLayout
		buttonPanel.add(openButton);
		// buttonPanel.add(saveButton);

		// Add the buttons and the log to this panel.
		add(buttonPanel, BorderLayout.PAGE_START);
		add(logScrollPane, BorderLayout.CENTER);

		log.append("Select kittingInstances.owl" + newline);
		log.append("kittingInstances.owl, soap.owl and kittingClasses.owl"
				+ newline + "must be in the same directory" + newline);
	}

	@Override
	public void actionPerformed(ActionEvent e) {

		// Handle open button action.
		if (e.getSource() == openButton) {
			int returnVal = fc.showOpenDialog(OntologyChooser.this);

			if (returnVal == JFileChooser.APPROVE_OPTION) {
				File file = fc.getSelectedFile();
				// This is where a real application would open the file.
				log.append("Opening: " + file.getName() + "." + newline);
			}
			log.setCaretPosition(log.getDocument().getLength());
		}

	}

	/** Returns an ImageIcon, or null if the path was invalid. */
	protected static ImageIcon createImageIcon(String path) {
		java.net.URL imgURL = OntologyChooser.class.getResource(path);
		if (imgURL != null) {
			return new ImageIcon(imgURL);
		} else {
			System.err.println("Couldn't find file: " + path);
			return null;
		}
	}

	/**
	 * Create the GUI and show it. For thread safety, this method should be
	 * invoked from the event dispatch thread.
	 */
	public static void createAndShowGUI() {
		// Create and set up the window.
		JFrame frame = new JFrame("FileChooserDemo");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// Add content to the window.
		frame.add(new OntologyChooser());

		// Display the window.
		frame.pack();
		frame.setVisible(true);
	}

}
