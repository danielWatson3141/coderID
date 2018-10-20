package round1a.p1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;

public class P1
{
	private static void calculate( int N, int L, String[] outlets, String[] devices, BufferedWriter bw, int n ) throws Exception
	{
		Arrays.sort( devices );
		
		String answer = "NOT POSSIBLE";
		
		String device = devices[0];
		
		main: for ( int i = 0; i < L; i++ )
		{
			for ( int j = 0; j < N; j++ )
			{
				Integer[] diff = diff( device, outlets[ j ] );
				if ( diff.length == i )
				{
					String[] flippedOutlet = flip( outlets, diff );
					if ( check(flippedOutlet, devices ) )
					{
						answer = ""+i;
						break main;
					}
				}
			}
		}
		
		bw.append( "Case #"+n+": " + answer + "\n" );
		bw.flush();
	}
	
	private static String[] flip( String[] outlets, Integer[] diff )
	{
		String[] flippedOutlets = new String[ outlets.length ];
		for ( int i = 0; i < outlets.length; i++ )
		{
			String flippedOutlet = flip( outlets[i], diff );
			flippedOutlets[i] = flippedOutlet;
		}
		return flippedOutlets;
	}
	
	private static String flip( String outlet, Integer[] diff )
	{
		char[] flippedOutlet = outlet.toCharArray();
		for ( Integer d : diff )
		{
			if ( flippedOutlet[d] == '0' )
				flippedOutlet[d] = '1';
			else if ( flippedOutlet[d] == '1' )
				flippedOutlet[d] = '0';
		}
		
		return new String( flippedOutlet );
	}
	
	private static boolean check( String[] outlets, String[] devices )
	{
		Arrays.sort( outlets );
		
		for ( int i = 0; i < outlets.length; i++ )
			if ( !outlets[i].equals( devices[i] ) )
				return false;
		
		return true;
	}
	
	private static Integer[] diff( String device, String outlet )
	{
		Collection<Integer> diffs = new ArrayList<Integer>();
		
		for ( int i = 0; i < device.length(); i++ )
			if ( device.charAt( i ) != outlet.charAt( i ) )
				diffs.add( i );
		
		return diffs.toArray( new Integer[0] );
	}

	public static void main( String[] args ) throws Exception
	{
		File inputFile = new File( "inputfiles/round1a/p1/input.txt" );
		FileReader fr = new FileReader( inputFile );
		BufferedReader br = new BufferedReader( fr );
		
		int numOfTestCases = Integer.parseInt( br.readLine() );
		
		File outputFile = new File( "inputfiles/round1a/p1/output.txt" );
		outputFile.delete();
		outputFile.createNewFile();
		FileWriter fw = new FileWriter( outputFile );
		BufferedWriter bw = new BufferedWriter( fw );
		
		for ( int i = 0; i < numOfTestCases; i++ )
		{
			String[] data = null;
			data = br.readLine().split( " " );
			int N = Integer.parseInt( data[0] );
			int L = Integer.parseInt( data[1] );
			
			String[] outlets = br.readLine().split( " " );
			
			String[] devices = br.readLine().split( " " );
			
			calculate( N, L, outlets, devices, bw, i+1 );
		}
		
		bw.flush();
		fw.flush();
		
		bw.close();
		fw.close();
	}
}
