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
 * \file      WriteFileXLSX.java
 * \author    Anthony Pietromartire \a pietromartire.anthony\@nist.gov
 * \version   1.0
 * \date      29 June 2012
 * \brief     Class to export model to import XLSX.
 *
 * \details   This class is used to export model of the files used to import individuals in the ontology from a xls file.
 */

/**
 * \class 	ExcelImport.WriteFileXLS
 * \brief     Class to export model to import XLSX.
 * \details   This class is used to export model of the files used to import individuals in the ontology from a xls file.
 */

package ExcelExport;

import Ontology.*;

import java.awt.Color;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;

import org.apache.poi.xssf.usermodel.XSSFCell;
import org.apache.poi.xssf.usermodel.XSSFCellStyle;
import org.apache.poi.xssf.usermodel.XSSFColor;
import org.apache.poi.xssf.usermodel.XSSFRow;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

public class WriteFileXLSX {
	XSSFRow row;
	XSSFCellStyle style;
	XSSFCell cell;
	XSSFWorkbook wb;
	XSSFSheet sheet1;
	ArrayList<String> classAdded;
	int indexCol;
	ArrayList<String> parents;
	/**
	 * \brief Path of our excel file.
	 */
	private String selectedFilePath;
	/**
	 * \brief The ontology.
	 */
	private Ontology ontology;

	/**
	 * \brief Constructor \details Constructor of the ReadFileXLS class. \param
	 * selectedFile excel file. \param owl our ontology.
	 */
	public WriteFileXLSX(String selectedFilePath, Ontology owl) {
		this.selectedFilePath = selectedFilePath;
		this.ontology = owl;
		classAdded = new ArrayList<String>();
		parents = new ArrayList<String>();
		create();
	}

	/**
	 * \brief Create the excel file.
	 */
	private void create() {
		OutputStream out;
		for (String classe : ontology.getClassesClean()) {
			try {
				out = new FileOutputStream(selectedFilePath + classe + ".xlsx");
				wb = new XSSFWorkbook();
				sheet1 = wb.createSheet("Sheet1");
				// Create a row and put some cells in it. Rows are 0 based.
				row = sheet1.createRow(0);
				// Create cell style
				style = wb.createCellStyle();
				style.setFillPattern(XSSFCellStyle.SOLID_FOREGROUND);
				style.setFillForegroundColor(new XSSFColor(Color.CYAN));
				// Create default cells.
				cell = row.createCell(0);
				cell.setCellValue("Individual Name");
				cell.setCellStyle(style);
				cell = row.createCell(1);
				cell.setCellValue("Type");
				cell.setCellStyle(style);
				row = sheet1.createRow(1);
				cell = row.createCell(1);
				cell.setCellValue(classe);
				row = sheet1.getRow(0);
				// add data properties
				indexCol = 2;
				classAdded.clear();
				addColumn(classe);

				wb.write(out);
				out.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	private void addColumn(String classe) {
		parents.clear();
		getParent(classe);
		for (int i = 0; i < ontology.getDp().getDataPropertiesClean().size(); i++) {
			if (ontology.getDp().getDataPropertiesClean().get(i).get(0)
					.equals(classe)
					|| parents.contains(ontology.getDp()
							.getDataPropertiesClean().get(i).get(0)))
				for (int j = 1; j < ontology.getDp().getDataPropertiesClean()
						.get(i).size(); j++) {
					cell = row.createCell(indexCol);
					cell.setCellValue(ontology.getDp().getDataPropertiesClean()
							.get(i).get(j));
					cell.setCellStyle(style);
					indexCol++;
				}
		}
		// add object properties
		for (int i = 0; i < ontology.getOp().getObjectPropertiesClean().size(); i++) {
			if (ontology.getOp().getObjectPropertiesClean().get(i).get(0)
					.equals(classe)
					|| parents.contains(ontology.getOp()
							.getObjectPropertiesClean().get(i).get(0)))
				for (int j = 1; j < ontology.getOp().getObjectPropertiesClean()
						.get(i).size(); j++) {
					cell = row.createCell(indexCol);
					cell.setCellValue(ontology.getOp()
							.getObjectPropertiesClean().get(i).get(j));
					cell.setCellStyle(style);
					indexCol++;
					/*for (String range : ontology
							.getOp()
							.getObjectPropertyRanges()
							.get(ontology.getOp().getObjectPropertiesClean()
									.get(i).get(j))) {
						if (!classAdded.contains(ontology.getOp()
								.getObjectPropertiesClean().get(i).get(j))) {
							classAdded.add(ontology.getOp()
									.getObjectPropertiesClean().get(i).get(j));
							addColumn(range);
						}

					}*/
				}
		}
	}

	public void getParent(String classe) {
		if (ontology.getSuperClassesClean().get(classe) != null) {
			for (String parent : ontology.getSuperClassesClean().get(classe)) {
				parents.add(parent);
				getParent(parent);
			}
		}
	}

}
