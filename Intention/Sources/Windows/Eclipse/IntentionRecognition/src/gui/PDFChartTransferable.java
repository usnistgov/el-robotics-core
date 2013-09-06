// Decompiled by Jad v1.5.8e2. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://kpdus.tripod.com/jad.html
// Decompiler options: packimports(3) fieldsfirst ansi space 

package gui;

import com.lowagie.text.*;
import com.lowagie.text.pdf.*;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.datatransfer.*;
import java.awt.geom.Rectangle2D;
import java.io.*;

import org.jfree.chart.JFreeChart;

public class PDFChartTransferable implements Transferable {

	final DataFlavor pdfFlavor;
	private JFreeChart chart;
	private int width;
	private int height;

	public PDFChartTransferable(JFreeChart jfreechart, int i, int j) {
		this(jfreechart, i, j, true);
	}

	public PDFChartTransferable(JFreeChart jfreechart, int i, int j,
			boolean flag) {
		pdfFlavor = new DataFlavor("application/pdf", "PDF");
		try {
			chart = (JFreeChart) jfreechart.clone();
		} catch (CloneNotSupportedException clonenotsupportedexception) {
			chart = jfreechart;
		}
		width = i;
		height = j;
	}

	public DataFlavor[] getTransferDataFlavors() {
		return (new DataFlavor[] { pdfFlavor });
	}

	public boolean isDataFlavorSupported(DataFlavor dataflavor) {
		return pdfFlavor.equals(dataflavor);
	}

	public Object getTransferData(DataFlavor dataflavor)
			throws UnsupportedFlavorException, IOException {
		if (pdfFlavor.equals(dataflavor)) {
			ByteArrayOutputStream bytearrayoutputstream = new ByteArrayOutputStream();
			writeChartAsPDF(bytearrayoutputstream, chart, width, height,
					new DefaultFontMapper());
			return new ByteArrayInputStream(bytearrayoutputstream.toByteArray());
		} else {
			throw new UnsupportedFlavorException(dataflavor);
		}
	}

	public static void writeChartAsPDF(
			ByteArrayOutputStream bytearrayoutputstream, JFreeChart jfreechart,
			int i, int j, FontMapper fontmapper) throws IOException {
		Rectangle rectangle = new Rectangle(i, j);
		// Document document = new Document(rectangle, 50F, 50F, 50F, 50F);
		Document document = new Document();

		try {
			PdfWriter pdfwriter = PdfWriter.getInstance(document,
					bytearrayoutputstream);
			document.addAuthor("JFreeChart");
			document.addSubject("Demonstration");
			document.open();
			PdfContentByte pdfcontentbyte = pdfwriter.getDirectContent();
			PdfTemplate pdftemplate = pdfcontentbyte.createTemplate(i, j);
			Graphics2D graphics2d = pdftemplate
					.createGraphics(i, j, fontmapper);
			java.awt.geom.Rectangle2D.Double double1 = new java.awt.geom.Rectangle2D.Double(
					0.0D, 0.0D, i, j);
			jfreechart.draw(graphics2d, double1);
			graphics2d.dispose();
			pdfcontentbyte.addTemplate(pdftemplate, 0.0F, 0.0F);
		} catch (DocumentException documentexception) {
			System.err.println(documentexception.getMessage());
		}
		document.close();
	}
}
