import java.util.ArrayList;
import java.util.Scanner;

public class B {
	private static class Node {
		private ArrayList<Node> edges = new ArrayList<Node>();
		boolean visited = false;
		static int[] tempres = new int[2];

		int numDeletes() {
			visited = true;
			int childCount = 0;
			int mySize = 1;
			int best = 0;
			int secbest = 0;
			for (Node n : edges) {
				if (!n.visited) {
					childCount++;
					n.numDeletes();
					mySize += tempres[0];
					if (tempres[0] - tempres[1] > best) {
						secbest = best;
						best = tempres[0] - tempres[1];
					} else if (tempres[0] - tempres[1] > secbest) {
						secbest = tempres[0] - tempres[1];
					}
				}
			}
			tempres[0] = mySize;
			if (childCount < 2) {
				tempres[1] = mySize - 1;
			} else {
				tempres[1] = mySize - (best + secbest + 1);
			}
			return tempres[1];
		}
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int numCases = scan.nextInt();
		for (int caseNum = 1; caseNum <= numCases; caseNum++) {
			System.out.printf("Case #%d: ", caseNum);
			System.out.println(solve(scan));
		}
	}

	private static int solve(Scanner scan) {
		int numNodes = scan.nextInt();
		Node[] nodes = new Node[numNodes];
		for (int i = 0; i < numNodes; i++) {
			nodes[i] = new Node();
		}
		for (int i = 0; i < numNodes - 1; i++) {
			addEdge(nodes[scan.nextInt() - 1], nodes[scan.nextInt() - 1]);
		}
		int minDeletes = Integer.MAX_VALUE;
		for (int i = 0; i < numNodes; i++) {
			int curDeletes = nodes[i].numDeletes();
			minDeletes = Math.min(minDeletes, curDeletes);
			for (int j = 0; j < numNodes; j++) {
				nodes[j].visited = false;
			}
		}
		return minDeletes;
	}

	private static void addEdge(Node node1, Node node2) {
		node1.edges.add(node2);
		node2.edges.add(node1);
	}
}
