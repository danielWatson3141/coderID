#include<bits/stdc++.h>

#define fr(a,b) for(int a = 0; a < b; a++)
#define frr(a,b,c) for(int a = b; a < c; a++)
#define ms(a,b) memset(a, b, sizeof(a))
#define INF 0x3f3f3f3f
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define ll long long
#define scs(s) scanf("%s", s)
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define pri(x) printf("%d\n", x)
#define vi vector<int>
#define vii vector< vi >

using namespace std;

int n, l, grau[1009];
vii adj;

int proc(int v, int pai) {
	if (grau[v] + (pai == -1? 0: -1) < 2) return 1;
	int ma = -1, mb = -1, opt;
	fr(x, adj[v].size()) if (adj[v][x] != pai) {
		opt = proc(adj[v][x], v);
		if (ma == -1 || opt > ma) {
			mb = ma; ma = opt;
		} else if (mb == -1 || opt > mb) mb = opt;
	}
	return ma+mb+1;
}

int main() {
    //freopen("B-small-attempt0.in", "r", stdin);
	//freopen("out", "w", stdout);
	int t, cn = 1;
	sc(t);
	while (t--) {
		printf("Case #%d: ", cn++);
		sc(n);
		adj = vii(n, vi());
		ms(grau, 0);
		fr(x, n-1) {
			int a, b;
			sc2(a, b); a--; b--;
			grau[a]++; grau[b]++;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int ans = 1;
		fr(x, n) ans = max(ans, proc(x, -1));
		pri(n - ans);
	}
	return 0;
}
