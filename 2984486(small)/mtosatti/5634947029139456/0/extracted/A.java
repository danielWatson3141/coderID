import java.util.Arrays;
import java.util.Scanner;


public class A {

	public static int L, N, total, cO[], cD[];

	public static void main(String[] args) {
		long O[], D[];
		String S;
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		for (int t = 1; t <= T; t++) {
			N = input.nextInt();
			L = input.nextInt();
			O = new long[N];
			D = new long[N];
			cO = new int[L];
			cD = new int[L];
			total = 0;
			for(int o = 0; o < N; o++) {
				S = input.next();
				for(int p = L - 1; p >= 0; p--) {
					if(S.charAt(p) == '1') {
						O[o] += Math.pow(2, p);
						cO[p]++;
					}
				}					
			}
			for(int d = 0; d < N; d++) {
				S = input.next();
				for(int p = L - 1; p >= 0; p--) {
					if(S.charAt(p) == '1') {
						D[d] += Math.pow(2, p);
						cD[p]++;
					}
				}					
			}
			
			total = check(0, O, D);			
			
			if (total > -1) {
				System.out.format("Case #%d: %d\n", t, total);
			} else {
				System.out.format("Case #%d: NOT POSSIBLE\n", t);
			}
		}
		input.close();
	}
	
	public static int check(int pos, long O[], long D[]) {
		long OS[] = new long[N], DS[] = new long[N];
		for(int n = 0; n < N; n++) {
			OS[n] = O[n];
			DS[n] = D[n];
		}
		int changes = 0, test;
		for(int l = pos; l < L; l++) {
			if(cO[l] != cD[l]) {
				if(cO[l] == N - cD[l]) {
					changes++;
					for(int n = 0; n < N; n++)
						OS[n] = OS[n] ^ (long) Math.pow(2, l); 
				} else {
					return -1;
				}
			} else {
				test = check(l+1, OS, DS);
				if(test > -1) {
					return changes + test;
				} else {
					for(int n = 0; n < N; n++)
						OS[n] = OS[n] ^ (long) Math.pow(2, l);
					test = check(l+1, OS, DS);
					if(test > -1) {
						return changes + test + 1; 
					} else {
						return - 1;
					}
				}
			}
		}
		Arrays.sort(OS);
		Arrays.sort(DS);
		for(int n = 0; n < N; n++)
			if(OS[n] != DS[n]) return -1;
		return changes;
	}

}
