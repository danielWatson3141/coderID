import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class B {
	static class E {
		int v;
		int d;
		public E(int v, int d) {
			super();
			this.v = v;
			this.d = d;
		}
	}

	public static void dfs1(ArrayList<Integer>[] adj, int[] depths, int[] treesize, int node) {
		int count = 1;
		for (int v : adj[node]) {
			if (depths[v] > depths[node]) {
				dfs1(adj, depths, treesize, v);
				count += treesize[v];
			}
		}
		treesize[node] = count;
	}
	public static int dfs(ArrayList<Integer>[] adj, int[] depths, int[] treesize, int node) {
		int numchild = adj[node].size();
		if (depths[node] > 0) {
			numchild -= 1;
		}
		
		if (numchild <= 1) {
			return treesize[node] - 1;
		}
		
		ArrayList<Integer> costs = new ArrayList<Integer>();
		for (int child : adj[node]) {
			if (depths[child] > depths[node]) {
				costs.add(- treesize[child] + dfs(adj, depths, treesize, child));
			}
		}
		Collections.sort(costs);
		return treesize[node] + costs.get(0) + costs.get(1) - 1;
	}
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("B-large.in"));
		int ncases = sc.nextInt();
		for (int csnum = 1; csnum <= ncases; csnum++) {
			int n = sc.nextInt();
			ArrayList<Integer>[] adj = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				adj[i] = new ArrayList<Integer>();
			}
			for (int i = 0; i < n-1; i++) {
				int v1 = sc.nextInt() - 1;
				int v2 = sc.nextInt() - 1;
				adj[v1].add(v2);
				adj[v2].add(v1);
			}
			int best = n;
			int[] depths = new int[n];
			int[] treesize = new int[n];
			LinkedList<E> q = new LinkedList<E>();
			for (int root = 0; root < n; root++) {
				// compute depths
				Arrays.fill(depths, n);
				q.push(new E(root, 0));
				while (!q.isEmpty()) {
					E curr = q.poll();
					depths[curr.v] = curr.d;
					for (int v : adj[curr.v]) {
						if (depths[v] > curr.d) {
							q.push(new E(v, curr.d+1));
						}
					}
				}
				// compute tree size at each node
				dfs1(adj, depths, treesize, root);

				best = Math.min(best, dfs(adj, depths, treesize, root));
			}
			System.out.println("Case #" + csnum + ": " + best);
		}
	}
}
