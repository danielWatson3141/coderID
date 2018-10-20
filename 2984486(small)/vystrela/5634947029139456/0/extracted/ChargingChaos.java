package com.google.code.ChargingChaos;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;

public class ChargingChaos {

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new FileReader(args[0]));

		int numCases = Integer.parseInt(br.readLine());

		for (int i = 0; i < numCases; i++) {
			solve(br, i+1);
		}

	}

	private static void solve(BufferedReader br, int i) throws NumberFormatException, IOException {

		System.out.print("Case #" + i + ": ");

		Scanner dimensions = new Scanner(br.readLine());

		int numDevices = dimensions.nextInt();
		int stringLength = dimensions.nextInt();

		ArrayList<String> outlets = new ArrayList<String>();

		ArrayList<String> chargers = new ArrayList<String>();

		Scanner lineReader = new Scanner(br.readLine());

		for (int count = 0; count < numDevices; count++) {
			outlets.add(lineReader.next());
		}
		lineReader.close();
		lineReader = new Scanner(br.readLine());

		for (int count = 0; count < numDevices; count++) {
			chargers.add(lineReader.next());
		}
		lineReader.close();

		int numSwitches = optimise(outlets, chargers, 0, stringLength);
		
		System.out.println(numSwitches == -1 ? "NOT POSSIBLE" : numSwitches);

	}
	
	private static int optimise(ArrayList<String> outlets, ArrayList<String> chargers, int i, int stringLength) {
		
		int bestFlips = stringLength + 1;
		
		ArrayList<String> sortedChargers = sort(chargers);
		
		for (int flipSignature = 0; flipSignature < Math.pow(2, stringLength); flipSignature++) {
			char[] flips = fromBinary(flipSignature).toCharArray();
			
			ArrayList<String> newOutlets = new ArrayList<String>();
			
			for (int j = 0; j < outlets.size(); j++) {
				newOutlets.add(outlets.get(j));
			}

			int numberOfFlips = 0;
			
			for (int j = 0; j < flips.length; j++) {
				if (flips[j] == '1') {
					newOutlets = flip(newOutlets, j);
					numberOfFlips++;
				}
			}
			
			if (numberOfFlips < bestFlips && isEqual(sort(newOutlets), sortedChargers)) {
				bestFlips = numberOfFlips;
			}
			
		}
		
		return bestFlips == stringLength + 1 ? -1 : bestFlips;
	}
	
	private static int toBinary(String input) {
		char[] digits = input.toCharArray();
		
		int value = 0;
		
		for (int i = 0 ; i < input.length(); i++ ) {
			value += (digits[i] - '0') * (int) Math.pow(2, input.length() - i - 1);
		}
		return value;
	}
	
	private static int countFlips(String input) {
		int retval = 0;
		for (int i = 0; i < input.length(); i++) {
			if (input.charAt(i) == 1) retval++;
		}
		return retval;
	}
	
	private static String fromBinary(int input) {
		
		int temp = input;
		StringBuffer sb = new StringBuffer();
		
		while (temp > 0) {
			sb.append(temp % 2);
			temp /= 2;
		}
		if (sb.length() == 0) return "0";
		
		return sb.toString();
	}

	private static ArrayList<String> flip(ArrayList<String> input, int switchNumber) {
		ArrayList<String> retVal = new ArrayList<String>();
		for (int i = 0; i < input.size(); i++) {
			char[] stream = input.get(i).toCharArray();
			stream[switchNumber] = stream[switchNumber] == '0' ? '1' : '0';
			retVal.add(new String(stream));
		}
		
		return retVal;
	}
	
	private static boolean isEqual(ArrayList<String> input1, ArrayList<String> input2) {
		for (int i = 0; i < input1.size(); i++) {
			if (!input1.get(i).equals(input2.get(i))) return false;
		}
		return true;
	}

	private static ArrayList<String> sort(ArrayList<String> input) {
		ArrayList<String> retVal = new ArrayList<String>();
		for (int i = 0; i < input.size(); i++) {
			retVal.add(input.get(i));
		}
		for (int i = 0; i < input.size() - 1; i++) {
			for (int j = 0; j < input.size() - 1; j++) {
				String first = retVal.get(j);
				String second = retVal.get(j+1);
				if (first.compareTo(second) < 0 ) {
					retVal.remove(j);
					retVal.remove(j);
					retVal.add(j, first);
					retVal.add(j, second);
				}
			}
		}
		return retVal;
	}

	private static String intersect(String[] firstCards, String[] secondCards, int k) {
		ArrayList<String> answers = new ArrayList<String>();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (firstCards[i].equals(secondCards[j])) answers.add(firstCards[i]);
			}
		}

		switch (answers.size()) {
		case 0:
			return "Case #" + k + ": Volunteer cheated!";
		case 1:
			return "Case #" + k + ": " + answers.get(0);
		default:
			return "Case #" + k + ": Bad magician!";
		}
	}

}
