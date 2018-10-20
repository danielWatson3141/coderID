#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const char inFileName[] = "B-small.in";
const char outFileName[] = "B-small.out";

const int MaxN = 1010;
const int inf = 1000000;

vector<int> adj[MaxN];
int d[MaxN];
int p[MaxN];
int num[MaxN];
bool mark[MaxN];

int T;
int n, m, sol;

void DFS(int u)
{
	mark[u] = true;
	num[u] = 1;
	for (int i = 0; i < (int)adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!mark[v])
		{
			p[v] = u;
			DFS(v);
		}
		if (v != p[u])
		{
			num[u] += num[v];
		}
	}

	d[u] = num[u] - 1;
	int min1 = inf, min2 = inf;
	for (int i = 0; i < (int)adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (v != p[u])
		{
			if (d[v] - num[v] < min1)
			{
				min2 = min1;
				min1 = d[v] - num[v];
			}
			else if (d[v] - num[v] < min2)
			{
				min2 = d[v] - num[v];
			}
		}
	}

	if (min2 != inf)
	{
		d[u] = d[u] + min1 + min2;
	}
}

int main() {
	
	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++) 
	{
		

		fscanf(inFile, "%d", &n);
		for (int i = 1; i < n; i++)
		{
			int a, b;
			fscanf(inFile, "%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		sol = n - 1;
		for (int root = 1; root <= n; root++)
		{
			for (int i = 1; i <= n; i++) p[i] = 0;
			for (int i = 1; i <= n; i++) mark[i] = false;
			DFS(root);
			if (d[root] < sol)
			{
				sol = d[root];
			}
		}

		fprintf(outFile, "Case #%d: %d\n", t + 1, sol);
		for (int i = 0; i <= n; i++)
			adj[i].clear();
	}	
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}
