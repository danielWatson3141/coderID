import java.util.Arrays;
import java.util.Scanner;


public class afast {
	
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		
		int t = in.nextInt();
		for (int z = 1; z <= t; z++)
		{
			int n = in.nextInt();
			int l = in.nextInt();
			long[] a = new long[n];
			long[] b = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = in.nextLong(2);
			for (int i = 0; i < n; i++)
				b[i] = in.nextLong(2);
			
			Arrays.sort(b);
			
			int ret = Integer.MAX_VALUE;
			long[] temp = new long[n];
			for (int i = 0; i < n; i++)
			{
				out: for (int j = 0; j < n; j++)
				{
					long mask = 0;
					for (int k = 0; k < l; k++) 
						if (((a[i] >> k) & 1l) != ((b[j] >> k) & 1l))
							mask |= 1l << k;
					for (int k = 0; k < n; k++)
					{
						temp[k] = a[k];
						for (int o = 0; o < l; o++)
							if ((mask & (1l << o)) != 0)
								temp[k] ^= 1l << o;
					}
					
					Arrays.sort(temp);
					for (int k = 0; k < n; k++)
						if (temp[k] != b[k])
							continue out;
					ret = Math.min(ret, Long.bitCount(mask));
				}
			}
			
			System.out.println("Case #" + z + ": " + (ret == Integer.MAX_VALUE ? "NOT POSSIBLE" : ret));
		}
		
	}

}
