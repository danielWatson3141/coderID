package round2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemA {

	Scanner scanner;
	
	int n;
	int l;
	
	ArrayList <String> outlets;
	ArrayList <String> devices;
	
	static String output = "";
	
	public static void main(String[] args) {
		ProblemA p = new ProblemA ();
		p.performTask();
		System.out.println (output);
	}
	
	public void performTask () {
		scanner = new Scanner (System.in);
		int testcases = scanner.nextInt();
		for (int a=0; a<testcases; a++) {
			n = scanner.nextInt();
			l = scanner.nextInt();
			outlets = new ArrayList <String> (n);
			devices = new ArrayList <String> (n);
			
			for (int i=0; i<n; i++) {
				String outlet = scanner.next();
				outlets.add(outlet);
			}
			
			for (int i=0; i<n; i++) {
				String device = scanner.next();
				devices.add(device);
			}
			
			// reading done
			
			int switchCount = trySwitches ();
			output+="Case #"+(a+1)+": ";
			if (switchCount==-1) {
				output+="NOT POSSIBLE\n";
			} else {
				output+=""+switchCount+"\n";
			}
		}
		
		
	}
	
	public int trySwitches () {
		if (isEquals(outlets, devices)) return 0;
		
		boolean [] switchingTable = new boolean [l];
		for (int i=0; i<l; i++) switchingTable[i] = false;
		
		while (!isEnd (switchingTable)){
			switchingTable = getNext (switchingTable);
			ArrayList <String> newOutlets = switchCompletely (outlets, switchingTable);
			
			//System.out.println (Arrays.toString(switchingTable)+", "+newOutlets);
			
			if (isEquals (devices, newOutlets)) {
				return getSwitchCount (switchingTable);
			}
		}
		return -1;
	}
	
	public boolean [] getNext (boolean [] array) {
		int current = array.length-1;
		while (true) {
			if (array[current]) {
				array [current] = false;
				current --;
			} else {
				array [current] = true;
				break;
			}
		}
		
		return array;
	}
	
	public int getSwitchCount (boolean [] array) {
		int count = 0;
		for (int i=0; i<array.length; i++) {
			if (array [i]) count++;
		}
		return count;
	}
	
	public boolean isEnd (boolean [] array) {
		for (int i=0; i<array.length; i++) {
			if (!array [i]) return false;
		}
		return true;
	}
	
	public boolean isEquals (ArrayList <String> first, ArrayList <String> second) {
		for (String s : first) {
			if (!second.contains(s)) return false;
		}
		return true;
	}
	
	public ArrayList <String> switchCompletely (ArrayList <String> outletsH, boolean [] switchingTable) {
		ArrayList <String> outlets = new ArrayList <String> (outletsH);
		for (int i=0; i<switchingTable.length; i++) {
			if (switchingTable [i]) {
				outlets = switchF(outlets, i);
			}
		}
		return outlets;
	}
	
	public ArrayList <String>  switchF (ArrayList <String> outlets, int index) {
		ArrayList <String> newOutlets = new ArrayList <String> (outlets.size());
		for (String outlet : outlets) {
			if (outlet.charAt(index)=='0') {
				outlet = outlet.substring(0, index)+"1"+outlet.substring(index+1,outlet.length());
			} else {
				outlet = outlet.substring(0, index)+"0"+outlet.substring(index+1,outlet.length());
			}
			newOutlets.add(outlet);
		}
		return newOutlets;
	}
}