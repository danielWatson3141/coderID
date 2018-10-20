import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;


public class A1 {

	public static int N,L;
	public static boolean[][] device;
	public static boolean[][] elc;
	
	public static void main(String[] args) throws IOException {
	//	Scanner scanner = new Scanner(new File("sample.txt"));
		//	Scanner scanner = new Scanner(new File("A-small-attempt0.in"));
		Scanner scanner = new Scanner(new File("A-large.in"));
		int T = scanner.nextInt();
		PrintWriter writer = new PrintWriter(new File("C:/Documents and Settings/USER/デスクトップ/pleiades-e4.3-ultimate-32bit-jre_20140321/workspace/Test/out.txt"));
		for(int i=1;i<=T;i++)
		{
			N = scanner.nextInt();
			L = scanner.nextInt();
			device = new boolean[N][L];
			elc = new boolean[N][L];

			for(int j=0;j<N;j++)
			{
				String s = scanner.next();
				for(int k=0;k<L;k++)
				{
					if(s.charAt(k)=='0')
						device[j][k]=false;
					else
						device[j][k]=true;
				}
			}
			
			for(int j=0;j<N;j++)
			{
				String s = scanner.next();
				for(int k=0;k<L;k++)
				{
					if(s.charAt(k)=='0')
						elc[j][k]=false;
					else
						elc[j][k]=true;
				}
			}

			int ans = solve();
			String anss;
			
			if(ans==Integer.MAX_VALUE)
				anss = "NOT POSSIBLE";
			else
				anss = ""+ans;
			System.out.println("Case #"+i+": "+anss);
			writer.println("Case #"+i+": "+anss);
		}
		writer.close();
	}

	public static int solve()
	{
		boolean[][][] result = new boolean[N][N][L];
		
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				for(int k=0;k<L;k++)
				{
					if(elc[i][k]==device[j][k])
						result[i][j][k]=true;
				}
			}
		}
		
		int min = Integer.MAX_VALUE;
		
		
		for(int i=0;i<N;i++)
		{
			HashSet<Integer> set = new HashSet<Integer>();
			boolean match2 = true;
			for(int j=1;j<N;j++)
			{
				boolean match3 = false;
				for(int h=0;h<N;h++)
				{
					boolean match = true;
					for(int k=0;k<L;k++)
					{
						if(result[0][i][k]!=result[j][h][k])
						{
							match = false;
							break;
						}
					}
					if(match)
					{
						match3 = true;
						set.add(h);
						break;
					}
				}
				
				if(!match3)
				{
					match2=false;
					break;
				}
			}
			
			if(match2)
			{
				set.add(i);
				
				if(set.size()==N)
				{
					int c=0;
					for(int k=0;k<L;k++)
						if(!result[0][i][k])
							c++;
					
					if(min>c)
						min = c;
				}
			}
		}
		
		return min;
	}
}
