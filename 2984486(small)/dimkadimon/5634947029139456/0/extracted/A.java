import java.io.*;
import java.util.*;
import java.math.*;

public class A
{

	public static void main(String[] args) throws Exception
	{
    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());
		

		for (int i=1; i<=T; i++)
		{
		  String line=in.readLine();
		  String[] temp=line.split("[ ]+");
		  int N=Integer.parseInt(temp[0]);
		  int L=Integer.parseInt(temp[1]);
		  line=in.readLine();
		  temp=line.split("[ ]+");
		  boolean[][] start=new boolean[N][L];
		  for (int m=0; m<N; m++)
		    for (int k=0; k<L; k++)
		      start[m][k]=(temp[m].charAt(k)=='1');
		  line=in.readLine();
		  temp=line.split("[ ]+");
		  boolean[][] end=new boolean[N][L];
		  for (int m=0; m<N; m++)
		    for (int k=0; k<L; k++)
		      end[m][k]=(temp[m].charAt(k)=='1');	      		    

      String ans=solve(N,L,start,end);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	

	public static String solve(int N, int L, boolean[][] start, boolean[][] end)
  {
    int[] ind=new int[N];
    for (int i=0; i<N; i++) ind[i]=i;
    
    int min=Integer.MAX_VALUE;
 
loop:    
    do
    {
      int[] diff=new int[L];    
      for (int i=0; i<N; i++)
        for (int k=0; k<L; k++)
          if (start[i][k]!=end[ind[i]][k]) diff[k]++;
          
      int count=0;
      for (int k=0; k<L; k++)
      {
        if (diff[k]>0)
        {
          count++;
          if (diff[k]!=N) continue loop;
        }
      }
      
      min=Math.min(min,count);
    }
    while(nextPermutation(ind));
    
    if (min==Integer.MAX_VALUE) return "NOT POSSIBLE";
    
    return ""+min;
  }
  
  
	//elements in a have to be sorted in ascending order	//changes the elements to achieve the next permutation	//returns false if there are no more permutations	public static boolean nextPermutation(int[] a)	{		int N=a.length;		int i=N-2;		for (; i>=0; i--)			if (a[i]<a[i+1])				break;		if (i<0) return false;				for (int j=N-1; j>=i; j--)		{			if (a[j]>a[i])			{				int temp=a[i];				a[i]=a[j];				a[j]=temp;				break;					}		}		for (int j=i+1; j<(N+i+1)/2; j++)		//reverse from a[i+1] to a[N-1]		{			int temp=a[j];			a[j]=a[N+i-j];			a[N+i-j]=temp;		}		return true;	}  
}