package com.mkomo.codejam.charging;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Driver {
	
	private static String solveCase(BufferedReader br) throws IOException {

		int bits = Integer.valueOf(br.readLine().split(" ")[1]);
		List<Integer> outs = readBinInts(br.readLine());
		List<Integer> devs = readBinInts(br.readLine());
//		System.out.println(outs);
//		System.out.println(devs);
		List<Integer> either = new ArrayList<Integer>();
		int switches = 0;
		for (int i = 0; i < bits; i++){
			int zeroOuts = getNumZeros(outs, i);
			int zeroDevs = getNumZeros(devs, i);
			if (zeroOuts == zeroDevs){
				if (zeroOuts + zeroDevs == outs.size()){
//					System.out.println("do OR don't switch " + i);
					either.add(i);
				} else {
//					System.out.println("don't switch " + i);
				}
			} else if (zeroOuts + zeroDevs == outs.size()){
//				System.out.println("do switch " + i);
				outs = sw(outs, i);
				switches ++ ;
			} else {
				return "NOT POSSIBLE";
			}
		}
		if (devs.containsAll(outs)){
			return "" + switches;
		} else {
			Collections.sort(devs);
			Collections.sort(outs);

			System.out.println(outs);
			System.out.println(devs);
			System.out.println(either);
			
			int a = tryAll(either, outs, devs);
			if (a < Integer.MAX_VALUE){
//				throw new RuntimeException("maybe " + a);
				return "" + (a + switches);
			} else {
				return "NOT_POSSIBLE";
			}
		}
	}

	private static int tryAll(List<Integer> either, List<Integer> outs,
			List<Integer> devs) {
		int sw = Integer.MAX_VALUE;
		for (Set<Integer> switchSubset : powerSet(new HashSet<Integer>(either))){
			List<Integer> newOuts = new ArrayList<Integer>(outs);
			for (Integer s : switchSubset){
				newOuts = sw(newOuts, s);
//				System.out.println(newOuts);
			}
			if (newOuts.containsAll(devs) && switchSubset.size() < sw){
				sw = switchSubset.size();
			}
		}
		return sw;
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
	    System.out.println(sets);
	    return sets;
	}

	private static List<Integer> sw(List<Integer> outs, int n) {
		List<Integer> newOuts = new ArrayList<Integer>(outs);
		for (int i = 0; i < outs.size(); i++){
			newOuts.set(i, outs.get(i) ^ (1 << n));
		}
		return newOuts;
	}

	private static int getNumZeros(List<Integer> things, int i) {
		int count = 0;
		for (int thing : things){
			if ((1 << i) == ((1 << i) & thing)){
				count ++;
			}
		}
		return count;
	}

	private static List<Integer> readBinInts(String line) {
		List<Integer> ints = new ArrayList<Integer>();
		for (String s : line.split(" ")){
			ints.add(Integer.parseInt(s, 2));
		}
		return ints;
	}

	/**
	 * immutable main method for all code jam problems
	 * 
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException{
		String SET_NAME="A-small-attempt1";
		String filename = getDir() + SET_NAME+".in";
		System.out.println(filename);
		BufferedReader br = new BufferedReader(new FileReader(filename));
		FileWriter fw = new FileWriter(getDir() + SET_NAME + ".out");
		int numCases = Integer.parseInt(br.readLine());
		for (int i = 1; i <= numCases; i++){
			System.out.println("Solving case " + i + "...");
			String output = "Case #" + i + ": " + solveCase(br) + '\n'; 
			System.out.println(output);
			fw.write(output);
		}
		fw.close();
	}
	
	private static String getDir() throws IOException{
		String pathToEnv = (new File(".")).getCanonicalPath();
		String pathToClass = Driver.class.getPackage().getName().replace('.', '/') + '/';
		return pathToEnv + "/src/main/java/" + pathToClass;
	}
}
