import java.util.*;
import java.io.*;
public class B
{
	public static ArrayList<Integer>[] adj;
	public static int[][] memo;
	
	public static void main(String[] args) throws Exception
	{
//		Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new File("b-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("bsmallattempt0.out")));
		
		int t = in.nextInt();
		for(int x = 0; x < t; x++)
		{
			int n = in.nextInt();
			
			adj = new ArrayList[n];
			for(int y = 0; y < adj.length; y++)
			{
				adj[y] = new ArrayList<Integer>();
			}
			
			for(int z = 0; z < n - 1; z++)
			{
				int a = in.nextInt() - 1;
				int b = in.nextInt() - 1;
				adj[a].add(b);
				adj[b].add(a);
			}
			
			memo = new int[n + 1][n + 1];
			for(int a = 0; a < memo.length; a++)
			{
				Arrays.fill(memo[a], -1);
			}
			
			int result = 0;
			for(int b = 0; b < adj.length; b++)
			{
				result = Math.max(result, fullify(b, n));
			}
			
			out.println("Case #" + (x + 1) + ": " + (n - result));
		}
		
		out.close();
	}
	
	public static int fullify(int node, int parent)
	{
		if(memo[node][parent] != -1)
		{
			return memo[node][parent];
		}
		else
		{
			ArrayList<Integer> values = new ArrayList<Integer>();
			for(int next : adj[node])
			{
				if(next != parent)
				{
					values.add(fullify(next, node));
				}
			}
			
			Collections.sort(values);
			
			int ret = 1;
			if(values.size() >= 2)
			{
				ret += values.get(values.size() - 1) + values.get(values.size() - 2);
			}
			
			return memo[node][parent] = ret;
		}
	}
}
