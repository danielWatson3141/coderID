import java.util.Arrays;
import java.util.Scanner;


public class cc {
	
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		int t= in.nextInt();
		
		for (int z = 1; z <= t; z++)
		{
			int n = in.nextInt();
			int l = in.nextInt();
			int[] num = new int[n];
			int[] out = new int[n];
			for (int i = 0; i < n; i++)
				num[i] = in.nextInt(2);
			for (int i = 0; i < n; i++)
				out[i] = in.nextInt(2);
			Arrays.sort(out);
			
			int best = Integer.MAX_VALUE;
			out: for (int mask = 0; mask < (1 << l); mask++)
			{
				int[] temp = new int[n];
				for (int i = 0; i < n; i++)
				{
					temp[i] = num[i];
					for (int j = 0; j < l; j++)
						if ((mask & (1 << j)) != 0)
							temp[i] ^= (1 << j);
				}
				Arrays.sort(temp);
				for (int i = 0; i < n; i++)
					if (temp[i] != out[i])
						continue out;
				best = Math.min(Integer.bitCount(mask), best);
			}
			
			System.out.println("Case #" + z + ": " + (best == Integer.MAX_VALUE ? "NOT POSSIBLE" : best));
		}
		
	}

}
