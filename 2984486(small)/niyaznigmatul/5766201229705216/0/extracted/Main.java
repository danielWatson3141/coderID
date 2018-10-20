import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		FullBinaryTree solver = new FullBinaryTree();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class FullBinaryTree {

    static List<Integer>[] edges;
//    static int[][][] dp;

//    static void dfs(int v, int p) {
//        for (int i : edges[v]) {
//            if (i == p) continue;
//            dfs(i, v);
//        }
//        // remove
//        {
//            int cur = 1;
//            for (int i : edges[v]) {
//                if (i == p) continue;
//                cur += takeTree(i);
//            }
//            dp[0][4][v] = cur;
//        }
//        {
//            int[][] cur = new int[2][4];
//            for (int[] d : cur) Arrays.fill(d, Integer.MAX_VALUE);
//            cur[0][0] = 0;
//            for (int i : edges[v]) {
//                if (i == p) continue;
//                int[][] next = new int[2][4];
//                for (int[] d : next) Arrays.fill(d, Integer.MAX_VALUE);
//                for (int curHas = 0; curHas < 2; curHas++) {
//                    for (int curDeg = 0; curDeg < 4; curDeg++) {
//                        int val = cur[curHas][curDeg];
//                        if (val == Integer.MAX_VALUE) continue;
//                        for (int has = 0; has + curHas < 2; has++) {
//                            int nHas = has + curHas;
//                            for (int deg = 0; deg <= 4; deg++) {
//                                int nextVal = dp[has][deg][i];
//                                if (nextVal == Integer.MAX_VALUE) continue;
//                                if (deg == 4) {
//                                    next[nHas][curDeg] = Math.min(next[nHas][curDeg], val + nextVal);
//                                } else if (deg == 3) {
//                                    continue;
//                                } else if (deg == 2) {
//                                    if (curDeg + 1 < 4) {
//                                        next[nHas][curDeg + 1] = Math.min(next[nHas][curDeg + 1], val + nextVal);
//                                    }
//                                } else if (deg == 1) {
//                                    if (nHas == 0 && curDeg + 1 < 4) {
//                                        next[1][curDeg + 1] = Math.min(next[1][curDeg + 1], val + nextVal);
//                                    }
//                                } else if (deg == 0) {
//                                    if (curDeg + 1 < 4) {
//                                        next[nHas][curDeg + 1] = Math.min(next[nHas][curDeg + 1], val + nextVal);
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//                cur = next;
//            }
//            for (int has = 0; has < 2; has++) {
//                for (int deg = 0; deg < 4; deg++) {
//                    dp[has][deg][v] = Math.min(dp[has][deg][v], cur[has][deg]);
//                }
//            }
//        }
//    }
//
//    static int takeTree(int v) {
//        int ret = Integer.MAX_VALUE;
//        ret = Math.min(ret, dp[0][0][v]);
//        ret = Math.min(ret, dp[1][1][v]);
//        ret = Math.min(ret, dp[1][3][v]);
//        ret = Math.min(ret, dp[0][2][v]);
//        return ret;
//    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        System.err.println(testNumber);
        int n = in.nextInt();
        edges = new List[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            edges[a].add(b);
            edges[b].add(a);
        }
//        dp = new int[2][5][n];
//        for (int[][] d1 : dp) {
//            for (int[] d : d1) {
//                Arrays.fill(d, Integer.MAX_VALUE);
//            }
//        }
//        dfs(0, -1);
//        for (int k = 0; k < n; k++) {
//            for (int j = 0; j < 5; j++) {
//                for (int i = 0; i < 2; i++) {
//                    System.out.println(i + " " + j + " " + k + " " + dp[i][j][k]);
//                }
//            }
//        }
//        out.println("Case #" + testNumber + ": " + takeTree(0));
        int ans = Integer.MAX_VALUE;
        size = new int[n];
        for (int root = 0; root < n; root++) {
            ans = Math.min(ans, dfs(root, -1));
        }
        out.println("Case #" + testNumber + ": " + ans);
    }

    static int dfs(int v, int p) {
        int dp0 = 0;
        int dp1 = Integer.MAX_VALUE;
        int dp2 = Integer.MAX_VALUE;
        size[v] = 1;
        for (int i = 0; i < edges[v].size(); i++) {
            int to = edges[v].get(i);
            if (to == p) continue;
            int val = dfs(to, v);
            size[v] += size[to];
            if (val == Integer.MAX_VALUE) throw new AssertionError();
            int nDP0 = Integer.MAX_VALUE;
            int nDP1 = Integer.MAX_VALUE;
            int nDP2 = Integer.MAX_VALUE;
            if (dp0 != Integer.MAX_VALUE) {
                nDP0 = Math.min(nDP0, dp0 + size[to]);
                nDP1 = Math.min(nDP1, dp0 + val);
            }
            if (dp1 != Integer.MAX_VALUE) {
                nDP1 = Math.min(nDP1, dp1 + size[to]);
                nDP2 = Math.min(nDP2, dp1 + val);
            }
            if (dp2 != Integer.MAX_VALUE) {
                nDP2 = Math.min(nDP2, dp2 + size[to]);
            }
            dp0 = nDP0;
            dp1 = nDP1;
            dp2 = nDP2;
        }
        int ret = Math.min(dp0, dp2);
//        System.out.println("v = " + v + ", ret = " + ret);
        return ret;
    }

    static int[] size;
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}

