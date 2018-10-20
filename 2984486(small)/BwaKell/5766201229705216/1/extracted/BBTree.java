import java.util.*;
import java.io.*;

public class BBTree
{
	static final int[] size = new int[1024], rem = new int[1024];
	static final Edge[] g = new Edge[1024];

	static void root(final int i, final int p)
	{
		size[i] = 1;
		rem[i] = 0;
		int a = 0, b = 0, c = 0;
		int ai = -1, bi = -1;
		for(Edge e = g[i]; e!=null; e=e.nxt)
			if(e.to!=p)
			{
				final int j = e.to;
				root(j,i);
				final int diff = size[j]-rem[j];
				size[i] += size[j];
				if(diff>a){ if(bi>=0) c += size[bi]; bi = ai; ai = j; b = a; a = diff; }
				else if(diff>b){ if(bi>=0) c += size[bi]; bi = j; b = diff; }
				else c += size[j];
			}
		if(bi<0) rem[i] = size[i]-1;
		else rem[i] = c + rem[ai]+rem[bi];
	}

	public static void main(String[] klein)
	{
		final Kattio in = new Kattio(System.in);
		final PrintWriter out = new PrintWriter(System.out);

		int T = in.getInt();
		loop:for(int t = 1; t<=T; t++)
		{
			final int N = in.getInt();
			Arrays.fill(g,0,N,null);
			for(int i = 1; i<N; i++)
			{
				final int a = in.getInt()-1, b = in.getInt()-1;
				g[a] = new Edge(b,g[a]);
				g[b] = new Edge(a,g[b]);
			}

			int best = 1024;
			for(int i = 0; i<N; i++)
			{
				Arrays.fill(size,0,N,0); Arrays.fill(rem,0,N,0);
				root(i,-1);
				if(rem[i]<best) best = rem[i];
			}

			out.println("Case #"+t+": " + best);
		}

		out.flush();
	}

	private static class Edge
	{
		final int to; final Edge nxt;
		Edge(final int t, final Edge e)
		{
			to = t; nxt = e;
		}
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
