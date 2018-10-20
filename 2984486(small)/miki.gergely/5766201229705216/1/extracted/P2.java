package round1a.p2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;

public class P2
{
	private static void calculate( int N, int[][] edges, BufferedWriter bw, int n ) throws Exception
	{
		int ranks[] = getRanks( edges );
		
		int max = 1;
		for ( int i = 1; i <= N; i++ )
			max = Math.max( check( edges, ranks, i, -1 ), max );
		
		String answer = "" + ( N - max );
		bw.append( "Case #"+n+": " + answer + "\n" );
		bw.flush();
	}
	
	private static int check( int[][] edges, int[] ranks, int root, int grandfather )
	{
		if ( ranks[root] < ( grandfather == -1 ? 2 : 3 ) )
			return 1;
		
		List<Integer> neighbours = getNeighbours( root, grandfather, edges );
		
		int max1 = 0;
		int max2 = 0;
		
		for ( int neighbour : neighbours )
		{
			int maxTree = check( edges, ranks, neighbour, root );
			if ( maxTree > max1 )
			{
				max2 = max1;
				max1 = maxTree;
			}
			else if ( maxTree > max2 )
				max2 = maxTree;
		}
		
		return 1 + max1 + max2;
	}
	
	private static List<Integer> getNeighbours( int root, int grandfather, int[][] edges )
	{
		List<Integer> neighbours = new ArrayList<Integer>();
		for ( int[] edge : edges )
		{
			if ( edge[0] == root && edge[1] != grandfather )
				neighbours.add( edge[1] );
			if ( edge[1] == root && edge[0] != grandfather )
				neighbours.add( edge[0] );
		}
		
		return neighbours;
	}

	private static int[] getRanks( int[][] edges )
	{
		int[] ranks = new int[edges.length + 2];
		
		for ( int[] edge : edges )
		{
			ranks[edge[0]]++;
			ranks[edge[1]]++;
		}
		
		return ranks;
	}

	public static void main( String[] args ) throws Exception
	{
		File inputFile = new File( "inputfiles/round1a/p2/input.txt" );
		FileReader fr = new FileReader( inputFile );
		BufferedReader br = new BufferedReader( fr );
		
		int numOfTestCases = Integer.parseInt( br.readLine() );
		
		File outputFile = new File( "inputfiles/round1a/p2/output.txt" );
		outputFile.delete();
		outputFile.createNewFile();
		FileWriter fw = new FileWriter( outputFile );
		BufferedWriter bw = new BufferedWriter( fw );
		
		for ( int i = 0; i < numOfTestCases; i++ )
		{
			int N = Integer.parseInt( br.readLine() );
			
			int[][] edges = new int[N-1][2];
			for ( int j = 0; j < N-1; j++ )
			{
				String[] edge = br.readLine().split( " " );
				edges[j][0] = Integer.parseInt( edge[0] );
				edges[j][1] = Integer.parseInt( edge[1] );
			}
			
			calculate( N, edges, bw, i+1 );
		}
		
		bw.flush();
		fw.flush();
		
		bw.close();
		fw.close();
	}
}
