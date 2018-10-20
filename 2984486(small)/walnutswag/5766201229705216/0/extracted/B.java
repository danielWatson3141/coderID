package round1a;

import java.io.*;
import java.util.*;

public class B {

	public static void main(String[] args) throws IOException {

		String path = "B";

		BufferedReader in = new BufferedReader(new FileReader(Main.DIR + path + ".in"));
		PrintWriter out = new PrintWriter(Main.DIR + path + ".out");

		int inputs = Integer.parseInt(in.readLine());

		for (int i = 0; i < inputs; i++) {
			int N = Integer.parseInt(in.readLine());
			int[][] graph = new int[N][];

			for (int j = 0; j < N-1; j++) {
				String[] split = in.readLine().split(" ");
				int v1 = Integer.parseInt(split[0]) - 1;
				int v2 = Integer.parseInt(split[1]) - 1;

				addEdge(graph, v1, v2);
			}

			/*
			System.out.println(Arrays.deepToString(graph));
			System.out.println(isFull(graph));
			int[][] g = removeVertex(graph, 1);
			g = removeVertex(g, 2);
			System.out.println(isFull(g));
			 */
			
			HashSet<String> visited = new HashSet<>();
			Queue<int[][]> queue = new LinkedList<>();
			queue.add(graph);
			int dist = 0;
			int front = 1;
			
			search: while (!queue.isEmpty()) {
				int newFront = 0;
				
				for (int j = 0; j < front; j++) {
					int[][] cur = queue.remove();
					if (visited.contains(toString(cur)))
						continue;
					
					if (isFull(cur))
						break search;

					visited.add(toString(cur));
					
					for (int k = 0; k < graph.length; k++) {
						if (cur[k] != null) {
							int[][] g = removeVertex(cur, k);
							if (!visited.contains(toString(g))) {
								queue.add(g);
								newFront++;
							}
								
						}
					}
				}

				
				front = newFront;
				dist++;
			}

			String ans = "Case #"+(i+1)+": "+dist;
			System.out.println(ans);
			out.println(ans);
		}

		in.close();
		out.close();

	}
	
	public static String toString(int[][] g) {
		StringBuilder b = new StringBuilder();
		for (int i = 0; i < g.length; i++) {
			if (g[i] != null)
				b.append(i+" ");
		}
		return b.toString();
	}

	public static int helper(int[][] graph) {
		if (isFull(graph))
			return 0;
		int min = Integer.MAX_VALUE;
		int[][] minGraph = null;
		for (int i = 0; i < graph.length; i++) {
			if (graph[i] == null)
				continue;
			int cost = 1 + helper1(removeVertex(graph, i));
			if (cost < min) {
				min = cost;
				minGraph = removeVertex(graph, i);
			}

		}

		return min;
	}

	public static int helper1(int[][] graph) {
		if (isFull(graph))
			return 0;
		
		int min = Integer.MAX_VALUE;

		for (int i = 0; i < graph.length; i++) {
			if (graph[i] == null)
				continue;
			int cost = 1 + helper1(removeVertex(graph, i));
			if (cost < min) {
				min = cost;
			}

		}

		return min;
	}


	public static int[][] removeVertex(int[][] graph, int v) {
		int[][] ans = new int[graph.length][];
		for (int i = 0; i < ans.length; i++) {
			if (i == v || graph[i] == null)
				ans[i] = null;
			else {
				if (contains(graph[i], v)) {
					ans[i] = new int[graph[i].length-1];
					int idx = 0;
					for (int t = 0; t < graph[i].length; t++) {
						if (graph[i][t] == v)
							continue;
						ans[i][idx++] = graph[i][t];
					}
				}
				else
					ans[i] = Arrays.copyOf(graph[i], graph[i].length);
			}
		}

		return ans;
	}

	public static boolean contains(int[] a, int v) {
		for (int n : a) {
			if (v == n)
				return true;
		}
		return false;
	}

	public static void addEdge(int[][] graph, int v1, int v2) {
		if (graph[v1] == null)
			graph[v1] = new int[]{v2};
		else {
			graph[v1] = Arrays.copyOf(graph[v1], graph[v1].length+1);
			graph[v1][graph[v1].length-1] = v2;
		}

		if (graph[v2] == null)
			graph[v2] = new int[]{v1};
		else {
			graph[v2] = Arrays.copyOf(graph[v2], graph[v2].length+1);
			graph[v2][graph[v2].length-1] = v1;
		}
	}

	public static boolean isFull(int[][] graph) {

		search: for (int v = 0; v < graph.length; v++) {
			if (graph[v] == null)
				continue;

			boolean[] visited = new boolean[graph.length];
			Queue<Integer> queue = new LinkedList<>();
			queue.add(v);

			while (!queue.isEmpty()) {
				int cur = queue.remove();
				if (visited[cur])
					continue;
				visited[cur] = true;

				int added = 0;
				int[] neighbors = graph[cur];
				for (int neighbor : neighbors) {
					if (!visited[neighbor]) {
						queue.add(neighbor);
						added++;
					}
				}
				if (added != 2 && added != 0)
					continue search;
			}

			for (int i = 0; i < visited.length; i++) {
				if (!visited[i] && graph[i] != null)
					continue search;
			}
			return true;
		}
	
		return false;
	}
}
