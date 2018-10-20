import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class A {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    int INF = 1000000;
    int answer;
        
    int N;
    int L;
    String[] targets;
    String[] sources;
    public void task() throws IOException {
    	N = nextInt();
    	L = nextInt();
    	targets = reader.readLine().split(" "); 
    	sources = reader.readLine().split(" ");
    	answer = INF;
    	go(targets, sources, 0, 0);    	
    	
    	if (answer == INF) {
    		out.println("NOT POSSIBLE");
    	} else {
    		out.println(answer);
    	}
    	
    }
    
    public void go(String[] targets, String[] sources, int pos, int flip) {
    	next: for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (targets[i].substring(0, pos).equals(sources[j].substring(0, pos))) {
					continue next;
				}
			}
			return;
		}
    	
    	if (pos == targets[0].length()) {
    		answer = Math.min(answer, flip);
    		return;
    	}
    	
    	int target1 = 0;
    	int source1 = 0;
		for (int i = 0; i < N; i++) {
			if (targets[i].charAt(pos) == '1') target1++;
			if (sources[i].charAt(pos) == '1') source1++;
		}
		if (target1 == source1) {
			go(targets, sources, pos+1, flip);
		}
		if (target1 == targets.length - source1) {
			String[] newSources = new String[N];
			for (int i = 0; i < N; i++) {
				StringBuilder sb = new StringBuilder();
				for (int j = 0; j < L; j++) {
					if (j == pos) {
						sb.append(sources[i].charAt(pos) == '1'? '0': '1');
					} else {
						sb.append(sources[i].charAt(j));
					}
				}
				newSources[i] = sb.toString(); 
			}
			go(targets, newSources, pos+1, flip+1);
		}		
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
		new A().run();
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
