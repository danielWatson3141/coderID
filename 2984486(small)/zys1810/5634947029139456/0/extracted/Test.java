package test;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Test {
	private final static String path = "D:\\desktop\\";
//	private final static String input = "input.txt";
	private final static String input = "A-small-attempt0.in";
	private final static String output = "output";
	private static FileWriter writer;

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new FileInputStream(path + input));
		writer = new FileWriter(path + output);
		int T = in.nextInt();
		outer:
		for (int i = 1; i <= T; i++) {
			int N = in.nextInt();
			int L = in.nextInt();
			int[] outlet = new int[N];
			int[] device = new int[N];
			int[] result = new int[N];
			for (int j = 0; j < N; j++) {
				outlet[j] = Integer.parseInt(in.next(), 2);
			}
			for (int j = 0; j < N; j++) {
				device[j] = Integer.parseInt(in.next(), 2);
			}
			Arrays.sort(device);
			Arrays.sort(outlet);
			if (Arrays.equals(device, outlet)) {
				printAns(i, 0);
				continue outer;
			}
			boolean[] map = new boolean[(int) Math.pow(2, L)];
			Queue<Integer> q = new LinkedList<Integer>();
			q.add(0);
			while (!q.isEmpty()) {
				int c = q.poll();
				for (int j = 0; j < L; j++) {
					if ((c & (1 << j)) == 0) {
						int next = c | (1 << j);
						if (!map[next]) {
							for (int k = 0; k < N; k++) {
								result[k] = outlet[k] ^ next;
							}
							Arrays.sort(result);
							if (Arrays.equals(result, device)) {
								printAns(i, next);
								continue outer;
							}
							map[next] = true;
							q.add(next);
						}
					}
				}
			}
			printAns(i, -1);
		}
		in.close();
		writer.close();
	}

	private static void printAns(int t, int num) {
		String ans = "NOT POSSIBLE";
		if (num != -1) {
			int cnt = 0;
			while (num != 0) {
				cnt++;
				num &= num - 1;
			}
			ans = String.valueOf(cnt);
		}
		try {
			writer.write("Case #" + t + ": " + ans + "\n");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}
}
