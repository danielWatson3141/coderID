import java.util.*;
import java.io.*;

public class treeReal {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("input/tree_small.in"));
		PrintStream output = new PrintStream(new File("output/tree_small.out"));
		PrintStream out = output;
		int T = input.nextInt();
		primary: for (int oncase = 0; oncase < T; oncase++) {
			out.printf("Case #%d: ", oncase+1);
			Map<Integer, Node> nodes = new HashMap<Integer, Node>();
			int n = input.nextInt();
			for (int i=1; i<=n; i++) {
				nodes.put(i, new Node(i));
			}
			for (int i=0; i<n-1; i++) {
				int j = input.nextInt();
				int k = input.nextInt();
				nodes.get(j).adj.put(k, nodes.get(k));
				nodes.get(k).adj.put(j, nodes.get(j));
			}
			int best = Integer.MAX_VALUE;
			for (Node cur : nodes.values()) {
				best = Math.min(best, cur.count(-1));
//				System.out.println(cur.id + " " + cur.count(-1));
			}
			out.println(Math.min(best, nodes.size()-1));
		}
		output.close();
	}
	
	public static class Node {
		Map<Integer, Node> adj = new HashMap<Integer, Node>();
		int id;
		
		public Node(int i) {
			id = i;
		}
		
		public boolean couldBeRoot() {
			return adj.size() >= 2;
		}
		
		public int children(int from) {
			int res = 0;
			for (Map.Entry<Integer, Node> entry : adj.entrySet()) {
				if (entry.getKey() != from) res += entry.getValue().children(id);
			}
			return res + 1;
		}
		
		public int count(int from) {
			return count(from, true);
		}
		
		public int count(int from, boolean saveable) {
			List<Node> children = new ArrayList<>();
			for (Node cur : adj.values()) {
				if (cur.id != from) children.add(cur);
			}
			switch (children.size()) {
			case 0:
				return 0;
			case 1:
				if (saveable) {
					return children.get(0).flood(id);
				} else {
					return flood(id);
				}
			case 2:
				return children.get(0).count(id) + children.get(1).count(id);
			default:
				int totalFlood = 0;
				List<Counter> counter = new ArrayList<Counter>();
				for (Node cur : children) {
					int flood = cur.flood(id);
					counter.add(new Counter(cur, flood, cur.count(id)));
				}
				Collections.sort(counter);
				int res = 0;
//				System.out.println("I am " + id + ", Keeping " + counter.get(0).node.id + " and " + counter.get(1).node.id);
				res += counter.remove(0).count + counter.remove(0).count;
				for (Counter cur : counter) {
					res += cur.flood;
				}
				return res;
			}
		}
		
		public int flood(int from) {
			int res = 1;
			for (Node cur : adj.values()) {
				if (cur.id != from) res += cur.flood(id);
			}
			return res;
		}
	}
	
	public static class Counter implements Comparable<Counter> {
		Node node;
		int flood;
		int count;
		public Counter(Node n, int f, int c) {
			node = n;
			flood = f;
			count = c;
		}
		public int compareTo(Counter other) {
			return (count - flood) - (other.count - other.flood);
		}
	}
}