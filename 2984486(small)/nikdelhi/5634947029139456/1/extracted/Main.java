package round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {

	public static void main(String args[]) throws NumberFormatException, IOException {
		
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		//BufferedReader in = new BufferedReader("A-small-attempt0.in");
		PrintWriter out = new PrintWriter("out");
		int tests = Integer.parseInt(in.readLine());
		
		for(int test = 1; test <= tests; test++) {
			
			String s[] = in.readLine().split(" ");
			int N = Integer.parseInt(s[0]);
			int L = Integer.parseInt(s[1]);
			
			String init[] = in.readLine().split(" ");
			String req[] = in.readLine().split(" ");
			
			ChargingChaos cc = new ChargingChaos();
			int ans = cc.solve(N, L, init, req);
			if(ans > 40) {
				
				out.println("Case #" + test + ": NOT POSSIBLE");
				
			}
			else {
				
				out.println("Case #" + test + ": " + ans);
				
			}
			
		}
		out.close();
		
		
	}
	
}
