import java.util.*;
import java.io.*;

public class Charge
{
	public static void main(String[] klein)
	{
		final Kattio in = new Kattio(System.in);
		final PrintWriter out = new PrintWriter(System.out);

		int T = in.getInt();
		loop:for(int t = 1; t<=T; t++)
		{
			final int N = in.getInt(), L = in.getInt();
			final BitSet[] v = new BitSet[N], u = new BitSet[N];
			for(int i = 0; i<N; i++){ v[i] = new BitSet(L); u[i] = new BitSet(L); }

			for(int i = 0; i<N; i++)
			{
				final char[] c = in.getWord().toCharArray();
				for(int j = 0; j<L; j++) if(c[j]=='1') v[i].set(j);
			}
			for(int i = 0; i<N; i++)
			{
				final char[] c = in.getWord().toCharArray();
				for(int j = 0; j<L; j++) if(c[j]=='1') u[i].set(j);
			}

			int best = L+10;
			brute:for(int i = 0; i<N; i++)
			{
				final BitSet tmp = (BitSet)v[0].clone();
				tmp.xor(u[i]);
				final int diff = tmp.cardinality();

				final String[] a = new String[N], b = new String[N];
				for(int j = 0; j<N; j++){ BitSet tm2 = (BitSet)v[j].clone(); tm2.xor(tmp); a[j] = tm2.toString(); }
				for(int j = 0; j<N; j++){ BitSet tm2 = (BitSet)u[j].clone(); /*tm2.xor(tmp);*/ b[j] = tm2.toString(); }
				Arrays.sort(a); Arrays.sort(b);
				for(int j = 0; j<N; j++) if(!a[j].equals(b[j])) continue brute;
				if(diff<best) best = diff;
			}

			out.println("Case #"+t+": " + (best<=L ? best : "NOT POSSIBLE"));
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
