package round1a;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {
	
	public static String FAIL = "NOT POSSIBLE";

	public static void main(String[] args) throws IOException {

		String path = "A";
		BufferedReader in = new BufferedReader(new FileReader(Main.DIR + path + ".in"));
		PrintWriter out = new PrintWriter(Main.DIR + path + ".out");
		
		int inputs = Integer.parseInt(in.readLine());
		
		next: for (int i = 0; i < inputs; i++) {
			String[] split = in.readLine().split(" ");
			long N = Long.parseLong(split[0]);
			long L = Long.parseLong(split[1]);
			
			String[] initial = in.readLine().split(" ");
			String[] required = in.readLine().split(" ");
			Arrays.sort(initial);
			Arrays.sort(required);
			
			//System.out.println("init: "+Arrays.toString(initial));
			//System.out.println("req: "+Arrays.toString(required));
			
			HashSet<String> hist = new HashSet<>();
			
			Queue<String[]> queue = new LinkedList<>();
			queue.add(initial);
			int distance = 0;
			int frontierSize = 1;
			
			while (!queue.isEmpty()) {
				int newFrontierSize = 0;
				
				for (int k = 0; k < frontierSize; k++) {
					String[] current = queue.remove();
					Arrays.sort(current);
					
					//System.out.println(distance+": "+Arrays.toString(current));
					
					if (isSame(current, required)) {
						System.out.println("Case #"+(i+1)+": "+distance);
						out.println("Case #"+(i+1)+": "+distance);
						continue next;
					}
					
					if (hist.contains(concat(current)))
						continue;
					
					hist.add(concat(current));
					
					for (int l = 0; l < L; l++) {
						
						String[] neighbor = flip(current, l);
						Arrays.sort(neighbor);
						if (!hist.contains(concat(neighbor))) {
							queue.add(neighbor);
							newFrontierSize++;
						}
							
					}
				}
				
				frontierSize = newFrontierSize;
				distance++;
			}
			
			System.out.println("Case #"+(i+1)+": "+FAIL);
			out.println("Case #"+(i+1)+": "+FAIL);
		}
		
		in.close();
		out.close();
		
	}
	
	public static String concat(String[] a) {
		StringBuilder builder = new StringBuilder();
		for (String s : a)
			builder.append(s);
		return builder.toString();
	}
	
	public static boolean isSame(String[] a1, String[] a2) {
		for (int i = 0; i < a1.length; i++) {
			if (!a1[i].equals(a2[i]))
				return false;
		}
		return true;
	}
	
	public static String[] flip(String[] a, int i) {
		
		String[] ans = new String[a.length];
		for (int j = 0; j < a.length; j++) {
			String cur = a[j];
			char old = cur.charAt(i);
			String flipped = cur.substring(0,i) + flip(old) + cur.substring(i+1);
			ans[j] = flipped;
		}
		

		return ans;
	}
	
	public static char flip(char c) {
		return c == '1' ? '0' : '1';
	}
	
}
