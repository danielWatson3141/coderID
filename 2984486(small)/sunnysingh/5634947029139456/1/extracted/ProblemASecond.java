package onlineround2014;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;

public class ProblemASecond {

	public static void main(String[] args) throws Exception {
		readProblem("D:/Sunny/GCJ/OnlineRound2014/A-small-attempt4.in");
	}

	public static void readProblem(String filePath) throws FileNotFoundException, IOException {
		BufferedReader reader = new BufferedReader(new FileReader(filePath));
		int testCases = Integer.parseInt(reader.readLine().trim());
		for(int i=1;i<=testCases;i++){
			String dataLine = reader.readLine().trim();
			String[] dataLineArray = dataLine.split(" ");
			int numOutlets = Integer.parseInt(dataLineArray[0]);
			int numSwitches = Integer.parseInt(dataLineArray[1]);

			dataLine = reader.readLine().trim();
			String[] initialFlowArray = dataLine.split(" ");

			dataLine = reader.readLine().trim();
			String[] desiredFlowArray = dataLine.split(" ");

			int minSwitchesToFlip=0;
			boolean isPossible = false;

			boolean initialCompare = compareArrays(initialFlowArray, desiredFlowArray); 

			if(!initialCompare){
				for(int j=0;j<numOutlets;j++){
					String left = initialFlowArray[j];
					for(int k=0;k<numOutlets;k++){
						String right = desiredFlowArray[k];
						String mask = xor(left,right);
						String[] outcome = new String[numOutlets];
						for(int t=0;t<numOutlets;t++){
							outcome[t] = xor(initialFlowArray[t],mask);
						}
						boolean isEqual = compareArrays(outcome, desiredFlowArray);
						if(isEqual){
							isPossible = true;
							int numberofFlips = countOnesInMask(mask);
							if(numberofFlips < minSwitchesToFlip && minSwitchesToFlip!=0){
								minSwitchesToFlip = numberofFlips;
							}else if(minSwitchesToFlip==0){
								minSwitchesToFlip = numberofFlips;
							}
						}
					}
				}
			}else{
				isPossible = true;
			}

			if(isPossible){
				System.out.println("Case #"+i+": "+minSwitchesToFlip);
			}else{
				System.out.println("Case #"+i+": NOT POSSIBLE");
			}
		}
		reader.close();
	}
	
	private static int countOnesInMask(String mask){
		int switches = 0;
		for (int i = 0; i < mask.length(); i++) {
			int number = Integer.parseInt(String.valueOf(mask.charAt(i)));
			if(number == 1){
				switches++;
			}
		}
		return switches;
	}

	private static String xor(String left, String right){
		StringBuilder sb = new StringBuilder();

		for (int i = 0; i < left.length(); i++) {
			sb.append(charOf(bitOf(left.charAt(i)) ^ bitOf(right.charAt(i))));
		}

		String result = sb.toString();

		return result;
	}

	private static boolean bitOf(char in) {
		return (in == '1');
	}

	private static char charOf(boolean in) {
		return (in) ? '1' : '0';
	}


	private static boolean compareArrays(String[] initial, String[] desired){
		boolean isEqual = false;

		Set<String> initialFlowSet = new HashSet<>();
		Set<String> desiredFlowSet = new HashSet<>();
		
		for(int i=0;i<initial.length;i++){
			initialFlowSet.add(initial[i]);
			desiredFlowSet.add(desired[i]);
		}
		
		isEqual = initialFlowSet.equals(desiredFlowSet);
		
		return isEqual;	
	}
	private static void printSet(Set<String> set){
		for(String s: set){
			System.out.println(s+" ");
		}
		System.out.println("\n");
	}
}
