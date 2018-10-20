package round1A_2014;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class A {
	InputReader in;

	public char swap(char c) {
		return (c == '0') ? '1' : '0';
	}

	public String solve() throws Exception {

		int N = in.nextInt();
		int L = in.nextInt();

		char[][] cur = new char[N][L];
		for (int i = 0; i < N; i++) {
			cur[i] = in.next().toCharArray();
		}
		Set<String> target = new HashSet<String>();
		for (int i = 0; i < N; i++) {
			target.add(in.next());
		}

		int ans = 1 << 25;
		for (int mask = 0; mask < (1 << L); mask++) {

			int cnt = 0;

			for (int col = 0; col < L; col++) {
				if ((mask & (1 << col)) != 0) {
					cnt++;
					for (int i = 0; i < N; i++)
						cur[i][col] = swap(cur[i][col]);
				}
			}
			Set<String> mine = new HashSet<String>();
			for (int i = 0; i < N; i++)
				mine.add(new String(cur[i]));

			for (int col = 0; col < L; col++) {
				if ((mask & (1 << col)) != 0) {
					for (int i = 0; i < N; i++)
						cur[i][col] = swap(cur[i][col]);
				}
			}
			
			if (mine.size() != N)
				continue;
			Iterator<String> iter = mine.iterator();
			boolean valid = true;
			while (iter.hasNext()) {
				if (!target.contains(iter.next())) {
					valid = false;
					break;
				}
			}
			if (!valid)
				continue;
			ans = Math.min(ans, cnt);
		}

		return (ans == 1 << 25) ? "NOT POSSIBLE" : (ans + "");
	}

	public void answer() throws Exception {
		in = new InputReader("in.in");
		FileWriter out = new FileWriter("out.out");
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) {
			out.write("Case #" + i + ": " + solve() + "\n");
		}
		out.close();
	}

	public static void main(String[] args) throws Exception {
		new A().answer();
	}

	static class InputReader {
		BufferedReader in;
		StringTokenizer st;

		public InputReader(String filename) throws IOException {
			in = new BufferedReader(new FileReader(filename));
			st = new StringTokenizer(in.readLine());

		}

		public String next() throws IOException {

			while (!st.hasMoreElements())
				st = new StringTokenizer(in.readLine());
			return st.nextToken();
		}

		public int nextInt() throws NumberFormatException, IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}
	}
}
