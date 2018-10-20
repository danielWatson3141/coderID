import java.util.HashSet;
import java.util.Scanner;

public class Main {
	private static HashSet<Long>[] row, col;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = sc.nextInt(), L = sc.nextInt();
			long[] outlets = new long[N];
			for (int j = 0; j < N; j++) {
				outlets[j] = Long.parseLong(sc.next(), 2);
			}
			long[] devices = new long[N];
			for (int j = 0; j < N; j++) {
				devices[j] = Long.parseLong(sc.next(), 2);
			}
			long[][] table = new long[N][N];
			row = new HashSet[N];
			col = new HashSet[N];
			for (int j = 0; j < N; j++) {
				row[j] = new HashSet<Long>();
				col[j] = new HashSet<Long>();
			}
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					table[j][k] = outlets[j] ^ devices[k];
					row[j].add(table[j][k]);
					col[k].add(table[j][k]);
				}
			}
			int min = 999;
			for (long l : row[0]) {
				if (match(l)) {
					min = Math.min(min, Long.bitCount(l));
				}
			}
			System.out.printf("Case #%d: %s\n", i, min == 999 ? "NOT POSSIBLE"
					: min);
		}
		sc.close();
	}

	private static boolean match(long n) {
		for (int i = 0; i < row.length; i++) {
			if (!row[i].contains(n)) {
				return false;
			}
			if (!col[i].contains(n)) {
				return false;
			}
		}
		return true;
	}
}