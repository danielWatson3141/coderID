import java.util.*;
import java.io.*;
public class ALarge
{
	public static void main(String[] args) throws Exception
	{
//		Scanner in = new Scanner(System.in);
		Scanner in = new Scanner(new File("a-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("alarge.out")));
		
		int t = in.nextInt();
		for(int x = 0; x < t; x++)
		{
			int n = in.nextInt();
			int l = in.nextInt();
			
			long[] outlets = new long[n];
			for(int y = 0; y < n; y++)
			{
				outlets[y] = Long.valueOf(in.next(), 2);
			}
			
			long[] devices = new long[n];
			for(int z = 0; z < n; z++)
			{
				devices[z] = Long.valueOf(in.next(), 2);
			}
			
			HashMap<Long, Integer> edges = new HashMap<Long, Integer>();
			for(int a = 0; a < devices.length; a++)
			{
				for(int b = 0; b < outlets.length; b++)
				{
					long mask = devices[a] ^ outlets[b];
					
					if(edges.containsKey(mask))
					{
						edges.put(mask, edges.get(mask) + 1);
					}
					else
					{
						edges.put(mask, 1);
					}
				}
			}
			
			int result = Integer.MAX_VALUE;
			for(long mask : edges.keySet())
			{
				if(edges.get(mask) == n)
				{
					result = Math.min(result, Long.bitCount(mask));
				}
			}
			
			out.print("Case #" + (x + 1) + ": ");
			if(result == Integer.MAX_VALUE)
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
