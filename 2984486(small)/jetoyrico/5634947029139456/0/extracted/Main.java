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
			inputStream = new FileInputStream("tc/A-small-attempt0.in");
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
		int[] e = new int[N];
		for (int i = 0; i < N; ++i) {
			e[i] = Integer.parseInt(in.next(), 2);
		}
		Set<Integer> deviceSet = new HashSet<>();
		for (int i = 0; i < N; ++i) deviceSet.add(Integer.parseInt(in.next(), 2));
		int res = Integer.MAX_VALUE;
		for (int mask = 0; mask < two(L); ++mask) {
			int[] ee = e.clone();
			for (int i = 0; i < L; ++i)
				if (contain(mask, i)) {
					for (int j = 0; j < N; ++j) ee[j] ^= two(i);
				}
			Set<Integer> set = new HashSet<>();
			for (int i = 0; i < ee.length; ++i) if (deviceSet.contains(ee[i])) set.add(ee[i]);
			if (deviceSet.size() == set.size()) {
				res = Math.min(res, Integer.bitCount(mask));
			}
		}
		if (res == Integer.MAX_VALUE) {
			out.print(String.format("Case #%d: NOT POSSIBLE\n", testNumber));
		} else {
			out.print(String.format("Case #%d: %d\n", testNumber, res));
		}
	}

	public static int two(int x) {
		return (1 << x);
	}

	public static boolean contain(int m, int x) {
		return (m & two(x)) != 0;
	}
}

