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
 * \file      ReadFileXLS.java
 * \author    Anthony Pietromartire \a pietromartire.anthony\@nist.gov
 * \version   1.0
 * \date      29 June 2012
 * \brief     Class to import from XLS.
 *
 * \details   This class is used to import individuals in the ontology from a xls file.
 */

/**
 * \class 	ExcelImport.ReadFileXLS
 * \brief     Class to import from XLS.
 * \details   This class is used to import individuals in the ontology from a xls file.
 */

package ExcelImport;

import Ontology.*;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

public class ReadFileXLS {
	
	/**
	 * \brief Our excel file.
	 */
	private File selectedFile;
	/**
	 * \brief The ontology.
	 */
	private Ontology ontology;

	/**
	 * \brief Constructor 
	 * \details Constructor of the ReadFileXLS class. 
	 * \param selectedFile excel file.
	 * \param owl our ontology.
	 */
	public ReadFileXLS(File selectedFile, Ontology owl) {
		this.selectedFile = selectedFile;
		this.ontology = owl;
		open();
	}

	/**
	 * \brief Open the selected File and call the different methods to import the data.
	 */
	public void open() {
		InputStream inp;
		try {
			inp = new FileInputStream(selectedFile.getAbsolutePath());
			HSSFWorkbook workbook = new HSSFWorkbook(inp);
			addAllTerms(workbook);
			addPropertyForTerm(workbook);
			inp.close();
		} catch (FileNotFoundException e) {
		} catch (IOException e) {
		}

	}

	/**
	 * \brief Create the individuals.
	 */
	private void addAllTerms(HSSFWorkbook workbook) {
		HSSFSheet sheet = (HSSFSheet) workbook.getSheetAt(0);
		int j = 1;
		HSSFRow row = sheet.getRow(j);
		// Get the first column (Term URI)
		HSSFCell cell = row.getCell(0);
		String name = cell.getStringCellValue();
		cell = row.getCell(1);
		String type = cell.getStringCellValue();
		// browse the line in starting by the second (the first used to show
		// title of column)
		while (j < sheet.getLastRowNum() + 1 && !name.equals("")) {
			name = name.replaceAll(" ", "_");
			name = name.toLowerCase();
			ontology.addIndividual(name, type);
			j++;
			if (j < sheet.getLastRowNum() + 1) {
				row = sheet.getRow(j);
				// Get the first column (Term URI)
				cell = row.getCell(0);
				name = cell.getStringCellValue();
				cell = row.getCell(1);
				type = cell.getStringCellValue();
			}
		}
	}

	/**
	 * \brief Update the individuals.
	 */
	private void addPropertyForTerm(HSSFWorkbook workbook) {
		HSSFSheet sheet = (HSSFSheet) workbook.getSheetAt(0);
		int j = 1;
		HSSFRow row = sheet.getRow(j);
		HSSFCell cell = row.getCell(0);
		String name = cell.getStringCellValue();
		while (j < sheet.getLastRowNum() + 1 && !name.equals("")) {
			int i = 2;
			cell = sheet.getRow(0).getCell(i);
			String prop = "";
			if (cell != null) {
				if (cell.getCellType() == 0)
					prop = String.valueOf(cell.getNumericCellValue());
				else
					prop = cell.getStringCellValue();
			} else
				prop = "";
			while (!prop.equals("")) {
				String value = "";
				cell = row.getCell(i);
				if (cell != null) {
					if (cell.getCellType() == 0)
						value = String.valueOf(cell.getNumericCellValue());
					else
						value = cell.getStringCellValue();
				} else
					value = "";
				if (ontology.getDp().getDataRequired().containsKey(prop))
					ontology.addDataPropertyValue(name, value, prop);
				else if (ontology.getOp().getObjectRequired().containsKey(prop))
					ontology.addObjectPropertyValue(name, value, prop);
				i++;
				cell = sheet.getRow(0).getCell(i);
				if (cell != null)
					prop = cell.getStringCellValue();
				else
					prop = "";

			}
			j++;
			if (j < sheet.getLastRowNum() + 1) {
				row = sheet.getRow(j);
				cell = row.getCell(0);
				name = cell.getStringCellValue();
			}
		}
	}
}
