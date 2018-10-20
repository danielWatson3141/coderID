#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MaxN = 1111;

struct edge{
	int u, v; edge*next;
} E[MaxN * 3], *P[MaxN], *cur;

void insert(int u, int v){
	edge* e = cur++;
	e->u = u, e->v = v;e->next = P[u];P[u] = e;
}

int dp[1111];
int deg[1111], size[1111];

void dfs(int cur, int fa){
	size[cur] = 1;
	for (edge *e = P[cur]; e != NULL; e = e->next){
		if (e->v != fa){
			deg[cur]++;
			dfs(e->v, e->u);
			size[cur] += size[e->v];
		}
	}
}

int f(int cur, int fa){
	if (deg[cur] == 0)
		return dp[cur] = 0;
	if (dp[cur] != 0)
		return dp[cur];
	if (deg[cur] == 1){
		int cnt = 0;
		for (edge *e = P[cur]; e != NULL; e = e->next){
			if (e->v != fa)
				cnt += size[e->v];
		}
		return dp[cur] = cnt;
	}
	int sum = 0;
	for (edge *e = P[cur]; e != NULL; e = e->next){
		if (e->v != fa){
			f(e->v, e->u);
			sum += size[e->v];
		}
	}
	int best = 0x7fffffff;
	for (edge *e1 = P[cur]; e1 != NULL; e1 = e1->next){
		if (e1->v != fa){
			for (edge *e2 = P[cur]; e2 != NULL; e2 = e2->next){
				if (e2 != e1 && e2->v != fa){
					if (sum - size[e1->v] - size[e2->v] + dp[e1->v] + dp[e2->v] < best)
						best = sum - size[e1->v] - size[e2->v] + dp[e1->v] + dp[e2->v];
				}
			}
		}
	}
	return dp[cur] = best;

}

int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		printf("Case #%d: ", cas);
		memset(E,0,sizeof(E));
		memset(P,0,sizeof(P));
		cur = E;
		int n; scanf("%d", &n);
		for (int i = 0; i < n - 1; i++){
			int u, v; scanf("%d%d", &u, &v);
			insert(u,v); insert(v,u);
		}
		int ans = 0x7fffffff;
		for (int i = 1; i <= n; i++){
			memset(deg,0,sizeof(deg));
			memset(size,0,sizeof(size));
			memset(dp,0,sizeof(dp));
			dfs(i, -1);
			ans = min(ans, f(i, -1));
		}
		printf("%d\n", ans);
	}
}