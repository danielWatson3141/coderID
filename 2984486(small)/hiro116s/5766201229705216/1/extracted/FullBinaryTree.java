
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;

public class FullBinaryTree {
	FastScanner in = new FastScanner(System.in);
	PrintWriter out = new PrintWriter(System.out);
	Integer[][] edge;
	int[][] dp = new int[1005][1005];
	int[][] cnt = new int[1005][1005];
	
	int childCount(int parent, int target) {
		int res = 0;
		for (int i = 0; i < edge[target].length; i++) {
			if (edge[target][i] != parent) res++;
		}
		
		return res;
	}
	
	int count(int parent, int target) {
		if (cnt[parent][target] != -1) return cnt[parent][target];
		
		int res = 1;
		for (int i = 0; i < edge[target].length; i++) {
			if (edge[target][i] != parent)
				res += count(target, edge[target][i]);
		}
		return cnt[parent][target] = res;
	}
	
	int rec(int parent, int target) {
		if (dp[parent][target] != -1) return dp[parent][target];
		
		int childNum = childCount(parent, target);
		if (childNum == 0) {
			return dp[parent][target] = 0;
		} else if (childNum == 1) {
			int x = (edge[target][0] != parent) ? edge[target][0] : edge[target][1];
			return dp[parent][target] = count(target, x);
		} else if (childNum == 2) {
			int res = 0;
			for (int i = 0; i < edge[target].length; i++) {
				if (edge[target][i] != parent) {
					res += rec(target, edge[target][i]);
				}
			}
			return dp[parent][target] = res;
		} else if (childNum >= 3) {
			int[] a = new int[childNum];
			int[] b = new int[childNum];
			
			for (int i = 0, index = 0; i < edge[target].length; i++) {
				if (edge[target][i] != parent) {
					a[index] = rec(target, edge[target][i]);
					b[index++] = count(target, edge[target][i]);
				}
			}
			
			int res = 0;
			for (int i = 0; i < a.length; i++) {
				res += a[i];
				b[i] -= a[i];
			}
			Arrays.sort(b);
			for (int i = 0; i < childNum - 2; i++) {
				res += b[i];
			}
			
			return dp[parent][target] = res;
		}
		
		return 0;
	}
	
	public void run() {
		int T = in.nextInt();
		for (int times = 1; times <= T; times++) {
			int res = Integer.MAX_VALUE;
			int N = in.nextInt();
			
			for (int i = 0; i < dp.length; i++) {
				Arrays.fill(dp[i], -1);
				Arrays.fill(cnt[i], -1);
			}
			
			ArrayList<Integer>[] in_edges = new ArrayList[N+1];
			for (int i = 0; i < in_edges.length; i++) {
				in_edges[i] = new ArrayList<Integer>();
			}
			
			for (int i = 0; i < N - 1; i++) {
				int nodeA = in.nextInt(), nodeB = in.nextInt();
				in_edges[nodeA].add(nodeB);
				in_edges[nodeB].add(nodeA);
			}
			
			edge = new Integer[N+1][];
			for (int i = 0; i < edge.length; i++) {
				edge[i] = in_edges[i].toArray(new Integer[0]);
			}
			
			for (int start = 1; start <= N; start++) {
				//"N+1" means that there is no parent. That is, start node is root.
				res = Math.min(res, rec(N+1, start));
			}
			
			out.println("Case #" + times + ": " + res);
			/*
			for (int i = 1; i < edge.length; i++) {
				for (int j = 0; j < edge[i].length; j++) {
					System.out.print(edge[i][j] + " ");
				}
				System.out.println();
			}
			System.out.println();
			*/
		}
		out.close();
	}

	public static void main(String[] args) {
		new FullBinaryTree().run();
	}

	class FastScanner {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;

		public FastScanner(InputStream stream) {
			this.stream = stream;
			//stream = new FileInputStream(new File("dec.in"));

		}

		int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		boolean isEndline(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		String nextLine() {
			int c = read();
			while (isEndline(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isEndline(c));
			return res.toString();
		}
	}
}

