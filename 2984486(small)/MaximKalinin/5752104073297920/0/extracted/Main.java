import java.io.StreamTokenizer;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
import java.util.Random;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		TokenizerReader in = new TokenizerReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    static final int n = 1000;
    static final int k = Math.min(31, n);

    static int[] num = new int[k];
    static int[] back = new int[n];
    static double[][] p = new double[k][n];

    static double[] step(double[] p, int pos) {
        double[] res = new double[n];
        for (int i = 0; i < n; ++i) {
            if (i == pos) {
                for (int j = 0; j < n; ++j)
                    res[j] += p[i] / n;
            } else {
                res[pos] += p[i] / n;
                res[i] += (n - 1) * p[i] / n;
            }
        }
        return res;
    }
    static {
        Arrays.fill(back, -1);
        Random rnd = new Random();
        for (int i = 0; i < k; ++i) {
            num[i] = rnd.nextInt(n);
//            num[i] = 0;
            p[i][num[i]] = 1;
            back[num[i]] = i;
        }
        for (int pos = 0; pos < n; ++pos)
            for (int j = 0; j < k; ++j)
                p[j] = step(p[j], pos);
/*
        for (double[] x : p)
            for (double d : x)
                System.err.print(d + " ");
*/
    }
    public void solve(@SuppressWarnings("UnusedParameters") int testNumber, TokenizerReader in, PrintWriter out) {
        in.nextInt();
        double prob = 1;
        int cntBad = 0;
        for (int i = 0; i < n; ++i) {
            int u = in.nextInt();
            if (back[u] >= 0) {
                prob *= p[back[u]][i];
                if (p[back[u]][i] > 0.001)
                    ++cntBad;
            }
        }
        boolean isBad = prob > Math.pow(1.0/n, k);
//        boolean isBad = cntBad > k/2;
        out.println("Case #" + testNumber + ": " + (isBad ? "BAD" : "GOOD"));
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

