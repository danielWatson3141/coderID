import java.util.*;
import java.io.*;

public class ChangingChaos {
	// Iteratively, toggle bit
	// Record down minimum number of bit toggle
	
	public static int numberOfSetBits(int i)
	{
	     i = i - ((i >> 1) & 0x55555555);
	     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
	}
	
	public static String solve(int[] input, int[] target, int N, int L) {
		HashSet<Integer> set = new HashSet<Integer>();
		for (int i : target) {
			set.add(i);
		}
		
		// 2 loop
		int min = Integer.MAX_VALUE;
		
		for (int i = 0; i < (1 << (L + 1)); i++) {
			ArrayList<Integer> a = new ArrayList<Integer>();
			for (int j = 0; j < N; j++) {
				a.add(input[j] ^ i);
			}
			
			int n = numberOfSetBits(i);
			if (set.containsAll(a) && min > n) {
				min = n	;
			}
		}
		
		return (min == Integer.MAX_VALUE) ? "NOT POSSIBLE" : min + "";
	}
	
	public static void main(String[] args) {
		String fileName = "A-small-attempt1";
		try (Scanner sc = new Scanner(new BufferedReader(new FileReader(fileName + ".in"))))
		{
			try(PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")))) {			
				int N, L;
				int[] input, target;
				int TC = sc.nextInt();
				for(int i = 1; i <= TC; i++) {
					N = sc.nextInt();
					L = sc.nextInt();
					
					int n;
					input = new int[N];
					target = new int[N];
					
					for (n = 0; n < N; n++) {
						target[n] = Integer.parseInt(sc.next(), 2);
					}
					
					for (n = 0; n < N; n++) {
						input[n] = Integer.parseInt(sc.next(), 2);
					}
					
					pw.printf("Case #%d: %s\n", i, solve(input, target, N, L));
				}
				
			} catch (IOException e) {
				e.printStackTrace();
			}
 
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
