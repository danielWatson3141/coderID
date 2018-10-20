import java.io.*;
import java.util.Scanner;

public class C
{

	public static int[] goodPerm(int n)
	{
		int[] numbers = new int[n];

		for (int i = 0; i < n; i++)
			numbers[i] = i;

		for (int i = 0; i < n; i++)
		{
			int pos = (int) (Math.random() * (n - i) + i);
			int temp = numbers[i];
			numbers[i] = numbers[pos];
			numbers[pos] = temp;
		}
		return numbers;
	}
	
	public static int[] badPerm(int n)
	{
		int[] numbers = new int[n];

		for (int i = 0; i < n; i++)
			numbers[i] = i;

		for (int i = 0; i < n; i++)
		{
			int pos = (int) (Math.random() * n);
			int temp = numbers[i];
			numbers[i] = numbers[pos];
			numbers[pos] = temp;
		}
		return numbers;
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "C-small1";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

		int noOfCases = in.nextInt();
		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			
			int N = in.nextInt();
			int[] numbers = new int[N];
			for (int i = 0; i < N; i++)
			{
				numbers[i] = in.nextInt();
			}
			
			int lowTotal = 0;
			for (int i = 0; i < 300; i++)
			{
				lowTotal += numbers[i];
			}
			double lowAvg = lowTotal/300.0;
			int highTotal = 0;
			for (int i = 400; i < 900; i++)
			{
				highTotal += numbers[i];
			}
			double highAvg = highTotal/500.0;
			System.out.println(lowAvg + " "+ highAvg);
			boolean good = true;
			if (highAvg - lowAvg > 10)
				good = false;
//			int [] totals = new int [N];
//			int trials = 1000000;
//			for (int doIt = 0; doIt < trials; doIt++)
//			{
//		        int [] numbers = badPerm (N);
//		        for (int i = 0; i < numbers.length; i++)
//		        	totals[i]+=numbers[i];
//			}
//		
//			for (int i = 0; i < totals.length; i++)
//			{
//				double value = 1.0*totals[i]/trials;
//				if (value < 494.5)
//					System.out.printf("%5d", i);
//			}
//			System.out.println();
//			for (int i = 0; i < totals.length; i++)
//			{
//				double value = 1.0*totals[i]/trials;
//				if (value > 504.5)
//					System.out.printf("%5d", i);
//			}
//			System.out.println();
////				System.out.printf("%6.1f", 1.0*totals[i]/trials);
////			System.out.println();
////			for (int i = totals.length/2; i < totals.length; i++)
////				System.out.printf("%6.1f", 1.0*totals[i]/trials);
//			System.out.println();
		

			if (good)
			{
				System.out.println("Case #" + caseNo + ": GOOD");
				out.println("Case #" + caseNo + ": GOOD");
			}
			else
			{
				System.out.println("Case #" + caseNo + ": BAD");
				out.println("Case #" + caseNo + ": BAD");
			}

		}
		in.close();
		out.close();

	}

}
