import java.io.*;
import java.util.*;

public class A {
	static class State implements Comparable<State> {
		String[] s;
		long switches;

		public int compareTo(State o) {
			long ans = switches - o.switches;
			if(ans > 0) return 1;
			else if(ans < 0) return -1;
			else return 0;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int tests = Integer.parseInt(in.readLine().trim());
		for(int test = 1; test <= tests; test++) {
			String[] s = in.readLine().split("\\s+");
			int n = Integer.parseInt(s[0]);
			int l = Integer.parseInt(s[1]);

			PriorityQueue<State> pq = new PriorityQueue<State>();
			State state = new State();
			state.s = in.readLine().split("\\s+");
			Arrays.sort(state.s);
			state.switches = 0;
			pq.add(state);

			ArrayList<String[]> als = new ArrayList<String[]>();
			als.add(state.s);

			State end = new State();
			end.s = in.readLine().split("\\s+");
			Arrays.sort(end.s);
			end.switches = Long.MAX_VALUE;

			System.out.print("Case #" + test + ": ");
			boolean answered = false;

			while(!pq.isEmpty()) {
				State stat = pq.poll();
				if(Arrays.equals(stat.s, end.s)) {
					System.out.println(stat.switches);
					answered = true;
					break;
				}

				if(stat.switches < l) {
					for(int i = 0; i < l; i++) {
						State newState = new State();
						newState.s = new String[n];
						newState.switches = stat.switches +1;
						for(int j = 0; j < n; j++) {
							newState.s[j] = stat.s[j].substring(0, i) + (stat.s[j].charAt(i) == '0'?'1':'0') + stat.s[j].substring(i+1);
						}
						Arrays.sort(newState.s);

						boolean notSeen = true;

						for(int j = 0; j < als.size(); j++) {
							if(Arrays.equals(als.get(j), newState.s)) notSeen = false;
						}

						if(notSeen) {
							als.add(newState.s);
							pq.add(newState);
//							for(int j = 0; j < n; j++) {
//								System.out.print(" " + newState.s[j]);
//							}
//							System.out.println();
						}

					}
				}
			}

			if(!answered) System.out.println("NOT POSSIBLE");
		}
	}
}
