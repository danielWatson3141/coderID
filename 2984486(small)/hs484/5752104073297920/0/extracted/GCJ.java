package gcj.Round1A2014.C;

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
		if (true) { filename = "C-small-attempt1.in"; }
//		if (true) { filename = "C-large-practice.in"; }

		Scanner sc = null;
		try {
			sc = new Scanner(new File(dir + "/" + filename));
		} catch (FileNotFoundException e) {
			tr(e.getMessage());
			return;
		}


		PrintWriter fout = new PrintWriter(new File(dir + "/" + filename + ".res"));
		GCJ obj = new GCJ();
//		obj.investigate();
		int TNO = sc.nextInt();
		for (int tno = 0; tno < TNO; tno++) {
			fout.write(String.format("Case #%d: ", (tno + 1)));
			obj.solve(sc, fout);
			fout.flush();
		}
		fout.flush();
		fout.close();
	}
//
//	Random rand = new Random();
//	void investigate() {
//		int N = 1000;
//
//		TreeMap<String, Integer> count = new TreeMap<String, Integer>();
//
//		for (int step = 0; step < 10000; step++) {
//			int[] a = new int[N];
//			for (int i = 0; i < N; i++) a[i] = i;
////			good(a);
//			bad(a);
//
//			int pos1 = -1;
//			for (int i = 0; i < a.length; i++)
//				if (a[i] == 1) {
//					pos1 = i;
//					break;
//				}
//
//			inc(count, String.format("%5d", pos1));
//		}
//
//		for (String s : count.keySet()) {
//			System.out.println(s + "\t" + count.get(s));
//		}
//	}
//
//	int rev(int[] a) {
//		int res = 0;
//		for (int i = 0; i < a.length; i++) {
//			for (int j = i + 1; j < a.length; j++) {
//				if (a[i] > a[j]) res++;
//			}
//		}
//		return res;
//	}
//
//	StringBuilder sb = new StringBuilder();
//	void inc(TreeMap<String, Integer> count, int[] a) {
//		sb.setLength(0);
//		for (int x : a) sb.append(x).append(",");
//		String s = sb.toString();
//		inc(count, s);
//	}
//	void inc(TreeMap<String, Integer> count, String s) {
//		sb.setLength(0);
//		int v = 0;
//		if (count.containsKey(s)) v = count.get(s);
//		count.put(s, v+1);
//	}
//
//	void good(int[] a) {
//		int n = a.length;
//		for (int k = 0; k < n; k++) {
//			int p = rand.nextInt(n - k) + k;
//			swap(a, k, p);
//		}
//	}
//	void bad(int[] a) {
//		int n = a.length;
//		for (int k = 0; k < n; k++) {
//			int p = rand.nextInt(n);
//			swap(a, k, p);
//		}
//	}
//	void swap(int[] a, int i, int j) {
//		int t = a[i];
//		a[i] = a[j];
//		a[j] = t;
//	}

	void solve(Scanner sc, PrintWriter fout) {
		int N = sc.nextInt();
		int[] a = new int[N];
		for (int i = 0; i < N; i++) a[i] = sc.nextInt();
		long sum = 0;
		for (int i = 0; i < N / 3; i++) {
			sum += a[i];
		}
		fout.println(sum < N * (N - 1) / 2 / 3 - 3000 ? "BAD" : "GOOD");
	}
}
