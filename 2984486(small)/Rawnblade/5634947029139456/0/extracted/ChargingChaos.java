import java.util.*;

public class ChargingChaos{
	static int[] device;
	static int N,L,MIN;
	public static void main(String[] args){
		Scanner reader = new Scanner(System.in);
		int times = reader.nextInt();
		int t = 1;
		while(times --> 0){
			MIN = (int)1e9;
			int n = N = reader.nextInt();
			int l = L = reader.nextInt();
			device = new int[n];
			int[] val = new int[n];
			for(int i = 0; i < n; i++)
				val[i] = Integer.parseInt(reader.next(), 2);
			for(int i = 0; i < n; i++)
				device[i] = Integer.parseInt(reader.next(), 2);
			f(0,0,val);
			if(MIN == (int)1e9)
				System.out.println("Case #"+t+++": NOT POSSIBLE");
			else
				System.out.println("Case #"+t+++": "+MIN);
		}
	}
	
	static int[][] g;
	static int src,sink,size;
	static boolean[] v;
	public static int flow(){
		v = new boolean[size];
		int sum = 0;
		while(sum < (sum = sum + dfs(src)))
			Arrays.fill(v,false);
		return sum;
	}
	
	public static int dfs(int s){
		if(s == sink) return 1;
		if(v[s]) return 0;
		v[s] = true;
		for(int i = 0; i < size; i++)
			if(g[s][i] > 0 && dfs(i) > 0){
				g[s][i]--;
				g[i][s]++;
				return 1;
			}
		return 0;
	}
	
	public static void f(int n, int m, int[] val){
		if(n == L){
			size = 2*N+2;
			src = size-2;
			sink = size-1;
			g = new int[size][size];
			for(int i = 0; i < N; i++){
				g[src][i] = 1;
				g[N+i][sink] = 1;
				for(int j = 0; j < N; j++)
					if(val[i] == device[j])
						g[i][N+j] = 1;
			}
			if(flow() == N)
				MIN = Math.min(MIN, m);
			return;
		}
		
		//don't flip
		f(n+1,m,val);
		//do flip
		for(int i = 0; i < N; i++)
			val[i] ^= (1<<n);
		f(n+1,m+1,val);
		for(int i = 0; i < N; i++)
			val[i] ^= (1<<n);
	}
}
