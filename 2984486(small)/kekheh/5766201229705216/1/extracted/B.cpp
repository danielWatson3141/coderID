#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std ;

#define MAX(a,b) a > b ? a : b 
#define MIN(a,b) a < b ? a : b
#define N 1001 

int degree[N][N] ; 
bool visit[N] ;
int n , T;

void init()
{
	memset(degree,0,n+1) ;
	memset(visit,false,n+1) ;
}

int solve( int root )
{
	int i , j = 0 ;
	int m1 = 0 ,m2 = 0 ;
	visit[root] = true ;
	for( i = 1 ; i <= degree[root][0] ; i ++ ) {
		if( !visit[degree[root][i]] )
			j ++ ;
	}
	if( j < 2 ) return 1 ;
	for( i = 1 ; i <= degree[root][0] ; i ++ ) {
		if( !visit[degree[root][i]] ) {
			j = solve(degree[root][i]) + 1 ;
			if( j >= m1 ) {
				m2 = m1 ;
				m1 = j ;
			}
			else if( j > m2 ) {
				m2 = j ;
			}
		}
	}
	return m1 + m2 - 1 ;
}

int main()
{
	freopen("B1.in","r",stdin) ;
	freopen("B1.out","w",stdout) ;
	int i , j ;
	while( scanf("%d",&T) != EOF ) {
		for( i = 1 ; i <= T ; i ++ ) {
			int m1 = 0 ;
			scanf("%d",&n);
			for( j = 1 ; j <= n ; j ++ ) 
				degree[j][0] = 0 ;
			for( j = 1 ;j < n ; j ++ ) {
				int k , j ;
				scanf("%d %d",&k,&j);
				degree[k][++ degree[k][0] ] = j ; 
				degree[j][++ degree[j][0] ] = k ; 
			}
			for( j = 1 ; j <= n ; j ++ ) {
				int k = solve(j) ;
				if( k > m1 ) m1 = k ;
//				printf("%d %d\n",j,m1);
				memset(visit,false,n+1) ;
			}
			printf("Case #%d: %d\n",i,n-m1);
		}
	}

	return 0 ;
}