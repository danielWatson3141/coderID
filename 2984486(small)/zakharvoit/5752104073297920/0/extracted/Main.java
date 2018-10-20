import java.io.InputStreamReader;
import java.io.IOException;
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
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

        int sum = 0;

        if (n % 2 == 1) {
            n--;
        }
        for (int i = 0; i < n / 2; i++) {
            sum += a[i];
        }

        int sum2 = 0;
        for (int i = n / 2; i < n; i++) {
            sum2 += a[i];
        }

        out.print(ContestUtil.gcjTestNumber(testNumber));
        if (sum2 - sum > n / 3.5) {
            out.println("BAD");
        } else {
            out.println("GOOD");
        }
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

