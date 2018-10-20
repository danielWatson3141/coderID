/* Filename: R1A2014C.java
 * Author: Mushiyo
 */

import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class R1A2014C {

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("C-small-attempt3.in"));
		PrintWriter out = new PrintWriter(new File("pC.out"));

		while (input.hasNext()) {
			int T = input.nextInt();

			for (int t = 1; t <= T; ++t) {
				int N = input.nextInt();
				int[] P = new int[N];

				int countInPos = 0;
				for (int i = 0; i < N; ++i) {
					P[i] = input.nextInt();

					if (P[i] - N / 2 > 0) {
						if (P[i] - N / 2 <= i) {
							++countInPos;
						}
					} else if (P[i] <= i) {
						++countInPos;
					}

				}

				out.printf("Case #%d: ", t);
				if ((double) countInPos / N > 0.37) {
					out.println("BAD");
				} else {
					out.println("GOOD");
				}
			}
		}

		out.close();
	}

}
