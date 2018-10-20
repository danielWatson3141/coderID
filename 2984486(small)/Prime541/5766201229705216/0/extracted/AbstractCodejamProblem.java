
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.LineNumberReader;
import java.io.Reader;
import java.io.Writer;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.util.Vector;

/**
 * 
 * @author Guillaume Giffard
 *
 */
public abstract class AbstractCodejamProblem {
	
	/*
	 * Interesting part to solve a codejam problem
	 */
	
	private boolean _isVerbose = false;
	private final void setVerbose(boolean iIsVerbose) {_isVerbose = iIsVerbose;}
	public final boolean isVerbose() {return _isVerbose;}

	private Reader _input = null;
	private final void setInput(Reader iInput) {_input = iInput;}
	public final Reader getInput() {return _input;}

	private Writer _output = null;
	private final void setOutput(Writer iOutput) {_output = iOutput;}
	public final Writer getOutput() {return _output;}
	
	private int _caseNo = -1;
	public final void setCaseNo(int iCaseNo) {_caseNo = iCaseNo;}
	public final int getCaseNo() {return _caseNo;}

	private int _caseNoExpected = -1;
	public final void setCaseNoExpected(int iCaseNoExpected) {_caseNoExpected = iCaseNoExpected;}
	public final int getCaseNoExpected() {return _caseNoExpected;}
	
	protected abstract void executeInput();
	
	/*
	 * Generic part, not to be read
	 */
	
	private static void printHelp() {
		System.out.println("usage: <problem class name> <input files...> [ -v ]");
		System.out.println("example: Welcome_To_Code_Jam -v sample.in");
	}
	
	public static void main(String[] args) {
		if (args.length < 1) {
			printHelp();
			return;
		}
		
		// Parse arguments
		String aProblemClassName = null;
		Vector<String> aInputFileNameVector = new Vector<String>(3);
		boolean aIsVerbose = false;
		for (String aArg : args) {
			if (aArg.startsWith("--") || aArg.equalsIgnoreCase("-h") || aArg.equalsIgnoreCase("/H") || aArg.equalsIgnoreCase("?H")) {
				printHelp();
				return;
			} else if (aArg.startsWith("-")) {
				if (aArg.equals("-v")) {
					aIsVerbose = true;
				}
			} else {
				if (aProblemClassName == null) {
					aProblemClassName = aArg;
				} else {
					aInputFileNameVector.add(aArg);
				}
			}
		}
		
		// Input validation
		if (aProblemClassName == null) {
			System.err.println("Error: No problem class name");
			printHelp();
			return;
		}
		if (aInputFileNameVector.isEmpty()) {
			System.err.println("Error: No input files");
			printHelp();
			return;
		}
		
		// Instantiate the problem
		try {
			Class<?> aClass = Class.forName(aProblemClassName);
			Class<? extends AbstractCodejamProblem> aAbstractProblemClass = aClass.asSubclass(AbstractCodejamProblem.class);
			Constructor<? extends AbstractCodejamProblem> aAbstractProblemConstructor = null;
			AbstractCodejamProblem aAbstractProblem = null;
			try {
				Class<?>[] aEmptyClassList = {};
				Object[] aEmptyObjectList = {};
				aAbstractProblemConstructor = aAbstractProblemClass.getConstructor(aEmptyClassList);
				aAbstractProblem = aAbstractProblemConstructor.newInstance(aEmptyObjectList);
			} catch (NoSuchMethodException e) {
				System.out.println("Error: No appropriate constructor in class " + aProblemClassName);
				return;
			}
			aAbstractProblem.setVerbose(aIsVerbose);
			
			// Loop over the input files
			for (String aInputFileName : aInputFileNameVector) {
				aAbstractProblem.executeProblem(aInputFileName);
			}
			
			System.err.println("Total executed in " + aAbstractProblem._totalExecNanoTime / 1000000L + " ms");
			System.err.println("Total executed in " + aAbstractProblem._totalExecNanoTime / 1000000000L + " s");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (InstantiationException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		} catch (SecurityException e) {
			e.printStackTrace();
		} catch (IllegalArgumentException e) {
			e.printStackTrace();
		} catch (InvocationTargetException e) {
			e.printStackTrace();
		}
	}
	
	private long _totalExecNanoTime = 0;
		
	private final void executeProblem(String iInputFileName) {
		// Prepare input and output
		FileReader aFileReader = null;
		FileWriter aFileWriter = null;
		try {
			System.err.println("Loading: " + iInputFileName);
			aFileReader = new java.io.FileReader(iInputFileName);
			setInput(aFileReader);
			aFileWriter = new java.io.FileWriter(iInputFileName + ".out");
			setOutput(aFileWriter);
			
			// Run the loop
			long aNanoStart = System.nanoTime();
			setCaseNo(-1);
			setCaseNoExpected(-1);
			executeInput();
			long aNanoStop = System.nanoTime();
			
			System.err.println("Executed in " + (aNanoStop - aNanoStart) / 1000L + " us");
			System.err.println("Executed in " + (aNanoStop - aNanoStart) / 1000000L + " ms");
			_totalExecNanoTime += (aNanoStop - aNanoStart);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		// Close files
		try {
			if (aFileWriter != null) aFileWriter.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		try {
			if (aFileReader != null) aFileReader.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		// Perform a few checks
		compareExpected(iInputFileName);
	}
	
	private final void compareExpected(String iInputFileName) {
		if (getCaseNo() != getCaseNoExpected()) {
			System.err.println("Warning: Unexpected number of cases: " + getCaseNo() + '/' + getCaseNoExpected());
		}
		
		// Open files
		FileReader aOutputFileReader = null;
		FileReader aExpectedFileReader = null;
		try {
			aOutputFileReader = new java.io.FileReader(iInputFileName + ".out");
		} catch (IOException e) {
			System.err.println("Error: No output file " + iInputFileName + ".out");
		}
		try {
			aExpectedFileReader = new java.io.FileReader(iInputFileName + ".expected");
		} catch (IOException e) {
			System.err.println("Warning: No expected output file " + iInputFileName + ".expected");
		}
		
		// Compare
		if (aOutputFileReader != null && aExpectedFileReader != null) {
			LineNumberReader aOutputLineReader = new LineNumberReader(aOutputFileReader);
			LineNumberReader aExpectedLineReader = new LineNumberReader(aExpectedFileReader);
			String aOutputLine = null;
			String aExpectedLine = null;
			try {
				do {
					aOutputLine = aOutputLineReader.readLine();
					aExpectedLine = aExpectedLineReader.readLine();
					if (aOutputLine == null && aExpectedLine != null ||
							aOutputLine != null && aExpectedLine == null ||
							aOutputLine != null && aExpectedLine != null && aOutputLine.compareTo(aExpectedLine) != 0) {
						System.err.println("Error: " + iInputFileName + ".out is not as " + iInputFileName + ".expected at line " + aOutputLineReader.getLineNumber());
						System.err.println("Expected: " + aExpectedLine);
						System.err.println("Output:   " + aOutputLine);
						break;
					}
				} while(aOutputLine != null && aExpectedLine != null);
				if (aOutputLine == null && aExpectedLine == null) {
					System.err.println("Ok: " + iInputFileName + ".out matches as " + iInputFileName + ".expected");
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		// Close files
		try {
			if (aOutputFileReader != null) aOutputFileReader.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		try {
			if (aExpectedFileReader != null) aExpectedFileReader.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
