import java.io.*;
import java.util.*;

public class A {
	public static int min, L;
	public static HashMap<String, Integer> DP;

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		PrintWriter pp = new PrintWriter("A.txt");

		int index = 1;
		while (T > 0) {
			pp.print("Case #" + index++ + ": ");
			int N = in.nextInt();
			L = in.nextInt();
			in.nextLine();
			int[] ini = new int[N];
			int[] end = new int[N];
			String line = in.nextLine();
			String[] toks = line.split("\\s+");
			for (int t = 0; t < N; ++t) {
				ini[t] = Integer.parseInt(toks[t], 2);
			}

			line = in.nextLine();

			toks = line.split("\\s+");
			for (int t = 0; t < N; ++t) {
				end[t] = Integer.parseInt(toks[t], 2);
			}
			min = Integer.MAX_VALUE;
			DP = new HashMap<String, Integer>();
			Arrays.sort(end);
			int ans = DP(ini, end, 0, N, 0);
			if (ans == Integer.MAX_VALUE)
				pp.println("NOT POSSIBLE");
			else
				pp.println(ans);
			T--;
		}
		pp.close();
		in.close();

	}

	private static int DP(int[] ini, int[] end, int a, int N, int b) {
		if (DP.containsKey(Arrays.toString(ini)))
			return DP.get(Arrays.toString(ini));
		
		if (a > L || b > min)
			return Integer.MAX_VALUE;
		
		boolean answer = true;
		Arrays.sort(ini);
		for (int i = 0; i < ini.length; i++) {
			if (ini[i] != end[i]) {
				answer = false;
				break;
			}
		}
		if (answer) {
			DP.put(Arrays.toString(ini), b);
			return b;
		}
		int one = DP(ini, end, a + 1, N, b);
		int[] in = ini.clone();
		for (int t = 0; t < N; t++)
			in[t] ^= (1 << (a));

		int two = DP(in, end, a + 1, N, b + 1);

		return Math.min(one, two);
	}
}
