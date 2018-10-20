package com.google.jam2014.Roudn1A;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class ChargingChaos {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		FileInputStream fis = new FileInputStream(args[0]);
		PrintWriter pw = new PrintWriter(new File(args[1]));
		Scanner scanner = new Scanner(fis);
		int T = scanner.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = scanner.nextInt();
			int L = scanner.nextInt();
			scanner.nextLine();
			String outletSs = scanner.nextLine().trim();
			String deviceSs = scanner.nextLine().trim();
			String[] outlets = outletSs.split(" ");
			String[] devices = deviceSs.split(" ");
			HashSet<String> deviceMap = new HashSet<String>();
			for (int j = 0; j < N; j++) {
				deviceMap.add(devices[j]);
			}
			int result = L + 1;
			for (int j = 0; j < N; j++) {
				boolean[] solution = new boolean[L];
				int changes = 0;
				for (int k = 0; k < L; k++) {
					if (outlets[0].charAt(k) == devices[j].charAt(k))
						solution[k] = false;
					else {
						solution[k] = true;
						changes++;
					}
				}
				boolean failure = false;
				for (int k = 1; k < N && !failure; k++) {
					StringBuilder newOutlet = new StringBuilder();
					for (int l = 0; l < L; l++) {
						if (solution[l]) {
							newOutlet.append(outlets[k].charAt(l) == '0' ? '1' : '0');
						} else {
							newOutlet.append(outlets[k].charAt(l));
						}
					}
					String tmp = newOutlet.toString(); 
					if (!deviceMap.contains(tmp)) {
						failure = true;
						break;
					}
				}
				
				if (!failure) {
					result = result < changes ? result : changes;
				}
			}
			if (result <= L) {
				System.out.println("Case #" + i + ": " + result);
				pw.println("Case #" + i + ": " + result);
			} else {
				System.out.println("Case #" + i + ": NOT POSSIBLE");
				pw.println("Case #" + i + ": NOT POSSIBLE");
			}
		}
		pw.close();
	}

}
