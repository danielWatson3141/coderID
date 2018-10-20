package round1a;

import java.io.*;
import java.util.*;

public class charging {
	public static void main(String[] args) throws IOException {
		PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
		BufferedReader br = new BufferedReader(new FileReader(new File("test.txt")));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine().trim());
		for (int casenum = 1; casenum <= T; casenum++) {
			out.print("Case #" + casenum + ": ");
			//int N = Integer.parseInt(br.readLine().trim());
			st = new StringTokenizer(br.readLine().trim());
			int N = Integer.parseInt(st.nextToken());
			int L = Integer.parseInt(st.nextToken());
			String[] correct = new String[N];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				correct[i] = st.nextToken();
			}
			Arrays.sort(correct);
			BitSet[] current = new BitSet[N];
			st = new StringTokenizer(br.readLine().trim());
			String cur;
			for (int i = 0; i < N; i++) {
				cur = st.nextToken();
				BitSet b = new BitSet(L);
				for (int j = 0; j < L; j++){
					if (cur.charAt(j) == '1')
						b.set(j);
				}
				current[i] = b;
			}
			int min = bruteforce(0, 0, current, correct, L);
			if (min != Integer.MAX_VALUE) {
				out.println(min);
			} else {
				out.println("NOT POSSIBLE");
			}
			
			// brute force for the shitty case
		}
		out.close();
	}
	
	static int bruteforce(int start, int flipped, BitSet[] current, String[] correct, int L) {
		int c = check(current, correct, flipped);
		if (c != Integer.MAX_VALUE) return c;
		int total = Integer.MAX_VALUE;
		for (int i = start; i < L; i++) {
			for (BitSet b : current) {
				b.flip(i);
			}
			int next = bruteforce(i + 1, flipped + 1, current, correct, L);
			if (next != Integer.MAX_VALUE) {
				total = Math.min(total, next);
			}
			for (BitSet b : current) {
				b.flip(i);
			}
		}
		return total;
	}
	static int check(BitSet[] current, String[] correct, int flipped) {
		String[] test = new String[correct.length];
		for (int i = 0; i < correct.length; i++) {
			//test[i] = current[i].toString();
			StringBuilder sb = new StringBuilder();
			for (int j = 0; j < correct[0].length(); j++) {
				sb.append(current[i].get(j)?'1':'0');
			}
			test[i] = sb.toString();
		}
		Arrays.sort(test);
		int q = 2;
		for (int i = 0; i < correct.length; i++) {
			if (!correct[i].equals(test[i])) {
				return Integer.MAX_VALUE;
			}
		}
		return flipped;
	}
	
}
