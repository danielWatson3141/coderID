package com.fabio.casado.codejam;

import java.util.Random;
import java.util.Scanner;

public class ProperShuffle {

	static int tests;
	static int N;
	static int currentIndex;
	static int digit;
	static int changes;

	public static void main(String[] args) {
		// Read test case
		Scanner scanner = new Scanner(System.in);
		tests = scanner.nextInt();

		for (int cases = 1; cases <= tests; cases++) {
			N = scanner.nextInt();
			changes = 0;

			for (int i = 0; i < N; i++) {
				digit = scanner.nextInt();
				if (digit != currentIndex) {
					changes++;
				}

				currentIndex++;
			}

			boolean good = new Random().nextBoolean();
			if (good) {
				System.out.println(String.format("Case #%d: GOOD", cases));
			} else {
				System.out.println(String.format("Case #%d: BAD", cases));
			}
		}
	}
}
