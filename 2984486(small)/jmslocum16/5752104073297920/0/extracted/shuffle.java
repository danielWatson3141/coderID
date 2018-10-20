package round1a;

import java.io.*;
import java.util.*;

public class shuffle {
	public static void main(String[] args) throws IOException {
		PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
		BufferedReader br = new BufferedReader(new FileReader(new File("test.txt")));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine().trim());
		for (int casenum = 1; casenum <= T; casenum++) {
			System.out.println(casenum);
			out.print("Case #" + casenum + ": ");
			int N = Integer.parseInt(br.readLine().trim());
			int inversions = 0;
			st = new StringTokenizer(br.readLine().trim());
			for (int i = 0; i < N; i++) {
				int q = Integer.parseInt(st.nextToken());
				if (q >= i) inversions++;
			}
			System.out.println(inversions);
			if (inversions >= 0.52 * N) {
				out.println("BAD");
			} else {
				out.println("GOOD");
			}
			
			// brute force for the shitty case
		}
		out.close();
	}
}