#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

const int MAXN = 1010;
int n;
struct edge {
	int t;
	edge *next;
}epool[MAXN * 2], *e[MAXN];
int psz;
multiset<int> s[MAXN];
int f[MAXN];
int ans;

void add_edge(int u, int v)
{
	edge e1 = {v, e[u]};
	e[u] = &(epool[psz++] = e1);
}

void init()
{
	psz = 0; memset(e, 0, sizeof(e));
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	ans = 0;
}

void dfs(int u, int fa)
{
	s[u].clear();
	for (edge *i = e[u]; i; i = i->next) {
		if (i->t == fa) continue;
		dfs(i->t, u);
		s[u].insert(f[i->t]);
	}
	f[u] = s[u].size() < 2 ? 1 : *s[u].rbegin() + *++s[u].rbegin() + 1;
}

void change(int u, int v)
{
	s[u].erase(s[u].find(f[v]));
	f[u] = s[u].size() < 2 ? 1 : *s[u].rbegin() + *++s[u].rbegin() + 1;
	s[v].insert(f[u]);
	f[v] = s[v].size() < 2 ? 1 : *s[v].rbegin() + *++s[v].rbegin() + 1;
}

void dfs2(int u, int fa)
{
	ans = max(ans, f[u]);
	for (edge *i = e[u]; i; i = i->next) {
		if (i->t == fa) continue;
		change(u, i->t);
		dfs2(i->t, u);
		change(i->t, u);
	}
}

int main()
{
	int dat;
	scanf("%d", &dat);
	for (int cas = 1; cas <= dat; ++cas) {
		init();
		dfs(1, 0);
		dfs2(1, 0);
		printf("Case #%d: %d\n", cas, n - ans);
	}
}
