import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;


public class P1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		sc.nextLine();
		for(int i = 0; i < cases; ++i)
		{
			sc.nextLine();
			String house[] = sc.nextLine().split(" ");
			String devices[] = sc.nextLine().split(" ");
			
			HashMap<String,ArrayList<ArrayList<Integer>>> switches = new HashMap<String,ArrayList<ArrayList<Integer>>>();
			for(String s : devices)
			{
				switches.put(s,new ArrayList<ArrayList<Integer>>());
				for(String h : house)
				{
					ArrayList<Integer> changes = new ArrayList<Integer>();

					for(int x = 0;x < s.length(); ++x)
					{
						if(s.charAt(x) != h.charAt(x))
						{
							changes.add(x);
						}
					}
					
						switches.get(s).add(changes);
					
				}
				
			}
			HashSet<ArrayList<Integer>> set = new HashSet<ArrayList<Integer>>();
			for(ArrayList<Integer> s : switches.get(devices[0]))
			{
				set.add(s);
			}
			boolean br = false;
			for(int x = 1; x < devices.length; ++x)
			{
				boolean field = false;
				HashSet<ArrayList<Integer>> vals = new HashSet<ArrayList<Integer>>();
				for(ArrayList<Integer> al : switches.get(devices[x]))
				{
					vals.add(al);
					
	
				}
				set.retainAll(vals);
				if(set.size() == 0)
				{
					System.out.println("Case #" + (i+1) + ": NOT POSSIBLE");
					br = true;
					break;
				}
			}
			if(br)
			{
				//System.out.println("Case #" + (i+1) + ": NOT POSSIBLE");
				continue;
			}
	
			else
			{
				ArrayList<ArrayList<Integer>> holder = new ArrayList<ArrayList<Integer>>();
				for(ArrayList<Integer> x : set)
					holder.add(x);
				Collections.sort(holder,new Comparator<ArrayList<Integer>>(){
					public int compare(ArrayList<Integer> a1, ArrayList<Integer> a2)
					{
						return Integer.compare(a1.size(),a2.size());
					}
				});
				System.out.println("Case #" + (i+1) + ": " + holder.get(0).size());
			}
		}
		
		
	}

}
