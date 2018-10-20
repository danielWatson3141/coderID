import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class B {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    int INF = 1000000;
    int N;
    ArrayList<Integer>[] ns;
    public void task() throws IOException {
    	N = nextInt();
    	ns = new ArrayList[N];
    	for (int i = 0; i < N; i++) {
    		ns[i] = new ArrayList<Integer>();
    	}
    	for (int i = 0; i < N - 1; i++) {
    		int v1 = nextInt() - 1;
    		int v2 = nextInt() - 1;
    		ns[v1].add(v2);
    		ns[v2].add(v1);    				
    	}
    	
    	int ans = INF;
    	for (int i = 0; i < N; i++) {
    		if (ns[i].size() < 2) {
    			ans = Math.min(ans, N-1);
    			continue;
    		}
    		
    		int[] needBT = new int[N];
    		dfs(i, new boolean[N], needBT, new int[N]);    		
    		ans = Math.min(ans, needBT[i]);    		
    		
    	}    	
    	
    	out.println(ans);
    }
    
    public void dfs(int cur, boolean[] visited, int[] needBT, int[] childCnt) {
    	visited[cur] = true;
    	
    	ArrayList<Integer> directChilds = new ArrayList<Integer>();
    	for (int v: ns[cur]) {
    		if (!visited[v]) {
    			directChilds.add(v);
    		}
    	}
    	
    	for (int v: directChilds) {    
    		dfs(v, visited, needBT, childCnt);    		
    		childCnt[cur] += childCnt[v];
    	}
    	childCnt[cur] += directChilds.size();
    	
    	if (directChilds.size() == 0) {    		
    		needBT[cur] = 0;
    		childCnt[cur] = 0;
    		
//    		out.println("root: " + (cur+1) + ": " + needBT[cur] + ", " + childCnt[cur]);
    		
    		return;
    	}
    	
//    	out.println(cur + ": " + directChilds.size());
    	
//    	for (int v: directChilds) {
//    		out.println("child: " + (v+1));
//    	}
    	
    	needBT[cur] = childCnt[cur];
		for (int i = 0; i < directChilds.size(); i++) {
			int v1 = directChilds.get(i);
			if (needBT[v1] == INF) continue;
			
			for (int j = i+1; j < directChilds.size(); j++) {
				int v2 = directChilds.get(j);
				if (needBT[v2] == INF) continue;
				
				int bt = childCnt[cur] - childCnt[v1] - childCnt[v2] - 2 + needBT[v1] + needBT[v2];				
				needBT[cur] = Math.min(needBT[cur], bt);
				
//				out.println((cur+1) + ": " + bt + ", " + childCnt[cur] + ", " + childCnt[v1] + ", " + childCnt[v2] + ", " + needBT[v1] + ", " + needBT[v2]);
//				out.println(v1 + " and " + v2);
				
			}
		}    	
		
//		out.println("root: " + (cur+1) + ": " + needBT[cur] + ", " + childCnt[cur]);
    }
        
	public void solve() throws IOException {
		int T = nextInt();
		for(int t = 1; t <= T; t++){
			out.print("Case #" + (t) + ": ");
			task();
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new B().run();
	}
	
	public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            out = new PrintWriter(System.out);
            solve();
            reader.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

}
