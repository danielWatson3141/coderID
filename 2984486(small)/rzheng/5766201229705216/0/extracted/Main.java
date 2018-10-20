import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	private static ArrayList<Integer>[] graph;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = sc.nextInt();
			graph = new ArrayList[N];
			for (int j = 0; j < N; j++) {
				graph[j] = new ArrayList<Integer>();
			}
			for (int j = 1; j < N; j++) {
				int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
				graph[a].add(b);
				graph[b].add(a);
			}
			int min = Integer.MAX_VALUE;
			for (int j = 0; j < N; j++) {
				min = Math.min(min, solve(j, -1));
			}
			System.out.printf("Case #%d: %d\n", i, min);
		}
		sc.close();
	}

	private static int solve(int curr, int parent) {
		int count = 0;
		for (int i : graph[curr]) {
			if (i != parent) {
				count++;
			}
		}
		if (count == 0) {
			return 0;
		} else if (count == 1) {
			int c = 0;
			for (int i : graph[curr]) {
				if (i != parent) {
					c += count(i, curr);
				}
			}
			return c;
		} else if (count == 2) {
			int c = 0;
			for (int i : graph[curr]) {
				if (i != parent) {
					c += solve(i, curr);
				}
			}
			return c;
		} else {
			HashMap<Integer, Integer> counts = new HashMap<Integer, Integer>();
			HashMap<Integer, Integer> solves = new HashMap<Integer, Integer>();
			for (int i : graph[curr]) {
				if (i != parent) {
					counts.put(i, count(i, curr));
					solves.put(i, solve(i, curr));
				}
			}
			int min = Integer.MAX_VALUE;
			for (int key1 : solves.keySet()) {
				for (int key2 : solves.keySet()) {
					if (key1 != key2) {
						int c = solves.get(key1) + solves.get(key2);
						for (int key3 : counts.keySet()) {
							if (key3 != key1 && key3 != key2) {
								c += counts.get(key3);
							}
						}
						min = Math.min(min, c);
					}
				}
			}
			return min;
		}
	}

	private static int count(int curr, int parent) {
		int count = 1;
		for (int i : graph[curr]) {
			if (i != parent) {
				count += count(i, curr);
			}
		}
		return count;
	}
}