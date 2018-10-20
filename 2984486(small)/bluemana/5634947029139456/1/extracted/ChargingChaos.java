package gcj.y2014.round1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ChargingChaos {

	public static void main(String[] args) throws Exception {
		BufferedReader reader = null;
		Writer writer = null;
		try {
			reader = new BufferedReader(new FileReader("A-large.in"));
			writer = new BufferedWriter(new FileWriter("A-large.out"));
			main(reader, writer);
		} finally {
			if (reader != null) {
				reader.close();
			}
			if (writer != null) {
				writer.close();
			}
		}
	}

	private static void main(BufferedReader reader, Writer writer) throws Exception {
		int testCount = Integer.parseInt(reader.readLine());
		for (int t = 0; t < testCount; t++) {
			reader.readLine();
			String[] outlets = reader.readLine().split(" ");
			String[] devices = reader.readLine().split(" ");
			System.out.println(String.format("%s\n%s", Arrays.toString(outlets), Arrays.toString(devices)));
			int flips = findMinimumFlips(outlets, devices);
			String result = formatResult(t, flips);
			System.out.println(result);
			writer.write(result + "\n");
		}
		writer.flush();
	}
	
	private static int findMinimumFlips(String[] outlets, String[] devices) {
		return findMinimumFlips(outlets, devices, 0);
	}
	
	private static int findMinimumFlips(String[] outlets, String[] devices, int i) {
		int result = 0;
		int n = outlets.length;
		int length = outlets[0].length();
		if (i < length) {
			int[] oneCount = countOnes(outlets, devices, i);
			int outletsOneCount = oneCount[0];
			int devicesOneCount = oneCount[1];
			if (outletsOneCount == devicesOneCount) {
				int temp = -1;
				if (canPlug(outlets, devices, i + 1)) {
					if (i < length - 1) {
						temp = findMinimumFlips(outlets, devices, i + 1);
					} else {
						temp = 0;
					}
				}
				if (temp != -1) {
					result += temp;
				} else {
					if (outletsOneCount == n - devicesOneCount) {
						outlets = flip(outlets, i);
						if (canPlug(outlets, devices, i + 1)) {
							if (i < length - 1) {
								temp = findMinimumFlips(outlets, devices, i + 1);
							} else {
								temp = 0;
							}
						}
					}
					if (temp != -1) {
						result += temp + 1;
					} else {
						result = -1;
					}
				}
			} else if (outletsOneCount == n - devicesOneCount) {
				int temp = -1;
				outlets = flip(outlets, i);
				if (canPlug(outlets, devices, i + 1)) {
					if (i < length - 1) {
						temp = findMinimumFlips(outlets, devices, i + 1);
					} else {
						temp = 0;
					}
				}
				if (temp != -1) {
					result += temp + 1;
				} else {
					result = -1;
				}
			} else {
				result = -1;
			}
		}
		return result;
	}
	
	private static int[] countOnes(String[] outlets, String[] devices, int i) {
		int n = outlets.length;
		int outletsOneCount = 0;
		int devicesOneCount = 0;
		for (int j = 0; j < n; j++) {
			if (outlets[j].charAt(i) == '1') {
				outletsOneCount++;
			}
			if (devices[j].charAt(i) == '1') {
				devicesOneCount++;
			}
		}
		return new int[] {outletsOneCount, devicesOneCount};
	}
	
	private static boolean canPlug(String[] outlets, String[] devices, int length) {
		boolean result = true;
		List<Integer> assignment = new ArrayList<Integer>();
		for (int i = 0; i < outlets.length; i++) {
			String outlet = outlets[i];
			for (int j = 0; j < devices.length; j++) {
				String device = devices[j];
				if (!assignment.contains(j) && device.startsWith(outlet.substring(0, length))) {
					assignment.add(j);
					break;
				}
			}
			if (assignment.size() < i + 1) {
				result = false;
				break;
			}
		}
		return result;
	}
	
	private static String[] flip(String[] outlets, int i) {
		int n = outlets.length;
		String[] result = new String[n];
		for (int j = 0; j < n; j++) {
			StringBuffer buffer = new StringBuffer(outlets[j]);
			buffer.replace(i, i + 1, "" + (outlets[j].charAt(i) == '0' ? '1' : '0'));
			result[j] = buffer.toString();
		}
		return result;
	}
	
	private static String formatResult(int t, int flips) {
		return String.format("Case #%d: %s", t + 1, flips == -1 ? "NOT POSSIBLE" : "" + flips);
	}
}
