import java.util.*;


public class Round1A2 {
	
	static Scanner scan;
	static int N;
	
	public static void main(String[] args) {
		scan = new Scanner(System.in);
		int cases = scan.nextInt();
		for(int i = 1; i <= cases; ++i) {
			System.out.print("Case #" + i + ": ");
			doCase();
		}
	}
	
	static void doCase() {
		N = scan.nextInt();
		Node[] nodes = new Node[N];
		for(int i = 0; i < N; ++i) {
			nodes[i] = new Node(i);
		}
		for(int i = 0; i < N-1; ++i) {
			int n1 = scan.nextInt() - 1;
			int n2 = scan.nextInt() - 1;
			nodes[n1].originalChildren.add(nodes[n2]);
			nodes[n2].originalChildren.add(nodes[n1]);
		}
		int largest = 0;
		for(int i = 0; i < N; ++i) {
			int l = tryRoot(i, nodes);
			if(l > largest) largest = l;
		}
		System.out.println(N-largest);
	}
	
	static int tryRoot(int root, Node[] nodes) {
		for(int i = 0; i < N; ++i) {
			nodes[i].visited = false;
		}
		nodes[root].Prepare();
		nodes[root].makeBinary();
		return nodes[root].size();
	}
	
	
	private static class Node {
		
		boolean visited;
		ArrayList<Node> children;
		ArrayList<Node> originalChildren;
		int index;
		
		public Node(int i) {
			index = i;
			originalChildren = new ArrayList<Node>();
		}
		
		void Prepare() {
			children = new ArrayList<Node>();
			visited = true;
			for(Node n : originalChildren) {
				if(n.visited) continue;
				children.add(n);
				n.Prepare();
			}
		}
		
		int size() {
			int s = 1;
			for (Node n : children) {
				s+=n.size();
			}
			return s;
		}
		
		void makeBinary() {
			for(Node n : children) {
				n.makeBinary();
			}
			while(children.size() > 2 || children.size() == 1) {
				deleteSmallestChild();
			}
			
		}
		
		void deleteSmallestChild() {
			Node smallest = null;
			int minSize = Integer.MAX_VALUE;
			for(Node n : children) {
				int currSize = n.size();
				if(currSize < minSize) {
					minSize = currSize;
					smallest = n;
				}
			}
			children.remove(smallest);
		}
		
		public boolean equals(Node n) {
			return index == n.index;
		}
	}

}
