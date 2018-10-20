#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector<vector<int>> treeNode;
vector<vector<int>> sonTreeNode;
int dp[2000];
int numofDelete[2000];
int calcDelteNode(int u,int root)
{
	numofDelete[u] = 1;
	for (int i = 0; i < treeNode[u].size(); ++i)
	{
		if (treeNode[u][i] != root)
		{
			sonTreeNode[u].push_back(treeNode[u][i]);
			numofDelete[u] += calcDelteNode(treeNode[u][i],u);
		}
	}
	return numofDelete[u];
}
int solve(int i)
{
	if (dp[i] >= 0)
	{
		return dp[i];
	}
	if (sonTreeNode[i].empty())
	{
		dp[i] = 0;
		return dp[i];
	}
	else if (sonTreeNode[i].size() == 1)
	{
		dp[i] = numofDelete[sonTreeNode[i][0]];
		return dp[i];
	}
	else
	{
		int res = -1;
		for (int p = 0; p < sonTreeNode[i].size(); ++p)
		{
			for (int q = p+1; q < sonTreeNode[i].size(); ++q)
			{
				int temp = solve(sonTreeNode[i][p]) + solve(sonTreeNode[i][q]) - numofDelete[sonTreeNode[i][p]] - numofDelete[sonTreeNode[i][q]] + numofDelete[i] -1;
				if (res == -1 || temp < res)
				{
					res = temp;
				}
			}
		}
		return res;
	}

}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T;
	int N;
	int a,b;
	
	scanf("%d",&T);
	for (int t = 1; t <= T; ++t)
	{
		scanf("%d",&N);
		treeNode.clear();
		sonTreeNode.clear();
		sonTreeNode.resize(N+1);
		treeNode.resize(N+1);
		for (int i = 0; i < N - 1; ++i)
		{
			scanf("%d%d",&a,&b);
			treeNode[a].push_back(b);
			treeNode[b].push_back(a);
		}
		int ans = -1;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				sonTreeNode[j].clear();
			}
			fill(dp,dp+N+1,-1);
			calcDelteNode(i,-1);
			int num = solve(i);
			if (ans == -1 || ans > num)
			{
				ans = num;
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}