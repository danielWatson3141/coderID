import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = sc.nextInt(), L = sc.nextInt();
			int[] outlets = new int[N];
			for (int j = 0; j < N; j++) {
				outlets[j] = Integer.parseInt(sc.next(), 2);
			}
			int[] devices = new int[N];
			for (int j = 0; j < N; j++) {
				devices[j] = Integer.parseInt(sc.next(), 2);
			}
			int min = 999;
			for (int j = 0; j < 1 << L; j++) {
				int[] o = new int[N];
				for (int k = 0; k < N; k++) {
					o[k] = outlets[k] ^ j;
				}
				if (match(o, devices)) {
					min = Math.min(min, Integer.bitCount(j));
				}
			}
			System.out.printf("Case #%d: %s\n", i, min == 999 ? "NOT POSSIBLE"
					: min);
		}
		sc.close();
	}

	private static boolean match(int[] a, int[] b) {
		int[] matched = new int[b.length];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < b.length; j++) {
				if (matched[j] == 0 && a[i] == b[j]) {
					matched[j] = 1;
					break;
				}
			}
		}
		for (int i = 0; i < b.length; i++) {
			if (matched[i] == 0) {
				return false;
			}
		}
		return true;
	}
}