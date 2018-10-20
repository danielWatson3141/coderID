import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Writer;
import java.util.StringTokenizer;
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
			inputStream = new FileInputStream("A-small-attempt1.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("A-small.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt(), L = in.nextInt(), i, j;
        char current[][] = new char[n][L], req[][] = new char[n][L];
        for(i=0;i<n;i++) {
            current[i] = in.next().toCharArray();
        }
        String R[] = new String[n], C[] = new String[n];
        for(i=0;i<n;i++) {
            R[i] = in.next();
            req[i] = R[i].toCharArray();

        }
        Arrays.sort(R);
        /*graph = new boolean[n][L]; // The basic graph
        assignedToApplicant = new int[L]; // A job i is assigned to which applicant
        Arrays.fill(assignedToApplicant, -1); // Initally none of the jobs are assigned
        visited = new boolean[L]; // This basically is reset for every candidate and stores if a candidate has seen this job
        int result = 0;
        for(i=0;i<n;i++) {
            for(j=0;j<L;j++) {
                if(current[i].charAt(j))
            }
        }
        for(i=0;i<n;i++) {
            //For every person, find a job
            Arrays.fill(visited, false);
            if(dfs(i)) {
                result++;
            }
        } */
        int ans = Integer.MAX_VALUE;
        for(i=(1<<L) - 1;i>=0;i--) {
            String s = Integer.toBinaryString(i);
            while (s.length()<L)
                s = "0" + s;
            int c = 0;
            for(j=0;j<L;j++) {
                if(s.charAt(j) == '1') {
                    for(int k=0;k<n;k++) {
                        if(current[k][j] == '0') {
                            current[k][j] = '1';
                        }
                        else current[k][j] = '0';
                    }
                    c++;
                }
            }
            for(j=0;j<n;j++) {
                String p="";
                for(int k=0;k<L;k++) {
                    p += current[j][k];
                }
                C[j] = p;
            }
            Arrays.sort(C);
            boolean match = true;
            for(j=0;j<n;j++) {
                if(C[j].compareTo(R[j]) != 0) {
                    match = false;
                    break;
                }
            }
            if(match) {
                ans = Math.min(ans, c);
            }
            for(j=0;j<L;j++) {
                if(s.charAt(j) == '1') {
                    for(int k=0;k<n;k++) {
                        if(current[k][j] == '0') {
                            current[k][j] = '1';
                        }
                        else current[k][j] = '0';
                    }
                    c++;
                }
            }
        }
        //DebugUtils.print("Finished case"+testNumber);
        out.print("Case #"+testNumber+": ");
        if(ans < Integer.MAX_VALUE) {
            out.printLine(ans);
        }
        else out.printLine("NOT POSSIBLE");

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

