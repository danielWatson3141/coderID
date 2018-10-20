package gcj2014R1A;

import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run(new Scanner(System.in));
	}

	void run(Scanner sc) {
		int n = sc.nextInt();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}

	static class Node {
		int index;
		List<Node> conect = new ArrayList<Node>();
		Node(int index) {this.index = index; }
	}
	int[][] memo;
	int countChild(Node[] nodes, int cur, int parent) {
		if(memo[cur][parent] >= 0) return memo[cur][parent];
		if(nodes[cur].conect.size() == 1) return memo[cur][parent] = 0;
		int sum = 0;
		for(Node n : nodes[cur].conect) if(n.index != parent) {
			sum += countChild(nodes, n.index, cur) + 1;
		}
		return memo[cur][parent] = sum;
	}
	int[][] memo2;
	int binaryTreeCheck(Node[] nodes, int cur, int parent) {
		if(memo2[cur][parent] >= 0) return memo2[cur][parent];
		if(nodes[cur].conect.size() == 1) return memo2[cur][parent] = 0;
		if(nodes[cur].conect.size() == 2) {
			int sum = 0;
			for(Node n : nodes[cur].conect) if(n.index != parent) {
				sum += countChild(nodes, n.index, cur) + 1;
			}
			return memo2[cur][parent] = sum;
		}
		if(nodes[cur].conect.size() == 3) {
			int sum = 0;
			for(Node n : nodes[cur].conect) if(n.index != parent) {
				sum += binaryTreeCheck(nodes, n.index, cur);
			}
			return memo2[cur][parent] = sum;
		}
		int[] deleteSize = new int[nodes[cur].conect.size() - 1];
		int[] checkSize = new int[nodes[cur].conect.size() - 1];
		int add = 0;
		for(Node n : nodes[cur].conect) if(n.index != parent) {
			checkSize[add] = binaryTreeCheck(nodes, n.index, cur);
			deleteSize[add] = countChild(nodes, n.index, cur) + 1;
			add++;
		}
		int min = 10000;
		for(int i = 0; i < add; i++) {
			for(int j = i; j < add; j++) {
				int sum = checkSize[i] + checkSize[j];
				for(int k = 0; k < add; k++) if(k != i && k != j) {
					sum += deleteSize[k];
				}
				min = Math.min(min, sum);
			}
		}
		return memo2[cur][parent] = min;
	}
	void solve(Scanner sc, int case_num) {
		int n = sc.nextInt();
		Node nodes[] = new Node[n];
		for(int i = 0; i < n; i++) nodes[i] = new Node(i);
		for(int i = 0; i < n - 1; i++) {
			int x = sc.nextInt() - 1;
			int y = sc.nextInt() - 1;
			nodes[x].conect.add(nodes[y]);
			nodes[y].conect.add(nodes[x]);
		}
		memo = new int[n][n];
		memo2 = new int[n][n];
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
			memo[i][j] = -1;
			memo2[i][j] = -1;
		}
		
		int res = n - 1;
		for(int i = 0; i < n; i++) {
			if(nodes[i].conect.size() == 1) continue;
			if(nodes[i].conect.size() == 2) {
				int sum = 0;
				for(Node node : nodes[i].conect) {
					sum += binaryTreeCheck(nodes, node.index, i);
				}
				res = Math.min(res, sum);
			} else {
				int[] deleteSize = new int[nodes[i].conect.size()];
				int[] checkSize = new int[nodes[i].conect.size()];
				int add = 0;
				for(Node node : nodes[i].conect) {
					checkSize[add] = binaryTreeCheck(nodes, node.index, i);
					deleteSize[add] = countChild(nodes, node.index, i) + 1;
					add++;
				}
				int min = 10000;
				for(int m = 0; m < add; m++) {
					for(int j = m; j < add; j++) {
						int sum = checkSize[m] + checkSize[j];
						for(int k = 0; k < add; k++) if(k != m && k != j) {
							sum += deleteSize[k];
						}
						min = Math.min(min, sum);
					}
				}
				res = Math.min(res, min);
			}
		}
		System.out.printf("Case #%d: %d\n", case_num, res);
	}
}
