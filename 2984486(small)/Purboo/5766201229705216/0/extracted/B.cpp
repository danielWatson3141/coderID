#include <stdio.h>
#include <string.h>

#define MAXN 1010
#define MAXE MAXN*2

int best, degree[MAXN], N;
int head[MAXN], nxt[MAXE], end[MAXE], eg;

void addEdge(int u, int v)
{
	end[eg] = v;
	nxt[eg] = head[u];
	head[u] = eg++;
}

void reduce(int u)
{
	int e, v;

	e = head[u];
	while (e != -1) {
		v = end[e];
		degree[v]--;
		e = nxt[e];
	}

	degree[u] = 0;
}

void rereduce(int u)
{
	int e, v;

	e = head[u];
	while (e != -1) {
		v = end[e];
		degree[v]++;
		e = nxt[e];
	}

	degree[u] = 1;
}

bool isFull()
{
	int i;
	int n_leaf = 0, n_int = 0;

	for (i = 1; i <= N; i++) {
		if (degree[i] == 1) n_leaf++;
		else if (degree[i] > 1) n_int++;
	}

	return n_leaf == n_int + 1 && n_leaf > 1; 
}

void dfs(int n)
{
	int i;

	if (n == 0) return;
	if (isFull()) {
		if (N - n  < best)
			best = N - n;
		return;
	}

	for (i = 1; i <= N; i++) {
		if (degree[i] == 1) {
			reduce(i);
			dfs(n - 1);
			rereduce(i);
		}
	}

}

int solve()
{
	int i, n = N;
	
	if (N <= 2) return N;
	if (N == 3) return 0;

	best = N;
	dfs(n);

	return best;
}

int main()
{
	int T, t, i, u, v;

	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d", &N);

		eg = 0;
		memset(head, -1, sizeof(head));
		memset(degree, 0, sizeof(degree));
		for (i = 1; i < N; i++) {
			scanf("%d %d", &u, &v);
			degree[u]++;
			degree[v]++;
			addEdge(u, v);
			addEdge(v, u);
		}
		printf("Case #%d: %d\n", t, solve());
	}

	return 0;
}

