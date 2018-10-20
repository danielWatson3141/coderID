import java.io.StreamTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Locale;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Reader;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		TokenizerReader in = new TokenizerReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    int n;
    boolean[][] g;

    public void solve(@SuppressWarnings("UnusedParameters") int testNumber, TokenizerReader in, PrintWriter out) {
        n = in.nextInt();
        g = new boolean[n][n];
        for (int i = 0; i < n-1; ++i) {
            int x = in.nextInt()-1, y = in.nextInt()-1;
            g[x][y] = g[y][x] = true;
        }
        treeSize = new int[n];
        dp = new int[n];
        int res = n-1;
        for (int root = 0; root < n; ++root)
            res = Math.min(res, solve(root));
        out.println("Case #" + testNumber + ": " + res);
    }

    int[] treeSize;
    int[] dp;
    private int solve(int root) {
        rec(root, -1);
        return dp[root];
    }

    private void rec(int u, int parent) {
        treeSize[u] = 1;
        PriorityQueue<Integer> ts = new PriorityQueue<>();
        for (int i = 0; i < n; ++i)
            if (g[u][i] && i != parent) {
                rec(i, u);
                treeSize[u] += treeSize[i];
                ts.add(dp[i] - treeSize[i]);
            }

        dp[u] = treeSize[u] - 1;
        if (ts.size() >= 2) {
            int r = treeSize[u] - 1 + ts.poll();
            r += ts.poll();
            dp[u] = Math.min(dp[u], r);
        }
    }
}

class TokenizerReader extends StreamTokenizer {
    public TokenizerReader(InputStream in) {
        super(new BufferedReader(new InputStreamReader(in)));
        defaultConfig();
    }

    public String nextString() {
        try {
            nextToken();
        } catch (IOException e) {
            throw new RuntimeException("nextString: exception in line " + lineno(), e);
        }
        return sval;
    }

    public String next() {
        return nextString();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public void defaultConfig() {
        resetSyntax();
        wordChars(33, 126);
        whitespaceChars(0, ' ');
    }

}

