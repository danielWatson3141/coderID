import java.io.*;
import java.util.*;

public class A {

	public static void main(String[] args) {
		new A().run();
	}

	private void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader(FNAME + ".in"));
			out = new PrintWriter(FNAME + ".out");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(566);
		}
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;
	Random rand = new Random(12345);

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	String FNAME = "a";

	private void solve() throws IOException {
		int testn = nextInt();
		for (int test = 1; test <= testn; test++) {
			out.print("Case #" + test + ": ");
			int n = nextInt();
			int len = nextInt();
			String[] a = new String[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextToken();
			}
			String[] b = new String[n];
			for (int i = 0; i < b.length; i++) {
				b[i] = nextToken();
			}
			ArrayList<Group> g = new ArrayList<>();
			g.add(new Group(a, b));
			int ans = match(g, 0, len);
			out.println(ans >= Integer.MAX_VALUE / 2 ? "NOT POSSIBLE" : ans);
			out.flush();
		}
	}

	private int match(ArrayList<Group> g, int x, int q) {
		if (x >= q) {
			return 0;
		}
		boolean canStay = true;
		boolean canFlip = true;
		for (int i = 0; i < g.size(); i++) {
			System.out.println(g.get(i).a.length + " " + g.get(i).b.length);
			int[] a = new int[2];
			int[] b = new int[2];
			for (int j = 0; j < g.get(i).a.length; j++) {
				a[g.get(i).a[j].charAt(x) - '0']++;
				b[g.get(i).b[j].charAt(x) - '0']++;
			}
			canStay &= a[0] == b[0] && a[1] == b[1];
			canFlip &= a[1] == b[0] && a[0] == b[1];
		}
		int ans = Integer.MAX_VALUE / 2;
		if (canStay) {
			ArrayList<Group> z = new ArrayList<>();
			for (int i = 0; i < g.size(); i++) {
				ArrayList<String>[] a = new ArrayList[2];
				ArrayList<String>[] b = new ArrayList[2];
				for (int j = 0; j < b.length; j++) {
					a[j] = new ArrayList<>();
					b[j] = new ArrayList<>();
				}
				for (int j = 0; j < g.get(i).a.length; j++) {
					a[g.get(i).a[j].charAt(x) - '0'].add(g.get(i).a[j]);
					b[g.get(i).b[j].charAt(x) - '0'].add(g.get(i).b[j]);
				}
				if (a[0].size() > 0) {
					z.add(new Group(a[0], b[0]));
				}
				if (a[1].size() > 0) {
					z.add(new Group(a[1], b[1]));
				}
			}
			ans = Math.min(ans, match(z, x + 1, q));
		}
		if (canFlip) {
			ArrayList<Group> z = new ArrayList<>();
			for (int i = 0; i < g.size(); i++) {
				ArrayList<String>[] a = new ArrayList[2];
				ArrayList<String>[] b = new ArrayList[2];
				for (int j = 0; j < b.length; j++) {
					a[j] = new ArrayList<>();
					b[j] = new ArrayList<>();
				}
				for (int j = 0; j < g.get(i).a.length; j++) {
					a[g.get(i).a[j].charAt(x) - '0'].add(g.get(i).a[j]);
					b[g.get(i).b[j].charAt(x) - '0'].add(g.get(i).b[j]);
				}
				if (a[0].size() > 0) {
					z.add(new Group(a[0], b[1]));
				}
				if (a[1].size() > 0) {
					z.add(new Group(a[1], b[0]));
				}
			}
			ans = Math.min(ans, match(z, x + 1, q) + 1);
		}
		return ans;
	}

	class Group {
		public Group(String[] a2, String[] b2) {
			a = a2.clone();
			b = b2.clone();
		}

		public Group(ArrayList<String> al1, ArrayList<String> al2) {
			a = new String[al1.size()];
			b = new String[al2.size()];
			for (int i = 0; i < a.length; i++) {
				a[i] = al1.get(i);
				b[i] = al2.get(i);
			}
		}

		String[] a;
		String[] b;
	}

}
