#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

string opc[155];
string need[155];

int n, l;
int used[55];
int parent[333];
int visit[333];
int mat[333][333];
int res[333][333];

int calc ( int pos ) {
	int s = 0;
	
	for ( int i = 0; i < 2 * n + 2; i ++ ) {
		for ( int j = 0; j < 2 * n + 2; j ++ ) {
			mat[i][j] = 0;
			res[i][j] = 0;
		}
	}
	
	for ( int i = 0; i < n; i ++ ) {
		mat[2 * n][i] = 1;
		mat[n + i][2 * n + 1] = 1;
	}
	
	for ( int i = 0; i < l; i ++ ) {
		if ( need[pos][i] != opc[0][i] ) {
			used[i] = true;
			s ++;
		} else used[i] = false;
	}
	
	int a, b;
	
	for ( int i = 0; i < n; i ++ ) {
		if ( i == pos ) continue;
		for ( int j = 1; j < n; j ++ ) {
			bool ok = true;
			for ( int k = 0; k < l && ok; k ++ ) {
				a = need[i][k] - '0';
				b = opc[j][k] - '0';
				if ( used[k] ) b = 1 - b;
				if ( a != b ) ok = false;
			}
			if ( ok ) mat[i][j + n] = 1;
			
			// cout << mat[i][j + n] << " ";
		}
		// cout << endl;
	}
	
	return s;
}

bool bfs ( int s, int t, int w ) {
	
	queue < int > Q;
	Q.push ( s );
	for ( int i = 0; i < 2 * n + 2; i ++ ) visit[i] = 0;
	visit[w] = 1;
	int x;
	
	while ( !Q.empty() ) {
		x = Q.front();
		Q.pop();
		
		for ( int i = 0; i < 2 * n + 2; i ++ ) {
			if ( mat[x][i] + res[x][i] > 0 && !visit[i] ) {
				visit[i] = true;
				parent[i] = x;
				if ( i == t ) return true;
				Q.push ( i );
			}
		}
	}
	
	return false;
}

int mf ( int s, int t, int w ) {
	parent[s] = -1;
	int f = 0;
	while ( bfs ( s, t, w ) ) {
		int x = t;
		while ( x != s ) {
			res[x][parent[x]] ++;
			res[parent[x]][x] --;
			x = parent[x];
		}
		f ++;
	}
	
	return f;
}

int main () {
	
	freopen ( "A.in", "r", stdin );
	freopen ( "ALarge.txt", "w", stdout );

	int tc, ntc = 0;
	
	scanf ( "%d", &tc );
	
	while ( tc -- ) {
	
		scanf ( "%d %d", &n, &l );
		ntc ++;
		
		memset ( mat, 0, sizeof ( mat ) );
		memset ( res, 0, sizeof ( res ) );
		
		for ( int i = 0; i < n; i ++ ) cin >> opc[i];
		for ( int i = 0; i < n; i ++ ) cin >> need[i];		
	
		int ans = -1, x, y;
	
		for ( int i = 0; i < n; i ++ ) {
			x = calc ( i );
			y = mf ( 2 * n, 2 * n + 1, i );
			// cout << x << " ** " << y << endl;
			if ( y == n - 1 ) {
				if ( ans > x || ans == -1 )
					ans = x;
			}
		}
		
		printf ( "Case #%d: ", ntc );
		
		if ( ans == -1 ) printf ( "NOT POSSIBLE\n" );
		else printf ( "%d\n", ans );
	
	}

	return 0;

}
