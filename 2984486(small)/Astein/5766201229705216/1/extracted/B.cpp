#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<int> graph[1005];
vector<int> child[1005];
vector<int> num_child;
vector<int> num_remove;

int traverse(int par, int k)
{
	num_child[k] = 1; // self
	for (int i = 0; i < graph[k].size(); ++i)
	{
		int node = graph[k][i];
		if (par == node) continue;
		child[k].push_back(node);
		num_child[k] += traverse(k, node);
	}
	return num_child[k];
}

int calc(int now)
{
	int ret = 0;

	if (child[now].size() == 0)
	{
		ret = 0;
	}
	else if (child[now].size() == 1)
	{
		ret = num_child[child[now][0]];
	}
	else
	{
		vector<int> cs;
		for (int i = 0; i < child[now].size(); ++i)
		{
			int c = calc(child[now][i]);
			int d = num_child[child[now][i]];
			ret += d;
			cs.push_back(c - d);
		}
		sort(cs.begin(), cs.end());
		ret += cs[0] + cs[1];
	}
	
	num_remove[now] = ret;
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int cn = 1; cn <= T; ++cn)
	{
		scanf("%d", &N);
		int ret = N;

		for (int i = 0; i < N; ++i)
			graph[i].clear();

		for (int i = 0; i < N - 1; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b); a--; b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j) child[j].clear();
			num_child.assign(N, 0);
			num_remove.assign(N, 0);

			traverse(-1, i);
			int now = calc(i);
			if (ret > now) ret = now;

			continue;
		}
		printf("Case #%d: %d\n", cn, ret);
	}
	return 0;
}