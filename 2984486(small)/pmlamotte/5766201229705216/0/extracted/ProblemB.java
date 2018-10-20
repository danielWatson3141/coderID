import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;


/**
 * @author Paul LaMotte
 *
 */
public class ProblemB {

	public static void main(String[] args) {
		try {
			System.setOut(new PrintStream(new FileOutputStream("ProblemB.out")));
			Scanner scan = new Scanner(new FileInputStream("ProblemB.in"));
			int cases = new Scanner(scan.nextLine()).nextInt();
			for (int l = 0; l < cases; l++) {
				int numNodes = scan.nextInt();
				int[][] tree = new int[numNodes][numNodes];
				for (int i = 0; i < numNodes - 1; i++) {
					int n1 = scan.nextInt() - 1;
					int n2 = scan.nextInt() - 1;
					tree[n1][n2] = 1;
					tree[n2][n1] = 1;
				}
				
				int sol = Integer.MAX_VALUE;
				for (int i = 0; i < numNodes; i++) {
					int newSol = solve(tree, i);
					//System.out.println("root: " + (i + 1) + " " + newSol);
					sol = Math.min(newSol, sol);
				}
				
				//System.out.println("tree");
				for (int i = 0; i < tree.length; i++) {
					//System.out.println(Arrays.toString(tree[i]));
				}
				
				System.out.printf("Case #%d: %d%n", l+1, sol);
			}
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static int solve(int[][] tree, int root) {
		int[][] treeCopy = new int[tree.length][tree.length];
		for (int i = 0; i < tree.length; i++) {
			treeCopy[i] = Arrays.copyOf(tree[i], tree.length);
		}
		HashSet<Integer> seen = new HashSet<Integer>();
		LinkedList<Integer> list = new LinkedList<Integer>();
		list.add(root);
		seen.add(root);
		LinkedList<Integer> traverse = new LinkedList<Integer>();
		traverse.add(root);
		while (list.size() > 0) {
			int node = list.poll();
			for (int i = 0; i < tree.length; i++) {
				if (tree[node][i] == 1 && !seen.contains(i)) {
					list.add(i);
					seen.add(i);
					traverse.addFirst(i);
					treeCopy[i][node] = 0;
					//System.out.println("node: " + (node+1) + " i: " + i);
				}
			}
		}
		for (int i = 0; i < tree.length; i++) {
			//System.out.println(Arrays.toString(treeCopy[i]));
		}
		
		int count = 0;
		while (traverse.size() > 0) {
			int node = traverse.poll();
			int numNodes = 0;
			for (int i = 0; i < tree.length; i++) {
				if (treeCopy[node][i] == 1) {
					numNodes++;
				}
			}
			//System.out.println("node: " + node + " numNodes: " + numNodes);
			if (numNodes == 0) {
				
			}
			else if (numNodes < 2) {
				for (int i = 0; i < tree.length; i++) {
					if (treeCopy[node][i] == 1) {
						count += purge(treeCopy, i);
					}
				}
			} else if (numNodes > 2) {
				while (numNodes > 2) {
					int idx = -1;
					int cost = Integer.MAX_VALUE;
					for (int i = 0; i < tree.length; i++) {
						if (treeCopy[node][i] == 1) {
							int newCost = purgeCost(treeCopy, i);
							if (newCost < cost) {
								cost = newCost;
								idx = i;
							}
						}
					}
					numNodes--;
					count += purge(treeCopy, idx);
				}
			} else {
				for (int i = 0; i < tree.length; i++) {
					if (treeCopy[node][i] == 1) {
						//traverse.add(i);
					}
				}
			}
		}
		
		
		return count;
	}
	
	public static int purgeCost(int[][] tree, int node) {
		int count = 0;
		LinkedList<Integer> list = new LinkedList<Integer>();
		list.add(node);
		while (list.size() > 0 ) {
			int next = list.poll();
			count++;
			for (int i = 0; i < tree.length; i++) {
				if (tree[next][i] == 1) {
					list.add(i);
				}
			}
		}
		
		return count;
	}
	
	public static int purge(int[][] tree, int node) {
		int count = 0;
		for (int i = 0; i < tree.length; i++) {
			if (tree[i][node] == 1) {
				tree[i][node] = 0;
			}
		}
		
		LinkedList<Integer> list = new LinkedList<Integer>();
		list.add(node);
		while (list.size() > 0) {
			int next = list.poll();
			count++;
			for (int i = 0; i < tree.length; i++) {
				if (tree[next][i] == 1) {
					list.add(i);
					tree[next][i] = 0; 
				}
			}
		}
		
		return count;
	}
}
