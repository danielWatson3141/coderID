#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, ans;
string st;
long long f[200], g[200], a[200];

long long change()
{
	long long ret = 0;
	for (int i = 0; i < m; i++) ret = ret * 2 + st[i] - '0';
	return ret;
}

void init()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> st;
		f[i] = change();
		a[i] = f[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> st;
		g[i] = change();
	}
}

void solve()
{
	ans = -1; long long t, d; bool p; int c;
	sort(g, g + n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		t = a[i] ^ g[j];
		for (int k = 0; k < n; k++) f[k] = a[k] ^ t;
		sort(f, f + n); p = true;
		for (int k = 0; k < n; k++) if (f[k] != g[k]) {
			p = false; continue;
		}
		if (p) {
			c = 0; d = t;
			while (d > 0) {
				c += d % 2;
				d /= 2;
			}
			if (ans == -1) ans = c;
			ans = min(ans, c);
		}
	}
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int cas; cin >> cas;
	for (int t = 1; t <= cas; t++) {
		init();
		solve();
		printf("Case #%d: ", t);
		if (ans == -1)
			puts("NOT POSSIBLE");
		else 
			printf("%d\n", ans);
	}
	return 0;
}

