import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Charging {
	private static InputStream in;
	private static PrintStream out;
	private static Scanner sc;
	private static BigInteger[] outlets;
	private static BigInteger[] plugs;
	private static int n;
	private static int l;
	static {
		try {
			in =
			 new FileInputStream("A-small-attempt0.in");
//			System.in;
			out =
			 new PrintStream(new FileOutputStream("out.txt"));
//			System.out;
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		sc = new Scanner(in);
		int numCases = sc.nextInt();
		for (int i = 0; i < numCases; i++) {
			out.println("Case #" + (i + 1) + ": " + solve());
		}
	}

	private static String solve() {
		n = sc.nextInt();
		l = sc.nextInt();

		outlets = new BigInteger[n];
		plugs = new BigInteger[n];
		for (int i = 0; i < n; i++) {
			BigInteger outlet = new BigInteger("0");
			String line = sc.next();
			for (int j = 0; j < l; j++) {

				if (line.charAt(j) == '1') {
					outlet=outlet.setBit(j);
				}
			}
			outlets[i] = outlet;

		}

		for (int i = 0; i < n; i++) {
			BigInteger plug = new BigInteger("0");
			String line = sc.next();
			for (int j = 0; j < l; j++) {

				if (line.charAt(j) == '1') {
					plug=plug.setBit(j);
				}
			}
			plugs[i] = plug;

		}

		int min = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			BigInteger mask = convertTo(outlets[0], plugs[i]);
			if (valid(mask, i)) {
				int diff = numberOfOnes(mask);
				if (diff < min) {
					min = diff;
				}
			}
		}
		return (min == Integer.MAX_VALUE ? "NOT POSSIBLE" : "" + min);
	}

	private static boolean valid(BigInteger mask, int pUsed) {
		boolean[] plugUsed = new boolean[n];

		plugUsed[pUsed] = true;

		return isValid(plugUsed, 1, mask);
	}

	private static boolean isValid(boolean[] plugUsed, int i, BigInteger mask) {
		if (i == n)
			return true;

		for (int j = 0; j < n; j++) {
			if (plugUsed[j])
				continue;
			if (mask.equals(convertTo(outlets[i], plugs[j]))) {
				plugUsed[j] = true;
				if (isValid(plugUsed, i + 1, mask))
					return true;
				plugUsed[j] = false;
			}
		}
		return false;
	}

	private static int numberOfOnes(BigInteger mask) {
		int res = 0;
		for (int i = 0; i < l; i++) {
			if (mask.testBit(i)) {
				res++;
			}
		}
		return res;
	}

	private static BigInteger convertTo(BigInteger i1, BigInteger i2) {
		BigInteger result = new BigInteger("0");
		for (int i = 0; i < l; i++) {
			if (i1.testBit(i) != i2.testBit(i)) {
				result=result.setBit(i);
			}
		}
		return result;
	}
}
