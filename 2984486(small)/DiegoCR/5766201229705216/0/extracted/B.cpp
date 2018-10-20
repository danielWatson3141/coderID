#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

vector < int > graph[1111];
int nh[1111];

void dfs1 ( int cur, int parent ) {
	int s = 0, v;
	
	for ( int i = 0; i < graph[cur].size(); i ++ ) {
		v = graph[cur][i];
		if ( v == parent ) continue;
		dfs1 ( v, cur );
		s += nh[v];
	}
	
	nh[cur] = s + 1;
}

int dfs2 ( int cur, int parent ) {
	
	int sumh = 0, v, x = 0;
	int m1 = 0, m2 = 0, temp;
	
	for ( int i = 0; i < graph[cur].size(); i ++ ) {
		v = graph[cur][i];
		if ( v == parent ) continue;
		x ++;
		sumh += nh[v];
		temp = nh[v] - dfs2 ( v, cur );
		if ( temp >= m1 ) {
			m2 = m1;
			m1 = temp;
		} else if ( temp > m2 ) {
			m2 = temp;
		}
	}
	
	// cout << cur << " " << sumh << " m1 " << m1 << " m2 " << m2 << endl;
	
	if ( x < 2 ) return sumh;
	return sumh - m1 - m2;
}

int main () {
	
	freopen ( "b.in", "r", stdin );
	freopen ( "BSmall.txt", "w", stdout );
	
	int tc, ntc = 0, n, a, b;
	
	scanf ( "%d", &tc );
	
	while ( tc -- ) {
		
		scanf ( "%d", &n );
		ntc ++;
		
		for ( int i = 0; i < n; i ++ ) graph[i].clear();
		
		for ( int i = 1; i < n; i ++ ) {
			scanf ( "%d %d", &a, &b );
			a --; b --;
			graph[a].push_back ( b );
			graph[b].push_back ( a );
		}
		
		int ans = n;
		
		for ( int i = 0; i < n; i ++ ) {
			// cout << "**********" << i << "*****************\n";
			dfs1 ( i, -1 );
			ans = min ( ans, dfs2 ( i, -1 ) );
			// cout << "*****************************\n";
		}
		
		printf ( "Case #%d: %d\n", ntc, ans );
	}
}
