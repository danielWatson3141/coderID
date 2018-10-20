import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("tree.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("tree.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Tree solver = new Tree();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class Tree {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] u = new int[n - 1];
        int[] v = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            u[i] = in.nextInt() - 1;
            v[i] = in.nextInt() - 1;
        }
        int answer = get(n, u, v);
        out.println("Case #" + testNumber + ": " + answer);
    }


    private static int get(int n, int[] u, int[] v) {
        return new Solver(n, u, v).solve();
    }

    static class Solver {
        int n;
        List<Integer>[] e;

        Solver(int n, int[] u, int[] v) {
            this.n = n;
            e = new List[n];
            for (int i = 0; i < n; i++) {
                e[i] = new ArrayList<>();
            }
            for (int i = 0; i < n - 1; i++) {
                e[u[i]].add(v[i]);
                e[v[i]].add(u[i]);
            }
        }

        int solve() {
            int best = 0;
            for (int root = 0; root < n; root++) {
                int cur = solve(root, -1);
                if (cur > best) {
                    best = cur;
                }
            }
            return n - best;
        }

        private int solve(int u, int p) {
            List<Integer> answers = new ArrayList<>();
            for (int v : e[u]) {
                if (v == p) {
                    continue;
                }
                answers.add(solve(v, u));
            }
            Collections.sort(answers);
            if (answers.size() >= 2) {
                return 1 + answers.get(answers.size() - 1) + answers.get(answers.size() - 2);
            } else {
                return 1;
            }
        }
    }
}

class InputReader {
    BufferedReader br;
    StringTokenizer st;

    public InputReader(InputStream stream) {
        br = new BufferedReader(new InputStreamReader(stream));
    }

    public String next() {
        return nextToken();
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            String line = null;
            try {
                line = br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

}

