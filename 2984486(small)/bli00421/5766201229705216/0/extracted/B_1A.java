import java.io.*;
import java.util.*;

public class B_1A {
	static final int INF = 1 << 30;
	static final String inFile = "B-small-attempt1.in", outFile = "output.txt";
	static ArrayList<Integer> adj[];
	
	static boolean[] used;
	
	static int size(ArrayList<Integer> s ) {
		int x = 0;
		for (int i : s) {
			if (used[i]) x++;
		} return x;
	}
	
	static boolean dfs(int v, int prev) {
		int sz = size(adj[v]);
		if (prev == -1 && sz != 0 && sz != 2) {
			//System.out.println("BAD " + sz);
			return false;
		}
		else if (prev != -1 && sz != 1 && sz != 3) {
			//System.out.println("BAD 2 " + v + " " + sz);
			return false;
		}
		
		for (int a : adj[v]) {
			if (a == prev) continue;
			if (!dfs(a, v)) {
				//System.out.println("HUH " + a);
				return false;
			}
		} return true;
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File(inFile));
		PrintWriter out = new PrintWriter(new FileWriter(outFile));
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int n = in.nextInt();
			adj = new ArrayList[n];
			for (int i = 0; i < n; i++) adj[i] = new ArrayList<Integer>();
			
			for (int i = 0; i + 1 < n; i++) {
				int x = in.nextInt() - 1, y = in.nextInt() - 1;
				adj[x].add(y);
				adj[y].add(x);
			}
			
			int min = n - 1;
			for (int i = 1; i < (1 << n); i++) {
				int count = 0;
				used = new boolean[n];
				
				for (int j = 0; j < n; j++) {
					used[j] = ((i & (1 << j)) > 0);
					if (used[j]) count++;
				}
				
				boolean found = false;
				for (int j = 0; j < n && !found; j++) {
					if (!used[j]) continue;
					if (dfs(j, -1)) found = true;
				}
				/*
				if (i + 1 == (1 << n)) {
					System.out.println("DFS");
					//dfs(0, -1);
				}*/
				
				
				if (found) min = Math.min(min, n - count);
			}
			
			out.println("Case #" + t + ": " + min);
		}
		
		out.close();
	}
}
