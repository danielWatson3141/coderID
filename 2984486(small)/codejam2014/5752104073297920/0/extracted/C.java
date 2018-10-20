import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class C {
	private static Scanner in;
	private static PrintWriter out; 
	
	private static int N;
	
	private static int size;
	private static int[] a;
	
	private static int[] dev;
	
	static void solve() 
	{
		N = in.nextInt();
		debug(new Date(), "Num tests: ", N);
		
		for(int i =0; i < N; i++)
		{
			size = in.nextInt();
			a = new int[size];
			dev = new int[size];
			
			for(int j = 0; j < size; j++)
			{
				a[j] = in.nextInt();
			}
			solveTest(i+1);
		}
		debug(new Date(), " Done Solving.");
	}
	
	static void solveTest(int test)
	{
		for(int k = 0; k < size; k++) {
			dev[k] = Math.abs(a[k] - k);
		}

		double mean = Math.sqrt(size -1);
		
		double stdv = getStdDev();
		
		double cel = mean - (stdv * 3);
		double fl = mean + (stdv * 3);
		
		System.out.println(Arrays.toString(dev));
		
		System.out.println("SDv: " + stdv);
		System.out.println("mean: " + mean);
		
		boolean good = true;
		int badcnt = 0;
		
		if(Math.abs(getMean() - mean) > stdv )
		{
			badcnt++;
		}
		
		for(int i: dev)
		{
			if(!(cel <= i && i <= fl))
			{
				badcnt++;
			}
		}
		if(badcnt == 0)
		{
			out.printf("Case #%d: %s%n", test, "GOOD");
		}
		else
		{
			out.printf("Case #%d: %s%n",test, "BAD");
		}
		
		debug(new Date(), " solved: ", test);
	}
	
	
	static double getMean()
    {
        double sum = 0.0;
        for(double d : dev)
            sum += d;
            return sum/size;
    }

	static double getVariance()
    {
        double mean = Math.sqrt(size - 1);
        double temp = 0;
        for(double d :dev)
            temp += (mean-(size / 2))*(mean-(size / 2));
            return temp/size;
    }

	static double getStdDev()
    {
        return Math.sqrt(getVariance());
    }

	static  double median() 
    {
       double[] b = new double[dev.length];
       System.arraycopy(dev, 0, b, 0, b.length);
       Arrays.sort(b);

       if (dev.length % 2 == 0) 
       {
          return (b[(b.length / 2) - 1] + b[b.length / 2]) / 2.0;
       } 
       else 
       {
          return b[b.length / 2];
       }
    }
    
	
	
	public static void main(String[] args) throws FileNotFoundException
	{
		try
		{
			in = new Scanner(new File("c:\\codejam2014\\c\\small.in"));
			out = new PrintWriter("C:\\codejam2014\\c\\small.out");
			
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
