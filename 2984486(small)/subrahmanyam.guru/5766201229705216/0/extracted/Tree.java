package codejam.a1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Tree {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("c://codejam//a1//binary//B-small-attempt0 (1).in"));
		PrintWriter out = new PrintWriter(new File("c://codejam//a1//binary//out.txt"));
		long T = sc.nextLong();
		for(long i=1;i<=T;i++)
		{
			long N = sc.nextLong();
			HashMap<Integer,ArrayList> tree = new HashMap<Integer,ArrayList>();
			for(int j=1;j<=N;j++)
			{
				tree.put(j, new ArrayList());
			}
			for(int j=0;j<N-1;j++)
			{
				int n1 = sc.nextInt();
				int n2 = sc.nextInt();
				tree.get(n1).add(n2);
				tree.get(n2).add(n1);
				
			}
			int min = 2000;
			for(int j=1;j<=N;j++)
			{
				int nubm = j;
				int del = calwithnum(j,tree,true,0);
				min = Math.min(del, min);
			}
			
				out.println("Case #"+i+": "+min);
			
			
		}
		out.close();
	}

	private static int calwithnum(int j, HashMap tree, boolean b, int i) {
		if(b)
		{
			ArrayList l = (ArrayList) tree.get(j);
			if(l.size()-i == 0)
			{
				return 0;
			}
			else if(l.size()-i == 1)
			{
				return calwithnum((Integer) l.get(0),tree,false, 1);
			}
			else if(l.size()-i == 2)
			{
				return calwithnum((Integer) l.get(0),tree,true,1) + calwithnum((Integer) l.get(1),tree,true,1);
			}
			else
			{
				return 2000;
			}
		}
		else
		{
			ArrayList l = (ArrayList) tree.get(j);
			if(l.size()-i == 0)
				return 1;
			else
				return 1 + calwithnum((Integer) l.get(0),tree,false,1);
		}
		
	}

}
