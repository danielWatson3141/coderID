import java.util.*;
import java.io.*;

public class Switches {

	static Scanner in;
	static PrintWriter out;

	static boolean found;
	static int flip;

	public static void main(String[] args) throws IOException {

		in = new Scanner(new FileInputStream("A-small-attempt1.in"));
		// in = new Scanner(new FileInputStream("q1in.txt"));
		out = new PrintWriter(new FileOutputStream("A-small-attempt1.out"));

		int iteration = in.nextInt();

		for (int z = 1; z <= iteration; z++) {

			found = false;
			flip = Integer.MAX_VALUE;

			int deviceN = in.nextInt();
			int switchN = in.nextInt();

			int[][] outlet = new int[deviceN][switchN];
			int[][] want = new int[deviceN][switchN];

			for (int i = 0; i < deviceN; i++) {
				String temp = in.next();
				for (int j = 0; j < switchN; j++) {
					outlet[i][j] = (int) temp.charAt(j) - (int) '0';
				}
			}

			for (int i = 0; i < deviceN; i++) {
				String temp = in.next();
				for (int j = 0; j < switchN; j++) {
					want[i][j] = (int) temp.charAt(j) - (int) '0';
				}
			}

			attemp(outlet, want, 0, 0);

			if (found) {
				System.out.println("Case #" + z + ": " + flip);
				out.println("Case #" + z + ": " + flip);
			} else {
				System.out.println("Case #" + z + ": " + "NOT POSSIBLE");
				out.println("Case #" + z + ": " + "NOT POSSIBLE");
			}

		}
		
		out.flush();
		out.close();

	}

	public static void attemp(int[][] current1, int[][] current2, int index, int flips) {

		if (match(current1, current2)) {
			found = true;
			if (flips < flip){
				flip = flips;
			}
			return;
		} else if (index == current1[0].length) {
			return;
		} else if (flips > flip){
			return;
		} else {

			for (int f = index; f < current1[0].length; f++) {
				for (int i = 0; i < current1.length; i++) {

					if (current1[i][f] == 0) {
						current1[i][f] = 1;
					} else {
						current1[i][f] = 0;
					}
				}
				attemp(current1, current2, index + 1, flips + 1);
				for (int i = 0; i < current1.length; i++) {

					if (current1[i][f] == 0) {
						current1[i][f] = 1;
					} else {
						current1[i][f] = 0;
					}
				}
			}
		}

	}

	public static boolean match(int[][] current1, int[][] current2) {

		boolean[] matched = new boolean[current2.length];

		for (int i = 0; i < current1.length; i++) {
			matched[i] = false;
		}

		l1: for (int i = 0; i < current1.length; i++) {
			l2: for (int j = 0; j < current1.length; j++) {

				if (!matched[j]) {
					boolean match = true;
					l3: for (int k = 0; k < current1[0].length; k++) {
						if (current1[i][k] != current2[j][k]) {
							match = false;
							break l3;
						}
					}

					if (match) {
						matched[j] = true;
					}

				}
			}
		}

		boolean good = true;
		for (int i = 0; i < current1.length; i++) {
			if (matched[i] == false) {
				good = false;
				break;
			}
		}

		return good;

	}

	public static void print(int[][] current) {
		System.out.println("dfgdf---gfg");
		for (int i = 0; i < current.length; i++) {
			for (int j = 0; j < current[0].length; j++) {
				System.out.print(current[i][j]);
			}
			System.out.print(" ");
		}

	}

}
