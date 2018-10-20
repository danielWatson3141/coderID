import java.util.Set;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.HashSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("tc/A-large.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("tc/output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		A solver = new A();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class A {
	public void solve(int testNumber, Scanner in, PrintWriter out) {
		int N = in.nextInt();
		int L = in.nextInt();
		long[] e = new long[N];
		long[] d = new long[N];
		Set<Long> dset = new HashSet<>();
		for (int i = 0; i < N; ++i) {
			e[i] = Long.parseLong(in.next(), 2);
		}
		for (int i = 0; i < N; ++i) {
			d[i] = Long.parseLong(in.next(), 2);
			dset.add(d[i]);
		}
		long d0 = d[0];
		int res = Integer.MAX_VALUE;
		for (int i = 0; i < e.length; ++i) {
			long cure = e[i];
			long mask = d0 ^ cure;
			long[] ee = e.clone();
			for (int j = 0; j < L; ++j)
				if (containL(mask, j)) {
					for (int k = 0; k < N; ++k) ee[k] ^= twoL(j);
				}
			Set<Long> set = new HashSet<>();
			for (int j = 0; j < ee.length; ++j) if (dset.contains(ee[j])) set.add(ee[j]);
			if (dset.size() == set.size()) {
				res = Math.min(res, Long.bitCount(mask));
			}
		}
		if (res == Integer.MAX_VALUE) {
			out.print(String.format("Case #%d: NOT POSSIBLE\n", testNumber));
		} else {
			out.print(String.format("Case #%d: %d\n", testNumber, res));
		}
	}

	public static long twoL(int x) {
		return (1L << x);
	}

	public static boolean containL(long m, int x) {
		return (m & twoL(x)) != 0;
	}
}

