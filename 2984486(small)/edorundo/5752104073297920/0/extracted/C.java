import java.util.*;
import java.io.*;
public class C
{
	public static void main(String[] args) throws Exception
	{
//		Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new File("c-small-attempt3.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("csmallattempt3.out")));
		
		int t = in.nextInt();
		for(int x = 0; x < t; x++)
		{
			int n = in.nextInt();
			
			int[] array = new int[n];
			for(int y = 0; y < array.length; y++)
			{
				array[y] = in.nextInt();
			}
			
			int inversions = 0;
			for(int z = 0; z < array.length; z++)
			{
				for(int a = z + 1; a < array.length; a++)
				{
					if(array[z] > array[a])
					{
						inversions++;
					}
				}
			}
			
			out.print("Case #" + (x + 1) + ": ");
			if(inversions >= 247500)
			{
				out.println("GOOD");
			}
			else
			{
				out.println("BAD");
			}
		}
		
		out.close();
	}
}
