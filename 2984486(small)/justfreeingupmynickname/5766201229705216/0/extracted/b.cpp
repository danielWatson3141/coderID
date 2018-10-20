#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 99999
using namespace std;

int tc, n, a, b;
vector<int> al[1234];
int sz(int at, int par) {
	int ans = 1;
	for (int i = 0; i < al[at].size(); i++) if (al[at][i] != par) ans += sz(al[at][i], at);
	return ans;
}
int calc(int at, int par) {
	int chc = 0;
	for (int i = 0; i < al[at].size(); i++) if (al[at][i] != par) chc++;
	if (chc==1) return sz(at, par)-1;
	if (!chc) return 0;
	int mx1 = 0, mx2 = 0, tot = 0;
	for (int i = 0; i < al[at].size(); i++) if (al[at][i] != par) {
		int chsz = sz(al[at][i], at), cst = calc(al[at][i], at);
		int sv = chsz - cst;
		tot += chsz;
		if (sv > mx1) {
			mx2 = mx1; mx1 = sv;
		}
		else if (sv > mx2) mx2 = sv;
	}
	//printf("%d %d %d\n", at, par, tot - mx1 - mx2);
	return tot - mx1 - mx2;
}
int main() {
	freopen("b.in", "r", stdin); freopen("b.out", "w", stdout);
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++) {
		scanf("%d", &n);
		int ans = INF;
		for (int i = 1; i <= n; i++) al[i].clear();
		for (int i = 0; i < n-1; i++) {
			scanf("%d %d", &a, &b);
			al[a].push_back(b); al[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) ans = min(ans, calc(i, -1));
		printf("Case #%d: %d\n", t+1, ans);
	}

	return 0;
}