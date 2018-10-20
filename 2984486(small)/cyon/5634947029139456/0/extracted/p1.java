import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;


public class p1 {

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
		for (int i=0;i<(1<<L);i++) {
			int flen = 0;
			StringBuilder[]no = new StringBuilder[N];
			for (int k=0;k<N;k++)no[k]=new StringBuilder();
			
			for (int j = 0; j<L;j++) {
				if (((i>>j) & 1) == 1) {
					flen++;
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
			Set<String> nout = new HashSet<>();
			for (int k=0;k<N;k++) {
				nout.add(no[k].toString());
			}
			//debug(nout, Integer.toBinaryString(i));
			boolean ok = true;
			for (int k=0;k<N;k++) {
				if (!nout.contains(d[k])) {
					ok = false;
					break;
				}
				else {
					nout.remove(d[k]);
				}
			}
			if (ok) {
				milen = Math.min(milen, flen);
			}
		}
		
		return (milen == L+1) ? "NOT POSSIBLE" : milen;
	}

	private static char flip(char c) {
		if (c == '0') return '1';
		return '0';
	}
}
