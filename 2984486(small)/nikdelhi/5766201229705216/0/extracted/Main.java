package round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Main {

	public static void main(String args[]) throws NumberFormatException, IOException {
		
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt1.in"));
		//BufferedReader in = new BufferedReader("A-small-attempt0.in");
		PrintWriter out = new PrintWriter("out");
		int tests = Integer.parseInt(in.readLine());
		
		for(int test = 1; test <= tests; test++) {
			
			int N = Integer.parseInt(in.readLine());
			List<Pair<String, String>> l = new ArrayList<Pair<String, String>>();
			
			for(int i = 0; i < N-1; i++) {
				
				String s[] = in.readLine().split(" ");
				l.add(new Pair<String, String>(s[0], s[1]));
				
			}
			
			FullBinaryTree fbt = new FullBinaryTree();
			int ans = fbt.solve(l);
			
			out.println("Case #" + test + ": " + ans);
			
		}
		out.close();
		
		
	}
	
}
