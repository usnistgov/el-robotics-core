// Decompiled by Jad v1.5.8e2. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://kpdus.tripod.com/jad.html
// Decompiler options: packimports(3) fieldsfirst ansi space 

package gui;

import java.awt.*;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;
import javax.swing.JPanel;
import org.jfree.text.TextUtilities;
import org.jfree.ui.TextAnchor;

public class DrawStringPanel extends JPanel {

	private static final Dimension PREFERRED_SIZE = new Dimension(500, 300);
	private boolean rotate;
	private String text;
	private TextAnchor anchor;
	private TextAnchor rotationAnchor;
	private Font font;
	private double angle;

	public DrawStringPanel(String s, boolean flag) {
		text = "Hello World";
		anchor = TextAnchor.TOP_LEFT;
		rotationAnchor = TextAnchor.TOP_LEFT;
		font = new Font("Serif", 0, 12);
		text = s;
		rotate = flag;
	}

	public Dimension getPreferredSize() {
		return PREFERRED_SIZE;
	}

	public void setAnchor(TextAnchor textanchor) {
		anchor = textanchor;
	}

	public void setRotationAnchor(TextAnchor textanchor) {
		rotationAnchor = textanchor;
	}

	public void setAngle(double d) {
		angle = d;
	}

	public Font getFont() {
		return font;
	}

	public void setFont(Font font1) {
		font = font1;
	}

	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		Graphics2D graphics2d = (Graphics2D) g;
		Dimension dimension = getSize();
		Insets insets = getInsets();
		java.awt.geom.Rectangle2D.Double double1 = new java.awt.geom.Rectangle2D.Double(
				insets.left, insets.top, dimension.getWidth()
						- (double) insets.left - (double) insets.right,
				dimension.getHeight() - (double) insets.top
						- (double) insets.bottom);
		double d = double1.getCenterX();
		double d1 = double1.getCenterY();
		java.awt.geom.Line2D.Double double2 = new java.awt.geom.Line2D.Double(
				d - 2D, d1 + 2D, d + 2D, d1 - 2D);
		java.awt.geom.Line2D.Double double3 = new java.awt.geom.Line2D.Double(
				d - 2D, d1 - 2D, d + 2D, d1 + 2D);
		graphics2d.setPaint(Color.red);
		graphics2d.draw(double2);
		graphics2d.draw(double3);
		graphics2d.setFont(font);
		graphics2d.setPaint(Color.black);
		if (rotate)
			TextUtilities.drawRotatedString(text, graphics2d, (float) d,
					(float) d1, anchor, angle, rotationAnchor);
		else
			TextUtilities.drawAlignedString(text, graphics2d, (float) d,
					(float) d1, anchor);
	}

}
