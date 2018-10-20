package google.codejam._2014.round_1A;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class ChargingChaos {
	static int minSwitches = 0;
	static boolean hasSolution = false;
	static String[] initial;
	static String[] required;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/in.txt"));
		PrintWriter out = new PrintWriter("out.txt");

		int t = Integer.parseInt(in.readLine());

		for (int tc = 1; tc <= t; tc++) {
			String[] split = in.readLine().split(" ");
			int n = Integer.parseInt(split[0]);
			int l = Integer.parseInt(split[1]);

			initial = in.readLine().split(" ");
			required = in.readLine().split(" ");

			minSwitches = l + 1;

			for (int i = 0; i < Math.pow(2, l); i++) {
				hasSolution = true;

				String str = Integer.toBinaryString(i);
				while (str.length() < l) {
					str = '0' + str;
				}

				int presses = 0;
				List<String> initialList = new ArrayList<String>();
				for (int j = 0; j < n; j++) {
					initialList.add(initial[j]);
				}

				for (int j = 0; j < l; j++) {
					if (str.charAt(j) == '1') {
						pressSwitch(j, initialList);
						presses++;
					}
				}

				for (String requiredStr : required) {
					if (!initialList.contains(requiredStr)) {
						hasSolution = false;
						break;
					}
				}

				if (hasSolution) {
					if (presses < minSwitches) {
						minSwitches = presses;
					}
				}
			}

			hasSolution = (minSwitches != l + 1);
			if (hasSolution) {
				out.println("Case #" + tc+": " + minSwitches);
			} else {
				out.println("Case #" + tc+": " + "NOT POSSIBLE");
			}
		}

		in.close();
		out.close();
	}

	private static void pressSwitch(int s, List<String> initialList) {
		List<String> newList = new ArrayList<String>();

		ListIterator<String> listIterator = initialList.listIterator();
		while (listIterator.hasNext()) {
			String str = listIterator.next();
			int n = Integer.parseInt(str, 2);
			n = n ^ (1 << s);

			String newStr = Integer.toBinaryString(n) + "";
			while (newStr.length() < str.length()) {
				newStr = '0' + newStr;
			}
			newList.add(newStr);
			listIterator.remove();
		}

		initialList.addAll(newList);
	}
}
