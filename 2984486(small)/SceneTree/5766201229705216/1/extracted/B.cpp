#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

vector<int> a[1005];
int n;
int f[1005], s[1005];

	void DP(int u, int fa)
	{
		int m1 = n + n, m2 = n + n;
		int tot = 0;
		s[u] = 0;
		for (int o = 0; o < SIZE(a[u]); ++o) {
			int v = a[u][o];
			if (v != fa) {
				DP(v, u);
				++tot;
				s[u] += s[v];
				if (f[v] - s[v] < m1) {
					m2 = m1;
					m1 = f[v] - s[v];
				} else if (f[v] - s[v] < m2) {
					m2 = f[v] - s[v];
				}
			}
		}
		if (tot == 0) f[u] = 0;
		else if (tot == 1) f[u] = s[u];
		else f[u] = m1 + m2 + s[u];
		s[u] ++;
	}
int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int Tests, tts;
	for (scanf("%d", &Tests); Tests--; ) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) a[i].clear();
		for (int i = 1; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[x].PB(y);
			a[y].PB(x);
		}

		int ans = n + n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				s[j] = 0, f[j] = 0;
			DP(i, 0);
			if (f[i] < ans) ans = f[i];
		}

		printf("Case #%d: %d\n", ++tts, ans);
	}
	return 0;
}