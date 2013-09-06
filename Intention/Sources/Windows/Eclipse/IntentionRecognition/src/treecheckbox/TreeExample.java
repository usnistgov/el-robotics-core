package treecheckbox;

import java.awt.*;
import javax.swing.*;

public class TreeExample extends JPanel{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
		// Instance attributes used in this example
		private	JPanel		topPanel;
		private	JTree		tree;
		private	JScrollPane scrollPane;

		// Constructor of main frame
		public TreeExample()
		{
			// Set the frame characteristics
	
			// Create a panel to hold all other components
			topPanel = new JPanel();
			topPanel.setLayout( new BorderLayout() );
			

			// Create a new tree control
			tree = new JTree();

			// Add the listbox to a scrolling pane
			scrollPane = new JScrollPane();
			scrollPane.getViewport().add( tree );
			topPanel.add( scrollPane, BorderLayout.CENTER );
		}
}
