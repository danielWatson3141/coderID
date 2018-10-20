import java.util.*;
import java.io.*;

public class A {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		for (int testCase = 1; testCase <= t; testCase++) {
			int n = s.nextInt();
			int l = s.nextInt();
			ArrayList<String> outlets = new ArrayList<String>();
			ArrayList<String> devices = new ArrayList<String>();
			for (int i = 0; i < n; i++) {
				outlets.add(s.next());
			}
			for (int i = 0; i < n; i++) {
				devices.add(s.next());
			}
			ToMatch tm = new ToMatch();
			tm.devices = devices;
			tm.outlets = outlets;
			ArrayList<ToMatch> zz = new ArrayList<ToMatch>();
			zz.add(tm);
			int answer = doIt(zz);
			String result = "" + answer;
			if (answer == -1) {
				result = "NOT POSSIBLE";
			}
			System.out.println("Case #" + testCase + ": " + result);
		}
	}

	private static int doIt(ArrayList<ToMatch> matches) {
		int flip = 0;
		for (ToMatch m : matches) {
			ArrayList<String> devices = m.devices;
			ArrayList<String> outlets = m.outlets;
			int zeroDevices = 0;
			int zeroOutlets = 0;
			for (String s : devices) {
				if (s.length() == 0) {
					return 0;
				}
				if (s.charAt(0) == '0') {
					zeroDevices++;
				}
			}
			for (String s : outlets) {
				if (s.charAt(0) == '0') {
					zeroOutlets++;
				}
			}
			if (flip == -1) {
				if (zeroDevices == zeroOutlets) {
					continue;
				} else {
					return -1;
				}
			}
			if (flip == 1) {
				if (zeroDevices == outlets.size() - zeroOutlets) {
					continue;
				} else {
					return -1;
				}
			}
			if (zeroDevices == zeroOutlets
					&& zeroDevices + zeroOutlets == outlets.size()) {
				continue;
			}
			if (zeroDevices == zeroOutlets) {
				flip = -1;
				continue;
			}
			if (zeroDevices + zeroOutlets == outlets.size()) {
				flip = 1;
				continue;
			}
			return -1;
		}
		ArrayList<ToMatch> nextMatches = new ArrayList<ToMatch>();
		int result = -1;
		if (flip == -1 || flip == 0) {
			for (ToMatch tm : matches) {
				ArrayList<String> zeroDevices = new ArrayList<String>();
				ArrayList<String> zeroOutlets = new ArrayList<String>();
				ArrayList<String> oneDevices = new ArrayList<String>();
				ArrayList<String> oneOutlets = new ArrayList<String>();
				for (String s : tm.devices) {
					if (s.charAt(0) == '0') {
						zeroDevices.add(s.substring(1));
					} else {
						oneDevices.add(s.substring(1));
					}
				}
				for (String s : tm.outlets) {
					if (s.charAt(0) == '0') {
						zeroOutlets.add(s.substring(1));
					} else {
						oneOutlets.add(s.substring(1));
					}
				}
				ToMatch zeroes = new ToMatch();
				ToMatch ones = new ToMatch();
				zeroes.devices = zeroDevices;
				zeroes.outlets = zeroOutlets;
				ones.devices = oneDevices;
				ones.outlets = oneOutlets;
				nextMatches.add(zeroes);
				nextMatches.add(ones);
			}
			int tempResult = doIt(nextMatches);
			if ((tempResult >= 0 && tempResult < result) || result == -1) {
				result = tempResult;
			}
		}
		nextMatches = new ArrayList<ToMatch>();
		if (flip == 1 || flip == 0) {
			for (ToMatch tm : matches) {
				ArrayList<String> zeroDevices = new ArrayList<String>();
				ArrayList<String> zeroOutlets = new ArrayList<String>();
				ArrayList<String> oneDevices = new ArrayList<String>();
				ArrayList<String> oneOutlets = new ArrayList<String>();
				for (String s : tm.devices) {
					if (s.charAt(0) == '0') {
						zeroDevices.add(s.substring(1));
					} else {
						oneDevices.add(s.substring(1));
					}
				}
				for (String s : tm.outlets) {
					if (s.charAt(0) == '0') {
						zeroOutlets.add(s.substring(1));
					} else {
						oneOutlets.add(s.substring(1));
					}
				}
				ToMatch zeroes = new ToMatch();
				ToMatch ones = new ToMatch();
				zeroes.devices = zeroDevices;
				zeroes.outlets = oneOutlets;
				ones.devices = oneDevices;
				ones.outlets = zeroOutlets;
				if (zeroes.devices.size() > 0)
					nextMatches.add(zeroes);
				if (ones.devices.size() > 0)
					nextMatches.add(ones);
			}
			int tempResult = doIt(nextMatches);
			if(tempResult > -1){
				tempResult++;
			}
			if ((tempResult >= 0 && tempResult < result) || result == -1) {
				result = tempResult;
			}
		}
		return result;
	}

	static class ToMatch {
		ArrayList<String> devices;
		ArrayList<String> outlets;
	}
}
