#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

ll toll(string& s) {
	ll ret = 0;
	FOR(i, sz(s)) ret = ret * 2 + s[i] - '0';
	return ret;
}

string XOR(string& a, string& b) {
	string ret;
	FOR(i, sz(a)) ret.push_back(a[i] == b[i] ? '0' : '1');
	return ret;
}

int popcount(ll x) {
	x = (x & 0x5555555555555555ULL) + ((x & 0xAAAAAAAAAAAAAAAAULL) >> 1);
	x = (x & 0x3333333333333333ULL) + ((x & 0xCCCCCCCCCCCCCCCCULL) >> 2);
	x = (x & 0x0F0F0F0F0F0F0F0FULL) + ((x & 0xF0F0F0F0F0F0F0F0ULL) >> 4);
	return (int)(x * 0x0101010101010101ULL >> 56);
}

int main(){

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {

		int n, l; cin >> n >> l;
		vector<ll> v(n), to(n);
		FOR(i, n) {
			string s; cin >> s; v[i] = toll(s);
		}
		FOR(i, n) {
			string s; cin >> s; to[i] = toll(s);
		}
		sort(to.begin(), to.end());

		int ans = 1000000;
		FOR(i, n) {
			ll x = v[0] ^ to[i];
			vector<ll> vnext;
			FOR(j, n) vnext.push_back(v[j] ^ x);
			sort(vnext.begin(), vnext.end());
			if (vnext == to) {
				int cnt = popcount(x);
				ans = min(ans, cnt);
			}
		}

		printf("Case #%d: ", t);
		if (ans == 1000000) {
			printf("NOT POSSIBLE\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
