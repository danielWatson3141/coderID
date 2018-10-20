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

        ProbB solver = new ProbB();
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            solver.solve(i+1, in, out);
        }
        out.close();
    }
}

class ProbB {
	public void solve(int testNumber, InputReader in, PrintWriter out) throws Exception {
		out.print("Case #" + testNumber + ": ");
		int N = in.nextInt();
		ArrayList<ArrayList<Integer>> adjs = new ArrayList<>();
		for (int i = 0; i < N; i++) adjs.add(new ArrayList<Integer>());
		for (int i = 0; i < N-1; i++) {
			int x = in.nextInt()-1;
			int y = in.nextInt()-1;
			adjs.get(x).add(y);
			adjs.get(y).add(x);
		}
		int[] dp = new int[N];
		dpc = new int[N];
		
		int ret = 1000000;
		for (int i = 0; i < N; i++) {
			Arrays.fill(dp, -1);
			Arrays.fill(dpc, -1);
			ret = Math.min(ret, go(i, adjs, -1, dp));
		}
		out.println(ret);
	}
	
	private int go(int cur, ArrayList<ArrayList<Integer>> adjs, int parent, int[] dp) {
		if (dp[cur] > -1) return dp[cur];
		ArrayList<Integer> adj = adjs.get(cur);
		int childcount = adj.size();
		if (parent > -1) childcount--;
		if (childcount == 0) return dp[cur] = 0;
		else if (childcount == 1) {
			int next = adj.get(0);
			if (next == parent) next = adj.get(1);
			return dp[cur] = count(next, adjs, cur);
		}
		int[] survive = new int[childcount];
		int pos = 0;
		int sum = 0;
		for (int a: adj) {
			if (a == parent) continue;
			survive[pos] += count(a, adjs, cur);
			sum += survive[pos];
			survive[pos] -= go(a, adjs, cur, dp);
			pos++;
		}
		Arrays.sort(survive);
		return dp[cur] = sum - survive[pos-1] - survive[pos-2];
	}
	
	int[] dpc;
	private int count(int cur, ArrayList<ArrayList<Integer>> adjs, int parent) {
		if (dpc[cur] > -1) return dpc[cur];
		int ret = 1;
		ArrayList<Integer> adj = adjs.get(cur);
		for (int a:adj) {
			if (a == parent) continue;
			ret += count(a, adjs, cur);
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