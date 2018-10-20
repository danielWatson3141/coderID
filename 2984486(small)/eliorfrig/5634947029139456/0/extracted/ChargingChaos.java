import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.Scanner;


public class ChargingChaos {

	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		String inputFilename = "A-small-attempt1.in";
		StringBuilder answer = new StringBuilder();
		try {
			FileInputStream fis = new FileInputStream(inputFilename);
			Scanner sc = new Scanner(fis);
			int testCases = sc.nextInt();
			for (int i=1; i<=testCases; i++) {
				int N = sc.nextInt();
				int L = sc.nextInt();
				long[] outlets = new long[N];
				for (int j=0; j<N; j++) {
					outlets[j] = Long.parseLong(sc.next(), 2);
				}
				long[] devices = new long[N];
				for (int j=0; j<N; j++) {
					devices[j] = Long.parseLong(sc.next(), 2);
				}
				String ans = solve(N, L, outlets, devices);
				answer.append("Case #" + i + ": " + ans + System.lineSeparator());
			}
			sc.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		writeOutput(answer.toString());
		System.out.println("in " + (System.currentTimeMillis() - start));
	}

	private static String solve(int n, int l, long[] outlets, long[] devices) {
		final String notPossible = "NOT POSSIBLE";
		long max = (long) Math.pow(2, l);
		long ans = l+1;
		for (long i=0; i<max; i++) {
			if (isTheSameAfterXor(n, i, outlets, devices)) {
				int bits = Long.bitCount(i);
				if (bits < ans)
					ans = bits;
			}
		}
		if (ans <= l)
			return "" + ans; 
		return notPossible;
	}

	private static boolean isTheSameAfterXor(int n, long j, long[] outlets, long[] devices) {
		long[] newOutlets = new long[outlets.length];
		for (int i=0; i<outlets.length; i++) {
			newOutlets[i] = outlets[i] ^ j;
		}
		long[] outletsSorted = LongMergeSort.sort(newOutlets, n, true);
		long[] devicesSorted = LongMergeSort.sort(devices, n, true);
		for (int i=0; i<outletsSorted.length; i++) {
			if (outletsSorted[i] != devicesSorted[i])
				return false;
		}
		return true;
	}
	private static void writeOutput(String string) {
		try {
			String outputFilename = "output.txt";
			BufferedWriter bw = new BufferedWriter(new FileWriter(outputFilename));
			bw.write(string);
			bw.close();
			System.out.println("success!");
		} catch (Exception e) {
			System.out.println("error!");
		}
	}

}
