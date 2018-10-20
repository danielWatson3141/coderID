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
		final Scanner scanner = new Scanner(new File("src/y2014/round1a/a/A-large.in"));
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
		final String[] outs = new String[numPlugs];
		final int[] outsAtPos = new int[lengthPlug];
		for (int i = 0;i < numPlugs; i++){
			final String binary = scanner.next();
			outs[i] = binary;
			for (int j = 0; j < lengthPlug; j++) {
				if (binary.charAt(j) == '1') {
					outsAtPos[j]++;
				}
			}
		}
		final String[] ins = new String[numPlugs];
		final int[] insAtPos = new int[lengthPlug];
		for (int i = 0;i < numPlugs; i++){
			final String binary = scanner.next();
			ins[i] = binary;
			for (int j = 0; j < lengthPlug; j++) {
				if (binary.charAt(j) == '1') {
					insAtPos[j]++;
				}
			}
		}

		final int[] switchPositions = new int[lengthPlug];
		final int switchesThrown = best(ins, outs, switchPositions, insAtPos, outsAtPos, 0, numPlugs, lengthPlug);
		if (switchesThrown == 999) {
			return "NOT POSSIBLE";
		}
		return "" + switchesThrown;
	}

	static int best(final String[] ins, final String[] outs, final int[] switchPositions, final int[] insAtPos, final int[] outsAtPos, final int i, final int numPlugs,  final int lengthPlug) {
		if (i >= lengthPlug) {
			if (!checkValidity(ins, outs, switchPositions, i)) {
				//System.out.println("Too bad.");
				return 999;
			}
			int count = 0;
			for (final int switchPosition : switchPositions) {
				if (switchPosition == 1) {
					count++;
				}
			}
			return count;
		}
		if (insAtPos[i] + insAtPos[i] == numPlugs) {
			switchPositions[i] = 0;
			int attempt1 = 999;
			if (checkValidity(ins, outs, switchPositions, i+1)) {
				attempt1 = best(ins, outs, switchPositions, insAtPos, outsAtPos, i+1, numPlugs, lengthPlug);
			}
			switchPositions[i] = 1;
			int attempt2 = 999;
			if (checkValidity(ins, outs, switchPositions, i+1)) {
				attempt2 = best(ins, outs, switchPositions, insAtPos, outsAtPos, i+1, numPlugs, lengthPlug);
			}
			return Math.min(attempt1, attempt2);
		}
		if (insAtPos[i] == outsAtPos[i]) {
			switchPositions[i] = 0;
			return best(ins, outs, switchPositions, insAtPos, outsAtPos, i+1, numPlugs, lengthPlug);
		} else if (insAtPos[i] == numPlugs - outsAtPos[i]) {
			switchPositions[i] = 1;
			return best(ins, outs, switchPositions, insAtPos, outsAtPos, i+1, numPlugs, lengthPlug);
		} else {
			return 999;
		}
	}

	private static boolean checkValidity(final String[] ins, final String[] outs, final int[] switchPositions, final int i) {
		final List<String> myIns = new ArrayList<String>();
		final List<String> myOuts = new ArrayList<String>();
		for (final String in : ins) {
			myIns.add(in.substring(0, i));
		}
		for (final String out : outs) {
			myOuts.add(switched(switchPositions, out, i));
		}
		Collections.sort(myIns);
		Collections.sort(myOuts);
		for (int j = 0; j < myIns.size(); j++) {
			if (!myIns.get(j).equals(myOuts.get(j))) {
				return false;
			}
		}
		return true;

	}

	private static String switched(final int[] switchPositions, final String out, final int i) {
		String result = "";
		for (int j = 0; j < i; j++) {
			if (switchPositions[j] == 0) {
				result += out.charAt(j);
			} else {
				result += out.charAt(j) == '1' ? '0' : '1';
			}
		}
		return result;
	}

	private static void write(final FileWriter writer, final String lineToWrite) throws IOException {
		writer.append(lineToWrite + "\n");
		System.out.println(lineToWrite);
	}
}
