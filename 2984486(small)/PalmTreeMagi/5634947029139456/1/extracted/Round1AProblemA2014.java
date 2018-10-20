
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import Qualification2014Lib.Helper;

public class Round1AProblemA2014
{
	public static boolean[][] parseIntoBooleans( String line, int numberOfIntegers, int numberOfDigits)
	{
		boolean numbers[][] = new boolean[numberOfIntegers][numberOfDigits];
		
		for( int i = 0; i < numberOfIntegers; i ++)
		{
			for( int j = 0; j < numberOfDigits; j ++)
			{
				numbers[i][j] = line.charAt( i * (numberOfDigits + 1) + j) == '1';
			}
		}
		
		return numbers;
	}
	
	public static void main(String[] args)
	{
		ArrayList<String> lines = Helper.readInput( "A-large.in");

		String output = new String();

		int numberOfTestCases = Integer.parseInt( lines.get( 0));
		for( int t = 0; t < numberOfTestCases; t ++)
		{
			int[] NL = Helper.parseIntegers(lines.get( t * 3 + 1), 2);

			output += "Case #" + (t + 1) + ": " + solve( parseIntoBooleans( lines.get( t * 3 + 2), NL[0], NL[1]), parseIntoBooleans( lines.get( t * 3 + 3), NL[0], NL[1])) + "\n";
		}

		Helper.writeOutput( output, "output.txt");
	}
	
	public static String solve( boolean[][] initialSet, boolean[][] goalSet)
	{
		ArrayList<Difference> differences = new ArrayList<Difference>();
		
		for( int i = 0; i < initialSet.length; i ++)
		{
			for( int j = 0; j < goalSet.length; j ++)
			{
				differences.add( new Difference( initialSet[i], goalSet[j]));
			}
		}
		
		Collections.sort( differences, new Comparator<Difference>()
		{
			@Override
			public int compare(Difference a, Difference b)
			{
				return a.numberOfDifferences - b.numberOfDifferences;
			}
		});
		
		// for each difference, see if it works on the lot
		for( Difference difference : differences)
		{
			if( differencesWorksOnLot( initialSet, goalSet, difference))
			{
				return Integer.toString( difference.numberOfDifferences);
			}
		}
		
		return "NOT POSSIBLE";
	}
	
	public static boolean differencesWorksOnLot( boolean[][] initialSet, boolean[][] goalSet, Difference difference)
	{
		boolean[] goalSetTaken = new boolean[goalSet.length];
		
		// compare each initial with each goal, and cross the goal off the list if found
		for( int i = 0; i < initialSet.length; i ++)
		{
			boolean foundMatch = false;
			for( int j = 0; j < goalSet.length && !foundMatch; j ++)
			{
				if( !goalSetTaken[j])
				{
					// does it match?
					Difference differenceCompare = new Difference( initialSet[i], goalSet[j]);
					if( differenceCompare.sameDiff( difference))
					{
						goalSetTaken[j] = true;
						foundMatch = true;
					}
				}
			}
			if( !foundMatch)
			{
				return false;
			}
		}
		return true;
	}
	
	public static class Difference
	{
		int numberOfDifferences;
		boolean[] differenceCode;
		
		public boolean sameDiff( Difference other)
		{
			for( int i = 0; i < differenceCode.length; i ++)
			{
				if( differenceCode[i] != other.differenceCode[i])
				{
					return false;
				}
			}
			return true;
		}
		
		public Difference( boolean[] a, boolean[] b)
		{
			numberOfDifferences = 0;
			differenceCode = new boolean[a.length];
			
			for( int i = 0; i < a.length; i ++)
			{
				if( a[i] != b[i])
				{
					numberOfDifferences ++;
					differenceCode[i] = true;
				}
			}
		}
		
		@Override
		public String toString()
		{
			String dcs = new String();
			for( int i = 0; i < differenceCode.length; i ++)
			{
				dcs += differenceCode[i] ? "1" : "0";
			}
			return numberOfDifferences + ":" + dcs;
		}
	}
}
