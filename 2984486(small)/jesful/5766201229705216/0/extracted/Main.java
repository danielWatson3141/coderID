import java.util.ArrayList;
import java.util.Scanner;

public class Main
{
	Scanner scan=new Scanner(System.in);
	
	int[] dp;
	int[] size;
	boolean[] vis;
	
	int N;
	ArrayList<Integer>[] list=new ArrayList[1010];
	
	void init()
	{
		N=scan.nextInt();
		dp=new int[N+10];
		size=new int[N+10];
		vis=new boolean[N+10];
		for (int i=1;i<=N;i++)
		{
			list[i]=new ArrayList<Integer>();
		}
		for (int i=0;i<N-1;i++)
		{
			int p=scan.nextInt();
			int q=scan.nextInt();
			list[p].add(q);
			list[q].add(p);
		}
	}
	
	int Size(int root,int p)
	{
		if (size[root]!=0) return size[root];
		size[root]=1;
		for (int i : list[root])
		{
			if (i==p)
				continue;
			size[root]+=Size(i,root);
		}
		return size[root];
	}
	
	int DP(int root,int p)
	{
		if (dp[root]!=-1) return dp[root];
		// case 1 : no child
		int c1=0;
		int cnt=0;
		for (int i : list[root])
		{
			if (i==p)
				continue;
			c1+=size[i];
			cnt++;
		}
		if (cnt<2)
		{
			dp[root]=c1;
		}
		else
		{
			dp[root]=c1;
			int min1=0x7FFFFFFF,min2=0x7FFFFFFF;
			for (int i : list[root])
			{
				if (i==p)
					continue;
				if (min1>DP(i,root)-size[i])
				{
					min2=min1;
					min1=DP(i,root)-size[i];
				}
				else if (min1==DP(i,root)-size[i])
				{
					if (min2>DP(i,root)-size[i])
						min2=DP(i,root)-size[i];
				}
				else if (min2>DP(i,root)-size[i])
				{
					min2=DP(i,root)-size[i];
				}
			}
			dp[root]=Math.min(dp[root],c1+min1+min2);
		}
		return dp[root];
	}
	
	void work()
	{
		int ans=0x7FFFFFFF;
		for (int i=1;i<=N;i++)
		{
			for (int j=1;j<=N;j++)
			{
				dp[j]=-1;
				size[j]=0;
				vis[j]=false;
			}
			Size(i,0);
			ans=Math.min(ans, DP(i,0));
		}
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
