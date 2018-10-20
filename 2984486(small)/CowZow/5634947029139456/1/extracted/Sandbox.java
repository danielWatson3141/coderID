package round1a;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Sandbox {
	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	    
		int testCases = Integer.parseInt(in.readLine());
		
		for (int testCaseCount = 1; testCaseCount <= testCases; testCaseCount++) {
			String input = in.readLine();
			Scanner s = new Scanner(input);
			
			int devices = s.nextInt();
			int bitLength = s.nextInt();
			
			HashSet<ArrayList<Integer>> combinations = null;
			
			String outletString = in.readLine();
			s = new Scanner(outletString);
			
			HashSet<ArrayList<Integer>> currentOutlets = new HashSet<ArrayList<Integer>>();
			HashSet<ArrayList<Integer>> desiredOutlets = new HashSet<ArrayList<Integer>>();
			
			for (int d = 0; d < devices; d++) {
				String bitString = s.next();
				ArrayList<Integer> outlet = new ArrayList<Integer>();
				for (int n = 0; n < bitLength; n++) {
					char bit = bitString.charAt(n);
					outlet.add(Character.getNumericValue(bit));
				}
				currentOutlets.add(outlet);
			}
			
			outletString = in.readLine();
			s = new Scanner(outletString);
			for (int d = 0; d < devices; d++) {
				String bitString = s.next();
				ArrayList<Integer> outlet = new ArrayList<Integer>();
				for (int n = 0; n < bitLength; n++) {
					char bit = bitString.charAt(n);
					outlet.add(Character.getNumericValue(bit));
				}
				desiredOutlets.add(outlet);
			}
			
			
			for (ArrayList<Integer> currentOutlet : currentOutlets) {
				HashSet<ArrayList<Integer>> currCombos = new HashSet<ArrayList<Integer>>();
				for (ArrayList<Integer> desiredOutlet : desiredOutlets) {
					currCombos.add(getFlips(currentOutlet, desiredOutlet));
				}
				
				if (combinations == null) {
					combinations = currCombos;
				} else {
					combinations.retainAll(currCombos);
				}
			}
			
			ArrayList<Integer> lowestCombo = null;
			for (ArrayList<Integer> combo : combinations) {
				if (lowestCombo == null) {
					lowestCombo = combo;
				} else if (combo.size() < lowestCombo.size()) {
					lowestCombo = combo;
				}
			}
			
			if (lowestCombo != null) {
				System.out.println("Case #" + testCaseCount + ": " + lowestCombo.size());
			} else {
				System.out.println("Case #" + testCaseCount + ": NOT POSSIBLE");
			}
		}
		
	}
	
	public static ArrayList<Integer> getFlips(ArrayList<Integer> curr, ArrayList<Integer> desired) {
		Iterator<Integer> currIter = curr.iterator();
		Iterator<Integer> desIter = desired.iterator();
		
		int counter = 0;
		ArrayList<Integer> list = new ArrayList<Integer>();
		while (currIter.hasNext()) {
			Integer currInt = currIter.next();
			Integer desInt = desIter.next();
			
			if (currInt != desInt) {
				list.add(counter);
			}
			counter++;
		}
		return list;
	}
}
