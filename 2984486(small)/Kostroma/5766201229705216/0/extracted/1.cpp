#pragma comment (linker, "/STACK:128000000")
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
//void precalc();
clock_t start;
//int timer = 1;
int main() {
#ifdef room111
    freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
	cout.sync_with_stdio(0);
	//precalc();
	cout.precision(10);
	cout << fixed;
	cin >> t;
	start = clock();
	int testNum = 1;
    while (t--) {
		cout << "Case #" << testNum++ << ": ";
        solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

const int L = 12;

int n;
vector<vector<int>> g;
vector<int> cnt;

vector<int> dp;

void dfs(int v, int p = -1) {
	cnt[v] = 1;
	vector<int> children;
	for (int to : g[v]) {
		if (to == p)
			continue;
		dfs(to, v);
		cnt[v] += cnt[to];
		children.push_back(dp[to] - cnt[to]);
	}
	dp[v] = cnt[v] - 1;
	sort(all(children));
	if (children.size() >= 2)
		dp[v] = min(dp[v], children[0] + children[1] + cnt[v] - 1);

}

void solve() {
	cin >> n;
	g.assign(n, vector<int>());
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ans = n;
	int bestRoot = -1;

	for (int root = 0; root < n; ++root) {
		cnt.assign(n, 0);
		dp.assign(n, n);
		dfs(root);
			if (dp[root] < ans) {
				ans = dp[root];
				bestRoot = root;
			}
	}

	cout << ans << "\n";
	//cout << "bestRoot = " << bestRoot << "\n";

}
