#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <list>
#include <algorithm>

#define MAXN 1001

using namespace std;
 
int T, n, sol;
int A[MAXN];

list <int> v;

bool isok( ) {

	int cnt = 1;

	for ( list<int>::iterator pos = v.begin(); pos != v.end(); ++pos ) {
		//printf( "%d ", *pos );
		if ( A[cnt] != *pos ) {
			return ( false );
		}
		++cnt;
	}
	//putchar( '\n' );

	return ( true );

}

int main( ) {

	scanf( "%d", &T );

	for ( int t = 0; t < T; ++t ) {

		scanf( "%d", &n );
	
		for ( int i = 1; i <= n; ++i )
			scanf( "%d", &A[i] );
		
/*
		putchar( '#' );
		for ( int i = 1; i <= n; ++i )
			printf( "%d ", A[i] );
		putchar( '\n' );
*/
		v.clear();

		for ( int i = 0; i < n; ++i )
			v.push_back( i );

		bool good = false;

		//isok();
		v.push_back( *v.begin() );
		v.pop_front();

		for ( int i = 1; i < n; ++i ) {
			
			if ( isok() ) {
				good = true;
				break;
			}

			v.push_back( *v.begin() );
			v.pop_front();
		}

		if ( !good ) {
			printf( "Case #%d: BAD\n", t+1 );
		}else {
			printf( "Case #%d: GOOD\n", t+1 );	
		}

	}

}
