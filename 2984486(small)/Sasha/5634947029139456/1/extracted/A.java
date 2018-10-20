import java.io.File;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

public class A {
	private static boolean compare(char[] a, char[] b, int len) {
		for (int i = 0; i < len; i++) {
			if (a[i] != b[i])
				return false;
		}
		return true;
	}

	private static char getOpssite(char c) {
		if (c == '1') {
			return '0';
		}
		return '1';
	}

	private static void sw(char[][] o, int pos) {
		for (int i = 0; i < o.length; i++) {
			o[i][pos] = getOpssite(o[i][pos]);
		}
	}

	private static int find(char[][] o, char[][] d, int count, int pos, int l) {

		boolean[] b = new boolean[o.length];

		for (int i = 0; i < o.length; i++) {
			boolean f = false;
			for (int j = 0; j < d.length; j++)
				if (!b[j] && compare(o[i], d[j], pos)) {
					f = true;
					b[j] = true;
					break;
				}
			if (!f) {
				return -1;
			}
		}
		
		if (pos == l) {
			return count;
		}

		int r1 = find(o, d, count, pos + 1, l);
		if (r1 != -1) {
			return r1;
		}
		sw(o, pos);
		int r2 = find(o, d, count + 1, pos + 1, l);
		sw(o, pos);

		return r2;

	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);

		Scanner in = new Scanner(new File("problem.in"));
		PrintStream out = new PrintStream(new File("problem.out"));

		int T = in.nextInt();
		for (int test = 1; test <= T; test++) {
			int n = in.nextInt();
			int l = in.nextInt();

			char[][] o = new char[n][];
			for (int i = 0; i < n; i++) {
				String s = in.next();
				o[i] = s.toCharArray();
			}
			char[][] d = new char[n][];
			for (int i = 0; i < n; i++) {
				String s = in.next();
				d[i] = s.toCharArray();
			}

			int res = find(o, d, 0, 0, l);
			out.print("Case #" + test + ": ");
			if (res >= 0) {
				out.println(res);
			} else {
				out.println("NOT POSSIBLE");
			}

		}

	}
}
