import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;


public class A {
	static void solveCase() {
		int N = sc.nextInt();
		int L = sc.nextInt();
		long outlet[] = new long[N];
		long device[] = new long[N];
		
		for (int i=0; i<N; i++) {
			String s = sc.next();
			outlet[i] = tolong(s, L);
		}
		for (int i=0; i<N; i++) {
			String s = sc.next();
			device[i] = tolong(s, L);
		}
		Arrays.sort(device);
		//p(device);
				
		int[][] matches = new int[N*N][];
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				matches[i*N+j] = new int[]{ i, j, dif(outlet[i], device[j]) };
			}
		}
		Arrays.sort(matches, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		
		boolean possible = false;
		for (int i=0; i<N*N; i++) {
			long a = outlet[matches[i][0]];
			long b = device[matches[i][1]];
			
			long[] outlet2 = outlet.clone();
			for (int j=0; j<N; j++) outlet2[j] ^= (a ^ b);
			Arrays.sort(outlet2);
			if (Arrays.equals(outlet2, device)) {
				printf("%d\n", matches[i][2]);
				possible = true;
				break;
			}
		}
		if (!possible) printf("NOT POSSIBLE\n");
	}
	
	 
	
	static int dif(long a, long b) {
		long c = a ^ b;
		int res = 0;
		while (c > 0) {
			res += c & 1;
			c >>= 1;
		}
		return res;
	}
	
	static long tolong(String s, int L) {
		long res = 0;
		for (int i=0; i<L; i++) {
			char c = s.charAt(i);
			if (c == '1') res |= 1<<(L-i-1);
		}
		return res;
	}
	
	static void printf(String f, Object... args) {
		System.out.printf(f, args);
	}
	
	static void p(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}
	
	static Scanner sc;
	public static void main(String[] args) throws FileNotFoundException {
		sc = new Scanner(args.length > 0 ? new FileInputStream(args[0]) : System.in);
		int numCases = sc.nextInt();
		for (int nCase=1; nCase<=numCases; nCase++) {
			printf("Case #%d: ", nCase);
			solveCase();
		}
		sc.close();
	}

}
