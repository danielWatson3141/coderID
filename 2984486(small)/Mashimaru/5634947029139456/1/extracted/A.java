import java.util.*;
import java.io.*;

public class A {
	public int n, L, flow;
	public int[] pre;
	public int[][] cap;
	public char[][] a, b;
	
	public boolean findPath() {
		pre = new int[2 * n + 2];
		Arrays.fill(pre, -1);
		pre[0] = 0;
		Queue <Integer> queue = new LinkedList <Integer> ();
		queue.add(0);
		while (!queue.isEmpty()) {
			int u = queue.remove();
			for (int v = 0; v < 2 * n + 2; v++) {
				if (pre[v] == -1 && cap[u][v] > 0) {
					pre[v] = u;
					if (v == 2 * n + 1) {
						return true;
					}
					queue.add(v);
				}
			}
		}
		return false;
	}
	
	public void augment() {
		flow++;
		for (int v = 2 * n + 1; v != 0; ) {
			int u = pre[v];
			cap[u][v]--;
			cap[v][u]++;
			v = u;
		}
	}
		
	
	public int matchFirstWith(int pos) {
		int numSwitches = 0;
		char[][] tempB = new char[n][L];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < L; j++) {
				tempB[i][j] = b[i][j];
			}
		}
		for (int j = 0; j < L; j++) {
			if (a[0][j] != tempB[pos][j]) {
				numSwitches++;
				for (int i = 0; i < n; i++) {
					if (tempB[i][j] == '0') {
						tempB[i][j] = '1';
					} else {
						tempB[i][j] = '0';
					}
				}
			}
		}
		flow = 0;
		for (int i = 0; i < cap.length; i++) {
			Arrays.fill(cap[i], 0);
		}
		for (int i = 1; i <= n; i++) {
			cap[0][i] = cap[n + i][2 * n + 1] = 1;
			for (int j = 1; j <= n; j++) {
				boolean ok = true;
				for (int k = 0; k < L; k++) {
					if (a[i - 1][k] != tempB[j - 1][k]) {
						ok = false;
						break;
					}
				}
				if (ok) {
					cap[i][n + j] = 1;
				} else {
					cap[i][n + j] = 0;
				}
			}
		}
		
		flow = 0;
		while (findPath()) {
			augment();
		}
		if (flow == n) {
			return numSwitches;
		}
		return Integer.MAX_VALUE;
	}
	
	public void run() {
		InputReader reader = new InputReader(System.in);
		PrintWriter writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		
		int numTests = reader.nextInt();
		for (int numCases = 1; numCases <= numTests; numCases++) {
			n = reader.nextInt();
			L = reader.nextInt();
			a = new char[n][];
			b = new char[n][];
			cap = new int[2 * n + 2][2 * n + 2];
			for (int i = 0; i < n; i++) {
				a[i] = reader.next().toCharArray();
			}
			for (int i = 0; i < n; i++) {
				b[i] = reader.next().toCharArray();
			}
			
			int ans = Integer.MAX_VALUE;
			for (int j = 0; j < n; j++) {
				int temp = matchFirstWith(j);
				if (ans > temp) {
					ans = temp;
				}
			}
			if (ans < Integer.MAX_VALUE) {
				writer.format(Locale.US, "Case #%d: %d\n", numCases, ans);
			} else {
				writer.format(Locale.US, "Case #%d: NOT POSSIBLE\n", numCases);
			}
		}
		
		writer.close();
	}
	
	public static void main(String[] args) {
		new A().run();
	}
	
	public class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;
		
		public InputReader(String fileName) {
			try {
				reader = new BufferedReader(new FileReader(fileName));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			tokenizer = null;
		}
		
		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}
			
		public boolean hasNext() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					String nextLine = reader.readLine();
					if (nextLine == null) {
						return false;
					} else {
						tokenizer = new StringTokenizer(nextLine);
					}
				} catch (IOException e) {
					return false;
				}
			}
			return true;
		}
		
		public String next() {
			hasNext();
			return tokenizer.nextToken();
		}
		
		public String nextLine() {
			hasNext();
			return tokenizer.nextToken("\n\r");
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}
