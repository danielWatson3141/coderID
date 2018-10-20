#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>

using namespace std;

struct edge
{
	int next, id;
}egs[2020];

int ver[1010],epos;

void addedge(int a, int b)
{
	egs[epos].id = b;
	egs[epos].next = ver[a];
	ver[a] = epos++;
}

void init()
{
	memset(ver, -1, sizeof(ver));
	epos = 0;
}

int n;

int sz[1010];
bool vis[1010];

int dfs0(int r)
{
	vis[r] = true;
	int i, k, s = 1;
	for (i = ver[r]; i != -1; i = egs[i].next)
	{
		k = egs[i].id;
		if (!vis[k])
		{
			s += dfs0(k);
		}
	}
	return sz[r] = s;
}

int dfs1(int r)
{
	vis[r] = true;
	int i, k, x = 0;
	vector<int> v;
	for (i = ver[r]; i != -1; i = egs[i].next)
	{
		k = egs[i].id;
		if (!vis[k])
		{
			v.push_back(dfs1(k));
		}
	}
	if (v.size() == 0) return 0;
	sort(v.begin(), v.end());
	if (v.size() == 1)
	{
		x = 1 + v[0];
	}
	else
	{
		i = v.size() - 1;
		while (i >= 2)
		{
			x += 1 + v[i];
			i--;
		}
		while (i >= 0)
		{
			x += v[i];
			i--;
		}
	}
	return x;
}

int judge()
{
	
	int r, mi = 1000000, i;
	for (i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		r=dfs1(i);
		mi = min(mi, r);
	}
	return mi;
	
	
	
}

int main()
{
	int t, ca, a, b;
	int i;
	scanf("%d", &t);
	for (ca = 1; ca <= t; ca++)
	{
		scanf("%d", &n);
		init();
		for (i = 1; i < n; i++)
		{
			scanf("%d%d", &a, &b);
			addedge(a, b);
			addedge(b, a);
		}
		printf("Case #%d: %d\n", ca, judge());
	}
	return 0;
}