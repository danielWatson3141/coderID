#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <deque>
#include <cstring>
using namespace std;

#define REP(i, m, n) for(int i=(m); i<int(n); ++i)
#define rep(i, n) for(int i=0; i<int(n); ++i)
#define each(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back                                                                          
#define mp make_pair
#define def(a, x) __typeof(x) a = x
#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> PI;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

const int INF = 1<<29;
int N;
vector<int> G[1010];
int dp[2][1010];
int f(bool b, int v, int p = -1) {
	if (dp[b][v] != -1){// 	cout << b << " " << v << " " <<dp[b][v] << endl;
	return dp[b][v];}
	int &cnt = dp[b][v];
	cnt = 0;
	vector<int> adj = G[v];
	each(it, adj) if (*it == p) {adj.erase(it); break;}
	rep(i, sz(adj)) cnt += f(false, adj[i], v);
	if (b) {
		if (sz(adj) == 0) return cnt = 0;
		if (sz(adj) == 1) return cnt;
	} else {
		return cnt = cnt+1;
	}
	priority_queue<int> Q;
//	cout << cnt << endl;
	rep(i, sz(adj)) {
//		cout << adj[i] << " " << f(false, adj[i], v)  << ";" <<f(true, adj[i], v) << endl;
		Q.push(f(false, adj[i], v) - f(true, adj[i], v));
	}
//	cout << b << " " << v << " " << cnt << endl;
	cnt -= Q.top();
//	cout << b << " " << v << " " << cnt << endl;
	Q.pop();
	cnt -= Q.top();
//	cout << b << " " << v << " " << cnt << endl;
	return cnt;
}
void solve() {
	cin >> N;
	rep(i, N) G[i].clear();
	rep(i, N-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	memset(dp, -1, sizeof(dp));
//	cout << f(true, 1, 0) << endl;
//	cout << f(true, 0) << endl;
//	return;


	int ans = N;

	rep(i, N) {
		memset(dp, -1, sizeof(dp));
//		cout << f(true, i) << endl;
		ans = min(ans, f(false, i));
		ans = min(ans, f(true, i));
	}
	cout << ans << endl;
}
int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}

