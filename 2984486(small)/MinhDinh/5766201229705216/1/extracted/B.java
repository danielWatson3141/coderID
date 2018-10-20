package b;
import java.util.*;import java.text.*;import java.math.*;import java.util.regex.*;import java.awt.geom.*;import java.io.*;import static java.lang.Math.*;import static java.lang.Character.*;import static java.lang.Integer.*;import static java.lang.Double.*;import static java.lang.Long.*;import static java.lang.System.*;import static java.util.Arrays.*; 

class Solver {
	public static final String FILE_NAME = "b"; 
//	public static final String FILE_NAME = "B-small-attempt0"; 
//	public static final String FILE_NAME = "B-large"; 
	
	public static final String FOLDER_NAME = "/Users/minh/Documents/workspace/GoogleCodeJam/src/b/";
	public static final String INPUT_FILE_NAME = FOLDER_NAME + FILE_NAME + ".in";
	public static final String OUTPUT_FILE_NAME = FOLDER_NAME + FILE_NAME + ".out";
	
	final int INF = Integer.MAX_VALUE/10;

	int m,n;
	int[][] a;
	
	public void input() throws Exception{
		n = new Integer (in.readLine());
		a = new int[n][n];
		for (int i = 0; i < n-1; i++) {
			String s = in.readLine();
			String[] ss = s.split("[ ]+");
			int u = new Integer (ss[0])-1;
			int v = new Integer (ss[1])-1;
			a[u][v] = 1;
			a[v][u] = 1;
		}
	}
	
	private String outputString () {
		return "Case #"+(B.CURRENT_TEST+1)+": ";
	}
	public void output() throws IOException {
		ret = n-ret;
		out.write(outputString() + ret);
		out.newLine();
		System.out.println(outputString() + ret);
	}
	
	int ret = Integer.MIN_VALUE;
	boolean [] seen;
	public void process() throws Exception{
		for (int i = 0; i < n; i++) {
			seen = new boolean[n];
			int temp = dfsMax (i);
			ret = max (ret, temp);
		}
	}

	void debug(Object...os) { 
		System.err.println(Arrays.deepToString(os));
	} 

	private int dfsMax (int u) {
		seen[u] = true;
		int childrenCount = 0;
		int[] children = new int[n];
		
		for (int i = 0; i < n; i++) if (!seen[i] && a[u][i]==1) children [ childrenCount++ ] = i;
		
		// 0 child
		int res = 1;
		
		// 2 children
		if (childrenCount>=2) {
			int[] maxx = new int[childrenCount];
			for (int i = 0; i < childrenCount; i++) {
				int v = children[i];
				seen[v] = true;
				maxx [i] = dfsMax (v);
			}
			sort (maxx);
			res += maxx[maxx.length-1] + maxx[maxx.length-2];
		}
		
		
		return res;
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
public class B {
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

