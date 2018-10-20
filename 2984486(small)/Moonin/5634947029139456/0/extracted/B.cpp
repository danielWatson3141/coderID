
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

#define fr( i , c , n ) for( int i = (c) ; i < (n) ;i++ )
#define clr( a , c ) memset( a , c , sizeof a )
#define P pair<int , int>
#define L  long long

#define maxn 11

string outlet[maxn];
string device[maxn];
string temp[maxn];
int main()
{

	int T;
	scanf("%d" , &T );
	fr( t , 1 , T+1 )
	{
		int n , l; scanf("%d%d" , &n , &l );
		cin.ignore();
		fr( i , 0 , n ){ cin >> outlet[i]; temp[i] = outlet[i]; }
		fr( i , 0 , n ) cin >> device[i];
		sort( device , device + n );
		int ans = l+1;
		for( int i = 0 ; i <= ( (1<<l) - 1 ) ; i++ )
		{
			int nrturned = 0;
			bool ok=true;
			for( int j = 0 ; j < l && ok ; j++ )
				if( (1<<j) & i )
				{
					nrturned++;
					for( int k = 0 ; k < n ;k++ )
						temp[k][j] = (( outlet[k][j] - '0') + 1 )%2 + '0';
				}
				else
				{
					for( int k = 0 ; k < n ;k++ )
						temp[k][j] = outlet[k][j];
				}
			sort( temp , temp + n );
			fr( i , 0 , n ) if( temp[i] != device[i] ){ ok =false; break;}
			if( ok ) ans = min( ans , nrturned ) ;
		}

		if( ans > l )
			printf("Case #%d: NOT POSSIBLE\n" , t );
		else
			printf("Case #%d: %d\n" , t , ans );
	}
	return 0;
}