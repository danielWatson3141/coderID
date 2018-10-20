import java.util.*;
import java.io.*;
import static java.lang.Math.*;

class Node implements Comparable<Node> {

	int val;
	int score;
	int size;

	Node( int val, int score, int size ) {
		this.val = val;
		this.score = score;
		this.size = size;
	}
	
	@Override public int compareTo( Node node ) {
		return size - node.size;
	}

	public String toString() {
		return String.format( "(idx, score, size) = (%d, %d, %d)", val, score, size );
	}
}

class Main {

    public static void main( final String[] args ) {

		final Scanner stdin = new Scanner( System.in );

		int T = stdin.nextInt();

		for ( int t = 1; t <= T; t++ ) {
			int N = stdin.nextInt();
			List<List<Integer>> table = new ArrayList<List<Integer>>();
			for ( int i = 0; i < N + 1; i++ ) {
				table.add( new ArrayList<Integer>() );
			}
			for ( int i = 0; i < N - 1; i++ ) {
				int x = stdin.nextInt();
				int y = stdin.nextInt();
				table.get( x ).add( y );
				table.get( y ).add( x );
			}

			boolean[] visited = new boolean[ N + 1 ];
			int[] sizes = new int[ N + 1 ];
			int minScore = Integer.MAX_VALUE;
			for ( int root = 1; root <= N; root++ ) {
				Arrays.fill( visited, false );
				Arrays.fill( sizes, 0 );
				int score = dfs( table, visited, sizes, root );
				// System.err.println( score + " " + root );
				if ( score < minScore ) {
					minScore = score;
				} 
			}
			//System.err.println();
			System.out.printf( "Case #%d: %d\n", t, minScore );
		}		
    }

	static List<Integer> count( List<Integer> list, boolean[] visited ) {
		List<Integer> ans = new ArrayList<Integer>();
		for ( int val : list ) {
			if ( !visited[ val ] ) {
				ans.add( val );
			}
		}
		return ans;
	}

	static int size( List<List<Integer>> table, boolean[] visited, int cur ) {
		visited[ cur ] = true;
		int count = 1;
		for ( int node : table.get( cur ) ) {
			if ( !visited[ node ] ) {
				count += size( table, visited, node );
			}
		}
		return count;
	}

	static int dfs( List<List<Integer>> table, boolean[] visited, int[] sizes, int cur ) {
		visited[ cur ] = true;
		List<Integer> canVisit = count( table.get( cur ), visited );
		switch( canVisit.size() ) {
		case 2:
			// 正しい2分木なので，子の削除数を足して返す
			int score = dfs( table, visited, sizes, canVisit.get( 0 ) ) +
				dfs( table, visited, sizes, canVisit.get( 1 ) );
			sizes[ cur ] = sizes[ canVisit.get( 0 ) ] + sizes[ canVisit.get( 1 ) ] + 1;
			return score;
		case 1:
			// 自分が保持している子を削除する必要あり
			sizes[ cur ] = size( table, visited, canVisit.get( 0 ) ) + 1;
			return sizes[ cur ] - 1;
		case 0:
			// 末端ノードなので正しい
			sizes[ cur ] = 1;
			return 0;
		default:
			// 3以上の場合，各ノードを回って数が多い2つを残す．
			List<Node> list = new ArrayList<Node>();
			sizes[ cur ] = 1;
			for ( int node : canVisit ) {
				score = dfs( table, visited, sizes, node );
				sizes[ cur ] += sizes[ node ];
				Node n = new Node( node, score, sizes[ node ] - score );
				list.add( n );
				// System.err.println( n );
			}
			Collections.sort( list );
			int ans = 0;
			for ( Node node : list ) {
				ans += node.score;
			}
			for ( int i = 0; i < list.size() - 2; i++ ) {
				Node node = list.get( i );
				ans += node.size;
			}
			return ans;
		}
	}
}
