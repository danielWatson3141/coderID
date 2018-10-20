import java.util.*;

public class Q2 {

	public static class Node {
		public int value;
		public List<Node> connected = new ArrayList<Node>();
		public boolean exists = true;
				
	}

	public static boolean traverse(Node node, Node parent, Set<Integer> visited) {
		visited.add(node.value);
		List<Node> traversible = new ArrayList<Node>();
		for (Node n: node.connected) {
			if (n.exists && n != parent) {
				traversible.add(n);
			}
		}
		if (traversible.size() == 0) return true;
		if (traversible.size() != 2) return false;
		
		return traverse(traversible.get(0), node, visited) && traverse(traversible.get(1), node, visited);
	}
	public static int solve(Map<Integer, Node> nodes, int size) {
		/* brute force and ignorance is key to solving Earth's greatest challenges */
		int numberDel = 0xffffff;
		List<Integer> listInt = new ArrayList<Integer>(nodes.keySet());
		Collections.sort(listInt);
		for (long mask = 0; mask < (1L << size); mask++) {
			int del = 0;
			for (int i = 0; i < size; i++) {
				boolean exists = ((mask >> i) & 1) == 0;
				if (!exists) del++;
				nodes.get(listInt.get(i)).exists = exists;
			}
			// yes, there are faster ways to count bits; no, I don't care
			if (del >= numberDel) continue;
			boolean foundOne = false;
			for (int rootIndex = 0; rootIndex < size; rootIndex++) {
				Set<Integer> traversed = new HashSet<Integer>();
				if (traverse(nodes.get(listInt.get(rootIndex)), null, traversed) && traversed.size() == (size - del)) {
					foundOne = true;
					break;
				}
			}
			if (foundOne) { //our count is lower than their count
				numberDel = del;
			}
		}
		return numberDel;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int countCases = scan.nextInt();
		for (int i = 0; i < countCases; i++) {
			Map<Integer, Node> nodes = new HashMap<Integer, Node>();
			int numNodes = scan.nextInt();
			for (int a = 0; a < numNodes - 1; a++) {
				int begin = scan.nextInt();
				int end = scan.nextInt();
				Node beginNode = nodes.get(begin);
				if (beginNode == null) {
					beginNode = new Node();
					beginNode.value = begin;
					nodes.put(begin, beginNode);
				}
				Node endNode = nodes.get(end);
				if (endNode == null) {
					endNode = new Node();
					endNode.value = end;
					nodes.put(end, endNode);
				}
				beginNode.connected.add(endNode);
				endNode.connected.add(beginNode);
			}
			int count = solve(nodes, numNodes);
			System.out.println("Case #" + (i + 1) + ": " + count);
		}
	}
}