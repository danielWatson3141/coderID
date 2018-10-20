import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("A.in"));
		PrintWriter out = new PrintWriter(new File("A.out"));
		int T = sc.nextInt();
		for(int t=1;t<=T;t++){
			int N = sc.nextInt();
			int L = sc.nextInt();
			int best= Integer.MAX_VALUE;
			String ans = "NOT POSSIBLE";
			long[] wall = new long[N];
			long[] items= new long[N];
			
			for(int a=0;a<N;a++)wall[a]=Long.parseLong(sc.next(), 2);
			for(int a=0;a<N;a++)items[a]=Long.parseLong(sc.next(), 2);
			Arrays.sort(items);
			for(int mask=0;mask<1<<L;mask++){
				long[] temp = new long[N];
				for(int a=0;a<N;a++)
					temp[a]=wall[a]^mask;
				Arrays.sort(temp);
				boolean ok = true;
				for(int a=0;a<N;a++)
					if(temp[a]!=items[a])ok=false;
				if(ok)
					best = Math.min(best,Integer.bitCount(mask));
			}
			if(best!=Integer.MAX_VALUE)
				ans = best+"";
			
			out.printf("Case #%d: %s%n",t,ans);
		}
		out.close();
		
		
	}
}
