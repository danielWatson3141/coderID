package com.google.jam2014.Roudn1A;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class FullBinaryTree {
	
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		FileInputStream fis = new FileInputStream(args[0]);
		PrintWriter pw = new PrintWriter(new File(args[1]));
		Scanner scanner = new Scanner(fis);
		int T = scanner.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = scanner.nextInt();
			HashSet<Integer>[] graph = new HashSet[N + 1];
			for (int j = 1; j <= N; j++)
				graph[j] = new HashSet<Integer>();
			for (int j = 1; j < N; j++) {
				int a1 = scanner.nextInt();
				int a2 = scanner.nextInt();
				graph[a1].add(a2);
				graph[a2].add(a1);
			}
			int remains = 1;
			for (int root = 1; root <= N; root++) {
				if (graph[root].size() == 1)
					continue;
				int tmp = calc(graph, root, -1);
				remains = remains > tmp ? remains : tmp;
			}
			System.out.println("Case #" + i + ": " + (N - remains));
			pw.println("Case #" + i + ": " + (N - remains));
		}
		pw.close();
	}
	
	public static int calc(HashSet<Integer>[] graph, int root, int from) {
		if (from != -1 && graph[root].size() <= 2)
			return 1;
		int[] remains = new int[graph[root].size()];
		remains[graph[root].size() - 1] = 0;
		Integer[] childList = graph[root].toArray(new Integer[graph[root].size()]);
		int counter = 0;
		for (int i : childList) {
			if (i == from)
				continue;
			remains[counter] = calc(graph, i, root);
			counter++;
		}
		Arrays.sort(remains);
		
		return 1 + remains[graph[root].size()-1] + remains[graph[root].size()-2];
	}
}
