package gcj2014;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class ChargingChaos {
	static String PATH = "data/gcj2014/1a/", PROBLEM = "A", SIZE = "small",
			ATTEMPT = "0";

	static long ones(long n) {
		int count = 0;
		while (n > 0) {
			if (n % 2 == 1)
				count++;
			n /= 2;
		}
		return count;
	}

	public static void main(String[] args) throws IOException {
		String filename = PATH + PROBLEM + "-" + SIZE;
		if (SIZE.equals("small"))
			filename += "-attempt" + ATTEMPT;
		Scanner sc = new Scanner(new File(filename + ".in"));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(filename + ".out"));
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			System.out.println(t);
			int N = sc.nextInt();
			int L = sc.nextInt();
			Set<Long> inits = new HashSet<Long>(), goals = new HashSet<Long>();
			for (int i = 0; i < N; i++) {
				inits.add(Long.parseLong(sc.next("[0-1]+"), 2));
			}
			for (int i = 0; i < N; i++) {
				goals.add(Long.parseLong(sc.next("[0-1]+"), 2));
			}

			List<Long> switches = new ArrayList<Long>();

			boolean first = true;
			for (long init : inits) {
				if (first) {
					// use the first outlet to match the devices
					for (long goal : goals) {
						switches.add(init ^ goal);
					}
					first = false;
				} else {
					// check if the switches make the candidates valid
					List<Long> newSwitches = new ArrayList<Long>();
					int i = 0;
					while (i < switches.size()) {
						if (goals.contains((switches.get(i) ^ init))) {
							// valid, check the next switch candidate
							i++;
						} else {
							// not valid, remove this candidate
							switches.remove(i);
						}
					}
					if (switches.size() == 0) {
						// not possible
						break;
					}
				}
			}

			// now the rest switches are all possible candidates
			System.out.println(switches);

			// find the one with least 1's: fewest moves
			long min = L, minSwitch = -1;
			for (long s : switches) {
				long moves = ones(s);
				if (moves < min) {
					min = moves;
					minSwitch = s;
				}
			}

			bw.write("Case #" + (t + 1) + ": "
					+ (minSwitch == -1 ? "NOT POSSIBLE" : min));
			bw.newLine();
		}
		sc.close();
		bw.close();
	}
}
