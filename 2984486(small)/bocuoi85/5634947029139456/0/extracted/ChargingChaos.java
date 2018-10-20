import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ChargingChaos {
	static final String input = "A-small-attempt1.in";
	static final String output = "output.txt";

	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader(input));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				output)));

		int testCount = readInts(f)[0];
		for (int testcase = 1; testcase <= testCount; testcase++) {
			int[] temp = readInts(f);
			int n = temp[0];
			int l = temp[1];
			String[] originalSwitches = readStrings(f);
			String[] devices = readStrings(f);
			StringBuilder[] savedSwitches = new StringBuilder[n];
			StringBuilder[] switches = new StringBuilder[n];
			for (int i = 0; i < originalSwitches.length; i++)
				switches[i] = new StringBuilder(originalSwitches[i]);
			for (int i = 0; i < switches.length; i++) {
				savedSwitches[i] = new StringBuilder(switches[i]);
			}
			Arrays.sort(devices);
			int res = Integer.MAX_VALUE;
			for (int sw = 0; sw < n; sw++) {
				for (int de = 0; de < n; de++) {
					for (int i = 0; i < switches.length; i++) {
						switches[i] = new StringBuilder(savedSwitches[i]);
					}
					int count = 0;
					// match sw and de
					for (int i = 0; i < l; i++)
						if (switches[sw].charAt(i) != devices[de].charAt(i)) {
							for (int j = 0; j < n; j++)
								if (switches[j].charAt(i) == '0')
									switches[j].setCharAt(i, '1');
								else
									switches[j].setCharAt(i, '0');
							count++;
						}
					String[] newSwitches = new String[n];
					for (int i = 0; i < n; i++)
						newSwitches[i] = new String(switches[i]);
					Arrays.sort(newSwitches);
					boolean ignored = false;
					for (int i = 0; i < n; i++)
						if (!newSwitches[i].equals(devices[i])) {
							ignored = true;
							break;
						}
					if (!ignored && count < res)
						res = count;
				}
			}
			if (res < Integer.MAX_VALUE)
				print(out, "Case #" + testcase + ": " + res);
			else
				print(out, "Case #" + testcase + ": NOT POSSIBLE");
		}

		out.close();
		System.exit(0);
	}

	private static void print(PrintWriter out, String s) {
		out.println(s);
		System.out.println(s);
	}

	private static int[] readInts(BufferedReader f) throws IOException {
		StringTokenizer st = new StringTokenizer(f.readLine());
		int[] res = new int[st.countTokens()];
		for (int i = 0; i < res.length; i++)
			res[i] = Integer.parseInt(st.nextToken());
		return res;
	}

	private static double[] readDoubles(BufferedReader f) throws IOException {
		StringTokenizer st = new StringTokenizer(f.readLine());
		double[] res = new double[st.countTokens()];
		for (int i = 0; i < res.length; i++)
			res[i] = Double.parseDouble(st.nextToken());
		return res;
	}

	private static String[] readStrings(BufferedReader f) throws IOException {
		StringTokenizer st = new StringTokenizer(f.readLine());
		String[] res = new String[st.countTokens()];
		for (int i = 0; i < res.length; i++)
			res[i] = st.nextToken();
		return res;
	}
}
