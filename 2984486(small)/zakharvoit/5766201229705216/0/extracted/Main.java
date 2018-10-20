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
        boolean[] del = new boolean[n];
        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    cnt++;
                }
            }
            if (cnt > ans) {
                continue;
            }
            Arrays.fill(del, false);
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    del[i] = true;
                }
            }
            for (int start = 0; start < n; start++) {
                if (del[start]) {
                    continue;
                }

                cntVis = 0;
                if (dfs(g, del, start, -1) && cntVis == n - cnt) {
                    ans = cnt;
                }
            }
        }

        out.println(ContestUtil.gcjTestNumber(testNumber) + ans);
    }

    int cntVis = 0;

    boolean dfs(List<Integer>[] g, boolean[] del, int v, int p) {
        cntVis++;
        int cnt = 0;
        for (int to : g[v]) {
            if (to != p && !del[to]) {
                cnt++;
            }
        }

        if (cnt != 2 && cnt != 0) {
            return false;
        }

        for (int to : g[v]) {
            if (to != p && !del[to]) {
                if (!dfs(g, del, to, v)) {
                    return false;
                }
            }
        }

        return true;
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

