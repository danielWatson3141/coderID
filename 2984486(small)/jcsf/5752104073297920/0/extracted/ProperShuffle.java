package codejam;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ProperShuffle {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(
				ProperShuffle.class.getResourceAsStream("proper-shuffle.txt"));

		int T = scanner.nextInt();

		BigInteger totalTally = BigInteger.ZERO;
		List<Long> localTallies = new ArrayList<>();

		for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
			int N = scanner.nextInt();

			long myTally = 0;

			for (int i = 0; i < N; i++) {
				myTally += Math.abs(scanner.nextInt() - i);
			}

			localTallies.add(myTally);
			totalTally = totalTally.add(BigInteger.valueOf(myTally));
		}

		long avg = totalTally.divide(BigInteger.valueOf(T)).longValue();

		for (int i = 0; i < localTallies.size(); i++) {
			boolean good = false;

			if (localTallies.get(i) > avg) {
				good = true;
			}

			System.out.println(String.format("Case #%d: %s", (i + 1),
					(good ? "GOOD" : "BAD")));
		}
	}
}
