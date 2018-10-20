package R1A;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws IOException,
			FileNotFoundException {
		String input = "A-small-attempt1.in";
		String output = "A-small-attempt1.out";
		// String input = "A-large.in";
		// String output = "A-large.out";

		Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(
				output)));

		int T = Integer.parseInt(scan.nextLine());
		for (int t = 1; t <= T; t++) {
			String[] line = scan.nextLine().split(" ");
			int N = Integer.parseInt(line[0]);
			int L = Integer.parseInt(line[1]);
			line = scan.nextLine().split(" ");
			char[][] flow = new char[N][L];
			for (int i = 0; i < N; i++)
				flow[i] = line[i].toCharArray();
			line = scan.nextLine().split(" ");
			char[][] device = new char[N][L];
			for (int i = 0; i < N; i++)
				device[i] = line[i].toCharArray();
			int ans = L;
			boolean ok = false;

			for (int i = 0; i < N; i++) {
				boolean[] mask = new boolean[L];
				for (int j = 0; j < L; j++)
					mask[j] = (flow[0][j] == device[i][j] ? false : true);
				match = new boolean[N + N][N + N];
				for (int j = 0; j < N; j++)
					for (int k = 0; k < N; k++) {
						match[j][N + k] = true;
						match[N + k][j] = true;
						for (int m = 0; m < L; m++)
							if (mask[m] == (flow[j][m] == device[k][m])) {
								match[j][N + k] = false;
								match[N + k][j] = false;
								break;
							}
					}
				int result = 0;
				visited = new boolean[N + N];
				pair = new int[N + N];
				Arrays.fill(pair, -1);
				for (int ai = 0; ai < N; ai++) {
					Arrays.fill(visited, false);
					if (find(ai))
						result++;
				}
				if (result == N) {
					ok = true;
					int cnt = 0;
					for (int k = 0; k < L; k++)
						if (mask[k])
							cnt++;
					ans = Math.min(ans, cnt);
				}
			}

			if (ok)
				pw.println("Case #" + t + ": " + ans);
			else
				pw.println("Case #" + t + ": NOT POSSIBLE");
		}

		scan.close();
		pw.close();
	}

	static boolean[][] match;
	static boolean[] visited;
	static int[] pair;

	private static boolean find(int ai) {
		for (int bi = 0; bi < match.length; bi++)
			if (match[ai][bi] && !visited[bi]) {
				visited[bi] = true;
				if (pair[bi] == -1 || find(pair[bi])) {
					pair[bi] = ai;
					return true;
				}
			}
		return false;
	}

}
