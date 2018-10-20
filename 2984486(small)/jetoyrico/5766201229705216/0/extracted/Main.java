import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.util.Arrays;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("tc/B-small-attempt0.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("tc/output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		B solver = new B();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class B {
	boolean[][] g;
	int del;
	boolean[] v;
	boolean ok;

    public void solve(int testNumber, Scanner in, PrintWriter out) {
	    int N = in.nextInt();
	    g = new boolean[N][N];
	    v = new boolean[N];
	    for (int i = 0; i < N - 1; ++i) {
		    int x = in.nextInt() - 1;
		    int y = in.nextInt() - 1;
		    g[x][y] = g[y][x] = true;
	    }
	    int res = Integer.MAX_VALUE;
	    for (int mask = 0; mask < two(N) - 1; ++mask) {
		    del = mask;
		    int delCount = Integer.bitCount(mask);
		    for (int par = 0; par < N; ++par) {
			    if (contain(mask, par)) continue;
			    Arrays.fill(v, false);
			    ok = true;
			    go(par);
			    int vCount = 0;
			    for (int i = 0; i < v.length; ++i) if (v[i]) vCount++;
			    ok = ok && N == vCount + delCount;
			    if (ok) {
				    res = Math.min(res, delCount);
			    }
		    }
	    }
	    out.print(String.format("Case #%d: %d\n", testNumber, res));
    }

	private void go(int node) {
		v[node] = true;
		int child = 0;
		for (int i = 0; i < g.length; ++i)
			if (!v[i] && !contain(del, i) && g[i][node])
				child++;
		if (child != 2 && child != 0) {
			ok = false;
			return;
		}
		for (int i = 0; i < g.length; ++i)
			if (!v[i] && !contain(del, i) && g[i][node]) {
				go(i);
			}
	}

	public static int two(int x) {
		return (1 << x);
	}

	public static boolean contain(int m, int x) {
		return (m & two(x)) != 0;
	}
}

