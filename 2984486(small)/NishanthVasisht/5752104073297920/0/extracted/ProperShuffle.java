package GCodeJam;

import java.util.*;

public class ProperShuffle {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int t=1; t<=T; t++) {
			
			int n = in.nextInt();
			
			int sum = 0;
			for (int i = 0; i < n; i++) {
				if (i < (n/2)) {
					sum += in.nextInt();
				}
				else {
					in.nextInt();
				}
			}
			
			int expectedSum = ((n / 2) * ((n / 2) - 1)) / 2;
			
			System.out.println("Case #" + t + ": " + ((sum > expectedSum) ? "GOOD" : "BAD"));
		}
	}
}
