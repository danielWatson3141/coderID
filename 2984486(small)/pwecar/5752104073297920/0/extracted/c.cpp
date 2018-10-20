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

int N, a[MAXN];

int main()
 {
	freopen("c.in", "r", stdin), freopen("c.out", "w", stdout);
	int cases = Read();
	fo (ca, 1, cases)
	 {
		scanf("%d", &N);
		int cnt1 = 0, cnt2 = 0;
		fo (i, 0, N - 1)
		 {
			a[i] = Read();
			if (a[i] > i) ++ cnt1;
			if (a[i] < i) ++cnt2;
		 }
		printf("Case #%d: ", ca);
		if (cnt1 - cnt2 > 30) puts("BAD"); else puts("GOOD");
	 }
	return 0;
 }
