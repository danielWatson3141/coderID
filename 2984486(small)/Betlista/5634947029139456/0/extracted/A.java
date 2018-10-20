import static java.lang.Integer.parseInt;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = parseInt(br.readLine());
		StringTokenizer tok;
		for (int ii = 0; ii < T; ii++) {
			int N, L;
			tok = new StringTokenizer(br.readLine());
			N = parseInt(tok.nextToken());
			L = parseInt(tok.nextToken());
			tok = new StringTokenizer(br.readLine());
			String[] in = new String[N];
			for (int i = 0; i < in.length; i++) {
				in[i] = tok.nextToken();
			}
			tok = new StringTokenizer(br.readLine());
			String[] out = new String[N];
			for (int i = 0; i < in.length; i++) {
				out[i] = tok.nextToken();
			}
			int res = solve(N, L, in, out);
			String s;
			if (res >= 0) {
				s = Integer.toString(res);
			} else {
				s = "NOT POSSIBLE";
			}
			System.out.printf("Case #%d: %s\n", ii + 1, s);
		}
	}

	private static int solve(int N, int L, String[] in, String[] out) {
		PriorityQueue<State> pq = new PriorityQueue<>();

		Arrays.sort(in);
		Arrays.sort(out);

		State f = new State(in, 0);
		pq.add(f);
		State goal = new State(out, 0);
		String goals = goal.toString();

		Set<String> tried = new HashSet<>();
		tried.add(f.toString());
		while (pq.isEmpty() == false) {
			State act = pq.poll();
			if (act.toString().equals(goals)) {
				return act.step;
			}

			for (int i = 0; i < L; i++) {
				// try switch
				String[] newArr = modify(act, i);
				Arrays.sort(newArr);
				State ns = new State(newArr, act.step + 1);
				if (tried.contains(ns.toString()) == false) {
					tried.add(ns.toString());
					pq.add(ns);
				}
			}
		}

		return -1;
	}

	private static String[] modify(State act, int idx) {
		String[] old = act.arr;
		String[] res = Arrays.copyOf(old, old.length);
		for (int i = 0; i < res.length; i++) {
			char[] ca = old[i].toCharArray();
			char c = ca[idx];
			if (c == '0') {
				ca[idx] = '1';
			} else {
				ca[idx] = '0';
			}
			res[i] = new String(ca);
		}
		return res;
	}

	static class State implements Comparable<State> {
		String[] arr;
		int step;

		public State(String[] arr, int step) {
			super();
			this.arr = arr;
			this.step = step;
		}

		@Override
		public String toString() {
			return Arrays.toString(arr);
		}

		@Override
		public int compareTo(State s) {
			return Integer.compare(this.step, s.step);
		}
	}

}
