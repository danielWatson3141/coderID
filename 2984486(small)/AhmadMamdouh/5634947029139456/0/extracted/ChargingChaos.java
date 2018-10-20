import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class ChargingChaos {
	static String problem = "A";

	public static void main(String[] args) throws Exception {
//		InputReader r = new InputReader(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		 InputReader r = new InputReader(new FileReader(problem +
		 ".in"));
		 PrintWriter out = new PrintWriter(new FileWriter(problem +
		 "Solution.out"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			int n = r.nextInt();
			int l = r.nextInt();
			String[] outlets = new String[n];
			for (int i = 0; i < outlets.length; i++)
				outlets[i] = r.next();
			String[] devices = new String[n];
			for (int i = 0; i < devices.length; i++)
				devices[i] = r.next();
			int res = 1 << 28;
			for (int i = 0; i < n; i++) {
				String d = devices[i];
				for (int j = 0; j < n; j++) {
					String outlet = outlets[j];
					int req = 0;
					for (int x = 0; x < l; x++)
						if (d.charAt(x) != outlet.charAt(x))
							req++;
					String[] newOutlets = new String[n];
					Arrays.fill(newOutlets, "");
					for (int k = 0; k < newOutlets.length; k++) {
						for (int x = 0; x < l; x++) {
							if (d.charAt(x) == outlet.charAt(x))
								newOutlets[k] += outlets[k].charAt(x);
							else {
								newOutlets[k] += (outlets[k].charAt(x) == '0' ? '1'
										: '0');
							}
						}
					}
					int can = 0;
					for (int k = 0; k < newOutlets.length; k++) {
						for (int x = 0; x < newOutlets.length; x++) {
							if (newOutlets[k].equals(devices[x]))
								can++;
						}
					}
					if (can == n)
						res = Math.min(res, req);
				}
			}
			if (res == 1 << 28)
				out.printf("Case #%d: NOT POSSIBLE\n", test++);
			else
				out.printf("Case #%d: %d\n", test++, res);
		}
		out.close();
	}

	static class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public InputReader(FileReader stream) {
			reader = new BufferedReader(stream);
			tokenizer = null;
		}

		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
