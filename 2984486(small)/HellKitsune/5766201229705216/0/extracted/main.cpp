#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int t, n;
vector<int> e[1000];
vector<bool> vis;

PII go(int v) {
	vis[v] = true;
	vector<int> ch;
	PII ret = mp(0, 1);
	REP(i, e[v].size())
		if (!vis[e[v][i]]) {
			PII goret = go(e[v][i]);
			ret.second += goret.second;
			ret.first += goret.first;
			ch.pb(goret.second - goret.first);
		}
	sort(ch.begin(), ch.end());
	int k = ch.size();
	REP(i, ch.size()) {
		if (k == 0 || k == 2)
			break;
		--k;
		ret.first += ch[i];
	}
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	REP(test, t) {
		cin >> n;
		REP(i, n)
			e[i].clear();
		REP(i, n - 1) {
			int x, y;
			cin >> x >> y; --x; --y;
			e[x].pb(y);
			e[y].pb(x);
		}
		int ans = n;
		REP(i, n) {
			vis.assign(n, false);
			ans = min(ans, go(i).first);
		}
		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
	return 0;
}
