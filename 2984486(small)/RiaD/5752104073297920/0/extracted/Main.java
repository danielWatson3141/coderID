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
import java.util.Random;
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
			final String regex = "C-.*.in";
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
            System.err.println(toRun);
            inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("propershuffle.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Reader in = new Reader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		ProperShuffle solver = new ProperShuffle();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class ProperShuffle {
    public void solve(int testNumber, Reader in, OutputWriter out) {

        int n = in .nextInt();
        int[] a = in.nextIntArray(n);
        out.println("Case #" + testNumber + ": " + (res(a) ? "GOOD" : "BAD"));
        if(true)
            return;

        int ok = 0;
        for(int i = 0; i < 120; ++i) {
            boolean x = RANDOM.nextBoolean();
            int [] input = gen(1000, x);
            if(x == res(input))
                ++ok;
        }
        out.println(ok);
        if(true)
            return;


        for(int i = 0; i < 20; ++i) {
            int [] input = gen(1000, true);
            out.println(eval(input) / 1.0);
        }
    }
    public static Random RANDOM = new Random();

    boolean res(int[] a) {
        return eval(a) < 1.7E11;
    }

    long eval(int [] a) {
        long cur = 0;
        int n = a.length;
        for(int i = 0; i < n; ++i) {
            cur += 1L * i * a[i] * a[i];
        }
        return cur;
    }

    int[] gen(int len, boolean good) {
        int[] res = new int[len];
        for(int i = 0; i < len; ++i) {
            if(good)
                res[i] = RANDOM.nextInt(len - i) + i;
            else
                res[i] = RANDOM.nextInt(len);
        }
        return go(res);
    }

    int[] go(int[] random) {
        int[] permutation = new int[random.length];
        for(int i = 0; i < random.length; ++i)
            permutation[i] = i;
        for(int i = 0; i < random.length; ++i) {
            int j = random[i];
            int tmp = permutation[i];
            permutation[i] = permutation[j];
            permutation[j] = tmp;
        }
        return permutation;
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

    public int[] nextIntArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = nextInt();
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

