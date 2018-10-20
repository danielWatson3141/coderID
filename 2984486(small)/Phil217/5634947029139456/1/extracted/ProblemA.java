package Round1A;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import java.util.Scanner;

public class ProblemA {

	static BufferedWriter out;
	static int switches;
	static int best;

	public static void solve(Scanner sc) throws IOException {
		int N = sc.nextInt();
		int L = sc.nextInt();
		String[] flow = new String[N];
		int[] ones = new int[L];
		for (int i = 0; i < N; i++) {
			flow[i] = sc.next();
			for (int j = 0; j < flow[i].length(); j++) {
				ones[j] += (flow[i].charAt(j) == '1' ? 1 : 0);
			}
		}
		String[] needed = new String[N];
		int[] onesNeeded = new int[L];
		for (int i = 0; i < N; i++) {
			needed[i] = sc.next();
			for (int j = 0; j < needed[i].length(); j++) {
				onesNeeded[j] += (needed[i].charAt(j) == '1' ? 1 : 0);
			}
		}
		switches = 0;
		best = L;
		boolean possible = true;
		char[][] flowChars = new char[N][L];
		for (int i = 0; i < flowChars.length; i++) {
			flowChars[i] = flow[i].toCharArray();
		}
		boolean[] possSw = new boolean[L];
		for (int i = 0; i < onesNeeded.length; i++) {
			if (ones[i] != onesNeeded[i]) {
				if (ones[i] != N - onesNeeded[i]) {
					possible = false;
				} else {
					switches++;
					sw(flowChars, i);
				}
			} else {
				if (ones[i] == N - onesNeeded[i]) {
					// possible switch
					possSw[i] = true;
				}
			}
		}
		// backTrack solution
		char[][] neededChars = new char[N][L];
		for (int i = 0; i < neededChars.length; i++) {
			neededChars[i] = needed[i].toCharArray();
		}
		if (possible) {
			possible = rec(flowChars, neededChars, possSw, 0);
		}

		if (possible) {
			System.out.println(best);
			out.write(best + "\n");
		} else {
			System.out.println("NOT POSSIBLE");
			out.write("NOT POSSIBLE" + "\n");
		}
	}

	public static boolean rec(char[][] flowChars, char[][] neededChars,
			boolean[] possSw, final int pos) {

		Arrays.sort(flowChars, new Comparator<char[]>() {
			@Override
			public int compare(char[] o1, char[] o2) {
				for (int i = 0; i < pos; i++) {
					if (o1[i] != o2[i]) {
						return o2[i] - o1[i];
					}
				}
				return 0;
			}
		});
		Arrays.sort(neededChars, new Comparator<char[]>() {
			@Override
			public int compare(char[] o1, char[] o2) {
				for (int i = 0; i < pos; i++) {
					if (o1[i] != o2[i]) {
						return o2[i] - o1[i];
					}
				}
				return 0;
			}
		});
		for (int i = 0; i < flowChars.length; i++) {
			for (int j = 0; j < pos; j++) {
				if (!(flowChars[i][j] == neededChars[i][j])) {
					return false;
				}
			}
		}
		if (pos < possSw.length) {
			boolean ret = rec(flowChars, neededChars, possSw, pos + 1);
			if (possSw[pos]) {
				sw(flowChars, pos);
				switches++;
				boolean ret2 = rec(flowChars, neededChars, possSw, pos + 1) || ret;
				switches--;
				sw(flowChars, pos);
				return ret2;
			}
			return ret;
		}
		best = Math.min(best, switches);
		return true;
	}

	public static void sw(char[][] flowChars, int s) {
		for (int j = 0; j < flowChars.length; j++) {
			flowChars[j][s] = (flowChars[j][s] == '1' ? '0' : '1');
		}
	}

	public static void main(String[] args) throws IOException {
//		 String name = "A-practice";
//		String name = "A-small-attempt5";
		 String name = "A-large";
		Scanner sc = new Scanner(new File(name + ".in"));
		sc.useLocale(Locale.US);

		FileWriter fstream = new FileWriter(name + ".out");
		out = new BufferedWriter(fstream);

		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			out.write("Case #" + i + ": ");
			solve(sc);
		}
		sc.close();
		out.close();
	}
}
