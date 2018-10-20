#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <cassert>
#include <climits>
using namespace std;
int E[1005][2], F[1005], siz[1005];
vector<int> adj[1005];
void go(int x, int p = -1) {
	siz[x] = 1;
	for (auto i = adj[x].begin(); i != adj[x].end(); ++i) {
		if (*i == p) continue;
		go(*i, x);
		siz[x] += siz[*i];
	}
	int mn = INT_MAX, mn2 = INT_MAX;
	// delete all child
	F[x] = siz[x] - 1;
	// take back 2 after delete
	int numc = 0;
	for (auto i = adj[x].begin(); i != adj[x].end(); ++i) {
		if (*i == p) continue;
		int v = -siz[*i] + F[*i];
		if (v < mn) {
			mn2 = mn;
			mn = v;
		} else if (v < mn2) {
			mn2 = v;
		}
		++numc;
	}
	if (numc >= 2) F[x] = min(F[x], siz[x] - 1 + mn + mn2);
}
int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		int N;
		scanf("%d", &N);
		for (int i = 1; i < N; ++i) {
			scanf("%d%d", &E[i][0], &E[i][1]);
		}
		int ans = INT_MAX;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) adj[j].clear();
			for (int j = 1; j < N; ++j) {
				adj[E[j][0]].push_back(E[j][1]);
				adj[E[j][1]].push_back(E[j][0]);
			}
			go(i);
			ans = min(ans, F[i]);
		}
		printf("Case #%d: %d\n", cn, ans);
	}
}

