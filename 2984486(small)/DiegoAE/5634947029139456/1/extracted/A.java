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
	
	static long[] out, dev;
	static int N,L;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++){
			N = sc.nextInt();
			L = sc.nextInt();
			out = new long[N];
			dev = new long[N];
			for(int i = 0; i < N; i++){
				String cad = sc.next();
				out[i] = Long.parseLong(cad, 2);
			}
			for(int i = 0; i < N; i++){
				String cad = sc.next();
				dev[i] = Long.parseLong(cad, 2);
			}
			Arrays.sort(dev);
			long best = Long.MAX_VALUE;
			for(int i = 0;  i < N; i++){
				long d = dev[i];
				for(int j = 0; j < N; j++){
					long o = out[j];
					long mask = compute_mask(d, o);
					long[] tmp = new long[N];
					for(int k = 0; k < N; k++)
						tmp[k] = convert(out[k], mask);
					Arrays.sort(tmp);
					boolean equal = true;
					for(int k = 0; k < N; k++)
						equal = equal && (tmp[k] == dev[k]);
					if (equal)
						best = Math.min(best, Long.bitCount(mask));
				}
			}
			if (best == Long.MAX_VALUE)
				System.out.printf("Case #%d: NOT POSSIBLE\n", c);
			else
				System.out.printf("Case #%d: %d\n", c, best);
		}
	}
	
	static long compute_mask(long a, long b){
		long ret = 0;
		for(int i = 0; i < L; i++){
			long f = a >> i;
			long s = b >> i;
			f = f & 1;
			s = s & 1;
			if (f != s)
				ret = ret | (1L<<i);
		}
		return ret;
	}
	
	static long convert(long outlet, long m){
		long ret = 0;
		for(int i = 0; i < L; i++){
			long bit = m >> i;
			bit = bit & 1;
			long nuevo = outlet >> i;
			nuevo = nuevo & 1;
			if (bit == 1)
				nuevo = nuevo ^ 1;
			ret = ret | (nuevo<<i);
		}
		return ret;
	}

}
