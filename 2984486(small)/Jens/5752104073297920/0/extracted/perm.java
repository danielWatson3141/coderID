import java.awt.Point;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * @author Jens Staahl
 */

public class perm {

	// some local config
	static boolean test = true;
	static String testDataFile = "C-small-attempt3.in";

	// Just solves the acutal kattis-problem
	ZKattio io;

	class Point {
		double x;
		int y;
		boolean good = true;

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}

		public Point(double x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	private void solve() throws Throwable {
		io = new ZKattio(stream);
		long t0 = System.currentTimeMillis();
		BufferedWriter writer = new BufferedWriter(new FileWriter(this.getClass().getCanonicalName() + ".out"));
		int n = io.getInt();

		double[] PP = new double[n];
		List<Point> ans_ = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			ans_.add(new Point(solveCase(i + 1, writer), i + 1));
		}
		Collections.sort(ans_, new Comparator<Point>() {
			@Override
			public int compare(Point o1, Point o2) {
				return Double.compare(o1.x, o2.x);
			}
		});
		for (int i = 0; i < ans_.size() / 2; i++) {
			ans_.get(i).good = false;
		}
		long time = System.currentTimeMillis() - t0;
		System.out.println("Time: " + (time));
		for (int i = 0; i < n; i++) {
			boolean good = false;
			for (int j = 0; j < ans_.size(); j++) {
				if(ans_.get(j).y == i){
					good = ans_.get(j).good;
					break;
				}
			}

			String cc = good ? "GOOD" : "BAD";
			String ans = "Case #" + (i+1) + ": " + cc + "\n";

			writer.write(ans);
			System.out.print(ans);
		}

		writer.flush();
	}

	private double solveCase(int caseNr, BufferedWriter writer) throws Throwable {
		int n = io.getInt();
		int[] p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = io.getInt();
		}

		double P = 0.5;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (p[j] > p[i]) {
					cnt++;
				}
			}
		}
		boolean good = true;

		if (cnt >= n * (n + 1) / 2) {
			good = false;
		}
		return (cnt + 0.d) / n * (n + 1.0);

	}

	public static void main(String[] args) throws Throwable {
		new perm().solve();
	}

	public perm() throws Throwable {
		if (test) {
			stream = new FileInputStream(testDataFile);
		}
	}

	InputStream stream = System.in;
	BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));// outStream
																				// =
																				// System.out;

}