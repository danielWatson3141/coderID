import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class A {

	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;
	
	public static void main(String[] args) throws IOException{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int test = nextInt();
		for (int t = 1; t <= test; t++) {
			pw.print("Case #"+t+": ");
			int n = nextInt();
			int L = nextInt();
			char[][]a = new char[n][L], b = new char[n][L];
			for (int i = 0; i < n; i++) {
				a[i] = next().toCharArray();
			}
			for (int i = 0; i < n; i++) {
				b[i] = next().toCharArray();
			}
			int INF = (int) 1e9;
			int ans = INF;
			char[][]c = new char[n][L];
			boolean[]used = new boolean[1 << L];
			for (int mask = 0; mask < (1 << L); mask++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < L; j++) {
						c[i][j] = a[i][j];
					}
				}
				for (int i = 0; i < L; i++) {
					if ((mask & (1 << i)) != 0) {
						for (int k = 0; k < n; k++) {
							if (c[k][i]=='0')
								c[k][i] = '1';
							else
								c[k][i] = '0';
						}
					}
				}
				Arrays.fill(used, false);
				for (int i = 0; i < n; i++) {
					int s = 0;
					for (int j = 0; j < L; j++) {
						if (c[i][j]=='1')
							s += (1 << j);
					}
					used[s] = true;
				}
				boolean ok = true;
				
				for (int i = 0; i < n; i++) {
					int s = 0;
					for (int j = 0; j < L; j++) {
						if (b[i][j]=='1')
							s += (1 << j);
					}
					if (!used[s])
						ok = false;
				}
				if (ok) {
					ans = Math.min(ans, Integer.bitCount(mask));
				}
			}
			if (ans==INF)
				pw.println("NOT POSSIBLE");
			else
				pw.println(ans);
		}
		pw.close();
	}

	private static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	private static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	private static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	private static String next() throws IOException{
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

}
