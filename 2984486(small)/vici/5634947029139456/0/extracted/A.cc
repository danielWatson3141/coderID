#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 222;
string sa[N], sb[N];
string sc[N], sd[N];
char inv(char x) {
	if (x == '1') return '0';
	if (x == '0') return '1';
}
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-out.txt", "w", stdout);
	int ca = 1; int T;
	for (scanf("%d", &T); T--; ) {
		int n, m; scanf("%d%d", &n, &m);
		rep(i, n) cin >> sa[i];
		rep(i, n) cin >> sb[i];
		rep(i, n) sd[i] = sb[i];
		sort(sd, sd + n);
		int ret = inf;
		rep(i, n) rep(j, n) {
			int tr = 0;
			rep(k, n) sc[k] = "";
			rep(k, m) {
				if (sa[i][k] == sb[j][k]) {
					rep(l, n) sc[l] += sa[l][k];
				} else {
					++tr;
					rep(l, n) {
						if (sa[l][k] == '1') sc[l] += '0';
						else sc[l] += '1';
					}
				}
			}
			sort(sc, sc + n);
			bool ok = 1;
			rep(k, n) if (sc[k] != sd[k]) {
				ok = 0;
				break;
			}
			if (ok) ret = min(ret, tr);
		}
		printf("Case #%d: ", ca++);
		if (ret == inf) puts("NOT POSSIBLE");
		else printf("%d\n", ret);
	}
	return 0;
}

