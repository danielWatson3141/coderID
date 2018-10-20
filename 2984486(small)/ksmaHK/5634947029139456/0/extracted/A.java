import java.util.*;

public class A {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	//int nCase = Integer.parseInt(scanner.nextLine());
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		int N = scanner.nextInt();
		int L = scanner.nextInt();
		String[] outletS = new String[N];
		String[] deviceS = new String[N];
		
		for (int i = 0; i < N; i++) {
			outletS[i] = scanner.next();
		}
		for (int i = 0; i < N; i++) {
			deviceS[i] = scanner.next();
		}
		
		char[][] outletC = new char[N][];
		char[][] deviceC = new char[N][];
		for (int i = 0; i < N; i++)
			outletC[i] = outletS[i].toCharArray();
		for (int i = 0; i < N; i++)
			deviceC[i] = deviceS[i].toCharArray();
		
		int[][] outlet = new int[N][L];
		int[][] device = new int[N][L];
		for (int i = 0; i < N; i++)
		for (int j = 0; j < L; j++) {
			outlet[i][j] = outletC[i][j]-'0';
			device[i][j] = deviceC[i][j]-'0';
		}
		/*
		System.out.println("outlet");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < L; j++)
				System.out.print(outlet[i][j]);
			System.out.println();
		}
		
		System.out.println("device");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < L; j++)
				System.out.print(device[i][j]);
			System.out.println();
		}
		*/
		int[][] a = new int[N][L];
		int best = L+1;
		int S = 1 << L;
		for (int k = 0; k < S; k++) {
			//System.out.println("k: "+k);
			for (int i = 0; i < N; i++)
			for (int j = 0; j < L; j++)
				a[i][j] = outlet[i][j];
			
			for (int j = 0; j < L; j++)
				if (((k >> (L-j-1)) & 1) > 0)
					for (int i = 0; i < N; i++)
						a[i][j] ^= 1;
			
			/*System.out.println("a");
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < L; j++)
					System.out.print(a[i][j]);
				System.out.println();
			}
			*/
			boolean[] match = new boolean[N];
			int count = 0;
			for (int i = 0; i < N; i++)
			for (int b = 0; b < N; b++)
				if (!match[b]) {
					int same = 0;
					for (int j = 0; j < L; j++)
						if (a[i][j] == device[b][j]) {
							same++;
						}
					if (same == L) {
						match[b] = true;
						count++;
					}
				}

			//System.out.println("count: "+count);
			if (count == N) {
				best = Math.min(best, Integer.bitCount(k));
			//	System.out.println("match k: "+Integer.bitCount(k));
			}				
		}
		
		
		if (best > L)
			System.out.println("Case #" + nc + ": NOT POSSIBLE");
		else
			System.out.println("Case #" + nc + ": " + best);
	}
}
}