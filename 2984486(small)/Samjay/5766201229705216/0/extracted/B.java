package con2014R1a;

import java.io.*;
import java.util.*;

public class B {
	
//	private static final String islarge = "-large";
	private static final String fileName = "results/con2014R1a/"+B.class.getSimpleName().toLowerCase();//+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	@SuppressWarnings("unchecked")
	private void solve() {
		int N = in.nextInt();
		ArrayList<Integer>[] nbs = new ArrayList[N];
		for(int i=0;i<N;i++){
			nbs[i] = new ArrayList<Integer>();
		}
		// connect tree
		for(int i=1;i<N;i++){
			int a = in.nextInt()-1,
				b = in.nextInt()-1;
			nbs[a].add(b);
			nbs[b].add(a);
		}
		int best = N-1;
		// dfs for best
		int[]size = new int[N];
		int[]unbalanced = new int[N];
		int[]parent = new int[N];
		int[]seq = new int[N];
		for(int i=0;i<N;i++){
			// try all one by one as the root
			Stack<Integer> stack = new Stack<Integer>();
			int n = 0;
			// create rooted structure
			for(int p=0;p<N;p++)parent[p]=-1; // reset parent relation
			stack.add(i);
			while(!stack.isEmpty()){
				int cur = stack.pop();
				seq[n++]=cur;
				size[cur]=1; // reset size, each node is of size 1
				unbalanced[cur]=0; // reset
				for(int nb : nbs[cur]){
					if(nb == parent[cur])continue;
					stack.add(nb);
					parent[nb]=cur;
				}
			}
			// calculate score
			for(int id=N-1;id > 0;id--){
				int cur = seq[id];
				size[parent[cur]]+=size[cur]; // move size up to parent
				// calculate best rebalanced
				if(nbs[cur].size()==1){ // only connected to a parent => LEAF
					// ignore
				}else if(nbs[cur].size()==2){ // has one child, so the entire underlying structure has to be removed in this case
					int oth = (nbs[cur].get(0)==parent[cur]?nbs[cur].get(1):nbs[cur].get(0));
					unbalanced[cur]+=size[oth];
				}else if(nbs[cur].size() > 2){
					int maxA=0,maxB=0;
					unbalanced[cur] = size[cur]-1;
					for(int nb : nbs[cur]){
						if(nb==parent[cur])continue;
						int sub = size[nb]-unbalanced[nb];
						if(sub > maxA){
							maxB=maxA;
							maxA=sub;
						}else if(sub > maxB){
							maxB=sub;
						}
					}
					unbalanced[cur] -= (maxA+maxB); // keep the unbalanced score as low as possible
				}
			}
			{
				// redo logic for root
				int cur = i;
				if(nbs[cur].size()==0){ // only connected to a parent => LEAF
					// ignore
				}else if(nbs[cur].size()==1){ // has one child, so the entire underlying structure has to be removed in this case
					unbalanced[cur]+=size[nbs[cur].get(0)];
				}else if(nbs[cur].size() >= 2){
					int maxA=0,maxB=0;
					unbalanced[cur] = size[cur]-1;
					for(int nb : nbs[cur]){
						int sub = size[nb]-unbalanced[nb];
						if(sub > maxA){
							maxB=maxA;
							maxA=sub;
						}else if(sub > maxB){
							maxB=sub;
						}
					}
					unbalanced[cur] -= (maxA+maxB); // keep the unbalanced score as low as possible
				}
			}
			if(unbalanced[i]<best)
				best=unbalanced[i];
			if(best==0)break;
		}
		
		// print sol
		out.println(best);
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new B().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
