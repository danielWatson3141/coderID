#include <stdio.h>
#include <vector>

using namespace std;

#define N 15
vector<int> g[N];
int del[N];
int sbt[N];

void dfs (int curr, int prev) {
	int cnt = 0, i, j;
	del[curr] = 0;
	sbt[curr] = 1;
	for (i = 0; i < g[curr].size(); i++) {
		int next = g[curr][i];
		if (next == prev)	continue;
		dfs(next, curr);
		sbt[curr] += sbt[next];
		cnt++;
	}
	if (!cnt)	return;
	if(cnt == 2) {
		for (i = 0; i < g[curr].size(); i++) {
			int next = g[curr][i];
			if (next == prev)	continue;
			del[curr] += del[next];
		}
	} else if (cnt == 1) {
		for (i = 0; i < g[curr].size(); i++) {
			int next = g[curr][i];
			if (next == prev)	continue;
			del[curr] += sbt[next];
		}
	} else {
		int m = N, dels;
		for (i = 0; i < g[curr].size(); i++) {
			for (j = i+1; j < g[curr].size(); j++) {
				if (g[curr][i] == prev || g[curr][j] == prev)	continue;
				dels = (sbt[curr]-1-sbt[g[curr][i]]-sbt[g[curr][j]]) +
						(del[g[curr][i]] + del[g[curr][j]]);
				m = min(m, dels);
			}
		}
		del[curr] = m;
	}
}

int main (void) {
	int t, c;
	int n, u, v, i;
	scanf ("%d", &t);
	for (c = 1; c <= t; c++) {
		scanf ("%d", &n);
		for (i = 0; i < n; i++)	g[i].clear();
		for (i = 0; i < n-1; i++) {
			scanf ("%d%d", &u, &v);
			u--; v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = N;
		for (i = 0; i < n; i++) {
			dfs(i, -1);
			ans = min(ans, del[i]);
		}
		printf ("Case #%d: %d\n", c, ans);
	}
}