

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

// Using the Google Guava library.
public class A {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/A-large-0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
			int n = in.nextInt();
			int l = in.nextInt();
			List<boolean []> init = readInput(in, n, l);
			List<boolean []> desired = readInput(in, n, l);
			Set<String> desiredSet = toString(desired);
			int minFlips = Integer.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					List<boolean []> copy =  new ArrayList<boolean[]>();
					for (boolean [] arr : init) {
						copy.add(Arrays.copyOf(arr, arr.length));
					}
					boolean[] flipped = new boolean[l];
					int flips = 0;
					for (int k = 0; k < l; k++) {
						if (copy.get(0)[k] != desired.get(j)[k]) {
							flips++;
							flipped[k] = true;
						}
					}
					if (flips >= minFlips) {
						continue;
					}
					for (int m = 0; m < n; m++) {
						for (int k = 0; k < l; k++) {
							copy.get(m)[k] ^= flipped[k];
						}
					}
					if (toString(copy).equals(desiredSet)) {
						minFlips = flips;
					}
				}
			}
			
			String ans = "Case #"+cs+": " + ((minFlips == Integer.MAX_VALUE) ? "NOT POSSIBLE" : minFlips);
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		in.close();
	}

	private static List<boolean []> readInput(Scanner in, int n, int l) {
		List<boolean []> init = new ArrayList<boolean[]>();
		for (int i = 0; i < n; i++) {
			String tok = in.next();
			boolean [] cur = new boolean[l];
			for (int j = 0; j < l; j++) {
				cur[j] = tok.charAt(j) == '1';
			}
			init.add(cur);
		}
		return init;
	}
	
	private static Set<String> toString(List<boolean []> list) {
		Set<String> set = new HashSet<String> ();
		for (boolean [] arr : list) {
			StringBuilder sb = new StringBuilder();
			for (boolean b : arr) {
				sb.append(b ? '1' : '0');
			}
			set.add(sb.toString());
		}
		return set;
	}
}
