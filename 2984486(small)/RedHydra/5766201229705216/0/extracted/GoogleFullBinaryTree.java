import java.util.*;
import java.io.*;

public class GoogleFullBinaryTree
{
	public static void main(String[] args) throws Exception
	{
		Scanner infile = new Scanner(new File("tree.in"));
		PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter("tree.out")));
		int iterations = infile.nextInt();
		for(int loop = 1; loop <= iterations; loop++)
		{
			int amount = infile.nextInt();
			Node[] nodes = new Node[amount];
			for(int i = 0; i < amount; i++)
			{
				nodes[i] = new Node();
			}
			for(int i = 0; i < amount - 1; i++)
			{
				int a = infile.nextInt();
				int b = infile.nextInt();
				
				nodes[a-1].connect(nodes[b-1]);
				nodes[b-1].connect(nodes[a-1]);
			}
			int max = 0;
			for(Node n: nodes)
			{
				if(n.getC().size() == 2)
				{
					int k = treeFrom(n, n);
					if(k > max)
						max = k;
				}
			}
			w.println("Case #" + loop + ": " + (amount - max));
		}
		w.close();
	}
	public static int treeFrom(Node n, Node p)
	{
		ArrayList<Node> connections = n.getC();
		
		if(connections.size() == 3)
		{
			for(int a = 0; a < 3; a++)
			{
				if(connections.get(a) == p)
				{
					connections.remove(p);
					break;
				}
			}
			return 2 + treeFrom(connections.get(0), n) + treeFrom(connections.get(1), n);
		}
		else if(n.getC().size() == 2)
		{
			if(connections.get(0)!=p && connections.get(1)!=p)
				return 3+treeFrom(connections.get(0), n) + treeFrom(connections.get(1), n);
			else
				return 0;
		}
		return 0;
	}
}
class Node
{
	private ArrayList<Node> connections;
	
	public Node()
	{
		connections = new ArrayList<Node>();
	}
	
	public void connect(Node n)
	{
		connections.add(n);
	}
	
	public ArrayList<Node> getC()
	{
		return connections;
	}
}