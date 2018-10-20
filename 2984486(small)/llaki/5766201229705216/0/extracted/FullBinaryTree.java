import java.util.*;
import java.io.*;

public class FullBinaryTree {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int T = sc.nextInt();
		for(int t=1; t<=T; t++){
			for(int i=0; i<=1000; i++){
				Arrays.fill(count[i], -1);
				Arrays.fill(dp[i], 0);
				Arrays.fill(been[i], false);
				G[i] = new ArrayList<Integer>();
			}
			
			n = sc.nextInt();
			for(int i=0; i<n-1; i++){
				int a = sc.nextInt(), b = sc.nextInt();
				G[a].add(b);
				G[b].add(a);
			}
			int answer = n;
			for(int i=1; i<=n; i++){
				answer = Math.min(answer, dpValue(i, 0));
			}
			pw.println("Case #"+t+": "+answer);
		}
		pw.println();
		pw.flush();
		pw.close();
	}
	
	static int count(int v, int p){
		if(count[v][p]!=-1) return count[v][p];
		int cnt = 1;
		for(int to : G[v]){
			if(to!=p) cnt += count(to, v);
		}
		return count[v][p] = cnt;
	}
	
	static int dpValue(int v, int p){
		if(been[v][p]) return dp[v][p];
		boolean isLeaf = (G[v].size()==0 || (G[v].size()==1 && G[v].get(0)==p));
		if(isLeaf){
			been[v][p] = true;
			return dp[v][p] = 0;
		}
		if(G[v].size()==1){
			been[v][p] = true;
			return dp[v][p] = count(v, p) - 1;
		}
		int sz = G[v].size();
		int minRemovals = count(v, p) - 1;
		for(int i=0; i<sz; i++){
			if(G[v].get(i)==p) continue;
			for(int j=i+1; j<sz; j++){
				if(G[v].get(j)==p) continue;
				int numRemoved = count(v, p) - count(G[v].get(i), v) - count(G[v].get(j), v) - 1;
				numRemoved += dpValue(G[v].get(i), v) + dpValue(G[v].get(j), v);
				minRemovals = Math.min(numRemoved, minRemovals);
			}
		}
		been[v][p] = true;
		return dp[v][p] = minRemovals;
	}
	
	
	static int[][] count = new int[1001][1001];
	static int[][] dp = new int[1001][1001];
	static boolean[][] been = new boolean[1001][1001];
	static int n;
	static ArrayList<Integer>[] G = new ArrayList[1001];
	
}
