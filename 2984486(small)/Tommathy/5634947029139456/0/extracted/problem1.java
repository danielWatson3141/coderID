package com.google.round1a;

import java.util.LinkedList;

import com.google.util.IOUtil;

public class problem1 {

	public static void main(String[] args) {
		IOUtil io = new IOUtil();
		int numberOfCases = io.getInt();
		for(int caseNum = 1; caseNum <= numberOfCases; caseNum++){
			int[] info = io.getInts();
			String[] t = io.getStrings();
			LinkedList<Integer> o = new LinkedList<Integer>();
			for(int i= 0; i < t.length; i++)
				o.add(Integer.parseInt(t[i], 2));
			LinkedList<Integer> d = new LinkedList<Integer>();
			t = io.getStrings();
			for(int i= 0; i < t.length; i++)
				d.add(Integer.parseInt(t[i], 2));
			int times = 0;
			int bestTimes = Integer.MAX_VALUE;
			for(int i = 0; i < o.size(); i++){
				int xor = (d.getFirst().intValue() ^ o.get(i).intValue());
				times = Integer.toString(xor, 2).replace("0", "").length();
				if(d.containsAll(xor(o, xor)))
					if(bestTimes > times){
						System.out.println(bestTimes + "\t" + times);
						bestTimes = times;
					}
			}
			if(bestTimes < Integer.MAX_VALUE)
				io.writePretty("" + bestTimes);
			else
				io.writePretty("NOT POSSIBLE");
		}
		io.close();
	}
	
	public static LinkedList<Integer> xor(LinkedList<Integer> o, int xor){
		LinkedList<Integer> no = new LinkedList<Integer>();
		for(int i = 0; i < o.size(); i++)
			no.add(new Integer(o.get(i).intValue() ^ xor));
		
		return no;
	}
	
	public static boolean chargedDevices(LinkedList<Integer> o, LinkedList<Integer> d){
		for(Integer i : o)
			if(!d.contains(i))
				return false;
			
		return true;
	}
}
