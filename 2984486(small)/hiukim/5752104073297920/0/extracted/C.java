import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class C {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    int N = 1000;
    int TRIAL = 1000;
	int[][] good = new int[TRIAL][N];
	int[][] bad = new int[TRIAL][N];
    
    public void task() throws IOException {
    	nextInt();
    	
    	int[] A = new int[N];
    	for (int i = 0; i < N; i++) {
    		A[i] = nextInt();
    	}
    	
    	
    	int bestGood = 0;
    	int bestBad = 0;
    	for (int t = 0; t < TRIAL; t++) {
    		int goodCnt = 0;
        	int badCnt = 0;
    		for (int i = 0; i < N; i++) {
        		if (good[t][i] == A[i]) goodCnt++;
        		if (bad[t][i] == A[i]) badCnt++; 
        	}
    		bestGood = Math.max(bestGood, goodCnt);
    		bestBad = Math.max(bestBad, badCnt);
		}
    	
//    	out.println(bestGood + ", " + bestBad);
    	if (bestGood > bestBad) {
    		out.println("GOOD");
    	} else {
    		out.println("BAD");
    	}
    }
    
    public void gen() {
    	for (int t = 0; t < TRIAL; t++) {
    		Random rnd = new Random();
    		
    		for (int i = 0; i < N; i++) {
    			good[t][i] = i;
    			bad[t][i] = i;
    		}
    		
    		for (int i = 0; i < N; i++) {
    			int pos = i + rnd.nextInt(N - 1 - i + 1);
    			int temp = good[t][i];
    			good[t][i] = good[t][pos];
    			good[t][pos] = temp;
    		}
    		
    		for (int i = 0; i < N; i++) {
    			int pos = rnd.nextInt(N - 1);
    			int temp = bad[t][i];
    			bad[t][i] = bad[t][pos];
    			bad[t][pos] = temp;
    		}
    	}
    }
        
	public void solve() throws IOException {
		gen();
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
		new C().run();
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
