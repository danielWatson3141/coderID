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
 
const int MAXN = 155, MAXM = 45;

LL a[MAXN], b[MAXN], c[MAXN];
int N, M, one[1 << 20];
char s[45];

LL Readbit()
 {
	LL ret = 0;
	scanf("%s", s);
	fo (i, 0, M - 1) ret |= ((LL) (s[i] - 48) << i);
	return ret;
 }
 
int main()
 {
	freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	int cases = Read();
	fo (ca, 1, cases)
	 {
		scanf("%d%d", &N, &M);
		fo (i, 1, N)
		 {
			a[i] = Readbit();
		 }
		fo (i, 1, N)
			b[i] = Readbit();
		sort(b + 1, b + N + 1);
		int ans = M + 1;
		fo (i, 1, N)
			fo (j, 1, N)
			 {
				LL cur = a[i] ^ b[j];
				fo (k, 1, N) c[k] = a[k] ^ cur;
				sort(c + 1, c + N + 1);
				bool chk = 1;
				fo (k, 1, N) if (b[k] != c[k]) { chk = 0; break; }
				if (chk)
				 {
					int cans = 0;
					fo (k, 0, M - 1) if (Bit(cur, k)) ++ cans;
					if (cans < ans) ans = cans;
				 }
			 }
		printf("Case #%d: ", ca);
		if (ans <= M) printf("%d\n", ans); else puts("NOT POSSIBLE");
	 }
	return 0;
 }
