/*
 * Google Code Challenge Java
 * 
 * Code written for the Google Code Challenge by Greg Dougherty
 * Created: April 12, 2013
 * 
 * Copyright 2013 by Greg Dougherty
 */

package com.google.GregTD.CodeJam2014.Round1A.ProbA;

import java.io.*;
import java.util.Arrays;

/**
 * @author Greg Dougherty
 *
 */
public class Charging
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
			
			// Run each test case
			for (int i = 0; i < numCases; ++i)
			{
				line = dataReader.readLine ();
				
				String[]	values = line.split (" ");
				int			numDevices = Integer.parseInt (values[0]);
				int			numBits = Integer.parseInt (values[1]);
				int[]		outlets = new int[numDevices];
				int[]		devices = new int[numDevices];
				
				line = dataReader.readLine ();
				values = line.split (" ");
				
				for (int j = 0; j < numDevices; ++j)
					outlets[j] = Integer.parseInt (values[j], 2);
				
				line = dataReader.readLine ();
				values = line.split (" ");
				
				for (int j = 0; j < numDevices; ++j)
					devices[j] = Integer.parseInt (values[j], 2);
				
				Arrays.sort (outlets);
				Arrays.sort (devices);
				
				int	numSwitch = getNumSwitches (numDevices, outlets, devices, numBits);
				
				dataWriter.write ("Case #" + (i + 1) + ": ");
				if (numSwitch < 0)
					dataWriter.write ("NOT POSSIBLE");
				else
					dataWriter.write ("" + numSwitch);
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
	
	
	/**
	 * 
	 * @param numDevices
	 * @param outlets
	 * @param devices
	 * @return
	 */
	private static int getNumSwitches (int numDevices, int[] outlets, int[] devices, int numBits)
	{
		if (Arrays.equals (outlets, devices))
			return 0;
		
		int[]	needed = getCounts (devices, numBits, numDevices);
		int[]	have = getCounts (outlets, numBits, numDevices);
		int		flips = 0;
		
		for (int i = 0; i < numBits; ++i)
		{
			int	need = needed[i];
			int	avail = have[i];
			
			if (need != avail)
			{
				++flips;
				if (need != (numDevices - avail))
					return -1;
			}
		}
		
		return flips;
	}
	
	
	private static final int[] getCounts (int[] source, int numBits, int numItems)
	{
		int[]	needed = new int[numBits];
		
		for (int i = 0; i < numBits; ++i)
		{
			int	total = 0;
			int	flag =  (1 << i);
			for (int j = 0; j < numItems; ++j)
			{
				if ((source[j] & flag) != 0)
					++total;
			}
			
			needed[i] = total;
		}
		
		return needed;
	}
	
}
