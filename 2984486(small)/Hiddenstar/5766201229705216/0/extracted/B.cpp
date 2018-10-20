#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
int he[1200], g[2500], nxt[2500], po;
inline void addedge(int s, int t){
	nxt[++ po] = he[s]; he[s] = po; g[po] = t;
}
int n;
inline bool cmp(PII x, PII y){
	return x.second - x.first > y.second - y.first;
}
PII dfs(int x, int la){
	vector<PII> d;
	int sz = 1, pd = 0;
	for (int i = he[x]; i; i = nxt[i])
		if (g[i] != la){
			d.push_back(dfs(g[i], x) );
		}
	for (int i = 0; i < d.size(); ++ i)
		sz += d[i].second;
	if (d.size() < 2){
		return make_pair(sz - 1, sz);
	}
	sort(d.begin(), d.end(), cmp);
	pd = sz;
	pd -= (d[0].second - d[0].first) + (d[1].second - d[1].first);
	return make_pair(pd - 1, sz);
}
inline void work(){
	po = 0;
	memset(he, 0, sizeof he);
	scanf("%d", &n);
	for (int i = 1; i < n; ++ i){
		int s, t;
		scanf("%d%d", &s, &t);
		addedge(s, t);
		addedge(t, s);
	}
	int ans = n;
	for (int i = 1; i <= n; ++ i)
		ans = min(ans, dfs(i, -1).first);
	printf("%d\n", ans);
}
int main(){
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
	int T;scanf("%d", &T);
	for (int cs = 1; cs <= T; ++ cs){
		printf("Case #%d: ", cs);
		work();
	}
}
