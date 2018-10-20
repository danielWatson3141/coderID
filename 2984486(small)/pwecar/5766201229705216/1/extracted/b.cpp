#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <map>
#include <set>

#define fi first
#define se second
#define fo(i,a,b) for (int i = a; i <= b; i ++)
#define fd(i,a,b) for (int i = a; i >= b; i --)
#define fe(i,x,y) for (int i = x, y = lnk[i]; i; i = nxt[i], y = lnk[i])
#define mkp make_pair
#define pb push_back
#define Fill(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define Bit(x,y) ((((x) >> (y)) & 1))
#define mit map<int,SI>::iterator
#define sit SI::iterator

using namespace std;
 
typedef long long LL;
typedef long double DB;
typedef pair <DB, DB> PD;
typedef pair <LL, LL> PLI;
typedef pair <PD, int> PDI;
typedef pair <int, int> PI;
typedef pair <int, PI> PII;
typedef pair <PI, PI> PIII;
typedef set <PI> SI;
typedef vector <int> VI;
 
int Read()
 {
    char c; while (c = getchar(), (c != '-') && (c < '0' || c > '9'));
    bool neg = (c == '-'); int ret = (neg ? 0 : c - 48);
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
    return neg ? -ret : ret;
 }
 
const int MAXN = 1005;

int st[MAXN], nxt[MAXN<<1], lnk[MAXN<<1];
int dp[MAXN][MAXN], size[MAXN][MAXN];
int N, M;

void DP(int x, int pre)
 {
	if (dp[x][pre] >= 0) return;
	size[x][pre] = 1;
	int deg = 0, mi1 = 0, mi2 = 0;
	fe (i, st[x], y) if (y != pre)
	 {
		deg ++, DP(y, x);
		size[x][pre] += size[y][x];
		if (dp[y][x] > mi1) mi2 = mi1, mi1 = dp[y][x];
			else if (dp[y][x] > mi2) mi2 = dp[y][x];
	 }
	if (deg < 2) { dp[x][pre] = 1; return; }
	dp[x][pre] = mi1 + mi2 + 1;
 }
 
int main()
 {
	freopen("b.in", "r", stdin), freopen("b.out", "w", stdout);
	int cases = Read();
	fo (ca, 1, cases)
	 {
		scanf("%d", &N);
		Fill(st, 0), Fill(nxt, 0);
		int cnt = 0;
		fo (i, 2, N)
		 {
			int x = Read(), y = Read();
			lnk[++ cnt] = y, nxt[cnt] = st[x], st[x] = cnt;
			lnk[++ cnt] = x, nxt[cnt] = st[y], st[y] = cnt;
		 }
		Fill(dp, -1);
		int ans = 0;
		fo (i, 1, N)
		 {
			DP(i, 0);
			if (dp[i][0] > ans) ans = dp[i][0];
		 }
		printf("Case #%d: %d\n", ca, N - ans);
	 }
	return 0;
 }