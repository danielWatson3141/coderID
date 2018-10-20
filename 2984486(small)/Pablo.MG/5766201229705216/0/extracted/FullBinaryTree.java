import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;


public class FullBinaryTree {
	
	private static class Result {
		private int root;
		private int parent;
		
		private Result(int root, int parent) {
			this.root = root;
			this.parent = parent;
		}
		
		@Override
		public int hashCode() {
			return root ^ parent;
		}
		
		@Override
		public boolean equals(Object o) {
			if (o instanceof Result) {
				Result o2 = (Result)o;
				return this.root == o2.root && this.parent == o2.parent; 
			}
			return false;
		}
	}
	
	private static class Node {
		private int id;
		private List<Node> connectedNodes = new LinkedList<Node>();
		
		private Node(int id) {
			this.id = id;
		}
		
		@Override
		public int hashCode() {
			return id;
		}
	}
	
	private static class Comp implements Comparator<int[]> {
		@Override
		public int compare(int[] o1, int[] o2) {
			return o1[0] - o2[0];
		}
	}
	
	static Scanner s;
	private static Map<Result, int[]> cachedResults;
	private static Comp resultComparator = new Comp();
	private static Node[] graph;

	public static void main(String[] args) {
//		try {
//			System.setIn(new java.io.FileInputStream("testFiles/input.txt"));
//		} catch (java.io.FileNotFoundException e) {}
		
		s = new Scanner(System.in);
		int numCases = Integer.parseInt(s.next());
		
		for (int i = 1; i <= numCases; i++) {
			int numNodes = Integer.parseInt(s.next());
			cachedResults = new HashMap<Result, int[]>(numCases);
			System.out.println("Case #" + i + ": " + treatCase(numNodes) );
		}
	}

	private static int treatCase(int numNodes) {
		graph = new Node[numNodes+1];
		for (int i = 1; i <= numNodes; i++) {
			graph[i] = new Node(i);
		}
		for (int i = 1; i < numNodes; i++) {
			int node1 = Integer.parseInt(s.next());
			int node2 = Integer.parseInt(s.next());
			graph[node1].connectedNodes.add(graph[node2]);
			graph[node2].connectedNodes.add(graph[node1]);
		}
		
		int bestValue = numNodes;
		for (int i = 1; i <= numNodes; i++) {
			int deleted;
			if ( graph[i].connectedNodes.size() == 1 ) {
				deleted = numNodes-1;
			} else {
				deleted = getSubBinayTree(i, 0)[1];
			}
			if (deleted < bestValue) {
				bestValue = deleted;
			}
		}
		return bestValue;
	}
	
	private static int[] leafNodeValue = new int[]{1, 0};
	
	//0 -> num nodes, 1 -> deleted nodes
	private static int[] getSubBinayTree(int root, int parent) {
		Result result = new Result(root, parent);
		if (!cachedResults.containsKey(result)) {
			List<int[]> results = new ArrayList<int[]>( graph[root].connectedNodes.size() - 1 );
			for (Node son : graph[root].connectedNodes) {
				if (son.id != parent) {
					if (graph[son.id].connectedNodes.size() > 1) {
						results.add( getSubBinayTree(son.id, root) );
					} else {
						results.add( leafNodeValue );
					}
				}
			}
			if (results.size() == 1) {
				cachedResults.put(result, new int[]{1, results.get(0)[0] + results.get(0)[1]});
			} else {
				Collections.sort(results, resultComparator);
				int removed = 0;
				while(results.size() > 2) {
					int[] element = results.remove(0);
					removed += element[0] + element[1];
				}
				cachedResults.put(result, new int[]{results.get(0)[0] + results.get(1)[0] + 1, results.get(0)[1] + results.get(1)[1] + removed});
			}
		}
		return cachedResults.get(result);
	}
}
