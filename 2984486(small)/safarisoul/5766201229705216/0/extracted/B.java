package R1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws IOException,
			FileNotFoundException {
		String input = "B-small-attempt1.in";
		String output = "B-small-attempt1.out";
		// String input = "B-large.in";
		// String output = "B-large.out";

		Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(
				output)));

		int T = Integer.parseInt(scan.nextLine());
		for (int t = 1; t <= T; t++) {
			N = Integer.parseInt(scan.nextLine());
			tree = new ArrayList<HashSet<Integer>>();
			for (int i = 0; i <= N; i++)
				tree.add(i, new HashSet<Integer>());
			for (int i = 1; i < N; i++) {
				String[] line = scan.nextLine().split(" ");
				int node1 = Integer.parseInt(line[0]);
				int node2 = Integer.parseInt(line[1]);
				tree.get(node1).add(node2);
				tree.get(node2).add(node1);
			}
			int ans = N;
			for (int i = 1; i <= N; i++) {
				int delete = N - size(i, -1);
				ans = Math.min(ans, delete);
			}
			pw.println("Case #" + t + ": " + ans);
		}

		scan.close();
		pw.close();
	}

	static int N;
	static ArrayList<HashSet<Integer>> tree;

	private static int size(int node, int parent) {
		ArrayList<Integer> branch = new ArrayList<Integer>();
		for (Integer child : tree.get(node))
			if (child != parent)
				branch.add(size(child, node));
		if (branch.size() < 2)
			return 1;
		Collections.sort(branch);
		return 1 + branch.get(branch.size() - 1)
				+ branch.get(branch.size() - 2);
	}

}
