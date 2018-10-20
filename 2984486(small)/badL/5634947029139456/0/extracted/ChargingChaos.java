package com.badal;

import static com.badal.util.InputUtility.getInt;
import static com.badal.util.InputUtility.getIntArray;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import com.badal.util.AbstractProblem;

public class ChargingChaos extends AbstractProblem {

	public static void main(String[] args) throws Exception {
		ChargingChaos problem = new ChargingChaos();
		problem.generateOutputForInput("C:\\Users\\badal\\Downloads\\A-small-attempt1.in");
	}

	@Override
	public void solve(BufferedReader br) throws Exception {
		int t = getInt(br);
		test: for (int i = 0; i < t; i++) {
			int[] inp = getIntArray(br);
			int n = inp[0];
			int l = inp[1];
			int[] available = getIntArray(br);
			int[] required = getIntArray(br);

			int flips = 0;
			List<Integer> list = new ArrayList<>();

			flips = check(n, l, available, required, 0, flips);
			if (flips == -1) {
				String out = "Case #" + (i + 1) + ": " + "NOT POSSIBLE";
				System.out.println(out);
				output.add(out);
				continue test;
			}

			String out = "Case #" + (i + 1) + ": " + flips;
			System.out.println(out);
			output.add(out);

		}
	}

	private int check(int n, int l, int[] available, int[] required, int k, int flips) {
		if (k == l) {
			Arrays.sort(available);
			Arrays.sort(required);
			if (Arrays.equals(available, required)) {
				return flips;
			} else {
				return -1;
			}
		}

		int av = 0;
		int re = 0;

		for (int j = 0; j < n; j++) {
			av += (available[j] % Math.pow(10, k + 1)) / Math.pow(10, k);
			re += (required[j] % Math.pow(10, k + 1)) / Math.pow(10, k);
		}

		if (av == re || av == n - re ) {
			if ((re == n / 2 && 0 == n % 2) || n==1) {
				int f = check(n, l, Arrays.copyOf(available, n), Arrays.copyOf(required, n), k+1,
						flips);
				if (f != -1)
					return f;
			}
			if (av == n - re) {
				flips++;
				for (int p = 0; p < n; p++) {
					int bit = (int) ((int)(available[p] % Math.pow(10, k + 1)) / Math.pow(10, k));
					if (bit == 0) {
						available[p] = (int) (available[p] + Math.pow(10, k));
					} else {
						available[p] = (int) (available[p] - Math.pow(10, k));
					}
				}
			}
			return check(n, l, available, required, k+1, flips);

		} else {
			return -1;
		}

	}
}
