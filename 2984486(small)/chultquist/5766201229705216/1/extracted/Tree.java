import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Tree {
	static int n;
	static ArrayList<Integer>[] edges;
	static int subtreeCost[][];
	static int solveCost[][];
	
	static int subtree(int root, int parent)
	{
		if (subtreeCost[root][parent] == -1) {
			subtreeCost[root][parent] = _subtree(root, parent);
		}
		return subtreeCost[root][parent];
	}

	static int solve(int root, int parent)
	{
		if (solveCost[root][parent] == -1) {
			solveCost[root][parent] = _solve(root, parent);
		}
		return solveCost[root][parent];
	}

	static int _subtree(int root, int parent)
	{
		int result = 1;
		for (int i = 0; i < edges[root].size(); i++) {
			int node = edges[root].get(i);
			if (node != parent) {
				result += subtree(node, root);
			}
		}
		return result;
	}
	
	static int _solve(int root, int parent)
	{
		int children = edges[root].size();
		if (parent != root) {
			children--;
		}
		
		if (children == 0) {
			return 0;
		}
		else if (children == 2) {
			int cost = 0;
			for (int i = 0; i < edges[root].size(); i++) {
				int node = edges[root].get(i);
				if (node != parent) {
					cost += solve(node, root);
				}
			}
			return cost;
		}
		else if (children == 1) {
			// Need to cull the only child.
			for (int i = 0; i < edges[root].size(); i++) {
				int node = edges[root].get(i);
				if (node != parent) {
					return subtree(node, root);
				}
			}
			assert(false);
			return 0;
		}
		else {
			// children > 2
			//
			// Need to determine which ones to cull.
			ArrayList<Integer> subtreeCount = new ArrayList<>();
			ArrayList<Integer> costs = new ArrayList<>();
			for (int i = 0; i < edges[root].size(); i++) {
				int node = edges[root].get(i);
				if (node != parent) {
					costs.add(solve(node, root));
					subtreeCount.add(subtree(node, root));
				}
			}
			
			int best = -1;
			for (int i = 0; i < costs.size(); i++) {
				for (int j = i + 1; j < costs.size(); j++) {
					int cost = costs.get(i) + costs.get(j);
					for (int k = 0; k < costs.size(); k++) {
						if (i != k && j != k) {
							cost += subtreeCount.get(k);
						}
					}
					if (best == -1 || cost < best) {
						best = cost;
					}
				}
			}
			return best;
		}
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int caseNum = 1; caseNum <= t; caseNum++) {
			int n = sc.nextInt();
			edges = new ArrayList[n];
			subtreeCost = new int[n][n];
			solveCost = new int[n][n];
			for (int i = 0; i < n; i++) {
				edges[i] = new ArrayList<>();
				for (int j = 0; j < n; j++) {
					subtreeCost[i][j] = -1;
					solveCost[i][j] = -1;
				}
			}
			for (int i = 1; i < n; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				x--; y--;
				edges[x].add(y);
				edges[y].add(x);
			}
		
			int best = -1;
			for (int i = 0; i < n; i++) {
				int cost = solve(i, i);
				//System.err.println("Cost of " + cost + " for " + i + " as root");
				if (best == -1 || cost < best) {
					best = cost;
				}
			}
			
			System.out.println("Case #" + caseNum + ": " + best);
		}
	}
}
