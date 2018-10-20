import java.io.IOException;
import java.util.Arrays;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.TreeSet;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Shamir14 (amirhossein.shapoori@gmail.com)
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
		Taskk solver = new Taskk();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class Taskk {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.readInt();
        int l = in.readInt();
        String[] outLet = new String[n];
        for (int i = 0; i < n; i++) {
            outLet[i] = in.next();
        }
        String[] dest = new String[n];
        for (int i = 0; i < n; i++) {
            dest[i] = in.readString();
        }
        Arrays.sort(dest);
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            TreeSet<String> treeSet = new TreeSet<String>();
            int[] pat = machCase(outLet[0], dest[i]);
            int temp = getOne(pat);
            treeSet.add(dest[i]);
            for (int j = 1; j < n; j++) {
                String build = getString(outLet[j], pat);
                treeSet.add(build);
            }
            boolean ok = true;
            int j = 0;
            for (String s : treeSet) {
                if(!dest[j].equals(s)) {
                    ok = false;
                    break;
                }
                j++;
            }
            if(ok) {
                ans = Math.min(ans, temp);
            }
        }
        out.printLine("Case #" + testNumber + ": " + (ans == Integer.MAX_VALUE ? "NOT POSSIBLE" : ans));
    }

    private int[] machCase(String a, String b) {
        int[] ret = new int[a.length()];
        for (int i = 0; i < a.length(); i++) {
            if(a.charAt(i) != b.charAt(i))
                ret[i] = 1;
        }
        return ret;
    }

    String getString(String a, int[] pattern) {
        String b = "";
        for (int i = 0; i < a.length(); i++) {
            if(pattern[i] == 0) {
                b += a.charAt(i);
            }
            else {
                b += (char)('1' - a.charAt(i) + '0');
            }
        }
        return b;
    }

    int getOne(int[] patt) {
        int cnt = 0;
        for (int i : patt) {
            cnt += i;
        }
        return cnt;
    }

}

class InputReader {
    // this IO reading - writing is provided by Egor Kulikov
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new UnknownError();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new UnknownError();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }


    public boolean hasNext(){
        return peek()!=-1;
    }

    public int peek() {
        if (numChars == -1)
            return -1;
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                return -1;
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar];
    }

    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new UnknownError();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public long readLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new UnknownError();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public String readString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuffer res = new StringBuffer();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
        return res.toString();
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    private String readLine0() {
        StringBuffer buf = new StringBuffer();
        int c = read();
        while (c != '\n' && c != -1) {
            if (c != '\r')
                buf.appendCodePoint(c);
            c = read();
        }
        return buf.toString();
    }

    public String readLine() {
        String s = readLine0();
        while (s.trim().length() == 0)
            s = readLine0();
        return s;
    }

    public String readLine(boolean ignoreEmptyLines) {
        if (ignoreEmptyLines)
            return readLine();
        else
            return readLine0();
    }

    public BigInteger readBigInteger() {
        try {
            return new BigInteger(readString());
        } catch (NumberFormatException e) {
            throw new UnknownError();
        }
    }

    public char readCharacter() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        return (char) c;
    }

    public double readDouble() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!isSpaceChar(c) && c != '.') {
            if (c == 'e' || c == 'E')
                return res * Math.pow(10, readInt());
            if (c < '0' || c > '9')
                throw new UnknownError();
            res *= 10;
            res += c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!isSpaceChar(c)) {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, readInt());
                if (c < '0' || c > '9')
                    throw new UnknownError();
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
        return res * sgn;
    }

    public boolean isExhausted() {
        int value;
        while (isSpaceChar(value = peek()) && value != -1)
            read();
        return value == -1;
    }

    public String next() {
        return readString();
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(outputStream);
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

    public void printLine(char[] array) {
        writer.println(array);
    }

    public void printFormat(String format, Object...objects) {
        writer.printf(format, objects);
    }

    public void close() {
        writer.close();
    }

    public void flush() {
        writer.flush();
    }
}

