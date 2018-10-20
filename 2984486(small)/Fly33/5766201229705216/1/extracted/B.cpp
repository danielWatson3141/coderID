#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <omp.h>
#include <functional>
#include <algorithm>
#include <cctype>
#include <list>
using namespace std;

static const int MAXN = 1012;

int N;
list< int > tie[ MAXN ];

void Read()
{
	int i;
	scanf( "%d", &N );
	for( i = 0; i < N; ++i )
		tie[ i ].clear();
	for( i = 1; i < N; ++i )
	{
		int x, y;
		scanf( "%d%d", &x, &y );
		--x;
		--y;
		tie[ x ].push_back( y );
		tie[ y ].push_back( x );
	}
}

//int Func( int k, int p )
//{
//	int b[ 3 ] = { 0, 0, 0 };
//	for( list< int >::const_iterator tie_it = tie[ k ].begin(); tie_it != tie[ k ].end(); ++tie_it )
//	{
//		if( *tie_it == p )
//			continue;
//		b[ 0 ] = Func( *tie_it, k ) + 1;
//		sort( b, b + 3 );
//	}
//	return b[ 1 ];
//}
//
//int Count( int k, int p, int d )
//{
//	if( d < 0 )
//		return 1;
//	int result = 0;
//	for( list< int >::const_iterator tie_it = tie[ k ].begin(); tie_it != tie[ k ].end(); ++tie_it )
//	{
//		if( *tie_it == p )
//			continue;
//		result += Count( *tie_it, k, d - 1 );
//	}
//	return result;
//}

int Count( int k, int p )
{
	int result = 0;
	int b[ 3 ] = { 0, 0, 0 };
	for( list< int >::const_iterator tie_it = tie[ k ].begin(); tie_it != tie[ k ].end(); ++tie_it )
	{
		if( *tie_it == p )
			continue;
		b[ 0 ] = Count( *tie_it, k );
		sort( b, b + 3 );
	}
	if( b[ 1 ] == 0 )
		return 1;
	return b[ 1 ] + b[ 2 ] + 1;
}

int Result;

void Work()
{
	int k;

	Result = N;

	for( k = 0; k < N; ++k )
	{
		int result = N - Count( k, -1 );
		if( Result > result )
			Result = result;
	}
}

void Write( int t )
{
	printf( "Case #%d: %d\n", t, Result );
}

int main()
{
	int i, t;
	scanf( "%d", &t );
	for( i = 0; i < t; ++i )
	{
		Read();
		Work();
		Write( i + 1 );
	}
	return 0;
}
