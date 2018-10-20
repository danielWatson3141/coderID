import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Prob1
{
	private static final int PROB = 1;
	private static final int ATTEMPT = 1;

	public static void main(final String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new FileReader(
				String.format("data%d%d.txt", PROB, ATTEMPT)));
		PrintWriter writer = new PrintWriter(new FileWriter(String.format(
				"out%d%d.txt", PROB, ATTEMPT)));
		int noCases = Integer.parseInt(reader.readLine());
		for (int testCase = 1; testCase <= noCases; testCase++) {
			String[] n_l = reader.readLine().split(" ");
			int n = Integer.parseInt(n_l[0]);
			int l = Integer.parseInt(n_l[1]);
			String[] a = reader.readLine().split(" ");
			String[] b = reader.readLine().split(" ");
			ArrayList<String> start = new ArrayList<String>();
			ArrayList<String> end = new ArrayList<String>();
			for (int i = 0; i < n; i++) {
				start.add(a[i]);
				end.add(b[i]);
			}
			int val = calc(start, end, n, l, 0);

			String output = val == -1 ? "NOT POSSIBLE" : ("" + val);
			writer.printf("Case #%d: %s%n", testCase, output);
		}
		writer.close();
		reader.close();
	}

	private static int calc(ArrayList<String> start, ArrayList<String> end,
			int n, int l, int pos)
	{
		ArrayList<String> q = new ArrayList<String>(end);
		q.retainAll(start);
		if (q.size() == n)
			return 0;
		if (pos == l) {
			return -1;
		}
		ArrayList<String> next = new ArrayList<String>();
		char[][] wint = new char[n][l];
		for (int i = 0; i < n; i++) {
			wint[i] = start.get(i).toCharArray();
			wint[i][pos] = wint[i][pos] == '1' ? '0' : '1';
			next.add(new String(wint[i]));
		}
		int a = calc(start, end, n, l, pos + 1);
		int b = calc(next, end, n, l, pos + 1);
		if (a != -1) {
			if (b != -1)
				return a < b + 1 ? a : b + 1;
			return a;
		}
		if (b != -1)
			return b + 1;
		return -1;
	}
}
