import java.util.*;
import java.io.*;

public class charging {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("input/charging_small.in"));
		PrintStream output = new PrintStream(new File("output/charging_small.out"));
		PrintStream out = output;
		int T = input.nextInt();
		primary: for (int oncase = 0; oncase < T; oncase++) {
//			System.out.println((oncase+1) + " / " + T);
			out.printf("Case #%d: ", oncase+1);
			int n = input.nextInt();
			int l = input.nextInt();
			Set<Integer> devices = new HashSet<Integer>();
			Set<Integer> plugs = new HashSet<Integer>();
			for (int i=0; i<n; i++) {
				plugs.add(input.nextInt(2));
			}
			for (int i=0; i<n; i++) {
				devices.add(input.nextInt(2));
			}
			if (plugs.size() != devices.size()) {
				System.out.println("NOT POSSIBLE");
				continue primary;
			}
			if (plugs.size() != n) {
				System.out.println("WHAT THE HELL?");
			}
			int best = Integer.MAX_VALUE;
			outer:for (int j=0; j<(1<<l); j++) {
				Set<Integer> temp = new HashSet<Integer>(devices); 
//				System.out.println("j is " + j);
				for (int cur : plugs) {
					if (!temp.remove(cur ^ j)) {
//						System.out.println("Looking for a device with " + (cur ^ j) + " from " + temp.toString());
						continue outer;
					}
				}
				best = Math.min(best, count(j));
			}
			out.println(best == Integer.MAX_VALUE ? "NOT POSSIBLE" : best);
		}
		output.close();
	}
	
	public static int count(int x) {
		int res = 0;
		while (x > 0) {
			x &= x-1;
			res++;
		}
		return res;
	}
}