import java.util.*;
import java.io.*;
public class ASmall
{
	public static void main(String[] args) throws Exception
	{
//		Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new File("a-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("asmallattempt0.out")));
		
		int t = in.nextInt();
		for(int x = 0; x < t; x++)
		{
			int n = in.nextInt();
			int l = in.nextInt();
			
			int[] outlets = new int[n];
			for(int y = 0; y < n; y++)
			{
				outlets[y] = Integer.valueOf(in.next(), 2);
			}
			
			int[] devices = new int[n];
			for(int z = 0; z < n; z++)
			{
				devices[z] = Integer.valueOf(in.next(), 2);
			}
			
			int result = 1000000000;
			for(int a = 0; a < (1 << l); a++)
			{
				HashSet<Integer> current = new HashSet<Integer>();
				for(int b = 0; b < outlets.length; b++)
				{
					current.add(outlets[b] ^ a);
				}
				
				int c;
				for(c = 0; c < devices.length; c++)
				{
					if(!current.contains(devices[c]))
					{
						break;
					}
				}
				
				if(c == devices.length)
				{
					result = Math.min(result, Integer.bitCount(a));
				}
			}
			
			out.print("Case #" + (x + 1) + ": ");
			if(result == 1000000000)
			{
				out.println("NOT POSSIBLE");
			}
			else
			{
				out.println(result);
			}
		}
		
		out.close();
	}
}
