import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


public class P2 {

	/**
	 * @param args
	 */
	
	static int num = 0;
	
	public static void dfs(HashMap<String,ArrayList<String>> list,HashMap<String,Boolean> vis,  String cur, String root)
	{
		vis.put(cur,true);
		for(String ot : list.get(cur))
		{
			if(vis.get(ot) == null)
			{
				if(list.get(ot).size() == 2 && !list.get(ot).contains(root))
					++num;
				dfs(list,vis,ot,root);

			}

		}
	}
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int times = sc.nextInt();
		for(int i = 0; i < times; ++i)
		{
			int nodes = sc.nextInt();
			HashMap<String,ArrayList<String>> list = new HashMap<String,ArrayList<String>>();
			sc.nextLine();
			for(int j =0; j < nodes-1; ++j)
			{
				String relat[] = sc.nextLine().split(" ");
				if(list.get(relat[0]) == null)
				{
					list.put(relat[0],new ArrayList<String>());
				}
				if(list.get(relat[1]) == null)
				{
					list.put(relat[1],new ArrayList<String>());
				}
				list.get(relat[0]).add(relat[1]);
				list.get(relat[1]).add(relat[0]);
			}
			ArrayList<String> possibleNodes = new ArrayList<String>();
			for(String  s: list.keySet())
			{
				if(list.get(s).size() == 2)
					possibleNodes.add(s);
			}
			
			// construct tree rooted at each s, choose min removals to get complete tree
			int value = Integer.MAX_VALUE;
			for(String s : possibleNodes)
			{
				num = 0;
				dfs(list, new HashMap<String,Boolean>(),s,s);
				if(num < value)
					value = num;
			}
			if(value == Integer.MAX_VALUE)
				value = 1;
			System.out.println("Case #" + (i+1) + ": " +value);
		}
	}

}
