import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

	private void work() throws IOException {

		// Scanner sc = new Scanner(new FileReader("C-large.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter(
		// "C-large.out"));
		Scanner sc = new Scanner(new FileReader("C-small-attempt1.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("C-small-attempt1.out"));
		// Scanner sc = new Scanner(new FileReader("c.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("c.out"));

		int nc = sc.nextInt();
		int bad = 0;
		for (int tc = 1; tc <= nc; tc++) {
			int n = sc.nextInt();
			int c[] = new int[2];
			for (int i = 0; i < n; i++) {
				if (sc.nextInt() == i) {
					c[i / 500]++;
				}
			}
			// System.out.println(c[0] + " " + c[1]);

			boolean good = Math.abs(c[0] - c[1]) > 0;
			if (!good)
				bad++;
			pw.printf("Case #%d: %s\n", tc, good ? "GOOD" : "BAD");
		}
		System.out.println(bad + " " + (120 - bad));
		pw.close();

	}

	public static void main(String[] args) throws IOException {
		new C().work();
	}

}
