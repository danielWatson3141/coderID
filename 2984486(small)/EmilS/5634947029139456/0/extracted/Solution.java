
import java.util.*;
import java.math.*;
import java.io.*;

public class Solution {

	ArrayList <int[]> listOfSwitches;

	public void generatePermuations (int [] switchesChanged, int index) {
		if (index == switchesChanged.length) {
			listOfSwitches.add(switchesChanged);
		}
		else {
			switchesChanged[index] = 0;
			generatePermuations(Arrays.copyOf(switchesChanged, switchesChanged.length), index + 1);
			
			switchesChanged[index] = 1;
			generatePermuations(Arrays.copyOf(switchesChanged, switchesChanged.length), index + 1);
		}
	}

	public int[][] copy2d (int [][] arr) {
		int newArr [][] = new int [arr.length][arr[0].length];
		for (int i = 0, len = arr.length; i < len; i++) {
			System.arraycopy(arr[i], 0, newArr[i], 0, arr[0].length);
		}

		return newArr;
	}

	public int [][] apply (int [] change, int [][] currentSwitches, int l) {
		// System.out.println("change.length: " +  change.length);
		// System.out.println("l: " +  l);
		for (int i = 0, lenA = currentSwitches.length; i < lenA; i++) {
			for (int x = 0; x < l; x++) {
				if (change[x] == 1)
					currentSwitches[i][x] = currentSwitches[i][x] == 1 ? 0 : 1;
			}
		}
		return currentSwitches;
	}

	public int numOnes (int [] arr) {
		int counter = 0;
		for (int i = 0, len = arr.length; i < len; i++) {
			if (arr[i] == 1)
				counter++;
		}
		return counter;
	}

	public boolean valid (int [][] possibleSwitches, int [][] desiredSwitches, int l) {

		for (int i = 0, lenA = possibleSwitches.length; i < lenA; i++) {
			for (int x = 0; x < l; x++) {
				if (possibleSwitches[i][x] != desiredSwitches[i][x]) {
					return false;
				}
			}
		}
		return true;
	}

	public void printSwitch (int [][] arr) {
		for (int i = 0, len = arr.length; i < len; i++) {
			for (int a = 0; a < arr[0].length; a++) {
				System.out.print(arr[i][a]);	
			}
			System.out.print(" ");
		}
		System.out.println();
	}


	public void sort2d (int [][] arr) {
		// System.out.print("before: ");
		// printSwitch(arr);
		Arrays.sort(arr, new Comparator <int[]> () {
		    public int compare(int [] a, int [] b) {
		        int valA = 0, valB = 0;

		        for (int i = 0, len = a.length - 1; i < len; i++) {
		        	valA += a[i];
		        	valB += b[i];

		        	valA *= 10;
		        	valB *= 10;
		        }

		        valA += a[a.length - 1];
		        valB += b[b.length - 1];

		        return Integer.compare(valA, valB);
		    }
		});
		// System.out.print("after: ");
		// printSwitch(arr);
	}


	public void printArr (int [] arr) {
		System.out.print("[");
		for (int i = 0, len = arr.length; i < len; i++) {
			System.out.print(" ");
			System.out.print(arr[i]);
			System.out.print(",");
		}
		System.out.println("]");
	}

	public void printPossibilities () {
		System.out.println("=== Printing POSSIBLE ===");
		for (int i = 0, len = listOfSwitches.size(); i < len; i++) {
			printArr(listOfSwitches.get(i));
		}
	}

	public Solution () throws IOException {
		BufferedReader in = new BufferedReader (new FileReader("A-small-attempt1.in"));
		PrintWriter out = new PrintWriter (new FileWriter("output.out"));
		int numCases = Integer.parseInt(in.readLine().trim());
		
		for (int cases = 1; cases <= numCases; cases++) {
			listOfSwitches = new ArrayList <int[]> ();
			
			StringTokenizer st = new StringTokenizer(in.readLine().trim());
			int n = Integer.parseInt(st.nextToken());
			int l = Integer.parseInt(st.nextToken());
			
			int currentSwitches [][] = new int [n][l];
			int desiredSwitches [][] = new int [n][l];
			st = new StringTokenizer(in.readLine().trim());
			StringTokenizer stB = new StringTokenizer(in.readLine().trim());
			for (int i = 0; i < n; i++) {
				char [] temp = st.nextToken().toCharArray();
				char [] tempB = stB.nextToken().toCharArray();
				for (int x = 0; x < l; x++) {
					currentSwitches[i][x] = temp[x] == '1' ? 1 : 0;
					desiredSwitches[i][x] = tempB[x] == '1' ? 1 : 0;
				}
			}

			int tempArr [] = new int [l];
			generatePermuations(tempArr, 0);


			sort2d(desiredSwitches);
			int min = Integer.MAX_VALUE;

			for (int i = 0, len = listOfSwitches.size(); i < len; i++) {
				int [][] newSwitches = apply(listOfSwitches.get(i), copy2d(currentSwitches), l);
				sort2d(newSwitches);
				if (valid(newSwitches, copy2d(desiredSwitches), l))
					min = Math.min(numOnes(listOfSwitches.get(i)), min);
			}

			System.out.print("Case #");
			System.out.print(cases);
			System.out.print(": ");

			if (Integer.MAX_VALUE == min)
				System.out.println("NOT POSSIBLE");
			else
				System.out.println(min);
			
		}
		out.close();
		in.close();
	}


	public static void main (String [] args) throws IOException {
		new Solution ();
	}
}