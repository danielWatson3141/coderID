package a;

import java.util.*;import java.text.*;import java.math.*;import java.util.regex.*;import java.awt.geom.*;import java.io.*;
import static java.lang.Math.*;import static java.lang.Character.*;import static java.lang.Integer.*;import static java.lang.Double.*;import static java.lang.Long.*;import static java.lang.System.*;import static java.util.Arrays.*; 
class Solver {
	public static final String FILE_NAME = "A"; 
//	public static final String FILE_NAME = "A-small-attempt0"; 
//	public static final String FILE_NAME = "A-large"; 
	
	public static final String FOLDER_NAME = "/Users/minh/Documents/workspace/GoogleCodeJam/src/a/";
	public static final String INPUT_FILE_NAME = FOLDER_NAME + FILE_NAME + ".in";
	public static final String OUTPUT_FILE_NAME = FOLDER_NAME + FILE_NAME + ".out";
	
	final int INF = Integer.MAX_VALUE/10;
	int m;
	int n,l;

	int[][] a, c;
	String[] b;
	
	public void input() throws Exception{
//		m = new Integer (in.readLine());
		String s = in.readLine();
		String[] ss = s.trim().split("[ ]+");
		n = new Integer (ss[0]);
		l = new Integer (ss[1]);
		String s1 = in.readLine();
		String s2 = in.readLine();
		String[] ss1 = s1.trim().split("[ ]+");
		b = s2.trim().split("[ ]+");
		a = new int[n][l];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < l; j++) {
				a[i][j] = ss1[i].charAt(j) =='0' ? 0 : 1;
			}
		}
	}
	void debug(Object...os) { 
		System.err.println(Arrays.deepToString(os));
	} 
	private String outputString () {
		return "Case #"+(A.CURRENT_TEST+1)+": ";
	}
	public void output() throws IOException {
		String res = ret+"";
		if (ret==Integer.MAX_VALUE/2) res = NOTPOSSIBLE; 
		
		out.write(outputString() + res);
		out.newLine();
		
		System.out.println(outputString() + res);
	}
	
	String NOTPOSSIBLE = "NOT POSSIBLE";
	int ret = Integer.MAX_VALUE/2;
	int temp = 0;

	public void process() throws Exception{
		sort(b);
		for (int bitmask = 0; bitmask < (1<<l); bitmask++) if (bitCount(bitmask)<ret){
			c = new int[n][l];
			for (int i = 0; i < n; i++) for (int j = 0; j < l; j++) c[i][j] = a[i][j];
			for (int i = 0; i < l; i++) if (CHECK(bitmask,i)){
				for (int j = 0; j < n; j++) c[j][i] ^= 1;
			}
			String[]bb = new String[n];
			for (int i = 0; i < n; i++) {
				bb[i] = "";
				for (int j = 0; j < l; j++) bb[i] += c[i][j];
			}
			sort (bb);
			boolean ok = true;
			for (int i = 0; i < n; i++) if (!bb[i].equals(b[i])){
				ok = false;
				break;
			}
//			debug (bitmask+ " " + ok);
			if (ok) {
				ret = bitCount (bitmask);
			}
		}
	}


	BufferedReader in;
	BufferedWriter out;
	
	public Solver(BufferedReader in, BufferedWriter out ){
		this.in = in;
		this.out = out;
	}
	
	int[] parseArrInt (String s) {
		s = s.trim();
		ArrayList<Integer> list = new ArrayList<Integer> ();
		String[] ss = s.split("[ ]+");
		for(String x:ss) list.add(new Integer(x));
		int[] ret = new int[list.size()];
		for (int i = 0; i < ret.length; i++) {
			ret[i] = list.get(i);
		}
		return ret;
	}
	
	// Bit Operators
	int SET(int mask, int u) { return mask | (1 << u);}
	boolean CHECK(int mask, int u) {return (mask & (1 << u)) != 0;}
	int FLIP(int mask, int u) {return mask ^ (1 << u);}
	int CLEAR(int mask, int u) {if (CHECK(mask, u)) return FLIP(mask, u);return mask;}
	long SET(long mask, long u) { return mask | (1L << u);}
	boolean CHECK(long mask, long u) {return (mask & (1L << u)) != 0;}
	long FLIP(long mask, long u) {return mask ^ (1L << u);}
	long CLEAR(long mask, long u) {if (CHECK(mask, u)) return FLIP(mask, u);return mask;}
}

/**
 * @author minh
 *
 */
public class A {
	static BufferedReader in;
	static BufferedWriter out;
	static int NUMBER_OF_TEST, CURRENT_TEST;
	
	public static void main(String[] args) throws java.lang.Exception {
		in =  new BufferedReader(new FileReader(new File (Solver.INPUT_FILE_NAME)));
		out = new BufferedWriter(new FileWriter(new File (Solver.OUTPUT_FILE_NAME)));
		
//		int[] temp = solver.parseArrInt(in.readLine());
//		// code here
//		NUMBER_OF_TEST = temp[0];
//		Solver solver = new Solver(in, out);
//		solver.input();
//		for(CURRENT_TEST = 0;CURRENT_TEST<NUMBER_OF_TEST;CURRENT_TEST++) {
//			solver.process();
//			solver.output();
//		}
//		
		
		NUMBER_OF_TEST = new Integer(in.readLine());
		for(CURRENT_TEST = 0;CURRENT_TEST<NUMBER_OF_TEST;CURRENT_TEST++) {
			Solver solver = new Solver(in, out);
			solver.input();
			solver.process();
			solver.output();
		}
		
		in.close();
		out.close();
	}
}

