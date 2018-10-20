package gcj.Round1A2014.A;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;
import java.io.*;

public class GCJ {

	public static void tr(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	public static void main(String[] args) throws Throwable {
		String pkg = new Object(){}.getClass().getEnclosingClass().getPackage().getName().replace('.', '/');
		String dir = "src/" + pkg;

		String filename = "";

//		if (true) { filename = "sample.in"; }
//		if (true) { filename = "A-small-attempt1.in"; }
		if (true) { filename = "A-large.in"; }

		Scanner sc = null;
		try {
			sc = new Scanner(new File(dir + "/" + filename));
		} catch (FileNotFoundException e) {
			tr(e.getMessage());
			return;
		}
		PrintWriter fout = new PrintWriter(new File(dir + "/" + filename + ".res"));

		GCJ obj = new GCJ();
		int TNO = sc.nextInt();
		for (int tno = 0; tno < TNO; tno++) {
			fout.write(String.format("Case #%d: ", (tno + 1)));
			obj.solve(sc, fout);
			fout.flush();
		}
		fout.flush();
		fout.close();
	}

	long nextBin(Scanner sc) {
		String s = sc.next();
		return Long.parseLong(s, 2);
	}

	void solve(Scanner sc, PrintWriter fout) {
		int N = sc.nextInt();
		int L = sc.nextInt();
		long[] dev = new long[N];
		long[] sw = new long[N];
		for (int i = 0; i < N; i++) sw[i] = nextBin(sc);
		for (int i = 0; i < N; i++) dev[i] = nextBin(sc);

		if (L <= 4) {
			int ans = 10000;
			sort(dev);
			for (int set = 0; set < (1 << L); set++) {
				if (check(dev, sw, N, L, set)) {
					ans = min(ans, Integer.bitCount(set));
				}
			}
			if (ans == 10000) {
				fout.println("NOT POSSIBLE");
			} else {
				fout.println(ans);
			}
		}
		else
		{
			int ans = 10000;
			int L1 = L / 2;
			int L2 = L - L1;

			List<Long> m1 = new ArrayList<Long>();
			List<Long> m2 = new ArrayList<Long>();

			long[] dev1 = new long[N];
			long[] sw1 = new long[N];
			long[] dev2 = new long[N];
			long[] sw2 = new long[N];

			for (int i = 0; i < N; i++) {
				dev1[i] = dev[i] & ((1 << L1) - 1);
				sw1[i] = sw[i] & ((1 << L1) - 1);

				dev2[i] = dev[i] >> L1;
				sw2[i] = sw[i] >> L1;
			}

			sort(dev);
			sort(dev1);
			sort(dev2);
			for (int set = 0; set < (1 << L1); set++) {
				if (check(dev1, sw1, N, L1, set)) {
					m1.add((long)set);
				}
			}
			for (int set = 0; set < (1 << L2); set++) {
				if (check(dev2, sw2, N, L2, set)) {
					m2.add((long)set);
				}
			}


			for (long s1: m1) for (long s2 : m2) {
				long set = (s2 << L1) + s1;
				if (check(dev, sw, N, L, set)) {
					ans = min(ans, Long.bitCount(set));
				}
			}
			if (ans == 10000) {
				fout.println("NOT POSSIBLE");
			} else {
				fout.println(ans);
			}
		}

	}

	boolean check(long[] dev, long[] sw, int N, int L, long set) {
		long mask = 0;
		for (int i = 0; i < L; i++) if ((set >> i & 1) == 1) {
			mask ^= (1L << i);
		}
		long[] st = sw.clone();
		for (int j = 0; j < N; j++) {
			st[j] ^= mask;
		}
		sort(st);
		return eq(dev, st);
	}


	boolean eq(long[] a, long[] b) {
		if (a.length != b.length) return false;
		for (int i = 0; i < a.length; i++)
			if (a[i] != b[i])
				return false;
		return true;
	}

}
