//Jakub "Cubix651" Cisło
//Zadanie: B
#include <cstdio>
#include <vector>
#include <algorithm>
#define PB push_back
using namespace std;

const int MAX = 1005;
int n, s[MAX], bin[MAX], sonsNum[MAX];
vector<int> g[MAX];
bool vis[MAX];

void clearVis()
{
	for(int i = 0; i <= n; ++i)
		vis[i] = false;
}

void clearCase()
{
	for(int i = 0; i <= n; ++i)
	{
		g[i].clear();
		sonsNum[i] = 0;
	}
}

void size(int v)
{
	vis[v] = true;
	s[v] = 1;
	for(int i = 0; i < g[v].size(); ++i)
	{
		if(!vis[g[v][i]])
		{
			size(g[v][i]);
			s[v] += s[g[v][i]];
		}
	}
}

void binarize(int v)
{
	vis[v] = true;
	bin[v] = 0;
	int m1 = 0, m2 = 0;
	for(int i = 0; i < g[v].size(); ++i)
		if(!vis[g[v][i]])
		{
			binarize(g[v][i]);
			bin[v] += s[g[v][i]];
			if(s[g[v][i]] - bin[g[v][i]] > m2)
			{
				if(s[g[v][i]] - bin[g[v][i]] > m1)
				{
					m2 = m1;
					m1 = s[g[v][i]] - bin[g[v][i]];
				}
				else
				{
					m2 = s[g[v][i]] - bin[g[v][i]];	
				}
			}
		}
	if(sonsNum[v] > 2)
	{
		/*printf("IM HERE\n");
		printf("%d %d\n", m1, m2);*/
		bin[v] -= m1;
		bin[v] -= m2;
	}
}

int solve()
{
	clearCase();
	int a, b;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		g[a].PB(b);
		g[b].PB(a);
		++sonsNum[a];
		++sonsNum[b];
	}
	int res = n+1;
	for(int i = 1; i <= n; ++i)
	{
		clearVis();
		size(i);
		/*for(int j = 1; j <= n; ++j)
			printf("%d\n", s[j]);*/
		clearVis();
		++sonsNum[i];
		binarize(i);
		/*for(int j = 1; j <= n; ++j)
			printf("%d\n", bin[j]);*/
		res = min(res, bin[i]);
		--sonsNum[i];
	}
	return res;
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i)
		printf("Case #%d: %d\n", i, solve());
	return 0;
}
