/*
 * 2014-04-26  Token  <token@token-HP-ENVY-14-SPECTRE-Notebook-PC>

 * 
 */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <class T> inline T checkmin(T &a, T b) {
	return (a < b) ? a : a = b;
}

template <class T> inline T checkmax(T &a, T b) {
	return (a > b) ? a : a = b;
}

#define rep(i, n) for (int i = 0; i < n; ++ i)

const int MaxiN = 1005;

int N, Ans;
vector <int> Adj[MaxiN];
bool Known[MaxiN];
int Opt[MaxiN];

void Import() {
	scanf("%d", &N);
	rep (i, N)
		Adj[i].clear();
	rep (i, N - 1) {
		int U, V;
		scanf("%d%d", &U, &V);
		-- U, -- V;
		Adj[U].push_back(V);
		Adj[V].push_back(U);
	}
}

void Export(int T) {
	printf("Case #%d: %d\n", T, N - Ans);
}

void DFS(int Cur) {
	Known[Cur] = 1;
	Opt[Cur] = 1;
	if (Adj[Cur].size() == 1)
		return;
	int best1 = 0, best2 = 0;
	for (vector <int>::iterator it = Adj[Cur].begin(); it != Adj[Cur].end(); ++ it)
		if (!Known[*it]) {
			DFS(*it);
			if (Opt[*it] > best2) {
				if (Opt[*it] > best1) {
					best2 = best1;
					best1 = Opt[*it];
				} else
					best2 = Opt[*it];
			}
		}
	if (best2 == 0)
		return;
	Opt[Cur] += best1 + best2;
}

void Solve() {
	Ans = 1;
	rep (r, N) {
		fill(Opt, Opt + N, 0);
		fill(Known, Known + N, 0);
		DFS(r);
		checkmax(Ans, Opt[r]);
	}
}

int main() {
	int TestCase = 0;
	scanf("%d", &TestCase);
	for (int T = 1; T <= TestCase; ++ T) {
		Import();
		Solve();
		Export(T);
	}
	return 0;
}
