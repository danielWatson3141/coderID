import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class Problem2 {
	
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new FileReader("problem2.txt"));
		
		int tests = scanner.nextInt();
		for(int i = 1; i <= tests; i++) {
			//Get the constants
			int N = scanner.nextInt();
			
			
			Node[] nodes = new Node[N];
			for(int j = 0; j < N; j++) {
				nodes[j] = new Node(j);
			}
			for(int j = 0; j < N - 1; j++) {
				int x = scanner.nextInt();
				int y = scanner.nextInt();
				
				nodes[x - 1].edges.add(nodes[y - 1].id);
				nodes[y - 1].edges.add(nodes[x - 1].id);
				//System.out.println(x + " " + y);
			}
			
			List<Node> possibleRoots = new ArrayList<Node>();
			for(int j = 0; j < N; j++) {
				if(nodes[j].edges.size() == 2 || nodes[j].edges.size() == 3) {
					possibleRoots.add(nodes[j]);
				}
			}
			
			//Special case: No possible roots
			if(possibleRoots.size() == 0) {
				System.out.printf("Case #%d: %d\n", i, N - 1);
				continue;
			}
			
			int best = Integer.MAX_VALUE;
			for(Node n : possibleRoots) {
				
				Node[] nodeList = cloneNodelist(nodes);
				int removed = getChildrenToRemove(nodeList, n.id);
				//System.out.println("**** considering " + n.id + "  " + removed);
				if(removed < best) {
					best = removed;
				}
			}
			
			System.out.printf("Case #%d: %d\n", i, best);			
		}
		
		scanner.close();
		
		System.exit(0);
	}
	
	private static class Node {
		public int id;
		public Set<Integer> edges = new TreeSet<Integer>(); 
		
		public Node(int id) {
			this.id = id;
		}
		
		public Node clone() {
			Node cloned = new Node(id);
			for(Integer i : edges) {
				cloned.edges.add(i);
			}
			return cloned;
		}
	}	
	
	private static Node[] cloneNodelist(Node[] list) {
		Node[] nodes = new Node[list.length];
		for(int j = 0; j < list.length; j++) {
			nodes[j] = list[j].clone();
		}
		return nodes;
	}
	
	private static int getChildrenToRemove(Node[] list, int root) {
		
		if(list[root].edges.size() == 2) {
			List<Node> results = new ArrayList<Node>();
			List<Node> visited = new ArrayList<Node>();
			List<Node> next = new ArrayList<Node>();
			visited.add(list[root]);
			for(Integer i : list[root].edges) {
				next.add(list[i]);
			}
		
			getChildrenToRemove(list, visited, next, results);
		
			return results.size();
		}
		int best = Integer.MAX_VALUE;
		for(Integer i : list[root].edges) {
			List<Node> results = new ArrayList<Node>();
			List<Node> visited = new ArrayList<Node>();
			List<Node> next = new ArrayList<Node>();
						
			Node[] nodeList = cloneNodelist(list);
			
			visited.add(nodeList[root]);
			//Chop off this branch
			results.add(nodeList[i]);
			visitChildren(nodeList, visited, results, i);
			for(Integer j : nodeList[root].edges) {
				if(!visited.contains(nodeList[j])) {
					next.add(nodeList[j]);
				}
			}
			
			getChildrenToRemove(nodeList, visited, next, results);
			
			if(results.size() < best) {
				best = results.size();
			}			
		}
		return best;
	}
	
	private static void getChildrenToRemove(Node[] list, List<Node> visited, List<Node> next, List<Node> results) {
		List<Node> nextRound = new ArrayList<Node>();
		for(Node n : next) {
			visited.add(n);
			if(n.edges.size() == 2) {				
				visitChildren(list, visited, results, n.id);
			}
			for(Integer i : n.edges) {
				if(!visited.contains(list[i])) {
					nextRound.add(list[i]);
				}
			}
		}
		if(nextRound.size() > 0) {
			getChildrenToRemove(list, visited, nextRound, results);
		}
	}
	
	private static void visitChildren(Node[] list, List<Node> visited, List<Node> results, int node) {
		for(Integer i : list[node].edges) {
			if(!visited.contains(list[i])) {
				visited.add(list[i]);
				results.add(list[i]);
				visitChildren(list, visited, results, i);
			}
		}
	}
	

}
