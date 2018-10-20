import java.io.*;
import java.math.*;
import java.util.*;

public class A{
	public static void main (String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= cases; t++){
			pw.print("Case #" + t + ": ");
			
			StringTokenizer st = getst(br);
			
			int n = nextInt(st);
			int l = nextInt(st);
			
			long[] initial = new long[n];
			long[] target = new long[n];
			
			st = getst(br);
			
			for(int i = 0; i < n; i++){
				initial[i] = Long.parseLong(st.nextToken(), 2);
			}
			
			st = getst(br);
			
			for(int i = 0; i < n; i++){
				target[i] = Long.parseLong(st.nextToken(), 2);
			}
			
			HashSet<Long> possibilities = null;
			
			for(int i = 0; i < n; i++){
				HashSet<Long> p = new HashSet<Long>();
				
				for(int j = 0; j < n; j++){
					p.add(initial[i] ^ target[j]);
				}
				
				if(i == 0){
					possibilities = p;
				} else {
					possibilities.retainAll(p);
				}
			}
			
			int ans = 50;
			
			for(long p : possibilities){
				HashSet<Long> toMatch = new HashSet<Long>();
				for(long i : target){
					toMatch.add(i);
				}
				boolean ok = true;
				for(long i : initial){
					boolean matched = toMatch.remove(i^p);
					if(!matched){
						ok = false;
						break;
					}
				}
				if(ok){
					ans = Math.min(ans, ones(p));
				}
			}
			
			if(ans == 50){
				pw.println("NOT POSSIBLE");
			} else {
				pw.println(ans);
			}
		}
		
		br.close();
		pw.close();
	}
	
	public static int ones(long n){
		if(n == 0){
			return 0;
		}
		return (int)(n%2) + ones(n >> 1);
	}
	
	public static int nextInt(BufferedReader br) throws Exception{
		return Integer.parseInt(br.readLine());
	}
	
	public static int nextInt(StringTokenizer st) throws Exception{
		return Integer.parseInt(st.nextToken());
	}
	
	public static StringTokenizer getst(BufferedReader br) throws Exception{
		return new StringTokenizer(br.readLine(), " ");
	}
}