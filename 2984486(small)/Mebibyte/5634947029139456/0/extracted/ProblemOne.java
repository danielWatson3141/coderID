import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.util.Arrays;

/**
 * Problem One
 * Question A from Google Code Jam 2014 Round 1A
 *
 * @author William Glenn Hollingsworth (Mebibyte)
 * @version 1.0
 */
public class ProblemOne {
	private static int mN, mL, min;
	private static Scanner scan;
	private static BufferedWriter writer;

	public static void main(String[] args) {
		try {
			scan = new Scanner(new File(args[0]));
			writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("output.txt"), "utf-8"));
			int tests = Integer.parseInt(scan.nextLine());
			for (int i = 1; i <= tests; i++) {
				mN = scan.nextInt();
				mL = scan.nextInt();
				int[] initial = new int[mN];
				int[] needed = new int[mN];

				for (int j = 0; j < mN; j++) {
					initial[j] = Integer.parseInt(scan.next(), 2);
				}
				for (int j = 0; j < mN; j++) {
					needed[j] = Integer.parseInt(scan.next(), 2);
				}
				Arrays.sort(needed);
				boolean done = check(initial, needed);
				if (done) writer.write("Case #" + i + ": 0\n");
				else {
					min = Integer.MAX_VALUE;
					
					for (int j = 0; j < 1 << mL; j++) {
						int[] curr = flip(initial, j);
						done = check(curr, needed);
						if (done & Integer.bitCount(j) < min) min = Integer.bitCount(j);
					}

					if (min == Integer.MAX_VALUE) writer.write("Case #" + i + ": " + "NOT POSSIBLE" + "\n");
					else writer.write("Case #" + i + ": " + min + "\n");
				}
			}
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static boolean check(int[] a, int[] b) {
		Arrays.sort(a);
		for (int j = 0; j < a.length; j++) {
			if (a[j] != b[j]) {
				return false;
			}
		}
		return true;
	}

	public static int[] flip(int[] a, int bit) {
		int[] curr = Arrays.copyOf(a, a.length);
		for (int i = 0; i < a.length; i++) {
			curr[i] ^= bit;
		}
		return curr;
	}
}