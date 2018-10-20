import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class A2 {

	public static int N,L;
	public static ArrayList<Integer>[] list;
	
	public static void main(String[] args) throws IOException {
		//	Scanner scanner = new Scanner(new File("sample.txt"));
		
		Scanner scanner = new Scanner(new File("B-small-attempt1.in"));
	//	Scanner scanner = new Scanner(new File("B-large.in"));
		int T = scanner.nextInt();
		PrintWriter writer = new PrintWriter(new File("C:/Documents and Settings/USER/デスクトップ/pleiades-e4.3-ultimate-32bit-jre_20140321/workspace/Test/out.txt"));
		for(int i=1;i<=T;i++)
		{
			N = scanner.nextInt();
			list = new ArrayList[N+1];
			for(int j=1;j<=N;j++)
				list[j]=new ArrayList<Integer>();
			
			for(int j=0;j<N-1;j++)
			{
				int x = scanner.nextInt();
				int y = scanner.nextInt();

				list[x].add(y);
				list[y].add(x);
			}

			int ans = solve();
			System.out.println("Case #"+i+": "+ans);
			writer.println("Case #"+i+": "+ans);
		}
		writer.close();
	}

	public static int solve()
	{
		if(N==2)
			return 1;
		
		int only2 = -1;
		for(int j=1;j<=N;j++)
		{
			if(list[j].size()==2)
			{
				if(only2==-1)
					only2 = j;
				else
				{
					only2=-1;
					break;
				}
			}
			else if(!(list[j].size()==1 || list[j].size()==3))
			{
				only2=-1;
				break;
			}
		}
		if(only2!=-1)
			return 0;
		
		int min = Integer.MAX_VALUE;
		for(int j=1;j<=N;j++)
		{
		//	System.out.println(j);
			if(list[j].size()<2)
				continue;
			
			int c=0;
			if(list[j].size()==2)
			{
				for(int i=0;i<list[j].size();i++)
				{
					int ch = check(list[j].get(i), j);
				//	System.out.println("@"+list[j].get(i)+" "+ch);
					c += ch;
				}
				if(min>c)
					min=c;
			}
			
			if(list[j].size()>2)
			{
				for(int i=0;i<list[j].size();i++)
				{
					int ch = check(list[j].get(i), j);
			//		System.out.println("&"+list[j].get(i)+" "+ch);
					c += ch;
				}
				
				if(min>c)
					min=c;
			}
			
	//		System.out.println(c);
	//		System.out.println();
		}

		return min;
	}
	
	public static int check(int target, int from)
	{
		if(list[target].size()==1)
			return 0;
		
		if(list[target].size()==3)
		{
			int c = 0;
			for(int i=0;i<list[target].size();i++)
			{
				if(list[target].get(i)==from)
					continue;
				else
					c += check(list[target].get(i), target);
			}
			return c;
		}
		
		if(list[target].size()==2)
		{
			if(list[target].get(0)==from)
				return count(list[target].get(1), target);
			else
				return count(list[target].get(0), target);
		}
		
	//	System.out.println("---"+target);
		int[] num = new int[list[target].size()];
		int ccc = 0;
		for(int i=0;i<list[target].size();i++)
		{
			if(list[target].get(i)==from)
				num[i] = -1;
			else
			{
				int ch = check(list[target].get(i), target);
			//	System.out.println("="+list[target].get(i)+" "+ch);
				num[i] = ch;
				ccc += ch;
			}
				
		}
		int sum = list[target].size()-3;
		Arrays.sort(num);
		int cnt=0;
		for(int i=0;i<sum;i++)
			cnt+=num[i];
		ccc += sum;
		return ccc;
	}
	
	public static int count(int target, int from)
	{
		if(list[target].size()==1)
			return 1;
		
		int c = 1;
		for(int i=0;i<list[target].size();i++)
		{
			if(list[target].get(i)==from)
				continue;
			else
				c += count(list[target].get(i), target);
		}
	//	System.out.println(target+" "+from+" "+c);
		return c;
	}
}
