import java.util.*;
public class b {
	static ArrayList<Integer>[] tree;
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		System.out.printf("Case #%d: ", t+1);
		int n = input.nextInt();
		ArrayList<Integer>[] g = new ArrayList[n];
		for(int i = 0; i<n; i++) g[i] = new ArrayList<Integer>();
		for(int i = 0; i<n-1; i++)
		{
			int a = input.nextInt()-1, b = input.nextInt()-1;
			g[a].add(b);
			g[b].add(a);
		}
		int res = n-1;
		for(int root = 0; root<n; root++)
		{
			tree = new ArrayList[n];
			for(int i = 0; i<n; i++) tree[i] = new ArrayList<Integer>();
			boolean[] vis = new boolean[n];
			Queue<Integer> q = new LinkedList<Integer>();
			vis[root] = true;
			q.add(root);
			while(!q.isEmpty())
			{
				int at = q.poll();
				for(int e: g[at])
				{
					if(!vis[e])
					{
						vis[e] = true;
						tree[at].add(e);
						q.add(e);
					}
				}
			}
			st = new int[n];
			Arrays.fill(st, -1);
			memo = new int[n];
			Arrays.fill(memo, -1);
			//System.out.println(root+" "+go(root));
			res = Math.min(res, go(root));
		}
		System.out.println(res);
	}
}
static int[] memo;
static int go(int at)
{
	if(memo[at] != -1) return memo[at];
	if(tree[at].size() == 1) return memo[at] = st(tree[at].get(0));
	else if(tree[at].size() == 0) return memo[at] = 0;
	else
	{
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		for(int e: tree[at])
		{
			pq.add(st(e) - go(e));
		}
		int res = st(at) - 1;
		while(pq.size() > 2) pq.poll();
		res -= pq.poll() + pq.poll();
		return memo[at] = res;
	}
}
static int[] st;
static int st(int at)
{
	if(st[at] != -1) return st[at];
	int res = 1;
	for(int e: tree[at]) res += st(e);
	return st[at] = res;
}
}
