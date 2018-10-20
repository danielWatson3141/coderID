//Template
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <ios>
#include <iomanip>
#include <ctime>
#include <numeric>
#include <functional>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <cstdarg>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
#define pair(x, y) make_pair(x, y)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)

inline int read() {
	static int r, sign;
	static char c;
	r = 0, sign = 1;
	do c = getchar(); while (c != '-' && (c < '0' || c > '9'));
	if (c == '-') sign = -1, c = getchar();
	while (c >= '0' && c <= '9') r = r * 10 + (int)(c - '0'), c = getchar();
	return sign * r;
}

template <typename T>
inline void print(T *a, int n) {
	for (int i = 1; i < n; ++i) cout << a[i] << " ";
	cout << a[n] << endl;
}
#define PRINT(_l, _r, _s, _t) { cout << #_l #_s "~" #_t #_r ": "; for (int _i = _s; _i != _t; ++_i) cout << _l _i _r << " "; cout << endl; }

#define N 1000
int T, n, l;
ll a[N + 1], b[N + 1], c[N + 1];
string str;

inline ll convert(string s) {
	ll ret = 0LL;
	for (int i = 0; i < l; ++i)
		if (s[i] == '1') ret |= 1LL << (l - i - 1);
	return ret;
}

const ll base = 1327, mod = 123456789012419LL;

inline ll Hash() {
	ll ret = 0LL;
	for (int i = 1; i <= n; ++i)
		ret = (ret * base + c[i]) % mod;
	return ret;
}

set <pair <ll, pair <int, int> > > h;
set <pair <ll, pair <int, int> > > :: iterator it;

bool check(ll x) {
	for (int i = 1; i <= n; ++i) {
		c[i] = a[i];
		for (int j = 0; j < l; ++j)
			if (x >> j & 1) c[i] ^= 1LL << j;
	}
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; ++i)
		if (b[i] != c[i]) return false;
	return true;
}

int calc(ll cur) {
	int ret = 0;
	while (cur > 0) {
		if (cur & 1LL) ++ret;
		cur >>= 1;
	}
	return ret;
}

int main(int argc, char *argv[]) {
#ifdef KANARI
	freopen("input.txt", "r", stdin);
	freopen("answer.txt", "w", stdout);
#endif
	
	int Case = 0;
	ios :: sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n >> l;
		for (int i = 1; i <= n; ++i) {
			cin >> str;
			a[i] = convert(str);
		}
		for (int i = 1; i <= n; ++i) {
			cin >> str;
			b[i] = convert(str);
		}
		
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		int ans = l + 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				ll cur = a[i] ^ b[j];
				if (check(cur))
					ans = min(ans, calc(cur));
			}
		
		cout << "Case #" << ++Case << ": ";
		if (ans > l) cout << "NOT POSSIBLE" << endl;
		else cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
