import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;


public class Q2 {
	
	static final String INPUT_PATH = "in.in";
	static final String OUTPUT_PATH = "out.out";
	static final String REF_PATH = "ref.out";
	static final boolean PRINT_OUTPUT_TO_CONSOLE = true;
	static final boolean COMPARE_WITH_REF = false;
	static final boolean INIT_INTERNALLY = false;

	// input data
	static int T;
	static int N;
	static int[]perm;
	
	static String res;
	
	// output data
	
	static void init() {
		/***** use only if INIT_INTERNALLY = true ****/

		/********************************************/
	}
	
	static void solveTest() {
		/***** customize this part *****/
		if(perm[0] <= 499) res = "BAD";
		else res = "GOOD";
		/******************************/
	}
	
	static void resetOutputData() {
		/***** customize this part *****/
		
		/******************************/
	}
	static int inputToData(String[] input, int line) {
		/***** customize this part *****/
		N = Integer.parseInt(input[line++]);
		String [] str = input[line++].split(" ");
		perm = new int[N];
		for(int j = 0; j < N; j++) {
			perm[j] = Integer.parseInt(str[j]);
		}
		
		/******************************/
		return line;
	}
	static ArrayList<String> dataToOutput(int test) {
		ArrayList<String> out = new ArrayList<>();
		/***** customize this part *****/
		String line = "Case #" + test +": ";
		line += res;
		out.add(line);
		/******************************/
		return out;
	}
	
	
	/** NO need to customize **/
	public static void main(String [] args) {
		if(!INIT_INTERNALLY) solve();
		else {
			init();
			resetOutputData();
			solveTest();
			printOutput(dataToOutput(0));
		}
		if(COMPARE_WITH_REF) checkOutput();
	}
	static void solve() {
		PrintWriter writer = null;
		try {
			writer = new PrintWriter(OUTPUT_PATH, "UTF-8");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		}

		String [] input = getLines(INPUT_PATH);
		int line = 0;
		T = Integer.parseInt(input[line++]);
		for(int test = 1; test <= T; test++) {
			line = inputToData(input, line);
			resetOutputData();
			solveTest();
			ArrayList<String> testResult = dataToOutput(test);
			printOutput(writer, testResult, test == T);
		}
		writer.close();
	}
	static void printOutput(ArrayList<String> testResult) {
		printOutput(null, testResult, false);
	}
	static void printOutput(PrintWriter writer, ArrayList<String> testResult, boolean isLast) {
		for(int i = 0; i < testResult.size(); i++) {
			String line = testResult.get(i);
			if(writer != null) writer.print(line + (!(isLast && (i == testResult.size() - 1)) ? "\n" : ""));
			if(PRINT_OUTPUT_TO_CONSOLE || writer == null) System.out.println(line);
		}
	}
	static String [] getLines(String path) {
		String[] lines = null;
		try {
			List<String> list = Files.readAllLines(Paths.get(path), Charset.defaultCharset());
			lines = list.toArray(new String[list.size()]);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return lines;
	}
	static void checkOutput() {
		checkMatch(getLines(OUTPUT_PATH), getLines(REF_PATH));
	}
	static void checkMatch(String [] output, String [] ref) {
		if(output.length != ref.length) {
			throw new RuntimeException("WRONG OUTPUT: Unequal number of lines");
		}
		for(int i = 0; i < output.length; i++) {
			if(!output[i].equalsIgnoreCase(ref[i])) {
				throw new RuntimeException("WRONG OUTPUT:\nOn Line "+i+":\nout:"+output[i]+"\nref:"+ref[i]+"\n");
			}
		}
		System.out.println("Everything is OK.");
	}
	
	
}
