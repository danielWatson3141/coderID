package com.fabio.casado.codejam;

import java.util.Scanner;

public class ChargingChaos {

	static int tests;
	static int N, L;
	static int devices[][];
	static int outlets[][];
	static boolean usedOutlets[];
	static int solution[];
	static int finalAnswer;

	public static void main(String[] args) {
		// Read test case
		Scanner scanner = new Scanner(System.in);
		tests = scanner.nextInt();

		String line, device;
		int deviceEnd;
		for (int cases = 1; cases <= tests; cases++) {
			N = scanner.nextInt();
			L = scanner.nextInt();
			line = scanner.nextLine();

			devices = new int[N][L];
			line = scanner.nextLine();
			for (int count = 0; count < N; count++) {
				deviceEnd = line.indexOf(" ");
				if (deviceEnd != -1) {
					device = line.substring(0, line.indexOf(" "));
				} else {
					device = line;
				}

				for (int digit = 0; digit < L; digit++) {
					devices[count][digit] = device.charAt(digit) - '0';
				}

				if (count + 1 < N) {
					line = line.substring(line.indexOf(" ") + 1);
				}
			}

			outlets = new int[N][L];
			usedOutlets = new boolean[N];
			solution = new int[L];
			finalAnswer = 9999999;
			line = scanner.nextLine();
			for (int count = 0; count < N; count++) {
				deviceEnd = line.indexOf(" ");
				if (deviceEnd != -1) {
					device = line.substring(0, line.indexOf(" "));
				} else {
					device = line;
				}

				for (int digit = 0; digit < L; digit++) {
					outlets[count][digit] = device.charAt(digit) - '0';
				}

				if (count + 1 < N) {
					line = line.substring(line.indexOf(" ") + 1);
				}
			}
			
			// Solve problem
			testSwitches(0);
			if (finalAnswer == 9999999) {
				System.out.println(String.format("Case #%d: NOT POSSIBLE", cases));
			} else {
				System.out.println(String.format("Case #%d: %d", cases, finalAnswer));
			}
		}
	}

	private static void testSwitches(int currentSwitch) {
		if (isSolution()) {
			int moves = 0;
			for (int i = 0; i < L; i++) {
				moves += solution[i];
			}
			
			if (finalAnswer > moves) {
				finalAnswer = moves;
			}
		}
		
		if (currentSwitch >= L) {
			return;
		}
		
		for (int i = 1; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				solution[currentSwitch] = i;
				if (devices[j][currentSwitch] == 0) {
					devices[j][currentSwitch] = 1;
				} else {
					devices[j][currentSwitch] = 0;
				}
			}
			
			testSwitches(currentSwitch + 1);
		}
	}

	private static boolean isSolution() {
		boolean result = true;
		for (int i = 0; i < N; i++) {
			if (!checkOutletForDevice(i)) {
				result = false;
				break;
			}
		}

		for (int i = 0; i < N; i++) {
			usedOutlets[i] = false;
		}
		return result;
	}

	private static boolean checkOutletForDevice(int deviceIndex) {
		boolean foundOutlet = true;
		for (int i = 0; i < N; i++) {
			foundOutlet = true;
			if (usedOutlets[i]) {
				foundOutlet = false;
				continue;
			}

			for (int j = 0; j < L; j++) {
				if (devices[deviceIndex][j] != outlets[i][j]) {
					foundOutlet = false;
					break;
				}
			}
			
			if (foundOutlet) {
				usedOutlets[i] = true;
				return true;
			}
		}

		return foundOutlet;
	}
}
