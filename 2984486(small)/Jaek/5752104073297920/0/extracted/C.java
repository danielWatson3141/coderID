package a_2014;

import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		
		double[][] probs = probability(1000);
		for(int i = 0; i<3; i++) {
			for(int j = 0; j<3; j++) {
				//System.out.print(probs[i][j]+"  ");
			}
			//System.out.println();
		}
		
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		
		
		for(int cas = 1; cas<=T; cas++) {
			int N = in.nextInt();
			int[] data = new int[N];
			for(int i = 0; i<N; i++) {
				data[i] = in.nextInt();
			}
			
			double chance = 1.0;
			for(int i = 0; i<N; i++) {
				chance = (1.0/N)*chance/probs[i][data[i]];
			}
			
			if(chance>1) {
				System.out.println("Case #"+cas+": GOOD");
			} else {
				System.out.println("Case #"+cas+": BAD");
			}
				
		}
	}
	
	public static double[][] probability(int N) {
		double[][] probs = new double[N][N];
		for(int i = 0; i<N; i++) {
			probs[i][i] = 1.0;
		}
		
		for(int i = 0; i<N-1; i++) {
			System.out.println(i);
			double[] next = new double[N];
			for(int j = 0; j<N; j++) {
				for(int k = 0; k<N; k++) {
					next[k] += probs[j][k]/N;
				}
			}
			for(int j = 0; j<N; j++) {
				for(int k = 0; k<N; k++) {
					probs[j][k] = ((N-1)*probs[j][k]/N)+(probs[i][k]/N);
				}
			}
			for(int j = 0; j<N; j++) {
				probs[i][j] = next[j];
			}
		}
		
		return probs;
	}
}
