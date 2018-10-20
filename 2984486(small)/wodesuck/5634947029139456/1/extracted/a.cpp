#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <set>

using namespace std;

typedef long long LL;
const int MAXN = 150;
int n, l;
LL x[MAXN], y[MAXN], z[MAXN];
set<LL> tr;
char buf[50];
int ans;

LL read()
{
	LL x = 0;
	scanf("%s", buf);
	for (int i = 0; i < l; ++i) x = x<<1|(buf[i] - '0');
	return x;
}

void init()
{
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; ++i) x[i] = read();
	for (int i = 0; i < n; ++i) y[i] = read();
	tr.clear();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			tr.insert(x[i]^y[j]);
		}
	}
	sort(x, x + n);
}

bool check(LL mask)
{
	for (int i = 0; i < n; ++i) z[i] = y[i]^mask;
	sort(z, z + n);
	for (int i = 0; i < n; ++i) {
		if (x[i] != z[i]) return false;
	}
	return true;
}

int calc(LL mask)
{
	int s = 0;
	for (int i = 0; i < l; ++i) s += mask>>i&1;
	return s;
}

void solve()
{
	ans = INT_MAX;
	for (set<LL>::iterator i = tr.begin(); i != tr.end(); ++i) {
		if (check(*i)) ans = min(ans, calc(*i));
	}
}

int main()
{
	int dat;
	scanf("%d", &dat);
	for (int cas = 1; cas <= dat; ++cas) {
		init();
		solve();
		if (ans < INT_MAX) {
			printf("Case #%d: %d\n", cas, ans);
		} else {
			printf("Case #%d: NOT POSSIBLE\n", cas);
		}
	}
}
