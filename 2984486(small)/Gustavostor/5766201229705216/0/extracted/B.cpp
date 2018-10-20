#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define sf(a) scanf("%d", &a)
#define sf2(a,b) scanf("%d%d", &a, &b)
#define sf3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sf4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
typedef long long ll;
typedef pair<ll,ll> pii;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f
#define MOD 10007

#define MAXN 1010
#define MAXM 1010

#define add(a,b) to[z] = b, ant[z] = adj[a], adj[a] = z++
int to[MAXM], ant[MAXM], adj[MAXN], z;

int T, N;
int q[MAXN], p[MAXN], dp[MAXN];

int dfscnt(int u, int pai) {
	int cnt = 1;
	p[u] = pai;
	for (int j = adj[u]; ~j; j = ant[j]) {
		int v = to[j];
		if (v != pai) cnt += dfscnt(v,u);
	}
	return q[u] = cnt;
}

int go(int u) {
	int &pd = dp[u];
	if (~pd) return pd;

	int cnt = 0, total = 0;
	int p1 = oo, p2 = oo;
	for (int j = adj[u]; ~j; j = ant[j]) {
		int v = to[j];
		if (v != p[u]) {
			total += q[v];
			cnt++;
			int aux = go(v) - q[v];
			if (aux < p1) p2 = p1, p1 = aux;
			else if (aux < p2) p2 = aux;
		}
	}
	if (cnt == 0) return pd = 0;
	else if (cnt == 1) return pd = total;
	else return pd = total + p1 + p2;
}

int main() {
	int cas = 1;
	scanf("%d", &T);
	while (T--) {
		cl(adj,-1); z = 0;
		scanf("%d", &N);
		rp(i,N-1) {
			int a, b;
			scanf("%d%d", &a, &b); a--, b--;
			add(a,b);
			add(b,a);
		}
		int res = oo;
		rp(i,N) {
			cl(dp,-1);
			dfscnt(i, -1);
			res = min(res, go(i));
		}
		printf("Case #%d: %d\n", cas++, res);
	}
}