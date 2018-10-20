package codejam.year2014.round1A;

import java.util.*;
import java.io.*;
import java.math.*;

public class A {

	private static Scanner sc;

	private static int N, L, caseNumber;
	
	private static String[] outlets;
	private static String[] flows;
	
	public static void main(final String[] args) {
//		setStreams("C:\\Users\\Yariv\\Desktop\\testA");
		 setStreams("C:\\Users\\Yariv\\Desktop\\A-small-attempt0");
		// setStreams("C:\\Users\\Yariv\\Desktop\\A-large");
		sc = new Scanner(System.in);
		final int numCases = sc.nextInt();
		handleCases(numCases);
	}

	private static void setStreams(final String baseFileName) {
		try {
			System.setIn(new FileInputStream(baseFileName + ".in"));
			 System.setOut(new PrintStream(baseFileName + ".out"));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void handleCases(final long numCases) {
		for (int i = 1; i <= numCases; i++) {
			caseNumber = i;
			handleCase();
		}
	}

	private static void handleCase() {
		N = sc.nextInt();
		L = sc.nextInt();
		
		outlets = new String[N];
		flows = new String[N];
		for(int i = 0 ; i < N ; i++) {
			outlets[i] = sc.next();
//			log("outlet "+ i + " " + outlets[i]);
		}
		
		for(int i = 0 ; i < N ; i++) {
			flows[i] = sc.next();
		}
		Set<Integer>[] possibles = new Set[N];
		for(int i = 0 ; i < N; i++) {
			Set<Integer> nums = new HashSet<>();
			for(int j = 0 ; j < N ; j++) {
				nums.add(j);
			}
			possibles[i] = nums;
		}
		
		int switches = run(0, 0, possibles);
		if(switches < Integer.MAX_VALUE) {
			System.out.println("Case #" + caseNumber + ": " + switches);
		}
		else {
			System.out.println("Case #" + caseNumber + ": " + "NOT POSSIBLE");
		}
	}
	
	private static int run(int step, int switches, Set<Integer>[] possibles) {
		for(int i = 0 ; i < N; i++) {
			log("Step " + step + " possbile for " + i + " " + possibles[i]);
		}
		if(step == L) {
			log("swtiches " + switches);
			return switches;
		}
		int sumOutlet = 0;
		int sumFlows = 0;
		for(int i = 0 ; i < N ; i++) {
			if(outlets[i].charAt(step) == '1') {
				sumOutlet++;
			}
			if(flows[i].charAt(step) == '1') {
				sumFlows++;
			}
		}

		if(sumOutlet != sumFlows && (sumOutlet != (N - sumFlows))) {
			log("failed");
			return Integer.MAX_VALUE;
		}
		
		int res1 = Integer.MAX_VALUE;
		int res2 = Integer.MAX_VALUE;
		
		Set<Integer>[] savePos = new Set[N];
		for(int i = 0 ; i < N ; i++) {
			savePos[i] = possibles[i];
		}
		boolean fail1 = false;
		boolean fail2 = false;
		if(sumOutlet == sumFlows) {
			for(int i = 0 ; i < N ; i++) {
				Set<Integer> oldSet = possibles[i];
				Set<Integer> newSet = new HashSet<>();
				for(Integer place : oldSet) {
					if(outlets[place].charAt(step) == flows[i].charAt(step)) {
						newSet.add(place);
					}
				}
				if(newSet.isEmpty()) {
					res1= Integer.MAX_VALUE;
					fail1 = true;
					break;
				}
				else {
					possibles[i] = newSet;
				}
			}
			if(!fail1) {
				res1 = run(step + 1, switches, possibles);
			}
		}
		
		
		if(sumOutlet == N - sumFlows) {
			for(int i = 0 ; i < N ; i++) {
				Set<Integer> oldSet = savePos[i];
				Set<Integer> newSet = new HashSet<>();
				for(Integer place : oldSet) {
					if(outlets[place].charAt(step) != flows[i].charAt(step)) {
						newSet.add(place);
					}
				}
				if(newSet.isEmpty()) {
					fail2 = true;
					res2= Integer.MAX_VALUE;
					break;
				}
				else {
					savePos[i] = newSet;
				}
			}
			if(!fail2) {
				res2 = run(step + 1, switches + 1, savePos);
			}
		}
		
		log("res1: " + res1 + " res2: " + res2);
		return Math.min(res1, res2);
	}
	private static void log(final String message) {
//		System.out.println(message);
	}
}
