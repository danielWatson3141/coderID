#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

#include<algorithm>
#include<utility>
#include<string>

#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

using namespace std;

#define FOR(i,N) for (int i = 0; i < (N); i++)
#define FORI(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, b, a) for (int i = (b) - 1; i >= a; i--)
#define DP(arg...) fprintf(stderr, ## arg) //COMPILER SPECIFIC!!!


typedef long long ll;

int t, T, N;

int X[2000], Y[2000];
vector<int> Ne[2000];
int S[2000];

int dfs2(int v, int par) {
	S[v] = 1;

	for (int w:Ne[v]) {
		if (w != par) {
			S[v] += dfs2(w, v);
		}
	}
	return S[v];
}

int dfs(int v, int par) {
	vector<int> rek;
	int AA = 0;
	int s = 0;
	for (int w:Ne[v]) {
		if (w != par) {
			rek.push_back(dfs(w,v) - S[w]);
			s++;
			AA += S[w];
		}
	}
	if (s >= 2) {
		sort(rek.begin(), rek.end());
		return rek[0] + rek[1] + AA;
	}
	else return S[v] - 1;

}

void solve() {
	FOR(n,N) Ne[n].clear();
	FOR(n,N-1) {
		Ne[X[n]].push_back(Y[n]);
		Ne[Y[n]].push_back(X[n]);
	}

	int minD = -1;
	FOR(root,N) {
		dfs2(root,-1);
		int D = dfs(root,-1);
		if (minD == -1)
			minD = D;
		else minD = min(D, minD);
	}

	printf("Case #%d: %d\n", t, minD);
}

int main() {
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d", &N);
		FOR(n,N-1) {
			scanf("%d%d", &X[n], &Y[n]);
			X[n]--; Y[n]--;
		}
		solve();
	}
	return 0;
}
