import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class B {
	
	public static int dfs(int prev, int node, ArrayList<HashSet<Integer>> adj_list, int[][] kill){
		final int out_edge = adj_list.get(node).size() - (prev == -1 ? 0 : 1);

		if(out_edge == 0){
			return 0;
		}else if(out_edge == 1){
			for(int next : adj_list.get(node)){
				if(next == prev){
					continue;
				}
				
				return kill[node][next] + 1;
			}
		}
		
		int sum = 0;
		for(int next : adj_list.get(node)){
			if(prev == next){
				continue;
			}
			
			final int cost = kill[node][next] + 1;
			sum += cost;
		}
		
		int  min_cost = Integer.MAX_VALUE;
		for(int fst : adj_list.get(node)){
			if(fst == prev){
				continue;
			}
			final int f_kills = kill[node][fst] + 1;
			final int f_costs = dfs(node, fst, adj_list, kill);
			
			for(int snd : adj_list.get(node)){
				if(snd == prev){
					continue;
				}else if(snd == fst){
					continue;
				}
				
				final int s_kills = kill[node][snd] + 1;
				final int s_costs = dfs(node, snd, adj_list, kill);
				
				min_cost = Math.min(min_cost, sum - f_kills - s_kills + f_costs + s_costs);
			}
		}
			
		
		//System.out.println(">>" + node + " " + min_cost);
		
		return min_cost;
	}
	
	public static int pre_dfs(int prev, int node, ArrayList<HashSet<Integer>> adj_list, int[][] kill){
		if(prev != -1 && kill[prev][node] >= 0){
			return kill[prev][node];
		}
		
		final int out_edges = adj_list.get(node).size() - (prev == -1 ? 0 : 1);
		if(out_edges == 0){
			if(prev == -1){
				return 0;
			}else{
				return kill[prev][node] = 0;
			}
		}
		
		int sum = 0;
		for(int next : adj_list.get(node)){
			if(prev == next){
				continue;
			}
			
			sum += pre_dfs(node, next, adj_list, kill) + 1;
		}
		
		if(prev == -1){
			return sum;
		}else{
			return kill[prev][node] = sum;
		}
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		final int T = sc.nextInt();
		
		for(int tc = 0; tc < T; tc++){
			final int tc_index = tc + 1;
			
			final int N = sc.nextInt();
			
			ArrayList<HashSet<Integer>> adj_list = new ArrayList<HashSet<Integer>>();
			for(int i = 0; i < N; i++){
				adj_list.add(new HashSet<Integer>());
			}
			
			for(int i = 0; i < N - 1; i++){
				final int x = sc.nextInt() - 1;
				final int y = sc.nextInt() - 1;
				
				adj_list.get(x).add(y);
				adj_list.get(y).add(x);
			}
			
			int[][] kill = new int[N][N];
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					kill[i][j] = -1;
				}
			}
			
			for(int start_node = 0; start_node < N; start_node++){
				pre_dfs(-1, start_node, adj_list, kill);
			}
			
			int min = -1;
			for(int start_node = 0; start_node < N; start_node++){
				
				final int ret = dfs(-1, start_node, adj_list, kill);
				if(ret < 0){
					continue;
				}
				//System.out.println(start_node + " : " + ret);
				min = Math.min(min < 0 ? Integer.MAX_VALUE : min, ret);
			}
			
			System.out.println("Case #" + tc_index + ": " + min);
		}
	}
	
}
