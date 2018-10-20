import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class ProblemA {

	// private static final String PROBLEM_NAME = "A-test";

	// private static final String PROBLEM_NAME = "A-small-attempt0";
	// private static final String PROBLEM_NAME = "A-small-attempt1";
	//private static final String PROBLEM_NAME = "A-small-attempt2";
	private static final String PROBLEM_NAME = "A-small-attempt3";

	// private static final String PROBLEM_NAME = "A-large";

	private static String flip(String s, int index) {
		char c = s.charAt(index);
		String result = s.substring(0, index);
		if (c == '0') {
			result += "1";
		} else {
			result += "0";
		}
		result += index < s.length() ? s.substring(index + 1) : "";
		return result;
	}

	private static void flipSwitches(List<String> sockets, int mask, int l) {
		int i = 0;
		int r = 1;
		while (i < l) {
			if ((r & mask) == r) {
				for (int j = 0; j < sockets.size(); j++) {
					sockets.set(j, flip(sockets.get(j), i));
				}
			}
			i++;
			r = 1 << i;
		}
	}

	public static int count(List<String> sockets, List<String> devices, int l) {
		Collections.sort(devices);
		boolean found = false;

		int maskMax = 1 << l;
		int mask = 0;
		for (int i = 0; i <= l; i++) {
			for (mask = 0; mask < maskMax; mask++) {
				if (flipsCount(mask, l) != i) {
					continue;
				}
				List<String> socketsPermutation = new ArrayList<String>(sockets);
				flipSwitches(socketsPermutation, mask, l);
				Collections.sort(socketsPermutation);
				socketsPermutation.removeAll(devices);
				if (socketsPermutation.size() == 0) {
					found = true;
					break;
				}
			}
			if (found) {
				break;
			}
		}

		return found ? flipsCount(mask, l) : -1;
	}

	private static int flipsCount(int mask, int l) {
		int flipsCount = 0;
		int i = 0;
		int r = 1;
		while (i < l) {
			if ((r & mask) == r) {
				flipsCount++;
			}
			i++;
			r = 1 << i;
		}
		return flipsCount;
	}

	public static void solve(Scanner in, PrintStream out) {
		int n = in.nextInt();
		int l = in.nextInt();
		List<String> sockets = new ArrayList<String>();
		for (int i = 0; i < n; i++) {
			sockets.add(in.next());
		}
		List<String> devices = new ArrayList<String>();
		for (int i = 0; i < n; i++) {
			devices.add(in.next());
		}

		int count = count(sockets, devices, l);
		if (count > -1) {
			out.println(count);
		} else {
			out.println("NOT POSSIBLE");
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File(PROBLEM_NAME + ".in"));
		PrintStream out = new PrintStream(new File(PROBLEM_NAME + ".out"));

		int t = in.nextInt();
		int caseNumber = 1;
		while (caseNumber <= t) {
			out.print("Case #" + caseNumber++ + ": ");
			solve(in, out);
		}
	}

}
