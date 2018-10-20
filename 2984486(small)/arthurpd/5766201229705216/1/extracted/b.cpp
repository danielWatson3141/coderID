#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
int n;
vector<int> graph[1123];
int sons[1123];

bool comp(pii a, pii b)
{
	return (a.first-a.second) < (b.first-b.second);
}

int filhos(int a, int p)
{
	int retv = 1;
	for(int i = 0; i < (int)graph[a].size(); i++)
		if(graph[a][i] != p)
			retv += filhos(graph[a][i], a);
	return sons[a] = retv;
}

int root(int a, int p)
{
	if(graph[a].size() == 1 && a != p)
		return 0;
	vector<pair<int, int> > f;
	for(int i = 0; i < (int)graph[a].size(); i++)
		if(graph[a][i] != p)
			f.push_back(pair<int,int> (root(graph[a][i],a), sons[graph[a][i]]));
	sort(f.begin(), f.end(), comp);
	if(f.size() == 1)
		return f[0].second;
	int retv = 0;
	for(int i = 2; i < f.size(); i++)
		retv += f[i].second;
	for(int i = 0; i < 2; i++)
		retv += f[i].first;
	return retv;
}

int
main(void)
{
	int T, t = 1, a, b;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			graph[i].clear();
		for(int i = 0; i < n-1; i++)
		{
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		int ans = 0x3f3f3f3f;
		for(int i = 1; i <= n; i++)
		{
			filhos(i, i);
			ans = min(ans, root(i, i));
		}
		printf("Case #%d: %d\n", t++, ans);
	}
}
