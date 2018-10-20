import java.io.*;    //PrintWriter
import java.math.*;  //BigInteger, BigDecimal
import java.util.*;  //StringTokenizer, ArrayList


public class GCJ_2014_R1_A
{	
	FastReader in;
	PrintWriter out;
	
	public static void main(String[] args)  {
		new GCJ_2014_R1_A().runWithFiles();
	}
	
	void run()
	{		
		in = new FastReader(System.in);
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}
	
	void runWithFiles() {
		//in = new FastReader(new File("src/A-ex.in"));
		in = new FastReader(new File("src/A-small-attempt0.in"));
		//in = new FastReader(new File("src/A-large.in"));
		try {
			//out = new PrintWriter(new File("src/A-ex.out"));
			out = new PrintWriter(new File("src/A-small-attempt0.out"));
			//out = new PrintWriter(new File("src/A-large.out"));
		} 
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		solve();
		out.close();
	}
	
	void solve()
	{
		int T = in.nextInt();  
		//in.nextLine(); //use after a nextInt() and prior to reading another in.nextLine()

		for (int tc = 1; tc <= T; tc++)
		{
			int N = in.nextInt();
			int L = in.nextInt();
			
			String[] aa = new String[N];
			String[] a = new String[N];
			String[] b = new String[N];
			for (int i = 0; i < N; i++) 
				aa[i] = in.next();
			for (int i = 0; i < N; i++) 
				b[i] = in.next();
			Arrays.sort(b);
			
			int min = 1000;
			for (int mask = 0; mask < (1 << L); mask++)
			{
				for (int i = 0; i < N; i++)
					a[i] = aa[i];
				
				for (int i = 0; i < L; i++)
					if ((mask & (1 << i)) > 0)
						for (int j = 0; j < N; j++)
						{
							String s = "";
							if (i > 0)
								s = a[j].substring(0,i);
							if (a[j].charAt(i) == '1')
								s += "0";
							else
								s += "1";
							if (i < L-1)
								s += a[j].substring(i+1,L);	
							a[j] = s;
						}
				
				Arrays.sort(a);
				boolean same = true;
				for (int i = 0; i < N; i++)
					if (!a[i].equals(b[i])) same = false;
				
				if (same)
					min = Math.min(min, Integer.bitCount(mask));					
			}
			
			String ans = "NOT POSSIBLE";
			if (min < 1000)
				ans = min + "";
			
			System.out.println("Case #" + tc + ": " + ans);
			out.println("Case #" + tc + ": " + ans);
		}
	}

	//-----------------------------------------------------

	
	class FastReader
	{
	    BufferedReader br;
	    StringTokenizer tokenizer;
	    
	    public FastReader(InputStream stream)
	    {
	        br = new BufferedReader(new InputStreamReader(stream));
	        tokenizer = null;
	    }
		public FastReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
				tokenizer = null;
			}
			catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
	    
	    private String next() {
	        while (tokenizer == null || !tokenizer.hasMoreTokens())
	            try {
	            	tokenizer = new StringTokenizer(br.readLine());
	            }
	            catch (IOException e) {
	                throw new RuntimeException(e);
	            }
	        return tokenizer.nextToken();
	    }
		public String nextLine() {
			try	{
				return br.readLine();
			}
			catch(Exception e) {
				throw(new RuntimeException());
			}
		}

	    int nextInt() {
	        return Integer.parseInt(next());
	    }
	    long nextLong() {
	        return Long.parseLong(next());
	    }
	    double nextDouble() {
	        return Double.parseDouble(next());
	    }	    
	    BigInteger nextBigInteger() {
	        return new BigInteger(next());
	    }
	    BigDecimal nextBigDecimal() {
	        return new BigDecimal(next());
	    }
	}
}
