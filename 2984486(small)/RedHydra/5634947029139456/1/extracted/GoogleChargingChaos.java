import java.util.*;
import java.io.*;

public class GoogleChargingChaos
{
	public static void main(String[] args) throws Exception
	{
		Scanner infile = new Scanner(new File("chaos.in"));
		PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter("chaos.out")));
		int iterations = infile.nextInt();
		for(int loop = 1; loop <= iterations; loop++)
		{
			int outlet = infile.nextInt();
			int length = infile.nextInt();
			
			ArrayList<String> outlets = new ArrayList<String>(outlet);
			for(int thing = 0; thing < outlet; thing++)
				outlets.add(infile.next());
				
			ArrayList<String> desired = new ArrayList<String>(outlet);
			for(int thing2 = 0; thing2 < outlet; thing2++)
				desired.add(infile.next());
			
			int min = length + 1;
			for(int a = 0; a < outlet; a++)
			{
				int b = convert(desired, outlets, a);
				if(b >= 0 && b < min)
					min = b;
			}
			
			if(min == length +1)
				w.println("Case #" + loop + ": NOT POSSIBLE");
			else
				w.println("Case #" + loop + ": " +  min);
		}
		w.close();
	}
	public static int convert(ArrayList<String> targeted, ArrayList<String> outlets, int index)
	{
		String changing = outlets.get(index);
		String target = targeted.get(0);
		int b = 0;
		
		ArrayList<String> poutlets = new ArrayList<String>();
		ArrayList<String> ptargeted = new ArrayList<String>();
		for(int a = 0; a < outlets.size(); a++)
		{
			poutlets.add(outlets.get(a));
			ptargeted.add(targeted.get(a));
		}
		for(int a = 0; a < target.length(); a++)
		{
			if(changing.charAt(a) != target.charAt(a))
			{
				poutlets = pull(poutlets, a);
				b++;
			}
		}
		
		if(check(poutlets, ptargeted))
			return b;
		else
			return -1;
	}
	private static boolean check(ArrayList<String> outlets, ArrayList<String> target)
	{
		for(int a = 0; a < outlets.size(); a++)
		{
			Iterator<String> i = target.iterator();
			while(i.hasNext())
			{
				String s = i.next();
				if(s.equals(outlets.get(a)))
				{
					i.remove();
					break;
				}
			}
		}
		if(target.size() == 0)
			return true;
		return false;
	}
	public static ArrayList<String> pull(ArrayList<String> outlets, int index)
	{
		ArrayList<String> outlets2 = new ArrayList<String>();
		for(int a = 0; a < outlets.size(); a++)
		{
			String s = outlets.get(a);
			char c = 'x';
			if(s.charAt(index) == '0')
				c = '1';
			else
				c = '0';
			String t = s.substring(0, index) + c + s.substring(index + 1, s.length());
			outlets2.add(t);
		}
		return outlets2;
	}			
}
			