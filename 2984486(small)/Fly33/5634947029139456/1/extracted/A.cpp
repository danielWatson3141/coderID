#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <omp.h>
#include <functional>
#include <algorithm>
#include <cctype>
using namespace std;

static const int MAXN = 156;
static const int MAXL = 42;

int N, L;
long long Out[ MAXN ];
long long Dev[ MAXN ];

void Read()
{
	int i, j;
	scanf( "%d%d", &N, &L );
	for( i = 0; i < N; ++i )
	{
		Out[ i ] = 0;
		for( j = 0; j < L; ++j )
		{
			int x;
			scanf( "%1d", &x );
			Out[ i ] = Out[ i ] << 1 | x;
		}
	}
	for( i = 0; i < N; ++i )
	{
		Dev[ i ] = 0;
		for( j = 0; j < L; ++j )
		{
			int x;
			scanf( "%1d", &x );
			Dev[ i ] = Dev[ i ] << 1 | x;
		}
	}
}

int Result;

void Work()
{
	int i, j;
	Result = -1;

	sort( Dev, Dev + N );
	sort( Out, Out + N );

	for( i = 0; i < N; ++i ) // Dev[i] to Out[0]
	{
		long long xor = Dev[ i ] ^ Out[ 0 ];
		for( j = 0; j < N; ++j )
			Out[ j ] ^= xor;

		sort( Out, Out + N );

		for( j = 0; j < N; ++j )
		{
			if( Dev[ j ] != Out[ j ] )
				break;
		}
		if( j == N )
		{
			long long x = xor;
			int r = 0;
			while( x != 0 )
			{
				x = ( x - 1 ) & x;
				++r;
			}
			if( Result == -1 || Result > r )
				Result = r;
		}

		for( j = 0; j < N; ++j )
			Out[ j ] ^= xor;

		sort( Out, Out + N );
	}
}

void Write( int t )
{
	if( Result != -1 )
		printf( "Case #%d: %d\n", t, Result );
	else
		printf( "Case #%d: NOT POSSIBLE\n", t );
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
