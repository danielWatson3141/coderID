package com.skidson.codejam.problems;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import com.skidson.codejam.Test;

public class ChargingChaos extends Test {
	
	// map of string lengths to substring lengths to all possible subsets
	private static Map<Integer, Map<Integer, List<List<Integer>>>> INDEX_SUBSETS = 
			new HashMap<Integer, Map<Integer, List<List<Integer>>>>();

	public ChargingChaos(BufferedReader in) {
		super(in);
	}

	@Override
	public String run() throws IOException {
		String[] args = in.readLine().split(" ");
		int numSwitches = Integer.parseInt(args[1]);
		
		Set<String> outlets = new HashSet<String>();
		Set<String> devices = new HashSet<String>();
		
		args = in.readLine().split(" ");
		for (String outlet : args) {
			outlets.add(outlet);
		}
		
		args = in.readLine().split(" ");
		for (String device : args) {
			devices.add(device);
		}
		
		// Iterate up from flicking no switches to flicking all of them.
		int numFlipped = 0;
		if (canDevicesCharge(devices, outlets))
			return String.valueOf(numFlipped);
		
		while (numFlipped < numSwitches) {
			numFlipped++;
				
				// get list of all array index combinations
			List<List<Integer>> indexCombos = getIndexCombinations(numSwitches, numFlipped);
			for (List<Integer> indexes : indexCombos) {
				Set<String> flipped = new HashSet<String>(outlets.size());
				for (String outlet : outlets) {
					for (int index : indexes) {
						outlet = flip(outlet, index);
					}
					flipped.add(outlet);
				}
				if (canDevicesCharge(devices, flipped))
					return String.valueOf(numFlipped);
			}
		}
		
		return "NOT POSSIBLE";
	}
	
	private static String flip(String outlet, int switchIndex) {
		String switchValue = outlet.charAt(switchIndex) == '0' ? "1" : "0";
		String flipped = outlet.substring(0, switchIndex) + switchValue;
		
		int length = outlet.length();
		if (switchIndex < length-1) {
			flipped += outlet.substring(switchIndex+1, length);
		}
		return flipped;
	}
	
	private static boolean canDevicesCharge(Set<String> devices, Set<String> outlets) {
		Set<String> workingOutlets = new HashSet<String>(outlets);
        
		for (String device : devices) {
			if (workingOutlets.contains(device)) {
				workingOutlets.remove(device);
			}
		}
		
		return workingOutlets.isEmpty();
	}
	
	private static List<List<Integer>> getIndexCombinations(int length, int k) {
		Map<Integer, List<List<Integer>>> stringLengthSubsets = INDEX_SUBSETS.get(length);
		if (stringLengthSubsets == null) {
			stringLengthSubsets = new HashMap<Integer, List<List<Integer>>>();
			INDEX_SUBSETS.put(length, stringLengthSubsets);
		}
		
		List<List<Integer>> indexSubsets = stringLengthSubsets.get(k);
		if (indexSubsets == null) {
			indexSubsets = new ArrayList<List<Integer>>();
			stringLengthSubsets.put(k, indexSubsets);
		}
		
		int[] subset = new int[k];
		if (indexSubsets.isEmpty()) {
			getIndexCombinations(length, subset, 0, 0);
//			System.out.println("----");
		}
		
	    return indexSubsets;
	}

	private static void getIndexCombinations(int length, int[] subset, int subsetSize, int nextIndex) {
	    if (subsetSize == subset.length) {
	    	Map<Integer, List<List<Integer>>> stringLengthSubsets = INDEX_SUBSETS.get(length);
	    	List<List<Integer>> indexSubsets = stringLengthSubsets.get(subset.length);
	    	List<Integer> subsetAsList = new ArrayList<Integer>();
	    	for (int i : subset) {
	    		subsetAsList.add(i);
	    	}
	    	indexSubsets.add(subsetAsList);
//	    	System.out.println(Arrays.toString(subset));
	    } else {
	        for (int j = nextIndex; j < length; j++) {
	            subset[subsetSize] = j;
	            getIndexCombinations(length, subset, subsetSize + 1, j + 1);
	        }
	    }
	}

}
