package codejam;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class ChargingChaos {
	public static void main(String[] args) {
		new ChargingChaos().go2();
	}

	private void go() {
		String start = "10100010000";

		BigInteger bi = new BigInteger(start, 2);

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 100; i++) {
			sb.append('1');
		}

		BigInteger mask = new BigInteger(sb.toString(), 2);

		while (mask.compareTo(BigInteger.ZERO) != 0) {
			mask = mask.subtract(BigInteger.ONE);

			System.out.println(mask);
		}
	}

	private void go2() {
		Scanner scanner = new Scanner(
				ChargingChaos.class.getResourceAsStream("charging-chaos.txt"));

		int T = scanner.nextInt();

		for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
			int N = scanner.nextInt();
			int L = scanner.nextInt();

			Set<BigInteger> initial = new HashSet<>();
			for (int i = 0; i < N; i++) {
				initial.add(new BigInteger(scanner.next(), 2));
			}

			Set<BigInteger> target = new HashSet<>();
			for (int i = 0; i < N; i++) {
				target.add(new BigInteger(scanner.next(), 2));
			}

			int required = solve(initial, target, L);

			if (required == -1) {
				System.out.println(String.format("Case #%d: NOT POSSIBLE",
						caseNumber));
			} else {
				System.out.println(String.format("Case #%d: %d", caseNumber,
						required));
			}
		}
	}

	public static boolean checkBit(long x, long k) {
		return (x & 1 << k) != 0;
	}

	private int solve(Set<BigInteger> initial, Set<BigInteger> target, int L) {
		for (long l = 0; l < (1L << L) - 1; l++) {
			List<BigInteger> flipped = new ArrayList<>(initial);

			for (int i = 0; i < flipped.size(); i++) {
				flipped.set(i, flipped.get(i).xor(BigInteger.valueOf(l)));
			}

			Set<BigInteger> compare = new HashSet<BigInteger>(target);
			compare.removeAll(flipped);

			if (compare.isEmpty()) {
				String binary = Long.toBinaryString(l);
				int count = binary.length() - binary.replace("1", "").length();

				return count;
			}
		}

		return -1;
	}
}
