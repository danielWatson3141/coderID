import java.util.Random;
import java.util.Scanner;


public class C {

	static Random random = new Random();
	
	
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		//double lim = 1.6617943592639947E8 - 5271029.437988451;
		double lim = 326;
		
		int a[] = new int[1000];
		for(int t = 1 ; t <= T; t++)
		{
			int n = in.nextInt();
			for(int i =0; i<n; i++) a[i] = in.nextInt();
			
			if(entropy(a) > lim)
				System.out.println("Case #" + t + ": GOOD" );
			else
				System.out.println("Case #" + t + ": BAD" );
		}
		
	}
	public static void main_old(String[] args) {
		int n = 1000, rep = 120;
		double avgg = 0, avgb = 0;
		double ming = 1E15, maxb = 0;
		double sdg = 0, sdb = 0;
		double g[] = new double[rep], b[] = new double[rep];
		int g326 = 0, b326 = 0;
		double lim = 1.6617943592639947E8 - 5271029.437988451; //x2
		//double lim = 326;
		
		for(int i=0; i<rep; i++)
		{
			g[i] = good(n);
			b[i] = bad(n); 
			avgg += g[i]/rep;
			avgb += b[i]/rep;
			ming = Math.min(ming, g[i]);
			maxb = Math.max(maxb, b[i]);
			if(g[i] > lim) g326++;
			if(b[i] < lim) b326++;
		}
		
		for(int i=0; i<rep; i++)
		{
			sdg += (g[i] - avgg)*(g[i] - avgg)/rep;
			sdb += (b[i] - avgb)*(b[i] - avgb)/rep;
		}
		
		sdg = Math.sqrt(sdg);
		sdb = Math.sqrt(sdb);
				
		System.out.println(avgg + " " + sdg  + " " + ming + " " + g326);
		System.out.println(avgb + " " + sdb + " "+ maxb + " " + b326);

	}
	
	static double good(int n)
	{
		int a[] = new int[n];
		for(int i=0; i<n; i++) a[i] = i;
		
		for(int i=0; i<n; i++)
		{
			int r = n-1-i == 0? i : random.nextInt(n-1-i) + i;
			int x = a[r];
			a[r] = a[i];
			a[i] = x;
		}
	
		return entropy(a);
	}
	
	
	static double bad(int n)
	{
		int a[] = new int[n];
		for(int i=0; i<n; i++) a[i] = i;
		
		for(int i=0; i<n; i++)
		{
			int r = random.nextInt(n-1);
			int x = a[r];
			a[r] = a[i];
			a[i] = x;
		}
				
		return entropy(a);
	}
	
	static double entropy(int a[])
	{
		double score = 0;
		for(int i=0; i<a.length; i++)
		{
			score += (double)Math.abs(a[i] - i)/a.length;
			//double x = (double)(a[i] - i); 
			//score += x*x;
		}
		return score;
	}
	
	
}
