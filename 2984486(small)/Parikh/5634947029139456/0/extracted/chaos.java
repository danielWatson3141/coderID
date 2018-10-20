import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class chaos {
	
	
	
	public static void main(String args[])throws IOException
	{
		BufferedReader obj = new BufferedReader(new FileReader("D:\\A-small-attempt0.in"));
		PrintWriter prt = new PrintWriter(new FileWriter("D:\\output.txt"));
		String line = obj.readLine();
		int t = Integer.parseInt(line);
		
		
		for (int i=1;i<=t;i++)
		{
			line = obj.readLine();
			String st[] = line.split(" ");
			System.out.print("Case #"+ i+": ");
			prt.print("Case #"+ i+": ");
			int n = Integer.parseInt(st[0]);
			int l = Integer.parseInt(st[1]);
			String s1[]= new String[n];
			String s2[]= new String[n];
			line = obj.readLine();
			 st = line.split(" ");
			for (int j=0;j<n;j++)
				{
				s1[j] =st[j];
				
				}
			line = obj.readLine();
			 st = line.split(" ");
			for (int j=0;j<n;j++)
				s2[j] =st[j];
			int ans = Integer.MAX_VALUE;
			for (int j=0;j<1<<l;j++)
			{
				StringBuilder s3[]= new StringBuilder[n];
				for (int k=0;k<n;k++)
					{
					s3[k]=new StringBuilder("");
					s3[k] =s3[k].append(s1[k]);
					//System.out.println(s3[k]);
					}
				//System.out.println(j);
				int a=0;
				int set[] = new int[l];
				int k1= j;
				int p=0,pos=0; 
				while(k1!=0)
				{
					if ((k1 & 1)==1)
						{
						
						set[p++]=pos;
						a++;
						//System.out.println(set[p-1]);
						}
					k1 = k1>>1;
			        pos++;
						
				}
				int len = l-1;
				//System.out.println(p);
				//for (int m = 0;m<p;m++)
				//System.out.println(set[m]);
				for (int m = 0;m<p;m++)
				{
					//System.out.println(set[m]);
				for (int k=0;k<n;k++)
				{
					
					//System.out.println(s3[k].charAt(set[m]))
					if (s3[k].charAt(len-set[m])=='1')
						s3[k].setCharAt(len-set[m], '0');
					else if (s3[k].charAt(len-set[m])=='0')
						 s3[k].setCharAt(len-set[m], '1');
						
				}
				}
				int arr[]= new int[n];
				int fl =0;
				//for (int k=0;k<n;k++)
				{
				//System.out.print(s3[k]+" ");
				
				}
				//System.out.println();
				for (int k=0;k<n;k++)
				{
					int c1=0;
					for (int m=0;m<n;m++)
					{
						//System.out.println(s2[k]);
						if (s2[k].equals(s3[m].toString()) )
						{
							if (arr[m]==0)
							{arr[m]=1;
							
							c1=1;
							}
							else
							{
								fl=1;
							    break;	
							}
						}
						
					}
					if (c1==0 || fl==1)
					{
						fl=1;
						break;
					}
				}
				if (fl==1)
					continue;
				else
				{
					if (a<ans)
						ans =a;
				}
			}
			if (ans==Integer.MAX_VALUE)
			System.out.println("NOT POSSIBLE");
			else
				System.out.println(ans);
			
		}
		
	}

}
