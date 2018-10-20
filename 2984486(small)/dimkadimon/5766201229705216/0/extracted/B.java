import java.io.*;
import java.util.*;
import java.math.*;

public class B
{

	public static void main(String[] args) throws Exception
	{
    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());
		

		for (int i=1; i<=T; i++)
		{
		  int N=Integer.parseInt(in.readLine());
		  boolean[][] adj=new boolean[N][N];
		  for (int k=0; k<N-1; k++)
		  {
		    String line=in.readLine();
		    String[] temp=line.split("[ ]+");
		    int a1=Integer.parseInt(temp[0])-1;
		    int a2=Integer.parseInt(temp[1])-1;		    
		    adj[a1][a2]=true;
		    adj[a2][a1]=true;
		  }      		    

      String ans=solve(N,adj);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	
	
	public static String solve(int N, boolean[][] adj)
	{
    int[] degree=new int[N];
	 
	 
	 
	 for (int i=0; i<N; i++)
	   for (int k=i+1; k<N; k++)
	     if (adj[i][k])
	     {
	       degree[i]++;
	       degree[k]++;
	     }
	     
	 int[] count=new int[5];
	 for (int i=0; i<N; i++)
	 {
	   if (degree[i]>3) count[4]++;
	   else count[degree[i]]++;
	 }
	 
	 //print(count);
	 
	 int ans=0;
	 
	 if (count[2]==0)
	 {
	   ans++;
	   count[2]=1;
	   count[3]--;
	 }
	 
	 ans+=Math.abs(count[2]-1);
   ans+=Math.abs(count[1]-count[3]-2);

	 return ""+ans;
  }
  
	public static void print(int[] a)
	{
	 for (int i=0; i<a.length; i++) System.out.print(a[i]+" ");
	 System.out.println();
  }  
}