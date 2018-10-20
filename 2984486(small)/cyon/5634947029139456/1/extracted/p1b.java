
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;
import java.util.StringTokenizer;


public class p1b {

	public static void debug(Object...args) {
		System.out.println(Arrays.deepToString(args));
	}
	
	public static void main(String...args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		solve(br, pw);
	}

	private static void solve(BufferedReader br, PrintWriter pw) throws Exception {
		int cases = Integer.parseInt(br.readLine());
		for (int c = 1; c <= cases; c++) {
			pw.printf("Case #%d: %s\n", c, solveCase(br, pw));
		}
	}

	private static Object solveCase(BufferedReader br, PrintWriter pw) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());
		String[]o = new String[N];
		String[]d = new String[N];
		st = new StringTokenizer(br.readLine());
		for (int i=0;i<N;i++) {
			o[i] = st.nextToken();
		}
		st = new StringTokenizer(br.readLine());
		for (int i=0;i<N;i++) {
			d[i] = st.nextToken();
		}
		
		
		int milen = L+1;
		
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				String p = need(o[i], d[j]);

				StringBuilder[] no = trans(o, i, p);

				Set<String> nout = new HashSet<>();
				for (int k = 0; k < N; k++) {
					nout.add(no[k].toString());
				}
				// debug(nout, Integer.toBinaryString(i));
				boolean ok = true;
				for (int k = 0; k < N; k++) {
					if (!nout.contains(d[k])) {
						ok = false;
						break;
					} else {
						nout.remove(d[k]);
					}
				}
				if (ok) {
					milen = Math.min(milen, flen(p));
				}
			}
		}
		
		
		return (milen == L+1) ? "NOT POSSIBLE" : milen;
	}

	private static int flen(String p) {
		int flen = 0;
		int N = p.length();
		for (int j = 0; j<N;j++) {
			if (p.charAt(j) == '1') flen++;
		}
		return flen;
	}

	private static StringBuilder[] trans(String[] o, int i, String p) {
		int N = o.length;
		int L = p.length();
		StringBuilder []no = new StringBuilder[N];
		for (int k=0;k<N;k++)no[k]=new StringBuilder();
		
		for (int j = 0; j<L;j++) {
			if (p.charAt(j) == '1') {
				for (int k=0;k<N;k++) {
					no[k].append(flip(o[k].charAt(j)));
				}
			}
			else {
				for (int k=0;k<N;k++) {
					no[k].append(o[k].charAt(j));
				}
			}
		}
		
		return no;
	}

	private static String need(String a, String b) {
		
		StringBuilder sb = new StringBuilder();
		for (int i=0;i<a.length();i++) {
			if (a.charAt(i) != b.charAt(i)) {
				sb.append("1");
			}
			else {
				sb.append("0");
			}
		}
		
		return sb.toString();
	}

	private static class S {
		
	}
	
	private static char flip(char c) {
		if (c == '0') return '1';
		return '0';
	}
}

