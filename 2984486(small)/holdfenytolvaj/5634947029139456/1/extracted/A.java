package gcjpractice.round1A2014;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class A {
	static String IMPOSSIBLE = "NOT POSSIBLE";

	public static void main(String[] args) {
		String base = "/home/radicsge/gcj2014/";
		String input = base + "a4.in";
		String output = base + "a4.out";

		try {
			Scanner sc = new Scanner(new FileReader(input));
			PrintWriter pw = new PrintWriter(output);

			int T = sc.nextInt();
			sc.nextLine();
			for (int t = 0; t < T; t++) {
				System.out.println("Test case " + (t + 1) + "...");
				int N = sc.nextInt();
				int L = sc.nextInt();
				sc.nextLine();

				String[] outlets;
				String[] devs;
				outlets = sc.nextLine().split(" ");
				devs = sc.nextLine().split(" ");

				int solution = solve(outlets, devs, L - 1);
				pw.println("Case #" + (t + 1) + ": " + (solution < 0 ? IMPOSSIBLE : solution));
				System.out.println("Case #" + (t + 1) + ": " + (solution < 0 ? IMPOSSIBLE : solution));

			}
			pw.println();
			pw.flush();
			pw.close();
			sc.close();
		} catch (FileNotFoundException ex) {
			ex.printStackTrace();
		}
	}

	private static int solve(String[] outlets, String[] devs, int l) {
		if (l < 0) {
			return 0;
		}

		String[] outletsBackup = Arrays.copyOf(outlets, outlets.length);

		int solution = Integer.MIN_VALUE;
		if (isThereAPossibleMatch(outlets, devs, l)) {
			solution = solve(outlets, devs, l - 1);
		}

		int solution2 = Integer.MIN_VALUE;
		switchPower(outletsBackup, l);
		if (isThereAPossibleMatch(outletsBackup, devs, l)) {
			solution2 = solve(outletsBackup, devs, l - 1) + 1;
		}

		if (solution < 0 && solution2 < 0) {
			return Integer.MIN_VALUE;
		}
		if (solution >= 0 && solution2 >= 0) {
			return Math.min(solution, solution2);
		}
		return Math.max(solution, solution2);

	}

	private static boolean isThereAPossibleMatch(String[] outlets, String[] devs, int l) {
		Map<String, Integer> m = new HashMap<>();
		for (String o : outlets) {
			if (!m.containsKey(o.substring(l))) {
				m.put(o.substring(l), 0);
			}
			m.put(o.substring(l), m.get(o.substring(l)) + 1);
		}

		for (String o : devs) {
			if (m.containsKey(o.substring(l)) && m.get(o.substring(l)) > 0) {
				m.put(o.substring(l), m.get(o.substring(l)) - 1);
			} else {
				return false;
			}
		}

		return true;
	}

	private static void switchPower(String[] outlets, int l) {
		for (int i = 0; i < outlets.length; i++) {
			char[] c = outlets[i].toCharArray();
			c[l] = (c[l] == '0' ? '1' : '0');
			outlets[i] = new String(c);
		}
	}

}
