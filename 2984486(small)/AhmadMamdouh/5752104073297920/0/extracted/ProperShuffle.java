import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;



public class ProperShuffle {
	static String problem = "C";

	public static void main(String[] args) throws Exception {
//		InputReader r = new InputReader(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		 InputReader r = new InputReader(new FileReader(problem +
		 ".in"));
		 PrintWriter out = new PrintWriter(new FileWriter(problem +
		 "Solution.out"));
		int T = r.nextInt();
		int test = 1;
		Random rand = new Random();
		while (T-- > 0) {
			int n = r.nextInt();
			int[] arr = new int[n];
			for (int i = 0; i < arr.length; i++) {
				arr[i] = r.nextInt();
			}
			int maxSim  = 0;
			for(int i=0;i<1000;i++){
				int[] seq = new int[1000];
				for (int j = 0; j < seq.length; j++) {
					seq[j]  = j;
				}
				for(int j=0;j<n;j++){
					int x = j + rand.nextInt(n - j);
					int temp = seq[j];
					seq[j] = seq[x];
					seq[x] = temp;
				}
				int similar = 0;
				for (int j = 0; j < seq.length; j++) {
					if(seq[j]==arr[j])
						similar++;
				}
				maxSim = Math.max(maxSim, similar);
			}
			int maxSim2 = 0;
			for(int i=0;i<1000;i++){
				int[] seq = new int[1000];
				for (int j = 0; j < seq.length; j++) {
					seq[j]  = j;
				}
				for(int j=0;j<n;j++){
					int x = rand.nextInt(n);
					int temp = seq[j];
					seq[j] = seq[x];
					seq[x] = temp;
				}
				int similar = 0;
				for (int j = 0; j < seq.length; j++) {
					if(seq[j]==arr[j])
						similar++;
				}
				maxSim2 = Math.max(maxSim2, similar);
			}
			out.printf("Case #%d: %s\n", test++,maxSim>maxSim2?"GOOD":"BAD");
		}
		out.close();
	}

	static class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public InputReader(FileReader stream) {
			reader = new BufferedReader(stream);
			tokenizer = null;
		}

		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
