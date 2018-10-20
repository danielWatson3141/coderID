#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstring>
#include <algorithm>
//using namespace std;
const int maxn = 1010;
const int maxm = 2020;
int n, m, testnum, c;
int f[maxn], top[maxn], next[maxm], point[maxm];
int g[maxn];
void dfs(int i, int fa) {
	
	int j = top[i], cost2 = 0, cost1 = 0, cost3 = 0, ans1 = maxn, ans2 = maxn;
	while (j) {
		int k = point[j];
		if (k != fa) {
			dfs(k, i);
			cost1++;
			cost2 += g[k];
			//cost2 += g[k][0];
			//cost3 += g[k][1];
			//if (f[k] - g[k][0] < ans1) { ans2 = ans1; ans1 = f[k]-g[k][0];  } else
			//if (f[k] - g[k][0] < ans2) { ans2 = f[k] -g[k][0]; }
			if (f[k] - g[k] < ans1) { ans2 = ans1; ans1 = f[k]-g[k];  } else
			if (f[k] - g[k] < ans2) { ans2 = f[k] -g[k]; }			
		}
		j = next[j];
	}

	//g[i][0] = 1 + cost3;
	//g[i][1] = cost2;
	//if (g[i][0] < g[i][1]) g[i][1] = g[i][0];
	g[i] = cost2 + 1;
	f[i] = cost2;
	if (cost1 >= 2)
		if (cost2 + ans1 + ans2 < f[i]) f[i] = cost2 + ans1 + ans2;
	//printf("	%d %d %d %d %d\n", fa, i, f[i], g[i][0], g[i][1]);

}
int tot = 0;
void add(int j, int k) {
	tot++; next[tot] = top[j]; top[j] = tot; point[tot] = k;
	tot++; next[tot] = top[k]; top[k] = tot; point[tot] = j;
}

int main() {
	freopen("B-small-attempt0.in.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &testnum);

	for (int test = 1; test <= testnum; test++) {
		scanf("%d", &n);
		tot = 0; memset(top, 0, sizeof(top));
		for (int i = 1; i <= n - 1; i++) {
			int j, k;
			scanf("%d%d", &j, &k);
			add(j, k);
		}
		int ans = n;
		for (int i = 1; i <= n; i++) {
			dfs(i, 0);
			if (f[i] < ans)
				ans = f[i];

//printf("%d %d %d\n",i, f[i],ans);
		}
		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}