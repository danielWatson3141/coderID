import java.util.Random;
import java.util.Scanner;

public class Main
{
	Scanner scan=new Scanner(System.in);
	
	int N;
	
	void run()
	{
		int threshold=245000;
		int[] a=new int[1010];
		int T=scan.nextInt();
		for (int i=1;i<=T;i++)
		{
			System.out.print("Case #"+i+": ");
			N=scan.nextInt();
			for (int j=0;j<N;j++)
				a[j]=scan.nextInt();
			int cnt=0;
			for (int j=0;j<N;j++)
			{
				for (int k=j+1;k<N;k++)
				{
					if (a[k]<a[j])
						cnt++;
				}
			}
			if (cnt<threshold)
				System.out.println("BAD");
			else
				System.out.println("GOOD");
		}
	}
	
	public static void main(String[] args)
	{
		new Main().run();
	}
}
