import java.util.Arrays;
import java.util.Scanner;
import java.io.*;

public class Test {
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("in.txt"));
		PrintStream out = new PrintStream(new File("out.txt"));
		int z = in.nextInt();
		for(int t=1;t<=z;t++)
		{
			int n = in.nextInt();
			int l = in.nextInt();
			int[][] a = new int[n][l];
			String[] b = new String[n];
			int min = 99;
			for(int i=0;i<n;i++)
			{
				String s = in.next();
				for(int j=0;j<l;j++)
					a[i][j] = Integer.parseInt(s.substring(j,j+1));
			}
			for(int i=0;i<n;i++)
				b[i] = in.next();
			Arrays.sort(b);
			for(int k=0;k<Math.pow(2,l);k++)
			{
				int[] flip = func(k,l);
				//for(int i=0;i<l;i++) System.out.print(flip[i]); System.out.println();
				int[][] c = new int[n][l];
				for(int i=0;i<n;i++)
					for(int j=0;j<l;j++)
						if(flip[j]==1) c[i][j] = (a[i][j]+1)%2;
						else c[i][j] = a[i][j];
				String[] d = new String[n];
				for(int i=0;i<n;i++)
				{
					d[i]="";
					for(int j=0;j<l;j++)
						d[i]+=c[i][j];
				}
				Arrays.sort(d);	
				int p;
				for(p=0;p<n;p++)
					if(!(b[p].equals(d[p]))) break;
				if(p==n)
				{
					int count=0;
					for(int i=0;i<l;i++)
						if(flip[i]==1) count++;
					if(min>count) min=count;
				}
			}
			out.print("Case #"+t+": ");
			if(min!=99) out.println(min);
			else out.println("NOT POSSIBLE");
		}
		in.close();
		out.close();
	}
	public static int[] func(int x,int l)
	{
		int[] out = new int[l];
		for(int i=0;i<l;i++)
		{
			if(x>=Math.pow(2,l-i-1))
			{
				out[i] = 1;
				x-=(int)Math.pow(2,l-i-1);
			}
			else out[i]=0;
		}
		return out;
	}
}
