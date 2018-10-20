

// a.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 20

int bits[ MAXN ], num_list[ MAXN ], s_list[ MAXN ];
int n, l, min_use, use;
char s[ MAXN ][ MAXN ], d[ MAXN ][ MAXN ];
bool ok;


void init_(){
	int i, k = 1;
	for ( i = 0; i <= 10; i ++ ){
		bits[ i ] = k;
		k *= 2;
	}
}

int trunIntoInt_s( int k ){
	int i, num = 0;
	for ( i = 0; i < l; i ++ )
		if ( s[k][i] == '1' )
			num += bits[i];
	return num;
}

int trunIntoInt_d( int k ){
	int i, num = 0;
	for ( i = 0; i < l; i ++ )
		if ( d[k][i] == '1' )
			num += bits[i];
	return num;
}

void init(){
	scanf( "%d%d", &n, &l );
	int i, j, num;
	for ( i = 1; i <= n; i ++ ){
		scanf( "%s", s[i] );
	}
	
	for ( i = 1; i <= n; i ++ ){
		scanf( "%s", d[i] );
		num_list[i] = trunIntoInt_d( i );
		//cout << num_list[i] << endl;
	}
	ok = false;
	min_use = MAXN;
	sort( num_list+1, num_list+n+1 );
}


inline void trun( char &c ){
	if ( c == '0' )
		c = '1';
	else
		c = '0';
}

void check(){
	int i;
	for ( i = 1; i <= n; i ++ )
		s_list[i] = trunIntoInt_s(i);
	sort( s_list+1, s_list+n+1 );
	for ( i = 1; i <= n; i ++ )
		if ( s_list[i] != num_list[i] )
			return;
	ok = true;
	if ( use < min_use )
		min_use = use;
}

void pro( int k ){
	int i, j;
	for ( i = 0; i <= 1; i ++ ){
		if ( i == 1 ){
			for ( j = 1; j <= n; j ++ )
				trun( s[j][k] );
			use ++;
		}
		if ( k == l-1 )
			check();
		else{
			pro(k+1);
		}
		if ( i == 1 ){
			for ( j = 1; j <= n; j ++ )
				trun( s[j][k] );
			use --;
		}
	}
}

void cal(){
	use = 0;
	pro(0);
	if ( ok )
		cout << min_use << endl;
	else
		cout << "NOT POSSIBLE" << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	init_();
	freopen( "A-small-attempt0.in", "r", stdin );
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

