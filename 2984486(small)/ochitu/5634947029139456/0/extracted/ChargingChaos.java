package shb.test.codejam.k14.round1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ChargingChaos {
	
//	private JamInputReader jam;
	private Scanner scanner;
	private StringBuffer out;

	public static void main(String[] args) throws IOException {
		ChargingChaos problem = new ChargingChaos("R1A-A-small-attempt0.in");
		
		int tests = problem.scanner.nextInt();

		for (int t = 1; t <= tests; t++) {
			problem.solve(t);
		}

		problem.printResults("chaos.out");
		problem.scanner.close();
	}


	private void solve(int t)  throws IOException{
		int n = scanner.nextInt();
		int l = scanner.nextInt();
		
		long[] outlets = new long[n];
		
		Set<Long> devices = new HashSet<Long>();
		for (int i = 0; i < n; i++) {
			//read n strings of lenght L
			String s = scanner.next();
			long nr = 0l;
			int pow = 1;
			for (int c=0; c<s.length(); c++) {
				nr += pow * (s.charAt(c) - 48);
				pow *=2;
			}
			outlets[i] = nr;
		}
		
		for (int i = 0; i < n; i++) {
			//read n strings of lenght L
			String s = scanner.next();
			long nr = 0l;
			int pow = 1;
			for (int c=0; c<s.length(); c++) {
				nr += pow * (s.charAt(c) - 48);
				pow *=2;
			}
			devices.add(nr);
		}
		int minSwitches = Integer.MAX_VALUE;
		
		for (long switc = 0; switc <= (long)Math.pow(2, l); switc++) {
			int switchesPulled = 0;
			Set<Long> switched = new HashSet<Long>();
			
			for (int i = 0; i < n; i++) {
				//apply switch to outlet[j]
				long num = outlets[i];
				long k = switc;
				
//				long newOutlet = 0l;
				int step = 0;
				while (k > 0) {
					long lastSwitchBit = k & 1;
					
					if (lastSwitchBit == 1) {
						switchesPulled++;
						long bit = ((num>>step) & 1)^1;
						
						num = ((((num>>step+1)<<1)|bit)<<step)|(num & ((1<<step)-1));
//					} else {
//						long lastBit = (num & 1);
//						newOutlet = newOutlet | (lastBit<<step);
					}
					k = k>>1;
//					num = num >> 1;
					step++;
				}
				switched.add(num);
			}
			
			switchesPulled/=n;
			//check sets are the same
			assert switched.size() == n;
			if (switched.containsAll(devices) && devices.containsAll(switched)) {
				//end formation
				if (switchesPulled < minSwitches) {
					minSwitches = switchesPulled;
				}
			}
		}
		
		if (t > 1) {
			out.append("\n");
		}
		out.append("Case #" + t + ": ");
		if (minSwitches == Integer.MAX_VALUE) {
			out.append("NOT POSSIBLE");
		} else {
			out.append(minSwitches);
		}
	}


	public ChargingChaos(String filename) throws FileNotFoundException {
//		jam = new JamInputReader(filename);
		scanner = new Scanner(new File(filename));
		out = new StringBuffer();
	}

	private void printResults(String filename) throws IOException {
		BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
		writer.append(out.toString());
		writer.close();
	}
}
