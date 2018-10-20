package dcho;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;

public class Round2q1 {
	private int count;
	private int T;
	private String[] lines;

	public Round2q1(String filename) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));

			this.count = 0;
			this.T = Integer.parseInt(br.readLine());
			this.lines = new String[3 * T];

			String s;
			int i = 0;
			while ((s = br.readLine()) != null)
				lines[i++] = s;
		} catch (FileNotFoundException e) {
			System.out.println("File was not found.");
		} catch (NumberFormatException e) {
			System.out.println("This expected a number but did not get one.");
		} catch (IOException e) {
			System.out.println("IOException occurred.");
		}
	}

	// public String getRow(int r) {
	// String row = lines[count + r - 1];
	// count += 4;
	// return row;
	// }

	public String[] get() {
		return lines[count++].split(" ");
	}

	public void solve() {
		// FIRST LINE IS GOALS
		HashSet<String> goals = new HashSet<String>();

		for (int i = 0; i < T; i++) {
			goals.clear();
			String[] vals = get();
			int N = Integer.parseInt(vals[0]);
			int L = Integer.parseInt(vals[1]);

			int min = L + 1;

			for (String x : get())
				goals.add(x);

			vals = get();
			String first = vals[0];

			for (String x : goals) {
				int[] diffs = diff(first, x);
				if (diffs.length < min) {
					String[] newVals = flip(vals, diffs);

					int c = 0;
					for (String s : newVals)
						if (goals.contains(s))
							c++;
					if (c == N)
						min = diffs.length;
				}
			}

			System.out.print("Case #" + (i + 1) + ": ");
			if (min == L + 1)
				System.out.println("NOT POSSIBLE");
			else
				System.out.println(min);
		}
	}

	private int[] diff(String a, String b) {
		int n = 0;

		for (int i = 0; i < a.length(); i++)
			if (a.charAt(i) != b.charAt(i))
				n++;

		int[] ret = new int[n];

		n = 0;
		for (int i = 0; i < a.length(); i++)
			if (a.charAt(i) != b.charAt(i))
				ret[n++] = i;

		return ret;
	}

	private String[] flip(String[] vals, int[] diffs) {
		StringBuilder sb;
		String[] ns = new String[vals.length];

		for (int i = 0; i < vals.length; i++) {
			int count = 0;
			sb = new StringBuilder();

			for (int j = 0; j < diffs.length; j++) {
				sb.append(vals[i].substring(count, diffs[j]));
				sb.append(vals[i].charAt(diffs[j]) == '0' ? '1' : '0');
				count = diffs[j] + 1;
			}
			sb.append(vals[i].substring(count));
			ns[i] = sb.toString();
		}
		return ns;
	}

	public static void main(String[] args) {
		Round2q1 x = new Round2q1("src/A-small-attempt0.in.txt");
		x.solve();
	}
}
