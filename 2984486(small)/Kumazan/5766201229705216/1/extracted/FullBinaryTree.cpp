#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> edge[1001];
int visit[1001];
int TreeSize(int node)
{
	int ans = 1;
	for(int x : edge[node])
		if(!visit[x])
		{
			visit[x] = 1;
			ans += TreeSize(x);
			visit[x] = 0;
		}
	// printf("treeSize(%d) = %d\n", node, ans);
	return ans;
}
int FBT(int node)
{
	int childNum = 0, treeSizeSum = 0;
	int firstLarge = 0, secondLarge = 0;
	for(int x : edge[node])
		if(!visit[x])
		{
			visit[x] = 1;
			childNum++;
			int treeSize = TreeSize(x);
			int tmp = treeSize - FBT(x);
			treeSizeSum += treeSize;
			if(tmp > firstLarge)
			{
				secondLarge = firstLarge;
				firstLarge = tmp;
			}
			else if(tmp > secondLarge)
				secondLarge = tmp;
			visit[x] = 0;
		}
	if(childNum == 0)
		return 0;
	if(childNum == 1)
		return treeSizeSum;
	return treeSizeSum - firstLarge - secondLarge;
}
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	for(int caseNum = 1; caseNum <= T; caseNum++)
	{
		int N, ans = 1000;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++)
			edge[i].clear();
		for(int i = 1; i < N; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		for(int i = 1; i <= N; i++)
		{
			visit[i] = 1;
			int tmp = FBT(i);
			visit[i] = 0;
			ans = tmp < ans ? tmp : ans;
		}
		printf("Case #%d: %d\n", caseNum, ans);
	}
	return 0;
}