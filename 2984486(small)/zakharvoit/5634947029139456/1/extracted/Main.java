import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;
import java.util.InputMismatchException;
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
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int l = in.nextInt();
        long[] outlet = new long[n];
        for (int i = 0; i < n; i++) {
            String inp = in.nextToken();
            for (int j = 0; j < inp.length(); j++) {
                if (inp.charAt(j) == '1') {
                    outlet[i] |= 1L << j;
                }
            }
        }

        long[] devices = new long[n];
        for (int i = 0; i < n; i++) {
            String inp = in.nextToken();
            for (int j = 0; j < inp.length(); j++) {
                if (inp.charAt(j) == '1') {
                    devices[i] |= 1L << j;
                }
            }
        }

        Arrays.sort(devices);
        int ans = Integer.MAX_VALUE;

        for (int q = 0; q < n; q++) {
            for (int w = 0; w < n; w++) {
                long mask = 0;
                int cnt = 0;
                for (int bit = 0; bit < l; bit++) {
                    if ((devices[q] & (1L << bit)) != (outlet[w] & (1L << bit))) {
                        mask |= 1L << bit;
                        cnt++;
                    }
                }
                if (cnt > ans) {
                    continue;
                }
                long[] newOuts;
                newOuts = outlet.clone();

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < l; j++) {
                        if ((mask & (1L << j)) != 0) {
                            newOuts[i] ^= (1L << j);
                        }
                    }
                }
                Arrays.sort(newOuts);
                boolean ok = true;
                for (int i = 0; i < n; i++) {
                    if (newOuts[i] != devices[i]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    ans = Math.min(ans, cnt);
                }
            }
        }
        out.println(ContestUtil.gcjTestNumber(testNumber) + (ans == Integer.MAX_VALUE
                ? "NOT POSSIBLE" : ans));
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

