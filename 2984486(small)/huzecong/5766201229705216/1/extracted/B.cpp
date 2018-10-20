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

#define N 1100
struct edge {
	int next, node;
} e[N << 1 | 1];
int head[N + 1], tot;

inline void addedge(int a, int b) {
	e[++tot].next = head[a];
	head[a] = tot, e[tot].node = b;
}

int T, Case = 0, n, f[N + 1], size[N + 1], cnt[N + 1];

void dfs(int x, int fa) {
	size[x] = 1, cnt[x] = 0;
	int m = 0, m2 = 0;
	for (int i = head[x]; i; i = e[i].next) {
		int node = e[i].node;
		if (node == fa) continue;
		dfs(node, x);
		size[x] += size[node];
		++cnt[x];
		int cur = size[node] - f[node];
		if (cur > m) m2 = m, m = cur;
		else if (cur > m2) m2 = cur;
	}
	f[x] = size[x] - 1;
	if (cnt[x] >= 2) f[x] -= m + m2;
}

int main(int argc, char *argv[]) {
#ifdef KANARI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ios :: sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n;
		tot = 0;
		for (int i = 1; i <= n; ++i) head[i] = 0;
		for (int i = 1; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			addedge(x, y), addedge(y, x);
		}
		
		int ans = n - 1;
		for (int i = 1; i <= n; ++i) {
			dfs(i, 0);
			ans = min(ans, f[i]);
		}
		
		cout << "Case #" << ++Case << ": ";
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
