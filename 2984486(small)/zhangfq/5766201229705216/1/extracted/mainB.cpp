#include <stdio.h>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <iostream>
using namespace std;

const int MAXN = 1001;
bool graph[MAXN][MAXN];
int n;
int childnode[MAXN][MAXN];
int childnum[MAXN];
bool inTree[MAXN];
int subChildNum[MAXN];
int deleteNum[MAXN];
int ans;

void buildTree(int rootn)
{
	int i, j;
	for (i = 0; i < n; ++ i)
	{
		if (inTree[i])
		{
			continue;
		}
		if (graph[rootn][i])
		{
			inTree[i] = true;
			childnode[rootn][childnum[rootn]] = i;
			childnum[rootn]++;			
		}
	}
	subChildNum[rootn] = 1;
	deleteNum[rootn] = 0;
	for (i = 0; i < childnum[rootn]; ++ i)
	{
		int iChild = childnode[rootn][i];
		buildTree(iChild);
		subChildNum[rootn] += subChildNum[iChild];
		deleteNum[rootn] += deleteNum[iChild];
	}
	if (childnum[rootn] == 1)
	{
		deleteNum[rootn] = subChildNum[rootn] - 1;
	}
	else if (childnum[rootn] > 2)
	{
		deleteNum[rootn] = subChildNum[rootn] - 1;
		for (i = 0; i < childnum[rootn]; ++ i)
		{
			int iChild1 = childnode[rootn][i];
			for (j = i+1; j < childnum[rootn]; ++ j)
			{
				int iChild2 = childnode[rootn][j];
				int curn = subChildNum[rootn] - 1 
					- subChildNum[iChild1] - subChildNum[iChild2] 
					+ deleteNum[iChild1] + deleteNum[iChild2];
				if (curn < deleteNum[rootn])
				{
					deleteNum[rootn] = curn;
				}
			}
		}
	}
}

int main()
{
	//freopen("B-small-attempt3.in", "r", stdin);
	//freopen("B-small-attempt3.out", "w", stdout);


	int nCase;
	int t;
	int i, j, k;
	int a, b;
	scanf("%d", &nCase);
	for (t = 1; t <= nCase; ++ t)
	{
		for (i = 0; i < n; ++ i)
		{
			for (j = 0; j < n; ++ j)
			{
				graph[i][j] = false;
			}
		}
		scanf("%d", &n);
		for (i = 1; i < n; ++ i)
		{
			scanf("%d%d", &a, &b);
			a--;
			b--;
			graph[a][b] = graph[b][a] = true;
		}

		ans = n;
		for (i = 0; i < n; ++ i)
		{
			//root = i;
			for (j = 0; j < n; ++ j)
			{
				inTree[j] = false;
				childnum[j] = 0;
			}
			inTree[i] = true;
			buildTree(i);
			if (deleteNum[i] < ans)
			{
				ans = deleteNum[i];
			}
		}

		printf("Case #%d: %d", t, ans);

		if (t < nCase)
		{
			printf("\n");
		}
	}

	//system("pause");
	return 0;
}

