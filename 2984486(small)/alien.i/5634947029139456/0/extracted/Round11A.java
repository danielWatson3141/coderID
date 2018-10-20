import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Round11A
{
	

	public void run()throws IOException
	{
		Scanner in = new Scanner(new File("a.in"));
		PrintWriter out = new PrintWriter("a.out");
		int nt = in.nextInt();
		for(int it = 1;it <= nt; it++)
		{
			int n = in.nextInt(), l = in.nextInt();
			in.nextLine();
			int [] a = new int[n];
			int [] b = new int[n];
			
			StringTokenizer st = new StringTokenizer(in.nextLine());
			for(int i=0;i<n;i++)
				a[i] = Integer.parseInt(st.nextToken(), 2);
			
			st = new StringTokenizer(in.nextLine());
			for(int i=0;i<n;i++)
				b[i] = Integer.parseInt(st.nextToken(), 2);
			
			int ret = Integer.MAX_VALUE;
			
			for(int mask=0;mask< (1 << l);mask++)
			{
				int [] c = new int[n];
				for(int i=0;i<n;i++)
				{
					int cur = a[i];
					for(int j=0;j<l;j++)
						if((mask & (1 << j)) > 0)
							cur = cur ^ (1 << j);
					c[i] = cur;
				}
				
				boolean ok = true;
				for(int i=0;i<n;i++)
				{
					boolean find = false;
					for(int j=0;j<n;j++)
						if(b[i] == c[j])
						{
							find = true;
							break;
						}
					ok = ok && find;
				}
				
				if(ok && ret > Integer.bitCount(mask))
					ret = Integer.bitCount(mask);
			}
			
			out.println("Case #" + it + ": " + (ret == Integer.MAX_VALUE ? "NOT POSSIBLE" : ret));
		}
		out.close();
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args)throws IOException
	{
		new Round11A().run();
	}

}
