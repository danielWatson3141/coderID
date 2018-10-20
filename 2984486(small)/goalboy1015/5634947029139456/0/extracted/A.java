import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class A {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "A";
	static final String INPUT = "small";
	static final String ID = "0";
	static final String PATH = "/Users/wangkai/Documents/software installer/codejam-commandline-1.2-beta1/source/";

	public static void main(String[] args) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int N = in.nextInt();
			int L = in.nextInt();
			String[] outletFlows = readFlows(in, N);
			String[] deviceFlows = readFlows(in, N);

			int minSwitchNum = Integer.MAX_VALUE;
			for (String deviceFlow : deviceFlows) {
				ArrayList<Integer> switches = compare(outletFlows[0],
						deviceFlow);

				if (switches.size() < minSwitchNum
						&& isSame(deviceFlows,
								makeSwitch(outletFlows, switches))) {
					minSwitchNum = switches.size();
				}
			}

			if (minSwitchNum == Integer.MAX_VALUE) {
				out.println("NOT POSSIBLE");
			} else {
				out.println(minSwitchNum);
			}
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	static String[] readFlows(Scanner in, int N) {
		String[] flows = new String[N];
		for (int i = 0; i < flows.length; i++) {
			flows[i] = in.next();
		}
		return flows;
	}

	static ArrayList<Integer> compare(String flow1, String flow2) {
		ArrayList<Integer> switches = new ArrayList<Integer>();
		for (int i = 0; i < flow1.length(); i++) {
			if (flow1.charAt(i) != flow2.charAt(i)) {
				switches.add(i);
			}
		}
		return switches;
	}

	static String[] makeSwitch(String[] flows, ArrayList<Integer> switches) {
		String[] switchedFlows = new String[flows.length];
		for (int i = 0; i < switchedFlows.length; i++) {
			StringBuffer flow = new StringBuffer(flows[i]);
			for (int index : switches) {
				flow.setCharAt(index, (char) (('0' + '1') - flow.charAt(index)));
			}
			switchedFlows[i] = flow.toString();
		}
		return switchedFlows;
	}

	static boolean isSame(String[] flows1, String[] flows2) {
		return new HashSet<String>(Arrays.asList(flows1))
				.equals(new HashSet<String>(Arrays.asList(flows2)));
	}
}
