import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.Map.Entry;

public class Main {
	public static void main(String[] args) throws IOException {
		(new Main()).solve();
	}

	public Main() {
	}
	
	//MyReader in = new MyReader();
	//PrintWriter out = new PrintWriter(System.out);
	
	void solve() throws IOException {
		//BufferedReader in = new BufferedReader(new
		//InputStreamReader(System.in));
		//Scanner in = new Scanner(System.in);
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new FileReader("input.txt"));
		PrintWriter out = new PrintWriter("output.txt");
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			int n = in.nextInt();
			int L = in.nextInt();
			String[] outlets = new String[n];
			String[] devices = new String[n];
			Set<String> d = new HashSet<String>();
			for (int j = 0; j < n; j++) {
				outlets[j] = in.next();//in.nextString();
			}
			for (int j = 0; j < n; j++) {
				devices[j] = in.next();//in.nextString();
				d.add(devices[j]);
			}
			int min = Integer.MAX_VALUE;
			for (int j = 0; j < n; j++) {
				Set<Integer> a = new HashSet<Integer>();
				for (int k = 0; k < L; k++) {
					if (outlets[0].charAt(k) != devices[j].charAt(k)) {
						a.add(k);
					}
				}
				boolean flag = true;
				for (int k = 1; k < n; k++) {
					StringBuilder sb = new StringBuilder();
					for (int p = 0; p < L; p++) {
						if (a.contains(p)) {
							char ch = outlets[k].charAt(p) == '1' ? '0' : '1';
							sb.append(ch);
						} else {
							sb.append(outlets[k].charAt(p));
						}
					}
					if (!d.contains(sb.toString())) {
						flag = false;
					}
				}
				if (flag && a.size() < min) {
					min = a.size();
				}
			}
			out.print("Case #" + (i + 1) + ": ");
			if (min <= L) {
				out.println(min);
			} else {
				out.println("NOT POSSIBLE");
			}
		}
		out.close();
	}

	class MyReader {
		private BufferedReader in;
		String[] parsed;
		int index = 0;

		public MyReader() {
			in = new BufferedReader(new InputStreamReader(System.in));
		}

		public int nextInt() throws NumberFormatException, IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return Integer.parseInt(parsed[index++]);
		}

		public long nextLong() throws NumberFormatException, IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return Long.parseLong(parsed[index++]);
		}
		
		public double nextDouble() throws NumberFormatException, IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return Double.parseDouble(parsed[index++]);
		}
		
		public String nextString() throws IOException {
			if (parsed == null || parsed.length == index) {
				read();
			}
			return parsed[index++];
		}

		private void read() throws IOException {
			parsed = in.readLine().split(" ");
			index = 0;
		}

		public String readLine() throws IOException {
			return in.readLine();
		}
		
		public int read(char[] cbuf) throws IOException {
			return in.read(cbuf);
		}
	}

};