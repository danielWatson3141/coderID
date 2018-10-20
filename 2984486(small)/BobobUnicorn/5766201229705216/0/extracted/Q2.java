import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;

public class Q2 {
	public static class Pair {
		public int size;
		public int node;

		public Pair(int f, int s) {
			super();
			this.size = f;
			this.node = s;
		}
	}

	public static class PairComp implements Comparator<Pair> {
		@Override
		public int compare(Pair l, Pair r) {
			return l.size - r.size;
		}
	}
	
	public static int sizeof(ArrayList<HashSet<Integer>> graph, int start, int node) {
		int count = 1;
		for (Integer i : graph.get(node)) {
			if (i != start) {
				count += sizeof(graph, node, i);
			}
		}
		
		return count;
	}
	
	public static void delete(ArrayList<HashSet<Integer>> graph, int start, int node) {
		for (Integer i : new HashSet<Integer>(graph.get(node))) {
			if (i != start) {
				delete(graph, node, i);
			}
		}
		
		graph.get(node).clear();
		graph.get(start).remove(node);
	}

	// indirect to prevent stack overflow
	public static int prune(ArrayList<HashSet<Integer>> graph) {
		int nodesremoved = 0;
		int temp = pruneinternal(graph);
		while (temp > 0) {
			nodesremoved += temp;
			temp = pruneinternal(graph);
		}

		return nodesremoved;
	}

	public static int pruneinternal(ArrayList<HashSet<Integer>> graph) {
		int nodesremoved = 0;

		int N = graph.size();

		// check for single nodes connected to 2-child nodes
		// o - o - o
		for (int node = 0; node < N; node++) {
			HashSet<Integer> neigh = graph.get(node);
			if (neigh.size() == 1) {
				HashSet<Integer> nnode = graph.get(neigh.iterator().next());
				if (nnode.size() == 2) {
					for (Integer i : nnode) {
						if (i != node) {
							if (graph.get(i).size() != 1) {
								// remove it
								neigh.clear();
								nnode.remove(node);
								nodesremoved++;
								
								//System.out.println(node);

								return nodesremoved;
							}
						}
					}
				}
			}
		}

		// check for nodes with more than 3 children
		int lowestnode = -1;
		int lowesttreesize = Integer.MAX_VALUE;
		HashSet<Integer> toremove = null;
		for (int node = 0; node < N; node++) {
			HashSet<Integer> neighbours = graph.get(node);
			if (neighbours.size() > 3) {
				ArrayList<Pair> ps = new ArrayList<Pair>(neighbours.size());
				for (Integer neighbour : neighbours) {
					int size = sizeof(graph, node, neighbour);
					ps.add(new Pair(size, neighbour));
				}
				
				Collections.sort(ps, new PairComp());
				
				int nodecount = 0;
				HashSet<Integer> nodestoremove = new HashSet<Integer>();
				for (int size = neighbours.size(), idx = 0; size > 3; size--, idx++) {
					nodecount += ps.get(idx).size;
					nodestoremove.add(ps.get(idx).node);
				}
				
				if (nodecount < lowesttreesize) {
					lowesttreesize = nodecount;
					lowestnode = node;
					toremove = nodestoremove;
				}
			}
		}
		
		if (lowestnode != -1) {
			for (Integer node: toremove) {
				delete(graph, lowestnode, node);
			}
			
			nodesremoved += lowesttreesize;
			return nodesremoved;
		}

		// check for cycles

		return nodesremoved;
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("B-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"B-small-attempt2.out")));

		int T = in.nextInt();

		for (int c = 1; c <= T; c++) {
			int N = in.nextInt();

			ArrayList<HashSet<Integer>> graph = new ArrayList<HashSet<Integer>>(
					N);
			for (int n = 0; n < N; n++) {
				graph.add(new HashSet<Integer>());
			}

			for (int e = 0; e < N - 1; e++) {
				int nf = in.nextInt();
				int ns = in.nextInt();
				graph.get(nf - 1).add(ns - 1);
				graph.get(ns - 1).add(nf - 1);
			}

			int nodesremoved = prune(graph);

			out.printf("Case #%d: %d\n", c, nodesremoved);
		}

		in.close();
		out.close();

	}

}
