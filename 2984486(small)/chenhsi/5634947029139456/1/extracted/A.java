import java.util.*;
import java.math.*;
import java.io.*;

public class A
{
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new BufferedReader(new FileReader("A-large.in")));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-large.out")));
		
		int tt = in.nextInt();
		for (int I = 1; I <= tt; I++)
		{
			out.print("Case #" + I + ": ");
			int n = in.nextInt();
			int l = in.nextInt();
			Set<String> allOutlets = new HashSet<> ();
			for (int i = 0; i < n; i++)
				allOutlets.add(in.next());
			Set<String> allDevices = new HashSet<> ();
			for (int i = 0; i < n; i++)
				allDevices.add(in.next());
			List<Set<String>> outlets = new ArrayList<> ();
			outlets.add(allOutlets);
			List<Set<String>> devices = new ArrayList<> ();
			devices.add(allDevices);
			int result = solve(outlets, devices, l);
			if (result == -1)
				out.println("NOT POSSIBLE");
			else
				out.println(result);
		}
		out.flush();
		out.close();
	}
	
	private static int solve(List<Set<String>> outlets, List<Set<String>> devices, int iter)
	{
//		System.out.println("iter = " + iter + ":\t" + outlets + " " + devices);
		if (iter == 0)
			return 0;
		int countA0 = 0, countA1 = 0;
		int countB0 = 0, countB1 = 0;
		for (Set<String> set : outlets)
			for (String s : set)
				if (s.charAt(0) == '0')
					countA0++;
				else
					countA1++;
		for (Set<String> set : devices)
			for (String s : set)
				if (s.charAt(0) == '0')
					countB0++;
				else
					countB1++;
//		System.out.println("Counts: " + countA0 + " " + countA1 + " " + countB0 + " " + countB1);
		int best = -1;
		outer: while (countA0 == countB0 && countA1 == countB1)
		{
//			System.out.println("At iter " + iter + ", same deemed possible");
			List<Set<String>> newOutlets = new ArrayList<> ();
			List<Set<String>> newDevices = new ArrayList<> ();
			for (int i = 0; i < outlets.size(); i++)
			{
				Set<String> outlet0 = new HashSet<> ();
				Set<String> outlet1 = new HashSet<> ();
				Set<String> device0 = new HashSet<> ();
				Set<String> device1 = new HashSet<> ();
				for (String s : outlets.get(i))
					if (s.charAt(0) == '0')
						outlet0.add(s.substring(1));
					else
						outlet1.add(s.substring(1));
				for (String s : devices.get(i))
					if (s.charAt(0) == '0')
						device0.add(s.substring(1));
					else
						device1.add(s.substring(1));
//				System.out.println(outlet0 + " " + outlet1 + " " + device0 + " " + device1);
				if (outlet0.size() != device0.size() || outlet1.size() != device1.size())
					break outer;
				if (outlet0.size() != 0)
				{
					newOutlets.add(outlet0);
					newDevices.add(device0);
				}
				if (outlet1.size() != 0)
				{
					newOutlets.add(outlet1);
					newDevices.add(device1);
				}
			}
//			System.out.println("At iter " + iter + ", same still deemed possible");
			best = solve(newOutlets, newDevices, iter - 1);
			break;
		}
//		System.out.println("Point 1 of " + iter + ": " + best);
		outer: while (countA0 == countB1 && countA1 == countB0)
		{
//			System.out.println("At iter " + iter + ", change deemed possible");
			List<Set<String>> newOutlets = new ArrayList<> ();
			List<Set<String>> newDevices = new ArrayList<> ();
			for (int i = 0; i < outlets.size(); i++)
			{
				Set<String> outlet0 = new HashSet<> ();
				Set<String> outlet1 = new HashSet<> ();
				Set<String> device0 = new HashSet<> ();
				Set<String> device1 = new HashSet<> ();
				for (String s : outlets.get(i))
					if (s.charAt(0) == '1')
						outlet0.add(s.substring(1));
					else
						outlet1.add(s.substring(1));
				for (String s : devices.get(i))
					if (s.charAt(0) == '0')
						device0.add(s.substring(1));
					else
						device1.add(s.substring(1));
//				System.out.println(outlet0 + " " + outlet1 + " " + device0 + " " + device1);
				if (outlet0.size() != device0.size() || outlet1.size() != device1.size())
					break outer;
				if (outlet0.size() != 0)
				{
					newOutlets.add(outlet0);
					newDevices.add(device0);
				}
				if (outlet1.size() != 0)
				{
					newOutlets.add(outlet1);
					newDevices.add(device1);
				}
			}
//			System.out.println("At iter " + iter + ", change still deemed possible");
			int temp = solve(newOutlets, newDevices, iter - 1);
			if (temp != -1)
				temp++;
			if (temp == -1 || best == -1)
				best = Math.max(temp, best);
			else
				best = Math.min(best, temp);
			break;
		}
//		System.out.println("Point 2 of " + iter + ": " + best);
		return best;
	}
}
