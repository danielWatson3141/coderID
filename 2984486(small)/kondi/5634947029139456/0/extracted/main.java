package round_1a;

import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class main {

	public static void main(String[] args) throws Exception {


		Scanner sc = new Scanner(new File("in.txt"));
		FileWriter out = new FileWriter(new File("out.txt"));
		int T = new Integer(sc.nextLine());
		for(int i = 1 ; i < T+1 ; i++)
		{
			int res = 999999;
			int N  = sc.nextInt();
			int L = sc.nextInt();
			String [] outlet = new String[N];
			String [] device = new String[N];
			for(int j = 0 ; j <N ; j++)
			{
				outlet[j] = sc.next();
				
			}
			for(int j = 0 ; j <N ; j++)
			{
				device[j] = sc.next();				
			}
			
			for(int j = 0 ; j < N ; j++)
			{
				for(int h = 0 ; h < N ; h++)
				{
					int cost = 0;
					boolean found = true;
					boolean [] change = new boolean[L];
					for(int z = 0 ; z < L ; z++)
					{
						 
						change [z] = (outlet[j].charAt(z) != device[h].charAt(z)); 
						 if(change[z])
							 cost++;
					}
					String [] newoutlet = new String[N];
					for(int k = 0 ; k < N ; k++)
					{
						newoutlet[k] = "";
						for(int x = 0 ;x < L ; x++)
							newoutlet[k] += change[x] ? outlet[k].charAt(x) == '1'?'0':'1' : outlet[k].charAt(x);
					}
					
					List<String>  outl=   Arrays.asList(newoutlet);
					
					for(int k = 0 ; k < N ; k++)
					{
						 if(!outl.contains(device[k]))
							 found = false;
					}
					if(found)
					{
						if(cost<res)
							res = cost;
					}
				}
			}
			String ret = res+"";
			if(res == 999999)
				ret = "NOT POSSIBLE";
			System.out.println("Case #"+i+": "+ret);
			out.write("Case #"+i+": "+ret+"\n");
			try{ sc.nextLine();}
			catch(Exception e){}

		}
		out.flush();
		sc.close();
		out.close();
	}
	
}
