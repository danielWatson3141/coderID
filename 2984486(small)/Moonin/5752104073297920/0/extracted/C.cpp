
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

int main()
{

	int T; scanf("%d" , &T );
	fr( t , 1 , T+1 )
	{
		int n; scanf("%d" , &n );
		fr( i , 0 , n )
		{
			int a;
			scanf("%d" , &a );
		}
		int ans = rand()%(2*n);
		if( ans < n )
			printf("Case #%d: GOOD\n",t);
		else
			printf("Case #%d: BAD\n",t);
	}
	return 0;
}