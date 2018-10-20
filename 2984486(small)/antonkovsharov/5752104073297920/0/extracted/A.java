import java.util.*;
import java.io.*;

public class A {
	FastScanner in;
	PrintWriter out;

	class Test implements Comparable<Test>{
		int num;
		double result;
		
		public Test(int num, double result) {
			this.num = num;
			this.result = result;
		}

		@Override
		public int compareTo(Test o) {
			return Double.compare(result, o.result);
		}
	}
	
	ArrayList<Test> ans;
	
	public void solve(int tests) throws IOException {
		ans = new ArrayList<>();
		for (int t = 0; t < tests; t++) {
			int n = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}
			double count = 0;
			for (int i = 0; i < n; i++) {
				double hi = i - 1, lo = Math.max(0, Math.min(n / 4, i - 4));
				if (a[i] <= hi && a[i] >= lo)
					count += (a[i] - lo) / (hi - lo);
			}
			ans.add(new Test(t, count));
		}
		Collections.sort(ans);
	}

	public void run() {
		try {
			in = new FastScanner(new File("task.in"));
			out = new PrintWriter(new File("task.out"));

			int tests = in.nextInt();
			solve(tests);
			
			TEST:
			for (int i = 0; i < tests; ++i) {
				out.print("Case #" + (i + 1) + ": ");
				for (int j = 0; j < ans.size(); j++)
					if (ans.get(j).num == i) {
						out.println((j < ans.size() / 2 ? "BAD" : "GOOD")/* + " " + ans.get(j).result*/);
						continue TEST;
					}
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] arg) {
		new A().run();
	}
}