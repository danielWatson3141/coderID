package gcj.r1a;

import gcj.C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	Scanner scanner;


	private void solve() throws FileNotFoundException {
		File input = new File("data/r1a/A-large.in");
		scanner = new Scanner(input);

		File test = new File("data/r1a/A.out");
		PrintStream out = new PrintStream(new FileOutputStream(test));
		System.setOut(out);

		int testCase = scanner.nextInt();
		scanner.nextLine();

		for (int i = 1; i <= testCase; i++) {
			System.out.printf("Case #%d: ", i);
			solveCase();
		}
	}
	

	private void solveCase() {
		int n = scanner.nextInt();
		int l = scanner.nextInt();
		String out[] = new String[n];
		String tab[] = new String[n];
		long[] lOut = new long[n];
		long[] lTab = new long[n];
		
		for (int i = 0; i < n; i++) {
			out[i] = scanner.next();
			lOut[i] = f(out[i]);
		}
		for (int i = 0; i < n; i++) {
			tab[i] = scanner.next();
			lTab[i] = f(tab[i]);
		}
		Arrays.sort(lTab);
		
		int ans = 100;;
		for (int i = 0; i < n; i++) {
			long diff = lOut[0] ^ lTab[i];
			if (ok(diff, lOut, lTab)) {
				ans = Math.min(ans, bitCount(diff));
			}
		}
		if (ans == 100) {
			System.out.println("NOT POSSIBLE");
		} else {
			System.out.println(ans);
		}
	}




	private int bitCount(long diff) {
		int ans = 0;
		while (diff > 0) {
			ans += diff % 2;
			diff /= 2L;
		}
		return ans;
	}

	private boolean ok(long diff, long[] lOut, long[] lTab) {
		long[] copyOut = new long[lOut.length];
		for (int i = 0; i < lOut.length; i++) {
			copyOut[i] = lOut[i] ^ diff;
		}
		Arrays.sort(copyOut);
		
		for (int i = 0; i < lOut.length; i++) {
			if (copyOut[i] != lTab[i]) {
				return false;
			}
		}
		return true;
	}




	private long f(String string) {
		long res = 0;
		for (int i = 0; i < string.length(); i++) {
			res = res * 2L + (string.charAt(i) - '0');
		}
		return res;
	}




	public static void main(String[] args) throws FileNotFoundException {
		new A().solve();
	}
	
}
