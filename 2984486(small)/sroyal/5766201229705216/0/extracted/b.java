import java.util.*;
public class b {
	public static int[][] memo;
	public static int[] size, par;
	public static ArrayList<Edge>[] g;
	public static Edge[] es;
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int t = br.nextInt();
		for(int c = 1;c<=t;c++){
			int n = br.nextInt();
			g = new ArrayList[n];
			for(int i = 0;i<n;i++){
				g[i] = new ArrayList<Edge>();
			}
			es = new Edge[2*(n-1)];
			for(int i = 0;i<n-1;i++){
				int s = br.nextInt()-1;
				int e = br.nextInt()-1;
				es[i] = new Edge(s, e, i);
				es[i+(n-1)] = new Edge(e, s, i+(n-1));
				g[s].add(es[i]);
				g[e].add(es[i+(n-1)]);
			}
			for(int i = 0;i<n;i++){
				for(int j = 0;j<g[i].size();j++){
					if(j == g[i].size()-1){
						g[i].get(j).next = -1;
					}
					else{
						g[i].get(j).next = g[i].get(j+1).index;
					}
				}
			}
			int best = n-1;
			for(int root = 0;root<n;root++){
				//Root tree
				size = new int[n];
				par = new int[n];
				rootTree(root, -1);
				memo = new int[3][2*n];
				for(int i = 0;i<3;i++){
					Arrays.fill(memo[i], -1);
				}
				best = Math.min(best, go(0, g[root].get(0).index));
			}
			System.out.println("Case #"+c+": "+best);
		}
	}
	public static int go(int taken, int EdgeOn){
		
		if(EdgeOn == -1 && (taken == 0 || taken == 2)){
			return 0;
		}
		if(EdgeOn == -1){
			return par.length+1;
		}
		if(memo[taken][EdgeOn] != -1){
			return memo[taken][EdgeOn];
		}
		int pos = es[EdgeOn].s;
		int next = es[EdgeOn].e;
		if(next == par[pos]){
			return memo[taken][EdgeOn] = go(taken, es[EdgeOn].next);
		}
		int ans = go(taken, es[EdgeOn].next)+size[next];
		if(taken < 2 && next != par[pos]){
			ans = Math.min(ans, go(taken+1, es[EdgeOn].next)+go(0, g[next].get(0).index));
		}
		return memo[taken][EdgeOn] = ans;
	}
	public static class Edge{
		int s, e, index, next;
		public Edge(int a, int b, int c){
			s = a;
			e = b;
			index = c;
		}
		public String toString(){
			return s+" "+e+" "+index+" "+next;
		}
	}
	public static int rootTree(int pos, int p){
		par[pos] = p;
		size[pos] = 1;
		for(Edge e : g[pos]){
			if(e.e != p){
				size[pos] += rootTree(e.e, pos);
			}
		}
		return size[pos];
	}
}
