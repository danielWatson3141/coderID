package com.sungard.codeJam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A {


	public static File inputFile = new File("C:\\Users\\vikas\\workspace\\CodeJam\\inputFile.txt");
	public static File outputFile = new File("C:\\Users\\vikas\\workspace\\CodeJam\\output.txt");
	
	public static void main(String[] args) {
		process();
	}
	
	static int N;
	static int L;
	static ArrayList<String> originalList;
	static ArrayList<String> finalList;
	static int min = Integer.MAX_VALUE;
	public static void process() {
		PrintWriter pw = null;
		Scanner scan = null;
		try {
			scan = new Scanner(inputFile);
			pw = new PrintWriter(outputFile);
			int T = scan.nextInt();
			for (int i=0; i<T; i++){
				N = scan.nextInt();
				L = scan.nextInt();
				min = Integer.MAX_VALUE;
				originalList = new ArrayList();
				finalList = new ArrayList();
				for (int j=0;j<N;j++){
					originalList.add(scan.next());
				}
				for (int j=0;j<N;j++){
					finalList.add(scan.next());
				}
				match(originalList, 0, 0);
				String result = "NOT POSSIBLE";
				if (min < Integer.MAX_VALUE) {
					result = min + "";
				}
				System.out.println(result);
				pw.println("Case #" + (i+1) + ": " + result);
			}
			
		} catch (FileNotFoundException e) {
			System.out.println("File Not Found:" + inputFile.getAbsolutePath());
		} finally {
			pw.close();
			scan.close();
		}
	}
	
	public static void match(ArrayList<String> list, int index, int count) {
		
		if (list.containsAll(finalList)) {
			if (count < min) {
				min = count;
			}
			return;
		}
		if (index >= L) return;
		match(list, index+1, count);
		ArrayList newList = newList(list, index);
		match(newList, index+1, count+1);
	}
	
	public static ArrayList newList(ArrayList<String> list, int index) {
		ArrayList newList = new ArrayList();
		for (String s : list) {
			char[] chars = s.toCharArray();
			char c = chars[index];
			if (c == '1') {
				c = '0';
			} else {
				c = '1';
			}
			chars[index] = c;
			newList.add(new String(chars));
		}
		return newList;
	}
}
