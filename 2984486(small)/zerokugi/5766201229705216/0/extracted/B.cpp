#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int T, n;
vector< vector<int> > g;

pii dfs(int r, int par){
	int nodes = 0;
	vector<pii> costs(2, pii(100000, 0));
	REP(i, g[r].size()){
		if(g[r][i] != par){
			pii ret = dfs(g[r][i], r);
			costs.push_back(pii(ret.first-ret.second, ret.first));
			nodes += ret.second;
		}
	}
	sort(costs.begin(), costs.end());
	int res = min(nodes, costs[0].first + costs[1].first + nodes);
	nodes ++;
//	printf("%d %2d %d\n", r+1, par+1, res);
	return pii(res, nodes);
}

main(){
	cin >> T;
	REP(t, T){
		int N;
		cin >> N;
		g = vector< vector<int> >(N);
		REP(i, N-1){
			int u, v;
			cin >> u >> v;
			u--;v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = 100000;
		REP(i, N){
			ans = min(ans, dfs(i, -1).first);
		}
		printf("Case #%d: %d\n", t+1, ans);
	}
	return 0;
}
