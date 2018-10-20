import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class A2 {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("A.in"));
		PrintWriter out = new PrintWriter(new File("A2.out"));
		int T = sc.nextInt();
		for(int t=1;t<=T;t++){
			int N = sc.nextInt();
			int L = sc.nextInt();
			String ans = "NOT POSSIBLE";
			long[] wall = new long[N];
			long[] items= new long[N];
			int best = Integer.MAX_VALUE;
			for(int a=0;a<N;a++)wall[a]=Long.parseLong(sc.next(), 2);
			for(int a=0;a<N;a++)items[a]=Long.parseLong(sc.next(), 2);
			
			Arrays.sort(items);
			for(int b=0;b<N;b++){
				long[] temp = new long[N];
				long mask = items[0]^wall[b];
				for(int a=0;a<N;a++)
					temp[a]=wall[a]^mask;
				Arrays.sort(temp);
				boolean ok = true;
				for(int a=0;a<N;a++)
					if(temp[a]!=items[a])ok=false;
				if(ok)
					best = Math.min(best,Long.bitCount(mask));
			}
			if(best!=Integer.MAX_VALUE)
				ans = best+"";
			
			out.printf("Case #%d: %s%n",t,ans);
		}
		out.close();
		
		
	}
}
