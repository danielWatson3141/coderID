#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include <fstream>

#define MAXN 1001

using namespace std;

int countC(int cur, int childC[MAXN], int childT[MAXN], vector<int> adj[MAXN], bool v[MAXN]);
int remNum(int par, int cur, int childC[MAXN], int childT[MAXN], vector<int> adj[MAXN], bool v[MAXN], int remC[MAXN]);

int T, N, v1, v2;
int main()
{
	string filename = "B-large";
	ifstream fin(filename + ".in");
	FILE *fout = fopen((filename + ".out").c_str(), "w");

	fin >> T;
	for(int t = 1; t <= T; t++)
	{
		fin >> N;

		vector<int>	adj[MAXN];
		for(int i = 0; i < N; i++)
		{
			adj[i] = vector<int>();
		}

		for(int i = 0; i < N - 1; i++)
		{
			fin >> v1 >> v2;
			adj[v1].push_back(v2);
			adj[v2].push_back(v1);
		}

		int mNum = N - 1;
		for(int root = 1; root <= N; root++)
		{
			int childC[MAXN] = {};
			int childT[MAXN] = {};
			bool visited[MAXN] = {};
			countC(root, childC, childT, adj, visited);

			// printf("Root:%d\n", root);
			// for(int i = 1; i <= N; i++)
			// {
			// 	printf("%d:%d ", i, childC[i]);
			// }
			// printf("\n");

			// printf("Root:%d\n", root);
			// for(int i = 1; i <= N; i++)
			// {
			// 	printf("%d:%d ", i, childT[i]);
			// }
			// printf("\n");

			int remC[MAXN] = {};
			bool visited2[MAXN] = {};
			mNum = min(mNum, remNum(root, root, childC, childT, adj, visited2, remC));
			// printf("Root:%d\n", root);
			// for(int i = 1; i <= N; i++)
			// {
			// 	printf("%d:%d ", i, remC[i]);
			// }
			// printf("\n");
			// printf("----------------------------------------\n");
		}

		fprintf(fout, "Case #%d: %d\n", t, mNum);	
	}

	fin.close();
	fclose(fout);
 	return 0;
}

int countC(int cur, int childC[MAXN], int childT[MAXN], vector<int> adj[MAXN], bool v[MAXN])
{
	v[cur] = true;

	int children = 0;
	for(int child : adj[cur])
	{
		if(!v[child])
		{
			children += countC(child, childC, childT, adj, v);
			childT[cur]++;
		}
	}
	childC[cur] = children;

	return children + 1;
}

int remNum(int par, int cur, int childC[MAXN], int childT[MAXN], vector<int> adj[MAXN], bool v[MAXN], int remC[MAXN])
{
	v[cur] = true;

	for(int child : adj[cur])
	{
		if(!v[child])
		{
			remNum(cur, child, childC, childT, adj, v, remC);
		}
	}

	int cost = MAXN;
	if(childT[cur] == 0)
	{
		cost = 0;
	}
	else if(childT[cur] == 1)
	{
		cost = childC[cur];
	}
	else
	{
		for(int i = 0; i < adj[cur].size(); i++)
		{
			for(int j = i + 1; j < adj[cur].size(); j++)
			{
				if(adj[cur][i] != par && adj[cur][j] != par)
				{
					int cCost = childC[cur] - childC[adj[cur][i]] - childC[adj[cur][j]] - 2;
					cCost += remC[adj[cur][i]] + remC[adj[cur][j]];
					// if(cost > cCost)
					// {
					// 	if(par == cur)
					// 	{
					// 		printf("At:%d-(%d,%d) childC[cur]:%d", cur, adj[cur][i], adj[cur][j], childC[cur]);
					// 		printf(" - %d - %d", childC[adj[cur][i]], childC[adj[cur][j]]);
					// 		printf(" + %d + %d", remC[adj[cur][i]], remC[adj[cur][j]]);
					// 		printf(" = %d, %d\n", cCost, cost);
					// 	}
					// }
					cost = min(cost, cCost);					
				}
			}
		}
	}
	remC[cur] = cost;
	return cost;
}