#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define rep(i, n) fr(i, 0, n)
#define N 2000
#define mp make_pair
#define pb push_back
#define ft first
#define sd second
typedef pair<int,int> pii;
#define oo 1000000000

vector<int> adj[N];
int size[N];
int n;


void dfs(int no, int dad){
	size[no] = 1;

	// printf("> %d %d\n", no, adj[no].size());
	for(int nt : adj[no]){
		if(nt == dad) continue;
		dfs(nt, no);
		size[no] += size[nt];
	}
}

int calc(int no, int dad){
	int best = 0, c = 0;
	for(int nt : adj[no]) if(nt != dad) best += size[nt], c++;

	if(c >= 2){
		int sum = best;

		rep(i, adj[no].size()){
			if(adj[no][i] == dad) continue;

			fr(j, i+1, adj[no].size()){
				if(adj[no][j] == dad) continue;
				best = min(best, sum - size[adj[no][i]] - size[adj[no][j]] + calc(adj[no][i], no) + calc(adj[no][j], no));
			}
		}
	}

	return best;
}



int main(){
	int t;
	scanf("%d", &t);

	fr(cc, 1, t+1){
		scanf("%d", &n);
		rep(i, n) adj[i].clear();

		rep(i, n-1){
			int u, v;
			scanf("%d%d", &u, &v);
			--u, --v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		int ans = oo;
		rep(i, n){
			dfs(i, -1);
			ans = min(ans, calc(i, -1));
		}

		printf("Case #%d: %d\n", cc, ans);
	}

}