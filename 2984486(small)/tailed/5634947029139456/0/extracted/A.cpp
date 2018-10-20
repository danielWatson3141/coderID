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
void solve() {
	int N, L;
	ll as[2][1000];
	cin >> N >> L;
	rep(j, 2) rep(i, N)  {
		string s;
		cin >> s;
		ll a = 0;
		rep(k, sz(s)) a = a*2 + int(s[k]-'0');
		as[j][i] = a;
	}
	int ans = INF;
	rep(i, N) rep(j, N) {
		ll y = as[0][i] ^ as[1][j];
		set<ll> s;
		rep(i, N) s.insert(as[0][i]);
		bool ok = true;
		rep(i, N) {
			ll x = as[1][i] ^ y;
			if (!s.count(x)) {
				ok = false;
				break;
			}
		}
		if (ok) ans = min(ans, __builtin_popcount(y));
	}
	if (ans == INF) {
		cout << "NOT POSSIBLE" << endl;
	} else
		cout << ans << endl;
}
int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
}

