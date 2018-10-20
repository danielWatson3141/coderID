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
		if (true) { filename = "A-small-attempt1.in"; }
//		if (true) { filename = "A-large-practice.in"; }

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

		int ans = 10000;
		sort(dev);
		for (int set = 0; set < (1 << L); set++) {
			long mask = 0;
			for (int i = 0; i < L; i++) if ((set >> i & 1) == 1) {
				mask ^= (1L << i);
			}
			long[] st = sw.clone();
			for (int j = 0; j < N; j++) {
				st[j] ^= mask;
			}
			sort(st);
			if (eq(dev, st)) {
				ans = min(ans, Integer.bitCount(set));
			}
		}
		if (ans == 10000) {
			fout.println("NOT POSSIBLE");
		} else {
			fout.println(ans);
		}

	}

	boolean eq(long[] a, long[] b) {
		if (a.length != b.length) return false;
		for (int i = 0; i < a.length; i++)
			if (a[i] != b[i])
				return false;
		return true;
	}

}
