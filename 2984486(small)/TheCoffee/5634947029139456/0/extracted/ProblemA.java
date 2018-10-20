import java.io.*;
import java.math.*;
import java.util.*;

public class ProblemA
{
	public static void main(String args[])
	{
		try
		{
			BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
			
			int cases = Integer.parseInt(br.readLine());
			
			for(int j = 0; j < cases; j++)
			{
				System.out.print("Case #" + (j+1) + ": " );
				
				String s = br.readLine();
				StringTokenizer st = new StringTokenizer(s);
				
				int n = Integer.parseInt(st.nextToken());
				int l = Integer.parseInt(st.nextToken());
				
				String lineA = br.readLine();
				String lineB = br.readLine();
				
				StringTokenizer stA = new StringTokenizer(lineA);
				StringTokenizer stB = new StringTokenizer(lineB);
				
				String[] a = new String[n];
				String[] b = new String[n];
				
				for(int i = 0; i < n; i++)
				{
					a[i] = stA.nextToken();
					b[i] = stB.nextToken();
				}
				
				process(a, b, n, l);
			}
			
			//System.out.println( processString("00100", "01010") );
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
		
	}
	
	public static void process(String[] a, String[] b, int n, int l)
	{
		int times = (int)Math.pow(2.0, (double)l);
		
		Set<String> aa = new HashSet<String>(Arrays.asList(a));
		Set<String> bb = new HashSet<String>(Arrays.asList(b));
		
		int bestAnswer = 2000000000;
		
		for(int i = 0; i < times; i++)
		{
			String timesString = giveLeadingZeroes(Integer.toBinaryString( i ), l);
			//System.out.println("timesString: " + timesString);
			
			// Process bb into cc
			Set<String> cc = new HashSet<String>();
			for(String s : bb)
			{
				cc.add(processString(s,timesString));
			}
			//System.out.println(bb.toString() + "  " + cc.toString());
				
			if(aa.equals(cc))
			{
				// sets are equal
				String timesAsBinary = Integer.toBinaryString( i );
				int numOfSwitches = 0;
				for(int j = 0; j < timesAsBinary.length(); j++)
				{
					if(timesAsBinary.charAt(j) == '1')
					{
						numOfSwitches++;
					}
				}
				
				//System.out.println("EQUAL" + numOfSwitches);
				if(numOfSwitches < bestAnswer)
				{
					bestAnswer = numOfSwitches;
				}
			}
		}
		
		//System.out.println(l + " " + timesString);
		//System.out.println(aa.toString());
		//System.out.println(bb.toString());
		
		if(bestAnswer == 2000000000)
		{
			System.out.println("NOT POSSIBLE");
		}
		else
		{
			System.out.println(bestAnswer);
		}
		
		//System.out.println("----");
	}
	
	public static String processString(String a, String b)
	{
		 int aa = Integer.parseInt(a, 2);
		 int bb = Integer.parseInt(b, 2);
		 
		 int cc = aa^bb;
		 
		 return giveLeadingZeroes(Integer.toBinaryString(cc), a.length());
	}
	
	public static String giveLeadingZeroes(String a, int l)
	{
		StringBuffer outputBuffer = new StringBuffer();
		
		for (int i = 0; i < l-a.length(); i++)
		{
		   outputBuffer.append("0");
		}
		
		return outputBuffer.toString()+a;
	}
}
