import java.util.*;
import java.io.*;

public class ChargingChaos
{
	public static void main(String args[])throws IOException
	{
		Scanner sc = new Scanner(new File("CC_s.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("CC_s.out"));
		int T=sc.nextInt();
		int i,j,k,l,m,N,L,min;
		boolean flag,out;
		char sw[][];
		String dev[];
		String bin="",check[],output;
		for(i=1;i<=T;i++)
		{
			output="";
			out=false;
			N=sc.nextInt();
			L=sc.nextInt();
			min=L;
			sw=new char[N][L];
			dev=new String[N];
			for(j=0;j<N;j++)
				sw[j]=sc.next().toCharArray();
			for(j=0;j<N;j++)
				dev[j]=sc.next();
			Arrays.sort(dev);
			for(j=0;j<Math.pow(2,L);j++)
			{
				bin=Integer.toBinaryString(j);
				while(bin.length()!=L)
				bin="0"+bin;
				check=new String[N];
				flag=true;
				for(k=0;k<N;k++)
				{
					check[k]="";
					for(m=0;m<L;m++)
					{
							if(bin.charAt(m)=='1')
							check[k]+=(sw[k][m]=='1'?"0":"1");
							else
								check[k]+=sw[k][m];
					}
				}
				Arrays.sort(check);
				for(k=0;k<N;k++)
				{
					if(!check[k].equals(dev[k]))
					{
						flag=false;
						break;
					}
				}
				if(flag)
				{

					if(Integer.bitCount(j)<min)
					{
						min=Integer.bitCount(j);
						output=Integer.toString(Integer.bitCount(j));
						out=true;
					}
				}
			}
			if(!out)
				output="NOT POSSIBLE";
		pw.println("Case #"+i+": "+output);

		}
		sc.close();
		pw.close();
	}
}