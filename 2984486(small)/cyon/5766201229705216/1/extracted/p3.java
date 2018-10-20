import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;


public class p3 {

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

	private static List<Integer>adj[];
	private static int size[];
	private static int trims = 0;
	private static Object solveCase(BufferedReader br, PrintWriter pw) throws Exception {
		int N = Integer.parseInt(br.readLine());
		
		adj = new List[N];
		for (int i=0;i<N;i++) adj[i] = new ArrayList<Integer>();
		
		
		for (int i=0;i<N-1;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken())-1;
			int b = Integer.parseInt(st.nextToken())-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		
		int maxi = 0;
		for (int i=0;i<N;i++) {
			if (adj[i].size() == 1) {
				maxi = Math.max(maxi, 1);
			}
			else {
				maxi = Math.max(maxi, trim(i,0,-1));
			}
		}
		return "" + (N-maxi);
	}

	private static int trim(int i, int r, int p) {
		
		int sz = adj[i].size();
		if (sz == 1) return 1;
		
		List<Integer> su = new ArrayList<Integer>();
		for (int v : adj[i]) {
			if (v == p) continue;
			su.add(-trim(v, r, i));
		}
		Collections.sort(su);
		//debug(i,p,su);
		if (su.size() == 1) {
			return 1;
		}
		int subs = 0;
		for (int k=0;k<2;k++) {
			subs += -su.get(k);
		}
		return subs + 1;
	}

	private static int go(int i,int p) {
		
		int cnt = 1;
		for (int v : adj[i]) {
			if (v == p) continue;
			cnt += go(v, i);
		}
		size[i]=cnt;
		
		return cnt;
	}
	
}

