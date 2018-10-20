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

double p[ MAXN ][ MAXN ];

void Init()
{
	int i, j, k;
	const int n = MAXN;
	double _a[ n ], _b[ n ], *a = _a, *b = _b;
	
	for( k = 0; k < n; ++k )
	{
		memset( a, 0, sizeof( _a ) );
		a[ k ] = 1;
		for( i = 0; i < n; ++i )
		{
			memset( b, 0, sizeof( _b ) );
			for( j = 0; j < n; ++j )
			{
				if( j != i )
				{
					b[ j ] += a[ j ] * ( n - 1 ) / n;
					b[ j ] += a[ i ] / n;
				}
				b[ i ] += a[ j ] / n;
			}
			swap( a, b );
		}
		for( j = 0; j < n; ++j )
		{
			p[ k ][ j ] = a[ j ];
		}
	}
}

int N;
int P[ MAXN ];

void Read()
{
	int i;
	scanf( "%d", &N );
	for( i = 0; i < N; ++i )
	{
		scanf( "%d", &P[ i ] );
	}
}

bool Result;

void Work()
{
	int i;
	double x = 0;
	Result = false;

	for( i = 0; i < N; ++i )
	{
		x += p[ P[ i ] ][ i ];
	}

	if( x >= 1 )
		return;

	Result = true;
}

void Write( int t )
{
	if( Result )
		printf( "Case #%d: GOOD\n", t );
	else
		printf( "Case #%d: BAD\n", t );
}

int main()
{
	int i, t;
	Init();
	scanf( "%d", &t );
	for( i = 0; i < t; ++i )
	{
		Read();
		Work();
		Write( i + 1 );
	}
	return 0;
}
