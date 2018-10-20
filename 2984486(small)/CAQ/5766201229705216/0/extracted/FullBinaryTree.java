package gcj2014;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class FullBinaryTree {
	static String PATH = "data/gcj2014/1a/", PROBLEM = "B", SIZE = "small",
			ATTEMPT = "1";

	static class TreeNode {
		int val;
		List<TreeNode> children;

		TreeNode(int v) {
			val = v;
			children = new ArrayList<TreeNode>();
		}

		public String toString() {
			return val + "";
		}

		void print() {
			if (children.size() > 0) {
				for (TreeNode c : children) {
					System.out.println(val + " -> " + c.val);
					c.print();
				}
			} else {
				System.out.println(val + " -> null");
			}
		}
	}

	static boolean[][] map;

	// static Set<Integer> keptNodes, removedNodes;

	/*
	 * Return the number of descendants of the node, incl. itself
	 */
	static int numOfDescendants(TreeNode node) {
		int sum = 1;
		for (TreeNode c : node.children) {
			sum += numOfDescendants(c);
		}
		return sum;
	}

	static int minCuts(TreeNode node) {
		List<TreeNode> c = node.children;
		// if this node is a leaf (no children): no cuts.
		if (c == null || c.size() == 0)
			return 0;
		if (c.size() == 2) {
			// if this node has exactly two children: no cuts, just go down
			int sum = 0;
			for (TreeNode tn : c) {
				sum += minCuts(tn);
			}
			return sum;
		} else if (c.size() == 1) {
			// this node has only one children: have to cut it and all
			// descendants
			return numOfDescendants(c.get(0));
		} else {
			// this node has more than two children: keep two and cut the
			// remainings.

			// first find the number of cuts of each child if keep that child
			List<Integer> cuts = new ArrayList<Integer>();
			for (TreeNode tn : c) {
				int numOfCuts = minCuts(tn);
				cuts.add(numOfCuts);
			}
			// then find the number of descendants -- if remove that child
			List<Integer> descendants = new ArrayList<Integer>();
			for (TreeNode tn : c) {
				descendants.add(numOfDescendants(tn));
			}

			// then brute-force
			int min = map.length;
			for (int i = 0; i < c.size(); i++) {
				for (int j = i + 1; j < c.size(); j++) {
					// keep i and j, cut the others
					int sum = 0;
					for (int k = 0; k < c.size(); k++) {
						if (k == i || k == j) {
							sum += cuts.get(k);
						} else {
							sum += descendants.get(k);
						}
					}
					if (sum < min)
						min = sum;
				}
			}
			return min;

			/*
			 * // then keep the minimum two cuts int min0Num = map.length,
			 * min0Index = map.length; for (int i = 0; i < cuts.size(); i++) {
			 * if (cuts.get(i) < min0Num) { min0Num = cuts.get(i); min0Index =
			 * i; } } int min1Num = map.length, min1Index = map.length; for (int
			 * i = 0; i < cuts.size(); i++) { if (i == min0Index) continue; if
			 * (cuts.get(i) > min1Num) { min1Num = cuts.get(i); min1Index = i; }
			 * } // the other nodes should all be cut int sum = 0; for (int i =
			 * 0; i < cuts.size(); i++) { if (i == min0Index || i == min1Index)
			 * continue; sum += cuts.get(i); } return sum;
			 */
		}
	}

	static TreeNode mapToTree(TreeNode n, Set<Integer> addedNodes) {
		// find the children of this node
		List<TreeNode> c = new ArrayList<TreeNode>();
		for (int i = 0; i < map.length; i++) {
			if (i == n.val)
				continue;
			if (addedNodes.contains(i))
				continue;
			if (map[i][n.val])
				c.add(new TreeNode(i));
		}
		// add the children to the addedNodes
		Set<Integer> newAddedNodes = new HashSet<Integer>();
		for (int an : addedNodes) {
			newAddedNodes.add(an);
		}
		for (TreeNode tn : c) {
			newAddedNodes.add(tn.val);
		}
		n.children = c;
		// recursively add the descendants
		for (TreeNode tn : n.children) {
			mapToTree(tn, newAddedNodes);
		}
		return n;
	}

	/*
	 * static void removeDescendant(int node) { // remove this node
	 * removedNodes.remove(node);
	 * 
	 * // find the children of the node List<Integer> children = new
	 * ArrayList<Integer>(); for (int i = 0; i < tree.length; i++) { if (i ==
	 * node) continue; if (keptNodes.contains(i) || removedNodes.contains(i))
	 * continue; if (tree[node][i]) children.add(i); }
	 * 
	 * // remove all the children recursively for (int c : children) {
	 * removeDescendant(c); } }
	 * 
	 * static void checkFBT(int node) { // when invoking this function, this
	 * node has already been kept
	 * 
	 * // find the children of the node List<Integer> children = new
	 * ArrayList<Integer>(); for (int i = 0; i < tree.length; i++) { if (i ==
	 * node) continue; if (keptNodes.contains(i) || removedNodes.contains(i))
	 * continue; if (tree[node][i]) children.add(i); } // if this node has no
	 * child or exactly 2 children, it is valid, we can // keep its children if
	 * (children.size() == 0 || children.size() == 2) { for (int c : children) {
	 * keptNodes.add(c); } // then check each of the children for (int c :
	 * children) { checkFBT(c); } } else { // we should remove some of the
	 * children to make it binary if (children.size() == 1) { // if this node
	 * has only one child, we have to remove the child // and all the
	 * grandchildren etc. removeDescendant(children.get(0)); } else { // if this
	 * node has more than two children, delete the } }
	 * 
	 * }
	 */

	public static void main(String[] args) throws IOException {
		String filename = PATH + PROBLEM + "-" + SIZE;
		if (SIZE.equals("small"))
			filename += "-attempt" + ATTEMPT;
		Scanner sc = new Scanner(new File(filename + ".in"));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(filename + ".out"));
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			System.out.println("Case " + t);

			int N = sc.nextInt();
			map = new boolean[N][];
			for (int n = 0; n < N; n++) {
				map[n] = new boolean[N];
			}
			for (int i = 0; i < N - 1; i++) {
				int a = sc.nextInt() - 1;
				int b = sc.nextInt() - 1;
				map[a][b] = true;
				map[b][a] = true;
			}

			// use each node as root
			int min = N;
			for (int root = 0; root < N; root++) {
				System.out.println(root + " as root");
				TreeNode r = new TreeNode(root);
				Set<Integer> a = new HashSet<Integer>();
				a.add(root);
				mapToTree(r, a);
				// r.print();

				// find the minimal cuts
				if (root == 3 && t == 1) {
					System.out.println("Hello");
				}
				int cuts = minCuts(r);
				System.out.println("Cuts: " + cuts);
				if (cuts < min)
					min = cuts;
			}

			bw.write("Case #" + (t + 1) + ": " + min);
			bw.newLine();
		}
		sc.close();
		bw.close();
	}
}
