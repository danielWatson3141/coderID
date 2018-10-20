#include <iostream>
#include <cstring>

const int N = 1024;
const int INF = ~0U>>2;

using namespace std;

struct Edge {
	int u, v;
	Edge *next;
} E[N], *P = E, *H[N];

int vis[N], f[N], w[N];

void Ins(int u, int v)
{
	P->u = u, P->v = v, P->next = H[u], H[u] = P++;
}

void DFS(int u)
{
	vis[u] = 1;
	w[u] = 0;
	int x = INF, y = INF;
	for (Edge *e = H[u]; e; e = e->next)
		if (!vis[e->v]) {
			DFS(e->v);
			w[u] += w[e->v];
			int g = f[e->v] - w[e->v];
			if (g <	x) {
				y = x, x = g;
			} else if (g < y) {
				y = g;			
			}
		}
	f[u] = min(w[u], x + y + w[u]);
	w[u] ++;
	// cout << u << " " << f[u] << " " << w[u] << endl;
}

int process(int cas)
{
	int N;
	cin >> N;
	P = E;
	memset(H, 0, sizeof(H));
	for (int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		Ins(u, v); Ins(v, u);
	}
	int ans = N;
	for (int i = 1; i <= N; ++i) {
		memset(vis, 0, sizeof(vis));
		DFS(i);
		if (f[i] < ans) ans = f[i];
		// cout << f[i] << endl;
	}
	cout << "Case #" << cas << ": " << ans << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) process(i);
}

