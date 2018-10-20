import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class A {
	
	public static int solve_small(final int N, final int L, Scanner sc){
		
		long[] input = new long[N];
		long[] output = new long[N];
		
		for(int i = 0; i < N; i++){
			input[i] = Long.parseLong(sc.next(), 2);
		}
		for(int i = 0; i < N; i++){
			output[i] = Long.parseLong(sc.next(), 2);
		}
		
		Arrays.sort(output);
		
		final long max_bit = 1l << L;
	
		for(long bit = 0; bit < max_bit; bit++){
			long tmp[] = new long[N];
			
			for(int i = 0; i < N; i++){
				tmp[i] = input[i] ^ bit;
			}
			
			//System.out.println(Long.toBinaryString(bit) + " : " + Long.bitCount(bit));
			//System.out.println(Arrays.toString(input));
			//System.out.println(Arrays.toString(tmp));
			//System.out.println(Arrays.toString(output));
			
			Arrays.sort(tmp);
		
			boolean is_same = true;
			for(int i = 0; i < N; i++){
				if(tmp[i] != output[i]){
					is_same = false;
					break;
				}
			}
			
			if(is_same){
				return Long.bitCount(bit);
			}
		}
		
		return -1;
	}
	
	public static int solve_large(final int N, final int L, Scanner sc){
		
		long[] input = new long[N];
		long[] output = new long[N];
		
		for(int i = 0; i < N; i++){
			input[i] = Long.parseLong(sc.next(), 2);
		}
		for(int i = 0; i < N; i++){
			output[i] = Long.parseLong(sc.next(), 2);
		}
		Arrays.sort(output);
		
		
		int ans = Integer.MAX_VALUE;
		boolean flag = false;
		
		long in_from = input[0];
		for(int to= 0; to < N; to++){
			long out_to = output[to];
				
			long bit = in_from ^ out_to;
				
			long[] tmp = new long[N];
			for(int i = 0; i < N; i++){
				tmp[i] = input[i] ^ bit;
			}
			Arrays.sort(tmp);
			
			boolean is_same = true;
			for(int i = 0; i < N; i++){
				if(tmp[i] != output[i]){
					is_same = false;
					break;
				}
			}
			
			if(is_same){
				flag = true;
				ans = Math.min(ans, Long.bitCount(bit));
			}
		}
		
		return flag ? ans : -1;
	}
	
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		final int T = sc.nextInt();
		
		for(int tc = 0; tc < T; tc++){
			
			final int N = sc.nextInt();
			final int L = sc.nextInt();
			
			final int ans = solve_large(N, L, sc);
			System.out.println("Case #" + (tc + 1) + ": " + (ans == -1 ? "NOT POSSIBLE" : ans));
		}
		
		sc.close();
	}
	
}
