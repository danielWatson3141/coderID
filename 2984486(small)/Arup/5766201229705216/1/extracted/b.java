import java.util.*;

public class b {

	public static int[] numNodes;

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {

			int n = stdin.nextInt();
			ArrayList[] g = new ArrayList[n];
			for (int i=0; i<n; i++)
				g[i] = new ArrayList<Integer>();

			for (int i=0; i<n-1; i++) {
				int v1 = stdin.nextInt()-1;
				int v2 = stdin.nextInt()-1;
				g[v1].add(v2);
				g[v2].add(v1);
			}


			int best = n;

			// Try root to be i.
			for (int i=0; i<n; i++) {

				boolean[] used = new boolean[n];
				numNodes = new int[n];
				fillNumNodes(g, i, used);

				boolean[] visited = new boolean[n];
				int ans = solveRec(g, i, visited);
				//System.out.println(i+" "+ans);
				if (ans == -1) continue;

				if (ans < best)
					best = ans;
			}

			System.out.println("Case #"+loop+": "+best);
		}
	}

	public static int solveRec(ArrayList[] g, int node, boolean[] visited) {

		visited[node] = true;
		int numChildren = 0;
		ArrayList<pair> sizes = new ArrayList<pair>();

		for (int i=0; i<g[node].size(); i++) {
			int child = (Integer)(g[node].get(i));
			if (!visited[child]) {
				numChildren++;
				sizes.add(new pair(child, numNodes[child]));
			}
		}

		if (numChildren == 0) return 0;
		if (numChildren == 1) return numNodes[node]-1;

		Collections.sort(sizes);

		int ans = 0;
		ans += solveRec(g, sizes.get(0).id, visited);
		ans += solveRec(g, sizes.get(1).id, visited);

		for (int i=2; i<sizes.size(); i++)
			ans += numNodes[sizes.get(i).id];

		return ans;
	}

	public static void fillNumNodes(ArrayList[] g, int node, boolean[] used) {

		int cnt = 1;
		used[node] = true;
		for (int i=0; i<g[node].size(); i++) {
			int child = (Integer)(g[node].get(i));
			if (!used[child])
				fillNumNodes(g, child, used);
			cnt += numNodes[child];
		}
		numNodes[node] = cnt;
	}
}

class pair implements Comparable<pair> {

	public int id;
	public int len;

	public pair(int index, int size) {
		id = index;
		len = size;
	}

	public int compareTo(pair other) {
		return other.len - this.len;
	}
}