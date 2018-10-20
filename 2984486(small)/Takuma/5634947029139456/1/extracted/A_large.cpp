// a.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 160

long long bits[ MAXN ], d_list[ MAXN ], s_list[ MAXN ], map[ MAXN*MAXN ];
int n, l, min_num;
char s[ MAXN ][ MAXN ], d[ MAXN ][ MAXN ];
bool ok;


void init_(){
	int i;
	long long k = 1;
	for ( i = 0; i <= 40; i ++ ){
		bits[ i ] = k;
		k *= 2;
	}
}

void init(){
	scanf( "%d%d", &n, &l );
	int i, j, num;
	for ( i = 1; i <= n; i ++ ){
		scanf( "%s", s[i] );
	}
	
	for ( i = 1; i <= n; i ++ ){
		scanf( "%s", d[i] );
	}
}

long long pick( int si, int dj ){
	int i;
	long long num = 0;
	for ( i = 0; i < l; i ++ ){
		if ( s[si][i] != d[dj][i] )
			num += bits[i];
	}
	return num;
}

void print_ans( long long num ){
	int use = 0;
	while ( num > 0 ){
		use += num % 2;
		num /= 2;
	}
	if ( use < min_num )
		min_num = use;
}


void cal(){
	int i, j, count;
	for ( i = 1; i <= n; i ++ )
		for ( j = 1; j <= n; j ++ )
			map[(i-1)*n+j] = pick( i,j );

	sort( map+1, map+n*n+1 );

	count = 0;
	ok = false;
	min_num = MAXN;
	map[0] = -1;
	for ( i = 1; i <= n*n; i ++ ){
		if ( map[i] == map[i-1] )
			count ++;
		else
			count = 1;
		if ( count == n ){
			print_ans( map[i] );
			ok = true;
		}
	}
	
	if ( ok )
		cout << min_num << endl;
	else
		cout << "NOT POSSIBLE" << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	init_();
	freopen( "A-large.in", "r", stdin );
	freopen( "out.txt", "w", stdout );
	int t, i;
	scanf( "%d\n", &t );
	for ( i = 1; i <= t; i ++ ){
		init();
		cout << "Case #" << i << ": ";
		cal();
	}
	return 0;
}

