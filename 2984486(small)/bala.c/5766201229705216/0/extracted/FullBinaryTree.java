package jam14.r1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Collection;
import java.util.Set;
import java.util.TreeSet;

import com.gaurav.tree.KAryTree;
import com.gaurav.tree.NodeNotFoundException;
import com.google.common.collect.HashMultimap;
import com.google.common.collect.Multimap;

public class FullBinaryTree {

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader("B-small-attempt2.bin"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("B-small-attempt2.out"));
		int t = Integer.parseInt(reader.readLine());
		for (int i = 0; i < t; i++) {
			int n = Integer.parseInt(reader.readLine());
			Multimap<Integer, Integer> edges = HashMultimap.create();
			for (int j = 0; j < n - 1; j++) {
				String[] inps = reader.readLine().split(" ");
				int node1 = Integer.parseInt(inps[0]);
				int node2 = Integer.parseInt(inps[1]);
				edges.put(node1, node2);
				edges.put(node2, node1);
			}
			System.out.println(edges);
			Set<Integer> vertices = edges.keySet();
			TreeSet<Integer> counts = new TreeSet<>();
			for (Integer vertex : vertices) {
				int leafCount = leafCount(vertex, edges);
				counts.add(leafCount);
				// System.out.println(vertex + "\t" + leafCount);
			}
			writer.write(new StringBuilder("Case #").append(i + 1).append(": ").append(counts.iterator().next()).append('\n')
					.toString());
			// System.out.println(counts.iterator().next());
		}
		reader.close();
		writer.close();
	}

	static int leafCount(Integer vertex, Multimap<Integer, Integer> edges) throws NodeNotFoundException {
		int count = 0;
		Set<Integer> keys = edges.keySet();
		int[] counts = new int[keys.size()];
		for (Integer node : keys) {
			counts[count++] = edges.get(node).size();
		}
		Arrays.sort(counts);
		int max = counts[counts.length - 1];

		KAryTree<Integer> tree = new KAryTree<>(max);
		tree.add(vertex);
		insertNodes(vertex, edges, tree);

		count = 0;
		for (Integer node : keys) {
			int size = tree.children(node).size();
			if (size != 2 && size != 0) {
				count++;
			}
		}
		return count;
	}

	static void insertNodes(Integer node, Multimap<Integer, Integer> edges, KAryTree<Integer> tree) throws NodeNotFoundException {
		Collection<Integer> children = edges.get(node);
		Integer parent = tree.parent(node);
		for (Integer child : children) {
			if (child != parent) {
				tree.add(node, child);
				insertNodes(child, edges, tree);
			}
		}
	}
}
