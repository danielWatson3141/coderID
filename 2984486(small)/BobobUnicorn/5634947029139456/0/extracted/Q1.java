import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Q1 {
	public static class Pair {
		public int f;
		public long s;

		public Pair(int f, long s) {
			super();
			this.f = f;
			this.s = s;
		}
	}

	public static class PairComp implements Comparator<Pair> {
		@Override
		public int compare(Pair l, Pair r) {
			return l.f - r.f;
		}
	}

	public static int bitcount(long val) {
		int count = 0;
		while (val > 0) {
			if ((val & 1) == 1) {
				count++;
			}
			val >>= 1;
		}
		return count;
	}

	public static void main(String[] args) throws Exception {
		String strNP = "NOT POSSIBLE";
		Scanner in = new Scanner(new File("A-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"A-small.out")));

		int T = in.nextInt();

		for (int c = 0; c < T; c++) {
			int N = in.nextInt();
			int L = in.nextInt();

			int[] outlet1counts = new int[L];
			int[] device1counts = new int[L];
			long[] outlets = new long[N];
			in.nextLine();

			for (int i = 0; i < N; i++) {
				String tk = in.next();
				for (int cc = 0; cc < tk.length(); cc++) {
					if (tk.charAt(cc) == '0') {
					} else if (tk.charAt(cc) == '1') {
						outlets[i] |= 1 << cc;
						outlet1counts[cc]++;
					}
				}
			}

			long[] devices = new long[N];
			// [device][outlet]
			long[][] distances = new long[N][N];

			in.nextLine();

			for (int i = 0; i < N; i++) {
				String tk = in.next();
				for (int cc = 0; cc < tk.length(); cc++) {
					if (tk.charAt(cc) == '0') {
					} else if (tk.charAt(cc) == '1') {
						devices[i] |= 1 << cc;
						device1counts[cc]++;
					}
				}

				// find distances
				for (int j = 0; j < N; j++) {
					distances[i][j] = devices[i] ^ outlets[j];
				}
			}

			Pair[] mdist = new Pair[N];
			for (int dist = 0; dist < N; dist++) {
				mdist[dist] = new Pair(bitcount(distances[0][dist]),
						distances[0][dist]);
			}
			Arrays.sort(mdist, new PairComp());
			
			boolean bbfound = false;

			for (int dist = 0; dist < N; dist++) {
				long ldist = mdist[dist].s;
				// traverse the distances to check if its all there
				boolean bfound = true;

				for (int dev2 = 0; dev2 < N; dev2++) {
					boolean found = false;
					for (int dist2 = 0; dist2 < N; dist2++) {
						if (distances[dev2][dist2] == ldist) {
							found = true;
							break;
						}
					}

					if (!found) {
						bfound = false;
						break;
					}
				}

				if (bfound) {
					out.printf("Case #%d: %d\n", c + 1, mdist[dist].f);
					bbfound = true;
					break;
				}
			}
			
			if (!bbfound) {
				out.printf("Case #%d: %s\n", c + 1, strNP);
			}
		}

		in.close();
		out.close();
	}
}
