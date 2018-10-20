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

const int N = 1005, M = N * 2;

int T, n, e;
int head[N], nxt[M], pnt[M], sz[N];

void init() {
	e = 0;
	memset(head, -1, sizeof(head));
	memset(sz, 0, sizeof(sz));
}

void add(int u, int v) {
	pnt[e] = v, nxt[e] = head[u], head[u] = e++, sz[u]++;
}

int gao(int p, int fa) {
	int m1, m2, tmp, v;
	m1 = m2 = 0;
	if (fa == -1 && sz[p] < 2) return 1;
	if (fa != -1 && sz[p] < 3) return 1;
	repe (i, p) {
		v = pnt[i];
		if (v == fa) continue;
		tmp = gao(v, p);
		if (tmp > m1) m2 = m1, m1 = tmp;
		else if (tmp <= m1 && tmp > m2) m2 = tmp;
	}
	return m1 + m2 + 1;
}

int main() {
	int u, v, x, y, ans, cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		init();
		rep (i, n - 1) {
			scanf("%d %d", &u, &v);
			add(u, v), add(v, u);
		}
		ans = 0;
		FOR (i, 1, n) {
			x = gao(i, -1);
			ans = max(ans, x);
		}
		printf("Case #%d: %d\n", ++cas, n - ans);
	}
    return 0;
}
