import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class FullBinaryTree {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			int N = in.nextInt();
			Node[] nodes = new Node[N];
			for (int j = 0; j < N; j++) {
				nodes[j] = new Node(j + 1);
			}
			for (int j = 0; j < N - 1; j++) {
				int X = in.nextInt();
				int Y = in.nextInt();
				nodes[X-1].addLink(nodes[Y-1]);
				nodes[Y-1].addLink(nodes[X-1]);				
			}
			System.out.println("Case #" + (i + 1) + ": " + solve(nodes));
		}
		in.close();
	}

	private static int solve(Node[] nodes) {
		int bestResult = Integer.MAX_VALUE;
		
		for (int i = 0; i < nodes.length; i++) {
			//System.out.println();
			//System.out.println("Trying node " + (i+1) + " as root");
			Node root = nodes[i];
			for (int j = 0; j < nodes.length; j++) {
				nodes[j].parent = null;
				nodes[j].children = new LinkedList<Node>();
			}
			buildRootedTree(root); //populate children
			/*for (int j = 0; j < nodes.length; j++) {
				System.out.println(nodes[j]);
			}*/
			int result = getNodesToDeleteFrom(root);
			
			//System.out.println("Result: " + result);
			
			if (result < bestResult) {
				bestResult = result;
				if (bestResult == 0) {
					break;
				}
			}
		}
		
		return bestResult;
	}

	private static void buildRootedTree(Node parent) {
		for (Node node : parent.linkedNodes) {
			if (parent.parent != node) {
				parent.children.add(node);
				node.parent = parent;
				buildRootedTree(node);
			}
		}
	}

	private static int getNodesToDeleteFrom(Node node) {
		if (node.children.size() == 0) {
			return 0;
		} else if (node.children.size() == 1) {
			return 1 + getRecursiveChildren(node.children.get(0));
		} else if (node.children.size() == 2) {
			return getNodesToDeleteFrom(node.children.get(0)) + getNodesToDeleteFrom(node.children.get(1));
		} else {
			int bestResult = Integer.MAX_VALUE;
			//we will have to remove all but 2
			for (int saved1 = 0; saved1 < node.children.size(); saved1++) {
				for (int saved2 = 0; saved2 < node.children.size(); saved2++) {
					if (saved1 == saved2) {
						continue;
					}
					int result = 0;
					for (int child = 0; child < node.children.size(); child++) {
						if (child != saved1 && child != saved2) {
							result += 1 + getRecursiveChildren(node.children.get(child));
						} else {
							result += getNodesToDeleteFrom(node.children.get(child));
						}
					}
					if (result < bestResult) {
						bestResult = result;
					}
				}
			}
			return bestResult;
		}
	}

	private static int getRecursiveChildren(Node node) {
		int result = 0;
		for (Node child : node.children) {
			result++;
			result += getRecursiveChildren(child);
		}
		return result;
	}
}

class Node {
	
	int index;
	List<Node> linkedNodes;
	
	Node parent;
	List<Node> children;
	
	public Node(int index) {
		this.index = index;
		linkedNodes = new LinkedList<Node>();
		children = new LinkedList<Node>();
	}
	
	public void addLink(Node other) {
		linkedNodes.add(other);
	}
	
	public String toString() {
		String result = "Node " + index;// + " connected to ";
		/*for (Node node : linkedNodes) {
			result += node.index + ",";
		}*/
		if (parent != null) {
			result += "\nWith parent " + parent.index + " and children ";
		} else {
			result += "\nWith children ";
		}
		for (Node node : children) {
			result += node.index + ",";
		}
		return result;
	}
}