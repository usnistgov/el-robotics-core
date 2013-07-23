

import java.io.File;

import org.semanticweb.owlapi.io.OWLOntologyInputSourceException;

import Ontology.Ontology;

public class CommandLine {

	private String pathSaveCpp, pathSaveSql, owlIn;
	//private String databaseUser, databasePass, databaseName;
	//private String hostname;
	private CodeGenerator codeGen;
	private boolean cppGen = false;
	
	public boolean genCpp() {
		return cppGen;
	}
	
	public CommandLine() {
		/*databasePass = "";
		hostname = "localhost";
		databaseUser = null;
		databaseName = null;*/
		pathSaveSql = null;
		owlIn = null;
		pathSaveCpp = null;
	}
	
	public void generateDao(Ontology o) {
		//codeGen.generateDao(o, hostname, databaseUser, databasePass, databaseName);
		codeGen.generateDao(o, null, null, null, null);
	}
	public void generateConnection() {
		codeGen.generateConnection();
	}
	public void generateClasses(Ontology o) {
		codeGen.generateClasses(o);
	}
	/**
	 * \brief If necessary, convert relative path parameters to absolute
	 */
	public void fixPaths() {
		File currentDir = new File(System.getProperty("user.dir"));
		File owlFile = new File(currentDir, owlIn);
		if(!(new File(owlIn).isAbsolute()))
			owlIn = owlFile.getAbsolutePath();
		
		if(cppGen) {
			File cppFile = new File(currentDir, pathSaveCpp);
			if(!(new File(pathSaveCpp).isAbsolute())) {
				pathSaveCpp = cppFile.getAbsolutePath();
			}
		} else {
			File sqlFile = new File(currentDir, pathSaveSql);
			if(!(new File(pathSaveSql).isAbsolute()))
				pathSaveSql = sqlFile.getAbsolutePath();
		}
		
	}
	public boolean isSetup() {
		//if(databaseUser == null || databaseName == null ||
		if(		owlIn == null || (pathSaveCpp == null && pathSaveSql == null))
			return false;
		return true;
	}
	/**
	 * \brief Parse program arguments
	 */
	private void parseArgs(String[] args) throws Exception{
		int index = 0;
		while(index < args.length)
		{
			try
			{
				if(args[index].equals("-owl")) {
					this.owlIn = args[++index];
				} else if(args[index].equals("-sql")) {
					this.pathSaveSql = args[++index];
					cppGen = false;
				} else if(args[index].equals("-cpp")) {
					this.pathSaveCpp = args[++index];
					cppGen = true;
				}
				//don't need database vars anymore
				/* else if(args[index].equals("-host")) {
					this.hostname = args[++index];
				} else if(args[index].equals("-user")) {
					this.databaseUser = args[++index];
				} else if(args[index].equals("-pass")) {
					this.databasePass = args[++index];
				} else if(args[index].equals("-database")) {
					this.databaseName = args[++index];
				}*/ else {
					throw new Exception();
				}
			} catch(ArrayIndexOutOfBoundsException e)
			{
				throw e;
			}
			index++;
		}
	}
	public Ontology getNewOntology() {
		Ontology o;
		if(cppGen) {
			o = new Ontology(owlIn, pathSaveCpp);
		}
		else
			o = new Ontology(owlIn, pathSaveSql);
		return o;
	}
	public void generateCpp(Ontology o) {
		codeGen = new CodeGenerator(pathSaveCpp);
		generateClasses(o);
		generateDao(o);
		generateConnection();
	}
	public static void main(String[] args) {
		CommandLine commandLine = new CommandLine();
		try
		{
			commandLine.parseArgs(args);
			if(!commandLine.isSetup()) {
				throw new Exception();
			}
		}
		catch(Exception e)
		{
			System.err.println("Error: incorrect usage of generator_no_gui");
			System.out.println("Correct usage is:\n" +
					"generator_no_gui.jar -owl owlInputFile " +
					"[-sql sql_output_directory|-cpp cpp_output_directory]");
			System.exit(1);
			
		}
		commandLine.fixPaths();
		try
		{
			Ontology o = commandLine.getNewOntology();
			if(commandLine.genCpp()) {
				commandLine.generateCpp(o);
			}
		}catch(OWLOntologyInputSourceException e)
		{
			System.err.println(e.getMessage());
		}
	}
}
