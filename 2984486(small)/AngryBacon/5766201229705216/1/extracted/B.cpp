#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)

const int N = 100000 + 10;

int n;
vector<int> adj[N];
int f[N], size[N];

int dfs(int u, int father)
{
	vector<int> vec;
	int v;
	size[u] = 1;
	foreach(it, adj[u]) {
		v = *it;
		if (v == father) continue;
		int tmp = dfs(v, u);
		vec.push_back(-size[v] + tmp);
		size[u] += size[v];
	}
	f[u] = size[u] - 1;
	if (vec.size() >= 2) {
		sort(vec.begin(), vec.end());
		int tmp = size[u] - 1;
		for(int i = 0; i < 2; ++ i) {
			tmp += vec[i];
		}
		f[u] = min(f[u], tmp);
	}
	return f[u];
}

void solve(int test)
{
	printf("Case #%d: ", test);
	int u, v;
	cin >> n;
	for(int i = 0; i < n; ++ i) {
		adj[i].clear();
	}
	for(int i = 0; i + 1 < n; ++ i) {
		scanf("%d%d", &u, &v);
		-- u, -- v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ret = n - 1;
	for(int i = 0; i < n; ++ i) {
		ret = min(ret, dfs(i, -1));
	}
	cout << ret << endl;
}

int main()
{
//	freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-attempt0.out", "w", stdout);
	//freopen("B-small-attempt1.in", "r", stdin); freopen("B-small-attempt1.out", "w", stdout);
	freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);
	int testcase;
	scanf("%d", &testcase);
	for(int i = 1; i <= testcase; ++ i) 
		solve(i);
	fclose(stdout);
	return 0;
}
