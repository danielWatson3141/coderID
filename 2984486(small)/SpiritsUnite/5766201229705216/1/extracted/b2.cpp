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
	int lrg = -1;
	int slrg = -1;
	for (int i = 0; i < adjSize[at]; i++)
	{
		if (adjList[at][i] == from) continue;
		int a = sub[adjList[at][i]] - cull[adjList[at][i]];
		if (a > lrg)
		{
			slrg = lrg;
			lrg = a;
		}
		else if (a > slrg) slrg = a;
	}
	if (slrg == -1) return cull[at] = totsub;
	return cull[at] = min(totsub, totsub - lrg - slrg);
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

