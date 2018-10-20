#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

vector<int> e[1111];
int f[1111][3], size[1111];
int n;

void dfs(int k, int p) {
	size[k] = 1;
	for (int i=0; i<e[k].size(); ++i) {
		int v = e[k][i];
		if (v != p) {
			dfs(v, k);
			size[k] += size[v];
		}
	}
	f[k][0] = 0;
	f[k][1] = f[k][2] = 111111111;
	for (int i=0; i<e[k].size(); ++i) {
		int v = e[k][i];
		if (v != p) {
			int now[3];
			memcpy(now, f[k], sizeof(now));
			for (int j=0; j<3; ++j) {
				f[k][j] = now[j] + size[v];
				if (!j) continue;
				f[k][j] = min(f[k][j], now[j-1] + min(f[v][0], f[v][2]));
			}
		}
	}
}

int main() {
	int _, cas = 0;
	scanf("%d", &_);
	while (_--) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) e[i].clear();
		for (int i=1; i<n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			u --; v --;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int ans = 111111111;
		for (int i=0; i<n; ++i) {
			dfs(i, -1);
			ans = min(ans, f[i][0]);
			ans = min(ans, f[i][2]);
		}
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}
