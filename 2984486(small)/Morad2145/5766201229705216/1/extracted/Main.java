package tree;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(
				"B-large.in"));

		int T = Integer.parseInt(in.readLine());

		for (int x = 1; x <= T; x++) {
			int N = Integer.parseInt(in.readLine());

			Edge[] edges = new Edge[N - 1];
			for (int i = 0; i < N - 1; i++) {
				edges[i] = new Edge(in.readLine());
			}

			long answer = findAnswer(N, edges);

			System.out.println("Case #" + x + ": " + answer);
		}

		in.close();
	}

	private static long findAnswer(int N, Edge[] edges) {
		int minCost = N;
		for (int root = 1; root <= N; root++) {
			Tree tree = new Tree(root, edges, -1);
			if (tree.costOfBinarification < minCost) {
				minCost = tree.costOfBinarification;
			}
		}
		return minCost;
	}

	private static class Edge {
		final int node1, node2;

		public Edge(String line) {
			String[] tokens = line.split(" ");

			this.node1 = Integer.parseInt(tokens[0]);
			this.node2 = Integer.parseInt(tokens[1]);
		}

	}

	private static class Tree {

		final int root;
		final ArrayList<Tree> children;
		final int costOfBinarification;
		final int size;

		public Tree(int root, Edge[] edges, int parent) {
			this.root = root;
			this.children = new ArrayList<Tree>();
			for (Edge e : edges) {
				if (e.node1 == root && e.node2 != parent) {
					children.add(new Tree(e.node2, edges, this.root));
				}
				if (e.node2 == root && e.node1 != parent) {
					children.add(new Tree(e.node1, edges, this.root));
				}
			}

			int size = 1;
			for (Tree t : children) {
				size += t.size;
			}
			this.size = size;

			if (children.size() == 0) {
				costOfBinarification = 0;
			} else if (children.size() == 1) {
				costOfBinarification = children.get(0).size;
			} else {
				Collections.sort(children, new Comparator<Tree>() {
					public int compare(Tree t1, Tree t2) {
						return Integer.compare(t1.costOfBinarification
								- t1.size, t2.costOfBinarification - t2.size);
					}
				});
				int sum = 0;
				for (int i = 0; i < children.size(); i++) {
					sum += children.get(i).size;
				}
				for (int i = 0; i < 2; i++) {
					sum -= children.get(i).size;
					sum += children.get(i).costOfBinarification;
				}
				costOfBinarification = sum;

			}
		}
	}
}
