import java.io.*;
import java.util.*;
import java.awt.*;

public class ChargingChaos {
	static final String INPUT = "A-small.in";
	static final String OUTPUT = "A-small.out";
	
	// fast I/O util
	static PrintWriter out = new PrintWriter( new BufferedOutputStream(System.out) );
	static BufferedReader br = new BufferedReader( new InputStreamReader(System.in) );
	static StringTokenizer st = new StringTokenizer("");
	static String next()	throws Exception	{
		
		while	( !st.hasMoreTokens() )	{
			String s = br.readLine();
			if	( s == null )	return	null;
			st = new StringTokenizer( s );
		}
		return	st.nextToken();
	}

	public static void main(String [] asda)	throws Exception	{
		
		br = new BufferedReader( new FileReader(INPUT) );
		out = new PrintWriter(OUTPUT);
		
		
		int CASES = Integer.parseInt( next() );
		
		for (int ccc = 1; ccc <= CASES; ccc++)	{
			out.print("Case #" + ccc + ": ");
			int N = Integer.parseInt( next() );
			int L = Integer.parseInt( next() );
			boolean board [][] = new boolean [N][L];
			for (int i = 0; i < N; i++)	{
				String s = next();
				for (int k = 0; k < L; k++)
					board[i][k] = s.charAt(k) == '1';
			}

			PriorityQueue<String> pq = new PriorityQueue<String>();
			for (int i = 0; i < N; i++)	{
				pq.add( next() );
			}
			
			//
			int min = Integer.MAX_VALUE;
			for (int i = 0; i < (1 << L); i++)	{
				Vector<Integer> v = new Vector<Integer>();
				for (int k = 0; k < L; k++)	{
					if	( (i & (1 << k) ) != 0 )
						v.add(k);
				}
				// test
				
				PriorityQueue<String> pq2 = getPQ(board, v);
				PriorityQueue<String> pq3 = new PriorityQueue<String>(pq);

				/*
				out.println( "flipped: " + v.toString() );
				out.println(" changed: " + pq2.toString() );
				out.println(" my     : " + pq3.toString() );
				*/
				while	( !pq3.isEmpty() && pq3.peek().equals( pq2.peek() ) )	{
					pq3.poll();
					pq2.poll();
				}
				if	( pq2.isEmpty() && v.size() < min )
					min = v.size();
			}
			
			if	( min == Integer.MAX_VALUE )
				out.println("NOT POSSIBLE");
			else
				out.println(min);
			
		}
		//
		out.flush();
		
		out.close();
		br.close();
	}

	private static PriorityQueue<String> getPQ(boolean[][] board, Vector<Integer> v) {
		PriorityQueue<String> pq = new PriorityQueue<String>();

		for (int i = 0; i < board.length; i++)	{
			StringBuilder sb = new StringBuilder();
			for (int k = 0; k < board[i].length; k++)	{
				if	( v.contains( Integer.valueOf(k) ) )
					sb.append( board[i][k] ? '0' : '1' );
				else
					sb.append( board[i][k] ? '1' : '0' );
			}
			pq.add( sb.toString() );
		}
		
		return	pq;
	}

}


