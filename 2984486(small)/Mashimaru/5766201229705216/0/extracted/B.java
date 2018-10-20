import java.util.*;
import java.io.*;

public class B {
	public int n;
	public int[] LE, c, d;
	public boolean[] free;
	public List <Edge> E;
	
	public class Edge {
		public int to, nextID;
		
		public Edge(int to, int nextID) {
			this.to = to;
			this.nextID = nextID;
		}
	}
	
	public class Pair implements Comparable <Pair> {
		public int first, second;
		
		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
		
		public int compareTo(Pair other) {
			if (first != other.first) {
				return first - other.first;
			}
			return second - other.second;
		}
		
		public String toString() {
			return "(" + first + ", " + (second+1) + ")";
		}
	}
	
	public void addEdge(int u, int v) {
		E.add(new Edge(v, LE[u]));
		LE[u] = E.size() - 1;
	}
	
	public void dfs(int u) {
		free[u] = false;
		c[u] = 1;
		List <Pair> children = new ArrayList <Pair> ();
		for (int ID = LE[u]; ID != -1; ID = E.get(ID).nextID) {
			int v = E.get(ID).to;
			if (free[v]) {
				dfs(v);
				c[u] += c[v];
				children.add(new Pair(c[v] - d[v], v));
			}
		}
		if (children.size() == 0) {
			d[u] = 0;
		} else if (children.size() == 1) {
			d[u] = c[children.get(0).second];
		} else {
			for (Pair pair : children) {
				d[u] += d[pair.second];
			}
			if (children.size() > 2) {
				Collections.sort(children);
				for (int i = 0; i < children.size() - 2; i++) {
					d[u] += children.get(i).first;
				}
			}
		}
//		System.out.println((u+1) + " ---> " + children + " " + c[u] + " " + d[u]);
	}
	
	public void run() {
		InputReader reader = new InputReader(System.in);
		PrintWriter writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		
		int numTests = reader.nextInt();
		for (int numCases = 1; numCases <= numTests; numCases++) {
			n = reader.nextInt();
			LE = new int[n];
			Arrays.fill(LE, -1);
			free = new boolean[n];
			c = new int[n];
			d = new int[n];
			E = new ArrayList <Edge> ();
			
			for (int i = 1; i < n; i++) {
				int u = reader.nextInt() - 1;
				int v = reader.nextInt() - 1;
				addEdge(u, v);
				addEdge(v, u);
			}
			
//			Arrays.fill(free, true);
//			dfs(7);
//			for (int i = 0; i < n; i++) {
//				System.out.println((i+1) + " " + c[i] + " " + d[i]);
//			}
//			System.out.println(d[7]);
			
			int ans = Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				Arrays.fill(free, true);
				Arrays.fill(c, 0);
				Arrays.fill(d, 0);
				dfs(i);
				if (ans > d[i]) {
					ans = d[i];
				}
			}
			
			writer.format(Locale.US, "Case #%d: %d\n", numCases, ans);
		}
		
		writer.close();
	}
	
	public static void main(String[] args) {
		new B().run();
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
