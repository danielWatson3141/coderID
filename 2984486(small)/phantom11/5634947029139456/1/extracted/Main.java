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
			outputStream = new FileOutputStream("A-large.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskALarge solver = new TaskALarge();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskALarge {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt(), m = in.nextInt(), i, j;
        String current[] = new String[n], req[] = new String[n];
        char C[][] = new char[n][m], R[][] = new char[n][m];
        for(i=0;i<n;i++) {
            current[i] = in.next();
            C[i] = current[i].toCharArray();
        }
        for(i=0;i<n;i++) {
            req[i] = in.next();
            R[i] = req[i].toCharArray();
        }
        Arrays.sort(current);
        Arrays.sort(req);
        
        int flip[] = new int[m];
        out.print("Case #"+testNumber+": ");
        int ans = Integer.MAX_VALUE, k;
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                int c = 0;
                Arrays.fill(flip, 0);
                for(k=0;k<m;k++) {
                    if(C[i][k] != R[j][k]) {
                        c++;
                        flip[k] = 1;
                    }
                }
                String cur[] = new String[n];
                for(int p=0;p<n;p++) {
                    StringBuilder s = new StringBuilder("");
                    for(k=0;k<m;k++) {
                        if(flip[k] == 1) {
                            if(C[p][k] == '0')
                                s.append('1');
                            else s.append('0');
                        }
                        else s.append(C[p][k]);
                    }
                    cur[p] = s.toString();
                }
                Arrays.sort(cur);
                
                boolean status = true;
                for(k=0;k<n;k++) {
                    if(!cur[k].equals(req[k])) {
                        status = false;
                        break;
                    }
                }
                if(status) {
                    ans = Math.min(ans, c);
                }
            }
        }
        if(ans < Integer.MAX_VALUE)
            out.printLine(ans);
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

