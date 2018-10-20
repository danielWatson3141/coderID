#include <stdio.h>
#include <vector>

#define N 1010

using namespace std;

vector<int> adj[N];
int t,n,mx;

int dfs(int u,int p) {
	int cnt = 0,ans = 0,mx = 0,mx1 = 0;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i];
		if(v != p) {
			int k = dfs(v,u);
			if(k > mx) {
				mx1 = mx;
				mx = k;
			}else if(k > mx1) {
				mx1 = k;
			}
			cnt ++;
		}
	}
	if(cnt == 0) return 1;
	if(cnt == 1) return 1;
	return mx + mx1 + 1;
}
int main() {
	scanf("%d",&t);
	for(int Case = 1; Case <= t; Case++) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			adj[i].clear();
		}
		for(int i=0;i<n-1;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int ans = n,mn = n;
		for(int i=1;i<=n;i++) {
			int sum = dfs(i,-1);
			if(n-sum < mn) {
				mn = n-sum;
			}
		}
		printf("Case #%d: %d\n",Case,mn);
	}
	return 0;
}
