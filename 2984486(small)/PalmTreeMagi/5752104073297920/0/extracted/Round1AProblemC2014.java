
import java.util.ArrayList;
import java.util.Random;

import Qualification2014Lib.Helper;

@SuppressWarnings("unused")
public class Round1AProblemC2014
{
	public static void main(String[] args)
	{
		ArrayList<String> lines = Helper.readInput( "C-small-attempt7.in");
		//ArrayList<String> lines = Helper.readInput( "in.in");

		String output = new String();

		int bad = 0;
		int good = 0;
		int diff = 0;
		
		int numberOfTestCases = Integer.parseInt( lines.get( 0));
		for( int t = 0; t < numberOfTestCases; t ++)
		{
			int[] list = Helper.parseIntegers( lines.get( t * 2 + 2), 1000);

			boolean sa = solve( list);
			boolean sb = solve2( list);
			
			String result;
			
			diff += (sa == sb) ? 0 : 1;
			
			if( sb)
			{
				bad ++;
				result = "BAD";
			}
			else
			{
				good ++;
				result = "GOOD";
			}
			
			output += "Case #" + (t + 1) + ": " + result + "\n";
		}
		
		Helper.writeOutput( output, "outputC.txt");

		System.out.println( bad);
		System.out.println( good);
		System.out.println( diff);
	}
	
	public static boolean solve2( int[] list)
	{
		long indexBefore = 0;
		for( int i = 0; i < 500; i ++)
		{
			indexBefore += list[i];
		}
		long indexAfter = 0;
		for( int i = 500; i < 1000; i ++)
		{
			indexAfter += list[i];
		}
		double averageBefore = indexBefore / 500.0;
		double averageAfter = indexAfter / 500.0;

		//System.out.println( averageAfter + ", " + averageBefore);
		
		return ( Math.abs( averageAfter - averageBefore) > 18.85);
	}
	
	public static boolean solve( int[] list)
	{
		final int A = 0;
		final int B = 25;
		final int C = 533;
		final int D = 800;
		long totalBefore = 0;
		for( int i = A; i < B; i ++)
		{
			totalBefore += list[i];
		}
		long totalAfter = 0;
		for( int i = C; i < D; i ++)
		{
			totalAfter += list[i];
		}
		double averageBefore = totalBefore / ((double)(B-A));
		double averageAfter = totalAfter / ((double)(D-C));
		
		//System.out.println( averageAfter + ", " + averageBefore);
		
		return ( Math.abs( averageAfter - averageBefore) > 49);
	}
/*
	public static void printGraph()
	{
		double[] outputGFinal = new double[100];
		double[] outputBFinal = new double[100];
		{
			long[] outputG = new long[outputGFinal.length];
			for( int i = 0; i < 1000000; i ++)
			{
				good( outputG);
			}
			for( int i = 0; i < outputG.length; i ++)
			{
				outputGFinal[i] = outputG[i] / 1000000.0;
			}
		}

		{
			long[] outputB = new long[outputBFinal.length];
			for( int i = 0; i < 1000000; i ++)
			{
				bad( outputB);
			}
			for( int i = 0; i < outputB.length; i ++)
			{
				outputBFinal[i] = outputB[i] / 1000000.0;
			}
		}
		
		for( int i = 0; i < outputGFinal.length; i ++)
		{
			System.out.print( outputGFinal[i] + ", ");
		}

		System.out.println();
		System.out.println();
		
		for( int i = 0; i < outputBFinal.length; i ++)
		{
			System.out.print( outputBFinal[i] + ", ");
		}
	}

	public static void good( long outputG[])
	{
		int[] set = new int[outputG.length];
		for( int i = 0; i < set.length; i ++)
		{
			set[i] = i;
		}
		Random random = new Random();
		for( int i = 0; i < set.length; i ++)
		{
			int p = random.nextInt( set.length - i) + i;
			swap( set, i, p);
		}
		for( int i = 0; i < set.length; i ++)
		{
			outputG[i] += set[i];
		}
	}

	public static void bad( long outputB[])
	{
		int[] set = new int[outputB.length];
		for( int i = 0; i < set.length; i ++)
		{
			set[i] = i;
		}
		Random random = new Random();
		for( int i = 0; i < set.length; i ++)
		{
			int p = random.nextInt( set.length);
			swap( set, i, p);
		}
		for( int i = 0; i < set.length; i ++)
		{
			outputB[i] += set[i];
		}
	}

	public static void swap( int[] set, int a, int b)
	{
		int temp = set[a];
		set[a] = set[b];
		set[b] = temp;
	}*/
}
