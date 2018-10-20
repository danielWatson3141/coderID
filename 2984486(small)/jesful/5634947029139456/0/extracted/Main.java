import java.util.HashMap;
import java.util.Scanner;

public class Main
{
	int N,L;

	Scanner scan=new Scanner(System.in);
	
	String[] source;
	String[] dest;

	void init()
	{
		N=scan.nextInt();
		L=scan.nextInt();
		source=new String[N];
		dest=new String[N];
		for (int i=0;i<N;i++)
		{
			source[i]=scan.next();
		}
		for (int i=0;i<N;i++)
		{
			dest[i]=scan.next();
		}
	}
	
	int check(int p,int q)
	{
		boolean[] flip=new boolean[L];
		for (int i=0;i<L;i++)
		{
			flip[i]=source[p].charAt(i)!=dest[q].charAt(i);
		}
		HashMap<String,Integer> map=new HashMap<String,Integer>();
		for (int i=0;i<N;i++)
		{
			StringBuilder sb=new StringBuilder();
			for (int j=0;j<L;j++)
			{
				if (flip[j])
				{
					sb.append(source[i].charAt(j)=='1'?'0':'1');
				}
				else
				{
					sb.append(source[i].charAt(j));
				}
			}
			if (map.containsKey(sb.toString()))
			{
				map.put(sb.toString(), map.get(sb.toString())+1);
			}
			else
			{
				map.put(sb.toString(), 1);
			}
		}
		
		HashMap<String,Integer> nmap=new HashMap<String,Integer>();
		for (int i=0;i<N;i++)
		{
			if (nmap.containsKey(dest[i]))
			{
				nmap.put(dest[i], nmap.get(dest[i])+1);
			}
			else
			{
				nmap.put(dest[i], 1);
			}
		}
		for (String s : nmap.keySet())
		{
			if (!map.containsKey(s)) return -1;
			if (map.get(s)!=nmap.get(s))
				return -1;
		}
		
		int cnt=0;
		for (int i=0;i<L;i++)
		{
			if (flip[i]==true)
				cnt++;
		}
		return cnt;
	}
	
	void work()
	{
		int ans=0x7FFFFFFF;
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++)
			{
				int res=check(i,j);
				if (res==-1)
					continue;
				ans=Math.min(ans,res);
			}
		}
		if (ans==0x7FFFFFFF)
			System.out.println("NOT POSSIBLE");
		else
			System.out.println(ans);
	}
	
	void run()
	{
		int T=scan.nextInt();
		for (int i=1;i<=T;i++)
		{
			init();
			System.out.print("Case #"+i+": ");
			work();
		}
	}
	
	public static void main(String[] args)
	{
		new Main().run();
	}
}
