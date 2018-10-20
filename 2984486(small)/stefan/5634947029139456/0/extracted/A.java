import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class A {
	public static final String FILENAME = "A-small-attempt0";

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/" + FILENAME
				+ ".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("src/"
				+ FILENAME + ".out"));
		Scanner s = new Scanner(in);
		int T = s.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = s.nextInt();
			int L = s.nextInt();
			boolean[][] outlets = new boolean[N][L];
			int[] outsum = new int[L];
			for (int j = 0; j < N; j++) {
				String t = s.next();
				for (int k = 0; k < L; k++) {
					outlets[j][k] = t.charAt(k) == '1';
					if (outlets[j][k]) {
						outsum[k]++;
					}
				}
			}
			boolean[][] devices = new boolean[N][L];
			int[] devsum = new int[L];
			for (int j = 0; j < N; j++) {
				String t = s.next();
				for (int k = 0; k < L; k++) {
					devices[j][k] = t.charAt(k) == '1';
					if (devices[j][k]) {
						devsum[k]++;
					}
				}
			}

			boolean impossible = false;
			int flips = 0;
			boolean[] guess = new boolean[L];
			for (int j = 0; j < L; j++) {
				if (outsum[j] == devsum[j] && outsum[j] == N - devsum[j]) {
					// what to do?
					guess[j] = true;
				} else if (outsum[j] == devsum[j]) {
					// no flip
				} else if (outsum[j] == N - devsum[j]) {
					// flip
					flips++;
					for (int k = 0; k < N; k++) {
						outlets[k][j] = !outlets[k][j];
					}
				} else {
					// impossible
					impossible = true;
				}
			}
			
			int add = minFlips(devices, outlets, guess);

			out.write("Case #" + i + ": "
					+ (impossible || add == Integer.MAX_VALUE ? "NOT POSSIBLE" : (flips+add)) + "\n");
		}
		in.close();
		out.close();
	}
	
	private static int minFlips(boolean[][] devices, boolean[][] outlets, boolean[] guess) {
		if(isSame(devices, outlets)) {
			return 0;
		}
		int t = -1;
		for (int i = 0; i < guess.length; i++) {
			if(guess[i]) {
				t = i;
			}
		}
		if(t == -1) {
			return Integer.MAX_VALUE;
		}
		guess[t] = false;
		int a = minFlips(devices, outlets, guess);
		for (int i = 0; i < outlets.length; i++) {
			outlets[i][t] = !outlets[i][t];
		}
		int b = minFlips(devices, outlets, guess);
		for (int i = 0; i < outlets.length; i++) {
			outlets[i][t] = !outlets[i][t];
		}
		guess[t] = true;
		
		if(a == Integer.MAX_VALUE && b == Integer.MAX_VALUE) {
			return Integer.MAX_VALUE;
		}
		else if(a == Integer.MAX_VALUE) {
			return b+1;
		}
		else if(b == Integer.MAX_VALUE) {
			return a;
		}
		else {
			return Math.min(a, b+1);
		}
	}

	private static boolean isSame(boolean[][] devices, boolean[][] outlets) {
		Comparator<boolean[]> comp = new Comparator<boolean[]>() {
			public int compare(boolean[] a, boolean[] b) {
				for (int i = 0; i < a.length; i++) {
					if (a[i] && !b[i]) {
						return 1;
					}
					if (!a[i] && b[i]) {
						return -1;
					}
				}
				return 0;
			}
		};
		
		Arrays.sort(devices, comp);
		Arrays.sort(outlets, comp);

		for (int i = 0; i < outlets.length; i++) {
			for (int j = 0; j < outlets[i].length; j++) {
				if (devices[i][j] != outlets[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

}
