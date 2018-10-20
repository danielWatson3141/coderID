import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class p2 {

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
		int N = Integer.parseInt(br.readLine());
		
		int[][]adj = new int[N][N];
		
		for (int i=0;i<N-1;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken())-1;
			int b = Integer.parseInt(st.nextToken())-1;
			adj[a][b]=adj[b][a]=1;
		}
		
		
		
		int mini = N+1;
		for (int i=0;i<(1<<N)-1;i++) {
					
			boolean []del=new boolean[N];
			int v = 0;
			for (int j = 0; j<N;j++) {
				if (((i>>j) & 1) == 1) {
					v++;
					del[j]=true;
				}
			}
			boolean[]vis=new boolean[N];
				
			
			boolean isbin = go(adj,vis,del);
			//debug(del,isbin,v);
			if (isbin) {

				isCon(adj,del,vis);
				boolean disc = false;
				for (int r=0;r<N;r++) {
					if (!vis[r] && !del[r]) {
						disc = true;
						break;
					}
				}
				//debug(del,isbin,disc,v);
				
				if (!disc) {
					mini = Math.min(mini, v);
				}
			}
		}

		
		return mini;
	}
	
	private static void isCon(int[][] adj, boolean[] del, boolean[] vis) {
		int N = vis.length;
		for (int i=0;i<N;i++) {
			if (!del[i]) {
				dfs(i,adj,del,vis);
				return;
			}
		}
		return;
	}

	private static void dfs(int i, int[][] adj, boolean[] del, boolean[] vis) {
		vis[i]=true;
		
		for (int j=0;j<vis.length;j++) {
			if (adj[i][j]==1 && !del[j] && !vis[j]) {
				dfs(j,adj,del,vis);
			}
		}
		return;
	}

	private static boolean go(int[][] adj, boolean[] vis, boolean[] del) {
		
		int N = vis.length;
		
		boolean saw2 = false;
		boolean dneed2 = true;
		for (int i=0;i<N;i++) {
			if (del[i]) continue;
			int cnt = 0;
			int oth = -1;
			for (int k=0;k<N;k++) {
				if (adj[i][k] == 1 && !del[k]) {
					cnt++;
					oth = k;
				}
			}
			if (cnt == 2 && saw2) {
				return false;
			}
			else if (cnt == 2) {
				saw2 = true;
			}
			
			if (cnt == 1) {
				int cnt2 = 0;
				for (int k=0;k<N;k++) {
					if (adj[oth][k] == 1 && !del[k]) {
						cnt2++;
					}
				}
				if (cnt2 == 1) {
					return false;
				}
			}
			
			if (cnt == 1 || cnt == 3) {
				dneed2 = false;
			}
			
			if (cnt != 1 && cnt != 2 && cnt != 3 && cnt != 0) {
				return false;
			}
		}
		return saw2 || dneed2;
	}
	
}
