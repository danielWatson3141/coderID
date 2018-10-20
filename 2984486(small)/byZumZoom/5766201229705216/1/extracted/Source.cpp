#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

vector < vector < int > > G;
int N, number, local;

vector <bool> U;
vector <int> tree_sz, dp;

void dfs(int v)
{
	U[v] = true;
	vector <int> childs;
	for(int i = 0; i < G[v].size(); ++i)
		if(!U[G[v][i]])
		{
			dfs(G[v][i]);
			childs.push_back(G[v][i]);
			tree_sz[v] += tree_sz[G[v][i]];
		}

	tree_sz[v]++;
	if(childs.size() == 0)
	{
		dp[v] = 0;
		return;
	}
	else if(childs.size() == 1)
	{
		dp[v] = tree_sz[childs[0]];
		return;
	}
	else if(childs.size() == 2)
	{
		dp[v] = dp[childs[0]] + dp[childs[1]];
		return;
	}
	else
	{
		int min_ans = 1000;
		int sum = tree_sz[v] - 1;
		for(int i = 0; i < childs.size(); ++i)
			for(int j = i + 1; j < childs.size(); ++j)
			{
				int cur_ans = sum - tree_sz[childs[i]] - tree_sz[childs[j]] + dp[childs[i]] + dp[childs[j]];
				if(cur_ans < min_ans)
					min_ans = cur_ans;
			}
		dp[v] = min_ans;
		return;
	}
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t)
	{
		cin >> N;
		G.clear();
		G.resize(N);
		U.clear();
		U.resize(N);
		int a, b;
		for(int i = 0; i < N-1; ++i)
		{
			cin >> a >> b;
			G[a-1].push_back(b-1);
			G[b-1].push_back(a-1);
		}

		int minans = 1000;
		for(int i = 0; i < N; ++ i)
		{
			U.assign(N, false);
			tree_sz.assign(N, 0);
			dp.assign(N, 0);
			dfs(i);
			if(dp[i] < minans)
				minans = dp[i];
		}
		cout << "Case #" << t << ": " << minans << endl;
	}

	return 0;
}
