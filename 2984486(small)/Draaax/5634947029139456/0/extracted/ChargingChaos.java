import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class ChargingChaos {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		
		int cases = kb.nextInt();
		
		for(int c = 1; c <= cases; c++) {
			int strings = kb.nextInt();
			int length = kb.nextInt();
			
			ArrayList<char[]> devices = new ArrayList<char[]>();
			
			for(int i = 0; i < strings; i++) {
				devices.add(kb.next().toCharArray());
			}
			
			ArrayList<char[]> chargers = new ArrayList<char[]>();
			
			for(int i = 0; i < strings; i++) {
				chargers.add(kb.next().toCharArray());
			}
			
			int n = solve(devices, chargers);
			
			System.out.print("Case #" + c + ": ");
			
			if(n == Integer.MAX_VALUE) {
				System.out.println("NOT POSSIBLE");
			} else {
				System.out.println(n);
			}
		}
	}
	private static int minimum = -1;
	
	private static int solve(ArrayList<char[]> devices, ArrayList<char[]> chargers) {
		minimum = Integer.MAX_VALUE;
		
		recursiveSolve(devices,chargers, 0, 0);
		
		return minimum;
	}
	
	private static void recursiveSolve(ArrayList<char[]> devices, ArrayList<char[]> chargers, int i, int switched) {
		if(doesMatch(devices, chargers)) {
			minimum = Math.min(minimum, switched);
			return;
		}
		
		for(int s = i; s < devices.get(0).length; s++) {
			recursiveSolve(devices, chargers, s+1,switched);
			
			switchAll(chargers, s);
			recursiveSolve(devices, chargers, s+1,switched+1);
			switchAll(chargers, s);
		}
		
	}
	
	private static void switchAll(ArrayList<char[]> chargers, int s) {
		for(int i = 0; i < chargers.size(); i++) {
			switchOne(chargers.get(i), s);
		}
	}
	
	private static void switchOne(char[] c, int i) {
		if(c[i] == '1') {
			c[i] = '0';
		} else {
			c[i] = '1';
		}
	}
	
	private static boolean doesMatch(ArrayList<char[]> devices, ArrayList<char[]> chargers) {
		boolean found[] = new boolean[devices.size()];
		
		loop: for(int i = 0; i < devices.size(); i++) {
			char[] device = devices.get(i);
			
			for(int j = 0; j < chargers.size(); j++) {
				if(!found[j]) {
					char[] charger = chargers.get(j);
					if(Arrays.equals(device, charger)) {
						found[j] = true;
						continue loop;
					}
					
				}
			}
			
			return false;
		}
		return true;
	}
}
