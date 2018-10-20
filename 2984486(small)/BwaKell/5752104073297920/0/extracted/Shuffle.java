import java.util.*;
import java.io.*;

public class Shuffle
{
	public static void main(String[] klein)
	{
		final Kattio in = new Kattio(System.in);
		final PrintWriter out = new PrintWriter(System.out);

		final Random rnd = new Random();

		int T = in.getInt();
		loop:for(int t = 1; t<=T; t++)
		{
			final int N = in.getInt();
			final int[] v = new int[N];
			for(int i = 0; i<N; i++) v[i] = in.getInt();

			double score = 0;
			for(int i = 0; i<N; i++)
			{
				final int num = v[i]; if(num==0) continue; if(num==N-1 && i==num) continue;
				final double base = num-N/2.0;
				if(i<num) score += (i - base)/(N-1)*2;
				else score -= (double)(N-i-1)/(N-num-1);
			}score /= N; score += 1; score /= 2;//System.err.println(score);

			out.println("Case #"+t+": " + (rnd.nextDouble()<score ? "BAD" : "GOOD"));
		}

		out.flush();
	}

	private static class Kattio
	{
		public Kattio(final InputStream i)
		{
			r = new BufferedReader(new InputStreamReader(i));
		}

		public boolean hasMoreTokens() {
			return peekToken() != null;
		}

		public int getInt() {
			return Integer.parseInt(nextToken());
		}

		public double getDouble() {
			return Double.parseDouble(nextToken());
		}

		public float getFloat()
		{
			return Float.parseFloat(nextToken());
		}

		public long getLong() {
			return Long.parseLong(nextToken());
		}

		public String getWord() {
			return nextToken();
		}



		private BufferedReader r;
		private String line;
		private StringTokenizer st;
		private String token;

		private String peekToken() {
		if (token == null)
			try {
			while (st == null || !st.hasMoreTokens()) {
				line = r.readLine();
				if (line == null) return null;
				st = new StringTokenizer(line);
			}
			token = st.nextToken();
			} catch (IOException e) { }
		return token;
		}

		private String nextToken() {
		String ans = peekToken();
		token = null;
		return ans;
		}
	}
}
