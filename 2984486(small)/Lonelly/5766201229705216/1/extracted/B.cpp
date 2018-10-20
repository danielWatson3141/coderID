#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

int Calculate(int node, int parent, vector<vector<int>> &e, vector<int> &subtree)
{
	subtree[node] += 1;
	for (int k = 0; k < e[node].size(); ++k)
	{
		if (e[node][k] == parent)
		{
			continue;
		}
		subtree[node] += Calculate(e[node][k], node, e, subtree);
	}
	return subtree[node];
}

int Find(int node, int parent, vector<vector<int>> &e, vector<int> &subtree, vector<int> &cache)
{
	if (cache[node] == -1)
	{
		int total = 0;
		for (int i = 0; i < e[node].size(); ++i)
		{
			if (e[node][i] == parent)
			{
				continue;
			}
			total += subtree[e[node][i]];
		}
		cache[node] = total;
		for (int i = 0; i < e[node].size(); ++i)
		{
			if (e[node][i] == parent)
			{
				continue;
			}
			for (int j = i + 1; j < e[node].size(); ++j)
			{
				if (e[node][j] == parent)
				{
					continue;
				}
				int tmp = total - subtree[e[node][i]] - subtree[e[node][j]];
				int findi = Find(e[node][i], node, e, subtree, cache);
				int findj = Find(e[node][j], node, e, subtree, cache);
				cache[node] = min<int>(cache[node], tmp + findi + findj);
			}

		}
	}
	return cache[node];
}

void solve(int index)
{
	cout << "Case #" << index + 1 << ": ";
	int N;
	cin >> N;
	vector<vector<int>> e(N, vector<int>());
	for (int i = 0; i < N - 1; ++i)
	{
		int j, k;
		cin >> j >> k;
		e[j - 1].push_back(k - 1);
		e[k - 1].push_back(j - 1);
	}
	int result = N - 1;
	for (int i = 0; i < N; ++i)
	{
		vector<int> cache(N, -1);
		vector<int> subtree(N, 0);
		for (int j = 0; j < e[i].size(); ++j)
		{
			Calculate(e[i][j], i, e, subtree);
		}
		result = min<int>(result, Find(i, i, e, subtree, cache));
	}
	cout << result;
	cout << endl;
}

int main(int argc, char **argv)
{
	//Sleep(10 * 1000);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		solve(i);
	}
	return 0;
}