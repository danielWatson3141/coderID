

import java.util.Arrays;
import java.util.Scanner;

public class Main {

	private static final int NMAX = 10;
	private static final int NOT_POSSIBLE = 10000000;

	public static void main(String[] args) {
		int T;
		int N, L;
		int a[], b[];
		Scanner s = new Scanner(System.in);
		T = s.nextInt();
		a = new int[NMAX];
		b = new int[NMAX];
		for (int t = 1; t <= T; t++) {
			N = s.nextInt();
			L = s.nextInt();
			for (int i = 0; i < N; i++) {
				a[i] = s.nextInt(2);
			}
			for (int i = 0; i < N; i++) {
				b[i] = s.nextInt(2);
			}
			int result = solve(N, L, a, b);
			if (result == NOT_POSSIBLE) {
				System.out.printf("Case #%d: NOT POSSIBLE\n", t);
			} else {
				System.out.printf("Case #%d: %d\n", t, result);
			}
		}
	}

	private static int solve(int N, int L, int a[], int b[]) {
		int temp[] = new int[N];
		int ptn = 1 << L;
		int result = NOT_POSSIBLE;
		Arrays.sort(b, 0, N);
		for (int i = 0; i < ptn; i++) {
			for (int j = 0; j < N; j++) {
				temp[j] = a[j] ^ i;
			}
			Arrays.sort(temp, 0, N);
			if (eq(temp, b, N)) {
				int bits, itemp;
				bits = 0;
				itemp = i;
				while (itemp > 0) {
					bits += ((itemp & 1) == 1) ? 1 : 0;
					itemp >>= 1;
				}
				result = Math.min(bits, result);
			}
		}
		return result;
	}

	private static boolean eq(int[] temp, int[] b, int N) {
		for (int i = 0; i < N; i++) {
			if (temp[i] != b[i]) {
				return false;
			}
		}
		return true;
	}
}
