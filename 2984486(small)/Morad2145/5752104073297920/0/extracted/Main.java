package shuffle;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(
				"C-small-attempt1.in"));

		int T = Integer.parseInt(in.readLine());

		List<Case> cases = new ArrayList<Case>();
		for (int x = 1; x <= T; x++) {
			@SuppressWarnings("unused")
			int N = Integer.parseInt(in.readLine());

			String[] tokens = in.readLine().split(" ");
			cases.add(new Case(x, tokens));
		}

		in.close();

		Collections.sort(cases, new Comparator<Case>() {
			public int compare(Case c1, Case c2) {
				return Integer.compare(c1.fixedPoints, c2.fixedPoints);
			}
		});
		for (int i = 0; i < cases.size() / 2; i++) {
			cases.get(i).goodBad = "BAD";
		}

		Collections.sort(cases, new Comparator<Case>() {
			public int compare(Case c1, Case c2) {
				return Integer.compare(c1.x, c2.x);
			}
		});

		for (Case c : cases) {
			System.out.println(c.toString());
		}
	}

	private static class Case {
		final int x;
		final int[] permutation;
		final int fixedPoints;
		String goodBad = "GOOD";

		public Case(int x, String[] perm) {
			this.x = x;
			this.permutation = new int[perm.length];
			for (int i = 0; i < perm.length; i++) {
				this.permutation[i] = Integer.parseInt(perm[i]);
			}

			fixedPoints = countFixedPoints(permutation);
		}

		private static int countFixedPoints(int[] permutation) {
			int count = 0;
			for (int i = 0; i < permutation.length; i++) {
				if (permutation[i] == i) {
					count++;
				}
			}
			return count;
		}

		@Override public String toString(){
			return "Case #"+x+": "+goodBad;
		}
	}
}
