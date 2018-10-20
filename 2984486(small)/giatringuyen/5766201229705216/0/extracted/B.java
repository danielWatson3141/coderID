import java.io.File;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class B {
	public static void main (String[] args) throws Exception {
		Scanner sc = new Scanner(new File("B-small-attempt2.in.txt"));
		PrintWriter writer = new PrintWriter("B-small-attempt2.out.txt", "UTF-8");
		//Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			int N = sc.nextInt();
			Node[] nodes = new Node[N];
			for (int i = 0; i < N; ++i) {
				nodes[i] = new Node(i);
			}
			for (int i = 0; i < N - 1; ++i) {
				int x = sc.nextInt() - 1;
				int y = sc.nextInt() - 1;
				nodes[x].neighbors.add(nodes[y]);
				nodes[y].neighbors.add(nodes[x]);
			}
			
			writer.println("Case #" + t + ": " + solve(nodes));
		}
		writer.close();
	}
	
	private static class Node {
		public int ind;
		public List<Node> neighbors = new LinkedList<Node>();
		
		public Node(int ind) {
			this.ind = ind;
		}
		
		@Override
		public boolean equals(Object that) {
			return that != null &&
				   this.getClass() == that.getClass() &&
				   this.ind == ((Node)that).ind;
		}
	}
	
	private static int solveHelper(Node cur, Node parent) {
		if (cur.neighbors.size() <= 1 ||
			(cur.neighbors.size() == 2 && parent != null)) {
			return 1;
		}
		
		LinkedList<Integer> max2 = new LinkedList<Integer>();
		
		for (Node child : cur.neighbors) {
			if (!child.equals(parent)) {
				int subTreeCnt = solveHelper(child, cur);
				if (max2.size() == 0 || (max2.size() == 1 && max2.getFirst() >= subTreeCnt)) {
					max2.addLast(subTreeCnt);
				} else if (max2.getFirst() < subTreeCnt) {
					max2.addFirst(subTreeCnt);
				}
				if (max2.size() == 3) {
					max2.removeLast();
				}
			}
		}

		return max2.getFirst() + max2.getLast() + 1;
	}
	
	private static int solve(Node[] nodes) {
		int max = 0;
		for (Node cur : nodes) {
			max = Math.max(max, solveHelper(cur, null));
		}
		
		return nodes.length - max;
	}
}
