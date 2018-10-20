import java.util.*;

class Main
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int ts = in.nextInt();
		for (int t = 0; t < ts; t++)
		{
			int n = in.nextInt();
			Node[] nodes = new Node[n];
			for (int i = 0; i < n; i++)
			{
				nodes[i] = new Node(i + 1);
			}
			for (int i = 0; i < n - 1; i++)
			{
				int a = in.nextInt() - 1, b = in.nextInt() - 1;
				nodes[a].addChild(nodes[b]);
				nodes[b].addChild(nodes[a]);
			}
			int ans = Integer.MIN_VALUE;
			for (int i = 0; i < n; i++)
			{
				ans = Math.max(ans, nodes[i].asRoot());
			}
			System.out.println("Case #" + (t+1) + ": " + (n - ans));
		}
	}
}

class Node
{
	int id;
	ArrayList<Node> children = new ArrayList<Node>();
	Map<Node, Integer> cache = new HashMap<Node, Integer>();

	Node(int id) { this.id = id; }

	void addChild(Node node)
	{
		children.add(node);
	}

	int getSize(Node parent)
	{
		if (!cache.containsKey(parent))
		{
			if (children.size() < 3) {
				cache.put(parent, 1);
			} else {
				Top t = new Top(2);
				for (Node child : children) {
					if (child != parent) {
						t.add(child.getSize(this));
					}
				}
				int[] res = t.get();
				cache.put(parent, 1 + res[0] + res[1]);
			}
		}
		//System.out.format("size of %d (parent %d): %d\n", id, parent.id, cache.get(parent));
		return cache.get(parent);
	}

	int asRoot()
	{
		if (children.size() < 2) return 1;
		Top t = new Top(2);
		for (Node child : children)
		{
			t.add(child.getSize(this));
		}
		int[] res = t.get();
		//System.out.format("size of %d (as root): %d\n", id, 1 + res[0] + res[1]);
		return 1 + res[0] + res[1];
	}
}

class Top
{
	int[] top;
	Top(int n) { top = new int[n+1]; for (int i = 0; i < n; i++) top[i] = Integer.MIN_VALUE; }
	void add(int x) {
		int i = top.length - 1;
		top[i] = x;
		while (i - 1 >= 0 && top[i-1] < top[i])
		{
			int t = top[i-1];
			top[i-1] = top[i];
			top[i] = t;
			i--;
		}
	}

	int[] get()
	{
		int[] res = new int[top.length - 1];
		System.arraycopy(top, 0, res, 0, top.length - 1);
		return res;
	}
}
