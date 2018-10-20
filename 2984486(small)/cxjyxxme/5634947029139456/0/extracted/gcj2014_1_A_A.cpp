#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <vector>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll maxn = 200;

ll T, n, l;
ll a1[maxn], a2[maxn];
map<ll, ll> m;

ll get(ll t)
{
	ll ans = 0;
	while (t)
	{
		t -= t & (-t);
		++ans;
	}
	return ans;
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	scanf("%I64d\n", &T);
	for (ll test = 1; test <= T; ++test)
	{
		scanf("%I64d %I64d\n", &n, &l);
		for (ll i = 0; i < n; ++i)
		{
			a1[i] = 0;
			char c = getchar();
			while (c != '1' && c != '0') c = getchar();
			while (c == '1' || c == '0')
			{
				a1[i] = a1[i] * 2LL + c - '0';
				c = getchar();
			}
		}
		for (ll i = 0; i < n; ++i)
		{
			a2[i] = 0;
			char c = getchar();
			while (c != '1' && c != '0') c = getchar();
			while (c == '1' || c == '0')
			{
				a2[i] = a2[i] * 2LL + c - '0';
				c = getchar();
			}
		}
		ll ans = 10000;
		for (ll i = 0; i < n; ++i)
		{
			bool br = true;
			m.clear();
			for (ll j = 0; j < n; ++j)
			{
				ll t = a1[0] ^ a2[i] ^ a1[j];
				if (m.count(t)) ++m[t];
				else m[t] = 1;
			}
			for (ll j = 0; j < n; ++j)
				if (!m.count(a2[j]) || m[a2[j]] == 0)
				{
					br = false;
					break;
				}
				else --m[a2[j]];
			if (br) ans = min(ans, get(a1[0] ^ a2[i]));
		}
		printf("Case #%I64d: ", test);
		if (ans == 10000) printf("NOT POSSIBLE\n");
		else printf("%I64d\n", ans);
	}
	fclose(stdin);fclose	(stdout);
}
