import java.io.StreamTokenizer;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Locale;
import java.util.AbstractSet;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Reader;
import java.io.FilenameFilter;
import java.util.HashSet;
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
			final String regex = "A-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		TokenizerReader in = new TokenizerReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    int N, L;
    long[] outlets, devices;
    int res, changed;
    public void solve(@SuppressWarnings("UnusedParameters") int testNumber, TokenizerReader in, PrintWriter out) {
        N = in.nextInt();
        L = in.nextInt();
        outlets = read(in, N, L);
        devices = read(in, N, L);
        res = L+1;
        changed = 0;
        go(0);
        out.print("Case #" + testNumber + ": ");
        out.println(res <= L ? res : "NOT POSSIBLE");
    }

    private void go(int p) {
        HashSet<Long> curOutlets = new HashSet<>();
        HashSet<Long> curDevices = new HashSet<>();
        for (int i = 0; i < N; ++i) {
            curOutlets.add(outlets[i] & ((1L << p) - 1));
            curDevices.add(devices[i] & ((1L << p) - 1));
        }
        if (!curOutlets.equals(curDevices))
            return;
        if (p == L) {
            res = Math.min(res, changed);
        } else {
            go(p+1);
            ++changed;
            for (int i = 0; i < N; ++i)
                devices[i] ^= (1 << p);
            go(p+1);
            --changed;
            for (int i = 0; i < N; ++i)
                devices[i] ^= (1 << p);
        }
    }

    private long[] read(TokenizerReader in, int n, int l) {
        long[] res = new long[n];
        for (int i = 0; i < n; ++i) {
            String s = in.nextString();
            res[i] = Long.parseLong(s, 2);
        }
        return res;
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

