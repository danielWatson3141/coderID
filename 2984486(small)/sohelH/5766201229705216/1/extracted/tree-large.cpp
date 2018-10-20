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
const int MAX = 1005;
vector<int> g[MAX];
int total;
int vis[MAX];

int dfs(int u) {
	vis[u] = 1;
	int children = 0;
	vector<int> v;
	for (int i = 0; i < g[u].size(); i++) {
		if (vis[g[u][i]] == 0) children++, v.push_back(g[u][i]);
	}

	if (children <= 1) {
		return 1;
	} else if (children == 2) {
		return 1 + dfs(v[0]) + dfs(v[1]);
	} else {
		int best = 0;
		vector<int> A;
		for (int i = 0;  i < v.size(); i++) A.push_back(dfs(v[i]));
		sort(A.begin(), A.end());
		reverse(A.begin(), A.end());
		return 1 + A[0] + A[1];
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
		for(int i = 0; i < n; i++) g[i].clear();
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			g[a].push_back(b); g[b].push_back(a);
		}

		int res = 0;

		for (int i = 0; i < n; i++) {
			int k = findBest(i);
			res = max(res, k);
		}
		printf("Case #%d: %d\n", cases, n - res);
	}
	return 0;
}
