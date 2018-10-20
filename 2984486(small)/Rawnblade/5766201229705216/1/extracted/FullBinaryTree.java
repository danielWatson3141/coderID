import java.util.*;

public class FullBinaryTree{
	static ArrayList<Integer>[] g;
	static int[] keep,cut;
	static int N;
	public static void main(String[] args){
		Scanner reader = new Scanner(System.in);
		int times = reader.nextInt();
		for(int counter = 1; counter <= times; counter++){
			int n = N = reader.nextInt();
			ArrayList<Integer>[] gr = new ArrayList[n];
			keep = new int[n];
			cut = new int[n];
			
			for(int i = 0; i < n; i++)
				gr[i] = new ArrayList<Integer>();
			for(int i = 0; i < n-1; i++){
				int s = reader.nextInt()-1;
				int t = reader.nextInt()-1;
				gr[s].add(t);
				gr[t].add(s);
			}
			
			int min = (int)1e9;
			for(int k = 0; k < n; k++){
				g = new ArrayList[n];
				for(int i = 0; i < n; i++)
					g[i] = new ArrayList<Integer>();
				
				ArrayDeque<Integer> q = new ArrayDeque<Integer>();
				boolean[] v = new boolean[n];
				
				q.add(k);
				v[k] = true;
				while(!q.isEmpty()){
					int c = q.remove();
					for(Integer e:gr[c])
						if(!v[e]){
							g[c].add(e);
							q.add(e);
							v[e] = true;
						}
				}
				
				Arrays.fill(cut, -1);
				Arrays.fill(keep, -1);
				min = Math.min(min, keep(k));
			}
			
			System.out.println("Case #"+counter+": "+min);
		}
	}
	
	public static void update(int v, int[] max){
		if(v > max[0]){
			max[1] = max[0];
			max[0] = v;
		}else if(v > max[1]){
			max[1] = v;
		}
	}
	
	//Cost to keep branch rooted at n
	public static int keep(int n){
		if(keep[n] == -1){
			int cost = cut(n) - 1; //Cut all my kids!
			
			int[] max = {-1,-1};
			for(Integer e:g[n]){
				int costToKeep = keep(e);
				int costToCut = cut(e);
				update(costToCut - costToKeep, max);
			}
			
			if(max[0] >= 0 && max[1] >= 0)
				cost -= max[0] + max[1];
			
			keep[n] = cost;
		}
		return keep[n];
	}
	
	//Cost to cut branch rooted at n
	public static int cut(int n){
		if(cut[n] == -1){
			int sum = 1;
			for(Integer e:g[n])
				sum += cut(e);
			cut[n] = sum;
		}
		return cut[n];
	}
}
