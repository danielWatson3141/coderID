package codejam2014;

import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) throws Exception {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        ProbA solver = new ProbA();
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            solver.solve(i+1, in, out);
        }
        out.close();
    }
}

class ProbA {
	public void solve(int testNumber, InputReader in, PrintWriter out) throws Exception {
		out.print("Case #" + testNumber + ": ");
		int N = in.nextInt();
		int L = in.nextInt();
		String init[] = new String[N];
		TreeSet<String> target = new TreeSet<>();
		for (int i = 0; i < N; i++) {
			init[i] = in.next();
		}
		for (int i = 0; i < N; i++) {
			target.add(in.next());
		}
		int ret = L+1;
		for (int i = 0; i < (1<<L); i++) {
			boolean match = true;
			for (int j = 0; j < N; j++) {
				StringBuffer sb = new StringBuffer();
				for (int k = 0; k < L; k++) {
					int bit = init[j].charAt(k) - '0';
					if (((1<<k)&i) == 0) {
						sb.append(bit);
					} else {
						sb.append(bit^1);
					}
				}
				if (!target.contains(sb.toString())) {
					match = false;
					break;
				}
			}
			if (match) {
				ret = Math.min(ret, bitcount(i));
			}
		}
		if (ret > L) {
			out.println("NOT POSSIBLE");
		} else {
			out.println(ret);
		}
	}
	private int bitcount(int set) {
		int ret = 0;
		for (int i = 0; i < 30; i++) {
			if (((1<<i)&set) > 0) {
				ret++;
			}
		}
		return ret;
	}
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
    
    public long nextLong() {
        return Long.parseLong(next());
    }
}