#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define ms(a,x) memset(a, x, sizeof(a))
#define forit(it,s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); ++it)
#define MAXN 155

int n, l;
ll a[MAXN];
ll b[MAXN];
char c[MAXN];

inline int get(ll x)
{
	int r = 0;
	while(x)
	{
		r += (x & 1);
		x >>= 1;
	}
	return r;
}

inline void solve()
{
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", c);
		a[i] = 0;
		for (int j = 0; j < l; ++j)
			if (c[j] == '1')
				a[i] |= (1LL << j);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", c);
		b[i] = 0;
		for (int j = 0; j < l; ++j)
			if (c[j] == '1')
				b[i] |= (1LL << j);
	}
	sort(b, b + n);
	int ans = l + 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			ll t = a[i] ^ b[j];
			for (int k = 0; k < n; ++k)
				a[k] ^= t;

			sort(a, a + n);

			bool ok = 1;
			for (int k = 0; k < n && ok; ++k)
				if (a[k] != b[k])
					ok = 0;

			if (ok)
				ans = min(ans, get(t));
			for (int k = 0; k < n; ++k)
				a[k] ^= t;
		}
	if (ans == l + 1)
	{
		puts("NOT POSSIBLE");
		return;
	}
	printf("%d\n", ans);
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
	{
		printf("Case #%d: ", t + 1);
		solve();
	}

	return 0;
}
