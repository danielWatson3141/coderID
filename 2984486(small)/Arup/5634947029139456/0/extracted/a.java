import java.util.*;

public class a {

	public static int n;
	public static int bits;

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {

			n = stdin.nextInt();
			bits = stdin.nextInt();

			long[] start = new long[n];
			for (int i=0; i<n; i++)
				start[i] = convert(stdin.next());

			long[] end = new long[n];
			for (int i=0; i<n; i++)
				end[i] = convert(stdin.next());

			// Means impossible.
			int best = bits+1;

			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					long xor = start[i] ^ end[j];
					boolean res = test(xor, start, end);
					if (res && Long.bitCount(xor) < best)
						best = Long.bitCount(xor);
				}
			}

			if (best > bits)
				System.out.println("Case #"+loop+": NOT POSSIBLE");
			else
				System.out.println("Case #"+loop+": "+best);
		}
	}

	public static long convert(String s) {
		long val = 0;
		for (int i=0; i<s.length(); i++) {
			long bit = (long)(s.charAt(i) - '0');
			val = 2*val + bit;
		}
		return val;
	}

	public static boolean test(long xor, long[] start, long[] end) {

		long[] a = new long[n];
		for (int i=0; i<n; i++)
			a[i] = start[i] ^ xor;
		long[] b = new long[n];
		for (int i=0; i<n; i++)
			b[i] = end[i];

		Arrays.sort(a);
		Arrays.sort(b);
		for (int i=0; i<n; i++)
			if (a[i] != b[i])
				return false;
		return true;
	}
}