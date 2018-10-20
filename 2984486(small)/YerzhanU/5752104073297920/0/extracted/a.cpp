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
#define MAXT 1000
#define MAXN 1001

int n;
int a[MAXN];
int b[MAXN];

inline int dist()
{
	int r = 0;
	for (int i = 0; i < n; ++i)
		r += abs(a[i] - b[i]);
	return r;
}

inline void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int r1 = 0;
	int r2 = 0;
	for (int t = 0; t < MAXT; ++t)
	{
		for (int i = 0; i < n; ++i)
			b[i] = i;
		for (int i = 0; i < n; ++i)
		{
			int p = (rand() % (n - i)) + i;
			swap(b[p], b[i]);
		}
		r1 += dist();
		for (int i = 0; i < n; ++i)
			b[i] = i;
		for (int i = 0; i < n; ++i)
		{
			int p = (rand() % n);
			swap(b[p], b[i]);
		}
		r2 += dist();
	}
//	cout << r1 << ' ' << r2 << endl;
	puts((1. * r1 / r2 < 1.0009 || abs(1 - 1. * r2 / r1) < 0.002056) ? "GOOD" : "BAD");
//	puts((abs(1 - 1. * r2 / r1) < 0.0020) ? "GOOD" : "BAD");
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	srand(2312);

	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
	{
		printf("Case #%d: ", t + 1);
		solve();
	}

	return 0;
}
