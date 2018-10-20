import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;


public class B {
	static ArrayList<Integer> AL[];
	static int[] depth;
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("B.in"));
		PrintWriter out = new PrintWriter(new File("B.out"));
		int T = sc.nextInt();
		for(int t=1;t<=T;t++){
			int N = sc.nextInt();
			AL = new ArrayList[N];
			for(int a=0;a<N;a++)AL[a]=new ArrayList<Integer>();
			for(int a=1;a<N;a++){
				int s =sc.nextInt()-1;
				int e = sc.nextInt()-1;
				AL[s].add(e);
				AL[e].add(s);
			}
			long best = Long.MAX_VALUE;
			for(int root = 0;root<N;root++){
				depth = new int[N];
				Arrays.fill(depth,-1);
				depth[root]=0;
				LinkedList<Integer> LL = new LinkedList<Integer>();
				LL.add(root);
				LL.add(0);
				while(!LL.isEmpty()){
					int cur = LL.poll();
					int d = LL.poll();
					for(Integer x : AL[cur]){
						if(depth[x]==-1){
							depth[x]=d+1;
							LL.add(x);
							LL.add(d+1);
						}
					}
				}
				best = Math.min(best,N-DP(root));
			}
			out.printf("Case #%d: %d%n",t,best);
		}
		out.close();
		
		
	}

	private static long DP(int root) {
		long best = 1;
		PriorityQueue<Long> PQ = new PriorityQueue<Long>();
		for(Integer x : AL[root]){
			if(depth[x]==depth[root]+1){
				PQ.add(DP(x));
			}
		}
		while(PQ.size()>2){
			PQ.poll();
		}
		if(PQ.size()==1)PQ.poll();
		while(!PQ.isEmpty())best+=PQ.poll();
		return best;
	}
}
