import java.math.*;
import java.util.*;
import java.io.*;

public class B
{
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new BufferedReader(new FileReader("B-small-attempt3.in")));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-small.out")));
		
		int tt = in.nextInt();
		for (int I = 1; I <= tt; I++)
		{
			out.print("Case #" + I + ": ");
			Map<Integer, Set<Integer>> edges = new HashMap<> ();
			int n = in.nextInt();
			for (int i = 1; i <= n; i++)
				edges.put(i, new HashSet<Integer> ());
			for (int i = 1; i < n; i++)
			{
				int a = in.nextInt();
				int b = in.nextInt();
				edges.get(a).add(b);
				edges.get(b).add(a);
			}
			System.out.println(edges);
			int best = n - 1;
			int choice = 0;
			for (int i = 1; i <= n; i++)
				if (edges.get(i).size() > 1)
				{
					int temp = n - rootTree(edges, i);
					if (temp < best)
					{
						best = temp;
						choice = i;
					}
				}
			out.println(best);
			System.out.println(best + " " + choice);
		}
		out.flush();
		out.close();
	}
	
	private static int rootTree(Map<Integer, Set<Integer>> edges, int root)
	{
//		System.out.println("\tcalling roottree on " + root + " with " + edges);
		if (edges.get(root).size() == 2)
			return explore(edges, root);
		else if (edges.get(root).size() < 2)
			throw new RuntimeException();
		else
		{
			List<Integer> list = new ArrayList<> ();
			for (int edge : new HashSet<Integer> (edges.get(root)))
			{
				edges.get(root).remove(edge);
				edges.get(edge).remove(root);
				list.add(explore(edges, edge));
				edges.get(root).add(edge);
				edges.get(edge).add(root);
			}
			Collections.sort(list);
			Collections.reverse(list);
//			System.out.println("\trootTree on " + root + " returning " + (list.get(0) + list.get(1) + 1));
			return list.get(0) + list.get(1) + 1;
		}
	}
	
	private static int explore(Map<Integer, Set<Integer>> edges, int root)
	{
//		System.out.println("\tcalling explore on " + root + " with " + edges);
		if (edges.get(root).size() <= 1)
			return 1;
		if (edges.get(root).size() > 2)
			return rootTree(edges, root);
		Set<Integer> explored = new HashSet<> ();
		explored.add(root);
		Queue<Integer> frontier = new LinkedList<> (edges.get(root));
		int safe = 0;
		while (!frontier.isEmpty())
		{
			int node = frontier.remove();
			explored.add(node);
			if (edges.get(node).size() <= 2)
				continue;
			if (edges.get(node).size() == 3)
			{
				for (int n : edges.get(node))
					if (!explored.contains(n))
						frontier.add(n);
			}
			else
			{
				int parent = -1;
				for (int n : edges.get(node))
					if (explored.contains(n))
						parent = n;
				edges.get(parent).remove(node);
				edges.get(node).remove(parent);
				safe += rootTree(edges, node) - 1;
				edges.get(node).add(parent);
				edges.get(parent).add(node);
			}
		}
//		System.out.println("\texplore on " + root + " returning " + (explored.size() + safe));
		return explored.size() + safe;
	}
}
