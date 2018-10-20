
package Qualification2014Lib;

import java.io.*;
import java.util.*;

public class Helper
{
	public static ArrayList<String> readInput( String filename)
	{
		Scanner scanner = null;

		ArrayList<String> lines = new ArrayList<String>();

		try
		{
			scanner = new Scanner( new BufferedReader( new FileReader( filename)));
			while( scanner.hasNextLine())
			{
				lines.add( scanner.nextLine());
			}
		}
		catch (FileNotFoundException e)
		{
			e.printStackTrace();
		}

		scanner.close();

		return lines;
	}

	public static void writeOutput( String output, String filename)
	{
		System.out.println( output);
		PrintWriter out = null;
		try
		{
			out = new PrintWriter( new FileWriter( filename));
			out.print( output);
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		if( out != null)
		{
			out.close();
		}
	}

	public static int[] parseIntegers( String line, int numberOfIntegers)
	{
		int numbers[] = new int[numberOfIntegers];

		for( int i = 0; i < numberOfIntegers; i ++)
		{
			int spaceIndex = line.indexOf( " ");
			if( spaceIndex != -1)
			{
				String strNum = line.substring( 0, spaceIndex);
				line = line.substring( spaceIndex + 1);
				numbers[i] = Integer.parseInt( strNum);
			}
			else
			{
				numbers[i] = Integer.parseInt( line);
			}
		}
		return numbers;
	}
}
