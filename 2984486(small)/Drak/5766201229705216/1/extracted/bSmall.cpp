#include <bits/stdc++.h>
using namespace std;
#define INF (1<<30)
#define WHITE 0
#define GREY 1
#define msg(x) cout<<#x<<" = "<<x<<endl;
#define N 1020
vector<int> adj[N];
int color[N];
int dfs(int node) {
	color[node] = GREY;
	int ans = 1;
	int hijos = 0;
	for(int i=0 ; i<adj[node].size() ; i++) {
		if( color[adj[node][i]] == WHITE ) hijos++;
	}
	if( hijos >= 2 ) {
		int max1 = -INF, max2 = -INF;
		for(int i=0 ; i<adj[node].size() ; i++) {
			int u = adj[node][i];
			if( color[u] == WHITE ){
				int ret = dfs(u);
				if( max1 < max2 ) swap(max1, max2);
				if( ret > max1 ) {
					max2 = max1;
					max1 = ret;
				} else {
					if( ret > max2 ) {
						max2 = ret;
					}
				}
			}
		}
		ans += max1 + max2;
	}
	return ans;
}
int main() {
    //ios_base::sync_with_stdio(0);
	int T, n, u, v;
	scanf("%d", &T);
	for(int caso=1 ; caso<=T ; caso++) {
		scanf("%d", &n);
		for(int i=1 ; i<n ; i++) {
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int ans = INF;
		for(int i=1 ; i<=n ; i++) {
			memset(color, WHITE, sizeof(color));
			int ret = dfs(i);
			//cout<<i<<" "<<ret<<endl;
			ans = min(ans, n - ret);
		}
		printf("Case #%d: %d\n", caso, ans);
		for(int i=0 ; i<=n ; i++) adj[i].clear();
	}
    return 0;
}