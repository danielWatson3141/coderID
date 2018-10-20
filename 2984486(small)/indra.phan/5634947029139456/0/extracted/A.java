import java.util.*;

public class A {
	private static int INF = (1 << 30) - 1;
	public static long out[], dev[];
	public static int N, L;
	
	private static void init() {
		out = new long[N+1];
		dev = new long[N+1];
		
		Arrays.fill(out, 0);
		Arrays.fill(dev, 0);
	}
	
	private static boolean isFulfill(int pos, long out[]) {
		HashMap<Long, Integer> mp = new HashMap<Long, Integer>();
		
		for(int i=0; i<N; i++) {
			long val = 0L;
			String x = lpad(Long.toBinaryString(out[i]), L, '0');

			for(int j=0; j<=pos; j++) 
				if(x.charAt(j) == '1') val += (long) (1<<(x.length() - j - 1));
			
			if(mp.containsKey(Long.valueOf(val))) {
				int ex = mp.get(Long.valueOf(val));
				mp.put(Long.valueOf(val), ex+1);
			} else {
				mp.put(Long.valueOf(val), 1);
			}
		}
		
		for(int i=0; i<N; i++) {
			long val = 0L;
			String x = lpad(Long.toBinaryString(dev[i]), L, '0');
			
			for(int j=0; j<=pos; j++) 
				if(x.charAt(j) == '1') val += (long) (1<<(x.length() - j - 1));
			
			if(mp.containsKey(Long.valueOf(val))) {
				int ex = mp.get(Long.valueOf(val));
				
				if(ex == 0) return false;
				
				mp.put(Long.valueOf(val), ex-1);
			} else {
				return false;
			}
		}
		
		return true;
	}
	
	private static long[] flip(int pos, long out[]) {
		long res[] = new long[N+1];
		
		for(int i=0; i<N; i++) {
			String x = lpad(Long.toBinaryString(out[i]), L, '0');
			
			if(x.charAt(pos) == '1') {
				res[i] = out[i] - (long) (1<<(x.length() - pos - 1));
			} else {
				res[i] = out[i] + (long) (1<<(x.length() - pos - 1));
			}
		}
		
		return res;
	}
	
	private static String lpad(String x, int n, char y) {
		StringBuilder sb = new StringBuilder();

		for (int toPrepend=n-x.length(); toPrepend>0; toPrepend--) {
		    sb.append(y);
		}

		sb.append(x);

		return sb.toString();
	}
	
	private static int go(int x, long out[]) {
		if(x == L) {
			return 0;
		}
		
		int res = INF;
		if(isFulfill(x, out)) {
			res = Math.min(res, go(x+1, out));
		}
		
		long flip[] = flip(x, out);
		if(isFulfill(x, flip)) {
			res = Math.min(res, go(x+1, flip) + 1);
		}
		
		return res;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int _i=1; _i<=T; _i++) {
			N = sc.nextInt();
			L = sc.nextInt();
			
			init();
			
			for(int i=0; i<N; i++) {
				String x = sc.next();
				long val = 0L;
				
				for(int j=0; j<x.length(); j++) 
					if(x.charAt(j) == '1') val += (long) (1<<(x.length() - j - 1));
				
				out[i] = val;
			}
			
			for(int i=0; i<N; i++) {
				String x = sc.next();
				long val = 0L;
				
				for(int j=0; j<x.length(); j++) 
					if(x.charAt(j) == '1') val += (long) (1<<(x.length() - j - 1));
				
				dev[i] = val;
			}
			
			int res = go(0, out);
			
			if(res == INF) {
				System.out.println("Case #" + _i + ": NOT POSSIBLE");
			} else {
				System.out.println("Case #" + _i + ": " + res);
			}
		}

	}

}
