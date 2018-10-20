package com.google.codejam.ka;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class FullBin {

	public static void main(String args[]) throws FileNotFoundException {
		parseInput(args[0]);
	}

	static int cnt = 0;

	private static class Node {
		List<Node> others = new LinkedList<Node>();
		boolean deleted = false;
		int id = cnt++;

		public int count() {
			int cnt = 0;
			for (Node other : others) {
				if (!other.deleted) {
					++cnt;
				}
			}
			return cnt;
		}
	}

	private static void parseInput(String arg) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(arg));
		int testCases = scanner.nextInt();
		for (int i = 0; i < testCases; i++) {
			cnt = 0;
			int n = scanner.nextInt();
			Node nodes[] = new Node[n];
			for (int j = 0; j < nodes.length; j++) {
				nodes[j] = new Node();
			}
			for (int j = 0; j < n - 1; j++) {
				int x = scanner.nextInt() - 1;
				int y = scanner.nextInt() - 1;
				nodes[x].others.add(nodes[y]);
				nodes[y].others.add(nodes[x]);
			}
			printOutput(i + 1, "" + solve(nodes));
		}
	}

	private static int solve(Node[] nodes) {
		int min = Integer.MAX_VALUE;
		for (Node node : nodes) {
			Queue<Node> q = new LinkedList<Node>();
			Set<Node> seen = new HashSet<Node>();
			q.add(node);
			while (!q.isEmpty()) {
				Node curr = q.poll();
				seen.add(curr);
				for (Node child : curr.others) {
					if ((node == curr  && curr.count() == 2) || (curr.count() == 3 && !seen.contains(child))) {
						q.add(child);
					}
				}
			}
			int deleteCnt = nodes.length - seen.size();
			if (deleteCnt < min) {
				min = deleteCnt;
			}
			if (min == 0) {
				break;
			}
		}
		return min;
	}

//	private static void resetNodes(Node[] nodes) {
//		for (Node node : nodes) {
//			if (node.count() > 0) {
//				node.deleted = false;
//			}
//		}
//	}
//
//	private static boolean isFull(Node[] nodes, int deleteCnt) {
//		for (Node node : nodes) {
//			if (!node.deleted) {
//				if (nodes.length - deleteCnt == isRoot(node)) {
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//
//	private static int isRoot(Node node) {
//		Set<Node> seen = new HashSet<Node>();
//		Queue<Node> q = new LinkedList<Node>();
//		q.add(node);
//		while (!q.isEmpty()) {
//			Node curr = q.poll();
//			seen.add(curr);
//			if (!(curr.count() == 0 || curr.count() == 2)) {
//				return false;
//			} else {
//				for (Node n : curr.others) {
//					if (!n.deleted) {
//						q.add(n);
//					}
//				}
//			}
//		}
//		return seen.size();
//	}

	private static void printOutput(int i, String s) {
		System.out.println(String.format("Case #%d: %s", i, s));
	}
}
