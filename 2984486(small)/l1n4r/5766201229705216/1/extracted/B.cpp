
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <memory.h>
using namespace std;

vector<int> g[1024];
int s[1024][1024];

int comp_s(const int u, const int w)
{
	if (s[u][w] >= 0)
	{
		return s[u][w];
	}

	int s_ = 1;

	for (int j = 0; j < g[u].size(); j++)
	{
		const int v = g[u][j];
		if (v != w)
		{
			s_ += comp_s(v, u);
		}
	}

	s[u][w] = s_;
	return s_;
}

int comp(const int root, const int parent)
{
	vector<int> tmp;

	int t = 0;
	for (int i = 0; i < g[root].size(); i++)
	{
		const int v = g[root][i];
		if (v != parent)
		{
			tmp.push_back(v);
			t += s[v][root];
		}
	}

	if (tmp.empty())
	{
		return 0;
	}

	for (int i = 0; i < tmp.size()-1; i++)
	{
		for (int j = i+1; j < tmp.size(); j++)
		{
			int q = comp(tmp[i],root) + comp(tmp[j],root);
			for (int k = 0; k < tmp.size(); k++)
			{
				if (k != i && k != j)
				{
					q += s[tmp[k]][root];
				}
			}
			t = min(t,q);
		}
	}

	return t;
}

int main()
{
	int test_cases;
	scanf("%d", &test_cases);

	for (int test_case = 1; test_case <= test_cases; test_case++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			g[i].clear();
			for (int j = 0; j < n; j++)
			{
				s[i][j] = -1;
			}
		}

		for (int i = 0; i <n-1; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			x--;
			y--;

			g[x].push_back(y);
			g[y].push_back(x);
		}

		for (int u = 0; u < n; u++)
		{
			for (int j = 0; j < g[u].size(); j++)
			{
				const int w = g[u][j];
				comp_s(u, w);

				//printf("%d %d : %d\n", u, w, s[u][w]);
			}
		}

		int ans = 1e6;
		for (int root = 0; root < n; root++)
		{
			ans = min(ans, comp(root,-1));
		}

		printf("Case #%d: %d\n", test_case, ans);
	}

	return 0;
}