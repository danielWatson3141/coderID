#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;

int T;
int n;
vector<vector<int> > next;
int dp[1234];
int best;

void dfs(int v, int f);

int main()
{
	scanf("%d", &T);

	for(int q=1; q<=T; q++) {
		scanf("%d", &n);
		next.clear();
		next.resize(n);
		for(int i=0; i<n-1; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			u--; v--;
			next[u].push_back(v);
			next[v].push_back(u);
		}
		best=0;
		for(int r=0; r<n; r++) {
			dfs(r, -1);
			best=max(dp[r], best);
		}
		printf("Case #%d: %d\n", q, n-best);
	}

	return 0;
}

void dfs(int v, int f)
{
	int max1=0, max2=0;
	for(int i=0; i<next[v].size(); i++) {
		int s=next[v][i];
		if(s==f) continue;
		dfs(s, v);
		if(dp[s]>max1) {
			max2=max1;
			max1=dp[s];
		}
		else if(dp[s]>max2) {
			max2=dp[s];
		}
	}
	if(max2>0) dp[v]=1+max1+max2;
	else dp[v]=1;
}
