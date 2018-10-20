#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <algorithm>

#define WHITE 0
#define BLACK 1
#define MAXN 1001

using namespace std;

int T, n, from, to, ans;
vector < list<int> > adj(MAXN);
bool visited[MAXN];

int test( int root ) {

	for ( int i = 1; i <= n; ++i )
		visited[i] = WHITE;

	queue <int> q;

	q.push( root );
	visited[root] = BLACK;

	int tot = 1;

	while ( !q.empty() ) {
		int top = q.front();
		q.pop();
		
		//printf( "extract %d\n", top );

		for ( list<int>::iterator pos = adj[top].begin(); pos != adj[top].end(); ++pos ) {
			//printf( "test visit %d\n", *pos );
			if ( visited[ *pos ] == WHITE ) {
				if ( adj[*pos].size() == 3 ) {
					//printf( "insert %d\n", *pos );
					q.push( *pos );
					visited[*pos] = true;
					++tot;
				}else {
					//printf( "%d has only %d neigh\n", *pos, (int)adj[*pos].size() );
					visited[*pos] = true;
					++tot;
				}
			}
		}

	}

	return ( n-tot );

}

int main( ) {

	scanf( "%d", &T );

	for ( int t = 0; t < T; ++t ) {

		scanf( "%d", &n );

		for ( int i = 1; i <= n; ++i )
			adj[i].clear();

		for ( int i = 1; i < n; ++i ) {
			scanf( "%d %d", &from, &to );
			adj[from].push_back( to );
			adj[to].push_back( from );
		}

		for ( int i = 1; i <= n; ++i ) {
			int tmp = test(i);
			//printf( "%d\n", tmp );
			if ( i == 1 ) {
				ans = tmp;
			}else {
				ans = min( ans, tmp );
			}
		}

		printf( "Case #%d: %d\n", t+1, ans );
		
	}

	return 0;

}
