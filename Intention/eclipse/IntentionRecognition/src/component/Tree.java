package component;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.net.URL;

import javax.swing.JEditorPane;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JTree;
import javax.swing.UIManager;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.TreeSelectionModel;

import orderingconstruct.AnyOrderOrderingConstruct;

public class Tree extends JPanel implements TreeSelectionListener{

	private JEditorPane htmlPane;
	private JTree tree;
	private URL helpURL;
	private static boolean DEBUG = true;
	//Optionally play with line styles.  Possible values are
	//"Angled" (the default), "Horizontal", and "None".
	private static boolean playWithLineStyle = false;
	private static String lineStyle = "Horizontal";

	//Optionally set the look and feel.
	private static boolean useSystemLookAndFeel = false;

	public Tree() {
		super(new GridLayout(1,0));
		//Create the nodes.
		DefaultMutableTreeNode top = new DefaultMutableTreeNode("Kit_A2B2C1D1");
		createNodes(top);

		//Create a tree that allows one selection at a time.
		tree = new JTree(top);
		tree.getSelectionModel().setSelectionMode
		(TreeSelectionModel.SINGLE_TREE_SELECTION);

		//Listen for when the selection changes.
		tree.addTreeSelectionListener(this);

		if (playWithLineStyle) {
			System.out.println("line style = " + lineStyle);
			tree.putClientProperty("JTree.lineStyle", lineStyle);
		}

		//Create the scroll pane and add the tree to it. 
		JScrollPane treeView = new JScrollPane(tree);

		//Create the HTML viewing pane.
		htmlPane = new JEditorPane();
		htmlPane.setEditable(false);
		
		JScrollPane htmlView = new JScrollPane(htmlPane);

		//Add the scroll panes to a split pane.
		JSplitPane splitPane = new JSplitPane(JSplitPane.VERTICAL_SPLIT);
		splitPane.setTopComponent(treeView);
		splitPane.setBottomComponent(htmlView);

		Dimension minimumSize = new Dimension(100, 50);
		htmlView.setMinimumSize(minimumSize);
		treeView.setMinimumSize(minimumSize);
		splitPane.setDividerLocation(100); 
		splitPane.setPreferredSize(new Dimension(500, 300));

		//Add the split pane to this panel.
		add(splitPane);
	}


	


	private void createTop(){
		DefaultMutableTreeNode top = new DefaultMutableTreeNode("Kit_A2B2C1D1");
		createNodes(top);
		tree = new JTree(top);
	}

	public void createNodes(DefaultMutableTreeNode top){
		
		DefaultMutableTreeNode anyorderOCTree = null;
		DefaultMutableTreeNode countOC = null;
		DefaultMutableTreeNode existOC = null;
		DefaultMutableTreeNode orderedlistOC = null;
		DefaultMutableTreeNode ontopwithcontactSR = null;
		DefaultMutableTreeNode partiallyinSR = null;
		DefaultMutableTreeNode underwithcontactSR = null;

		orderedlistOC = new DefaultMutableTreeNode("OC13");
		top.add(orderedlistOC);

		existOC = new DefaultMutableTreeNode("OC1");
		orderedlistOC.add(existOC);

		existOC = new DefaultMutableTreeNode("OC11");
		orderedlistOC.add(existOC);

		//AnyOrderOrderingConstruct anyorderOC = new AnyOrderOrderingConstruct("OC10");
		anyorderOCTree = new DefaultMutableTreeNode(new AnyOrderOrderingConstruct("OC10"));
		orderedlistOC.add(anyorderOCTree);
	}

	/**
     * Create the GUI and show it.  For thread safety,
     * this method should be invoked from the
     * event dispatch thread.
     */
    public static void createAndShowGUI() {
        if (useSystemLookAndFeel) {
            try {
                UIManager.setLookAndFeel(
                    UIManager.getSystemLookAndFeelClassName());
            } catch (Exception e) {
                System.err.println("Couldn't use system look and feel.");
            }
        }
 
        //Create and set up the window.
        JFrame frame = new JFrame("TreeDemo");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
        //Add content to the window.
        frame.add(new Tree());
 
        //Display the window.
        frame.pack();
        frame.setVisible(true);
    }
    
	@Override
	public void valueChanged(TreeSelectionEvent e) {
		DefaultMutableTreeNode node = (DefaultMutableTreeNode)
				tree.getLastSelectedPathComponent();
		
		if (node == null) return;
		
		Object nodeInfo = node.getUserObject();
       
        if (DEBUG) {
            System.out.println(nodeInfo.toString());
        }
	}

}
