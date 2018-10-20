import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class A
{
	
	static int leastSwitches;
	static int [] leastTally;
	static int[] outlets;
	static int[] devices;
	static int N;
	static int L;
	public static void flipSwitch( int swtch)
	{
		for (int i = 0; i <outlets.length; i++)
			outlets[i] ^= (1 << swtch);
	}
	
	static void solve (int lastSwitch, int noOfSwitches)
	{
		
	//	if (noOfSwitches >= leastTally[lastSwitch])
		if (match())
		{
			if (noOfSwitches < leastSwitches)
				leastSwitches = noOfSwitches;
		}
		if (lastSwitch >= L)
			return;
		
		// Flip this switch
		flipSwitch(lastSwitch);
		solve(lastSwitch + 1, noOfSwitches + 1);
		flipSwitch(lastSwitch);
		solve(lastSwitch + 1, noOfSwitches);
		
		
	}
	public static boolean match ( )
	{
		Arrays.sort(outlets);
		Arrays.sort(devices);
		for (int i = 0; i <outlets.length; i++)
			if (outlets[i] != devices[i])
				return false;
		return true;
	}
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "A-small1";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

		int noOfCases = in.nextInt();
		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			N = in.nextInt();
			L = in.nextInt();
			//int [] oBits = new int [L];
			//int [] dBits = new int [L];
			 outlets = new int[N];
			devices = new int[N];
			for (int i = 0; i < N; i++)
			{
				String bits = in.next();
			//	for (int j = 0; j < bits.length(); j++)
			//		oBits[j] += bits.charAt(j) - '0';
				outlets[i] = Integer.parseInt(bits, 2);
			}
			for (int i = 0; i < N; i++)
			{
				String bits = in.next();
			//	for (int j = 0; j < bits.length(); j++)
			//		dBits[j] += bits.charAt(j) - '0';
				devices[i] = Integer.parseInt(bits, 2);
			}
			
			leastSwitches = Integer.MAX_VALUE;
			leastTally = new int [L + 1];
			for (int i = 0; i < leastTally.length; i++)
				leastTally[i] = Integer.MAX_VALUE /2;
			solve (0, 0);
			
			
//			for (int j = 0; j < L; j++)
//				System.out.printf("%3d", oBits[j]);
//			System.out.println();
//			for (int j = 0; j < L; j++)
//				System.out.printf("%3d", dBits[j]);
//			System.out.println();
//			
//			int [] flip = new int [L];
//			boolean possible = true;
//			for (int i = 0; i < L && possible; i++)
//			{
//				 int diff = Math.abs(oBits[i]- dBits[i]);
//				 if (diff == 0)
//					 flip [i] = 0;
//				 else if (N-oBits[i]== dBits[i] )
//					 flip [i] = 1;
//				 else
//					 possible = false;
//			}
//			
//			for (int j = 0; j < L; j++)
//				System.out.printf("%3d", flip[j]);
//			System.out.println();
//			
//			// Flip the switches
//			int switches = 0;
//			if (possible)
//			{
//				
//				for (int i = 0; i < L; i++)
//				{
//					if (flip[i] == 1)
//					{
//					    flipSwitch(outlets, L -i-1);
//					    switches++;
//					}
//				}
//			}
//				
//	
//			if (!match(outlets, devices))
//				possible = false;
//			
			
		

			if (leastSwitches < Integer.MAX_VALUE)
			{
				System.out.printf("Case #%d: %d%n", caseNo, leastSwitches);
				out.printf("Case #%d: %d%n", caseNo, leastSwitches);
			}
			else
			{
				System.out.printf("Case #%d: NOT POSSIBLE%n", caseNo);
				out.printf("Case #%d: NOT POSSIBLE%n", caseNo);
			}

		}
		in.close();
		out.close();

	}

}
