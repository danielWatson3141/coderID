import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class ChargingChaos 
{

	public static void main(String[] args) throws IOException 
	{
		Scanner in = new Scanner(new FileReader("A-small-attempt0.in"));
		
		File file = new File("chaossmall.out");
		PrintWriter ou = new PrintWriter(new FileWriter(file));
		
		int numCases = in.nextInt();
		
		
		
		for(int caseIndex=1; caseIndex<=numCases; caseIndex++)
		{
			int N = in.nextInt();  // number of items
			int L = in.nextInt(); // length of string
		
		
			long[] devices = new long[N];
			long[] outlets = new long[N];
			
			for(int i=0; i<N; i++)
			{
				devices[i] = Long.parseLong(in.next(), 2);
			}
			
			for(int i=0; i<N; i++)
			{
				outlets[i] = Long.parseLong(in.next(), 2);
				
			}
			
			//sort them so that comparing later is faster
			Arrays.sort(devices);
			
			int minSwaps = 100;
			for(int i=0; i<N; i++)
			{//make each outlet match a device
				//do this by determining the mask which needs to be applied, applying it to all then seeing if this is a valid soln. 
				long[] out = outlets.clone();
				
				//match outlet i to device 0
				long mask = out[i] ^ devices[0];
				
				//apply mask to all the outlets
				for(int j=0; j<N; j++)
				{
					out[j] = out[j] ^ mask;
				}
				
				Arrays.sort(out);
				
				//now check to see if the arrays out and devices are equivalent.  If so, this is a valid mask
				boolean valid = true;
				for(int j=0; j<N; j++)
				{
					if (out[j] != devices[j])
					{
						valid = false;
						break;
					}
				}
				
				//count the number of swaps this one took
				if (valid)
				{
					//determine number of swaps in that mask.  Each one is represented by a 1
					int numSwaps  = 0;
					while(mask !=0)
					{
						if (mask%2 == 1)
							numSwaps++;
						mask /=2;
					}
					minSwaps = Math.min(minSwaps, numSwaps);
					
				}
				
			}
			if (minSwaps != 100)
				ou.println("Case #" + caseIndex + ": " + minSwaps);
			else
				ou.println("Case #" + caseIndex + ": NOT POSSIBLE");
			
		}
		ou.close();
	}
}
