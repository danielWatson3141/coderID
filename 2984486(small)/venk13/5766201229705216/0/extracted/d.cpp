//venk13
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <cassert>

using namespace std;

#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

vector <pair <int, int> > edgeLst;
vector <int> edges[15];
bool vis[15];
int deg[15];

int bits(int a) {
	int cnt = 0;
	while(a) cnt += (a & 1), a >>= 1;
	return cnt;
}

int dfs(int i) {
	vis[i] = 1;
	int cnt = 1;
	for(int j = 0; j < sz(edges[i]); j++)
		if(!vis[edges[i][j]])
			cnt += dfs(edges[i][j]);
	return cnt;
}

int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, cas = 1; cin >> t;
	while(t--) {
		cout << "Case #" << cas++ << ": ";
		int n; cin >> n;
		edgeLst.clear();
		for(int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v; --u, --v;
			edgeLst.pb(mp(u, v));
		}
		int myans = 1 << 30;
		for(int mask = (1 << n) - 1; mask > 0; --mask) {
			for(int i = 0; i < n; i++)
				edges[i].clear();
			memset(deg, 0, sizeof deg);
			memset(vis, 0, sizeof vis);
			int choose = -1;
			for(int i = 0; i < n; i++)
				if(mask & (1 << i)) {
					choose = i;
					break;
				}
			for(int i = 0; i < n - 1; i++)
				if((mask & (1 << edgeLst[i].fi)) && (mask & (1 << edgeLst[i].se))) {
					edges[edgeLst[i].fi].pb(edgeLst[i].se), edges[edgeLst[i].se].pb(edgeLst[i].fi);
					deg[edgeLst[i].fi]++, deg[edgeLst[i].se]++;
				}
			int siz = dfs(choose);
			if(siz != bits(mask)) continue;
			int one = 0, two = 0, three = 0, zero = 0;
			for(int i = 0; i < n; i++) {
				if(!(mask & (1 << i))) continue;
				if(deg[i] == 0) zero++;
				if(deg[i] == 1) one++;
				if(deg[i] == 2) two++;
				if(deg[i] == 3) three++;
			}
			if(two == 1 && one + two + three == siz || siz == 1 && zero == 1) {
				myans = min(myans, n - siz);
			}
		}
		cout << myans << '\n';
	}
	return 0;
}