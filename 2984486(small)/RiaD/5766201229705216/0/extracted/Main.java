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
import java.util.ArrayList;
import java.util.Collections;
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
			final String regex = "B-.*.in";
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
			outputStream = new FileOutputStream("fullbinarytree.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Reader in = new Reader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		FullBinaryTree solver = new FullBinaryTree();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class FullBinaryTree {
    private int deleted;

    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        ArrayList<Integer>[] graph = new ArrayList[n];
        for(int i = 0; i < n; ++i) {
            graph[i] = new ArrayList<Integer>();
        }
        for(int i = 0; i < n - 1; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            graph[x].add(y);
            graph[y].add(x);
        }

        int answer = n - 1;

        for(int i = 0; i < n; ++i) {
            deleted = 0;
            rec(graph, i, -1);

            answer = Math.min(answer, deleted);
        }
        out.println("Case #" + testNumber + ": " + answer);
    }

    private int rec(ArrayList<Integer>[] graph, int v, int p) {

        ArrayList<Integer> sizes = new ArrayList<Integer>();
        for (int to : graph[v]) {
            if(to != p)
                sizes.add(rec(graph, to, v));
        }
        if(sizes.isEmpty())
            return 1;
        if(sizes.size() == 1) {
            deleted += sizes.get(0);
            return 1;
        }
        Collections.sort(sizes, Collections.reverseOrder());
        for(int i = 2; i < sizes.size(); ++i) {
            deleted += sizes.get(i);
        }
        return 1 + sizes.get(0) + sizes.get(1);
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

