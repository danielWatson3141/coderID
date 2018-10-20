import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class B {
	static int N;
	static ArrayList<Integer> [] adj;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int kase=1;kase<=T;kase++) {
			N = in.nextInt();
			adj = new ArrayList [N];
			for(int i=0;i<N;i++)
				adj[i]=new ArrayList<Integer>();
			for(int i=0;i<N-1;i++) {
				int x = in.nextInt()-1;
				int y = in.nextInt()-1;
				adj[x].add(y);
				adj[y].add(x);
			}
			int min = Integer.MAX_VALUE;
			for(int i=0;i<N;i++) {
				int x = N-solve(i,-1);
				if(x<min)
					min=x;
			}
			System.out.println("Case #"+kase+": "+min);
		}
	}
	static int solve(int rt, int but) {
		ArrayList<Integer> vals = new ArrayList<Integer>();
		int s=1;
		for(int i=0;i<adj[rt].size();i++) {
			if(adj[rt].get(i)==but)
				continue;
			int x = solve(adj[rt].get(i),rt);
			vals.add(x);
		}
		if(vals.size()==0) {
			return 1;
		}
		if(vals.size()==1)
			return 1;
		else {
			int [] valt = new int[vals.size()];
			for(int i=0;i<vals.size();i++)
				valt[i]=vals.get(i);
			Arrays.sort(valt);
			return valt[vals.size()-1]+valt[vals.size()-2]+1;
		}
	}
}