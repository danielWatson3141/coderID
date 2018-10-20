import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class ProblemB1 {

	public static void main(String... argv) throws Exception {
		String filename = ProblemB1.class.getSimpleName();
		Scanner in = new Scanner(new File(filename + ".in"));
		PrintWriter out = new PrintWriter(new File(filename + ".out"));
		solve(in, out);
		out.flush();
		out.close();
	}

	private static final void solve(final Scanner in, final PrintWriter out) throws Exception {
		int testCount = in.nextInt();
		for (int testCase = 1; testCase <= testCount; ++testCase) {
			String result = solveTest(in, out);
			out.println(String.format("Case #%d: %s", testCase, result));
		}
	}

	private static final String solveTest(final Scanner in, final PrintWriter out) throws Exception {

		int n = in.nextInt();

		List<List<Integer>> g = new ArrayList<List<Integer>>();
		for (int i = 0; i < n; ++i) {
			g.add(new ArrayList<Integer>(16));
		}

		for (int i = 0; i < n - 1; ++i) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			g.get(x).add(y);
			g.get(y).add(x);
		}

		int minCount = Integer.MAX_VALUE;

		int size[] = new int[n];

		for (int i = 0; i < n; ++i) {
			Arrays.fill(size, 0);
			int count = compute(i, -1, g, size);
			if (count < minCount) {
				minCount = count;
			}
		}

		String result = "" + minCount;
		return result;
	}

	private static final int compute(int num, int parent, List<List<Integer>> g, int size[]) {

		int[] subCompute = new int[g.get(num).size() + (parent == -1 ? 0 : -1)];
		int index = 0;
		int subTreeSize = 0;
		int totalSubCompute = 0;
		for (int to : g.get(num)) {
			if (to != parent) {
				subCompute[index] = compute(to, num, g, size);
				subCompute[index] = size[to] - subCompute[index];
				++index;
				subTreeSize += size[to];
			}
		}

		int result = subTreeSize;

		if (subCompute.length > 1) {
			Arrays.sort(subCompute);
			if (result > subTreeSize - subCompute[subCompute.length - 1] - subCompute[subCompute.length - 2]) {
				result = subTreeSize - subCompute[subCompute.length - 1] - subCompute[subCompute.length - 2];
			}
		}

		size[num] = 1 + subTreeSize;

		return result;
	}
}
