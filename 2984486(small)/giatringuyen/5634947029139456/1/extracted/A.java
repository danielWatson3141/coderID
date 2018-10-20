import java.io.File;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.Set;
import java.math.BigInteger;


public class A {
	public static void main (String[] args) throws Exception {
		Scanner sc = new Scanner(new File("A-large.in.txt"));
		PrintWriter writer = new PrintWriter("A-large.out.txt", "UTF-8");
		//Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			int N = sc.nextInt();
			int L = sc.nextInt();
			int result = solve(readSet(sc, N), readSet(sc, N));
			writer.println(
				"Case #" + t + ": " + 
				(result == -1 ? "NOT POSSIBLE" : result));
		}
		writer.close();
	}
	
	private static Set<Long> readSet(Scanner sc, int N) {
		Set<Long> set = new HashSet<Long>();
		for (int i = 0; i < N; ++i) {
			set.add(new BigInteger(sc.next(), 2).longValue());
		}
		return set;
 	}
	
	private static int solve(Set<Long> set1, Set<Long> set2) {
		if (set1.size() != set2.size()) {
			return -1;
		}
		
		Map<Long, Integer> offsetsCnt = new HashMap<Long, Integer>();
		for (long num1 : set1) {
			for (long num2 : set2) {
				long offset = num1 ^ num2;
				if (offsetsCnt.containsKey(offset)) {
					offsetsCnt.put(offset, offsetsCnt.get(offset) + 1);
				} else {
					offsetsCnt.put(offset, 1);
				}
			}
		}
		
		int N = set1.size();
		int min = Integer.MAX_VALUE;
		for (Entry<Long, Integer> offsetCnt : offsetsCnt.entrySet()) {
			if (offsetCnt.getValue() == N) {
				min = Math.min(min, Long.bitCount(offsetCnt.getKey()));
			}
		}
		
		return min == Integer.MAX_VALUE ? -1 : min; 
	}
}
