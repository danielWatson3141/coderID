import java.io.*;
import java.util.*;
import java.math.*;

public class C
{

	public static void main(String[] args) throws Exception
	{
    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());
		
		double pGood=1.0;

		for (int i=1; i<=T; i++)
		{		  
		  int N=Integer.parseInt(in.readLine());		  
		  String line=in.readLine();
		  String[] temp=line.split("[ ]+");
		  int[] a=new int[N];
		  for (int k=0; k<N; k++) a[k]=Integer.parseInt(temp[k]);
		  
      String ans=solve(a);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	
	public static String solve(int[] a)
	{
	   int score=0;
	   for (int i=0; i<a.length; i++) score+=Math.abs(a[i]-i);
	   
	   double mean=score*1.0/a.length;
     //System.out.println(mean);
     
     double tol=20;
     double need=a.length*1.0/3;
     if (mean>=need-tol && mean<=need+tol) return "GOOD";
     
     return "BAD";
	}
}