import java.util.*;
public class a {
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int t = br.nextInt();
		for(int c = 1;c<=t;c++){
			int n = br.nextInt();
			int l = br.nextInt();
			String[] ds = new String[n];
			String[] os = new String[n];
			for(int i = 0;i<n;i++){
				ds[i] = br.next();
			}
			for(int j = 0;j<n;j++){
				os[j] = br.next();
			}
			long[][] mask = new long[n][n];
			for(int i = 0;i<n;i++){
				for(int j = 0;j<n;j++){
					long m = 0;
					for(int k = 0;k<l;k++){
						if(ds[i].charAt(k) != os[j].charAt(k)){
							m|=(1l<<k);
						}
					}
					mask[i][j] = m;
				}
			}
			int best = 1000000;
			for(int i = 0;i<n;i++){
				long curMask = mask[0][i];
				Dinic d = new Dinic(2*n+2, 2*n, 2*n+1);
				for(int j = 0;j<n;j++){
					d.add(2*n, j, 1);
					d.add(j+n, 2*n+1, 1);
				}
				for(int j = 0;j<n;j++){
					for(int k = 0;k<n;k++){
						if(mask[j][k] == curMask){
							d.add(j, k+n, 1);
						}
					}
				}
				if(d.maxFlow() == n){
					best = Math.min(best, Long.bitCount(curMask));
				}
			}
			if(best == 1000000){
				System.out.println("Case #"+c+": NOT POSSIBLE");
			}
			else{
				System.out.println("Case #"+c+": "+best);
			}
		}
	}
	public static class Dinic {
		ArrayList<edge>[] gg;
		ArrayDeque<Integer> qu;
		edge[][] g;
		int src, sink, n;
		int[] dist;
		boolean[] blocked;
		public Dinic(int N, int s, int t) {
			n = N; src = s; sink = t;
			g = new edge[n][0];
			gg = new ArrayList[n];
			qu = new ArrayDeque<Integer>();
			for (int i = 0; i < n; gg[i] = new ArrayList<edge>(),i++);
		}
		public boolean add(int s, int e, int cap) {
			return gg[s].add(new edge(e, cap, gg[e].size() + (s == e ? 1 : 0))) && gg[e].add(new edge(s, 0, gg[s].size() - 1));
		}
		public int maxFlow() {
			for(int i=0;i<n; i++)
				g[i] = gg[i].toArray(g[i]);
			int ans = 0;
			blocked = new boolean[n];
			while (bfs()){
				Arrays.fill(blocked, false);
				ans+=dfs(src, (int)1e9);
			}
			return ans;
		}
		public boolean bfs() {
			dist = new int[n];
			qu.add(sink);
			while(!qu.isEmpty() ){
				int cur = qu.poll();
				if(dist[src] != 0 && dist[cur] >= dist[src]) break;
				for(edge e : g[cur])
					if(g[e.e][e.rev].flow < g[e.e][e.rev].cap && e.e != sink &&  dist[e.e] == 0 && qu.add(e.e) && (dist[e.e]=dist[cur]+1)>0);
			}
			qu.clear();
			return (dist[src] != 0);
		}
		public int dfs(int pos, int min) {
			if (pos == sink) return min;
			int flow = 0;
			for (edge e : g[pos])
				if (!blocked[e.e] && dist[e.e]+1 == dist[pos] && e.flow < e.cap) {
					int cur = dfs(e.e, Math.min(min-flow, e.cap-e.flow));
					g[e.e][e.rev].flow = -(e.flow += cur);
					flow+=cur;
					if(flow == min)
						return flow;
				}
			if(flow != min)
				blocked[pos] = true;
			return flow;
		}
		public class edge {
			int e, flow, rev, cap;
			public edge(int b, int c, int f) {
				cap = c; e = b; rev = f;
			}
		}
	}
}
