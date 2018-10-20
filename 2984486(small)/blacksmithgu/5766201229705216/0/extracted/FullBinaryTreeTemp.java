import java.io.*;
import java.util.*;
import java.lang.*;

public class FullBinaryTreeTemp {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new File("FullBinaryTree.in"));
		PrintStream out = new PrintStream(new File("FullBinaryTree.out"));

		int t = input.nextInt();
		for(int s = 0; s < t; s++) {
			int c = input.nextInt();
			
			Graph graph = new Graph(c);
			for(int a = 0; a < c - 1; a++) {
				int first = input.nextInt(), second = input.nextInt();
				graph.connect(first, second);
				graph.connect(second, first);
			}
			
			// Select all non-edges as roots to check
			int minSelected = Integer.MAX_VALUE, minNode = 0;
			for(Node n : graph.nodes.values()) {
				if(n.connections.size() > 1)
				{
					Graph newGraph = new Graph(graph, n);
					int res = rem(newGraph.root);
					
					System.out.println("Trying " + n.n + " : " + res);
					if(minSelected > res) {
						minSelected = res;
						minNode = n.n;
					}
				}
			}
			
			System.out.println("Case #" + (s + 1) + ":" + graph.nodes.size() + " nodes.");
			
			out.println("Case #" + (s + 1) + ": " + minSelected);
		}
		
		input.close();
		System.out.close();
	}
	
	public static int rem(Node current) {
		if(current.conn().size() == 0) return 0; // Special Case: Edge node
		if(current.conn().size() == 1) return count(current) - 1; // Special Case: We know this won't work out.
		
		int sum = 0;
		// Take 2 nodes with lowest rem() values.
		// We consider this connections to be only outgoing at this point.
		HashMap<Node, Integer> counts = new HashMap<Node, Integer>();
		HashMap<Node, Integer> rem = new HashMap<Node, Integer>();
		
		for(Node out : current.connections) {
			out.remove(current);
			
			int res = rem(out);
			counts.put(out, count(out));
			rem.put(out, res);
			
			sum += res;
		}
		
		int totalCost = 0;
		while(current.connections.size() > 2) {
			HashMap<Node, Integer> costs = new HashMap<Node, Integer>();
			
			for(Node n : current.connections) {
				costs.put(n, counts.get(n) + sum - rem.get(n));
			}
			
			Iterator<Node> it = costs.keySet().iterator();
			Node minNode = it.next();
			while(it.hasNext()) {
				Node next = it.next();
				if(costs.get(next) < costs.get(minNode)) minNode = next;
			}
			
			totalCost += counts.get(minNode);
			current.connections.remove(minNode);
			
			sum -= rem.get(minNode);
		}
		
		return totalCost + sum;
	}
	
	public static int count(Node current) {
		if(current.connections.size() == 0) return 1;
		
		int c = 1;
		for(Node out : current.connections) {
			out.remove(current);
			
			c += count(out);
		}
		
		return c;
	}
	
	public static class Graph {
		public HashMap<Integer, Node> nodes;
		public Node root;
		
		public Graph(int max) {
			nodes = new HashMap<>();
			for(int n = 1; n <= max; n++)
				nodes.put(n, new Node(n));
			
			root = null;
		}
		
		public Graph(Graph copy, Node select) {
			nodes = new HashMap<>();
			for(int x = 1; x <= copy.nodes.size(); x++) {
				nodes.put(x, new Node(x));
				if(copy.nodes.get(x) == select)
					root = nodes.get(x);
			}
			
			for(Node other : copy.nodes.values()) {
				Node local = nodes.get(other.n);
				for(Node rem : other.connections)
					local.connections.add(nodes.get(rem.n));
			}
		}
		
		public void connect(int n, int n2) {
			nodes.get(n).connections.add(nodes.get(n2));
		}
		
		public void disconnect(int n, int n2) {
			nodes.get(n).connections.remove(nodes.get(n2));
		}
		
		public Node get(int n) {
			return nodes.get(n);
		}
	}
	
	public static class Node {
		public HashSet<Node> connections;
		public int n;
		
		public Node(int n) {
			this.n = n;
			connections = new HashSet<>();
		}
		
		public void add(Node n) {
			connections.add(n);
		}
		
		public void remove(Node n) {
			connections.remove(n);
		}
		
		@Override
		public boolean equals(Object o) {
			Node n = (Node) o;
			return n.n == this.n;
		}
		
		@Override
		public int hashCode() {
			return n;
		}
		
		public HashSet<Node> conn() {
			return connections;
		}
	}
}