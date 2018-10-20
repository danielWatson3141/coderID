#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

vector<int> adj[1005];
vector<int> chd[1005];
int cnt[1005];
int n;

void dfs(int u, int p) {
	cnt[u] = 1;
	for(int i=0;i<adj[u].size();++i) {
		int v = adj[u][i];
		if(v == p) continue;
		chd[u].push_back(v);
		dfs(v, u), cnt[u] += cnt[v];
	}
}

int dp[1005];
int go(int u) {
	int &ret = dp[u];
	if(ret != -1) return ret;
	ret = 1000000;

	vector<int> list(chd[u].size(),0);
	int below = 0;
	for(int i=0;i<chd[u].size();++i) {
		int v = chd[u][i];
		below += cnt[v];
		list[i] = go(v)-cnt[v];
	}
	if(chd[u].size() < 2) return ret = below;
	else {
		sort(list.begin(),list.end());
		ret = below + (list[0] + list[1]);
	} return ret;
}

int main() {
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int Ts;
	scanf("%d",&Ts);
	for(int cs=1;cs<=Ts;++cs) {
		for(int j=0;j<1005;++j) adj[j].clear();

		printf("Case #%d: ", cs);

		scanf("%d",&n);
		for(int i=0;i<n-1;++i) {
			int u,v; scanf("%d%d",&u,&v);
			u--,v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int ans = 1<<30;
		for(int r=0;r<n;++r) {
			memset(dp,-1,sizeof(dp));
			for(int i=0;i<n;++i) chd[i].clear();
			dfs(r,-1);
			ans = min(ans, go(r));
		} printf("%d\n",ans);
	}
}