package round1a;

import java.util.Arrays;
import java.util.Scanner;

public class ChargingChaos {

	public static int[][] getCombinations(int p, int q) {

		int pow = (int) Math.pow(p, q);
		int[][] res = new int[pow][q];

		for (int i = 0; i < pow; i++) {
			int m = i;
			int k = q;
			while (m != 0) {
				res[i][--k] = m % p;
				m = m / p;
			}
		}
		return res;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int cases = sc.nextInt();

		for (int cs = 1; cs <= cases; cs++) {

			int N = sc.nextInt();
			int L = sc.nextInt();

			int[] initialState = new int[N];
			int[] finalState = new int[N];

			for (int i = 0; i < N; i++) {
				initialState[i] = Integer.parseInt(sc.next(), 2);
			}

			for (int i = 0; i < N; i++) {
				finalState[i] = Integer.parseInt(sc.next(), 2);
			}

			Arrays.sort(initialState);
			Arrays.sort(finalState);

			int[][] combs = getCombinations(2, L);

			int min = L;
			boolean found = false;

			for (int[] comb : combs) {
				int count = 0;
				int[] temp = Arrays.copyOf(initialState, N);
				for (int i = 0; i < comb.length; i++) {
					if (comb[i] == 1) {
						count++;
						for (int j = 0; j < N; j++) {
							if ((temp[j] & (1 << i)) == 0) {
								temp[j] |= (1 << i);
							} else {
								temp[j] &= ~(1 << i);
							}

						}
					}
				}

				Arrays.sort(temp);
				
				if (Arrays.equals(finalState, temp)) {
				    found = true;
					min = Math.min(min, count);
				}
			}

			if (found)
				System.out.println("Case #" + cs + ": " + min);
			else
				System.out.println("Case #" + cs + ": " + "NOT POSSIBLE");
		}
	}

}
