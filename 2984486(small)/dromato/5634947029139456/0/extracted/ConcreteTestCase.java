package assigment;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

import javax.sql.PooledConnection;

import codejam.war.TestCase;

public class ConcreteTestCase implements TestCase {
	private int numberOfDevices;
	private int numberOfSwitches;

	private String[] devices;
	private String[] outlets;

	public ConcreteTestCase(int numberOfDevices, int numberOfSwitches, String[] devices, String[] outlets) {
		this.numberOfDevices = numberOfDevices;
		this.numberOfSwitches = numberOfSwitches;
		this.devices = devices;
		this.outlets = outlets;
	}

	@Override
	public String solve(int testCaseNo) {
		String[][] configurations = new String[numberOfDevices][numberOfDevices];
		for (int i = 0; i < devices.length; i++) {
			for (int j = 0; j < outlets.length; j++) {
				configurations[i][j] = addConfiguration(devices[i], outlets[j]);
			}
		}
		return findSolution(configurations, testCaseNo);
	}

	private String findSolution(String[][] configurations, int testCaseNo) {
		List<String> possibleSolutions = Arrays.asList(configurations[0]);
		for (int i = 1; i < numberOfDevices; i++) {
			possibleSolutions = reevaluateSolutions(possibleSolutions, configurations[i]);
		}
		
		return getAnswer(possibleSolutions, testCaseNo);
	}

	private String getAnswer(List<String> possibleSolutions, int testCaseNo) {
		if(possibleSolutions.isEmpty()) {
			return String.format("Case #%s: NOT POSSIBLE", testCaseNo);
		}
		int solution = parse(possibleSolutions.get(0));
		int another = -1;
		for(String str : possibleSolutions) {
			another = parse(str);
			if(solution > another) {
				solution = another;
			}
		}
		return String.format("Case #%s: %s", testCaseNo, solution);
	}

	private int parse(String string) {
		int res = 0;
		for (int i = 0; i < string.length(); i++) {
			if(string.charAt(i) == '1') {
				res++;
			}
		}
		return res;
	}

	private List<String> reevaluateSolutions(List<String> possibleSolutions, String[] row) {
		List<String> rowL = Arrays.asList(row);
		List<String> newPossibleSolutions = new ArrayList<>(numberOfDevices);
		newPossibleSolutions.addAll(possibleSolutions);
		
		for (String solution : possibleSolutions) {
			if (!rowL.contains(solution)) {
				newPossibleSolutions.remove(solution);
			}
		}
		
		return newPossibleSolutions;
	}

	private String addConfiguration(String device, String outlet) {
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < device.length(); i++) {
			if (device.charAt(i) == outlet.charAt(i)) {
				result.append("0");
			} else {
				result.append("1");
			}
		}
		return result.toString();
	}

}
