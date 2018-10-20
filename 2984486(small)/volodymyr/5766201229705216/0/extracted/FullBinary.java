import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FullBinary {
	private static InputStream in;
	private static PrintStream out;
	private static Scanner sc;
	private static List[] adjs;
	private static int n;
	private static int[] sizes;

	static {
		try {
			in =
			 new FileInputStream("B-small-attempt4.in");
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
		adjs = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			adjs[i] = new ArrayList();
		}
		for (int i = 0; i < n - 1; i++) {
			int j = sc.nextInt() - 1;
			int k = sc.nextInt() - 1;
			adjs[j].add(k);
			adjs[k].add(j);
		}

		int min = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			int solve = solveForRoot(i);
			if (solve < min)
				min = solve;
		}
		return "" + min;
	}

	private static int solveForRoot(int root) {

		sizes = new int[n];
		calcSize(root, sizes, -1);

		return removeExtra(root, -1);
	}

	private static int removeExtra(int root, int parent) {
		int res = 0;
		if ((parent == -1 && adjs[root].size() == 1)
				|| (parent != -1 && adjs[root].size() == 2)) {
			return sizes[root];
		} else if ((parent == -1 && adjs[root].size() > 2)
				|| (parent != -1 && adjs[root].size() > 3)) {
			int firstKeep = 0;
			int firstKeepSize = Integer.MIN_VALUE;
			int secondKeepSize = Integer.MIN_VALUE;
			int secondKeep = 0;

			for (Object o : adjs[root]) {
				int j = ((Integer) o);
				if (j == parent)
					continue;

				int size = sizes[j];
				if (size > firstKeepSize) {
					if (size > secondKeepSize) {
						firstKeep = secondKeep;
						firstKeepSize = secondKeepSize;
						secondKeep = j;
						secondKeepSize = size;
					} else {
						firstKeep = j;
						firstKeepSize = size;
					}
				}
			}
			for (Object o : adjs[root]) {

				int j = ((Integer) o);
				if (j == parent)
					continue;
				if (j == firstKeep || j == secondKeep) {
					res += removeExtra(j, root);
				} else {
					res += sizes[j] + 1;
				}

			}

		} else {
			for (Object o : adjs[root]) {

				int j = ((Integer) o);
				if (j == parent)
					continue;
				res += removeExtra(j, root);
			}
		}
		return res;

	}

	private static int calcSize(int root, int[] size,  int parent) {
		int thisSize = 0;

		for (Object o : adjs[root]) {
			Integer nextInt = (Integer) o;
			if (nextInt == parent) {
				continue;
			}
			thisSize += calcSize(nextInt, size, root);
		}
		size[root] = thisSize;

		return thisSize + 1;
	}
}
