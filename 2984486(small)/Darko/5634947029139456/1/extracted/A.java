import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class A {

	private void work() throws IOException {
		Scanner sc = new Scanner(new FileReader("A-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A-large.out"));
		// Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		// PrintWriter pw = new PrintWriter(new
		// FileWriter("A-small-attempt0.out"));
		// Scanner sc = new Scanner(new FileReader("a.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("a.out"));

		long[] outlets = new long[200];
		long[] devices = new long[200];

		Set<Long> outSet = new TreeSet<Long>();
		Set<Long> devSet = new TreeSet<Long>();

		int oo = 99999;

		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			int n = sc.nextInt();
			int len = sc.nextInt();
			for (int i = 0; i < n; i++) {
				outlets[i] = Long.valueOf(sc.next(), 2);
			}
			devSet.clear();
			for (int i = 0; i < n; i++) {
				devices[i] = Long.valueOf(sc.next(), 2);
				devSet.add(devices[i]);
			}

			int min = oo;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					long mask = 0;
					for (int k = 0; k < len; k++) {
						if (((1L << k) & outlets[i]) != (((1L << k) & devices[j]))) {
							mask |= 1L << k;
						}
					}
					int bc = Long.bitCount(mask);
					if (bc < min) {
						outSet.clear();
						for (int k = 0; k < n; k++) {
							long t = outlets[k];
							for (int l = 0; l < len; l++) {
								if (((1L << l) & mask) != 0) {
									t ^= 1L << l;
								}
							}
							outSet.add(t);
						}
						if (outSet.equals(devSet)) {
							min = bc;
						}
					}
				}
			}

			pw.printf("Case #%d: %s\n", tc, min == oo ? "NOT POSSIBLE"
					: Integer.toString(min));
		}
		pw.close();
	}

	public static void main(String[] args) throws IOException {
		new A().work();
	}
}
