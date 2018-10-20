package charging;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Set;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));

		int T = Integer.parseInt(in.readLine());

		for (int x = 1; x <= T; x++) {
			String[] tokens = in.readLine().split(" ");
			int N = Integer.parseInt(tokens[0]);
			int L = Integer.parseInt(tokens[1]);

			tokens = in.readLine().split(" ");
			long[] A = new long[N];
			for (int i = 0; i < A.length; i++) {
				A[i] = Long.parseLong(tokens[i], 2);
			}

			tokens = in.readLine().split(" ");
			long[] B = new long[N];
			for (int i = 0; i < B.length; i++) {
				B[i] = Long.parseLong(tokens[i], 2);
			}

			long answer = findAnswer(A, B);

			if (answer == Long.MAX_VALUE) {
				System.out.println("Case #" + x + ": NOT POSSIBLE");
			} else {
				System.out.println("Case #" + x + ": " + answer);
			}
		}

		in.close();
	}

	private static long findAnswer(long[] A, long[] B) {
		Set<Long> aSet = new TreeSet<Long>();
		for (long aVal : A) {
			aSet.add(aVal);
		}

		long minMaskLen = Long.MAX_VALUE;
		for (long firstB : B) {
			long mask = firstB ^ A[0];
			if (maskOk(aSet, B, mask)) {
				long maskLen = maskLen(mask);
				if (maskLen < minMaskLen) {
					minMaskLen = maskLen;
				}
			}
		}
		return minMaskLen;
	}

	private static long maskLen(long mask) {
		long len = 0;
		while (mask > 0) {
			len += (mask % 2);
			mask /= 2;
		}
		return len;
	}

	private static boolean maskOk(Set<Long> aSet, long[] B, long mask) {
		for (long b : B) {
			if (!aSet.contains(b ^ mask)) {
				return false;
			}
		}
		return true;
	}

}
