import java.util.Scanner;
import java.io.*;

public class CodeJam {
	
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("in.txt"));
		PrintStream out = new PrintStream(new File("out.txt"));
		int t=in.nextInt();
		for(int q=1;q<=t;q++)
		{
			out.print("Case #"+q+": ");
			int n=in.nextInt();
			int[][] M=new int[n][n];
			for(int i=0;i<n-1;i++)
			{
				int x=in.nextInt();
				int y=in.nextInt();
				x--;
				y--;
				M[x][y]=1;
				M[y][x]=1;
			}
			int ans=n+1;
			for(int i=0;i<n;i++)
			{
				int[] visit=new int[n];
				visit[i]=1;
				traverse(n,M,visit,i);
				int re=check(n,M,visit,i);
				if(re<ans)
					ans=re;
			}
			out.println(ans);
		}
		in.close();
		out.close();
	}
	
	public static void traverse(int n,int[][] M,int[] visit,int x)
	{
		for(int i=0;i<n;i++)
			if(visit[i]==0 && M[i][x]==1)
			{
				visit[i]=visit[x]+1;
				traverse(n,M,visit,i);
			}
	}
	
	public static int check(int n,int[][] M,int[] visit,int x)
	{
		int c=0;
		for(int i=0;i<n;i++)
			if(visit[i]==visit[x]+1 && M[i][x]==1)
				c++;
		if(c==0)
			return 0;
		if(c==1)
		{
			for(int i=0;i<n;i++)
				if(visit[i]==visit[x]+1 && M[i][x]==1)
					return allChildOf(n,M,visit,x);
		}
		int max=0,maxmax=0;
		for(int i=0;i<n;i++)
			if(visit[i]==visit[x]+1 && M[i][x]==1)
			{
				int k=allChildOf(n,M,visit,i)-check(n,M,visit,i);
				if(k>=maxmax)
				{
					max=maxmax;
					maxmax=k;
				}
				else if(k>max)
					max=k;
			}
		return allChildOf(n,M,visit,x)-maxmax-max-2;
	}
	
	public static int allChildOf(int n,int[][] M,int[] visit,int x)
	{
		int c=0;
		for(int i=0;i<n;i++)
			if(visit[i]==visit[x]+1 && M[i][x]==1)
				c+=allChildOf(n,M,visit,i)+1;
		return c;
	}
}
