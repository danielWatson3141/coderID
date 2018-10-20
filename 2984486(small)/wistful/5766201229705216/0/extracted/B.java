import java.io.*;
import java.util.*;

public class B {

    List<Integer>[] l;

    int dfs(int v, int p) {
        int b1 = 0;
        int b2 = 0;
        for (int u : l[v]) {
            if (u != p) {
                int res = dfs(u, v);
                if (res > b1) {
                    if (b1 > b2) {
                        b2 = b1;
                    }
                    b1 = res;
                } else if (res > b2) {
                    b2 = res;
                }
            }
        }
        if (b2 == 0) {
            return 1;
        }
        return b1 + b2 + 1;
    }

    void solve() throws IOException {
        in = new InputReader("B-small-attempt0.in");
        out = new OutputWriter("B-small-attempt0.out");

        int testCount = in.readInt();
        for (int test = 1; test <= testCount; ++test) {
            int n = in.readInt();
            l = new ArrayList[n];
            for (int i = 0; i < n; ++i) {
                l[i] = new ArrayList<Integer>();
            }
            for (int i = 0; i < n - 1; ++i) {
                int x = in.readInt() - 1;
                int y = in.readInt() - 1;
                l[x].add(y);
                l[y].add(x);
            }
            int best = 0;
            for (int r = 0; r < n; ++r) {
                int res = dfs(r, -1);
                if (res > best) {
                    best = res;
                }
            }
            out.println("Case #" + test + ": " + (n - best));
        }

        exit();
    }

    void exit() {
        //System.err.println((System.currentTimeMillis() - startTime) + " ms");
        out.close();
        System.exit(0);
    }

    InputReader in;
    OutputWriter out;

    //long startTime = System.currentTimeMillis();

    public static void main(String[] args) throws IOException {
        new B().solve();
    }

    class InputReader {

        private InputStream stream;

        private byte[] buffer = new byte[1024];
        private int pos, len;

        private int cur;

        private StringBuilder sb = new StringBuilder(32);

        InputReader(String name) throws IOException {
            if (name.equals("__std")) {
                stream = System.in;
            } else {
                stream = new FileInputStream(name);
            }
            cur = read();
        }

        private int read() throws IOException {
            if (len == -1) {
                throw new EOFException();
            }
            if (pos >= len) {
                pos = 0;
                len = stream.read(buffer);
                if (len == -1) return -1;
            }
            return buffer[pos++];
        }

        char readChar() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            char res = (char) cur;
            cur = read();
            return res;
        }

        int readInt() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            while (whitespace()) {
                cur = read();
            }
            if (cur == -1) {
                throw new EOFException();
            }
            int sign = 1;
            if (cur == '-') {
                sign = -1;
                cur = read();
            }
            int res = 0;
            while (!whitespace()) {
                if (cur < '0' || cur > '9') {
                    throw new NumberFormatException();
                }
                res *= 10;
                res += cur - '0';
                cur = read();
            }
            return res * sign;
        }

        long readLong() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            return Long.parseLong(readToken());
        }

        double readDouble() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            return Double.parseDouble(readToken());
        }

        String readLine() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            sb.setLength(0);
            while (cur != -1 && cur != '\r' && cur != '\n') {
                sb.append((char) cur);
                cur = read();
            }
            if (cur == '\r') {
                cur = read();
            }
            if (cur == '\n') {
                cur = read();
            }
            return sb.toString();
        }

        String readToken() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            while (whitespace()) {
                cur = read();
            }
            if (cur == -1) {
                throw new EOFException();
            }
            sb.setLength(0);
            while (!whitespace()) {
                sb.append((char) cur);
                cur = read();
            }
            return sb.toString();
        }

        boolean whitespace() {
            return cur == ' ' || cur == '\t' || cur == '\r' || cur == '\n' || cur == -1;
        }

        boolean eof() {
            return cur == -1;
        }
    }

    class OutputWriter {

        private PrintWriter writer;

        OutputWriter(String name) throws IOException {
            if (name.equals("__std")) {
                writer = new PrintWriter(System.out);
            } else {
                writer = new PrintWriter(name);
            }
        }

        void print(String format, Object ... args) {
            writer.print(new Formatter(Locale.US).format(format, args));
        }

        void println(String format, Object ... args) {
            writer.println(new Formatter(Locale.US).format(format, args));
        }

        void print(Object value) {
            writer.print(value);
        }

        void println(Object value) {
            writer.println(value);
        }

        void println() {
            writer.println();
        }

        void close() {
            writer.close();
        }
    }
}
