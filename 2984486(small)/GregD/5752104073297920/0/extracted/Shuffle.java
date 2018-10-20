/*
 * Google Code Challenge Java
 * 
 * Code written for the Google Code Challenge by Greg Dougherty
 * Created: April 12, 2013
 * 
 * Copyright 2013 by Greg Dougherty
 */

package com.google.GregTD.CodeJam2014.Round1A.ProbC;

import java.io.*;
import java.util.Arrays;
import java.util.Random;

/**
 * @author Greg Dougherty
 *
 */
public class Shuffle
{
	
	private static final String	kInSuffix = ".in";
	private static final String	kOutSuffix = ".out";
	
	
	/**
	 * @param args
	 */
	public static void main (String[] args)
	{
		String	inName = args[0];
		int		nameLen = inName.indexOf (kInSuffix);
		String	outName = inName.substring (0, nameLen) + kOutSuffix;
		File	dataFile = new File (args[0]);
		File	resultFile = new File (outName);
		
		try
		{
			BufferedReader	dataReader = new BufferedReader (new FileReader (dataFile));
			BufferedWriter	dataWriter = new BufferedWriter (new FileWriter (resultFile));
			String			line = dataReader.readLine ();	// Get first line
			int				numCases = Integer.parseInt (line);
			
			double[][]		logOdds = odds (1000, 1000000);
			
			// Run each test case
			for (int i = 0; i < numCases; ++i)
			{
				line = dataReader.readLine ();	// Num numbers 1000
				line = dataReader.readLine ();
				
				int[]		numbers = new int[1000];
				String[]	values = line.split (" ");
				
				for (int j = 0; j < 1000; ++j)
					numbers[j] = Integer.parseInt (values[j]);
				
				double	prob = 0;
				for (int j = 0; j < 1000; ++j)
					prob += logOdds[j][numbers[j]];
				
				dataWriter.write ("Case #" + (i + 1) + ": ");
				if (prob > 0.0)
					dataWriter.write ("BAD");
				else
					dataWriter.write ("GOOD");
				dataWriter.newLine ();
				dataWriter.flush ();
			}
			
			dataReader.close ();
			dataWriter.close ();
		}
		catch (IOException ioE)
		{
			ioE.printStackTrace ();
		}
	}
	
	
	private static double[][] odds (int size, int reps)
	{
		int[][]	counts = new int[size][];
		double	base = Math.log (reps / size);
		
		for (int j = 0; j < size; ++j)
		{
			int[]	row = counts[j] = new int[size];
			for (int i = 0; i < size; ++i)
				row[i] = 1;	// Psuedocounts
		}
		
		for (int i = 0; i < reps; ++i)
		{
			int[]	numbers = new int[size];
			
			for (int j = 0; j < size; ++j)
				numbers[j] = j;
			
			Random	rand = new Random ();
			
			for (int j = 0; j < size; ++j)
			{
				int	pos = rand.nextInt (size);
				int	hold = numbers[j];
				numbers[j] = numbers[pos];
				numbers[pos] = hold;
			}
			
			for (int j = 0; j < size; ++j)
				++counts[j][numbers[j]];
		}
		
		double[][]	logOdds = new double[size][];
		for (int j = 0; j < size; ++j)
			logOdds[j] = new double[size];
		
		for (int i = 0; i < size; ++i)
		{
			double[]	odds = logOdds[i];
			int[]		row = counts[i];
			for (int j = 0; j < size; ++j)
				odds[j] = Math.log (row[j]) - base;
		}
		
		return logOdds;
	}
	
}
