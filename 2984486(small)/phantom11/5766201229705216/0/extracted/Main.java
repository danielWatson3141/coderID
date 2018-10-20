import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Writer;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Collection;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Lokesh Khandelwal
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("B-small-attempt0.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("B-small.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    boolean visited[];
    List<Integer> graph[];
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt(), i, j;
        graph = new List[n];
        visited = new boolean[n];
        for(i=0;i<n;i++) {
            graph[i] = new ArrayList();
        }
        for(i=0;i<n-1;i++) {
            int a = in.nextInt() - 1, b = in.nextInt() - 1;
            graph[a].add(b);
            graph[b].add(a);
        }
        int ans = n;
        for(i=(1<<n)-1;i>=0;i--) {
            String s = Integer.toBinaryString(i);
            while (s.length() < n) {
                s = "0" + s;
            }

            for(int root = 0;root<n;root++) {
                if(s.charAt(root) == '0') continue;
                Arrays.fill(visited, false);
                for(j=0;j<n;j++) {
                    if(s.charAt(j)=='0') {
                        visited[j] = true;
                    }
                }
                Queue<Integer> queue = new LinkedList<Integer>();

                visited[root] = true;
                queue.add(root);
                boolean status = true;
                while (!queue.isEmpty()) {
                    int x = queue.poll(), p, c = 0;
                    for(j=graph[x].size()-1;j>=0;j--) {
                        p = graph[x].get(j);
                        if(!visited[p]) {
                            visited[p] = true;
                            queue.add(p);
                            c++;
                        }
                    }
                    if(c == 0 || c == 2) {

                    }
                    else {
                        status = false;
                        break;
                    }
                }
                for(j=0;j<n;j++) {
                    if(!visited[j]) {
                        status = false;
                        break;
                    }
                }
                if(status) {

                    int c = 0;
                    for(j=0;j<n;j++) {

                        if(s.charAt(j) == '0')
                            c++;
                    }
                    
                    ans = Math.min(ans, c);
                    break;
                }
            }
        }
        out.printLine("Case #"+testNumber+": "+ans);
    }

}

class InputReader
{
    BufferedReader in;
    StringTokenizer tokenizer=null;

    public InputReader(InputStream inputStream)
    {
        in=new BufferedReader(new InputStreamReader(inputStream));
    }
    public String next()
    {
        try{
            while (tokenizer==null||!tokenizer.hasMoreTokens())
            {
                tokenizer=new StringTokenizer(in.readLine());
            }
            return tokenizer.nextToken();
        }
        catch (IOException e)
        {
            return null;
        }
    }
    public int nextInt()
    {
        return Integer.parseInt(next());
    }
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}
}

