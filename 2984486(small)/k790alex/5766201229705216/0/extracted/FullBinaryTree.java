
import java.io.*;
import java.util.*;
import java.awt.*;

public class FullBinaryTree {
	static final String INPUT = "B-small.in";
	static final String OUTPUT = "B-small.out";
	
	// fast I/O util
	static PrintWriter out = new PrintWriter( new BufferedOutputStream(System.out), true );
	static BufferedReader br = new BufferedReader( new InputStreamReader(System.in) );
	static StringTokenizer st = new StringTokenizer("");
	static String next()	throws Exception	{
		
		while	( !st.hasMoreTokens() )	{
			String s = br.readLine();
			if	( s == null )	return	null;
			st = new StringTokenizer( s );
		}
		return	st.nextToken();
	}

	public static void main(String [] asda)	throws Exception	{
		
		br = new BufferedReader( new FileReader(INPUT) );
		out = new PrintWriter(OUTPUT);
		
		
		int CASES = Integer.parseInt( next() );
		
		for (int ccc = 1; ccc <= CASES; ccc++)	{
			out.print("Case #" + ccc + ": ");
			int N = Integer.parseInt( next() );
			
			ArrayList<Integer> tree [] = new ArrayList [N + 1];
			for (int i = 0; i <= N; i++)
				tree[i] = new ArrayList<Integer>();
			
			for (int i = 1; i < N; i++)	{
				int a = Integer.parseInt( next() );
				int b = Integer.parseInt( next() );
				tree[a].add(b);
				tree[b].add(a);
			}
			
			
			int max = 0;
			
			for (int i = 0; i < (1 << N); i++)	{
				unused = new boolean [N + 1];
				for (int k = 0; k < N; k++)	{
					if	( (i & (1 << k) ) != 0 )
						unused[k + 1] = true;
				}
				

				for (int id = 1; id <= N; id++)	{
					if	( unused[id] )
						continue;
			
					Node root = buildTree(tree, i);
					int x = count(root);
					max = Math.max(x, max);
				}
			}
			
			
			out.println(N - max);
			
		}
		//
		out.flush();
		
		out.close();
		br.close();
	}
	static boolean unused [];
	private static int count(Node root) {
		if	( root == null )
			return	0;
		int ans = 1;
		
		if	( root.count() == 2 )	for (Node node : root.sons)	{
			ans += count(node);
		}
		
		return ans;
	}

	private static Node buildTree(ArrayList<Integer>[] tree, int r) {
		Node root = new Node();
		root.id = r;
		
		if	( r >= tree.length )
			return root;

		boolean marked [] = new boolean [ tree.length ];
		marked[r] = true;
		
		if	( free(tree[ r ], marked) > 2 )
			return	root;
		
		for (int i = 0, k = 0; i < tree[r].size(); i++)	{
			Node node = new Node();
			node.id = tree[r].get(i);
			
			if	( unused[ node.id ] )
				continue;

			if	( free(tree[ node.id ], marked) > 2 )
				continue;

			root.sons[k++] = node;
			
			build( node, tree, marked );
		}
		
		return root;
	}
	private static int free(ArrayList<Integer> list, boolean marked[]) {
		int free = 0;
		for (int val : list)	{
			if ( unused[val] || marked[val] )
				continue;
			free++;
		}
		return free;
	}

	private static void build(Node node, ArrayList<Integer>[] tree, boolean[] marked) {
		int id = node.id;
		marked[id] = true;
		for (int i = 0, k = 0; i < tree[id].size(); i++)	{
			int to = tree[id].get(i);
			if	( marked[to] || unused[to] )
				continue;
			
			Node n = new Node();
			n.id = to;
			

			if	( free(tree[ n.id ], marked) > 2 )
				continue;
			
			node.sons[k++] = n;
			

			
			build( n, tree, marked );
		}
	}
	static class Node	{
		int id = 0;
		Node [] sons = new Node[2];
		
		public int count()	{
			int x = 0;
			for (Node n : sons)	if	(n != null)
				x++;
			return	x;
		}
		
		public String toString()	{
			return	id + "";
		}
	}
}





/*

1

9
1 4
2 4
2 9
3 7
3 8
4 5
4 7
6 8




*/

