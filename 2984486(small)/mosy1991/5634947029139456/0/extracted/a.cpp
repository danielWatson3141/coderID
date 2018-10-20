#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))

#define MAXN 200
#define MAXL 50
#define INF 1000000

typedef long long LL;
int n, l;
LL a1[MAXN], a2[MAXN], f[MAXN];
char s1[MAXN][MAXL], s2[MAXN][MAXL];

bool vis[MAXL];

LL change(char s[])
{
	int len = strlen(s);
	LL pow = 1;
	LL ans = 0;
	for (int i = len - 1; i >= 0; --i)
	{
		LL tmp = s[i] - '0';
		ans += tmp * pow;
		pow <<= 1;
	}
	return ans;
}

int solve()
{
	int ans = INF;
	for (int j = 0; j < n; ++j)
	{
		LL t = a1[0] ^ a2[j];
		for (int k = 0; k < n; ++k)
			f[k] = a1[k] ^ t;
		sort(f, f + n); 
		bool ok = true;
		for (int k = 0; k < n; ++k)
			if (f[k] != a2[k])
			{
				ok = false;
				break;
			}
		if (!ok) continue;
		int num = 0;
		while (t)
		{
			if (t & 1) ++num;
			t >>= 1;
		}
		ans = min(ans, num);
	}
	return ans;
}

int main()
{
	int T, cases = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &l);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s1[i]);
			a1[i] = change(s1[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s2[i]);
			a2[i] = change(s2[i]);
		}
		sort(a2, a2 + n);
		int ans = solve();
		printf("Case #%d: ", ++cases);
		if (ans == INF)
		{
			printf("NOT POSSIBLE\n");
		}
		else printf("%d\n", ans);
	}
	return 0;
}
