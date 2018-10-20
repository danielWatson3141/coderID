package round1a;

import java.util.Scanner;

public class ProperShuffle {


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int cases = sc.nextInt();

		for (int cs = 1; cs <= cases; cs++) {
			int N = sc.nextInt();
			
			int []a = new int[N];
			
			for(int i = 0; i < N; i++) {
				a[i] = sc.nextInt();
			}
			
			boolean found = false;
			
			for(int i = 0; i < N; i++) {
				if(a[i] == i) {
					found = true;
				}
			}
			
			System.out.println("Case #" + cs + ": " + (found ? "BAD" : "GOOD"));
		}
	}
}
