import java.util.*;

public class B {
	static class Node {
		Integer index;
		List<Integer> adj;
		boolean examined;
		boolean visited;

		public Node(int i) {
			index = i;
			adj = new ArrayList<Integer>();
			examined = false;
			visited = false;
		}
	}
	static class Pri {
		int v;
		int p;

		public Pri(int v, int p) {
			this.v = v;
			this.p = p;
		}
	}

	private Node[] nodes;
	private Node[] tnodes;
	private int count;
	private int total;

	public static void main(String[] args) {
		new B();
	}

	public B() {
		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		for (int n = 0; n < cases; n++) {
			int numNodes = input.nextInt();
			int numEdges = numNodes - 1;
			nodes = new Node[numNodes];
			tnodes = new Node[numNodes];
			for (int i = 0; i < numNodes; i++) {
				nodes[i] = new Node(i);
				tnodes[i] = new Node(i);
			}
			for (int i = 0; i < numEdges; i++) {
				int u = input.nextInt() - 1;
				int v = input.nextInt() - 1;
				nodes[u].adj.add(v);
				nodes[v].adj.add(u);
				tnodes[u].adj.add(v);
				tnodes[v].adj.add(u);
			}

			PriorityQueue<Node> queue = new PriorityQueue<Node>(10, new Comparator<Node>() {
				public int compare(Node a, Node b) {
					return a.adj.size() - b.adj.size();
				}
			});
			for (int i = 0; i < numNodes; i++) {
				queue.add(tnodes[i]);
			}
			int e = numEdges;
			while (e > 1) {
				List<Node> list = new ArrayList<Node>();
				list.add(queue.remove());
				int deg = list.get(0).adj.size();
				while (queue.peek().adj.size() == deg) {
					list.add(queue.remove());
				}
				for (Node a : list) {
					for (Integer v : a.adj) {
						Node b = tnodes[v];
						b.adj.remove(a.index);
						queue.remove(b);
						queue.add(b);
						e--;
					}
					a.adj.clear();
				}
			}
			int min = Integer.MAX_VALUE;
			while (!queue.isEmpty()) {
				int r = queue.remove().index;
				total = 0;
				for (int i = 0; i < numNodes; i++) {
					nodes[i].visited = false;
				}
				dfs(r, false);
				min = Math.min(total, min);
			}
			System.out.println("Case #" + (n+1) + ": " + min);
		}
	}

	private void dfs(int u, boolean doCount) {
		Node a = nodes[u];

		if (doCount) {
			if (a.visited || a.examined) return;
			a.examined = true;

			count++;
			for (Integer v : a.adj) {
				dfs(v, true);
			}

			a.examined = false;
		} else {
			if (a.visited) return;
			a.visited = true;

			int x = 0;
			for (Integer v : a.adj) {
				if (!nodes[v].visited) x++;
			}

			if (x > 2) {
				PriorityQueue<Pri> queue = new PriorityQueue<Pri>(10, new Comparator<Pri>() {
					public int compare(Pri a, Pri b) {
						return a.p - b.p;
					}
				});
				for (Integer v : a.adj) {
					count = 0;
					if (!nodes[v].visited) {
						dfs(v, true);
						queue.add(new Pri(v, count));
					}
				}
				while (queue.size() > 2) {
					total += queue.remove().p;
				}
				while (!queue.isEmpty()) {
					dfs(queue.remove().v, false);
				}
			} else if (x == 2) {
				for (Integer v : a.adj) {
					if (!nodes[v].visited) {
						dfs(v, false);
					}
				}
			} else if (x == 1) {
				for (Integer v : a.adj) {
					count = 0;
					if (!nodes[v].visited) {
						dfs(v, true);
						total += count;
					}
				}
			}
		}
	}
}
