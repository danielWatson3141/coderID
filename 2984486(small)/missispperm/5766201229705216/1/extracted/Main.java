import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.Map.Entry;

public class Main {
	public static void main(String[] args) throws IOException {
		(new Main()).solve();
	}

	public Main() {
	}
	
	//MyReader in = new MyReader();
	//PrintWriter out = new PrintWriter(System.out);
	
	void solve() throws IOException {
		//BufferedReader in = new BufferedReader(new
		//InputStreamReader(System.in));
		//Scanner in = new Scanner(System.in);
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new FileReader("input.txt"));
		PrintWriter out = new PrintWriter("output.txt");
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			int n = in.nextInt();
			Unit[] v = new Unit[n];
			for (int j = 0; j < n - 1; j++) {
				int x = in.nextInt() - 1;
				int y = in.nextInt() - 1;
				if (v[x] == null) {
					v[x] = new Unit();
				}
				v[x].a.add(y);
				if (v[y] == null) {
					v[y] = new Unit();
				}
				v[y].a.add(x);
			}
			int best = Integer.MAX_VALUE;
			for (int j = 0; j < n; j++) {
				Vertex res = count(v, j, -1);
				int cur = res.del;
				if (cur < best) {
					best = cur;
				}
			}
			out.println("Case #" + (i + 1) + ": " + best);
		}
		out.close();
	}
	
	Vertex count(Unit[] v, int x, int prev) {
		List<Integer> childs = v[x].a;
		List<Integer> childRes = new ArrayList<Integer>();
		List<Integer> childCount = new ArrayList<Integer>();
		int sum = 0;
		for (Integer child : childs) {
			if (child != prev) {
				Vertex ver = count(v, child, x);
				childRes.add(ver.del);
				childCount.add(ver.all);
				sum += ver.all;
			}
		}
		if (childRes.size() < 2) {
			return new Vertex(sum + 1, sum);
		} else {
			int best = Integer.MAX_VALUE;
			for (int i = 0; i < childRes.size(); i++) {
				for (int j = i + 1; j < childRes.size(); j++) {
					int cur = sum - childCount.get(i) - childCount.get(j) + childRes.get(i) + childRes.get(j);
					if (cur < best) {
						best = cur;
					}
				}
			}
			return new Vertex(sum + 1, best);
		}
	}
	
	class Unit {
		 public List<Integer> a = new ArrayList<Integer>();
	}
	
	class Vertex {
		public int all;
		public int del;
		public Vertex(int all, int del) {
			super();
			this.all = all;
			this.del = del;
		}
	}

	class MyReader {
		private BufferedReader in;
		String[] parsed;
		int index = 0;

		public MyReader() {
			in = new BufferedReader(new InputStreamReader(System.in));
		}

		public int nextInt() throws NumberFormatException, IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return Integer.parseInt(parsed[index++]);
		}

		public long nextLong() throws NumberFormatException, IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return Long.parseLong(parsed[index++]);
		}
		
		public double nextDouble() throws NumberFormatException, IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return Double.parseDouble(parsed[index++]);
		}
		
		public String nextString() throws IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return parsed[index++];
		}

		private void read() throws IOException {
			parsed = in.readLine().split(" ");
			index = 0;
		}

		public String readLine() throws IOException {
			return in.readLine();
		}
		
		public int read(char[] cbuf) throws IOException {
			return in.read(cbuf);
		}
	}

};