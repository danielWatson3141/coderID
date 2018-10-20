import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.HashSet;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author RiaD
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			final String regex = "A-.*.in";
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
			outputStream = new FileOutputStream("chaos.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Reader in = new Reader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		ChargingChaos solver = new ChargingChaos();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class ChargingChaos {
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int l = in.nextInt();

        String[] a = in.nextStringArray(n);
        String[] b = in.nextStringArray(n);



        int best = l + 1;
        for(int i = 0; i < n; ++i) {
            boolean[] change = new boolean[l];
            for(int j = 0; j < l; ++j) {
                change[j] = a[0].charAt(j) != b[i].charAt(j);
            }
            HashSet<String> have = new HashSet<String>();
            HashSet<String> need = new HashSet<String>();
            for (String s : b) {
                need.add(s);
            }
            for (String s : a) {
                StringBuffer sb = new StringBuffer(s);
                for(int j = 0; j < l; ++j) {
                    if(change[j])
                        sb.setCharAt(j, (char) ('0' + '1' - sb.charAt(j)));
                }
                have.add(sb.toString());
            }

            if(have.equals(need)) {
                int currentChange = 0;
                for (boolean bool : change) {
                    if(bool)
                        ++currentChange;
                }
                best = Math.min(best, currentChange);
            }
        }
        out.print("Case #" + testNumber + ": ");
        if(best > l) {
            out.println("NOT POSSIBLE");
        }
        else
            out.println(best);
    }
}

class Reader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Reader(BufferedReader reader) {
        this.reader = reader;
    }

    public Reader(InputStream stream) {
        this(new BufferedReader(new InputStreamReader(stream)));
    }

    public String nextString() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public String next() {
        return nextString();
    }

    public String[] nextStringArray(int size) {
        String[] array = new String[size];
        for (int i = 0; i < size; ++i) {
            array[i] = nextString();
        }
        return array;
    }

    private String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

class OutputWriter extends PrintWriter {

	public OutputWriter(OutputStream out) {
		super(out);
	}

	public OutputWriter(Writer writer){
		super(writer);
	}

}

