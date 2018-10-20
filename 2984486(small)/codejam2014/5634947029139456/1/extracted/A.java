
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Date;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;


public class A 
{
	private static Scanner in;
	private static PrintWriter out; 
	
	private static int N;
	private static int S;
	private static int L;
	
	private static Set<Long> P;
	
	private static long[] OO;
	
	static void solve() 
	{
		N = in.nextInt();
		debug(new Date(), "Num tests: ", N);
		
		for(int i =0; i < N; i++)
		{
			debug(new Date(), "solving: ", i);
			S = in.nextInt();
			L = in.nextInt();
			
			P = new HashSet<Long>();
			
			OO = new long[S];
			long[] PP = new long[S];
			
			for(int j = 0; j < S; j++)
			{
				String str = in.next();
				OO[j] = Long.parseLong(str, 2);
			}
			
			for(int j = 0; j < S; j++)
			{
				String str = in.next();
				P.add(Long.parseLong(str, 2));
				PP[j] = Long.parseLong(str, 2);
				
			}
			
			debug(new Date(), "solving: ", i);
			
			boolean done = false;
			int fin = 9999;
			
			for(long pp : PP)
			{
				long diff = OO[0] ^ pp;
				done = true;
				for(int k = 0; k < S; k++)
				{
					long oo = OO[k] ^ diff;
					if(!P.contains(oo))
					{
						done = false;
						break;
					}
				}
				
				if(done)
				{
					done = true;
					int lfin = 0;
					String ss = Long.toString(diff, 2);
					for(char c : ss.toCharArray())
					{
						if (c == '1')
						{
							lfin++;
						}
					}
					fin = Math.min(lfin, fin);
				}
			}
			
						
			if(fin != 9999)
			{
				out.printf("Case #%d: %d%n", (i + 1), fin);
			}
			else
			{
				out.printf("Case #%d: %s%n", (i + 1), "NOT POSSIBLE");
			}
	
			
			out.flush();
		}
		debug(new Date(), " Done Solving.");
		
	}
	
	
	public static void main(String[] args) throws FileNotFoundException
	{
		try
		{
			in = new Scanner(new File("c:\\codejam2014\\a\\big.in"));
			out = new PrintWriter("C:\\codejam2014\\a\\big.out");
			
			solve();
		}
		finally
		{
			if(in != null)
				in.close();
			if(out != null)
			{
				out.flush();
				out.close();
			}
		}
		
		debug(new Date(), " Done Solving.");
		
	}
	
	private static void debug(Object... objects)
	{
		StringBuilder builder = new StringBuilder();
		for(Object o : objects)
		{
			builder.append(String.valueOf(o));
		}
		debug(builder.toString());
	}
	
	private static void debug(String str)
	{
		System.out.println(str);
	}
		
}
