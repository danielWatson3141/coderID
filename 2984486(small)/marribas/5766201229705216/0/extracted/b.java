import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class b {

	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int z = 1; z <= t; z++)
		{
			int n = in.nextInt();
			adj = new ArrayList[n];
			for (int i = 0; i < n; i++)
				adj[i] = new ArrayList<Integer>();
				
			for (int i = 0; i < n - 1; i++)
			{
				int u = in.nextInt() - 1;
				int v = in.nextInt() - 1;
				adj[u].add(v);
				adj[v].add(u);
			}
			
			dadj = new ArrayList[n];
			int ret = 987654321;
			size = new int[n];
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					dadj[j] = new ArrayList<Integer>();
				Arrays.fill(size, 0);
				dfs(i, -1);
				memo = new int[n];
				Arrays.fill(memo, -1);
				ret = Math.min(go(i), ret);
			}
			
			System.out.println("Case #" + z + ": " + ret);
		}
	}
	
	static int dfs(int u, int p)
	{
		int am = 0;
		for (int v : adj[u])
		{
			if (v == p)
				continue;
			dadj[u].add(v);
			am += dfs(v, u);
		}
		
		return size[u] = am + 1;
	}
	
	static int go(int u)
	{
		if (memo[u] != -1)
			return memo[u];
		
		if (dadj[u].size() == 0)
			return 0;
		
		if (dadj[u].size() == 1)
			return size[u] - 1;
		
		int ret = size[u] - 1;
		Pair[] am = new Pair[dadj[u].size()];
		int i = 0;
		for (int v : dadj[u])
			am[i++] = new Pair(v, go(v), size[v]);
		
		Arrays.sort(am);
		
		if (am.length >= 2)
			ret = Math.min(ret, am[0].value + am[1].value + ret - size[am[0].index] - size[am[1].index]);

		return memo[u] = ret;
	}
	
	
	static class Pair implements Comparable<Pair>
	{
		int index, value, below;
		public Pair(int index, int value, int below)
		{
			this.index = index;
			this.value = value;
			this.below = below;
		}
		
		public int compareTo(Pair o)
		{
			return (this.value - below) - (o.value - o.below);
		}
	}
	
	static int[] memo;
	static int[] size;
	static ArrayList<Integer>[] dadj;
	static ArrayList<Integer>[] adj;
}
