import java.util.*;

public class chargeSmall
{
	static Scanner scan;
	static String out;
	static int T,N,L; 
	static int[] outlet, device, f;
	
	static int bitCount(int a)
	{
		int c=0;
		
		for(int i=0; (1<<i)<=a; i++)
			if((a&(1<<i))>0)
				c++;
		return c;
	}
	public static void main(String[] args)
	{
		scan= new Scanner(System.in);
		T= scan.nextInt();
		
		for(int t=1; t<=T; t++)
		{			
			N= scan.nextInt();
			L= scan.nextInt();
			outlet= new int[N];
			device = new int[N];
			f = new int[1<<L];
			
			for(int i=0; i<N; i++)
				outlet[i]= Integer.parseInt(scan.next(),2);
			
			for(int i=0; i<N; i++)
				device[i]= Integer.parseInt(scan.next(),2);
			
			int mask=0;
			boolean yes=false;
			out= "NOT POSSIBLE";
			int min= Integer.MAX_VALUE;
			for(; mask< (1<<L) && !yes; mask++)
			{
				yes= true;
				Arrays.fill(f,0);
				for(int i=0; i<N; i++)
					f[outlet[i]^mask]++;

				for(int i=0; i<N && yes; i++)
				{
					yes= f[device[i]]>0;
					f[device[i]]--;
				}
					
				if(yes)
				{
					min= Math.min(min,bitCount(mask));
	//				System.out.println(mask +" "+bitCount(7));
					out= min+"";
				}
			}
			
			System.out.println("Case #"+t+": "+out);
		}
	}
}