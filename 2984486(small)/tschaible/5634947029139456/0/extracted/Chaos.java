import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


public class Chaos {

	public static void main(String[] args) throws IOException {
		solve("chaos.input");
		solve("chaos.a-small.input");

	}
	
	public static void solve(String fileName) throws IOException	
	{
		Scanner scanner = new Scanner(new File(fileName));
		FileWriter out = new FileWriter(fileName+".output");
		int cases = scanner.nextInt();
		for ( int i = 1; i <= cases; i++)
		{
						
			int n = scanner.nextInt();
			int l = scanner.nextInt();
			String outlets [] = new String [n];
			String chargers [] = new String [n];
			
			for (int j = 0; j < n; j++ )
			{
				outlets[j] = scanner.next("[0-1]+");			
			}
			
			for (int j = 0; j < n; j++ )
			{
				chargers[j] = scanner.next("[0-1]+");
			}
			
			
			System.out.println("Case #" + i);
			out.write("Case #" + i + ": ");
			//print(outlets,chargers);
			//print(swap(outlets,0),chargers);
			int count = getMinCount(0,0,outlets,chargers);
			if ( count == 9999999 )
			{
				out.write("NOT POSSIBLE\n");
			}
			else
			{
				out.write(count + "\n");
			}
			System.out.println("Moves: " + getMinCount(0,0,outlets,chargers));
			
		}		
		scanner.close();
		out.close();
		
	}
	
	private static int getMinCount(int totalCount, int i, String[] outlets, String[] chargers)
	{
		if ( matches(outlets,chargers) == outlets.length )
		{
			return totalCount;
		}
		if ( i == outlets[0].length() )
		{
			return 9999999;
		}
		int dontSwap = getMinCount(totalCount,i+1,outlets,chargers);
		int swap = getMinCount(totalCount+1,i+1,swap(outlets,i),chargers);
		
		return Math.min(swap, dontSwap);
	}
	
	private static String [] swap(String [] outlets, int i )
	{
		String [] newOutlets = new String[outlets.length];
		for (int j = 0; j < outlets.length; j++ )
		{
			char [] newString = outlets[j].toCharArray();
			if ( outlets[j].charAt(i) == '0' )
			{				
				newString[i]='1';
			}
			else
			{
				newString[i]='0';
			}
			newOutlets[j] = new String(newString);
		}
		return newOutlets;		
	}
	
	private static int matches(String[] outlets, String[] chargers)
	{
		int matches = 0;
		for ( int i = 0; i < outlets.length; i++ )
		{
			for ( int j = 0; j < outlets.length; j++ )
			{
				if ( outlets[i].equals(chargers[j]) )
				{
					matches++;
					break;
				}
			}
		}
		return matches;
	}
	
	private static void print(String[] outlets, String[] chargers)
	{
		for ( int i = 0; i < outlets.length; i++ )
		{
			System.out.print(outlets[i]);		
			System.out.print("\t");
			System.out.println(chargers[i]);
		}
	}

}
