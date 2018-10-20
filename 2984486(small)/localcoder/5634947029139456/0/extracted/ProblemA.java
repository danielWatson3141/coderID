package y2014.round1a.a;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class ProblemA {

	public static void main(final String[] args) throws IOException {
		final Scanner scanner = new Scanner(new File("src/y2014/round1a/a/A-small-attempt1.in"));
		final FileWriter writer = new FileWriter("src/y2014/round1a/a/out.txt");
		final int numTestCases = scanner.nextInt();
		for (int i = 0; i < numTestCases; i++) {
			final String result = solveCase(scanner);
			final String lineToWrite = "Case #" + (i + 1) + ": " + result;
			write(writer, lineToWrite);
		}
		writer.close();
	}

	private static String solveCase(final Scanner scanner) {
		final int numPlugs = scanner.nextInt();
		final int lengthPlug = scanner.nextInt();
		final int[] outs = new int[numPlugs];
		for (int i = 0;i < numPlugs; i++){
			final String binary = scanner.next();
			outs[i] = Integer.parseInt(binary, 2);
		}
		final int[] ins = new int[numPlugs];
		for (int i = 0;i < numPlugs; i++){
			final String binary = scanner.next();
			ins[i] = Integer.parseInt(binary, 2);
		}
		//brute force - check every possibility

		int bestSoFar = 999;
		for(int i = 0; i < Math.pow(2, lengthPlug); i++) {
			final int[] outs2 = new int[numPlugs];
			for (int j = 0; j < numPlugs; j++) {
				outs2[j] = outs[j] ^ i;
			}
			final int switches = switchesFlipped(i);
			if (isValid(ins, outs2)) {
				if (switches < bestSoFar) {
					bestSoFar = switches;
				}
			}
		}
		if (bestSoFar == 999) {
			return "NOT POSSIBLE";
		}
		return "" + bestSoFar;
	}

	private static int switchesFlipped(final int i) {
		final String binary = Integer.toBinaryString(i);
		return  binary.length() - binary.replace("1", "").length();
	}

	private static boolean isValid(final int[] ins, final int[] outs) {
		final List<Integer> myIns = new ArrayList<Integer>();
		final List<Integer> myOuts = new ArrayList<Integer>();
		for(final int intValue : ins) {
			myIns.add(intValue);
		}
		for(final int intValue : outs) {
			myOuts.add(intValue);
		}
		Collections.sort(myIns);
		Collections.sort(myOuts);
		for (int i = 0; i < myIns.size(); i++) {
			if (!myIns.get(i).equals(myOuts.get(i))) {
				return false;
			}
		}
		return true;
	}

	private static void write(final FileWriter writer, final String lineToWrite) throws IOException {
		writer.append(lineToWrite + "\n");
		System.out.println(lineToWrite);
	}
}
