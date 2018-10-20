import java.io.*;
import java.util.*;


/**
 * Template
 * @author Albert Choi
 */
public class A {
	static BufferedReader _reader = new BufferedReader(new InputStreamReader(System.in));
	static String _s;
	static StringTokenizer _st;
	static String nline() throws IOException { _s = _reader.readLine(); _st = new StringTokenizer(_s); return _s; }
	static int nint() throws IOException { return Integer.parseInt(_st.nextToken()); }
	static long nlong() throws IOException { return Long.parseLong(_st.nextToken()); }
	static String nword() throws IOException { return _st.nextToken(); }
	static double ndouble() throws IOException { return Double.parseDouble(_st.nextToken()); }
	static PrintStream sout = System.out, serr = System.err;
	
	public static void main(String[] args) throws IOException {
		nline();
		int T = nint();
		
		for (int t=1; t<=T; t++) {
			String sans = doProblem();
			sout.println("Case #" + t + ": " + sans);
		}
	}
	
	static String doProblem() throws IOException {
		nline();
		int N = nint(), L = nint();
		nline();
//		Set<String> outlets = new HashSet<>();
		Set<Long> outs = new HashSet<>();
		for (int i=0; i<N; i++) {
			String outi = nword();
//			outlets.add(outi);
			outs.add(Long.valueOf(outi, 2));
			//boolean[] outlets = new boolean[L];
		}
		nline();
		//Set<String> devices = new HashSet<>();
		Set<Long> devs = new HashSet<>();
		for (int i=0; i<N; i++) {
			String devi = nword();
//			devices.add(devi);
			devs.add(Long.valueOf(devi, 2));
			//boolean[] devices = new boolean[L];
		}
		
		Queue<List<Integer>> tries = new LinkedList<>();
		tries.add(new ArrayList<Integer>());
		
		int ans = bfs(outs, devs, tries, L);
		
		return ans == -1 ? "NOT POSSIBLE" : ""+ans;
	}
	
	static boolean check(Set<Long> switches, Set<Long> devs) {
		if (switches.equals(devs)) return true;
		return false;
	}
	
	static Set<Long> flip(Set<Long> outs, List<Integer> indexes) {
		Set<Long> result = new HashSet<>();
		for (long l : outs) {
			for (int i : indexes) {
				l = l ^ (1 << i);
			}
			result.add(l);
		}
		return result;
	}
	
	static int bfs(Set<Long> outlets, Set<Long> devs, Queue<List<Integer>> tests, int L) {
		while (!tests.isEmpty()) {
			List<Integer> indexes = tests.remove();
			Set<Long> outs2 = flip(outlets, indexes);
			if (outs2.equals(devs)) return indexes.size();
			
			int nextIdx = 0;
			if (!indexes.isEmpty()) nextIdx = indexes.get(indexes.size() - 1) + 1;

			for (int i = nextIdx; i < L; i++) {
				List<Integer> test2 = new ArrayList<Integer>(indexes);
				test2.add(i);
				tests.add(test2);
			}
		}

		return -1;
	}

}
