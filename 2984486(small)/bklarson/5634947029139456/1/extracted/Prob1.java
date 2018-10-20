package Round1A;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.math.BigInteger;

public class Prob1 {
	private static BufferedReader r;
	private static PrintStream outFile;
	private static PrintStream out = new PrintStream(new OutputStream() {
		@Override
		public void write(int b) throws IOException {
			System.out.write(b);
			outFile.write(b);
		}
	});

	public static void main(String[] args) throws IOException {
		File f = new File("/home/blarson/input");
		r = new BufferedReader(new FileReader(f));
		outFile = new PrintStream(new FileOutputStream(new File(
				"/home/blarson/output")));
		final int numCases = readInt();

		for (int i = 0; i < numCases; i++) {
			out.print("Case #" + (i + 1) + ": ");

			solve();

			out.println();
		}

		out.close();
	}

	private static void solve() throws IOException {
		int[] nums = readIntArray(2);
		int n = nums[0];
		BigInteger[] currentPower = new BigInteger[n];
		BigInteger[] neededPower = new BigInteger[n];

		String[] data = r.readLine().trim().split(" ");
		for(int i = 0; i < n; i++) {
			currentPower[i] = new BigInteger(data[i], 2);
		}
		data = r.readLine().trim().split(" ");
		for(int i = 0; i < n; i++) {
			neededPower[i] = new BigInteger(data[i], 2);
		}
		
		if(testValid(currentPower, neededPower, new BigInteger("0"))) {
			out.print("0");
			return;
		}
		
		int bestSwaps = Integer.MAX_VALUE;
		for(BigInteger power : currentPower) {
			BigInteger swap = power.xor(neededPower[0]);
			if(bestSwaps > swap.bitCount()) {
				if(testValid(currentPower, neededPower, swap)) {				
					bestSwaps = swap.bitCount();
				}
			}
		}
		if (bestSwaps == Integer.MAX_VALUE) {
			out.print("NOT POSSIBLE");
		} else {
			out.print(bestSwaps);
		}
	}

	private static boolean testValid(BigInteger[] currentPower,
			BigInteger[] neededPower, BigInteger swap) {
		for(BigInteger power : currentPower) {
			BigInteger switchedPower = power.xor(swap);
			boolean found = false;
			for(BigInteger needed : neededPower) {
				if(switchedPower.equals(needed)) {
					found = true;
					break;
				}
			}
			if(!found) {
				return false;
			}
		}
		return true;
	}

	private static double[] readDoubleArray(int maxItems) throws IOException {
		double[] array = new double[maxItems];
		String line = r.readLine().trim();
		String[] data = line.split(" ");
		for (int i = 0; i < data.length && i < maxItems; i++) {
			array[i] = Double.parseDouble(data[i]);
		}
		return array;
	}

	private static int[] readIntArray(int maxItems) throws IOException {
		int[] array = new int[maxItems];
		String line = r.readLine().trim();
		String[] data = line.split(" ");
		for (int i = 0; i < data.length && i < maxItems; i++) {
			array[i] = Integer.parseInt(data[i]);
		}
		return array;
	}

	private static int readInt() throws IOException {
		String line = r.readLine().trim();
		return new Integer(line);
	}
}
