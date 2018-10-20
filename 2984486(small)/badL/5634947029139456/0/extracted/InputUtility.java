package com.badal.util;

import java.io.BufferedReader;

public class InputUtility {

	public static int[] getIntArray(BufferedReader br) throws Exception{
		String[] split = br.readLine().split(" ");
		int[] ret = new int[split.length];
		for(int i = 0; i<split.length; i++){
			ret[i] = Integer.parseInt(split[i]);
		}
		return ret;
	}
	
	public static double[] getDoubleArray(BufferedReader br) throws Exception{
		String[] split = br.readLine().split(" ");
		double[] ret = new double[split.length];
		for(int i = 0; i<split.length; i++){
			ret[i] = Double.parseDouble(split[i]);
		}
		return ret;
	}
	
	public static int getInt(BufferedReader br)  throws Exception{
		return Integer.parseInt(br.readLine());
	}

	public static int[][] getIntMatrix(BufferedReader br, int row, int column)  throws Exception{
		int[][] ret = new int[row][column];
		for (int i = 0; i < row; i++) {
			String[] split = br.readLine().split(" ");
			for (int j = 0; j < column; j++) {
				ret[i][j] = Integer.parseInt(split[j]); 
			}
		}
		return ret;
	}
	
	public static String[] getLines(BufferedReader br, int count) throws Exception{
		String[] ret = new String[count];
		for(int i = 0; i<count; i++){
			ret[i] = br.readLine();
		}
		return ret;
	}
}
