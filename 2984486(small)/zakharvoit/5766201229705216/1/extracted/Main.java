import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Locale;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.util.StringTokenizer;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Zakhar Voit(zakharvoit@gmail.com)
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
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        List<Integer>[] g = new List[n];

        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            g[v].add(u);
            g[u].add(v);
        }
        int ans = Integer.MAX_VALUE;
        size = new int[n];
        for (int start = 0; start < n; start++) {
            Arrays.fill(size, 0);
            countSize(g, start, -1);
            ans = Math.min(ans, dfs(g, start, -1));
        }

        out.println(ContestUtil.gcjTestNumber(testNumber) + ans);
    }

    int[] size;

    void countSize(List<Integer>[] g, int v, int p) {
        size[v] = 1;
        for (int to : g[v]) {
            if (to != p) {
                countSize(g, to, v);
                size[v] += size[to];
            }
        }
    }

    int dfs(List<Integer>[] g, int v, int p) {
        if (size[v] == 1) {
            return 0;
        }
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();

        for (int to: g[v]) {
            if (to != p) {
                a.add(dfs(g, to, v));
                b.add(size[to]);
            }
        }

        int[][] dp = new int[a.size()][3];

        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = -1;
            }
        }

        dp[0][0] = b.get(0);
        dp[0][1] = a.get(0);

        for (int i = 1; i < a.size(); i++) {
            for (int j = 0; j < 3; j++) {
                if (dp[i - 1][j] == -1) {
                    continue;
                }
                if (dp[i][j] == -1 || dp[i][j] > dp[i - 1][j] + b.get(i)) {
                    dp[i][j] = dp[i - 1][j] + b.get(i);
                }
                if (j < 2) {
                    if (dp[i][j + 1] == -1 || dp[i][j + 1] > dp[i - 1][j] + a.get(i)) {
                        dp[i][j + 1] = dp[i - 1][j] + a.get(i);
                    }
                }
            }
        }

        int res = Integer.MAX_VALUE;
        if (dp[a.size() - 1][2] != -1) {
            res = dp[a.size() - 1][2];
        }
        if (dp[a.size() - 1][0] != -1) {
            res = Math.min(res, dp[a.size() - 1][0]);
        }
        return res;
    }
}

class Scanner {
    BufferedReader in;
    StringTokenizer tok;

    public Scanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }

    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }

        return tok.nextToken();
    }

    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

}

class ContestUtil {
    static public String gcjTestNumber(int test) {
        return "Case #" + test + ": ";
    }
}

