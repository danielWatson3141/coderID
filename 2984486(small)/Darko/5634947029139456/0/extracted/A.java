import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class A {

	private void work() throws IOException {
		// Scanner sc = new Scanner(new FileReader("A-large.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("A-large.out"));
		Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt0.out"));
		// Scanner sc = new Scanner(new FileReader("a.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("a.out"));

		Set<Integer> outlets = new TreeSet<Integer>();
		Set<Integer> devices = new TreeSet<Integer>();
		int[] tmp = new int[200];
		Set<Integer> test = new TreeSet<Integer>();

		int oo = 99999;

		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			int n = sc.nextInt();
			int len = sc.nextInt();
			outlets.clear();
			devices.clear();
			for (int i = 0; i < n; i++) {
				outlets.add(Integer.valueOf(sc.next(), 2));
			}
			for (int i = 0; i < n; i++) {
				devices.add(Integer.valueOf(sc.next(), 2));
			}
			int min = oo;
			for (int i = 0; i < 1 << len; i++) {
				int bc = Integer.bitCount(i);
				if (bc >= min)
					continue;
				n = 0;
				for (int x : outlets)
					tmp[n++] = x;

				for (int j = 0; j < len; j++) {
					if (((1 << j) & i) != 0) {
						for (int k = 0; k < n; k++) {
							tmp[k] ^= 1 << j;
						}
					}
				}

				test.clear();
				for (int j = 0; j < n; j++) {
					test.add(tmp[j]);
				}
				if (test.equals(devices)) {
					min = bc;
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
