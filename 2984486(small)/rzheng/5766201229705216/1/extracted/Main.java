import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	private static ArrayList<Integer>[] graph;
	private static int[] solves, counts;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = sc.nextInt();
			graph = new ArrayList[N];
			solves = new int[N];
			counts = new int[N];
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
				for (int k = 0; k < N; k++) {
					solves[k] = counts[k] = -1;
				}
				min = Math.min(min, solve(j, -1));
			}
			System.out.printf("Case #%d: %d\n", i, min);
		}
		sc.close();
	}

	private static int solve(int curr, int parent) {
		if (solves[curr] != -1) {
			return solves[curr];
		}
		int count = 0;
		for (int i : graph[curr]) {
			if (i != parent) {
				count++;
			}
		}
		if (count == 0) {
			return solves[curr] = 0;
		} else if (count == 1) {
			int c = 0;
			for (int i : graph[curr]) {
				if (i != parent) {
					c += count(i, curr);
				}
			}
			return solves[curr] = c;
		} else if (count == 2) {
			int c = 0;
			for (int i : graph[curr]) {
				if (i != parent) {
					c += solve(i, curr);
				}
			}
			return solves[curr] = c;
		} else {
			for (int i : graph[curr]) {
				if (i != parent) {
					count(i, curr);
					solve(i, curr);
				}
			}
			int min = Integer.MAX_VALUE;
			int sum = 0;
			for (int i : graph[curr]) {
				if (i != parent) {
					sum += counts[i];
				}
			}
			for (int i : graph[curr]) {
				if (i != parent) {
					for (int j : graph[curr]) {
						if (j != parent && i != j) {
							int c = solves[i] + solves[j] + sum - counts[i]
									- counts[j];
							min = Math.min(min, c);
						}
					}
				}
			}
			return solves[curr] = min;
		}
	}

	private static int count(int curr, int parent) {
		if (counts[curr] != -1) {
			return counts[curr];
		}
		int count = 1;
		for (int i : graph[curr]) {
			if (i != parent) {
				count += count(i, curr);
			}
		}
		return counts[curr] = count;
	}
}