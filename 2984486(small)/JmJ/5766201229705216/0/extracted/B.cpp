#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
using namespace std;
vector<int> g[1001];
int nodos[1001][1001];

int dfs( int s, int p ){
	int res = 1;
	for( int i = 0; i < g[s].size(); i++){
		int u = g[s][i];
		if ( u == p ) continue;
		res += dfs( u , s );
	}
	return res;
}

bool check(int s, int p){
	if ( g[s].size() != 1 && g[s].size() != 3) return false;
	int res = 1;
	for( int i = 0; i < g[s].size(); i++){
		if ( g[s][i] == p ) continue;
		res &= check( g[s][i] , s );
		int u = g[s][i];
		
	}
	return res;
}
int m[1001][1001]; // root, parent
int res ;
int n;
int solve( int , int );
void solve(){
	for( int i = 0; i < n; i++){
		for( int j = 0; j < g[i].size(); j++){
			nodos[i][g[i][j]] = dfs(i, g[i][j] );
			if (check(i, g[i][j] )){
				m[i][g[i][j]] = true;
			}
		}
	}
	int ans = 1<<30;
	for( int i = 0; i < n; i++){
		ans = min( ans, solve(i,-1));
	}
	printf("%d\n", ans);
}

int solve( int i, int p ){
	if ( g[i].size() == 2 && p != -1 ) return nodos[i][p] - 1;
//	if ( g[i].size() == 2 && p != -1 ) return 1;
	int res = 0;
	vector<int> v;
	
	for( int j = 0; j < g[i].size(); j++){
		int u = g[i][j];
		if ( u == p ) continue;
		if ( m[u][i] ) v.push_back( g[u].size() );
		else{
			res += solve( u, i );
		}
	}
	sort( v.rbegin(),v.rend());
	for( int j = 2; j < v.size() ; j++){
		res += v[j];
	}
	return res;
}

int main(){
	int runs;
	scanf("%d",&runs);
	for( int r = 1; r <= runs; r++){
		printf("Case #%d: ",r);
		scanf("%d",&n);
		for( int i = 0; i < n; i++) g[i].clear();
		memset( nodos, 0, sizeof nodos);
		memset(m , 0, sizeof m );
		for( int i = 0; i < n - 1; i++){
			int u , v;
			scanf("%d%d",&u,&v);
			u--,v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		solve();
	}


	return 0;
}
