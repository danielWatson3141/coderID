package codejam;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main1 {
	public static void main(String[] args) throws IOException {
		// StreamTokenizer in = new StreamTokenizer(new BufferedReader(new
		// InputStreamReader(System.in)));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(
				new FileOutputStream("a.out")));
		Scanner cin = new Scanner(new FileInputStream("A-small-attempt2.in"));
//		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
//		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();

		for (int i = 1; i <= T; i++) {
			int N, L;
			N = cin.nextInt();
			L = cin.nextInt();
			long[] a = new long[150];
			long[] b = new long[150];

			int[] bitNum = new int[40];
			int[] bitNum2 = new int[40];
			for (int j = 0; j < N; j++) {
				String s = cin.next();
				a[j] = convert(s, bitNum);
			}

			for (int j = 0; j < N; j++) {
				String s = cin.next();
				b[j] = convert(s, bitNum2);
			}

			int res = getNum(a, b, bitNum, bitNum2, N, L);
			out.print("Case #");
			out.print(i);
			out.print(": ");
			if (res == -1)
				out.println("NOT POSSIBLE");
			else
				out.println(res);
		}
		out.flush();
		out.close();
	}

	private static int getNum(long[] a, long[] b, int[] bitNum, int[] bitNum2,
			int n, int l) {
		int res = 0;
		boolean[] tobe = new boolean[40];
		for (int i = 0; i < tobe.length; i++) {
			tobe[i] = false;
		}
		for (int i = 0; i < l; i++) {
			if (bitNum[i] != bitNum2[i]) {
				if (bitNum[i] != (n - bitNum2[i]))
					return -1;
				else {
					swap(a, i, n);
					res++;
				}
			} else {
				if (bitNum[i] == (n - bitNum2[i])) {
					tobe[i] = true;
				}
			}
		}

		return getNum(a, b, tobe, 0, l, res, n);
	}

	private static int getNum(long[] a, long[] b, boolean[] tobe, int i, int l,
			int res, int n) {

		if (equal(a, b, n))
			return res;
		if (i == l)
			return -1;
		int tem = getNum(a, b, tobe, i + 1, l, res, n);
		if (tobe[i] && tem == -1) {
			swap(a, i, n);
			int temp = getNum(a, b, tobe, i + 1, l, res + 1, n);
			swap(a, i, n);
			return temp;
		}
		return tem;
	}

	private static boolean equal(long[] a, long[] b, int n) {
		for (int i = 0; i < n; i++) {
			boolean find = false;
			for (int j = 0; j < n; j++) {
				if (a[j] == b[i]) {
					find = true;
					break;
				}
			}
			if (!find)
				return false;
		}
		return true;
	}

	private static void swap(long[] a, int i, int n) {
		long scale = 1 << i;
		for (int j = 0; j < n; j++) {
			a[j] ^= scale;
		}
	}

	private static long convert(String s, int[] bitNum) {
		char[] c = s.toCharArray();
		long scale = 1L;
		long res = 0L;
		for (int i = 0; i < c.length; i++) {
			if (c[i] == '1') {
				bitNum[i]++;
				res += scale;
			}
			scale = scale << 1;
		}
		return res;
	}
}
