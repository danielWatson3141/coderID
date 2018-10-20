import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens()) {
			in = new StringTokenizer(br.readLine());
		}
		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public void solve() throws IOException {
		int n = nextInt();
		int l = nextInt();

		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = Long.parseLong(nextToken(), 2);
		}

		long[] b = new long[n];
		for (int i = 0; i < n; i++) {
			b[i] = Long.parseLong(nextToken(), 2);
		}

		long good = -1;
		for (int i = 0; i < n; i++) {
			boolean fail = false;
			HashSet<Long> outlet = new HashSet<Long>();
			long d = a[i] ^ b[0];
			for (int j = 0; j < n; j++) {
				outlet.add(a[j] ^ d);
			}

			for (int j = 0; j < n; j++) {
				if (!outlet.contains(b[j]))
					fail = true;
			}
			if (!fail && Long.bitCount(good) > Long.bitCount(d)) {
				good = d;
			}
		}
		if (good == -1) {
			out.println("NOT POSSIBLE");
		} else {
			out.println(Long.bitCount(good));
		}
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");

			int t = nextInt();
			for (int i = 0; i < t; i++) {
				out.print(String.format("Case #%d: ", i + 1));
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
