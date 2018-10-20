import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;


public class Q1 {
	
	static final String INPUT_PATH = "in.in";
	static final String OUTPUT_PATH = "out.out";
	static final String REF_PATH = "ref.out";
	static final boolean PRINT_OUTPUT_TO_CONSOLE = true;
	static final boolean COMPARE_WITH_REF = false;
	static final boolean INIT_INTERNALLY = false;

	// input data
	static int T;
	static int N, L;
	static String[] outlets;
	static String[] devices;
	static byte [][] outl;
	static byte [][] dev;
	static BigInteger [] o;
	static BigInteger [] d;
	
	// output data
	static int resL;
	static boolean impos;
	
	static void init() {
		/***** use only if INIT_INTERNALLY = true ****/
		N = 3; L = 2;
		outlets = new String [] { "01", "11", "10" };
		devices = new String [] { "11", "00", "10" };
		/********************************************/
	}
	static HashSet<String> set;
	static boolean canFlipToSol(int l, HashSet<Integer> flips) {

		Integer [] idx = new Integer[flips.size()];
		flips.toArray(idx);
		Arrays.sort(idx);
		String key = Arrays.deepToString(idx);
		if(set.contains(key))
			return false;
		
		if(flips.size() == l) {
			BigInteger [] oo = new BigInteger[N];
			for(int i = 0; i < N; i++) {
				oo[i] = o[i];
			}
			//System.out.println("bef:"+Arrays.deepToString(oo) + " -- " + Arrays.deepToString(d));
			for(int i = 0; i < N; i++) {
				for(int f = 0; f < L; f++) {
					if(flips.contains(f))
						oo[i] = oo[i].flipBit(f);
				}
			}
			Arrays.sort(oo);
			//System.out.println(Arrays.deepToString(oo) + " -- " + Arrays.deepToString(d) + " flips: "+flips.toString());
			for(int h = 0; h < N; h++) {
				if(!oo[h].equals(d[h])) {
					//System.out.println(oo[h] + "!=" + d[h]);
					return false;
				}
			}

		return true;
		}
		
		for(int u = 0; u < L; u++) {
			if(!flips.contains(u)) {
				//System.out.println("flips: "+flips + "u="+u);
				flips.add(u);
				boolean res = canFlipToSol(l, flips);
				if(res) return true;
				Integer [] idx2 = new Integer[flips.size()];
				flips.toArray(idx2);
				Arrays.sort(idx2);
				String key2 = Arrays.deepToString(idx2);
				set.add(key2);
				flips.remove(u);
			}
		}
		return false;
	}
	static void solveTest() {
		/***** customize this part *****/
		outl = new byte[outlets.length][];
		dev = new byte[outlets.length][];
		o = new BigInteger[outlets.length];
		d = new BigInteger[outlets.length];
		int i = 0;
		for(String s : outlets) {
			//outl[i] = new BigInteger(s, 2).toByteArray();
			//dev[i] = new BigInteger(devices[i], 2).toByteArray();
			o[i] = new BigInteger(s, 2);
			d[i] = new BigInteger(devices[i], 2);
			i++;
		}
		Arrays.sort(d);
		
		boolean res = false;
		set = new HashSet<>();
		for (int l = 0; l <= L; l++) {
			//System.out.println("l="+l);
			set.clear();
			res = Q1.canFlipToSol(l, new HashSet());
			if(res) {
				resL = l;
				break;
			}
		}
		
		if(!res) {
			impos = true;
		}
		/******************************/
	}
	
	static void resetOutputData() {
		/***** customize this part *****/
		impos = false;
		resL = -1;
		/******************************/
	}
	static int inputToData(String[] input, int line) {
		/***** customize this part *****/
		String [] str = input[line++].split(" ");
		N = Integer.parseInt(str[0]);
		L = Integer.parseInt(str[1]);
		outlets = input[line++].split(" ");
		devices = input[line++].split(" ");
		
		/******************************/
		return line;
	}
	static ArrayList<String> dataToOutput(int test) {
		ArrayList<String> out = new ArrayList<>();
		/***** customize this part *****/
		String line = "Case #" + test +": ";
		line += (impos ? "NOT POSSIBLE" : resL);
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
