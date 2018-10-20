import java.util.*;

public class Q1 {
	public static int solve(long[] current, long[] desired, int bits) {
		int flipCount = 0;
		/* for each bit: 
		 * Leave as-is, mask off the remainder, sort the result, compare
		 * flip it, mask off the remainder, sort, compare, add
		 * else: break with nope
		 */
		long[] tempCurrent = new long[current.length];
		long[] tempDesired = new long[current.length];
		for (int i = 0; i < bits; i++) {
			for (int a = 0; a < desired.length; a++) {
				tempDesired[a] = desired[a] & ((1 << (i + 1)) - 1);
				tempCurrent[a] = current[a] & ((1 << (i + 1)) - 1);
			}
			Arrays.sort(tempDesired);
			Arrays.sort(tempCurrent);
			//System.out.println(Arrays.toString(tempDesired));
			//System.out.println(Arrays.toString(tempCurrent));
			/* leave it */
			if (Arrays.equals(tempDesired, tempCurrent)) continue;
			for (int a = 0; a < desired.length; a++) {
				tempCurrent[a] = tempCurrent[a] ^ (1 << i);
			}
			Arrays.sort(tempCurrent);
			if (Arrays.equals(tempDesired, tempCurrent)) {
				flipCount++;
				for (int a = 0; a < current.length; a++) {
					current[a] ^= (1 << i);
				}
			} else {
				return -1;
			}
		}
		return flipCount;
	}

	public static int solve2(long[] current, long[] desired, int bits) {
		int flipCount = -1;
		/* for each bit: 
		 * Leave as-is, mask off the remainder, sort the result, compare
		 * flip it, mask off the remainder, sort, compare, add
		 * else: break with nope
		 */
		long[] tempCurrent = new long[current.length];
		Arrays.sort(desired);
		for (long mask = 0; mask < (1 << bits); mask++) {
			for (int a = 0; a < desired.length; a++) {
				tempCurrent[a] = current[a] ^ mask;
			}
			Arrays.sort(tempCurrent);
			if (!Arrays.equals(desired, tempCurrent)) continue;
			int flips = 0;
			long maskc = mask;
			while(maskc != 0) {
				long bottom = maskc & 0x1;
				if (bottom != 0) flips++;
				maskc >>= 1;
			}
			if (flipCount == -1 || flips < flipCount) flipCount = flips;
			
		}
		return flipCount;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int count = scan.nextInt();
		for (int i = 0; i < count; i++) {
			int numberOfOutlets = scan.nextInt();
			int outletLength = scan.nextInt();
			long[] current = new long[numberOfOutlets];
			for (int j = 0; j < numberOfOutlets; j++) {
				current[j] = scan.nextLong(2);
			}
			long[] desired = new long[numberOfOutlets];
			for (int j = 0; j < numberOfOutlets; j++) {
				desired[j] = scan.nextLong(2);
			}
			int flipCount = solve2(current, desired, outletLength);
			System.out.println("Case #" + (i + 1) + ": " + (flipCount == -1? "NOT POSSIBLE" : flipCount));
			System.out.flush();
		}
	}
}