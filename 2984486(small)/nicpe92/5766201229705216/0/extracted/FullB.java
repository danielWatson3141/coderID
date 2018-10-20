import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;


public class FullB {
	private static ArrayList<ArrayList<Integer>> adj;
	private static int N;
	private static boolean[] vis;
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T =Integer.parseInt(in.readLine());
		for (int c = 0; c < T; c++) {
			N = Integer.parseInt(in.readLine());
			adj = new ArrayList<ArrayList<Integer>>();
			for (int i = 0; i < N; i++) {
				adj.add(new ArrayList<Integer>());
			}
			for (int i = 0; i < N-1; i++) {
				String[] s = in.readLine().split(" ");
				int X = Integer.parseInt(s[0]);
				int Y = Integer.parseInt(s[1]);
				adj.get(X-1).add(Y-1);
				adj.get(Y-1).add(X-1);
			}
			int min = 100000;
			for (int root = 0; root < N; root++) {
				vis = new boolean[N];
				int act = visit(root);
				min = Math.min(N-act, min);
			}
			System.out.println("Case #"+(c+1)+": "+min);
		}
	}

	private static int visit(int root) {
		vis[root]=true;
		ArrayList<Integer> subr = new ArrayList<Integer>();
		for (Integer hijo : adj.get(root)) {
			if(!vis[hijo])
			{
				//System.out.println(hijo);
				subr.add(visit(hijo));
			}
		}
		if(subr.size()==0)
			return 1;
		else if(subr.size()==1)
			return 1;
		else
		{
			Collections.sort(subr);
			return 1+subr.get(subr.size()-2) + subr.get(subr.size()-1);
		}
	}

}
