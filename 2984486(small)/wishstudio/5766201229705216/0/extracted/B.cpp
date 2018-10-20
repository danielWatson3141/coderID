#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define maxN 2000

int N;
vector<int> edges[maxN];
int cnt[maxN], ans[maxN];
int arr[maxN];

void dfs(int u, int parent)
{
	cnt[u] = 0;
	int gain1 = INT_MAX, gain2 = INT_MAX;
	for (int v: edges[u])
		if (v != parent)
		{
			dfs(v, u);
			cnt[u] += cnt[v] + 1;
			int gain = ans[v] - (cnt[v] + 1);
			if (gain < gain1)
			{
				gain2 = gain1;
				gain1 = gain;
			}
			else if (gain < gain2)
				gain2 = gain;
		}
	if (gain2 < INT_MAX && gain1 + gain2 < 0)
		ans[u] = cnt[u] + gain1 + gain2;
	else
		ans[u] = cnt[u];
}

int main()
{
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
			edges[i].clear();
		for (int i = 1; i < N; i++)
		{
			int u, v;
			cin >> u >> v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		int best = INT_MAX;
		for (int i = 1; i <= N; i++)
		{
			dfs(i, -1);
			best = min(best, ans[i]);
		}
		cout << "Case #" << z << ": " << best << endl;
	}
	return 0;
}
