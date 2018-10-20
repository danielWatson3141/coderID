import java.util.*;
import java.io.*;
public class B {
	static ArrayList<Integer> tree[];
	static int oo = 87654321;
	static int costdel[][];
	static int costbin[][];
	@SuppressWarnings("unchecked")
	public static void main(String[] args)throws IOException {
		
		//Scanner qwe = new Scanner(System.in);
		Scanner qwe = new Scanner(new File("b.in"));
		PrintWriter out = new PrintWriter("b.out");
		
		int T = qwe.nextInt();
		
		for(int cse = 1; cse <= T; cse++){
			int N = qwe.nextInt();
			tree = new ArrayList[N];
			
			for(int i =0; i < N; i++)
				tree[i] = new ArrayList<Integer>();
			
			for(int i =0; i < N-1; i++){
				int a = qwe.nextInt()-1;
				int b = qwe.nextInt()-1;
				
				tree[a].add(b);
				tree[b].add(a);
			}
			
			costdel = new int[N][N];
			for(int i =0; i < N; i++)
				Arrays.fill(costdel[i], -1);
			
			costbin = new int[N][N+1];
			for(int i =0; i < N; i++)
				Arrays.fill(costbin[i], -1);
			
			int min = Integer.MAX_VALUE;
			for(int root = 0; root < N; root++){
				min = Math.min(min, costMakeBin(root,N));
			}
			
			out.printf("Case #%d: %d\n",cse,min);
		}
		
		qwe.close();
		out.close();
	}
	
	static int costMakeBin(int node, int from){
		if(costbin[node][from] != -1) return costbin[node][from];
		
		int max = -oo;
		int smax = -oo;
		int total = 0;

		for(int to: tree[node]){
			if(to == from) continue;
			int cost = costMakeBin(to, node);
			int dc = costdelete(to,node);
			total+=dc;
			int gain = dc-cost;
			if(gain > max){
				smax = max;
				max = gain;
			}
			else if(gain > smax){
				smax = gain;
			}
		}
		
		
		return costbin[node][from] = Math.min(total, total-max-smax);
	}
	
	//includes deleting this node
	static int costdelete(int node, int from){
		if(costdel[node][from] != -1) return costdel[node][from];
		
		int sum = 1;
		for(int to: tree[node]){
			if(to == from) continue;
			sum += costdelete(to,node);
		}
		
		return costdel[node][from] = sum;
		
	}

}
