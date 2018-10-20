#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;

#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())

const int INF = 1000;
const int MAX_N = 150;
const int MAX_L = 40;

int tc;
int N, L;

ll outlet[MAX_N + 5];
ll device[MAX_N + 5];

bool possible(int d, int o) {
	vector<ll> oc(N), dc(N);
	
	REP(i, N) dc[i] = device[i];
	
	ll beda = outlet[o] ^ device[d];
	REP(i, N) oc[i] = outlet[i] ^ beda;
	
	/*
	puts("");
	printf("oc : ");
	REP(i, N) printf("%d, ", oc[i]); puts("");
	
	printf("dc : ");
	REP(i, N) printf("%d, ", dc[i]); puts("");
	*/
	
	sort(dc.begin(), dc.end());
	sort(oc.begin(), oc.end());
	
	return dc == oc;
}

ll binary(ll x) {
	ll ret = 0;
	int idx = 0;
	while(x) {
		if (x%10 == 1) ret += (1LL << idx);
		x /= 10;
		idx++;
	}
	return ret;
}

void solve() {
	scanf("%d %d", &N, &L);
	REP(i, N) scanf("%lld", &outlet[i]), outlet[i] = binary(outlet[i]);
	REP(i, N) scanf("%lld", &device[i]), device[i] = binary(device[i]);
	
	int ans = INF;
	REP(dev, N)	REP(out, N) {
		int cost = __builtin_popcountll(device[dev] ^ outlet[out]);
		if (possible(dev, out))	ans = min(ans, cost);
	}
	printf("Case #%d: ", tc);
	if (ans >= INF) puts("NOT POSSIBLE");
	else printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) solve();
	return 0;
}
