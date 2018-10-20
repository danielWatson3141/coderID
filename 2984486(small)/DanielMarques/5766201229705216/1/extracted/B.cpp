#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int adj[1010][1010], nadj[1010], vis[1010], tot[1010];

int go(int node) {
	if (vis[node] == 1) return 0;
	vis[node] = 1;

	int best = -1, sbest = -1;
	for (int i = 0; i < nadj[node]; i++) {
		if (vis[adj[node][i]] == 0) {
			int aux = go(adj[node][i]);

			if (aux > best) {
				sbest = best;
				best = aux;
			}
			else if (aux > sbest) {
				sbest = aux;
			}
		}
	}
	//printf("dfs: %d %d %d\n", node, best, sbest);
	if (best != -1 && sbest != -1) {
		tot[node] = sbest + best + 1;
	}
	else {
		tot[node] = 1;
	}
	return tot[node];
}

int main() {
	int T;
	scanf(" %d", &T);
	for (int _42=1; _42 <=T; _42++) {
		scanf(" %d", &N);
		memset(nadj, 0, sizeof(nadj));
		for (int i = 0; i < N-1; i++) {
			int a, b;
			scanf(" %d %d ", &a, &b);
			adj[a][nadj[a]] = b;
			adj[b][nadj[b]] = a;
			nadj[a]++;
			nadj[b]++;
		}
		/*
		for (int i =1;i<=N;i++) {
			for (int j =0;j<nadj[i];j++) {
				printf("%d %d\n", i, adj[i][j]);
			}
		}
		*/
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			//printf("for%d\n", i);
			memset(vis, 0, sizeof(vis));
			memset(tot, 0, sizeof(tot));
			ans = max(ans, go(i));
		}
		
		printf("Case #%d: %d\n", _42, N - ans);
	}
	return 0;
}