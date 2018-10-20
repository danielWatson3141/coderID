package google.codejam._2014.round_1A;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FullBinaryTree {
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("src/inb.txt"));
		PrintWriter out = new PrintWriter("outb.txt");

		int t = in.nextInt();
		in.nextLine();

		for (int tc = 1; tc <= t; tc++) {
			int n = in.nextInt();

			List<Integer>[] adj = new List[n + 1];

			for (int i = 1; i < n; i++) {
				in.nextLine();
				int u = in.nextInt();
				int v = in.nextInt();

				if (adj[u] == null) {
					adj[u] = new ArrayList<Integer>();
				}

				if (adj[v] == null) {
					adj[v] = new ArrayList<Integer>();
				}

				adj[u].add(v);
				adj[v].add(u);
			}

			int minCount = n - 1;

			for (int i = 1; i <= n; i++) {
				boolean[] viz = new boolean[n + 1];
				boolean[] deleted = new boolean[n + 1];

				bfs(i, adj, viz, deleted);

				int count = 0;
				for (int j = 1; j <= n; j++) {
					if (deleted[j]) {
						count++;
					}
				}

				if (count < minCount) {
					minCount = count;
					System.out.println(tc + ": root " + i);
				}
			}

			out.println("Case #" + tc + ": " + minCount);
		}

		in.close();
		out.close();
	}

	private static void bfs(int v, List<Integer>[] adj, boolean[] viz,
			boolean[] deleted) {
		List<Integer> queue = new ArrayList<Integer>();
		queue.add(v);
		viz[v] = true;

		while (queue.size() > 0) {
			int crt = queue.remove(0);
			int count = 0;

			for (Integer neigh : adj[crt]) {
				if (!viz[neigh]) {
					queue.add(neigh);
					count++;
					if (deleted[crt]) {
						deleted[neigh] = true;
					}
				}
			}

			if (count % 2 != 0) {
				for (Integer neigh : adj[crt]) {
					if (!viz[neigh]) {
						deleted[neigh] = true;
						viz[neigh] = true;
					}
				}
			} else {
				for (Integer neigh : adj[crt]) {
					if (!viz[neigh]) {
						viz[neigh] = true;
					}
				}
			}
		}
	}
}
