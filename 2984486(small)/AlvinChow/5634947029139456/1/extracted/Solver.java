import java.io.*;
import java.util.*;

public class Solver {

	private Scanner in;
	private PrintStream out;

	public static void main(String[] args) throws Exception {
		if (args.length < 1)
			System.out.println("No input file");
		else
			new Solver(new File(args[0]), new File(args[0] + ".out"));
	}

	public Solver(File inFile, File outFile) throws Exception {
		try (final OutputStream fileOs = new FileOutputStream(outFile)) {
			in = new Scanner(inFile);
			out = new PrintStream(new OutputStream() {
				@Override
				public void write(int b) throws IOException {
					System.out.write(b);
					fileOs.write(b);
				}
			});
			init();
			int T = in.nextInt();
			in.nextLine();
			for (int i = 1; i <= T; i++) {
				out.print("Case #" + i + ": ");
				solve();
				out.println();
			}
		}
	}

	/* ******************************************************** */
	/* start here */
	/* ******************************************************** */

	public void init() throws Exception {
		// nothing
	}

	public void solve() throws Exception {
		int N = in.nextInt();
		int L = in.nextInt();
		in.nextLine();
		Set<String> initialSet = new TreeSet<String>(Arrays.asList(in.nextLine().split("\\s+")));
		Set<String> targetSet = new TreeSet<String>(Arrays.asList(in.nextLine().split("\\s+")));

		if (test(initialSet, targetSet, new LinkedList<Integer>())) {
			out.print(0);
			return;
		}

		int minChange = 10000;

		for (String initial : initialSet) {
			for (String target : targetSet) {
				List<Integer> changes = getChanges(initial, target);
				if (changes.size() == 0)
					continue;
				if (test(initialSet, targetSet, changes)) {
					if (changes.size() == 1) {
						out.print(1);
						return;
					}
					minChange = Math.min(minChange, changes.size());
				}
			}
		}

		if (minChange >= 10000)
			out.print("NOT POSSIBLE");
		else
			out.print(minChange);

	}

	public boolean test(Set<String> initialSet, Set<String> targetSet, List<Integer> changes) {
		Set<String> changeSet = new HashSet<String>();
		for (String initial : initialSet) {
			String change = change(initial, changes);
			if (changeSet.contains(change) || !targetSet.contains(change))
				return false;
			changeSet.add(change);
		}
		return true;
	}

	public String change(String initial, List<Integer> changes) {
		char[] change = initial.toCharArray();
		for (Integer pos : changes) {
			change[pos] = change[pos] == '1' ? '0' : '1';
		}
		return new String(change);
	}

	public List<Integer> getChanges(String initial, String target) {
		List<Integer> changes = new LinkedList<Integer>();
		for (int i = 0; i < initial.length(); i++) {
			if (initial.charAt(i) != target.charAt(i))
				changes.add(i);
		}

		return changes;
	}
}
