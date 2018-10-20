#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <algorithm>

#define MAXL 41
#define MAXN 151
#define INF 999999999

using namespace std;

int T, n, l;
char text[MAXL];
multiset <long long> s;
long long A[MAXN];
bool pos;
int sol;

long long toDecimal( int b ) {
   long long result = 0;
   int multiplier = 1;
   
   int n = l-1;

   for ( int n = l-1; n >= 0; --n ) {
      result += (text[n]-'0') * multiplier;
      multiplier *= b;
   }
      
   return ( result );

}

bool isGoal( ) {

	for ( int i = 1; i <= n; ++i ) {
		if ( s.find( A[i] ) == s.end( ) )
			return ( false );
	}

	return ( true );

}

void print( ) {
	for ( int i = 1; i <= n; ++i ) {
		printf( "%lld ", A[i] );
	}
	putchar( '\n' );
}

int f( int i ) {

	//print( );

	if ( i > l ) {
		if ( !isGoal() ) {
			return ( INF );
		}
		pos = true;
		return ( 0 );
	}

	if ( isGoal() ) {
		pos = true;
		return ( 0 );
	}

	int ans = f( i + 1 );

	for ( int j = 1; j <= n; ++j ) {
		A[j] ^= (1 << i);
	}

	ans = min ( ans, 1 + f( i+1 ) );

	for ( int j = 1; j <= n; ++j ) {
		A[j] ^= (1 << i);
	}

	return ( ans );

}

int main( ) {

	scanf( "%d", &T );

	for ( int t = 0; t < T; ++t ) {

		scanf( "%d %d", &n, &l );

		s.clear();

		for ( int i = 1; i <= n; ++i ) {
			scanf( "%s", text );
			//printf( "%d ", toDecimal(2) );
			A[i] = toDecimal(2);
		}

		//putchar( '\n');

		for ( int i = 0; i < n; ++i ) {
			scanf( "%s", text );
			//printf( "%d ", toDecimal(2) );
			s.insert( toDecimal(2) );
		}

		//putchar('#');

		pos = false;

		sol = f(0);

		if ( pos ) {
			printf( "Case #%d: %d\n", t+1, sol );
		}else {
			printf( "Case #%d: NOT POSSIBLE\n", t+1 );
		}

		//printf( "Ans := %d\n", f(0) );
		//putchar('\n' );

	}

	return 0;

}
