package r1a2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

public class FullBinaryTree {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		FullBinaryTree obj = new FullBinaryTree();
		obj.solve(fileName);
	}

	int min = 0;

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String str = br.readLine();
			StringTokenizer token = new StringTokenizer(str, " ");
			int N = Integer.parseInt(token.nextToken());

			int[][] e = new int[N - 1][2];
			for (int j = 0; j < N - 1; j++) {
				str = br.readLine();
				token = new StringTokenizer(str, " ");
				e[j][0] = Integer.parseInt(token.nextToken()) - 1;
				e[j][1] = Integer.parseInt(token.nextToken()) - 1;
			}

			min = Integer.MAX_VALUE;
			Node[] n = new Node[N];
			for (int j = 0; j < N; j++) {
				n[j] = new Node();
			}
			for (int j = 0; j < N - 1; j++) {
				n[e[j][0]].adj.add(n[e[j][1]]);
				n[e[j][1]].adj.add(n[e[j][0]]);
			}
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					n[k].totalChild = 0;
					n[k].binToDelete = 0;
				}
				calcTotal(n[j], null);
				calcBinToDelete(n[j], null);
				min = Math.min(min, n[j].binToDelete);
			}

			bw.write("Case #" + (i + 1) + ": " + min);
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}

	private void calcTotal(Node a, Node parent) {
		for (Node ch : a.adj) {
			if (ch == parent) {
				continue;
			}
			calcTotal(ch, a);
			a.totalChild += ch.totalChild + 1;
		}
	}

	private void calcBinToDelete(Node a, Node parent) {
		switch (a.adj.size()) {
		case 0:
			if (parent == null) {
				a.binToDelete = 0;
			} else {
				a.binToDelete = 0;
			}
			break;
		case 1:
			if (parent == null) {
				a.binToDelete = a.totalChild;
			} else {
				a.binToDelete = 0;
			}
			break;
		case 2:
			if (parent == null) {
				for (Node ch : a.adj) {
					calcBinToDelete(ch, a);
					a.binToDelete += ch.binToDelete;
				}
			} else {
				for (Node ch : a.adj) {
					if (ch == parent) {
						continue;
					}
					a.binToDelete += ch.totalChild + 1;
				}
			}
			break;

		default:
			int total = 0;
			int max1 = 0;
			int max2 = 0;
			for (Node ch : a.adj) {
				if (ch == parent) {
					continue;
				}
				calcBinToDelete(ch, a);
				total += ch.totalChild + 1;
				int tmp = ch.totalChild + 1 - ch.binToDelete;
				if (tmp > max1) {
					max2 = max1;
					max1 = tmp;
				} else if (tmp > max2) {
					max2 = tmp;
				}
			}
			a.binToDelete = total - max1 - max2;

			break;
		}
	}

	class Node {
		ArrayList<Node> adj = new ArrayList<Node>();
		int totalChild = 0;
		int binToDelete = 0;
	}
}
