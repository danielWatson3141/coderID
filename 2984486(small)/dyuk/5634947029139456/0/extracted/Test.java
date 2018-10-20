import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Test {
	public static void main(String[] args) {
		try {
			InputStream inputStream = new FileInputStream(
					"D:\\codeforse\\CF\\input.txt");
			OutputStream outputStream = new FileOutputStream(
					"D:\\codeforse\\CF\\output.txt");
			// InputStream inputStream = System.in;
			// OutputStream outputStream = System.out;
			InputReader in = new InputReader(inputStream);
			PrintWriter out = new PrintWriter(outputStream);
			C solver = new C();
			int t = in.nextInt();
			for (int i = 1; i <= t; i++) {
				solver.solve(i, in, out);
			}
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

class C {

	public void solve(int testNumber, InputReader in, PrintWriter out) {
		out.print("Case #"+testNumber+": ");
		
		int n = in.nextInt();
		int k = in.nextInt();
		
		long[] a = new long[n];
		long[] b = new long[n];
		for (int i = 0; i < n; i++){
			a[i] = Long.parseLong(in.nextString(), 2);
		}
		HashMap<Long,Long> m = new HashMap<Long,Long>();
		
		long t = 0;
		long tmp = 0;
		
		ArrayList<Long> ans = new ArrayList<Long>();
		for (int i = 0; i < n; i++){
			b[i] = Long.parseLong(in.nextString(), 2);
			for (int j = 0; j < n; j++){
				t = b[i]^a[j];
				if (m.get(t) != null){
					tmp = m.get(t);
					m.put(t, ++tmp);
					if (tmp == n){
						ans.add(t);
					}
					
				}else{
					m.put(t, 1L);
					if (n == 1){
						ans.add(t);
					}
				}
			}
		}
		
		String s;
		int min = 1000;
		int mint = 0;
		for (Long long1 : ans) {
			s = Long.toString(long1,2);
			int l = s.length();
			 mint = 0;
			for (int i = 0; i < l; i++){
				if (s.charAt(i)== '1'){
					mint++;
				}
			}
			min = Math.min(min, mint);
		}
		if (min == 1000){
			out.print("NOT POSSIBLE");
		}else{
			out.print(min);
		}
		//out.print(Long.toString(n,2));
		//out.print(Long.toString(n^0,2));
		
		//out.print(Integer.parseInt("11111111111111111111", 2));
		//out.print(Long.parseLong("1111111111111111111111111111111111111111", 2));
		
		out.println();
				
	}

	class Pair implements Comparable<Pair> {
		//ArrayList<Pair> p = new ArrayList<Pair>();
		//Collections.sort(p, Comparators.AGE);
		int[] b;
		int count = 0;

		LinkedList<Pair> pp;
		int bonus;

		int k;
		double r;

		public Pair(int x, int y, int k) {
			this.k = k;
			this.r = Math.sqrt(x * x + y * y);

		}

		@Override
		public int compareTo(Pair o) {
			return Comparators.AGE.compare(this, o);
		}

		public String toString() {
			return "" + r + " ";
		}

	}

	public static class Comparators {

		public static Comparator<Pair> AGE = new Comparator<Pair>() {
			@Override
			public int compare(Pair o1, Pair o2) {
				return o1.r > o2.r ? 1 : (o1.r < o2.r ? -1 : 0);
			}
		};
	}
}



class InputReader {

	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
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

	public Double nextDouble() {
		return Double.parseDouble(next());
	}

	public String nextString() {
		return next();
	}

}
