

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

// Using the Google Guava library.
public class B {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/B-small-0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
			int n = in.nextInt();
			List<List<Integer>> list = new ArrayList<List<Integer>>();
			for (int i = 0; i <= n; i++) {
				list.add(new ArrayList<Integer>());
			}
			for (int i = 1; i < n; i++) {
				int x = in.nextInt();
				int y = in.nextInt();
				list.get(x).add(y);
				list.get(y).add(x);
			}
			// Try possible roots
			int best = 0;
			for (int i = 1; i <= n; i++) {
				if (list.get(i).size() == 1) {
					continue;
				}
//				System.out.println(i + " " + biggestTree(list, i, -1));
				best = Math.max(biggestTree(list, i, -1), best);
				
			}
			String ans = "Case #"+cs+": " + (n - best);
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		in.close();
	}
	
	private static int biggestTree(List<List<Integer>> list, int cur, int parent) {
		List<Integer> neighbors = list.get(cur);
		if (parent >= 0 && neighbors.size() <= 2) {
			return 1;
		}
		if (parent < 0 && neighbors.size() < 2) {
			return 1;
		}
		List<Integer> counts = new ArrayList<Integer>();
		for (int neigh : neighbors) {
			if (neigh != parent) {
				counts.add(biggestTree(list, neigh, cur));
			}
		}
		Collections.sort(counts);
		return 1 + counts.get(counts.size()-1) + counts.get(counts.size()-2);
	}
}
