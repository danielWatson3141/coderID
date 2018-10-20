#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define INF 0x3fffffff
#define MAX_EDGE_NUM 4000
#define MAX_NODE_NUM 2000

struct edge
{
	int u, v;
	int next;
} edge[MAX_EDGE_NUM];

int vis[MAX_NODE_NUM], edge_num, head[MAX_NODE_NUM];
int num[MAX_NODE_NUM];
int degree[MAX_NODE_NUM];
int dp[MAX_NODE_NUM];
int node_num;

void add_edge(int u, int v)
{
	edge[edge_num].u = u;
	edge[edge_num].v = v;
	edge[edge_num].next = head[u];
	head[u] = edge_num++;
}

int dfs(int s)
{
	vis[s] = 1;
	int dpt = 0;
	vector<int> tsort;
	for (int i = head[s]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if (vis[v] == 1)
			continue;
		dfs(v);
		num[s] += num[v] + 1;
		tsort.push_back((num[v] + 1) - dp[v]);
		degree[s]++;
		dpt += dp[v];
	}
	if (degree[s] == 0)
	{
		dp[s] = 0;
		num[s] = 0;
		return 0;
	}
	if (degree[s] == 2)
	{
		dp[s] = dpt;
		return 0;
	}
	if (degree[s] == 1)
	{
		dp[s] = num[s];
		return 0;

	}
	sort(tsort.begin(), tsort.end());

	dp[s] = num[s] - tsort[tsort.size() - 1] - tsort[tsort.size() - 2];
	return 0;

}

void input()
{
	scanf("%d", &node_num);
	memset(degree, 0, sizeof(degree));
	edge_num = 0;
	memset(head, -1, sizeof(head));
	for (int i = 0; i < node_num - 1; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add_edge(x, y);
		add_edge(y, x);
	}
}

int work()
{
	int ret = INF;
	for (int i = 1; i <= node_num; i++)
	{
		memset(vis, 0, sizeof(vis));
		memset(degree, 0, sizeof(degree));
		memset(dp, 0, sizeof(dp));
		memset(num, 0, sizeof(num));
		dfs(i);
		int temp = dp[i];
		if (ret > temp)
			ret = temp;
	}
	return ret;
}

int main()
{
	int case_num;
	scanf("%d", &case_num);
	for (int i = 0; i < case_num; i++)
	{
		input();
		int ans = work();
		printf("Case #%d: %d\n", i + 1, ans);
	}
	return 0;
}
