#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define N 1005
using namespace std;

int n, x, y, ed;
int l[N], qd[N+N], qn[N+N], dp[N], sz[N];

void bd(int x, int y){
	qd[++ed] = y, qn[ed] = l[x], l[x] = ed;
}

int dfs(int x, int p){
	int cnt = 0;
	sz[x] = 1;
	EXP(i,l[x]) if (qd[i] != p){
		dfs(qd[i], x);
		sz[x] += sz[qd[i]];
		++cnt;
	}
	dp[x] = sz[x] - 1;
	if (cnt >= 2){
		int mn[2] = {n, n};
		EXP(i,l[x]) if (qd[i] != p){
			int t = dp[qd[i]] - sz[qd[i]];
			if (t <= mn[0]) mn[1] = mn[0], mn[0] = t;
			else mn[1] = min(mn[1], t);
		}
		dp[x] = min(dp[x], mn[0] + mn[1] + sz[x] - 1);
	}
	return dp[x];
}

void solve(int tc){
	int x, y;
	scanf("%d", &n);
	ed = 0;
	CLR(l, 0);
	FOR(i,0,n-1){
		scanf("%d%d", &x, &y), x--, y--;
		bd(x, y), bd(y, x);
	}
	int ret = n - 1;
	FOR(i,0,n) ret = min(ret, dfs(i, -1));
	printf("Case #%d: %d\n", tc, ret);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
