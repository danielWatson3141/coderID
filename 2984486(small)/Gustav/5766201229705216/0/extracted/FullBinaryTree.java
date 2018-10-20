package gustafson.ryan;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FullBinaryTree {
    private final BufferedReader reader;
    private final PrintWriter writer;

    public FullBinaryTree(String file) throws IOException {
	reader = new BufferedReader(new FileReader(file));
	writer = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));
    }

    public void solve() throws IOException {
	int numCases = readInt();
	for (int i = 0; i < numCases; i++) {
	    int numNodes = readInt();
	    System.out.println("Case " + (i + 1));

	    Map<Integer, List<Integer>> nodeToAdjacents = new HashMap<>();

	    int[] twoNodes = new int[2];
	    for (int j = 0; j < numNodes - 1; j++) {
		read(twoNodes);
		addAdjacent(nodeToAdjacents, twoNodes[0], twoNodes[1]);
		addAdjacent(nodeToAdjacents, twoNodes[1], twoNodes[0]);
	    }

	    // For each node, check to see if it could be a binary tree root.
	    int minRemoved = Integer.MAX_VALUE;
	    for (int node = 1; node <= numNodes; node++) {
		// Node many nodes in the binary tree starting from here?
		//System.out.println("root: " + node);
		int size = countBinaryTreeNodes(nodeToAdjacents, -1, node);
		minRemoved = Math.min(minRemoved, numNodes - size);
	    }
	    System.out.println(minRemoved);

	    writeCase(i + 1);
	    writer.print(" ");
	    writer.print(minRemoved);
	    writer.println();
	}
	writer.flush();
	writer.close();
    }

    private int countBinaryTreeNodes(Map<Integer, List<Integer>> nodeToAdjacents, int parent, int node) {
	List<Integer> adjacents = nodeToAdjacents.get(node);
//	System.out.println("(" + parent + ") " + node + " -> " + adjacents);
	int count = adjacents.size();
	if (adjacents.contains(parent)) {
	    count--;
	}
	//System.out.println("count = " + count);
	if (count == 0) {
//	    System.out.println("+1");
	    return 1;
	} else if (count == 1) {
	    return 1; // Cut from below, count me as 1
//	} else if (count == 2) {
//	    int child1 = adjacents.get(0);
//	    int child2 = adjacents.get(1);
//	    if (child1 == parent) {
//		child1 = adjacents.get(2);
//	    } else if (child2 == parent) {
//		child2 = adjacents.get(2);
//	    }
//	    int total = 1 + countBinaryTreeNodes(nodeToAdjacents, node, child1)
//		    + countBinaryTreeNodes(nodeToAdjacents, node, child2);
//	    //System.out.println("+" + total);
//	    return total;
	} else { //if (count >= 2) {
	    // Pick the children each with the maximum size.
	    int max1 = 0;
	    int max2 = 0;

	    for (int i =0; i < adjacents.size();i++) {
		int child = adjacents.get(i);
		if (child == parent) {
		    continue;
		}
		int size = countBinaryTreeNodes(nodeToAdjacents, node, child);
		if (size > max1) {
		    max2 = max1;
		    max1 = size;
		} else if (size > max2){
		    max2 = size;
		}
	    }
	    
	    return 1 + max1 + max2;
	}
    }

    private void addAdjacent(Map<Integer, List<Integer>> nodeToAdjacents, int first, int second) {
	List<Integer> adjacents = nodeToAdjacents.get(first);
	if (adjacents == null) {
	    adjacents = new ArrayList<>(3);
	    nodeToAdjacents.put(first, adjacents);
	}
	adjacents.add(second);
    }

    private void writeCase(int n) {
	writer.print("Case #");
	writer.print(n);
	writer.print(": ");
    }

    private int readInt() throws IOException {
	return Integer.parseInt(reader.readLine().trim());
    }

    private void read(int[] array) throws IOException {
	String line = reader.readLine();
	String[] split = line.split(" ");
	for (int i = 0; i < split.length; i++) {
	    array[i] = Integer.parseInt(split[i]);
	}
    }

    public static void main(String[] args) throws Exception {
	String file = "B-test.in";
			file = "B-small-attempt1.in";
	//		file = "B-large.in";
	FullBinaryTree fullBinaryTree = new FullBinaryTree(file);
	fullBinaryTree.solve();
    }
}
