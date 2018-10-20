import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

import com.google.common.base.Charsets;
import com.google.common.collect.ImmutableList;
import com.google.common.io.Files;


public class ChargingChaos {

	public static void main(String [] args) throws IOException{
		// Read the lines of a UTF-8 text file
		ImmutableList<String> lines = Files.asCharSource(new File(args[0]), Charsets.UTF_8).readLines();
		int numCases = Integer.parseInt(lines.get(0));
		File outputFile = new File(args[1]);
		if(outputFile.exists()){
			outputFile.delete();
			outputFile.createNewFile();
		}
		PrintWriter writer = new PrintWriter(outputFile);
		for(int i = 0; i< numCases; i++){
			String numLine = lines.get(i*3+1);
			String initConfLine = lines.get(i*3+2);
			String reqConfLine = lines.get(i*3+3);
			System.out.println("Case "+i+" Num line:"+numLine);
			System.out.println(initConfLine);
			System.out.println(reqConfLine);
			solveCase(initConfLine,reqConfLine,i+1, writer);
		}
		writer.close();
	}


	private static void solveCase(String initConfLine, String reqConfLine, int caseNum, PrintWriter writer) {
		String [] initConfs = initConfLine.split(" ");
		String [] reqConfs = reqConfLine.split(" ");

		assert(initConfLine.length()==reqConfLine.length());
		assert(initConfs[0].length() == reqConfs[0].length());
		int countOfInitEvery0Digits [] = new int [initConfs[0].length()];
		int countOfFinalEvery0Digits [] = new int [initConfs[0].length()];

		for (int i = 0; i< initConfs.length;i++){
			String initConf = initConfs[i];
			String reqConf = reqConfs[i];
			for (int j = 0; j < initConf.length(); j++){
				if(initConf.charAt(j)=='0'){
					countOfInitEvery0Digits[j] ++;
				}
				if(reqConf.charAt(j)=='0'){
					countOfFinalEvery0Digits[j] ++;
				}
			}

		}

		boolean flips [] = new boolean [initConfs[0].length()];
		Set<Integer> toFlip = new HashSet<Integer>();
		
		for(int i = 0; i < countOfInitEvery0Digits.length; i++){
			if (countOfInitEvery0Digits [i] == countOfFinalEvery0Digits[i]){
				// Not to flip
				flips [i] = false;
				if(countOfInitEvery0Digits[i]== initConfs.length - countOfFinalEvery0Digits[i]){
					toFlip.add(i);
				}
			}else if(countOfInitEvery0Digits[i]== initConfs.length - countOfFinalEvery0Digits[i]){
				// To flip
				flips [i] = true;
			}else{
				writer.append("Case #"+caseNum+": NOT POSSIBLE\n");
				return;
			}
		}
		
		List<Set<Integer> > toFlipList = new ArrayList<Set<Integer>>();
		toFlipList.addAll(powerSet(toFlip));
		Collections.sort(toFlipList, new Comparator<Set<Integer>>(){
            public int compare(Set<Integer> s1,Set<Integer> s2){
                return s1.size()-s2.size();
          }});
		for(Set<Integer> s : toFlipList){
			boolean flipsCopy [] = new boolean [flips.length];
			System.arraycopy( flips, 0, flipsCopy, 0, flips.length );
			for(Integer i : s){
				flipsCopy[i] = true;
			}
			if(testConfiguration (initConfs, reqConfs, flipsCopy)){
				int flipCount = 0;
				for(int j = 0; j< flipsCopy.length; j++){
					if(flipsCopy[j] == true){
						flipCount ++;
					}
				}
				writer.append("Case #"+caseNum+": "+flipCount+"\n");

				return;
			}
		}
		writer.append("Case #"+caseNum+": NOT POSSIBLE\n");
	}
	
	public static <T> Set<Set<T>> powerSet(Set<T> originalSet) {
	    Set<Set<T>> sets = new HashSet<Set<T>>();
	    if (originalSet.isEmpty()) {
	    	sets.add(new HashSet<T>());
	    	return sets;
	    }
	    List<T> list = new ArrayList<T>(originalSet);
	    T head = list.get(0);
	    Set<T> rest = new HashSet<T>(list.subList(1, list.size())); 
	    for (Set<T> set : powerSet(rest)) {
	    	Set<T> newSet = new HashSet<T>();
	    	newSet.add(head);
	    	newSet.addAll(set);
	    	sets.add(newSet);
	    	sets.add(set);
	    }		
	    return sets;
	}
	
	public static boolean testConfiguration(String [] initConfs, String[]reqConfs, boolean flips[]){
		HashMap<String,Integer> flipedMap = new HashMap<String,Integer>();

		for(int i = 0; i < initConfs.length; i++){
			StringBuilder sb = new StringBuilder();
			String initConf = initConfs[i];
			for (int j = 0; j < initConf.length(); j++){
				if(initConf.charAt(j)=='0'){
					if(flips[j]==true){
						sb.append('1');
					}else{
						sb.append('0');
					}
				}else{
					if(flips[j]==true){
						sb.append('0');
					}else{
						sb.append('1');
					}
				}
			}
			Integer count = flipedMap.get(sb.toString());
			if(count == null){
				flipedMap.put(sb.toString(), 1);
			}else{
				flipedMap.put(sb.toString(), count+1);
			}
		}
		for(int i = 0; i < reqConfs.length; i++){
			String reqConf = reqConfs[i];
			if(!flipedMap.containsKey(reqConf)||flipedMap.get(reqConf)==0){
				return false;
			}
			flipedMap.put(reqConf,flipedMap.get(reqConf)-1);
		}
		return true;
	}
}
