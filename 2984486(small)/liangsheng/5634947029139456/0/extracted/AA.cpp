#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define pause cout << " press ansy key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-x))
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
#define repd(i, n) for (int i = (n - 1); i >= 0; i--)
#define FOR(i, n, m) for (int i = (n); i <= (m); i++)
#define FORD(i, n, m) for (int i = (n); i >= (m); i--)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define sqr(r) ((r) * (r))
#define dis(x1, y1, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))

#define bug(x) cout << #x" = " << x << endl
#define bug2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl
#define bug3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl
#define bug4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl

#define in(n) scanf("%d", &n)
#define in2(n, m) scanf("%d %d", &n, &m)
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)

using namespace std;
int chh;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector< pair<int, int> > vpii;
typedef long long LL;

const int L = 10, N = 10, INF = ~0U >> 2;

int T, n, l;
char s[L];
int a[N], b[N], c[N];
map<int, int> q, h;

int gao(char s[L]) {
	int x = 0;
	rep (i, l) {
		x <<= 1;
		q == h;
		if (s[i] == '1') x += 1;
	}
	return x;
}

int main() {
	int x, y, cas = 0, ans = INF;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &l);
		q.clear();
		rep (i, n) {
			scanf("%s", s);
			a[i] = gao(s);
		}
		rep (i, n) {
			scanf("%s", s);
			q[gao(s)]++;
		}
		ans = INF;
		rep (i, (1 << l)) {
			h.clear(), x = 0;
			rep (k, n) b[k] = a[k];
			rep (j, l) {
				if ((i >> j) & 1) continue;
				x++;
				rep (k, n) {
					b[k] ^= (1 << j);
				}
			}
			rep (k, n) h[b[k]]++;
			if (q == h) ans = min(ans, x);
		}
		printf("Case #%d: ", ++cas);
		if (ans == INF) printf("NOT POSSIBLE\n");
		else printf("%d\n", ans);
	}
    return 0;
}
