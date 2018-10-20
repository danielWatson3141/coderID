#include <iostream>
#include <vector>

using namespace std;

int T;
int n;
int adjList[1024][1024];
int adjSize[1024];
int sub[1024];
int cull[1024];

int gsub(int at, int from)
{
	int ans = 0;
	for (int i = 0; i < adjSize[at]; i++)
	{
		if (adjList[at][i] != from)
			ans += gsub(adjList[at][i], at);
	}
	return sub[at] = ans + 1;
}

int dp(int at, int from)
{
	int totsub = 0;
	for (int i = 0; i < adjSize[at]; i++)
	{
		if (adjList[at][i] != from)
		{
			dp(adjList[at][i], at);
			totsub += sub[adjList[at][i]];
		}
	}
	int ans = totsub;
	for (int i = 0; i < adjSize[at]; i++)
	{
		if (adjList[at][i] == from) continue;
		for (int j = i + 1; j < adjSize[at]; j++)
		{
			if (adjList[at][j] == from) continue;
			int a = adjList[at][i], b = adjList[at][j];
			ans = min(ans, totsub - sub[a] - sub[b] + cull[a] + cull[b]);
		}
	}
	return cull[at] = ans;
}

int main()
{
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		cin >> n;
		for (int i = 0; i < n-1; i++)
		{
			int a, b;
			cin >> a >> b;
			adjList[a][adjSize[a]++] = b;
			adjList[b][adjSize[b]++] = a;
		}

		int ans = 1024;
		for (int i = 1; i <= n; i++)
		{
			gsub(i, -1);
			ans = min(ans, dp(i, -1));
		}
		cout << "Case #" << C << ": " << ans << '\n';

		for (int i = 1; i <= n; i++)
		{
			adjSize[i] = 0;
		}
	}
	return 0;
}

