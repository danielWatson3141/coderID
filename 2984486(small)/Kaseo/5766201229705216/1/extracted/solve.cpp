#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

const long long INF = 1000000007;
typedef pair <int, int> ii;
long long gcd( long long b, long long s ){
	return (s!=0) ? gcd( s, b%s ) : b;
}

vector <int> e[1005];
bool v[1005];
int c[1005];

int getChild( int x ){
	v[x] = 1;
    int si = e[x].size();
 
    int tot = 0;
    for(int i=0; i<si; i++)
		if( !v[e[x][i]] )
			tot += getChild( e[x][i] ) + 1;
		
    c[x] = tot;
 
    return tot;
}


int dfs ( int x ){

	v[x] = 1;

	vector <int> t;
	int si = e[x].size();
	int tot = 0;
	int add = 0;
	for(int i=0; i<si; i++){
		if( !v[e[x][i]] ){
			t.push_back( 1 + c[e[x][i]] - dfs( e[x][i] ) );
			add += c[e[x][i]]+1;
			tot ++;
		}
	}

	if( tot >= 2 ) {
		sort( t.begin(), t.end() );
		return add - (t[tot-1] + t[tot-2]);
	}
	else if( tot == 1 )
		return add;
	else
		return 0;

}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);

	for(int R=1; R<=T; R++ ){
		int n;
		scanf("%d", &n);
		for(int i=0; i<n-1; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			e[a].push_back( b );
			e[b].push_back( a );
		}

		int res = INF;
		for(int i=1; i<=n; i++){
			memset( v, 0, sizeof( v ) );
			memset( c, 0, sizeof( c ) );
			getChild( i );
			memset( v, 0, sizeof( v ) );
			res = min( res, dfs( i ) );
		
		}

		for(int i=1; i<=n; i++)
			e[i].clear();
	
		printf("Case #%d: ", R);
		printf("%d\n", res);
	}
}