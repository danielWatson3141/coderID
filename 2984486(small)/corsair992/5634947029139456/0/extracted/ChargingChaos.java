package com.example.codejam.chargingchaos;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Locale;

public class ChargingChaos {
	private static final int MIN_TEST_CASE_NUMBER = 1, MAX_TEST_CASE_NUMBER = 100;

	private static final String ANSWER_HEADER_FORMAT = "Case #%d: %s";
	private static final String RESULT_NOT_POSSIBLE = "NOT POSSIBLE";

	@SuppressWarnings("resource")
	public static void main(String[] args) throws IOException {
		if (args.length == 0)
			throw new IllegalArgumentException("No arguments passed");

		Reader reader = new FileReader(args[0]);
		String[] answers;
		try {
			BufferedReader buffer = new BufferedReader(reader);
			reader = buffer;

			int testCaseNumber = Integer.parseInt(buffer.readLine());
			if (testCaseNumber < MIN_TEST_CASE_NUMBER)
				throw new IllegalArgumentException(
						"Number is less than a minimum of " + MIN_TEST_CASE_NUMBER);
			if (testCaseNumber > MAX_TEST_CASE_NUMBER)
				throw new IllegalArgumentException(
						"Number is greated than a maximum " + MAX_TEST_CASE_NUMBER);
			answers = new String[testCaseNumber];

			for (int i = 0; i < testCaseNumber; i++) {
				answers[i] = solve(buffer, i + 1);
			}
		} finally {
			reader.close();
		}

		Writer writer = args.length > 1 ? new FileWriter(args[1]) :
			new OutputStreamWriter(System.out);
		try {
			BufferedWriter buffer = new BufferedWriter(writer);
			writer = buffer;
			for (int i = 0; i < answers.length; i++) {
				buffer.write(String.format(Locale.US,
						ANSWER_HEADER_FORMAT, i + 1, answers[i]));
				buffer.newLine();
			}
		} finally {
			writer.close();
		}
	}

	private static String solve(BufferedReader buffer, int number) throws IOException {
		String[] input = buffer.readLine().split(" ");
		if (input.length != 2)
			throw new IllegalArgumentException("The first input line in test case " +
					number + " does not consist of 3 space-separated values");

		int devicesNum = Integer.parseInt(input[0]);
		int flowLength = Integer.parseInt(input[1]);

		long[] currentConfigs = new long[devicesNum];
		long[] requiredConfigs = new long[devicesNum];
		{
			String[] currentConfigStrings = buffer.readLine().split(" ");
			if (currentConfigStrings.length != devicesNum)
				throw new IllegalArgumentException("The second input line in test case " +
						number + " does not hold the same number of strings as specified in N");
			for (int i = 0; i < devicesNum; i++) {
				String currentConfigString = currentConfigStrings[i];
				if (currentConfigString.length() != flowLength)
					throw new IllegalArgumentException("Element #" + i +
							" from the current configuration list in test case " +
							number + " does not hold the same number of strings as specified in L");
				currentConfigs[i] = Long.parseLong(currentConfigString, 2);
			}

			String[] requiredConfigStrings = buffer.readLine().split(" ");
			if (requiredConfigStrings.length != devicesNum)
				throw new IllegalArgumentException("The second input line in test case " +
						number + " does not hold the same number of strings as specified in N");
			for (int i = 0; i < devicesNum; i++) {
				String requiredConfigString = requiredConfigStrings[i];
				if (requiredConfigString.length() != flowLength)
					throw new IllegalArgumentException("Element #" + i +
							" from the current configuration list in test case " +
							number + " does not hold the same number of strings as specified in L");
				requiredConfigs[i] = Long.parseLong(requiredConfigString, 2);
			}
		}

		boolean[] switches = new boolean[flowLength];
		for (int i = 0; i <= flowLength; i++) {
			if (isPossible(currentConfigs, requiredConfigs, switches, i)) {
				return Integer.toString(i);
			}
		}
		return RESULT_NOT_POSSIBLE;
	}

	private static boolean isPossible(long[] currentConfigs, long[] requiredConfigs,
			boolean[] switches, int switchesNum) {
		if (currentConfigs.length != requiredConfigs.length)
			throw new IllegalArgumentException();

		int currentSwitchesNum = 0;
		for (boolean mySwitch : switches) {
			if (mySwitch) {
				currentSwitchesNum++;
			}
		}

		if (currentSwitchesNum > switchesNum ||
				(currentSwitchesNum == switchesNum && switchesNum != 0))
			throw new IllegalArgumentException();

		boolean recursionRequired = switchesNum - currentSwitchesNum > 1;
		for (int i = 0; i < switches.length; i++) {
			if (switches[i]) continue;
			switches[i] = true;
			if (recursionRequired) {
				if (isPossible(currentConfigs, requiredConfigs,
						switches, switchesNum)) {
					return true;
				}
			} else {
				long mySwitch = 0;
				if (switchesNum > 0) {
					for (int j = 0; j < switches.length; j++) {
						if (switches[j]) {
							mySwitch |= 1 << (switches.length - 1 - j);
						}
					}
				}

				List<Long> testConfigList = new ArrayList<Long>();
				for (long currentConfig : currentConfigs) {
					testConfigList.add(currentConfig ^= mySwitch);
				}

				List<Long> requiredConfigList = new ArrayList<Long>();
				for (long requiredConfig : requiredConfigs) {
					requiredConfigList.add(requiredConfig);
				}

				for (Iterator<Long> testConfigIterator = testConfigList.iterator();
						testConfigIterator.hasNext();) {
					Long testConfig = testConfigIterator.next();
					if (!requiredConfigList.remove(testConfig))
						break;
					testConfigIterator.remove();
				}
				if (testConfigList.isEmpty() && requiredConfigList.isEmpty())
					return true;
			}
			switches[i] = false;
		}
		return false;
	}
}