package gcj.r1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class B {

	Scanner scanner;


	private void solve() throws FileNotFoundException {
		File input = new File("data/r1a/B-large.in");
		scanner = new Scanner(input);

		File test = new File("data/r1a/B.out");
		PrintStream out = new PrintStream(new FileOutputStream(test));
		System.setOut(out);

		int testCase = scanner.nextInt();
		scanner.nextLine();

		for (int i = 1; i <= testCase; i++) {
			System.out.printf("Case #%d: %d\n", i, solveCase());
		}
	}
	

	int n;
	Node[] tree;
	
	class Node {
		int id;
		List<Integer> ch = new ArrayList<Integer>();
		
		void add(int x) {
			ch.add(x);
		}
		
		int chNumber(boolean isRoot) {
			return isRoot ? ch.size() : ch.size() - 1;
		}
	}
	
	private int solveCase() {
		n = scanner.nextInt();
		tree = new Node[n];
		for (int i = 0; i < n; i++) {
			tree[i] = new Node();
			tree[i].id = i;
		}
		for (int i = 0; i < n - 1; i++) {
			int a = scanner.nextInt() - 1;
			int b = scanner.nextInt() - 1;
			tree[a].add(b);
			tree[b].add(a);
		}
		
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = Math.max(ans, gao(i, -1));
		}
		
		return n - ans;
	}

	private int gao(int id, int parent) {
		Node node = tree[id];
		if (node.chNumber(parent < 0) < 2) {
			return 1;
		}
		List<Integer> tmp = new ArrayList<Integer>();
		for (int i : node.ch) {
			if (i == parent) {
				continue;
			}
			tmp.add(gao(i, id));
		}
		Collections.sort(tmp);
		return 1 + tmp.get(tmp.size() - 1) + tmp.get(tmp.size() - 2);
	}

	public static void main(String[] args) throws FileNotFoundException {
		new B().solve();
	}
	
}
