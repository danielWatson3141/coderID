import java.util.*;

public class a {
	static int oo = 987654321;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for(int t=1; t<=T; t++) {
			int n = in.nextInt();
			int l = in.nextInt();
			long[] switches = new long[n];
			long[] devices = new long[n];
			for(int i=0; i<n; i++) switches[i] = in.nextLong(2);
			for(int i=0; i<n; i++) devices[i] = in.nextLong(2);
			
			Arrays.sort(switches);
			Arrays.sort(devices);
			int ans = score(devices, switches, 0);
			
			for(long x : devices)
				ans = Math.min(ans, score(devices, switches, x^switches[0]));
				
			System.out.printf("Case #%d: ", t);
			if(ans >= oo) System.out.println("NOT POSSIBLE");
			else System.out.println(ans);
		}
	}
	static int score(long[] v, long[] has, long mask) {	
		int n = v.length;
		long[] cpy = new long[v.length];
		for(int i=0; i<n; i++) cpy[i] = v[i]^mask;
		Arrays.sort(cpy);
		for(int i=0; i<n; i++)
			if(cpy[i] != has[i])
				return oo;
		return Long.bitCount(mask);
	}
}