import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.BitSet;

/**
 * @author Jens Staahl
 */

public class fst {

	// some local config
	static boolean test = true;
	static String testDataFile = "A-small-attempt0 (1).in";

	// Just solves the acutal kattis-problem
	ZKattio io;

	private void solve() throws Throwable {
		io = new ZKattio(stream);
		long t0 = System.currentTimeMillis();
		BufferedWriter writer = new BufferedWriter(new FileWriter(this.getClass().getCanonicalName() + ".out"));
		int n = io.getInt();
		for (int i = 0; i < n; i++) {
			solveCase(i + 1, writer);
		}
		writer.flush();
		long time = System.currentTimeMillis() - t0;
		System.out.println("Time: " + (time));
	}

	private void solveCase(int caseNr, BufferedWriter writer) throws Throwable {
		int n = io.getInt(), L = io.getInt();
		BitSet[] set = new BitSet[n];
		BitSet[] target = new BitSet[n];
		for (int i = 0; i < n; i++) {
			set[i] = new BitSet();
			String word = io.getWord();
			for (int j = 0; j < word.length(); j++) {
				if (word.charAt(j) == '1') {
					set[i].set(j);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			target[i] = new BitSet();
			String word = io.getWord();
			for (int j = 0; j < word.length(); j++) {
				if (word.charAt(j) == '1') {
					target[i].set(j);
				}
			}
		}

		int best = Integer.MAX_VALUE;
		outout: for (int i = 0; i < n; i++) {
			int cnt = 0;
			BitSet flip = new BitSet();
			for (int j = 0; j < L; j++) {
				if (set[0].get(j) != target[i].get(j)) {
					flip.set(j);
					cnt++;
				}
			}
			if (cnt > best) {
				continue;
			}
			BitSet[] cp = new BitSet[n];
			for (int j = 0; j < cp.length; j++) {
				BitSet c = (BitSet) set[j].clone();
				for (int k = 0; k < L; k++) {
					if (flip.get(k)) {
						c.flip(k);
					}
				}
				cp[j] = c;
			}
			out: for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if(cp[j].equals(target[k])){
						continue out;
					}
				}
				continue outout;
			}

			best = Math.min(cnt, best);
		}
		String cc = best < Integer.MAX_VALUE ? best + "" : "NOT POSSIBLE";

		String ans = "Case #" + caseNr + ": " + cc + "\n";

		writer.write(ans);
		System.out.print(ans);
	}

	public static void main(String[] args) throws Throwable {
		new fst().solve();
	}

	public fst() throws Throwable {
		if (test) {
			stream = new FileInputStream(testDataFile);
		}
	}

	InputStream stream = System.in;
	BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));// outStream
																				// =
																				// System.out;

}