import static java.lang.StringBuffer.*; //Of Utmost Importance and Indisputable Gravity.
import static java.lang.Math.*;
import java.math.*;
import java.util.*;
import java.io.*;

public class Charging {
	public static void main(String args[]) throws IOException {
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("charging.out")); 
		
		int times = sc.nextInt();
		sc.nextLine();
		o: for(int time = 1;time <= times;time++)
		{
			out.print("Case #" + time + ": ");
			
			int N = sc.nextInt();
			int L = sc.nextInt();
			
			int[] swaps = new int[L]; //0 = don't swap, 1 = swap, 2 = maybe swap
			String[] iniFlows = new String[N];
			String[] reqFlows = new String[N];
			
			for(int x = 0;x < N;x++)
				iniFlows[x] = sc.next();
			for(int x = 0;x < N;x++)
				reqFlows[x] = sc.next();
			
			for(int i = 0;i < L;i++) //Counts up # of 0's at each index, compares ini vs req
			{
				int ini0 = 0;
				int req0 = 0;
				for(int x = 0;x < N;x++)
				{
					if(iniFlows[x].charAt(i) == '0')
						ini0++;
					if(reqFlows[x].charAt(i) == '0')
						req0++;
				}
				if(ini0 + req0 == N && ini0 == req0) //Maybe need swap, mirror or not
					swaps[i] = 2;
				else if(ini0 + req0 == N) //Not mirror but swap makes sense
					swaps[i] = 1;
				else if(ini0 + req0 != N && ini0 == req0) //Don't need to swap
					swaps[i] = 0;
				else { //Don't add up no matter what
					out.println("NOT POSSIBLE");
					continue o;
				}
			}
			
			int count = 0;
			for(int i = 0;i < L;i++)
			{
				if(swaps[i] == 1)
				{
					count++;
					for(int x = 0;x < N;x++)
					{
						char rep = (iniFlows[x].charAt(i) == '1') ? '0' : '1';
						iniFlows[x] = iniFlows[x].substring(0,i) + rep + iniFlows[x].substring(i+1);
					}
				}
			}
			
			ArrayList<Integer> indexes = new ArrayList<Integer>(); //And then there was brute force =/
			for(int i = 0;i < L;i++)
			{
				if(swaps[i] == 2)
					indexes.add(i);
					
			}
			String oldState = Integer.toBinaryString(0);
			while(oldState.length() < indexes.size())
				oldState = "0" + oldState;
			
			for(int i = 0;i < pow(2,indexes.size());i++)
			{
				String newState = Integer.toBinaryString(i);
				while(newState.length() < indexes.size())
					newState = "0" + newState;
				for(int x = 0;x < indexes.size();x++)
				{
					if(oldState.charAt(x) != newState.charAt(x))
						for(int y = 0;y < N;y++)
						{
							char rep = (iniFlows[y].charAt(indexes.get(x)) == '1') ? '0' : '1';
							iniFlows[y] = iniFlows[y].substring(0,indexes.get(x)) + rep + iniFlows[y].substring(indexes.get(x)+1);
						}
				}
				if(solved(iniFlows,reqFlows,N))
				{
					for(int x = 0;x < indexes.size();x++)
						if(newState.charAt(x) == '1')
							count++;
					break;
				}
				oldState = newState;
			}
			
			out.println(count);
		}
		
		sc.close();
		out.close();
	}
	public static boolean solved(String[] iniFlows, String[] reqFlows, int N)
	{
		boolean[] taken = new boolean[N];
		Arrays.fill(taken,false);
		for(int x = 0;x < N;x++)
		{
			boolean worked = false;
		
			for(int y = 0;y < N;y++)
			{
				if(taken[y])
					continue;
				if(iniFlows[x].equals(reqFlows[y]))
				{
					worked = true;
					taken[y] = true;
					break;
				}
			}
			if(!worked)
				return false;
		}
		return true;
	}
}
