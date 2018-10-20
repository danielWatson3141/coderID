import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class A {
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens())
				tk=new StringTokenizer(br.readLine());
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	static int[] out, dev;
	static int N,L;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++){
			N = sc.nextInt();
			L = sc.nextInt();
			out = new int[N];
			dev = new int[N];
			for(int i = 0; i < N; i++){
				String cad = sc.next();
				out[i] = Integer.parseInt(cad, 2);
			}
			for(int i = 0; i < N; i++){
				String cad = sc.next();
				dev[i] = Integer.parseInt(cad, 2);
			}
			int best = Integer.MAX_VALUE;
			Arrays.sort(dev);
			for(int mask = 0; mask < (1<<L); mask++){
				int[] tmp = new int[N];
				for(int i = 0; i < N; i++)
					tmp[i] = convert(out[i], mask);
				Arrays.sort(tmp);
				boolean equal = true;
				for(int i = 0; i < N; i++)
					equal = equal && (tmp[i] == dev[i]);
				if (equal)
					best = Math.min(best, Integer.bitCount(mask));
			}
			if (best == Integer.MAX_VALUE)
				System.out.printf("Case #%d: NOT POSSIBLE\n", c);
			else
				System.out.printf("Case #%d: %d\n", c, best);
		}
	}
	
	static int convert(int outlet, int m){
		int ret = 0;
		for(int i = 0; i < L; i++){
			int bit = m >> i;
			bit = bit & 1;
			int nuevo = outlet >> i;
			nuevo = nuevo & 1;
			if (bit == 1)
				nuevo = nuevo ^ 1;
			ret = ret | (nuevo<<i);
		}
		return ret;
	}

}
