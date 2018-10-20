package com.google.util;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileFilter;
import javax.swing.filechooser.FileNameExtensionFilter;

public class IOUtil {
	BufferedWriter writer;
	BufferedReader reader;
	int caseNum = 1;
	
	public IOUtil (String fileIn, String fileOut){
		
		File file = new File(fileIn);
		try {
			reader = new BufferedReader( new FileReader(file));
			file = new File(fileOut);
			writer = new BufferedWriter( new FileWriter(file));
		} catch (IOException e) {
			System.out.println("Something went wrong");
			e.printStackTrace();
		}
	}
	
	public IOUtil(){
		JFileChooser fc = new JFileChooser("C:\\Users\\Tom\\Downloads");
		FileFilter filter = new FileNameExtensionFilter("Google Code Jam","in");
		fc.setFileFilter(filter);
		fc.showOpenDialog(null);
		File file = fc.getSelectedFile();
		String fileOut = "C:\\Users\\Tom\\Downloads\\testout.txt";
		try {
			reader = new BufferedReader( new FileReader(file));
			file = new File(fileOut);
			writer = new BufferedWriter( new FileWriter(file));
		} catch (IOException e) {
			System.out.println("Something went wrong");
			e.printStackTrace();
		}
	}
	public String[] getStrings(){
		String[] returnVal = {};
		try{
			returnVal = reader.readLine().split(" ");
		} catch (IOException e) {
			
		}
		return returnVal;
	}
	
	public int getInt(){
		String returnInt = "";
		try {
			returnInt = reader.readLine();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return Integer.parseInt(returnInt);
	}
	
	public int[] getInts(){
		String[] stringInts = {""};
		try {
			stringInts = reader.readLine().split(" ");
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int[] returnVal = new int[stringInts.length];
		for (int i = 0; i < stringInts.length; i++)
			returnVal[i] = Integer.parseInt(stringInts[i]);
		
		return returnVal;
	}
	
	public LinkedList<Integer> getIntegers(){
		int[] ints = getInts();
		LinkedList<Integer> integers = new LinkedList<Integer>();
		for(int i = 0; i < ints.length; i++)
			integers.add(new Integer(ints[i]));
		return integers;
	}
	
	public LinkedList<Integer> getRowAsLinkedList(){
		int row = getInt();
		for(int discardRows = 1; discardRows < row; discardRows++)
			getInts();
		LinkedList<Integer> returnVal = getIntegers();
		for(int discardRows = row; discardRows < 4; discardRows++)
			getInts();
		return returnVal;
	}
	
	public void writePretty(String output){
		try {
			writer.write("Case #" + caseNum++ + ": " + output + "\n");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void close(){
		try {
			writer.close();
			reader.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public double[] getDoubles(){
		String[] stringDoubles = null;
		try {
			stringDoubles = reader.readLine().split(" ");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		double[] returnVal = new double[stringDoubles.length];
		for(int i = 0; i < returnVal.length; i++)
			returnVal[i] = Double.parseDouble(stringDoubles[i]);
		return returnVal;
	}
}
