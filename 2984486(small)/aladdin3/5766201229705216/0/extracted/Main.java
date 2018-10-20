import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Mahmoud Aladdin <aladdin3>
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
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
    public void solve(int testNumber, InputReader jin, OutputWriter jout) {
        int n = jin.int32();

        int[] a = new int[n];
        int[] b = new int[n];
        for(int i = 0; i < n - 1; i++) {
            a[i] = jin.int32() - 1;
            b[i] = jin.int32() - 1;
        }

        int remove = Integer.MAX_VALUE;
        for(int i = 0; i < (1 << n); i++) {
            int[] deg = new int[n]; Arrays.fill(deg, 0);
            UnionFind uf = new UnionFind(n);
            int mx = 0;
            for(int j = 0; j < n - 1; j++) {
                if((i & (1 << a[j])) > 0) continue;
                if((i & (1 << b[j])) > 0) continue;
                uf.union(a[j], b[j]);
                deg[a[j]]++; deg[b[j]]++;
                mx = Math.max(mx, Math.max(deg[a[j]], deg[b[j]]));
            }
            boolean valid = true; int p = -1;
            for(int k = 0; k < n; k++) {
                if((k & (1 << i)) > 0) {
                    if(p == -1) p = uf.find(k);
                    valid &= uf.isConnected(p, k);
                }
            }
            if(valid) {
                int[] cd = new int[mx + 1];
                for(int k = 0; k < n; k++) {
                    if((i & (1 << k)) == 0) {
                        cd[deg[k]]++;
                    }
                }
                if(mx < 2) {
                    int sum = 0; for(int k = 1; k <= mx; k++) sum += cd[k];
                    valid = cd[0] == 1 && sum == 0;
                } else {
                    int sum = cd[0]; for(int k = 4; k <= mx; k++) sum += cd[k];
                    valid = cd[2] == 1 && sum == 0;
                }
            }
            if(valid) {
                remove = Math.min(remove, Integer.bitCount(i));
            }
        }
        jout.println("Case #" + testNumber + ":", remove);
    }
}

class InputReader {
    private static final int bufferMaxLength = 1024;
    private InputStream in;
    private byte[] buffer;
    private int currentBufferSize;
    private int currentBufferTop;
    private static final String tokenizers = " \t\r\f\n";
    
    public InputReader(InputStream stream) {
        this.in = stream;
        buffer = new byte[bufferMaxLength];
        currentBufferSize = 0;
        currentBufferTop = 0;
    }
    
    private boolean refill() {
        try {
            this.currentBufferSize = this.in.read(this.buffer);
            this.currentBufferTop = 0;
        } catch(Exception e) {}
        return this.currentBufferSize > 0;
    }
    
    
    private Byte readChar() {
        if(currentBufferTop < currentBufferSize) {
            return this.buffer[this.currentBufferTop++];
        } else {
            if(!this.refill()) {
                return null;
            } else {
                return readChar();
            }
        }
    }

    public String next() {
        return token();
    }
    
    public String token()  {
        StringBuffer tok = new StringBuffer();
        Byte first;
        while((first = readChar()) != null && (tokenizers.indexOf((char) first.byteValue()) != -1));
        if(first == null) return null;
        tok.append((char)first.byteValue());
        while((first = readChar()) != null && (tokenizers.indexOf((char) first.byteValue()) == -1)) {
            tok.append((char)first.byteValue());
        }
        return tok.toString();
    }
    
    public Integer int32() throws NumberFormatException {
        String tok = token();
        return tok == null? null : Integer.parseInt(tok);
    }

    }

class OutputWriter {
    private final int bufferMaxOut = 1024;
    private PrintWriter out;
    private StringBuilder output;
    private boolean forceFlush = false;

    public OutputWriter(OutputStream outStream) {
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outStream)));
        output = new StringBuilder(2 * bufferMaxOut);
    }

    public OutputWriter(Writer writer) {
        forceFlush = true;
        out = new PrintWriter(writer);
        output = new StringBuilder(2 * bufferMaxOut);
    }

    private void autoFlush() {
        if(forceFlush || output.length() >= bufferMaxOut) {
            flush();
        }
    }

    public void print(Object... tokens) {
        for(int i = 0; i < tokens.length; i++) {
            if(i != 0) output.append(' ');
            output.append(tokens[i]);
        }
        autoFlush();
    }

    public void println(Object... tokens) {
        print(tokens);
        output.append('\n');
        autoFlush();
    }

    public void flush() {
        out.print(output);
        output.setLength(0);
    }

    public void close() {
        flush();
        out.close();
    }
}

class UnionFind {
    private int[] parent;

    public UnionFind(int size) {
        parent = new int[size];
        for(int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    public void union(int a, int b) {
        this.parent[this.find(a)] = this.find(b);
    }

    public int find(int id) {
        if(this.parent[id] != id)
            this.parent[id] = find(this.parent[id]);
        return this.parent[id];
    }

    public boolean isConnected(int a, int b) {
        return this.find(a) == this.find(b);
    }
}

