import java.io.IOException;
import java.util.Locale;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.FilenameFilter;
import java.util.HashSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "A-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        int M = in.nextInt();
        String [] outlet = new String[N];
        String devices[ ] = new String[N];
        for(int i=0;i<N;i++) {
           outlet[i] = in.nextToken();
        }

        for(int i=0;i<N;i++) {
            devices[i] = in.nextToken();
        }

        // match for the first device
        int bestCount = Integer.MAX_VALUE;
        for(int i = 0;i<N;i++) {
            int curCount = 0;
            boolean swapped[] = new boolean[M];
            for(int j=0;j<M;j++) {
                 if(outlet[i].charAt(j) != devices[0].charAt(j)) {
                    swapped [j] = true;
                     ++curCount;
                 }
            }
            HashSet<String> outlets = new HashSet<String>();
            for(int j=0;j<N;j++) {
                if(j==i) continue;
                char[] out1 = outlet[j].toCharArray();
                for(int k=0;k<M;k++) {
                    if(swapped[k]) {
                        if(out1[k] == '0')
                            out1[k] = '1';
                        else out1[k] = '0';
                    }
                }
                outlets.add(String.valueOf(out1));
            }
            boolean good = true;
            for(int j=1;j<N;j++) {
                if(!outlets.contains(devices[j])) {
                     good = false;
                }
                else {
                    outlets.remove(devices[j]);
                }
            }
            if(good) {
                if(curCount<bestCount)
                    bestCount = curCount;
            }


        }
        if(bestCount != Integer.MAX_VALUE) {
            out.println("Case #"+testNumber+": "+bestCount);
        }
        else   out.println("Case #"+testNumber+": "+"NOT POSSIBLE");

    }
}

class InputReader {

    private InputStream stream;
    int curCharIndex = 0;
    int charsInBuf = 0;
     byte buf[] = new byte[16*1024];

    public InputReader(InputStream stream) {
        this.stream = stream;
    }


    public int readChar() {

        if (curCharIndex >= charsInBuf) {
            curCharIndex = 0;
            try {
                charsInBuf = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (charsInBuf <= 0)
                return -1;
        }
        return buf[curCharIndex++];
    }


    public int nextInt() {

        int c;
        do {
            c = readChar();
        }while(isWhitespace(c));

        int sign = 1;
        if (c == '-') {
            c = readChar();
            sign = -1;

        }
        int res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = readChar();
        } while (!isWhitespace(c) && c!=-1);
        return sign * res;
    }


    public String nextToken() {
        int c;
        do {
            c = readChar();
        }while(isWhitespace(c));

        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = readChar();
        } while (!isWhitespace(c) && c!=-1);
        return res.toString();
    }

    /*
    * For the purpose of compatibilty with Chelper Chrome extension
     */

    public String next() {
        return nextToken();
    }


    private boolean isWhitespace(int c) {
        return  c==' ' || c=='\n'|| c=='\r' || c=='\t';
    }
}


