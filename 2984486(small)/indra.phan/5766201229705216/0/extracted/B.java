import java.util.*;

public class B {
	private static int INF = (1 << 30) - 1;
	
	private static int N;
	private static boolean mp[][];
	private static boolean vis[];
	

	private static void init() {
		mp = new boolean[N+2][N+2];
		vis = new boolean[N+2];
		
		for(int i=0; i<N+2; i++) Arrays.fill(mp[i], false);
		Arrays.fill(vis, false);
	}
	
	private static int go(int x, boolean isDel) {
		vis[x] = true;
		
		int ctr = 0;
		for(int i=1; i<=N; i++) {
			if(vis[i]) continue;
			if(mp[x][i]) ctr++;
		}
		
		int res = ((ctr == 2 || ctr == 0) && !isDel) ? 0 : 1;
		
		for(int i=1; i<=N; i++) {
			if(vis[i]) continue;
			if(mp[x][i]) {
				res += go(i, (ctr == 2) ? isDel : false);
			}
		}
		
		return res;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int _i=1; _i<=T; _i++) {
			N = sc.nextInt();
			
			init();
			
			for(int i=0; i<N-1; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				
				mp[x][y] = true;
				mp[y][x] = true;
			}
			
			int res = INF;
			for(int i=1; i<=N; i++) {
				Arrays.fill(vis, false);
				res = Math.min(res, go(i, false));
			}
			
			System.out.println("Case #" + _i + ": " + res);
		}
		

	}

}
