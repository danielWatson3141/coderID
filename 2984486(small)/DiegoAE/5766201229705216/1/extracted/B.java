import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class B {
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens())
				tk=new StringTokenizer(br.readLine());
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	static int N;
	
	static class Node{
		int id;
		LinkedList<Integer> v;
		public Node(int idd){
			id = idd;
			v = new LinkedList<Integer>();
		}
	}
	
	static class Pair implements Comparable<Pair>{
		int costo;
		int reales;
		public Pair(int c, int r){
			costo = c;
			reales = r;
		}
		@Override
		public int compareTo(Pair o) {
			return reales - o.reales;
		}
	}
	
	
	static Pair dfs(int idx, int parent){
		int costo = 0;
		int reales = 0;
		ArrayList<Pair> t = new ArrayList<Pair>();
		for(int h: array[idx].v){
			if (h == parent)
				continue;
			t.add(dfs(h, idx));
		}
		if (t.size() == 0)
			return new Pair(0, 1);
		if (t.size() == 1)
			return new Pair(t.get(0).costo + t.get(0).reales, 1);
		Collections.sort(t);
		for(int i = 0; i < t.size() - 2; i++){
			Pair aux = t.get(i);
			costo += aux.costo + aux.reales;
		}
		for(int i = t.size() - 2; i < t.size(); i++){
			Pair aux = t.get(i);
			costo += aux.costo;
			reales += aux.reales;
		}
		return new Pair(costo, reales + 1);
	}
	
	static Node[] array;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++){
			N = sc.nextInt();
			array = new Node[N];
			for(int i = 0; i < N; i++)
				array[i] = new Node(i);
			for(int i = 0; i < N - 1; i++){
				int a = sc.nextInt() - 1;
				int b = sc.nextInt() - 1;
				array[a].v.add(b);
				array[b].v.add(a);
			}
			int best = Integer.MAX_VALUE;
			for(int i = 0; i < N; i++){
				Pair ans = dfs(i, -1);
				best = Math.min(best, ans.costo);
			}
			System.out.printf("Case #%d: %d\n", c, best);
		}
	}

}
