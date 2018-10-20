import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;


public class C {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("C.in"));
		PrintWriter out = new PrintWriter(new File("C.out"));
		int T = sc.nextInt();
		int G =0 ;
		int B=0;
		PriorityQueue<Long> caps = new PriorityQueue<Long>();
		for(int t=1;t<=T;t++){
			int N = sc.nextInt();
			int[] array = new int[N];
			for(int a=0;a<N;a++)array[a]=sc.nextInt();
			long dist = 0;
			for(int a=0;a<N;a++)
				dist+=Math.abs(array[a]-a);
			long cap = (327982);
			boolean flag = dist>=cap;
			if(flag)G++;
			else B++;
			caps.add(dist);
			out.printf("Case #%d: %s%n",t,flag?"GOOD":"BAD");
		}
		System.out.println(G+" "+B);
		for(int a=0;a<T/2;a++)caps.poll();
		System.out.println(caps.poll());
		out.close();
		
		
	}
}
