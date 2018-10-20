import java.util.*;

public class b {
	static int n, oo = 987654321;;
	static int[] memo, sizes;
	static ArrayList<Integer>[] g;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for(int t=1; t<=T; t++) {
			n = in.nextInt();
			g = new ArrayList[n];
			for(int i=0; i<n; i++) g[i] = new ArrayList<Integer>();
			for(int i=0; i<n-1; i++) {
				int x = in.nextInt()-1;
				int y = in.nextInt()-1;
				g[x].add(y);
				g[y].add(x);
			}
			int ans = oo;
			for(int i=0; i<n; i++)
				ans = Math.min(ans, solve(i));
			
			System.out.printf("Case #%d: %d%n", t, ans);
		}
	}
	static int solve(int root) {
		memo = new int[n];
		Arrays.fill(memo, -1);
		sizes = new int[n];
		getSizes(root, root);
		return n-solve(root, root);
	}
	static int solve(int pos, int par) {
		if(memo[pos] != -1) return memo[pos];
		
		int ans = 1; // remove all others
		ArrayList<Integer> subtrees = new ArrayList<Integer>();
		for(int x : g[pos])
			if(x != par)
				subtrees.add(solve(x, pos));
		Collections.sort(subtrees);
		if(subtrees.size() >= 2) {
			int tmp = 1;
			for(int i=subtrees.size()-2; i<subtrees.size(); i++)
				tmp += subtrees.get(i);
			ans = Math.max(ans, tmp);
		}
		return memo[pos] = ans;
	}
	static int getSizes(int pos, int par) {
		int ret = 1;
		for(int x : g[pos])
			if(x != par)
				ret += getSizes(x, pos);
		return sizes[pos] = ret;
	}
}