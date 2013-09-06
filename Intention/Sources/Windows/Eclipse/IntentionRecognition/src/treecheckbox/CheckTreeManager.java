package treecheckbox;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Enumeration;
import java.util.List;
import java.util.Stack;

import javax.swing.JCheckBox;
import javax.swing.JTree;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.TreeModel;
import javax.swing.tree.TreePath;




public class CheckTreeManager extends MouseAdapter implements TreeSelectionListener{ 
    private CheckTreeSelectionModel selectionModel; 
    private JTree tree = new JTree(); 
    int hotspot = new JCheckBox().getPreferredSize().width; 
 
    public CheckTreeManager(JTree tree){ 
        this.tree = tree; 
        selectionModel = new CheckTreeSelectionModel(tree.getModel()); 
        tree.setCellRenderer(new CheckTreeCellRenderer(tree.getCellRenderer(), selectionModel)); 
        tree.addMouseListener(this); 
        selectionModel.addTreeSelectionListener(this); 
    } 
    public void addChildPaths(TreePath path, TreeModel model, List result){
        Object item = path.getLastPathComponent();
        int childCount = model.getChildCount(item);
        for(int i = 0; i<childCount; i++)
            result.add(path.pathByAddingChild(model.getChild(item, i)));
    }

    public ArrayList getDescendants(TreePath paths[] , TreeModel model){
        ArrayList result = new ArrayList();
        Stack pending = new Stack();
        pending.addAll(Arrays.asList(paths));
        while(!pending.isEmpty()){
            TreePath path = (TreePath)pending.pop();
            addChildPaths(path, model, pending);
            result.add(path);
        }
        return result;
    }
    
    public ArrayList<Object> getAllCheckedPaths(CheckTreeManager manager, JTree tree){
        return getDescendants(manager.getSelectionModel().getSelectionPaths(), tree.getModel());
    }

    /**
     * 
     */
    public void mouseClicked(MouseEvent me){ 
    	TreePath path = tree.getPathForLocation(me.getX(), me.getY()); 

    	
    	DefaultMutableTreeNode node = (DefaultMutableTreeNode) path.getLastPathComponent();
    	 
       // DefaultMutableTreeNode node = ((DefaultMutableTreeNode)path.getLastPathComponent()).getUserObject();;
        Object nodeInfo = node.getUserObject();
        if (node.isLeaf()){
        	//System.out.println("yep leaf");
        	//System.out.println(node.getParent().toString());
        	//System.out.println(node.toString());
      	  //RobotDisplay.RobotInfo robot = (RobotDisplay.RobotInfo)nodeInfo;
      	  //RobotUtil.showRobotInfo((String) robot.getRobotLabel());
      }
        
        if(path==null) 
            return; 
        if(me.getX()>tree.getPathBounds(path).x+hotspot) 
            return; 
        

 
        boolean selected = selectionModel.isPathSelected(path, true); 
        selectionModel.removeTreeSelectionListener(this); 

        try{ 
            if(selected) 
                selectionModel.removeSelectionPath(path); 
            else 
                selectionModel.addSelectionPath(path); 
        } finally{ 
            selectionModel.addTreeSelectionListener(this); 
            tree.treeDidChange(); 
        } 
    }

 
    public CheckTreeSelectionModel getSelectionModel(){ 
        return selectionModel; 
    } 
 
    public void valueChanged(TreeSelectionEvent e){ 
        tree.treeDidChange(); 
        System.out.println("click click");
    } 
}