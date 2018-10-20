#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstdarg>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
 
#define all(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define sz(c) (int)(c).size()
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int NaN = -239;
const int INF = 100000;
const int maxn = 1 << 10;

vector<int> g[maxn];
int dp[maxn][2];

void cost(int s, int pr) {
	int sum = 0;
	int child = 0;
	vector<int> q;
	for (int i = 0; i < sz(g[s]); i++) {
		if (g[s][i] != pr) {
			cost(g[s][i], s);
			sum += dp[g[s][i]][1];
			q.pb(dp[g[s][i]][0] - (dp[g[s][i]][1] + 1));
			child++;
		}
	}
	//eprintf("cost %d %d, child = %d\n", s, pr, child);
	//eprintf("sum = %d\n", sum);
	dp[s][1] = sum + child;
	dp[s][0] = sum + child;
	sort(q.begin(), q.end());
	if (sz(q) >= 2) {
		dp[s][0] += q[0] + q[1];
	}
}
void solve(int test) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		g[i].clear();
	}
	for (int i = 0; i < n - 1; i++) {
		int x, y; scanf("%d%d", &x, &y), x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	int res = n;
	for (int i = 0; i < n; i++) {
		cost(i, -1);
		//eprintf("cost %d = %d\n", i, dp[i][0]);
		res = min(dp[i][0], res);
	}
	printf("Case #%d: %d\n", test, res);
}

int main() {
	int T; scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		solve(test);
	}
}
