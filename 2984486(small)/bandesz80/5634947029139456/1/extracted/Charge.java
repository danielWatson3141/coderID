package com.google.codejam.ka;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Charge {

	public static void main(String args[]) throws FileNotFoundException {
		parseInput(args[0]);
	}

	private static void parseInput(String arg) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(arg));
		int testCases = scanner.nextInt();
		for (int i = 0; i < testCases; i++) {
			int n = scanner.nextInt();
			int l = scanner.nextInt();
			int chargers[][] = new int[n][l];
			int phones[][] = new int[n][l];
			for (int j = 0; j < n; j++) {
				String pattern = scanner.next();
				for (int k = 0; k < l; k++) {
					chargers[j][k] = Integer.parseInt("" + pattern.charAt(k));
				}
			}
			for (int j = 0; j < n; j++) {
				String pattern = scanner.next();
				for (int k = 0; k < l; k++) {
					phones[j][k] = Integer.parseInt("" + pattern.charAt(k));
				}
			}

			int solve = solve(chargers, phones);
			String res = "NOT POSSIBLE";
			if (solve != Integer.MAX_VALUE) {
				res = Integer.toString(solve);
			}
			printOutput(i + 1, res);
		}
	}

	private static int solve(int[][] chargers, int[][] phones) {
		if (valid(chargers, phones, new Integer[]{})) {
			return 0;
		}
		Queue<int[]> q = new LinkedList<int[]>();
		for (int i = 0; i < chargers[0].length; i++) {
			q.add(new int[]{i});
		}
		int min = Integer.MAX_VALUE;
		for (int[] charger : chargers) {
			for (int[] phone : phones) {
				Integer[] flips = getFlips(charger, phone);
				if (valid(chargers, phones, flips)) {
					if (min > flips.length) {
						min = flips.length;
					}
				}
			}
		}
		return min;
	}

	private static Integer[] getFlips(int[] charger, int[] phone) {
		LinkedList<Integer> flips = new LinkedList<Integer>();
		for (int i = 0; i < charger.length; i++) {
			if (charger[i] != phone[i]) {
				flips.add(i);
			}
		}
		return flips.toArray(new Integer[flips.size()]);
	}

	private static boolean valid(int[][] chargers, int[][] phones, Integer[] flips) {
		for (int[] charger : chargers) {
			boolean found = false;
			for (int[] phone : phones) {
				if (isEqualChargerWithPhone(flips, charger, phone)) {
					found = true;
					break;
				}
			}
			if (!found) {
				return false;
			}
		}
		return true;
	}

	private static boolean isEqualChargerWithPhone(Integer[] flips, int[] charger, int[] phone) {
		boolean equals = false;
		for (int i = 0; i < charger.length; i++) {
			boolean flipped = isFlipped(flips, i);
			if (flipped) {
				equals = charger[i] != phone[i];
			} else {
				equals = charger[i] == phone[i];
			}
			if (!equals) {
				return false;
			}
		}
		return true;
	}

	private static boolean isFlipped(Integer[] next, int i) {
		boolean flipped = false;
		for (Integer aNext : next) {
			if (i == aNext) {
				flipped = true;
				break;
			}
		}
		return flipped;
	}

//	private static boolean valid(int[][] chargers, int[][] phones) {
//		for (int[] charger : chargers) {
//			boolean found = false;
//			for (int[] phone : phones) {
//				if (Arrays.equals(charger, phone)) {
//					found = true;
//					break;
//				}
//			}
//			if (!found) {
//				return false;
//			}
//		}
//		return true;
//	}

	private static void printOutput(int i, String s) {
		System.out.println(String.format("Case #%d: %s", i, s));
	}
}
