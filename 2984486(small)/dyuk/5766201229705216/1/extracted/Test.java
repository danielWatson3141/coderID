import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Test {
	public static void main(String[] args) {
		try {
			InputStream inputStream = new FileInputStream(
					"D:\\codeforse\\CF\\input.txt");
			OutputStream outputStream = new FileOutputStream(
					"D:\\codeforse\\CF\\output.txt");
			// InputStream inputStream = System.in;
			// OutputStream outputStream = System.out;
			InputReader in = new InputReader(inputStream);
			PrintWriter out = new PrintWriter(outputStream);
			C solver = new C();
			int t = in.nextInt();
			for (int i = 1; i <= t; i++) {
				solver.solve(i, in, out);
			}
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

class C {

	public void solve(int testNumber, InputReader in, PrintWriter out) {
		out.print("Case #" + testNumber + ": ");

		int n = in.nextInt();

		Pair[] p = new Pair[n];
		for (int i = 0; i < n; i++) {
			p[i] = new Pair(i);
		}
		int a = 0;
		int b = 0;
		for (int i = 0; i < n-1; i++) {
			a = in.nextInt() - 1;
			b = in.nextInt() - 1;

			p[a].add(p[b]);
			p[b].add(p[a]);
		}
		int max = 0;
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			tmp = p[i].get(-1);
			//System.out.println(tmp);
			max = Math.max(max, tmp);
		}
		out.print(n-max);
		// out.print(Long.toString(n,2));
		// out.print(Long.toString(n^0,2));

		// out.print(Integer.parseInt("11111111111111111111", 2));
		// out.print(Long.parseLong("1111111111111111111111111111111111111111",
		// 2));

		out.println();

	}

	class Pair implements Comparable<Pair> {
		// ArrayList<Pair> p = new ArrayList<Pair>();
		// Collections.sort(p, Comparators.AGE);
		int r;
		
		ArrayList<Pair> pp;
		int me;

		public Pair(int a) {
			me = a;
			pp = new ArrayList<Pair>();
		}

		public void add(Pair p) {
			pp.add(p);
		}

		public int get(int from) {
			int sum = 0;
			ArrayList<Integer> ans = new ArrayList<Integer>();
			for (Pair p : pp) {
				if (p.me != from || from == -1) {
					// sum += p.get(false);
					int t = p.get(this.me);
					if (t > 0) {
						ans.add(t);
					}
				}
			}
			int l = ans.size();
			if (l == 0) {
				return 1;
			} else if (l == 1) {
				return 1;
			} else{
				Collections.sort(ans);
				//System.out.println(l);
				for (int i = l-1; i >=l-2; i--){
					//System.out.println(i);
					sum+=ans.get(i);
				}
				return sum+1;
			}
		}

		@Override
		public int compareTo(Pair o) {
			return Comparators.AGE.compare(this, o);
		}

		public String toString() {
			return "" + r + " ";
		}

	}

	public static class Comparators {

		public static Comparator<Pair> AGE = new Comparator<Pair>() {
			@Override
			public int compare(Pair o1, Pair o2) {
				return o1.r > o2.r ? 1 : (o1.r < o2.r ? -1 : 0);
			}
		};
	}
}

class InputReader {

	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public Double nextDouble() {
		return Double.parseDouble(next());
	}

	public String nextString() {
		return next();
	}

}
