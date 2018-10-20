/*
* Google Code Jam 2014
* @author: Sohel Hafiz
*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

int n;
int g[16][16];
int total;
int vis[16];
int dp[16];
int dfs(int u) {
	vis[u] = 1;
	int children = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (g[u][i] && vis[i] == 0) children++, v.push_back(i);
	}

	if (children <= 1) {
		return 1;
	} else if (children == 2) {
		return 1 + dfs(v[0]) + dfs(v[1]);
	} else {
		int best = 0;
		int A[16];
		for (int i = 0;  i < v.size(); i++) A[i] = dfs(v[i]);
		for (int i = 0; i < v.size(); i++)
			for (int j = i + 1; j < v.size(); j++) {
				int k = A[i] + A[j];
				best = max(best, k);
			}
		return 1 + best;
	}
}

int findBest(int root) {
	total = 0;
	memset(vis, 0, sizeof(vis));
	int res = dfs(root);
	return res;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		cin >> n;
		memset(g, 0, sizeof(g));
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			g[a][b] = g[b][a] = 1;
		}

		int res = 0;

		for (int i = 0; i < n; i++) {
			int k = findBest(i);
			//cout << i << " " << k << " --" << endl;
			res = max(res, k);
		}
		printf("Case #%d: %d\n", cases, n - res);
	}
	return 0;
}
