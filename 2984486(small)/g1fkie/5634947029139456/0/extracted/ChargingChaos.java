package codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;

public class ChargingChaos {
	
	public static void main(String[] args) {
		
		File file = new File("C:\\Users\\Marco\\Desktop\\A-small-attempt1.in");
		Scanner sc = null;
		int numCases = 0;
		
		try {
			sc = new Scanner(file);
			numCases = sc.nextInt();
		} catch (FileNotFoundException e) {
			System.out.println("Fehler beim Einlesen!");
			e.printStackTrace();
		}
		
		for (int caseNum = 1; caseNum <= numCases; caseNum++) {
			
			int N = Integer.parseInt(sc.next());
			int L = Integer.parseInt(sc.next());
			
			int[] devices = new int[N];
			int[] flows = new int[N];
			
			Set<Integer> flowSet = new HashSet<Integer>();
			Set<Integer> posSet = new HashSet<Integer>();
			
			for (int i = 0; i < N; i++) {
				devices[i] = Integer.parseInt(sc.next(), 2);
//				System.err.println(devices[i]);
			}
			
			for (int i = 0; i < N; i++) {
				int tmp = Integer.parseInt(sc.next(), 2);
				flows[i] = tmp;
				flowSet.add(tmp);
//				System.err.println(flows[i]);
			}
			
			for (int i = 0; i < N; i++) {
				posSet.add(devices[0] ^ flows[i]);
			}
			
			boolean impossible = false;
			
			for (int i = 1; i < N; i++) {
				
				LinkedList<Integer> toDelete = new LinkedList<Integer>();
				
				for (Integer a : posSet) {
					if (flowSet.contains(devices[i] ^ a)) {
						
					} else {
						toDelete.add(a);
//						System.out.println("----------Deleted " + a);
					}
				}
//				System.out.println("-------Deleted size " + toDelete.size());
				posSet.removeAll(toDelete);
				
				if (posSet.isEmpty()) {
					impossible = true;
					break;
				}
			}
			
			System.out.print("Case #" + caseNum + ": ");
			
			if (impossible) {
				System.out.println("NOT POSSIBLE");
				continue;
			}
			
			int tmp = Integer.MAX_VALUE;
			
			for (Integer a : posSet) {
				
				int tmp2 = Integer.bitCount(a); 
				
				if (tmp2 < tmp) {
					tmp = tmp2;
				}
			}
			
			System.out.println(tmp);
		}
	}
}
