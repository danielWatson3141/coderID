import java.util.*;
import java.io.*;
import static java.lang.Math.*;

class Main {

    public static void main( final String[] args ) {

		final Scanner stdin = new Scanner( System.in );

		int T = stdin.nextInt();
		for ( int t = 1; t <= T; t++ ) {
			int N = stdin.nextInt();
			int L = stdin.nextInt();

			int[] from = new int[ N ];
			for ( int i = 0; i < N; i++ ){
				from[ i ] = stdin.nextInt( 2 );
			}
			int[] to = new int[ N ];
			for ( int i = 0; i < N; i++ ){
				to[ i ] = stdin.nextInt( 2 );
			}
			int[] indices = new int[ N ];
			for ( int i = 0; i < N; i++ ) {
				indices[ i ] = i;
			}

			int minCount = L * 2;
			do {
				int xor = ( from[ 0 ] ^ to[ indices[ 0 ] ] );
				boolean success = true;
				for ( int i = 1; i < N; i++ ) {
					if ( ( from[ i ] ^ to[ indices[ i ] ] ) != xor ) {
						success = false;
						break;
					}
				}
				if ( success ) {
					minCount = Math.min( minCount, Integer.bitCount( xor ) );
				}
			} while( nextPerm( indices ) );

			if ( minCount == L * 2 ) {
				System.out.printf( "Case #%d: NOT POSSIBLE\n", t );
			} else {
				System.out.printf( "Case #%d: %d\n", t, minCount );
			}
		}
    }

	static int min( int[] array, int from, int to, int less ) {
		int index = -1;
		int val = 100000000;
		for ( int i = from; i < to; i++ ) {
			if ( array[ i ] > less && val > array[ i ] )  {
				index = i;
				val = array[ i ];
			}
		}
		return index;
	}

	static void swap( int[] array, int a, int b ) {
		int tmp = array[ a ];
		array[ a ] = array[ b ];
		array[ b ] = tmp;
	}

	static void psort( int[] array, int from, int to ) {
		int[] tmp = new int[ to - from ];
		for ( int i = from; i < to; i++ ) {
			tmp[ i - from ] = array[ i ];
		}
		Arrays.sort( tmp );
		for ( int i = from; i < to; i++ ) {
			array[ i ] = tmp[ i - from ];
		}
	}

	static boolean nextPerm( int[] array ) {
		int i = array.length - 1;
		while( i > 0 && array[ i - 1 ] > array[ i ] ) {
			i--;
		}
		if ( i > 0 ) {
			int minIndex = min( array, i, array.length, array[ i - 1 ] );
			swap( array, i - 1, minIndex );
			psort( array, i, array.length );
			return true;
		} else {
			return false;
		}
	}
}
