import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Round1B
{
	int n;
	boolean [][] e;
	boolean [] was;
	int [] count;
	
	private int rec(int i)
	{
		was[i] = true;
		
		int c = 0;
		int [] f = new int[n];
		Arrays.fill(f, -1);
		for(int j=0;j<n;j++)
		{
			if(e[i][j] && !was[j])
			{
				c++;
				f[j] = rec(j);
				count[i] += count[j];
			}
		}
		
		count[i]++;
		
		int sum = 0;
		for(int j=0;j<n;j++)
			if(f[j] != -1)
			{
				sum += count[j];
			}
		
		if(c < 2)
			return sum;
		
		int min1 = -1, min2 = -1;
		for(int j=0;j<n;j++)
		{
			if(f[j] != -1)
			{
				int cur = f[j] - count[j];
				if(min1 == -1 || cur < f[min1] - count[min1])
				{
					if(min2 == -1 || f[min1] - count[min1] < f[min2] - count[min2])
					{
						min2 = min1;
					}
					min1 = j;
				}
				else if(min2 == -1 || cur < f[min2] - count[min2])
				{
					min2 = j;
				}
			}
		}
		int sum2 = 0;
		for(int j=0;j<n;j++)
			if(f[j] != -1)
			{
				if(j == min1 || j == min2)
					sum2 += f[j];
				else
					sum2 += count[j];
			}
		return Math.min(sum, sum2);
	}

	public void run()throws IOException
	{
		Scanner in = new Scanner(new File("b.in"));
		PrintWriter out = new PrintWriter("b.out");
		int nt = in.nextInt();
		for(int it = 1;it <= nt; it++)
		{
			System.err.println("test " + it);
			n = in.nextInt();
			e = new boolean[n][n];
			for(int i=0;i<n - 1;i++)
			{
				int p = in.nextInt() - 1, q = in.nextInt() - 1;
				e[p][q] = e[q][p] = true;
			}
			
			int ret = Integer.MAX_VALUE;
			for(int i=0;i<n;i++)
			{
				was = new boolean[n];
				Arrays.fill(was, false);
				
				count = new int[n];
				Arrays.fill(count, 0);
				
				int cur = rec(i);
				if(cur < ret)
					ret = cur;
			}
			out.println("Case #" + it + ": " + ret);
		}
		out.close();
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args)throws IOException
	{
		new Round1B().run();
	}

}
