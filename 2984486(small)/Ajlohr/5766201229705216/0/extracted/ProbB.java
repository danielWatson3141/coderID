package round1;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class ProbB {
public static void main(String[] args)
{
	Scanner sc = new Scanner(System.in);
	int numcases = sc.nextInt();
	for(int curcase = 1 ; curcase <=numcases;curcase++)
	{
		int N = sc.nextInt();
		List<Set<Integer>> graph = new ArrayList<Set<Integer>>();
		for(int i=0;i<N;i++)
		{
			graph.add(new HashSet<Integer>());
		}
		for(int i=0;i<N-1;i++)
		{
			int v1 = sc.nextInt();
			int v2 = sc.nextInt();
			graph.get(v1-1).add(v2-1);
				graph.get(v2-1).add(v1-1);
		}
		int maxdepth = 0;
		for(int i=0;i<N;i++)
		{
			curroot = i;
			if(maxfullsize(graph,i,i)>maxdepth)
				{

				//System.out.println("!!"+i);
				maxdepth = maxfullsize(graph,i,i);
				}
				
		}
		//System.out.println(maxdepth);
		
		System.out.println("Case #"+curcase+": "+(N- maxdepth));
	}
}
public static int curroot;
public static int maxfullsize(List<Set<Integer>> graph, int curvert,int comingfrom)
{
	int sum = 1;
	/*if((curvert!=curroot)&&(graph.get(curvert).size()!=3))
		return 1;
	if((curvert==curroot)&&(graph.get(curvert).size()!=2))
		return 1;*/
	int maxone = 0;
	int maxtwo = 0;
	for(Integer I : graph.get(curvert))
	{
		if((I==curroot)||(I==comingfrom))
			continue;
		int s =maxfullsize(graph,I,curvert);
		if(s>maxtwo)
		{
			if(s>maxone)
			{
			maxtwo = maxone;
			maxone = s;
			}
			else
			maxtwo = s;
		}
	}
	if(maxtwo ==0)
		return 1;
	else
		return 1+maxone+maxtwo;
}
}
